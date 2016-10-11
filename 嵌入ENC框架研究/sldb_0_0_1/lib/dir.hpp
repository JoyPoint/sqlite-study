// liangxx@cndatacom.com

// 目录管理

#ifndef LIANGXIAXU_SQLITE_SLDB_DIR_HPP_20121225
#define LIANGXIAXU_SQLITE_SLDB_DIR_HPP_20121225

// libstd
#include <list>
#include <iostream>
#include <string>
// libboost
#include "boost/filesystem.hpp"
#include "boost/format.hpp"

namespace sqlite
{
namespace sldb
{

// 递归创建目录
inline void 
create_dir(const char* path)
{
    std::string dir = path;
    if (boost::filesystem::exists(dir.c_str()))
        return;
    std::list<std::string> dir_stack;
    dir_stack.push_front(dir);
    register int i = dir.rfind("/");
    while (i > 0)
    {
        dir = dir.substr(0, i);
        if (boost::filesystem::exists(dir.c_str()))
            break;
        dir_stack.push_front(dir);
        i = dir.rfind("/", i);
    }
    boost::system::error_code ec;
    for (std::list<std::string>::iterator it = dir_stack.begin(); it != dir_stack.end(); it ++)
    {
        if (false == boost::filesystem::create_directory((*it).c_str(), ec))
        {
            boost::format info("[error] <create_dir> create directory `%1%`: Failure: %2%");
            info % (*it).c_str() % boost::system::system_error(ec).what();
            std::cout << info.str() << std::endl;
        }
        else
        {
            boost::format info("[success] <create_dir> create directory `%1%`: success: %2%");
            info % (*it).c_str() % boost::system::system_error(ec).what();
            std::cout << info.str() << std::endl;
        }
    }
}

// 返回文件名
// 输入 "/usr/include/test.h"
// 返回 "test.h"
inline std::string 
get_file_name(const char* path)
{
    boost::filesystem::path path_ = path;
    return path_.filename().string();
}

// 返回路径名
// 输入 "/usr/include/test.h"
// 返回 "/usr/include"
inline std::string 
get_path_name(const char* path)
{
    boost::filesystem::path path_ = path;
    return path_.parent_path().string();
}

} // namesapce sldb
} // namesapce sqlite

#endif // LIANGXIAXU_SQLITE_SLDB_DIR_HPP_20121225

// vim: set tabstop=4 shiftwidth=4 expandtab:
