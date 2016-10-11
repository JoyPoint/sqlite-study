// liangxx@cndatacom.com

// lib
#include "slhdb.h"
#include "base.hpp"
// lib boost
#include "boost/format.hpp"

namespace sqlite
{
namespace sldb
{

// [0]
slhdb::slhdb(size_t capacity, const std::string& path_, slfstr_shell* slfstrsh_wptr, slfstr_shell* slfstrsh_bptr)
    : _slmstr_flag(true), 
      _path(path_ + ".dbmf"), 
      _slfstrsh_wsptr(slfstrsh_wptr), 
      _slfstrsh_bsptr(slfstrsh_bptr), 
      _pre_key("")
{
    // 打开内存数据库
    _slmstrsh_sptr=slmstrsh_sptr(new slmdb_shell);
    _slmstrsh_sptr->open(capacity, _path);
    resume(false);
}

bool
slhdb::open(void)
{
    // 打开文件数据库
    return _slfstrsh_wsptr ? _slfstrsh_wsptr->open(_path) : true;
}
// [0]

// [1]
bool 
slhdb::fetch(const std::string& key, char_sptr* val_buf, size_t* val_len)
{
    // 如果内存数据库不存在该键并且内存数据库已满，就从文件数据库中查询
    // 否则从内存数据库中查询
    if (! _slmstrsh_sptr->exist(key) && _slmstrsh_sptr->full())
        return _slfstrsh_wsptr ? _slfstrsh_wsptr->fetch(key, val_buf, val_len) : (*val_len = 0);
    return _slmstrsh_sptr->fetch(key, val_buf, val_len);
}

bool 
slhdb::insert(const std::string& key, const void* val_buf, size_t val_len)
{
    // 优先插入内存数据库
    // 若失败则插入文件数据库
    if (_slmstrsh_sptr->insert(key, val_buf, val_len))
        return true;
    return _slfstrsh_wsptr ? _slfstrsh_wsptr->insert(key, val_buf, val_len) : false;
}

bool 
slhdb::replace(const std::string& key, const void* val_buf, size_t val_len)
{
    if (_slmstrsh_sptr->replace(key, val_buf, val_len))
        return true;
    return _slfstrsh_wsptr ? _slfstrsh_wsptr->replace(key, val_buf, val_len) : false;
}

bool 
slhdb::erase(const std::string& key)
{
    if (_slmstrsh_sptr->erase(key))
        return true;
    return _slfstrsh_wsptr ? _slfstrsh_wsptr->erase(key) : false;
}
// [1]

// [2]
bool 
slhdb::first(std::string* key, char_sptr* val_buf, size_t* val_len)
{
    if (_slmstr_flag)
    {
        if (_slmstrsh_sptr->first(key, val_buf, val_len))
        {
            _pre_key = *key;
            return true;
        }
        return slfstr_shell_first(key, val_buf, val_len) && ! (_slmstr_flag = false);
    }
    else
    {
        if (slfstr_shell_first(key, val_buf, val_len))
        {
            _pre_key = *key;
            return true;
        }
        _slmstr_flag = true;
    }
    return false;
}

bool 
slhdb::next(std::string* nkey, char_sptr* val_buf, size_t* val_len)
{
    if (_slmstr_flag)
    {
        if (_slmstrsh_sptr->next(_pre_key, nkey, val_buf, val_len))
        {
            _pre_key = *nkey;
            return true;
        }
        // 获取内存数据库的下一个键失败，所以接下来要获取文件数据库的第一个键
        // _slmstr_flag = false 保证获取的是文件数据库的键
        _slmstr_flag = false;
        return first(nkey, val_buf, val_len);
    }
    else
    {
        if (slfstr_shell_next(nkey, val_buf, val_len))
        {
            _pre_key = *nkey;
            return true;
        }
        _slmstr_flag = true;
    }
    return false;
}

size_t 
slhdb::mark_erasure(const std::string& key)
{
    size_t rc = 0;
    if (_slmstr_flag)
        rc = _slmstrsh_sptr->mark_erasure(key);
    else
        rc = slfstr_shell_mark_erasure(key);
    return rc;
}

size_t 
slhdb::erase_marked(void)
{
    size_t rc = 0;
    rc += _slmstrsh_sptr->erase_marked();
    rc += slfstr_shell_erase_marked();
    resume(false);
    return rc;
}

void 
slhdb::sync(void)
{
    _slmstrsh_sptr->sync();
    if (_slfstrsh_wsptr) 
        _slfstrsh_wsptr->sync();
}
// [2]

// [3]
bool 
slhdb::resume(bool flag)
{
    if (! _slfstrsh_wsptr || ! _slfstrsh_bsptr)
        return false;
    if (! (_resume_flag = flag))
    {
        if (_slfstrsh_bsptr)
            _slfstrsh_bsptr->close();
        _slfstrsh_esptr = _slfstrsh_wsptr;
        return true;
    }
    _slfstrsh_wsptr->close();
    std::string err;
    std::string to = _path + "_" + local_second_clock_iso_string();
    bool ren_flag = rename(_path.data(), to.data(), &err);
    if (! ren_flag)
    {
        boost::format info("[error] <resume> rename('%1%', '%2%'): %3%");
        info % _path % to % err;
        std::cout << info.str() << std::endl;
    }
    if (! _slfstrsh_wsptr->open(_path))
        return false;
    if (ren_flag && _slfstrsh_bsptr->open(to))
        _slfstrsh_esptr = _slfstrsh_bsptr;
    else
        _slfstrsh_esptr = _slfstrsh_wsptr;
    return true;
}

bool 
slhdb::resume(const std::string& key, const void* val_buf, size_t val_len)
{
    if (_slmstr_flag || ! _resume_flag)
        return true;
    return _slfstrsh_wsptr ? _slfstrsh_wsptr->insert(key, val_buf, val_len) : false;
}

bool 
slhdb::slfstr_shell_first(std::string* key, char_sptr* val_buf, size_t* val_len)
{
    if (! _slfstrsh_esptr || ! _slfstrsh_esptr->first(&_key_buf, &_key_len))
        return false;
    //_key = *key = _key_buf.get();
    //_pre_key = *key;
    //return _slfstrsh_esptr->fetch(_key.data(), _key.size() + 1, val_buf, val_len);

    _pre_key = *key = _key_buf.get();
    return _slfstrsh_esptr->fetch(_pre_key.data(), _pre_key.size() + 1, val_buf, val_len);
}

bool 
slhdb::slfstr_shell_next(std::string* nkey, char_sptr* val_buf, size_t* val_len)
{
    //if (! _slfstrsh_esptr || ! _slfstrsh_esptr->next(_key.data(), _key.size() + 1, &_key_buf, &_key_len))
    //    return false;
    //_key = *nkey = _key_buf.get();
    //_pre_key = *nkey;
    //return _slfstrsh_esptr->fetch(_key.data(), _key.size() + 1, val_buf, val_len);

    if (! _slfstrsh_esptr || ! _slfstrsh_esptr->next(_pre_key.data(), _pre_key.size() + 1, &_key_buf, &_key_len))
        return false;
    _pre_key = *nkey = _key_buf.get();
    return _slfstrsh_esptr->fetch(_pre_key.data(), _pre_key.size() + 1, val_buf, val_len);
}

size_t 
slhdb::slfstr_shell_mark_erasure(const std::string& key)
{
    //if (key != _key)
    //    return 0;

    if (key != _pre_key)
        return 0;

    return _slfstrsh_esptr ? _slfstrsh_esptr->mark_erasure(_key_buf, _key_len) : 0;
}

size_t 
slhdb::slfstr_shell_erase_marked(void)
{
    return _slfstrsh_esptr ? _slfstrsh_esptr->erase_marked() : 0;
}
// [3]

} // namesapce sldb
} // namespace sqlite

// vim: set tabstop=4 shiftwidth=4 expandtab:
