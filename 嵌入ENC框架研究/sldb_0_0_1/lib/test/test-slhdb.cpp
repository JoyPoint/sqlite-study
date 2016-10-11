// doitpie@gmail.com

// libstd
#include <iostream>
// lib3p_boost
#include "boost/lexical_cast.hpp"
// lib
#include "lib/slhdb.h"

int main(void)
{
    using namespace sqlite::sldb;

    register int i = 0;
    register int j = 0;

    char_sptr val_sptr;
    size_t    val_size;

#if 0
    // pure memory database with size 30
    slhdb slhdb_pure(30, "test-slhdb-pure", NULL, NULL);


    for (i = 0; i < 100; i ++)
    {
        val_size = sizeof(int);
        // fetch: if not exist, insert it
        int rs = slhdb_pure.fetch(boost::lexical_cast<std::string>(i), &val_sptr, &val_size);
        int* pi = reinterpret_cast<int*>(val_sptr.get());
        if (rs)
        { // exist, replace it with (*pi+1)
            ++ *pi;
            slhdb_pure.replace(boost::lexical_cast<std::string>(i), val_sptr.get(), val_size);
        }
        else
        { // not exist, insert it
            *pi = i;
            slhdb_pure.insert(boost::lexical_cast<std::string>(i), val_sptr.get(), val_size);
        }
    }
    slhdb_pure.sync();
#endif

#if 1
    // hybrid database
    slhdb slhdb_(0, "test-slhdb", new slfdb_shell, new slfdb_shell);
    slhdb_.open();
    j = 0;

    for (i = 0; i < 100; i ++)
    {
        if (slhdb_.fetch(boost::lexical_cast<std::string>(i), &val_sptr, &val_size))
        {// 获取到键
            if (val_size)
            {// 值存在
                int* p = reinterpret_cast<int*>(val_sptr.get());
                std::cout << "fetch\t" << i << " => " << *p << std::endl;
            }
            else
            {// 值不存在
                int tmp = i + 1;
                int* p = &tmp;
                val_size = sizeof(int);
                slhdb_.replace(boost::lexical_cast<std::string>(i), p, val_size);
                std::cout << "replace\t" << i << " => " << *p << std::endl;
            }
        }
        else
        {// 键不存在
            int tmp = i;
            int* p = &tmp;
            val_size = sizeof(int);
            slhdb_.insert(boost::lexical_cast<std::string>(i), p, val_size);
            std::cout << "insert\t" << i << " => " << *p << std::endl;
        }
    }
#endif

#if 1
    std::string key;
    slhdb_.resume(true);
#endif

#if 1
    j = 0;
    if (slhdb_.first(&key, &val_sptr, &val_size))
    {
        do
        {
            int* pi = reinterpret_cast<int*>(val_sptr.get());
            if (*pi % 2 == 0)
            {
                slhdb_.mark_erasure(key);
                std::cout << "mark_erasure\t" << key << " => " << *pi << std::endl;
            }
            else
            {
                slhdb_.resume(key, val_sptr.get(), val_size);
                std::cout << "resume\t\t" << key << " => " << *pi << std::endl;
            }
        } while (slhdb_.next(&key, &val_sptr, &val_size));
    }
    slhdb_.erase_marked();
//    j = 0;
//    if (slhdb_.first(&key, &val_sptr, &val_size))
//    {
//        do
//        {
//            int* pi = reinterpret_cast<int*>(val_sptr.get());
//            std::cout << "new " << ++ j << ": "  << key << " => " << *pi << std::endl;
//        } while (slhdb_.next(&key, &val_sptr, &val_size));
//    }
#endif

    return 0;
}

// vim: set tabstop=4 shiftwidth=4 expandtab:
