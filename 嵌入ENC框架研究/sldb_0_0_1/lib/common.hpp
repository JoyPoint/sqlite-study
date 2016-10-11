// liangxx@cndatacom.com

#ifndef LIANGXIAXU_SQLITE_SLDB_COMMON_HPP_20130118
#define LIANGXIAXU_SQLITE_SLDB_COMMON_HPP_20130118

// SLDB COMMON STATEMENT & DEFINITION

// lib3p sqlite3
#include "sqlite3.h"
// lib3p boost
#include "boost/shared_ptr.hpp"

namespace sqlite
{
namespace sldb
{

typedef boost::shared_ptr<char> char_sptr;

// sqlite database mode
#define FDB 0
#define MDB 1

/* optimization level
** synchronous : full - normal - off : bbb
*/
#define FULL   4
#define NORMAL 2
#define OFF    1
/*
** |------|------|
** |-file-|memory|
** |   100|   100|  full   - full
** |   100|   010|  full   - normal
** |   100|   001|  full   - off
** |   010|   100|  normal - full
** |   010|   010|  normal - normal
** |   010|   001|  noraml - off
** |   001|   100|  off    - full
** |   001|   010|  off    - normal
** |   001|   001|  off    - off
** |------|------|
*/
#define LEVEL0 44
#define LEVEL1 42
#define LEVEL2 41
#define LEVEL3 24
#define LEVEL4 22
#define LEVEL5 21
#define LEVEL6 14
#define LEVEL7 12
#define LEVEL8 11

// you can set the level you want ......
#define OPTLEVEL LEVEL8

inline 
int optimize(sqlite3* db, int mode)
{
    switch (OPTLEVEL)
    {
        case LEVEL0:
            sqlite3_exec(db, "pragma synchronous = full;", NULL, NULL, NULL);
            break;
        case LEVEL1:
            if (FDB == mode)
                sqlite3_exec(db, "pragma synchronous = full;", NULL, NULL, NULL);
            else if (MDB == mode)
                sqlite3_exec(db, "pragma synchronous = normal;", NULL, NULL, NULL);
            break;
        case LEVEL2:
            if (FDB == mode)
                sqlite3_exec(db, "pragma synchronous = full;", NULL, NULL, NULL);
            else if (MDB == mode)
                sqlite3_exec(db, "pragma synchronous = off;", NULL, NULL, NULL);
            break;
        case LEVEL3:
            if (FDB == mode)
                sqlite3_exec(db, "pragma synchronous = normal;", NULL, NULL, NULL);
            else if (MDB == mode)
                sqlite3_exec(db, "pragma synchronous = full;", NULL, NULL, NULL);
            break;
        case LEVEL4:
            sqlite3_exec(db, "pragma synchronous = normal;", NULL, NULL, NULL);
            break;
        case LEVEL5:
            if (FDB == mode)
                sqlite3_exec(db, "pragma synchronous = normal;", NULL, NULL, NULL);
            else if (MDB == mode)
                sqlite3_exec(db, "pragma synchronous = off;", NULL, NULL, NULL);
            break;
        case LEVEL6:
            if (FDB == mode)
                sqlite3_exec(db, "pragma synchronous = off;", NULL, NULL, NULL);
            else if (MDB == mode)
                sqlite3_exec(db, "pragma synchronous = full;", NULL, NULL, NULL);
            break;
        case LEVEL7:
            if (FDB == mode)
                sqlite3_exec(db, "pragma synchronous = off;", NULL, NULL, NULL);
            else if (MDB == mode)
                sqlite3_exec(db, "pragma synchronous = normal;", NULL, NULL, NULL);
            break;
        case LEVEL8:
            sqlite3_exec(db, "pragma synchronous = off;", NULL, NULL, NULL);
            break;
        default:
            break;
    }
    return OPTLEVEL;
}

} // namesapce sldb
} // namesapce sqlite

#endif // LIANGXIAXU_SQLITE_SLDB_COMMON_HPP_20130118

// vim: set tabstop=4 shiftwidth=4 expandtab:
