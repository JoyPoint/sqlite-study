//delete_test_mem_cpp

#include <stdio.h>
#include <string>

#include <sqlite3.h>

#include <sys/time.h>

#define TESTTIME 1000000

int main()
{
    //db obj
    sqlite3 *db;
    //stmt obj
    sqlite3_stmt *stmt;
    
    char *sql = "insert into inserttest values(?, ?, ?, ?);";
    char *creat = "create table inserttest(ID integer primary key, NAME text, GOAL real, NOTE text);";
    char *delet = "delete from inserttest where ID = ?;";
    const char *insertnote = "Hello, nice to see you!"; 
    const char *insertname = "myname";

    register int i;
    
    //time
    struct timeval begin;
    struct timeval end;
    long int waste;
    
    int testtime = 20;
    
    int rc;
    
    rc = sqlite3_open(":memory:", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}
    
    sqlite3_prepare(db, creat, strlen(creat), &stmt, 0);
    while (sqlite3_step(stmt) == SQLITE_ROW);
    
    
    for (register int c = 0; c < testtime; c ++)
    {
        rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, 0);
        //---------------------------------------------------------------------
        gettimeofday(&begin, NULL);
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
        }
        gettimeofday(&end, NULL);
        waste = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
        printf("The Waste Of Insert Time Is: %ld s\n", waste);
        //---------------------------------------------------------------------
    
        sqlite3_prepare(db, delet, strlen(delet), &stmt, 0);
        gettimeofday(&begin, NULL);
        for (i = 1; i <= TESTTIME; i ++)
        {
            //bind
            sqlite3_bind_int(stmt, 1, i);
            while (sqlite3_step(stmt) == SQLITE_ROW);
            //reset
            sqlite3_reset(stmt);
        }
        gettimeofday(&end, NULL);
        waste = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
        printf("The Waste Of Delete Time Is: %ld us\n", waste);
    }
    
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    
    
    return 0;
}


/* vim: set tabstop=4 shiftwidth=4 expandtab: */
