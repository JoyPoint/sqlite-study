//delete_test.cpp
#include <stdio.h>
#include <string>
#include <sqlite3.h>
#include <sys/time.h>

#include <boost/progress.hpp>

int main()
{
    sqlite3 * db;
    sqlite3_stmt * stmt;
    
    //boost::progress_display d(100);
    
    
    char * zErrMsg = 0;
    int rc;
    
    char * sql_create = "create table inserttest(ID integer primary key, NAME text, GOAL real, NOTE text);";
    char * sql_insert = "insert into inserttest values(?, ?, ?, ?);";
    char * sql_delete = "delete from inserttest where ID = ?;";
    
    const char *insertnote = "Hello, nice to see you!"; 
    const char *insertname = "myname";
    
    
    int id;
    unsigned char *name;
    int goal;
    int insertline = 1000000;
    int i;
    
    struct timeval begin;
    struct timeval end;
    long int waste_insert;
    long int waste_delete;
    
    
    rc = sqlite3_open("./mydb.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}
    
    
    //insert
    sqlite3_prepare(db, sql_insert, strlen(sql_insert), &stmt, 0);
    gettimeofday(&begin, NULL);
    for (i = 1; i <= insertline; i ++)
    {
        //if (i % 20000 == 0)
        //    ++ d;
        sqlite3_bind_int(stmt, 1, i);
        sqlite3_bind_text(stmt, 2, insertname, strlen(insertname), SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 3, 2.3);
        sqlite3_bind_text(stmt, 4, insertnote, strlen(insertnote), SQLITE_TRANSIENT);
        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }
    gettimeofday(&end, NULL);
    waste_insert = (end.tv_sec - begin.tv_sec) * 1000 + (end.tv_usec - begin.tv_usec) / 1000;
    
    sqlite3_finalize(stmt);
    
    //delete
    sqlite3_prepare(db, sql_delete, strlen(sql_delete), &stmt, 0);
    //---------------------------------------------------------------------
    gettimeofday(&begin, NULL);
    for (i = 1; i <= insertline; i ++)
    {
        //if (i % 20000 == 0)
        //    ++ d;
        sqlite3_bind_int(stmt, 1, i);
        sqlite3_step(stmt);
        sqlite3_reset(stmt);
    }
    gettimeofday(&end, NULL);
    waste_delete = (end.tv_sec - begin.tv_sec) * 1000 + (end.tv_usec - begin.tv_usec) / 1000;
        
        
    //---------------------------------------------------------------------
    
    printf("the time insert is :%ld ms\n", waste_insert);
    printf("the time delete is :%ld ms\n", waste_delete);
    
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return 0;
}
/* vim: set tabstop=4 shiftwidth=4 expandtab: */
