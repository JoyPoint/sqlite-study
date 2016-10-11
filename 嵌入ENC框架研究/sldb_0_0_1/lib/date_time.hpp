// doitpie@gmail.com

#ifndef JINJIAN_SQLITE_SLDB_DATE_TIME_HPP_20111113
#define JINJIAN_SQLITE_SLDB_DATE_TIME_HPP_20111113

#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/thread/thread.hpp"

namespace sqlite
{
namespace sldb
{

inline void msleep(long ms) { boost::this_thread::sleep(boost::posix_time::milliseconds(ms)); }
inline void usleep(long us) { boost::this_thread::sleep(boost::posix_time::microseconds(us)); }
inline void ssleep(long ss) { boost::this_thread::sleep(boost::posix_time::seconds(ss));      }

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
    return boost::posix_time::to_simple_string(boost::posix_time::from_time_t(t+seconds));
}

inline boost::posix_time::time_duration
time_of_day(time_t t, size_t seconds = 8*3600)
{
    return boost::posix_time::from_time_t(t+seconds).time_of_day();
}

} // namesapce sldb
} // namespace sqlite

#endif // JINJIAN_SQLITE_SLDB_DATE_TIME_HPP_20111113

// vim: set tabstop=4 shiftwidth=4 expandtab:
