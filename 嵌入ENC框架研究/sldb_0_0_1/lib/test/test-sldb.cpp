// liangxx@cndatacom.com
// test-sqlitedb_cpp

#include "lib/sqlitedb.h"
#include "sqlite3.h"
#include <iostream>
#include <string>

int main(void)
{
    // testtable->|-id-|-key-|-name-|
    sqlitedb sqlitedb_("testtable", "key", "name");

    sqlitedb_.open();
    sqlitedb_.table();
    sqlitedb_.fetch();
    sqlitedb_.fetch("1");
    sqlitedb_.insert( "1", "liangxiaxu");
    sqlitedb_.fetch();
    sqlitedb_.replace("1", "LiangXiaxu");
    sqlitedb_.fetch("1");
    sqlitedb_.insert( "2", "hayukleung");
    sqlitedb_.insert( "3", "HayukLeung");
    sqlitedb_.fetch();
    sqlitedb_.fetch("2");
    sqlitedb_.remove( "3");
    sqlitedb_.fetch();

    sqlitedb_.dump();
    sqlitedb_.insert("3", "chinadatacom");

    sqlitedb_.load();
    sqlitedb_.insert("4", "thinkpad");
    sqlitedb_.fetch();
    sqlitedb_.dump();
    return true;
}

// vim: set tabstop=4 shiftwidth=4 expandtab:
