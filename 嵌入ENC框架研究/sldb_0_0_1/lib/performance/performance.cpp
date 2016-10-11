// liangxx@cndatacom.com

// libstd
#include <iostream>
#include <stdlib.h>
// lib3p_boost
#include "boost/lexical_cast.hpp"
#include "boost/progress.hpp"
// lib
#include "lib/slhdb.h"
#include "lib/base.hpp"

int main(int argc, char* argv[])
{
    using namespace sqlite::sldb;

    unsigned int CAPCITY;
    unsigned int RECORDS;

    if (argc != 2)
    {
        std::cout << "usage : ./bin/performance <RecordsNumber>" << std::endl;
        return -1;
    }
    else
    {
        // memory capcity N*100
        CAPCITY = atoi(argv[1]);
        // numbers of records N*100
        RECORDS = CAPCITY;
    }

    // global varible
    register unsigned int i = 0;

    // for fetch
    char_sptr dat_sptr;
    size_t dat_size;

    // for insert
    size_t val_size = sizeof(char) * 256;
    char* val = (char*)malloc(val_size);
    memcpy(val, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890", 26 + 26 + 10 + 1);
    std::string key;

#if 1
    {
        std::cout << "\n===================================================";
        std::cout << "\n========== PureMemoryDataBasePerformance ==========";
        std::cout << "\n===================================================" << std::endl;
        slhdb slhdb_memory_(CAPCITY, "memory", NULL, NULL);
        slhdb_memory_.open();
        // insert =========================================================================
        {
            boost::progress_display progress(100);
            watch timer;
            
            for (i = 0; i < RECORDS; i ++)
            {
                key = boost::lexical_cast<std::string>(i);
                switch (key.length())
                {
                    case 11 :                           break;
                    case 10 : key = "0"          + key; break;
                    case  9 : key = "00"         + key; break;
                    case  8 : key = "000"        + key; break;
                    case  7 : key = "0000"       + key; break;
                    case  6 : key = "00000"      + key; break;
                    case  5 : key = "000000"     + key; break;
                    case  4 : key = "0000000"    + key; break;
                    case  3 : key = "00000000"   + key; break;
                    case  2 : key = "000000000"  + key; break;
                    case  1 : key = "0000000000" + key; break;
                    default:  return -1;
                }

                slhdb_memory_.insert(key, val, val_size);
                if ((i % (RECORDS / 100) == 0))
                    ++ progress;
            }
        }
        // iterator =======================================================================
        {
            watch timer;

            slhdb_memory_.resume(true);

            if (slhdb_memory_.first(&key, &dat_sptr, &dat_size))
            {
                do
                {
                    //for (register int j = 0; j < 256; j ++)
                    //    std::cout << dat_sptr.get()[j] << " ";
                    //std::cout << std::endl;
                    slhdb_memory_.mark_erasure(key);
                } while (slhdb_memory_.next(&key, &dat_sptr, &dat_size));
            }
            slhdb_memory_.erase_marked();
        }
    }
#endif

#if 1
    {
        std::cout << "\n===================================================";
        std::cout << "\n=========== PureFileDataBasePerformance ===========";
        std::cout << "\n===================================================" << std::endl;
        slhdb slhdb_file_(0, "file", new slfdb_shell, new slfdb_shell);
        slhdb_file_.open();
        // insert =========================================================================
        {
            boost::progress_display progress(100);
            watch timer;

            for (i = 0; i < RECORDS; i ++)
            {
                key = boost::lexical_cast<std::string>(i);
                switch (key.length())
                {
                    case 11 :                           break;
                    case 10 : key = "0"          + key; break;
                    case  9 : key = "00"         + key; break;
                    case  8 : key = "000"        + key; break;
                    case  7 : key = "0000"       + key; break;
                    case  6 : key = "00000"      + key; break;
                    case  5 : key = "000000"     + key; break;
                    case  4 : key = "0000000"    + key; break;
                    case  3 : key = "00000000"   + key; break;
                    case  2 : key = "000000000"  + key; break;
                    case  1 : key = "0000000000" + key; break;
                    default:  return -1;
                }

                slhdb_file_.insert(key, val, val_size);
                if ((i % (RECORDS / 100) == 0))
                    ++ progress;
            }
        }
        // iterator =======================================================================
        {
            watch timer;

            slhdb_file_.resume(true);
            if (slhdb_file_.first(&key, &dat_sptr, &dat_size))
            {
                do
                {
                    //for (register int j = 0; j < 256; j ++)
                    //    std::cout << dat_sptr.get()[j] << " ";
                    //std::cout << std::endl;
                    slhdb_file_.mark_erasure(key);
                } while (slhdb_file_.next(&key, &dat_sptr, &dat_size));
            }
            slhdb_file_.erase_marked();
        }
    }
#endif

#if 1
    {
        std::cout << "\n===================================================";
        std::cout << "\n============ HybridDataBasePerformance ============";
        std::cout << "\n===================================================" << std::endl;
        slhdb slhdb_hybrid_(CAPCITY / 2, "hybrid", new slfdb_shell, new slfdb_shell);
        slhdb_hybrid_.open();
        // insert =========================================================================
        {
            boost::progress_display progress(100);
            watch timer;

            for (i = 0; i < RECORDS; i ++)
            {
                key = boost::lexical_cast<std::string>(i);
                switch (key.length())
                {
                    case 11 :                           break;
                    case 10 : key = "0"          + key; break;
                    case  9 : key = "00"         + key; break;
                    case  8 : key = "000"        + key; break;
                    case  7 : key = "0000"       + key; break;
                    case  6 : key = "00000"      + key; break;
                    case  5 : key = "000000"     + key; break;
                    case  4 : key = "0000000"    + key; break;
                    case  3 : key = "00000000"   + key; break;
                    case  2 : key = "000000000"  + key; break;
                    case  1 : key = "0000000000" + key; break;
                    default:  return -1;
                }

                slhdb_hybrid_.insert(key, val, val_size);
                if ((i % (RECORDS / 100) == 0))
                    ++ progress;
            }
        }
        // iterator =======================================================================
        {
            watch timer;

            slhdb_hybrid_.resume(true);

            if (slhdb_hybrid_.first(&key, &dat_sptr, &dat_size))
            {
                do
                {
                    //for (register int j = 0; j < 256; j ++)
                    //    std::cout << dat_sptr.get()[j] << " ";
                    //std::cout << std::endl;
                    slhdb_hybrid_.mark_erasure(key);
                } while (slhdb_hybrid_.next(&key, &dat_sptr, &dat_size));
            }
            slhdb_hybrid_.erase_marked();
        }
    }
#endif

    return 0;
}

// vim: set tabstop=4 shiftwidth=4 expandtab:
