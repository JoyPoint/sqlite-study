//libunencapsulated_h
#ifndef LIBUNENCAPSULATED_H
#define LIBUNENCAPSULATED_H

#include <sqlite3.h>
#include <stdio.h>
#include <string>

//process database
//i: database name string, sql string
//o: true or false
bool dbProc(std::string dbname, std::string sql);

#endif//LIBUNENCAPSULATED_H
// vim: set tabstop=4 shiftwidth=4 expandtab: 
