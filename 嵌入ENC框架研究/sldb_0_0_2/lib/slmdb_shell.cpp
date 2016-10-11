// liangxx@cndatacom.com

// lib3p_sqlite3
#include "sqlite3.h"
// lib3p_boost
#include "boost/format.hpp"
//#include "boost/algorithm/string.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
// libstd
#include <iostream>
// lib
#include "common.hpp"
#include "slmdb_shell.h"

namespace sqlite
{
namespace sldb
{

// construction =======================================================================
slmdb_shell::slmdb_shell()
    : _sldb(NULL), 
      _stmt_insert( NULL), 
      _stmt_replace(NULL), 
      _stmt_fetch(  NULL), 
      _stmt_erase(  NULL), 
      _stmt_exist(  NULL), 
      _stmt_first(  NULL), 
      _stmt_next(   NULL), 
      _stmt_size(   NULL), 
      _size(0), 
      _capacity(0), // ÈÝÁ¿
      _max_id(0), 
      _path("")     // Â·¾¶
{
    _sql_crt_tbl = "create table tbl(id integer primary key, key not null unique, val);";
    _sql_insert = "insert into tbl(key, val) values(?, ?);";
    _sql_replace = "update tbl set val = ? where key = ?;";
    _sql_fetch = "select val from tbl where key = ?;";
    _sql_erase = "delete from tbl where key = ?;";
    _sql_exist = "select * from tbl where key = ?;";
    _sql_first = "select key from tbl, (select min(id) as minid from tbl) t where tbl.id = t.minid;";
    _sql_next = "select key from tbl where id = ?;";
    _sql_size = "select count(*) from tbl;";
    _sql_tbl_exist = "select count(*) from sqlite_master where type='table' and name='tbl';";
    _sql_id_from_key = "select id from tbl where key = ?;";
    _sql_max_id = "select max(id) from tbl;";
    _sql_min_id = "select min(id) from tbl;";
}

slmdb_shell::~slmdb_shell(void)
{
    if (_sldb != NULL)
    {
        close();
    }
}

// public =============================================================================
bool 
slmdb_shell::open(size_t capacity_, const std::string& path_)
{
    int rc = sqlite3_open(":memory:", &_sldb);
    if (SQLITE_OK == rc)
    {
        // sync optimize ...
        optimize(_sldb, MDB);

        char* errmsg = NULL;
        rc = sqlite3_exec(_sldb, _sql_crt_tbl, NULL, NULL, &errmsg);
        if (SQLITE_OK == rc)
        {
            _capacity = capacity_;
            _path = path_;
            return true;
        }
        else
        {
            std::cout << "[error] <open> create table" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "[error] <open> open database" << std::endl;
        return false;
    }
}

void 
slmdb_shell::close(void)
{
    if (_stmt_insert != NULL)
    {
        sqlite3_finalize(_stmt_insert);
        _stmt_insert = NULL;
    }
    if (_stmt_replace != NULL)
    {
        sqlite3_finalize(_stmt_replace);
        _stmt_replace = NULL;
    }
    if (_stmt_fetch != NULL)
    {
        sqlite3_finalize(_stmt_fetch);
        _stmt_fetch = NULL;
    }
    if (_stmt_erase != NULL)
    {
        sqlite3_finalize(_stmt_erase);
        _stmt_erase = NULL;
    }
    if (_stmt_exist != NULL)
    {
        sqlite3_finalize(_stmt_exist);
        _stmt_exist = NULL;
    }
    if (_stmt_first != NULL)
    {
        sqlite3_finalize(_stmt_first);
        _stmt_first = NULL;
    }
    if (_stmt_next != NULL)
    {
        sqlite3_finalize(_stmt_next);
        _stmt_next = NULL;
    }
    if (_stmt_size != NULL)
    {
        sqlite3_finalize(_stmt_size);
        _stmt_size = NULL;
    }
    if (SQLITE_OK == sqlite3_close(_sldb))
        _sldb = NULL;
    else
        std::cout << "[error] <close> close database" << std::endl;
}

void 
slmdb_shell::sync(void)
{
    dump();
}

bool 
slmdb_shell::insert(const void* key_buf, size_t key_len, const void* val_buf, size_t val_len)
{
    if (full())
    {
        //std::cout << "[error] <insert> slmdb is full" << std::endl;
        return false;
    }
    
    int rc = 0;
    if (_stmt_insert != NULL)
        // not first time to insert
        sqlite3_reset(_stmt_insert);
    else
        // first time to insert
        sqlite3_prepare(_sldb, _sql_insert, -1, &_stmt_insert, 0);

    rc = sqlite3_bind_blob(_stmt_insert, 1, key_buf, key_len, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "[error] <insert> sql bind" << std::endl;
        return false;
    }

    rc = sqlite3_bind_blob(_stmt_insert, 2, val_buf, val_len, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "[error] <insert> sql bind" << std::endl;
        return false;
    }

    rc = sqlite3_step(_stmt_insert);
    if (rc != SQLITE_DONE)
    {
        std::cout << "[error] <insert> sql step" << std::endl;
        std::cout << "_stmt_insert: " << _stmt_insert << std::endl;
        return false;
    }

    _size ++;
    return true;
}

bool 
slmdb_shell::replace(const void* key_buf, size_t key_len, const void* val_buf, size_t val_len)
{
    int rc = 0;
    if (_stmt_replace != NULL)
        // not first time to replace
        sqlite3_reset(_stmt_replace);
    else
        // first time to replace
        sqlite3_prepare(_sldb, _sql_replace, -1, &_stmt_replace, 0);

    rc = sqlite3_bind_blob(_stmt_replace, 1, val_buf, val_len, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "[error] <replace> sql bind" << std::endl;
        return false;
    }

    rc = sqlite3_bind_blob(_stmt_replace, 2, key_buf, key_len, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "[error] <replace> sql bind" << std::endl;
        return false;
    }

    rc = sqlite3_step(_stmt_replace);
    if (rc != SQLITE_DONE)
    {
        std::cout << "[error] <replace> sql step" << std::endl;
        std::cout << "_stmt_replace: " << _stmt_replace << std::endl;
        return false;
    }

    return true;
}

bool 
slmdb_shell::fetch(const void* key_buf, size_t key_len, char_sptr* val_buf, size_t* val_len)
{
    if (_stmt_fetch != NULL)
        // not first time to fetch
        sqlite3_reset(_stmt_fetch);
    else
        // first time to fetch
        sqlite3_prepare(_sldb, _sql_fetch, -1, &_stmt_fetch, 0);

    sqlite3_bind_blob(_stmt_fetch, 1, key_buf, key_len, SQLITE_TRANSIENT);
    int rc = sqlite3_step(_stmt_fetch);
    if ((rc != SQLITE_ROW) && (rc != SQLITE_DONE))
        std::cout << "[error] <fetch> sql step" << std::endl;
    
    //*val_buf = char_sptr((char*)sqlite3_column_blob(_stmt_fetch, 0), std::free);
    //*val_buf = char_sptr((char*)sqlite3_column_blob(_stmt_fetch, 0));
    *val_len = (size_t)sqlite3_column_bytes(_stmt_fetch, 0);
    char* tmp = (char*)std::malloc((*val_len) * sizeof(char));
    std::memset(tmp, 0, *val_len);
    std::memcpy(tmp, (char*)sqlite3_column_blob(_stmt_fetch, 0), *val_len);
    *val_buf = char_sptr(tmp, std::free);

    if (sqlite3_data_count(_stmt_fetch) != 0)
        return true;
    else
        return false;
}

bool 
slmdb_shell::erase(const void* key_buf, size_t key_len)
{
    int rc = 0;
    if (_stmt_erase != NULL)
        // not first time to erase
        sqlite3_reset(_stmt_erase);
    else
        // first time to erase
        sqlite3_prepare(_sldb, _sql_erase, -1, &_stmt_erase, 0);

    rc = sqlite3_bind_blob(_stmt_erase, 1, key_buf, key_len, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "[error] <erase> sql bind" << std::endl;
        return false;
    }

    rc = sqlite3_step(_stmt_erase);
    if (rc != SQLITE_DONE)
    {
        std::cout << "[error] <erase> sql step" << std::endl;
        std::cout << "_stmt_erase: " << _stmt_erase << std::endl;
        return false;
    }

    _size --;
    return true;
}

bool 
slmdb_shell::exist(const void* key_buf, size_t key_len)
{
    int rc = 0;
    if (_stmt_exist != NULL)
        // not first time to exist
        sqlite3_reset(_stmt_exist);
    else
        // first time to exist
        sqlite3_prepare(_sldb, _sql_exist, -1, &_stmt_exist, 0);

    rc = sqlite3_bind_blob(_stmt_exist, 1, key_buf, key_len, NULL);
    if (rc != SQLITE_OK)
    {
        std::cout << "[error] <exist> sql bind" << std::endl;
        return false;
    }

    rc = sqlite3_step(_stmt_exist);
    if ((rc != SQLITE_ROW) && (rc != SQLITE_DONE))
    {
        std::cout << "[error] <exist> sql step" << std::endl;
        std::cout << "_stmt_exist: " << _stmt_exist << std::endl;
        return false;
    }

    if (sqlite3_data_count(_stmt_exist) != 0)
        return true;
    else
        return false;
}

bool 
slmdb_shell::first(char_sptr* key_buf, size_t* key_len)
{
    if (_stmt_first != NULL)
    {
        sqlite3_finalize(_stmt_first);
        _stmt_first = NULL;
    }

    sqlite3_prepare(_sldb, _sql_first, -1, &_stmt_first, 0);

    int rc = sqlite3_step(_stmt_first);
    if ((rc != SQLITE_ROW) && (rc != SQLITE_DONE))
        std::cout << "[error] <first> sql step" << std::endl;

    *key_len = (size_t)sqlite3_column_bytes(_stmt_first, 0);
    char* tmp = (char*)std::malloc((*key_len) * sizeof(char));
    std::memset(tmp, 0, *key_len);
    std::memcpy(tmp, (char*)sqlite3_column_blob(_stmt_first, 0), *key_len);
    *key_buf = char_sptr(tmp, std::free);

    if (sqlite3_data_count(_stmt_first) != 0)
    {
        _max_id = get_max_id();
        //sqlite3_finalize(_stmt_first);
        //_stmt_first = NULL;
        return true;
    }
    else
    {
        //sqlite3_finalize(_stmt_first);
        //_stmt_first = NULL;
        return false;
    }
}

bool 
slmdb_shell::next(const void* key_buf, size_t key_len, char_sptr* nkey_buf, size_t* nkey_len)
{
    if (_stmt_next != NULL)
        sqlite3_reset(_stmt_next);
    else
        sqlite3_prepare(_sldb, _sql_next, -1, &_stmt_next, 0);

    unsigned long int nextid = get_id_from_key(key_buf, key_len);
    //int maxid = get_max_id();

    if (nextid < _max_id)
    {
        do
        {
            nextid ++;
            sqlite3_bind_int(_stmt_next, 1, nextid);
            int rc = sqlite3_step(_stmt_next);
            if ((rc != SQLITE_ROW) && (rc != SQLITE_DONE))
                std::cout << "[error] <next> sql step" << std::endl;
            *nkey_len = (size_t)sqlite3_column_bytes(_stmt_next, 0);
            char* tmp = (char*)std::malloc((*nkey_len) * sizeof(char));
            memcpy(tmp, (char*)sqlite3_column_blob(_stmt_next, 0), *nkey_len);
            *nkey_buf = char_sptr(tmp, std::free);

            if (sqlite3_data_count(_stmt_next) != 0)
                return true;
        } while (nextid <= _max_id);
    }
    return false;
}

size_t 
slmdb_shell::mark_erasure(const char_sptr& key_buf, size_t key_len)
{
    mark_unit mark_unit_;
    mark_unit_.key_buf = key_buf;
    mark_unit_.key_len = key_len;

    _vec_mark_unit.push_back(mark_unit_);
    return _vec_mark_unit.size();
}

size_t 
slmdb_shell::erase_marked(void)
{
    size_t res_size = 0;
    size_t max_size = _vec_mark_unit.size();
    for (size_t i = 0; i < max_size; i ++)
        if (erase(_vec_mark_unit.at(i).key_buf.get(), _vec_mark_unit.at(i).key_len))
            res_size ++;
    // clear vector
    _vec_mark_unit.clear();
    boost::format info("sqlite('%1%'): erase %2% / (req = %3%), remain %4% record(s)");
    info % ":memory:" % res_size % max_size % size();
    std::cout << info.str() << std::endl;
    return res_size;
}

bool 
slmdb_shell::full(void)
{
    return (size() >= _capacity);
}

// private ============================================================================
#if 1
void 
slmdb_shell::get_size(void)
{
    if (_stmt_size != NULL)
        sqlite3_finalize(_stmt_size);
    sqlite3_prepare(_sldb, _sql_size, -1, &_stmt_size, 0);
    sqlite3_step(_stmt_size);
    _size = (size_t)sqlite3_column_int(_stmt_size, 0);
}
#endif

#if 1
bool 
slmdb_shell::dump(void)
{
    int rc = 0;

    sqlite3_backup* pbackup = NULL;
    sqlite3* pto = NULL;

    // 20121009T164000
    std::string time(boost::posix_time::to_iso_string(boost::posix_time::from_time_t(std::time(NULL) + 8 * 3600)));
    time.erase(time.find('T'), 1);

    boost::format bkdb("sldb_%1%.db");
    bkdb % time;
    std::string bkdb_path = "./" + bkdb.str();

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
        std::cout << "[success] <dump> " << std::endl;
        _sldb = pto;
        return true;
    }
    else
    {
        std::cout << "[error] <dump> " << sqlite3_errmsg(_sldb) << std::endl;
        return false;
    }
}
#endif

#if 1
bool
slmdb_shell::load(void)
{
    int rc = 0;

    sqlite3_backup* pbackup = NULL;
    sqlite3* pto = NULL;

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
        std::cout << "[success] <load> " << std::endl;
        _sldb = pto;
        return true;
    }
    else
    {
        std::cout << "[error] <load> " << sqlite3_errmsg(_sldb) << std::endl;
        return false;
    }
}
#endif

bool 
slmdb_shell::tbl_exist(void)
{
    int rc = 0;
    sqlite3_stmt* stmt = NULL;
    rc = sqlite3_prepare(_sldb, _sql_tbl_exist, -1, &stmt, 0);
    if (rc != SQLITE_OK)
    {
        std::cout << "[error] <tbl_exist> sql prepare" << std::endl;
        return false;
    }
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW)
    {
        std::cout << "[error] <tbl_exist> sql step" << std::endl;
        return false;
    }
    int flag = sqlite3_column_int(stmt, 0);
    rc = sqlite3_finalize(stmt);
    if (rc != SQLITE_OK)
    {
        std::cout << "[error] <tbl_exist> sql finalize" << std::endl;
        return false;
    }
    stmt = NULL;
    if (1 == flag)
        return true;
    else
        return false;
}

