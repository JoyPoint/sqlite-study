// liangxx@cndatacom.com

// lib3p_sqlite3
#include "sqlite3.h"
// lib3p_boost
#include "boost/lexical_cast.hpp"
#include "boost/format.hpp"
// libstd
#include <iostream>
#include <string>
#include <string.h>
#include <time.h>
#include <unistd.h>
// lib
#include "lib/slfdb_shell.h"

// global
const int T = 10;

int main(void)
{
    using namespace sqlite::sldb;
    slfdb_shell slfdb_shell_;
    // open ===============================================================================
    slfdb_shell_.open("./slfdb.db");

    // insert =============================================================================
    std::cout << "Test insert ..." << std::endl;
    std::cout << "-- before insert" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << "\n" << std::endl;

    // insert c_string
    for (register int i = 0; i < T; i ++)
    {
        boost::format key_fmt("%1%");
        key_fmt % i;
        boost::format val_fmt("%1%");
        val_fmt % std::time(NULL);

        // len = strlen + 1
        slfdb_shell_.insert(key_fmt.str().c_str(), key_fmt.str().length() + 1, val_fmt.str().c_str(), val_fmt.str().length() + 1);
    }

    // insert numeric
    for (register int i = T; i < 2 * T; i ++)
    {
        int key_buf = i;
        time_t val_buf = std::time(NULL);

        // len = memlen
        slfdb_shell_.insert(&key_buf, sizeof(int), &val_buf, sizeof(time_t));
    }

    std::cout << "-- after insert" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << std::endl;
    std::cout << "\n" << std::endl;

    // replace ============================================================================
    std::cout << "Test replace ..." << std::endl;
    std::cout << "-- before replace" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << "\n" << std::endl;

    // replace c_string
    for (register int i = 0; i < T; i ++)
    {
        boost::format key_fmt("%1%");
        key_fmt % i;
        boost::format val_fmt("%1%");
        val_fmt % "cndatacom";

        // len = strlen + 1
        slfdb_shell_.replace(key_fmt.str().c_str(), key_fmt.str().length() + 1, val_fmt.str().c_str(), val_fmt.str().length() + 1);
    }

    std::cout << "-- after replace" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << std::endl;
    std::cout << "\n" << std::endl;

    // fetch ==============================================================================
    std::cout << "Test fetch ..." << std::endl;
    std::cout << "-- before fetch" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << "\n" << std::endl;

    for (register int i = 0; i < T; i ++)
    {
        boost::format key_fmt("%1%");
        key_fmt % i;
        char_sptr val_buf;
        size_t val_len;

        // len = strlen + 1
        if (slfdb_shell_.fetch(key_fmt.str().c_str(), key_fmt.str().length() + 1, &val_buf, &val_len) && (val_len != 0))
        {
            std::cout << "-- key: " << key_fmt.str().c_str()    << std::endl;
            std::cout << "-- val: " << val_buf.get()            << std::endl;
            std::cout << "-- len: " << val_len << "\n"          << std::endl;
        }
        else
        {
            std::cout << "fetch nothing ..." << std::endl;
        }
    }

    for (register int i = T; i < 2 * T; i ++)
    {
        int key_buf = i;
        size_t key_len = sizeof(int);
        char_sptr val_buf;
        size_t val_len;

        // len = memlen
        if (slfdb_shell_.fetch(&key_buf, key_len, &val_buf, &val_len) && (val_len != 0))
        {
            time_t* tmp = reinterpret_cast<time_t*>(val_buf.get());
            std::cout << "-- key: " << key_buf          << std::endl;
            std::cout << "-- val: " << *tmp             << std::endl;
            std::cout << "-- len: " << val_len << "\n"  << std::endl;
        }
        else
        {
            std::cout << "fetch nothing ..." << std::endl;
        }
    }

    std::cout << "-- after fetch" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << std::endl;
    std::cout << "\n" << std::endl;

    // first - next - mark_erasure - erase_marked =======================================
    std::cout << "Test first & next & mark_erasure & erase_marked ..." << std::endl;
    std::cout << "-- before traverse" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << "\n" << std::endl;

    char_sptr val_sptr;
    size_t val_size;
    char_sptr key_sptr;
    size_t key_size;
    char_sptr nkey_sptr;
    size_t nkey_size;
#if 1
    if (slfdb_shell_.first(&key_sptr, &key_size))
    {
        register int i = 0;
        nkey_sptr = key_sptr;
        nkey_size = key_size;
        do
        {
            key_sptr = nkey_sptr;
            key_size = nkey_size;
            slfdb_shell_.fetch((void*)(key_sptr.get()), key_size, &val_sptr, &val_size);
            char* tmp = reinterpret_cast<char*>(val_sptr.get());
            std::cout << ++ i << "\t:" << key_sptr.get() << "\t=> " << tmp << std::endl;
            slfdb_shell_.mark_erasure(key_sptr, key_size);
        } while (slfdb_shell_.next(key_sptr.get(), key_size, &nkey_sptr, &nkey_size) && (i < T));
        slfdb_shell_.erase_marked();
    }
#endif
#if 1
    if (slfdb_shell_.first(&key_sptr, &key_size))
    {
        register int i = T;
        nkey_sptr = key_sptr;
        nkey_size = key_size;
        do
        {
            key_sptr = nkey_sptr;
            key_size = nkey_size;
            slfdb_shell_.fetch((void*)(key_sptr.get()), key_size, &val_sptr, &val_size);
            int* tmpkey = reinterpret_cast<int*>(key_sptr.get());
            time_t* tmp = reinterpret_cast<time_t*>(val_sptr.get());
            std::cout << ++ i << "\t:" << *tmpkey << "\t=> " << *tmp << std::endl;
            slfdb_shell_.mark_erasure(key_sptr, key_size);
        } while (slfdb_shell_.next(key_sptr.get(), key_size, &nkey_sptr, &nkey_size));
        slfdb_shell_.erase_marked();
    }
#endif

    std::cout << "-- after traverse" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << "\n" << std::endl;
    std::cout << "\n" << std::endl;

#if 0
    // sync ===============================================================================
    std::cout << "Test sync ..." << std::endl;
    std::cout << "-- before sync" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << "\n" << std::endl;

    slfdb_shell_.sync();
    std::cout << "-- after sync" << std::endl;
    std::cout << "-- size: " << slfdb_shell_.size() << std::endl;
    std::cout << "\n" << std::endl;
#endif
    // close ==============================================================================
    slfdb_shell_.close();
    return true;
}

// vim: set tabstop=4 shiftwidth=4 expandtab:
