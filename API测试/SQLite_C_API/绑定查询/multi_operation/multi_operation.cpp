//multi_operation.cpp


#include <stdio.h>
#include <string>
#include <sqlite3.h>
#include <sys/time.h>

int main()
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char sql[] = "insert into inserttest values(?, ?, ?, ?);";
    
    const char *insertnote = "Hello, nice to see you!"; 
    const char *insertname = "myname";
    
    sqlite3_stmt *stmt;
    int id;
    unsigned char *name;
    int goal;
    int insertline = 100000;
    int i;
    
    struct timeval begin;
    struct timeval end;
    long int waste;
    
    
    rc = sqlite3_open("./mydb.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}
    
    //---------------------------------------------------------------------
    rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, 0);
    if (rc) {
        fprintf(stderr, "Can't open statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}
    
    //right align output format
//    printf("%10s %10s %10s\n", "id", "name", "goal");
//    printf("%10s %10s %10s\n", "--", "----", "----");

    gettimeofday(&begin, NULL);
    
    for (i = 1; i <= insertline; i ++)
    {
        sqlite3_bind_int(stmt, 1, i);
        sqlite3_bind_text(stmt, 2, insertname, strlen(insertname), SQLITE_TRANSIENT);
        sqlite3_bind_double(stmt, 3, 2.3);
        sqlite3_bind_text(stmt, 4, insertnote, strlen(insertnote), SQLITE_TRANSIENT);
        
        while (sqlite3_step(stmt) == SQLITE_ROW) {
        //    id = sqlite3_column_int(stmt, 0);
        //    name = (unsigned char *)sqlite3_column_text(stmt, 0);
        //    goal = sqlite3_column_int(stmt, 2);
        }
        
        sqlite3_reset(stmt);
    }
    
    gettimeofday(&end, NULL);
    
    
    //---------------------------------------------------------------------
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    waste = (end.tv_sec - begin.tv_sec) * 1000 + (end.tv_usec - begin.tv_usec) / 1000;
    printf("the time is :%ld ms\n", waste);
    return 0;

}
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
/* vim: set tabstop=4 shiftwidth=4 expandtab: */