int 
slmdb_shell::get_id_from_key(const void* key_buf, size_t key_len)
{
    sqlite3_stmt* stmt = NULL;

    sqlite3_prepare(_sldb, _sql_id_from_key, -1, &stmt, 0);
    sqlite3_bind_blob(stmt, 1, key_buf, key_len, SQLITE_TRANSIENT);
    int rc = sqlite3_step(stmt);
    if ((rc != SQLITE_ROW) && (rc != SQLITE_DONE))
        std::cout << "[error] <get_id_from_key> sql step" << std::endl;

    int id = (int)sqlite3_column_int(stmt, 0);

    if (sqlite3_data_count(stmt) != 0)
    {
        sqlite3_finalize(stmt);
        stmt = NULL;
        return id;
    }
    else
    {
        sqlite3_finalize(stmt);
        stmt = NULL;
        return -1;
    }
}

int 
slmdb_shell::get_id_from_val(const void* val_buf, size_t val_len)
{
    return 0;
}

int 
slmdb_shell::get_max_id(void)
{
    sqlite3_stmt* stmt = NULL;
    sqlite3_prepare(_sldb, _sql_max_id, -1, &stmt, 0);
    int rc = sqlite3_step(stmt);
    if ((rc != SQLITE_ROW) && (rc != SQLITE_DONE))
        std::cout << "[error] <get_max_id> sql step" << std::endl;
    int id = (int)sqlite3_column_int(stmt, 0);

    if (sqlite3_data_count(stmt) != 0)
    {
        sqlite3_finalize(stmt);
        stmt = NULL;
        return id;
    }
    else
    {
        sqlite3_finalize(stmt);
        stmt = NULL;
        return -1;
    }
}

int 
slmdb_shell::get_min_id(void)
{
    sqlite3_stmt* stmt = NULL;
    sqlite3_prepare(_sldb, _sql_min_id, -1, &stmt, 0);
    int rc = sqlite3_step(stmt);
    if ((rc != SQLITE_ROW) && (rc != SQLITE_DONE))
        std::cout << "[error] <get_min_id> sql step" << std::endl;
    int id = (int)sqlite3_column_int(stmt, 0);

    if (sqlite3_data_count(stmt) != 0)
    {
        sqlite3_finalize(stmt);
        stmt = NULL;
        return id;
    }
    else
    {
        sqlite3_finalize(stmt);
        stmt = NULL;
        return -1;
    }
}

} // namespace sldb
} // namespace sqlite

// vim: set tabstop=4 shiftwidth=4 expandtab:
