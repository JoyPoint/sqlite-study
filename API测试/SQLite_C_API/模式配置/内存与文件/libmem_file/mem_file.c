//mem_file_c

#include "mem_file.h"

int loadOrSaveDb(sqlite3 *pInMemeory, const char *zFilename, int isSave)
{
    int rc;
    sqlite3 *pFile;
    sqlite3_backup *pBackup;
    sqlite3 *pTo;
    sqlite3 *pFrom;
    
    rc = sqlite3_open(zFilename, &pFile);
    if (rc == SQLITE_OK)
    {
        pFrom = (isSave ? pInMemeory : pFile);
        pTo = (isSave ? pFile : pInMemeory);
        pBackup = sqlite3_backup_init(pTo, "main", pFrom, "main");
        
        if (pBackup)
        {
            (void)sqlite3_backup_step(pBackup, -1);
            (void)sqlite3_backup_finish(pBackup);
        }
        rc = sqlite3_errcode(pTo);
    }
    (void)sqlite3_close(pFile);
    
    return rc;
}


// vim: set tabstop=4 shiftwidth=4 expandtab: 
