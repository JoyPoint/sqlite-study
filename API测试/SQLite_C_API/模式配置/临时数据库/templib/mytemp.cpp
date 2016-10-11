//mytemp_cpp
#include "mytemp.h"

#include <iostream>
#include <string>
#include <sys/time.h>

#include <boost/progress.hpp>

int main()
{
    sqlite3 *db;
    sqlite3_stmt *stmt;
    
    char *zErrMsg = 0;
    int rc;
    
    //sql
    char * sql_drop   = "drop table test;";
    char * sql_create = "create table test(ID integer primary key, \
                         NAME text, GOAL real, NOTE text);";
    char * sql_insert = "insert into test values(?, ?, ?, ?);";
    char * sql_query  = "select * from test where ID = 100;";
    
    //data seg
    int id;
    const char * name = "myname";
    float goal;
    const char * note = "Hello SQLite, nice to see you!";
    
    //get info
    int qid;
    unsigned char * qname;
    float qgoal;
    unsigned char * qnote;
    
    //recycle
    register int cyc;
    
    //time
    struct timeval begin;
    struct timeval end;
    struct timeval mid;
    long int waste;
    
    
    //open a temp db
    //rc = sqlite3_open(":memory:", &db);//memory
    rc = sqlite3_open("", &db);//temp
    //rc = sqlite3_open("mytemp.db", &db);//file
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
    
    //drop table test
    rc = sqlite3_prepare(db, sql_drop, strlen(sql_drop), &stmt, 0);
    rc = sqlite3_step(stmt);
    if (rc == SQLITE_DONE)
    {
        std::cout << "An old table test dropped." << std::endl;
    }
    sqlite3_finalize(stmt);
    
    
    //create a test table
    rc = sqlite3_prepare(db, sql_create, strlen(sql_create), &stmt, 0);
    if (rc)
    {
        fprintf(stderr, "Can't open statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        std::cout << "Error to create table." << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        
        return 1;
    }
    sqlite3_finalize(stmt);
    
    //time info
    //boost::progress_display d(100);
    //boost::progress_timer t;
    
    //insert test
    rc = sqlite3_prepare(db, sql_insert, strlen(sql_insert), &stmt, 0);
    if (rc)
    {
        fprintf(stderr, "Can't open statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    gettimeofday(&begin, NULL);
    for (cyc = 1; cyc < TESTTIME + 1; cyc ++)
    {
        sqlite3_bind_int(stmt, 1, cyc);
        sqlite3_bind_text(stmt, 2, name, strlen(name), SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 3, 4.0);
        sqlite3_bind_text(stmt, 4, note, strlen(note), SQLITE_TRANSIENT);
        
        
        
        //while (sqlite3_step(stmt) == SQLITE_ROW);
        
        
        
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE)
        {
            std::cout << "Error to insert table :" << cyc << std::endl;
            sqlite3_finalize(stmt);
            sqlite3_close(db);
        
            return 1;
        }
        else if (cyc % 100000 == 0)
        {
            gettimeofday(&mid, NULL);
            waste = (mid.tv_sec - begin.tv_sec) * 1000000 + (mid.tv_usec - begin.tv_usec);
            std::cout << "Time Passed: " << waste / 1000000 << " sec." << std::endl;
            
            std::cout << "Inserted :" << cyc << std::endl;
        }
        
        sqlite3_reset(stmt);
        
        //if (cyc % (TESTTIME / 100) == 0)
        //    ++ d;
    }
    gettimeofday(&end, NULL);
    sqlite3_finalize(stmt);
    
    
    //query
    rc = sqlite3_prepare(db, sql_query, strlen(sql_query), &stmt, 0);
    if (rc)
    {
        fprintf(stderr, "Can't open statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_ROW)
    {
        std::cout << "Error to query." << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        
        return 1;
    }
    qid   =                  sqlite3_column_int   (stmt, 0);
    qname = (unsigned char *)sqlite3_column_text  (stmt, 1);
    qgoal =                  sqlite3_column_double(stmt, 2);
    qnote = (unsigned char *)sqlite3_column_text  (stmt, 3);
    std::cout << qid << qname << qgoal << qnote << std::endl;
    sqlite3_finalize(stmt);
    
    
    
    sqlite3_close(db);
    std::cout << std::endl;
    waste = (end.tv_sec - begin.tv_sec) * 1000000 + (end.tv_usec - begin.tv_usec);
    printf("the time is :%ld us\n", waste);
    std::cout << std::endl;
    
    return 0;
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

static sqlite3 *db;

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i ++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");

    return 0;
}

sqlite3 *db_connect(char *db_name)
{
    int rc;
    rc = sqlite3_open(db_name, &db);

    return db;
}

int db_exec_stmt(char *sql)
{
    int rc;
    char *zErrMsg = 0;
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
        exit(1);
    }
    
    return 0;
}

void db_exec()
{
    char *sql = "insert into user_info (id, user_name) values(?,?)";
    sqlite3_stmt *stmt;
    const char *tail;
    int i;
    int ncols;
    int rc; 
    char *name = "xiaoliang";

    rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "sql error:%s\n", sqlite3_errmsg(db));
    }
    
    sqlite3_bind_int(stmt, 1, 20);
    sqlite3_bind_text(stmt, 2, name, strlen(name), SQLITE_STATIC);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

}

int main(int argc, char **argv)
{
    char *db_name = "test.db";

    db = db_connect(db_name);
    // rc = db_exec_stmt(sql);
    db_exec();

    sqlite3_close(db);
    
    return 0;
}
*/

}
/* vim: set tabstop=4 shiftwidth=4 expandtab: */
