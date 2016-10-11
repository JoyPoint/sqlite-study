// liangxx@cndatacom.com
// sqlitedb_cpp

#include "sqlitedb.h"
#include "sqlite3.h"
#include "boost/format.hpp"
#include "boost/lexical_cast.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include <iostream>
#include "sap_item.h"
#include "dir.hpp"

namespace cdc
{
namespace smmc
{
namespace sap
{

// ----------------------------------------------------------------------------
sqlitedb::sqlitedb(const enc::base::cfgmgr_sptr& cfgmgr_sptr_, const std::string& tbl_name, const std::string& key_name, const std::string& content_name)
    : _cfgmgr_sptr(cfgmgr_sptr_), 
      _sldb(NULL), 
      _stmt(NULL), 
      _tbl(tbl_name), 
      _key(key_name), 
      _content(content_name), 
      _mode(false), 
      _size(0)
{
    sap_item sap_item_;
    // if fetch fail, set default
    if (! _cfgmgr_sptr->merged_config.fetch(&sap_item_))
    {
        _path = "./data/dbf";
    }
    else
    {
        _path = sap_item_.sqlite_path;
    }
    create_dir(_path);
}

sqlitedb::~sqlitedb(void)
{
    if (NULL == _sldb)
    {
    }
    else
    {
        close();
    }
}

// ----------------------------------------------------------------------------
bool 
sqlitedb::open(void)
{
#ifdef _DEBUG_
    std::cout << "[- DEBUG -] <open> _sldb = " << _sldb << std::endl;
#endif

    int rc = 0;
    std::string sldb_path = _path + "/sldb.db";
    if (_mode)
        rc = sqlite3_open(sldb_path.c_str(), &_sldb);
    else
        rc = sqlite3_open(":memory:", &_sldb);

#ifdef _DEBUG_
    std::cout << "[- DEBUG -] <open> _sldb = " << _sldb << std::endl;
#endif

    if (SQLITE_OK == rc)
    {
        std::cout << "[-SUCCESS-] <open> " << std::endl;
        return true;
    }
    else
    {
        std::cout << "[- ERROR -] <open> " << sqlite3_errmsg(_sldb) << std::endl;
        close();
        return false;
    }
}

bool
sqlitedb::close(void)
{
#ifdef _DEBUG_
    std::cout << "[- DEBUG -] <close> _sldb = " << _sldb << std::endl;
#endif

    int rc = sqlite3_close(_sldb);
    _sldb = NULL;

#ifdef _DEBUG_
    std::cout << "[- DEBUG -] <close> _sldb = " << _sldb << std::endl;
#endif

    if (SQLITE_OK == rc)
    {
        std::cout << "[-SUCCESS-] <close> " << std::endl;
        return true;
    }
    else
    {
        std::cout << "[- ERROR -] <close> " << sqlite3_errmsg(_sldb) << std::endl;
        return false;
    }
}

bool 
sqlitedb::table(void)
{
    boost::format sql("create table %1%(id integer primary key, %2% varchar(64) not null unique, %3% varchar(128));");
    sql % _tbl % _key % _content;

    return exec(sql.str(), "table");
}

bool 
sqlitedb::fetch(void)
{
    boost::format sql("select * from %1%;");
    sql % _tbl;

    return exec_fetch(sql.str(), "all");
}

bool 
sqlitedb::fetch(const std::string& key_val)
{
    boost::format sql("select * from %1% where %2% = '%3%';");
    sql % _tbl % _key % key_val;

    return exec_fetch(sql.str(), "key");
}

bool 
sqlitedb::insert(const std::string& key_val, const std::string& content_val)
{
    boost::format sql("insert into %1%(%2%, %3%) values('%4%', '%5%');");
    sql % _tbl % _key % _content % key_val % content_val;

    if (exec(sql.str(), "insert"))
    {
        _size ++;
        return true;
    }
    else
    {
        return false;
    }
}

bool 
sqlitedb::replace(const std::string& key_val, const std::string& content_val)
{
    boost::format sql("update %1% set %2% = '%3%' where %4% = '%5%';");
    sql % _tbl % _content % content_val % _key % key_val;

    return exec(sql.str(), "replace");
}

bool 
sqlitedb::remove(void)
{
    boost::format sql("delete from %1%;");
    sql % _tbl;

    if (exec(sql.str(), "remove all"))
    {
        _size = 0;
        return true;
    }
    else
    {
        return false;
    }
}

bool 
sqlitedb::remove(const std::string& key_val)
{
    boost::format sql("delete from %1% where %2% = '%3%';");
    sql % _tbl % _key % key_val;

    if (exec(sql.str(), "remove key"))
    {
        _size --;
        return true;
    }
    else
    {
        return false;
    }
}

bool 
sqlitedb::first()
{
    return true;
}

bool 
sqlitedb::next()
{
    return true;
}

bool 
sqlitedb::dump(void)
{
    int rc;

    sqlite3_backup* pbackup;
    sqlite3 *pto;

    if (! _mode)
    {
        std::string time(boost::posix_time::to_iso_string(boost::posix_time::from_time_t(std::time(NULL) + 8 * 3600))); // 20121009T164000
        time.erase(time.find('T'), 1);

        boost::format bkdb("/sldb_%1%.db");
        bkdb % time;
        std::string bkdb_path = _path + bkdb.str();

        sqlite3_open(bkdb_path.c_str(), &pto);

        pbackup = sqlite3_backup_init(pto, "main", _sldb, "main");

        if (pbackup)
        {
            sqlite3_backup_step(pbackup, -1);
            sqlite3_backup_finish(pbackup);
        }
        rc = sqlite3_errcode(pto);
        if (SQLITE_OK == rc)
        {
            std::cout << "[-SUCCESS-] <dump> " << std::endl;
            _sldb = pto;
            _mode = true;
            return true;
        }
        else
        {
            std::cout << "[- ERROR -] <dump> " << sqlite3_errmsg(_sldb) << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "[- ERROR -] <dump> " << "sldb already dump to file" << std::endl;
        return false;
    }
}

bool
sqlitedb::load(void)
{
    int rc;

    sqlite3_backup* pbackup;
    sqlite3 *pto;

    if (_mode)
    {
        sqlite3_open(":memory:", &pto);

        pbackup = sqlite3_backup_init(pto, "main", _sldb, "main");

        if (pbackup)
        {
            sqlite3_backup_step(pbackup, -1);
            sqlite3_backup_finish(pbackup);
        }
        rc = sqlite3_errcode(pto);
        if (SQLITE_OK == rc)
        {
            std::cout << "[-SUCCESS-] <load> " << std::endl;
            _sldb = pto;
            _mode = false;
            return true;
        }
        else
        {
            std::cout << "[- ERROR -] <load> " << sqlite3_errmsg(_sldb) << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "[- ERROR -] <load> " << "sldb already load to memory" << std::endl;
        return false;
    }
}

// ----------------------------------------------------------------------------
bool 
sqlitedb::exec(const std::string& sql, const std::string& label)
{
    char* errmsg = NULL;
    int rc = sqlite3_exec(_sldb, sql.c_str(), NULL, NULL, &errmsg);
    if (SQLITE_OK == rc)
    {
        std::cout << "[-SUCCESS-] <" << label << "> " << std::endl;
        return true;
    }
    else
    {
        std::cout << "[- ERROR -] <" << label << "> " << errmsg << std::endl;
        return false;
    }
}

bool
sqlitedb::exec_fetch(const std::string& sql, const std::string& label)
{
    char** rslt;
    int row;
    int col;
    char* errmsg = NULL;

    int rc = sqlite3_get_table(_sldb, sql.c_str(), &rslt, &row, &col, &errmsg);
    if (SQLITE_OK == rc)
    {
        //²éÑ¯³É¹¦
        std::cout << "[-SUCCESS-] <fetch " << label << "> " << row << " records fetch" << std::endl;
        std::cout << "\n";
        if (row != 0)
        {
            for (register int i = 0; i < row + 1; i ++)
            {
                for (register int j = 0; j < col; j ++)
                {
                    std::cout << rslt[i * col + j] << "\t";
                }
                std::cout << std::endl;
                if (0 == i) 
                {
                    for (register int k = 0; k < col; k ++)
                        std::cout << "--------";
                    std::cout << std::endl;
                }
            }
            std::cout << "\n\n";
        }
        sqlite3_free_table(rslt);
        return true;
    }
    else
    {
        std::cout << "[- ERROR -] <fetch " << label << "> " << errmsg << std::endl;
        sqlite3_free_table(rslt);
        return false;
    }
}

} // namespace sap
} // namespace smmc
} // namespace cdc

// vim: set tabstop=4 shiftwidth=4 expandtab:
