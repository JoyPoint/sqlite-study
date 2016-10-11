//test-mem_file_c

#include "../mem_file.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    //para input check
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s DATABASE\n", argv[0]);
        return(1);
    }
    
    //open a mem db
    sqlite3 *mem;
    sqlite3_open(":memory:", &mem);
    
    //get file db
    char *file = argv[1];
    
    //load file->mem
    loadOrSaveDb(mem, file, 0);
    
    char *sql = "select * from courses;";
    
    sqlite3_stmt *stmt;
    sqlite3_prepare(mem, sql, strlen(sql), &stmt, 0);

    int id;
	unsigned char *name;
	int goal;
    
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
		id = sqlite3_column_int(stmt, 0);
		name = (unsigned char *)sqlite3_column_text(stmt, 1);
		goal = sqlite3_column_int(stmt, 2);
		printf("%10d %10s %10d\n", id, name, goal);
	}
    
    sqlite3_finalize(stmt);
	sqlite3_close(mem);
    
    return 0;
}


// vim: set tabstop=4 shiftwidth=4 expandtab: 

/*
	sqlite3 *db;
	char *zErrMsg = 0;

	rc = sqlite3_open("./mydb.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}
	
	rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, 0);
	if (rc) {
		fprintf(stderr, "Can't open statement: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}
*/	


