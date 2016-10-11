//multi_operation.cpp

#include <stdio.h>
#include <string>
#include <sqlite3.h>
#include <sys/time.h>

#define TESTTIME 1000000

int main()
{
    sqlite3 * db;
    sqlite3_stmt * stmt;
    
    char * zErrMsg = 0;
    int rc;
    register int i;
    
    char * sql_insert = "insert into inserttest values(?, ?, ?, ?);";
    
    const char * insertnote = "Hello, nice to see you!"; 
    const char * insertname = "myname";
    
    struct timeval begin;
    struct timeval end;
    long int waste;

    rc = sqlite3_open("./mydb.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}
    
    rc = sqlite3_prepare(db, sql_insert, strlen(sql_insert), &stmt, 0);
    if (rc) {
        fprintf(stderr, "Can't open statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}

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
    //    printf("Inserted: %8d\n", i);
    }
    
    gettimeofday(&end, NULL);
    //---------------------------------------------------------------------
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    waste = end.tv_sec - begin.tv_sec;
    printf("The Waste Of Time Is: %d s\n", waste);
    
    return 0;
}

/* vim: set tabstop=4 shiftwidth=4 expandtab: */
