//libunencapsulated_cpp
#include "libunencapsulated.h"

bool dbProc(std::string dbname, std::string sql)
{
    sqlite3 * db;
    sqlite3_stmt * stmt;
    
	int id;
	unsigned char * name;
	int goal;
    
	if (sqlite3_open(dbname.c_str(), &db))
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
	}
    
	if (sqlite3_prepare(db, sql.c_str(), strlen(sql.c_str()), &stmt, 0))
    {
        fprintf(stderr, "Can't open statement: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
	}
    
    //proc database
    // for query-like sql, sqlite3_step return SQLITE_ROW if success
    // for other operate sql(insert or delete ...), 
    //      sqlite3_step return SQLITE_DONE if success
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        id = sqlite3_column_int(stmt, 0);
        name = (unsigned char *)sqlite3_column_text(stmt, 1);
        goal = sqlite3_column_int(stmt, 2);
        printf("%10d %10s %10d\n", id, name, goal);
	}
    
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    
    return true;
}
// vim: set tabstop=4 shiftwidth=4 expandtab: 
