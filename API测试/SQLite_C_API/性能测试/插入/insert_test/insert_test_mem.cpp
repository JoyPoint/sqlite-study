//insert_test_mem_cpp

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
    
    char * sql_insert = "insert into inserttest values(?, ?, ?, ?);";
    char * sql_create = "create table inserttest(ID integer primary key, \
                        NAME text, GOAL real, NOTE text);";
    char * sql_query = "select NAME from inserttest where ID = 251314;";
                        
    const char *insertnote = "Hello, nice to see you!"; 
    const char *insertname = "myname";

    register int i;
    
    int id;
    unsigned char * name;
    double goal;
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
    sqlite3_finalize(stmt);
    
    //insert
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
        
        sqlite3_step(stmt);
        //reset
        sqlite3_reset(stmt);
    //    printf("Inserted: %8d\n", i);
    }
    
    gettimeofday(&end, NULL);
    sqlite3_finalize(stmt);
    //---------------------------------------------------------------------
    
    //query
    sqlite3_prepare(db, sql_query, strlen(sql_query), &stmt, 0);
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        //id = sqlite3_column_int(stmt, 0);
        name = (unsigned char *)sqlite3_column_text(stmt, 0);
        //goal = sqlite3_column_double(stmt, 2);
        //note = (unsigned char *)sqlite3_column_text(stmt, 3);
        //printf("%d %s %f %s\n", id, name, goal, note);
        printf("%s\n", name);
    }
    sqlite3_finalize(stmt);
    
   
    sqlite3_close(db);
    
    waste = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
    printf("The Waste Of Time Is: %ld us\n", waste);
    
    return 0;
}


/* vim: set tabstop=4 shiftwidth=4 expandtab: */
