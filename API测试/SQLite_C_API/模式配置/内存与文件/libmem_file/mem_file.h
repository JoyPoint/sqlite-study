//mem_file_h
#ifndef MEM_FILE_H
#define MEM_FILE_H

#include "/home/liangxx/local/include/sqlite3.h"

//////////////////////////////////////////////////////////////////////////////
//pInMemory: pointer to mem
//zFilename: pointer to file
//isSave  0: file->mem
//        1: mem->file
//////////////////////////////////////////////////////////////////////////////
int loadOrSaveDb(sqlite3 *pInMemeory, const char *zFilename, int isSave);


#endif//MEM_FILE_H

// vim: set tabstop=4 shiftwidth=4 expandtab: 
