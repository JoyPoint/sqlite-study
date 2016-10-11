//query_test_mem_cpp

#include <stdio.h>
#include <string>

#include <sqlite3.h>
//#include <sqlite3ext.h>

#include <sys/time.h>

#define TESTTIME 1000000

int main()
{
    //db obj
    sqlite3 *db;
    //stmt obj
    sqlite3_stmt *stmt;
    
    char * sql_insert = "insert into inserttest values(?, ?, ?, ?);";
    char * sql_create = "create table inserttest(ID integer primary key, NAME text, GOAL real, NOTE text);";
    char * sql_query = "select NOTE from inserttest where ID = ?;";
    const char * insertnote = "Hello, nice to see you!"; 
    const char * insertname = "myname";

    register int i;
    
    unsigned char * note;
    
    //time
    struct timeval begin;
    struct timeval end;
    long int waste;
    
    int rc;
    
    rc = sqlite3_open(":memory:", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}
    
    //create table
    sqlite3_prepare(db, sql_create, strlen(sql_create), &stmt, 0);
    while (sqlite3_step(stmt) == SQLITE_ROW);

    //insert data
    sqlite3_prepare(db, sql_insert, strlen(sql_insert), &stmt, 0);
    for (i = 1; i <= TESTTIME; i ++)
    {
        //bind
        sqlite3_bind_int(stmt, 1, i);
        sqlite3_bind_text(stmt, 2, insertname, strlen(insertname), SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 3, 2.3);
        sqlite3_bind_text(stmt, 4, insertnote, strlen(insertnote), SQLITE_TRANSIENT);
        
        while (sqlite3_step(stmt) == SQLITE_ROW);
        //reset
        sqlite3_reset(stmt);
    //    printf("Next: %8d\n", i);
    }
    
    
    //---------------------------------------------------------------------
    
    sqlite3_prepare(db, sql_query, strlen(sql_query), &stmt, 0);
    register int count = 21;
    while (-- count)
    {
        gettimeofday(&begin, NULL);
        
        for (i = 1; i <= TESTTIME; i ++)
        {
            if (i % 1000 == 0) {
                //bind
                sqlite3_bind_int(stmt, 1, i);
        
                while (sqlite3_step(stmt) == SQLITE_ROW)
                {
                    note = (unsigned char *)sqlite3_column_text(stmt, 0);
                }
                //reset
                sqlite3_reset(stmt);
            }
        }
        gettimeofday(&end, NULL);

        waste = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
        printf("The Waste Of Time Is:%2d ==== %d us\n", (20 - count), waste);
    }
    
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    
    
    return 0;
}


/* vim: set tabstop=4 shiftwidth=4 expandtab: */
