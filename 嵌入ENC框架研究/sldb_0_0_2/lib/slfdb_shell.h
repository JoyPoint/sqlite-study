// liangxx@cndatacom.com

#ifndef LIANGXIAXU_SQLITE_SLDB_SLFDB_SHELL_H_20130116
#define LIANGXIAXU_SQLITE_SLDB_SLFDB_SHELL_H_20130116

/* 
**    SQLITE文件数据库
** | ****** tbl ****** |
** | id  | key  | val  |
** |-----|------|------|
** |  1  | key1 | val1 |
** |  2  | .... | .... |
*/

// lib3p_sqlite3
#include "sqlite3.h"
// lib3p_boost
// libstd
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
// lib
#include "common.hpp"
#include "slfstr_shell.hpp"

namespace sqlite
{
namespace sldb
{

class slfdb_shell : public slfstr_shell
{
public:
    slfdb_shell(void);
   ~slfdb_shell(void);

    // 操作
    bool open   (const std::string& path_);
    void close  (void);
    void sync   (void);
    bool insert (const void* key_buf, size_t  key_len, const void* val_buf, size_t  val_len);
    bool replace(const void* key_buf, size_t  key_len, const void* val_buf, size_t  val_len);
    bool fetch  (const void* key_buf, size_t  key_len, char_sptr*  val_buf, size_t* val_len);
    bool erase  (const void* key_buf, size_t  key_len);
    bool exist  (const void* key_buf, size_t  key_len);
    bool first  (char_sptr*  key_buf, size_t* key_len);
    bool next   (const void* key_buf, size_t  key_len, char_sptr* nkey_buf, size_t* nkey_len);
    size_t mark_erasure(const char_sptr& key_buf, size_t key_len);
    size_t erase_marked(void);
    size_t size(void) const { return _size; }
    std::string path(void) const { return _path; }

private:
    void get_size(void);
    bool tbl_exist(void);
    int  get_id_from_key(const void* key_buf, size_t key_len);
    int  get_id_from_val(const void* val_buf, size_t val_len);
    int  get_max_id(void);
    int  get_min_id(void);
    bool dump(void);
    bool load(void);

private:
    // sqlite object
    sqlite3* _sldb;
    sqlite3_stmt* _stmt_insert;
    sqlite3_stmt* _stmt_replace;
    sqlite3_stmt* _stmt_fetch;
    sqlite3_stmt* _stmt_erase;
    sqlite3_stmt* _stmt_exist;
    sqlite3_stmt* _stmt_first;
    sqlite3_stmt* _stmt_next;
    sqlite3_stmt* _stmt_size;
    sqlite3_stmt* _stmt_tbl_exist;
private:
    struct mark_unit
    {
        char_sptr key_buf;
        size_t key_len;
    };
    std::vector<mark_unit> _vec_mark_unit;
    size_t _size;
    unsigned long int _max_id;
    std::string _path;
private:
    const char* _sql_crt_tbl;
    const char* _sql_insert;
    const char* _sql_replace;
    const char* _sql_fetch;
    const char* _sql_erase;
    const char* _sql_exist;
    const char* _sql_first;
    const char* _sql_next;
    const char* _sql_size;
    const char* _sql_tbl_exist;
    const char* _sql_id_from_key;
    const char* _sql_max_id;
    const char* _sql_min_id;
};

} // sldb
} // sqlite

#endif // LIANGXIAXU_SQLITE_SLDB_SLFDB_SHELL_H_20130116

// vim: set tabstop=4 shiftwidth=4 expandtab:
