// liangxx@cndatacom.com

#ifndef LIANGXIAXU_SQLITE_SLDB_BASE_H_20111024
#define LIANGXIAXU_SQLITE_SLDB_BASE_H_20111024

// Base Module for [TIME] \ [DIRECTORY] Management

// libstd
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
// libboost
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/static_assert.hpp"
#include "boost/thread/thread.hpp"
#include "boost/noncopyable.hpp"
#include "boost/filesystem.hpp"
#include "boost/progress.hpp"
#include "boost/format.hpp"

namespace sqlite
{
namespace sldb
{

// ================================================ time sleep ================================================
inline void 
ssleep(long ss)
{
    boost::this_thread::sleep(boost::posix_time::seconds(ss));
}

inline void 
msleep(long ms)
{
    boost::this_thread::sleep(boost::posix_time::milliseconds(ms));
}

inline void 
usleep(long us) 
{
    boost::this_thread::sleep(boost::posix_time::microseconds(us));
}

// ================================================ time string ================================================
inline std::string 
local_second_clock_simple_string(void)
{
    return boost::posix_time::to_simple_string(boost::posix_time::second_clock::local_time());
}

inline std::string 
local_microsec_clock_simple_string(void)
{
    return boost::posix_time::to_simple_string(boost::posix_time::microsec_clock::local_time());
}

inline std::string 
local_second_clock_iso_string(void)
{
    return boost::posix_time::to_iso_string(boost::posix_time::second_clock::local_time());
}

inline std::string 
local_microsec_clock_iso_string(void)
{
    return boost::posix_time::to_iso_string(boost::posix_time::microsec_clock::local_time());
}

inline std::string 
to_simple_string(time_t t, size_t seconds = 8 * 3600)
{
    return boost::posix_time::to_simple_string(boost::posix_time::from_time_t(t + seconds));
}

inline boost::posix_time::time_duration 
time_of_day(time_t t, size_t seconds = 8 * 3600)
{
    return boost::posix_time::from_time_t(t + seconds).time_of_day();
}

// ================================================ time counter ================================================
// <<boost chengxuku wanquan kaifa zhinan>>
// N is the precision
template<int N = 2 >
class new_progress_timer : public boost::timer
{
public:
    new_progress_timer(std::ostream& os = std::cout)
        : m_os(os)
    {
        // static assert
        BOOST_STATIC_ASSERT(N >= 0 && N <= 10);
    }
    ~new_progress_timer(void)
    {
        try
        {
            // keep stream status
            std::istream::fmtflags old_flags = m_os.setf(std::istream::fixed, std::istream::floatfield);
            std::streamsize old_prec = m_os.precision(N);

            // output time
            m_os << elapsed() << " sec\n" << std::endl;

            // resume stream status
            m_os.flags(old_flags);
            m_os.precision(old_prec);
        }
        catch (...) {} // destructor function shall not throw any exceptions ......
    }
private:
    std::ostream& m_os;
};

// time counter by gettimeofday()
class watch : private boost::noncopyable
{
public:
    watch(void)
    {
        gettimeofday(&_head, NULL);
    }
    ~watch(void)
    {
        gettimeofday(&_tail, NULL);
        //long ut = (_tail.tv_sec - _head.tv_sec) * 1000000 + (_tail.tv_usec - _head.tv_usec);
        long mt = (_tail.tv_sec - _head.tv_sec) * 1000 + (_tail.tv_usec - _head.tv_usec) / 1000;
        //long st = (_tail.tv_sec - _head.tv_sec) + (_tail.tv_usec - _head.tv_usec) / 1000000;
        //std::cout << ut << " us" << std::endl;
        std::cout << mt << " ms" << std::endl;
        //std::cout << st << " s"  << std::endl;
    }
private:
    struct timeval _head;
    struct timeval _tail;
};

// ================================================ directory management ================================================
// dirname/basename
inline std::string 
dirname(const char* path)
{
    boost::filesystem::path path_(path);
    return path_.parent_path().string();
}

inline std::string 
basename(const char* path)
{
    boost::filesystem::path path_(path);
    return path_.filename().string();
}

// temp name
inline std::string 
tempname(const std::string& model = "%%%%_%%%%_%%%%_%%%%")
{
    return boost::filesystem::unique_path(model).string();
}

// remove/rename
inline bool 
remove(const char* path, std::string* err = NULL)
{
    boost::system::error_code ec;
    boost::filesystem::remove(path,ec);
    if (err)
        *err = ec.message();
    return ! ec.value();
}

inline bool 
rename(const char* from, const char* to, std::string* err = NULL)
{
    boost::system::error_code ec;
    boost::filesystem::rename(from, to, ec);
    if (err)
        *err = ec.message();
    return ! ec.value();
}

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

#define ENC_BASE_KILO (1000)
#define ENC_BASE_MEGA (1000000L)
// slice_wait: number * usleep(slice * base);
inline bool 
slice_wait(const bool* flag_ptr0, const bool* flag_ptr1, size_t number, size_t slice, size_t base)
{
    // the addr of var flag_ptrX should not be 0
    if (! flag_ptr0 && ! flag_ptr1)
        return false;
    for (size_t n = 0; n < number; ++ n)
    {
        if (flag_ptr0 && ! *flag_ptr0)
            return false;
        if (flag_ptr1 && ! *flag_ptr1)
            return false;
        usleep(slice * base);
    }
    return (! flag_ptr0 || *flag_ptr0) && (! flag_ptr1 || *flag_ptr1);
}

// number suffix
template<typename N> 
inline std::string 
num_suff(N n)
{
    switch(n)
    {
        case 1:  return "st";
        case 2:  return "nd";
        case 3:  return "rd";
        default: return "th";
    }
}

// touch file
inline void 
touch(const char* filename)
{
    std::ofstream ofs(filename, std::ios::app);
}

} // namesapce sldb
} // namespace sqlite

#endif // LIANGXIAXU_SQLITE_SLDB_BASE_H_20111024

// vim: set tabstop=4 shiftwidth=4 expandtab:
