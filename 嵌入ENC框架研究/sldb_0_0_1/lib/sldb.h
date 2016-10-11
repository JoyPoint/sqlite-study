// liangxx@cndatacom.com

#ifndef LIANGXIAXU_SQLITE_DEMO_SQLITEDB_H_20121212
#define LIANGXIAXU_SQLITE_DEMO_SQLITEDB_H_20121212

#include "sqlite3.h"
#include <string>
#include "boost/cstdint.hpp"

namespace sqlite
{
namespace demo
{

class sqlitedb
{
public:
    sqlitedb(const std::string& tbl_name, const std::string& key_name, const std::string& content_name);
    ~sqlitedb(void);
    // --------------------------------------------------------------------
    // connect/build a db
    bool open(void);
    bool close(void);
    // --------------------------------------------------------------------
    // init table
    bool table(void);
    // fetch all
    bool fetch(void);
    // fetch according to key
    bool fetch(const std::string& key_val);
    bool insert(const std::string& key_val, const std::string& content_val);
    bool replace(const std::string& key_val, const std::string& content_val);
    // remove all
    bool remove(void);
    // remove key
    bool remove(const std::string& key_val);

    bool first();
    bool next();
    // --------------------------------------------------------------------
    boost::uint32_t size(void) const { return _size; }
    // dbA[mem]->dbB[file]
    bool dump(void);
    // dbA[file]->dbB[mem]
    bool load(void);

private:
    // encapsulate sqlite3_exec()
    bool exec(const std::string& sql, const std::string& label);
    // encapsulate sqlite3_get_table()
    bool exec_fetch(const std::string& sql, const std::string& label);

private:
    // sqlite object ------------------------------------------------------
    sqlite3*      _sldb;
    sqlite3_stmt* _stmt;
    // table --------------------------------------------------------------
    // | id | _key | _content |
    // |----|------|----------|
    // |  1 | key_ | content_ |
    // |  2 | .... | ........ |
    std::string _tbl;
    std::string _key;
    std::string _content;
    // running mode
    // --false: memory (default)
    // --true : file
    bool _mode;
    // size
    boost::uint32_t _size;
    // ......
};

} // demo
} // sqlite

#endif // LIANGXIAXU_SQLITE_DEMO_SQLITEDB_H_20121212

// vim: set tabstop=4 shiftwidth=4 expandtab:
