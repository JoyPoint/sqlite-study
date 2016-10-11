// liangxx@cndatacom.com

#ifndef LIANGXIAXU_SQLITE_SLDB_SLFSTR_SHELL_HPP_20130204
#define LIANGXIAXU_SQLITE_SLDB_SLFSTR_SHELL_HPP_20130204

// 二进制及字符串接口
// [void*] & [std::string] interface for sqlite file database

// lib3p boost
#include "boost/utility.hpp"
// libstd
#include <string>
// lib
#include "common.hpp"

namespace sqlite
{
namespace sldb
{

class slfstr_shell : private boost::noncopyable
{
public:
    virtual ~slfstr_shell(){}

    // ================== 二进制接口 ==================
    virtual bool open(const std::string& path_) = 0;
    virtual void close(void) = 0;
    virtual void sync( void) = 0;
    virtual bool insert( const void* key_buf, size_t  key_len, const void* val_buf, size_t  val_len) = 0;
    virtual bool replace(const void* key_buf, size_t  key_len, const void* val_buf, size_t  val_len) = 0;
    virtual bool fetch(  const void* key_buf, size_t  key_len, char_sptr*  val_buf, size_t* val_len) = 0;
    virtual bool erase(  const void* key_buf, size_t  key_len) = 0;
    virtual bool exist(  const void* key_buf, size_t  key_len) = 0;
    virtual bool first(  char_sptr*  key_buf, size_t* key_len) = 0;
    virtual bool next(   const void* key_buf, size_t  key_len, char_sptr* nkey_buf, size_t* nkey_len) = 0;
    virtual size_t size(void) = 0;
    virtual size_t mark_erasure(const char_sptr& key_buf, size_t key_len) = 0;
    virtual size_t erase_marked(void) = 0;
    virtual std::string path(void) const = 0;

    // ================== 字符串接口 ==================
    virtual bool insert(const std::string& key, const void* val_buf, size_t val_len)
    { 
        return insert(key.data(), key.size() + 1, val_buf, val_len);
    }
    virtual bool replace(const std::string& key, const void* val_buf, size_t val_len)
    { 
        return replace(key.data(), key.size() + 1, val_buf, val_len);
    }
    virtual bool fetch(const std::string& key, char_sptr* val_buf, size_t* val_len)
    {
        return fetch(key.data(), key.size() + 1, val_buf, val_len);
    }
    virtual bool erase(const std::string& key)
    {
        return erase(key.data(), key.size() + 1);
    }
    virtual bool exist(const std::string& key)
    {
        return exist(key.data(), key.size() + 1);
    }
    virtual bool first(std::string* key, char_sptr* val_buf, size_t* val_len)
    {
        char_sptr key_buf;
        size_t key_len;
        // 获取第一个键
        bool rc = first(&key_buf, &key_len);
        if (rc)
        {
            *key = reinterpret_cast<char*>(key_buf.get());
            // 根据获取到的键去获取对应的值
            return fetch(key->data(), key_len, val_buf, val_len);
        }
        else
            return false;
    }
    // 输入键，获取下一个键和值
    virtual bool next(const std::string& key, std::string* nkey, char_sptr* val_buf, size_t* val_len)
    {
        char_sptr nkey_buf;
        size_t nkey_len;
        bool rc = next(key.data(), key.size() + 1, &nkey_buf, &nkey_len);
        if (rc)
        {
            *nkey = reinterpret_cast<char*>(nkey_buf.get());
            return fetch(nkey->data(), nkey_len, val_buf, val_len);
        }
        else
            return false;
    }

protected:
    slfstr_shell(void) {}

}; // class slfstr_shell

typedef boost::shared_ptr<slfstr_shell> slfstrsh_sptr;

} // namesapce sldb
} // namespace sqlite

#endif // LIANGXIAXU_SQLITE_SLDB_SLFSTR_SHELL_HPP_20130204

// vim: set tabstop=4 shiftwidth=4 expandtab:
