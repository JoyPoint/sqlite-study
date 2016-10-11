//test-unencapsulated_cpp
#include "libunencapsulated.h"

int main()
{
    std::string dbname("./mydb.db");
    std::string sql("insert into courses values(7, 'снс╬', 5);");
    //std::string sql("select * from courses;");
    
    dbProc(dbname, sql);
    
    return 0;
}
// vim: set tabstop=4 shiftwidth=4 expandtab: 
