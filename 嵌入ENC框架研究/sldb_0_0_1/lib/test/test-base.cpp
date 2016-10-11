// liangxx@cndatacom.com

// libstd
#include <iostream>
#include <string>
// lib
#include "lib/base.hpp"

int main(void)
{
    using namespace sqlite::sldb;
    char* p1 = "/data2/liangxx/sqlite/test/p1";
    sqlite::sldb::create_dir(p1);
    char* p2 = "/data2/liangxx/sqlite/test/p2/p2.txt";
    std::cout << get_file_name(p2) << std::endl;
    std::cout << get_path_name(p2) << std::endl;
    return 0;
}

// vim: set tabstop=4 shiftwidth=4 expandtab:
