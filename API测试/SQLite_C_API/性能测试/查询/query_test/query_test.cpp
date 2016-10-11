//query_test_cpp

#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <sys/time.h>

int main()
{
    sqlite3 * db;
    sqlite3_stmt * stmt;
    
    char * zErrMsg = 0;
    int rc;
    char * sql = "select NOTE from inserttest where ID = ?;";
    
    int id;
    unsigned char * name;
    double goal;
    unsigned char * note;
    
    int queryline = 1000000;
    int i;
    
    struct timeval begin;
    struct timeval end;
    long int waste;
    
    rc = sqlite3_open("./mydb.db", &db);
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}
    
    rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, 0);
    if (rc)
    {
        fprintf(stderr, "Can't open statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
	}
    
    //---------------------------------------------------------------------
    gettimeofday(&begin, NULL);

    for (i = 1; i <= queryline; i ++)
    {
        if (i % 1000 == 0) {
            sqlite3_bind_int(stmt, 1, i);
        
            while (sqlite3_step(stmt) == SQLITE_ROW) {
            //    id = sqlite3_column_int(stmt, 0);
            //    name = (unsigned char *)sqlite3_column_text(stmt, 1);
            //    goal = sqlite3_column_double(stmt, 2);
                note = (unsigned char *)sqlite3_column_text(stmt, 0);
            }
        
            sqlite3_reset(stmt);
        //    printf("%20s\n", note);
        }
        else {}
    }
    
    gettimeofday(&end, NULL);
    waste = (end.tv_sec - begin.tv_sec) * 1000000 + \
            (end.tv_usec - begin.tv_usec);
    printf("the time is :%d us\n", waste);
    //---------------------------------------------------------------------
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return 0;
}

/* vim: set tabstop=4 shiftwidth=4 expandtab: */
