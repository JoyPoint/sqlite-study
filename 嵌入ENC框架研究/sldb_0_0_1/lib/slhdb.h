// liangxx@cndatacom.com

#ifndef LIANGXIAXU_SQLITE_SLDB_SLHDB_H_20130204
#define LIANGXIAXU_SQLITE_SLDB_SLHDB_H_20130204

/* 
**    SQLITE混合数据库
** | ****** tbl ****** |
** | id  | key  | val  |
** |-----|------|------|
** |  1  | key1 | val1 |
** |  2  | .... | .... |
*/

// lib3p_sqlite3
#include "sqlite3.h"
// lib3p_boost
#include "boost/utility.hpp"
#include "boost/shared_ptr.hpp"
// libstd
#include <string>
// lib
#include "common.hpp"
#include "slfdb_shell.h"
#include "slmdb_shell.h"

namespace sqlite
{
namespace sldb
{

class slhdb : private boost::noncopyable
{
public:
    slhdb(size_t capacity, const std::string& path, slfstr_shell* slfstrsh_wptr, slfstr_shell* slfstrsh_bptr);

    bool open(void);

    bool fetch(  const std::string&  key, char_sptr*  val_buf, size_t* val_len);
    bool insert( const std::string&  key, const void* val_buf, size_t  val_len);
    bool replace(const std::string&  key, const void* val_buf, size_t  val_len);
    bool erase(  const std::string&  key);
    bool first(        std::string*  key, char_sptr*  val_buf, size_t* val_len);
    bool next(         std::string* nkey, char_sptr*  val_buf, size_t* val_len);
    size_t size(void) { return _slmstrsh_sptr->size() + (_slfstrsh_wsptr ? _slfstrsh_wsptr->size() : 0); }
    size_t mark_erasure(const std::string& key);
    size_t erase_marked(void);
    void sync(void);
    bool resume(bool flag);
    bool resume(const std::string& key, const void* val_buf, size_t val_len);

private:
    bool   slfstr_shell_first(std::string*  key, char_sptr* val_buf, size_t* val_len);
    bool   slfstr_shell_next( std::string* nkey, char_sptr* val_buf, size_t* val_len);
    size_t slfstr_shell_mark_erasure(const std::string& key);
    size_t slfstr_shell_erase_marked(void);

    bool _resume_flag; 
    bool _slmstr_flag;
    std::string _path;

    // 内存数据库
    slmstrsh_sptr _slmstrsh_sptr;
    // 文件数据库
    slfstrsh_sptr _slfstrsh_wsptr;
    slfstrsh_sptr _slfstrsh_bsptr;
    slfstrsh_sptr _slfstrsh_esptr;

//    std::string _key;
    std::string _pre_key;
    size_t      _key_len;
    char_sptr   _key_buf;

}; // class slhdb

typedef boost::shared_ptr<slhdb> slhdb_sptr;

} // namesapce sldb
} // namespace sqlite

#endif // LIANGXIAXU_SQLITE_SLDB_SLHDB_H_20130204

// vim: set tabstop=4 shiftwidth=4 expandtab:
