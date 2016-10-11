// doitpie@gmail.com

#ifndef JINJIAN_SQLITE_SLDB_BASE_H_20111024
#define JINJIAN_SQLITE_SLDB_BASE_H_20111024

#include <string>
#include <fstream>

namespace sqlite
{
namespace sldb
{

// dirname/basename
std::string dirname(const char* path);
std::string basename(const char* path);
// as if tempnam
std::string tempname(const std::string& model = "%%%%_%%%%_%%%%_%%%%");
// remove/rename
bool remove(const char* path, std::string* err = NULL);
bool rename(const char* from, const char* to, std::string* err = NULL);

#define ENC_BASE_KILO (1000)
#define ENC_BASE_MEGA (1000000L)
// slice_wait: number * usleep(slice * base);
bool slice_wait(const bool* flag_ptr0, const bool* flag_ptr1, size_t number, size_t slice, size_t base);

// number suffix
template<typename N>
inline std::string num_suff(N n)
{
    switch(n)
    {
    case 1: return "st";
    case 2: return "nd";
    case 3: return "rd";
    }
    return "th";
}

// touch file
inline void touch(const char* filename) { std::ofstream ofs(filename,std::ios::app); }

} // namesapce sldb
} // namespace sqlite

#endif // JINJIAN_SQLITE_SLDB_BASE_H_20111024

// vim: set tabstop=4 shiftwidth=4 expandtab:
