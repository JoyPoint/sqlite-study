// doitpie@gmail.com

#include "boost/filesystem.hpp"
#include "base.h"
#include "date_time.hpp"

namespace sqlite
{
namespace sldb
{

// [1]
std::string 
dirname(const char* path)
{
    boost::filesystem::path path_(path);
    return path_.parent_path().string();
}

std::string 
basename(const char* path)
{
    boost::filesystem::path path_(path);
    return path_.filename().string();
}
// [1]

// [2]
std::string 
tempname(const std::string& model)
{
    return boost::filesystem::unique_path(model).string();
}

bool 
remove(const char* path, std::string* err)
{
    boost::system::error_code ec;
    boost::filesystem::remove(path,ec);
    if (err)
        *err = ec.message();
    return ! ec.value();
}

bool 
rename(const char* from, const char* to, std::string* err)
{
    boost::system::error_code ec;
    boost::filesystem::rename(from, to, ec);
    if (err)
        *err = ec.message();
    return ! ec.value();
}
// [2]

// [3]
// slice_wait: number * usleep(slice * base);
bool
slice_wait(const bool* flag_ptr0, const bool* flag_ptr1, size_t number, size_t slice, size_t base)
{
    // the addr of var flag_ptrX should not be 0
    if (! flag_ptr0 && ! flag_ptr1)
        return false;
        
    for (size_t n = 0; n < number; ++n)
    {
        if (flag_ptr0 && ! *flag_ptr0)
            return false;
        if (flag_ptr1 && ! *flag_ptr1)
            return false;
        usleep(slice*base);
    }
    return (! flag_ptr0 || *flag_ptr0) && (! flag_ptr1 || *flag_ptr1);
}
// [3]

} // namesapce sldb
} // namespace sqlite

// vim: set tabstop=4 shiftwidth=4 expandtab:
