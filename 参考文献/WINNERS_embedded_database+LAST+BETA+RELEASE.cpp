/************ WINNERS' EMBEDDED SQL DATABASE 1.0 ********\
*                                                        *
***************** started from SQLITE 3.4.1 **************
*                                                        *
************** Starting Optimization 8-AGO-2007 **********
*                                                        *
****************** Last modify 25-Ago-2007 ***************
*                                                        *
****** http://www.chiacchio.net/Winners-project.htm ******
*                                                        *
\************* (scheduled)Finished 31 AGO 2007 **********/
#define _WN_SQL3_H_
#include<stdarg.h>
#define WN_SQL_VERSION "0.1.0"
const char WN_SQL3_version[]=WN_SQL_VERSION;
typedef struct WN_SQL3 WN_SQL3;
#ifdef WN_SQL_INT64_TYPE
typedef WN_SQL_INT64_TYPE WN_SQL_int64;
typedef unsigned WN_SQL_INT64_TYPE WN_SQL_uint64;
#elif defined(_MSC_VER)|| defined(__BORLANDC__)
typedef __int64 WN_SQL_int64;
typedef unsigned __int64 WN_SQL_uint64;
#else
typedef long long int WN_SQL_int64;
typedef unsigned long long int WN_SQL_uint64;
#endif
#ifdef WN_SQL_OMIT_FLOATING_POINT
# define double WN_SQL_int64
#endif
typedef int(*WN_SQL3_callback)(void*,int,char**,char**);
#define WN_SQL_OK 0
#define WN_SQL_ERROR 1
#define WN_SQL_INTERNAL 2
#define WN_SQL_PERM 3
#define WN_SQL_ABORT 4
#define WN_SQL_BUSY 5
#define WN_SQL_LOCKED 6
#define WN_SQL_NOMEM 7
#define WN_SQL_READONLY 8
#define WN_SQL_INTERRUPT 9
#define WN_SQL_IOERR 10
#define WN_SQL_CORRUPT 11
#define WN_SQL_NOTFOUND 12
#define WN_SQL_FULL 13
#define WN_SQL_CANTOPEN 14
#define WN_SQL_PROTOCOL 15
#define WN_SQL_EMPTY 16
#define WN_SQL_SCHEMA 17
#define WN_SQL_TOOBIG 18
#define WN_SQL_CONSTRAINT 19
#define WN_SQL_MISMATCH 20
#define WN_SQL_MISUSE 21
#define WN_SQL_NOLFS 22
#define WN_SQL_AUTH 23
#define WN_SQL_FORMAT 24
#define WN_SQL_RANGE 25
#define WN_SQL_NOTADB 26
#define WN_SQL_ROW 100
#define WN_SQL_DONE 101
#define WN_SQL_IOERR_READ (WN_SQL_IOERR |(1<<8))
#define WN_SQL_IOERR_SHORT_READ (WN_SQL_IOERR |(2<<8))
#define WN_SQL_IOERR_WRITE (WN_SQL_IOERR |(3<<8))
#define WN_SQL_IOERR_FSYNC (WN_SQL_IOERR |(4<<8))
#define WN_SQL_IOERR_DIR_FSYNC (WN_SQL_IOERR |(5<<8))
#define WN_SQL_IOERR_TRUNCATE (WN_SQL_IOERR |(6<<8))
#define WN_SQL_IOERR_FSTAT (WN_SQL_IOERR |(7<<8))
#define WN_SQL_IOERR_UNLOCK (WN_SQL_IOERR |(8<<8))
#define WN_SQL_IOERR_RDLOCK (WN_SQL_IOERR |(9<<8))
#define WN_SQL_IOERR_DELETE (WN_SQL_IOERR |(10<<8))
#define WN_SQL_IOERR_BLOCKED (WN_SQL_IOERR |(11<<8))
#define WN_SQL_DENY 1
#define WN_SQL_IGNORE 2
#define WN_SQL_CREATE_INDEX 1
#define WN_SQL_CREATE_TABLE 2
#define WN_SQL_CREATE_TEMP_INDEX 3
#define WN_SQL_CREATE_TEMP_TABLE 4
#define WN_SQL_CREATE_TEMP_TRIGGER 5
#define WN_SQL_CREATE_TEMP_VIEW 6
#define WN_SQL_CREATE_TRIGGER 7
#define WN_SQL_CREATE_VIEW 8
#define WN_SQL_DELETE 9
#define WN_SQL_DROP_INDEX 10
#define WN_SQL_DROP_TABLE 11
#define WN_SQL_DROP_TEMP_INDEX 12
#define WN_SQL_DROP_TEMP_TABLE 13
#define WN_SQL_DROP_TEMP_TRIGGER 14
#define WN_SQL_DROP_TEMP_VIEW 15
#define WN_SQL_DROP_TRIGGER 16
#define WN_SQL_DROP_VIEW 17
#define WN_SQL_INSERT 18
#define WN_SQL_PRAGMA 19
#define WN_SQL_READ 20
#define WN_SQL_SELECT 21
#define WN_SQL_TRANSACTION 22
#define WN_SQL_UPDATE 23
#define WN_SQL_ATTACH 24
#define WN_SQL_DETACH 25
#define WN_SQL_ALTER_TABLE 26
#define WN_SQL_REINDEX 27
#define WN_SQL_ANALYZE 28
#define WN_SQL_CREATE_VTABLE 29
#define WN_SQL_DROP_VTABLE 30
#define WN_SQL_FUNCTION 31
#define WN_SQL_COPY 0
typedef struct Mem WN_SQL3_value;
typedef struct WN_SQL3_context WN_SQL3_context;
#define WN_SQL_INTEGER 1
#define WN_SQL_FLOAT 2
#define WN_SQL_BLOB 4
#define WN_SQL_NULL 5
#ifdef WN_SQL_TEXT
# undef WN_SQL_TEXT
#else
# define WN_SQL_TEXT 3
#endif
#define WN_SQL3_TEXT 3
#define WN_SQL_UTF8 1
#define WN_SQL_UTF16LE 2
#define WN_SQL_UTF16BE 3
#define WN_SQL_UTF16 4
#define WN_SQL_ANY 5
#define WN_SQL_UTF16_ALIGNED 8
typedef void(*WN_SQL3_destructor_type)(void*);
#define WN_SQL_STATIC((WN_SQL3_destructor_type)0)
#define WN_SQL_TRANSIENT((WN_SQL3_destructor_type)-1)
char *WN_SQL3_temp_directory=0;
typedef struct WN_SQL3_vtab WN_SQL3_vtab;
typedef struct WN_SQL3_index_info WN_SQL3_index_info;
typedef struct WN_SQL3_vtab_cursor WN_SQL3_vtab_cursor;
typedef struct WN_SQL3_module WN_SQL3_module;
struct WN_SQL3_module
{
	int iVersion;
	int(*xCreate)(WN_SQL3*,void *pAux,int argc,const char *const*argv,WN_SQL3_vtab **ppVTab,char**);
	int(*xConnect)(WN_SQL3*,void *pAux,int argc,const char *const*argv,WN_SQL3_vtab **ppVTab,char**);
	int(*xBestIndex)(WN_SQL3_vtab *pVTab,WN_SQL3_index_info*);
	int(*xDisconnect)(WN_SQL3_vtab *pVTab);
	int(*xDestroy)(WN_SQL3_vtab *pVTab);
	int(*xOpen)(WN_SQL3_vtab *pVTab,WN_SQL3_vtab_cursor **ppCursor);
	int(*xClose)(WN_SQL3_vtab_cursor*);
	int(*xFilter)(WN_SQL3_vtab_cursor*,int idxNum,const char *idxStr,int argc,WN_SQL3_value **argv);
	int(*xNext)(WN_SQL3_vtab_cursor*);
	int(*xEof)(WN_SQL3_vtab_cursor*);
	int(*xColumn)(WN_SQL3_vtab_cursor*,WN_SQL3_context*,int);
	int(*xRowid)(WN_SQL3_vtab_cursor*,WN_SQL_int64 *pRowid);
	int(*xUpdate)(WN_SQL3_vtab *,int,WN_SQL3_value **,WN_SQL_int64 *);
	int(*xBegin)(WN_SQL3_vtab *pVTab);
	int(*xSync)(WN_SQL3_vtab *pVTab);
	int(*xCommit)(WN_SQL3_vtab *pVTab);
	int(*xRollback)(WN_SQL3_vtab *pVTab);
	int(*xFindFunction)(WN_SQL3_vtab *pVtab,int nArg,const char *zName,void(**pxFunc)(WN_SQL3_context*,int,WN_SQL3_value**),void **ppArg);
	int(*xRename)(WN_SQL3_vtab *pVtab,const char *zNew);
};
struct WN_SQL3_index_info
{
	const int nConstraint;
	const struct WN_SQL3_index_constraint
	{
		int iColumn,iTermOffset;
		unsigned char op,usable;
	}*const aConstraint;
	const int nOrderBy;
	const struct WN_SQL3_index_orderby
	{
		int iColumn;
		unsigned char desc;
	}*const aOrderBy;
	struct WN_SQL3_index_constraint_usage
	{
		int argvIndex;
		unsigned char omit;
	}*const aConstraintUsage;
	int idxNum;
	char *idxStr;
	int needToFreeIdxStr,orderByConsumed;
	double estimatedCost;
};
#define WN_SQL_INDEX_CONSTRAINT_EQ 2
#define WN_SQL_INDEX_CONSTRAINT_GT 4
#define WN_SQL_INDEX_CONSTRAINT_LE 8
#define WN_SQL_INDEX_CONSTRAINT_LT 16
#define WN_SQL_INDEX_CONSTRAINT_GE 32
#define WN_SQL_INDEX_CONSTRAINT_MATCH 64
struct WN_SQL3_vtab
{
	const WN_SQL3_module *pModule;
	int nRef;
	char *zErrMsg;
};
struct WN_SQL3_vtab_cursor
{
	WN_SQL3_vtab *pVtab;
};
typedef struct WN_SQL3_blob WN_SQL3_blob;
#ifdef WN_SQL_OMIT_FLOATING_POINT
# undef double
#endif
#endif
#ifndef _WN_SQLINT_H_
#define _WN_SQLINT_H_
# define WN_SQL_MAX_LENGTH 1000000000
# define WN_SQL_MAX_COLUMN 2000
# define WN_SQL_MAX_SQL_LENGTH 1000000
#ifndef WN_SQL_MAX_EXPR_DEPTH
# define WN_SQL_MAX_EXPR_DEPTH 1000
#endif
# define WN_SQL_MAX_COMPOUND_SELECT 500
# define WN_SQL_MAX_VDBE_OP 25000
# define WN_SQL_MAX_FUNCTION_ARG 100
# define WN_SQL_DEFAULT_CACHE_SIZE 2000
# define WN_SQL_DEFAULT_TEMP_CACHE_SIZE 500
# define WN_SQL_MAX_ATTACHED 10
# define WN_SQL_MAX_VARIABLE_NUMBER 999
#ifndef WN_SQL_DEFAULT_PAGE_SIZE
# define WN_SQL_DEFAULT_PAGE_SIZE 1024
#endif
#ifndef WN_SQL_MAX_PAGE_SIZE
# define WN_SQL_MAX_PAGE_SIZE 32768
#endif
#ifndef WN_SQL_MAX_PAGE_COUNT
# define WN_SQL_MAX_PAGE_COUNT 1073741823
#endif
#ifndef WN_SQL_MAX_LIKE_PATTERN_LENGTH
# define WN_SQL_MAX_LIKE_PATTERN_LENGTH 50000
#endif
#if defined(WN_SQL_TCL)|| defined(TCLSH)
# include<tcl.h>
#endif
#if !defined(NDEBUG)&& !defined(WN_SQL_DEBUG)
# define NDEBUG 1
#endif
#ifndef WN_SQL_DISABLE_LFS
# define _LARGE_FILE 1
# ifndef _FILE_OFFSET_BITS
# define _FILE_OFFSET_BITS 64
# endif
# define _LARGEFILE_SOURCE 1
#endif
#ifndef _WN_SQL_HASH_H_
#define _WN_SQL_HASH_H_
typedef struct Hash Hash;
typedef struct HashElem HashElem;
struct Hash
{
	char keyClass,copyKey;
	int count;
	HashElem *first;
	void *(*xMalloc)(int);
	void(*xFree)(void *);
	int htsize;
	struct _ht
	{
		int count;
		HashElem *chain;
	}*ht;
};
struct HashElem
{
	HashElem *next,*prev;
	void *data,pKey;
	int nKey;
};
#define WN_SQL_HASH_STRING 3
#define WN_SQL_HASH_BINARY 4
#define WN_SQLHashFirst(H)((H)->first)
#define WN_SQLHashNext(E)((E)->next)
#define WN_SQLHashData(E)((E)->data)
#define WN_SQLHashKey(E)((E)->pKey)
#define WN_SQLHashKeysize(E)((E)->nKey)
#define WN_SQLHashCount(H)((H)->count)
#endif
#define TK_SEMI 1
#define TK_EXPLAIN 2
#define TK_QUERY 3
#define TK_PLAN 4
#define TK_BEGIN 5
#define TK_TRANSACTION 6
#define TK_DEFERRED 7
#define TK_IMMEDIATE 8
#define TK_EXCLUSIVE 9
#define TK_COMMIT 10
#define TK_END 11
#define TK_ROLLBACK 12
#define TK_CREATE 13
#define TK_TABLE 14
#define TK_IF 15
#define TK_NOT 16
#define TK_EXISTS 17
#define TK_TEMP 18
#define TK_LP 19
#define TK_RP 20
#define TK_AS 21
#define TK_COMMA 22
#define TK_ID 23
#define TK_ABORT 24
#define TK_AFTER 25
#define TK_ANALYZE 26
#define TK_ASC 27
#define TK_ATTACH 28
#define TK_BEFORE 29
#define TK_CASCADE 30
#define TK_CAST 31
#define TK_CONFLICT 32
#define TK_DATABASE 33
#define TK_DESC 34
#define TK_DETACH 35
#define TK_EACH 36
#define TK_FAIL 37
#define TK_FOR 38
#define TK_IGNORE 39
#define TK_INITIALLY 40
#define TK_INSTEAD 41
#define TK_LIKE_KW 42
#define TK_MATCH 43
#define TK_KEY 44
#define TK_OF 45
#define TK_OFFSET 46
#define TK_PRAGMA 47
#define TK_RAISE 48
#define TK_REPLACE 49
#define TK_RESTRICT 50
#define TK_ROW 51
#define TK_TRIGGER 52
#define TK_VACUUM 53
#define TK_VIEW 54
#define TK_VIRTUAL 55
#define TK_REINDEX 56
#define TK_RENAME 57
#define TK_CTIME_KW 58
#define TK_ANY 59
#define TK_OR 60
#define TK_AND 61
#define TK_IS 62
#define TK_BETWEEN 63
#define TK_IN 64
#define TK_ISNULL 65
#define TK_NOTNULL 66
#define TK_NE 67
#define TK_EQ 68
#define TK_GT 69
#define TK_LE 70
#define TK_LT 71
#define TK_GE 72
#define TK_ESCAPE 73
#define TK_BITAND 74
#define TK_BITOR 75
#define TK_LSHIFT 76
#define TK_RSHIFT 77
#define TK_PLUS 78
#define TK_MINUS 79
#define TK_STAR 80
#define TK_SLASH 81
#define TK_REM 82
#define TK_CONCAT 83
#define TK_COLLATE 84
#define TK_UMINUS 85
#define TK_UPLUS 86
#define TK_BITNOT 87
#define TK_STRING 88
#define TK_JOIN_KW 89
#define TK_CONSTRAINT 90
#define TK_DEFAULT 91
#define TK_NULL 92
#define TK_PRIMARY 93
#define TK_UNIQUE 94
#define TK_CHECK 95
#define TK_REFERENCES 96
#define TK_AUTOINCR 97
#define TK_ON 98
#define TK_DELETE 99
#define TK_UPDATE 100
#define TK_INSERT 101
#define TK_SET 102
#define TK_DEFERRABLE 103
#define TK_FOREIGN 104
#define TK_DROP 105
#define TK_UNION 106
#define TK_ALL 107
#define TK_EXCEPT 108
#define TK_INTERSECT 109
#define TK_SELECT 110
#define TK_DISTINCT 111
#define TK_DOT 112
#define TK_FROM 113
#define TK_JOIN 114
#define TK_USING 115
#define TK_ORDER 116
#define TK_BY 117
#define TK_GROUP 118
#define TK_HAVING 119
#define TK_LIMIT 120
#define TK_WHERE 121
#define TK_INTO 122
#define TK_VALUES 123
#define TK_INTEGER 124
#define TK_FLOAT 125
#define TK_BLOB 126
#define TK_REGISTER 127
#define TK_VARIABLE 128
#define TK_CASE 129
#define TK_WHEN 130
#define TK_THEN 131
#define TK_ELSE 132
#define TK_INDEX 133
#define TK_ALTER 134
#define TK_TO 135
#define TK_ADD 136
#define TK_COLUMNKW 137
#define TK_TO_TEXT 138
#define TK_TO_BLOB 139
#define TK_TO_NUMERIC 140
#define TK_TO_INT 141
#define TK_TO_REAL 142
#define TK_END_OF_FILE 143
#define TK_ILLEGAL 144
#define TK_SPACE 145
#define TK_UNCLOSED_STRING 146
#define TK_COMMENT 147
#define TK_FUNCTION 148
#define TK_COLUMN 149
#define TK_AGG_FUNCTION 150
#define TK_AGG_COLUMN 151
#define TK_CONST_FUNC 152
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#define WN_SQL3_isnan(X)((X)!=(X))
#ifdef WN_SQL_OMIT_FLOATING_POINT
# define double WN_SQL_int64
# define LONGDOUBLE_TYPE WN_SQL_int64
# ifndef WN_SQL_BIG_DBL
# define WN_SQL_BIG_DBL(0x7fffffffffffffff)
# endif
# define WN_SQL_OMIT_DATETIME_FUNCS 1
# define WN_SQL_OMIT_TRACE 1
# undef WN_SQL_MIXED_ENDIAN_64BIT_FLOAT
#endif
#ifndef WN_SQL_BIG_DBL
# define WN_SQL_BIG_DBL(1e99)
#endif
#ifdef WN_SQL_OMIT_TEMPDB
#define OMIT_TEMPDB 1
#else
#define OMIT_TEMPDB 0
#endif
#define NULL_DISTINCT_FOR_UNIQUE 1
#define WN_SQL_MAX_FILE_FORMAT 4
#ifndef WN_SQL_DEFAULT_FILE_FORMAT
# define WN_SQL_DEFAULT_FILE_FORMAT 1
#endif
#ifndef TEMP_STORE
# define TEMP_STORE 1
#endif
#ifndef offsetof
#define offsetof(STRUCTURE,FIELD) ((int)((char*)&((STRUCTURE*)0)->FIELD))
#endif
#if 'A'=='\301'
# define WN_SQL_EBCDIC 1
#else
# define WN_SQL_ASCII 1
#endif
# define u32 unsigned int
#endif
#ifndef UINT16_TYPE
# define UINT16_TYPE unsigned short int
#endif
#ifndef INT16_TYPE
# define INT16_TYPE short int
#endif
#ifndef UINT8_TYPE
# define UINT8_TYPE unsigned char
#endif
#ifndef INT8_TYPE
# define INT8_TYPE signed char
#endif
#ifndef LONGDOUBLE_TYPE
# define LONGDOUBLE_TYPE long double
#endif
typedef WN_SQL_int64 i64;
typedef WN_SQL_uint64 u64;
typedef UINT16_TYPE u16;
typedef INT16_TYPE i16;
typedef UINT8_TYPE u8;
typedef INT8_TYPE i8;
extern const int WN_SQL3one;
#if defined(i386)|| defined(__i386__)|| defined(_M_IX86)
# define WN_SQL_BIGENDIAN 0
# define WN_SQL_LITTLEENDIAN 1
# define WN_SQL_UTF16NATIVE WN_SQL_UTF16LE
#else
# define WN_SQL_BIGENDIAN(*(char *)(&WN_SQL3one)==0)
# define WN_SQL_LITTLEENDIAN(*(char *)(&WN_SQL3one)==1)
# define WN_SQL_UTF16NATIVE(WN_SQL_BIGENDIAN?WN_SQL_UTF16BE:WN_SQL_UTF16LE)
#endif
typedef struct BusyHandler BusyHandler;
struct BusyHandler
{
	int(*xFunc)(void *,int);
	void *pArg;
	int nBusy;
};
#ifndef _WN_SQL_VDBE_H_
#define _WN_SQL_VDBE_H_
typedef struct Vdbe Vdbe;
struct VdbeOp
{
	u8 opcode;
	int p1,p2,p3type;
	char *p3;
#ifdef VDBE_PROFILE
	int cnt;
	long long cycles;
#endif
};
typedef struct VdbeOp VdbeOp;
struct VdbeOpList
{
	u8 opcode;
	signed char p1;
	short int p2;
	char *p3;
};
typedef struct VdbeOpList VdbeOpList;
#define P3_NOTUSED 0
#define P3_DYNAMIC (-1)
#define P3_STATIC (-2)
#define P3_COLLSEQ (-4)
#define P3_FUNCDEF (-5)
#define P3_KEYINFO (-6)
#define P3_VDBEFUNC (-7)
#define P3_MEM (-8)
#define P3_TRANSIENT (-9)
#define P3_VTAB (-10)
#define P3_MPRINTF (-11)
#define P3_KEYINFO_HANDOFF (-9)
#define COLNAME_NAME 0
#define COLNAME_DECLTYPE 1
#define COLNAME_DATABASE 2
#define COLNAME_TABLE 3
#define COLNAME_COLUMN 4
#define COLNAME_N 5
#define ADDR(X) (-1-(X))
#define OP_MemLoad 1
#define OP_VNext 2
#define OP_HexBlob 126
#define OP_Column 3
#define OP_SetCookie 4
#define OP_IfMemPos 5
#define OP_Real 125
#define OP_Sequence 6
#define OP_MoveGt 7
#define OP_Ge 72
#define OP_RowKey 8
#define OP_Eq 68
#define OP_OpenWrite 9
#define OP_NotNull 66
#define OP_If 10
#define OP_ToInt 141
#define OP_String8 88
#define OP_Pop 11
#define OP_VRowid 12
#define OP_CollSeq 13
#define OP_OpenRead 14
#define OP_Expire 15
#define OP_AutoCommit 17
#define OP_Gt 69
#define OP_IntegrityCk 18
#define OP_Sort 19
#define OP_Function 20
#define OP_And 61
#define OP_Subtract 79
#define OP_Noop 21
#define OP_Return 22
#define OP_Remainder 82
#define OP_NewRowid 23
#define OP_Multiply 80
#define OP_IfMemNeg 24
#define OP_Variable 25
#define OP_String 26
#define OP_RealAffinity 27
#define OP_VRename 28
#define OP_ParseSchema 29
#define OP_VOpen 30
#define OP_Close 31
#define OP_CreateIndex 32
#define OP_IsUnique 33
#define OP_NotFound 34
#define OP_Int64 35
#define OP_MustBeInt 36
#define OP_Halt 37
#define OP_Rowid 38
#define OP_IdxLT 39
#define OP_AddImm 40
#define OP_Statement 41
#define OP_RowData 42
#define OP_MemMax 43
#define OP_Push 44
#define OP_Or 60
#define OP_NotExists 45
#define OP_MemIncr 46
#define OP_Gosub 47
#define OP_Divide 81
#define OP_Integer 48
#define OP_ToNumeric 140
#define OP_MemInt 49
#define OP_Prev 50
#define OP_Concat 83
#define OP_BitAnd 74
#define OP_VColumn 51
#define OP_CreateTable 52
#define OP_Last 53
#define OP_IsNull 65
#define OP_IncrVacuum 54
#define OP_IdxRowid 55
#define OP_MakeIdxRec 56
#define OP_ShiftRight 77
#define OP_ResetCount 57
#define OP_FifoWrite 58
#define OP_Callback 59
#define OP_ContextPush 62
#define OP_DropTrigger 63
#define OP_DropIndex 64
#define OP_IdxGE 73
#define OP_IdxDelete 84
#define OP_Vacuum 86
#define OP_MoveLe 89
#define OP_IfNot 90
#define OP_DropTable 91
#define OP_MakeRecord 92
#define OP_ToBlob 139
#define OP_Delete 93
#define OP_AggFinal 94
#define OP_ShiftLeft 76
#define OP_Dup 95
#define OP_Goto 96
#define OP_TableLock 97
#define OP_FifoRead 98
#define OP_Clear 99
#define OP_IdxGT 100
#define OP_MoveLt 101
#define OP_Le 70
#define OP_VerifyCookie 102
#define OP_AggStep 103
#define OP_Pull 104
#define OP_ToText 138
#define OP_Not 16
#define OP_ToReal 142
#define OP_SetNumColumns 105
#define OP_AbsValue 106
#define OP_Transaction 107
#define OP_VFilter 108
#define OP_Negative 85
#define OP_Ne 67
#define OP_VDestroy 109
#define OP_ContextPop 110
#define OP_BitOr 75
#define OP_Next 111
#define OP_IdxInsert 112
#define OP_Distinct 113
#define OP_Lt 71
#define OP_Insert 114
#define OP_Destroy 115
#define OP_ReadCookie 116
#define OP_ForceInt 117
#define OP_LoadAnalysis 118
#define OP_Explain 119
#define OP_IfMemZero 120
#define OP_OpenPseudo 121
#define OP_OpenEphemeral 122
#define OP_Null 123
#define OP_Blob 124
#define OP_Add 78
#define OP_MemStore 127
#define OP_Rewind 128
#define OP_MoveGe 129
#define OP_VBegin 130
#define OP_VUpdate 131
#define OP_BitNot 87
#define OP_VCreate 132
#define OP_MemMove 133
#define OP_MemNull 134
#define OP_Found 135
#define OP_NullRow 136
#define OP_NotUsed_137 137
#define NOPUSH_MASK_0 0xeeb4
#define NOPUSH_MASK_1 0xf96b
#define NOPUSH_MASK_2 0xfbb6
#define NOPUSH_MASK_3 0xfe64
#define NOPUSH_MASK_4 0xffff
#define NOPUSH_MASK_5 0x6ef7
#define NOPUSH_MASK_6 0xfbfb
#define NOPUSH_MASK_7 0x8767
#define NOPUSH_MASK_8 0x7d9f
#define NOPUSH_MASK_9 0x0000
#ifdef WN_SQL_DEBUG
void WN_SQL3VdbeTrace(Vdbe*,FILE*);
#endif
#ifndef NDEBUG
void WN_SQL3VdbeComment(Vdbe*,const char*,...);
# define VdbeComment(X)WN_SQL3VdbeComment X
#else
# define VdbeComment(X)
#endif
#endif
#define _BTREE_H_
#define WN_SQL_N_BTREE_META 10
#ifndef WN_SQL_DEFAULT_AUTOVACUUM
#define WN_SQL_DEFAULT_AUTOVACUUM 0
#define BTREE_AUTOVACUUM_NONE 0
#define BTREE_AUTOVACUUM_FULL 1
#define BTREE_AUTOVACUUM_INCR 2
typedef struct Btree Btree;
typedef struct BtCursor BtCursor;
typedef struct BtShared BtShared;
#define BTREE_OMIT_JOURNAL 1
#define BTREE_NO_READLOCK 2
#define BTREE_MEMORY 4
#define BTREE_INTKEY 1
#define BTREE_ZERODATA 2
#define BTREE_LEAFDATA 4
#ifdef WN_SQL_TEST
int WN_SQL3BtreeCursorInfo(BtCursor*,int*,int);
void WN_SQL3BtreeCursorList(Btree*);
int WN_SQL3BtreePageDump(Btree*,int,int recursive);
#endif
#endif
#ifndef _PAGER_H_
#define _PAGER_H_
typedef u32 Pgno;
typedef struct Pager Pager;
typedef struct PgHdr DbPage;
#define PAGER_OMIT_JOURNAL 0x0001
#define PAGER_NO_READLOCK 0x0002
#define PAGER_LOCKINGMODE_QUERY-1
#define PAGER_LOCKINGMODE_NORMAL 0
#define PAGER_LOCKINGMODE_EXCLUSIVE 1
#define WN_SQL3PagerGet(A,B,C)WN_SQL3PagerAcquire(A,B,C,0)
#if defined(WN_SQL_ENABLE_MEMORY_MANAGEMENT)&& !defined(WN_SQL_OMIT_DISKIO)
int WN_SQL3PagerReleaseMemory(int);
#endif
#ifdef WN_SQL_HAS_CODEC
void WN_SQL3PagerSetCodec(Pager*,void*(*)(void*,void*,Pgno,int),void*);
#endif
#if !defined(NDEBUG)|| defined(WN_SQL_TEST)
Pgno WN_SQL3PagerPagenumber(DbPage*);
int WN_SQL3PagerIswriteable(DbPage*);
#endif
#if defined(WN_SQL_DEBUG)|| defined(WN_SQL_TEST)
int WN_SQL3PagerLockstate(Pager*);
#endif
#ifdef WN_SQL_TEST
int *WN_SQL3PagerStats(Pager*);
void WN_SQL3PagerRefdump(Pager*);
int pager3_refinfo_enable;
#endif
#ifdef WN_SQL_TEST
void disable_simulated_io_errors(void);
void enable_simulated_io_errors(void);
#else
# define disable_simulated_io_errors()
# define enable_simulated_io_errors()
#endif
#endif
#ifdef WN_SQL_MEMDEBUG
extern int WN_SQL3_nMalloc;
extern int WN_SQL3_nFree;
extern int WN_SQL3_iMallocFail;
extern int WN_SQL3_iMallocReset;
extern void *WN_SQL3_pFirst;
extern int WN_SQL3_nMaxAlloc;
extern int WN_SQL3_mallocDisallowed;
extern int WN_SQL3_isFail;
extern const char *WN_SQL3_zFile;
extern int WN_SQL3_iLine;
#define ENTER_MALLOC(WN_SQL3_zFile=__FILE__,WN_SQL3_iLine=__LINE__)
#define WN_SQL3Malloc(x)(ENTER_MALLOC,WN_SQL3Malloc(x,1))
#define WN_SQLMallocRaw(x)(ENTER_MALLOC,WN_SQL3MallocRaw(x,1))
#define WN_SQLRealloc(x,y)(ENTER_MALLOC,WN_SQL3Realloc(x,y))
#define WN_SQLStrDup(x)(ENTER_MALLOC,WN_SQL3StrDup(x))
#define WN_SQLStrNDup(x,y)(ENTER_MALLOC,WN_SQL3StrNDup(x,y))
#define WN_SQLReallocOrFree(x,y)(ENTER_MALLOC,WN_SQL3ReallocOrFree(x,y))
#else
#define ENTER_MALLOC 0
#define WN_SQLMallocRaw(x)WN_SQL3MallocRaw(x,1)
#define WN_SQLRealloc(x,y)WN_SQL3Realloc(x,y)
#define WN_SQLStrDup(x)WN_SQL3StrDup(x)
#define WN_SQLStrNDup(x,y)WN_SQL3StrNDup(x,y)
#define WN_SQLReallocOrFree(x,y)WN_SQL3ReallocOrFree(x,y)
#endif
extern int WN_SQL3_mallocHasFailed;
#define WN_SQL3MallocFailed()(WN_SQL3_mallocHasFailed && WN_SQL3OsInMutex(1))
struct ThreadData
{
	int dummy;
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
	int nSoftHeapLimit;
	int nAlloc;
	Pager *pPager;
#endif
#ifndef WN_SQL_OMIT_SHARED_CACHE
	u8 useSharedData;
	BtShared *pBtree;
#endif
};
#define MASTER_NAME "WN_SQL_master"
#define TEMP_MASTER_NAME "WN_SQL_temp_master"
#define MASTER_ROOT 1
#define SCHEMA_TABLE(x)((!OMIT_TEMPDB)&&(x==1)?TEMP_MASTER_NAME:MASTER_NAME)
#define ArraySize(X)(sizeof(X)/sizeof(X[0]))
typedef struct AggInfo AggInfo;
typedef struct AuthContext AuthContext;
typedef struct CollSeq CollSeq;
typedef struct Column Column;
typedef struct Db Db;
typedef struct Schema Schema;
typedef struct Expr Expr;
typedef struct ExprList ExprList;
typedef struct FKey FKey;
typedef struct FuncDef FuncDef;
typedef struct IdList IdList;
typedef struct Index Index;
typedef struct KeyClass KeyClass;
typedef struct KeyInfo KeyInfo;
typedef struct Module Module;
typedef struct NameContext NameContext;
typedef struct Parse Parse;
typedef struct Select Select;
typedef struct SrcList SrcList;
typedef struct ThreadData ThreadData;
typedef struct Table Table;
typedef struct TableLock TableLock;
typedef struct Token Token;
typedef struct TriggerStack TriggerStack;
typedef struct TriggerStep TriggerStep;
typedef struct Trigger Trigger;
typedef struct WhereInfo WhereInfo;
typedef struct WhereLevel WhereLevel;
#ifndef _WN_SQL_OS_H_
#define _WN_SQL_OS_H_
#if defined(OS_OTHER)
# if OS_OTHER==1
# undef OS_UNIX
# define OS_UNIX 0
# undef OS_WIN
# define OS_WIN 0
# undef OS_OS2
# define OS_OS2 0
# else
# undef OS_OTHER
# endif
#endif
#if !defined(OS_UNIX)&& !defined(OS_OTHER)
# define OS_OTHER 0
# ifndef OS_WIN
# if defined(_WIN32)|| defined(WIN32)|| defined(__CYGWIN__)|| defined(__MINGW32__)|| defined(__BORLANDC__)
# define OS_WIN 1
# define OS_UNIX 0
# define OS_OS2 0
# elif defined(__EMX__)|| defined(_OS2)|| defined(OS2)|| defined(_OS2_)|| defined(__OS2__)
# define OS_WIN 0
# define OS_UNIX 0
# define OS_OS2 1
# else
# define OS_WIN 0
# define OS_UNIX 1
# define OS_OS2 0
# endif
# else
# define OS_UNIX 0
# define OS_OS2 0
# endif
#else
# ifndef OS_WIN
# define OS_WIN 0
# endif
#endif
#if OS_WIN
# include<windows.h>
# define WN_SQL_TEMPNAME_SIZE(MAX_PATH+50)
#elif OS_OS2
# if(__GNUC__ > 3 || __GNUC__==3 && __GNUC_MINOR__ >=3)&& defined(OS2_HIGH_MEMORY)
# include<os2safe.h>
# endif
# define INCL_DOSDATETIME
# define INCL_DOSFILEMGR
# define INCL_DOSERRORS
# define INCL_DOSMISC
# define INCL_DOSPROCESS
# define INCL_DOSMODULEMGR
# include<os2.h>
# define WN_SQL_TEMPNAME_SIZE(CCHMAXPATHCOMP)
#else
# define WN_SQL_TEMPNAME_SIZE 200
#endif
#ifndef SET_FULLSYNC
# define SET_FULLSYNC(x,y)
#endif
#ifndef WN_SQL_DEFAULT_SECTOR_SIZE
# define WN_SQL_DEFAULT_SECTOR_SIZE 512
#endif
#ifndef TEMP_FILE_PREFIX
# define TEMP_FILE_PREFIX "etilqs_"
#endif
#if OS_UNIX
#define WN_SQL3OsOpenReadWrite WN_SQL3UnixOpenReadWrite
#define WN_SQL3OsOpenExclusive WN_SQL3UnixOpenExclusive
#define WN_SQL3OsOpenReadOnly WN_SQL3UnixOpenReadOnly
#define WN_SQL3OsDelete WN_SQL3UnixDelete
#define WN_SQL3OsFileExists WN_SQL3UnixFileExists
#define WN_SQL3OsFullPathname WN_SQL3UnixFullPathname
#define WN_SQL3OsIsDirWritable WN_SQL3UnixIsDirWritable
#define WN_SQL3OsSyncDirectory WN_SQL3UnixSyncDirectory
#define WN_SQL3OsTempFileName WN_SQL3UnixTempFileName
#define WN_SQL3OsRandomSeed WN_SQL3UnixRandomSeed
#define WN_SQL3OsSleep WN_SQL3UnixSleep
#define WN_SQL3OsCurrentTime WN_SQL3UnixCurrentTime
#define WN_SQL3OsEnterMutex WN_SQL3UnixEnterMutex
#define WN_SQL3OsLeaveMutex WN_SQL3UnixLeaveMutex
#define WN_SQL3OsInMutex WN_SQL3UnixInMutex
#define WN_SQL3OsThreadSpecificData WN_SQL3UnixThreadSpecificData
#define WN_SQL3OsMalloc WN_SQL3GenericMalloc
#define WN_SQL3OsRealloc WN_SQL3GenericRealloc
#define WN_SQL3OsFree WN_SQL3GenericFree
#define WN_SQL3OsAllocationSize WN_SQL3GenericAllocationSize
#define WN_SQL3OsDlopen WN_SQL3UnixDlopen
#define WN_SQL3OsDlsym WN_SQL3UnixDlsym
#define WN_SQL3OsDlclose WN_SQL3UnixDlclose
#endif
#if OS_WIN
#define WN_SQL3OsOpenReadWrite WN_SQL3WinOpenReadWrite
#define WN_SQL3OsOpenExclusive WN_SQL3WinOpenExclusive
#define WN_SQL3OsOpenReadOnly WN_SQL3WinOpenReadOnly
#define WN_SQL3OsDelete WN_SQL3WinDelete
#define WN_SQL3OsFileExists WN_SQL3WinFileExists
#define WN_SQL3OsFullPathname WN_SQL3WinFullPathname
#define WN_SQL3OsIsDirWritable WN_SQL3WinIsDirWritable
#define WN_SQL3OsSyncDirectory WN_SQL3WinSyncDirectory
#define WN_SQL3OsTempFileName WN_SQL3WinTempFileName
#define WN_SQL3OsRandomSeed WN_SQL3WinRandomSeed
#define WN_SQL3OsSleep WN_SQL3WinSleep
#define WN_SQL3OsCurrentTime WN_SQL3WinCurrentTime
#define WN_SQL3OsEnterMutex WN_SQL3WinEnterMutex
#define WN_SQL3OsLeaveMutex WN_SQL3WinLeaveMutex
#define WN_SQL3OsInMutex WN_SQL3WinInMutex
#define WN_SQL3OsThreadSpecificData WN_SQL3WinThreadSpecificData
#define WN_SQL3OsMalloc WN_SQL3GenericMalloc
#define WN_SQL3OsRealloc WN_SQL3GenericRealloc
#define WN_SQL3OsFree WN_SQL3GenericFree
#define WN_SQL3OsAllocationSize WN_SQL3GenericAllocationSize
#define WN_SQL3OsDlopen WN_SQL3WinDlopen
#define WN_SQL3OsDlsym WN_SQL3WinDlsym
#define WN_SQL3OsDlclose WN_SQL3WinDlclose
#endif
#if OS_OS2
#define WN_SQL3OsOpenReadWrite WN_SQL3Os2OpenReadWrite
#define WN_SQL3OsOpenExclusive WN_SQL3Os2OpenExclusive
#define WN_SQL3OsOpenReadOnly WN_SQL3Os2OpenReadOnly
#define WN_SQL3OsDelete WN_SQL3Os2Delete
#define WN_SQL3OsFileExists WN_SQL3Os2FileExists
#define WN_SQL3OsFullPathname WN_SQL3Os2FullPathname
#define WN_SQL3OsIsDirWritable WN_SQL3Os2IsDirWritable
#define WN_SQL3OsSyncDirectory WN_SQL3Os2SyncDirectory
#define WN_SQL3OsTempFileName WN_SQL3Os2TempFileName
#define WN_SQL3OsRandomSeed WN_SQL3Os2RandomSeed
#define WN_SQL3OsSleep WN_SQL3Os2Sleep
#define WN_SQL3OsCurrentTime WN_SQL3Os2CurrentTime
#define WN_SQL3OsEnterMutex WN_SQL3Os2EnterMutex
#define WN_SQL3OsLeaveMutex WN_SQL3Os2LeaveMutex
#define WN_SQL3OsInMutex WN_SQL3Os2InMutex
#define WN_SQL3OsThreadSpecificData WN_SQL3Os2ThreadSpecificData
#define WN_SQL3OsMalloc WN_SQL3GenericMalloc
#define WN_SQL3OsRealloc WN_SQL3GenericRealloc
#define WN_SQL3OsFree WN_SQL3GenericFree
#define WN_SQL3OsAllocationSize WN_SQL3GenericAllocationSize
#define WN_SQL3OsDlopen WN_SQL3Os2Dlopen
#define WN_SQL3OsDlsym WN_SQL3Os2Dlsym
#define WN_SQL3OsDlclose WN_SQL3Os2Dlclose
#endif
#if OS_OTHER
# include "os_other.h"
#endif
typedef struct OsFile OsFile;
typedef struct IoMethod IoMethod;
struct IoMethod
{
	int(*xClose)(OsFile**);
	int(*xOpenDirectory)(OsFile*,const char*);
	int(*xRead)(OsFile*,void*,int amt);
	int(*xWrite)(OsFile*,const void*,int amt);
	int(*xSeek)(OsFile*,i64 offset);
	int(*xTruncate)(OsFile*,i64 size);
	int(*xSync)(OsFile*,int);
	void(*xSetFullSync)(OsFile *id,int setting);
	int(*xFileHandle)(OsFile *id);
	int(*xFileSize)(OsFile*,i64 *pSize);
	int(*xLock)(OsFile*,int);
	int(*xUnlock)(OsFile*,int);
	int(*xLockState)(OsFile *id);
	int(*xCheckReservedLock)(OsFile *id);
	int(*xSectorSize)(OsFile *id);
};
struct OsFile
{
	IoMethod const *pMethod;
};
#define NO_LOCK 0
#define SHARED_LOCK 1
#define RESERVED_LOCK 2
#define PENDING_LOCK 3
#define EXCLUSIVE_LOCK 4
#ifndef WN_SQL_TEST
#define PENDING_BYTE 0x40000000
#else
extern u32 WN_SQL3_pending_byte;
#define PENDING_BYTE WN_SQL3_pending_byte
#endif
#define RESERVED_BYTE(PENDING_BYTE+1)
#define SHARED_FIRST(PENDING_BYTE+2)
#define SHARED_SIZE 510
#if defined(WN_SQL_TEST)|| defined(WN_SQL_DEBUG)
int WN_SQL3OsFileHandle(OsFile *id);
int WN_SQL3OsLockState(OsFile *id);
#endif
#ifdef WN_SQL_ENABLE_REDEF_IO
struct WN_SQL3OsVtbl
{
	int(*xOpenReadWrite)(const char*,OsFile**,int*);
	int(*xOpenExclusive)(const char*,OsFile**,int);
	int(*xOpenReadOnly)(const char*,OsFile**);
	int(*xDelete)(const char*);
	int(*xFileExists)(const char*);
	char *(*xFullPathname)(const char*);
	int(*xIsDirWritable)(char*);
	int(*xSyncDirectory)(const char*);
	int(*xTempFileName)(char*);
	int(*xRandomSeed)(char*);
	int(*xSleep)(int ms);
	int(*xCurrentTime)(double*);
	void(*xEnterMutex)(void);
	void(*xLeaveMutex)(void);
	int(*xInMutex)(int);
	ThreadData *(*xThreadSpecificData)(int);
	void *(*xMalloc)(int);
	void *(*xRealloc)(void *,int);
	void(*xFree)(void *);
	int(*xAllocationSize)(void *);
	void *(*xDlopen)(const char*);
	void *(*xDlsym)(void*,const char*);
	int(*xDlclose)(void*);
};
#ifdef WN_SQL_OMIT_DISKIO
# define IF_DISKIO(X)0
#else
# define IF_DISKIO(X)X
#endif
#ifdef WN_SQL_OMIT_LOAD_EXTENSION
# define IF_DLOPEN(X)0
#else
# define IF_DLOPEN(X)X
#endif
struct WN_SQL3OsVtbl WN_SQL3Os={IF_DISKIO(WN_SQL3OsOpenReadWrite),IF_DISKIO(WN_SQL3OsOpenExclusive),IF_DISKIO(WN_SQL3OsOpenReadOnly),IF_DISKIO(WN_SQL3OsDelete),IF_DISKIO(WN_SQL3OsFileExists),IF_DISKIO(WN_SQL3OsFullPathname),IF_DISKIO(WN_SQL3OsIsDirWritable),IF_DISKIO(WN_SQL3OsSyncDirectory),IF_DISKIO(WN_SQL3OsTempFileName),WN_SQL3OsRandomSeed,WN_SQL3OsSleep,WN_SQL3OsCurrentTime,WN_SQL3OsEnterMutex,WN_SQL3OsLeaveMutex,WN_SQL3OsInMutex,WN_SQL3OsThreadSpecificData,WN_SQL3OsMalloc,WN_SQL3OsRealloc,WN_SQL3OsFree,WN_SQL3OsAllocationSize,IF_DLOPEN(WN_SQL3OsDlopen),IF_DLOPEN(WN_SQL3OsDlsym),IF_DLOPEN(WN_SQL3OsDlclose),};
struct WN_SQL3OsVtbl *WN_SQL3_os_switch(void);
#undef WN_SQL3OsOpenReadWrite
#undef WN_SQL3OsOpenExclusive
#undef WN_SQL3OsOpenReadOnly
#undef WN_SQL3OsDelete
#undef WN_SQL3OsFileExists
#undef WN_SQL3OsFullPathname
#undef WN_SQL3OsIsDirWritable
#undef WN_SQL3OsSyncDirectory
#undef WN_SQL3OsTempFileName
#undef WN_SQL3OsRandomSeed
#undef WN_SQL3OsSleep
#undef WN_SQL3OsCurrentTime
#undef WN_SQL3OsEnterMutex
#undef WN_SQL3OsLeaveMutex
#undef WN_SQL3OsInMutex
#undef WN_SQL3OsThreadSpecificData
#undef WN_SQL3OsMalloc
#undef WN_SQL3OsRealloc
#undef WN_SQL3OsFree
#undef WN_SQL3OsAllocationSize
#define WN_SQL3OsOpenReadWrite WN_SQL3Os.xOpenReadWrite
#define WN_SQL3OsOpenExclusive WN_SQL3Os.xOpenExclusive
#define WN_SQL3OsOpenReadOnly WN_SQL3Os.xOpenReadOnly
#define WN_SQL3OsDelete WN_SQL3Os.xDelete
#define WN_SQL3OsFileExists WN_SQL3Os.xFileExists
#define WN_SQL3OsFullPathname WN_SQL3Os.xFullPathname
#define WN_SQL3OsIsDirWritable WN_SQL3Os.xIsDirWritable
#define WN_SQL3OsSyncDirectory WN_SQL3Os.xSyncDirectory
#define WN_SQL3OsTempFileName WN_SQL3Os.xTempFileName
#define WN_SQL3OsRandomSeed WN_SQL3Os.xRandomSeed
#define WN_SQL3OsSleep WN_SQL3Os.xSleep
#define WN_SQL3OsCurrentTime WN_SQL3Os.xCurrentTime
#define WN_SQL3OsEnterMutex WN_SQL3Os.xEnterMutex
#define WN_SQL3OsLeaveMutex WN_SQL3Os.xLeaveMutex
#define WN_SQL3OsInMutex WN_SQL3Os.xInMutex
#define WN_SQL3OsThreadSpecificData WN_SQL3Os.xThreadSpecificData
#define WN_SQL3OsMalloc WN_SQL3Os.xMalloc
#define WN_SQL3OsRealloc WN_SQL3Os.xRealloc
#define WN_SQL3OsFree WN_SQL3Os.xFree
#define WN_SQL3OsAllocationSize WN_SQL3Os.xAllocationSize
#endif
#endif
struct Db
{
	char *zName;
	Btree *pBt;
	u8 inTrans,safety_level;
	void *pAux;
	void(*xFreeAux)(void*);
	Schema *pSchema;
};
struct Schema
{
	int schema_cookie;
	Hash tblHash,idxHash,trigHash,aFKey;
	Table *pSeqTab;
	u8 file_format,enc;
	u16 flags;
	int cache_size;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	WN_SQL3 *db;
#endif
};
#define DbHasProperty(D,I,P)(((D)->aDb[I].pSchema->flags&(P))==(P))
#define DbHasAnyProperty(D,I,P)(((D)->aDb[I].pSchema->flags&(P)))
#define DbSetProperty(D,I,P)(D)->aDb[I].pSchema->flags|=(P)
#define DbClearProperty(D,I,P)(D)->aDb[I].pSchema->flags&=~(P)
#define DB_SchemaLoaded 0x0001
#define DB_UnresetViews 0x0002
#define DB_Empty 0x0004
struct WN_SQL3
{
	int nDb,flags,errCode,errMask,magic,nChange,nTotalChange,nTable;
	u8 autoCommit,temp_store;
	Db *aDb;
	CollSeq *pDfltColl;
	i64 lastRowid,priorNewRowid;
	struct WN_SQL3InitInfo
	{
		int iDb,newTnum;
		u8 busy;
	}init;
	int nExtension;
	void **aExtension;
	struct Vdbe *pVdbe;
	int activeVdbeCnt;
	void(*xTrace)(void*,const char*);
	void *pTraceArg;
	void(*xProfile)(void*,const char*,u64);
	void *pProfileArg;
	void *pCommitArg;
	int(*xCommitCallback)(void*);
	void *pRollbackArg;
	void(*xRollbackCallback)(void*);
	void *pUpdateArg;
	void(*xUpdateCallback)(void*,int,const char*,const char*,WN_SQL_int64);
	void(*xCollNeeded)(void*,WN_SQL3*,int eTextRep,const char*);
	void(*xCollNeeded16)(void*,WN_SQL3*,int eTextRep,const void*);
	void *pCollNeededArg;
	WN_SQL3_value *pErr;
	char *zErrMsg,*zErrMsg16;
	union
	{
		int isInterrupted;
		double notUsed1;
	}u1;
#ifndef WN_SQL_OMIT_AUTHORIZATION
	int(*xAuth)(void*,int,const char*,const char*,const char*,const char*);
	void *pAuthArg;
#endif
#ifndef WN_SQL_OMIT_PROGRESS_CALLBACK
	int(*xProgress)(void *);
	void *pProgressArg;
	int nProgressOps;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	Hash aModule;
	Table *pVTab;
	WN_SQL3_vtab **aVTrans;
	int nVTrans;
#endif
	Hash aFunc,aCollSeq;
	BusyHandler busyHandler;
	int busyTimeout;
	Db aDbStatic[2];
#ifdef WN_SQL_SSE
	WN_SQL3_stmt *pFetch;
#endif
	u8 dfltLockMode;
};
#define ENC(db)((db)->aDb[0].pSchema->enc)
#define WN_SQL_VdbeTrace 0x00000001
#define WN_SQL_InTrans 0x00000008
#define WN_SQL_InternChanges 0x00000010
#define WN_SQL_FullColNames 0x00000020
#define WN_SQL_ShortColNames 0x00000040
#define WN_SQL_CountRows 0x00000080
#define WN_SQL_NullCallback 0x00000100
#define WN_SQL_SqlTrace 0x00000200
#define WN_SQL_VdbeListing 0x00000400
#define WN_SQL_WriteSchema 0x00000800
#define WN_SQL_NoReadlock 0x00001000
#define WN_SQL_IgnoreChecks 0x00002000
#define WN_SQL_ReadUncommitted 0x00004000
#define WN_SQL_LegacyFileFmt 0x00008000
#define WN_SQL_FullFSync 0x00010000
#define WN_SQL_LoadExtension 0x00020000
#define WN_SQL_RecoveryMode 0x00040000
#define WN_SQL_MAGIC_OPEN 0xa029a697
#define WN_SQL_MAGIC_CLOSED 0x9f3c2d33
#define WN_SQL_MAGIC_BUSY 0xf03b7906
#define WN_SQL_MAGIC_ERROR 0xb5357930
struct FuncDef
{
	i16 nArg;
	u8 iPrefEnc,needCollSeq,flags;
	void *pUserData;
	FuncDef *pNext;
	void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value**);
	void(*xStep)(WN_SQL3_context*,int,WN_SQL3_value**);
	void(*xFinalize)(WN_SQL3_context*);
	char zName[1];
};
struct Module
{
	const WN_SQL3_module *pModule;
	const char *zName;
	void *pAux;
	void(*xDestroy)(void *);
};
#define WN_SQL_FUNC_LIKE 0x01
#define WN_SQL_FUNC_CASE 0x02
#define WN_SQL_FUNC_EPHEM 0x04
struct Column
{
	char *zName;
	Expr *pDflt;
	char *zType,*zColl;
	u8 notNull,isPrimKey;
	char affinity;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	u8 isHidden;
#endif
};
struct CollSeq
{
	char *zName;
	u8 enc,type;
	void *pUser;
	int(*xCmp)(void*,int,const void*,int,const void*);
	void(*xDel)(void*);
};
#define WN_SQL_COLL_BINARY 1
#define WN_SQL_COLL_NOCASE 2
#define WN_SQL_COLL_REVERSE 3
#define WN_SQL_COLL_USER 0
#define WN_SQL_SO_ASC 0
#define WN_SQL_SO_DESC 1
#define WN_SQL_AFF_TEXT 'a'
#define WN_SQL_AFF_NONE 'b'
#define WN_SQL_AFF_NUMERIC 'c'
#define WN_SQL_AFF_INTEGER 'd'
#define WN_SQL_AFF_REAL 'e'
#define WN_SQL3IsNumericAffinity(X)((X)>=WN_SQL_AFF_NUMERIC)
struct Table
{
	char *zName;
	int nCol;
	Column *aCol;
	int iPKey;
	Index *pIndex;
	int tnum;
	Select *pSelect;
	int nRef;
	Trigger *pTrigger;
	FKey *pFKey;
	char *zColAff;
#ifndef WN_SQL_OMIT_CHECK
	Expr *pCheck;
#endif
#ifndef WN_SQL_OMIT_ALTERTABLE
	int addColOffset;
#endif
	u8 readOnly,isEphem,hasPrimKey,keyConf,autoInc;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	u8 isVirtual,isCommit;
	Module *pMod;
	WN_SQL3_vtab *pVtab;
	int nModuleArg;
	char **azModuleArg;
#endif
	Schema *pSchema;
};
#ifndef WN_SQL_OMIT_VIRTUALTABLE
# define IsVirtual(X)((X)->isVirtual)
# define IsHiddenColumn(X)((X)->isHidden)
#else
# define IsVirtual(X)0
# define IsHiddenColumn(X)0
#endif
struct FKey
{
	Table *pFrom;
	FKey *pNextFrom;
	char *zTo;
	FKey *pNextTo;
	int nCol;
	struct sColMap
	{
		int iFrom;
		char *zCol;
	}*aCol;
	u8 isDeferred,updateConf,deleteConf,insertConf;
};
#define OE_None 0
#define OE_Rollback 1
#define OE_Abort 2
#define OE_Fail 3
#define OE_Ignore 4
#define OE_Replace 5
#define OE_Restrict 6
#define OE_SetNull 7
#define OE_SetDflt 8
#define OE_Cascade 9
#define OE_Default 99
struct KeyInfo
{
	u8 enc,incrKey;
	int nField;
	u8 *aSortOrder;
	CollSeq *aColl[1];
};
struct Index
{
	char *zName;
	int nColumn,*aiColumn;
	unsigned *aiRowEst;
	Table *pTable;
	int tnum;
	u8 onError,autoIndex;
	char *zColAff;
	Index *pNext;
	Schema *pSchema;
	u8 *aSortOrder;
	char **azColl;
};
struct Token
{
	const unsigned char *z;
	unsigned dyn :1;
	unsigned n :31;
};
struct AggInfo
{
	u8 directMode,useSortingIdx;
	int sortingIdx;
	ExprList *pGroupBy;
	int nSortingColumn;
	struct AggInfo_col
	{
		Table *pTab;
		int iTable,iColumn,iSorterColumn,iMem;
		Expr *pExpr;
	}*aCol;
	int nColumn,nColumnAlloc,nAccumulator;
	struct AggInfo_func
	{
		Expr *pExpr;
		FuncDef *pFunc;
		int iMem,iDistinct;
	}*aFunc;
	int nFunc,nFuncAlloc;
};
struct Expr
{
	u8 op;
	char affinity;
	u16 flags;
	CollSeq *pColl;
	Expr *pLeft,*pRight;
	ExprList *pList;
	Token token,span;
	int iTable,iColumn;
	AggInfo *pAggInfo;
	int iAgg,iRightJoinTable;
	Select *pSelect;
	Table *pTab;
	Schema *pSchema;
#if WN_SQL_MAX_EXPR_DEPTH>0
	int nHeight;
#endif
};
#define EP_FromJoin 0x01
#define EP_Agg 0x02
#define EP_Resolved 0x04
#define EP_Error 0x08
#define EP_Distinct 0x10
#define EP_VarSelect 0x20
#define EP_Dequoted 0x40
#define EP_InfixFunc 0x80
#define EP_ExpCollate 0x100
#define ExprHasProperty(E,P)(((E)->flags&(P))==(P))
#define ExprHasAnyProperty(E,P)(((E)->flags&(P)))
#define ExprSetProperty(E,P)(E)->flags|=(P)
#define ExprClearProperty(E,P)(E)->flags&=~(P)
struct ExprList
{
	int nExpr,nAlloc,iECursor;
	struct ExprList_item
	{
		Expr *pExpr;
		char *zName;
		u8 sortOrder,isAgg,done;
	}*a;
};
struct IdList
{
	struct IdList_item
	{
		char *zName;
		int idx;
	}*a;
	int nId,nAlloc;
};
typedef u64 Bitmask;
struct SrcList
{
	i16 nSrc,nAlloc;
	struct SrcList_item
	{
		char *zDatabase,*zName,*zAlias;
		Table *pTab;
		Select *pSelect;
		u8 isPopulated,jointype;
		int iCursor;
		Expr *pOn;
		IdList *pUsing;
		Bitmask colUsed;
	}a[1];
};
#define JT_INNER 0x0001
#define JT_CROSS 0x0002
#define JT_NATURAL 0x0004
#define JT_LEFT 0x0008
#define JT_RIGHT 0x0010
#define JT_OUTER 0x0020
#define JT_ERROR 0x0040
struct WhereLevel
{
	int iFrom,flags,iMem,iLeftJoin;
	Index *pIdx;
	int iTabCur,iIdxCur,brk,nxt,cont,top,op,p1,p2,nEq,nIn;
	struct InLoop
	{
		int iCur,topAddr;
	}*aInLoop;
	WN_SQL3_index_info *pBestIdx;
	WN_SQL3_index_info *pIdxInfo;
};
struct WhereInfo
{
	Parse *pParse;
	SrcList *pTabList;
	int iTop,iContinue,iBreak,nLevel;
	WN_SQL3_index_info **apInfo;
	WhereLevel a[1];
};
struct NameContext
{
	Parse *pParse;
	SrcList *pSrcList;
	ExprList *pEList;
	int nRef,nErr;
	u8 allowAgg,hasAgg,isCheck;
	int nDepth;
	AggInfo *pAggInfo;
	NameContext *pNext;
};
struct Select
{
	ExprList *pEList;
	u8 op,isDistinct,isResolved,isAgg,usesEphm,disallowOrderBy;
	char affinity;
	SrcList *pSrc;
	Expr *pWhere;
	ExprList *pGroupBy;
	Expr *pHaving;
	ExprList *pOrderBy;
	Select *pPrior;
	Select *pRightmost;
	Expr *pLimit;
	Expr *pOffset;
	int iLimit,iOffset,addrOpenEphm[3];
};
#define SRT_Union 1
#define SRT_Except 2
#define SRT_Discard 3
#define IgnorableOrderby(X)(X<=SRT_Discard)
#define SRT_Callback 4
#define SRT_Mem 5
#define SRT_Set 6
#define SRT_Table 7
#define SRT_EphemTab 8
#define SRT_Subroutine 9
#define SRT_Exists 10
struct Parse
{
	WN_SQL3 *db;
	int rc;
	char *zErrMsg;
	Vdbe *pVdbe;
	u8 colNamesSet,nameClash,checkSchema,nested,parseError;
	int nErr,nTab,nMem,nSet,ckOffset;
	u32 writeMask,cookieMask;
	int cookieGoto,cookieValue[WN_SQL_MAX_ATTACHED+2];
#ifndef WN_SQL_OMIT_SHARED_CACHE
	int nTableLock;
	TableLock *aTableLock;
#endif
	int nVar,nVarExpr,nVarExprAlloc;
	Expr **apVarExpr;
	u8 explain;
	Token sErrToken,sNameToken,sLastToken;
	const char *zSql,*zTail;
	Table *pNewTable;
	Trigger *pNewTrigger;
	TriggerStack *trigStack;
	const char *zAuthContext;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	Token sArg;
	u8 declareVtab;
	Table *pVirtualLock;
#endif
#if WN_SQL_MAX_EXPR_DEPTH>0
	int nHeight;
#endif
};
#ifdef WN_SQL_OMIT_VIRTUALTABLE
#define IN_DECLARE_VTAB 0
#else
#define IN_DECLARE_VTAB(pParse->declareVtab)
#endif
struct AuthContext
{
	const char *zAuthContext;
	Parse *pParse;
};
#define OPFLAG_NCHANGE 1
#define OPFLAG_LASTROWID 2
#define OPFLAG_ISUPDATE 4
#define OPFLAG_APPEND 8
struct Trigger
{
	char *name,*table;
	u8 op,tr_tm;
	Expr *pWhen;
	IdList *pColumns;
	Token nameToken;
	Schema *pSchema,*pTabSchema;
	TriggerStep *step_list;
	Trigger *pNext;
};
#define TRIGGER_BEFORE 1
#define TRIGGER_AFTER 2
struct TriggerStep
{
	int op,orconf;
	Trigger *pTrig;
	Select *pSelect;
	Token target;
	Expr *pWhere;
	ExprList *pExprList;
	IdList *pIdList;
	TriggerStep *pNext,*pLast;
};
struct TriggerStack
{
	Table *pTab;
	int newIdx,oldIdx,orconf,ignoreJump;
	Trigger *pTrigger;
	TriggerStack *pNext;
};
typedef struct DbFixer DbFixer;
struct DbFixer
{
	Parse *pParse;
	const char *zDb,*zType;
	const Token *pName;
};
typedef struct
{
	WN_SQL3 *db;
	int iDb;
	char **pzErrMsg;
	int rc;
}InitData;
extern int WN_SQL3_always_code_trigger_setup;
extern const unsigned char WN_SQL3UtfTrans1[];
#define WN_SQL_READ_UTF8(zIn,c) {\
c=*(zIn++);\
if(c>=0xc0){\
c=WN_SQL3UtfTrans1[c-0xc0];\
while((*zIn & 0xc0)==0x80){\
c=(c<<6)+(0x3f & *(zIn++));\
}\
if(c<0x80 \
||(c&0xFFFFF800)==0xD800 \
||(c&0xFFFFFFFE)==0xFFFE){c=0xFFFD;}\
}\
}
#define WN_SQL_SKIP_UTF8(zIn){\
if((*(zIn++))>=0xc0){\
while((*zIn & 0xc0)==0x80){zIn++;}\
}\
}
#ifdef WN_SQL_DEBUG
int WN_SQL3Corrupt(void);
# define WN_SQL_CORRUPT_BKPT WN_SQL3Corrupt()
#else
# define WN_SQL_CORRUPT_BKPT WN_SQL_CORRUPT
#endif
# define WN_SQL3CheckMemory(a,b)
#if !defined(WN_SQL_OMIT_VIEW)|| !defined(WN_SQL_OMIT_VIRTUALTABLE)
int WN_SQL3ViewGetColumnNames(Parse*,Table*);
#else
# define WN_SQL3ViewGetColumnNames(A,B)0
#endif
#ifndef WN_SQL_OMIT_TRIGGER
#else
# define WN_SQL3TriggersExist(A,B,C,D,E,F)0
# define WN_SQL3DeleteTrigger(A)
# define WN_SQL3DropTriggerPtr(A,B)
# define WN_SQL3UnlinkAndDeleteTrigger(A,B,C)
# define WN_SQL3CodeRowTrigger(A,B,C,D,E,F,G,H,I)0
#endif
#ifndef WN_SQL_OMIT_AUTHORIZATION
#else
# define WN_SQL3AuthRead(a,b,c)
# define WN_SQL3AuthCheck(a,b,c,d,e)0
# define WN_SQL3AuthContextPush(a,b,c)
# define WN_SQL3AuthContextPop(a)((void)(a))
#endif
extern const unsigned char WN_SQL3UpperToLower[];
#ifndef WN_SQL_OMIT_LOAD_EXTENSION
void WN_SQL3CloseExtensions(WN_SQL3*);
int WN_SQL3AutoLoadExtensions(WN_SQL3*);
#else
# define WN_SQL3CloseExtensions(X)
# define WN_SQL3AutoLoadExtensions(X)0
#endif
#ifndef WN_SQL_OMIT_SHARED_CACHE
void WN_SQL3TableLock(Parse *,int,int,u8,const char *);
#else
#define WN_SQL3TableLock(v,w,x,y,z)
#endif
#ifdef WN_SQL_TEST
int WN_SQL3Utf8To8(unsigned char*);
#endif
#ifdef WN_SQL_MEMDEBUG
void WN_SQL3MallocDisallow(void);
void WN_SQL3MallocAllow(void);
int WN_SQL3TestMallocFail(void);
#else
#define WN_SQL3TestMallocFail()0
#define WN_SQL3MallocDisallow()
#define WN_SQL3MallocAllow()
#endif
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
void *WN_SQL3ThreadSafeMalloc(int);
void WN_SQL3ThreadSafeFree(void *);
#else
#define WN_SQL3ThreadSafeMalloc WN_SQL3MallocX
#define WN_SQL3ThreadSafeFree WN_SQL3FreeX
#endif
#ifdef WN_SQL_OMIT_VIRTUALTABLE
# define WN_SQL3VtabClear(X)
# define WN_SQL3VtabSync(X,Y)(Y)
# define WN_SQL3VtabRollback(X)
# define WN_SQL3VtabCommit(X)
#else
#endif
#if WN_SQL_MAX_EXPR_DEPTH>0
void WN_SQL3ExprSetHeight(Expr *);
int WN_SQL3SelectExprHeight(Select *);
#else
#define WN_SQL3ExprSetHeight(x)
#endif
#ifdef WN_SQL_SSE
#include "sseInt.h"
#endif
#ifdef WN_SQL_DEBUG
void WN_SQL3ParserTrace(FILE*,char *);
#endif
#ifdef WN_SQL_ENABLE_IOTRACE
# define IOTRACE(A)if(WN_SQL3_io_trace){WN_SQL3_io_trace A;}
void WN_SQL3VdbeIOTraceSql(Vdbe*);
#else
# define IOTRACE(A)
# define WN_SQL3VdbeIOTraceSql(X)
#endif
extern void(*WN_SQL3_io_trace)(const char*,...);
#endif
#include "WINNER_Date_Time.cpp"
#include<ctype.h>
int WN_SQL3OsClose(OsFile **pId)
{
	OsFile *id;
	if(pId &&(id=*pId))
		return id->pMethod->xClose(pId);
	else
		return 0;
}
int WN_SQL3OsOpenDirectory(OsFile *id,const char *zName)
{
	return id->pMethod->xOpenDirectory(id,zName);
}
int WN_SQL3OsRead(OsFile *id,void *pBuf,int amt)
{
	return id->pMethod->xRead(id,pBuf,amt);
}
int WN_SQL3OsWrite(OsFile *id,const void *pBuf,int amt)
{
	return id->pMethod->xWrite(id,pBuf,amt);
}
int WN_SQL3OsSeek(OsFile *id,i64 offset)
{
	return id->pMethod->xSeek(id,offset);
}
int WN_SQL3OsTruncate(OsFile *id,i64 size)
{
	return id->pMethod->xTruncate(id,size);
}
int WN_SQL3OsSync(OsFile *id,int fullsync)
{
	return id->pMethod->xSync(id,fullsync);
}
void WN_SQL3OsSetFullSync(OsFile *id,int value)
{
	id->pMethod->xSetFullSync(id,value);
}
int WN_SQL3OsFileSize(OsFile *id,i64 *pSize)
{
	return id->pMethod->xFileSize(id,pSize);
}
int WN_SQL3OsLock(OsFile *id,int lockType)
{
	return id->pMethod->xLock(id,lockType);
}
int WN_SQL3OsUnlock(OsFile *id,int lockType)
{
	return id->pMethod->xUnlock(id,lockType);
}
int WN_SQL3OsCheckReservedLock(OsFile *id)
{
	return id->pMethod->xCheckReservedLock(id);
}
int WN_SQL3OsSectorSize(OsFile *id)
{
	int(*xSectorSize)(OsFile*)=id->pMethod->xSectorSize;
return xSectorSize ? xSectorSize(id):WN_SQL_DEFAULT_SECTOR_SIZE;
}
#if defined(WN_SQL_TEST)|| defined(WN_SQL_DEBUG)
int WN_SQL3OsFileHandle(OsFile *id)
{
	return id->pMethod->xFileHandle(id);
}
int WN_SQL3OsLockState(OsFile *id)
{
	return id->pMethod->xLockState(id);
}
#endif
#ifdef WN_SQL_ENABLE_REDEF_IO
struct WN_SQL3OsVtbl *WN_SQL3_os_switch(void)
{
	return &WN_SQL3Os;
}
#endif
#define MAX(x,y)((x)>(y)?(x):(y))
#if defined(WN_SQL_ENABLE_MEMORY_MANAGEMENT)&& !defined(WN_SQL_OMIT_DISKIO)
void WN_SQL3_soft_heap_limit(int n)
{
	ThreadData *pTd=WN_SQL3ThreadData();
	if(pTd)pTd->nSoftHeapLimit=n;
	WN_SQL3ReleaseThreadData();
}
int WN_SQL3_release_memory(int n)
{
	return WN_SQL3PagerReleaseMemory(n);
}
#else
#define WN_SQL3_release_memory(x) 0
#endif
#ifdef WN_SQL_MEMDEBUG
#if defined(__GLIBC__)&& WN_SQL_MEMDEBUG>2
extern int backtrace(void **,int);
#define TESTALLOC_STACKSIZE 128
#define TESTALLOC_STACKFRAMES((TESTALLOC_STACKSIZE-8)/sizeof(void*))
#else
#define backtrace(x,y)
#define TESTALLOC_STACKSIZE 0
#define TESTALLOC_STACKFRAMES 0
#endif
#ifndef TESTALLOC_NGUARD
# define TESTALLOC_NGUARD 2
#endif
#define TESTALLOC_FILESIZE 64
#define TESTALLOC_USERSIZE 64
const char *WN_SQL3_malloc_id=0;
#define TESTALLOC_OFFSET_GUARD1(p)(sizeof(void *)* 2)
#define TESTALLOC_OFFSET_DATA(p)(\
TESTALLOC_OFFSET_GUARD1(p)+sizeof(u32)* TESTALLOC_NGUARD \
)
#define TESTALLOC_OFFSET_GUARD2(p)(\
TESTALLOC_OFFSET_DATA(p)+WN_SQL3OsAllocationSize(p)-TESTALLOC_OVERHEAD \
)
#define TESTALLOC_OFFSET_LINENUMBER(p)(\
TESTALLOC_OFFSET_GUARD2(p)+sizeof(u32)* TESTALLOC_NGUARD \
)
#define TESTALLOC_OFFSET_FILENAME(p)(\
TESTALLOC_OFFSET_LINENUMBER(p)+sizeof(u32)\
)
#define TESTALLOC_OFFSET_USER(p) (\
TESTALLOC_OFFSET_FILENAME(p)+TESTALLOC_FILESIZE \
)
#define TESTALLOC_OFFSET_STACK(p)(\
TESTALLOC_OFFSET_USER(p)+TESTALLOC_USERSIZE+8-\
(TESTALLOC_OFFSET_USER(p)% 8)\
)
#define TESTALLOC_OVERHEAD (\
sizeof(void *)*2+\
TESTALLOC_NGUARD*sizeof(u32)*2+\
sizeof(u32)+TESTALLOC_FILESIZE+\
TESTALLOC_USERSIZE+\
TESTALLOC_STACKSIZE \
)
int WN_SQL3_nMalloc;
int WN_SQL3_nFree;
int WN_SQL3_memUsed;
int WN_SQL3_memMax;
int WN_SQL3_iMallocFail;
int WN_SQL3_iMallocReset=-1;
void *WN_SQL3_pFirst=0;
int WN_SQL3_nMaxAlloc=0;
int WN_SQL3_mallocDisallowed=0;
int WN_SQL3_isFail=0;
const char *WN_SQL3_zFile=0;
int WN_SQL3_iLine=0;
int WN_SQL3_mallocfail_trace=0;
int WN_SQL3TestMallocFail()
{
	if(WN_SQL3_isFail)return 1;
	if(WN_SQL3_iMallocFail>=0)
	{
		WN_SQL3_iMallocFail--;
		if(WN_SQL3_iMallocFail==0)
		{
			WN_SQL3_iMallocFail=WN_SQL3_iMallocReset;
			WN_SQL3_isFail=1;
			if(WN_SQL3_mallocfail_trace)WN_SQL3DebugPrintf("###_malloc_fails_###\n");
			return 1;
		}
	}
	return 0;
}
void checkGuards(u32 *p)
{
	int i;
	char *zAlloc=(char *)p;
	char *z=&zAlloc[TESTALLOC_OFFSET_GUARD1(p)];
	for(i=0;i<TESTALLOC_NGUARD;i++);
	z=&zAlloc[TESTALLOC_OFFSET_GUARD2(p)];
	for(i=0;i<TESTALLOC_NGUARD;i++)
	{
		u32 guard=0;
		memcpy(&guard,&z[i*sizeof(u32)],sizeof(u32));
	}
}
void applyGuards(u32 *p)
{
	int i;
	char *zAlloc=(char *)p,*z=&zAlloc[TESTALLOC_OFFSET_GUARD1(p)];
	for(i=0;i<TESTALLOC_NGUARD;i++)((u32 *)z)[i]=0xdead1122;
	z=&zAlloc[TESTALLOC_OFFSET_GUARD2(p)];
	for(i=0;i<TESTALLOC_NGUARD;i++)
	{
		const int guard=0xdead3344;
		memcpy(&z[i*sizeof(u32)],&guard,sizeof(u32));
	}
	z=&((char *)z)[TESTALLOC_NGUARD*sizeof(u32)];
	z=&zAlloc[TESTALLOC_OFFSET_LINENUMBER(p)];
	memcpy(z,&WN_SQL3_iLine,sizeof(u32));
	z=&zAlloc[TESTALLOC_OFFSET_FILENAME(p)];
	strncpy(z,WN_SQL3_zFile,TESTALLOC_FILESIZE);
	z[TESTALLOC_FILESIZE-1]='\0';
	z=&zAlloc[TESTALLOC_OFFSET_USER(p)];
	z[0]=0;
	if(WN_SQL3_malloc_id)
	{
		strncpy(z,WN_SQL3_malloc_id,TESTALLOC_USERSIZE);
		z[TESTALLOC_USERSIZE-1]=0;
	}
	z=&zAlloc[TESTALLOC_OFFSET_STACK(p)];
	backtrace((void **)z,TESTALLOC_STACKFRAMES);
	checkGuards(p);
}
void *getOsPointer(void *p)
{
	char *z=(char *)p;
	return(void *)(&z[-1 * TESTALLOC_OFFSET_DATA(p)]);
}
#if WN_SQL_MEMDEBUG>1
void linkAlloc(void *p)
{
	void **pp=(void **)p;
	pp[0]=0;
	pp[1]=WN_SQL3_pFirst;
	if(WN_SQL3_pFirst)((void **)WN_SQL3_pFirst)[0]=p;
	WN_SQL3_pFirst=p;
}
void unlinkAlloc(void *p)
{
	void **pp=(void **)p;
	if(p==WN_SQL3_pFirst)
	{
		WN_SQL3_pFirst=pp[1];
		if(WN_SQL3_pFirst)((void **)WN_SQL3_pFirst)[0]=0;
	}
	else
	{
		void **pprev=pp[0];
		void **pnext=pp[1];
		pprev[1]=(void *)pnext;
		if(pnext)pnext[0]=(void *)pprev;
	}
}
void relinkAlloc(void *p)
{
	void **pp=(void **)p;
	if(pp[0])
		((void **)(pp[0]))[1]=p;
	else
		WN_SQL3_pFirst=p;
	if(pp[1])((void **)(pp[1]))[0]=p;
}
#else
#define linkAlloc(x)
#define relinkAlloc(x)
#define unlinkAlloc(x)
#endif
#if defined(TCLSH)&& defined(WN_SQL_DEBUG)&& WN_SQL_MEMDEBUG>1
int WN_SQL3OutstandingMallocs(Tcl_Interp *interp)
{
	void *p;
	Tcl_Obj *pRes=Tcl_NewObj();
	Tcl_IncrRefCount(pRes);
	for(p=WN_SQL3_pFirst;p;p=((void **)p)[1])
	{
		Tcl_Obj *pEntry=Tcl_NewObj(),*pStack=Tcl_NewObj();
		char *z;
		u32 iLine;
		int nBytes=WN_SQL3OsAllocationSize(p)-TESTALLOC_OVERHEAD;
		char *zAlloc=(char *)p;
		int i;
		Tcl_ListObjAppendElement(0,pEntry,Tcl_NewIntObj(nBytes));
		z=&zAlloc[TESTALLOC_OFFSET_FILENAME(p)];
		Tcl_ListObjAppendElement(0,pEntry,Tcl_NewStringObj(z,-1));
		z=&zAlloc[TESTALLOC_OFFSET_LINENUMBER(p)];
		memcpy(&iLine,z,sizeof(u32));
		Tcl_ListObjAppendElement(0,pEntry,Tcl_NewIntObj(iLine));
		z=&zAlloc[TESTALLOC_OFFSET_USER(p)];
		Tcl_ListObjAppendElement(0,pEntry,Tcl_NewStringObj(z,-1));
		z=&zAlloc[TESTALLOC_OFFSET_STACK(p)];
		for(i=0;i<TESTALLOC_STACKFRAMES;i++)
		{
			char zHex[128];
			WN_SQL3_snprintf(sizeof(zHex),zHex,"%p",((void **)z)[i]);
			Tcl_ListObjAppendElement(0,pStack,Tcl_NewStringObj(zHex,-1));
		}
		Tcl_ListObjAppendElement(0,pEntry,pStack);
		Tcl_ListObjAppendElement(0,pRes,pEntry);
	}
	Tcl_ResetResult(interp);
	Tcl_SetObjResult(interp,pRes);
	Tcl_DecrRefCount(pRes);
	return TCL_OK;
}
#endif
void * OSMALLOC(int n)
{
	WN_SQL3OsEnterMutex();
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
	WN_SQL3_nMaxAlloc=MAX(WN_SQL3_nMaxAlloc,WN_SQL3ThreadDataReadOnly()->nAlloc);
#endif
	if(!WN_SQL3TestMallocFail())
	{
		u32 *p;
		p=(u32 *)WN_SQL3OsMalloc(n+TESTALLOC_OVERHEAD);
		WN_SQL3_nMalloc++;
		applyGuards(p);
		linkAlloc(p);
		WN_SQL3OsLeaveMutex();
		return(void *)(&p[TESTALLOC_NGUARD+2*sizeof(void *)/sizeof(u32)]);
	}
	WN_SQL3OsLeaveMutex();
	return 0;
}
int OSSIZEOF(void *p)
{
	if(p)
	{
		u32 *pOs=(u32 *)getOsPointer(p);
		return WN_SQL3OsAllocationSize(pOs)-TESTALLOC_OVERHEAD;
	}
	return 0;
}
void OSFREE(void *pFree)
{
	u32 *p;
	WN_SQL3OsEnterMutex();
	p=(u32 *)getOsPointer(pFree);
	checkGuards(p);
	unlinkAlloc(p);
	memset(pFree,0x55,OSSIZEOF(pFree));
	WN_SQL3OsFree(p);
	WN_SQL3_nFree++;
	WN_SQL3OsLeaveMutex();
}
void * OSREALLOC(void *pRealloc,int n)
{
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
	WN_SQL3_nMaxAlloc=MAX(WN_SQL3_nMaxAlloc,WN_SQL3ThreadDataReadOnly()->nAlloc);
#endif
	if(!WN_SQL3TestMallocFail())
	{
		u32 *p=(u32 *)getOsPointer(pRealloc);
		checkGuards(p);
		p=WN_SQL3OsRealloc(p,n+TESTALLOC_OVERHEAD);
		applyGuards(p);
		relinkAlloc(p);
		return(void *)(&p[TESTALLOC_NGUARD+2*sizeof(void *)/sizeof(u32)]);
	}
	return 0;
}
void OSMALLOC_FAILED()
{
	WN_SQL3_isFail=0;
}
#else
#define OSMALLOC(x) WN_SQL3OsMalloc(x)
#define OSREALLOC(x,y) WN_SQL3OsRealloc(x,y)
#define OSFREE(x) WN_SQL3OsFree(x)
#define OSSIZEOF(x) WN_SQL3OsAllocationSize(x)
#define OSMALLOC_FAILED()
#endif
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
int enforceSoftLimit(int n)
{
	ThreadData *pTsd=WN_SQL3ThreadData();
	if(pTsd==0)return 0;
	if(n>0 && pTsd->nSoftHeapLimit>0)
		while(pTsd->nAlloc+n>pTsd->nSoftHeapLimit && WN_SQL3_release_memory(n));
	return 1;
}
#else
# define enforceSoftLimit(X)1
#endif
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
void updateMemoryUsedCount(int n)
{
	ThreadData *pTsd=WN_SQL3ThreadData();
	if(pTsd)
	{
		pTsd->nAlloc+=n;
		if(pTsd->nAlloc==0 && pTsd->nSoftHeapLimit==0)WN_SQL3ReleaseThreadData();
	}
}
#else
#define updateMemoryUsedCount(x)
#endif
void *WN_SQL3MallocRaw(int n,int doMemManage)
{
	void *p=0;
	if(n>0 && !WN_SQL3MallocFailed()&&(!doMemManage || enforceSoftLimit(n)))
		while((p=OSMALLOC(n))==0 && WN_SQL3_release_memory(n));
		if(p)
			if(doMemManage)	updateMemoryUsedCount(OSSIZEOF(p));
		else
		{
			WN_SQL3FailedMalloc();
			OSMALLOC_FAILED();
		}
	return p;
}
void *WN_SQL3Realloc(void *p,int n)
{
	if(WN_SQL3MallocFailed())return 0;
	if(p)
	{
		void *np=0;
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
int origSize=OSSIZEOF(p);
#endif
		if(enforceSoftLimit(n-origSize))
			while((np=OSREALLOC(p,n))==0 && WN_SQL3_release_memory(n));
			if(np)
				updateMemoryUsedCount(OSSIZEOF(np)-origSize);
			else
			{
				WN_SQL3FailedMalloc();
				OSMALLOC_FAILED();
			}
		return np;
	}
	else
		return WN_SQL3Malloc(n,1);
}
void WN_SQL3FreeX(void *p)
{
	if(p)
	{
		updateMemoryUsedCount(0-OSSIZEOF(p));
		OSFREE(p);
	}
}
void *WN_SQL3Malloc(int n,int doMemManage)
{
	void *p=WN_SQL3MallocRaw(n,doMemManage);
	if(p)memset(p,0,n);
	return p;
}
void *WN_SQL3ReallocOrFree(void *p,int n)
{
	void *pNew=WN_SQL3Realloc(p,n);
	if(!pNew)WN_SQL3FreeX(p);
	return pNew;
}
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
void *WN_SQL3ThreadSafeMalloc(int n)
{
	(void)ENTER_MALLOC;
	return WN_SQL3Malloc(n,0);
}
void WN_SQL3ThreadSafeFree(void *p)
{
	(void)ENTER_MALLOC;
	if(p)OSFREE(p);
}
#endif
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
int WN_SQL3AllocSize(void *p){
return OSSIZEOF(p);
}
#endif
char *WN_SQL3StrDup(const char *z)
{
	if(z==0)return 0;
	int n=strlen(z)+1;
	char *zNew=WN_SQL3MallocRaw(n,1);
	if(zNew)memcpy(zNew,z,n);
	return zNew;
}
char *WN_SQL3StrNDup(const char *z,int n)
{
	if(z==0)return 0;
	char *zNew=WN_SQL3MallocRaw(n+1,1);
	if(zNew)
	{
		memcpy(zNew,z,n);
		zNew[n]=0;
	}
	return zNew;
}
void WN_SQL3SetString(char **pz,...)
{
	va_list ap;
	int nByte=1;
	const char *z;
	char *zResult;
	va_start(ap,pz);
	while((z=va_arg(ap,const char*)))nByte+=strlen(z);
	va_end(ap);
	WN_SQL3FreeX(*pz);
	*pz=zResult=WN_SQLMallocRaw(nByte);
	if(zResult==0)return;
	*zResult=0;
	va_start(ap,pz);
	while((z=va_arg(ap,const char*)))
	{
		int n=strlen(z);
		memcpy(zResult,z,n);
		zResult+=n;
	}
	zResult[0]=0;
	va_end(ap);
}
int WN_SQL3_mallocHasFailed=0;
int WN_SQL3ApiExit(WN_SQL3* db,int rc)
{
	if(WN_SQL3MallocFailed())
	{
		WN_SQL3_mallocHasFailed=0;
		WN_SQL3OsLeaveMutex();
		WN_SQL3Error(db,WN_SQL_NOMEM,0);
		rc=WN_SQL_NOMEM;
	}
	return rc &(db ? db->errMask :0xff);
}
void WN_SQL3FailedMalloc()
{
	if(!WN_SQL3MallocFailed())
	{
		WN_SQL3OsEnterMutex();
		WN_SQL3_mallocHasFailed=1;
	}
}
#ifdef WN_SQL_MEMDEBUG
void WN_SQL3MallocDisallow()
{
	WN_SQL3_mallocDisallowed++;
}
void WN_SQL3MallocAllow()
{
	WN_SQL3_mallocDisallowed--;
}
#endif
#include<math.h>
#define etRADIX 1
#define etFLOAT 2
#define etEXP 3
#define etGENERIC 4
#define etSIZE 5
#define etSTRING 6
#define etDYNSTRING 7
#define etPERCENT 8
#define etCHARX 9
#define etCHARLIT 10
#define etSQLESCAPE 11
#define etSQLESCAPE2 12
#define etTOKEN 13
#define etSRCLIST 14
#define etPOINTER 15
#define etSQLESCAPE3 16
typedef unsigned char etByte;
typedef struct et_info
{
	char fmttype;
	etByte base,flags,type,charset,prefix;
}et_info;
#define FLAG_SIGNED 1
#define FLAG_INTERN 2
#define FLAG_STRING 4
const char aDigits[]="0123456789ABCDEF0123456789abcdef";
const char aPrefix[]="-x0\000X0";
const et_info fmtinfo[]={{'d',10,1,etRADIX,0,0},{'s',0,4,etSTRING,0,0},{'g',0,1,etGENERIC,30,0},{'z',0,6,etDYNSTRING,0,0},{'q',0,4,etSQLESCAPE,0,0},{'Q',0,4,etSQLESCAPE2,0,0},{'w',0,4,etSQLESCAPE3,0,0},{'c',0,0,etCHARX,0,0},{'o',8,0,etRADIX,0,2},{'u',10,0,etRADIX,0,0},{'x',16,0,etRADIX,16,1},{'X',16,0,etRADIX,0,4},#ifndef WN_SQL_OMIT_FLOATING_POINT
{'f',0,1,etFLOAT,0,0},{'e',0,1,etEXP,30,0},{'E',0,1,etEXP,14,0},{'G',0,1,etGENERIC,14,0},#endif
{'i',10,1,etRADIX,0,0},{'n',0,0,etSIZE,0,0},{'%',0,0,etPERCENT,0,0},{'p',16,0,etPOINTER,0,1},{'T',0,2,etTOKEN,0,0},{'S',0,2,etSRCLIST,0,0},};
#define etNINFO(sizeof(fmtinfo)/sizeof(fmtinfo[0]))
#ifndef WN_SQL_OMIT_FLOATING_POINT
int et_getdigit(LONGDOUBLE_TYPE *val,int *cnt)
{
	if((*cnt)++>=16)return '0';
	int digit=(int)*val;
	LONGDOUBLE_TYPE d=digit;
	digit+='0';
	*val=(*val-d)*10.0;
	return digit;
}
#endif
# define WN_SQL_PRINT_BUF_SIZE 350
#define etBUFSIZE WN_SQL_PRINT_BUF_SIZE
int vxprintf(void(*func)(void*,const char*,int),void *arg,int useExtended,const char *fmt,va_list ap)
{
	char *bufpt;
	int precision,length,idx,count,width,c;
	etByte flag_leftjustify,flag_plussign,flag_blanksign,flag_alternateform,flag_altform2,flag_zeropad,flag_long,flag_longlong,done;
	WN_SQL_uint64 longvalue;
	LONGDOUBLE_TYPE realvalue;
	const et_info *infop;
	char buf[etBUFSIZE],prefix;
	etByte errorflag=0,xtype;
	char *zExtra;
	const char spaces[]=" ";
#define etSPACESIZE(sizeof(spaces)-1)
#ifndef WN_SQL_OMIT_FLOATING_POINT
	int exp,e2;
	double rounder;
	etByte flag_dp,flag_rtz,flag_exp;
	int nsd;
#endif
	func(arg,"",0);
	count=length=0;
	bufpt=0;
	for(;(c=(*fmt));++fmt)
	{
		if(c!='%')
		{
			bufpt=(char *)fmt;
			int amt=1;
			while((c=(*++fmt))!='%' && c)amt++;
			(*func)(arg,bufpt,amt);
			count+=amt;
			if(c==0)break;
		}
		if((c=(*++fmt))==0)
		{
			errorflag=1;
			(*func)(arg,"%",1);
			count++;
			break;
		}
		flag_leftjustify=flag_plussign=flag_blanksign=flag_alternateform=flag_altform2=flag_zeropad=0;
		done=0;
		do
		{
			switch(c)
			{
			case '-':
				flag_leftjustify=1;
				break;
			case '+':
				flag_plussign=1;
				break;
			case ' ':
				flag_blanksign=1;
				break;
			case '#':
				flag_alternateform=1;
				break;
			case '!':
				flag_altform2=1;
				break;
			case '0':
				flag_zeropad=1;
				break;
			default:
				done=1;
				break;
			}
		}while(!done &&(c=(*++fmt)));
		width=0;
		if(c=='*')
		{
			width=va_arg(ap,int);
			if(width<0)
			{
				flag_leftjustify=1;
				width=-width;
			}
			c=*++fmt;
		}
		else
			while(c>='0' && c<='9')
			{
				width=width*10+c-'0';
				c=*++fmt;
			}
		if(width > etBUFSIZE-10)width=etBUFSIZE-10;
		if(c=='.')
		{
			precision=0;
			c=*++fmt;
			if(c=='*')
			{
				precision=va_arg(ap,int);
				if(precision<0)precision=-precision;
				c=*++fmt;
			}
			else
				while(c>='0' && c<='9')
				{
					precision=precision*10+c-'0';
					c=*++fmt;
				}
		}
		else
			precision=-1;
		if(c=='l')
		{
			flag_long=1;
			c=*++fmt;
			if(c=='l')
			{
				flag_longlong=1;
				c=*++fmt;
			}
			else
				flag_longlong=0;
		}
		else
			flag_long=flag_longlong=0;
		infop=0;
		for(idx=0;idx<etNINFO;idx++)
			if(c==fmtinfo[idx].fmttype)
			{
				infop=&fmtinfo[idx];
				if(useExtended ||(infop->flags & FLAG_INTERN)==0)
					xtype=infop->type;
				else
					return-1;
				break;
			}
			zExtra=0;
			if(infop==0)return-1;
			if(precision>etBUFSIZE-40 &&(infop->flags & FLAG_STRING)==0)precision=etBUFSIZE-40;
			switch(xtype)
			{
			case etPOINTER:
				flag_longlong=sizeof(char*)==sizeof(i64);
				flag_long=sizeof(char*)==sizeof(long int);
			case etRADIX:
				if(infop->flags & FLAG_SIGNED)
				{
					i64 v;
					if(flag_longlong)
						v=va_arg(ap,i64);
					else
						if(flag_long)
							v=va_arg(ap,long int);
						else
							v=va_arg(ap,int);
					if(v<0)
					{
						longvalue=-v;
						prefix='-';
					}
					else
					{
						longvalue=v;
						if(flag_plussign)
							prefix='+';
						else
							if(flag_blanksign)
								prefix=' ';
							else
								prefix=0;
					}
				}
				else
				{
					if(flag_longlong)
						longvalue=va_arg(ap,u64);
					else
						if(flag_long)
							longvalue=va_arg(ap,unsigned long int);
						else
							longvalue=va_arg(ap,u32);
					prefix=0;
				}
				if(longvalue==0)flag_alternateform=0;
				if(flag_zeropad && precision<width-(prefix))precision=width-(prefix!=0);
				bufpt=&buf[etBUFSIZE-1];
				register const char *cset;
				register int base;
				cset=&aDigits[infop->charset];
				base=infop->base;
				do
				{
					*(--bufpt)=cset[longvalue%base];
					longvalue=longvalue/base;
				}while(longvalue>0);
				length=&buf[etBUFSIZE-1]-bufpt;
				for(idx=precision-length;idx>0;idx--)*(--bufpt)='0';
				if(prefix)*(--bufpt)=prefix;
				if(flag_alternateform && infop->prefix)
				{
					char x;
					const char pre=&aPrefix[infop->prefix];
					if(*bufpt!=pre[0])for(;(x=(*pre));pre++)*(--bufpt)=x;
				}
				length=&buf[etBUFSIZE-1]-bufpt;
				break;
			case etFLOAT:
			case etEXP:
			case etGENERIC:
				realvalue=va_arg(ap,double);
#ifndef WN_SQL_OMIT_FLOATING_POINT
				if(precision<0)precision=6;
				if(precision>etBUFSIZE/2-10)precision=etBUFSIZE/2-10;
				if(realvalue<0.0)
				{
					realvalue=-realvalue;
					prefix='-';
				}
				else
					if(flag_plussign)
						prefix='+';
					else
						if(flag_blanksign)
							prefix=' ';
						else
							prefix=0;
				if(xtype==etGENERIC && precision>0)precision--;
				for(idx=precision,rounder=0.5;idx>0;idx--,rounder*=0.1);
				if(xtype==etFLOAT)realvalue+=rounder;
				exp=0;
				if(WN_SQL3_isnan(realvalue))
				{
					bufpt="NaN";
					length=3;
					break;
				}
				if(realvalue>0.0)
				{
					while(realvalue>=1e32 && exp<=350)
					{
						realvalue *=1e-32;
						exp+=32;
					}
					while(realvalue>=1e8 && exp<=350)
					{
						realvalue *=1e-8;
						exp+=8;
					}
					while(realvalue>=10.0 && exp<=350)
					{
						realvalue *=0.1;
						exp++;
					}
					while(realvalue<1e-8 && exp>=-350)
					{
						realvalue *=1e8;
						exp-=8;
					}
					while(realvalue<1.0 && exp>=-350)
					{
						realvalue *=10.0;
						exp--;
					}
					if(exp>350 || exp<-350)
					{
						if(prefix=='-')
							bufpt="-Inf";
						else
							if(prefix=='+')
								bufpt="+Inf";
							else
								bufpt="Inf";
						length=strlen(bufpt);
						break;
					}
				}
				bufpt=buf;
				flag_exp=xtype==etEXP;
				if(xtype!=etFLOAT)
				{
					realvalue+=rounder;
					if(realvalue>=10.0)
					{
						realvalue *=0.1;
						exp++;
					}
				}
				if(xtype==etGENERIC)
				{
					flag_rtz=!flag_alternateform;
					if(exp<-4 || exp>precision)
						xtype=etEXP;
					else
					{
						precision=precision-exp;
						xtype=etFLOAT;
					}
				}
				else
					flag_rtz=0;
				if(xtype==etEXP)
					e2=0;
				else
					e2=exp;
				nsd=0;
				flag_dp=(precision>0)| flag_alternateform | flag_altform2;
				if(prefix)*(bufpt++)=prefix;
				if(e2<0)
					*(bufpt++)='0';
				else
					for(;e2>=0;e2--)*(bufpt++)=et_getdigit(&realvalue,&nsd);
				if(flag_dp)*(bufpt++)='.';
				for(e2++;e2<0 && precision>0;precision--,e2++)*(bufpt++)='0';
				while((precision--)>0)*(bufpt++)=et_getdigit(&realvalue,&nsd);
				if(flag_rtz && flag_dp)
				{
					while(bufpt[-1]=='0')*(--bufpt)=0;
										if(bufpt[-1]=='.')
						if(flag_altform2)
							*(bufpt++)='0';
						else
							*(--bufpt)=0;
				}
				if(flag_exp ||(xtype==etEXP && exp))
				{
					*(bufpt++)=aDigits[infop->charset];
					if(exp<0)
						*(bufpt++)='-';exp=-exp;
					else
						*(bufpt++)='+';
					if(exp>=100)
					{
						*(bufpt++)=(exp/100)+'0';
						exp %=100;
					}
					*(bufpt++)=exp/10+'0';
					*(bufpt++)=exp%10+'0';
				}
				*bufpt=0;
				length=bufpt-buf;
				bufpt=buf;
				if(flag_zeropad && !flag_leftjustify && length<width)
				{
					int i,nPad=width-length;
					for(i=width;i>=nPad;i--)bufpt[i]=bufpt[i-nPad];
					i=prefix!=0;
					while(nPad--)bufpt[i++]='0';
					length=width;
				}
#endif
				break;
			case etSIZE:
				*(va_arg(ap,int*))=count;
				length=width=0;
				break;
			case etPERCENT:
				buf[0]='%';
				bufpt=buf;
				length=1;
				break;
			case etCHARLIT:
			case etCHARX:
				c=buf[0]=(xtype==etCHARX ? va_arg(ap,int):*++fmt);
				if(precision>=0)
				{
					for(idx=1;idx<precision;idx++)buf[idx]=c;
					length=precision;
				}
				else
					length=1;
				bufpt=buf;
				break;
			case etSTRING:
			case etDYNSTRING:
				bufpt=va_arg(ap,char*);
				if(bufpt==0)
					bufpt="";
				else
					if(xtype==etDYNSTRING)
						zExtra=bufpt;
					length=strlen(bufpt);
					if(precision>=0 && precision<length)length=precision;
					break;
			case etSQLESCAPE:
			case etSQLESCAPE2:
			case etSQLESCAPE3:
				int i,j,n,ch,isnull,needQuote;
				char q=((xtype==etSQLESCAPE3)?'"':'\''),*escarg=va_arg(ap,char*);
				isnull=escarg==0;
				if(isnull)escarg=(xtype==etSQLESCAPE2 ? "NULL" :"(NULL)");
				for(i=n=0;(ch=escarg[i]);i++)if(ch==q)n++;
				needQuote=!isnull && xtype==etSQLESCAPE2;
				n+=i+1+needQuote*2;
				if(n>etBUFSIZE)
				{
					bufpt=zExtra=WN_SQL3Malloc(n);
					if(bufpt==0)return-1;
				}
				else
					bufpt=buf;
				j=0;
				if(needQuote)bufpt[j++]=q;
				for(i=0;(ch=escarg[i]);i++)
				{
					bufpt[j++]=ch;
					if(ch==q)bufpt[j++]=ch;
				}
				if(needQuote)bufpt[j++]=q;
				bufpt[j]=0;
				length=j;
				break;
			case etTOKEN:
				Token *pToken=va_arg(ap,Token*);
				if(pToken && pToken->z)	(*func)(arg,(char*)pToken->z,pToken->n);
				length=width=0;
				break;
			case etSRCLIST:
				SrcList *pSrc=va_arg(ap,SrcList*);
				int k=va_arg(ap,int);
				struct SrcList_item *pItem=&pSrc->a[k];
				if(pItem->zDatabase && pItem->zDatabase[0])
				{
					(*func)(arg,pItem->zDatabase,strlen(pItem->zDatabase));
					(*func)(arg,".",1);
				}
				(*func)(arg,pItem->zName,strlen(pItem->zName));
				length=width=0;
			}
			if(!flag_leftjustify)
			{
				register int nspace;
				nspace=width-length;
				if(nspace>0)
				{
					count+=nspace;
					while(nspace>=etSPACESIZE)
					{
						(*func)(arg,spaces,etSPACESIZE);
						nspace-=etSPACESIZE;
					}
					if(nspace>0)(*func)(arg,spaces,nspace);
				}
			}
			if(length>0)
			{
				(*func)(arg,bufpt,length);
				count+=length;
			}
			if(flag_leftjustify)
			{
				register int nspace;
				nspace=width-length;
				if(nspace>0)
				{
					count+=nspace;
					while(nspace>=etSPACESIZE)
					{
						(*func)(arg,spaces,etSPACESIZE);
						nspace-=etSPACESIZE;
					}
					if(nspace>0)(*func)(arg,spaces,nspace);
				}
			}
			if(zExtra)WN_SQL3FreeX(zExtra);
		}
		return errorflag ?-1 :count;
}
struct sgMprintf
{
	char *zBase,*zText;
	int nChar,nTotal,nAlloc;
	void *(*xRealloc)(void*,int);
};
void mout(void *arg,const char *zNewText,int nNewChar)
{
	struct sgMprintf *pM=(struct sgMprintf*)arg;
	pM->nTotal+=nNewChar;
	if(pM->nChar+nNewChar+1 > pM->nAlloc)
	{
		if(pM->xRealloc==0)
			nNewChar=pM->nAlloc-pM->nChar-1;
		else
		{
			int nAlloc=pM->nChar+nNewChar*2+1;
			if(pM->zText==pM->zBase)
			{
				pM->zText=pM->xRealloc(0,nAlloc);
				if(pM->zText && pM->nChar)memcpy(pM->zText,pM->zBase,pM->nChar);
			}
			else
			{
				char *zNew=pM->xRealloc(pM->zText,nAlloc);
				if(zNew)
					pM->zText=zNew;
				else
					return;
			}
			pM->nAlloc=nAlloc;
		}
	}
	if(pM->zText)
	{
		if(nNewChar>0)
		{
			memcpy(&pM->zText[pM->nChar],zNewText,nNewChar);
			pM->nChar+=nNewChar;
		}
		pM->zText[pM->nChar]=0;
	}
}
char *base_vprintf(void *(*xRealloc)(void*,int),int useInternal,char *zInitBuf,int nInitBuf,const char *zFormat,va_list ap)
{
	struct sgMprintf sM;
	sM.zBase=sM.zText=zInitBuf;
	sM.nChar=sM.nTotal=0;
	sM.nAlloc=nInitBuf;
	sM.xRealloc=xRealloc;
	vxprintf(mout,&sM,useInternal,zFormat,ap);
	if(xRealloc)
		if(sM.zText==sM.zBase)
		{
			sM.zText=xRealloc(0,sM.nChar+1);
			if(sM.zText)memcpy(sM.zText,sM.zBase,sM.nChar+1);
		}
		else
			if(sM.nAlloc>sM.nChar+10)
			{
				char *zNew=xRealloc(sM.zText,sM.nChar+1);
				if(zNew)sM.zText=zNew;
			}
	return sM.zText;
}
void *printf_realloc(void *old,int size)
{
	return WN_SQLRealloc(old,size);
}
char *WN_SQL3VMPrintf(const char *zFormat,va_list ap)
{
	char zBase[WN_SQL_PRINT_BUF_SIZE];
	return base_vprintf(printf_realloc,1,zBase,sizeof(zBase),zFormat,ap);
}
char *WN_SQL3MPrintf(const char *zFormat,...)
{
	va_list ap;
	char *z;
	char zBase[WN_SQL_PRINT_BUF_SIZE];
	va_start(ap,zFormat);
	z=base_vprintf(printf_realloc,1,zBase,sizeof(zBase),zFormat,ap);
	va_end(ap);
	return z;
}
char *WN_SQL3_vmprintf(const char *zFormat,va_list ap)
{
	char zBase[WN_SQL_PRINT_BUF_SIZE];
	return base_vprintf(WN_SQL3_realloc,0,zBase,sizeof(zBase),zFormat,ap);
}
char *WN_SQL3_mprintf(const char *zFormat,...)
{
	va_list ap;
	va_start(ap,zFormat);
	char *z=WN_SQL3_vmprintf(zFormat,ap);
	va_end(ap);
	return z;
}
char *WN_SQL3_snprintf(int n,char *zBuf,const char *zFormat,...)
{
	if(n<=0)return zBuf;
	va_list ap;
	zBuf[0]=0;
	va_start(ap,zFormat);
	char *z=base_vprintf(0,0,zBuf,n,zFormat,ap);
	va_end(ap);
	return z;
}
#if defined(WN_SQL_TEST)|| defined(WN_SQL_DEBUG)|| defined(WN_SQL_MEMDEBUG)
void WN_SQL3DebugPrintf(const char *zFormat,...)
{
	extern int getpid(void);
	va_list ap;
	char zBuf[500];
	va_start(ap,zFormat);
	base_vprintf(0,0,zBuf,sizeof(zBuf),zFormat,ap);
	va_end(ap);
	fprintf(stdout,"%s",zBuf);
	fflush(stdout);
}
#endif
int randomByte(void)
{
	unsigned char t;
	struct
	{
		unsigned char isInit,i,j,s[256];
	}prng;
	if(!prng.isInit)
	{
		int i;
		char k[256];
		prng.j=0;
		prng.i=0;
		WN_SQL3OsRandomSeed(k);
		for(i=0;i<256;i++)prng.s[i]=i;
		for(i=0;i<256;i++)
		{
			prng.j+=prng.s[i]+k[i];
			t=prng.s[prng.j];
			prng.s[prng.j]=prng.s[i];
			prng.s[i]=t;
		}
		prng.isInit=1;
	}
	prng.i++;
	t=prng.s[prng.i];
	prng.j+=t;
	prng.s[prng.i]=prng.s[prng.j];
	prng.s[prng.j]=t;
	t+=prng.s[prng.i];
	return prng.s[t];
}
void WN_SQL3Randomness(int N,void *pBuf)
{
	unsigned char *zBuf=pBuf;
	WN_SQL3OsEnterMutex();
	while(N--)*(zBuf++)=randomByte();
	WN_SQL3OsLeaveMutex();
}
#ifndef _VDBEINT_H_
#define _VDBEINT_H_
#define keyToInt(X) (X)
#define intToKey(X) (X)
extern const char *const WN_SQL3OpcodeNames[];
typedef struct VdbeOp Op;
typedef unsigned char Bool;
struct Cursor
{
	BtCursor *pCursor;
	int iDb,nData,nField,cacheStatus,payloadSize;
	i64 lastRowid,nextRowid,movetoTarget,iKey,seqCount;
	Bool zeroed,rowidIsValid,atFirst,useRandomRowid,nullRow,nextRowidValid,pseudoTable,deferredMoveto,isTable,isIndex;
	u8 bogusIncrKey,*pIncrKey,*aRow;
	Btree *pBt;
	char *pData;
	KeyInfo *pKeyInfo;
	WN_SQL3_vtab_cursor *pVtabCursor;
	const WN_SQL3_module *pModule;
	u32 *aType,*aOffset;
};
typedef struct Cursor Cursor;
#define NBFS 32
#define CACHE_STALE 0
struct Mem
{
	union {
		i64 i;
		FuncDef *pDef;
	}u;
	double r;
	char *z;
	int n;
	u16 flags;
	u8 type,enc;
	void(*xDel)(void *);
	char zShort[NBFS];
};
typedef struct Mem Mem;
#define MEM_Null 0x0001
#define MEM_Str 0x0002
#define MEM_Int 0x0004
#define MEM_Real 0x0008
#define MEM_Blob 0x0010
#define MEM_Term 0x0020
#define MEM_Dyn 0x0040
#define MEM_Static 0x0080
#define MEM_Ephem 0x0100
#define MEM_Short 0x0200
#define MEM_Agg 0x0400
#define MEM_Zero 0x0800
#ifdef WN_SQL_OMIT_INCRBLOB
#undef MEM_Zero
#define MEM_Zero 0x0000
#endif
struct VdbeFunc
{
	FuncDef *pFunc;
	int nAux;
	struct AuxData
	{
		void *pAux;
		void(*xDelete)(void *);
	}apAux[1];
};
typedef struct VdbeFunc VdbeFunc;
struct WN_SQL3_context
{
	FuncDef *pFunc;
	VdbeFunc *pVdbeFunc;
	Mem s,*pMem;
	u8 isError;
	CollSeq *pColl;
};
typedef struct Set Set;
struct Set
{
	Hash hash;
	HashElem *prev;
};
typedef struct FifoPage FifoPage;
struct FifoPage
{
	int nSlot,iWrite,iRead;
	FifoPage *pNext;
	i64 aSlot[1];
};
typedef struct Fifo Fifo;
struct Fifo
{
	int nEntry;
	FifoPage *pFirst,*pLast;
};
typedef struct Context Context;
struct Context
{
	i64 lastRowid;
	int nChange;
	Fifo sFifo;
};
struct Vdbe
{
	WN_SQL3 *db;
	Vdbe *pPrev,*pNext;
	int nOp,nOpAlloc,nLabel,nLabelAlloc,*aLabel,okVar,magic,nMem;
	Op *aOp;
	Mem *aStack,*pTos,**apArg,*aColName,*aMem;
	int nCursor;
	Cursor **apCsr;
	int nVar;
	Mem *aVar;
	char **azVar;
	Fifo sFifo;
	int contextStackTop,contextStackDepth;
	Context *contextStack;
	unsigned uniqueCnt;
	int pc,rc,errorAction,inTempTrans,returnStack[100],returnDepth,nResColumn,popStack,nCallback,cacheCtr;
	char *zErrMsg,**azResColumn;
	u8 resOnStack,explain,changeCntOn,aborted,expired,minWriteFileFormat,inVtabMethod;
	int nChange;
	i64 startTime;
	int nSql;
	char *zSql;
#ifdef WN_SQL_DEBUG
	FILE *trace;
#endif
	int openedStatement;
#ifdef WN_SQL_SSE
	int fetchId;
	int lru;
#endif
};
#define VDBE_MAGIC_INIT 0x26bceaa5
#define VDBE_MAGIC_RUN 0xbdf20da3
#define VDBE_MAGIC_HALT 0x519c2973
#define VDBE_MAGIC_DEAD 0xb606c3c8
#if defined(WN_SQL_DEBUG)|| defined(VDBE_PROFILE)
void WN_SQL3VdbePrintOp(FILE*,int,Op*);
#endif
#ifndef NDEBUG
void WN_SQL3VdbeMemSanity(Mem*);
int WN_SQL3VdbeOpcodeNoPush(u8);
#endif
int WN_SQL3VdbeMemTranslate(Mem*,u8);
#ifdef WN_SQL_DEBUG
void WN_SQL3VdbePrintSql(Vdbe*);
void WN_SQL3VdbeMemPrettyPrint(Mem *pMem,char *zBuf);
#endif
#ifndef WN_SQL_OMIT_INCRBLOB
int WN_SQL3VdbeMemExpandBlob(Mem *);
#else
#define WN_SQL3VdbeMemExpandBlob(x)0
#endif
#endif
const int WN_SQL3one=1;
const unsigned char WN_SQL3UtfTrans1[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x00,0x01,0x02,0x03,0x00,0x01,0x00,0x00,};
#define WRITE_UTF8(zOut,c) {if(c<0x00080)*zOut++=(c&0xFF);\
\
else if(c<0x00800){\
*zOut++=0xC0+((c>>6)&0x1F);\
*zOut++=0x80+(c & 0x3F);\
}\
else if(c<0x10000){\
*zOut++=0xE0+((c>>12)&0x0F);\
*zOut++=0x80+((c>>6)& 0x3F);\
*zOut++=0x80+(c & 0x3F);\
}else{\
*zOut++=0xF0+((c>>18)& 0x07);\
*zOut++=0x80+((c>>12)& 0x3F);\
*zOut++=0x80+((c>>6)& 0x3F);\
*zOut++=0x80+(c & 0x3F);\
}\
}
#define WRITE_UTF16LE(zOut,c) {\
if(c<=0xFFFF){\
*zOut++=(c&0x00FF);\
*zOut++=((c>>8)&0x00FF);\
}else{\
*zOut++=(((c>>10)&0x003F)+(((c-0x10000)>>10)&0x00C0));\
*zOut++=(0x00D8+(((c-0x10000)>>18)&0x03));\
*zOut++=(c&0x00FF);\
*zOut++=(0x00DC+((c>>8)&0x03));\
}\
}
#define WRITE_UTF16BE(zOut,c) {\
if(c<=0xFFFF){\
*zOut++=((c>>8)&0x00FF);\
*zOut++=(c&0x00FF);\
}else{\
*zOut++=(0x00D8+(((c-0x10000)>>18)&0x03));\
*zOut++=(((c>>10)&0x003F)+(((c-0x10000)>>10)&0x00C0));\
*zOut++=(0x00DC+((c>>8)&0x03));\
*zOut++=(c&0x00FF);\
}\
}
#define READ_UTF16LE(zIn,c) {\
c=(*zIn++);\
c+=((*zIn++)<<8);\
if(c>=0xD800 && c<0xE000){\
int c2=(*zIn++);\
c2+=((*zIn++)<<8);\
c=(c2&0x03FF)+((c&0x003F)<<10)+(((c&0x03C0)+0x0040)<<10);\
if((c & 0xFFFF0000)==0)c=0xFFFD;\
}\
}
#define READ_UTF16BE(zIn,c) {\
c=((*zIn++)<<8);\
c+=(*zIn++);\
if(c>=0xD800 && c<0xE000){\
int c2=((*zIn++)<<8);\
c2+=(*zIn++);\
c=(c2&0x03FF)+((c&0x003F)<<10)+(((c&0x03C0)+0x0040)<<10);\
if((c & 0xFFFF0000)==0)c=0xFFFD;\
}\
}
#ifndef WN_SQL_OMIT_UTF16
int WN_SQL3VdbeMemTranslate(Mem *pMem,u8 desiredEnc)
{
	int len;
	unsigned char *zOut,*zIn,*zTerm,*z,zShort[NBFS];
	u32 c;
#if defined(TRANSLATE_TRACE)&& defined(WN_SQL_DEBUG)
	char zBuf[100];
	WN_SQL3VdbeMemPrettyPrint(pMem,zBuf);
	fprintf(stderr,"INPUT:%s\n",zBuf);
#endif
	if(pMem->enc!=WN_SQL_UTF8 && desiredEnc!=WN_SQL_UTF8)
	{
		u8 temp;
		int rc;
		if(rc=WN_SQL3VdbeMemMakeWriteable(pMem))return WN_SQL_NOMEM;
		zIn=(u8*)pMem->z;
		zTerm=&zIn[pMem->n];
		while(zIn<zTerm)
		{
			temp=*zIn;
			*zIn=*(zIn+1);
			zIn++;
			*zIn++=temp;
		}
		pMem->enc=desiredEnc;
		goto translate_out;
	}
	if(desiredEnc==WN_SQL_UTF8)
		len=pMem->n * 2+1;
	else
		len=pMem->n * 2+2;
	zIn=(u8*)pMem->z;
	zTerm=&zIn[pMem->n];
	if(len>NBFS)
	{
		zOut=WN_SQLMallocRaw(len);
		if(!zOut)return WN_SQL_NOMEM;
	}
	else
		zOut=zShort;
	z=zOut;
	if(pMem->enc==WN_SQL_UTF8)
	{
		u32 iExtra=0xD800;
		if(0==(pMem->flags&MEM_Term)&& zTerm>zIn &&(zTerm[-1]&0x80))
		{
			unsigned char *zExtra=&zTerm[-1];
			while(zExtra>zIn &&(zExtra[0]&0xC0)==0x80)	zExtra--;
			if((zExtra[0]&0xC0)==0xC0)
			{
				unsigned char *zFree=0,zBuf[16];
				int nExtra=(pMem->n+zIn-zExtra);
				zTerm=zExtra;
				if(nExtra>15)
				{
					zExtra=WN_SQLMallocRaw(nExtra+1);
					if(!zExtra)return WN_SQL_NOMEM;
					zFree=zExtra;
				}
				else
					zExtra=zBuf;
				memcpy(zExtra,zTerm,nExtra);
				zExtra[nExtra]='\0';
				WN_SQL_READ_UTF8(zExtra,iExtra);
				WN_SQL3FreeX(zFree);
			}
		}
		if(desiredEnc==WN_SQL_UTF16LE)
		{
			while(zIn<zTerm)
			{
				WN_SQL_READ_UTF8(zIn,c);
				WRITE_UTF16LE(z,c);
			}
			if(iExtra!=0xD800)WRITE_UTF16LE(z,iExtra);
		}
		else
		{
			while(zIn<zTerm)
			{
				WN_SQL_READ_UTF8(zIn,c);
				WRITE_UTF16BE(z,c);
			}
			if(iExtra!=0xD800)WRITE_UTF16BE(z,iExtra);
		}
		pMem->n=z-zOut;
		*z++=0;
	}
	else
	{
		if(pMem->enc==WN_SQL_UTF16LE)
		{
			while(zIn<zTerm)
			{
				READ_UTF16LE(zIn,c);
				WRITE_UTF8(z,c);
			}
		}
		else
			while(zIn<zTerm)
			{
				READ_UTF16BE(zIn,c);
				WRITE_UTF8(z,c);
			}
		pMem->n=z-zOut;
	}
	*z=0;
	WN_SQL3VdbeMemRelease(pMem);
	pMem->flags &=~(MEM_Static|MEM_Dyn|MEM_Ephem|MEM_Short);
	pMem->enc=desiredEnc;
	if(zOut==zShort)
	{
		memcpy(pMem->zShort,zOut,len);
		zOut=(u8*)pMem->zShort;
		pMem->flags |=(MEM_Term|MEM_Short);
	}
	else
		pMem->flags |=(MEM_Term|MEM_Dyn);
	pMem->z=(char*)zOut;
translate_out:
#if defined(TRANSLATE_TRACE)&& defined(WN_SQL_DEBUG)
	char zBuf[100];
	WN_SQL3VdbeMemPrettyPrint(pMem,zBuf);
	fprintf(stderr,"OUTPUT:%s\n",zBuf);
#endif
	return 0;
}
int WN_SQL3VdbeMemHandleBom(Mem *pMem)
{
	int rc=0;
	u8 bom=0;
	if(pMem->n<0 || pMem->n>1)
	{
		u8 b1=*(u8 *)pMem->z,b2=*(((u8 *)pMem->z)+1);
		if(b1==0xFE && b2==0xFF) bom=WN_SQL_UTF16BE;
		if(b1==0xFF && b2==0xFE)bom=WN_SQL_UTF16LE;
	}
	if(bom)
		if(pMem->flags & MEM_Dyn)
		{
			void(*xDel)(void*)=pMem->xDel;
			char *z=pMem->z;
			pMem->z=0;
			pMem->xDel=0;
			rc=WN_SQL3VdbeMemSetStr(pMem,&z[2],pMem->n-2,bom,WN_SQL_TRANSIENT);
			xDel(z);
		}
		else
			rc=WN_SQL3VdbeMemSetStr(pMem,&pMem->z[2],pMem->n-2,bom,WN_SQL_TRANSIENT);
	return rc;
}
#endif
int WN_SQL3Utf8CharLen(const char *zIn,int nByte)
{
	int r=0;
	const u8 *z=(const u8*)zIn,u8 *zTerm;
	if(nByte>=0)
		zTerm=&z[nByte];
	else
		zTerm=(const u8*)(-1);
	while(*z && z<zTerm)
	{
		WN_SQL_SKIP_UTF8(z);
		r++;
	}
	return r;
}
#ifndef WN_SQL_OMIT_UTF16
char *WN_SQL3Utf16to8(const void *z,int nByte)
{
	Mem m;
	memset(&m,0,sizeof(m));
	WN_SQL3VdbeMemSetStr(&m,z,nByte,WN_SQL_UTF16NATIVE,WN_SQL_STATIC);
	WN_SQL3VdbeChangeEncoding(&m,WN_SQL_UTF8);
	return(m.flags & MEM_Dyn)? m.z :WN_SQLStrDup(m.z);
}
int WN_SQL3Utf16ByteLen(const void *zIn,int nChar)
{
	u32 c=1;
	char const *z=zIn;
	int n=0;
	if(WN_SQL_UTF16NATIVE==WN_SQL_UTF16BE)
	{
		while(c &&((nChar<0)|| n<nChar))
		{
			READ_UTF16BE(z,c);
			n++;
		}
	}
	else
	{
		while(c &&((nChar<0)|| n<nChar))
		{
			READ_UTF16LE(z,c);
			n++;
		}
	}
	return(z-(char const *)zIn)-((c==0)?2:0);
}
#if defined(WN_SQL_TEST)
int WN_SQL3Utf8To8(unsigned char *zIn)
{
	unsigned char *zOut=zIn,*zStart=zIn;
	int c;
	while(1)
	{
		WN_SQL_READ_UTF8(zIn,c);
		if(c==0)break;
		if(c!=0xfffd)WRITE_UTF8(zOut,c);
	}
	*zOut=0;
	return zOut-zStart;
}
#endif
#if defined(WN_SQL_TEST)
void WN_SQL3UtfSelfTest()
{
	u32 i,t,c;
	unsigned char zBuf[20],*z;
	int n;
	for(i=0;i<0x00110000;i++)
	{
		z=zBuf;
		WRITE_UTF8(z,i);
		n=z-zBuf;
		z[0]=0;
		z=zBuf;
		WN_SQL_READ_UTF8(z,c);
		t=i;
		if(i>=0xD800 && i<=0xDFFF)t=0xFFFD;
		if((i&0xFFFFFFFE)==0xFFFE)t=0xFFFD;
	}
	for(i=0;i<0x00110000;i++)
	{
		if(i>=0xD800 && i<0xE000)continue;
		z=zBuf;
		WRITE_UTF16LE(z,i);
		n=z-zBuf;
		z[0]=0;
		z=zBuf;
		READ_UTF16LE(z,c);
	}
	for(i=0;i<0x00110000;i++)
	{
		if(i>=0xD800 && i<0xE000)continue;
		z=zBuf;
		WRITE_UTF16BE(z,i);
		n=z-zBuf;
		z[0]=0;
		z=zBuf;
		READ_UTF16BE(z,c);
	}
}
#endif
#endif
void WN_SQL3Error(WN_SQL3 *db,int err_code,const char *zFormat,...)
{
	if(db &&(db->pErr ||(db->pErr=WN_SQL3ValueNew())))
	{
		db->errCode=err_code;
		if(zFormat)
		{
			char *z;
			va_list ap;
			va_start(ap,zFormat);
			z=WN_SQL3VMPrintf(zFormat,ap);
			va_end(ap);
			WN_SQL3ValueSetStr(db->pErr,-1,z,WN_SQL_UTF8,WN_SQL3FreeX);
		}
		else
			WN_SQL3ValueSetStr(db->pErr,0,0,WN_SQL_UTF8,WN_SQL_STATIC);
	}
}
void WN_SQL3ErrorMsg(Parse *pParse,const char *zFormat,...)
{
	va_list ap;
	pParse->nErr++;
	WN_SQL3FreeX(pParse->zErrMsg);
	va_start(ap,zFormat);
	pParse->zErrMsg=WN_SQL3VMPrintf(zFormat,ap);
	va_end(ap);
	if(pParse->rc==0)pParse->rc=WN_SQL_ERROR;
}
void WN_SQL3ErrorClear(Parse *pParse)
{
	WN_SQL3FreeX(pParse->zErrMsg);
	pParse->zErrMsg=0;
	pParse->nErr=0;
}	
void WN_SQL3Dequote(char *z)
{
	int quote,i,j;
	if(z==0)return;
	quote=z[0];
	switch(quote)
	{
	case '\'':break;
	case '"':break;
	case '`':break;
	case '[':quote=']';break;
	default:return;
	}
	for(i=1,j=0;z[i];i++)
		if(z[i]==quote)
			if(z[i+1]==quote)
			{
				z[j++]=quote;
				i++;
			}
			else
			{
				z[j++]=0;
				break;
			}
		else
			z[j++]=z[i];
}
const unsigned char WN_SQL3UpperToLower[]={
#ifdef WN_SQL_ASCII
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
#endif
#ifdef WN_SQL_EBCDIC
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,66,67,68,69,70,71,72,73,106,107,108,109,110,111,112,81,82,83,84,85,86,87,88,89,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,156,159,160,161,162,163,164,165,166,167,168,169,170,171,140,141,142,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,129,130,131,132,133,134,135,136,137,202,203,204,205,206,207,208,145,146,147,148,149,150,151,152,153,218,219,220,221,222,223,224,225,162,163,164,165,166,167,168,169,232,203,204,205,206,207,239,240,241,242,243,244,245,246,247,248,249,219,220,221,222,255,
#endif
};
#define UpperToLower WN_SQL3UpperToLower
int WN_SQL3StrICmp(const char *zLeft,const char *zRight)
{
	register unsigned char *a=(unsigned char *)zLeft,*b=(unsigned char *)zRight;
	while(*a && UpperToLower[*a]==UpperToLower[*b])
	{
		a++;
		b++;
	}
	return UpperToLower[*a]-UpperToLower[*b];
}
int WN_SQL3StrNICmp(const char *zLeft,const char *zRight,int N)
{
	register unsigned char *a=(unsigned char *)zLeft,*b=(unsigned char *)zRight;
	while(N--> 0 && *a && UpperToLower[*a]==UpperToLower[*b])
	{
		a++;
		b++;
	}
	return N<0 ? 0 :UpperToLower[*a]-UpperToLower[*b];
}
int WN_SQL3IsNumber(const char *z,int *realnum,u8 enc)
{
	int incr=(enc==WN_SQL_UTF8?1:2);
	if(enc==WN_SQL_UTF16BE)z++;
	if(*z=='-' || *z=='+')z+=incr;
	if(!isdigit(*(u8*)z))return 0;
	z+=incr;
	if(realnum)*realnum=0;
	while(isdigit(*(u8*)z))z+=incr;
	if(*z=='.')
	{
		z+=incr;
		if(!isdigit(*(u8*)z))return 0;
		while(isdigit(*(u8*)z))	z+=incr;
		if(realnum)*realnum=1;
	}
	if(*z=='e' || *z=='E')
	{
		z+=incr;
		if(*z=='+' || *z=='-')z+=incr;
		if(!isdigit(*(u8*)z))return 0;
		while(isdigit(*(u8*)z))	z+=incr;
		if(realnum)*realnum=1;
	}
	return *z==0;
}
int WN_SQL3AtoF(const char *z,double *pResult)
{
#ifndef WN_SQL_OMIT_FLOATING_POINT
	int sign=1;
	const char *zBegin=z;
	LONGDOUBLE_TYPE v1=0.0;
	while(isspace(*(u8*)z))z++;
	if(*z=='-')
	{
		sign=-1;
		z++;
	}
	else
		if(*z=='+')	z++;
	while(isdigit(*(u8*)z))
	{
		v1=v1*10.0+(*z-'0');
		z++;
	}
	if(*z=='.')
	{
		LONGDOUBLE_TYPE divisor=1.0;
		z++;
		while(isdigit(*(u8*)z))
		{
			v1=v1*10.0+(*z-'0');
			divisor *=10.0;
			z++;
		}
		v1 /=divisor;
	}
	if(*z=='e' || *z=='E')
	{
		int esign=1,eval=0;
		LONGDOUBLE_TYPE scale=1.0;
		z++;
		if(*z=='-')
		{
			esign=-1;
			z++;
		}
		else
			if(*z=='+')z++;
			while(isdigit(*(u8*)z))
			{
				eval=eval*10+*z-'0';
				z++;
			}
			while(eval>=64)
			{
				scale *=1.0e+64;
				eval-=64;
			}
			while(eval>=16)
			{
				scale *=1.0e+16;
				eval-=16;
			}
			while(eval>=4)
			{
				scale *=1.0e+4;
				eval-=4;
			}
			while(eval>=1)
			{
				scale *=1.0e+1;
				eval-=1;
			}
			if(esign<0)
				v1 /=scale;
			else
				v1 *=scale;
	}
	*pResult=sign<0 ?-v1 :v1;
	return z-zBegin;
#else
	return WN_SQL3Atoi64(z,pResult);
#endif
}
int compare2pow63(const char *zNum)
{
	int c=memcmp(zNum,"922337203685477580",18);
	if(c==0)c=zNum[18]-'8';
	return c;
}
int WN_SQL3Atoi64(const char *zNum,i64 *pNum)
{
	i64 v=0;
	int neg,i,c;
	while(isspace(*(u8*)zNum))zNum++;
	if(*zNum=='-')
	{
		neg=1;
		zNum++;
	}
	else
		if(*zNum=='+')
		{
			neg=0;
			zNum++;
		}
		else
			neg=0;
	while(zNum[0]=='0')zNum++;
	for(i=0;(c=zNum[i])>='0' && c<='9';i++)v=v*10+c-'0';
	*pNum=neg ?-v :v;
	if(c || i==0 || i>19)
		return 0;
	else
		if(i<19)
			return 1;
		else
			return compare2pow63(zNum)<neg;
}
int WN_SQL3FitsIn64Bits(const char *zNum)
{
	int i,c,neg=0;
	if(*zNum=='-')
	{
		neg=1;
		zNum++;
	}
	else
		if(*zNum=='+')zNum++;
	while(*zNum=='0')zNum++;
	for(i=0;(c=zNum[i])>='0' && c<='9';i++);
	if(i<19)
		return 1;
	else
		if(i>19)
			return 0;
		else
			return compare2pow63(zNum)<neg;
}
int WN_SQL3GetInt32(const char *zNum,int *pValue)
{
	WN_SQL_int64 v=0;
	int i,c,neg=0;
	if(zNum[0]=='-')
	{
		neg=1;
		zNum++;
	}
	else
		if(zNum[0]=='+')zNum++;
	while(zNum[0]=='0')zNum++;
	for(i=0;i<10 &&(c=zNum[i]-'0')>=0 && c<=9;i++)v=v*10+c;
	if(i>9)return 0;
	if(v-neg>2147483647)return 0;
	if(neg)v=-v;
	*pValue=(int)v;
	return 1;
}
int WN_SQL3SafetyCheck(WN_SQL3 *db)
{
	if(db==0)return 1;
	int magic=db->magic;
	if(magic!=WN_SQL_MAGIC_CLOSED && magic!=WN_SQL_MAGIC_OPEN && magic!=WN_SQL_MAGIC_BUSY)return 1;
	return 0;
}
int WN_SQL3PutVarint(unsigned char *p,u64 v)
{
	int i,j,n;
	u8 buf[10];
	if(v &(((u64)0xff000000)<<32))
	{
		p[8]=v;
		v >>=8;
		for(i=7;i>=0;i--)
		{
			p[i]=(v & 0x7f)| 0x80;
			v >>=7;
		}
		return 9;
	}
	n=0;
	do
	{
		buf[n++]=(v & 0x7f)| 0x80;
		v >>=7;
	}while(v);
	buf[0] &=0x7f;
	for(i=0,j=n-1;j>=0;j--,i++)p[i]=buf[j];
	return n;
}
int WN_SQL3GetVarint(const unsigned char *p,u64 *v)
{
	u32 x;
	u64 x64;
	int n;
	unsigned char c;
	if(((c=p[0])& 0x80)==0)
	{
		*v=c;
		return 1;
	}
	x=c & 0x7f;
	if(((c=p[1])& 0x80)==0)
	{
		*v=(x<<7)| c;
		return 2;
	}
	x=(x<<7)|(c&0x7f);
	if(((c=p[2])& 0x80)==0)
	{
		*v=(x<<7)| c;
		return 3;
	}
	x=(x<<7)|(c&0x7f);
	if(((c=p[3])& 0x80)==0)
	{
		*v=(x<<7)| c;
		return 4;
	}
	x64=(x<<7)|(c&0x7f);
	n=4;
	do
	{
		c=p[n++];
		if(n==9)
		{
			x64=(x64<<8)| c;
			break;
		}
		x64=(x64<<7)|(c&0x7f);
	}while((c & 0x80));
	*v=x64;
	return n;
}
int WN_SQL3GetVarint32(const unsigned char *p,u32 *v)
{
	unsigned char c;
	if(((signed char*)p)[0]>=0)
	{
		*v=p[0];
		return 1;
	}
	u32 x=p[0] & 0x7f;
	if(((signed char*)p)[1]>=0)
	{
		*v=(x<<7)| p[1];
		return 2;
	}
	x=(x<<7)|(p[1] & 0x7f);
	int n=2;
	do
	{
		x=(x<<7)|((c=p[n++])&0x7f);
	}while((c & 0x80)&& n<9);
	*v=x;
	return n;
}
int WN_SQL3VarintLen(u64 v)
{
	int i=0;
	do
	{
		i++;
		v >>=7;
	}while(v && i<9);
	return i;
}
u32 WN_SQL3Get4byte(const u8 *p)
{
	return(p[0]<<24)|(p[1]<<16)|(p[2]<<8)| p[3];
}
void WN_SQL3Put4byte(unsigned char *p,u32 v)
{
	p[0]=v>>24;
	p[1]=v>>16;
	p[2]=v>>8;
	p[3]=v;
}
#if !defined(WN_SQL_OMIT_BLOB_LITERAL)|| defined(WN_SQL_HAS_CODEC) || defined(WN_SQL_TEST)
int hexToInt(int h)
{
	if(h>='0' && h<='9')
		return h-'0';
	else
		if(h>='a' && h<='f')
			return h-'a'+10;
		else
			return h-'A'+10;
}
#endif
#if !defined(WN_SQL_OMIT_BLOB_LITERAL)|| defined(WN_SQL_HAS_CODEC)
void *WN_SQL3HexToBlob(const char *z)
{
	int i,n=strlen(z);
	if(n%2)return 0;
	char *zBlob=(char *)WN_SQL3Malloc(n/2);
	if(zBlob)for(i=0;i<n;i+=2)zBlob[i/2]=(hexToInt(z[i])<<4)| hexToInt(z[i+1]);
	return zBlob;
}
#endif
int WN_SQL3SafetyOn(WN_SQL3 *db)
{
	if(db->magic==WN_SQL_MAGIC_OPEN)
	{
		db->magic=WN_SQL_MAGIC_BUSY;
		return 0;
	}
	else
		if(db->magic==WN_SQL_MAGIC_BUSY)
		{
			db->magic=WN_SQL_MAGIC_ERROR;
			db->u1.isInterrupted=1;
		}
		return 1;
}
int WN_SQL3SafetyOff(WN_SQL3 *db)
{
	if(db->magic==WN_SQL_MAGIC_BUSY)
	{
		db->magic=WN_SQL_MAGIC_OPEN;
		return 0;
	}
	else
	{
		db->magic=WN_SQL_MAGIC_ERROR;
		db->u1.isInterrupted=1;
		return 1;
	}
}
ThreadData *WN_SQL3ThreadData()
{
	ThreadData *p=(ThreadData*)WN_SQL3OsThreadSpecificData(1);
	if(!p)WN_SQL3FailedMalloc();
	return p;
}
const ThreadData *WN_SQL3ThreadDataReadOnly()
{
	const ThreadData zeroData={0};
	const ThreadData *pTd=WN_SQL3OsThreadSpecificData(0);
	return pTd ? pTd :&zeroData;
}
void WN_SQL3ReleaseThreadData()
{
	WN_SQL3OsThreadSpecificData(-1);
}
void WN_SQL3HashInit(Hash *pNew,int keyClass,int copyKey)
{
	pNew->keyClass=keyClass;
#if 0
	if(keyClass==WN_SQL_HASH_POINTER || keyClass==WN_SQL_HASH_INT)copyKey=0;
#endif
	pNew->copyKey=copyKey;
	pNew->first=0;
	pNew->count=0;
	pNew->htsize=0;
	pNew->ht=0;
	pNew->xMalloc=WN_SQL3MallocX;
	pNew->xFree=WN_SQL3FreeX;
}
void WN_SQL3HashClear(Hash *pH)
{
	HashElem *elem=pH->first;
	pH->first=0;
	if(pH->ht)pH->xFree(pH->ht);
	pH->ht=0;
	pH->htsize=0;
	while(elem)
	{
		HashElem *next_elem=elem->next;
		if(pH->copyKey && elem->pKey)pH->xFree(elem->pKey);
		pH->xFree(elem);
		elem=next_elem;
	}
	pH->count=0;
}
#if 0
int intHash(const void *pKey,int nKey)
{
	return nKey ^(nKey<<8)^(nKey>>8);
}
int intCompare(const void *pKey1,int n1,const void *pKey2,int n2)
{
	return n2-n1;
}
#endif
#if 0
int ptrHash(const void *pKey,int nKey)
{
	uptr x=Addr(pKey);
	return x ^(x<<8)^(x>>8);
}
int ptrCompare(const void *pKey1,int n1,const void *pKey2,int n2)
{
	if(pKey1==pKey2)return 0;
	if(pKey1<pKey2)return-1;
	return 1;
}
#endif
int strHash(const void *pKey,int nKey)
{
	const char *z=(const char *)pKey;
	int h=0;
	if(nKey<=0)nKey=strlen(z);
	while(nKey > 0)
	{
		h=(h<<3)^ h ^ WN_SQL3UpperToLower[(unsigned char)*z++];
		nKey--;
	}
	return h & 0x7fffffff;
}
int strCompare(const void *pKey1,int n1,const void *pKey2,int n2)
{
	if(n1!=n2)return 1;
	return WN_SQL3StrNICmp((const char*)pKey1,(const char*)pKey2,n1);
}
int binHash(const void *pKey,int nKey)
{
	int h=0;
	const char *z=(const char *)pKey;
	while(nKey--> 0)h=(h<<3)^ h ^ *(z++);
	return h & 0x7fffffff;
}
int binCompare(const void *pKey1,int n1,const void *pKey2,int n2)
{
	if(n1!=n2)return 1;
	return memcmp(pKey1,pKey2,n1);
}
int(*hashFunction(int keyClass))(const void*,int)
{
#if 0
switch(keyClass){
case WN_SQL_HASH_INT:return &intHash;
case WN_SQL_HASH_POINTER:return &ptrHash;
case WN_SQL_HASH_STRING:return &strHash;
case WN_SQL_HASH_BINARY:return &binHash;;
}
return 0;
#else
	if(keyClass==WN_SQL_HASH_STRING)
		return &strHash;
	else
		return &binHash;
#endif
}
int(*compareFunction(int keyClass))(const void*,int,const void*,int)
{
#if 0
switch(keyClass){
case WN_SQL_HASH_INT:return &intCompare;
case WN_SQL_HASH_POINTER:return &ptrCompare;
case WN_SQL_HASH_STRING:return &strCompare;
case WN_SQL_HASH_BINARY:return &binCompare;
}
return 0;
#else
	if(keyClass==WN_SQL_HASH_STRING)
		return &strCompare;
	else
		return &binCompare;
#endif
}
void insertElement(Hash *pH,struct _ht *pEntry,HashElem *pNew)
{
	HashElem *pHead;
	pHead=pEntry->chain;
	if(pHead)
	{
		pNew->next=pHead;
		pNew->prev=pHead->prev;
		if(pHead->prev)
			pHead->prev->next=pNew;
		else
			pH->first=pNew;
		pHead->prev=pNew;
	}
	else
	{
		pNew->next=pH->first;
		if(pH->first)pH->first->prev=pNew;
		pNew->prev=0;
		pH->first=pNew;
	}
	pEntry->count++;
	pEntry->chain=pNew;
}
void rehash(Hash *pH,int new_size)
{
	HashElem *elem,*next_elem;
	int(*xHash)(const void*,int);
	struct _ht *new_ht=(struct _ht *)pH->xMalloc(new_size*sizeof(struct _ht));
	if(new_ht==0)return;
	if(pH->ht)pH->xFree(pH->ht);
	pH->ht=new_ht;
	pH->htsize=new_size;
	xHash=hashFunction(pH->keyClass);
	for(elem=pH->first,pH->first=0;elem;elem=next_elem)
	{
		int h=(*xHash)(elem->pKey,elem->nKey)&(new_size-1);
		next_elem=elem->next;
		insertElement(pH,&new_ht[h],elem);
	}
}
HashElem *findElementGivenHash(const Hash *pH,const void *pKey,int nKey,int h)
{
	HashElem *elem;
	int count;
	int(*xCompare)(const void*,int,const void*,int);
	if(pH->ht)
	{
		struct _ht *pEntry=&pH->ht[h];
		elem=pEntry->chain;
		count=pEntry->count;
		xCompare=compareFunction(pH->keyClass);
		while(count--&& elem)
		{
			if((*xCompare)(elem->pKey,elem->nKey,pKey,nKey)==0)return elem;
			elem=elem->next;
		}
	}
	return 0;
}
void removeElementGivenHash(Hash *pH,HashElem* elem,int h)
{
	struct _ht *pEntry;
	if(elem->prev)
		elem->prev->next=elem->next;
	else
		pH->first=elem->next;
	if(elem->next)elem->next->prev=elem->prev;
	pEntry=&pH->ht[h];
	if(pEntry->chain==elem)	pEntry->chain=elem->next;
	pEntry->count--;
	if(pEntry->count<=0)pEntry->chain=0;
	if(pH->copyKey)pH->xFree(elem->pKey);
	pH->xFree(elem);
	pH->count--;
	if(pH->count<=0)WN_SQL3HashClear(pH);
}
void *WN_SQL3HashFind(const Hash *pH,const void *pKey,int nKey)
{
	int h;
	HashElem *elem;
	int(*xHash)(const void*,int);
	if(pH==0 || pH->ht==0)return 0;
	xHash=hashFunction(pH->keyClass);
	h=(*xHash)(pKey,nKey);
	elem=findElementGivenHash(pH,pKey,nKey,h &(pH->htsize-1));
	return elem ? elem->data :0;
}
void *WN_SQL3HashInsert(Hash *pH,const void *pKey,int nKey,void *data)
{
	int(*xHash)(const void*,int);
	xHash=hashFunction(pH->keyClass);
	int hraw=(*xHash)(pKey,nKey),h=hraw &(pH->htsize-1);
	HashElem *new_elem,*elem=findElementGivenHash(pH,pKey,nKey,h);
	if(elem)
	{
		void *old_data=elem->data;
		if(data==0)
			removeElementGivenHash(pH,elem,h);
		else
			elem->data=data;
		return old_data;
	}
	if(data==0)return 0;
	new_elem=(HashElem*)pH->xMalloc(sizeof(HashElem));
	if(new_elem==0)return data;
	if(pH->copyKey && pKey)
	{
		new_elem->pKey=pH->xMalloc(nKey);
		if(new_elem->pKey==0)
		{
			pH->xFree(new_elem);
			return data;
		}
		memcpy((void*)new_elem->pKey,pKey,nKey);
	}
	else
		new_elem->pKey=(void*)pKey;
	new_elem->nKey=nKey;
	pH->count++;
	if(pH->htsize==0)
	{
		rehash(pH,8);
		if(pH->htsize==0)
		{
			pH->count=0;
			if(pH->copyKey)pH->xFree(new_elem->pKey);
			pH->xFree(new_elem);
			return data;
		}
	}
	if(pH->count > pH->htsize)rehash(pH,pH->htsize*2);
	h=hraw &(pH->htsize-1);
	insertElement(pH,&pH->ht[h],new_elem);
	new_elem->data=data;
	return 0;
}
#if !defined(WN_SQL_OMIT_EXPLAIN)|| !defined(NDEBUG)|| defined(VDBE_PROFILE)|| defined(WN_SQL_DEBUG)
const char *const WN_SQL3OpcodeNames[]={"?","MemLoad","VNext","Column","SetCookie","IfMemPos","Sequence","MoveGt","RowKey","OpenWrite","If","Pop","VRowid","CollSeq","OpenRead","Expire","Not","AutoCommit","IntegrityCk","Sort","Function","Noop","Return","NewRowid","IfMemNeg","Variable","String","RealAffinity","VRename","ParseSchema","VOpen","Close","CreateIndex","IsUnique","NotFound","Int64","MustBeInt","Halt","Rowid","IdxLT","AddImm","Statement","RowData","MemMax","Push","NotExists","MemIncr","Gosub","Integer","MemInt","Prev","VColumn","CreateTable","Last","IncrVacuum","IdxRowid","MakeIdxRec","ResetCount","FifoWrite","Callback","Or","And","ContextPush","DropTrigger","DropIndex","IsNull","NotNull","Ne","Eq","Gt","Le","Lt","Ge","IdxGE","BitAnd","BitOr","ShiftLeft","ShiftRight","Add","Subtract","Multiply","Divide","Remainder","Concat","IdxDelete","Negative","Vacuum","BitNot","String8","MoveLe","IfNot","DropTable","MakeRecord","Delete","AggFinal","Dup","Goto","TableLock","FifoRead","Clear","IdxGT","MoveLt","VerifyCookie","AggStep","Pull","SetNumColumns","AbsValue","Transaction","VFilter","VDestroy","ContextPop","Next","IdxInsert","Distinct","Insert","Destroy","ReadCookie","ForceInt","LoadAnalysis","Explain","IfMemZero","OpenPseudo","OpenEphemeral","Null","Blob","Real","HexBlob","MemStore","Rewind","MoveGe","VBegin","VUpdate","VCreate","MemMove","MemNull","Found","NullRow","NotUsed_137","ToText","ToBlob","ToNumeric","ToInt","ToReal",};
#endif
#if OS_OS2
#if defined(THREADSAFE)&& THREADSAFE
# define WN_SQL_OS2_THREADS 1
#endif
#ifdef WN_SQL_TEST
u32 WN_SQL3_pending_byte=0x40000000;
#endif
int WN_SQL3_os_trace=0;
#ifdef WN_SQL_DEBUG
#define OSTRACE1(X)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X)
#define OSTRACE2(X,Y)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y)
#define OSTRACE3(X,Y,Z)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z)
#define OSTRACE4(X,Y,Z,A)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A)
#define OSTRACE5(X,Y,Z,A,B)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B)
#define OSTRACE6(X,Y,Z,A,B,C)\
if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B,C)
#define OSTRACE7(X,Y,Z,A,B,C,D)\
if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B,C,D)
#else
#define OSTRACE1(X)
#define OSTRACE2(X,Y)
#define OSTRACE3(X,Y,Z)
#define OSTRACE4(X,Y,Z,A)
#define OSTRACE5(X,Y,Z,A,B)
#define OSTRACE6(X,Y,Z,A,B,C)
#define OSTRACE7(X,Y,Z,A,B,C,D)
#endif
#ifdef WN_SQL_PERFORMANCE_TRACE
__inline__ unsigned long long int hwtime(void){
unsigned long long int x;
__asm__("rdtsc\n\t"
"mov %%edx,%%ecx\n\t"
:"=A"(x));
return x;
}
unsigned long long int g_start;
u32 elapse;
#define TIMER_START g_start=hwtime()
#define TIMER_END elapse=hwtime()-g_start
#define TIMER_ELAPSED elapse
#else
#define TIMER_START
#define TIMER_END
#define TIMER_ELAPSED 0
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_io_error_hit=0;
int WN_SQL3_io_error_pending=0;
int WN_SQL3_io_error_persist=0;
int WN_SQL3_diskfull_pending=0;
int WN_SQL3_diskfull=0;
#define SimulateIOError(CODE)\
if(WN_SQL3_io_error_pending || WN_SQL3_io_error_hit)\
if(WN_SQL3_io_error_pending--==1 \
||(WN_SQL3_io_error_persist && WN_SQL3_io_error_hit))\
{local_ioerr();CODE;}
void local_ioerr()
{
	IOTRACE(("IOERR\n"));
	WN_SQL3_io_error_hit=1;
}
#define SimulateDiskfullError(CODE) \
if(WN_SQL3_diskfull_pending){\
if(WN_SQL3_diskfull_pending==1){\
local_ioerr();\
WN_SQL3_diskfull=1;\
WN_SQL3_io_error_hit=1;\
CODE;\
}else{\
WN_SQL3_diskfull_pending--;\
}\
}
#else
#define SimulateIOError(A)
#define SimulateDiskfullError(A)
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_open_file_count=0;
#define OpenCounter(X)WN_SQL3_open_file_count+=(X)
#else
#define OpenCounter(X)
#endif
#if defined(WN_SQL_ENABLE_MEMORY_MANAGEMENT)|| defined(WN_SQL_MEMDEBUG)
void *WN_SQL3GenericMalloc(int n)
{
	char *p=(char *)malloc(n+8);
	if(p)
	{
		*(int *)p=n;
		p+=8;
	}
	return(void *)p;
}
void *WN_SQL3GenericRealloc(void *p,int n)
{
	char *p2=((char *)p-8);
	p2=(char*)realloc(p2,n+8);
	if(p2)
	{
		*(int *)p2=n;
		p2+=8;
	}
	return(void *)p2;
}
void WN_SQL3GenericFree(void *p)
{
	free((void *)((char *)p-8));
}
int WN_SQL3GenericAllocationSize(void *p)
{
	return p ? *(int *)((char *)p-8):0;
}
#else
void *WN_SQL3GenericMalloc(int n)
{
	return(void*)[n];
}
void *WN_SQL3GenericRealloc(void *p,int n)
{
	p=realloc(p,n);
	return p;
}
void WN_SQL3GenericFree(void *p)
{
	free(p);
}
int WN_SQL3GenericAllocationSize(void *p)
{
	return 0;
}
#endif
#ifndef PAGER_SECTOR_SIZE
# define PAGER_SECTOR_SIZE 512
#endif
typedef struct os2File os2File;
struct os2File
{
	IoMethod const *pMethod;
	HFILE h;
	int delOnClose;
	char* pathToDel;
	unsigned char locktype;
};
#ifndef WN_SQL_OMIT_DISKIO
int WN_SQL3Os2Delete(const char *zFilename)
{
	APIRET rc=DosDelete((PSZ)zFilename);
	OSTRACE2("DELETE \"%s\"\n",zFilename);
	return rc==NO_ERROR ? 0 :WN_SQL_IOERR;
}
int WN_SQL3Os2FileExists(const char *zFilename)
{
	FILESTATUS3 fsts3ConfigInfo;
	memset(&fsts3ConfigInfo,0,sizeof(fsts3ConfigInfo));
	return DosQueryPathInfo((PSZ)zFilename,FIL_STANDARD,&fsts3ConfigInfo,sizeof(FILESTATUS3))==NO_ERROR;
}
int allocateOs2File(os2File *pInit,OsFile **pld);
int WN_SQL3Os2OpenReadWrite(const char *zFilename,OsFile **pld,int *pReadonly)
{
	os2File f;
	HFILE hf;
	ULONG ulAction;
	APIRET rc=DosOpen((PSZ)zFilename,&hf,&ulAction,0L,FILE_ARCHIVED | FILE_NORMAL,OPEN_ACTION_CREATE_IF_NEW | OPEN_ACTION_OPEN_IF_EXISTS,OPEN_FLAGS_FAIL_ON_ERROR | OPEN_FLAGS_RANDOM | OPEN_SHARE_DENYNONE | OPEN_ACCESS_READWRITE,(PEAOP2)NULL);
	if(rc!=NO_ERROR)
	{
		rc=DosOpen((PSZ)zFilename,&hf,&ulAction,0L,FILE_ARCHIVED | FILE_NORMAL,OPEN_ACTION_CREATE_IF_NEW | OPEN_ACTION_OPEN_IF_EXISTS,OPEN_FLAGS_FAIL_ON_ERROR | OPEN_FLAGS_RANDOM | OPEN_SHARE_DENYWRITE | OPEN_ACCESS_READONLY,(PEAOP2)NULL);
	if(rc!=NO_ERROR)return WN_SQL_CANTOPEN;
		*pReadonly=1;
	}
	else
		*pReadonly=0;
	f.h=hf;
	f.locktype=NO_LOCK;
	f.delOnClose=0;
	f.pathToDel=NULL;
	OpenCounter(+1);
	OSTRACE3("OPEN R/W %d \"%s\"\n",hf,zFilename);
	return allocateOs2File(&f,pld);
}
int WN_SQL3Os2OpenExclusive(const char *zFilename,OsFile **pld,int delFlag)
{
	os2File f;
	HFILE hf;
	ULONG ulAction;
	APIRET rc=DosOpen((PSZ)zFilename,&hf,&ulAction,0L,FILE_NORMAL,OPEN_ACTION_CREATE_IF_NEW | OPEN_ACTION_REPLACE_IF_EXISTS,OPEN_FLAGS_FAIL_ON_ERROR | OPEN_FLAGS_RANDOM | OPEN_SHARE_DENYREADWRITE | OPEN_ACCESS_READWRITE,(PEAOP2)NULL);
	if(rc!=NO_ERROR)return WN_SQL_CANTOPEN;
	f.h=hf;
	f.locktype=NO_LOCK;
	f.delOnClose=delFlag ? 1 :0;
	f.pathToDel=delFlag ? WN_SQL3OsFullPathname(zFilename):NULL;
	OpenCounter(+1);
	if(delFlag)DosForceDelete((PSZ)WN_SQL3OsFullPathname(zFilename));
	OSTRACE3("OPEN EX %d \"%s\"\n",hf,WN_SQL3OsFullPathname(zFilename));
	return allocateOs2File(&f,pld);
}
int WN_SQL3Os2OpenReadOnly(const char *zFilename,OsFile **pld)
{
	os2File f;
	HFILE hf;
	ULONG ulAction;
	APIRET rc=DosOpen((PSZ)zFilename,&hf,&ulAction,0L,FILE_NORMAL,OPEN_SHARE_DENYWRITE | OPEN_ACCESS_READONLY,(PEAOP2)NULL);
	if(DosOpen((PSZ)zFilename,&hf,&ulAction,0L,FILE_NORMAL,OPEN_ACTION_OPEN_IF_EXISTS,OPEN_FLAGS_FAIL_ON_ERROR | OPEN_FLAGS_RANDOM | OPEN_SHARE_DENYWRITE | OPEN_ACCESS_READONLY,(PEAOP2)NULL)!=NO_ERROR)return WN_SQL_CANTOPEN;
	f.h=hf;
	f.locktype=NO_LOCK;
	f.delOnClose=0;
	f.pathToDel=NULL;
	OpenCounter(+1);
	OSTRACE3("OPEN RO %d \"%s\"\n",hf,zFilename);
	return allocateOs2File(&f,pld);
}
int os2OpenDirectory(OsFile *id,const char *zDirname)
{
	return 0;
}
int WN_SQL3Os2TempFileName(char *zBuf)
{
	const unsigned char zChars[]=
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789";
	int i,j;
	PSZ zTempPath=0;
	if(DosScanEnv((PSZ)"TEMP",&zTempPath)&& DosScanEnv((PSZ)"TMP",&zTempPath)&&DosScanEnv((PSZ)"TMPDIR",&zTempPath))
		ULONG ulDriveNum=0,ulDriveMap=0;
		DosQueryCurrentDisk(&ulDriveNum,&ulDriveMap);
		sprintf((char*)zTempPath,"%c:",(char)('A'+ulDriveNum-1));
	}
	for(;;)
	{
		sprintf(zBuf,"%s\\"TEMP_FILE_PREFIX,zTempPath);
		j=strlen(zBuf);
		WN_SQL3Randomness(15,&zBuf[j]);
		for(i=0;i<15;i++,j++)
			zBuf[j]=(char)zChars[((unsigned char)zBuf[j])%(sizeof(zChars)-1)];
		zBuf[j]=0;
		if(!WN_SQL3OsFileExists(zBuf))break;
	}
	OSTRACE2("TEMP FILENAME:%s\n",zBuf);
	return 0;
}
int os2Close(OsFile **pld)
{
	os2File *pFile;
	APIRET rc=NO_ERROR;
	if(pld &&(pFile=(os2File*)*pld))
	{
		OSTRACE2("CLOSE %d\n",pFile->h);
		rc=DosClose(pFile->h);
		pFile->locktype=NO_LOCK;
		if(pFile->delOnClose)rc=DosForceDelete((PSZ)pFile->pathToDel);
		*pld=0;
		OpenCounter(-1);
	}
	return rc==NO_ERROR ? 0 :WN_SQL_IOERR;
}
int os2Read(OsFile *id,void *pBuf,int amt)
{
	ULONG got;
	SimulateIOError(return WN_SQL_IOERR);
	OSTRACE3("READ %d lock=%d\n",((os2File*)id)->h,((os2File*)id)->locktype);
	DosRead(((os2File*)id)->h,pBuf,amt,&got);
	if(got==(ULONG)amt)
		return 0;
	else
		if(got==0)
			return WN_SQL_IOERR_READ;
		else
		{
			memset(&((char*)pBuf)[got],0,amt-got);
			return WN_SQL_IOERR_SHORT_READ;
		}
}
int os2Write(OsFile *id,const void *pBuf,int amt)
{
	APIRET rc=NO_ERROR;
	ULONG wrote;
	SimulateIOError(return WN_SQL_IOERR);
	SimulateDiskfullError(return WN_SQL_FULL);
	OSTRACE3("WRITE %d lock=%d\n",((os2File*)id)->h,((os2File*)id)->locktype);
	while(amt > 0 && (rc=DosWrite(((os2File*)id)->h,(PVOID)pBuf,amt,&wrote))&& wrote > 0)
	{
		amt-=wrote;
		pBuf=&((char*)pBuf)[wrote];
	}
	return(rc!=NO_ERROR || amt >(int)wrote)? WN_SQL_FULL :0;
}
int os2Seek(OsFile *id,i64 offset)
{
	APIRET rc=NO_ERROR;
	ULONG filePointer=0L;
	rc=DosSetFilePtr(((os2File*)id)->h,offset,FILE_BEGIN,&filePointer);
	OSTRACE3("SEEK %d %lld\n",((os2File*)id)->h,offset);
	return rc==NO_ERROR ? 0 :WN_SQL_IOERR;
}
int os2Sync(OsFile *id,int dataOnly)
{
	OSTRACE3("SYNC %d lock=%d\n",((os2File*)id)->h,((os2File*)id)->locktype);
	return DosResetBuffer(((os2File*)id)->h)==NO_ERROR ? 0 :WN_SQL_IOERR;
}
int WN_SQL3Os2SyncDirectory(const char *zDirname)
{
	SimulateIOError(return WN_SQL_IOERR);
	return 0;
}
int os2Truncate(OsFile *id,i64 nByte)
{
	APIRET rc=NO_ERROR;
	ULONG upperBits=nByte>>32;
	OSTRACE3("TRUNCATE %d %lld\n",((os2File*)id)->h,nByte);
	SimulateIOError(return WN_SQL_IOERR);
	rc=DosSetFilePtr(((os2File*)id)->h,nByte,FILE_BEGIN,&upperBits);
	if(rc!=NO_ERROR)return WN_SQL_IOERR;
	rc=DosSetFilePtr(((os2File*)id)->h,0L,FILE_END,&upperBits);
	return rc==NO_ERROR ? 0 :WN_SQL_IOERR;
}
int os2FileSize(OsFile *id,i64 *pSize)
{
	APIRET rc=NO_ERROR;
	FILESTATUS3 fsts3FileInfo;
	memset(&fsts3FileInfo,0,sizeof(fsts3FileInfo));
	SimulateIOError(return WN_SQL_IOERR);
	rc=DosQueryFileInfo(((os2File*)id)->h,FIL_STANDARD,&fsts3FileInfo,sizeof(FILESTATUS3));
	if(rc==NO_ERROR)
	{
		*pSize=fsts3FileInfo.cbFile;
		return 0;
	}
	else
		return WN_SQL_IOERR;
}
int getReadLock(os2File *id)
{
	FILELOCK LockArea,UnlockArea;
	memset(&LockArea,0,sizeof(LockArea));
	memset(&UnlockArea,0,sizeof(UnlockArea));
	LockArea.lOffset=SHARED_FIRST;
	LockArea.lRange=SHARED_SIZE;
	UnlockArea.lOffset=0L;
	UnlockArea.lRange=0L;
	return DosSetFileLocks(id->h,&UnlockArea,&LockArea,2000L,1L);
}
int unlockReadLock(os2File *id)
{
	FILELOCK LockArea,UnlockArea;
	memset(&LockArea,0,sizeof(LockArea));
	memset(&UnlockArea,0,sizeof(UnlockArea));
	LockArea.lOffset=0L;
	LockArea.lRange=0L;
	UnlockArea.lOffset=SHARED_FIRST;
	UnlockArea.lRange=SHARED_SIZE;
	return DosSetFileLocks(id->h,&UnlockArea,&LockArea,2000L,1L);
}
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
int WN_SQL3Os2IsDirWritable(char *zDirname)
{
	FILESTATUS3 fsts3ConfigInfo;
	APIRET rc=NO_ERROR;
	memset(&fsts3ConfigInfo,0,sizeof(fsts3ConfigInfo));
	if(zDirname==0)return 0;
	if(strlen(zDirname)>CCHMAXPATH)return 0;
	rc=DosQueryPathInfo((PSZ)zDirname,FIL_STANDARD,&fsts3ConfigInfo,sizeof(FILESTATUS3));
	if(rc!=NO_ERROR)return 0;
	if((fsts3ConfigInfo.attrFile & FILE_DIRECTORY)!=FILE_DIRECTORY)return 0;
	return 1;
}
#endif
int os2Lock(OsFile *id,int locktype)
{
	APIRET rc=0;
	APIRET res=NO_ERROR;
	int newLocktype;
	int gotPendingLock=0;
	FILELOCK LockArea,UnlockArea;
	os2File *pFile=(os2File*)id;
	memset(&LockArea,0,sizeof(LockArea));
	memset(&UnlockArea,0,sizeof(UnlockArea));
	OSTRACE4("LOCK %d %d was %d\n",pFile->h,locktype,pFile->locktype);
	if(pFile->locktype>=locktype)return 0;
	newLocktype=pFile->locktype;
	if(pFile->locktype==NO_LOCK ||(locktype==EXCLUSIVE_LOCK && pFile->locktype==RESERVED_LOCK))
	{
		int cnt=3;
		LockArea.lOffset=PENDING_BYTE;
		LockArea.lRange=1L;
		UnlockArea.lOffset=0L;
		UnlockArea.lRange=0L;
		while(cnt-->0 &&(res=DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L))!=NO_ERROR)
		{
			OSTRACE2("could not get a PENDING lock. cnt=%d\n",cnt);
			DosSleep(1);
		}
		gotPendingLock=res;
	}
	if(locktype==SHARED_LOCK && res)
	{
		res=getReadLock(pFile);
		if(res==NO_ERROR)newLocktype=SHARED_LOCK;
	}
	if(locktype==RESERVED_LOCK && res)
	{
		LockArea.lOffset=RESERVED_BYTE;
		LockArea.lRange=1L;
		UnlockArea.lOffset=0L;
		UnlockArea.lRange=0L;
		res=DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L);
		if(res==NO_ERROR)newLocktype=RESERVED_LOCK;
	}
	if(locktype==EXCLUSIVE_LOCK && res)
	{
		newLocktype=PENDING_LOCK;
		gotPendingLock=0;
	}
	if(locktype==EXCLUSIVE_LOCK && res)
	{
		res=unlockReadLock(pFile);
		OSTRACE2("unreadlock=%d\n",res);
		LockArea.lOffset=SHARED_FIRST;
		LockArea.lRange=SHARED_SIZE;
		UnlockArea.lOffset=0L;
		UnlockArea.lRange=0L;
		res=DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L);
		if(res==NO_ERROR)
			newLocktype=EXCLUSIVE_LOCK;
		else
			OSTRACE2("error-code=%d\n",res);
	}
	if(gotPendingLock && locktype==SHARED_LOCK)
	{
		LockArea.lOffset=0L;
		LockArea.lRange=0L;
		UnlockArea.lOffset=PENDING_BYTE;
		UnlockArea.lRange=1L;
		DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L);
	}
	if(res==NO_ERROR)
		rc=0;
	else
	{
		OSTRACE4("LOCK FAILED %d trying for %d but got %d\n",pFile->h,locktype,newLocktype);
		rc=WN_SQL_BUSY;
	}
	pFile->locktype=newLocktype;
	return rc;
}
int os2CheckReservedLock(OsFile *id)
{
	APIRET rc=NO_ERROR;
	os2File *pFile=(os2File*)id;
	if(pFile->locktype>=RESERVED_LOCK)
	{
		rc=1;
		OSTRACE3("TEST WR-LOCK %d %d(local)\n",pFile->h,rc);
	}
	else
	{
		FILELOCK LockArea,UnlockArea;
		memset(&LockArea,0,sizeof(LockArea));
		memset(&UnlockArea,0,sizeof(UnlockArea));
		LockArea.lOffset=RESERVED_BYTE;
		LockArea.lRange=1L;
		UnlockArea.lOffset=0L;
		UnlockArea.lRange=0L;
		rc=DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L);
		if(rc==NO_ERROR)
		{
			LockArea.lOffset=0L;
			LockArea.lRange=0L;
			UnlockArea.lOffset=RESERVED_BYTE;
			UnlockArea.lRange=1L;
			rc=DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L);
		}
		OSTRACE3("TEST WR-LOCK %d %d(remote)\n",pFile->h,rc);
	}
	return rc;
}
int os2Unlock(OsFile *id,int locktype)
{
	int type;
	APIRET rc=0;
	os2File *pFile=(os2File*)id;
	FILELOCK LockArea,UnlockArea;
	memset(&LockArea,0,sizeof(LockArea));
	memset(&UnlockArea,0,sizeof(UnlockArea));
	OSTRACE4("UNLOCK %d to %d was %d\n",pFile->h,locktype,pFile->locktype);
	type=pFile->locktype;
	if(type>=EXCLUSIVE_LOCK)
	{
		LockArea.lOffset=0L;
		LockArea.lRange=0L;
		UnlockArea.lOffset=SHARED_FIRST;
		UnlockArea.lRange=SHARED_SIZE;
		DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L);
		if(locktype==SHARED_LOCK && getReadLock(pFile)!=NO_ERROR)rc=WN_SQL_IOERR;
	}
	if(type>=RESERVED_LOCK)
	{
		LockArea.lOffset=0L;
		LockArea.lRange=0L;
		UnlockArea.lOffset=RESERVED_BYTE;
		UnlockArea.lRange=1L;
		DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L);
	}
	if(locktype==NO_LOCK && type>=SHARED_LOCK)unlockReadLock(pFile);
	if(type>=PENDING_LOCK)
	{
		LockArea.lOffset=0L;
		LockArea.lRange=0L;
		UnlockArea.lOffset=PENDING_BYTE;
		UnlockArea.lRange=1L;
		DosSetFileLocks(pFile->h,&UnlockArea,&LockArea,2000L,1L);
	}
	pFile->locktype=locktype;
	return rc;
}
char *WN_SQL3Os2FullPathname(const char *zRelative)
{
	char *zFull=0;
	if(strchr(zRelative,':'))
		WN_SQL3SetString(&zFull,zRelative,(char*)0);
	else
	{
		ULONG ulDriveNum=0,ulDriveMap=0,cbzBufLen=WN_SQL_TEMPNAME_SIZE;
		char zDrive[2],*zBuff=WN_SQL3Malloc(cbzBufLen);
		if(zBuff)
		{
			DosQueryCurrentDisk(&ulDriveNum,&ulDriveMap);
			if(DosQueryCurrentDir(ulDriveNum,(PBYTE)zBuff,&cbzBufLen)==NO_ERROR)
			{
				sprintf(zDrive,"%c",(char)('A'+ulDriveNum-1));
				WN_SQL3SetString(&zFull,zDrive,":\\",zBuff,"\\",zRelative,(char*)0);
			}
			WN_SQL3FreeX(zBuff);
		}
	}
	return zFull;
}
void os2SetFullSync(OsFile *id,int v)
{
	return;
}
int os2FileHandle(OsFile *id)
{
	return(int)((os2File*)id)->h;
}
int os2LockState(OsFile *id)
{
	return((os2File*)id)->locktype;
}
int os2SectorSize(OsFile *id)
{
	return WN_SQL_DEFAULT_SECTOR_SIZE;
}
const IoMethod WN_SQL3Os2IoMethod={os2Close,os2OpenDirectory,os2Read,os2Write,os2Seek,os2Truncate,os2Sync,os2SetFullSync,os2FileHandle,os2FileSize,os2Lock,os2Unlock,os2LockState,os2CheckReservedLock,os2SectorSize,};
int allocateOs2File(os2File *pInit,OsFile **pld)
{
	os2File *pNew=WN_SQL3Malloc(sizeof(*pNew));
	if(pNew==0)
	{
		DosClose(pInit->h);
		*pld=0;
		return WN_SQL_NOMEM;
	}
	else
	{
		*pNew=*pInit;
		pNew->pMethod=&WN_SQL3Os2IoMethod;
		pNew->locktype=NO_LOCK;
		*pld=(OsFile*)pNew;
		OpenCounter(+1);
		return 0;
	}
}
#endif
#ifndef WN_SQL_OMIT_LOAD_EXTENSION
void *WN_SQL3Os2Dlopen(const char *zFilename)
{
	UCHAR loadErr[256];
	HMODULE hmod;
	APIRET rc;
	rc=DosLoadModule((PSZ)loadErr,sizeof(loadErr),zFilename,&hmod);
	if(rc!=NO_ERROR)return 0;
	return(void*)hmod;
}
void *WN_SQL3Os2Dlsym(void *pHandle,const char *zSymbol)
{
	PFN pfn;
	APIRET rc;
	rc=DosQueryProcAddr((HMODULE)pHandle,0L,zSymbol,&pfn);
	if(rc!=NO_ERROR)
	{
		char _zSymbol[256]="_";
		strncat(_zSymbol,zSymbol,255);
		rc=DosQueryProcAddr((HMODULE)pHandle,0L,_zSymbol,&pfn);
	}
	if(rc!=NO_ERROR)return 0;
	return(void *)pfn;
}
int WN_SQL3Os2Dlclose(void *pHandle)
{
	return DosFreeModule((HMODULE)pHandle);
}
#endif
int WN_SQL3Os2RandomSeed(char *zBuf)
{
	memset(zBuf,0,256);
	DosGetDateTime((PDATETIME)zBuf);
	return 0;
}
int WN_SQL3Os2Sleep(int ms)
{
	DosSleep(ms);
	return ms;
}
int inMutex=0;
#ifdef WN_SQL_OS2_THREADS
ULONG mutexOwner;
#endif
void WN_SQL3Os2EnterMutex()
{
#ifdef WN_SQL_OS2_THREADS
	PTIB ptib;
	DosEnterCritSec();
	DosGetInfoBlocks(&ptib,NULL);
	mutexOwner=ptib->tib_ptib2->tib2_ultid;
#endif
	inMutex=1;
}
void WN_SQL3Os2LeaveMutex()
{
#ifdef WN_SQL_OS2_THREADS
	PTIB ptib;
#endif
	inMutex=0;
#ifdef WN_SQL_OS2_THREADS
	DosGetInfoBlocks(&ptib,NULL);
	DosExitCritSec();
#endif
}
int WN_SQL3Os2InMutex(int thisThreadOnly)
{
#ifdef WN_SQL_OS2_THREADS
	PTIB ptib;
	DosGetInfoBlocks(&ptib,NULL);
	return inMutex>0 &&(thisThreadOnly==0 || mutexOwner==ptib->tib_ptib2->tib2_ultid);
#else
	return inMutex>0;
#endif
}
#ifdef WN_SQL_TEST
int WN_SQL3_current_time=0;
#endif
int WN_SQL3Os2CurrentTime(double *prNow)
{
	DATETIME dt;
	DosGetDateTime(&dt);
	USHORT second=(USHORT)dt.seconds,minute=(USHORT)dt.minutes+dt.timezone,hour=(USHORT)dt.hours,day=(USHORT)dt.day,month=(USHORT)dt.month,year=(USHORT)dt.year;
	double now=day-32076+1461*(year+4800+(month-14)/12)/4+367*(month-2-(month-14)/12*12)/12-3*((year+4900+(month-14)/12)/100)/4+(hour+12.0)/24.0+minute/1440.0+second/86400.0;
	*prNow=now;
#ifdef WN_SQL_TEST
	if(WN_SQL3_current_time)*prNow=WN_SQL3_current_time/86400.0+2440587.5;
#endif
	return 0;
}
#ifdef WN_SQL_TEST
int WN_SQL3_tsd_count=0;
# define TSD_COUNTER_INCR InterlockedIncrement(&WN_SQL3_tsd_count)
# define TSD_COUNTER_DECR InterlockedDecrement(&WN_SQL3_tsd_count)
#else
# define TSD_COUNTER_INCR
# define TSD_COUNTER_DECR
#endif
ThreadData *WN_SQL3Os2ThreadSpecificData(int allocateFlag)
{
	ThreadData **s_ppTsd=NULL;
	const ThreadData zeroData={0,0,0};
	ThreadData *pTsd;
	if(!s_ppTsd)
	{
		WN_SQL3OsEnterMutex();
		if(!s_ppTsd)
		{
			PULONG pul;
			APIRET rc=DosAllocThreadLocalMemory(1,&pul);
			if(rc!=NO_ERROR)
			{
				WN_SQL3OsLeaveMutex();
				return 0;
			}
			s_ppTsd=(ThreadData **)pul;
		}
		WN_SQL3OsLeaveMutex();
	}
	pTsd=*s_ppTsd;
	if(allocateFlag>0)
	{
		if(!pTsd)
		{
			pTsd=WN_SQL3OsMalloc(sizeof(zeroData));
			if(pTsd)
			{
				*pTsd=zeroData;
				*s_ppTsd=pTsd;
				TSD_COUNTER_INCR;
	}	}	}
	else
		if(pTsd && allocateFlag<0 && memcmp(pTsd,&zeroData,sizeof(ThreadData))==0)
		{
			WN_SQL3OsFree(pTsd);
			*s_ppTsd=NULL;
			TSD_COUNTER_DECR;
			pTsd=0;
		}
		return pTsd;
}
#endif
#if OS_UNIX
#ifndef WN_SQL_DISABLE_LFS
# define _LARGE_FILE 1
# ifndef _FILE_OFFSET_BITS
# define _FILE_OFFSET_BITS 64
# endif
# define _LARGEFILE_SOURCE 1
#endif
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/time.h>
#include<errno.h>
#ifdef WN_SQL_ENABLE_LOCKING_STYLE
#include<sys/ioctl.h>
#include<sys/param.h>
#include<sys/mount.h>
#endif
#ifndef THREADSAFE
# define THREADSAFE 1
#endif
#if THREADSAFE
# include<pthread.h>
# define WN_SQL_UNIX_THREADS 1
#endif
#ifndef WN_SQL_DEFAULT_FILE_PERMISSIONS
# define WN_SQL_DEFAULT_FILE_PERMISSIONS 0644
#endif
typedef struct unixFile unixFile;
struct unixFile
{
	IoMethod const *pMethod;
	struct openCnt *pOpen;
	struct lockInfo *pLock;
#ifdef WN_SQL_ENABLE_LOCKING_STYLE
	void *lockingContext;
#endif
	int h,dirfd;
	unsigned char locktype,isOpen,fullSync;
	i64 offset;
#ifdef WN_SQL_UNIX_THREADS
	pthread_t tid;
#endif
};
#ifdef WN_SQL_CRASH_TEST
extern int WN_SQL3CrashTestEnable;
extern int WN_SQL3CrashOpenReadWrite(const char*,OsFile**,int*);
extern int WN_SQL3CrashOpenExclusive(const char*,OsFile**,int);
extern int WN_SQL3CrashOpenReadOnly(const char*,OsFile**,int);
# define CRASH_TEST_OVERRIDE(X,A,B,C)\
if(WN_SQL3CrashTestEnable)return X(A,B,C);
#else
# define CRASH_TEST_OVERRIDE(X,A,B,C)
#endif
#ifdef WN_SQL_TEST
u32 WN_SQL3_pending_byte=0x40000000;
#endif
int WN_SQL3_os_trace=0;
#ifdef WN_SQL_DEBUG
#define OSTRACE1(X) if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X)
#define OSTRACE2(X,Y)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y)
#define OSTRACE3(X,Y,Z)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z)
#define OSTRACE4(X,Y,Z,A)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A)
#define OSTRACE5(X,Y,Z,A,B)if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B)
#define OSTRACE6(X,Y,Z,A,B,C)\
if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B,C)
#define OSTRACE7(X,Y,Z,A,B,C,D) \
if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B,C,D)
#else
#define OSTRACE1(X)
#define OSTRACE2(X,Y)
#define OSTRACE3(X,Y,Z)
#define OSTRACE4(X,Y,Z,A)
#define OSTRACE5(X,Y,Z,A,B)
#define OSTRACE6(X,Y,Z,A,B,C)
#define OSTRACE7(X,Y,Z,A,B,C,D)
#endif
#ifdef WN_SQL_PERFORMANCE_TRACE
__inline__ unsigned long long int hwtime(void){
unsigned long long int x;
__asm__("rdtsc\n\t"
"mov %%edx,%%ecx\n\t"
:"=A"(x));
return x;
}
unsigned long long int g_start;
u32 elapse;
#define TIMER_START g_start=hwtime()
#define TIMER_END elapse=hwtime()-g_start
#define TIMER_ELAPSED elapse
#else
#define TIMER_START
#define TIMER_END
#define TIMER_ELAPSED 0
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_io_error_hit=0;
int WN_SQL3_io_error_pending=0;
int WN_SQL3_io_error_persist=0;
int WN_SQL3_diskfull_pending=0;
int WN_SQL3_diskfull=0;
#define SimulateIOError(CODE) \
if(WN_SQL3_io_error_pending || WN_SQL3_io_error_hit)\
if(WN_SQL3_io_error_pending--==1 \
||(WN_SQL3_io_error_persist && WN_SQL3_io_error_hit))\
{local_ioerr();CODE;}
void local_ioerr()
{
	IOTRACE(("IOERR\n"));
	WN_SQL3_io_error_hit=1;
}
#define SimulateDiskfullError(CODE) if(WN_SQL3_diskfull_pending){if(WN_SQL3_diskfull_pending==1){local_ioerr();WN_SQL3_diskfull=1;WN_SQL3_io_error_hit=1;CODE;}else WN_SQL3_diskfull_pending--;}
#else
#define SimulateIOError(A)
#define SimulateDiskfullError(A)
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_open_file_count=0;
#define OpenCounter(X)WN_SQL3_open_file_count+=(X)
#else
#define OpenCounter(X)
#endif
#if defined(WN_SQL_ENABLE_MEMORY_MANAGEMENT)|| defined(WN_SQL_MEMDEBUG)
void *WN_SQL3GenericMalloc(int n)
{
	char *p=(char *)malloc(n+8);
	if(p)
	{
		*(int *)p=n;
		p+=8;
	}
	return(void *)p;
}
void *WN_SQL3GenericRealloc(void *p,int n)
{
	char *p2=((char *)p-8);
	p2=(char*)realloc(p2,n+8);
	if(p2)
	{
		*(int *)p2=n;
		p2+=8;
	}
	return(void *)p2;
}
void WN_SQL3GenericFree(void *p)
{
	free((void *)((char *)p-8));
}
int WN_SQL3GenericAllocationSize(void *p)
{
	return p ? *(int *)((char *)p-8):0;
}
#else
void *WN_SQL3GenericMalloc(int n)
{
	char *p=(char *)malloc(n);
	return(void *)p;
}
void *WN_SQL3GenericRealloc(void *p,int n)
{
	p=realloc(p,n);
	return p;
}
void WN_SQL3GenericFree(void *p)
{
	free(p);
}
int WN_SQL3GenericAllocationSize(void *p)
{
	return 0;
}
#endif
#ifndef PAGER_SECTOR_SIZE
# define PAGER_SECTOR_SIZE 512
#endif
#ifndef WN_SQL_OMIT_DISKIO
#ifndef O_LARGEFILE
# define O_LARGEFILE 0
#endif
#ifdef WN_SQL_DISABLE_LFS
# undef O_LARGEFILE
# define O_LARGEFILE 0
#endif
#ifndef O_NOFOLLOW
# define O_NOFOLLOW 0
#endif
#ifndef O_BINARY
# define O_BINARY 0
#endif
#ifdef __DJGPP__
# define fcntl(A,B,C)0
#endif
#ifdef WN_SQL_UNIX_THREADS
#define threadid pthread_self()
#else
#define threadid 0
#endif
#if defined(WN_SQL_UNIX_THREADS)
# define SET_THREADID(X) (X)->tid=pthread_self()
# define CHECK_THREADID(X)(threadsOverrideEachOthersLocks==0 && \
!pthread_equal((X)->tid,pthread_self()))
#else
# define SET_THREADID(X)
# define CHECK_THREADID(X)0
#endif
struct lockKey
{
	dev_t dev;
	ino_t ino;
#ifdef WN_SQL_UNIX_THREADS
	pthread_t tid;
#endif
};
struct lockInfo
{
	struct lockKey key;
	int cnt,locktype,nRef;
};
struct openKey
{
	dev_t dev;
	ino_t ino;
};
struct openCnt
{
	struct openKey key;
	int nRef,nLock,nPending,*aPending;
};
Hash lockHash={WN_SQL_HASH_BINARY,0,0,0,WN_SQL3ThreadSafeMalloc,WN_SQL3ThreadSafeFree,0,0};
Hash openHash={WN_SQL_HASH_BINARY,0,0,0,WN_SQL3ThreadSafeMalloc,WN_SQL3ThreadSafeFree,0,0};
#ifdef WN_SQL_ENABLE_LOCKING_STYLE
typedef enum {
	posixLockingStyle=0,	afpLockingStyle,	flockLockingStyle,	dotlockLockingStyle,	noLockingStyle,	unsupportedLockingStyle
}WN_SQL3LockingStyle;
#endif
#ifdef WN_SQL_UNIX_THREADS
#ifndef WN_SQL_THREAD_OVERRIDE_LOCK
# define WN_SQL_THREAD_OVERRIDE_LOCK-1
#endif
#ifdef WN_SQL_TEST
int threadsOverrideEachOthersLocks=WN_SQL_THREAD_OVERRIDE_LOCK;
#else
int threadsOverrideEachOthersLocks=WN_SQL_THREAD_OVERRIDE_LOCK;
#endif
struct threadTestData
{
	int fd,result;
	struct flock lock;
};
#ifdef WN_SQL_LOCK_TRACE
int lockTrace(int fd,int op,struct flock *p)
{
	char *zOpName,*zType;
	int s,savedErrno;
	if(op==F_GETLK)
		zOpName="GETLK";
	else
		if(op==F_SETLK)
			zOpName="SETLK";
		else
		{
			s=fcntl(fd,op,p);
			WN_SQL3DebugPrintf("fcntl unknown %d %d %d\n",fd,op,s);
			return s;
		}
	if(p->l_type==F_RDLCK)
		zType="RDLCK";
	else
		if(p->l_type==F_WRLCK)
			zType="WRLCK";
		else
			if(p->l_type==F_UNLCK)
				zType="UNLCK";
	s=fcntl(fd,op,p);
	savedErrno=errno;
	WN_SQL3DebugPrintf("fcntl %d %d %s %s %d %d %d %d\n",threadid,fd,zOpName,zType,(int)p->l_start,(int)p->l_len,(int)p->l_pid,s);
	if(s==(-1)&& op==F_SETLK &&(p->l_type==F_RDLCK || p->l_type==F_WRLCK))
	{
		struct flock l2;
		l2=*p;
		fcntl(fd,F_GETLK,&l2);
		if(l2.l_type==F_RDLCK)
			zType="RDLCK";
		else
			if(l2.l_type==F_WRLCK)
				zType="WRLCK";
			else
				if(l2.l_type==F_UNLCK)zType="UNLCK";
		WN_SQL3DebugPrintf("fcntl-failure-reason:%s %d %d %d\n",zType,(int)l2.l_start,(int)l2.l_len,(int)l2.l_pid);
	}
	errno=savedErrno;
	return s;
}
#define fcntl lockTrace
#endif
void *threadLockingTest(void *pArg)
{
	struct threadTestData *pData=(struct threadTestData*)pArg;
	pData->result=fcntl(pData->fd,F_SETLK,&pData->lock);
	return pArg;
}
void testThreadLockingBehavior(int fd_orig)
{
	struct threadTestData d[2];
	pthread_t t[2];
	int fd=dup(fd_orig);
	if(fd<0)return;
	memset(d,0,sizeof(d));
	d[0].fd=fd;
	d[0].lock.l_type=F_RDLCK;
	d[0].lock.l_len=1;
	d[0].lock.l_start=0;
	d[0].lock.l_whence=SEEK_SET;
	d[1]=d[0];
	d[1].lock.l_type=F_WRLCK;
	pthread_create(&t[0],0,threadLockingTest,&d[0]);
	pthread_create(&t[1],0,threadLockingTest,&d[1]);
	pthread_join(t[0],0);
	pthread_join(t[1],0);
	close(fd);
	threadsOverrideEachOthersLocks=d[0].result==0 && d[1].result==0;
}
#endif
void releaseLockInfo(struct lockInfo *pLock)
{
	if(pLock==NULL)return;
	pLock->nRef--;
	if(pLock->nRef==0)
	{
		WN_SQL3HashInsert(&lockHash,&pLock->key,sizeof(pLock->key),0);
		WN_SQL3ThreadSafeFree(pLock);
	}
}
void releaseOpenCnt(struct openCnt *pOpen)
{
	if(pOpen==NULL)return;
	pOpen->nRef--;
	if(pOpen->nRef==0)
	{
		WN_SQL3HashInsert(&openHash,&pOpen->key,sizeof(pOpen->key),0);
		free(pOpen->aPending);
		WN_SQL3ThreadSafeFree(pOpen);
	}
}
#ifdef WN_SQL_ENABLE_LOCKING_STYLE
WN_SQL3LockingStyle WN_SQL3TestLockingStyle(const char *filePath,int fd)
{
	struct flock lockInfo;
	lockInfo.l_len=1;
	lockInfo.l_start=0;
	lockInfo.l_whence=SEEK_SET;
	lockInfo.l_type=F_RDLCK;
	if(fcntl(fd,F_GETLK,&lockInfo)!=-1)return posixLockingStyle;
	return dotlockLockingStyle;
}
WN_SQL3LockingStyle WN_SQL3DetectLockingStyle(const char *filePath,int fd)
{
#ifdef WN_SQL_FIXED_LOCKING_STYLE
	return(WN_SQL3LockingStyle)WN_SQL_FIXED_LOCKING_STYLE;
#else
	struct statfs fsInfo;
	if(statfs(filePath,&fsInfo)==-1)return WN_SQL3TestLockingStyle(filePath,fd);
	if(fsInfo.f_flags & MNT_RDONLY)return noLockingStyle;
	if((!strcmp(fsInfo.f_fstypename,"hfs"))||(!strcmp(fsInfo.f_fstypename,"ufs")))return posixLockingStyle;
	if(!strcmp(fsInfo.f_fstypename,"afpfs"))return afpLockingStyle;
	if(!strcmp(fsInfo.f_fstypename,"nfs"))return WN_SQL3TestLockingStyle(filePath,fd);
	if(!strcmp(fsInfo.f_fstypename,"smbfs"))return flockLockingStyle;
	if(!strcmp(fsInfo.f_fstypename,"msdos"))return dotlockLockingStyle;
	if(!strcmp(fsInfo.f_fstypename,"webdav"))return unsupportedLockingStyle;
	return WN_SQL3TestLockingStyle(filePath,fd);
#endif
}
#endif
int findLockInfo(int fd,struct lockInfo **ppLock,struct openCnt **ppOpen)
{
	int rc;
	struct stat statbuf;
	if(rc=fstat(fd,&statbuf))return 1;
	struct lockKey key1;
	struct openKey key2;
	struct lockInfo *pLock;
	struct openCnt *pOpen;
	memset(&key1,0,sizeof(key1));
	key1.dev=statbuf.st_dev;
	key1.ino=statbuf.st_ino;
#ifdef WN_SQL_UNIX_THREADS
	if(threadsOverrideEachOthersLocks<0)testThreadLockingBehavior(fd);
	key1.tid=threadsOverrideEachOthersLocks ? 0 :pthread_self();
#endif
	memset(&key2,0,sizeof(key2));
	key2.dev=statbuf.st_dev;
	key2.ino=statbuf.st_ino;
	pLock=(struct lockInfo*)WN_SQL3HashFind(&lockHash,&key1,sizeof(key1));
	if(pLock==0)
	{
		struct lockInfo *pOld;
		pLock=WN_SQL3ThreadSafeMalloc(sizeof(*pLock));
		if(pLock==0)
		{
			rc=1;
			goto exit_findlockinfo;
		}
		pLock->key=key1;
		pLock->nRef=1;
		pLock->cnt=0;
		pLock->locktype=0;
		pOld=WN_SQL3HashInsert(&lockHash,&pLock->key,sizeof(key1),pLock);
		if(pOld)
		{
			WN_SQL3ThreadSafeFree(pLock);
			rc=1;
			goto exit_findlockinfo;
		}
	}
	else
		pLock->nRef++;
	*ppLock=pLock;
	if(ppOpen)
	{
		pOpen=(struct openCnt*)WN_SQL3HashFind(&openHash,&key2,sizeof(key2));
		if(pOpen==0)
		{
			struct openCnt *pOld;
			pOpen=WN_SQL3ThreadSafeMalloc(sizeof(*pOpen));
			if(pOpen==0)
			{
				releaseLockInfo(pLock);
				rc=1;
				goto exit_findlockinfo;
			}
			pOpen->key=key2;
			pOpen->nRef=1;
			pOpen->nLock=0;
			pOpen->nPending=0;
			pOpen->aPending=0;
			pOld=WN_SQL3HashInsert(&openHash,&pOpen->key,sizeof(key2),pOpen);
			if(pOld)
			{
				WN_SQL3ThreadSafeFree(pOpen);
				releaseLockInfo(pLock);
				rc=1;
				goto exit_findlockinfo;
			}
		}
		else
			pOpen->nRef++;
		*ppOpen=pOpen;
	}
exit_findlockinfo:
	return rc;
}
#ifdef WN_SQL_DEBUG
const char *locktypeName(int locktype)
{
	switch(locktype)
	{
	case NO_LOCK:
		return "NONE";
	case SHARED_LOCK:
		return "SHARED";
	case RESERVED_LOCK:
		return "RESERVED";
	case PENDING_LOCK:
		return "PENDING";
	case EXCLUSIVE_LOCK:
		return "EXCLUSIVE";
	}
	return "ERROR";
}
#endif
#ifdef WN_SQL_UNIX_THREADS
	int transferOwnership(unixFile *pFile)
	{
		if(threadsOverrideEachOthersLocks)return 0;
		pthread_t hSelf=pthread_self();
		if(pthread_equal(pFile->tid,hSelf))
		{
			OSTRACE1("No-transfer,same thread\n");
			return 0;
		}
		if(pFile->locktype!=NO_LOCK)return WN_SQL_MISUSE;
		OSTRACE4("Transfer ownership of %d from %d to %d\n",pFile->h,pFile->tid,hSelf);
		pFile->tid=hSelf;
		if(pFile->pLock!=NULL)
		{
			releaseLockInfo(pFile->pLock);
			int rc=findLockInfo(pFile->h,&pFile->pLock,0);
			OSTRACE5("LOCK %d is now %s(%s,%d)\n",pFile->h,locktypeName(pFile->locktype),locktypeName(pFile->pLock->locktype),pFile->pLock->cnt);
			return rc;
		}
		else
			return 0;
	}
#else
# define transferOwnership(X)0
#endif
int WN_SQL3UnixDelete(const char *zFilename)
{
	SimulateIOError(return WN_SQL_IOERR_DELETE);
	unlink(zFilename);
	return 0;
}
int WN_SQL3UnixFileExists(const char *zFilename)
{
	return access(zFilename,0)==0;
}
int allocateUnixFile(int h,OsFile **pId,const char *zFilename,int delFlag);
int WN_SQL3UnixOpenReadWrite(const char *zFilename,OsFile **pId,int *pReadonly)
{
	CRASH_TEST_OVERRIDE(WN_SQL3CrashOpenReadWrite,zFilename,pId,pReadonly);
	int h=open(zFilename,O_RDWR|O_CREAT|O_LARGEFILE|O_BINARY,WN_SQL_DEFAULT_FILE_PERMISSIONS);
	if(h<0)
	{
#ifdef EISDIR
		if(errno==EISDIR)return WN_SQL_CANTOPEN;
#endif
		h=open(zFilename,O_RDONLY|O_LARGEFILE|O_BINARY);
		if(h<0)return WN_SQL_CANTOPEN;
		*pReadonly=1;
	}
	else
		*pReadonly=0;
	return allocateUnixFile(h,pId,zFilename,0);
}
int WN_SQL3UnixOpenExclusive(const char *zFilename,OsFile **pId,int delFlag)
{
	CRASH_TEST_OVERRIDE(WN_SQL3CrashOpenExclusive,zFilename,pId,delFlag);
	int h=open(zFilename,O_RDWR|O_CREAT|O_EXCL|O_NOFOLLOW|O_LARGEFILE|O_BINARY,delFlag ? 0600 :WN_SQL_DEFAULT_FILE_PERMISSIONS);
	if(h<0)return WN_SQL_CANTOPEN;
	return allocateUnixFile(h,pId,zFilename,delFlag);
}
int WN_SQL3UnixOpenReadOnly(const char *zFilename,OsFile **pId)
{
	CRASH_TEST_OVERRIDE(WN_SQL3CrashOpenReadOnly,zFilename,pId,0);
	int h=open(zFilename,O_RDONLY|O_LARGEFILE|O_BINARY);
	if(h<0)	return WN_SQL_CANTOPEN;
	return allocateUnixFile(h,pId,zFilename,0);
}
int unixOpenDirectory(OsFile *id,const char *zDirname)
{
	int h;
	unixFile *pFile=(unixFile*)id;
	SET_THREADID(pFile);
	pFile->dirfd=h=open(zDirname,O_RDONLY|O_BINARY,0);
	if(h<0)return WN_SQL_CANTOPEN;
#ifdef FD_CLOEXEC
	fcntl(h,F_SETFD,fcntl(h,F_GETFD,0)| FD_CLOEXEC);
#endif
	OSTRACE3("OPENDIR %-3d %s\n",h,zDirname);
	return 0;
}
int WN_SQL3UnixTempFileName(char *zBuf)
{
	const char *azDirs[]={0,"/var/tmp","/usr/tmp","/tmp",".",};
	const unsigned char zChars[]=
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789";
	int i,j;
	struct stat buf;
	const char *zDir=".";
	azDirs[0]=WN_SQL3_temp_directory;
	for(i=0;i<sizeof(azDirs)/sizeof(azDirs[0]);i++)
		if(azDirs[i] && !stat(azDirs[i],&buf) &&S_ISDIR(buf.st_mode)&&!access(azDirs[i],07))
		{
			zDir=azDirs[i];
			break;
		}
	do
	{
		WN_SQL3_snprintf(WN_SQL_TEMPNAME_SIZE,zBuf,"%s/"TEMP_FILE_PREFIX,zDir);
		j=strlen(zBuf);
		WN_SQL3Randomness(15,&zBuf[j]);
		for(i=0;i<15;i++,j++)zBuf[j]=(char)zChars[((unsigned char)zBuf[j])%(sizeof(zChars)-1)];
		zBuf[j]=0;
	}while(access(zBuf,0)==0);
	return 0;
}
int WN_SQL3UnixIsDirWritable(char *zBuf)
{
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
	struct stat buf;
	return zBuf&&zBuf[0]&&!stat(zBuf,&buf)&&S_ISDIR(buf.st_mode)&&!access(zBuf,07);
#endif
	return 1;
}
int seekAndRead(unixFile *id,void *pBuf,int cnt)
{
	int got;
	i64 newOffset;
	TIMER_START;
#if defined(USE_PREAD)
	got=pread(id->h,pBuf,cnt,id->offset);
	SimulateIOError(got=-1);
#elif defined(USE_PREAD64)
	got=pread64(id->h,pBuf,cnt,id->offset);
	SimulateIOError(got=-1);
#else
	newOffset=lseek(id->h,id->offset,SEEK_SET);
	SimulateIOError(newOffset--);
	if(newOffset!=id->offset)return-1;
	got=read(id->h,pBuf,cnt);
#endif
	TIMER_END;
	OSTRACE5("READ %-3d %5d %7lld %d\n",id->h,got,id->offset,TIMER_ELAPSED);
	if(got>0)id->offset+=got;
	return got;
}
int unixRead(OsFile *id,void *pBuf,int amt)
{
	int got=seekAndRead((unixFile*)id,pBuf,amt);
	if(got==amt)
		return 0;
	else
		if(got<0)
			return WN_SQL_IOERR_READ;
		else
		{
			memset(&((char*)pBuf)[got],0,amt-got);
			return WN_SQL_IOERR_SHORT_READ;
		}
}
int seekAndWrite(unixFile *id,const void *pBuf,int cnt)
{
	int got;
	i64 newOffset;
	TIMER_START;
#if defined(USE_PREAD)
	got=pwrite(id->h,pBuf,cnt,id->offset);
#elif defined(USE_PREAD64)
	got=pwrite64(id->h,pBuf,cnt,id->offset);
#else
	newOffset=lseek(id->h,id->offset,SEEK_SET);
	if(newOffset!=id->offset)return-1;
	got=write(id->h,pBuf,cnt);
#endif
	TIMER_END;
	OSTRACE5("WRITE %-3d %5d %7lld %d\n",id->h,got,id->offset,TIMER_ELAPSED);
	if(got>0)id->offset+=got;
	return got;
}
int unixWrite(OsFile *id,const void *pBuf,int amt)
{
	int wrote=0;
	while(amt>0 &&(wrote=seekAndWrite((unixFile*)id,pBuf,amt))>0)
	{
		amt-=wrote;
		pBuf=&((char*)pBuf)[wrote];
	}
	SimulateIOError((wrote=(-1),amt=1));
	SimulateDiskfullError((wrote=0,amt=1));
	if(amt>0)
	{
		if(wrote<0)
			return WN_SQL_IOERR_WRITE;
		else
			return WN_SQL_FULL;
	}
	return 0;
}
int unixSeek(OsFile *id,i64 offset)
{
#ifdef WN_SQL_TEST
	if(offset)SimulateDiskfullError(return WN_SQL_FULL);
#endif
	((unixFile*)id)->offset=offset;
	return 0;
}
#ifdef WN_SQL_TEST
int WN_SQL3_sync_count=0;
int WN_SQL3_fullsync_count=0;
#endif
#ifndef HAVE_FDATASYNC
# define fdatasync fsync
#endif
#ifdef F_FULLFSYNC
# define HAVE_FULLFSYNC 1
#else
# define HAVE_FULLFSYNC 0
#endif
int full_fsync(int fd,int fullSync,int dataOnly)
{
	int rc;
#ifdef WN_SQL_TEST
	if(fullSync)WN_SQL3_fullsync_count++;
	WN_SQL3_sync_count++;
#endif
#ifdef WN_SQL_NO_SYNC
	rc=0;
#else
#if HAVE_FULLFSYNC
	if(fullSync)
		rc=fcntl(fd,F_FULLFSYNC,0);
	else
		rc=1;
	if(rc)rc=fsync(fd);
#else
	if(dataOnly)
		rc=fdatasync(fd);
	else
		rc=fsync(fd);
#endif
#endif
	return rc;
}
int unixSync(OsFile *id,int dataOnly)
{
	unixFile *pFile=(unixFile*)id;
	OSTRACE2("SYNC %-3d\n",pFile->h);
	int rc=full_fsync(pFile->h,pFile->fullSync,dataOnly);
	SimulateIOError(rc=1);
	if(rc)return WN_SQL_IOERR_FSYNC;
	if(pFile->dirfd>=0)
	{
		OSTRACE4("DIRSYNC %-3d(have_fullfsync=%d fullsync=%d)\n",pFile->dirfd,HAVE_FULLFSYNC,pFile->fullSync);
#ifndef WN_SQL_DISABLE_DIRSYNC
		if((!HAVE_FULLFSYNC || !pFile->fullSync)&& full_fsync(pFile->dirfd,0,0))
		{}
#endif
		close(pFile->dirfd);
		pFile->dirfd=-1;
	}
	return 0;
}
int WN_SQL3UnixSyncDirectory(const char *zDirname)
{
#ifdef WN_SQL_DISABLE_DIRSYNC
	return 0;
#else
	int fd=open(zDirname,O_RDONLY|O_BINARY,0);
	OSTRACE3("DIRSYNC %-3d(%s)\n",fd,zDirname);
	if(fd<0)return WN_SQL_CANTOPEN;
	int r=fsync(fd);
	close(fd);
	SimulateIOError(r=1);
	if(r)
		return WN_SQL_IOERR_DIR_FSYNC;
	else
		return 0;
#endif
}
int unixTruncate(OsFile *id,i64 nByte)
{
	int rc=ftruncate(((unixFile*)id)->h,(off_t)nByte);
	SimulateIOError(rc=1);
	if(rc)
		return WN_SQL_IOERR_TRUNCATE;
	else
		return 0;
}
int unixFileSize(OsFile *id,i64 *pSize)
{
	struct stat buf;
	int rc=fstat(((unixFile*)id)->h,&buf);
	SimulateIOError(rc=1);
	if(rc)return WN_SQL_IOERR_FSTAT;
	*pSize=buf.st_size;
	return 0;
}
int unixCheckReservedLock(OsFile *id)
{
	int r=0;
	unixFile *pFile=(unixFile*)id;
	WN_SQL3OsEnterMutex();
	if(pFile->pLock->locktype>SHARED_LOCK)r=1;
	if(!r)
	{
		struct flock lock;
		lock.l_whence=SEEK_SET;
		lock.l_start=RESERVED_BYTE;
		lock.l_len=1;
		lock.l_type=F_WRLCK;
		fcntl(pFile->h,F_GETLK,&lock);
		if(lock.l_type!=F_UNLCK)r=1;
	}
	WN_SQL3OsLeaveMutex();
	OSTRACE3("TEST WR-LOCK %d %d\n",pFile->h,r);
	return r;
}
int unixLock(OsFile *id,int locktype)
{
	int rc=0;
	unixFile *pFile=(unixFile*)id;
	struct lockInfo *pLock=pFile->pLock;
	struct flock lock;
	int s;
	OSTRACE7("LOCK %d %s was %s(%s,%d)pid=%d\n",pFile->h,locktypeName(locktype),locktypeName(pFile->locktype),locktypeName(pLock->locktype),pLock->cnt ,getpid());
	if(pFile->locktype>=locktype)
	{
		OSTRACE3("LOCK %d %s ok(already held)\n",pFile->h,locktypeName(locktype));
		return 0;
	}
	WN_SQL3OsEnterMutex();
	rc=transferOwnership(pFile);
	if(rc)
	{
		WN_SQL3OsLeaveMutex();
		return rc;
	}
	pLock=pFile->pLock;
	if((pFile->locktype!=pLock->locktype &&(pLock->locktype>=PENDING_LOCK || locktype>SHARED_LOCK)))
	{
		rc=WN_SQL_BUSY;
		goto end_lock;
	}
	if(locktype==SHARED_LOCK &&(pLock->locktype==SHARED_LOCK || pLock->locktype==RESERVED_LOCK))
	{
		pFile->locktype=SHARED_LOCK;
		pLock->cnt++;
		pFile->pOpen->nLock++;
		goto end_lock;
	}
	lock.l_len=1L;
	lock.l_whence=SEEK_SET;
	if(locktype==SHARED_LOCK||(locktype==EXCLUSIVE_LOCK && pFile->locktype<PENDING_LOCK))
	{
		lock.l_type=(locktype==SHARED_LOCK?F_RDLCK:F_WRLCK);
		lock.l_start=PENDING_BYTE;
		s=fcntl(pFile->h,F_SETLK,&lock);
		if(s==(-1))
		{
			rc=(errno==EINVAL)? WN_SQL_NOLFS :WN_SQL_BUSY;
			goto end_lock;
		}
	}
	if(locktype==SHARED_LOCK)
	{
		lock.l_start=SHARED_FIRST;
		lock.l_len=SHARED_SIZE;
		s=fcntl(pFile->h,F_SETLK,&lock);
		lock.l_start=PENDING_BYTE;
		lock.l_len=1L;
		lock.l_type=F_UNLCK;
		if(fcntl(pFile->h,F_SETLK,&lock))
		{
			rc=WN_SQL_IOERR_UNLOCK;
			goto end_lock;
		}
		if(s==(-1))
			rc=(errno==EINVAL)? WN_SQL_NOLFS :WN_SQL_BUSY;
		else
		{
			pFile->locktype=SHARED_LOCK;
			pFile->pOpen->nLock++;
			pLock->cnt=1;
		}
	}
	else
		if(locktype==EXCLUSIVE_LOCK && pLock->cnt>1)
			rc=WN_SQL_BUSY;
		else
		{
			lock.l_type=F_WRLCK;
			switch(locktype)
			{
			case RESERVED_LOCK:
				lock.l_start=RESERVED_BYTE;
				break;
			case EXCLUSIVE_LOCK:
				lock.l_start=SHARED_FIRST;
				lock.l_len=SHARED_SIZE;
				break;
			default:
			}
			s=fcntl(pFile->h,F_SETLK,&lock);
			if(s==(-1))rc=(errno==EINVAL)? WN_SQL_NOLFS :WN_SQL_BUSY;
		}
		if(rc==0)
		{
			pFile->locktype=locktype;
			pLock->locktype=locktype;
		}
		else
			if(locktype==EXCLUSIVE_LOCK)
			{
				pFile->locktype=PENDING_LOCK;
				pLock->locktype=PENDING_LOCK;
			}
end_lock:
		WN_SQL3OsLeaveMutex();
		OSTRACE4("LOCK %d %s %s\n",pFile->h,locktypeName(locktype),rc==0 ? "ok" :"failed");
		return rc;
}
int unixUnlock(OsFile *id,int locktype)
{
	struct lockInfo *pLock;
	struct flock lock;
	int rc=0;
	unixFile *pFile=(unixFile*)id;
	OSTRACE7("UNLOCK %d %d was %d(%d,%d)pid=%d\n",pFile->h,locktype,pFile->locktype,pFile->pLock->locktype,pFile->pLock->cnt,getpid());
	if(pFile->locktype<=locktype)return 0;
	if(CHECK_THREADID(pFile))return WN_SQL_MISUSE;
	WN_SQL3OsEnterMutex();
	pLock=pFile->pLock;
	if(pFile->locktype>SHARED_LOCK)
	{
		if(locktype==SHARED_LOCK)
		{
			lock.l_type=F_RDLCK;
			lock.l_whence=SEEK_SET;
			lock.l_start=SHARED_FIRST;
			lock.l_len=SHARED_SIZE;
			if(fcntl(pFile->h,F_SETLK,&lock)==(-1))rc=WN_SQL_IOERR_RDLOCK;
		}
		lock.l_type=F_UNLCK;
		lock.l_whence=SEEK_SET;
		lock.l_start=PENDING_BYTE;
		lock.l_len=2L;
		if(fcntl(pFile->h,F_SETLK,&lock)!=(-1))
			pLock->locktype=SHARED_LOCK;
		else
			rc=WN_SQL_IOERR_UNLOCK;
	}
	if(locktype==NO_LOCK)
	{
		struct openCnt *pOpen;
		pLock->cnt--;
		if(pLock->cnt==0)
		{
			lock.l_type=F_UNLCK;
			lock.l_whence=SEEK_SET;
			lock.l_start=lock.l_len=0L;
			if(fcntl(pFile->h,F_SETLK,&lock)!=(-1))
				pLock->locktype=NO_LOCK;
			else
				rc=WN_SQL_IOERR_UNLOCK;
		}
		pOpen=pFile->pOpen;
		pOpen->nLock--;
		if(pOpen->nLock==0 && pOpen->nPending>0)
		{
			int i;
			for(i=0;i<pOpen->nPending;i++)close(pOpen->aPending[i]);
			free(pOpen->aPending);
			pOpen->nPending=0;
			pOpen->aPending=0;
		}
	}
	WN_SQL3OsLeaveMutex();
	pFile->locktype=locktype;
	return rc;
}
int unixClose(OsFile **pId)
{
	unixFile *id=(unixFile*)*pId;
	if(!id)return 0;
	unixUnlock(*pId,NO_LOCK);
	if(id->dirfd>=0)close(id->dirfd);
	id->dirfd=-1;
	WN_SQL3OsEnterMutex();
	if(id->pOpen->nLock)
	{
		struct openCnt *pOpen=id->pOpen;
		int *aNew=realloc(pOpen->aPending,(pOpen->nPending+1)*sizeof(int));
		if(aNew)
		{
			pOpen->aPending=aNew;
			pOpen->aPending[pOpen->nPending]=id->h;
			pOpen->nPending++;
		}
	}
	else
		close(id->h);
	releaseLockInfo(id->pLock);
	releaseOpenCnt(id->pOpen);
	WN_SQL3OsLeaveMutex();
	id->isOpen=0;
	OSTRACE2("CLOSE %-3d\n",id->h);
	OpenCounter(-1);
	WN_SQL3ThreadSafeFree(id);
	*pId=0;
	return 0;
}
#ifdef WN_SQL_ENABLE_LOCKING_STYLE
#pragma mark AFP Support
typedef struct afpLockingContext afpLockingContext;
struct afpLockingContext
{
	unsigned long long sharedLockByte;
	char *filePath;
};
struct ByteRangeLockPB2
{
	unsigned long long offset,length,retRangeStart;
	unsigned char unLockFlag,startEndFlag;
	int fd;
};
#define afpfsByteRangeLock2FSCTL	_IOWR('z',23,struct ByteRangeLockPB2)
int _AFPFSSetLock(const char *path,int fd,unsigned long long offset,unsigned long long length,int setLockFlag)
{
	struct ByteRangeLockPB2	pb;
	int err;
	pb.unLockFlag=setLockFlag ? 0 :1;
	pb.startEndFlag=0;
	pb.offset=offset;
	pb.length=length;
	pb.fd=fd;
	OSTRACE5("AFPLOCK setting lock %s for %d in range %llx:%llx\n",(setLockFlag?"ON":"OFF"),fd,offset,length);
	err=fsctl(path,afpfsByteRangeLock2FSCTL,&pb,0);
	if(err==-1)
	{
		OSTRACE4("AFPLOCK failed to fsctl()'%s' %d %s\n",path,errno,strerror(errno));
		return 1;
	}
	else
		return 0;
}
int afpUnixCheckReservedLock(OsFile *id)
{
	int r=0;
	unixFile *pFile=(unixFile*)id;
	afpLockingContext *context=(afpLockingContext *)pFile->lockingContext;
	if(pFile->locktype>SHARED_LOCK)r=1;
	if(!r)
	{
		int failed=_AFPFSSetLock(context->filePath,pFile->h,RESERVED_BYTE,1,1);
		if(failed)
			r=1;
		else 
			_AFPFSSetLock(context->filePath,pFile->h,RESERVED_BYTE,1,0);
	}
	OSTRACE3("TEST WR-LOCK %d %d\n",pFile->h,r);
	return r;
}
int afpUnixLock(OsFile *id,int locktype)
{
	int rc=0;
	unixFile *pFile=(unixFile*)id;
	afpLockingContext *context=(afpLockingContext *)pFile->lockingContext;
	int gotPendingLock=0;
	OSTRACE5("LOCK %d %s was %s pid=%d\n",pFile->h,locktypeName(locktype),locktypeName(pFile->locktype),getpid());
	if(pFile->locktype>=locktype)
	{
		OSTRACE3("LOCK %d %s ok(already held)\n",pFile->h,locktypeName(locktype));
		return 0;
	}
	WN_SQL3OsEnterMutex();
	rc=transferOwnership(pFile);
	if(rc)
	{
		WN_SQL3OsLeaveMutex();
		return rc;
	}
	if(locktype==SHARED_LOCK||(locktype==EXCLUSIVE_LOCK && pFile->locktype<PENDING_LOCK))
	{
		int failed=_AFPFSSetLock(context->filePath,pFile->h,PENDING_BYTE,1,1);
		if(failed)
		{
			rc=WN_SQL_BUSY;
			goto afp_end_lock;
		}
	}
	if(locktype==SHARED_LOCK)
	{
		int lk,failed,tries=0;
		lk=random();
		context->sharedLockByte=(lk & 0x7fffffff)%(SHARED_SIZE-1);
		failed=_AFPFSSetLock(context->filePath,pFile->h,SHARED_FIRST+context->sharedLockByte,1,1);
		if(_AFPFSSetLock(context->filePath,pFile->h,PENDING_BYTE,1,0))
		{
			rc=WN_SQL_IOERR_UNLOCK;
			goto afp_end_lock;
		}
		if(failed)
			rc=WN_SQL_BUSY;
		else
			pFile->locktype=SHARED_LOCK;
	}
	else
	{
		int failed=0;
		if(locktype >=RESERVED_LOCK && pFile->locktype<RESERVED_LOCK)failed=_AFPFSSetLock(context->filePath,pFile->h,RESERVED_BYTE,1,1);
		if(!failed && locktype==EXCLUSIVE_LOCK)
		{
			if(!_AFPFSSetLock(context->filePath,pFile->h,SHARED_FIRST+context->sharedLockByte,1,0))
			{
				failed=_AFPFSSetLock(context->filePath,pFile->h,SHARED_FIRST,SHARED_SIZE,1);
				if(failed && _AFPFSSetLock(context->filePath,pFile->h,SHARED_FIRST+context->sharedLockByte,1,1))rc=WN_SQL_IOERR_RDLOCK;
			}
			else
				rc=WN_SQL_IOERR_UNLOCK;
		}
		if(failed && rc==0)rc=WN_SQL_BUSY;
	}
	if(rc==0)
		pFile->locktype=locktype;
	else
		if(locktype==EXCLUSIVE_LOCK)pFile->locktype=PENDING_LOCK;
afp_end_lock:
	WN_SQL3OsLeaveMutex();
	OSTRACE4("LOCK %d %s %s\n",pFile->h,locktypeName(locktype),rc==0 ? "ok" :"failed");
	return rc;
}
int afpUnixUnlock(OsFile *id,int locktype)
{
	struct flock lock;
	int rc=0;
	unixFile *pFile=(unixFile*)id;
	afpLockingContext *context=(afpLockingContext *)pFile->lockingContext;
	OSTRACE5("UNLOCK %d %d was %d pid=%d\n",pFile->h,locktype,pFile->locktype,getpid());
	if(pFile->locktype<=locktype)return 0;
	if(CHECK_THREADID(pFile))return WN_SQL_MISUSE;
	WN_SQL3OsEnterMutex();
	if(pFile->locktype>SHARED_LOCK)
	{
		if(locktype==SHARED_LOCK)
		{
			int failed=0;
			if(pFile->locktype==EXCLUSIVE_LOCK)
			{
				failed=_AFPFSSetLock(context->filePath,pFile->h,SHARED_FIRST,SHARED_SIZE,0);
				if(!failed)
				{
					if(_AFPFSSetLock(context->filePath,pFile->h,SHARED_FIRST+context->sharedLockByte,1,1)) rc=WN_SQL_IOERR_RDLOCK;
				}
				else
					rc=WN_SQL_IOERR_UNLOCK;
			}
		}
		if(rc==0 && pFile->locktype>=PENDING_LOCK)
			if(_AFPFSSetLock(context->filePath,pFile->h,PENDING_BYTE,1,0))rc=WN_SQL_IOERR_UNLOCK;
		if(rc==0 && pFile->locktype>=RESERVED_LOCK)
			if(_AFPFSSetLock(context->filePath,pFile->h,RESERVED_BYTE,1,0))rc=WN_SQL_IOERR_UNLOCK;
	}
	if(locktype==NO_LOCK)
	{
		int failed=_AFPFSSetLock(context->filePath,pFile->h,SHARED_FIRST+context->sharedLockByte,1,0);
		if(failed)rc=WN_SQL_IOERR_UNLOCK;
	}
	if(rc==0)pFile->locktype=locktype;
	WN_SQL3OsLeaveMutex();
	return rc;
}
int afpUnixClose(OsFile **pId)
{
	unixFile *id=(unixFile*)*pId;
	if(!id)return 0;
	afpUnixUnlock(*pId,NO_LOCK);
	if(id->lockingContext!=NULL)
	{
		if(((afpLockingContext *)id->lockingContext)->filePath!=NULL)WN_SQL3ThreadSafeFree(((afpLockingContext*)id->lockingContext)->filePath);
		WN_SQL3ThreadSafeFree(id->lockingContext);
	}
	if(id->dirfd>=0)close(id->dirfd);
	id->dirfd=-1;
	close(id->h);
	id->isOpen=0;
	OSTRACE2("CLOSE %-3d\n",id->h);
	OpenCounter(-1);
	WN_SQL3ThreadSafeFree(id);
	*pId=0;
	return 0;
}
#pragma mark flock()style locking
typedef void flockLockingContext;
int flockUnixCheckReservedLock(OsFile *id)
{
	unixFile *pFile=(unixFile*)id;
	if(pFile->locktype==RESERVED_LOCK)
		return 1;
	else
	{
		int rc=flock(pFile->h,LOCK_EX | LOCK_NB);
		if(!rc)
		{
			flock(pFile->h,LOCK_UN);
			return 0;
		}
		return 1;
	}
}
int flockUnixLock(OsFile *id,int locktype)
{
	unixFile *pFile=(unixFile*)id;
	if(pFile->locktype > NO_LOCK)
	{
		pFile->locktype=locktype;
		return 0;
	}
	int rc=flock(pFile->h,LOCK_EX | LOCK_NB);
	if(rc)
		return WN_SQL_BUSY;
	else
	{
		pFile->locktype=locktype;
		return 0;
	}
}
int flockUnixUnlock(OsFile *id,int locktype)
{
	unixFile *pFile=(unixFile*)id;
	if(pFile->locktype==locktype)return 0;
	if(locktype==SHARED_LOCK)
	{
		pFile->locktype=locktype;
		return 0;
	}
	int rc=flock(pFile->h,LOCK_UN);
	if(rc)
		return WN_SQL_IOERR_UNLOCK;
	else
	{
		pFile->locktype=NO_LOCK;
		return 0;
	}
}
int flockUnixClose(OsFile **pId)
{
	unixFile *id=(unixFile*)*pId;
	if(!id)return 0;
	flockUnixUnlock(*pId,NO_LOCK);
	if(id->dirfd>=0)close(id->dirfd);
	id->dirfd=-1;
	WN_SQL3OsEnterMutex();
	close(id->h);
	WN_SQL3OsLeaveMutex();
	id->isOpen=0;
	OSTRACE2("CLOSE %-3d\n",id->h);
	OpenCounter(-1);
	WN_SQL3ThreadSafeFree(id);
	*pId=0;
	return 0;
}
#pragma mark Old-School .lock file based locking
typedef struct dotlockLockingContext dotlockLockingContext;
struct dotlockLockingContext
{
	char *lockPath;
};
int dotlockUnixCheckReservedLock(OsFile *id)
{
	unixFile *pFile=(unixFile*)id;
	dotlockLockingContext *context=(dotlockLockingContext *)pFile->lockingContext;
	if(pFile->locktype==RESERVED_LOCK)
		return 1;
	else
	{
		struct stat statBuf;
		if(lstat(context->lockPath,&statBuf)==0)
			return 1;
		else
			return 0;
	}
}
int dotlockUnixLock(OsFile *id,int locktype)
{
	unixFile *pFile=(unixFile*)id;
	dotlockLockingContext *context=(dotlockLockingContext *)pFile->lockingContext;
	if(pFile->locktype > NO_LOCK)
	{
		pFile->locktype=locktype;
		utimes(context->lockPath,NULL);
		return 0;
	}
	struct stat statBuf;
	if(lstat(context->lockPath,&statBuf)==0)return WN_SQL_BUSY;
	int fd=open(context->lockPath,O_RDONLY|O_CREAT|O_EXCL,0600);
	if(fd<0)return WN_SQL_BUSY;
	close(fd);
	pFile->locktype=locktype;
	return 0;
}
int dotlockUnixUnlock(OsFile *id,int locktype)
{
	unixFile *pFile=(unixFile*)id;
	dotlockLockingContext *context=(dotlockLockingContext *)pFile->lockingContext;
	if(pFile->locktype==locktype)return 0;
	if(locktype==SHARED_LOCK)
	{
		pFile->locktype=locktype;
		return 0;
	}
	unlink(context->lockPath);
	pFile->locktype=NO_LOCK;
	return 0;
}
int dotlockUnixClose(OsFile **pId)
{
	unixFile *id=(unixFile*)*pId;
	if(!id)return 0;
	dotlockUnixUnlock(*pId,NO_LOCK);
	if(id->lockingContext!=NULL)
	{
		if(((dotlockLockingContext *)id->lockingContext)->lockPath!=NULL)WN_SQL3ThreadSafeFree(((dotlockLockingContext *)
		id->lockingContext)->lockPath);
		WN_SQL3ThreadSafeFree(id->lockingContext);
	}
	if(id->dirfd>=0)close(id->dirfd);
	id->dirfd=-1;
	WN_SQL3OsEnterMutex();
	close(id->h);
	WN_SQL3OsLeaveMutex();
	id->isOpen=0;
	OSTRACE2("CLOSE %-3d\n",id->h);
	OpenCounter(-1);
	WN_SQL3ThreadSafeFree(id);
	*pId=0;
	return 0;
}
#pragma mark No locking
typedef void nolockLockingContext;
int nolockUnixCheckReservedLock(OsFile *id)
{
	return 0;
}
int nolockUnixLock(OsFile *id,int locktype)
{
	return 0;
}
int nolockUnixUnlock(OsFile *id,int locktype)
{
	return 0;
}
int nolockUnixClose(OsFile **pId)
{
	unixFile *id=(unixFile*)*pId;
	if(!id)return 0;
	if(id->dirfd>=0)close(id->dirfd);
	id->dirfd=-1;
	WN_SQL3OsEnterMutex();
	close(id->h);
	WN_SQL3OsLeaveMutex();
	id->isOpen=0;
	OSTRACE2("CLOSE %-3d\n",id->h);
	OpenCounter(-1);
	WN_SQL3ThreadSafeFree(id);
	*pId=0;
	return 0;
}
#endif
	char *WN_SQL3UnixFullPathname(const char *zRelative)
	{
		char *zFull=0;
		if(zRelative[0]=='/')
			WN_SQL3SetString(&zFull,zRelative,(char*)0);
		else
		{
			char *zBuf=WN_SQL3Malloc(5000);
			if(zBuf==0)return 0;
			zBuf[0]=0;
			WN_SQL3SetString(&zFull,getcwd(zBuf,5000),"/",zRelative,(char*)0);
			WN_SQL3FreeX(zBuf);
		}
	return zFull;
}
void unixSetFullSync(OsFile *id,int v)
{
	((unixFile*)id)->fullSync=v;
}
int unixFileHandle(OsFile *id)
{
	return((unixFile*)id)->h;
}
int unixLockState(OsFile *id)
{
	return((unixFile*)id)->locktype;
}
int unixSectorSize(OsFile *id)
{
	return WN_SQL_DEFAULT_SECTOR_SIZE;
}
const IoMethod WN_SQL3UnixIoMethod={unixClose,unixOpenDirectory,unixRead,unixWrite,unixSeek,unixTruncate,unixSync,unixSetFullSync,unixFileHandle,unixFileSize,unixLock,unixUnlock,unixLockState,unixCheckReservedLock,unixSectorSize,};
#ifdef WN_SQL_ENABLE_LOCKING_STYLE
const IoMethod WN_SQL3AFPLockingUnixIoMethod={afpUnixClose,unixOpenDirectory,unixRead,unixWrite,unixSeek,unixTruncate,unixSync,unixSetFullSync,unixFileHandle,unixFileSize,afpUnixLock,afpUnixUnlock,unixLockState,afpUnixCheckReservedLock,unixSectorSize,};
const IoMethod WN_SQL3FlockLockingUnixIoMethod={flockUnixClose,unixOpenDirectory,unixRead,unixWrite,unixSeek,unixTruncate,unixSync,unixSetFullSync,unixFileHandle,unixFileSize,flockUnixLock,flockUnixUnlock,unixLockState,flockUnixCheckReservedLock,unixSectorSize,};
const IoMethod WN_SQL3DotlockLockingUnixIoMethod={dotlockUnixClose,unixOpenDirectory,unixRead,unixWrite,unixSeek,unixTruncate,unixSync,unixSetFullSync,unixFileHandle,unixFileSize,dotlockUnixLock,dotlockUnixUnlock,unixLockState,dotlockUnixCheckReservedLock,unixSectorSize,};
const IoMethod WN_SQL3NolockLockingUnixIoMethod={
nolockUnixClose,unixOpenDirectory,unixRead,unixWrite,unixSeek,unixTruncate,unixSync,unixSetFullSync,unixFileHandle,unixFileSize,nolockUnixLock,nolockUnixUnlock,unixLockState,nolockUnixCheckReservedLock,unixSectorSize,};
#endif
#ifdef WN_SQL_ENABLE_LOCKING_STYLE
int allocateUnixFile(int h,OsFile **pId,const char *zFilename,int delFlag)
{
	WN_SQL3LockingStyle lockingStyle;
	unixFile *pNew,f;
	int rc;
	memset(&f,0,sizeof(f));
	lockingStyle=WN_SQL3DetectLockingStyle(zFilename,h);
	if(lockingStyle==posixLockingStyle)
	{
		WN_SQL3OsEnterMutex();
		rc=findLockInfo(h,&f.pLock,&f.pOpen);
		WN_SQL3OsLeaveMutex();
		if(rc)
		{
			close(h);
			unlink(zFilename);
			return WN_SQL_NOMEM;
		}
	}
	else
	{
		f.pLock=NULL;
		f.pOpen=NULL;
	}
	if(delFlag)unlink(zFilename);
	f.dirfd=-1;
	f.h=h;
	SET_THREADID(&f);
	pNew=WN_SQL3ThreadSafeMalloc(sizeof(unixFile));
	if(pNew==0)
	{
		close(h);
		WN_SQL3OsEnterMutex();
		releaseLockInfo(f.pLock);
		releaseOpenCnt(f.pOpen);
		WN_SQL3OsLeaveMutex();
		*pId=0;
		return WN_SQL_NOMEM;
	}
	else
	{
		*pNew=f;
		switch(lockingStyle)
		{
		case afpLockingStyle:
			pNew->pMethod=&WN_SQL3AFPLockingUnixIoMethod;
			pNew->lockingContext=WN_SQL3ThreadSafeMalloc(sizeof(afpLockingContext));
			int nFilename=strlen(zFilename)+1;
			((afpLockingContext *)pNew->lockingContext)->filePath=WN_SQL3ThreadSafeMalloc(nFilename);
			memcpy(((afpLockingContext *)pNew->lockingContext)->filePath,zFilename,nFilename);
			srandomdev();
			break;
		case flockLockingStyle:
			pNew->pMethod=&WN_SQL3FlockLockingUnixIoMethod;
			break;
		case dotlockLockingStyle:
			pNew->pMethod=&WN_SQL3DotlockLockingUnixIoMethod;
			pNew->lockingContext=WN_SQL3ThreadSafeMalloc(sizeof(dotlockLockingContext));
			int nFilename=strlen(zFilename)+6;
			((dotlockLockingContext *)pNew->lockingContext)->lockPath=WN_SQL3ThreadSafeMalloc(nFilename);
			WN_SQL3_snprintf(nFilename,((dotlockLockingContext *)pNew->lockingContext)->lockPath,"%s.lock",zFilename);
			break;
		case posixLockingStyle:
			pNew->pMethod=&WN_SQL3UnixIoMethod;
			break;
		case noLockingStyle:
		case unsupportedLockingStyle:
		default:
			pNew->pMethod=&WN_SQL3NolockLockingUnixIoMethod;
		}
		*pId=(OsFile*)pNew;
		OpenCounter(+1);
		return 0;
	}
}
#else
int allocateUnixFile(int h,OsFile **pId,const char *zFilename,int delFlag)
{
	unixFile *pNew,f;
#ifdef FD_CLOEXEC
	fcntl(h,F_SETFD,fcntl(h,F_GETFD,0)| FD_CLOEXEC);
#endif
	memset(&f,0,sizeof(f));
	WN_SQL3OsEnterMutex();
	int rc=findLockInfo(h,&f.pLock,&f.pOpen);
	WN_SQL3OsLeaveMutex();
	if(delFlag)unlink(zFilename);
	if(rc)
	{
		close(h);
		return WN_SQL_NOMEM;
	}
	OSTRACE3("OPEN %-3d %s\n",h,zFilename);
	f.dirfd=-1;
	f.h=h;
	SET_THREADID(&f);
	pNew=WN_SQL3ThreadSafeMalloc(sizeof(unixFile));
	if(pNew==0)
	{
		close(h);
		WN_SQL3OsEnterMutex();
		releaseLockInfo(f.pLock);
		releaseOpenCnt(f.pOpen);
		WN_SQL3OsLeaveMutex();
		*pId=0;
		return WN_SQL_NOMEM;
	}
	else
	{
		*pNew=f;
		pNew->pMethod=&WN_SQL3UnixIoMethod;
		*pId=(OsFile*)pNew;
		OpenCounter(+1);
		return 0;
	}
}
#endif
#endif
#ifndef WN_SQL_OMIT_LOAD_EXTENSION
#include<dlfcn.h>
void *WN_SQL3UnixDlopen(const char *zFilename)
{
	return dlopen(zFilename,RTLD_NOW | RTLD_GLOBAL);
}
void *WN_SQL3UnixDlsym(void *pHandle,const char *zSymbol)
{
	return dlsym(pHandle,zSymbol);
}
int WN_SQL3UnixDlclose(void *pHandle)
{
	return dlclose(pHandle);
}
#endif
int WN_SQL3UnixRandomSeed(char *zBuf)
{
	memset(zBuf,0,256);
#if !defined(WN_SQL_TEST)
	int pid,fd=open("/dev/urandom",O_RDONLY);
	if(fd<0)
	{
		time_t t;
		time(&t);
		memcpy(zBuf,&t,sizeof(t));
		pid=getpid();
		memcpy(&zBuf[sizeof(time_t)],&pid,sizeof(pid));
	}
	else
	{
		read(fd,zBuf,256);
		close(fd);
	}
#endif
	return 0;
}
int WN_SQL3UnixSleep(int ms)
{
#if defined(HAVE_USLEEP)&& HAVE_USLEEP
	usleep(ms*1000);
	return ms;
#else
	sleep((ms+999)/1000);
	return 1000*((ms+999)/1000);
#endif
}
	int inMutex=0;
#ifdef WN_SQL_UNIX_THREADS
	pthread_t mutexOwner;
	int mutexOwnerValid=0;
	pthread_mutex_t mutexMain=PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_t mutexAux=PTHREAD_MUTEX_INITIALIZER;
#endif
void WN_SQL3UnixEnterMutex()
{
#ifdef WN_SQL_UNIX_THREADS
	pthread_mutex_lock(&mutexAux);
	if(!mutexOwnerValid || !pthread_equal(mutexOwner,pthread_self()))
	{
		pthread_mutex_unlock(&mutexAux);
		pthread_mutex_lock(&mutexMain);
		pthread_mutex_lock(&mutexAux);
		mutexOwner=pthread_self();
		mutexOwnerValid=1;
	}
	inMutex++;
	pthread_mutex_unlock(&mutexAux);
#else
	inMutex++;
#endif
}
void WN_SQL3UnixLeaveMutex()
{
#ifdef WN_SQL_UNIX_THREADS
	pthread_mutex_lock(&mutexAux);
	inMutex--;
	if(inMutex==0)
	{
		mutexOwnerValid=0;
		pthread_mutex_unlock(&mutexMain);
	}
	pthread_mutex_unlock(&mutexAux);
#else
	inMutex--;
#endif
}
int WN_SQL3UnixInMutex(int thisThrd)
{
#ifdef WN_SQL_UNIX_THREADS
	int rc;
	pthread_mutex_lock(&mutexAux);
	rc=inMutex>0 &&(thisThrd==0 || pthread_equal(mutexOwner,pthread_self()));
	pthread_mutex_unlock(&mutexAux);
	return rc;
#else
	return inMutex>0;
#endif
}
#ifdef WN_SQL_TEST
	int WN_SQL3_tsd_count=0;
# ifdef WN_SQL_UNIX_THREADS
	pthread_mutex_t tsd_counter_mutex=PTHREAD_MUTEX_INITIALIZER;
# define TSD_COUNTER(N) \
pthread_mutex_lock(&tsd_counter_mutex);\
WN_SQL3_tsd_count+=N;\
pthread_mutex_unlock(&tsd_counter_mutex);
# else
# define TSD_COUNTER(N)WN_SQL3_tsd_count+=N
# endif
#else
# define TSD_COUNTER(N)
#endif
	ThreadData *WN_SQL3UnixThreadSpecificData(int allocateFlag)
	{
		const ThreadData zeroData={0};
#ifdef WN_SQL_UNIX_THREADS
		pthread_key_t key;
		int keyInit=0;
		ThreadData *pTsd;
		if(!keyInit)
		{
			WN_SQL3OsEnterMutex();
			if(!keyInit)
			{
				int rc=pthread_key_create(&key,0);
				if(rc)
				{
					WN_SQL3OsLeaveMutex();
					return 0;
				}
				keyInit=1;
			}
			WN_SQL3OsLeaveMutex();
		}
		pTsd=pthread_getspecific(key);
		if(allocateFlag>0)
		{
			if(pTsd==0)
			{
				if(!WN_SQL3TestMallocFail())pTsd=WN_SQL3OsMalloc(sizeof(zeroData));
#ifdef WN_SQL_MEMDEBUG
				WN_SQL3_isFail=0;
#endif
				if(pTsd)
				{
					*pTsd=zeroData;
					pthread_setspecific(key,pTsd);
					TSD_COUNTER(+1);
				}
			}
		}
		else
			if(pTsd && allocateFlag<0&& memcmp(pTsd,&zeroData,sizeof(ThreadData))==0)
			{
				WN_SQL3OsFree(pTsd);
				pthread_setspecific(key,0);
				TSD_COUNTER(-1);
				pTsd=0;
			}
			return pTsd;
#else
			ThreadData *pTsd=0;
			if(allocateFlag>0)
			{
				if(pTsd==0)
				{
					if(!WN_SQL3TestMallocFail())pTsd=WN_SQL3OsMalloc(sizeof(zeroData));
#ifdef WN_SQL_MEMDEBUG
					WN_SQL3_isFail=0;
#endif
					if(pTsd)
					{
						*pTsd=zeroData;
						TSD_COUNTER(+1);
					}
				}
			}
			else
				if(pTsd && allocateFlag<0&& memcmp(pTsd,&zeroData,sizeof(ThreadData))==0)
				{
					WN_SQL3OsFree(pTsd);
					TSD_COUNTER(-1);
					pTsd=0;
				}
	return pTsd;
#endif
}
#ifdef WN_SQL_TEST
int WN_SQL3_current_time=0;
#endif
int WN_SQL3UnixCurrentTime(double *prNow)
{
#ifdef NO_GETTOD
	time_t t;
	time(&t);
	*prNow=t/86400.0+2440587.5;
#else
	struct timeval sNow;
	gettimeofday(&sNow,0);
	*prNow=2440587.5+sNow.tv_sec/86400.0+sNow.tv_usec/86400000000.0;
#endif
#ifdef WN_SQL_TEST
	if(WN_SQL3_current_time)*prNow=WN_SQL3_current_time/86400.0+2440587.5;
#endif
	return 0;
}
#endif
#if OS_WIN
#include<winbase.h>
#ifdef __CYGWIN__
# include<sys/cygwin.h>
#endif
#if defined(THREADSAFE)&& THREADSAFE
# define WN_SQL_W32_THREADS 1
#endif
#ifdef WN_SQL_TEST
u32 WN_SQL3_pending_byte=0x40000000;
#endif
int WN_SQL3_os_trace=0;
#ifdef WN_SQL_DEBUG
#define OSTRACE1(X) if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X)
#define OSTRACE2(X,Y) if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y)
#define OSTRACE3(X,Y,Z) if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z)
#define OSTRACE4(X,Y,Z,A) if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A)
#define OSTRACE5(X,Y,Z,A,B) if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B)
#define OSTRACE6(X,Y,Z,A,B,C) \
if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B,C)
#define OSTRACE7(X,Y,Z,A,B,C,D) \
if(WN_SQL3_os_trace)WN_SQL3DebugPrintf(X,Y,Z,A,B,C,D)
#else
#define OSTRACE1(X)
#define OSTRACE2(X,Y)
#define OSTRACE3(X,Y,Z)
#define OSTRACE4(X,Y,Z,A)
#define OSTRACE5(X,Y,Z,A,B)
#define OSTRACE6(X,Y,Z,A,B,C)
#define OSTRACE7(X,Y,Z,A,B,C,D)
#endif
#ifdef WN_SQL_PERFORMANCE_TRACE
__inline__ unsigned long long int hwtime(void){
unsigned long long int x;
__asm__("rdtsc\n\t"
"mov %%edx,%%ecx\n\t"
:"=A"(x));
return x;
}
unsigned long long int g_start;
u32 elapse;
#define TIMER_START g_start=hwtime()
#define TIMER_END elapse=hwtime()-g_start
#define TIMER_ELAPSED elapse
#else
#define TIMER_START
#define TIMER_END
#define TIMER_ELAPSED 0
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_io_error_hit=0;
int WN_SQL3_io_error_pending=0;
int WN_SQL3_io_error_persist=0;
int WN_SQL3_diskfull_pending=0;
int WN_SQL3_diskfull=0;
#define SimulateIOError(CODE) if(WN_SQL3_io_error_pending || WN_SQL3_io_error_hit)if(WN_SQL3_io_error_pending--==1 ||(WN_SQL3_io_error_persist && WN_SQL3_io_error_hit)){local_ioerr();CODE;}
void local_ioerr()
{	IOTRACE(("IOERR\n"));
	WN_SQL3_io_error_hit=1;
}
#define SimulateDiskfullError(CODE) \
if(WN_SQL3_diskfull_pending){\
if(WN_SQL3_diskfull_pending==1){\
local_ioerr();\
WN_SQL3_diskfull=1;\
WN_SQL3_io_error_hit=1;\
CODE;\
}else{\
WN_SQL3_diskfull_pending--;\
}\
}
#else
#define SimulateIOError(A)
#define SimulateDiskfullError(A)
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_open_file_count=0;
#define OpenCounter(X)WN_SQL3_open_file_count+=(X)
#else
#define OpenCounter(X)
#endif
#if defined(WN_SQL_ENABLE_MEMORY_MANAGEMENT)|| defined(WN_SQL_MEMDEBUG)
void *WN_SQL3GenericMalloc(int n)
{
	char *p=(char *)malloc(n+8);
	if(p)
	{
		*(int *)p=n;
		p+=8;
	}
	return(void *)p;
}
void *WN_SQL3GenericRealloc(void *p,int n)
{
	char *p2=((char *)p-8);
	p2=(char*)realloc(p2,n+8);
	if(p2)
	{
		*(int *)p2=n;
		p2+=8;
	}
	return(void *)p2;
}
void WN_SQL3GenericFree(void *p)
{
	free((void *)((char *)p-8));
}
int WN_SQL3GenericAllocationSize(void *p)
{
	return p ? *(int *)((char *)p-8):0;
}
#else
void *WN_SQL3GenericMalloc(int n)
{
	char *p=new char[n];
	return(void *)p;
}
void *WN_SQL3GenericRealloc(void *p,int n){
	p=realloc(p,n);
	return p;
}
void WN_SQL3GenericFree(void *p)
{
	delete[] p;
}
int WN_SQL3GenericAllocationSize(void *p)
{
	return 0;
}
#endif
# define PAGER_SECTOR_SIZE 512
#if defined(_WIN32_WCE)
# define OS_WINCE 1
# define AreFileApisANSI()1
#else
# define OS_WINCE 0
#endif
#if OS_WINCE
typedef struct winceLock
{
	int nReaders;
	BOOL bPending,bReserved,bExclusive;
}winceLock;
#endif
typedef struct winFile winFile;
struct winFile
{
	IoMethod const *pMethod;
	HANDLE h;
	unsigned char locktype;
	short sharedLockByte;
#if OS_WINCE
	WCHAR *zDeleteOnClose;
	HANDLE hMutex;
HANDLE hShared;
winceLock local;
winceLock *shared;
#endif
};
#ifndef WN_SQL_OMIT_DISKIO
	int WN_SQL3_os_type=0;
#if OS_WINCE
# define isNT()(1)
#else
int isNT(void)
{
	if(WN_SQL3_os_type==0)
	{
		OSVERSIONINFO sInfo;
		sInfo.dwOSVersionInfoSize=sizeof(sInfo);
		GetVersionEx(&sInfo);
		WN_SQL3_os_type=sInfo.dwPlatformId==VER_PLATFORM_WIN32_NT ? 2 :1;
	}
	return WN_SQL3_os_type==2;
}
#endif
WCHAR *utf8ToUnicode(const char *zFilename)
{
	int nChar=MultiByteToWideChar(CP_UTF8,0,zFilename,-1,NULL,0);
	WCHAR *zWideFilename=WN_SQL3Malloc(nChar*sizeof(zWideFilename[0]));
	if(zWideFilename==0)return 0;
	nChar=MultiByteToWideChar(CP_UTF8,0,zFilename,-1,zWideFilename,nChar);
	if(nChar==0)
	{
		WN_SQL3FreeX(zWideFilename);
		zWideFilename=0;
	}
	return zWideFilename;
}
char *unicodeToUtf8(const WCHAR *zWideFilename)
{
	int nByte=WideCharToMultiByte(CP_UTF8,0,zWideFilename,-1,0,0,0,0);
	char *zFilename=WN_SQL3Malloc(nByte);
	if(zFilename==0)return 0;
	nByte=WideCharToMultiByte(CP_UTF8,0,zWideFilename,-1,zFilename,nByte,0,0);
	if(nByte==0)
	{
		WN_SQL3FreeX(zFilename);
		zFilename=0;
	}
	return zFilename;
}
WCHAR *mbcsToUnicode(const char *zFilename)
{
	int codepage=AreFileApisANSI()? CP_ACP :CP_OEMCP,nByte=MultiByteToWideChar(codepage,0,zFilename,-1,NULL,0)*sizeof(WCHAR);
	WCHAR *zMbcsFilename=WN_SQL3Malloc(nByte*sizeof(zMbcsFilename[0]));
	if(zMbcsFilename==0)return 0;
	nByte=MultiByteToWideChar(codepage,0,zFilename,-1,zMbcsFilename,nByte);
	if(nByte==0)
	{
		WN_SQL3FreeX(zMbcsFilename);
		zMbcsFilename=0;
	}
	return zMbcsFilename;
}
char *unicodeToMbcs(const WCHAR *zWideFilename)
{
	int codepage=AreFileApisANSI()? CP_ACP :CP_OEMCP,nByte=WideCharToMultiByte(codepage,0,zWideFilename,-1,0,0,0,0);
	char *zFilename=WN_SQL3Malloc(nByte);
	if(zFilename==0)return 0;
	nByte=WideCharToMultiByte(codepage,0,zWideFilename,-1,zFilename,nByte,0,0);
	if(nByte==0)
	{
		WN_SQL3FreeX(zFilename);
		zFilename=0;
	}
	return zFilename;
}
char *mbcsToUtf8(const char *zFilename)
{
	WCHAR *zTmpWide=mbcsToUnicode(zFilename);
	if(zTmpWide==0)return 0;
	char *zFilenameUtf8=unicodeToUtf8(zTmpWide);
	WN_SQL3FreeX(zTmpWide);
	return zFilenameUtf8;
}
char *utf8ToMbcs(const char *zFilename)
{
	WCHAR *zTmpWide=utf8ToUnicode(zFilename);
	if(zTmpWide==0)return 0;
	char *zFilenameMbcs=unicodeToMbcs(zTmpWide);
	WN_SQL3FreeX(zTmpWide);
	return zFilenameMbcs;
}
#if OS_WINCE
struct tm *__cdecl localtime(const time_t *t)
{
	struct tm y;
	FILETIME uTm,lTm;
	SYSTEMTIME pTm;
	i64 t64=*t;
	t64=(t64+11644473600)*10000000;
	uTm.dwLowDateTime=t64 & 0xFFFFFFFF;
	uTm.dwHighDateTime=t64 >> 32;
	FileTimeToLocalFileTime(&uTm,&lTm);
	FileTimeToSystemTime(&lTm,&pTm);
	y.tm_year=pTm.wYear-1900;
	y.tm_mon=pTm.wMonth-1;
	y.tm_wday=pTm.wDayOfWeek;
	y.tm_mday=pTm.wDay;
	y.tm_hour=pTm.wHour;
	y.tm_min=pTm.wMinute;
	y.tm_sec=pTm.wSecond;
	return &y;
}
#define GetTempPathA(a,b)
#define LockFile(a,b,c,d,e)winceLockFile(&a,b,c,d,e)
#define UnlockFile(a,b,c,d,e)winceUnlockFile(&a,b,c,d,e)
#define LockFileEx(a,b,c,d,e,f)winceLockFileEx(&a,b,c,d,e,f)
#define HANDLE_TO_WINFILE(a)(winFile*)&((char*)a)[-offsetof(winFile,h)]
void winceMutexAcquire(HANDLE h)
{
	DWORD dwErr;
	do
	{
		dwErr=WaitForSingleObject(h,INFINITE);
	}while(dwErr!=WAIT_OBJECT_0 && dwErr!=WAIT_ABANDONED);
}
#define winceMutexRelease(h)ReleaseMutex(h)
BOOL winceCreateLock(const char *zFilename,winFile *pFile)
{
	WCHAR *zName=utf8ToUnicode(zFilename),*zTok=CharLowerW(zName);
	BOOL bInit=TRUE;
	ZeroMemory(&pFile->local,sizeof(pFile->local));
	for(;*zTok;zTok++)if(*zTok=='\\')*zTok='_';
	pFile->hMutex=CreateMutexW(NULL,FALSE,zName);
	if(!pFile->hMutex)
	{
		WN_SQL3FreeX(zName);
		return FALSE;
	}
	winceMutexAcquire(pFile->hMutex);
	CharUpperW(zName);
	pFile->hShared=CreateFileMappingW(INVALID_HANDLE_VALUE,NULL,PAGE_READWRITE,0,sizeof(winceLock),zName);
	if(GetLastError()==ERROR_ALREADY_EXISTS)bInit=FALSE;
	WN_SQL3FreeX(zName);
	if(pFile->hShared)
	{
		pFile->shared=(winceLock*)MapViewOfFile(pFile->hShared,FILE_MAP_READ|FILE_MAP_WRITE,0,0,sizeof(winceLock));
		if(!pFile->shared)
		{
			CloseHandle(pFile->hShared);
			pFile->hShared=NULL;
		}
	}
	if(pFile->hShared==NULL)
	{
		winceMutexRelease(pFile->hMutex);
		CloseHandle(pFile->hMutex);
		pFile->hMutex=NULL;
		return FALSE;
	}
	if(bInit)ZeroMemory(pFile->shared,sizeof(winceLock));
	winceMutexRelease(pFile->hMutex);
	return TRUE;
}
void winceDestroyLock(winFile *pFile)
{
	if(pFile->hMutex)
	{
		winceMutexAcquire(pFile->hMutex);
		if(pFile->local.nReaders)pFile->shared->nReaders--;
		if(pFile->local.bReserved)pFile->shared->bReserved=FALSE;
		if(pFile->local.bPending)pFile->shared->bPending=FALSE;
		if(pFile->local.bExclusive)pFile->shared->bExclusive=FALSE;
		UnmapViewOfFile(pFile->shared);
		CloseHandle(pFile->hShared);
		if(pFile->zDeleteOnClose)
		{
			DeleteFileW(pFile->zDeleteOnClose);
			WN_SQL3FreeX(pFile->zDeleteOnClose);
			pFile->zDeleteOnClose=0;
		}
		winceMutexRelease(pFile->hMutex);
		CloseHandle(pFile->hMutex);
		pFile->hMutex=NULL;
	}
}
BOOL winceLockFile(HANDLE *phFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh)
{
	winFile *pFile=HANDLE_TO_WINFILE(phFile);
	BOOL bReturn=FALSE;
	if(!pFile->hMutex)return TRUE;
	winceMutexAcquire(pFile->hMutex);
	if(dwFileOffsetLow==SHARED_FIRST && nNumberOfBytesToLockLow==SHARED_SIZE)
	{
		if(pFile->shared->nReaders==0 && pFile->shared->bExclusive==0)
		{
			pFile->shared->bExclusive=TRUE;
			pFile->local.bExclusive=TRUE;
			bReturn=TRUE;
		}
	}
	else
		if((dwFileOffsetLow >=SHARED_FIRST && dwFileOffsetLow<SHARED_FIRST+SHARED_SIZE)&& nNumberOfBytesToLockLow==1)
		{
			if(pFile->shared->bExclusive==0)
			{
				pFile->local.nReaders++;
				if(pFile->local.nReaders==1)pFile->shared->nReaders++;
				bReturn=TRUE;
			}
		}
		else
			if(dwFileOffsetLow==PENDING_BYTE && nNumberOfBytesToLockLow==1)
			{
				if(pFile->shared->bPending==0)
				{
					pFile->shared->bPending=TRUE;
					pFile->local.bPending=TRUE;
					bReturn=TRUE;
				}
			}
			else
				if(dwFileOffsetLow==RESERVED_BYTE && nNumberOfBytesToLockLow==1)
				{
					if(pFile->shared->bReserved==0)
					{
						pFile->shared->bReserved=TRUE;
						pFile->local.bReserved=TRUE;
						bReturn=TRUE;
					}
				}
				winceMutexRelease(pFile->hMutex);
				return bReturn;
}
BOOL winceUnlockFile(HANDLE *phFile,DWORD dwFileOffsetLow,DWORD dwFileOffsetHigh,DWORD nNumberOfBytesToUnlockLow,DWORD nNumberOfBytesToUnlockHigh)
{
	winFile *pFile=HANDLE_TO_WINFILE(phFile);
	BOOL bReturn=FALSE;
	if(!pFile->hMutex)return TRUE;
	winceMutexAcquire(pFile->hMutex);
	if(dwFileOffsetLow >=SHARED_FIRST && dwFileOffsetLow<SHARED_FIRST+SHARED_SIZE)
	{
		if(pFile->local.bExclusive)
		{
			pFile->local.bExclusive=FALSE;
			pFile->shared->bExclusive=FALSE;
			bReturn=TRUE;
		}
		else
			if(pFile->local.nReaders)
			{
				pFile->local.nReaders--;
				if(pFile->local.nReaders==0)pFile->shared->nReaders--;
				bReturn=TRUE;
			}
	}
	else
		if(dwFileOffsetLow==PENDING_BYTE && nNumberOfBytesToUnlockLow==1)
		{
			if(pFile->local.bPending)
			{
				pFile->local.bPending=FALSE;
				pFile->shared->bPending=FALSE;
				bReturn=TRUE;
			}
		}
		else
			if(dwFileOffsetLow==RESERVED_BYTE && nNumberOfBytesToUnlockLow==1)
			{
				if(pFile->local.bReserved)
				{
					pFile->local.bReserved=FALSE;
					pFile->shared->bReserved=FALSE;
					bReturn=TRUE;
				}
			}
			winceMutexRelease(pFile->hMutex);
			return bReturn;
}
BOOL winceLockFileEx(HANDLE *phFile,DWORD dwFlags,DWORD dwReserved,DWORD nNumberOfBytesToLockLow,DWORD nNumberOfBytesToLockHigh,LPOVERLAPPED lpOverlapped)
{
	if(lpOverlapped->Offset==SHARED_FIRST && dwFlags==1 && nNumberOfBytesToLockLow==SHARED_SIZE)return winceLockFile(phFile,SHARED_FIRST,0,1,0);
	return FALSE;
}
#endif
void *convertUtf8Filename(const char *zFilename)
{
	if(isNT())
		return utf8ToUnicode(zFilename);
	else
		return utf8ToMbcs(zFilename);
}
#define MX_DELETION_ATTEMPTS 3
int WN_SQL3WinDelete(const char *zFilename)
{
	int cnt=0,rc;
	void *zConverted=convertUtf8Filename(zFilename);
	if(zConverted==0)return WN_SQL_NOMEM;
	SimulateIOError(return WN_SQL_IOERR_DELETE);
	if(isNT())
		do
		{
			rc=DeleteFileW(zConverted);
		}while(rc==0 && GetFileAttributesW(zConverted)!=0xffffffff && cnt++<MX_DELETION_ATTEMPTS &&(Sleep(100),1));
	else
#if OS_WINCE
return WN_SQL_NOMEM;
#else
		do
		{
			rc=DeleteFileA(zConverted);
		}while(rc==0 && GetFileAttributesA(zConverted)!=0xffffffff && cnt++<MX_DELETION_ATTEMPTS &&(Sleep(100),1));
#endif
	WN_SQL3FreeX(zConverted);
	OSTRACE2("DELETE \"%s\"\n",zFilename);
	return rc ? 0 :WN_SQL_IOERR;
}
int WN_SQL3WinFileExists(const char *zFilename)
{
	int exists=0;
	void *zConverted=convertUtf8Filename(zFilename);
	if(zConverted==0)return WN_SQL_NOMEM;
	if(isNT())
		exists=GetFileAttributesW((WCHAR*)zConverted)!=0xffffffff;
	else
#if OS_WINCE
		return WN_SQL_NOMEM;
#else
		exists=GetFileAttributesA((char*)zConverted)!=0xffffffff;
#endif
	WN_SQL3FreeX(zConverted);
	return exists;
}
int allocateWinFile(winFile *pInit,OsFile **pId);
int WN_SQL3WinOpenReadWrite(const char *zFilename,OsFile **pId,int *pReadonly)
{
	winFile f;
	void *zConverted=convertUtf8Filename(zFilename);
	if(zConverted==0)return WN_SQL_NOMEM;
	HANDLE h;
	if(isNT())
	{
		h=CreateFileW((WCHAR*)zConverted,GENERIC_READ | GENERIC_WRITE,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS,NULL);
		if(h==INVALID_HANDLE_VALUE)
		{
			h=CreateFileW((WCHAR*)zConverted,GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS,NULL);
			if(h==INVALID_HANDLE_VALUE)
			{
				WN_SQL3FreeX(zConverted);
				return WN_SQL_CANTOPEN;
			}
			*pReadonly=1;
		}
		else
			*pReadonly=0;
#if OS_WINCE
		if(!winceCreateLock(zFilename,&f))
		{
			CloseHandle(h);
			WN_SQL3FreeX(zConverted);
			return WN_SQL_CANTOPEN;
		}
#endif
	}
	else
	{
#if OS_WINCE
return WN_SQL_NOMEM;
#else
		h=CreateFileA((char*)zConverted,GENERIC_READ | GENERIC_WRITE,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS,NULL);
		if(h==INVALID_HANDLE_VALUE)
		{
			h=CreateFileA((char*)zConverted,GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_ALWAYS,FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS,NULL );
			if(h==INVALID_HANDLE_VALUE)
			{
				WN_SQL3FreeX(zConverted);
				return WN_SQL_CANTOPEN;
			}
			*pReadonly=1;
		}
		else
			*pReadonly=0;
#endif
	}
	WN_SQL3FreeX(zConverted);
	f.h=h;
#if OS_WINCE
	f.zDeleteOnClose=0;
#endif
	OSTRACE3("OPEN R/W %d \"%s\"\n",h,zFilename);
	return allocateWinFile(&f,pId);
}
int WN_SQL3WinOpenExclusive(const char *zFilename,OsFile **pId,int delFlag)
{	winFile f;
	HANDLE h;
	void *zConverted=convertUtf8Filename(zFilename);
	if(zConverted==0)return WN_SQL_NOMEM;
	DWORD fileflags=FILE_FLAG_RANDOM_ACCESS;
	u8 inStmt;
};
#ifdef WN_SQL_HAS_CODEC
# define CODEC1(P,D,N,X)if(P->xCodec){P->xCodec(P->pCodecArg,D,N,X);}
# define CODEC2(P,D,N,X)((char*)(P->xCodec?P->xCodec(P->pCodecArg,D,N,X):D))
#else
# define CODEC1(P,D,N,X)
# define CODEC2(P,D,N,X)((char*)D)
#endif
#define PGHDR_TO_DATA(P)((void*)(&(P)[1]))
#define DATA_TO_PGHDR(D)(&((PgHdr*)(D))[-1])
#define PGHDR_TO_EXTRA(G,P)((void*)&((char*)(&(G)[1]))[(P)->pageSize])
#define PGHDR_TO_HIST(P,PGR) \
((PgHistory*)&((char*)(&(P)[1]))[(PGR)->pageSize+(PGR)->nExtra])
struct Pager
{
	u8 journalOpen,journalStarted,useJournal,noReadlock,stmtOpen,stmtInUse,
		stmtAutoopen,noSync,fullSync,full_fsync,state,tempFile,readOnly,needSync,
		dirtyCache,alwaysRollback,memDb,setMaster,doNotSync,exclusiveMode,
		changeCountDone,*aInJournal,*aInStmt;
	int errCode,dbSize,origDbSize,stmtSize,nRec,stmtNRec,nExtra,pageSize,nPage,		nRef,mxPage;
	u32 cksumInit;
	Pgno mxPgno;
	char *zFilename,*zJournal,*zDirectory;
	OsFile *fd,*jfd,*stfd;
	BusyHandler *pBusyHandler;
	PgHdr *pFirst,*pLast,*pFirstSynced,*pAll,*pStmt,*pDirty;
	i64 journalOff,journalHdr,stmtHdrOff,stmtCksum,stmtJSize;
	int sectorSize;
#ifdef WN_SQL_TEST
	int nHit,nMiss,nRead,nWrite;
#endif
	void(*xDestructor)(DbPage*,int);
	void(*xReiniter)(DbPage*,int);
#ifdef WN_SQL_HAS_CODEC
	void *(*xCodec)(void*,void*,Pgno,int);
	void *pCodecArg;
#endif
	int nHash;
	PgHdr **aHash;
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
	Pager *pNext;
#endif
	char *pTmpSpace,dbFileVers[16];
};
#ifdef WN_SQL_TEST
int WN_SQL3_pager_readdb_count=0;
int WN_SQL3_pager_writedb_count=0;
int WN_SQL3_pager_writej_count=0;
int WN_SQL3_pager_pgfree_count=0;
# define PAGER_INCR(v)v++
#else
# define PAGER_INCR(v)
#endif
const unsigned char aJournalMagic[]={
0xd9,0xd5,0x05,0xf9,0x20,0xa1,0x63,0xd7,};
#define JOURNAL_PG_SZ(pPager)((pPager->pageSize)+8)
#define JOURNAL_HDR_SZ(pPager)(pPager->sectorSize)
#ifdef WN_SQL_OMIT_MEMORYDB
# define MEMDB 0
#else
# define MEMDB pPager->memDb
#endif
#define PAGER_MJ_PGNO(x) ((PENDING_BYTE/((x)->pageSize))+1)
#define PAGER_MAX_PGNO 2147483647
#ifdef WN_SQL_DEBUG
int pager3_refinfo_enable=0;
void pager_refinfo(PgHdr *p)
{
	if(!pager3_refinfo_enable)return;
	int cnt=0;
	WN_SQL3DebugPrintf("REFCNT:%4d addr=%p nRef=%-3d total=%d\n",p->pgno,PGHDR_TO_DATA(p),p->nRef,p->pPager->nRef);
	cnt++;
}
# define REFINFO(X)pager_refinfo(X)
#else
# define REFINFO(X)
#endif
int pageInStatement(PgHdr *pPg)
{
	Pager *pPager=pPg->pPager;
	if(MEMDB)
		return PGHDR_TO_HIST(pPg,pPager)->inStmt;
	else
	{
		Pgno pgno=pPg->pgno;
		u8 *a=pPager->aInStmt;
		return(a &&(int)pgno<=pPager->stmtSize &&(a[pgno/8] &(1<<(pgno&7))));
	}
}
void pager_resize_hash_table(Pager *pPager,int N)
{
	PgHdr **aHash,*pPg;
	aHash=WN_SQL3Malloc(sizeof(aHash[0])*N);
	if(aHash==0)return;
	WN_SQL3FreeX(pPager->aHash);
	pPager->nHash=N;
	pPager->aHash=aHash;
	for(pPg=pPager->pAll;pPg;pPg=pPg->pNextAll)
	{
		int h;
		if(pPg->pgno==0)continue;
		h=pPg->pgno &(N-1);
		pPg->pNextHash=aHash[h];
		if(aHash[h])aHash[h]->pPrevHash=pPg;
		aHash[h]=pPg;
		pPg->pPrevHash=0;
	}
}
int read32bits(OsFile *fd,u32 *pRes)
{
	unsigned char ac[4];
	int rc=WN_SQL3OsRead(fd,ac,sizeof(ac));
	if(rc==0)*pRes=WN_SQL3Get4byte(ac);
	return rc;
}
#define put32bits(A,B)WN_SQL3Put4byte((u8*)A,B)
int write32bits(OsFile *fd,u32 val)
{
	char ac[4];
	put32bits(ac,val);
	return WN_SQL3OsWrite(fd,ac,4);
}
int pager_error(Pager *pPager,int rc)
{
	int rc2=rc & 0xff;
	if(rc2==WN_SQL_FULL||rc2==WN_SQL_IOERR||rc2==WN_SQL_CORRUPT)pPager->errCode=rc;
	return rc;
}
#ifdef WN_SQL_CHECK_PAGES
u32 pager_datahash(int nByte,unsigned char *pData)
{
	u32 hash=0;
	int i;
	for(i=0;i<nByte;i++) hash=(hash*1039)+pData[i];
	return hash;
}
u32 pager_pagehash(PgHdr *pPage)
{
	return pager_datahash(pPage->pPager->pageSize,(unsigned char *)PGHDR_TO_DATA(pPage));
}
#define CHECK_PAGE(x)checkPage(x)
void checkPage(PgHdr *pPg)
{
	Pager *pPager=pPg->pPager;
	pPg->pageHash==pager_pagehash(pPg));
}
#else
#define pager_datahash(X,Y)0
#define pager_pagehash(X)0
#define CHECK_PAGE(x)
#endif
int readMasterJournal(OsFile *pJrnl,char **pzMaster)
{
	int rc;
	*pzMaster=0;
	i64 szJ;
	if((rc=WN_SQL3OsFileSize(pJrnl,&szJ)) || szJ<16)return rc;
	if(rc=WN_SQL3OsSeek(pJrnl,szJ-16))return rc;
	u32 len;
	if(rc=read32bits(pJrnl,&len))return rc;
	u32 cksum;
	if(rc=read32bits(pJrnl,&cksum))return rc;
	unsigned char aMagic[8];
	if((rc=WN_SQL3OsRead(pJrnl,aMagic,8)) || memcmp(aMagic,aJournalMagic,8))return rc;
	if(rc=WN_SQL3OsSeek(pJrnl,szJ-16-len))return rc;
	*pzMaster=(char *)WN_SQL3Malloc(len+1);
	if(!*pzMaster)return WN_SQL_NOMEM;
	if(rc=WN_SQL3OsRead(pJrnl,*pzMaster,len))
	{
		WN_SQL3FreeX(*pzMaster);
		*pzMaster=0;
		return rc;
	}
	for(int i=0;i<len;i++) cksum-=(*pzMaster)[i];
	if(cksum)
	{
		WN_SQL3FreeX(*pzMaster);
		*pzMaster=0;
	}
	else
		(*pzMaster)[len]='\0';
	return 0;
}
int seekJournalHdr(Pager *pPager)
{
	i64 offset=0,c=pPager->journalOff;
	if(c) offset=((c-1)/JOURNAL_HDR_SZ(pPager)+1)* JOURNAL_HDR_SZ(pPager);
	pPager->journalOff=offset;
	return WN_SQL3OsSeek(pPager->jfd,pPager->journalOff);
}
int writeJournalHdr(Pager *pPager)
{
	int rc;
	if(pPager->stmtHdrOff==0) pPager->stmtHdrOff=pPager->journalOff;
	if(rc=seekJournalHdr(pPager))return rc;
	pPager->journalHdr=pPager->journalOff;
	pPager->journalOff+=JOURNAL_HDR_SZ(pPager);
	char zHeader[sizeof(aJournalMagic)+16];
	memcpy(zHeader,aJournalMagic,sizeof(aJournalMagic));
	put32bits(&zHeader[sizeof(aJournalMagic)],pPager->noSync ? 0xffffffff :0);
	WN_SQL3Randomness(sizeof(pPager->cksumInit),&pPager->cksumInit);
	put32bits(&zHeader[sizeof(aJournalMagic)+4],pPager->cksumInit);
	put32bits(&zHeader[sizeof(aJournalMagic)+8],pPager->dbSize);
	put32bits(&zHeader[sizeof(aJournalMagic)+12],pPager->sectorSize);
	IOTRACE(("JHDR %p %lld %d\n",pPager,pPager->journalHdr,sizeof(zHeader)))
;
	if((rc=WN_SQL3OsWrite(pPager->jfd,zHeader,sizeof(zHeader)))==0)
	{
		IOTRACE(("JTAIL %p %lld\n",pPager,pPager->journalOff-1))
		if((rc=WN_SQL3OsSeek(pPager->jfd,pPager->journalOff-1))==0) rc=WN_SQL3OsWrite(pPager->jfd,"\000",1);
	}
	return rc;
}
int readJournalHdr(Pager *pPager,i64 journalSize,u32 *pNRec,u32 *pDbSize)
{
	int rc;
	if(rc=seekJournalHdr(pPager))return rc;
	if(pPager->journalOff+JOURNAL_HDR_SZ(pPager)> journalSize)return WN_SQL_DONE;
	unsigned char aMagic[8];
	if(rc=WN_SQL3OsRead(pPager->jfd,aMagic,sizeof(aMagic)))return rc;
	if(memcmp(aMagic,aJournalMagic,sizeof(aMagic)))return WN_SQL_DONE;
	if(rc=read32bits(pPager->jfd,pNRec))return rc;
	if(rc=read32bits(pPager->jfd,&pPager->cksumInit))return rc;
	if(rc=read32bits(pPager->jfd,pDbSize))return rc;
	if(rc=read32bits(pPager->jfd,(u32 *)&pPager->sectorSize))return rc;
	pPager->journalOff+=JOURNAL_HDR_SZ(pPager);
	return WN_SQL3OsSeek(pPager->jfd,pPager->journalOff);
}
int writeMasterJournal(Pager *pPager,const char *zMaster)
{
	if(!zMaster || pPager->setMaster)return 0;
	int rc,lenstrlen(zMaster),i;
	u32 cksum=0;
	char zBuf[sizeof(aJournalMagic)+2*4];
	pPager->setMaster=1;
	for(i=0;i<len;i++)cksum+=zMaster[i];
	if(pPager->fullSync && rc=seekJournalHdr(pPager))return rc;
	pPager->journalOff+=(len+20);
	if(rc=write32bits(pPager->jfd,PAGER_MJ_PGNO(pPager)))return rc;
	if(rc=WN_SQL3OsWrite(pPager->jfd,zMaster,len))return rc;
	put32bits(zBuf,len);
	put32bits(&zBuf[4],cksum);
	memcpy(&zBuf[8],aJournalMagic,sizeof(aJournalMagic));
	rc=WN_SQL3OsWrite(pPager->jfd,zBuf,8+sizeof(aJournalMagic));
	pPager->needSync=!pPager->noSync;
	return rc;
}
void page_add_to_stmt_list(PgHdr *pPg)
{
	Pager *pPager=pPg->pPager;
	PgHistory *pHist=PGHDR_TO_HIST(pPg,pPager);
	if(!pHist->inStmt)
	{
		if(pPager->pStmt)PGHDR_TO_HIST(pPager->pStmt,pPager)->pPrevStmt=pPg;
		pHist->pNextStmt=pPager->pStmt;
		pPager->pStmt=pPg;
		pHist->inStmt=1;
	}
}
PgHdr *pager_lookup(Pager *pPager,Pgno pgno)
{
	if(pPager->aHash==0)return 0;
	PgHdr *p=pPager->aHash[pgno &(pPager->nHash-1)];
	while(p && p->pgno!=pgno)p=p->pNextHash;
	return p;
}
void pager_unlock(Pager *pPager)
{
	if(!pPager->exclusiveMode)
	{
		if(!MEMDB)
		{
			WN_SQL3OsUnlock(pPager->fd,NO_LOCK);
			pPager->dbSize=-1;
			IOTRACE(("UNLOCK %p\n",pPager))
		}
		pPager->state=PAGER_UNLOCK;
		pPager->changeCountDone=0;
	}
}
void pagerUnlockAndRollback(Pager *p)
{
	if(p->errCode)return;
	if(p->state>=PAGER_RESERVED)WN_SQL3PagerRollback(p);
	pager_unlock(p);
}
void pager_reset(Pager *pPager)
{
	if(pPager->errCode)return;
	PgHdr *pPg,*pNext;
	for(pPg=pPager->pAll;pPg;pPg=pNext)
	{
		IOTRACE(("PGFREE %p %d\n",pPager,pPg->pgno));
		PAGER_INCR(WN_SQL3_pager_pgfree_count);
		pNext=pPg->pNextAll;
		WN_SQL3FreeX(pPg);
	}
	pPager->pStmt=0;
	pPager->pFirst=0;
	pPager->pFirstSynced=0;
	pPager->pLast=0;
	pPager->pAll=0;
	pPager->nHash=0;
	WN_SQL3FreeX(pPager->aHash);
	pPager->nPage=0;
	pPager->aHash=0;
	pPager->nRef=0;
}
int pager_end_transaction(Pager *pPager)
{
	if(pPager->state<PAGER_RESERVED)return 0;
	PgHdr *pPg;
	int rc=0,rc2=0;
	WN_SQL3PagerStmtCommit(pPager);
	if(pPager->stmtOpen && !pPager->exclusiveMode)
	{
		WN_SQL3OsClose(&pPager->stfd);
		pPager->stmtOpen=0;
	}
	if(pPager->journalOpen)
	{
		if(pPager->exclusiveMode&&(rc=WN_SQL3OsTruncate(pPager->jfd,0))==0)
		{
			WN_SQL3OsSeek(pPager->jfd,0);
			pPager->journalOff=0;
			pPager->journalStarted=0;
		}
		else
		{
			WN_SQL3OsClose(&pPager->jfd);
			pPager->journalOpen=0;
			if(rc==0)rc=WN_SQL3OsDelete(pPager->zJournal);
		}
		WN_SQL3FreeX(pPager->aInJournal);
		pPager->aInJournal=0;
		for(pPg=pPager->pAll;pPg;pPg=pPg->pNextAll)
		{
			pPg->inJournal=0;
			pPg->dirty=0;
			pPg->needSync=0;
			pPg->alwaysRollback=0;
#ifdef WN_SQL_CHECK_PAGES
			pPg->pageHash=pager_pagehash(pPg);
#endif
		}
		pPager->pDirty=0;
		pPager->dirtyCache=0;
		pPager->nRec=0;
	}
	if(!pPager->exclusiveMode)
	{
		rc2=WN_SQL3OsUnlock(pPager->fd,SHARED_LOCK);
		pPager->state=PAGER_SHARED;
	}
	else
		if(pPager->state==PAGER_SYNCED)pPager->state=PAGER_EXCLUSIVE;
	pPager->origDbSize=0;
	pPager->setMaster=0;
	pPager->needSync=0;
	pPager->pFirstSynced=pPager->pFirst;
	pPager->dbSize=-1;
	return(rc?rc:rc2);
}
u32 pager_cksum(Pager *pPager,const u8 *aData)
{
	u32 cksum=pPager->cksumInit;
	int i=pPager->pageSize-200;
	while(i>0)
	{
		cksum+=aData[i];
		i-=200;
	}
	return cksum;
}
int pager_playback_one_page(Pager *pPager,OsFile *jfd,int useCksum)
{
	PgHdr *pPg;
	Pgno pgno;
	u32 cksum;
	u8 *aData=(u8 *)pPager->pTmpSpace;
	int rc=read32bits(jfd,&pgno);
	if(rc)return rc;
	if(rc=WN_SQL3OsRead(jfd,aData,pPager->pageSize))return rc;
	pPager->journalOff+=pPager->pageSize+4;
	if(pgno==0 || pgno==PAGER_MJ_PGNO(pPager))return WN_SQL_DONE;
	if(pgno>(unsigned)pPager->dbSize)return 0;
	if(useCksum)
	{
		if(rc=read32bits(jfd,&cksum))return rc;
		pPager->journalOff+=4;
		if(pager_cksum(pPager,aData)!=cksum) return WN_SQL_DONE;
	}
	pPg=pager_lookup(pPager,pgno);
	PAGERTRACE4("PLAYBACK %d page %d hash(%08x)\n",PAGERID(pPager),pgno,pager_datahash(pPager->pageSize,aData));
	if(pPager->state>=PAGER_EXCLUSIVE &&(pPg==0 || pPg->needSync==0))
	{
		if((rc=WN_SQL3OsSeek(pPager->fd,(pgno-1)*(i64)pPager->pageSize))==0) rc=WN_SQL3OsWrite(pPager->fd,aData,pPager->pageSize);
		if(pPg)makeClean(pPg);
	}
	if(pPg)
	{
		void *pData;
		pData=PGHDR_TO_DATA(pPg);
		memcpy(pData,aData,pPager->pageSize);
		if(pPager->xReiniter)pPager->xReiniter(pPg,pPager->pageSize);
#ifdef WN_SQL_CHECK_PAGES
		pPg->pageHash=pager_pagehash(pPg);
#endif
		if(pgno==1)memcpy(&pPager->dbFileVers,&((u8*)pData)[24],sizeof(pPager->dbFileVers));
		CODEC1(pPager,pData,pPg->pgno,3);
	}
	return rc;
}
int pager_delmaster(const char *zMaster)
{
	int master_open=0;
	OsFile *master=0;
	char *zMasterJournal=0;
	i64 nMasterJournal;
	int rc=WN_SQL3OsOpenReadOnly(zMaster,&master);
	if(rc)goto delmaster_out;
	master_open=1;
	if(rc=WN_SQL3OsFileSize(master,&nMasterJournal))goto delmaster_out;
	if(nMasterJournal>0)
	{
		char *zJournal,*zMasterPtr=0;
		zMasterJournal=(char *)WN_SQL3Malloc(nMasterJournal);
		if(!zMasterJournal)
		{
			rc=WN_SQL_NOMEM;
			goto delmaster_out;
		}
		rc=WN_SQL3OsRead(master,zMasterJournal,nMasterJournal);
		if(rc)goto delmaster_out;
		zJournal=zMasterJournal;
		while((zJournal-zMasterJournal)<nMasterJournal)
		{
			if(WN_SQL3OsFileExists(zJournal))
			{
				OsFile *journal=0;
				int c;
				if(rc=WN_SQL3OsOpenReadOnly(zJournal,&journal))goto delmaster_out;
				rc=readMasterJournal(journal,&zMasterPtr);
				WN_SQL3OsClose(&journal);
				if(rc)goto delmaster_out;
				c=zMasterPtr && strcmp(zMasterPtr,zMaster)==0;
				WN_SQL3FreeX(zMasterPtr);
				if(c)goto delmaster_out;
			}
			zJournal+=(strlen(zJournal)+1);
		}
	}
	rc=WN_SQL3OsDelete(zMaster);
delmaster_out:
	if(zMasterJournal)WN_SQL3FreeX(zMasterJournal);
	if(master_open)WN_SQL3OsClose(&master);
	return rc;
}
int pager_truncate(Pager *pPager,int nPage)
{
	int rc=0;
	if(pPager->state>=PAGER_EXCLUSIVE)
	{
		rc=WN_SQL3OsTruncate(pPager->fd,pPager->pageSize*(i64)nPage);
	}
	if(rc==0)
	{
		pPager->dbSize=nPage;
		pager_truncate_cache(pPager);
	}
	return rc;
}
void setSectorSize(Pager *pPager)
{
	pPager->sectorSize=WN_SQL3OsSectorSize(pPager->fd);
	if(pPager->sectorSize<pPager->pageSize)pPager->sectorSize=pPager->pageSize;
}
int pager_playback(Pager *pPager,int isHot)
{
	i64 szJ;
	u32 nRec;
	int i;
	Pgno mxPg=0;
	int rc=WN_SQL3OsFileSize(pPager->jfd,&szJ);
	char *zMaster=0;
	if(rc || szJ==0)goto end_playback;
	if(rc=readMasterJournal(pPager->jfd,&zMaster) ||(zMaster && !WN_SQL3OsFileExists(zMaster)))
	{
		WN_SQL3FreeX(zMaster);
		zMaster=0;
		if(rc==WN_SQL_DONE)rc=0;
		goto end_playback;
	}
	WN_SQL3OsSeek(pPager->jfd,0);
	pPager->journalOff=0;
	while(1)
	{
		rc=readJournalHdr(pPager,szJ,&nRec,&mxPg);
		if(rc)
		{
			if(rc==WN_SQL_DONE)rc=0;
			goto end_playback;
		}
		if(nRec==0xffffffff)nRec=(szJ-JOURNAL_HDR_SZ(pPager))/JOURNAL_PG_SZ(pPager);
		if(nRec==0 && !isHot)nRec=(szJ-pPager->journalOff)/ JOURNAL_PG_SZ(pPager);
		if(pPager->journalOff==JOURNAL_HDR_SZ(pPager) && (rc=pager_truncate(pPager,mxPg))goto end_playback;
		for(i=0;i<nRec;i++)
			if(rc=pager_playback_one_page(pPager,pPager->jfd,1))
				if(rc==WN_SQL_DONE)
				{
					rc=0;
					pPager->journalOff=szJ;
					break;
				}
				else
					goto end_playback;
	}
end_playback:
	if(rc==0)rc=pager_end_transaction(pPager);
	if(zMaster)
	{
		if(rc==0)rc=pager_delmaster(zMaster);
		WN_SQL3FreeX(zMaster);
	}
	setSectorSize(pPager);
	return rc;
}
int pager_stmt_playback(Pager *pPager)
{
	i64 szJ,hdrOff;
	int nRec,i,rc;
	szJ=pPager->journalOff;
#ifndef NDEBUG
	i64 os_szJ;
	if(rc=WN_SQL3OsFileSize(pPager->jfd,&os_szJ))return rc;
#endif
	hdrOff=pPager->stmtHdrOff;
	if(!hdrOff)hdrOff=szJ;
	rc=pager_truncate(pPager,pPager->stmtSize);
	WN_SQL3OsSeek(pPager->stfd,0);
	nRec=pPager->stmtNRec;
	for(i=nRec-1;i>=0;i--)
		if(rc=pager_playback_one_page(pPager,pPager->stfd,0))goto end_stmt_playback;
	rc=WN_SQL3OsSeek(pPager->jfd,pPager->stmtJSize);
	if(rc)goto end_stmt_playback;
	pPager->journalOff=pPager->stmtJSize;
	pPager->cksumInit=pPager->stmtCksum;
	while(pPager->journalOff<hdrOff)
	{
		rc=pager_playback_one_page(pPager,pPager->jfd,1);
		if(rc)goto end_stmt_playback;
	}
	while(pPager->journalOff<szJ)
	{
		u32 nJRec,dummy;
		rc=readJournalHdr(pPager,szJ,&nJRec,&dummy);
		if(rc)goto end_stmt_playback;
		if(nJRec==0)nJRec=(szJ-pPager->journalOff)/(pPager->pageSize+8);
		for(i=nJRec-1;i>=0 && pPager->journalOff<szJ;i--)
		{
			rc=pager_playback_one_page(pPager,pPager->jfd,1);
			if(rc)goto end_stmt_playback;
		}
	}
	pPager->journalOff=szJ;
end_stmt_playback:
	if(rc==0)pPager->journalOff=szJ;
	return rc;
}
void WN_SQL3PagerSetCachesize(Pager *pPager,int mxPage)
{
	if(mxPage>10)
		pPager->mxPage=mxPage;
	else
		pPager->mxPage=10;
}
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
void WN_SQL3PagerSetSafetyLevel(Pager *pPager,int level,int full_fsync)
{
	pPager->noSync=level==1 || pPager->tempFile;
	pPager->fullSync=level==3 && !pPager->tempFile;
	pPager->full_fsync=full_fsync;
	if(pPager->noSync)pPager->needSync=0;
}
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_opentemp_count=0;
#endif
int WN_SQL3PagerOpentemp(OsFile **pFd)
{
	int cnt=8,rc;
	char zFile[WN_SQL_TEMPNAME_SIZE];
#ifdef WN_SQL_TEST
	WN_SQL3_opentemp_count++;
#endif
	do
	{
		cnt--;
		WN_SQL3OsTempFileName(zFile);
		rc=WN_SQL3OsOpenExclusive(zFile,pFd,1);
	}while(cnt>0 && rc && rc!=WN_SQL_NOMEM);
	return rc;
}
int WN_SQL3PagerOpen(Pager **ppPager,const char *zFilename,int nExtra,int flags)
{
	Pager *pPager=0;
	char *zFullPathname=0;
	int nameLen,rc=0,i,tempFile=0,memDb=0,readOnly=0,
		useJournal=(flags & PAGER_OMIT_JOURNAL)==0,
		noReadlock=(flags & PAGER_NO_READLOCK)!=0;
	OsFile *fd=0;
	char zTemp[WN_SQL_TEMPNAME_SIZE];
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
	ThreadData *pTsd=WN_SQL3ThreadData();
#endif
	*ppPager=0;
	if(zFilename && zFilename[0])
	{
#ifndef WN_SQL_OMIT_MEMORYDB
	if(strcmp(zFilename,":memory:")==0)
	{
		memDb=1;
		zFullPathname=WN_SQLStrDup("");
	}
	else
#endif
	{
		zFullPathname=WN_SQL3OsFullPathname(zFilename);
		if(zFullPathname)rc=WN_SQL3OsOpenReadWrite(zFullPathname,&fd,&readOnly);
	}
	}
	else
	{
		rc=WN_SQL3PagerOpentemp(&fd);
		WN_SQL3OsTempFileName(zTemp);
		zFilename=zTemp;
		zFullPathname=WN_SQL3OsFullPathname(zFilename);
		if(rc==0)tempFile=1;
	}
	if(zFullPathname)
	{
		nameLen=strlen(zFullPathname);
		pPager=WN_SQL3Malloc(sizeof(*pPager)+nameLen*3+30);
		if(pPager && rc==0)
			pPager->pTmpSpace=(char *)WN_SQLMallocRaw(WN_SQL_DEFAULT_PAGE_SIZE);
	}
	if(!pPager || !zFullPathname || !pPager->pTmpSpace || rc)
	{
		WN_SQL3OsClose(&fd);
		WN_SQL3FreeX(zFullPathname);
		WN_SQL3FreeX(pPager);
		return((rc==0)?WN_SQL_NOMEM:rc);
	}
	PAGERTRACE3("OPEN %d %s\n",FILEHANDLEID(fd),zFullPathname);
	IOTRACE(("OPEN %p %s\n",pPager,zFullPathname))
	pPager->zFilename=(char*)&pPager[1];
	pPager->zDirectory=&pPager->zFilename[nameLen+1];
	pPager->zJournal=&pPager->zDirectory[nameLen+1];
	memcpy(pPager->zFilename,zFullPathname,nameLen+1);
	memcpy(pPager->zDirectory,zFullPathname,nameLen+1);
	for(i=nameLen;i>0 && pPager->zDirectory[i-1]!='/';i--);
	if(i>0)pPager->zDirectory[i-1]=0;
	memcpy(pPager->zJournal,zFullPathname,nameLen);
	WN_SQL3FreeX(zFullPathname);
	memcpy(&pPager->zJournal[nameLen],"-journal",sizeof("-journal"));
	pPager->fd=fd;
	pPager->useJournal=useJournal && !memDb;
	pPager->noReadlock=noReadlock && readOnly;
	pPager->dbSize=memDb-1;
	pPager->pageSize=WN_SQL_DEFAULT_PAGE_SIZE;
	pPager->mxPage=100;
	pPager->mxPgno=WN_SQL_MAX_PAGE_COUNT;
	pPager->tempFile=tempFile;
	pPager->exclusiveMode=tempFile;
	pPager->memDb=memDb;
	pPager->readOnly=readOnly;
	pPager->noSync=pPager->tempFile || !useJournal;
	pPager->fullSync=(pPager->noSync?0:1);
	pPager->nExtra=FORCE_ALIGNMENT(nExtra);
	if(!memDb)setSectorSize(pPager);
	*ppPager=pPager;
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
	pPager->pNext=pTsd->pPager;
	pTsd->pPager=pPager;
#endif
	return 0;
}
void WN_SQL3PagerSetBusyhandler(Pager *pPager,BusyHandler *pBusyHandler)
{
	pPager->pBusyHandler=pBusyHandler;
}
void WN_SQL3PagerSetDestructor(Pager *pPager,void(*xDesc)(DbPage*,int))
{
	pPager->xDestructor=xDesc;
}
void WN_SQL3PagerSetReiniter(Pager *pPager,void(*xReinit)(DbPage*,int))
{
	pPager->xReiniter=xReinit;
}
int WN_SQL3PagerSetPagesize(Pager *pPager,int pageSize)
{
	if(!pPager->memDb && pPager->nRef==0)
	{
		pager_reset(pPager);
		pPager->pageSize=pageSize;
		pPager->pTmpSpace=WN_SQL3ReallocOrFree(pPager->pTmpSpace,pageSize);
	}
	return pPager->pageSize;
}
int WN_SQL3PagerMaxPageCount(Pager *pPager,int mxPage)
{
	if(mxPage>0)pPager->mxPgno=mxPage;
	WN_SQL3PagerPagecount(pPager);
	return pPager->mxPgno;
}
#ifdef WN_SQL_TEST
extern int WN_SQL3_io_error_pending;
extern int WN_SQL3_io_error_hit;
int saved_cnt;
void disable_simulated_io_errors(void)
{
	saved_cnt=WN_SQL3_io_error_pending;
	WN_SQL3_io_error_pending=-1;
}
void enable_simulated_io_errors(void)
{
	WN_SQL3_io_error_pending=saved_cnt;
}
#else
# define disable_simulated_io_errors()
# define enable_simulated_io_errors()
#endif
int WN_SQL3PagerReadFileheader(Pager *pPager,int N,unsigned char *pDest)
{
	int rc=0;
	memset(pDest,0,N);
	if(MEMDB==0)
	{
		disable_simulated_io_errors();
		WN_SQL3OsSeek(pPager->fd,0);
		enable_simulated_io_errors();
		IOTRACE(("DBHDR %p 0 %d\n",pPager,N))
		rc=WN_SQL3OsRead(pPager->fd,pDest,N);
		if(rc==WN_SQL_IOERR_SHORT_READ)rc=0;
	}
	return rc;
}
int WN_SQL3PagerPagecount(Pager *pPager)
{
	i64 n;
	int rc;
	if(pPager->errCode)return 0;
	if(pPager->dbSize>=0)
		n=pPager->dbSize;
	else
	{
		if((rc=WN_SQL3OsFileSize(pPager->fd,&n)))
		{
			pager_error(pPager,rc);
			return 0;
		}
		if(n>0 && n<pPager->pageSize)
			n=1;
		else
			n /=pPager->pageSize;
		if(pPager->state!=PAGER_UNLOCK)	pPager->dbSize=n;
	}
	if(n==(PENDING_BYTE/pPager->pageSize))n++;
	if(n>pPager->mxPgno)pPager->mxPgno=n;
	return n;
}
#ifndef WN_SQL_OMIT_MEMORYDB
void clearHistory(PgHistory *pHist)
{
	WN_SQL3FreeX(pHist->pOrig);
	WN_SQL3FreeX(pHist->pStmt);
	pHist->pOrig=0;
	pHist->pStmt=0;
}
#else
#define clearHistory(x)
#endif
int syncJournal(Pager*);
void unlinkHashChain(Pager *pPager,PgHdr *pPg)
{
	if(pPg->pgno==0)return;
	if(pPg->pNextHash)pPg->pNextHash->pPrevHash=pPg->pPrevHash;
	if(pPg->pPrevHash)
		pPg->pPrevHash->pNextHash=pPg->pNextHash;
	else
	{
		int h=pPg->pgno &(pPager->nHash-1);
		pPager->aHash[h]=pPg->pNextHash;
	}
	if(MEMDB)clearHistory(PGHDR_TO_HIST(pPg,pPager));
	pPg->pgno=0;
	pPg->pNextHash=pPg->pPrevHash=0;
}
void unlinkPage(PgHdr *pPg)
{
	Pager *pPager=pPg->pPager;
	if(pPg==pPager->pFirstSynced)
	{
		PgHdr *p=pPg->pNextFree;
		while(p && p->needSync)p=p->pNextFree;
		pPager->pFirstSynced=p;
	}
	if(pPg->pPrevFree)
		pPg->pPrevFree->pNextFree=pPg->pNextFree;
	else
		pPager->pFirst=pPg->pNextFree;
	if(pPg->pNextFree)
		pPg->pNextFree->pPrevFree=pPg->pPrevFree;
	else
		pPager->pLast=pPg->pPrevFree;
	pPg->pNextFree=pPg->pPrevFree=0;
	unlinkHashChain(pPager,pPg);
}
void pager_truncate_cache(Pager *pPager)
{
	PgHdr *pPg,**ppPg;
	int dbSize=pPager->dbSize;
	ppPg=&pPager->pAll;
	while((pPg=*ppPg))
		if(pPg->pgno<=dbSize)
			ppPg=&pPg->pNextAll;
		else
			if(pPg->nRef>0)
			{
				memset(PGHDR_TO_DATA(pPg),0,pPager->pageSize);
				ppPg=&pPg->pNextAll;
			}
			else
			{
				*ppPg=pPg->pNextAll;
				IOTRACE(("PGFREE %p %d\n",pPager,pPg->pgno));
				PAGER_INCR(WN_SQL3_pager_pgfree_count);
				unlinkPage(pPg);
				makeClean(pPg);
				WN_SQL3FreeX(pPg);
				pPager->nPage--;
			}
}
int pager_wait_on_lock(Pager *pPager,int locktype)
{
	int rc;
	if(pPager->state>=locktype)
		rc=0;
	else
	{
		do
		{
			rc=WN_SQL3OsLock(pPager->fd,locktype);
		}while(rc==WN_SQL_BUSY && WN_SQL3InvokeBusyHandler(pPager->pBusyHandler));
		if(rc==0)
		{
			pPager->state=locktype;
			IOTRACE(("LOCK %p %d\n",pPager,locktype))
		}
	}
	return rc;
}
int WN_SQL3PagerTruncate(Pager *pPager,Pgno nPage)
{
	int rc;
	WN_SQL3PagerPagecount(pPager);
	if(pPager->errCode)	return pPager->errCode;
	if(nPage>=(unsigned)pPager->dbSize)return 0;
	if(MEMDB)
	{
		pPager->dbSize=nPage;
		pager_truncate_cache(pPager);
		return 0;
	}
	if(rc=syncJournal(pPager))return rc;
	if(rc=pager_wait_on_lock(pPager,EXCLUSIVE_LOCK))return rc;
	return pager_truncate(pPager,nPage);
}
int WN_SQL3PagerClose(Pager *pPager)
{
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
	ThreadData *pTsd=WN_SQL3ThreadData();
#endif
	disable_simulated_io_errors();
	pPager->errCode=0;
	pPager->exclusiveMode=0;
	pager_reset(pPager);
	pagerUnlockAndRollback(pPager);
	enable_simulated_io_errors();
	PAGERTRACE2("CLOSE %d\n",PAGERID(pPager));
	IOTRACE(("CLOSE %p\n",pPager))
	if(pPager->journalOpen)WN_SQL3OsClose(&pPager->jfd);
	WN_SQL3FreeX(pPager->aInJournal);
	if(pPager->stmtOpen)WN_SQL3OsClose(&pPager->stfd);
	WN_SQL3OsClose(&pPager->fd);
#ifdef WN_SQL_ENABLE_MEMORY_MANAGEMENT
	if(pPager==pTsd->pPager)
		pTsd->pPager=pPager->pNext;
	else
	{
		Pager *pTmp;
		for(pTmp=pTsd->pPager;pTmp->pNext!=pPager;pTmp=pTmp->pNext);
		pTmp->pNext=pPager->pNext;
	}
#endif
	WN_SQL3FreeX(pPager->aHash);
	WN_SQL3FreeX(pPager->pTmpSpace);
	WN_SQL3FreeX(pPager);
	return 0;
}
#if !defined(NDEBUG)|| defined(WN_SQL_TEST)
Pgno WN_SQL3PagerPagenumber(DbPage *p)
{
	return p->pgno;
}
#endif
void _page_ref(PgHdr *pPg)
{
	if(pPg->nRef==0)
	{
		if(pPg==pPg->pPager->pFirstSynced)
		{
			PgHdr *p=pPg->pNextFree;
			while(p && p->needSync)p=p->pNextFree;
			pPg->pPager->pFirstSynced=p;
		}
		if(pPg->pPrevFree)
			pPg->pPrevFree->pNextFree=pPg->pNextFree;
		else
			pPg->pPager->pFirst=pPg->pNextFree;
		if(pPg->pNextFree)
			pPg->pNextFree->pPrevFree=pPg->pPrevFree;
		else
			pPg->pPager->pLast=pPg->pPrevFree;
		pPg->pPager->nRef++;
	}
	pPg->nRef++;
	REFINFO(pPg);
}
#ifdef WN_SQL_DEBUG
void page_ref(PgHdr *pPg)
{	
	if(pPg->nRef)
	{
		pPg->nRef++;
		REFINFO(pPg);
	}
	else
		_page_ref(pPg);
}
#else
# define page_ref(P)((P)->nRef==0?_page_ref(P):(void)(P)->nRef++)
#endif
int WN_SQL3PagerRef(DbPage *pPg)
{
	page_ref(pPg);
	return 0;
}
int syncJournal(Pager *pPager)
{
	PgHdr *pPg;
	int rc=0;
	if(pPager->needSync)
	{
		if(!pPager->tempFile)
		{
#ifndef NDEBUG
			i64 jSz;
			if(rc=WN_SQL3OsFileSize(pPager->jfd,&jSz))return rc;
#endif
			if(pPager->fullSync)
			{
				PAGERTRACE2("SYNC journal of %d\n",PAGERID(pPager));
				IOTRACE(("JSYNC %p\n",pPager))
				if(rc=WN_SQL3OsSync(pPager->jfd,0))return rc;
			}
			if(rc=WN_SQL3OsSeek(pPager->jfd,pPager->journalHdr+sizeof(aJournalMagic)))return rc;
			IOTRACE(("JHDR %p %lld %d\n",pPager,pPager->journalHdr+sizeof(aJournalMagic),4))
			if(rc=write32bits(pPager->jfd,pPager->nRec))return rc;
			if(rc=WN_SQL3OsSeek(pPager->jfd,pPager->journalOff))return rc;
			PAGERTRACE2("SYNC journal of %d\n",PAGERID(pPager));
			IOTRACE(("JSYNC %p\n",pPager))
			if(rc=WN_SQL3OsSync(pPager->jfd,pPager->full_fsync))return rc;
			pPager->journalStarted=1;
		}
		pPager->needSync=0;
		for(pPg=pPager->pAll;pPg;pPg=pPg->pNextAll)pPg->needSync=0;
		pPager->pFirstSynced=pPager->pFirst;
	}
#ifndef NDEBUG
	else
		for(pPg=pPager->pAll;pPg;pPg=pPg->pNextAll);
#endif
	return 0;
}
PgHdr *merge_pagelist(PgHdr *pA,PgHdr *pB)
{
	PgHdr result,*pTail;
	pTail=&result;
	while(pA && pB)
		if(pA->pgno<pB->pgno)
		{
			pTail->pDirty=pA;
			pTail=pA;
			pA=pA->pDirty;
		}
		else
		{
			pTail->pDirty=pB;
			pTail=pB;
			pB=pB->pDirty;
		}
	if(pA)
		pTail->pDirty=pA;
	else
		if(pB)
			pTail->pDirty=pB;
		else
			pTail->pDirty=0;
	return result.pDirty;
}
#define N_SORT_BUCKET_ALLOC 25
#define N_SORT_BUCKET 25
#ifdef WN_SQL_TEST
int WN_SQL3_pager_n_sort_bucket=0;
#undef N_SORT_BUCKET
#define N_SORT_BUCKET \
(WN_SQL3_pager_n_sort_bucket?WN_SQL3_pager_n_sort_bucket:N_SORT_BUCKET_ALLOC)
#endif
PgHdr *sort_pagelist(PgHdr *pIn)
{
	PgHdr *a[N_SORT_BUCKET_ALLOC],*p;
	int i;
	memset(a,0,sizeof(a));
	while(pIn)
	{
		p=pIn;
		pIn=p->pDirty;
		p->pDirty=0;
		for(i=0;i<N_SORT_BUCKET-1;i++)
		{
			if(a[i])
			{
				p=merge_pagelist(a[i],p);
				a[i]=0;
			}
			else
			{
				a[i]=p;
				break;
			}
		}
		if(i==N_SORT_BUCKET-1)a[i]=merge_pagelist(a[i],p);
	}
	p=a[0];
	for(i=1;i<N_SORT_BUCKET;i++)p=merge_pagelist(p,a[i]);
	return p;
}
int pager_write_pagelist(PgHdr *pList)
{
	Pager *pPager;
	int rc;
	if(pList==0)return 0;
	pPager=pList->pPager;
	if(rc=pager_wait_on_lock(pPager,EXCLUSIVE_LOCK))return rc;
	pList=sort_pagelist(pList);
	while(pList)
	{
		if(rc=WN_SQL3OsSeek(pPager->fd,(pList->pgno-1)*(i64)pPager->pageSize))return rc;
		if(pList->pgno<=pPager->dbSize)
		{
			char *pData=CODEC2(pPager,PGHDR_TO_DATA(pList),pList->pgno,6);
			PAGERTRACE4("STORE %d page %d hash(%08x)\n",PAGERID(pPager),pList->pgno,pager_pagehash(pList));
			IOTRACE(("PGOUT %p %d\n",pPager,pList->pgno));
			rc=WN_SQL3OsWrite(pPager->fd,pData,pPager->pageSize);
			PAGER_INCR(WN_SQL3_pager_writedb_count);
			PAGER_INCR(pPager->nWrite);
			if(pList->pgno==1)memcpy(&pPager->dbFileVers,&pData[24],sizeof(pPager->dbFileVers));
		}
#ifndef NDEBUG
		else
			PAGERTRACE3("NOSTORE %d page %d\n",PAGERID(pPager),pList->pgno);
#endif
		if(rc)return rc;
		pList->dirty=0;
#ifdef WN_SQL_CHECK_PAGES
		pList->pageHash=pager_pagehash(pList);
#endif
		pList=pList->pDirty;
	}
	return 0;
}
PgHdr *pager_get_all_dirty_pages(Pager *pPager)
{
	return pPager->pDirty;
}
int hasHotJournal(Pager *pPager)
{
	if((!pPager->useJournal)||(!WN_SQL3OsFileExists(pPager->zJournal))||(WN_SQL3OsCheckReservedLock(pPager->fd)))return 0;
	if(WN_SQL3PagerPagecount(pPager))
		return 1;
	else
	{
		WN_SQL3OsDelete(pPager->zJournal);
		return 0;
	}
}
int pager_recycle(Pager *pPager,int syncOk,PgHdr **ppPg)
{
	*ppPg=0;
	PgHdr *pPg=pPager->pFirstSynced;
	int rc;
	if(pPg==0 && pPager->pFirst && syncOk && !MEMDB)
	{
		if(rc=syncJournal(pPager))return rc;
		if(pPager->fullSync)
		{
			pPager->nRec=0;
			if(rc=writeJournalHdr(pPager))return rc;
		}
		pPg=pPager->pFirst;
	}
	if(pPg==0)return 0;
	if(pPg->dirty)
	{
		makeClean(pPg);
		pPg->dirty=1;
		pPg->pDirty=0;
		if(rc=pager_write_pagelist(pPg))return rc;
	}
	if(pPg->alwaysRollback)
	{
		IOTRACE(("ALWAYS_ROLLBACK %p\n",pPager))
		pPager->alwaysRollback=1;
	}
	unlinkPage(pPg);
	*ppPg=pPg;
	return 0;
}
#if defined(WN_SQL_ENABLE_MEMORY_MANAGEMENT)&& !defined(WN_SQL_OMIT_DISKIO)
int WN_SQL3PagerReleaseMemory(int nReq)
{
	const ThreadData *pTsdro=WN_SQL3ThreadDataReadOnly();
	int nReleased=0;
	int i;
	if(WN_SQL3OsInMutex(0))return 0;
	for(i=0;i<=1;i++)
	{
		Pager *pPager=pTsdro->pPager;
		for(;pPager &&(nReq<0 || nReleased<nReq);pPager=pPager->pNext)
		{
			PgHdr *pPg;
			int rc;
			if(MEMDB)continue;
			while(0==(rc=pager_recycle(pPager,i,&pPg))&& pPg)
			{
				PgHdr *pTmp;
								if(pPg==pPager->pAll)
					pPager->pAll=pPg->pNextAll;
				else
				{
					for(pTmp=pPager->pAll;pTmp->pNextAll!=pPg;pTmp=pTmp->pNextAll);
					pTmp->pNextAll=pPg->pNextAll;
				}
				nReleased+=WN_SQL3AllocSize(pPg);
				IOTRACE(("PGFREE %p %d\n",pPager,pPg->pgno));
				PAGER_INCR(WN_SQL3_pager_pgfree_count);
				WN_SQL3FreeX(pPg);
			}
			if(rc)
			{
												pager_error(pPager,rc);
			}
		}
	}
	return nReleased;
}
#endif
int readDbPage(Pager *pPager,PgHdr *pPg,Pgno pgno)
{
	int rc=WN_SQL3OsSeek(pPager->fd,(pgno-1)*(i64)pPager->pageSize);
	if(rc==0)rc=WN_SQL3OsRead(pPager->fd,PGHDR_TO_DATA(pPg),pPager->pageSize);
	PAGER_INCR(WN_SQL3_pager_readdb_count);
	PAGER_INCR(pPager->nRead);
	IOTRACE(("PGIN %p %d\n",pPager,pgno));
	if(pgno==1)	memcpy(&pPager->dbFileVers,&((u8*)PGHDR_TO_DATA(pPg))[24],sizeof(pPager->dbFileVers));
	CODEC1(pPager,PGHDR_TO_DATA(pPg),pPg->pgno,3);
	PAGERTRACE4("FETCH %d page %d hash(%08x)\n",PAGERID(pPager),pPg->pgno,pager_pagehash(pPg));
	return rc;
}
int pagerSharedLock(Pager *pPager)
{
	int rc=0;
	if(pPager->state==PAGER_UNLOCK)
	{
		if(!MEMDB)
		{
						if(!pPager->noReadlock)
			{
				rc=pager_wait_on_lock(pPager,SHARED_LOCK);
				if(rc)return pager_error(pPager,rc);
							}
			if(hasHotJournal(pPager))
			{
				rc=WN_SQL3OsLock(pPager->fd,EXCLUSIVE_LOCK);
				if(rc)
				{
					pager_unlock(pPager);
					return pager_error(pPager,rc);
				}
				pPager->state=PAGER_EXCLUSIVE;
				rc=WN_SQL_BUSY;
				if(WN_SQL3OsFileExists(pPager->zJournal))
				{
					int ro;
					rc=WN_SQL3OsOpenReadWrite(pPager->zJournal,&pPager->jfd,&ro);
					if(ro)
					{
						rc=WN_SQL_BUSY;
						WN_SQL3OsClose(&pPager->jfd);
					}
				}
				if(rc)
				{
					pager_unlock(pPager);
					return WN_SQL_BUSY;
				}
				pPager->journalOpen=1;
				pPager->journalStarted=0;
				pPager->journalOff=0;
				pPager->setMaster=0;
				pPager->journalHdr=0;
				rc=pager_playback(pPager,1);
				if(rc)return pager_error(pPager,rc);
							}
			if(pPager->pAll)
			{
				char dbFileVers[sizeof(pPager->dbFileVers)];
				WN_SQL3PagerPagecount(pPager);
				if(pPager->errCode)return pPager->errCode;
				if(pPager->dbSize>0)
				{
					IOTRACE(("CKVERS %p %d\n",pPager,sizeof(dbFileVers)));
					if(rc=WN_SQL3OsSeek(pPager->fd,24))return rc;
					if(rc=WN_SQL3OsRead(pPager->fd,&dbFileVers,sizeof(dbFileVers)))return rc;
				}
				else
					memset(dbFileVers,0,sizeof(dbFileVers));
				if(memcmp(pPager->dbFileVers,dbFileVers,sizeof(dbFileVers)))
					pager_reset(pPager);
			}
		}
				if(pPager->state==PAGER_UNLOCK)pPager->state=PAGER_SHARED;
	}
	return rc;
}
int pagerAllocatePage(Pager *pPager,PgHdr **ppPg)
{
	int rc=0;
	PgHdr *pPg;
	if(pPager->nPage<pPager->mxPage || pPager->pFirst==0 || MEMDB
		||(pPager->pFirstSynced==0 && pPager->doNotSync))
	{
		if(pPager->nPage>=pPager->nHash)
		{
			pager_resize_hash_table(pPager,pPager->nHash<256 ? 256 :pPager->nHash*2);
			if(pPager->nHash==0)
			{
				rc=WN_SQL_NOMEM;
				goto pager_allocate_out;
			}
		}
		pPg=WN_SQLMallocRaw(sizeof(*pPg)+pPager->pageSize+sizeof(u32)+pPager->nExtra+MEMDB*sizeof(PgHistory));
		if(pPg==0)
		{
			rc=WN_SQL_NOMEM;
			goto pager_allocate_out;
		}
		memset(pPg,0,sizeof(*pPg));
		if(MEMDB)memset(PGHDR_TO_HIST(pPg,pPager),0,sizeof(PgHistory));
		pPg->pPager=pPager;
		pPg->pNextAll=pPager->pAll;
		pPager->pAll=pPg;
		pPager->nPage++;
	}
	else
	{
		rc=pager_recycle(pPager,1,&pPg);
		if(rc==WN_SQL_BUSY)	rc=WN_SQL_IOERR_BLOCKED;
		if(rc)goto pager_allocate_out;
					}
	*ppPg=pPg;
pager_allocate_out:
	return rc;
}
int pager_get_content(PgHdr *pPg)
{
	if(pPg->needRead)
	{
		int rc=readDbPage(pPg->pPager,pPg,pPg->pgno);
		if(rc==0)
			pPg->needRead=0;
		else
			return rc;
	}
	return 0;
}
int WN_SQL3PagerAcquire(Pager *pPager,Pgno pgno,DbPage **ppPage,int noContent)
{
	int rc;
	if(pgno>PAGER_MAX_PGNO || pgno==0 || pgno==PAGER_MJ_PGNO(pPager))return WN_SQL_CORRUPT_BKPT;
	*ppPage=0;
	if(pPager->errCode && pPager->errCode!=WN_SQL_FULL)return pPager->errCode;
	if(rc=pagerSharedLock(pPager))return rc;
	PgHdr *pPg=pager_lookup(pPager,pgno);
	if(pPg==0)
	{
		PAGER_INCR(pPager->nMiss);
		if(rc=pagerAllocatePage(pPager,&pPg))return rc;
		pPg->pgno=pgno;
		if(pPager->aInJournal &&(int)pgno<=pPager->origDbSize)
		{
			WN_SQL3CheckMemory(pPager->aInJournal,pgno/8);
			pPg->inJournal=(pPager->aInJournal[pgno/8] &(1<<(pgno&7)))!=0;
			pPg->needSync=0;
		}
		else
		{
			pPg->inJournal=0;
			pPg->needSync=0;
		}
		makeClean(pPg);
		pPg->nRef=1;
		REFINFO(pPg);
		pPager->nRef++;
		if(pPager->nExtra>0)memset(PGHDR_TO_EXTRA(pPg,pPager),0,pPager->nExtra);
		int nMax=WN_SQL3PagerPagecount(pPager);
		if(pPager->errCode)
		{
			WN_SQL3PagerUnref(pPg);
			return pPager->errCode;
		}
		if(nMax<(int)pgno || MEMDB ||(noContent && !pPager->alwaysRollback))
		{
			if(pgno>pPager->mxPgno)
			{
				WN_SQL3PagerUnref(pPg);
				return WN_SQL_FULL;
			}
			memset(PGHDR_TO_DATA(pPg),0,pPager->pageSize);
			pPg->needRead=noContent && !pPager->alwaysRollback;
			IOTRACE(("ZERO %p %d\n",pPager,pgno));
		}
		else
		{
			rc=readDbPage(pPager,pPg,pgno);
			if(rc && rc!=WN_SQL_IOERR_SHORT_READ)
			{
				pPg->pgno=0;
				WN_SQL3PagerUnref(pPg);
				return rc;
			}
			pPg->needRead=0;
		}
		int h=pgno &(pPager->nHash-1);
		pPg->pNextHash=pPager->aHash[h];
		pPager->aHash[h]=pPg;
		if(pPg->pNextHash)pPg->pNextHash->pPrevHash=pPg;
#ifdef WN_SQL_CHECK_PAGES
		pPg->pageHash=pager_pagehash(pPg);
#endif
	}
	else
	{
		PAGER_INCR(pPager->nHit);
		if((!noContent)&&(rc=pager_get_content(pPg)))return rc;
		page_ref(pPg);
	}
	*ppPage=pPg;
	return 0;
}
DbPage *WN_SQL3PagerLookup(Pager *pPager,Pgno pgno)
{
	if(pPager->state==PAGER_UNLOCK)return 0;
	if(pPager->errCode && pPager->errCode!=WN_SQL_FULL)return 0;
	PgHdr *pPg=pager_lookup(pPager,pgno);
	if(pPg==0)return 0;
	page_ref(pPg);
	return pPg;
}
int WN_SQL3PagerUnref(DbPage *pPg)
{
	pPg->nRef--;
	REFINFO(pPg);
	CHECK_PAGE(pPg);
	if(pPg->nRef==0)
	{
		Pager *pPager;
		pPager=pPg->pPager;
		pPg->pNextFree=0;
		pPg->pPrevFree=pPager->pLast;
		pPager->pLast=pPg;
		if(pPg->pPrevFree)
			pPg->pPrevFree->pNextFree=pPg;
		else
			pPager->pFirst=pPg;
		if(pPg->needSync==0 && pPager->pFirstSynced==0)
			pPager->pFirstSynced=pPg;
		if(pPager->xDestructor)pPager->xDestructor(pPg,pPager->pageSize);
		pPager->nRef--;
		if(pPager->nRef==0 &&(!pPager->exclusiveMode || pPager->journalOff>0))pagerUnlockAndRollback(pPager);
	}
	return 0;
}
int pager_open_journal(Pager *pPager)
{
	int rc;
	WN_SQL3PagerPagecount(pPager);
	pPager->aInJournal=WN_SQL3Malloc(pPager->dbSize/8+1);
	if(pPager->aInJournal==0)
	{
		rc=WN_SQL_NOMEM;
		goto failed_to_open_journal;
	}
	rc=WN_SQL3OsOpenExclusive(pPager->zJournal,&pPager->jfd,pPager->tempFile);
	pPager->journalOff=0;
	pPager->setMaster=0;
	pPager->journalHdr=0;
	if(rc)
	{
		if(rc==WN_SQL_NOMEM)WN_SQL3OsDelete(pPager->zJournal);
		goto failed_to_open_journal;
	}
	WN_SQL3OsSetFullSync(pPager->jfd,pPager->full_fsync);
	WN_SQL3OsSetFullSync(pPager->fd,pPager->full_fsync);
	WN_SQL3OsOpenDirectory(pPager->jfd,pPager->zDirectory);
	pPager->journalOpen=1;
	pPager->journalStarted=0;
	pPager->needSync=0;
	pPager->alwaysRollback=0;
	pPager->nRec=0;
	if(pPager->errCode)
	{
		rc=pPager->errCode;
		goto failed_to_open_journal;
	}
	pPager->origDbSize=pPager->dbSize;
	rc=writeJournalHdr(pPager);
	if(pPager->stmtAutoopen && rc==0)rc=WN_SQL3PagerStmtBegin(pPager);
	if(rc && rc!=WN_SQL_NOMEM &&(rc=pager_end_transaction(pPager))==0)rc=WN_SQL_FULL;
	return rc;
failed_to_open_journal:
	WN_SQL3FreeX(pPager->aInJournal);
	pPager->aInJournal=0;
	return rc;
}
int WN_SQL3PagerBegin(DbPage *pPg,int exFlag)
{
	Pager *pPager=pPg->pPager;
	int rc=0;
	if(pPager->state==PAGER_SHARED)
	{
		if(MEMDB)
		{
			pPager->state=PAGER_EXCLUSIVE;
			pPager->origDbSize=pPager->dbSize;
		}
		else
		{
			if((rc=WN_SQL3OsLock(pPager->fd,RESERVED_LOCK))==0)
			{
				pPager->state=PAGER_RESERVED;
				if(exFlag)rc=pager_wait_on_lock(pPager,EXCLUSIVE_LOCK);
			}
			if(rc)return rc;
			pPager->dirtyCache=0;
			PAGERTRACE2("TRANSACTION %d\n",PAGERID(pPager));
			if(pPager->useJournal && !pPager->tempFile)rc=pager_open_journal(pPager);
		}
	}
	else
		if(pPager->journalOpen && pPager->journalOff==0)
		{
			WN_SQL3PagerPagecount(pPager);
			pPager->aInJournal=WN_SQL3Malloc(pPager->dbSize/8+1);
			if(!pPager->aInJournal)
				rc=WN_SQL_NOMEM;
			else
			{
				pPager->origDbSize=pPager->dbSize;
				rc=writeJournalHdr(pPager);
			}
		}
		return rc;
}
void makeDirty(PgHdr *pPg)
{
	if(pPg->dirty==0)
	{
		Pager *pPager=pPg->pPager;
		pPg->dirty=1;
		pPg->pDirty=pPager->pDirty;
		if(pPager->pDirty)pPager->pDirty->pPrevDirty=pPg;
		pPg->pPrevDirty=0;
		pPager->pDirty=pPg;
	}
}
void makeClean(PgHdr *pPg)
{
	if(pPg->dirty)
	{
		pPg->dirty=0;
		if(pPg->pDirty)pPg->pDirty->pPrevDirty=pPg->pPrevDirty;
		if(pPg->pPrevDirty)
			pPg->pPrevDirty->pDirty=pPg->pDirty;
		else
			pPg->pPager->pDirty=pPg->pDirty;
	}
}
int pager_write(PgHdr *pPg)
{
	void *pData=PGHDR_TO_DATA(pPg);
	Pager *pPager=pPg->pPager;
	int rc=0;
	if(pPager->errCode)return pPager->errCode;
	if(pPager->readOnly)return WN_SQL_PERM;
	CHECK_PAGE(pPg);
	if(rc=pager_get_content(pPg))return rc;
	makeDirty(pPg);
	if(pPg->inJournal &&(pageInStatement(pPg)|| pPager->stmtInUse==0))
		pPager->dirtyCache=1;
	else
	{
		if(rc=WN_SQL3PagerBegin(pPg,0))return rc;
		if(!pPager->journalOpen && pPager->useJournal)
		{
			rc=pager_open_journal(pPager);
			if(rc)return rc;
		}
		pPager->dirtyCache=1;
		if(!pPg->inJournal &&(pPager->useJournal || MEMDB))
		{
			if((int)pPg->pgno<=pPager->origDbSize)
			{
				int szPg;
				if(MEMDB)
				{
					PgHistory *pHist=PGHDR_TO_HIST(pPg,pPager);
					PAGERTRACE3("JOURNAL %d page %d\n",PAGERID(pPager),pPg->pgno);
					pHist->pOrig=WN_SQLMallocRaw(pPager->pageSize);
					if(pHist->pOrig)memcpy(pHist->pOrig,PGHDR_TO_DATA(pPg),pPager->pageSize);
				}
				else
				{
					u32 cksum,saved;
					char *pData2,*pEnd;
					pData2=CODEC2(pPager,pData,pPg->pgno,7);
					cksum=pager_cksum(pPager,(u8*)pData2);
					pEnd=pData2+pPager->pageSize;
					pData2-=4;
					saved=*(u32*)pEnd;
					put32bits(pEnd,cksum);
					szPg=pPager->pageSize+8;
					put32bits(pData2,pPg->pgno);
					rc=WN_SQL3OsWrite(pPager->jfd,pData2,szPg);
					IOTRACE(("JOUT %p %d %lld %d\n",pPager,pPg->pgno,pPager->journalOff,szPg));
					PAGER_INCR(WN_SQL3_pager_writej_count);
					pPager->journalOff+=szPg;
					PAGERTRACE5("JOURNAL %d page %d needSync=%d hash(%08x)\n",PAGERID(pPager),pPg->pgno,pPg->needSync,pager_pagehash(pPg));
					*(u32*)pEnd=saved;
					if(rc)return rc;
					pPager->nRec++;
					pPager->aInJournal[pPg->pgno/8] |=1<<(pPg->pgno&7);
					pPg->needSync=!pPager->noSync;
					if(pPager->stmtInUse)pPager->aInStmt[pPg->pgno/8] |=1<<(pPg->pgno&7);
				}
			}
			else
			{
				pPg->needSync=!pPager->journalStarted && !pPager->noSync;
				PAGERTRACE4("APPEND %d page %d needSync=%d\n",PAGERID(pPager),pPg->pgno,pPg->needSync);
			}
			if(pPg->needSync)pPager->needSync=1;
			pPg->inJournal=1;
		}
		if(pPager->stmtInUse && !pageInStatement(pPg)&&(int)pPg->pgno<=pPager->stmtSize)
		{
			if(MEMDB)
			{
				PgHistory *pHist=PGHDR_TO_HIST(pPg,pPager);
				pHist->pStmt=WN_SQLMallocRaw(pPager->pageSize);
				if(pHist->pStmt)memcpy(pHist->pStmt,PGHDR_TO_DATA(pPg),pPager->pageSize);
				PAGERTRACE3("STMT-JOURNAL %d page %d\n",PAGERID(pPager),pPg->pgno);
				page_add_to_stmt_list(pPg);
			}
			else
			{
				char *pData2=CODEC2(pPager,pData,pPg->pgno,7)-4;
				put32bits(pData2,pPg->pgno);
				rc=WN_SQL3OsWrite(pPager->stfd,pData2,pPager->pageSize+4);
				PAGERTRACE3("STMT-JOURNAL %d page %d\n",PAGERID(pPager),pPg->pgno);
				if(rc)return rc;
				pPager->stmtNRec++;
				pPager->aInStmt[pPg->pgno/8] |=1<<(pPg->pgno&7);
			}
		}
	}
	if(pPager->dbSize<(int)pPg->pgno)
	{
		pPager->dbSize=pPg->pgno;
		if(!MEMDB && pPager->dbSize==PENDING_BYTE/pPager->pageSize)pPager->dbSize++;
	}
	return rc;
}
int WN_SQL3PagerWrite(DbPage *pDbPage)
{
	int rc=0;
	PgHdr *pPg=pDbPage;
	Pager *pPager=pPg->pPager;
	Pgno nPagePerSector=(pPager->sectorSize/pPager->pageSize);
	if(!MEMDB && nPagePerSector>1)
	{
		int nPage,ii;
		pPager->doNotSync=1;
		Pgno pg1=((pPg->pgno-1)& ~(nPagePerSector-1))+1;
		Pgno nPageCount=WN_SQL3PagerPagecount(pPager);
		if(pPg->pgno>nPageCount)
			nPage=(pPg->pgno-pg1)+1;
		else
			if((pg1+nPagePerSector-1)>nPageCount)
				nPage=nPageCount+1-pg1;
			else
				nPage=nPagePerSector;
		for(ii=0;ii<nPage && rc==0;ii++)
		{
			Pgno pg=pg1+ii;
			if(!pPager->aInJournal || pg==pPg->pgno || pg>pPager->origDbSize || !(pPager->aInJournal[pg/8]&(1<<(pg&7))))
				if(pg!=PAGER_MJ_PGNO(pPager))
				{
					PgHdr *pPage;
					if((rc=WN_SQL3PagerGet(pPager,pg,&pPage))==0)
					{
						rc=pager_write(pPage);
						WN_SQL3PagerUnref(pPage);
					}
				}
		}
		pPager->doNotSync=0;
	}
	else
		return pager_write(pDbPage);
	return rc;
}
#ifndef NDEBUG
int WN_SQL3PagerIswriteable(DbPage *pPg){
return pPg->dirty;
}
#endif
#ifndef WN_SQL_OMIT_VACUUM
int WN_SQL3PagerOverwrite(Pager *pPager,Pgno pgno,void *pData)
{
	PgHdr *pPg;
	int rc=WN_SQL3PagerGet(pPager,pgno,&pPg);
	if(rc==0)
	{
		if((rc=WN_SQL3PagerWrite(pPg))==0)memcpy(WN_SQL3PagerGetData(pPg),pData,pPager->pageSize);
		WN_SQL3PagerUnref(pPg);
	}
	return rc;
}
#endif
void WN_SQL3PagerDontWrite(DbPage *pDbPage)
{
	PgHdr *pPg=pDbPage;
	Pager *pPager=pPg->pPager;
	if(MEMDB)return;
	pPg->alwaysRollback=1;
	if(pPg->dirty && !pPager->stmtInUse)
	{
		if(pPager->dbSize==(int)pPg->pgno && pPager->origDbSize<pPager->dbSize)
		{
		}
		else
		{
			PAGERTRACE3("DONT_WRITE page %d of %d\n",pPg->pgno,PAGERID(pPager));
			IOTRACE(("CLEAN %p %d\n",pPager,pPg->pgno))
			makeClean(pPg);
#ifdef WN_SQL_CHECK_PAGES
			pPg->pageHash=pager_pagehash(pPg);
#endif
		}
	}
}
void WN_SQL3PagerDontRollback(DbPage *pPg)
{
	Pager *pPager=pPg->pPager;
	if(pPager->journalOpen==0)return;
	if(pPg->alwaysRollback || pPager->alwaysRollback || MEMDB)return;
	if(!pPg->inJournal &&(int)pPg->pgno<=pPager->origDbSize)
	{
		pPager->aInJournal[pPg->pgno/8] |=1<<(pPg->pgno&7);
		pPg->inJournal=1;
		pPg->needRead=0;
		if(pPager->stmtInUse)pPager->aInStmt[pPg->pgno/8] |=1<<(pPg->pgno&7);
		PAGERTRACE3("DONT_ROLLBACK page %d of %d\n",pPg->pgno,PAGERID(pPager));
		IOTRACE(("GARBAGE %p %d\n",pPager,pPg->pgno))
	}
	if(pPager->stmtInUse && !pageInStatement(pPg)&&(int)pPg->pgno<=pPager->stmtSize)pPager->aInStmt[pPg->pgno/8] |=1<<(pPg->pgno&7);
}
int pager_incr_changecounter(Pager *pPager)
{
	PgHdr *pPgHdr;
	u32 change_counter;
	int rc;
	if(!pPager->changeCountDone)
	{
		if(rc=WN_SQL3PagerGet(pPager,1,&pPgHdr))return rc;
		rc=WN_SQL3PagerWrite(pPgHdr);
		if(rc=WN_SQL3PagerWrite(pPgHdr))return rc;
		change_counter=WN_SQL3Get4byte((u8*)pPager->dbFileVers);
		change_counter++;
		put32bits(((char*)PGHDR_TO_DATA(pPgHdr))+24,change_counter);
		WN_SQL3PagerUnref(pPgHdr);
		pPager->changeCountDone=1;
	}
	return 0;
}
int WN_SQL3PagerCommitPhaseOne(Pager *pPager,const char *zMaster,Pgno nTrunc)
{
	int rc=0;
	PAGERTRACE4("DATABASE SYNC:File=%s zMaster=%s nTrunc=%d\n",pPager->zFilename,zMaster,nTrunc);
	if(pPager->state!=PAGER_SYNCED && !MEMDB && pPager->dirtyCache)
	{
		PgHdr *pPg;
		if(!pPager->setMaster)
		{
			if(rc=pager_incr_changecounter(pPager))goto sync_exit;
#ifndef WN_SQL_OMIT_AUTOVACUUM
			if(nTrunc){
				Pgno i;
				int iSkip=PAGER_MJ_PGNO(pPager);
				for(i=nTrunc+1;i<=pPager->origDbSize;i++)
					if(!(pPager->aInJournal[i/8] &(1<<(i&7)))&& i!=iSkip)
					{
						if(rc=WN_SQL3PagerGet(pPager,i,&pPg))goto sync_exit;
						rc=WN_SQL3PagerWrite(pPg);
						WN_SQL3PagerUnref(pPg);
						if(rc)goto sync_exit;
					}
			}
#endif
			if(rc=writeMasterJournal(pPager,zMaster))goto sync_exit;
			rc=syncJournal(pPager);
			if(rc=syncJournal(pPager))goto sync_exit;
		}
#ifndef WN_SQL_OMIT_AUTOVACUUM
		if(nTrunc && rc=WN_SQL3PagerTruncate(pPager,nTrunc))goto sync_exit;
#endif
		pPg=pager_get_all_dirty_pages(pPager);
		if(rc=pager_write_pagelist(pPg))goto sync_exit;
		pPager->pDirty=0;
		if(!pPager->noSync)rc=WN_SQL3OsSync(pPager->fd,0);
		IOTRACE(("DBSYNC %p\n",pPager))
		pPager->state=PAGER_SYNCED;
	}
	else
		if(MEMDB && nTrunc)rc=WN_SQL3PagerTruncate(pPager,nTrunc);
sync_exit:
	if(rc==WN_SQL_IOERR_BLOCKED)rc=WN_SQL_BUSY;
	return rc;
}
int WN_SQL3PagerCommitPhaseTwo(Pager *pPager)
{
	if(pPager->errCode)return pPager->errCode;
	int rc;
	PgHdr *pPg;
	if(pPager->state<PAGER_RESERVED)return WN_SQL_ERROR;
	PAGERTRACE2("COMMIT %d\n",PAGERID(pPager));
	if(MEMDB)
	{
		pPg=pager_get_all_dirty_pages(pPager);
		while(pPg)
		{
			PgHistory *pHist=PGHDR_TO_HIST(pPg,pPager);
			clearHistory(pHist);
			pPg->dirty=0;
			pPg->inJournal=0;
			pHist->inStmt=0;
			pPg->needSync=0;
			pHist->pPrevStmt=pHist->pNextStmt=0;
			pPg=pPg->pDirty;
		}
		pPager->pDirty=0;
#ifndef NDEBUG
		for(pPg=pPager->pAll;pPg;pPg=pPg->pNextAll)PgHistory *pHist=PGHDR_TO_HIST(pPg,pPager);
#endif
		pPager->pStmt=0;
		pPager->state=PAGER_SHARED;
		return 0;
	}
	return pager_error(pPager,pager_end_transaction(pPager));
}
int WN_SQL3PagerRollback(Pager *pPager)
{
	int rc;
	PAGERTRACE2("ROLLBACK %d\n",PAGERID(pPager));
	if(MEMDB)
	{
		PgHdr *p;
		for(p=pPager->pAll;p;p=p->pNextAll)
		{
			PgHistory *pHist;
			if(!p->dirty)continue;
			pHist=PGHDR_TO_HIST(p,pPager);
			if(pHist->pOrig)
			{
				memcpy(PGHDR_TO_DATA(p),pHist->pOrig,pPager->pageSize);
				PAGERTRACE3("ROLLBACK-PAGE %d of %d\n",p->pgno,PAGERID(pPager));
			}
			else
				PAGERTRACE3("PAGE %d is clean on %d\n",p->pgno,PAGERID(pPager));
			clearHistory(pHist);
			p->dirty=0;
			p->inJournal=0;
			pHist->inStmt=0;
			pHist->pPrevStmt=pHist->pNextStmt=0;
			if(pPager->xReiniter)pPager->xReiniter(p,pPager->pageSize);
		}
		pPager->pDirty=0;
		pPager->pStmt=0;
		pPager->dbSize=pPager->origDbSize;
		pager_truncate_cache(pPager);
		pPager->stmtInUse=0;
		pPager->state=PAGER_SHARED;
		return 0;
	}
	if(!pPager->dirtyCache || !pPager->journalOpen)	return pager_end_transaction(pPager);
	if(pPager->errCode && pPager->errCode!=WN_SQL_FULL)
	{
		if(pPager->state>=PAGER_EXCLUSIVE)pager_playback(pPager,0);
		return pPager->errCode;
	}
	if(pPager->state==PAGER_RESERVED)
	{
		rc=pager_playback(pPager,0);
		int rc2=pager_end_transaction(pPager);
		if(rc==0)rc=rc2;
	}
	else
		rc=pager_playback(pPager,0);
	pPager->dbSize=-1;
	return pager_error(pPager,rc);
}
int WN_SQL3PagerIsreadonly(Pager *pPager)
{
	return pPager->readOnly;
}
int WN_SQL3PagerRefcount(Pager *pPager)
{
	return pPager->nRef;
}
#ifdef WN_SQL_TEST
int *WN_SQL3PagerStats(Pager *pPager)
{
	int a[11];
	a[0]=pPager->nRef;
	a[1]=pPager->nPage;
	a[2]=pPager->mxPage;
	a[3]=pPager->dbSize;
	a[4]=pPager->state;
	a[5]=pPager->errCode;
	a[6]=pPager->nHit;
	a[7]=pPager->nMiss;
	a[8]=0;
	a[9]=pPager->nRead;
	a[10]=pPager->nWrite;
	return a;
}
#endif
int WN_SQL3PagerStmtBegin(Pager *pPager)
{
	int rc;
	PAGERTRACE2("STMT-BEGIN %d\n",PAGERID(pPager));
	if(MEMDB)
	{
		pPager->stmtInUse=1;
		pPager->stmtSize=pPager->dbSize;
		return 0;
	}
	if(!pPager->journalOpen)
	{
		pPager->stmtAutoopen=1;
		return 0;
	}
	pPager->aInStmt=WN_SQL3Malloc(pPager->dbSize/8+1);
	if(pPager->aInStmt==0)return WN_SQL_NOMEM;
#ifndef NDEBUG
	if(rc=WN_SQL3OsFileSize(pPager->jfd,&pPager->stmtJSize))goto stmt_begin_failed;
#endif
	pPager->stmtJSize=pPager->journalOff;
	pPager->stmtSize=pPager->dbSize;
	pPager->stmtHdrOff=0;
	pPager->stmtCksum=pPager->cksumInit;
	if(!pPager->stmtOpen)
	{
		if(rc=WN_SQL3PagerOpentemp(&pPager->stfd))goto stmt_begin_failed;
		pPager->stmtOpen=1;
		pPager->stmtNRec=0;
	}
	pPager->stmtInUse=1;
	return 0;
stmt_begin_failed:
	if(pPager->aInStmt)
	{
		WN_SQL3FreeX(pPager->aInStmt);
		pPager->aInStmt=0;
	}
	return rc;
}
int WN_SQL3PagerStmtCommit(Pager *pPager)
{
	if(pPager->stmtInUse)
	{
		PgHdr *pPg,*pNext;
		PAGERTRACE2("STMT-COMMIT %d\n",PAGERID(pPager));
		if(!MEMDB)
		{
			WN_SQL3OsSeek(pPager->stfd,0);
			WN_SQL3FreeX(pPager->aInStmt);
			pPager->aInStmt=0;
		}
		else
			for(pPg=pPager->pStmt;pPg;pPg=pNext)
			{
				PgHistory *pHist=PGHDR_TO_HIST(pPg,pPager);
				pNext=pHist->pNextStmt;
				pHist->inStmt=0;
				pHist->pPrevStmt=pHist->pNextStmt=0;
				WN_SQL3FreeX(pHist->pStmt);
				pHist->pStmt=0;
			}
		pPager->stmtNRec=0;
		pPager->stmtInUse=0;
		pPager->pStmt=0;
	}
	pPager->stmtAutoopen=0;
	return 0;
}
int WN_SQL3PagerStmtRollback(Pager *pPager)
{
	int rc;
	if(pPager->stmtInUse)
	{
		PAGERTRACE2("STMT-ROLLBACK %d\n",PAGERID(pPager));
		if(MEMDB)
		{
			PgHdr *pPg;
			PgHistory *pHist;
			for(pPg=pPager->pStmt;pPg;pPg=pHist->pNextStmt)
			{
				pHist=PGHDR_TO_HIST(pPg,pPager);
				if(pHist->pStmt)
				{
					memcpy(PGHDR_TO_DATA(pPg),pHist->pStmt,pPager->pageSize);
					WN_SQL3FreeX(pHist->pStmt);
					pHist->pStmt=0;
				}
			}
			pPager->dbSize=pPager->stmtSize;
			pager_truncate_cache(pPager);
			rc=0;
		}
		else
			rc=pager_stmt_playback(pPager);
		WN_SQL3PagerStmtCommit(pPager);
	}
	else
		rc=0;
	pPager->stmtAutoopen=0;
	return rc;
}
const char *WN_SQL3PagerFilename(Pager *pPager)
{
	return pPager->zFilename;
}
const char *WN_SQL3PagerDirname(Pager *pPager)
{
	return pPager->zDirectory;
}
const char *WN_SQL3PagerJournalname(Pager *pPager)
{
	return pPager->zJournal;
}
int WN_SQL3PagerNosync(Pager *pPager)
{
	return pPager->noSync;
}
#ifdef WN_SQL_HAS_CODEC
void WN_SQL3PagerSetCodec(Pager *pPager,void *(*xCodec)(void*,void*,Pgno,int),void *pCodecArg)
{
	pPager->xCodec=xCodec;
	pPager->pCodecArg=pCodecArg;
}
#endif
#ifndef WN_SQL_OMIT_AUTOVACUUM
int WN_SQL3PagerMovepage(Pager *pPager,DbPage *pPg,Pgno pgno)
{
	PgHdr *pPgOld;
	int h;
	Pgno needSyncPgno=0;
	PAGERTRACE5("MOVE %d page %d(needSync=%d)moves to %d\n",PAGERID(pPager),pPg->pgno,pPg->needSync,pgno);
	IOTRACE(("MOVE %p %d %d\n",pPager,pPg->pgno,pgno))
	pager_get_content(pPg);
	if(pPg->needSync)needSyncPgno=pPg->pgno;
	unlinkHashChain(pPager,pPg);
	pPg->needSync=0;
	pPgOld=pager_lookup(pPager,pgno);
	if(pPgOld)
	{
		unlinkHashChain(pPager,pPgOld);
		makeClean(pPgOld);
		pPg->needSync=pPgOld->needSync;
	}
	else
		pPg->needSync=0;
	if(pPager->aInJournal &&(int)pgno<=pPager->origDbSize)
		pPg->inJournal=(pPager->aInJournal[pgno/8] &(1<<(pgno&7)))!=0;
	else
		pPg->inJournal=0;
	pPg->pgno=pgno;
	h=pgno &(pPager->nHash-1);
	if(pPager->aHash[h])pPager->aHash[h]->pPrevHash=pPg;
	pPg->pNextHash=pPager->aHash[h];
	pPager->aHash[h]=pPg;
	pPg->pPrevHash=0;
	makeDirty(pPg);
	pPager->dirtyCache=1;
	if(needSyncPgno)
	{
		PgHdr *pPgHdr;
		int rc=WN_SQL3PagerGet(pPager,needSyncPgno,&pPgHdr);
		if(rc)return rc;
		pPager->needSync=1;
		pPgHdr->needSync=1;
		pPgHdr->inJournal=1;
		makeDirty(pPgHdr);
		WN_SQL3PagerUnref(pPgHdr);
	}
	return 0;
}
#endif
void *WN_SQL3PagerGetData(DbPage *pPg)
{
	return PGHDR_TO_DATA(pPg);
}
void *WN_SQL3PagerGetExtra(DbPage *pPg)
{
	Pager *pPager=pPg->pPager;
	return(pPager?PGHDR_TO_EXTRA(pPg,pPager):0);
}
int WN_SQL3PagerLockingMode(Pager *pPager,int eMode)
{
	if(eMode>=0 && !pPager->tempFile)pPager->exclusiveMode=eMode;
	return(int)pPager->exclusiveMode;
}
#if defined(WN_SQL_DEBUG)|| defined(WN_SQL_TEST)
int WN_SQL3PagerLockstate(Pager *pPager)
{
	return WN_SQL3OsLockState(pPager->fd);
}
#endif
#ifdef WN_SQL_DEBUG
void WN_SQL3PagerRefdump(Pager *pPager)
{
	PgHdr *pPg;
	for(pPg=pPager->pAll;pPg;pPg=pPg->pNextAll)
	{
		if(pPg->nRef<=0)continue;
		WN_SQL3DebugPrintf("PAGE %3d addr=%p nRef=%d\n",pPg->pgno,PGHDR_TO_DATA(pPg),pPg->nRef);
	}
}
#endif
#endif
#define ROUND8(x)((x+7)&~7)
#define MX_CELL_SIZE(pBt)(pBt->pageSize-8)
#define MX_CELL(pBt)((pBt->pageSize-8)/3)
typedef struct MemPage MemPage;
typedef struct BtLock BtLock;
#ifndef WN_SQL_FILE_HEADER
# define WN_SQL_FILE_HEADER "WN_SQL format 3"
#endif
#define PTF_INTKEY 0x01
#define PTF_ZERODATA 0x02
#define PTF_LEAFDATA 0x04
#define PTF_LEAF 0x08
struct MemPage
{
	u8 isInit,idxShift,nOverflow,intKey,leaf,zeroData,leafData,hasData,hdrOffset,childPtrSize;
	u16 maxLocal,minLocal,cellOffset,idxParent,nFree,nCell;
	struct _OvflCell
	{
		u8 *pCell;
		u16 idx;
	}aOvfl[5];
	BtShared *pBt;
	u8 *aData;
	DbPage *pDbPage;
	Pgno pgno;
	MemPage *pParent;
};
#define EXTRA_SIZE sizeof(MemPage)
struct Btree
{
	WN_SQL3 *pWN_SQL;
	BtShared *pBt;
	u8 inTrans;
};
#define TRANS_NONE 0
#define TRANS_READ 1
#define TRANS_WRITE 2
struct BtShared
{
	Pager *pPager;
	BtCursor *pCursor;
	MemPage *pPage1;
	u8 inStmt,readOnly,maxEmbedFrac,minEmbedFrac,minLeafFrac,pageSizeFixed;
#ifndef WN_SQL_OMIT_AUTOVACUUM
	u8 autoVacuum,incrVacuum;
	Pgno nTrunc;
#endif
	u16 pageSize,usableSize;
	int maxLocal,minLocal,maxLeaf,minLeaf;
	BusyHandler *pBusyHandler;
	u8 inTransaction;
	int nRef,nTransaction;
	void *pSchema;
	void(*xFreeSchema)(void*);
#ifndef WN_SQL_OMIT_SHARED_CACHE
	BtLock *pLock;
	BtShared *pNext;
#endif
};
typedef struct CellInfo CellInfo;
struct CellInfo {
	u8 *pCell;
	i64 nKey;
	u32 nData,nPayload;
	u16 nHeader,nLocal,iOverflow,nSize;
};
struct BtCursor
{
	Btree *pBtree;
	BtCursor *pNext,*pPrev;
	int(*xCompare)(void*,int,const void*,int,const void*);
	void *pArg;
	Pgno pgnoRoot;
	MemPage *pPage;
	int idx;
	CellInfo info;
	u8 wrFlag,eState;
	void *pKey;
	i64 nKey;
	int skip;
#ifndef WN_SQL_OMIT_INCRBLOB
	u8 isIncrblobHandle;
	Pgno *aOverflow;
#endif
};
#define CURSOR_INVALID 0
#define CURSOR_VALID 1
#define CURSOR_REQUIRESEEK 2
#if WN_SQL_TEST
# define TRACE(X)if(WN_SQL3_btree_trace){printf X;fflush(stdout);}
#else
# define TRACE(X)
#endif
#define getVarint WN_SQL3GetVarint
#define getVarint32(A,B)((*B=*(A))<=0x7f?1:WN_SQL3GetVarint32(A,B))
#define putVarint WN_SQL3PutVarint
#ifdef WN_SQL_OMIT_DISKIO
# define PENDING_BYTE_PAGE(pBt)0x7fffffff
#else
# define PENDING_BYTE_PAGE(pBt)((PENDING_BYTE/(pBt)->pageSize)+1)
#endif
struct BtLock
{
	tree *pBtree;
	Pgno iTable;
	8 eLock;
	BtLock *pNext;
};
#define READ_LOCK 1
#define WRITE_LOCK 2
#define PTRMAP_PAGENO(pBt,pgno)ptrmapPageno(pBt,pgno)
#define PTRMAP_PTROFFSET(pBt,pgno)(5*(pgno-ptrmapPageno(pBt,pgno)-1))
#define PTRMAP_ISPAGE(pBt,pgno)(PTRMAP_PAGENO((pBt),(pgno))==(pgno))
#define PTRMAP_ROOTPAGE 1
#define PTRMAP_FREEPAGE 2
#define PTRMAP_OVERFLOW1 3
#define PTRMAP_OVERFLOW2 4
#define PTRMAP_BTREE 5
#define btreeIntegrity(p)\
#ifndef WN_SQL_OMIT_AUTOVACUUM
#define ISAUTOVACUUM(pBt->autoVacuum)
#else
#define ISAUTOVACUUM 0
#endif
typedef struct IntegrityCk IntegrityCk;
struct IntegrityCk
{
	BtShared *pBt;
	Pager *pPager;
	int nPage,*anRef,mxErr;
	char *zErrMsg;
	int nErr;
};
#define get2byte(x)((x)[0]<<8 |(x)[1])
#define put2byte(p,v)((p)[0]=(v)>>8,(p)[1]=(v))
#define get4byte WN_SQL3Get4byte
#define put4byte WN_SQL3Put4byte
const char zMagicHeader[]=WN_SQL_FILE_HEADER;
#if WN_SQL_TEST
int WN_SQL3_btree_trace=0;
#endif
int checkReadLocks(Btree*,Pgno,BtCursor*);
#ifdef WN_SQL_OMIT_SHARED_CACHE
#define queryTableLock(a,b,c)0
#define lockTable(a,b,c)0
#define unlockAllTables(a)
#else
int queryTableLock(Btree *p,Pgno iTab,u8 eLock)
{
	BtShared *pBt=p->pBt;
	BtLock *pIter;
	if(0==WN_SQL3ThreadDataReadOnly()->useSharedData)return 0;
	if(!p->pWN_SQL || 0==(p->pWN_SQL->flags&WN_SQL_ReadUncommitted)|| eLock==WRITE_LOCK || iTab==MASTER_ROOT)
		for(pIter=pBt->pLock;pIter;pIter=pIter->pNext)
			if(pIter->pBtree!=p && pIter->iTable==iTab &&(pIter->eLock!=eLock || eLock!=READ_LOCK))return WN_SQL_LOCKED;
	return 0;
}
int lockTable(Btree *p,Pgno iTable,u8 eLock)
{
	BtShared *pBt=p->pBt;
	BtLock *pLock=0,*pIter;
	if(0==WN_SQL3ThreadDataReadOnly()->useSharedData)return 0;
		if((p->pWN_SQL)&&(p->pWN_SQL->flags&WN_SQL_ReadUncommitted)&&
		(eLock==READ_LOCK)&& iTable!=MASTER_ROOT)return 0;
	for(pIter=pBt->pLock;pIter;pIter=pIter->pNext)
		if(pIter->iTable==iTable && pIter->pBtree==p)
		{
			pLock=pIter;
			break;
		}
	if(!pLock)
	{
		pLock=(BtLock *)WN_SQL3Malloc(sizeof(BtLock));
		if(!pLock)return WN_SQL_NOMEM;
		pLock->iTable=iTable;
		pLock->pBtree=p;
		pLock->pNext=pBt->pLock;
		pBt->pLock=pLock;
	}
		if(eLock>pLock->eLock)pLock->eLock=eLock;
	return 0;
}
void unlockAllTables(Btree *p)
{
	BtLock **ppIter=&p->pBt->pLock;
		while(*ppIter)
	{
		BtLock *pLock=*ppIter;
		if(pLock->pBtree==p)
		{
			*ppIter=pLock->pNext;
			WN_SQL3FreeX(pLock);
		}
		else
			ppIter=&pLock->pNext;
	}
}
#endif
#ifndef WN_SQL_OMIT_INCRBLOB
void invalidateOverflowCache(BtCursor *pCur)
{
	WN_SQL3FreeX(pCur->aOverflow);
	pCur->aOverflow=0;
}
void invalidateAllOverflowCache(BtShared *pBt)
{
	BtCursor *p;
	for(p=pBt->pCursor;p;p=p->pNext)invalidateOverflowCache(p);
}
#else
#define invalidateOverflowCache(x)
#define invalidateAllOverflowCache(x)
#endif
int saveCursorPosition(BtCursor *pCur)
{
	int rc;
			rc=WN_SQL3BtreeKeySize(pCur,&pCur->nKey);
	if(rc==0 && 0==pCur->pPage->intKey)
	{
		void *pKey=WN_SQL3Malloc(pCur->nKey);
		if(pKey)
		{
			rc=WN_SQL3BtreeKey(pCur,0,pCur->nKey,pKey);
			if(rc==0)
				pCur->pKey=pKey;
			else
				WN_SQL3FreeX(pKey);
		}
		else
			rc=WN_SQL_NOMEM;
	}
		if(rc==0)
	{
		releasePage(pCur->pPage);
		pCur->pPage=0;
		pCur->eState=CURSOR_REQUIRESEEK;
	}
	invalidateOverflowCache(pCur);
	return rc;
}
int saveAllCursors(BtShared *pBt,Pgno iRoot,BtCursor *pExcept)
{
	BtCursor *p;
	for(p=pBt->pCursor;p;p=p->pNext)
		if(p!=pExcept &&(0==iRoot || p->pgnoRoot==iRoot)&& p->eState==CURSOR_VALID)
		{
			int rc=saveCursorPosition(p);
			if(rc)return rc;
		}
	return 0;
}
void clearCursorPosition(BtCursor *pCur)
{
	WN_SQL3FreeX(pCur->pKey);
	pCur->pKey=0;
	pCur->eState=CURSOR_INVALID;
}
int WN_SQL3BtreeRestoreOrClearCursorPosition(BtCursor *pCur)
{
	int rc;
	#ifndef WN_SQL_OMIT_INCRBLOB
	if(pCur->isIncrblobHandle)return WN_SQL_ABORT;
#endif
	pCur->eState=CURSOR_INVALID;
	rc=WN_SQL3BtreeMoveto(pCur,pCur->pKey,pCur->nKey,0,&pCur->skip);
	if(rc==0)
	{
		WN_SQL3FreeX(pCur->pKey);
		pCur->pKey=0;
			}
	return rc;
}
#define restoreOrClearCursorPosition(p)\
(p->eState==CURSOR_REQUIRESEEK ? \
WN_SQL3BtreeRestoreOrClearCursorPosition(p):\
0)
#ifndef WN_SQL_OMIT_AUTOVACUUM
Pgno ptrmapPageno(BtShared *pBt,Pgno pgno)
{
	int nPagesPerMapPage=(pBt->usableSize/5)+1,iPtrMap=(pgno-2)/nPagesPerMapPage,
		ret=(iPtrMap*nPagesPerMapPage)+2;
	if(ret==PENDING_BYTE_PAGE(pBt))ret++;
	return ret;
}
int ptrmapPut(BtShared *pBt,Pgno key,u8 eType,Pgno parent)
{
	DbPage *pDbPage;
	u8 *pPtrmap;
	Pgno iPtrmap;
	int offset,rc;
			if(key==0)return WN_SQL_CORRUPT_BKPT;
	iPtrmap=PTRMAP_PAGENO(pBt,key);
	rc=WN_SQL3PagerGet(pBt->pPager,iPtrmap,&pDbPage);
	if(rc)return rc;
	offset=PTRMAP_PTROFFSET(pBt,key);
	pPtrmap=(u8 *)WN_SQL3PagerGetData(pDbPage);
	if(eType!=pPtrmap[offset] || get4byte(&pPtrmap[offset+1])!=parent)
	{
		TRACE(("PTRMAP_UPDATE:%d->(%d,%d)\n",key,eType,parent));
		rc=WN_SQL3PagerWrite(pDbPage);
		if(rc==0)
		{
			pPtrmap[offset]=eType;
			put4byte(&pPtrmap[offset+1],parent);
		}
	}
	WN_SQL3PagerUnref(pDbPage);
	return rc;
}
int ptrmapGet(BtShared *pBt,Pgno key,u8 *pEType,Pgno *pPgno)
{
	DbPage *pDbPage;
	int iPtrmap,offset,rc;
	u8 *pPtrmap;
	iPtrmap=PTRMAP_PAGENO(pBt,key);
	rc=WN_SQL3PagerGet(pBt->pPager,iPtrmap,&pDbPage);
	if(rc)return rc;
	pPtrmap=(u8 *)WN_SQL3PagerGetData(pDbPage);
	offset=PTRMAP_PTROFFSET(pBt,key);
		*pEType=pPtrmap[offset];
	if(pPgno)*pPgno=get4byte(&pPtrmap[offset+1]);
	WN_SQL3PagerUnref(pDbPage);
	if(*pEType<1 || *pEType>5)return WN_SQL_CORRUPT_BKPT;
	return 0;
}
#endif
#define findCell(pPage,iCell)\
((pPage)->aData+get2byte(&(pPage)->aData[(pPage)->cellOffset+2*(iCell)]))
u8 *WN_SQL3BtreeFindCell(MemPage *pPage,int iCell)
{
			return findCell(pPage,iCell);
}
u8 *findOverflowCell(MemPage *pPage,int iCell)
{
	int i;
	for(i=pPage->nOverflow-1;i>=0;i--)
	{
		int k;
		struct _OvflCell *pOvfl;
		pOvfl=&pPage->aOvfl[i];
		k=pOvfl->idx;
		if(k<=iCell)
		{
			if(k==iCell)return pOvfl->pCell;
			iCell--;
		}
	}
	return findCell(pPage,iCell);
}
void WN_SQL3BtreeParseCellPtr(MemPage *pPage,u8 *pCell,CellInfo *pInfo)
{
	int n=pPage->childPtrSize;
	32 nPayload;
	pInfo->pCell=pCell;
	if(pPage->hasData)
		n+=getVarint32(&pCell[n],&nPayload);
	else
		nPayload=0;
	pInfo->nData=nPayload;
	if(pPage->intKey)
		n+=getVarint(&pCell[n],(u64 *)&pInfo->nKey);
	else
	{
		u32 x;
		n+=getVarint32(&pCell[n],&x);
		pInfo->nKey=x;
		nPayload+=x;
	}
	pInfo->nPayload=nPayload;
	pInfo->nHeader=n;
	if(nPayload<=pPage->maxLocal)
	{
		int nSize;
		pInfo->nLocal=nPayload;
		pInfo->iOverflow=0;
		nSize=nPayload+n;
		if(nSize<4)nSize=4;
		pInfo->nSize=nSize;
	}
	else
	{
		int minLocal,maxLocal,surplus;
		minLocal=pPage->minLocal;
		maxLocal=pPage->maxLocal;
		surplus=minLocal+(nPayload-minLocal)%(pPage->pBt->usableSize-4);
		if(surplus<=maxLocal)
			pInfo->nLocal=surplus;
		else
			pInfo->nLocal=minLocal;
		pInfo->iOverflow=pInfo->nLocal+n;
		pInfo->nSize=pInfo->iOverflow+4;
	}
}
#define parseCell(pPage,iCell,pInfo)\
WN_SQL3BtreeParseCellPtr((pPage),findCell((pPage),(iCell)),(pInfo))
void WN_SQL3BtreeParseCell(MemPage *pPage,int iCell,CellInfo *pInfo)
{
	parseCell(pPage,iCell,pInfo);
}
#ifndef NDEBUG
int cellSize(MemPage *pPage,int iCell)
{
	CellInfo info;
	WN_SQL3BtreeParseCell(pPage,iCell,&info);
	return info.nSize;
}
#endif
int cellSizePtr(MemPage *pPage,u8 *pCell)
{
	CellInfo info;
	WN_SQL3BtreeParseCellPtr(pPage,pCell,&info);
	return info.nSize;
}
#ifndef WN_SQL_OMIT_AUTOVACUUM
int ptrmapPutOvflPtr(MemPage *pPage,u8 *pCell)
{
	if(pCell)
	{
		CellInfo info;
		WN_SQL3BtreeParseCellPtr(pPage,pCell,&info);
				if((info.nData+(pPage->intKey?0:info.nKey))>info.nLocal)
		{
			Pgno ovfl=get4byte(&pCell[info.iOverflow]);
			return ptrmapPut(pPage->pBt,ovfl,PTRMAP_OVERFLOW1,pPage->pgno);
		}
	}
	return 0;
}
int ptrmapPutOvfl(MemPage *pPage,int iCell){
u8 *pCell;
pCell=findOverflowCell(pPage,iCell);
return ptrmapPutOvflPtr(pPage,pCell);
}
#endif
int defragmentPage(MemPage *pPage)
{
	int i,pc,addr,hdr,size,usableSize,cellOffset,brk,nCell;
	unsigned char *data,*temp;
					temp=WN_SQL3Malloc(pPage->pBt->pageSize);
	if(temp==0)return WN_SQL_NOMEM;
	data=pPage->aData;
	hdr=pPage->hdrOffset;
	cellOffset=pPage->cellOffset;
	nCell=pPage->nCell;
		usableSize=pPage->pBt->usableSize;
	brk=get2byte(&data[hdr+5]);
	memcpy(&temp[brk],&data[brk],usableSize-brk);
	brk=usableSize;
	for(i=0;i<nCell;i++)
	{
		u8 *pAddr;
		pAddr=&data[cellOffset+i*2];
		pc=get2byte(pAddr);
				size=cellSizePtr(pPage,&temp[pc]);
		brk-=size;
		memcpy(&data[brk],&temp[pc],size);
		put2byte(pAddr,brk);
	}
		put2byte(&data[hdr+5],brk);
	data[hdr+1]=0;
	data[hdr+2]=0;
	data[hdr+7]=0;
	addr=cellOffset+2*nCell;
	memset(&data[addr],0,brk-addr);
	WN_SQL3FreeX(temp);
	return 0;
}
int allocateSpace(MemPage *pPage,int nByte)
{
	int addr,pc,size,top,nCell,cellOffset;
	unsigned char *data=pPage->aData;
	if(nByte<4)nByte=4;
	if(pPage->nFree<nByte || pPage->nOverflow>0)return 0;
	pPage->nFree-=nByte;
	int hdr=pPage->hdrOffset;
	int nFrag=data[hdr+7];
	if(nFrag<60)
	{
		addr=hdr+1;
		while((pc=get2byte(&data[addr]))>0)
		{
			size=get2byte(&data[pc+2]);
			if(size>=nByte)
			{
				if(size<nByte+4)
				{
					memcpy(&data[addr],&data[pc],2);
					data[hdr+7]=nFrag+size-nByte;
					return pc;
				}
				else
				{
					put2byte(&data[pc+2],size-nByte);
					return pc+size-nByte;
				}
			}
			addr=pc;
		}
	}
	top=get2byte(&data[hdr+5]);
	nCell=get2byte(&data[hdr+3]);
	cellOffset=pPage->cellOffset;
	if(nFrag>=60 || cellOffset+2*nCell > top-nByte)
	{
		if(defragmentPage(pPage))return 0;
		top=get2byte(&data[hdr+5]);
	}
	top-=nByte;
	put2byte(&data[hdr+5],top);
	return top;
}
void freeSpace(MemPage *pPage,int start,int size)
{
	int addr,pbegin,hdr;
	unsigned char *data=pPage->aData;
	if(size<4)size=4;
#ifdef WN_SQL_SECURE_DELETE
	memset(&data[start],0,size);
#endif
	hdr=pPage->hdrOffset;
	addr=hdr+1;
	while((pbegin=get2byte(&data[addr]))<start && pbegin>0)addr=pbegin;
	put2byte(&data[addr],start);
	put2byte(&data[start],pbegin);
	put2byte(&data[start+2],size);
	pPage->nFree+=size;
	addr=pPage->hdrOffset+1;
	while((pbegin=get2byte(&data[addr]))>0)
	{
		int pnext,psize;
		pnext=get2byte(&data[pbegin]);
		psize=get2byte(&data[pbegin+2]);
		if(pbegin+psize+3 >=pnext && pnext>0)
		{
			int frag=pnext-(pbegin+psize);
			data[pPage->hdrOffset+7]-=frag;
			put2byte(&data[pbegin],get2byte(&data[pnext]));
			put2byte(&data[pbegin+2],pnext+get2byte(&data[pnext+2])-pbegin);
		}
		else
			addr=pbegin;
	}
	if(data[hdr+1]==data[hdr+5] && data[hdr+2]==data[hdr+6])
	{
		int top;
		pbegin=get2byte(&data[hdr+1]);
		memcpy(&data[hdr+1],&data[pbegin],2);
		top=get2byte(&data[hdr+5]);
		put2byte(&data[hdr+5],top+get2byte(&data[pbegin+2]));
	}
}
void decodeFlags(MemPage *pPage,int flagByte)
{
	BtShared *pBt;
	pPage->intKey=(flagByte &(PTF_INTKEY|PTF_LEAFDATA))!=0;
	pPage->zeroData=(flagByte & PTF_ZERODATA)!=0;
	pPage->leaf=(flagByte & PTF_LEAF)!=0;
	pPage->childPtrSize=4*(pPage->leaf==0);
	pBt=pPage->pBt;
	if(flagByte & PTF_LEAFDATA)
	{
		pPage->leafData=1;
		pPage->maxLocal=pBt->maxLeaf;
		pPage->minLocal=pBt->minLeaf;
	}
	else
	{
		pPage->leafData=0;
		pPage->maxLocal=pBt->maxLocal;
		pPage->minLocal=pBt->minLocal;
	}
	pPage->hasData=!(pPage->zeroData ||(!pPage->leaf && pPage->leafData));
}
int WN_SQL3BtreeInitPage(MemPage *pPage,MemPage *pParent)
{
	int pc,hdr;
	u8 *data;
	BtShared *pBt=pPage->pBt;
	int usableSize,cellOffset,nFree,top;
	if(pPage->pParent!=pParent &&(pPage->pParent || pPage->isInit))return WN_SQL_CORRUPT_BKPT;
	if(pPage->isInit)return 0;
	if(pPage->pParent==0 && pParent)
	{
		pPage->pParent=pParent;
		WN_SQL3PagerRef(pParent->pDbPage);
	}
	hdr=pPage->hdrOffset;
	data=pPage->aData;
	decodeFlags(pPage,data[hdr]);
	pPage->nOverflow=0;
	pPage->idxShift=0;
	usableSize=pBt->usableSize;
	pPage->cellOffset=cellOffset=hdr+12-4*pPage->leaf;
	top=get2byte(&data[hdr+5]);
	pPage->nCell=get2byte(&data[hdr+3]);
	if(pPage->nCell>MX_CELL(pBt))return WN_SQL_CORRUPT_BKPT;
	if(pPage->nCell==0 && pParent && pParent->pgno!=1)return WN_SQL_CORRUPT_BKPT;
	pc=get2byte(&data[hdr+1]);
	nFree=data[hdr+7]+top-(cellOffset+2*pPage->nCell);
	while(pc>0)
	{
		int next,size;
		if(pc>usableSize-4)return WN_SQL_CORRUPT_BKPT;
		next=get2byte(&data[pc]);
		size=get2byte(&data[pc+2]);
		if(next>0 && next<=pc+size+3)return WN_SQL_CORRUPT_BKPT;
		nFree+=size;
		pc=next;
	}
	pPage->nFree=nFree;
	if(nFree>=usableSize)return WN_SQL_CORRUPT_BKPT;
	pPage->isInit=1;
	return 0;
}
void zeroPage(MemPage *pPage,int flags)
{
	unsigned char *data=pPage->aData;
	BtShared *pBt=pPage->pBt;
	int hdr=pPage->hdrOffset;
	memset(&data[hdr],0,pBt->usableSize-hdr);
	data[hdr]=flags;
	int first=hdr+8+4*((flags&PTF_LEAF)==0);
	memset(&data[hdr+1],0,4);
	data[hdr+7]=0;
	put2byte(&data[hdr+5],pBt->usableSize);
	pPage->nFree=pBt->usableSize-first;
	decodeFlags(pPage,flags);
	pPage->hdrOffset=hdr;
	pPage->cellOffset=first;
	pPage->nOverflow=0;
	pPage->idxShift=0;
	pPage->nCell=0;
	pPage->isInit=1;
}
int WN_SQL3BtreeGetPage(BtShared *pBt,Pgno pgno,MemPage **ppPage,int noContent)
{
	DbPage *pDbPage;
	int rc=WN_SQL3PagerAcquire(pBt->pPager,pgno,(DbPage**)&pDbPage,noContent);
	if(rc)return rc;
	MemPage *pPage=(MemPage *)WN_SQL3PagerGetExtra(pDbPage);
	pPage->aData=WN_SQL3PagerGetData(pDbPage);
	pPage->pDbPage=pDbPage;
	pPage->pBt=pBt;
	pPage->pgno=pgno;
	pPage->hdrOffset=pPage->pgno==1 ? 100 :0;
	*ppPage=pPage;
	return 0;
}
int getAndInitPage(BtShared *pBt,Pgno pgno,MemPage **ppPage,MemPage *pParent)
{
	int rc;
	if(pgno==0)return WN_SQL_CORRUPT_BKPT;
	rc=WN_SQL3BtreeGetPage(pBt,pgno,ppPage,0);
	if(rc==0 &&(*ppPage)->isInit==0)return WN_SQL3BtreeInitPage(*ppPage,pParent);
	return rc;
}
void releasePage(MemPage *pPage)
{
	if(pPage)WN_SQL3PagerUnref(pPage->pDbPage);
}
void pageDestructor(DbPage *pData,int pageSize)
{
	MemPage *pPage;
	pPage=(MemPage *)WN_SQL3PagerGetExtra(pData);
	if(pPage->pParent)
	{
		MemPage *pParent=pPage->pParent;
		pPage->pParent=0;
		releasePage(pParent);
	}
	pPage->isInit=0;
}
void pageReinit(DbPage *pData,int pageSize)
{
	MemPage *pPage;
	pPage=(MemPage *)WN_SQL3PagerGetExtra(pData);
	if(pPage->isInit)
	{
		pPage->isInit=0;
		WN_SQL3BtreeInitPage(pPage,pPage->pParent);
	}
}
int WN_SQL3BtreeOpen(const char *zFilename,WN_SQL3 *pWN_SQL,Btree **ppBtree,int flags)
{
	BtShared *pBt;
	Btree *p;
	int rc=0,nReserve;
	unsigned char zDbHeader[100];
#if !defined(WN_SQL_OMIT_SHARED_CACHE)&& !defined(WN_SQL_OMIT_DISKIO)
	const ThreadData *pTsdro;
#endif
#if !defined(WN_SQL_OMIT_SHARED_CACHE)|| !defined(WN_SQL_OMIT_AUTOVACUUM)
#ifdef WN_SQL_OMIT_MEMORYDB
	const int isMemdb=0;
#else
	const int isMemdb=zFilename && !strcmp(zFilename,":memory:");
#endif
#endif
	p=WN_SQL3Malloc(sizeof(Btree));
	if(!p)return WN_SQL_NOMEM;
	p->inTrans=TRANS_NONE;
	p->pWN_SQL=pWN_SQL;
#if !defined(WN_SQL_OMIT_SHARED_CACHE)&& !defined(WN_SQL_OMIT_DISKIO)
	pTsdro=WN_SQL3ThreadDataReadOnly();
	if(pTsdro->useSharedData && zFilename && !isMemdb)
	{
		char *zFullPathname=WN_SQL3OsFullPathname(zFilename);
		if(!zFullPathname)
		{
			WN_SQL3FreeX(p);
			return WN_SQL_NOMEM;
		}
		for(pBt=pTsdro->pBtree;pBt;pBt=pBt->pNext)
			if(0==strcmp(zFullPathname,WN_SQL3PagerFilename(pBt->pPager)))
			{
				p->pBt=pBt;
				*ppBtree=p;
				pBt->nRef++;
				WN_SQL3FreeX(zFullPathname);
				return 0;
			}
		WN_SQL3FreeX(zFullPathname);
	}
#endif
	pBt=WN_SQL3Malloc(sizeof(*pBt));
	if(pBt==0)
	{
		rc=WN_SQL_NOMEM;
		goto btree_open_out;
	}
	if((rc=WN_SQL3PagerOpen(&pBt->pPager,zFilename,EXTRA_SIZE,flags))==0)rc=WN_SQL3PagerReadFileheader(pBt->pPager,sizeof(zDbHeader),zDbHeader);
	if(rc)goto btree_open_out;
	p->pBt=pBt;
	WN_SQL3PagerSetDestructor(pBt->pPager,pageDestructor);
	WN_SQL3PagerSetReiniter(pBt->pPager,pageReinit);
	pBt->pCursor=0;
	pBt->pPage1=0;
	pBt->readOnly=WN_SQL3PagerIsreadonly(pBt->pPager);
	pBt->pageSize=get2byte(&zDbHeader[16]);
	if(pBt->pageSize<512 || pBt->pageSize>WN_SQL_MAX_PAGE_SIZE ||((pBt->pageSize-1)&pBt->pageSize))
	{
		pBt->pageSize=WN_SQL_DEFAULT_PAGE_SIZE;
		pBt->maxEmbedFrac=64;
		pBt->minEmbedFrac=32;
		pBt->minLeafFrac=32;
#ifndef WN_SQL_OMIT_AUTOVACUUM
		if(zFilename && !isMemdb)
		{
			pBt->autoVacuum=(WN_SQL_DEFAULT_AUTOVACUUM ? 1 :0);
			pBt->incrVacuum=(WN_SQL_DEFAULT_AUTOVACUUM==2 ? 1 :0);
}
#endif
			nReserve=0;
	}
	else
	{
		nReserve=zDbHeader[20];
		pBt->maxEmbedFrac=zDbHeader[21];
		pBt->minEmbedFrac=zDbHeader[22];
		pBt->minLeafFrac=zDbHeader[23];
		pBt->pageSizeFixed=1;
#ifndef WN_SQL_OMIT_AUTOVACUUM
		pBt->autoVacuum=(get4byte(&zDbHeader[36+4*4])?1:0);
		pBt->incrVacuum=(get4byte(&zDbHeader[36+7*4])?1:0);
#endif
	}
	pBt->usableSize=pBt->pageSize-nReserve;
	WN_SQL3PagerSetPagesize(pBt->pPager,pBt->pageSize);
#if !defined(WN_SQL_OMIT_SHARED_CACHE)&& !defined(WN_SQL_OMIT_DISKIO)
	if(pTsdro->useSharedData && zFilename && !isMemdb)
	{
		pBt->pNext=pTsdro->pBtree;
		WN_SQL3ThreadData()->pBtree=pBt;
	}
#endif
	pBt->nRef=1;
	*ppBtree=p;
btree_open_out:
	if(rc)
	{
		if(pBt && pBt->pPager)WN_SQL3PagerClose(pBt->pPager);
		WN_SQL3FreeX(pBt);
		WN_SQL3FreeX(p);
		*ppBtree=0;
	}
	return rc;
}
int WN_SQL3BtreeClose(Btree *p)
{
	BtShared *pBt=p->pBt;
	BtCursor *pCur;
#ifndef WN_SQL_OMIT_SHARED_CACHE
	ThreadData *pTsd;
#endif
	pCur=pBt->pCursor;
	while(pCur)
	{
		BtCursor *pTmp=pCur;
		pCur=pCur->pNext;
		if(pTmp->pBtree==p)WN_SQL3BtreeCloseCursor(pTmp);
	}
	WN_SQL3BtreeRollback(p);
	WN_SQL3FreeX(p);
#ifndef WN_SQL_OMIT_SHARED_CACHE
	if(--pBt->nRef)return 0;
	pTsd=(ThreadData *)WN_SQL3ThreadDataReadOnly();
	if(pTsd->pBtree==pBt)
		pTsd->pBtree=pBt->pNext;
	else
	{
		BtShared *pPrev;
		for(pPrev=pTsd->pBtree;pPrev && pPrev->pNext!=pBt;pPrev=pPrev->pNext);
		if(pPrev)pPrev->pNext=pBt->pNext;
	}
#endif
	WN_SQL3PagerClose(pBt->pPager);
	if(pBt->xFreeSchema && pBt->pSchema)pBt->xFreeSchema(pBt->pSchema);
	WN_SQL3FreeX(pBt->pSchema);
	WN_SQL3FreeX(pBt);
	return 0;
}
int WN_SQL3BtreeSetBusyHandler(Btree *p,BusyHandler *pHandler)
{
	BtShared *pBt=p->pBt;
	pBt->pBusyHandler=pHandler;
	WN_SQL3PagerSetBusyhandler(pBt->pPager,pHandler);
	return 0;
}
int WN_SQL3BtreeSetCacheSize(Btree *p,int mxPage)
{
	BtShared *pBt=p->pBt;
	WN_SQL3PagerSetCachesize(pBt->pPager,mxPage);
	return 0;
}
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
int WN_SQL3BtreeSetSafetyLevel(Btree *p,int level,int fullSync)
{
	BtShared *pBt=p->pBt;
	WN_SQL3PagerSetSafetyLevel(pBt->pPager,level,fullSync);
	return 0;
}
#endif
int WN_SQL3BtreeSyncDisabled(Btree *p)
{
	BtShared *pBt=p->pBt;
	return WN_SQL3PagerNosync(pBt->pPager);
}
#if !defined(WN_SQL_OMIT_PAGER_PRAGMAS)|| !defined(WN_SQL_OMIT_VACUUM)
int WN_SQL3BtreeSetPageSize(Btree *p,int pageSize,int nReserve)
{
	BtShared *pBt=p->pBt;
	if(pBt->pageSizeFixed)return WN_SQL_READONLY;
	if(nReserve<0)nReserve=pBt->pageSize-pBt->usableSize;
	if(pageSize>=512 && pageSize<=WN_SQL_MAX_PAGE_SIZE && ((pageSize-1)&pageSize)==0)pBt->pageSize=WN_SQL3PagerSetPagesize(pBt->pPager,pageSize);
	pBt->usableSize=pBt->pageSize-nReserve;
	return 0;
}
int WN_SQL3BtreeGetPageSize(Btree *p)
{
	return p->pBt->pageSize;
}
int WN_SQL3BtreeGetReserve(Btree *p)
{
	return p->pBt->pageSize-p->pBt->usableSize;
}
int WN_SQL3BtreeMaxPageCount(Btree *p,int mxPage)
{
	return WN_SQL3PagerMaxPageCount(p->pBt->pPager,mxPage);
}
#endif
int WN_SQL3BtreeSetAutoVacuum(Btree *p,int autoVacuum)
{
#ifdef WN_SQL_OMIT_AUTOVACUUM
	return WN_SQL_READONLY;
#else
	BtShared *pBt=p->pBt;
	int av=(autoVacuum?1:0);
	if(pBt->pageSizeFixed && av!=pBt->autoVacuum)return WN_SQL_READONLY;
	pBt->autoVacuum=av;
	return 0;
#endif
}
int WN_SQL3BtreeGetAutoVacuum(Btree *p)
{
#ifdef WN_SQL_OMIT_AUTOVACUUM
	return BTREE_AUTOVACUUM_NONE;
#else
	return((!p->pBt->autoVacuum)?BTREE_AUTOVACUUM_NONE:(!p->pBt->incrVacuum)?BTREE_AUTOVACUUM_FULL:BTREE_AUTOVACUUM_INCR);
#endif
}
int lockBtree(BtShared *pBt)
{
	int rc,pageSize;
	MemPage *pPage1;
	if(pBt->pPage1)return 0;
	if((rc=WN_SQL3BtreeGetPage(pBt,1,&pPage1,0)))return rc;
	rc=WN_SQL_NOTADB;
	if(WN_SQL3PagerPagecount(pBt->pPager)>0)
	{
		u8 *page1=pPage1->aData;
		if(memcmp(page1,zMagicHeader,16))goto page1_init_failed;
		if(page1[18]>1)pBt->readOnly=1;
		if(page1[19]>1)goto page1_init_failed;
		pageSize=get2byte(&page1[16]);
		if(((pageSize-1)&pageSize)|| pageSize<512)goto page1_init_failed;
		pBt->pageSize=pageSize;
		pBt->usableSize=pageSize-page1[20];
		if(pBt->usableSize<500)goto page1_init_failed;
		pBt->maxEmbedFrac=page1[21];
		pBt->minEmbedFrac=page1[22];
		pBt->minLeafFrac=page1[23];
#ifndef WN_SQL_OMIT_AUTOVACUUM
		pBt->autoVacuum=(get4byte(&page1[36+4*4])?1:0);
		pBt->incrVacuum=(get4byte(&page1[36+7*4])?1:0);
#endif
	}
	pBt->maxLocal=(pBt->usableSize-12)*pBt->maxEmbedFrac/255-23;
	pBt->minLocal=(pBt->usableSize-12)*pBt->minEmbedFrac/255-23;
	pBt->maxLeaf=pBt->usableSize-35;
	pBt->minLeaf=(pBt->usableSize-12)*pBt->minLeafFrac/255-23;
	if(pBt->minLocal>pBt->maxLocal || pBt->maxLocal<0)goto page1_init_failed;
	pBt->pPage1=pPage1;
	return 0;
page1_init_failed:
	releasePage(pPage1);
	pBt->pPage1=0;
	return rc;
}
int lockBtreeWithRetry(Btree *pRef)
{
	int rc=0;
	if(pRef->inTrans==TRANS_NONE)
	{
		u8 inTransaction=pRef->pBt->inTransaction;
		btreeIntegrity(pRef);
		rc=WN_SQL3BtreeBeginTrans(pRef,0);
		pRef->pBt->inTransaction=inTransaction;
		pRef->inTrans=TRANS_NONE;
		if(rc==0)pRef->pBt->nTransaction--;
		btreeIntegrity(pRef);
	}
	return rc;
}
void unlockBtreeIfUnused(BtShared *pBt)
{
	if(pBt->inTransaction==TRANS_NONE && pBt->pCursor==0 && pBt->pPage1)
	{
		if(WN_SQL3PagerRefcount(pBt->pPager)>=1)
		{
			if(pBt->pPage1->aData==0)
			{
				MemPage *pPage=pBt->pPage1;
				pPage->aData=&((u8*)pPage)[-pBt->pageSize];
				pPage->pBt=pBt;
				pPage->pgno=1;
			}
			releasePage(pBt->pPage1);
		}
		pBt->pPage1=0;
		pBt->inStmt=0;
	}
}
int newDatabase(BtShared *pBt)
{
	if(WN_SQL3PagerPagecount(pBt->pPager)>0)return 0;
	MemPage *pP1=pBt->pPage1;
	unsigned char *data=pP1->aData;
	int rc=WN_SQL3PagerWrite(pP1->pDbPage);
	if(rc)return rc;
	memcpy(data,zMagicHeader,sizeof(zMagicHeader));
	put2byte(&data[16],pBt->pageSize);
	data[18]=1;
	data[19]=1;
	data[20]=pBt->pageSize-pBt->usableSize;
	data[21]=pBt->maxEmbedFrac;
	data[22]=pBt->minEmbedFrac;
	data[23]=pBt->minLeafFrac;
	memset(&data[24],0,100-24);
	zeroPage(pP1,PTF_INTKEY|PTF_LEAF|PTF_LEAFDATA);
	pBt->pageSizeFixed=1;
#ifndef WN_SQL_OMIT_AUTOVACUUM
	put4byte(&data[36+4*4],pBt->autoVacuum);
	put4byte(&data[36+7*4],pBt->incrVacuum);
#endif
	return 0;
}
int WN_SQL3BtreeBeginTrans(Btree *p,int wrflag)
{
	BtShared *pBt=p->pBt;
	int rc=0;
	btreeIntegrity(p);
	if(p->inTrans==TRANS_WRITE ||(p->inTrans==TRANS_READ && !wrflag))return 0;
	if(pBt->readOnly && wrflag)return WN_SQL_READONLY;
	if(pBt->inTransaction==TRANS_WRITE && wrflag)return WN_SQL_BUSY;
	do
	{
		if(pBt->pPage1==0)rc=lockBtree(pBt);
		if(rc==0 && wrflag)
			if(pBt->readOnly)
				rc=WN_SQL_READONLY;
			else
			{
				rc=WN_SQL3PagerBegin(pBt->pPage1->pDbPage,wrflag>1);
				if(rc==0)rc=newDatabase(pBt);
			}
		if(rc==0)
			if(wrflag)pBt->inStmt=0;
			else
				unlockBtreeIfUnused(pBt);
	}while(rc==WN_SQL_BUSY && pBt->inTransaction==TRANS_NONE && WN_SQL3InvokeBusyHandler(pBt->pBusyHandler));
	if(rc==0)
	{
		if(p->inTrans==TRANS_NONE)pBt->nTransaction++;
		p->inTrans=(wrflag?TRANS_WRITE:TRANS_READ);
		if(p->inTrans>pBt->inTransaction)pBt->inTransaction=p->inTrans;
	}
	btreeIntegrity(p);
	return rc;
}
#ifndef WN_SQL_OMIT_AUTOVACUUM
int setChildPtrmaps(MemPage *pPage)
{
	int i,nCell,rc;
	BtShared *pBt=pPage->pBt;
	int isInitOrig=pPage->isInit;
	Pgno pgno=pPage->pgno;
	if((rc=WN_SQL3BtreeInitPage(pPage,pPage->pParent)))goto set_child_ptrmaps_out;
	nCell=pPage->nCell;
	for(i=0;i<nCell;i++)
	{
		u8 *pCell=findCell(pPage,i);
		rc=ptrmapPutOvflPtr(pPage,pCell);
		if(rc)goto set_child_ptrmaps_out;
		if(!pPage->leaf)
		{
			Pgno childPgno=get4byte(pCell);
			rc=ptrmapPut(pBt,childPgno,PTRMAP_BTREE,pgno);
			if(rc)goto set_child_ptrmaps_out;
		}
	}
	if(!pPage->leaf)
	{
		Pgno childPgno=get4byte(&pPage->aData[pPage->hdrOffset+8]);
		rc=ptrmapPut(pBt,childPgno,PTRMAP_BTREE,pgno);
	}
set_child_ptrmaps_out:
	pPage->isInit=isInitOrig;
	return rc;
}
int modifyPagePointer(MemPage *pPage,Pgno iFrom,Pgno iTo,u8 eType)
{
	if(eType==PTRMAP_OVERFLOW2)
	{
		if(get4byte(pPage->aData)!=iFrom)return WN_SQL_CORRUPT_BKPT;
		put4byte(pPage->aData,iTo);
	}
	else
	{
		int isInitOrig=pPage->isInit,i;
		WN_SQL3BtreeInitPage(pPage,0);
		int nCell=pPage->nCell;
		for(i=0;i<nCell;i++)
		{
			u8 *pCell=findCell(pPage,i);
			if(eType==PTRMAP_OVERFLOW1)
			{
				CellInfo info;
				WN_SQL3BtreeParseCellPtr(pPage,pCell,&info);
				if(info.iOverflow)
					if(iFrom==get4byte(&pCell[info.iOverflow]))
					{
						put4byte(&pCell[info.iOverflow],iTo);
						break;
					}
			}
			else
				if(get4byte(pCell)==iFrom)
				{
					put4byte(pCell,iTo);
					break;
				}
		}
		if(i==nCell)
		{
			if(eType!=PTRMAP_BTREE || get4byte(&pPage->aData[pPage->hdrOffset+8])!=iFrom)return WN_SQL_CORRUPT_BKPT;
			put4byte(&pPage->aData[pPage->hdrOffset+8],iTo);
		}
		pPage->isInit=isInitOrig;
	}
	return 0;
}
int relocatePage(BtShared *pBt,MemPage *pDbPage,u8 eType,Pgno iPtrPage,Pgno iFreePage)
{
	MemPage *pPtrPage;
	Pgno iDbPage=pDbPage->pgno;
	Pager *pPager=pBt->pPager;
	eType==PTRMAP_BTREE || eType==PTRMAP_ROOTPAGE);
	TRACE(("AUTOVACUUM:Moving %d to free page %d(ptr page %d type %d)\n",iDbPage,iFreePage,iPtrPage,eType));
	int rc=WN_SQL3PagerMovepage(pPager,pDbPage->pDbPage,iFreePage);
	if(rc)return rc;
	pDbPage->pgno=iFreePage;
	if(eType==PTRMAP_BTREE || eType==PTRMAP_ROOTPAGE)
		if(rc=setChildPtrmaps(pDbPage))return rc;
		else
		{
			Pgno nextOvfl=get4byte(pDbPage->aData);
			if(nextOvfl)
			{
				rc=ptrmapPut(pBt,nextOvfl,PTRMAP_OVERFLOW2,iFreePage);
				if(rc)return rc;
			}
		}
		if(eType!=PTRMAP_ROOTPAGE)
		{
			rc=WN_SQL3BtreeGetPage(pBt,iPtrPage,&pPtrPage,0);
			if(rc)return rc;
			rc=WN_SQL3PagerWrite(pPtrPage->pDbPage);
			if(rc)
			{
				releasePage(pPtrPage);
				return rc;
			}
			rc=modifyPagePointer(pPtrPage,iDbPage,iFreePage,eType);
			releasePage(pPtrPage);
			if(rc==0)rc=ptrmapPut(pBt,iFreePage,eType,iPtrPage);
		}
		return rc;
}
int incrVacuumStep(BtShared *pBt,Pgno nFin)
{
	Pgno iLastPg=pBt->nTrunc,nFreeList;
	if(iLastPg==0)iLastPg=WN_SQL3PagerPagecount(pBt->pPager);
	if(!PTRMAP_ISPAGE(pBt,iLastPg)&& iLastPg!=PENDING_BYTE_PAGE(pBt))
	{
		int rc;
		u8 eType;
		Pgno iPtrPage;
		nFreeList=get4byte(&pBt->pPage1->aData[36]);
		if(nFreeList==0 || nFin==iLastPg)return WN_SQL_DONE;
		rc=ptrmapGet(pBt,iLastPg,&eType,&iPtrPage);
		if(rc)return rc;
		if(eType==PTRMAP_ROOTPAGE)return WN_SQL_CORRUPT_BKPT;
		if(eType==PTRMAP_FREEPAGE)
		{
			if(nFin==0)
			{
				Pgno iFreePg;
				MemPage *pFreePg;
				rc=allocateBtreePage(pBt,&pFreePg,&iFreePg,iLastPg,1);
				if(rc)return rc;
				releasePage(pFreePg);
			}
		}
		else
		{
			Pgno iFreePg;
			MemPage *pLastPg;
			rc=WN_SQL3BtreeGetPage(pBt,iLastPg,&pLastPg,0);
			if(rc)return rc;
			do
			{
				MemPage *pFreePg;
				rc=allocateBtreePage(pBt,&pFreePg,&iFreePg,0,0);
				if(rc)
				{
					releasePage(pLastPg);
					return rc;
				}
				releasePage(pFreePg);
			}while(nFin && iFreePg>nFin);
			rc=WN_SQL3PagerWrite(pLastPg->pDbPage);
			if(rc)return rc;
			rc=relocatePage(pBt,pLastPg,eType,iPtrPage,iFreePg);
			releasePage(pLastPg);
			if(rc)return rc;
		}
	}
	pBt->nTrunc=iLastPg-1;
	while(pBt->nTrunc==PENDING_BYTE_PAGE(pBt)||PTRMAP_ISPAGE(pBt,pBt->nTrunc))pBt->nTrunc--;
	return 0;
}
int WN_SQL3BtreeIncrVacuum(Btree *p)
{
	BtShared *pBt=p->pBt;
	if(!pBt->autoVacuum)return WN_SQL_DONE;
	invalidateAllOverflowCache(pBt);
	return incrVacuumStep(pBt,0);
}
int autoVacuumCommit(BtShared *pBt,Pgno *pnTrunc)
{
	int rc=0;
	Pager *pPager=pBt->pPager;
#ifndef NDEBUG
	int nRef=WN_SQL3PagerRefcount(pPager);
#endif
	invalidateAllOverflowCache(pBt);
	if(!pBt->incrVacuum)
	{
		Pgno nFin=0;
		if(pBt->nTrunc==0)
		{
			Pgno nFree,nPtrmap;
			const int pgsz=pBt->pageSize;
			Pgno nOrig=WN_SQL3PagerPagecount(pBt->pPager);
			if(PTRMAP_ISPAGE(pBt,nOrig))return WN_SQL_CORRUPT_BKPT;
			if(nOrig==PENDING_BYTE_PAGE(pBt))nOrig--;
			nFree=get4byte(&pBt->pPage1->aData[36]);
			nPtrmap=(nFree-nOrig+PTRMAP_PAGENO(pBt,nOrig)+pgsz/5)/(pgsz/5);
			nFin=nOrig-nFree-nPtrmap;
			if(nOrig>PENDING_BYTE_PAGE(pBt)&& nFin<=PENDING_BYTE_PAGE(pBt))nFin--;
			while(PTRMAP_ISPAGE(pBt,nFin)|| nFin==PENDING_BYTE_PAGE(pBt))nFin--;
		}
		while(rc==0)rc=incrVacuumStep(pBt,nFin);
		if(rc==WN_SQL_DONE)
		{
			rc=0;
			if(pBt->nTrunc)
			{
				WN_SQL3PagerWrite(pBt->pPage1->pDbPage);
				put4byte(&pBt->pPage1->aData[32],0);
				put4byte(&pBt->pPage1->aData[36],0);
				pBt->nTrunc=nFin;
			}
		}
		if(rc)WN_SQL3PagerRollback(pPager);
	}
	if(rc==0)
	{
		*pnTrunc=pBt->nTrunc;
		pBt->nTrunc=0;
	}
	return rc;
}
#endif
int WN_SQL3BtreeCommitPhaseOne(Btree *p,const char *zMaster)
{
	int rc=0;
	if(p->inTrans==TRANS_WRITE)
	{
		BtShared *pBt=p->pBt;
		Pgno nTrunc=0;
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->autoVacuum)
	{
		rc=autoVacuumCommit(pBt,&nTrunc);
		if(rc)return rc;
	}
#endif
	rc=WN_SQL3PagerCommitPhaseOne(pBt->pPager,zMaster,nTrunc);
	}
	return rc;
}
int WN_SQL3BtreeCommitPhaseTwo(Btree *p)
{
	BtShared *pBt=p->pBt;
	btreeIntegrity(p);
	if(p->inTrans==TRANS_WRITE)
	{
		int rc;
		rc=WN_SQL3PagerCommitPhaseTwo(pBt->pPager);
		if(rc)return rc;
		pBt->inTransaction=TRANS_READ;
		pBt->inStmt=0;
	}
	unlockAllTables(p);
	if(p->inTrans!=TRANS_NONE)
	{
		pBt->nTransaction--;
		if(0==pBt->nTransaction)pBt->inTransaction=TRANS_NONE;
	}
	p->inTrans=TRANS_NONE;
	unlockBtreeIfUnused(pBt);
	btreeIntegrity(p);
	return 0;
}
int WN_SQL3BtreeCommit(Btree *p)
{
	int rc;
	rc=WN_SQL3BtreeCommitPhaseOne(p,0);
	if(rc==0)rc=WN_SQL3BtreeCommitPhaseTwo(p);
	return rc;
}
#ifndef NDEBUG
int countWriteCursors(BtShared *pBt)
{
	BtCursor *pCur;
	int r=0;
	for(pCur=pBt->pCursor;pCur;pCur=pCur->pNext)if(pCur->wrFlag)r++;
	return r;
}
#endif
int WN_SQL3BtreeRollback(Btree *p)
{
	int rc;
	BtShared *pBt=p->pBt;
	MemPage *pPage1;
	rc=saveAllCursors(pBt,0,0);
#ifndef WN_SQL_OMIT_SHARED_CACHE
	if(rc)
		while(pBt->pCursor)
		{
			WN_SQL3 *db=pBt->pCursor->pBtree->pWN_SQL;
			if(db)WN_SQL3AbortOtherActiveVdbes(db,0);
		}
#endif
	btreeIntegrity(p);
	unlockAllTables(p);
	if(p->inTrans==TRANS_WRITE)
	{
		int rc2;
#ifndef WN_SQL_OMIT_AUTOVACUUM
		pBt->nTrunc=0;
#endif
		rc2=WN_SQL3PagerRollback(pBt->pPager);
		if(rc2)	rc=rc2;
		if(WN_SQL3BtreeGetPage(pBt,1,&pPage1,0)==0)releasePage(pPage1);
		pBt->inTransaction=TRANS_READ;
	}
	if(p->inTrans!=TRANS_NONE)
	{
		pBt->nTransaction--;
		if(0==pBt->nTransaction)pBt->inTransaction=TRANS_NONE;
	}
	p->inTrans=TRANS_NONE;
	pBt->inStmt=0;
	unlockBtreeIfUnused(pBt);
	btreeIntegrity(p);
	return rc;
}
int WN_SQL3BtreeBeginStmt(Btree *p)
{
	int rc;
	BtShared *pBt=p->pBt;
	if((p->inTrans!=TRANS_WRITE)|| pBt->inStmt)
		return pBt->readOnly ? WN_SQL_READONLY :WN_SQL_ERROR;
	rc=pBt->readOnly ? 0 :WN_SQL3PagerStmtBegin(pBt->pPager);
	pBt->inStmt=1;
	return rc;
}
int WN_SQL3BtreeCommitStmt(Btree *p)
{
	int rc;
	BtShared *pBt=p->pBt;
	if(pBt->inStmt && !pBt->readOnly)
		rc=WN_SQL3PagerStmtCommit(pBt->pPager);
	else
		rc=0;
	pBt->inStmt=0;
	return rc;
}
int WN_SQL3BtreeRollbackStmt(Btree *p)
{
	int rc=0;
	BtShared *pBt=p->pBt;
	WN_SQL3MallocDisallow();
	if(pBt->inStmt && !pBt->readOnly)
	{
		rc=WN_SQL3PagerStmtRollback(pBt->pPager);
		pBt->inStmt=0;
	}
	WN_SQL3MallocAllow();
	return rc;
}
int dfltCompare(void *NotUsed,int n1,const void *p1,int n2,const void *p2)
{
	int c=memcmp(p1,p2,n1<n2 ? n1 :n2);
	if(c==0)c=n1-n2;
	return c;
}
int WN_SQL3BtreeCursor(Btree *p,int iTable,int wrFlag,int(*xCmp)(void*,int,const void*,int,const void*),void *pArg,BtCursor **ppCur)
{
	int rc;
	BtCursor *pCur;
	BtShared *pBt=p->pBt;
	*ppCur=0;
	if(wrFlag)
	{
		if(pBt->readOnly)return WN_SQL_READONLY;
		if(checkReadLocks(p,iTable,0))return WN_SQL_LOCKED;
	}
	if(pBt->pPage1==0)
	{
		if(rc=lockBtreeWithRetry(p))return rc;
		if(pBt->readOnly && wrFlag)return WN_SQL_READONLY;
	}
	pCur=WN_SQL3Malloc(sizeof(*pCur));
	if(pCur==0)
	{
		rc=WN_SQL_NOMEM;
		goto create_cursor_exception;
	}
	pCur->pgnoRoot=(Pgno)iTable;
	if(iTable==1 && WN_SQL3PagerPagecount(pBt->pPager)==0)
	{
		rc=WN_SQL_EMPTY;
		goto create_cursor_exception;
	}
	rc=getAndInitPage(pBt,pCur->pgnoRoot,&pCur->pPage,0);
	if(rc)goto create_cursor_exception;
	pCur->xCompare=xCmp ? xCmp :dfltCompare;
	pCur->pArg=pArg;
	pCur->pBtree=p;
	pCur->wrFlag=wrFlag;
	pCur->pNext=pBt->pCursor;
	if(pCur->pNext)pCur->pNext->pPrev=pCur;
	pBt->pCursor=pCur;
	pCur->eState=CURSOR_INVALID;
	*ppCur=pCur;
	return 0;
create_cursor_exception:
	if(pCur)
	{
		releasePage(pCur->pPage);
		WN_SQL3FreeX(pCur);
	}
	unlockBtreeIfUnused(pBt);
	return rc;
}
int WN_SQL3BtreeCloseCursor(BtCursor *pCur)
{
	BtShared *pBt=pCur->pBtree->pBt;
	clearCursorPosition(pCur);
	if(pCur->pPrev)
		pCur->pPrev->pNext=pCur->pNext;
	else
		pBt->pCursor=pCur->pNext;
	if(pCur->pNext)pCur->pNext->pPrev=pCur->pPrev;
	releasePage(pCur->pPage);
	unlockBtreeIfUnused(pBt);
	invalidateOverflowCache(pCur);
	WN_SQL3FreeX(pCur);
	return 0;
}
void WN_SQL3BtreeGetTempCursor(BtCursor *pCur,BtCursor *pTempCur)
{
	memcpy(pTempCur,pCur,sizeof(*pCur));
	pTempCur->pNext=0;
	pTempCur->pPrev=0;
	if(pTempCur->pPage)	WN_SQL3PagerRef(pTempCur->pPage->pDbPage);
}
void WN_SQL3BtreeReleaseTempCursor(BtCursor *pCur)
{
	if(pCur->pPage)	WN_SQL3PagerUnref(pCur->pPage->pDbPage);
}
#ifndef NDEBUG
void CellInfo info;
memset(&info,0,sizeof(info));
WN_SQL3BtreeParseCell(pCur->pPage,pCur->idx,&info);
}
#endif
#ifdef _MSC_VER
void getCellInfo(BtCursor *pCur)
{
	if(pCur->info.nSize==0)	WN_SQL3BtreeParseCell(pCur->pPage,pCur->idx,&pCur->info);
}
#else
#define getCellInfo (pCur)\
if(pCur->info.nSize==0){\
WN_SQL3BtreeParseCell(pCur->pPage,pCur->idx,&pCur->info);\
}else{\
}
#endif
int WN_SQL3BtreeKeySize(BtCursor *pCur,i64 *pSize)
{
	int rc=restoreOrClearCursorPosition(pCur);
	if(rc==0)
		if(pCur->eState==CURSOR_INVALID)
			*pSize=0;
		else
		{
			getCellInfo(pCur);
			*pSize=pCur->info.nKey;
		}
	return rc;
}
int WN_SQL3BtreeDataSize(BtCursor *pCur,u32 *pSize)
{
	int rc=restoreOrClearCursorPosition(pCur);
	if(rc==0)
		if(pCur->eState==CURSOR_INVALID)
			*pSize=0;
		else
		{
			getCellInfo(pCur);
			*pSize=pCur->info.nData;
		}
	return rc;
}
int getOverflowPage(BtShared *pBt,Pgno ovfl,MemPage **ppPage,Pgno *pPgnoNext)
{
	Pgno next=0;
	int rc;
	if(!pPgnoNext)return WN_SQL3BtreeGetPage(pBt,ovfl,ppPage,1);
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->autoVacuum)
	{
		Pgno pgno;
		Pgno iGuess=ovfl+1;
		u8 eType;
		while(PTRMAP_ISPAGE(pBt,iGuess)||iGuess==PENDING_BYTE_PAGE(pBt))iGuess++;
		if(iGuess<=WN_SQL3PagerPagecount(pBt->pPager))
		{
			rc=ptrmapGet(pBt,iGuess,&eType,&pgno);
			if(rc)return rc;
			if(eType==PTRMAP_OVERFLOW2 && pgno==ovfl)next=iGuess;
		}
	}
#endif
	if(next==0 || ppPage)
	{
		MemPage *pPage=0;
		rc=WN_SQL3BtreeGetPage(pBt,ovfl,&pPage,next!=0);
		if(next==0 && rc==0)next=get4byte(pPage->aData);
		if(ppPage)
			*ppPage=pPage;
		else
			releasePage(pPage);
	}
	*pPgnoNext=next;
	return rc;
}
int copyPayload(void *pPayload,void *pBuf,int nByte,int eOp,DbPage *pDbPage
)
{
	if(eOp)
	{
		int rc=WN_SQL3PagerWrite(pDbPage);
		if(rc)return rc;
		memcpy(pPayload,pBuf,nByte);
	}
	else
		memcpy(pBuf,pPayload,nByte);
	return 0;
}
int accessPayload(BtCursor *pCur,int offset,int amt,unsigned char *pBuf,int skipKey,int eOp)
{
	unsigned char *aPayload;
	int rc=0,iIdx=0;
	u32 nKey;
	MemPage *pPage=pCur->pPage;
	BtShared *pBt=pCur->pBtree->pBt;
	getCellInfo(pCur);
	aPayload=pCur->info.pCell+pCur->info.nHeader;
	nKey=(pPage->intKey ? 0 :pCur->info.nKey);
	if(skipKey)offset+=nKey;
	if(offset+amt > nKey+pCur->info.nData)return WN_SQL_ERROR;
	if(offset<pCur->info.nLocal)
	{
		int a=amt;
		if(a+offset>pCur->info.nLocal)a=pCur->info.nLocal-offset;
		rc=copyPayload(&aPayload[offset],pBuf,a,eOp,pPage->pDbPage);
		offset=0;
		pBuf+=a;
		amt-=a;
	}
	else
		offset-=pCur->info.nLocal;
	if(rc==0 && amt>0)
	{
		const int ovflSize=pBt->usableSize-4;
		Pgno nextPage;
		nextPage=get4byte(&aPayload[pCur->info.nLocal]);
#ifndef WN_SQL_OMIT_INCRBLOB
		if(pCur->isIncrblobHandle && !pCur->aOverflow)
		{
			int nOvfl=(pCur->info.nPayload-pCur->info.nLocal+ovflSize-1)/ovflSize;
			pCur->aOverflow=(Pgno *)WN_SQL3Malloc(sizeof(Pgno)*nOvfl);
			if(nOvfl && !pCur->aOverflow)rc=WN_SQL_NOMEM;
		}
		if(pCur->aOverflow && pCur->aOverflow[offset/ovflSize])
		{
			iIdx=(offset/ovflSize);
			nextPage=pCur->aOverflow[iIdx];
			offset=(offset%ovflSize);
		}
#endif
		for(;rc==0 && amt>0 && nextPage;iIdx++)
		{
#ifndef WN_SQL_OMIT_INCRBLOB
			if(pCur->aOverflow)	pCur->aOverflow[iIdx]=nextPage;
#endif
			if(offset>=ovflSize)
			{
#ifndef WN_SQL_OMIT_INCRBLOB
				if(pCur->aOverflow && pCur->aOverflow[iIdx+1])
					nextPage=pCur->aOverflow[iIdx+1];
				else
#endif
					rc=getOverflowPage(pBt,nextPage,0,&nextPage);
				offset-=ovflSize;
			}
			else
			{
				DbPage *pDbPage;
				int a=amt;
				rc=WN_SQL3PagerGet(pBt->pPager,nextPage,&pDbPage);
				if(rc==0)
				{
					aPayload=WN_SQL3PagerGetData(pDbPage);
					nextPage=get4byte(aPayload);
					if(a+offset > ovflSize)a=ovflSize-offset;
					rc=copyPayload(&aPayload[offset+4],pBuf,a,eOp,pDbPage);
					WN_SQL3PagerUnref(pDbPage);
					offset=0;
					amt-=a;
					pBuf+=a;
				}
			}
		}
	}
	if(rc==0 && amt>0)return WN_SQL_CORRUPT_BKPT;
	return rc;
}
int WN_SQL3BtreeKey(BtCursor *pCur,u32 offset,u32 amt,void *pBuf)
{
	int rc=restoreOrClearCursorPosition(pCur);
	if(rc==0)
	{
		if(pCur->pPage->intKey)return WN_SQL_CORRUPT_BKPT;
		rc=accessPayload(pCur,offset,amt,(unsigned char*)pBuf,0,0);
	}
	return rc;
}
int WN_SQL3BtreeData(BtCursor *pCur,u32 offset,u32 amt,void *pBuf)
{
	int rc=restoreOrClearCursorPosition(pCur);
	if(rc==0)rc=accessPayload(pCur,offset,amt,pBuf,1,0);
	return rc;
}
const unsigned char *fetchPayload(BtCursor *pCur,int *pAmt,int skipKey
)
{
	unsigned char *aPayload;
	MemPage *pPage;
	u32 nKey;
	int nLocal;
	pPage=pCur->pPage;
	getCellInfo(pCur);
	aPayload=pCur->info.pCell;
	aPayload+=pCur->info.nHeader;
	if(pPage->intKey)
		nKey=0;
	else
		nKey=pCur->info.nKey;
	if(skipKey)
	{
		aPayload+=nKey;
		nLocal=pCur->info.nLocal-nKey;
	}
	else
	{
		nLocal=pCur->info.nLocal;
		if(nLocal>nKey)nLocal=nKey;
	}
	*pAmt=nLocal;
	return aPayload;
}
const void *WN_SQL3BtreeKeyFetch(BtCursor *pCur,int *pAmt)
{
	if(pCur->eState==CURSOR_VALID)return(const void*)fetchPayload(pCur,pAmt,0);
	return 0;
}
const void *WN_SQL3BtreeDataFetch(BtCursor *pCur,int *pAmt)
{
	if(pCur->eState==CURSOR_VALID)return(const void*)fetchPayload(pCur,pAmt,1);
	return 0;
}
int moveToChild(BtCursor *pCur,u32 newPgno)
{
	int rc;
	MemPage *pNewPage,*pOldPage;
	BtShared *pBt=pCur->pBtree->pBt;
	rc=getAndInitPage(pBt,newPgno,&pNewPage,pCur->pPage);
	if(rc)return rc;
	pNewPage->idxParent=pCur->idx;
	pOldPage=pCur->pPage;
	pOldPage->idxShift=0;
	releasePage(pOldPage);
	pCur->pPage=pNewPage;
	pCur->idx=0;
	pCur->info.nSize=0;
	if(pNewPage->nCell<1)return WN_SQL_CORRUPT_BKPT;
	return 0;
}
int WN_SQL3BtreeIsRootPage(MemPage *pPage)
{
	MemPage *pParent=pPage->pParent;
	if(pParent==0)return 1;
	if(pParent->pgno>1)return 0;
	if(get2byte(&pParent->aData[pParent->hdrOffset+3])==0)return 1;
	return 0;
}
void WN_SQL3BtreeMoveToParent(BtCursor *pCur)
{
	MemPage *pParent,*pPage;
	int idxParent;
	pPage=pCur->pPage;
	pParent=pPage->pParent;
	idxParent=pPage->idxParent;
	WN_SQL3PagerRef(pParent->pDbPage);
	releasePage(pPage);
	pCur->pPage=pParent;
	pCur->info.nSize=0;
	pCur->idx=idxParent;
}
int moveToRoot(BtCursor *pCur)
{
	MemPage *pRoot;
	int rc=0;
	BtShared *pBt=pCur->pBtree->pBt;
	if(pCur->eState==CURSOR_REQUIRESEEK)clearCursorPosition(pCur);
	pRoot=pCur->pPage;
	if(!(pRoot && pRoot->pgno==pCur->pgnoRoot))
	{
		if(rc=getAndInitPage(pBt,pCur->pgnoRoot,&pRoot,0)
		{
			pCur->eState=CURSOR_INVALID;
			return rc;
		}
		releasePage(pCur->pPage);
		pCur->pPage=pRoot;
	}
	pCur->idx=0;
	pCur->info.nSize=0;
	if(pRoot->nCell==0 && !pRoot->leaf)
	{
		Pgno subpage;
		subpage=get4byte(&pRoot->aData[pRoot->hdrOffset+8]);
		pCur->eState=CURSOR_VALID;
		rc=moveToChild(pCur,subpage);
	}
	pCur->eState=((pCur->pPage->nCell>0)?CURSOR_VALID:CURSOR_INVALID);
	return rc;
}
int moveToLeftmost(BtCursor *pCur)
{
	Pgno pgno;
	int rc;
	MemPage *pPage;
	while(!(pPage=pCur->pPage)->leaf)
	{
		pgno=get4byte(findCell(pPage,pCur->idx));
		rc=moveToChild(pCur,pgno);
		if(rc)return rc;
	}
	return 0;
}
int moveToRightmost(BtCursor *pCur)
{
	Pgno pgno;
	int rc;
	MemPage *pPage;
	while(!(pPage=pCur->pPage)->leaf)
	{
		pgno=get4byte(&pPage->aData[pPage->hdrOffset+8]);
		pCur->idx=pPage->nCell;
		rc=moveToChild(pCur,pgno);
		if(rc)return rc;
	}
	pCur->idx=pPage->nCell-1;
	pCur->info.nSize=0;
	return 0;
}
int WN_SQL3BtreeFirst(BtCursor *pCur,int *pRes)
{
	int rc;
	rc=moveToRoot(pCur);
	if(rc)return rc;
	if(pCur->eState==CURSOR_INVALID)
	{
		*pRes=1;
		return 0;
	}
	*pRes=0;
	rc=moveToLeftmost(pCur);
	return rc;
}
int WN_SQL3BtreeLast(BtCursor *pCur,int *pRes)
{
	int rc=moveToRoot(pCur);
	if(rc)return rc;
	if(CURSOR_INVALID==pCur->eState)
	{
		*pRes=1;
		return 0;
	}
	*pRes=0;
	rc=moveToRightmost(pCur);
	return rc;
}
int WN_SQL3BtreeMoveto(BtCursor *pCur,const void *pKey,i64 nKey,int biasRight,int *pRes)
{
	int rc;
	rc=moveToRoot(pCur);
	if(rc)return rc;
	if(pCur->eState==CURSOR_INVALID)
	{
		*pRes=-1;
		return 0;
	}
	for(;;)
	{
		int lwr,upr;
		Pgno chldPg;
		MemPage *pPage=pCur->pPage;
		int c=-1;
		lwr=0;
		upr=pPage->nCell-1;
		if(!pPage->intKey && pKey==0)return WN_SQL_CORRUPT_BKPT;
		if(biasRight)
			pCur->idx=upr;
		else
			pCur->idx=(upr+lwr)/2;
		if(lwr<=upr)
			for(;;)
			{
				void *pCellKey;
				i64 nCellKey;
				pCur->info.nSize=0;
				if(pPage->intKey)
				{
					u8 *pCell=findCell(pPage,pCur->idx)+pPage->childPtrSize;
					if(pPage->hasData)
					{
						u32 dummy;
						pCell+=getVarint32(pCell,&dummy);
					}
					getVarint(pCell,(u64 *)&nCellKey);
					if(nCellKey<nKey)c=-1;
					else
						c=(nCellKey>nKey);
				}
				else
				{
					int available;
					pCellKey=(void *)fetchPayload(pCur,&available,0);
					nCellKey=pCur->info.nKey;
					if(available>=nCellKey)
						c=pCur->xCompare(pCur->pArg,nCellKey,pCellKey,nKey,pKey);
					else
					{
						pCellKey=WN_SQLMallocRaw(nCellKey);
						if(pCellKey==0)return WN_SQL_NOMEM;
						rc=WN_SQL3BtreeKey(pCur,0,nCellKey,(void *)pCellKey);
						c=pCur->xCompare(pCur->pArg,nCellKey,pCellKey,nKey,pKey);
						WN_SQL3FreeX(pCellKey);
						if(rc)return rc;
					}
				}
				if(c==0)
					if(pPage->leafData && !pPage->leaf)
					{
						lwr=pCur->idx;
						upr=lwr-1;
						break;
					}
					else
					{
						if(pRes)*pRes=0;
						return 0;
					}
				if(c<0)
					lwr=pCur->idx+1;
				else
					upr=pCur->idx-1;
				if(lwr>upr)break;
				pCur->idx=(lwr+upr)/2;
			}
			if(pPage->leaf)
				chldPg=0;
			else
				if(lwr>=pPage->nCell)
					chldPg=get4byte(&pPage->aData[pPage->hdrOffset+8]);
				else
					chldPg=get4byte(findCell(pPage,lwr));
			if(chldPg==0)
			{
				if(pRes)*pRes=c;
				return 0;
			}
			pCur->idx=lwr;
			pCur->info.nSize=0;
			if(rc=moveToChild(pCur,chldPg))return rc;
	}
}
int WN_SQL3BtreeEof(BtCursor *pCur)
{
	return(CURSOR_VALID!=pCur->eState);
}
int WN_SQL3BtreeNext(BtCursor *pCur,int *pRes)
{
	int rc=restoreOrClearCursorPosition(pCur);
	if(rc)return rc;
	MemPage *pPage=pCur->pPage;
	if(CURSOR_INVALID==pCur->eState)
	{
		*pRes=1;
		return 0;
	}
	if(pCur->skip>0)
	{
		pCur->skip=0;
		*pRes=0;
		return 0;
	}
	pCur->skip=0;
	pCur->idx++;
	pCur->info.nSize=0;
	if(pCur->idx>=pPage->nCell)
	{
		if(!pPage->leaf)
		{
			rc=moveToChild(pCur,get4byte(&pPage->aData[pPage->hdrOffset+8]));
			if(rc)return rc;
			rc=moveToLeftmost(pCur);
			*pRes=0;
			return rc;
		}
		do
		{
			if(WN_SQL3BtreeIsRootPage(pPage))
			{
				*pRes=1;
				pCur->eState=CURSOR_INVALID;
				return 0;
			}
			WN_SQL3BtreeMoveToParent(pCur);
			pPage=pCur->pPage;
		}while(pCur->idx>=pPage->nCell);
		*pRes=0;
		if(pPage->leafData)
			rc=WN_SQL3BtreeNext(pCur,pRes);
		else
			rc=0;
		return rc;
	}
	*pRes=0;
	if(pPage->leaf)return 0;
	return moveToLeftmost(pCur);
}
int WN_SQL3BtreePrevious(BtCursor *pCur,int *pRes)
{
	int rc=restoreOrClearCursorPosition(pCur);
	if(rc)return rc;
	Pgno pgno;
	MemPage *pPage;
	if(CURSOR_INVALID==pCur->eState)
	{
		*pRes=1;
		return 0;
	}
	if(pCur->skip<0)
	{
		pCur->skip=0;
		*pRes=0;
		return 0;
	}
	pCur->skip=0;
	pPage=pCur->pPage;
	if(!pPage->leaf)
	{
		pgno=get4byte(findCell(pPage,pCur->idx));
		rc=moveToChild(pCur,pgno);
		if(rc)return rc;
		rc=moveToRightmost(pCur);
	}
	else
	{
		while(pCur->idx==0)
		{
			if(WN_SQL3BtreeIsRootPage(pPage))
			{
				pCur->eState=CURSOR_INVALID;
				*pRes=1;
				return 0;
			}
			WN_SQL3BtreeMoveToParent(pCur);
			pPage=pCur->pPage;
		}
		pCur->idx--;
		pCur->info.nSize=0;
		if(pPage->leafData && !pPage->leaf)
			rc=WN_SQL3BtreePrevious(pCur,pRes);
		else
			rc=0;
	}
	*pRes=0;
	return rc;
}
int allocateBtreePage(BtShared *pBt,MemPage **ppPage,Pgno *pPgno,Pgno nearby,u8 exact)
{
	MemPage *pPage1,*pTrunk=0,*pPrevTrunk=0;	
	int rc,n,k;
	pPage1=pBt->pPage1;
	n=get4byte(&pPage1->aData[36]);
	if(n>0)
	{
		Pgno iTrunk;
		u8 searchList=0;
#ifndef WN_SQL_OMIT_AUTOVACUUM
		if(exact && nearby<=WN_SQL3PagerPagecount(pBt->pPager))
		{
			u8 eType;
			rc=ptrmapGet(pBt,nearby,&eType,0);
			if(rc)return rc;
			if(eType==PTRMAP_FREEPAGE)searchList=1;
			*pPgno=nearby;
		}
#endif
		rc=WN_SQL3PagerWrite(pPage1->pDbPage);
		if(rc)return rc;
		put4byte(&pPage1->aData[36],n-1);
		do
		{
			pPrevTrunk=pTrunk;
			if(pPrevTrunk)
				iTrunk=get4byte(&pPrevTrunk->aData[0]);
			else
				iTrunk=get4byte(&pPage1->aData[32]);
			rc=WN_SQL3BtreeGetPage(pBt,iTrunk,&pTrunk,0);
			if(rc)
			{
				pTrunk=0;
				goto end_allocate_page;
			}
			k=get4byte(&pTrunk->aData[4]);
			if(k==0 && !searchList)
			{
				rc=WN_SQL3PagerWrite(pTrunk->pDbPage);
				if(rc)goto end_allocate_page;
				*pPgno=iTrunk;
				memcpy(&pPage1->aData[32],&pTrunk->aData[0],4);
				*ppPage=pTrunk;
				pTrunk=0;
				TRACE(("ALLOCATE:%d trunk-%d free pages left\n",*pPgno,n-1));
			}
			else
				if(k>pBt->usableSize/4-8)
				{
					rc=WN_SQL_CORRUPT_BKPT;
					goto end_allocate_page;
#ifndef WN_SQL_OMIT_AUTOVACUUM
				}
				else
					if(searchList && nearby==iTrunk)
					{
						*ppPage=pTrunk;
						searchList=0;
						rc=WN_SQL3PagerWrite(pTrunk->pDbPage);
						if(rc)goto end_allocate_page;
						if(k==0)
						{
							if(!pPrevTrunk)
								memcpy(&pPage1->aData[32],&pTrunk->aData[0],4);
							else
								memcpy(&pPrevTrunk->aData[0],&pTrunk->aData[0],4);
						}
						else
						{
							MemPage *pNewTrunk;
							Pgno iNewTrunk=get4byte(&pTrunk->aData[8]);
							rc=WN_SQL3BtreeGetPage(pBt,iNewTrunk,&pNewTrunk,0);
							if(rc)goto end_allocate_page;
							rc=WN_SQL3PagerWrite(pNewTrunk->pDbPage);
							if(rc)
							{
								releasePage(pNewTrunk);
								goto end_allocate_page;
							}
							memcpy(&pNewTrunk->aData[0],&pTrunk->aData[0],4);
							put4byte(&pNewTrunk->aData[4],k-1);
							memcpy(&pNewTrunk->aData[8],&pTrunk->aData[12],(k-1)*4);
							releasePage(pNewTrunk);
							if(!pPrevTrunk)
								put4byte(&pPage1->aData[32],iNewTrunk);
							else
							{
								rc=WN_SQL3PagerWrite(pPrevTrunk->pDbPage);
								if(rc)goto end_allocate_page;
								put4byte(&pPrevTrunk->aData[0],iNewTrunk);
							}
						}
						pTrunk=0;
						TRACE(("ALLOCATE:%d trunk-%d free pages left\n",*pPgno,n-1));
#endif
					}
					else
					{
						int closest;
						Pgno iPage;
						unsigned char *aData=pTrunk->aData;
						rc=WN_SQL3PagerWrite(pTrunk->pDbPage);
						if(rc)goto end_allocate_page;
						if(nearby>0)
						{
							int i,dist;
							closest=0;
							dist=get4byte(&aData[8])-nearby;
							if(dist<0)dist=-dist;
							for(i=1;i<k;i++)
							{
								int d2=get4byte(&aData[8+i*4])-nearby;
								if(d2<0)d2=-d2;
								if(d2<dist)
								{
									closest=i;
									dist=d2;
								}
							}
						}
						else
							closest=0;
						iPage=get4byte(&aData[8+closest*4]);
						if(!searchList || iPage==nearby)
						{
							*pPgno=iPage;
							if(*pPgno>WN_SQL3PagerPagecount(pBt->pPager))return WN_SQL_CORRUPT_BKPT;
							TRACE(("ALLOCATE:%d was leaf %d of %d on trunk %d"
":%d more free pages\n",*pPgno,closest+1,k,pTrunk->pgno,n-1));
							if(closest<k-1)memcpy(&aData[8+closest*4],&aData[4+k*4],4);
							put4byte(&aData[4],k-1);
							rc=WN_SQL3BtreeGetPage(pBt,*pPgno,ppPage,1);
							if(rc==0)
							{
								WN_SQL3PagerDontRollback((*ppPage)->pDbPage);
								rc=WN_SQL3PagerWrite((*ppPage)->pDbPage);
								if(rc)releasePage(*ppPage);
							}
							searchList=0;
						}
					}
					releasePage(pPrevTrunk);
					pPrevTrunk=0;
}while(searchList);
}
else
{
	*pPgno=WN_SQL3PagerPagecount(pBt->pPager)+1;
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->nTrunc)
	{
		*pPgno=pBt->nTrunc+1;
		if(*pPgno==PENDING_BYTE_PAGE(pBt))(*pPgno)++;
	}
	if(pBt->autoVacuum && PTRMAP_ISPAGE(pBt,*pPgno))
	{
		TRACE(("ALLOCATE:%d from end of file(pointer-map page)\n",*pPgno));
		(*pPgno)++;
	}
	if(pBt->nTrunc)pBt->nTrunc=*pPgno;
#endif
	rc=WN_SQL3BtreeGetPage(pBt,*pPgno,ppPage,0);
	if(rc)return rc;
	rc=WN_SQL3PagerWrite((*ppPage)->pDbPage);
	if(rc)releasePage(*ppPage);
	TRACE(("ALLOCATE:%d from end of file\n",*pPgno));
}
end_allocate_page:
	releasePage(pTrunk);
	releasePage(pPrevTrunk);
	return rc;
}
int freePage(MemPage *pPage)
{
	BtShared *pBt=pPage->pBt;
	MemPage *pPage1=pBt->pPage1;
	int rc,n,k;
	pPage->isInit=0;
	releasePage(pPage->pParent);
	pPage->pParent=0;
	if(rc=WN_SQL3PagerWrite(pPage1->pDbPage))return rc;
	n=get4byte(&pPage1->aData[36]);
	put4byte(&pPage1->aData[36],n+1);
#ifdef WN_SQL_SECURE_DELETE
	rc=WN_SQL3PagerWrite(pPage->pDbPage);
	if(rc)return rc;
	memset(pPage->aData,0,pPage->pBt->pageSize);
#endif
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->autoVacuum)
	{
		rc=ptrmapPut(pBt,pPage->pgno,PTRMAP_FREEPAGE,0);
		if(rc)return rc;
	}
#endif
	if(n==0)
	{
		rc=WN_SQL3PagerWrite(pPage->pDbPage);
		if(rc)return rc;
		memset(pPage->aData,0,8);
		put4byte(&pPage1->aData[32],pPage->pgno);
		TRACE(("FREE-PAGE:%d first\n",pPage->pgno));
	}
	else
	{
		MemPage *pTrunk;
		rc=WN_SQL3BtreeGetPage(pBt,get4byte(&pPage1->aData[32]),&pTrunk,0);
		if(rc)return rc;
		k=get4byte(&pTrunk->aData[4]);
		if(k>=pBt->usableSize/4-8)
		{
			rc=WN_SQL3PagerWrite(pPage->pDbPage);
			if(rc)return rc;
			put4byte(pPage->aData,pTrunk->pgno);
			put4byte(&pPage->aData[4],0);
			put4byte(&pPage1->aData[32],pPage->pgno);
			TRACE(("FREE-PAGE:%d new trunk page replacing %d\n",pPage->pgno,pTrunk->pgno));
		}
		else
		{
			rc=WN_SQL3PagerWrite(pTrunk->pDbPage);
			if(rc==0)
			{
				put4byte(&pTrunk->aData[4],k+1);
				put4byte(&pTrunk->aData[8+k*4],pPage->pgno);
#ifndef WN_SQL_SECURE_DELETE
				WN_SQL3PagerDontWrite(pPage->pDbPage);
#endif
			}
			TRACE(("FREE-PAGE:%d leaf on trunk page %d\n",pPage->pgno,pTrunk->pgno));
		}
		releasePage(pTrunk);
	}
	return rc;
}
int clearCell(MemPage *pPage,unsigned char *pCell)
{
	BtShared *pBt=pPage->pBt;
	CellInfo info;
	Pgno ovflPgno;
	int rc,nOvfl,ovflPageSize;
	WN_SQL3BtreeParseCellPtr(pPage,pCell,&info);
	if(info.iOverflow==0)return 0;
	ovflPgno=get4byte(&pCell[info.iOverflow]);
	ovflPageSize=pBt->usableSize-4;
	nOvfl=(info.nPayload-info.nLocal+ovflPageSize-1)/ovflPageSize;
	while(nOvfl--)
	{
		MemPage *pOvfl;
		if(ovflPgno==0 || ovflPgno>WN_SQL3PagerPagecount(pBt->pPager))return WN_SQL_CORRUPT_BKPT;
		rc=getOverflowPage(pBt,ovflPgno,&pOvfl,(nOvfl==0)?0:&ovflPgno);
		if(rc)return rc;
		rc=freePage(pOvfl);
		WN_SQL3PagerUnref(pOvfl->pDbPage);
		if(rc)return rc;
	}
	return 0;
}
int fillInCell(MemPage *pPage,unsigned char *pCell,const void *pKey,i64 nKey,const void *pData,int nData,int nZero,int *pnSize)
{
	int nPayload;
	const u8 *pSrc;
	int nSrc,n,rc,spaceLeft;
	MemPage *pOvfl=0,*pToRelease=0;
	unsigned char *pPrior,*pPayload;
	BtShared *pBt=pPage->pBt;
	Pgno pgnoOvfl=0;
	int nHeader;
	CellInfo info;
	nHeader=0;
	if(!pPage->leaf)nHeader+=4;
	if(pPage->hasData)
		nHeader+=putVarint(&pCell[nHeader],nData+nZero);
	else
		nData=nZero=0;
	nHeader+=putVarint(&pCell[nHeader],*(u64*)&nKey);
	WN_SQL3BtreeParseCellPtr(pPage,pCell,&info);
	nPayload=nData+nZero;
	if(pPage->intKey)
	{
		pSrc=pData;
		nSrc=nData;
		nData=0;
	}
	else
	{
		nPayload+=nKey;
		pSrc=pKey;
		nSrc=nKey;
	}
	*pnSize=info.nSize;
	spaceLeft=info.nLocal;
	pPayload=&pCell[nHeader];
	pPrior=&pCell[info.iOverflow];
	while(nPayload>0)
	{
		if(spaceLeft==0)
		{
			int isExact=0;
#ifndef WN_SQL_OMIT_AUTOVACUUM
			Pgno pgnoPtrmap=pgnoOvfl;
			if(pBt->autoVacuum)
			{
				do
				{
					pgnoOvfl++;
				}while(PTRMAP_ISPAGE(pBt,pgnoOvfl)|| pgnoOvfl==PENDING_BYTE_PAGE(pBt));
			}
#endif
			rc=allocateBtreePage(pBt,&pOvfl,&pgnoOvfl,pgnoOvfl,isExact);
#ifndef WN_SQL_OMIT_AUTOVACUUM
			if(pBt->autoVacuum && rc==0)
			{
				u8 eType=(pgnoPtrmap?PTRMAP_OVERFLOW2:PTRMAP_OVERFLOW1);
				rc=ptrmapPut(pBt,pgnoOvfl,eType,pgnoPtrmap);
				if(rc)releasePage(pOvfl);
			}
#endif
			if(rc)
			{
				releasePage(pToRelease);
				return rc;
			}
			put4byte(pPrior,pgnoOvfl);
			releasePage(pToRelease);
			pToRelease=pOvfl;
			pPrior=pOvfl->aData;
			put4byte(pPrior,0);
			pPayload=&pOvfl->aData[4];
			spaceLeft=pBt->usableSize-4;
		}
		n=nPayload;
		if(n>spaceLeft)n=spaceLeft;
		if(nSrc>0)
		{
			if(n>nSrc)n=nSrc;
			memcpy(pPayload,pSrc,n);
		}
		else
			memset(pPayload,0,n);
		nPayload-=n;
		pPayload+=n;
		pSrc+=n;
		nSrc-=n;
		spaceLeft-=n;
		if(nSrc==0)
		{
			nSrc=nData;
			pSrc=pData;
		}
	}
	releasePage(pToRelease);
	return 0;
}
int reparentPage(BtShared *pBt,Pgno pgno,MemPage *pNewParent,int idx)
{
	if(pgno==0)return 0;
	MemPage *pThis;
	DbPage *pDbPage=WN_SQL3PagerLookup(pBt->pPager,pgno);
	if(pDbPage)
	{
		pThis=(MemPage *)WN_SQL3PagerGetExtra(pDbPage);
		if(pThis->isInit)
		{
			if(pThis->pParent!=pNewParent)
			{
				if(pThis->pParent)WN_SQL3PagerUnref(pThis->pParent->pDbPage);
				pThis->pParent=pNewParent;
				WN_SQL3PagerRef(pNewParent->pDbPage);
			}
			pThis->idxParent=idx;
		}
		WN_SQL3PagerUnref(pDbPage);
	}
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->autoVacuum)return ptrmapPut(pBt,pgno,PTRMAP_BTREE,pNewParent->pgno);
#endif
	return 0;
}
int reparentChildPages(MemPage *pPage)
{
	int i;
	BtShared *pBt=pPage->pBt;
	int rc=0;
	if(pPage->leaf)return 0;
	for(i=0;i<pPage->nCell;i++)
	{
		u8 *pCell=findCell(pPage,i);
		if(!pPage->leaf)
		{
			rc=reparentPage(pBt,get4byte(pCell),pPage,i);
			if(rc)return rc;
		}
	}
	if(!pPage->leaf)
	{
		rc=reparentPage(pBt,get4byte(&pPage->aData[pPage->hdrOffset+8]),pPage,i);
		pPage->idxShift=0;
	}
	return rc;
}
void dropCell(MemPage *pPage,int idx,int sz)
{
	int i;
	u8 *data=pPage->aData,*ptr=&data[pPage->cellOffset+2*idx];
	int pc=get2byte(ptr);
	freeSpace(pPage,pc,sz);
	for(i=idx+1;i<pPage->nCell;i++,ptr+=2)
	{
		ptr[0]=ptr[2];
		ptr[1]=ptr[3];
	}
	pPage->nCell--;
	put2byte(&data[pPage->hdrOffset+3],pPage->nCell);
	pPage->nFree+=2;
	pPage->idxShift=1;
}
int insertCell(MemPage *pPage,int i,u8 *pCell,int sz,u8 *pTemp,u8 nSkip)
{
	int idx,j,top,end,ins,hdr,cellOffset;
	u8 *data,*ptr;
	if(pPage->nOverflow || sz+2>pPage->nFree)
	{
		if(pTemp)
		{
			memcpy(pTemp+nSkip,pCell+nSkip,sz-nSkip);
			pCell=pTemp;
		}
		j=pPage->nOverflow++;
		pPage->aOvfl[j].pCell=pCell;
		pPage->aOvfl[j].idx=i;
		pPage->nFree=0;
	}
	else
	{
		data=pPage->aData;
		hdr=pPage->hdrOffset;
		top=get2byte(&data[hdr+5]);
		cellOffset=pPage->cellOffset;
		end=cellOffset+2*pPage->nCell+2;
		ins=cellOffset+2*i;
		if(end > top-sz)
		{
			if(int rc=defragmentPage(pPage))return rc;
			top=get2byte(&data[hdr+5]);
		}
		idx=allocateSpace(pPage,sz);
		pPage->nCell++;
		pPage->nFree-=2;
		memcpy(&data[idx+nSkip],pCell+nSkip,sz-nSkip);
		for(j=end-2,ptr=&data[j];j>ins;j-=2,ptr-=2)
		{
			ptr[0]=ptr[-2];
			ptr[1]=ptr[-1];
		}
		put2byte(&data[ins],idx);
		put2byte(&data[hdr+3],pPage->nCell);
		pPage->idxShift=1;
#ifndef WN_SQL_OMIT_AUTOVACUUM
		if(pPage->pBt->autoVacuum)
		{
			CellInfo info;
			WN_SQL3BtreeParseCellPtr(pPage,pCell,&info);
			if((info.nData+(pPage->intKey?0:info.nKey))>info.nLocal)
			{
				Pgno pgnoOvfl=get4byte(&pCell[info.iOverflow]);
				if(int rc=ptrmapPut(pPage->pBt,pgnoOvfl,PTRMAP_OVERFLOW1,pPage->pgno))return rc;
			}
		}
#endif
	}
	return 0;
}
void assemblePage(MemPage *pPage,int nCell,u8 **apCell,int *aSize)
{
	int i,totalSize=0,hdr=pPage->hdrOffset,cellptr,cellbody;
	for(i=0;i<nCell;i++) totalSize+=aSize[i];
	cellptr=pPage->cellOffset;
	u8 *data=pPage->aData;
	put2byte(&data[hdr+3],nCell);
	if(nCell)
	{
		cellbody=allocateSpace(pPage,totalSize);
		pPage->nFree-=2*nCell;
		for(i=0;i<nCell;i++)
		{
			put2byte(&data[cellptr],cellbody);
			memcpy(&data[cellbody],apCell[i],aSize[i]);
			cellptr+=2;
			cellbody+=aSize[i];
		}
	}
	pPage->nCell=nCell;
}
#define NN 1
#define NB(NN*2+1)
#ifndef WN_SQL_OMIT_QUICKBALANCE
int balance_quick(MemPage *pPage,MemPage *pParent)
{
	int rc;
	MemPage *pNew;
	Pgno pgnoNew;
	u8 *pCell;
	int szCell;
	CellInfo info;
	BtShared *pBt=pPage->pBt;
	int parentIdx=pParent->nCell;
	int parentSize;
	u8 parentCell[64];
	rc=allocateBtreePage(pBt,&pNew,&pgnoNew,0,0);
	if(rc)return rc;
	pCell=pPage->aOvfl[0].pCell;
	szCell=cellSizePtr(pPage,pCell);
	zeroPage(pNew,pPage->aData[0]);
	assemblePage(pNew,1,&pCell,&szCell);
	pPage->nOverflow=0;
	pNew->pParent=pParent;
	WN_SQL3PagerRef(pParent->pDbPage);
	pCell=findCell(pPage,pPage->nCell-1);
	WN_SQL3BtreeParseCellPtr(pPage,pCell,&info);
	rc=fillInCell(pParent,parentCell,0,info.nKey,0,0,0,&parentSize);
	if(rc)return rc;
	rc=insertCell(pParent,parentIdx,parentCell,parentSize,0,4);
	if(rc)return rc;
	put4byte(findOverflowCell(pParent,parentIdx),pPage->pgno);
	put4byte(&pParent->aData[pParent->hdrOffset+8],pgnoNew);
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->autoVacuum)
	{
		rc=ptrmapPut(pBt,pgnoNew,PTRMAP_BTREE,pParent->pgno);
		if(rc==0)rc=ptrmapPutOvfl(pNew,0);
		if(rc)
		{
			releasePage(pNew);
			return rc;
		}
	}
#endif
	releasePage(pNew);
	return balance(pParent,0);
}
#endif
int balance_nonroot(MemPage *pPage)
{
	MemPage *pParent=pPage->pParent,*apOld[NB],*apCopy[NB],*apNew[NB+2];
	int nCell=0,nMaxCells=0,nOld,nNew,nDiv,i,j,k,idx,nxDiv,rc,leafCorrection,
		leafData,usableSpace,pageFlags,subtotal,iSpace=0,cntNew[NB+2],szNew[NB+2],*szCell;
	Pgno pgnoOld[NB],pgnoNew[NB+2];
	u8 *apDiv[NB],**apCell=0,*aCopy[NB],*aSpace;
#ifndef WN_SQL_OMIT_AUTOVACUUM
	u8 *aFrom=0;
#endif
	BtShared *pBt=pPage->pBt;
	if((rc=WN_SQL3PagerWrite(pParent->pDbPage)))return rc;
	TRACE(("BALANCE:begin page %d child of %d\n",pPage->pgno,pParent->pgno));
#ifndef WN_SQL_OMIT_QUICKBALANCE
	if(pPage->leaf && pPage->intKey && pPage->leafData && pPage->nOverflow==1 && pPage->aOvfl[0].idx==pPage->nCell && pPage->pParent->pgno!=1 && get4byte(&pParent->aData[pParent->hdrOffset+8])==pPage->pgno)return balance_quick(pPage,pParent);
#endif
	if(pParent->idxShift)
	{
		Pgno pgno=pPage->pgno;
		for(idx=0;idx<pParent->nCell;idx++)
			if(get4byte(findCell(pParent,idx))==pgno)break;
	}
	else
		idx=pPage->idxParent;
	nOld=nNew=0;
	WN_SQL3PagerRef(pParent->pDbPage);
	nxDiv=idx-NN;
	if(nxDiv+NB > pParent->nCell)nxDiv=pParent->nCell-NB+1;
	if(nxDiv<0)nxDiv=0;
	nDiv=0;
	for(i=0,k=nxDiv;i<NB;i++,k++)
	{
		if(k<pParent->nCell)
		{
			apDiv[i]=findCell(pParent,k);
			nDiv++;
			pgnoOld[i]=get4byte(apDiv[i]);
		}
		else
			if(k==pParent->nCell)
				pgnoOld[i]=get4byte(&pParent->aData[pParent->hdrOffset+8]);
			else
				break;
		if(rc=getAndInitPage(pBt,pgnoOld[i],&apOld[i],pParent))goto balance_cleanup;
		apOld[i]->idxParent=k;
		apCopy[i]=0;
		nOld++;
		nMaxCells+=1+apOld[i]->nCell+apOld[i]->nOverflow;
	}
	nMaxCells=(nMaxCells+1)&~1;
	apCell=WN_SQLMallocRaw(nMaxCells*sizeof(u8*)+nMaxCells*sizeof(int)+ROUND8(sizeof(MemPage))*NB+pBt->pageSize*(5+NB)+(ISAUTOVACUUM ? nMaxCells :0));
	if(apCell==0)
	{
		rc=WN_SQL_NOMEM;
		goto balance_cleanup;
	}
	szCell=(int*)&apCell[nMaxCells];
	aCopy[0]=(u8*)&szCell[nMaxCells];
	for(i=1;i<NB;i++)aCopy[i]=&aCopy[i-1][pBt->pageSize+ROUND8(sizeof(MemPage))];
	aSpace=&aCopy[NB-1][pBt->pageSize+ROUND8(sizeof(MemPage))];
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->autoVacuum)aFrom=&aSpace[5*pBt->pageSize];
#endif
	for(i=0;i<nOld;i++)
	{
		MemPage *p=apCopy[i]=(MemPage*)&aCopy[i][pBt->pageSize];
		p->aData=&((u8*)p)[-pBt->pageSize];
		memcpy(p->aData,apOld[i]->aData,pBt->pageSize+sizeof(MemPage));
		p->aData=&((u8*)p)[-pBt->pageSize];
	}
	nCell=0;
	leafCorrection=pPage->leaf*4;
	leafData=pPage->leafData && pPage->leaf;
	for(i=0;i<nOld;i++)
	{
		MemPage *pOld=apCopy[i];
		int limit=pOld->nCell+pOld->nOverflow;
		for(j=0;j<limit;j++)
		{
			apCell[nCell]=findOverflowCell(pOld,j);
			szCell[nCell]=cellSizePtr(pOld,apCell[nCell]);
#ifndef WN_SQL_OMIT_AUTOVACUUM
			if(pBt->autoVacuum)
			{
				int a;
				aFrom[nCell]=i;
				for(a=0;a<pOld->nOverflow;a++)
					if(pOld->aOvfl[a].pCell==apCell[nCell])
					{
						aFrom[nCell]=0xFF;
						break;
					}
			}
#endif
			nCell++;
		}
		if(i<nOld-1)
		{
			int sz=cellSizePtr(pParent,apDiv[i]);
			if(leafData)
				dropCell(pParent,nxDiv,sz);
			else
			{
				u8 *pTemp;
				szCell[nCell]=sz;
				pTemp=&aSpace[iSpace];
				iSpace+=sz;
				memcpy(pTemp,apDiv[i],sz);
				apCell[nCell]=pTemp+leafCorrection;
#ifndef WN_SQL_OMIT_AUTOVACUUM
				if(pBt->autoVacuum)aFrom[nCell]=0xFF;
#endif
				dropCell(pParent,nxDiv,sz);
				szCell[nCell]-=leafCorrection;
				if(!pOld->leaf)
					memcpy(apCell[nCell],&pOld->aData[pOld->hdrOffset+8],4);
				else
					if(szCell[nCell]<4)szCell[nCell]=4;
				nCell++;
			}
		}
	}
	usableSpace=pBt->usableSize-12+leafCorrection;
	for(subtotal=k=i=0;i<nCell;i++)
	{
		subtotal+=szCell[i]+2;
		if(subtotal>usableSpace)
		{
			szNew[k]=subtotal-szCell[i];
			cntNew[k]=i;
			if(leafData)i--;
			subtotal=0;
			k++;
		}
	}
	szNew[k]=subtotal;
	cntNew[k]=nCell;
	k++;
	for(i=k-1;i>0;i--)
	{
		int szRight=szNew[i],szLeft=szNew[i-1],r=cntNew[i-1]-1,d=r+1-leafData;
		while(szRight==0 || szRight+szCell[d]+2<=szLeft-(szCell[r]+2))
		{
			szRight+=szCell[d]+2;
			szLeft-=szCell[r]+2;
			cntNew[i-1]--;
			r=cntNew[i-1]-1;
			d=r+1-leafData;
		}
		szNew[i]=szRight;
		szNew[i-1]=szLeft;
	}
	pageFlags=pPage->aData[0];
	for(i=0;i<k;i++)
	{
		MemPage *pNew;
		if(i<nOld)
		{
			pNew=apNew[i]=apOld[i];
			pgnoNew[i]=pgnoOld[i];
			apOld[i]=0;
			rc=WN_SQL3PagerWrite(pNew->pDbPage);
			nNew++;
			if(rc)goto balance_cleanup;
		}
		else
		{
			rc=allocateBtreePage(pBt,&pNew,&pgnoNew[i],pgnoNew[i-1],0);
			if(rc)goto balance_cleanup;
			apNew[i]=pNew;
			nNew++;
		}
		zeroPage(pNew,pageFlags);
	}
	while(i<nOld)
	{
		if(=freePage(apOld[i]))goto balance_cleanup;
		releasePage(apOld[i]);
		apOld[i]=0;
		i++;
	}
	for(i=0;i<k-1;i++)
	{
		int minV=pgnoNew[i],minI=i;
		for(j=i+1;j<k;j++)
			if(pgnoNew[j]<(unsigned)minV)
			{
				minI=j;
				minV=pgnoNew[j];
			}
		if(minI>i)
		{
			int t;
			MemPage *pT;
			t=pgnoNew[i];
			pT=apNew[i];
			pgnoNew[i]=pgnoNew[minI];
			apNew[i]=apNew[minI];
			pgnoNew[minI]=t;
			apNew[minI]=pT;
		}
	}
	TRACE(("BALANCE:old:%d %d %d new:%d(%d)%d(%d)%d(%d)%d(%d)%d(%d)\n",pgnoOld[0],nOld>=2 ? pgnoOld[1] :0,nOld>=3 ? pgnoOld[2] :0,pgnoNew[0],szNew[0],nNew>=2 ? pgnoNew[1] :0,nNew>=2 ? szNew[1] :0,nNew>=3 ? pgnoNew[2] :0,nNew>=3 ? szNew[2] :0,nNew>=4 ? pgnoNew[3] :0,nNew>=4 ? szNew[3] :0,nNew>=5 ? pgnoNew[4] :0,nNew>=5 ? szNew[4] :0));
	j=0;
	for(i=0;i<nNew;i++)
	{
		MemPage *pNew=apNew[i];
		assemblePage(pNew,cntNew[i]-j,&apCell[j],&szCell[j]);
#ifndef WN_SQL_OMIT_AUTOVACUUM
		if(pBt->autoVacuum)
			for(k=j;k<cntNew[i];k++)
				if(aFrom[k]==0xFF || apCopy[aFrom[k]]->pgno!=pNew->pgno)
				{
					rc=ptrmapPutOvfl(pNew,k-j);
					if(rc)goto balance_cleanup;
				}
#endif
		j=cntNew[i];
		if(i<nNew-1 && j<nCell)
		{
			u8 *pCell,*pTemp;
			int sz;
			pCell=apCell[j];
			sz=szCell[j]+leafCorrection;
			if(!pNew->leaf)
			{
				memcpy(&pNew->aData[8],pCell,4);
				pTemp=0;
			}
			else
				if(leafData)
				{
					CellInfo info;
					j--;
					WN_SQL3BtreeParseCellPtr(pNew,apCell[j],&info);
					pCell=&aSpace[iSpace];
					fillInCell(pParent,pCell,0,info.nKey,0,0,0,&sz);
					iSpace+=sz;
					pTemp=0;
				}
				else
				{
					pCell-=4;
					pTemp=&aSpace[iSpace];
					iSpace+=sz;
					if(szCell[j]==4)sz=cellSizePtr(pParent,pCell);
				}
				rc=insertCell(pParent,nxDiv,pCell,sz,pTemp,4);
				if(rc)goto balance_cleanup;
				put4byte(findOverflowCell(pParent,nxDiv),pNew->pgno);
#ifndef WN_SQL_OMIT_AUTOVACUUM
				if(pBt->autoVacuum && !leafData)
					if(rc=ptrmapPutOvfl(pParent,nxDiv))goto balance_cleanup;
#endif
				j++;
				nxDiv++;
		}
	}
	if((pageFlags & PTF_LEAF)==0)memcpy(&apNew[nNew-1]->aData[8],&apCopy[nOld-1]->aData[8],4);
	if(nxDiv==pParent->nCell+pParent->nOverflow)
		put4byte(&pParent->aData[pParent->hdrOffset+8],pgnoNew[nNew-1]);
	else
		put4byte(findOverflowCell(pParent,nxDiv),pgnoNew[nNew-1]);
	for(i=0;i<nNew;i++)
	{
		rc=reparentChildPages(apNew[i]);
		if(rc)goto balance_cleanup;
	}
	rc=reparentChildPages(pParent);
	if(rc)goto balance_cleanup;
	rc=balance(pParent,0);
balance_cleanup:
	WN_SQL3FreeX(apCell);
	for(i=0;i<nOld;i++)releasePage(apOld[i]);
	for(i=0;i<nNew;i++)releasePage(apNew[i]);
	releasePage(pParent);
	TRACE(("BALANCE:finished with %d:old=%d new=%d cells=%d\n",pPage->pgno,nOld,nNew,nCell));
	return rc;
}
int balance_shallower(MemPage *pPage)
{
	MemPage *pChild;
	Pgno pgnoChild;
	int rc=0;
	BtShared *pBt=pPage->pBt;
	int mxCellPerPage=MX_CELL(pBt);
	u8 **apCell=WN_SQLMallocRaw(mxCellPerPage*(sizeof(u8*)+sizeof(int)));
	if(apCell==0)return WN_SQL_NOMEM;
	int *szCell=(int*)&apCell[mxCellPerPage];
	if(pPage->leaf)
		TRACE(("BALANCE:empty table %d\n",pPage->pgno));
	else
	{
		pgnoChild=get4byte(&pPage->aData[pPage->hdrOffset+8]);
		rc=WN_SQL3BtreeGetPage(pPage->pBt,pgnoChild,&pChild,0);
		if(rc)goto end_shallow_balance;
		if(pPage->pgno==1)
		{
			rc=WN_SQL3BtreeInitPage(pChild,pPage);
			if(rc)goto end_shallow_balance;
			if(pChild->nFree>=100)
			{
				int i;
				zeroPage(pPage,pChild->aData[0]);
				for(i=0;i<pChild->nCell;i++)
				{
					apCell[i]=findCell(pChild,i);
					szCell[i]=cellSizePtr(pChild,apCell[i]);
				}
				assemblePage(pPage,pChild->nCell,apCell,szCell);
				put4byte(&pPage->aData[pPage->hdrOffset+8],get4byte(&pChild->aData[pChild->hdrOffset+8]));
				freePage(pChild);
				TRACE(("BALANCE:child %d transfer to page 1\n",pChild->pgno));
			}
			else
				TRACE(("BALANCE:child %d will not fit on page 1\n",pChild->pgno));
		}
		else
		{
			memcpy(pPage->aData,pChild->aData,pPage->pBt->usableSize);
			pPage->isInit=0;
			pPage->pParent=0;
			rc=WN_SQL3BtreeInitPage(pPage,0);
			freePage(pChild);
			TRACE(("BALANCE:transfer child %d into root %d\n",pChild->pgno,pPage->pgno));
		}
		rc=reparentChildPages(pPage);
#ifndef WN_SQL_OMIT_AUTOVACUUM
		if(pBt->autoVacuum)
		{
			int i;
			for(i=0;i<pPage->nCell;i++)
			{
				rc=ptrmapPutOvfl(pPage,i);
				if(rc)goto end_shallow_balance;
			}
		}
#endif
		if(rc)goto end_shallow_balance;
		releasePage(pChild);
	}
end_shallow_balance:
	WN_SQL3FreeX(apCell);
	return rc;
}
int balance_deeper(MemPage *pPage)
{
	MemPage *pChild;
	Pgno pgnoChild;
	BtShared *pBt=pPage->pBt;
	int rc=allocateBtreePage(pBt,&pChild,&pgnoChild,pPage->pgno,0);
	if(rc)return rc;
	int usableSize=pBt->usableSize;
	u8 *data=pPage->aData,cdata=pChild->aData;
	int hdr=pPage->hdrOffset,brk=get2byte(&data[hdr+5]);
	memcpy(cdata,&data[hdr],pPage->cellOffset+2*pPage->nCell-hdr);
	memcpy(&cdata[brk],&data[brk],usableSize-brk);
	rc=WN_SQL3BtreeInitPage(pChild,pPage);
	if(rc)goto balancedeeper_out;
	memcpy(pChild->aOvfl,pPage->aOvfl,pPage->nOverflow*sizeof(pPage->aOvfl[0]));
	pChild->nOverflow=pPage->nOverflow;
	if(pChild->nOverflow)pChild->nFree=0;
	zeroPage(pPage,pChild->aData[0] & ~PTF_LEAF);
	put4byte(&pPage->aData[pPage->hdrOffset+8],pgnoChild);
	TRACE(("BALANCE:copy root %d into %d\n",pPage->pgno,pChild->pgno));
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->autoVacuum)
	{
		int i;
		rc=ptrmapPut(pBt,pChild->pgno,PTRMAP_BTREE,pPage->pgno);
		if(rc)goto balancedeeper_out;
		for(i=0;i<pChild->nCell;i++)
			if(rc=ptrmapPutOvfl(pChild,i))return rc;
	}
#endif
	rc=balance_nonroot(pChild);
balancedeeper_out:
	releasePage(pChild);
	return rc;
}
int balance(MemPage *pPage,int insert)
{
	int rc=0;
	if(pPage->pParent==0)
	{
		if(pPage->nOverflow>0)rc=balance_deeper(pPage);
		if(rc==0 && pPage->nCell==0)rc=balance_shallower(pPage);
	}
	else
		if(pPage->nOverflow>0 || (!insert && pPage->nFree>pPage->pBt->usableSize*2/3))rc=balance_nonroot(pPage);
	return rc;
}
int checkReadLocks(Btree *pBtree,Pgno pgnoRoot,BtCursor *pExclude)
{
	BtCursor *p;
	BtShared *pBt=pBtree->pBt;
	WN_SQL3 *db=pBtree->pWN_SQL;
	for(p=pBt->pCursor;p;p=p->pNext)
	{
		if(p==pExclude)continue;
		if(p->eState!=CURSOR_VALID)continue;
		if(p->pgnoRoot!=pgnoRoot)continue;
		if(p->wrFlag==0)
		{
			WN_SQL3 *dbOther=p->pBtree->pWN_SQL;
			if(dbOther==0 || (dbOther!=db &&(dbOther->flags & WN_SQL_ReadUncommitted)==0))return WN_SQL_LOCKED;
		}
		else
			if(p->pPage->pgno!=p->pgnoRoot)moveToRoot(p);
	}
	return 0;
}
int WN_SQL3BtreeInsert(BtCursor *pCur,const void *pKey,i64 nKey,const void *pData,int nData,int nZero,int appendBias)
{
	int rc,loc,szNew;
	MemPage *pPage;
	BtShared *pBt=pCur->pBtree->pBt;
	unsigned char *oldCell,*newCell=0;
	if(pBt->inTransaction!=TRANS_WRITE)return pBt->readOnly ? WN_SQL_READONLY :WN_SQL_ERROR;
	if(!pCur->wrFlag)return WN_SQL_PERM;
	if(checkReadLocks(pCur->pBtree,pCur->pgnoRoot,pCur))return WN_SQL_LOCKED;
	clearCursorPosition(pCur);
	if((rc=saveAllCursors(pBt,pCur->pgnoRoot,pCur))||(rc=WN_SQL3BtreeMoveto(pCur,pKey,nKey,appendBias,&loc)))return rc;
	pPage=pCur->pPage;
	TRACE(("INSERT:table=%d nkey=%lld ndata=%d page=%d %s\n",pCur->pgnoRoot,nKey,nData,pPage->pgno,loc==0 ? "overwrite" :"new entry"));
	if(rc=WN_SQL3PagerWrite(pPage->pDbPage))return rc;
	newCell=WN_SQLMallocRaw(MX_CELL_SIZE(pBt));
	if(newCell==0)return WN_SQL_NOMEM;
	if(rc=fillInCell(pPage,newCell,pKey,nKey,pData,nData,nZero,&szNew))goto end_insert;
	if(loc==0 && CURSOR_VALID==pCur->eState)
	{
		int szOld;
		oldCell=findCell(pPage,pCur->idx);
		if(!pPage->leaf)memcpy(newCell,oldCell,4);
		szOld=cellSizePtr(pPage,oldCell);
		if(rc=clearCell(pPage,oldCell))goto end_insert;
		dropCell(pPage,pCur->idx,szOld);
	}
	else
		if(loc<0 && pPage->nCell>0)
		{
			pCur->idx++;
			pCur->info.nSize=0;
		}
		if(rc=insertCell(pPage,pCur->idx,newCell,szNew,0,0))goto end_insert;
		rc=balance(pPage,1);
		if(rc==0)moveToRoot(pCur);
end_insert:
		WN_SQL3FreeX(newCell);
		return rc;
}
int WN_SQL3BtreeDelete(BtCursor *pCur)
{
	MemPage *pPage=pCur->pPage;
	unsigned char *pCell;
	int rc;
	Pgno pgnoChild=0;
	BtShared *pBt=pCur->pBtree->pBt;
	if(pBt->inTransaction!=TRANS_WRITE)return pBt->readOnly ? WN_SQL_READONLY :WN_SQL_ERROR;
	if(pCur->idx >=pPage->nCell)return WN_SQL_ERROR;
	if(!pCur->wrFlag)return WN_SQL_PERM;
	if(checkReadLocks(pCur->pBtree,pCur->pgnoRoot,pCur))return WN_SQL_LOCKED;
	if((rc=restoreOrClearCursorPosition(pCur))||(rc=saveAllCursors(pBt,		pCur->pgnoRoot,pCur))||(rc=WN_SQL3PagerWrite(pPage->pDbPage)))return rc;
	pCell=findCell(pPage,pCur->idx);
	if(!pPage->leaf)pgnoChild=get4byte(pCell);
	rc=clearCell(pPage,pCell);
	if(rc)return rc;
	if(!pPage->leaf)
	{
		BtCursor leafCur;
		unsigned char *pNext;
		int szNext;
		int notUsed;
		unsigned char *tempCell=0;
		WN_SQL3BtreeGetTempCursor(pCur,&leafCur);
		rc=WN_SQL3BtreeNext(&leafCur,&notUsed);
		if(rc==0)rc=WN_SQL3PagerWrite(leafCur.pPage->pDbPage);
		if(rc==0)
		{
			TRACE(("DELETE:table=%d delete internal from %d replace from leaf %d\n",pCur->pgnoRoot,pPage->pgno,leafCur.pPage->pgno));
			dropCell(pPage,pCur->idx,cellSizePtr(pPage,pCell));
			pNext=findCell(leafCur.pPage,leafCur.idx);
			szNext=cellSizePtr(leafCur.pPage,pNext);
						tempCell=WN_SQLMallocRaw(MX_CELL_SIZE(pBt));
			if(tempCell==0)
				rc=WN_SQL_NOMEM;
		}
		if(rc==0)rc=insertCell(pPage,pCur->idx,pNext-4,szNext+4,tempCell,0);
		if(rc==0)
		{
			put4byte(findOverflowCell(pPage,pCur->idx),pgnoChild);
			rc=balance(pPage,0);
		}
		if(rc==0)
		{
			dropCell(leafCur.pPage,leafCur.idx,szNext);
			rc=balance(leafCur.pPage,0);
		}
		WN_SQL3FreeX(tempCell);
		WN_SQL3BtreeReleaseTempCursor(&leafCur);
	}
	else
	{
		TRACE(("DELETE:table=%d delete from leaf %d\n",pCur->pgnoRoot,pPage->pgno));
		dropCell(pPage,pCur->idx,cellSizePtr(pPage,pCell));
		rc=balance(pPage,0);
	}
	if(rc==0)moveToRoot(pCur);
	return rc;
}
int WN_SQL3BtreeCreateTable(Btree *p,int *piTable,int flags)
{
	BtShared *pBt=p->pBt;
	MemPage *pRoot;
	Pgno pgnoRoot;
	int rc;
	if(pBt->inTransaction!=TRANS_WRITE)return pBt->readOnly ? WN_SQL_READONLY :WN_SQL_ERROR;
	#ifdef WN_SQL_OMIT_AUTOVACUUM
rc=allocateBtreePage(pBt,&pRoot,&pgnoRoot,1,0);
if(rc)return rc;
#else
	if(pBt->autoVacuum)
	{
		Pgno pgnoMove;
		MemPage *pPageMove;
		invalidateAllOverflowCache(pBt);
		rc=WN_SQL3BtreeGetMeta(p,4,&pgnoRoot);
		if(rc)return rc;
		pgnoRoot++;
		if(pgnoRoot==PTRMAP_PAGENO(pBt,pgnoRoot)||pgnoRoot==PENDING_BYTE_PAGE(pBt))pgnoRoot++;
		if(rc=allocateBtreePage(pBt,&pPageMove,&pgnoMove,pgnoRoot,1))return rc;
		if(pgnoMove!=pgnoRoot)
		{
			u8 eType;
			Pgno iPtrPage;
			releasePage(pPageMove);
			rc=WN_SQL3BtreeGetPage(pBt,pgnoRoot,&pRoot,0);
			if(rc)return rc;
			rc=ptrmapGet(pBt,pgnoRoot,&eType,&iPtrPage);
			if(rc || eType==PTRMAP_ROOTPAGE || eType==PTRMAP_FREEPAGE)
			{
				releasePage(pRoot);
				return rc;
			}
			rc=WN_SQL3PagerWrite(pRoot->pDbPage);
			if(rc)
			{
				releasePage(pRoot);
				return rc;
			}
			rc=relocatePage(pBt,pRoot,eType,iPtrPage,pgnoMove);
			releasePage(pRoot);
			if(rc)return rc;
			if(rc=WN_SQL3BtreeGetPage(pBt,pgnoRoot,&pRoot,0))return rc;
			rc=WN_SQL3PagerWrite(pRoot->pDbPage);
			if(rc)
			{
				releasePage(pRoot);
				return rc;
			}
		}
		else
			pRoot=pPageMove;
		rc=ptrmapPut(pBt,pgnoRoot,PTRMAP_ROOTPAGE,0);
		if(rc)
		{
			releasePage(pRoot);
			return rc;
		}
		rc=WN_SQL3BtreeUpdateMeta(p,4,pgnoRoot);
		if(rc)
		{
			releasePage(pRoot);
			return rc;
		}
	}
	else
		if(rc=allocateBtreePage(pBt,&pRoot,&pgnoRoot,1,0))return rc;
#endif
	zeroPage(pRoot,flags | PTF_LEAF);
	WN_SQL3PagerUnref(pRoot->pDbPage);
	*piTable=(int)pgnoRoot;
	return 0;
}
int clearDatabasePage(BtShared *pBt,Pgno pgno,MemPage *pParent,int freePageFlag)
{
	MemPage *pPage=0;
	int rc;
	unsigned char *pCell;
	int i;
	if(pgno>WN_SQL3PagerPagecount(pBt->pPager))return WN_SQL_CORRUPT_BKPT;
	rc=getAndInitPage(pBt,pgno,&pPage,pParent);
	if(rc)goto cleardatabasepage_out;
	for(i=0;i<pPage->nCell;i++)
	{
		pCell=findCell(pPage,i);
		if(!pPage->leaf)
		{
			rc=clearDatabasePage(pBt,get4byte(pCell),pPage->pParent,1);
			if(rc)goto cleardatabasepage_out;
		}
		rc=clearCell(pPage,pCell);
		if(rc)goto cleardatabasepage_out;
	}
	if(!pPage->leaf)
	{
		rc=clearDatabasePage(pBt,get4byte(&pPage->aData[8]),pPage->pParent,1);
		if(rc)goto cleardatabasepage_out;
	}
	if(freePageFlag)
		rc=freePage(pPage);
	else
		if((rc=WN_SQL3PagerWrite(pPage->pDbPage))==0)zeroPage(pPage,pPage->aData[0] | PTF_LEAF);
cleardatabasepage_out:
	releasePage(pPage);
	return rc;
}
int WN_SQL3BtreeClearTable(Btree *p,int iTable)
{
	int rc;
	BtShared *pBt=p->pBt;
	if(p->inTrans!=TRANS_WRITE)return pBt->readOnly ? WN_SQL_READONLY :WN_SQL_ERROR;
	rc=checkReadLocks(p,iTable,0);
	if(rc)return rc;
	if((rc=saveAllCursors(pBt,iTable,0)))return rc;
	return clearDatabasePage(pBt,(Pgno)iTable,0,0);
}
int WN_SQL3BtreeDropTable(Btree *p,int iTable,int *piMoved)
{
	int rc;
	MemPage *pPage=0;
	BtShared *pBt=p->pBt;
	if(p->inTrans!=TRANS_WRITE)return pBt->readOnly ? WN_SQL_READONLY :WN_SQL_ERROR;
	if(pBt->pCursor)return WN_SQL_LOCKED;
	if(rc=WN_SQL3BtreeGetPage(pBt,(Pgno)iTable,&pPage,0))return rc;
	if(rc=WN_SQL3BtreeClearTable(p,iTable))
	{
		releasePage(pPage);
		return rc;
	}
	*piMoved=0;
	if(iTable>1)
	{
#ifdef WN_SQL_OMIT_AUTOVACUUM
	rc=freePage(pPage);
	releasePage(pPage);
#else
	if(pBt->autoVacuum)
	{
		Pgno maxRootPgno;
		rc=WN_SQL3BtreeGetMeta(p,4,&maxRootPgno);
		if(rc)
		{
			releasePage(pPage);
			return rc;
		}
		if(iTable==maxRootPgno)
		{
			rc=freePage(pPage);
			releasePage(pPage);
			if(rc)return rc;
		}
		else
		{
			MemPage *pMove;
			releasePage(pPage);
			if(rc=WN_SQL3BtreeGetPage(pBt,maxRootPgno,&pMove,0))return rc;
			rc=relocatePage(pBt,pMove,PTRMAP_ROOTPAGE,0,iTable);
			releasePage(pMove);
			if(rc)return rc;
			if(rc=WN_SQL3BtreeGetPage(pBt,maxRootPgno,&pMove,0))return rc;
			rc=freePage(pMove);
			releasePage(pMove);
			if(rc)return rc;
			*piMoved=maxRootPgno;
		}
		maxRootPgno--;
		if(maxRootPgno==PENDING_BYTE_PAGE(pBt))maxRootPgno--;
		if(maxRootPgno==PTRMAP_PAGENO(pBt,maxRootPgno))maxRootPgno--;
		rc=WN_SQL3BtreeUpdateMeta(p,4,maxRootPgno);
	}
	else
	{
		rc=freePage(pPage);
		releasePage(pPage);
	}
#endif
	}
	else
	{
		zeroPage(pPage,PTF_INTKEY|PTF_LEAF);
		releasePage(pPage);
	}
	return rc;
}
int WN_SQL3BtreeGetMeta(Btree *p,int idx,u32 *pMeta)
{
	DbPage *pDbPage;
	int rc;
	BtShared *pBt=p->pBt;
	if(rc=queryTableLock(p,1,READ_LOCK))return rc;
	if(rc=WN_SQL3PagerGet(pBt->pPager,1,&pDbPage))return rc;
	unsigned char *pP1=(unsigned char *)WN_SQL3PagerGetData(pDbPage);
	*pMeta=get4byte(&pP1[36+idx*4]);
	WN_SQL3PagerUnref(pDbPage);
#ifdef WN_SQL_OMIT_AUTOVACUUM
	if(idx==4 && *pMeta>0)pBt->readOnly=1;
#endif
	return lockTable(p,1,READ_LOCK);
}
int WN_SQL3BtreeUpdateMeta(Btree *p,int idx,u32 iMeta)
{
	BtShared *pBt=p->pBt;
	unsigned char *pP1;
	int rc;
	if(p->inTrans!=TRANS_WRITE)return pBt->readOnly ? WN_SQL_READONLY :WN_SQL_ERROR;
	pP1=pBt->pPage1->aData;
	if(rc=WN_SQL3PagerWrite(pBt->pPage1->pDbPage))return rc;
	put4byte(&pP1[36+idx*4],iMeta);
	if(idx==7)pBt->incrVacuum=iMeta;
	return 0;
}
int WN_SQL3BtreeFlags(BtCursor *pCur)
{
	MemPage *pPage=pCur->pPage;
	return pPage ? pPage->aData[pPage->hdrOffset] :0;
}
Pager *WN_SQL3BtreePager(Btree *p)
{
	return p->pBt->pPager;
}
#ifndef WN_SQL_OMIT_INTEGRITY_CHECK
void checkAppendMsg(IntegrityCk *pCheck,char *zMsg1,const char *zFormat,...)
{
	va_list ap;
	if(!pCheck->mxErr)return;
	pCheck->mxErr--;
	pCheck->nErr++;
	va_start(ap,zFormat);
	char *zMsg2=WN_SQL3VMPrintf(zFormat,ap);
	va_end(ap);
	if(zMsg1==0)zMsg1="";
	if(pCheck->zErrMsg)
	{
		char *zOld=pCheck->zErrMsg;
		pCheck->zErrMsg=0;
		WN_SQL3SetString(&pCheck->zErrMsg,zOld,"\n",zMsg1,zMsg2,(char*)0);
		WN_SQL3FreeX(zOld);
	}
	else
		WN_SQL3SetString(&pCheck->zErrMsg,zMsg1,zMsg2,(char*)0);
	WN_SQL3FreeX(zMsg2);
}
#endif
#ifndef WN_SQL_OMIT_INTEGRITY_CHECK
int checkRef(IntegrityCk *pCheck,int iPage,char *zContext)
{
	if(iPage==0)return 1;
	if(iPage>pCheck->nPage || iPage<0)
	{
		checkAppendMsg(pCheck,zContext,"invalid page number %d",iPage);
		return 1;
	}
	if(pCheck->anRef[iPage]==1)
	{
		checkAppendMsg(pCheck,zContext,"2nd reference to page %d",iPage);
		return 1;
	}
	return(pCheck->anRef[iPage]++)>1;
}
#ifndef WN_SQL_OMIT_AUTOVACUUM
void checkPtrmap(IntegrityCk *pCheck,Pgno iChild,u8 eType,Pgno iParent,char *zContext)
{
	u8 ePtrmapType;
	Pgno iPtrmapParent;
	int rc=ptrmapGet(pCheck->pBt,iChild,&ePtrmapType,&iPtrmapParent);
	if(rc)
	{
		checkAppendMsg(pCheck,zContext,"Failed to read ptrmap key=%d",iChild);
		return;
	}
	if(ePtrmapType!=eType || iPtrmapParent!=iParent)
		checkAppendMsg(pCheck,zContext,"Bad ptr map entry key=%d expected=(%d,%d)got=(%d,%d)",iChild,eType,iParent,ePtrmapType,iPtrmapParent);
}
#endif
void checkList(IntegrityCk *pCheck,int isFreeList,int iPage,int N,char *zContext)
{
	int i,expected=N,iFirst=iPage;
	while(N-->0 && pCheck->mxErr)
	{
		DbPage *pOvflPage;
		unsigned char *pOvflData;
		if(iPage<1)
		{
			checkAppendMsg(pCheck,zContext,"%d of %d pages missing from overflow list starting at %d",N+1,expected,iFirst);
			break;
		}
		if(checkRef(pCheck,iPage,zContext))break;
		if(WN_SQL3PagerGet(pCheck->pPager,(Pgno)iPage,&pOvflPage))
		{
			checkAppendMsg(pCheck,zContext,"failed to get page %d",iPage);
			break;
		}
		pOvflData=(unsigned char *)WN_SQL3PagerGetData(pOvflPage);
		if(isFreeList)
		{
			int n=get4byte(&pOvflData[4]);
#ifndef WN_SQL_OMIT_AUTOVACUUM
			if(pCheck->pBt->autoVacuum)checkPtrmap(pCheck,iPage,PTRMAP_FREEPAGE,0,zContext);
#endif
			if(n>pCheck->pBt->usableSize/4-8)
			{
				checkAppendMsg(pCheck,zContext,"freelist leaf count too big on page %d",iPage);
				N--;
			}
			else
			{
				for(i=0;i<n;i++)
				{
					Pgno iFreePage=get4byte(&pOvflData[8+i*4]);
#ifndef WN_SQL_OMIT_AUTOVACUUM
					if(pCheck->pBt->autoVacuum)
						checkPtrmap(pCheck,iFreePage,PTRMAP_FREEPAGE,0,zContext);
#endif
					checkRef(pCheck,iFreePage,zContext);
				}
				N-=n;
			}
		}
#ifndef WN_SQL_OMIT_AUTOVACUUM
		else
			if(pCheck->pBt->autoVacuum && N>0)
			{
				i=get4byte(pOvflData);
				checkPtrmap(pCheck,i,PTRMAP_OVERFLOW2,iPage,zContext);
			}
#endif
		iPage=get4byte(pOvflData);
		WN_SQL3PagerUnref(pOvflPage);
	}
}
#endif
#ifndef WN_SQL_OMIT_INTEGRITY_CHECK
int checkTreePage(IntegrityCk *pCheck,int iPage,MemPage *pParent,char *zParentContext)
{
	MemPage *pPage;
	int i,rc,depth,d2,pgno,cnt,hdr,cellStart,nCell;
	u8 *data;
	char zContext[100],*hit;
	WN_SQL3_snprintf(sizeof(zContext),zContext,"Page %d:",iPage);
	BtShared *pBt=pCheck->pBt;
	int usableSize=pBt->usableSize;
	if(iPage==0)return 0;
	if(checkRef(pCheck,iPage,zParentContext))return 0;
	if((rc=WN_SQL3BtreeGetPage(pBt,(Pgno)iPage,&pPage,0)))
	{
		checkAppendMsg(pCheck,zContext,"unable to get the page. error code=%d",rc);
		return 0;
	}
	if((rc=WN_SQL3BtreeInitPage(pPage,pParent)))
	{
		checkAppendMsg(pCheck,zContext,"WN_SQL3BtreeInitPage()returns error code %d",rc);
		releasePage(pPage);
		return 0;
	}
	depth=0;
	for(i=0;i<pPage->nCell && pCheck->mxErr;i++)
	{
		u8 *pCell;
		int sz;
		CellInfo info;
		WN_SQL3_snprintf(sizeof(zContext),zContext,"On tree page %d cell %d:",iPage,i);
		pCell=findCell(pPage,i);
		WN_SQL3BtreeParseCellPtr(pPage,pCell,&info);
		sz=info.nData;
		if(!pPage->intKey)sz+=info.nKey;
		if(sz>info.nLocal)
		{
			int nPage=(sz-info.nLocal+usableSize-5)/(usableSize-4);
			Pgno pgnoOvfl=get4byte(&pCell[info.iOverflow]);
#ifndef WN_SQL_OMIT_AUTOVACUUM
			if(pBt->autoVacuum)checkPtrmap(pCheck,pgnoOvfl,PTRMAP_OVERFLOW1,iPage,zContext);
#endif
			checkList(pCheck,0,pgnoOvfl,nPage,zContext);
		}
		if(!pPage->leaf)
		{
			pgno=get4byte(pCell);
#ifndef WN_SQL_OMIT_AUTOVACUUM
			if(pBt->autoVacuum)checkPtrmap(pCheck,pgno,PTRMAP_BTREE,iPage,zContext);
#endif
			d2=checkTreePage(pCheck,pgno,pPage,zContext);
			if(i>0 && d2!=depth)checkAppendMsg(pCheck,zContext,"Child page depth differs");
			depth=d2;
		}
	}
	if(!pPage->leaf)
	{
		pgno=get4byte(&pPage->aData[pPage->hdrOffset+8]);
		WN_SQL3_snprintf(sizeof(zContext),zContext,"On page %d at right child:",iPage);
#ifndef WN_SQL_OMIT_AUTOVACUUM
		if(pBt->autoVacuum)checkPtrmap(pCheck,pgno,PTRMAP_BTREE,iPage,0);
#endif
		checkTreePage(pCheck,pgno,pPage,zContext);
	}
	data=pPage->aData;
	hdr=pPage->hdrOffset;
	hit=WN_SQL3Malloc(usableSize);
	if(hit)
	{
		memset(hit,1,get2byte(&data[hdr+5]));
		nCell=get2byte(&data[hdr+3]);
		cellStart=hdr+12-4*pPage->leaf;
		for(i=0;i<nCell;i++)
		{
			int pc=get2byte(&data[cellStart+i*2]),size=cellSizePtr(pPage,&data[pc]),j;
			if((pc+size-1)>=usableSize || pc<0)
				checkAppendMsg(pCheck,0,"Corruption detected in cell %d on page %d",i,iPage,0);
			else
				for(j=pc+size-1;j>=pc;j--)hit[j]++;
		}
		for(cnt=0,i=get2byte(&data[hdr+1]);i>0 && i<usableSize && cnt<10000;cnt++)
		{
			int size=get2byte(&data[i+2]);
			int j;
			if((i+size-1)>=usableSize || i<0)
				checkAppendMsg(pCheck,0,"Corruption detected in cell %d on page %d",i,iPage,0);
			else
				for(j=i+size-1;j>=i;j--)hit[j]++;
			i=get2byte(&data[i]);
		}
		for(i=cnt=0;i<usableSize;i++)
			if(hit[i]==0)
				cnt++;
			else
				if(hit[i]>1)
				{
					checkAppendMsg(pCheck,0,"Multiple uses for byte %d of page %d",i,iPage);
					break;
				}
		if(cnt!=data[hdr+7]) checkAppendMsg(pCheck,0,"Fragmented space is %d byte reported as %d on page %d",cnt,data[hdr+7],iPage);
	}
	WN_SQL3FreeX(hit);
	releasePage(pPage);
	return depth+1;
}
#endif
#ifndef WN_SQL_OMIT_INTEGRITY_CHECK
char *WN_SQL3BtreeIntegrityCheck(Btree *p,int *aRoot,int nRoot,int mxErr,int *pnErr)
{
	int i,nRef;
	IntegrityCk sCheck;
	BtShared *pBt=p->pBt;
	nRef=WN_SQL3PagerRefcount(pBt->pPager);
	if(lockBtreeWithRetry(p))return WN_SQLStrDup("Unable to acquire a read lock on the database");
	sCheck.pBt=pBt;
	sCheck.pPager=pBt->pPager;
	sCheck.nPage=WN_SQL3PagerPagecount(sCheck.pPager);
	sCheck.mxErr=mxErr;
	sCheck.nErr=0;
	*pnErr=0;
#ifndef WN_SQL_OMIT_AUTOVACUUM
	if(pBt->nTrunc)sCheck.nPage=pBt->nTrunc;
#endif
	if(sCheck.nPage==0)
	{
		unlockBtreeIfUnused(pBt);
		return 0;
	}
	sCheck.anRef=WN_SQLMallocRaw((sCheck.nPage+1)*sizeof(sCheck.anRef[0]));
	if(!sCheck.anRef)
	{
		unlockBtreeIfUnused(pBt);
		*pnErr=1;
		return WN_SQL3MPrintf("Unable to malloc %d bytes",(sCheck.nPage+1)*sizeof(sCheck.anRef[0]));
	}
	for(i=0;i<=sCheck.nPage;i++){sCheck.anRef[i]=0;}
	i=PENDING_BYTE_PAGE(pBt);
	if(i<=sCheck.nPage)sCheck.anRef[i]=1;
	sCheck.zErrMsg=0;
	checkList(&sCheck,1,get4byte(&pBt->pPage1->aData[32]),get4byte(&pBt->pPage1->aData[36]),"Main freelist:");
	for(i=0;i<nRoot && sCheck.mxErr;i++)
	{
		if(aRoot[i]==0)continue;
#ifndef WN_SQL_OMIT_AUTOVACUUM
		if(pBt->autoVacuum && aRoot[i]>1)checkPtrmap(&sCheck,aRoot[i],PTRMAP_ROOTPAGE,0,0);
#endif
		checkTreePage(&sCheck,aRoot[i],0,"List of tree roots:");
	}
	for(i=1;i<=sCheck.nPage && sCheck.mxErr;i++)
	{
#ifdef WN_SQL_OMIT_AUTOVACUUM
		if(sCheck.anRef[i]==0)
		{
			checkAppendMsg(&sCheck,0,"Page %d is never used",i);
		}
#else
		if(sCheck.anRef[i]==0 &&(PTRMAP_PAGENO(pBt,i)!=i || !pBt->autoVacuum))
		{
			checkAppendMsg(&sCheck,0,"Page %d is never used",i);
		}
		if(sCheck.anRef[i] &&(PTRMAP_PAGENO(pBt,i)==i && pBt->autoVacuum))checkAppendMsg(&sCheck,0,"Pointer map page %d is referenced",i);
#endif
	}
	unlockBtreeIfUnused(pBt);
	if(nRef!=WN_SQL3PagerRefcount(pBt->pPager))checkAppendMsg(&sCheck,0,"Outstanding page count goes from %d to %d during this analysis",nRef,WN_SQL3PagerRefcount(pBt->pPager));
	WN_SQL3FreeX(sCheck.anRef);
	*pnErr=sCheck.nErr;
	return sCheck.zErrMsg;
}
#endif
const char *WN_SQL3BtreeGetFilename(Btree *p)
{
		return WN_SQL3PagerFilename(p->pBt->pPager);
}
const char *WN_SQL3BtreeGetDirname(Btree *p)
{
	return WN_SQL3PagerDirname(p->pBt->pPager);
}
const char *WN_SQL3BtreeGetJournalname(Btree *p)
{
		return WN_SQL3PagerJournalname(p->pBt->pPager);
}
#ifndef WN_SQL_OMIT_VACUUM
int WN_SQL3BtreeCopyFile(Btree *pTo,Btree *pFrom)
{
	int rc=0;
	Pgno i,nPage,nToPage,iSkip;
	BtShared *pBtTo=pTo->pBt;
	BtShared *pBtFrom=pFrom->pBt;
	if(pTo->inTrans!=TRANS_WRITE||pFrom->inTrans!=TRANS_WRITE)return WN_SQL_ERROR;
	if(pBtTo->pCursor)return WN_SQL_BUSY;
	nToPage=WN_SQL3PagerPagecount(pBtTo->pPager);
	nPage=WN_SQL3PagerPagecount(pBtFrom->pPager);
	iSkip=PENDING_BYTE_PAGE(pBtTo);
	for(i=1;rc==0 && i<=nPage;i++)
	{
		DbPage *pDbPage;
		if(i==iSkip)continue;
		rc=WN_SQL3PagerGet(pBtFrom->pPager,i,&pDbPage);
		if(rc)break;
		rc=WN_SQL3PagerOverwrite(pBtTo->pPager,i,WN_SQL3PagerGetData(pDbPage));
		WN_SQL3PagerUnref(pDbPage);
	}
	for(i=nPage+1;rc==0 && i<=nToPage;i++)
	{
		DbPage *pDbPage;
		if(i==iSkip)continue;
		rc=WN_SQL3PagerGet(pBtTo->pPager,i,&pDbPage);
		if(rc)break;
		rc=WN_SQL3PagerWrite(pDbPage);
		WN_SQL3PagerDontWrite(pDbPage);
		WN_SQL3PagerUnref(pDbPage);
	}
	if(!rc && nPage<nToPage)rc=WN_SQL3PagerTruncate(pBtTo->pPager,nPage);
	if(rc)WN_SQL3BtreeRollback(pTo);
	return rc;
}
#endif
int WN_SQL3BtreeIsInTrans(Btree *p)
{
	return(p &&(p->inTrans==TRANS_WRITE));
}
int WN_SQL3BtreeIsInStmt(Btree *p)
{
	return(p->pBt && p->pBt->inStmt);
}
int WN_SQL3BtreeIsInReadTrans(Btree *p)
{
	return(p &&(p->inTrans!=TRANS_NONE));
}
void *WN_SQL3BtreeSchema(Btree *p,int nBytes,void(*xFree)(void *))
{
	BtShared *pBt=p->pBt;
	if(!pBt->pSchema)
	{
		pBt->pSchema=WN_SQL3Malloc(nBytes);
		pBt->xFreeSchema=xFree;
	}
	return pBt->pSchema;
}
int WN_SQL3BtreeSchemaLocked(Btree *p)
{
	return(queryTableLock(p,MASTER_ROOT,READ_LOCK)!=0);
}
#ifndef WN_SQL_OMIT_SHARED_CACHE
int WN_SQL3BtreeLockTable(Btree *p,int iTab,u8 isWriteLock)
{
	int rc=0;
	u8 lockType=(isWriteLock?WRITE_LOCK:READ_LOCK);
	rc=queryTableLock(p,iTab,lockType);
	if(rc==0)rc=lockTable(p,iTab,lockType);
	return rc;
}
#endif
#ifndef WN_SQL_OMIT_INCRBLOB
int WN_SQL3BtreePutData(BtCursor *pCsr,u32 offset,u32 amt,void *z)
{
	if(pCsr->eState==CURSOR_REQUIRESEEK)return WN_SQL_ABORT;
	if(!pCsr->wrFlag)return WN_SQL_READONLY;
	if(checkReadLocks(pCsr->pBtree,pCsr->pgnoRoot,pCsr))return WN_SQL_LOCKED;
	if(pCsr->eState==CURSOR_INVALID || !pCsr->pPage->intKey)return WN_SQL_ERROR;
	return accessPayload(pCsr,offset,amt,(unsigned char *)z,0,1);
}
void WN_SQL3BtreeCacheOverflow(BtCursor *pCur)
{
	pCur->isIncrblobHandle=1;
}
#endif
FifoPage *allocateFifoPage(int nEntry)
{
	FifoPage *pPage;
	if(nEntry>32767)nEntry=32767;
	pPage=WN_SQLMallocRaw(sizeof(FifoPage)+sizeof(i64)*(nEntry-1));
	if(pPage)
	{
		pPage->nSlot=nEntry;
		pPage->iWrite=0;
		pPage->iRead=0;
		pPage->pNext=0;
	}
	return pPage;
}
void WN_SQL3VdbeFifoInit(Fifo *pFifo)
{
	memset(pFifo,0,sizeof(*pFifo));
}
int WN_SQL3VdbeFifoPush(Fifo *pFifo,i64 val)
{
	FifoPage *pPage;
	pPage=pFifo->pLast;
	if(pPage==0)
	{
		pPage=pFifo->pLast=pFifo->pFirst=allocateFifoPage(20);
		if(pPage==0)return WN_SQL_NOMEM;
	}
	else
		if(pPage->iWrite>=pPage->nSlot)
		{
			pPage->pNext=allocateFifoPage(pFifo->nEntry);
			if(pPage->pNext==0)return WN_SQL_NOMEM;
			pPage=pFifo->pLast=pPage->pNext;
		}
	pPage->aSlot[pPage->iWrite++]=val;
	pFifo->nEntry++;
	return 0;
}
int WN_SQL3VdbeFifoPop(Fifo *pFifo,i64 *pVal)
{
	FifoPage *pPage;
	if(pFifo->nEntry==0)return WN_SQL_DONE;
	pPage=pFifo->pFirst;
	*pVal=pPage->aSlot[pPage->iRead++];
	pFifo->nEntry--;
	if(pPage->iRead>=pPage->iWrite)
	{
		pFifo->pFirst=pPage->pNext;
		WN_SQL3FreeX(pPage);
		if(pFifo->nEntry==0)pFifo->pLast=0;
	}
	else
		return 0;
}
void WN_SQL3VdbeFifoClear(Fifo *pFifo)
{
	FifoPage *pPage,*pNextPage;
	for(pPage=pFifo->pFirst;pPage;pPage=pNextPage)
	{
		pNextPage=pPage->pNext;
		WN_SQL3FreeX(pPage);
	}
	WN_SQL3VdbeFifoInit(pFifo);
}
#define expandBlob(P)(((P)->flags&MEM_Zero)?WN_SQL3VdbeMemExpandBlob(P):0)
int WN_SQL3VdbeChangeEncoding(Mem *pMem,int desiredEnc)
{
	if(!(pMem->flags&MEM_Str)|| pMem->enc==desiredEnc)return 0;
#ifdef WN_SQL_OMIT_UTF16
	return WN_SQL_ERROR;
#else
	return WN_SQL3VdbeMemTranslate(pMem,desiredEnc);
#endif
}
int WN_SQL3VdbeMemDynamicify(Mem *pMem)
{
	int n;
	u8 *z;
	expandBlob(pMem);
	if((pMem->flags &(MEM_Ephem|MEM_Static|MEM_Short))==0)return 0;
	n=pMem->n;
	z=WN_SQLMallocRaw(n+2);
	if(z==0)return WN_SQL_NOMEM;
	pMem->flags |=MEM_Dyn|MEM_Term;
	pMem->xDel=0;
	memcpy(z,pMem->z,n);
	z[n]=0;
	z[n+1]=0;
	pMem->z=(char*)z;
	pMem->flags &=~(MEM_Ephem|MEM_Static|MEM_Short);
	return 0;
}
#ifndef WN_SQL_OMIT_INCRBLOB
int WN_SQL3VdbeMemExpandBlob(Mem *pMem)
{
	if(pMem->flags & MEM_Zero)
	{

		int nByte=pMem->n+pMem->u.i;
		if(nByte<=0)nByte=1;
		char *pNew=WN_SQL3Malloc(nByte);
		if(pNew==0)return WN_SQL_NOMEM;
		memcpy(pNew,pMem->z,pMem->n);
		memset(&pNew[pMem->n],0,pMem->u.i);
		WN_SQL3VdbeMemRelease(pMem);
		pMem->z=pNew;
		pMem->n+=pMem->u.i;
		pMem->u.i=0;
		pMem->flags &=~(MEM_Zero|MEM_Static|MEM_Ephem|MEM_Short|MEM_Term);
		pMem->flags |=MEM_Dyn;
	}
	return 0;
}
#endif
int WN_SQL3VdbeMemMakeWriteable(Mem *pMem)
{
	int n;
	u8 *z;
	expandBlob(pMem);
	if((pMem->flags &(MEM_Ephem|MEM_Static))==0)return 0;
	if((n=pMem->n)+2<sizeof(pMem->zShort))
	{
		z=(u8*)pMem->zShort;
		pMem->flags |=MEM_Short|MEM_Term;
	}
	else
	{
		z=WN_SQLMallocRaw(n+2);
		if(z==0)return WN_SQL_NOMEM;
		pMem->flags |=MEM_Dyn|MEM_Term;
		pMem->xDel=0;
	}
	memcpy(z,pMem->z,n);
	z[n]=0;
	z[n+1]=0;
	pMem->z=(char*)z;
	pMem->flags &=~(MEM_Ephem|MEM_Static);
	return 0;
}
int WN_SQL3VdbeMemNulTerminate(Mem *pMem)
{
	if((pMem->flags & MEM_Term)||(pMem->flags & MEM_Str)==0)return 0;
	if(pMem->flags &(MEM_Static|MEM_Ephem))
		return WN_SQL3VdbeMemMakeWriteable(pMem);
	else
	{
		char *z;
		WN_SQL3VdbeMemExpandBlob(pMem);
		z=WN_SQL3Malloc(pMem->n+2);
		if(!z)return WN_SQL_NOMEM;
		memcpy(z,pMem->z,pMem->n);
		z[pMem->n]=0;
		z[pMem->n+1]=0;
		if(pMem->xDel)
			pMem->xDel(pMem->z);
		else
			WN_SQL3FreeX(pMem->z);
		pMem->xDel=0;
		pMem->z=z;
		pMem->flags |=MEM_Term;
	}
	return 0;
}
int WN_SQL3VdbeMemStringify(Mem *pMem,int enc)
{
	int rc=0,fg=pMem->flags;
	char *z=pMem->zShort;
	if(fg & MEM_Int)
		WN_SQL3_snprintf(NBFS,z,"%lld",pMem->u.i);
	else
		WN_SQL3_snprintf(NBFS,z,"%!.15g",pMem->r);
	pMem->n=strlen(z);
	pMem->z=z;
	pMem->enc=WN_SQL_UTF8;
	pMem->flags |=MEM_Str | MEM_Short | MEM_Term;
	WN_SQL3VdbeChangeEncoding(pMem,enc);
	return rc;
}
int WN_SQL3VdbeMemFinalize(Mem *pMem,FuncDef *pFunc)
{
	int rc=0;
	if(pFunc && pFunc->xFinalize)
	{
		WN_SQL3_context ctx;
		ctx.s.flags=MEM_Null;
		ctx.s.z=pMem->zShort;
		ctx.pMem=pMem;
		ctx.pFunc=pFunc;
		ctx.isError=0;
		pFunc->xFinalize(&ctx);
		if(pMem->z && pMem->z!=pMem->zShort)WN_SQL3FreeX(pMem->z);
		*pMem=ctx.s;
		if(pMem->flags & MEM_Short)pMem->z=pMem->zShort;
		if(ctx.isError)rc=WN_SQL_ERROR;
	}
	return rc;
}
void WN_SQL3VdbeMemRelease(Mem *p)
{
	if(p->flags &(MEM_Dyn|MEM_Agg))
	{
		if(p->xDel)
		{
			if(p->flags & MEM_Agg)
			{
				WN_SQL3VdbeMemFinalize(p,p->u.pDef);
				WN_SQL3VdbeMemRelease(p);
			}
			else
				p->xDel((void *)p->z);
		}
		else
			WN_SQL3FreeX(p->z);
		p->z=0;
		p->xDel=0;
	}
}
i64 WN_SQL3VdbeIntValue(Mem *pMem)
{
	int flags=pMem->flags;
	if(flags & MEM_Int)
		return pMem->u.i;
	else
		if(flags & MEM_Real)
			return(i64)pMem->r;
		else
			if(flags &(MEM_Str|MEM_Blob))
			{
				i64 value;
				pMem->flags |=MEM_Str;
				if(WN_SQL3VdbeChangeEncoding(pMem,WN_SQL_UTF8)|| WN_SQL3VdbeMemNulTerminate(pMem))return 0;
				WN_SQL3Atoi64(pMem->z,&value);
				return value;
			}
			else
				return 0;
}
double WN_SQL3VdbeRealValue(Mem *pMem)
{
	if(pMem->flags & MEM_Real)
		return pMem->r;
	else
		if(pMem->flags & MEM_Int)
			return(double)pMem->u.i;
		else
			if(pMem->flags &(MEM_Str|MEM_Blob))
			{
				double val=0.0;
				pMem->flags |=MEM_Str;
				if(WN_SQL3VdbeChangeEncoding(pMem,WN_SQL_UTF8)|| WN_SQL3VdbeMemNulTerminate(pMem))return 0.0;
				WN_SQL3AtoF(pMem->z,&val);
				return val;
			}
			else
				return 0.0;
}
void WN_SQL3VdbeIntegerAffinity(Mem *pMem)
{
	pMem->u.i=pMem->r;
	if(((double)pMem->u.i)==pMem->r)pMem->flags |=MEM_Int;
}
int WN_SQL3VdbeMemIntegerify(Mem *pMem)
{
	pMem->u.i=WN_SQL3VdbeIntValue(pMem);
	WN_SQL3VdbeMemRelease(pMem);
	pMem->flags=MEM_Int;
	return 0;
}
int WN_SQL3VdbeMemRealify(Mem *pMem)
{
	pMem->r=WN_SQL3VdbeRealValue(pMem);
	WN_SQL3VdbeMemRelease(pMem);
	pMem->flags=MEM_Real;
	return 0;
}
int WN_SQL3VdbeMemNumerify(Mem *pMem)
{
	double r1=WN_SQL3VdbeRealValue(pMem),r2;
	i64 i=(i64)r1;
	r2=(double)i;
	if(r1==r2)
		WN_SQL3VdbeMemIntegerify(pMem);
	else
	{
		pMem->r=r1;
		pMem->flags=MEM_Real;
		WN_SQL3VdbeMemRelease(pMem);
	}
	return 0;
}
void WN_SQL3VdbeMemSetNull(Mem *pMem)
{
	WN_SQL3VdbeMemRelease(pMem);
	pMem->flags=MEM_Null;
	pMem->type=WN_SQL_NULL;
	pMem->n=0;
}
void WN_SQL3VdbeMemSetZeroBlob(Mem *pMem,int n)
{
	WN_SQL3VdbeMemRelease(pMem);
	pMem->flags=MEM_Blob|MEM_Zero|MEM_Short;
	pMem->type=WN_SQL_BLOB;
	pMem->n=0;
	if(n<0)n=0;
	pMem->u.i=n;
	pMem->z=pMem->zShort;
	pMem->enc=WN_SQL_UTF8;
}
void WN_SQL3VdbeMemSetInt64(Mem *pMem,i64 val)
{
	WN_SQL3VdbeMemRelease(pMem);
	pMem->u.i=val;
	pMem->flags=MEM_Int;
	pMem->type=WN_SQL_INTEGER;
}
void WN_SQL3VdbeMemSetDouble(Mem *pMem,double val)
{
	if(WN_SQL3_isnan(val))
		WN_SQL3VdbeMemSetNull(pMem);
	else
	{
		WN_SQL3VdbeMemRelease(pMem);
		pMem->r=val;
		pMem->flags=MEM_Real;
		pMem->type=WN_SQL_FLOAT;
	}
}
int WN_SQL3VdbeMemTooBig(Mem *p)
{
	if(p->flags &(MEM_Str|MEM_Blob))
	{
		int n=p->n;
		if(p->flags & MEM_Zero)n+=p->u.i;
		return n>WN_SQL_MAX_LENGTH;
	}
	return 0;
}
void WN_SQL3VdbeMemShallowCopy(Mem *pTo,const Mem *pFrom,int srcType)
{
	memcpy(pTo,pFrom,sizeof(*pFrom)-sizeof(pFrom->zShort));
	pTo->xDel=0;
	if(pTo->flags &(MEM_Str|MEM_Blob))
	{
		pTo->flags &=~(MEM_Dyn|MEM_Static|MEM_Short|MEM_Ephem);
		pTo->flags |=srcType;
	}
}
int WN_SQL3VdbeMemCopy(Mem *pTo,const Mem *pFrom)
{
	int rc;
	if(pTo->flags & MEM_Dyn)WN_SQL3VdbeMemRelease(pTo);
	WN_SQL3VdbeMemShallowCopy(pTo,pFrom,MEM_Ephem);
	if(pTo->flags & MEM_Ephem)
		rc=WN_SQL3VdbeMemMakeWriteable(pTo);
	else
		rc=0;
	return rc;
}
int WN_SQL3VdbeMemMove(Mem *pTo,Mem *pFrom)
{
	int rc;
	if(pTo->flags & MEM_Dyn)WN_SQL3VdbeMemRelease(pTo);
	memcpy(pTo,pFrom,sizeof(Mem));
	if(pFrom->flags & MEM_Short)pTo->z=pTo->zShort;
	pFrom->flags=MEM_Null;
	pFrom->xDel=0;
	if(pTo->flags & MEM_Ephem)
		rc=WN_SQL3VdbeMemMakeWriteable(pTo);
	else
		rc=0;
	return rc;
}
int WN_SQL3VdbeMemSetStr(Mem *pMem,const char *z,int n,u8 enc,void(*xDel)(void*))
{
	WN_SQL3VdbeMemRelease(pMem);
	if(!z)
	{
		pMem->flags=MEM_Null;
		pMem->type=WN_SQL_NULL;
		return 0;
	}
	pMem->z=(char *)z;
	if(xDel==WN_SQL_STATIC)
		pMem->flags=MEM_Static;
	else
		if(xDel==WN_SQL_TRANSIENT)
			pMem->flags=MEM_Ephem;
		else
		{
			pMem->flags=MEM_Dyn;
			pMem->xDel=xDel;
		}
		pMem->enc=enc;
		pMem->type=enc==0 ? WN_SQL_BLOB :WN_SQL_TEXT;
		pMem->n=n;
		switch(enc)
		{
		case 0:
			pMem->flags |=MEM_Blob;
			pMem->enc=WN_SQL_UTF8;
			break;
		case WN_SQL_UTF8:
			pMem->flags |=MEM_Str;
			if(n<0)
			{
				pMem->n=strlen(z);
				pMem->flags |=MEM_Term;
			}
			break;
#ifndef WN_SQL_OMIT_UTF16
		case WN_SQL_UTF16LE:
		case WN_SQL_UTF16BE:
			pMem->flags |=MEM_Str;
			if(pMem->n<0)
			{
				pMem->n=WN_SQL3Utf16ByteLen(pMem->z,-1);
				pMem->flags |=MEM_Term;
			}
			if(WN_SQL3VdbeMemHandleBom(pMem))return WN_SQL_NOMEM;
#endif
		}
		if(pMem->flags&MEM_Ephem)return WN_SQL3VdbeMemMakeWriteable(pMem);
		return 0;
}
int WN_SQL3MemCompare(const Mem *pMem1,const Mem *pMem2,const CollSeq *pColl)
{
	int rc,f1=pMem1->flags,f2=pMem2->flags,combined_flags=f1|f2;
	if(combined_flags&MEM_Null)return(f2&MEM_Null)-(f1&MEM_Null);
	if(combined_flags&(MEM_Int|MEM_Real))
	{
		if(!(f1&(MEM_Int|MEM_Real)))return 1;
		if(!(f2&(MEM_Int|MEM_Real)))return-1;
		if((f1 & f2 & MEM_Int)==0)
		{
			double r1,r2;
			if((f1&MEM_Real)==0)
				r1=pMem1->u.i;
			else
				r1=pMem1->r;
			if((f2&MEM_Real)==0)
				r2=pMem2->u.i;
			else
				r2=pMem2->r;
			if(r1<r2)return-1;
			if(r1>r2)return 1;
			return 0;
		}
		else
		{
			if(pMem1->u.i<pMem2->u.i)return-1;
			if(pMem1->u.i > pMem2->u.i)return 1;
			return 0;
		}
	}
	if(combined_flags&MEM_Str)
	{
		if((f1 & MEM_Str)==0)return 1;
		if((f2 & MEM_Str)==0)return-1;
		pMem1->enc==WN_SQL_UTF16LE || pMem1->enc==WN_SQL_UTF16BE);
		if(pColl)
		{
			if(pMem1->enc==pColl->enc)
				return pColl->xCmp(pColl->pUser,pMem1->n,pMem1->z,pMem2->n,pMem2->z);
			else
			{
				u8 origEnc=pMem1->enc;
				const void *v1,*v2;
				int n1,n2;
				v1=WN_SQL3ValueText((WN_SQL3_value*)pMem1,pColl->enc);
				n1=v1==0 ? 0 :pMem1->n;
				v2=WN_SQL3ValueText((WN_SQL3_value*)pMem2,pColl->enc);
				n2=v2==0 ? 0 :pMem2->n;
				rc=pColl->xCmp(pColl->pUser,n1,v1,n2,v2);
				WN_SQL3ValueText((WN_SQL3_value*)pMem1,origEnc);
				WN_SQL3ValueText((WN_SQL3_value*)pMem2,origEnc);
				return rc;
			}
		}
	}
	rc=memcmp(pMem1->z,pMem2->z,(pMem1->n>pMem2->n)?pMem2->n:pMem1->n);
	if(rc==0)rc=pMem1->n-pMem2->n;
	return rc;
}
int WN_SQL3VdbeMemFromBtree(BtCursor *pCur,int offset,int amt,int key,Mem *pMem)
{
	char *zData;
	int available=0;
	if(key)
		zData=(char *)WN_SQL3BtreeKeyFetch(pCur,&available);
	else
		zData=(char *)WN_SQL3BtreeDataFetch(pCur,&available);
	pMem->n=amt;
	if(offset+amt<=available)
	{
		pMem->z=&zData[offset];
		pMem->flags=MEM_Blob|MEM_Ephem;
	}
	else
	{
		int rc;
		if(amt>NBFS-2)
		{
			zData=(char *)WN_SQLMallocRaw(amt+2);
			if(!zData)return WN_SQL_NOMEM;
			pMem->flags=MEM_Blob|MEM_Dyn|MEM_Term;
			pMem->xDel=0;
		}
		else
		{
			zData=&(pMem->zShort[0]);
			pMem->flags=MEM_Blob|MEM_Short|MEM_Term;
		}
		pMem->z=zData;
		pMem->enc=0;
		pMem->type=WN_SQL_BLOB;
		if(key)
			rc=WN_SQL3BtreeKey(pCur,offset,amt,zData);
		else
			rc=WN_SQL3BtreeData(pCur,offset,amt,zData);
		zData[amt]=0;
		zData[amt+1]=0;
		if(rc)
		{
			if(amt>NBFS-2)WN_SQL3FreeX(zData);
			return rc;
		}
	}
	return 0;
}
#ifndef NDEBUG
void WN_SQL3VdbeMemSanity(Mem *pMem)
{
	int flags=pMem->flags;
	if(flags &(MEM_Str|MEM_Blob))
	{
		int x=flags &(MEM_Static|MEM_Dyn|MEM_Ephem|MEM_Short);
		if((flags & MEM_Str))pMem->enc==WN_SQL_UTF16BE || pMem->enc==WN_SQL_UTF16LE);
	}
}
#endif
const void *WN_SQL3ValueText(WN_SQL3_value* pVal,u8 enc)
{
	if(!pVal)return 0;
	if(pVal->flags&MEM_Null)return 0;
	pVal->flags |=(pVal->flags & MEM_Blob)>>3;
	expandBlob(pVal);
	if(pVal->flags&MEM_Str)
	{
		WN_SQL3VdbeChangeEncoding(pVal,enc & ~WN_SQL_UTF16_ALIGNED);
		if((enc & WN_SQL_UTF16_ALIGNED)&& 1==(1&(int)pVal->z))
			if(WN_SQL3VdbeMemMakeWriteable(pVal))return 0;
		WN_SQL3VdbeMemNulTerminate(pVal);
	}
	else
		WN_SQL3VdbeMemStringify(pVal,enc);
	if(pVal->enc==(enc & ~WN_SQL_UTF16_ALIGNED))
		return pVal->z;
	else
		return 0;
}
WN_SQL3_value *WN_SQL3ValueNew(void)
{
	Mem *p=WN_SQL3Malloc(sizeof(*p));
	if(p)
	{
		p->flags=MEM_Null;
		p->type=WN_SQL_NULL;
	}
	return p;
}
int WN_SQL3ValueFromExpr(Expr *pExpr,u8 enc,u8 affinity,WN_SQL3_value **ppVal)
{
	int op;
	char *zVal=0;
	WN_SQL3_value *pVal=0;
	if(!pExpr)
	{
		*ppVal=0;
		return 0;
	}
	op=pExpr->op;
	if(op==TK_STRING || op==TK_FLOAT || op==TK_INTEGER)
	{
		zVal=WN_SQLStrNDup((char*)pExpr->token.z,pExpr->token.n);
		pVal=WN_SQL3ValueNew();
		if(!zVal || !pVal)goto no_mem;
		WN_SQL3Dequote(zVal);
		WN_SQL3ValueSetStr(pVal,-1,zVal,WN_SQL_UTF8,WN_SQL3FreeX);
		if((op==TK_INTEGER || op==TK_FLOAT)&& affinity==WN_SQL_AFF_NONE)
			WN_SQL3ValueApplyAffinity(pVal,WN_SQL_AFF_NUMERIC,enc);
		else
			WN_SQL3ValueApplyAffinity(pVal,affinity,enc);
	}
	else
		if(op==TK_UMINUS)
		{
			if(0==WN_SQL3ValueFromExpr(pExpr->pLeft,enc,affinity,&pVal))
			{
				pVal->u.i=-1 * pVal->u.i;
				pVal->r=-1.0 * pVal->r;
			}
		}
#ifndef WN_SQL_OMIT_BLOB_LITERAL
		else
			if(op==TK_BLOB)
			{
				pVal=WN_SQL3ValueNew();
				zVal=WN_SQLStrNDup((char*)pExpr->token.z+1,pExpr->token.n-1);
				if(!zVal || !pVal)goto no_mem;
				WN_SQL3Dequote(zVal);
				int nVal=strlen(zVal)/2;
				WN_SQL3VdbeMemSetStr(pVal,WN_SQL3HexToBlob(zVal),nVal,0,WN_SQL3FreeX);
				WN_SQL3FreeX(zVal);
			}
#endif
			*ppVal=pVal;
			return 0;
no_mem:
			WN_SQL3FreeX(zVal);
			WN_SQL3ValueFree(pVal);
			*ppVal=0;
			return WN_SQL_NOMEM;
}
void WN_SQL3ValueSetStr(WN_SQL3_value *v,int n,const void *z,u8 enc,void(*xDel)(void*))
{
	if(v)WN_SQL3VdbeMemSetStr((Mem *)v,z,n,enc,xDel);
}
void WN_SQL3ValueFree(WN_SQL3_value *v)
{
	if(!v)return;
	WN_SQL3ValueSetStr(v,0,0,WN_SQL_UTF8,WN_SQL_STATIC);
	WN_SQL3FreeX(v);
}
int WN_SQL3ValueBytes(WN_SQL3_value *pVal,u8 enc)
{
	Mem *p=(Mem*)pVal;
	if((p->flags & MEM_Blob)|| WN_SQL3ValueText(pVal,enc))
	{
		if(p->flags & MEM_Zero)
			return p->n+p->u.i;
		else
			return p->n;
	}
	return 0;
}
#ifdef WN_SQL_DEBUG
int WN_SQL3_vdbe_addop_trace=0;
#endif
Vdbe *WN_SQL3VdbeCreate(WN_SQL3 *db)
{
	Vdbe *p=WN_SQL3Malloc(sizeof(Vdbe));
	if(p==0)return 0;
	p->db=db;
	if(db->pVdbe)db->pVdbe->pPrev=p;
	p->pNext=db->pVdbe;
	p->pPrev=0;
	db->pVdbe=p;
	p->magic=VDBE_MAGIC_INIT;
	return p;
}
void WN_SQL3VdbeSetSql(Vdbe *p,const char *z,int n)
{
	if(p==0)return;
	p->zSql=WN_SQL3StrNDup(z,n);
}
const char *WN_SQL3VdbeGetSql(Vdbe *p)
{
	return p->zSql;
}
void WN_SQL3VdbeSwap(Vdbe *pA,Vdbe *pB)
{
	Vdbe tmp=*pA,*pTmp;
	*pA=*pB;
	*pB=tmp;
	pTmp=pA->pNext;
	pA->pNext=pB->pNext;
	pB->pNext=pTmp;
	pTmp=pA->pPrev;
	pA->pPrev=pB->pPrev;
	pB->pPrev=pTmp;
	char *zTmp=pA->zSql;
	pA->zSql=pB->zSql;
	pB->zSql=zTmp;
	int nTmp=pA->nSql;
	pA->nSql=pB->nSql;
	pB->nSql=nTmp;
}
#ifdef WN_SQL_DEBUG
void WN_SQL3VdbeTrace(Vdbe *p,FILE *trace)
{
	p->trace=trace;
}
#endif
void resizeOpArray(Vdbe *p,int N)
{
	int runMode=p->magic==VDBE_MAGIC_RUN;
	if(runMode || p->nOpAlloc<N)
	{
		VdbeOp *pNew;
		int nNew=N+100*(!runMode);
		int oldSize=p->nOpAlloc;
		pNew=WN_SQLRealloc(p->aOp,nNew*sizeof(Op));
		if(pNew)
		{
			p->nOpAlloc=nNew;
			p->aOp=pNew;
			if(nNew>oldSize)memset(&p->aOp[oldSize],0,(nNew-oldSize)*sizeof(Op));
		}
	}
}
int WN_SQL3VdbeAddOp(Vdbe *p,int op,int p1,int p2)
{
	int i;
	VdbeOp *pOp;
	i=p->nOp;
	if(p->nOpAlloc<=i)
	{
		resizeOpArray(p,i+1);
		if(WN_SQL3MallocFailed())return 0;
	}
	p->nOp++;
	pOp=&p->aOp[i];
	pOp->opcode=op;
	pOp->p1=p1;
	pOp->p2=p2;
	pOp->p3=0;
	pOp->p3type=P3_NOTUSED;
	p->expired=0;
#ifdef WN_SQL_DEBUG
	if(WN_SQL3_vdbe_addop_trace)WN_SQL3VdbePrintOp(0,i,&p->aOp[i]);
#endif
	return i;
}
int WN_SQL3VdbeOp3(Vdbe *p,int op,int p1,int p2,const char *zP3,int p3type){
	int addr=WN_SQL3VdbeAddOp(p,op,p1,p2);
	WN_SQL3VdbeChangeP3(p,addr,zP3,p3type);
	return addr;
}
int WN_SQL3VdbeMakeLabel(Vdbe *p)
{
	int i;
	i=p->nLabel++;
	if(i>=p->nLabelAlloc)
	{
		p->nLabelAlloc=p->nLabelAlloc*2+10;
		p->aLabel=WN_SQLReallocOrFree(p->aLabel,p->nLabelAlloc*sizeof(p->aLabel[0]));
	}
	if(p->aLabel)p->aLabel[i]=-1;
	return-1-i;
}
void WN_SQL3VdbeResolveLabel(Vdbe *p,int x)
{
	int j=-1-x;
	if(p->aLabel)p->aLabel[j]=p->nOp;
}
int opcodeNoPush(u8 op)
{
	const u32 masks[5]={NOPUSH_MASK_0+(((unsigned)NOPUSH_MASK_1)<<16),NOPUSH_MASK_2+(((unsigned)NOPUSH_MASK_3)<<16),NOPUSH_MASK_4+(((unsigned)NOPUSH_MASK_5)<<16),NOPUSH_MASK_6+(((unsigned)NOPUSH_MASK_7)<<16),NOPUSH_MASK_8+(((unsigned)NOPUSH_MASK_9)<<16)};
	return(masks[op>>5] &(1<<(op&0x1F)));
}
#ifndef NDEBUG
int WN_SQL3VdbeOpcodeNoPush(u8 op)
{
	return opcodeNoPush(op);
}
#endif
void resolveP2Values(Vdbe *p,int *pMaxFuncArgs,int *pMaxStack)
{
	int i,nMaxArgs=0,nMaxStack=p->nOp;
	Op *pOp;
	int *aLabel=p->aLabel,doesStatementRollback=0,hasStatementBegin=0;
	for(pOp=p->aOp,i=p->nOp-1;i>=0;i--,pOp++)
	{
		u8 opcode=pOp->opcode;if(opcode==OP_Function || opcode==OP_AggStep
#ifndef WN_SQL_OMIT_VIRTUALTABLE
|| opcode==OP_VUpdate
#endif
)
		if(pOp->p2>nMaxArgs)nMaxArgs=pOp->p2;
		if(opcode==OP_Halt)
		{
			if(pOp->p1==WN_SQL_CONSTRAINT && pOp->p2==OE_Abort)doesStatementRollback=1;
		}
		else
			if(opcode==OP_Statement)
			{
				hasStatementBegin=1;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
			}
			else
				if(opcode==OP_VUpdate || opcode==OP_VRename)
					doesStatementRollback=1;
				else
					if(opcode==OP_VFilter)
					{
						int n=pOp[-2].p1;
						if(n>nMaxArgs)nMaxArgs=n;
#endif
					}
					if(opcodeNoPush(opcode))nMaxStack--;
					if(pOp->p2>=0)continue;
					pOp->p2=aLabel[-1-pOp->p2];
	}
	WN_SQL3FreeX(p->aLabel);
	p->aLabel=0;
	*pMaxFuncArgs=nMaxArgs;
	*pMaxStack=nMaxStack;
	if(hasStatementBegin && !doesStatementRollback)
		for(pOp=p->aOp,i=p->nOp-1;i>=0;i--,pOp++)
			if(pOp->opcode==OP_Statement)pOp->opcode=OP_Noop;
}
int WN_SQL3VdbeCurrentAddr(Vdbe *p)
{
	return p->nOp;
}
int WN_SQL3VdbeAddOpList(Vdbe *p,int nOp,VdbeOpList const *aOp)
{
	resizeOpArray(p,p->nOp+nOp);
	if(WN_SQL3MallocFailed())return 0;
	int addr=p->nOp;
	if(nOp>0)
	{
		int i;
		VdbeOpList const *pIn=aOp;
		for(i=0;i<nOp;i++,pIn++)
		{
			int p2=pIn->p2;
			VdbeOp *pOut=&p->aOp[i+addr];
			pOut->opcode=pIn->opcode;
			pOut->p1=pIn->p1;
			pOut->p2=p2<0 ? addr+ADDR(p2):p2;
			pOut->p3=pIn->p3;
			pOut->p3type=pIn->p3 ? P3_STATIC :P3_NOTUSED;
#ifdef WN_SQL_DEBUG
			if(WN_SQL3_vdbe_addop_trace)WN_SQL3VdbePrintOp(0,i+addr,&p->aOp[i+addr]);
#endif
		}
		p->nOp+=nOp;
	}
	return addr;
}
void WN_SQL3VdbeChangeP1(Vdbe *p,int addr,int val)
{
	if(p && addr>=0 && p->nOp>addr && p->aOp)p->aOp[addr].p1=val;
}
void WN_SQL3VdbeChangeP2(Vdbe *p,int addr,int val)
{
	if(p && addr>=0 && p->nOp>addr && p->aOp)p->aOp[addr].p2=val;
}
void WN_SQL3VdbeJumpHere(Vdbe *p,int addr)
{
	WN_SQL3VdbeChangeP2(p,addr,p->nOp);
}
void freeEphemeralFunction(FuncDef *pDef)
{
	if(pDef &&(pDef->flags & WN_SQL_FUNC_EPHEM))WN_SQL3FreeX(pDef);
}
void freeP3(int p3type,void *p3)
{
	if(p3)
		switch(p3type)
		{
		case P3_DYNAMIC:
		case P3_KEYINFO:
		case P3_KEYINFO_HANDOFF:
			WN_SQL3FreeX(p3);
			break;
		case P3_MPRINTF:
			WN_SQL3_free(p3);
			break;
		case P3_VDBEFUNC:
			VdbeFunc *pVdbeFunc=(VdbeFunc *)p3;
			freeEphemeralFunction(pVdbeFunc->pFunc);
			WN_SQL3VdbeDeleteAuxData(pVdbeFunc,0);
			WN_SQL3FreeX(pVdbeFunc);
			break;
		case P3_FUNCDEF:
			freeEphemeralFunction((FuncDef*)p3);
			break;
		case P3_MEM:
			WN_SQL3ValueFree((WN_SQL3_value*)p3);
			break;
		}
}
void WN_SQL3VdbeChangeToNoop(Vdbe *p,int addr,int N)
{
	if(p && p->aOp)
	{
		VdbeOp *pOp=&p->aOp[addr];
		while(N--)
		{
			freeP3(pOp->p3type,pOp->p3);
			memset(pOp,0,sizeof(pOp[0]));
			pOp->opcode=OP_Noop;
			pOp++;
		}
	}
}
void WN_SQL3VdbeChangeP3(Vdbe *p,int addr,const char *zP3,int n)
{
	Op *pOp;
	if(p==0 || p->aOp==0 || WN_SQL3MallocFailed())
	{
		if(n!=P3_KEYINFO)freeP3(n,(void*)*(char**)&zP3);
		return;
	}
	if(addr<0 || addr>=p->nOp)
	{
		addr=p->nOp-1;
		if(addr<0)return;
	}
	pOp=&p->aOp[addr];
	freeP3(pOp->p3type,pOp->p3);
	pOp->p3=0;
	if(zP3==0)
	{
		pOp->p3=0;
		pOp->p3type=P3_NOTUSED;
	}
	else
		if(n==P3_KEYINFO)
		{
			KeyInfo *pKeyInfo;
			int nField,nByte;
			nField=((KeyInfo*)zP3)->nField;
			nByte=sizeof(*pKeyInfo)+(nField-1)*sizeof(pKeyInfo->aColl[0])+nField;
			pKeyInfo=WN_SQLMallocRaw(nByte);
			pOp->p3=(char*)pKeyInfo;
			if(pKeyInfo)
			{
				unsigned char *aSortOrder;
				memcpy(pKeyInfo,zP3,nByte);
				aSortOrder=pKeyInfo->aSortOrder;
				if(aSortOrder)
				{
					pKeyInfo->aSortOrder=(unsigned char*)&pKeyInfo->aColl[nField];
					memcpy(pKeyInfo->aSortOrder,aSortOrder,nField);
				}
				pOp->p3type=P3_KEYINFO;
			}
			else
				pOp->p3type=P3_NOTUSED;
		}
		else
			if(n==P3_KEYINFO_HANDOFF)
			{
				pOp->p3=(char*)zP3;
				pOp->p3type=P3_KEYINFO;
			}
			else
				if(n<0)
				{
					pOp->p3=(char*)zP3;
					pOp->p3type=n;
				}
				else
				{
					if(n==0)n=strlen(zP3);
					pOp->p3=WN_SQLStrNDup(zP3,n);
					pOp->p3type=P3_DYNAMIC;
				}
}
#ifndef NDEBUG
void WN_SQL3VdbeComment(Vdbe *p,const char *zFormat,...)
{
	va_list ap;
	va_start(ap,zFormat);
	WN_SQL3VdbeChangeP3(p,-1,WN_SQL3VMPrintf(zFormat,ap),P3_DYNAMIC);
	va_end(ap);
}
#endif
VdbeOp *WN_SQL3VdbeGetOp(Vdbe *p,int addr)
{
	return((addr>=0 && addr<p->nOp)?(&p->aOp[addr]):0);
}
#if !defined(WN_SQL_OMIT_EXPLAIN)|| !defined(NDEBUG)\
|| defined(VDBE_PROFILE)|| defined(WN_SQL_DEBUG)
char *displayP3(Op *pOp,char *zTemp,int nTemp)
{
	char *zP3;
	switch(pOp->p3type)
	{
	case P3_KEYINFO:
		KeyInfo *pKeyInfo=(KeyInfo*)pOp->p3;
		WN_SQL3_snprintf(nTemp,zTemp,"keyinfo(%d",pKeyInfo->nField);
		int i=strlen(zTemp),j;
		for(j=0;j<pKeyInfo->nField;j++)
		{
			CollSeq *pColl=pKeyInfo->aColl[j];
			if(pColl)
			{
				int n=strlen(pColl->zName);
				if(i+n>nTemp-6)
				{
					memcpy(&zTemp[i],",...",4);
					break;
				}
				zTemp[i++]=',';
				if(pKeyInfo->aSortOrder && pKeyInfo->aSortOrder[j])zTemp[i++]='-';
				memcpy(&zTemp[i],pColl->zName,n+1);
				i+=n;
			}
			else
				if(i+4<nTemp-6)
				{
					memcpy(&zTemp[i],",nil",4);
					i+=4;
				}
		}
		zTemp[i++]=')';
		zTemp[i]=0;
		zP3=zTemp;
		break;
	case P3_COLLSEQ:
		CollSeq *pColl=(CollSeq*)pOp->p3;
		WN_SQL3_snprintf(nTemp,zTemp,"collseq(%.20s)",pColl->zName);
		zP3=zTemp;
		break;
	case P3_FUNCDEF:
		FuncDef *pDef=(FuncDef*)pOp->p3;
		WN_SQL3_snprintf(nTemp,zTemp,"%s(%d)",pDef->zName,pDef->nArg);
		zP3=zTemp;
		break;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	case P3_VTAB:
		WN_SQL3_vtab *pVtab=(WN_SQL3_vtab*)pOp->p3;
		WN_SQL3_snprintf(nTemp,zTemp,"vtab:%p:%p",pVtab,pVtab->pModule);
		zP3=zTemp;
		break;
#endif
	default:
		zP3=pOp->p3;
		if(zP3==0 || pOp->opcode==OP_Noop)zP3="";
	}
	return zP3;
}
#endif
#if defined(VDBE_PROFILE)|| defined(WN_SQL_DEBUG)
void WN_SQL3VdbePrintOp(FILE *pOut,int pc,Op *pOp)
{
	char *zP3,zPtr[50];
	const char *zFormat1="%4d %-13s %4d %4d %s\n";
	if(pOut==0)pOut=stdout;
	zP3=displayP3(pOp,zPtr,sizeof(zPtr));
	fprintf(pOut,zFormat1,pc,WN_SQL3OpcodeNames[pOp->opcode],pOp->p1,pOp->p2,zP3);
	fflush(pOut);
}
#endif
void releaseMemArray(Mem *p,int N)
{
	if(p)while(N-->0)WN_SQL3VdbeMemRelease(p++);
}
#ifndef WN_SQL_OMIT_EXPLAIN
int WN_SQL3VdbeList(Vdbe *p)
{
	WN_SQL3 *db=p->db;
	int i,rc=0;
	if(p->magic!=VDBE_MAGIC_RUN)return WN_SQL_MISUSE;
	if(p->pTos==&p->aStack[4])releaseMemArray(p->aStack,5);
	p->resOnStack=0;
	do
	{
		i=p->pc++;
	}while(i<p->nOp && p->explain==2 && p->aOp[i].opcode!=OP_Explain);
	if(i>=p->nOp)
	{
		p->rc=0;
		rc=WN_SQL_DONE;
	}
	else
		if(db->u1.isInterrupted)
		{
			p->rc=WN_SQL_INTERRUPT;
			rc=WN_SQL_ERROR;
			WN_SQL3SetString(&p->zErrMsg,WN_SQL3ErrStr(p->rc),(char*)0);
		}
		else
		{
			Op *pOp=&p->aOp[i];
			Mem *pMem=p->aStack;
			pMem->flags=MEM_Int;
			pMem->type=WN_SQL_INTEGER;
			pMem->u.i=i;
			pMem++;
			pMem->flags=MEM_Static|MEM_Str|MEM_Term;
			pMem->z=(char*)WN_SQL3OpcodeNames[pOp->opcode];
			pMem->n=strlen(pMem->z);
			pMem->type=WN_SQL_TEXT;
			pMem->enc=WN_SQL_UTF8;
			pMem++;
			pMem->flags=MEM_Int;
			pMem->u.i=pOp->p1;
			pMem->type=WN_SQL_INTEGER;
			pMem++;
			pMem->flags=MEM_Int;
			pMem->u.i=pOp->p2;
			pMem->type=WN_SQL_INTEGER;
			pMem++;
			pMem->flags=MEM_Ephem|MEM_Str|MEM_Term;
			pMem->z=displayP3(pOp,pMem->zShort,sizeof(pMem->zShort));
			pMem->n=strlen(pMem->z);
			pMem->type=WN_SQL_TEXT;
			pMem->enc=WN_SQL_UTF8;
			p->nResColumn=5-2*(p->explain-1);
			p->pTos=pMem;
			p->rc=0;
			p->resOnStack=1;
			rc=WN_SQL_ROW;
		}
		return rc;
}
#endif
#ifdef WN_SQL_DEBUG
void WN_SQL3VdbePrintSql(Vdbe *p)
{
	int nOp=p->nOp;
	if(nOp<1)return;
	VdbeOp *pOp=&p->aOp[nOp-1];
	if(pOp->opcode==OP_Noop && pOp->p3)
	{
		const char *z=pOp->p3;
		while(isspace(*(u8*)z))z++;
		printf("SQL:[%s]\n",z);
	}
}
#endif
#if !defined(WN_SQL_OMIT_TRACE)&& defined(WN_SQL_ENABLE_IOTRACE)
void WN_SQL3VdbeIOTraceSql(Vdbe *p)
{
	if(WN_SQL3_io_trace==0)return;
	int nOp=p->nOp;
	if(nOp<1)return;
	VdbeOp *pOp=&p->aOp[nOp-1];
	if(pOp->opcode==OP_Noop && pOp->p3)
	{
		char *z=WN_SQL3StrDup(pOp->p3);
		int i,j;
		for(i=0;isspace((unsigned char)z[i]);i++);
		for(j=0;z[i];i++)
			if(isspace((unsigned char)z[i]))
			{
				if(z[i-1]!=' ')z[j++]=' ';
			}
			else
				z[j++]=z[i];
		z[j]=0;
		WN_SQL3_io_trace("SQL %s\n",z);
		WN_SQL3FreeX(z);
	}
}
#endif
void WN_SQL3VdbeMakeReady(Vdbe *p,int nVar,int nMem,int nCursor,int isExplain)
{
	int n;
	p->magic=VDBE_MAGIC_RUN;
	if(p->aStack==0)
	{
		int nArg,nStack;
		resolveP2Values(p,&nArg,&nStack);
		resizeOpArray(p,p->nOp);
		if(isExplain)nStack=10;
		p->aStack=WN_SQL3Malloc(nStack*sizeof(p->aStack[0])+nArg*sizeof(Mem*)+nVar*sizeof(Mem)+nVar*sizeof(char*)+nMem*sizeof(Mem)+nCursor*sizeof(Cursor*));
		if(!WN_SQL3MallocFailed())
		{
			p->aMem=&p->aStack[nStack];
			p->nMem=nMem;
			p->aVar=&p->aMem[nMem];
			p->nVar=nVar;
			p->okVar=0;
			p->apArg=(Mem**)&p->aVar[nVar];
			p->azVar=(char**)&p->apArg[nArg];
			p->apCsr=(Cursor**)&p->azVar[nVar];
			p->nCursor=nCursor;
			for(n=0;n<nVar;n++)p->aVar[n].flags=MEM_Null;
		}
	}
	for(n=0;n<p->nMem;n++)p->aMem[n].flags=MEM_Null;
	p->pTos=&p->aStack[-1];
	p->pc=-1;
	p->rc=0;
	p->uniqueCnt=0;
	p->returnDepth=0;
	p->errorAction=OE_Abort;
	p->popStack=0;
	p->explain |=isExplain;
	p->magic=VDBE_MAGIC_RUN;
	p->nChange=0;
	p->cacheCtr=1;
	p->minWriteFileFormat=255;
	p->openedStatement=0;
#ifdef VDBE_PROFILE
	int i;
	for(i=0;i<p->nOp;i++)
	{
		p->aOp[i].cnt=0;
		p->aOp[i].cycles=0;
	}
#endif
}
void WN_SQL3VdbeFreeCursor(Vdbe *p,Cursor *pCx)
{
	if(pCx==0)return;
	if(pCx->pCursor)WN_SQL3BtreeCloseCursor(pCx->pCursor);
	if(pCx->pBt)WN_SQL3BtreeClose(pCx->pBt);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(pCx->pVtabCursor)
	{
		WN_SQL3_vtab_cursor *pVtabCursor=pCx->pVtabCursor;
		const WN_SQL3_module *pModule=pCx->pModule;
		p->inVtabMethod=1;
		WN_SQL3SafetyOff(p->db);
		pModule->xClose(pVtabCursor);
		WN_SQL3SafetyOn(p->db);
		p->inVtabMethod=0;
	}
#endif
	WN_SQL3FreeX(pCx->pData);
	WN_SQL3FreeX(pCx->aType);
	WN_SQL3FreeX(pCx);
}
void closeAllCursors(Vdbe *p)
{
	int i;
	if(p->apCsr==0)return;
	for(i=0;i<p->nCursor;i++)
		if(!p->inVtabMethod ||(p->apCsr[i] && !p->apCsr[i]->pVtabCursor))
		{
			WN_SQL3VdbeFreeCursor(p,p->apCsr[i]);
			p->apCsr[i]=0;
		}
}
void Cleanup(Vdbe *p)
{
	int i;
	if(p->aStack)
	{
		releaseMemArray(p->aStack,1+(p->pTos-p->aStack));
		p->pTos=&p->aStack[-1];
	}
	closeAllCursors(p);
	releaseMemArray(p->aMem,p->nMem);
	WN_SQL3VdbeFifoClear(&p->sFifo);
	if(p->contextStack)
	{
		for(i=0;i<p->contextStackTop;i++)WN_SQL3VdbeFifoClear(&p->contextStack[i].sFifo);
		WN_SQL3FreeX(p->contextStack);
	}
	p->contextStack=0;
	p->contextStackDepth=0;
	p->contextStackTop=0;
	WN_SQL3FreeX(p->zErrMsg);
	p->zErrMsg=0;
	p->resOnStack=0;
}
void WN_SQL3VdbeSetNumCols(Vdbe *p,int nResColumn)
{
	Mem *pColName;
	int n;
	releaseMemArray(p->aColName,p->nResColumn*COLNAME_N);
	WN_SQL3FreeX(p->aColName);
	n=nResColumn*COLNAME_N;
	p->nResColumn=nResColumn;
	p->aColName=pColName=(Mem*)WN_SQL3Malloc(sizeof(Mem)*n);
	if(p->aColName==0)return;
	while(n--> 0)(pColName++)->flags=MEM_Null;
}
int WN_SQL3VdbeSetColName(Vdbe *p,int idx,int var,const char *zName,int N)
{
	int rc;
	Mem *pColName;
	if(WN_SQL3MallocFailed())return WN_SQL_NOMEM;
	pColName=&(p->aColName[idx+var*p->nResColumn]);
	if(N==P3_DYNAMIC || N==P3_STATIC)
		rc=WN_SQL3VdbeMemSetStr(pColName,zName,-1,WN_SQL_UTF8,WN_SQL_STATIC);
	else
		rc=WN_SQL3VdbeMemSetStr(pColName,zName,N,WN_SQL_UTF8,WN_SQL_TRANSIENT);
	if(rc==0 && N==P3_DYNAMIC)
	{
		pColName->flags=(pColName->flags&(~MEM_Static))|MEM_Dyn;
		pColName->xDel=0;
	}
	return rc;
}
int vdbeCommit(WN_SQL3 *db)
{
	int i,nTrans=0,rc=0,needXcommit=0;
	rc=WN_SQL3VtabSync(db,rc);
	if(rc)return rc;
	for(i=0;i<db->nDb;i++)
	{
		Btree *pBt=db->aDb[i].pBt;
		if(pBt && WN_SQL3BtreeIsInTrans(pBt))
		{
			needXcommit=1;
			if(i!=1)nTrans++;
		}
	}
	if(needXcommit && db->xCommitCallback)
	{
		WN_SQL3SafetyOff(db);
		rc=db->xCommitCallback(db->pCommitArg);
		WN_SQL3SafetyOn(db);
		if(rc)return WN_SQL_CONSTRAINT;
	}
	if(0==strlen(WN_SQL3BtreeGetFilename(db->aDb[0].pBt))|| nTrans<=1)
	{
		for(i=0;rc==0 && i<db->nDb;i++)
		{
			Btree *pBt=db->aDb[i].pBt;
			if(pBt)rc=WN_SQL3BtreeCommitPhaseOne(pBt,0);
		}
		for(i=0;rc==0 && i<db->nDb;i++)
		{
			Btree *pBt=db->aDb[i].pBt;
			if(pBt)rc=WN_SQL3BtreeCommitPhaseTwo(pBt);
		}
		if(rc==0)WN_SQL3VtabCommit(db);
	}
#ifndef WN_SQL_OMIT_DISKIO
	else
	{
		int needSync=0;
		char *zMaster=0;
		char const *zMainFile=WN_SQL3BtreeGetFilename(db->aDb[0].pBt);
		OsFile *master=0;
		do
		{
			u32 random;
			WN_SQL3FreeX(zMaster);
			WN_SQL3Randomness(sizeof(random),&random);
			zMaster=WN_SQL3MPrintf("%s-mj%08X",zMainFile,random&0x7fffffff);
			if(!zMaster)return WN_SQL_NOMEM;
		}while(WN_SQL3OsFileExists(zMaster));
		if(rc=WN_SQL3OsOpenExclusive(zMaster,&master,0))
		{
			WN_SQL3FreeX(zMaster);
			return rc;
		}
		for(i=0;i<db->nDb;i++)
		{
			Btree *pBt=db->aDb[i].pBt;
			if(i==1)continue;
			if(pBt && WN_SQL3BtreeIsInTrans(pBt))
			{
				char const *zFile=WN_SQL3BtreeGetJournalname(pBt);
				if(zFile[0]==0)continue;
				if(!needSync && !WN_SQL3BtreeSyncDisabled(pBt))needSync=1;
				rc=WN_SQL3OsWrite(master,zFile,strlen(zFile)+1);
				if(rc)
				{
					WN_SQL3OsClose(&master);
					WN_SQL3OsDelete(zMaster);
					WN_SQL3FreeX(zMaster);
					return rc;
				}
			}
		}
		zMainFile=WN_SQL3BtreeGetDirname(db->aDb[0].pBt);
		rc=WN_SQL3OsOpenDirectory(master,zMainFile);
		if(rc ||(needSync &&(rc=WN_SQL3OsSync(master,0))))
		{
			WN_SQL3OsClose(&master);
			WN_SQL3OsDelete(zMaster);
			WN_SQL3FreeX(zMaster);
			return rc;
		}
		for(i=0;rc==0 && i<db->nDb;i++)
		{
			Btree *pBt=db->aDb[i].pBt;
			if(pBt && WN_SQL3BtreeIsInTrans(pBt))rc=WN_SQL3BtreeCommitPhaseOne(pBt,zMaster);
		}
		WN_SQL3OsClose(&master);
		if(rc)
		{
			WN_SQL3FreeX(zMaster);
			return rc;
		}
		rc=WN_SQL3OsDelete(zMaster);
		WN_SQL3FreeX(zMaster);
		zMaster=0;
		if(rc)return rc;
		rc=WN_SQL3OsSyncDirectory(zMainFile);
		if(rc)return rc;
		disable_simulated_io_errors();
		for(i=0;i<db->nDb;i++)
		{
			Btree *pBt=db->aDb[i].pBt;
			if(pBt)WN_SQL3BtreeCommitPhaseTwo(pBt);
		}
		enable_simulated_io_errors();
		WN_SQL3VtabCommit(db);
	}
#endif
	return rc;
}
#ifndef NDEBUG
void checkActiveVdbeCnt(WN_SQL3 *db)
{
	int cnt=0;
	Vdbe *p=db->pVdbe;
	while(p)
	{
		if(p->magic==VDBE_MAGIC_RUN && p->pc>=0)cnt++;
		p=p->pNext;
	}
}
#else
#define checkActiveVdbeCnt(x)
#endif
void WN_SQL3AbortOtherActiveVdbes(WN_SQL3 *db,Vdbe *pExcept)
{
	Vdbe *pOther;
	for(pOther=db->pVdbe;pOther;pOther=pOther->pNext)
	{
		if(pOther==pExcept)continue;
		if(pOther->magic!=VDBE_MAGIC_RUN || pOther->pc<0)continue;
		checkActiveVdbeCnt(db);
		closeAllCursors(pOther);
		checkActiveVdbeCnt(db);
		pOther->aborted=1;
	}
}
int WN_SQL3VdbeHalt(Vdbe *p)
{
	WN_SQL3 *db=p->db;
	int i;
	int(*xFunc)(Btree *pBt)=0;
	int isSpecialError;
	if(WN_SQL3MallocFailed())p->rc=WN_SQL_NOMEM;
	if(p->magic!=VDBE_MAGIC_RUN)
	{
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		closeAllCursors(p);
#endif
		return 0;
	}
	closeAllCursors(p);
	checkActiveVdbeCnt(db);
	if(p->pc>=0)
	{
		int mrc;
		mrc=p->rc & 0xff;
		isSpecialError=((mrc==WN_SQL_NOMEM || mrc==WN_SQL_IOERR || mrc==WN_SQL_INTERRUPT)?1:0);
		if(isSpecialError)
		{
			int isReadOnly=1,isStatement=0;
			for(i=0;i<p->nOp;i++)
				switch(p->aOp[i].opcode)
				{
				case OP_Transaction:
					if(p->aOp[i].p2 || mrc!=WN_SQL_INTERRUPT)isReadOnly=0;
					break;
				case OP_Statement:
					isStatement=1;
				}
			if(!isReadOnly)
			{
				if(p->rc==WN_SQL_IOERR_BLOCKED && isStatement)
				{
					xFunc=WN_SQL3BtreeRollbackStmt;
					p->rc=WN_SQL_BUSY;
				}
				else
					if(p->rc==WN_SQL_NOMEM && isStatement)
						xFunc=WN_SQL3BtreeRollbackStmt;
					else
						WN_SQL3AbortOtherActiveVdbes(db,p);
				WN_SQL3RollbackAll(db);
				db->autoCommit=1;
			}
		}
	}
	if(db->autoCommit && db->activeVdbeCnt==1)
	{
		if(p->rc==0 ||(p->errorAction==OE_Fail && !isSpecialError))
		{
			int rc=vdbeCommit(db);
			if(rc==WN_SQL_BUSY)
				return WN_SQL_BUSY;
			else
				if(rc)
				{
					p->rc=rc;
					WN_SQL3RollbackAll(db);
				}
				else
					WN_SQL3CommitInternalChanges(db);
		}
		else
			WN_SQL3RollbackAll(db);
	}
	else
		if(!xFunc)
			if(p->rc==0 || p->errorAction==OE_Fail)
			{
				if(p->openedStatement)xFunc=WN_SQL3BtreeCommitStmt;
			}
			else
				if(p->errorAction==OE_Abort)
					xFunc=WN_SQL3BtreeRollbackStmt;
				else
				{
					WN_SQL3AbortOtherActiveVdbes(db,p);
					WN_SQL3RollbackAll(db);
					db->autoCommit=1;
				}
		xFunc==WN_SQL3BtreeCommitStmt ||xFunc==WN_SQL3BtreeRollbackStmt);
		for(i=0;xFunc && i<db->nDb;i++)
		{
			int rc;
			Btree *pBt=db->aDb[i].pBt;
			if(pBt)
			{
				rc=xFunc(pBt);
				if(rc &&(p->rc==0 || p->rc==WN_SQL_CONSTRAINT))
				{
					p->rc=rc;
					WN_SQL3SetString(&p->zErrMsg,0);
				}
			}
		}
		if(p->changeCntOn && p->pc>=0)
		{
			if(!xFunc || xFunc==WN_SQL3BtreeCommitStmt)
				WN_SQL3VdbeSetChanges(db,p->nChange);
			else
				WN_SQL3VdbeSetChanges(db,0);
			p->nChange=0;
		}
		if(p->rc && db->flags&WN_SQL_InternChanges)
		{
			WN_SQL3ResetInternalSchema(db,0);
			db->flags=(db->flags | WN_SQL_InternChanges);
		}
	}
	if(p->pc>=0)db->activeVdbeCnt--;
	p->magic=VDBE_MAGIC_HALT;
	checkActiveVdbeCnt(db);
	return 0;
}
void WN_SQL3VdbeResetStepResult(Vdbe *p)
{
	p->rc=0;
}
int WN_SQL3VdbeReset(Vdbe *p)
{
	WN_SQL3 *db=p->db;
	WN_SQL3SafetyOn(db);
	WN_SQL3VdbeHalt(p);
	WN_SQL3SafetyOff(db);
	if(p->pc>=0)
	{
		if(p->zErrMsg)
		{
			WN_SQL3ValueSetStr(db->pErr,-1,p->zErrMsg,WN_SQL_UTF8,WN_SQL3FreeX);
			db->errCode=p->rc;
			p->zErrMsg=0;
		}
		else
			if(p->rc)
				WN_SQL3Error(db,p->rc,0);
			else
				WN_SQL3Error(db,0,0);
	}
	else
		if(p->rc && p->expired)WN_SQL3Error(db,p->rc,0);
	Cleanup(p);
#ifdef VDBE_PROFILE
	FILE *out=fopen("vdbe_profile.out","a");
	if(out)
	{
		int i;
		fprintf(out,"----");
		for(i=0;i<p->nOp;i++)
			fprintf(out,"%02x",p->aOp[i].opcode);
		fprintf(out,"\n");
		for(i=0;i<p->nOp;i++)
		{
			fprintf(out,"%6d %10lld %8lld ",p->aOp[i].cnt,p->aOp[i].cycles,p->aOp[i].cnt>0 ? p->aOp[i].cycles/p->aOp[i].cnt :0);
			WN_SQL3VdbePrintOp(out,i,&p->aOp[i]);
		}
		fclose(out);
	}
#endif
	p->magic=VDBE_MAGIC_INIT;
	p->aborted=0;
	if(p->rc==WN_SQL_SCHEMA)WN_SQL3ResetInternalSchema(db,0);
	return p->rc & db->errMask;
}
int WN_SQL3VdbeFinalize(Vdbe *p)
{
	int rc=0;
	if(p->magic==VDBE_MAGIC_RUN || p->magic==VDBE_MAGIC_HALT)
		rc=WN_SQL3VdbeReset(p);
	else
		if(p->magic!=VDBE_MAGIC_INIT)return WN_SQL_MISUSE;
	WN_SQL3VdbeDelete(p);
	return rc;
}
void WN_SQL3VdbeDeleteAuxData(VdbeFunc *pVdbeFunc,int mask)
{
	int i;
	for(i=0;i<pVdbeFunc->nAux;i++)
	{
		struct AuxData *pAux=&pVdbeFunc->apAux[i];
		if((i>31 || !(mask&(1<<i)))&& pAux->pAux)
		{
			if(pAux->xDelete)pAux->xDelete(pAux->pAux);
			pAux->pAux=0;
		}
	}
}
void WN_SQL3VdbeDelete(Vdbe *p)
{
	int i;
	if(p==0)return;
	Cleanup(p);
	if(p->pPrev)
		p->pPrev->pNext=p->pNext;
	else
		p->db->pVdbe=p->pNext;
	if(p->pNext)p->pNext->pPrev=p->pPrev;
	if(p->aOp)
	{
		for(i=0;i<p->nOp;i++)
		{
			Op *pOp=&p->aOp[i];
			freeP3(pOp->p3type,pOp->p3);
		}
		WN_SQL3FreeX(p->aOp);
	}
	releaseMemArray(p->aVar,p->nVar);
	WN_SQL3FreeX(p->aLabel);
	WN_SQL3FreeX(p->aStack);
	releaseMemArray(p->aColName,p->nResColumn*COLNAME_N);
	WN_SQL3FreeX(p->aColName);
	WN_SQL3FreeX(p->zSql);
	p->magic=VDBE_MAGIC_DEAD;
	WN_SQL3FreeX(p);
}
int WN_SQL3VdbeCursorMoveto(Cursor *p)
{
	if(p->deferredMoveto)
	{
		int res,rc;
#ifdef WN_SQL_TEST
extern int WN_SQL3_search_count;
#endif
		if(rc=WN_SQL3BtreeMoveto(p->pCursor,0,p->movetoTarget,0,&res))return rc;
		*p->pIncrKey=0;
		p->lastRowid=keyToInt(p->movetoTarget);
		p->rowidIsValid=res==0;
		if(res<0)
			if(rc=WN_SQL3BtreeNext(p->pCursor,&res))return rc;
#ifdef WN_SQL_TEST
		WN_SQL3_search_count++;
#endif
		p->deferredMoveto=0;
		p->cacheStatus=CACHE_STALE;
	}
	return 0;
}
u32 WN_SQL3VdbeSerialType(Mem *pMem,int file_format)
{
	int flags=pMem->flags,n;
	if(flags&MEM_Null)return 0;
	if(flags&MEM_Int)
	{
# define MAX_6BYTE((((i64)0x00001000)<<32)-1)
		i64 i=pMem->u.i,u;
		if(file_format>=4 &&(i&1)==i)return 8+i;
		u=i<0 ?-i :i;
		if(u<=127)return 1;
		if(u<=32767)return 2;
		if(u<=8388607)return 3;
		if(u<=2147483647)return 4;
		if(u<=MAX_6BYTE)return 5;
		return 6;
	}
	if(flags&MEM_Real)return 7;
	n=pMem->n;
	if(flags & MEM_Zero)n+=pMem->u.i;
	return((n*2)+12+((flags&MEM_Str)!=0));
}
int WN_SQL3VdbeSerialTypeLen(u32 serial_type)
{
	if(serial_type>=12)
		return(serial_type-12)/2;
	else
	{
		const u8 aSize[]={0,1,2,3,4,6,8,8,0,0,0,0};
		return aSize[serial_type];
	}
}
#ifdef WN_SQL_MIXED_ENDIAN_64BIT_FLOAT
double floatSwap(double in)
{
	union
	{
		double r;
		u32 i[2];
	}u;
	u32 t;
	u.r=in;
	t=u.i[0];
	u.i[0]=u.i[1];
	u.i[1]=t;
	return u.r;
}
# define swapMixedEndianFloat(X) X=floatSwap(X)
#else
# define swapMixedEndianFloat(X)
#endif
int WN_SQL3VdbeSerialPut(u8 *buf,int nBuf,Mem *pMem,int file_format)
{
	u32 serial_type=WN_SQL3VdbeSerialType(pMem,file_format);
	int len;
	if(serial_type<=7 && serial_type>0)
	{
		u64 v;
		int i;
		if(serial_type==7)
		{
			swapMixedEndianFloat(pMem->r);
			memcpy(&v,&pMem->r,sizeof(v));
		}
		else
			v=pMem->u.i;
		len=i=WN_SQL3VdbeSerialTypeLen(serial_type);
		while(i--)
		{
			buf[i]=(v&0xFF);
			v >>=8;
		}
		return len;
	}
	if(serial_type>=12)
	{
		len=pMem->n;
		memcpy(buf,pMem->z,len);
		if(pMem->flags & MEM_Zero)
		{
			len+=pMem->u.i;
			if(len>nBuf)len=nBuf;
			memset(&buf[pMem->n],0,len-pMem->n);
		}
		return len;
	}
	return 0;
}
int WN_SQL3VdbeSerialGet(const unsigned char *buf,u32 serial_type,
								Mem *pMem)
{
	switch(serial_type)
	{
	case 10:
	case 11:
	case 0:
		pMem->flags=MEM_Null;
		break;
	case 1:
		pMem->u.i=(signed char)buf[0];
		pMem->flags=MEM_Int;
		return 1;
	case 2:
		pMem->u.i=(((signed char)buf[0])<<8)| buf[1];
		pMem->flags=MEM_Int;
		return 2;
	case 3:
		pMem->u.i=(((signed char)buf[0])<<16)|(buf[1]<<8)| buf[2];
		pMem->flags=MEM_Int;
		return 3;
	case 4:
		pMem->u.i=(buf[0]<<24)|(buf[1]<<16)|(buf[2]<<8)| buf[3];
		pMem->flags=MEM_Int;
		return 4;
	case 5:
		u64 x=(((signed char)buf[0])<<8)| buf[1];
		u32 y=(buf[2]<<24)|(buf[3]<<16)|(buf[4]<<8)| buf[5];
		x=(x<<32)| y;
		pMem->u.i=*(i64*)&x;
		pMem->flags=MEM_Int;
		return 6;
	case 6:
	case 7:
		u64 x;
		u32 y;
#if !defined(NDEBUG)&& !defined(WN_SQL_OMIT_FLOATING_POINT)
		const u64 t1=((u64)0x3ff00000)<<32;
		const double r1=1.0;
		double r2=r1;
		swapMixedEndianFloat(r2);
#endif
		x=(buf[0]<<24)|(buf[1]<<16)|(buf[2]<<8)| buf[3];
		y=(buf[4]<<24)|(buf[5]<<16)|(buf[6]<<8)| buf[7];
		x=(x<<32)| y;
		if(serial_type==6)
		{
			pMem->u.i=*(i64*)&x;
			pMem->flags=MEM_Int;
		}
		else
		{
			memcpy(&pMem->r,&x,sizeof(x));
			swapMixedEndianFloat(pMem->r);
			pMem->flags=MEM_Real;
		}
		return 8;
	case 8:
	case 9:
		pMem->u.i=serial_type-8;
		pMem->flags=MEM_Int;
		return 0;
	default:
		int len=(serial_type-12)/2;
		pMem->z=(char *)buf;
		pMem->n=len;
		pMem->xDel=0;
		if(serial_type&0x01)
			pMem->flags=MEM_Str | MEM_Ephem;
		else
			pMem->flags=MEM_Blob | MEM_Ephem;
		return len;
	}
	return 0;
}
#define GetVarint(A,B)((B=*(A))<=0x7f ? 1 :WN_SQL3GetVarint32(A,&B))
int WN_SQL3VdbeRecordCompare(
void *userData,int nKey1,const void *pKey1,int nKey2,const void *pKey2)
{
	KeyInfo *pKeyInfo=(KeyInfo*)userData;
	u32 d1,d2,idx1,idx2,szHdr1,szHdr2;
	int i=0,nField,rc=0;
	const unsigned char *aKey1=(const unsigned char *)pKey1;
	const unsigned char *aKey2=(const unsigned char *)pKey2;
	Mem mem1,mem2;
	mem1.enc=pKeyInfo->enc;
	mem2.enc=pKeyInfo->enc;
	idx1=GetVarint(aKey1,szHdr1);
	d1=szHdr1;
	idx2=GetVarint(aKey2,szHdr2);
	d2=szHdr2;
	nField=pKeyInfo->nField;
	while(idx1<szHdr1 && idx2<szHdr2)
	{
		u32 serial_type1,serial_type2;
		idx1+=GetVarint(aKey1+idx1,serial_type1);
		if(d1>=nKey1 && WN_SQL3VdbeSerialTypeLen(serial_type1)>0)break;
		idx2+=GetVarint(aKey2+idx2,serial_type2);
		if(d2>=nKey2 && WN_SQL3VdbeSerialTypeLen(serial_type2)>0)break;
		d1+=WN_SQL3VdbeSerialGet(&aKey1[d1],serial_type1,&mem1);
		d2+=WN_SQL3VdbeSerialGet(&aKey2[d2],serial_type2,&mem2);
		rc=WN_SQL3MemCompare(&mem1,&mem2,i<nField ? pKeyInfo->aColl[i] :0);
		if(mem1.flags & MEM_Dyn)WN_SQL3VdbeMemRelease(&mem1);
		if(mem2.flags & MEM_Dyn)WN_SQL3VdbeMemRelease(&mem2);
		if(rc)break;
		i++;
	}
	if(rc==0)
	{
		if(pKeyInfo->incrKey)
			rc=-1;
		else
			if(d1<nKey1)
				rc=1;
			else
				if(d2<nKey2)rc=-1;
	}
	else
		if(pKeyInfo->aSortOrder && i<pKeyInfo->nField && pKeyInfo->aSortOrder[i])			rc=-rc;
	return rc;
}
int WN_SQL3VdbeIdxRowidLen(const u8 *aKey)
{
	u32 szHdr,typeRowid;
	WN_SQL3GetVarint32(aKey,&szHdr);
	WN_SQL3GetVarint32(&aKey[szHdr-1],&typeRowid);
	return WN_SQL3VdbeSerialTypeLen(typeRowid);
}
int WN_SQL3VdbeIdxRowid(BtCursor *pCur,i64 *rowid)
{
	i64 nCellKey=0;
	int rc;
	u32 szHdr,typeRowid,lenRowid;
	Mem m,v;
	WN_SQL3BtreeKeySize(pCur,&nCellKey);
	if(nCellKey<=0)	return WN_SQL_CORRUPT_BKPT;
	rc=WN_SQL3VdbeMemFromBtree(pCur,0,nCellKey,1,&m);
	if(rc)return rc;
	WN_SQL3GetVarint32((u8*)m.z,&szHdr);
	WN_SQL3GetVarint32((u8*)&m.z[szHdr-1],&typeRowid);
	lenRowid=WN_SQL3VdbeSerialTypeLen(typeRowid);
	WN_SQL3VdbeSerialGet((u8*)&m.z[m.n-lenRowid],typeRowid,&v);
	*rowid=v.u.i;
	WN_SQL3VdbeMemRelease(&m);
	return 0;
}
int WN_SQL3VdbeIdxKeyCompare(Cursor *pC,int nKey,const u8 *pKey,int *res)
{
	i64 nCellKey=0;
	int rc,lenRowid;
	BtCursor *pCur=pC->pCursor;
	Mem m;
	WN_SQL3BtreeKeySize(pCur,&nCellKey);
	if(nCellKey<=0)
	{
		*res=0;
		return 0;
	}
	rc=WN_SQL3VdbeMemFromBtree(pC->pCursor,0,nCellKey,1,&m);
	if(rc)return rc;
	lenRowid=WN_SQL3VdbeIdxRowidLen((u8*)m.z);
	*res=WN_SQL3VdbeRecordCompare(pC->pKeyInfo,m.n-lenRowid,m.z,nKey,pKey);
	WN_SQL3VdbeMemRelease(&m);
	return 0;
}
void WN_SQL3VdbeSetChanges(WN_SQL3 *db,int nChange)
{
	db->nChange=nChange;
	db->nTotalChange+=nChange;
}
void WN_SQL3VdbeCountChanges(Vdbe *v)
{
	v->changeCntOn=1;
}
void WN_SQL3ExpirePreparedStatements(WN_SQL3 *db)
{
	Vdbe *p;
	for(p=db->pVdbe;p;p=p->pNext)p->expired=1;
}
WN_SQL3 *WN_SQL3VdbeDb(Vdbe *v)
{
	return v->db;
}
int WN_SQL3_expired(WN_SQL3_stmt *pStmt)
{
	Vdbe *p=(Vdbe*)pStmt;
	return p==0 || p->expired;
}
const void *WN_SQL3_value_blob(WN_SQL3_value *pVal)
{
	Mem *p=(Mem*)pVal;
	if(p->flags &(MEM_Blob|MEM_Str))
	{
		WN_SQL3VdbeMemExpandBlob(p);
		p->flags &=~MEM_Str;
		p->flags |=MEM_Blob;
		return p->z;
	}
	else
		return WN_SQL3_value_text(pVal);
}
int WN_SQL3_value_bytes(WN_SQL3_value *pVal)
{
	return WN_SQL3ValueBytes(pVal,WN_SQL_UTF8);
}
int WN_SQL3_value_bytes16(WN_SQL3_value *pVal)
{
	return WN_SQL3ValueBytes(pVal,WN_SQL_UTF16NATIVE);
}
double WN_SQL3_value_double(WN_SQL3_value *pVal)
{
	return WN_SQL3VdbeRealValue((Mem*)pVal);
}
int WN_SQL3_value_int(WN_SQL3_value *pVal)
{
	return WN_SQL3VdbeIntValue((Mem*)pVal);
}
WN_SQL_int64 WN_SQL3_value_int64(WN_SQL3_value *pVal)
{
	return WN_SQL3VdbeIntValue((Mem*)pVal);
}
const unsigned char *WN_SQL3_value_text(WN_SQL3_value *pVal)
{
	return(const unsigned char *)WN_SQL3ValueText(pVal,WN_SQL_UTF8);
}
#ifndef WN_SQL_OMIT_UTF16
const void *WN_SQL3_value_text16(WN_SQL3_value* pVal)
{
	return WN_SQL3ValueText(pVal,WN_SQL_UTF16NATIVE);
}
const void *WN_SQL3_value_text16be(WN_SQL3_value *pVal)
{
	return WN_SQL3ValueText(pVal,WN_SQL_UTF16BE);
}
const void *WN_SQL3_value_text16le(WN_SQL3_value *pVal)
{
	return WN_SQL3ValueText(pVal,WN_SQL_UTF16LE);
}
#endif
int WN_SQL3_value_type(WN_SQL3_value* pVal)
{
	return pVal->type;
}
void WN_SQL3_result_blob(WN_SQL3_context *pCtx,const void *z,int n,void(*xDel)(void *))
{
	WN_SQL3VdbeMemSetStr(&pCtx->s,z,n,0,xDel);
}
void WN_SQL3_result_double(WN_SQL3_context *pCtx,double rVal)
{
	WN_SQL3VdbeMemSetDouble(&pCtx->s,rVal);
}
void WN_SQL3_result_error(WN_SQL3_context *pCtx,const char *z,int n)
{
	pCtx->isError=1;
	WN_SQL3VdbeMemSetStr(&pCtx->s,z,n,WN_SQL_UTF8,WN_SQL_TRANSIENT);
}
#ifndef WN_SQL_OMIT_UTF16
void WN_SQL3_result_error16(WN_SQL3_context *pCtx,const void *z,int n)
{
	pCtx->isError=1;
	WN_SQL3VdbeMemSetStr(&pCtx->s,z,n,WN_SQL_UTF16NATIVE,WN_SQL_TRANSIENT);
}
#endif
void WN_SQL3_result_int(WN_SQL3_context *pCtx,int iVal)
{
	WN_SQL3VdbeMemSetInt64(&pCtx->s,(i64)iVal);
}
void WN_SQL3_result_int64(WN_SQL3_context *pCtx,i64 iVal)
{
	WN_SQL3VdbeMemSetInt64(&pCtx->s,iVal);
}
void WN_SQL3_result_null(WN_SQL3_context *pCtx)
{
	WN_SQL3VdbeMemSetNull(&pCtx->s);
}
void WN_SQL3_result_text(WN_SQL3_context *pCtx,const char *z,int n,void(*xDel)(void *))
{
	WN_SQL3VdbeMemSetStr(&pCtx->s,z,n,WN_SQL_UTF8,xDel);
}
#ifndef WN_SQL_OMIT_UTF16
void WN_SQL3_result_text16(WN_SQL3_context *pCtx,const void *z,int n,void(*xDel)(void *))
{
	WN_SQL3VdbeMemSetStr(&pCtx->s,z,n,WN_SQL_UTF16NATIVE,xDel);
}
void WN_SQL3_result_text16be(WN_SQL3_context *pCtx,const void *z,int n,void(*xDel)(void *))
{
	WN_SQL3VdbeMemSetStr(&pCtx->s,z,n,WN_SQL_UTF16BE,xDel);
}
void WN_SQL3_result_text16le(WN_SQL3_context *pCtx,const void *z,int n,void(*xDel)(void *))
{
	WN_SQL3VdbeMemSetStr(&pCtx->s,z,n,WN_SQL_UTF16LE,xDel);
}
#endif
void WN_SQL3_result_value(WN_SQL3_context *pCtx,WN_SQL3_value *pValue)
{
	WN_SQL3VdbeMemCopy(&pCtx->s,pValue);
}
void WN_SQL3_result_zeroblob(WN_SQL3_context *pCtx,int n)
{
	WN_SQL3VdbeMemSetZeroBlob(&pCtx->s,n);
}
void WN_SQL3_result_error_toobig(WN_SQL3_context *pCtx)
{
	WN_SQL3VdbeMemSetZeroBlob(&pCtx->s,WN_SQL_MAX_LENGTH+1);
}
int WN_SQL3Step(Vdbe *p)
{
	WN_SQL3 *db;
	int rc;
	if(p==0 || p->magic!=VDBE_MAGIC_RUN)return WN_SQL_MISUSE;
	if(p->aborted)return WN_SQL_ABORT;
	if(p->pc<=0 && p->expired)
	{
		if(p->rc==0)p->rc=WN_SQL_SCHEMA;
		rc=WN_SQL_ERROR;
		goto end_of_step;
	}
	db=p->db;
	if(WN_SQL3SafetyOn(db))
	{
		p->rc=WN_SQL_MISUSE;
		return WN_SQL_MISUSE;
	}
	if(p->pc<0)
	{
		if(db->activeVdbeCnt==0)db->u1.isInterrupted=0;
#ifndef WN_SQL_OMIT_TRACE
		if(db->xTrace && !db->init.busy)
		{
			WN_SQL3SafetyOff(db);
			db->xTrace(db->pTraceArg,p->aOp[p->nOp-1].p3);
			if(WN_SQL3SafetyOn(db))
			{
				p->rc=WN_SQL_MISUSE;
				return WN_SQL_MISUSE;
			}
		}
		if(db->xProfile && !db->init.busy)
		{
			double rNow;
			WN_SQL3OsCurrentTime(&rNow);
			p->startTime=(rNow-(int)rNow)*3600.0*24.0*1000000000.0;
		}
#endif
#ifdef WN_SQL_DEBUG
if((db->flags & WN_SQL_SqlTrace)){
WN_SQL3DebugPrintf("SQL-trace:%s\n",p->aOp[p->nOp-1].p3);
}
#endif
		db->activeVdbeCnt++;
		p->pc=0;
	}
#ifndef WN_SQL_OMIT_EXPLAIN
	if(p->explain)
	{
		rc=WN_SQL3VdbeList(p);
	}
	else
#endif
		rc=WN_SQL3VdbeExec(p);
	if(WN_SQL3SafetyOff(db))rc=WN_SQL_MISUSE;
#ifndef WN_SQL_OMIT_TRACE
	if(rc!=WN_SQL_ROW && db->xProfile && !db->init.busy)
	{
		double rNow;
		u64 elapseTime;
		WN_SQL3OsCurrentTime(&rNow);
		elapseTime=(rNow-(int)rNow)*3600.0*24.0*1000000000.0-p->startTime;
		db->xProfile(db->pProfileArg,p->aOp[p->nOp-1].p3,elapseTime);
	}
#endif
	WN_SQL3Error(p->db,rc,0);
	p->rc=WN_SQL3ApiExit(p->db,p->rc);
end_of_step:
	if(p->zSql &&(rc&0xff)<WN_SQL_ROW)
	{
		WN_SQL3Error(p->db,p->rc,0);
		return p->rc;
	}
	else
		return rc;
}
#ifdef WN_SQL_OMIT_PARSER
int WN_SQL3_step(WN_SQL3_stmt *pStmt)
{
	return WN_SQL3Step((Vdbe*)pStmt);
}
#else
int WN_SQL3_step(WN_SQL3_stmt *pStmt)
{
	int cnt=0,rc;
	Vdbe *v=(Vdbe*)pStmt;
	while((rc=WN_SQL3Step(v))==WN_SQL_SCHEMA && cnt++<5 && WN_SQL3Reprepare(v))
	{
		WN_SQL3_reset(pStmt);
		v->expired=0;
	}
	return rc;
}
#endif
void *WN_SQL3_user_data(WN_SQL3_context *p)
{
	return p->pFunc->pUserData;
}
void WN_SQL3InvalidFunction(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	const char *zName=context->pFunc->zName;
	char *zErr;
	zErr=WN_SQL3MPrintf("unable to use function %s in the requested context",zName);
	WN_SQL3_result_error(context,zErr,-1);
	WN_SQL3FreeX(zErr);
}
void *WN_SQL3_aggregate_context(WN_SQL3_context *p,int nByte)
{
	Mem *pMem=p->pMem;
	if((pMem->flags & MEM_Agg)==0)
	{
		if(nByte==0)
			pMem->z=0;
		else
		{
			pMem->flags=MEM_Agg;
			pMem->xDel=WN_SQL3FreeX;
			pMem->u.pDef=p->pFunc;
			if(nByte<=NBFS)
			{
				pMem->z=pMem->zShort;
				memset(pMem->z,0,nByte);
			}
			else
				pMem->z=WN_SQL3Malloc(nByte);
		}
	}
	return(void*)pMem->z;
}
void *WN_SQL3_get_auxdata(WN_SQL3_context *pCtx,int iArg)
{
	VdbeFunc *pVdbeFunc=pCtx->pVdbeFunc;
	if(!pVdbeFunc || iArg>=pVdbeFunc->nAux || iArg<0)return 0;
	return pVdbeFunc->apAux[iArg].pAux;
}
void WN_SQL3_set_auxdata(WN_SQL3_context *pCtx,int iArg,void *pAux,void(*xDelete)(void*))
{
	struct AuxData *pAuxData;
	VdbeFunc *pVdbeFunc;
	if(iArg<0)return;
	pVdbeFunc=pCtx->pVdbeFunc;
	if(!pVdbeFunc || pVdbeFunc->nAux<=iArg)
	{
		int nMalloc=sizeof(VdbeFunc)+sizeof(struct AuxData)*iArg;
		pVdbeFunc=WN_SQLRealloc(pVdbeFunc,nMalloc);
		if(!pVdbeFunc)return;
		pCtx->pVdbeFunc=pVdbeFunc;
		memset(&pVdbeFunc->apAux[pVdbeFunc->nAux],0,sizeof(struct AuxData)*(iArg+1-pVdbeFunc->nAux));
		pVdbeFunc->nAux=iArg+1;
		pVdbeFunc->pFunc=pCtx->pFunc;
	}
	pAuxData=&pVdbeFunc->apAux[iArg];
	if(pAuxData->pAux && pAuxData->xDelete)pAuxData->xDelete(pAuxData->pAux);
	pAuxData->pAux=pAux;
	pAuxData->xDelete=xDelete;
}
int WN_SQL3_aggregate_count(WN_SQL3_context *p)
{
	return p->pMem->n;
}
int WN_SQL3_column_count(WN_SQL3_stmt *pStmt)
{
	Vdbe *pVm=(Vdbe *)pStmt;
	return pVm ? pVm->nResColumn :0;
}
int WN_SQL3_data_count(WN_SQL3_stmt *pStmt)
{
	Vdbe *pVm=(Vdbe *)pStmt;
	if(pVm==0 || !pVm->resOnStack)return 0;
	return pVm->nResColumn;
}
Mem *columnMem(WN_SQL3_stmt *pStmt,int i)
{
	Vdbe *pVm=(Vdbe *)pStmt;
	int vals=WN_SQL3_data_count(pStmt);
	if(pVm==0 || pVm->resOnStack==0 || i>=pVm->nResColumn || i<0)
	{
		const Mem nullMem={{0},0.0,"",0,MEM_Null,WN_SQL_NULL};
		WN_SQL3Error(pVm->db,WN_SQL_RANGE,0);
		return(Mem*)&nullMem;
	}
	return &pVm->pTos[(1-vals)+i];
}
void columnMallocFailure(WN_SQL3_stmt *pStmt)
{
	Vdbe *p=(Vdbe *)pStmt;
	p->rc=WN_SQL3ApiExit(0,p->rc);
}
const void *WN_SQL3_column_blob(WN_SQL3_stmt *pStmt,int i)
{
	const void *val;
	val=WN_SQL3_value_blob(columnMem(pStmt,i));
	columnMallocFailure(pStmt);
	return val;
}
int WN_SQL3_column_bytes(WN_SQL3_stmt *pStmt,int i)
{
	int val=WN_SQL3_value_bytes(columnMem(pStmt,i));
	columnMallocFailure(pStmt);
	return val;
}
int WN_SQL3_column_bytes16(WN_SQL3_stmt *pStmt,int i)
{
	int val=WN_SQL3_value_bytes16(columnMem(pStmt,i));
	columnMallocFailure(pStmt);
	return val;
}
double WN_SQL3_column_double(WN_SQL3_stmt *pStmt,int i)
{
	double val=WN_SQL3_value_double(columnMem(pStmt,i));
	columnMallocFailure(pStmt);
	return val;
}
int WN_SQL3_column_int(WN_SQL3_stmt *pStmt,int i)
{
	int val=WN_SQL3_value_int(columnMem(pStmt,i));
	columnMallocFailure(pStmt);
	return val;
}
WN_SQL_int64 WN_SQL3_column_int64(WN_SQL3_stmt *pStmt,int i)
{
	WN_SQL_int64 val=WN_SQL3_value_int64(columnMem(pStmt,i));
	columnMallocFailure(pStmt);
	return val;
}
const unsigned char *WN_SQL3_column_text(WN_SQL3_stmt *pStmt,int i)
{
	const unsigned char *val=WN_SQL3_value_text(columnMem(pStmt,i));
	columnMallocFailure(pStmt);
	return val;
}
WN_SQL3_value *WN_SQL3_column_value(WN_SQL3_stmt *pStmt,int i)
{
	return columnMem(pStmt,i);
}
#ifndef WN_SQL_OMIT_UTF16
const void *WN_SQL3_column_text16(WN_SQL3_stmt *pStmt,int i)
{
	const void *val=WN_SQL3_value_text16(columnMem(pStmt,i));
	columnMallocFailure(pStmt);
	return val;
}
#endif
int WN_SQL3_column_type(WN_SQL3_stmt *pStmt,int i)
{
	return WN_SQL3_value_type(columnMem(pStmt,i));
}
const void *columnName(WN_SQL3_stmt *pStmt,int N,const void *(*xFunc)(Mem*),int useType)
{
	const void *ret;
	Vdbe *p=(Vdbe *)pStmt;
	int n=WN_SQL3_column_count(pStmt);
	if(p==0 || N>=n || N<0)return 0;
	N+=useType*n;
	ret=xFunc(&p->aColName[N]);
	WN_SQL3ApiExit(0,0);
	return ret;
}
const char *WN_SQL3_column_name(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text,COLNAME_NAME);
}
#ifndef WN_SQL_OMIT_UTF16
const void *WN_SQL3_column_name16(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text16,COLNAME_NAME);
}
#endif
const char *WN_SQL3_column_decltype(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text,COLNAME_DECLTYPE);
}
#ifndef WN_SQL_OMIT_UTF16
const void *WN_SQL3_column_decltype16(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text16,COLNAME_DECLTYPE);
}
#endif
#ifdef WN_SQL_ENABLE_COLUMN_METADATA
const char *WN_SQL3_column_database_name(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text,COLNAME_DATABASE);
}
#ifndef WN_SQL_OMIT_UTF16
const void *WN_SQL3_column_database_name16(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text16,COLNAME_DATABASE);
}
#endif
const char *WN_SQL3_column_table_name(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text,COLNAME_TABLE);
}
#ifndef WN_SQL_OMIT_UTF16
const void *WN_SQL3_column_table_name16(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text16,COLNAME_TABLE);
}
#endif
const char *WN_SQL3_column_origin_name(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text,COLNAME_COLUMN);
}
#ifndef WN_SQL_OMIT_UTF16
const void *WN_SQL3_column_origin_name16(WN_SQL3_stmt *pStmt,int N)
{
	return columnName(pStmt,N,(const void*(*)(Mem*))WN_SQL3_value_text16,COLNAME_COLUMN);
}
#endif
#endif
int vdbeUnbind(Vdbe *p,int i)
{
	if(p==0 || p->magic!=VDBE_MAGIC_RUN || p->pc>=0)
	{
		if(p)WN_SQL3Error(p->db,WN_SQL_MISUSE,0);
		return WN_SQL_MISUSE;
	}
	if(i<1 || i>p->nVar)
	{
		WN_SQL3Error(p->db,WN_SQL_RANGE,0);
		return WN_SQL_RANGE;
	}
	i--;
	Mem *pVar=&p->aVar[i];
	WN_SQL3VdbeMemRelease(pVar);
	pVar->flags=MEM_Null;
	WN_SQL3Error(p->db,0,0);
	return 0;
}
int bindText(WN_SQL3_stmt *pStmt,int i,const void *zData,int nData,void(*xDel)(void*),int encoding)
{
	Vdbe *p=(Vdbe *)pStmt;
	Mem *pVar;
	int rc;
	rc=vdbeUnbind(p,i);
	if(rc || zData==0)return rc;
	pVar=&p->aVar[i-1];
	rc=WN_SQL3VdbeMemSetStr(pVar,zData,nData,encoding,xDel);
	if(rc==0 && encoding)rc=WN_SQL3VdbeChangeEncoding(pVar,ENC(p->db));
	WN_SQL3Error(((Vdbe *)pStmt)->db,rc,0);
	return WN_SQL3ApiExit(((Vdbe *)pStmt)->db,rc);
}
int WN_SQL3_bind_blob(WN_SQL3_stmt *pStmt,int i,const void *zData,int nData,void(*xDel)(void*))
{
	return bindText(pStmt,i,zData,nData,xDel,0);
}
int WN_SQL3_bind_double(WN_SQL3_stmt *pStmt,int i,double rValue)
{
	Vdbe *p=(Vdbe *)pStmt;
	int rc=vdbeUnbind(p,i);
	if(rc==0)WN_SQL3VdbeMemSetDouble(&p->aVar[i-1],rValue);
	return rc;
}
int WN_SQL3_bind_int(WN_SQL3_stmt *p,int i,int iValue)
{
	return WN_SQL3_bind_int64(p,i,(i64)iValue);
}
int WN_SQL3_bind_int64(WN_SQL3_stmt *pStmt,int i,WN_SQL_int64 iValue)
{
	Vdbe *p=(Vdbe *)pStmt;
	int rc=vdbeUnbind(p,i);
	if(rc==0)WN_SQL3VdbeMemSetInt64(&p->aVar[i-1],iValue);
	return rc;
}
int WN_SQL3_bind_null(WN_SQL3_stmt* p,int i)
{
	return vdbeUnbind((Vdbe *)p,i);
}
int WN_SQL3_bind_text(WN_SQL3_stmt *pStmt,int i,const char *zData,int nData,void(*xDel)(void*))
{
	return bindText(pStmt,i,zData,nData,xDel,WN_SQL_UTF8);
}
#ifndef WN_SQL_OMIT_UTF16
int WN_SQL3_bind_text16(WN_SQL3_stmt *pStmt,int i,const void *zData,int nData,void(*xDel)(void*))
{
	return bindText(pStmt,i,zData,nData,xDel,WN_SQL_UTF16NATIVE);
}
#endif
int WN_SQL3_bind_value(WN_SQL3_stmt *pStmt,int i,const WN_SQL3_value *pValue)
{
	int rc;
	Vdbe *p=(Vdbe *)pStmt;
	rc=vdbeUnbind(p,i);
	if(rc==0)WN_SQL3VdbeMemCopy(&p->aVar[i-1],pValue);
	return rc;
}
int WN_SQL3_bind_zeroblob(WN_SQL3_stmt *pStmt,int i,int n)
{
	Vdbe *p=(Vdbe *)pStmt;
	int rc=vdbeUnbind(p,i);
	if(rc==0)WN_SQL3VdbeMemSetZeroBlob(&p->aVar[i-1],n);
	return rc;
}
int WN_SQL3_bind_parameter_count(WN_SQL3_stmt *pStmt)
{
	Vdbe *p=(Vdbe*)pStmt;
	return p ? p->nVar :0;
}
void createVarMap(Vdbe *p)
{
	if(!p->okVar)
	{
		int j;
		Op *pOp;
		for(j=0,pOp=p->aOp;j<p->nOp;j++,pOp++)
			if(pOp->opcode==OP_Variable)p->azVar[pOp->p1-1]=pOp->p3;
		p->okVar=1;
	}
}
const char *WN_SQL3_bind_parameter_name(WN_SQL3_stmt *pStmt,int i)
{
	Vdbe *p=(Vdbe*)pStmt;
	if(p==0 || i<1 || i>p->nVar)return 0;
	createVarMap(p);
	return p->azVar[i-1];
}
int WN_SQL3_bind_parameter_index(WN_SQL3_stmt *pStmt,const char *zName)
{
	Vdbe *p=(Vdbe*)pStmt;
	if(p==0) return 0;
	createVarMap(p);
	if(zName)
	{
		int i;
		for(i=0;i<p->nVar;i++)
		{
			const char *z=p->azVar[i];
			if(z && strcmp(z,zName)==0)	return i+1;
		}
	}
	return 0;
}
int WN_SQL3_transfer_bindings(WN_SQL3_stmt *pFromStmt,WN_SQL3_stmt *pToStmt)
{
	Vdbe *pFrom=(Vdbe*)pFromStmt,*pTo=(Vdbe*)pToStmt;
	int i,rc=0;
	if((pFrom->magic!=VDBE_MAGIC_RUN && pFrom->magic!=VDBE_MAGIC_HALT)||(pTo->magic!=VDBE_MAGIC_RUN && pTo->magic!=VDBE_MAGIC_HALT))return WN_SQL_MISUSE;
	if(pFrom->nVar!=pTo->nVar)return WN_SQL_ERROR;
	for(i=0;rc==0 && i<pFrom->nVar;i++)
	{
		WN_SQL3MallocDisallow();
		rc=WN_SQL3VdbeMemMove(&pTo->aVar[i],&pFrom->aVar[i]);
		WN_SQL3MallocAllow();
	}
	return rc;
}
WN_SQL3 *WN_SQL3_db_handle(WN_SQL3_stmt *pStmt)
{
	return pStmt ?((Vdbe*)pStmt)->db :0;
}
#ifdef WN_SQL_TEST
int WN_SQL3_search_count=0;
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_interrupt_count=0;
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_sort_count=0;
#endif
#ifdef WN_SQL_TEST
int WN_SQL3_max_blobsize=0;
#endif
#define Release(P) if((P)->flags&MEM_Dyn)WN_SQL3VdbeMemRelease(P);
#define Stringify(P,enc) \
if(((P)->flags&(MEM_Str|MEM_Blob))==0 && WN_SQL3VdbeMemStringify(P,enc))\
{goto no_mem;}
#define Dynamicify(P,enc) WN_SQL3VdbeMemDynamicify(P)
#define GetVarint(A,B)((B=*(A))<=0x7f ? 1 :WN_SQL3GetVarint32(A,&B))
#define Deephemeralize(P) \
if(((P)->flags&MEM_Ephem)\
&& WN_SQL3VdbeMemMakeWriteable(P))goto no_mem;
#define ExpandBlob(P)(((P)->flags&MEM_Zero)?WN_SQL3VdbeMemExpandBlob(P):0)
#define storeTypeInfo(A,B)_storeTypeInfo(A)
void _storeTypeInfo(Mem *pMem)
{
	int flags=pMem->flags;
	if(flags & MEM_Null)
		pMem->type=WN_SQL_NULL;
	else
		if(flags & MEM_Int)
			pMem->type=WN_SQL_INTEGER;
		else
			if(flags & MEM_Real)
				pMem->type=WN_SQL_FLOAT;
			else
				if(flags & MEM_Str)
					pMem->type=WN_SQL_TEXT;
				else
					pMem->type=WN_SQL_BLOB;
}
void popStack(Mem **ppTos,int N)
{
	Mem *pTos=*ppTos;
	while(N>0)
	{
		N--;
		Release(pTos);
		pTos--;
	}
	*ppTos=pTos;
}
Cursor *allocateCursor(Vdbe *p,int iCur,int iDb)
{
	Cursor *pCx;
	if(p->apCsr[iCur])WN_SQL3VdbeFreeCursor(p,p->apCsr[iCur]);
	p->apCsr[iCur]=pCx=WN_SQL3Malloc(sizeof(Cursor));
	if(pCx)pCx->iDb=iDb;
	return pCx;
}
void applyNumericAffinity(Mem *pRec)
{
	if((pRec->flags &(MEM_Real|MEM_Int))==0)
	{
		int realnum;
		WN_SQL3VdbeMemNulTerminate(pRec);
		if((pRec->flags&MEM_Str)&& WN_SQL3IsNumber(pRec->z,&realnum,pRec->enc))
		{
			i64 value;
			WN_SQL3VdbeChangeEncoding(pRec,WN_SQL_UTF8);
			if(!realnum && WN_SQL3Atoi64(pRec->z,&value))
			{
				WN_SQL3VdbeMemRelease(pRec);
				pRec->u.i=value;
				pRec->flags=MEM_Int;
			}
			else
				WN_SQL3VdbeMemRealify(pRec);
		}
	}
}
void applyAffinity(Mem *pRec,char affinity,u8 enc)
{
	if(affinity==WN_SQL_AFF_TEXT)
	{
		if(0==(pRec->flags&MEM_Str)&&(pRec->flags&(MEM_Real|MEM_Int)))
			WN_SQL3VdbeMemStringify(pRec,enc);
		pRec->flags &=~(MEM_Real|MEM_Int);
	}
	else
		if(affinity!=WN_SQL_AFF_NONE)
		{
			|| affinity==WN_SQL_AFF_NUMERIC);
			applyNumericAffinity(pRec);
			if(pRec->flags & MEM_Real)WN_SQL3VdbeIntegerAffinity(pRec);
		}
}
int WN_SQL3_value_numeric_type(WN_SQL3_value *pVal)
{
	Mem *pMem=(Mem*)pVal;
	applyNumericAffinity(pMem);
	storeTypeInfo(pMem,0);
	return pMem->type;
}
void WN_SQL3ValueApplyAffinity(WN_SQL3_value *pVal,u8 affinity,u8 enc)
{
	applyAffinity((Mem *)pVal,affinity,enc);
}
#ifdef WN_SQL_DEBUG
void WN_SQL3VdbeMemPrettyPrint(Mem *pMem,char *zBuf)
{
	char *zCsr=zBuf;
	int f=pMem->flags;
	const char *const encnames[]={"(X)","(8)","(16LE)","(16BE)"};
	if(f&MEM_Blob)
	{
		int i;
		char c;
		if(f & MEM_Dyn)
			c='z';
		else
			if(f & MEM_Static)
				c='t';
			else
				if(f & MEM_Ephem)
					c='e';
				else
					c='s';
		WN_SQL3_snprintf(100,zCsr,"%c",c);
		zCsr+=strlen(zCsr);
		WN_SQL3_snprintf(100,zCsr,"%d[",pMem->n);
		zCsr+=strlen(zCsr);
		for(i=0;i<16 && i<pMem->n;i++)
		{
			WN_SQL3_snprintf(100,zCsr,"%02X",((int)pMem->z[i] & 0xFF));
			zCsr+=strlen(zCsr);
		}
		for(i=0;i<16 && i<pMem->n;i++)
		{
			char z=pMem->z[i];
			if(z<32 || z>126)
				*zCsr++='.';
			else
				*zCsr++=z;
		}
		WN_SQL3_snprintf(100,zCsr,"]%s",encnames[pMem->enc]);
		zCsr+=strlen(zCsr);
		if(f & MEM_Zero)
		{
			WN_SQL3_snprintf(100,zCsr,"+%lldz",pMem->u.i);
			zCsr+=strlen(zCsr);
		}
		*zCsr='\0';
	}
	else
		if(f & MEM_Str)
		{
			int j,k;
			zBuf[0]=' ';
			if(f & MEM_Dyn)
				zBuf[1]='z';
			else
				if(f & MEM_Static)
					zBuf[1]='t';
				else
					if(f & MEM_Ephem)
						zBuf[1]='e';
					else
						zBuf[1]='s';
			k=2;
			WN_SQL3_snprintf(100,&zBuf[k],"%d",pMem->n);
			k+=strlen(&zBuf[k]);
			zBuf[k++]='[';
			for(j=0;j<15 && j<pMem->n;j++)
			{
				u8 c=pMem->z[j];
				if(c>=0x20 && c<0x7f)
					zBuf[k++]=c;
				else
					zBuf[k++]='.';
			}
			zBuf[k++]=']';
			WN_SQL3_snprintf(100,&zBuf[k],encnames[pMem->enc]);
			k+=strlen(&zBuf[k]);
			zBuf[k++]=0;
		}
}
#endif
#ifdef VDBE_PROFILE
__inline__ unsigned long long int hwtime(void)
{
	unsigned long long int x;
	__asm__("rdtsc\n\t"
"mov %%edx,%%ecx\n\t"
:"=A"(x));
return x;
}
#endif
int WN_SQL3VdbeExec(Vdbe *p)
{
	int pc,rc=0;
	Op *pOp;
	WN_SQL3 *db=p->db;
	u8 encoding=ENC(db);
	Mem *pTos;
#ifdef VDBE_PROFILE
	unsigned long long start;
	int origPc;
#endif
#ifndef WN_SQL_OMIT_PROGRESS_CALLBACK
	int nProgressOps=0;
#endif
#ifndef NDEBUG
	Mem *pStackLimit;
#endif
	if(p->magic!=VDBE_MAGIC_RUN)return WN_SQL_MISUSE;
	pTos=p->pTos;
	if(p->rc==WN_SQL_NOMEM)goto no_mem;
	p->rc=0;
	if(p->popStack)
	{
		popStack(&pTos,p->popStack);
		p->popStack=0;
	}
	p->resOnStack=0;
	db->busyHandler.nBusy=0;
	if(db->u1.isInterrupted)goto abort_due_to_interrupt;;
	WN_SQL3VdbeIOTraceSql(p);
#ifdef WN_SQL_DEBUG
	if((p->db->flags & WN_SQL_VdbeListing)|| WN_SQL3OsFileExists("vdbe_explain"))
	{
		int i;
		printf("VDBE Program Listing:\n");
		WN_SQL3VdbePrintSql(p);
		for(i=0;i<p->nOp;i++)WN_SQL3VdbePrintOp(stdout,i,&p->aOp[i]);
	}
	if(WN_SQL3OsFileExists("vdbe_trace"))p->trace=stdout;
#endif
	for(pc=p->pc;rc==0;pc++)
	{
		if(WN_SQL3MallocFailed())goto no_mem;
#ifdef VDBE_PROFILE
		origPc=pc;
		start=hwtime();
#endif
		pOp=&p->aOp[pc];
#ifdef WN_SQL_DEBUG
		if(p->trace)
		{
			if(pc==0)
			{
				printf("VDBE Execution Trace:\n");
				WN_SQL3VdbePrintSql(p);
			}
			WN_SQL3VdbePrintOp(p->trace,pc,pOp);
		}
		if(p->trace==0 && pc==0 && WN_SQL3OsFileExists("vdbe_sqltrace"))
			WN_SQL3VdbePrintSql(p);
#endif
#ifdef WN_SQL_TEST
		if(WN_SQL3_interrupt_count>0)
		{
			WN_SQL3_interrupt_count--;
			if(WN_SQL3_interrupt_count==0)WN_SQL3_interrupt(db);
		}
#endif
#ifndef WN_SQL_OMIT_PROGRESS_CALLBACK
		if(db->xProgress)
		{
			if(db->nProgressOps==nProgressOps)
			{
				int prc;
				if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
				prc=db->xProgress(db->pProgressArg);
				if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
				if(prc)
				{
					rc=WN_SQL_INTERRUPT;
					goto vdbe_halt;
				}
				nProgressOps=0;
			}
			nProgressOps++;
		}
#endif
#ifndef NDEBUG
		pStackLimit=pTos;
		if(!WN_SQL3VdbeOpcodeNoPush(pOp->opcode))pStackLimit++;
#endif
		switch(pOp->opcode)
		{
		case OP_Goto:
			if(db->u1.isInterrupted)goto abort_due_to_interrupt;;
			pc=pOp->p2-1;
			break;
		case OP_Gosub:
			p->returnStack[p->returnDepth++]=pc+1;
			pc=pOp->p2-1;
			break;
		case OP_Return:
			p->returnDepth--;
			pc=p->returnStack[p->returnDepth]-1;
			break;
		case OP_Halt:
			p->pTos=pTos;
			p->rc=pOp->p1;
			p->pc=pc;
			p->errorAction=pOp->p2;
			if(pOp->p3)	WN_SQL3SetString(&p->zErrMsg,pOp->p3,(char*)0);
			rc=WN_SQL3VdbeHalt(p);
			if(rc==WN_SQL_BUSY)
			{
				p->rc=WN_SQL_BUSY;
				return WN_SQL_BUSY;
			}
			return p->rc ? WN_SQL_ERROR :WN_SQL_DONE;
		case OP_Integer:
			pTos++;
			pTos->flags=MEM_Int;
			pTos->u.i=pOp->p1;
			break;
		case OP_Int64:
			pTos++;
			pTos->flags=MEM_Str|MEM_Static|MEM_Term;
			pTos->z=pOp->p3;
			pTos->n=strlen(pTos->z);
			pTos->enc=WN_SQL_UTF8;
			pTos->u.i=WN_SQL3VdbeIntValue(pTos);
			pTos->flags |=MEM_Int;
			break;
		case OP_Real:
			pTos++;
			pTos->flags=MEM_Str|MEM_Static|MEM_Term;
			pTos->z=pOp->p3;
			pTos->n=strlen(pTos->z);
			pTos->enc=WN_SQL_UTF8;
			pTos->r=WN_SQL3VdbeRealValue(pTos);
			pTos->flags |=MEM_Real;
			WN_SQL3VdbeChangeEncoding(pTos,encoding);
			break;
		case OP_String8:
			pOp->opcode=OP_String;
			pOp->p1=strlen(pOp->p3);
#ifndef WN_SQL_OMIT_UTF16
			if(encoding!=WN_SQL_UTF8)
			{
				pTos++;
				WN_SQL3VdbeMemSetStr(pTos,pOp->p3,-1,WN_SQL_UTF8,WN_SQL_STATIC);
				if(WN_SQL3VdbeChangeEncoding(pTos,encoding))goto no_mem;
				if(WN_SQL3VdbeMemDynamicify(pTos))goto no_mem;
				pTos->flags &=~(MEM_Dyn);
				pTos->flags |=MEM_Static;
				if(pOp->p3type==P3_DYNAMIC)WN_SQL3FreeX(pOp->p3);
				pOp->p3type=P3_DYNAMIC;
				pOp->p3=pTos->z;
				pOp->p1=pTos->n;
				break;
			}
#endif
		case OP_String:
			pTos++;
			pTos->flags=MEM_Str|MEM_Static|MEM_Term;
			pTos->z=pOp->p3;
			pTos->n=pOp->p1;
			pTos->enc=encoding;
			break;
		case OP_Null:
			pTos++;
			pTos->flags=MEM_Null;
			pTos->n=0;
			break;
#ifndef WN_SQL_OMIT_BLOB_LITERAL
		case OP_HexBlob:
			pOp->opcode=OP_Blob;
			pOp->p1=strlen(pOp->p3)/2;
			if(pOp->p1)
			{
				char *zBlob=WN_SQL3HexToBlob(pOp->p3);
				if(!zBlob)goto no_mem;
				if(pOp->p3type==P3_DYNAMIC)WN_SQL3FreeX(pOp->p3);
				pOp->p3=zBlob;
				pOp->p3type=P3_DYNAMIC;
			}
			else
			{
				if(pOp->p3type==P3_DYNAMIC)WN_SQL3FreeX(pOp->p3);
				pOp->p3type=P3_STATIC;
				pOp->p3="";
			}
		case OP_Blob:
			pTos++;
			WN_SQL3VdbeMemSetStr(pTos,pOp->p3,pOp->p1,0,0);
			pTos->enc=encoding;
			break;
#endif
		case OP_Variable:
			int j=pOp->p1-1;
			Mem *pVar;
			pVar=&p->aVar[j];
			if(WN_SQL3VdbeMemTooBig(pVar))goto too_big;
			pTos++;
			WN_SQL3VdbeMemShallowCopy(pTos,&p->aVar[j],MEM_Static);
			break;
		case OP_Pop:
			popStack(&pTos,pOp->p1);
			break;
		case OP_Dup:
			Mem *pFrom=&pTos[-pOp->p1];
			pTos++;
			WN_SQL3VdbeMemShallowCopy(pTos,pFrom,MEM_Ephem);
			if(pOp->p2)Deephemeralize(pTos);
			break;
		case OP_Pull:
			Mem *pFrom=&pTos[-pOp->p1];
			int i;
			Mem ts;
			ts=*pFrom;
			Deephemeralize(pTos);
			for(i=0;i<pOp->p1;i++,pFrom++)
			{
				Deephemeralize(&pFrom[1]);
				*pFrom=pFrom[1];
				if(pFrom->flags & MEM_Short)pFrom->z=pFrom->zShort;
			}
			*pTos=ts;
			if(pTos->flags & MEM_Short)pTos->z=pTos->zShort;
			break;
		case OP_Push:
			Mem *pTo=&pTos[-pOp->p1];
			WN_SQL3VdbeMemMove(pTo,pTos);
			pTos--;
			break;
		case OP_Callback:
			Mem *pMem;
			Mem *pFirstColumn;
			pFirstColumn=&pTos[0-pOp->p1];
			for(pMem=p->aStack;pMem<pFirstColumn;pMem++)Deephemeralize(pMem);
			p->cacheCtr=(p->cacheCtr+2)|1;
			for(;pMem<=pTos;pMem++)
			{
				WN_SQL3VdbeMemNulTerminate(pMem);
				storeTypeInfo(pMem,encoding);
			}
			p->resOnStack=1;
			p->nCallback++;
			p->popStack=pOp->p1;
			p->pc=pc+1;
			p->pTos=pTos;
			return WN_SQL_ROW;
		case OP_Concat:
			char *zNew;
			i64 nByte=0;
			int nField,i,j;
			Mem *pTerm;
			nField=pOp->p1+2;
			pTerm=&pTos[1-nField];
			for(i=0;i<nField;i++,pTerm++)
			{
				if(pTerm->flags&MEM_Null)
				{
					nByte=-1;
					break;
				}
				ExpandBlob(pTerm);
				Stringify(pTerm,encoding);
				nByte+=pTerm->n;
			}
			if(nByte<0)
			{
				if(pOp->p2==0)popStack(&pTos,nField);
				pTos++;
				pTos->flags=MEM_Null;
			}
			else
			{
				if(nByte+2>WN_SQL_MAX_LENGTH)goto too_big;
				zNew=WN_SQLMallocRaw(nByte+2);
				if(zNew==0)goto no_mem;
				j=0;
				pTerm=&pTos[1-nField];
				for(i=j=0;i<nField;i++,pTerm++)
				{
					int n=pTerm->n;
					memcpy(&zNew[j],pTerm->z,n);
					j+=n;
				}
				zNew[j]=0;
				zNew[j+1]=0;
				if(pOp->p2==0)popStack(&pTos,nField);
				pTos++;
				pTos->n=j;
				pTos->flags=MEM_Str|MEM_Dyn|MEM_Term;
				pTos->xDel=0;
				pTos->enc=encoding;
				pTos->z=zNew;
			}
			break;
		case OP_Add:
		case OP_Subtract:
		case OP_Multiply:
		case OP_Divide:
		case OP_Remainder:
			{
			Mem *pNos=&pTos[-1];
			int flags;
			flags=pTos->flags | pNos->flags;
			if(flags & MEM_Null)
			{
				Release(pTos);
				pTos--;
				Release(pTos);
				pTos->flags=MEM_Null;
			}
			else
				if((pTos->flags & pNos->flags & MEM_Int)==MEM_Int)
				{
					i64 a,b;
					a=pTos->u.i;
					b=pNos->u.i;
					switch(pOp->opcode)
					{
					case OP_Add:
						b+=a;
						break;
					case OP_Subtract:
						b-=a;
						break;
					case OP_Multiply:
						b*=a;
						break;
					case OP_Divide:
						if(a==0)goto divide_by_zero;
						if(a==-1 && b==(((i64)1)<<63))a=1;
						b /=a;
						break;
					default:
						if(a==0)goto divide_by_zero;
						if(a==-1)a=1;
						b%=a;
					}
					Release(pTos);
					pTos--;
					Release(pTos);
					pTos->u.i=b;
					pTos->flags=MEM_Int;
				}
				else
				{
					double a,b;
					a=WN_SQL3VdbeRealValue(pTos);
					b=WN_SQL3VdbeRealValue(pNos);
					switch(pOp->opcode)
					{
					case OP_Add:
						b+=a;
						break;
					case OP_Subtract:
						b-=a;
						break;
					case OP_Multiply:
						b*=a;
						break;
					case OP_Divide:
						if(a==0.0)goto divide_by_zero;
						b/=a;
						break;
					default:
						i64 ia=(i64)a,ib=(i64)b;
						if(ia==0)goto divide_by_zero;
						if(ia==-1)ia=1;
						b=ib % ia;
						break;
					}
					if(WN_SQL3_isnan(b))goto divide_by_zero;
					Release(pTos);
					pTos--;
					Release(pTos);
					pTos->r=b;
					pTos->flags=MEM_Real;
					if((flags & MEM_Real)==0)WN_SQL3VdbeIntegerAffinity(pTos);
				}
				break;
divide_by_zero:
				Release(pTos);
				pTos--;
				Release(pTos);
				pTos->flags=MEM_Null;
				break;
			}
		case OP_CollSeq:
			break;
		case OP_Function:
			int i;
			Mem *pArg;
			WN_SQL3_context ctx;
			WN_SQL3_value **apVal;
			int n=pOp->p2;
			apVal=p->apArg;
			pArg=&pTos[1-n];
			for(i=0;i<n;i++,pArg++)
			{
				apVal[i]=pArg;
				storeTypeInfo(pArg,encoding);
			}
			if(pOp->p3type==P3_FUNCDEF)
			{
				ctx.pFunc=(FuncDef*)pOp->p3;
				ctx.pVdbeFunc=0;
			}
			else
			{
				ctx.pVdbeFunc=(VdbeFunc*)pOp->p3;
				ctx.pFunc=ctx.pVdbeFunc->pFunc;
			}
			ctx.s.flags=MEM_Null;
			ctx.s.z=0;
			ctx.s.xDel=0;
			ctx.isError=0;
			if(ctx.pFunc->needCollSeq)ctx.pColl=(CollSeq *)pOp[-1].p3;
			if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
			(*ctx.pFunc->xFunc)(&ctx,n,apVal);
			if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
			if(WN_SQL3MallocFailed())goto no_mem;
			popStack(&pTos,n);
			if(ctx.pVdbeFunc)
			{
				WN_SQL3VdbeDeleteAuxData(ctx.pVdbeFunc,pOp->p1);
				pOp->p3=(char *)ctx.pVdbeFunc;
				pOp->p3type=P3_VDBEFUNC;
			}
			if(ctx.isError)
			{
				WN_SQL3SetString(&p->zErrMsg,WN_SQL3_value_text(&ctx.s),(char*)0);
				rc=WN_SQL_ERROR;
			}
			WN_SQL3VdbeChangeEncoding(&ctx.s,encoding);
			pTos++;
			pTos->flags=0;
			WN_SQL3VdbeMemMove(pTos,&ctx.s);
			if(WN_SQL3VdbeMemTooBig(pTos))goto too_big;
			break;
		case OP_BitAnd:
		case OP_BitOr:
		case OP_ShiftLeft:
		case OP_ShiftRight:
			Mem *pNos=&pTos[-1];
			if((pTos->flags | pNos->flags)& MEM_Null)
			{
				popStack(&pTos,2);
				pTos++;
				pTos->flags=MEM_Null;
				break;
			}
			i64 a=WN_SQL3VdbeIntValue(pNos),b=WN_SQL3VdbeIntValue(pTos);
			switch(pOp->opcode)
			{
			case OP_BitAnd:
				a&=b;
				break;
			case OP_BitOr:
				a|=b;
				break;
			case OP_ShiftLeft:
				a<<=b;
				break;
			case OP_ShiftRight:
				a>>=b;
				break;
			}
			Release(pTos);
			pTos--;
			Release(pTos);
			pTos->u.i=a;
			pTos->flags=MEM_Int;
			break;
		case OP_AddImm:
			WN_SQL3VdbeMemIntegerify(pTos);
			pTos->u.i+=pOp->p1;
			break;
		case OP_ForceInt:
			i64 v;
			applyAffinity(pTos,WN_SQL_AFF_NUMERIC,encoding);
			if((pTos->flags &(MEM_Int|MEM_Real))==0)
			{
				Release(pTos);
				pTos--;
				pc=pOp->p2-1;
				break;
			}
			if(pTos->flags & MEM_Int)
				v=pTos->u.i+(pOp->p1!=0);
			else
			{
				WN_SQL3VdbeMemRealify(pTos);
				v=(int)pTos->r;
				if(pTos->r>(double)v)v++;
				if(pOp->p1 && pTos->r==(double)v)v++;
			}
			Release(pTos);
			pTos->u.i=v;
			pTos->flags=MEM_Int;
			break;
		case OP_MustBeInt:
			applyAffinity(pTos,WN_SQL_AFF_NUMERIC,encoding);
			if((pTos->flags & MEM_Int)==0)
			{
				if(pOp->p2==0)
				{
					rc=WN_SQL_MISMATCH;
					goto abort_due_to_error;
				}
				else
				{
					if(pOp->p1)popStack(&pTos,1);
					pc=pOp->p2-1;
				}
			}
			else
			{
				Release(pTos);
				pTos->flags=MEM_Int;
			}
			break;
		case OP_RealAffinity:
			if(pTos->flags & MEM_Int)WN_SQL3VdbeMemRealify(pTos);
			break;
#ifndef WN_SQL_OMIT_CAST
		case OP_ToText:
			if(pTos->flags & MEM_Null)break;
			pTos->flags |=(pTos->flags&MEM_Blob)>>3;
			applyAffinity(pTos,WN_SQL_AFF_TEXT,encoding);
			rc=ExpandBlob(pTos);
			pTos->flags &=~(MEM_Int|MEM_Real|MEM_Blob);
			break;
		case OP_ToBlob:
			if(pTos->flags & MEM_Null)break;
			if((pTos->flags & MEM_Blob)==0)
			{
				applyAffinity(pTos,WN_SQL_AFF_TEXT,encoding);
				pTos->flags |=MEM_Blob;
			}
			pTos->flags &=~(MEM_Int|MEM_Real|MEM_Str);
			break;
		case OP_ToNumeric:
			if((pTos->flags &(MEM_Null|MEM_Int|MEM_Real))==0)WN_SQL3VdbeMemNumerify(pTos);
			break;
#endif
		case OP_ToInt:
			if((pTos->flags & MEM_Null)==0)WN_SQL3VdbeMemIntegerify(pTos);
			break;
#ifndef WN_SQL_OMIT_CAST
		case OP_ToReal:
			if((pTos->flags & MEM_Null)==0)WN_SQL3VdbeMemRealify(pTos);
			break;
#endif
		case OP_Eq:
		case OP_Ne:
		case OP_Lt:
		case OP_Le:
		case OP_Gt:
		case OP_Ge:
			Mem *pNos;
			int flags,res;
			char affinity;
			pNos=&pTos[-1];
			flags=pTos->flags|pNos->flags;
			if(flags&MEM_Null)
			{
				if((pOp->p1 & 0x200))
				{
					WN_SQL3VdbeMemSetInt64(pTos,(pTos->flags & MEM_Null)==0);
					WN_SQL3VdbeMemSetInt64(pNos,(pNos->flags & MEM_Null)==0);
				}
				else
				{
					popStack(&pTos,2);
					if(pOp->p2)
						if(pOp->p1 & 0x100)
						{
							pc=pOp->p2-1;
						}
					else
					{
						pTos++;
						pTos->flags=MEM_Null;
					}
					break;
				}
			}
			affinity=pOp->p1 & 0xFF;
			if(affinity)
			{
				applyAffinity(pNos,affinity,encoding);
				applyAffinity(pTos,affinity,encoding);
			}
			ExpandBlob(pNos);
			ExpandBlob(pTos);
			res=WN_SQL3MemCompare(pNos,pTos,(CollSeq*)pOp->p3);
			switch(pOp->opcode)
			{
			case OP_Eq:
				res=res==0;
				break;
			case OP_Ne:
				res=res!=0;
				break;
			case OP_Lt:
				res=res<0;
				break;
			case OP_Le:
				res=res<=0;
				break;
			case OP_Gt:
				res=res>0;
				break;
			default:
				res=res>=0;
			}
			popStack(&pTos,2);
			if(pOp->p2)
			{
				if(res)pc=pOp->p2-1;
			}
			else
			{
				pTos++;
				pTos->flags=MEM_Int;
				pTos->u.i=res;
			}
			break;
		case OP_And:
		case OP_Or:
			Mem *pNos=&pTos[-1];
			int v1,v2;
			if(pTos->flags & MEM_Null)
				v1=2;
			else
			{
				WN_SQL3VdbeMemIntegerify(pTos);
				v1=pTos->u.i==0;
			}
			if(pNos->flags & MEM_Null)
				v2=2;
			else
			{
				WN_SQL3VdbeMemIntegerify(pNos);
				v2=pNos->u.i==0;
			}
			if(pOp->opcode==OP_And)
			{
				const unsigned char and_logic[]={0,1,2,1,1,1,2,1,2};
				v1=and_logic[v1*3+v2];
			}
			else
			{
				const unsigned char or_logic[]={0,0,0,0,1,2,0,2,2};
				v1=or_logic[v1*3+v2];
			}
			popStack(&pTos,2);
			pTos++;
			if(v1==2)
				pTos->flags=MEM_Null;
			else
			{
				pTos->u.i=v1==0;
				pTos->flags=MEM_Int;
			}
			break;
		case OP_Negative:
		case OP_AbsValue:
			if((pTos->flags &(MEM_Real|MEM_Int|MEM_Null))==0)WN_SQL3VdbeMemNumerify(pTos);
			if(pTos->flags & MEM_Real)
			{
				Release(pTos);
				if(pOp->opcode==OP_Negative || pTos->r<0.0)pTos->r=-pTos->r;
				pTos->flags=MEM_Real;
			}
			else
				if(pTos->flags & MEM_Int)
				{
					Release(pTos);
					if(pOp->opcode==OP_Negative || pTos->u.i<0)pTos->u.i=-pTos->u.i;
					pTos->flags=MEM_Int;
				}
				break;
		case OP_Not:
			if(pTos->flags & MEM_Null)break;
			WN_SQL3VdbeMemIntegerify(pTos);
			pTos->u.i=!pTos->u.i;
			pTos->flags=MEM_Int;
			break;
		case OP_BitNot:
			if(pTos->flags & MEM_Null)break;
			WN_SQL3VdbeMemIntegerify(pTos);
			pTos->u.i=~pTos->u.i;
			pTos->flags=MEM_Int;
			break;
		case OP_Explain:
		case OP_Noop:
			break;
		case OP_If:
		case OP_IfNot:
			int c;
			if(pTos->flags & MEM_Null)
				c=pOp->p1;
			else
			{
#ifdef WN_SQL_OMIT_FLOATING_POINT
				c=WN_SQL3VdbeIntValue(pTos);
#else
				c=WN_SQL3VdbeRealValue(pTos)!=0.0;
#endif
				if(pOp->opcode==OP_IfNot)c=!c;
			}
			Release(pTos);
			pTos--;
			if(c)pc=pOp->p2-1;
			break;
		case OP_IsNull:
			if(pTos->flags & MEM_Null)
			{
				pc=pOp->p2-1;
				if(pOp->p1<0)popStack(&pTos,-pOp->p1);
			}
			if(pOp->p1>0)popStack(&pTos,pOp->p1);
			break;
		case OP_NotNull:
			int i,cnt=pOp->p1;
			if(cnt<0)cnt=-cnt;
			for(i=0;i<cnt &&(pTos[1+i-cnt].flags & MEM_Null)==0;i++);
			if(i>=cnt)pc=pOp->p2-1;
			if(pOp->p1>0)popStack(&pTos,cnt);
			break;
		case OP_SetNumColumns:
			Cursor *pC;
			pC=p->apCsr[pOp->p1];
			pC->nField=pOp->p2;
			break;
		case OP_Column:{
			int p1=pOp->p1,p2=pOp->p2,len,i;
			char *zRec,*zData;
			BtCursor *pCrsr;
			u32 payloadSize,*aType,*aOffset,nField;
			Mem sMem;
			sMem.flags=0;
			pTos++;
			pTos->flags=MEM_Null;
			Cursor *pC=p->apCsr[p1];
			if(pC->pCursor)
			{
				if(rc=WN_SQL3VdbeCursorMoveto(pC))goto abort_due_to_error;
				zRec=0;
				pCrsr=pC->pCursor;
				if(pC->nullRow)
					payloadSize=0;
				else
					if(pC->cacheStatus==p->cacheCtr)
					{
						payloadSize=pC->payloadSize;
						zRec=(char*)pC->aRow;
					}
					else
						if(pC->isIndex)
						{
							i64 payloadSize64;
							WN_SQL3BtreeKeySize(pCrsr,&payloadSize64);
							payloadSize=payloadSize64;
						}
						else
							WN_SQL3BtreeDataSize(pCrsr,&payloadSize);
				nField=pC->nField;
			}
			else
				if(pC->pseudoTable)
				{
					payloadSize=pC->nData;
					zRec=pC->pData;
					pC->cacheStatus=CACHE_STALE;
					nField=pC->nField;
					pCrsr=0;
				}
				else
				{
					zRec=0;
					payloadSize=0;
					pCrsr=0;
					nField=0;
				}
				if(payloadSize==0)break;
				if(payloadSize>WN_SQL_MAX_LENGTH)goto too_big;
				if(pC && pC->cacheStatus==p->cacheCtr)
				{
					aType=pC->aType;
					aOffset=pC->aOffset;
				}
				else
				{
					u8 *zIdx,*zEndHdr;
					u32 offset;
					int szHdrSz,avail;
					aType=pC->aType;
					if(aType==0)pC->aType=aType=WN_SQLMallocRaw(2*nField*sizeof(aType));
					if(aType==0)goto no_mem;
					pC->aOffset=aOffset=&aType[nField];
					pC->payloadSize=payloadSize;
					pC->cacheStatus=p->cacheCtr;
					if(zRec)
						zData=zRec;
					else
					{
						if(pC->isIndex)
							zData=(char*)WN_SQL3BtreeKeyFetch(pCrsr,&avail);
						else
							zData=(char*)WN_SQL3BtreeDataFetch(pCrsr,&avail);
						if(avail>=payloadSize)
						{
							zRec=zData;
							pC->aRow=(u8*)zData;
						}
						else
							pC->aRow=0;
					}
					szHdrSz=GetVarint((u8*)zData,offset);
					if(!zRec && avail<offset)
					{
						rc=WN_SQL3VdbeMemFromBtree(pCrsr,0,offset,pC->isIndex,&sMem);
						if(rc)goto op_column_out;
						zData=sMem.z;
					}
					zEndHdr=(u8 *)&zData[offset];
					zIdx=(u8 *)&zData[szHdrSz];
					for(i=0;i<nField;i++)
						if(zIdx<zEndHdr)
						{
							aOffset[i]=offset;
							zIdx+=GetVarint(zIdx,aType[i]);
							offset+=WN_SQL3VdbeSerialTypeLen(aType[i]);
						}
						else
							aOffset[i]=0;
					Release(&sMem);
					sMem.flags=MEM_Null;
					if(zIdx>zEndHdr || offset>payloadSize)
					{
						rc=WN_SQL_CORRUPT_BKPT;
						goto op_column_out;
					}
				}
				if(aOffset[p2])
				{
					if(zRec)
						zData=&zRec[aOffset[p2]];
					else
					{
						len=WN_SQL3VdbeSerialTypeLen(aType[p2]);
						if(rc=WN_SQL3VdbeMemFromBtree(pCrsr,aOffset[p2],len,pC->isIndex,&sMem))goto op_column_out;
						zData=sMem.z;
					}
					WN_SQL3VdbeSerialGet((u8*)zData,aType[p2],pTos);
					pTos->enc=encoding;
				}
				else
					if(pOp->p3type==P3_MEM)
						WN_SQL3VdbeMemShallowCopy(pTos,(Mem *)(pOp->p3),MEM_Static);
					else
						pTos->flags=MEM_Null;
				if((sMem.flags & MEM_Dyn))
				{
					pTos->flags &=~MEM_Ephem;
					pTos->flags |=MEM_Dyn|MEM_Term;
				}
				rc=WN_SQL3VdbeMemMakeWriteable(pTos);
op_column_out:
				break;
	case OP_MakeIdxRec:
	case OP_MakeRecord:
		u8 *zNewRecord;
		Mem *pRec,*pRowid=0,*pData0=&pTos[1-nField];
		u64 nData=0,nByte=0;
		int nHdr=0,nZero=0,nVarint,containsNull=0,leaveOnStack=((pOp->p1<0)?1:0),nField=pOp->p1 *(leaveOnStack?-1:1),jumpIfNull=pOp->p2,addRowid=pOp->opcode==OP_MakeIdxRec,file_format=p->minWriteFileFormat,i;
		u32 serial_type;
		char *zAffinity=pOp->p3,zTemp[NBFS];
		for(pRec=pData0;pRec<=pTos;pRec++)
		{
			if(zAffinity)applyAffinity(pRec,zAffinity[pRec-pData0],encoding);
			if(pRec->flags&MEM_Null)containsNull=1;
			if(pRec->flags&MEM_Zero && pRec->n>0)ExpandBlob(pRec);
			serial_type=WN_SQL3VdbeSerialType(pRec,file_format);
			int len=WN_SQL3VdbeSerialTypeLen(serial_type);
			nData+=len;
			nHdr+=WN_SQL3VarintLen(serial_type);
			if(pRec->flags & MEM_Zero)
				nZero+=pRec->u.i;
			else
				if(len)nZero=0;
		}
		if(addRowid)
		{
			pRowid=&pTos[0-nField];
			WN_SQL3VdbeMemIntegerify(pRowid);
			serial_type=WN_SQL3VdbeSerialType(pRowid,0);
			nData+=WN_SQL3VdbeSerialTypeLen(serial_type);
			nHdr+=WN_SQL3VarintLen(serial_type);
			nZero=0;
		}
		nHdr+=nVarint=WN_SQL3VarintLen(nHdr);
		if(nVarint<WN_SQL3VarintLen(nHdr))nHdr++;
		nByte=nHdr+nData-nZero;
		if(nByte>WN_SQL_MAX_LENGTH)goto too_big;
		if(nByte>sizeof(zTemp))
			if(!(zNewRecord=WN_SQLMallocRaw(nByte)))goto no_mem;
		else
			zNewRecord=(u8*)zTemp;
		i=WN_SQL3PutVarint(zNewRecord,nHdr);
		for(pRec=pData0;pRec<=pTos;pRec++)
		{
			serial_type=WN_SQL3VdbeSerialType(pRec,file_format);
			i+=WN_SQL3PutVarint(&zNewRecord[i],serial_type);
		}
		if(addRowid)i+=WN_SQL3PutVarint(&zNewRecord[i],WN_SQL3VdbeSerialType(pRowid,0));
		for(pRec=pData0;pRec<=pTos;pRec++)i+=WN_SQL3VdbeSerialPut(&zNewRecord[i],nByte-i,pRec,file_format);
		if(addRowid)i+=WN_SQL3VdbeSerialPut(&zNewRecord[i],nByte-i,pRowid,0);
		if(!leaveOnStack)popStack(&pTos,nField+addRowid);
		pTos++;
		pTos->n=nByte;
		if(nByte<=sizeof(zTemp))
		{
			pTos->z=pTos->zShort;
			memcpy(pTos->zShort,zTemp,nByte);
			pTos->flags=MEM_Blob | MEM_Short;
		}
		else
		{
			pTos->z=(char*)zNewRecord;
			pTos->flags=MEM_Blob | MEM_Dyn;
			pTos->xDel=0;
		}
		if(nZero)
		{
			pTos->u.i=nZero;
			pTos->flags |=MEM_Zero;
		}
		pTos->enc=WN_SQL_UTF8;
		if(jumpIfNull && containsNull)pc=jumpIfNull-1;
		break;
	case OP_Statement:
		int i=pOp->p1;
		Btree *pBt;
		if(i>=0 && i<db->nDb &&(pBt=db->aDb[i].pBt)&& !(db->autoCommit))
		{
			if(!WN_SQL3BtreeIsInStmt(pBt))
			{
				rc=WN_SQL3BtreeBeginStmt(pBt);
				p->openedStatement=1;
			}
		}
		break;
	case OP_AutoCommit:
		u8 i=pOp->p1,rollback=pOp->p2;
		if(db->activeVdbeCnt>1 && i && !db->autoCommit)
		{
			WN_SQL3SetString(&p->zErrMsg,"cannot ",rollback?"rollback":"commit"," transaction-SQL statements in progress",(char*)0);
			rc=WN_SQL_ERROR;
		}
		else
			if(i!=db->autoCommit)
			{
				if(pOp->p2)
				{
					WN_SQL3RollbackAll(db);
					db->autoCommit=1;
				}
				else
				{
					db->autoCommit=i;
					if(WN_SQL3VdbeHalt(p)==WN_SQL_BUSY)
					{
						p->pTos=pTos;
						p->pc=pc;
						db->autoCommit=1-i;
						p->rc=WN_SQL_BUSY;
						return WN_SQL_BUSY;
					}
				}
				if(p->rc==0)
					return WN_SQL_DONE;
				else
					return WN_SQL_ERROR;
			}
			else
			{
				WN_SQL3SetString(&p->zErrMsg,(!i)?"cannot start a transaction within a transaction":(
(rollback)?"cannot rollback-no transaction is active":
"cannot commit-no transaction is active"),(char*)0);
				rc=WN_SQL_ERROR;
			}
			break;
	case OP_Transaction:
		int i=pOp->p1;
		Btree *pBt=db->aDb[i].pBt;
		if(pBt)
		{
			if((rc=WN_SQL3BtreeBeginTrans(pBt,pOp->p2))==WN_SQL_BUSY)
			{
				p->pc=pc;
				p->rc=WN_SQL_BUSY;
				p->pTos=pTos;
				return WN_SQL_BUSY;
			}
			if(rc && rc!=WN_SQL_READONLY)goto abort_due_to_error;
		}
		break;
	case OP_ReadCookie:
		int iMeta,iDb=pOp->p1,iCookie=pOp->p2;
		if(iDb<0)
		{
			iDb=(-1*(iDb+1));
			iCookie *=-1;
		}
		rc=WN_SQL3BtreeGetMeta(db->aDb[iDb].pBt,1+iCookie,(u32 *)&iMeta);
		pTos++;
		pTos->u.i=iMeta;
		pTos->flags=MEM_Int;
		break;
	case OP_SetCookie:
		Db *pDb=&db->aDb[pOp->p1];
		WN_SQL3VdbeMemIntegerify(pTos);
		rc=WN_SQL3BtreeUpdateMeta(pDb->pBt,1+pOp->p2,(int)pTos->u.i);
		if(pOp->p2==0)
		{
			pDb->pSchema->schema_cookie=pTos->u.i;
			db->flags|=WN_SQL_InternChanges;
		}
		else
			if(pOp->p2==1)pDb->pSchema->file_format=pTos->u.i;
		pTos--;
		if(pOp->p1==1)WN_SQL3ExpirePreparedStatements(db);
		break;
	case OP_VerifyCookie:
		int iMeta;
		Btree *pBt=db->aDb[pOp->p1].pBt;
		if(pBt)
			rc=WN_SQL3BtreeGetMeta(pBt,1,(u32 *)&iMeta);
		else
		{
			rc=0;
			iMeta=0;
		}
		if(rc==0 && iMeta!=pOp->p2)
		{
			WN_SQL3SetString(&p->zErrMsg,"database schema has changed",(char*)0);
			if(db->aDb[pOp->p1].pSchema->schema_cookie!=iMeta)WN_SQL3ResetInternalSchema(db,pOp->p1);
			WN_SQL3ExpirePreparedStatements(db);
			rc=WN_SQL_SCHEMA;
		}
		break;
	case OP_OpenRead:
	case OP_OpenWrite:
		WN_SQL3VdbeMemIntegerify(pTos);
		int i=pOp->p1,p2=pOp->p2,wrFlag,iDb=pTos->u.i;
		pTos--;
		Db *pDb=&db->aDb[iDb];
		Btree *pX=pDb->pBt;
		if(pOp->opcode==OP_OpenWrite)
		{
			wrFlag=1;
			if(pDb->pSchema->file_format<p->minWriteFileFormat)p->minWriteFileFormat=pDb->pSchema->file_format;
		}
		else
			wrFlag=0;
		if(p2<=0)
		{
			WN_SQL3VdbeMemIntegerify(pTos);
			p2=pTos->u.i;
			pTos--;
		}
		Cursor *pCur=allocateCursor(p,i,iDb);
		if(pCur==0)goto no_mem;
		pCur->nullRow=1;
		if(pX==0)break;
		rc=WN_SQL3BtreeCursor(pX,p2,wrFlag,WN_SQL3VdbeRecordCompare,pOp->p3,&pCur->pCursor);
		if(pOp->p3type==P3_KEYINFO)
		{
			pCur->pKeyInfo=(KeyInfo*)pOp->p3;
			pCur->pIncrKey=&pCur->pKeyInfo->incrKey;
			pCur->pKeyInfo->enc=ENC(p->db);
		}
		else
		{
			pCur->pKeyInfo=0;
			pCur->pIncrKey=&pCur->bogusIncrKey;
		}
		switch(rc)
		{
		case WN_SQL_BUSY:
			p->pc=pc;
			p->rc=WN_SQL_BUSY;
			p->pTos=&pTos[1+(pOp->p2<=0)];
			return WN_SQL_BUSY;
		case 0:
			int flags=WN_SQL3BtreeFlags(pCur->pCursor);
			if((flags & 0xf0)||((flags & 0x07)!=5 &&(flags & 0x07)!=2))
			{
				rc=WN_SQL_CORRUPT_BKPT;
				goto abort_due_to_error;
			}
			pCur->isTable=(flags & BTREE_INTKEY)!=0;
			pCur->isIndex=(flags & BTREE_ZERODATA)!=0;
			if((pCur->isTable && pOp->p3type==P3_KEYINFO)||(pCur->isIndex && pOp->p3type!=P3_KEYINFO))
			{
				rc=WN_SQL_CORRUPT_BKPT;
				goto abort_due_to_error;
			}
			break;
		case WN_SQL_EMPTY:
			pCur->isTable=pOp->p3type!=P3_KEYINFO;
			pCur->isIndex=!pCur->isTable;
			rc=0;
			break;
		default:
			goto abort_due_to_error;
		}
		break;
	case OP_OpenEphemeral:
		int i=pOp->p1;
		Cursor *pCx=allocateCursor(p,i,-1);
		if(pCx==0)goto no_mem;
		pCx->nullRow=1;
		if((rc=WN_SQL3BtreeFactory(db,0,1,WN_SQL_DEFAULT_TEMP_CACHE_SIZE,&pCx->pBt))==0)rc=WN_SQL3BtreeBeginTrans(pCx->pBt,1);
		if(rc==0 && pOp->p3)
		{
			int pgno;
			if((rc=WN_SQL3BtreeCreateTable(pCx->pBt,&pgno,BTREE_ZERODATA))==0)
			{
				rc=WN_SQL3BtreeCursor(pCx->pBt,pgno,1,WN_SQL3VdbeRecordCompare,pOp->p3,&pCx->pCursor);
				pCx->pKeyInfo=(KeyInfo*)pOp->p3;
				pCx->pKeyInfo->enc=ENC(p->db);
				pCx->pIncrKey=&pCx->pKeyInfo->incrKey;
			}
			pCx->isTable=0;
		}
		else
		{
			rc=WN_SQL3BtreeCursor(pCx->pBt,MASTER_ROOT,1,0,0,&pCx->pCursor);
			pCx->isTable=1;
			pCx->pIncrKey=&pCx->bogusIncrKey;
		}
		pCx->nField=pOp->p2;
		pCx->isIndex=!pCx->isTable;
		break;
	case OP_OpenPseudo:
		int i=pOp->p1;
		Cursor *pCx=allocateCursor(p,i,-1);
		if(pCx==0)goto no_mem;
		pCx->nullRow=1;
		pCx->pseudoTable=1;
		pCx->pIncrKey=&pCx->bogusIncrKey;
		pCx->isTable=1;
		pCx->isIndex=0;
		break;
	case OP_Close:
		int i=pOp->p1;
		if(i>=0 && i<p->nCursor)
		{
			WN_SQL3VdbeFreeCursor(p,p->apCsr[i]);
			p->apCsr[i]=0;
		}
		break;
	case OP_MoveLt:
	case OP_MoveLe:
	case OP_MoveGe:
	case OP_MoveGt:
		int i=pOp->p1;
		Cursor *pC=p->apCsr[i];
		if(pC->pCursor)
		{
			int res,oc=pOp->opcode;
			pC->nullRow=0;
			*pC->pIncrKey=oc==OP_MoveGt || oc==OP_MoveLe;
			if(pC->isTable)
			{
				i64 iKey;
				WN_SQL3VdbeMemIntegerify(pTos);
				iKey=intToKey(pTos->u.i);
				if(pOp->p2==0 && pOp->opcode==OP_MoveGe)
				{
					pC->movetoTarget=iKey;
					pC->deferredMoveto=1;
					pTos--;
					break;
				}
				if(rc=WN_SQL3BtreeMoveto(pC->pCursor,0,(u64)iKey,0,&res))goto abort_due_to_error;
				pC->lastRowid=pTos->u.i;
				pC->rowidIsValid=res==0;
			}
			else
			{
				ExpandBlob(pTos);
				if(rc=WN_SQL3BtreeMoveto(pC->pCursor,pTos->z,pTos->n,0,&res))goto abort_due_to_error;
				pC->rowidIsValid=0;
			}
			pC->deferredMoveto=0;
			pC->cacheStatus=CACHE_STALE;
			*pC->pIncrKey=0;
#ifdef WN_SQL_TEST
			WN_SQL3_search_count++;
#endif
			if(oc==OP_MoveGe || oc==OP_MoveGt)
			{
				if(res<0)
				{
					if(rc=WN_SQL3BtreeNext(pC->pCursor,&res))goto abort_due_to_error;
					pC->rowidIsValid=0;
				}
				else
					res=0;
			}
			else
				if(res>=0)
				{
					if(rc=WN_SQL3BtreePrevious(pC->pCursor,&res))goto abort_due_to_error;
					pC->rowidIsValid=0;
				}
				else
					res=WN_SQL3BtreeEof(pC->pCursor);
			if(res)
				if(pOp->p2>0)
					pc=pOp->p2-1;
				else
					pC->nullRow=1;
		}
		Release(pTos);
		pTos--;
		break;
	case OP_Distinct:
	case OP_NotFound:
	case OP_Found:
		int i=pOp->p1,alreadyExists=0;
		Cursor *pC;
		if((pC=p->apCsr[i])->pCursor)
		{
			Stringify(pTos,encoding);
			int res,rx=WN_SQL3BtreeMoveto(pC->pCursor,pTos->z,pTos->n,0,&res);
			alreadyExists=rx==0 && res==0;
			pC->deferredMoveto=0;
			pC->cacheStatus=CACHE_STALE;
		}
		if(pOp->opcode==OP_Found)
		{
			if(alreadyExists)pc=pOp->p2-1;
		}
		else
			if(!alreadyExists)pc=pOp->p2-1;
		if(pOp->opcode!=OP_Distinct)
		{
			Release(pTos);
			pTos--;
		}
		break;
	case OP_IsUnique:
		int i=pOp->p1;
		Mem *pNos=&pTos[-1];
		WN_SQL3VdbeMemIntegerify(pTos);
		i64 R=pTos->u.i;
		pTos--;
		Cursor *pCx=p->apCsr[i];
		BtCursor *pCrsr=pCx->pCursor;
		if(pCrsr)
		{
			int res;
			i64 v;
			Stringify(pNos,encoding);
			char *zKey=pNos->z;
			int nKey=pNos->n,szRowid=WN_SQL3VdbeIdxRowidLen((u8*)zKey),len=nKey-szRowid;
			pCx->cacheStatus=CACHE_STALE;
			if(rc=WN_SQL3BtreeMoveto(pCrsr,zKey,len,0,&res))goto abort_due_to_error;
			if(res<0)
			{
				rc=WN_SQL3BtreeNext(pCrsr,&res);
				if(res)
				{
					pc=pOp->p2-1;
					break;
				}
			}
			if(rc=WN_SQL3VdbeIdxKeyCompare(pCx,len,(u8*)zKey,&res))goto abort_due_to_error;
			if(res>0)
			{
				pc=pOp->p2-1;
				break;
			}
			if(rc=WN_SQL3VdbeIdxRowid(pCrsr,&v))goto abort_due_to_error;
			if(v==R)
			{
				pc=pOp->p2-1;
				break;
			}
			pTos++;
			pTos->u.i=v;
			pTos->flags=MEM_Int;
		}
		break;
	case OP_NotExists:
		int i=pOp->p1;
		Cursor *pC;
		BtCursor *pCrsr;
		if((pCrsr=(pC=p->apCsr[i])->pCursor))
		{
			int res;
			u64 iKey;
			iKey=intToKey(pTos->u.i);
			rc=WN_SQL3BtreeMoveto(pCrsr,0,iKey,0,&res);
			pC->lastRowid=pTos->u.i;
			pC->rowidIsValid=res==0;
			pC->nullRow=0;
			pC->cacheStatus=CACHE_STALE;
			if(res)
			{
				pc=pOp->p2-1;
				pC->rowidIsValid=0;
			}
		}
		Release(pTos);
		pTos--;
		break;
	case OP_Sequence:
		int i=pOp->p1;
		pTos++;
		pTos->u.i=p->apCsr[i]->seqCount++;
		pTos->flags=MEM_Int;
		break;
	case OP_NewRowid:
		int i=pOp->p1;
		i64 v=0;
		Cursor *pC;
		if(!(pC=p->apCsr[i])->pCursor==0)
		{
			int res,rx=0,cnt=0;
			i64 x;
			if((WN_SQL3BtreeFlags(pC->pCursor)&(BTREE_INTKEY|BTREE_ZERODATA))!=
BTREE_INTKEY)
			{
				rc=WN_SQL_CORRUPT_BKPT;
				goto abort_due_to_error;
			}
#ifdef WN_SQL_32BIT_ROWID
# define MAX_ROWID 0x7fffffff
#else
# define MAX_ROWID((((u64)0x7fffffff)<<32)|(u64)0xffffffff)
#endif
			if(!pC->useRandomRowid)
			{
				if(pC->nextRowidValid)
					v=pC->nextRowid;
				else
				{
					if(rc=WN_SQL3BtreeLast(pC->pCursor,&res))goto abort_due_to_error;
					if(res)
						v=1;
					else
					{
						WN_SQL3BtreeKeySize(pC->pCursor,&v);
						v=keyToInt(v);
						if(v==MAX_ROWID)
							pC->useRandomRowid=1;
						else
							v++;
					}
				}
#ifndef WN_SQL_OMIT_AUTOINCREMENT
				if(pOp->p2)
				{
					Mem *pMem=&p->aMem[pOp->p2];
					WN_SQL3VdbeMemIntegerify(pMem);
					if(pMem->u.i==MAX_ROWID || pC->useRandomRowid)
					{
						rc=WN_SQL_FULL;
						goto abort_due_to_error;
					}
					if(v<pMem->u.i+1)v=pMem->u.i+1;
					pMem->u.i=v;
				}
#endif
				if(v<MAX_ROWID)
				{
					pC->nextRowidValid=1;
					pC->nextRowid=v+1;
				}
				else
					pC->nextRowidValid=0;
			}
			if(pC->useRandomRowid)
			{
				v=db->priorNewRowid;
				cnt=0;
				do
				{
					if(v==0 || cnt>2)
					{
						WN_SQL3Randomness(sizeof(v),&v);
						if(cnt<5)v&=0xffffff;
					}
					else
					{
						unsigned char r;
						WN_SQL3Randomness(1,&r);
						v+=r+1;
					}
					if(v==0)continue;
					x=intToKey(v);
					rx=WN_SQL3BtreeMoveto(pC->pCursor,0,(u64)x,0,&res);
					cnt++;
				}while(cnt<1000 && rx==0 && res==0);
				db->priorNewRowid=v;
				if(rx==0 && res==0)
				{
					rc=WN_SQL_FULL;
					goto abort_due_to_error;
				}
			}
			pC->rowidIsValid=0;
			pC->deferredMoveto=0;
			pC->cacheStatus=CACHE_STALE;
		}
		pTos++;
		pTos->u.i=v;
		pTos->flags=MEM_Int;
		break;
	case OP_Insert:
		Mem *pNos=&pTos[-1];
		int i=pOp->p1;
		Cursor *pC;
		if(((pC=p->apCsr[i])->pCursor || pC->pseudoTable))
		{
			i64 iKey;
			iKey=intToKey(pNos->u.i);
			if(pOp->p2 & OPFLAG_NCHANGE)p->nChange++;
			if(pOp->p2 & OPFLAG_LASTROWID)db->lastRowid=pNos->u.i;
			if(pC->nextRowidValid && pNos->u.i>=pC->nextRowid)pC->nextRowidValid=0;
			if(pTos->flags & MEM_Null)
			{
				pTos->z=0;
				pTos->n=0;
			}
			if(pC->pseudoTable)
			{
				WN_SQL3FreeX(pC->pData);
				pC->iKey=iKey;
				pC->nData=pTos->n;
				if(pTos->flags & MEM_Dyn)
				{
					pC->pData=pTos->z;
					pTos->flags=MEM_Null;
				}
				else
				{
					pC->pData=WN_SQLMallocRaw(pC->nData+2);
					if(!pC->pData)goto no_mem;
					memcpy(pC->pData,pTos->z,pC->nData);
					pC->pData[pC->nData]=0;
					pC->pData[pC->nData+1]=0;
				}
				pC->nullRow=0;
			}
			else
			{
				int nZero;
				if(pTos->flags & MEM_Zero)
					nZero=pTos->u.i;
				else
					nZero=0;
				rc=WN_SQL3BtreeInsert(pC->pCursor,0,iKey,pTos->z,pTos->n,nZero,pOp->p2 & OPFLAG_APPEND);
			}
			pC->rowidIsValid=0;
			pC->deferredMoveto=0;
			pC->cacheStatus=CACHE_STALE;
			if(rc==0 && db->xUpdateCallback && pOp->p3)
			{
				const char *zDb=db->aDb[pC->iDb].zName,*zTbl=pOp->p3;
				int op=((pOp->p2 & OPFLAG_ISUPDATE)? WN_SQL_UPDATE :WN_SQL_INSERT);
				db->xUpdateCallback(db->pUpdateArg,op,zDb,zTbl,iKey);
			}
		}
		popStack(&pTos,2);
		break;
	case OP_Delete:
		int i=pOp->p1;
		Cursor *pC=p->apCsr[i];
		if(pC->pCursor)
		{
			i64 iKey;
			if(db->xUpdateCallback && pOp->p3)
				if(pC->rowidIsValid)
					iKey=pC->lastRowid;
				else
				{
					if(rc=WN_SQL3BtreeKeySize(pC->pCursor,&iKey))goto abort_due_to_error;
					iKey=keyToInt(iKey);
				}
			if(rc=WN_SQL3VdbeCursorMoveto(pC))goto abort_due_to_error;
			rc=WN_SQL3BtreeDelete(pC->pCursor);
			pC->nextRowidValid=0;
			pC->cacheStatus=CACHE_STALE;
			if(rc==0 && db->xUpdateCallback && pOp->p3)
			{
				const char *zDb=db->aDb[pC->iDb].zName,*zTbl=pOp->p3;
				db->xUpdateCallback(db->pUpdateArg,WN_SQL_DELETE,zDb,zTbl,iKey);
			}
		}
		if(pOp->p2 & OPFLAG_NCHANGE)p->nChange++;
		break;
	case OP_ResetCount:
		if(pOp->p1)WN_SQL3VdbeSetChanges(db,p->nChange);
		p->nChange=0;
		break;
	case OP_RowKey:
	case OP_RowData:
		int i=pOp->p1;
		u32 n;
		pTos++;
		Cursor *pC=p->apCsr[i];
		if(pC->nullRow)
			pTos->flags=MEM_Null;
		else
			if(pC->pCursor)
			{
				BtCursor *pCrsr=pC->pCursor;
				;
				if(rc=WN_SQL3VdbeCursorMoveto(pC))goto abort_due_to_error;
				if(pC->nullRow)
				{
					pTos->flags=MEM_Null;
					break;
				}
				else
					if(pC->isIndex)
					{
						i64 n64;
						WN_SQL3BtreeKeySize(pCrsr,&n64);
						if(n64>WN_SQL_MAX_LENGTH)goto too_big;
						n=n64;
					}
					else
						WN_SQL3BtreeDataSize(pCrsr,&n);
				if(n>WN_SQL_MAX_LENGTH)goto too_big;
				pTos->n=n;
				if(n<=NBFS)
				{
					pTos->flags=MEM_Blob | MEM_Short;
					pTos->z=pTos->zShort;
				}
				else
				{
					char *z=WN_SQLMallocRaw(n);
					if(z==0)goto no_mem;
					pTos->flags=MEM_Blob | MEM_Dyn;
					pTos->xDel=0;
					pTos->z=z;
				}
				if(pC->isIndex)
					rc=WN_SQL3BtreeKey(pCrsr,0,n,pTos->z);
				else
					rc=WN_SQL3BtreeData(pCrsr,0,n,pTos->z);
			}
			else
				if(pC->pseudoTable)
				{
					pTos->n=pC->nData;
					pTos->z=pC->pData;
					pTos->flags=MEM_Blob|MEM_Ephem;
				}
				else
					pTos->flags=MEM_Null;
		pTos->enc=WN_SQL_UTF8;
		break;
	case OP_Rowid:
		int i=pOp->p1;
		i64 v;
		Cursor *pC=p->apCsr[i];
		if(rc=WN_SQL3VdbeCursorMoveto(pC))goto abort_due_to_error;
		pTos++;
		if(pC->rowidIsValid)
			v=pC->lastRowid;
		else
			if(pC->pseudoTable)
				v=keyToInt(pC->iKey);
			else
				if(pC->nullRow || pC->pCursor==0)
				{
					pTos->flags=MEM_Null;
					break;
				}
				else
				{
					WN_SQL3BtreeKeySize(pC->pCursor,&v);
					v=keyToInt(v);
				}
				pTos->u.i=v;
				pTos->flags=MEM_Int;
				break;
	case OP_NullRow:
		int i=pOp->p1;
		Cursor *pC=p->apCsr[i];
		pC->nullRow=1;
		pC->rowidIsValid=0;
		break;
	case OP_Last:
		int i=pOp->p1;
		BtCursor *pCrsr;
		Cursor *pC=p->apCsr[i];
		if((pCrsr=pC->pCursor))
		{
			int res;
			rc=WN_SQL3BtreeLast(pCrsr,&res);
			pC->nullRow=res;
			pC->deferredMoveto=0;
			pC->cacheStatus=CACHE_STALE;
			if(res && pOp->p2>0)pc=pOp->p2-1;
		}
		else
			pC->nullRow=0;
		break;
	case OP_Sort:
#ifdef WN_SQL_TEST
		WN_SQL3_sort_count++;
		WN_SQL3_search_count--;
#endif
	case OP_Rewind:
		int i=pOp->p1;
		BtCursor *pCrsr;
		int res;
		Cursor *pC=p->apCsr[i];
		if((pCrsr=pC->pCursor))
		{
			rc=WN_SQL3BtreeFirst(pCrsr,&res);
			pC->atFirst=res==0;
			pC->deferredMoveto=0;
			pC->cacheStatus=CACHE_STALE;
		}
		else
			res=1;
		pC->nullRow=res;
		if(res && pOp->p2>0)pc=pOp->p2-1;
		break;
	case OP_Prev:
	case OP_Next:
		BtCursor *pCrsr;
		if(db->u1.isInterrupted)goto abort_due_to_interrupt;;
		Cursor *pC=p->apCsr[pOp->p1];
		if(pC==0)break;
		if((pCrsr=pC->pCursor))
		{
			int res;
			if(pC->nullRow)res=1;
			else
			{
				rc=pOp->opcode==OP_Next ? WN_SQL3BtreeNext(pCrsr,&res):WN_SQL3BtreePrevious(pCrsr,&res);
				pC->nullRow=res;
				pC->cacheStatus=CACHE_STALE;
			}
			if(res==0)
			{
				pc=pOp->p2-1;
#ifdef WN_SQL_TEST
				WN_SQL3_search_count++;
#endif
			}
		}
		else
			pC->nullRow=1;
			pC->rowidIsValid=0;
			break;
	case OP_IdxInsert:
		int i=pOp->p1;
		Cursor *pC;
		BtCursor *pCrsr;
		if((pCrsr=(pC=p->apCsr[i])->pCursor)&&(rc=ExpandBlob(pTos))==0)
		{
			int nKey=pTos->n;
			const char *zKey=pTos->z;
			rc=WN_SQL3BtreeInsert(pCrsr,zKey,nKey,"",0,0,pOp->p2);
			pC->cacheStatus=CACHE_STALE;
		}
		Release(pTos);
		pTos--;
		break;
	case OP_IdxDelete:
		int i=pOp->p1;
		Cursor *pC;
		BtCursor *pCrsr;
		if((pCrsr=(pC=p->apCsr[i])->pCursor))
		{
			int res;
			rc=WN_SQL3BtreeMoveto(pCrsr,pTos->z,pTos->n,0,&res);
			if(rc==0 && res==0)rc=WN_SQL3BtreeDelete(pCrsr);
			pC->cacheStatus=CACHE_STALE;
		}
		Release(pTos);
		pTos--;
		break;
	case OP_IdxRowid:
		int i=pOp->p1;
		BtCursor *pCrsr;
		Cursor *pC;
		pTos++;
		pTos->flags=MEM_Null;
		if((pCrsr=(pC=p->apCsr[i])->pCursor))
		{
			i64 rowid;
			if(pC->nullRow)
				pTos->flags=MEM_Null;
			else
			{
				if(rc=WN_SQL3VdbeIdxRowid(pCrsr,&rowid))goto abort_due_to_error;
				pTos->flags=MEM_Int;
				pTos->u.i=rowid;
			}
		}
		break;
	case OP_IdxLT:
	case OP_IdxGT:
	case OP_IdxGE:
		int i=pOp->p1;
		Cursor *pC;
		if((pC=p->apCsr[i])->pCursor)
		{
			int res;
			ExpandBlob(pTos);
			*pC->pIncrKey=pOp->p3!=0;
			rc=WN_SQL3VdbeIdxKeyCompare(pC,pTos->n,(u8*)pTos->z,&res);
			*pC->pIncrKey=0;
			if(rc)break;
			if(pOp->opcode==OP_IdxLT)
				res=-res;
			else
				if(pOp->opcode==OP_IdxGE)res++;
			if(res>0)pc=pOp->p2-1;
		}
		Release(pTos);
		pTos--;
		break;
	case OP_Destroy:
		int iMoved,iCnt;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		Vdbe *pVdbe;
		iCnt=0;
		for(pVdbe=db->pVdbe;pVdbe;pVdbe=pVdbe->pNext)if(pVdbe->magic==VDBE_MAGIC_RUN && pVdbe->inVtabMethod<2 && pVdbe->pc>=0)iCnt++;
#else
		iCnt=db->activeVdbeCnt;
#endif
		if(iCnt>1)
			rc=WN_SQL_LOCKED;
		else
		{
			rc=WN_SQL3BtreeDropTable(db->aDb[pOp->p2].pBt,pOp->p1,&iMoved);
			pTos++;
			pTos->flags=MEM_Int;
			pTos->u.i=iMoved;
#ifndef WN_SQL_OMIT_AUTOVACUUM
			if(rc==0 && iMoved)WN_SQL3RootPageMoved(&db->aDb[pOp->p2],iMoved,pOp->p1);
#endif
		}
		break;
	case OP_Clear:
		rc=WN_SQL3BtreeClearTable(db->aDb[pOp->p2].pBt,pOp->p1);
		break;
	case OP_CreateIndex:
	case OP_CreateTable:
		int pgno,flags;
		Db *pDb=&db->aDb[pOp->p1];
		if(pOp->opcode==OP_CreateTable)
			flags=BTREE_LEAFDATA|BTREE_INTKEY;
		else
			flags=BTREE_ZERODATA;
		rc=WN_SQL3BtreeCreateTable(pDb->pBt,&pgno,flags);
		pTos++;
		if(rc==0)
		{
			pTos->u.i=pgno;
			pTos->flags=MEM_Int;
		}
		else
			pTos->flags=MEM_Null;
		break;
	case OP_ParseSchema:
		char *zSql;
		int iDb=pOp->p1;
		const char *zMaster;
		InitData initData;
		if(!pOp->p2 && !DbHasProperty(db,iDb,DB_SchemaLoaded))break;
		zMaster=SCHEMA_TABLE(iDb);
		initData.db=db;
		initData.iDb=pOp->p1;
		initData.pzErrMsg=&p->zErrMsg;
		zSql=WN_SQL3MPrintf("SELECT name,rootpage,sql FROM '%q'.%s WHERE %s",db->aDb[iDb].zName,zMaster,pOp->p3);
		if(zSql==0)goto no_mem;
		WN_SQL3SafetyOff(db);
		db->init.busy=1;
		rc=WN_SQL3_exec(db,zSql,WN_SQL3InitCallback,&initData,0);
		if(rc==WN_SQL_ABORT)rc=initData.rc;
		WN_SQL3FreeX(zSql);
		db->init.busy=0;
		WN_SQL3SafetyOn(db);
		if(rc==WN_SQL_NOMEM)
		{
			WN_SQL3FailedMalloc();
			goto no_mem;
		}
		break;
#if !defined(WN_SQL_OMIT_ANALYZE)&& !defined(WN_SQL_OMIT_PARSER)
	case OP_LoadAnalysis:
		int iDb=pOp->p1;
		rc=WN_SQL3AnalysisLoad(db,iDb);
		break;
#endif
	case OP_DropTable:
		WN_SQL3UnlinkAndDeleteTable(db,pOp->p1,pOp->p3);
		break;
	case OP_DropIndex:
		WN_SQL3UnlinkAndDeleteIndex(db,pOp->p1,pOp->p3);
		break;
	case OP_DropTrigger:
		WN_SQL3UnlinkAndDeleteTrigger(db,pOp->p1,pOp->p3);
		break;
#ifndef WN_SQL_OMIT_INTEGRITY_CHECK
	case OP_IntegrityCk:
		int nRoot,*aRoot,j,nErr;
		char *z;
		Mem *pnErr;
		for(nRoot=0;&pTos[-nRoot]>=p->aStack;nRoot++)
			if((pTos[-nRoot].flags & MEM_Int)==0)break;
		aRoot=WN_SQLMallocRaw(sizeof(int*)*(nRoot+1));
		if(aRoot==0)goto no_mem;
		j=pOp->p1;
		pnErr=&p->aMem[j];
		for(j=0;j<nRoot;j++)aRoot[j]=pTos[-j].u.i;
		aRoot[j]=0;
		popStack(&pTos,nRoot);
		pTos++;
		z=WN_SQL3BtreeIntegrityCheck(db->aDb[pOp->p2].pBt,aRoot,nRoot,pnErr->u.i,&nErr);
		pnErr->u.i-=nErr;
		if(nErr==0)
			pTos->flags=MEM_Null;
		else
		{
			pTos->z=z;
			pTos->n=strlen(z);
			pTos->flags=MEM_Str | MEM_Dyn | MEM_Term;
			pTos->xDel=0;
		}
		pTos->enc=WN_SQL_UTF8;
		WN_SQL3VdbeChangeEncoding(pTos,encoding);
		WN_SQL3FreeX(aRoot);
		break;
#endif
	case OP_FifoWrite:
		WN_SQL3VdbeMemIntegerify(pTos);
		WN_SQL3VdbeFifoPush(&p->sFifo,pTos->u.i);
		pTos--;
		break;
	case OP_FifoRead:
		i64 v;
		if(db->u1.isInterrupted)goto abort_due_to_interrupt;;
		if(WN_SQL3VdbeFifoPop(&p->sFifo,&v)==WN_SQL_DONE)
			pc=pOp->p2-1;
		else
		{
			pTos++;
			pTos->u.i=v;
			pTos->flags=MEM_Int;
		}
		break;
#ifndef WN_SQL_OMIT_TRIGGER
	case OP_ContextPush:
		int i=p->contextStackTop++;
		Context *pContext;
		if(i>=p->contextStackDepth)
		{
			p->contextStackDepth=i+1;
			p->contextStack=WN_SQLReallocOrFree(p->contextStack,sizeof(Context)*(i+1));
			if(p->contextStack==0)goto no_mem;
		}
		pContext=&p->contextStack[i];
		pContext->lastRowid=db->lastRowid;
		pContext->nChange=p->nChange;
		pContext->sFifo=p->sFifo;
		WN_SQL3VdbeFifoInit(&p->sFifo);
		break;
	case OP_ContextPop:
		Context *pContext=&p->contextStack[--p->contextStackTop];
		db->lastRowid=pContext->lastRowid;
		p->nChange=pContext->nChange;
		WN_SQL3VdbeFifoClear(&p->sFifo);
		p->sFifo=pContext->sFifo;
		break;
#endif
	case OP_MemStore:
		rc=WN_SQL3VdbeMemMove(&p->aMem[pOp->p1],pTos);
		pTos--;
		if(pOp->p2)break;
	case OP_MemLoad:
		int i=pOp->p1;
		pTos++;
		WN_SQL3VdbeMemShallowCopy(pTos,&p->aMem[i],MEM_Ephem);
		break;
#ifndef WN_SQL_OMIT_AUTOINCREMENT
	case OP_MemMax:
		int i=pOp->p1;
		Mem *pMem=&p->aMem[i];
		WN_SQL3VdbeMemIntegerify(pMem);
		WN_SQL3VdbeMemIntegerify(pTos);
		if(pMem->u.i<pTos->u.i)pMem->u.i=pTos->u.i;
		break;
#endif
	case OP_MemIncr:
		int i=pOp->p2;
		Mem *pMem=&p->aMem[i];
		pMem->u.i+=pOp->p1;
		break;
	case OP_IfMemPos:
		int i=pOp->p1;
		Mem *pMem=&p->aMem[i];
		if(pMem->u.i>0)pc=pOp->p2-1;
		break;
	case OP_IfMemNeg:
		int i=pOp->p1;
		Mem *pMem=&p->aMem[i];
		if(pMem->u.i<0)pc=pOp->p2-1;
		break;
	case OP_IfMemZero:
		int i=pOp->p1;
		Mem *pMem=&p->aMem[i];
		if(pMem->u.i==0)pc=pOp->p2-1;
		break;
	case OP_MemNull:
		WN_SQL3VdbeMemSetNull(&p->aMem[pOp->p1]);
		break;
	case OP_MemInt:
		WN_SQL3VdbeMemSetInt64(&p->aMem[pOp->p2],pOp->p1);
		break;
	case OP_MemMove:
		rc=WN_SQL3VdbeMemMove(&p->aMem[pOp->p1],&p->aMem[pOp->p2]);
		break;
	case OP_AggStep:
		int n=pOp->p2,i;
		Mem *pMem,*pRec;
		WN_SQL3_context ctx;
		WN_SQL3_value **apVal;
		pRec=&pTos[1-n];
		apVal=p->apArg;
		for(i=0;i<n;i++,pRec++)
		{
			apVal[i]=pRec;
			storeTypeInfo(pRec,encoding);
		}
		ctx.pFunc=(FuncDef*)pOp->p3;
		ctx.pMem=pMem=&p->aMem[pOp->p1];
		pMem->n++;
		ctx.s.flags=MEM_Null;
		ctx.s.z=0;
		ctx.s.xDel=0;
		ctx.isError=0;
		ctx.pColl=0;
		if(ctx.pFunc->needCollSeq)ctx.pColl=(CollSeq *)pOp[-1].p3;
		(ctx.pFunc->xStep)(&ctx,n,apVal);
		popStack(&pTos,n);
		if(ctx.isError)
		{
			WN_SQL3SetString(&p->zErrMsg,WN_SQL3_value_text(&ctx.s),(char*)0);
			rc=WN_SQL_ERROR;
		}
		WN_SQL3VdbeMemRelease(&ctx.s);
		break;
	case OP_AggFinal:
		Mem *pMem=&p->aMem[pOp->p1];
		rc=WN_SQL3VdbeMemFinalize(pMem,(FuncDef*)pOp->p3);
		if(rc==WN_SQL_ERROR)WN_SQL3SetString(&p->zErrMsg,WN_SQL3_value_text(pMem),(char*)0);
		if(WN_SQL3VdbeMemTooBig(pMem))goto too_big;
		break;
#if !defined(WN_SQL_OMIT_VACUUM)&& !defined(WN_SQL_OMIT_ATTACH)
	case OP_Vacuum:
		if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
		rc=WN_SQL3RunVacuum(&p->zErrMsg,db);
		if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
		break;
#endif
#if !defined(WN_SQL_OMIT_AUTOVACUUM)
	case OP_IncrVacuum:
		Btree *pBt=db->aDb[pOp->p1].pBt;
		if((rc=WN_SQL3BtreeIncrVacuum(pBt))==WN_SQL_DONE)
		{
			pc=pOp->p2-1;
			rc=0;
		}
		break;
#endif
	case OP_Expire:
		if(!pOp->p1)
			WN_SQL3ExpirePreparedStatements(db);
		else
			p->expired=1;
		break;
#ifndef WN_SQL_OMIT_SHARED_CACHE
	case OP_TableLock:
		int p1=pOp->p1;
		u8 isWriteLock=(p1<0);
		if(isWriteLock)p1=(-1*p1)-1;
		rc=WN_SQL3BtreeLockTable(db->aDb[p1].pBt,pOp->p2,isWriteLock);
		if(rc==WN_SQL_LOCKED)
		{
			const char *z=(const char *)pOp->p3;
			WN_SQL3SetString(&p->zErrMsg,"database table is locked:",z,(char*)0);
		}
		break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VBegin:
			rc=WN_SQL3VtabBegin(db,(WN_SQL3_vtab *)pOp->p3);
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VCreate:
			rc=WN_SQL3VtabCallCreate(db,pOp->p1,pOp->p3,&p->zErrMsg);
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VDestroy:
			p->inVtabMethod=2;
			rc=WN_SQL3VtabCallDestroy(db,pOp->p1,pOp->p3);
			p->inVtabMethod=0;
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VOpen:
			Cursor *pCur=0;
			WN_SQL3_vtab_cursor *pVtabCursor=0;
			WN_SQL3_vtab *pVtab=(WN_SQL3_vtab *)(pOp->p3);
			WN_SQL3_module *pModule=(WN_SQL3_module *)pVtab->pModule;
			if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
			rc=pModule->xOpen(pVtab,&pVtabCursor);
			if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
			if(0==rc)
			{
				pVtabCursor->pVtab=pVtab;
				pCur=allocateCursor(p,pOp->p1,-1);
				if(pCur)
				{
					pCur->pVtabCursor=pVtabCursor;
					pCur->pModule=pVtabCursor->pVtab->pModule;
				}
				else
					pModule->xClose(pVtabCursor);
			}
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VFilter:
			int nArg;
			const WN_SQL3_module *pModule;
			Cursor *pCur=p->apCsr[pOp->p1];
			pModule=pCur->pVtabCursor->pVtab->pModule;
			nArg=pTos[-1].u.i;
			{
				int res=0,i;
				Mem **apArg=p->apArg;
				for(i=0;i<nArg;i++)
				{
					apArg[i]=&pTos[i+1-2-nArg];
					storeTypeInfo(apArg[i],0);
				}
				if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
				p->inVtabMethod=1;
				rc=pModule->xFilter(pCur->pVtabCursor,pTos->u.i,pOp->p3,nArg,apArg);
				p->inVtabMethod=0;
				if(rc==0)res=pModule->xEof(pCur->pVtabCursor);
				if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
				if(res)pc=pOp->p2-1;
			}
			popStack(&pTos,2+nArg);
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VRowid:
			const WN_SQL3_module *pModule;
			Cursor *pCur=p->apCsr[pOp->p1];
			pModule=pCur->pVtabCursor->pVtab->pModule;
			if(pModule->xRowid==0)
			{
				WN_SQL3SetString(&p->zErrMsg,"Unsupported module operation:xRowid",0);
				rc=WN_SQL_ERROR;
			}
			else
			{
				WN_SQL_int64 iRow;
				if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
				rc=pModule->xRowid(pCur->pVtabCursor,&iRow);
				if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
				pTos++;
				pTos->flags=MEM_Int;
				pTos->u.i=iRow;
			}
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VColumn:
			const WN_SQL3_module *pModule;
			Cursor *pCur=p->apCsr[pOp->p1];
			pModule=pCur->pVtabCursor->pVtab->pModule;
			if(pModule->xColumn==0)
			{
				WN_SQL3SetString(&p->zErrMsg,"Unsupported module operation:xColumn",0);
				rc=WN_SQL_ERROR;
			}
			else
			{
				WN_SQL3_context sContext;
				memset(&sContext,0,sizeof(sContext));
				sContext.s.flags=MEM_Null;
				if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
				rc=pModule->xColumn(pCur->pVtabCursor,&sContext,pOp->p2);
				WN_SQL3VdbeChangeEncoding(&sContext.s,encoding);
				pTos++;
				pTos->flags=0;
				WN_SQL3VdbeMemMove(pTos,&sContext.s);
				if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
				if(WN_SQL3VdbeMemTooBig(pTos))goto too_big;
			}
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VNext:
			const WN_SQL3_module *pModule;
			int res=0;
			Cursor *pCur=p->apCsr[pOp->p1];
			pModule=pCur->pVtabCursor->pVtab->pModule;
			if(pModule->xNext==0)
			{
				WN_SQL3SetString(&p->zErrMsg,"Unsupported module operation:xNext",0);
				rc=WN_SQL_ERROR;
			}
			else
			{
				if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
				p->inVtabMethod=1;
				rc=pModule->xNext(pCur->pVtabCursor);
				p->inVtabMethod=0;
				if(rc==0)res=pModule->xEof(pCur->pVtabCursor);
				if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
				if(!res)pc=pOp->p2-1;
			}
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VRename:
			WN_SQL3_vtab *pVtab=(WN_SQL3_vtab *)(pOp->p3);
			Stringify(pTos,encoding);
			if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
			WN_SQL3VtabLock(pVtab);
			rc=pVtab->pModule->xRename(pVtab,pTos->z);
			WN_SQL3VtabUnlock(db,pVtab);
			if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
			popStack(&pTos,1);
			break;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		case OP_VUpdate:
			WN_SQL3_vtab *pVtab=(WN_SQL3_vtab *)(pOp->p3);
			WN_SQL3_module *pModule=(WN_SQL3_module *)pVtab->pModule;
			int nArg=pOp->p2;
			if(pModule->xUpdate==0)
			{
				WN_SQL3SetString(&p->zErrMsg,"read-only table",0);
				rc=WN_SQL_ERROR;
			}
			else
			{
				int i;
				WN_SQL_int64 rowid;
				Mem **apArg=p->apArg,*pX=&pTos[1-nArg];
				for(i=0;i<nArg;i++,pX++)
				{
					storeTypeInfo(pX,0);
					apArg[i]=pX;
				}
				if(WN_SQL3SafetyOff(db))goto abort_due_to_misuse;
				WN_SQL3VtabLock(pVtab);
				rc=pModule->xUpdate(pVtab,nArg,apArg,&rowid);
				WN_SQL3VtabUnlock(db,pVtab);
				if(WN_SQL3SafetyOn(db))goto abort_due_to_misuse;
				if(pOp->p1 && rc==0)db->lastRowid=rowid;
			}
			popStack(&pTos,nArg);
			break;
#endif
		default:
			break;
	}
#ifdef VDBE_PROFILE
	long long elapse=hwtime()-start;
	pOp->cycles+=elapse;
	pOp->cnt++;
#if 0
	fprintf(stdout,"%10lld ",elapse);
	WN_SQL3VdbePrintOp(stdout,origPc,&p->aOp[origPc]);
#endif
#endif
#ifdef WN_SQL_TEST
	if(pTos>=p->aStack &&(pTos->flags &(MEM_Blob|MEM_Str))&& pTos->n>WN_SQL3_max_blobsize)WN_SQL3_max_blobsize=pTos->n;
#endif
#ifndef NDEBUG
	if(pTos>=p->aStack && pTos->flags)WN_SQL3VdbeMemSanity(pTos);
#ifdef WN_SQL_DEBUG
	if(p->trace && pTos>=p->aStack)
	{
		int i;
		fprintf(p->trace,"Stack:");
		for(i=0;i>-5 && &pTos[i]>=p->aStack;i--)
		{
			if(pTos[i].flags & MEM_Null)
				fprintf(p->trace," NULL");
			else
				if((pTos[i].flags &(MEM_Int|MEM_Str))==(MEM_Int|MEM_Str))
					fprintf(p->trace," si:%lld",pTos[i].u.i);
				else
					if(pTos[i].flags & MEM_Int)
						fprintf(p->trace," i:%lld",pTos[i].u.i);
					else
						if(pTos[i].flags & MEM_Real)
							fprintf(p->trace," r:%g",pTos[i].r);
						else
						{
							char zBuf[200];
							WN_SQL3VdbeMemPrettyPrint(&pTos[i],zBuf);
							fprintf(p->trace," ");
							fprintf(p->trace,"%s",zBuf);
						}
		}
		if(rc)fprintf(p->trace," rc=%d",rc);
		fprintf(p->trace,"\n");
	}
#endif
#endif
}
vdbe_halt:
	if(rc)
	{
		p->rc=rc;
		rc=WN_SQL_ERROR;
	}
	else
		rc=WN_SQL_DONE;
	WN_SQL3VdbeHalt(p);
	p->pTos=pTos;
	return rc;
too_big:
	WN_SQL3SetString(&p->zErrMsg,"string or blob too big",(char*)0);
	rc=WN_SQL_TOOBIG;
	goto vdbe_halt;
no_mem:
	WN_SQL3SetString(&p->zErrMsg,"out of memory",(char*)0);
	rc=WN_SQL_NOMEM;
	goto vdbe_halt;
abort_due_to_misuse:
	rc=WN_SQL_MISUSE;
abort_due_to_error:
	if(p->zErrMsg==0)
	{
		if(WN_SQL3MallocFailed())rc=WN_SQL_NOMEM;
		WN_SQL3SetString(&p->zErrMsg,WN_SQL3ErrStr(rc),(char*)0);
	}
	goto vdbe_halt;
abort_due_to_interrupt:
	if(db->magic!=WN_SQL_MAGIC_BUSY)
		rc=WN_SQL_MISUSE;
	else
		rc=WN_SQL_INTERRUPT;
	p->rc=rc;
	WN_SQL3SetString(&p->zErrMsg,WN_SQL3ErrStr(rc),(char*)0);
	goto vdbe_halt;
}
#ifndef WN_SQL_OMIT_INCRBLOB
typedef struct Incrblob Incrblob;
struct Incrblob
{
	int flags,nByte,iOffset;
	BtCursor *pCsr;
	WN_SQL3_stmt *pStmt;
};
int WN_SQL3_blob_open(WN_SQL3* db,const char *zDb,const char *zTable,const char *zColumn,WN_SQL_int64 iRow,int flags,WN_SQL3_blob **ppBlob)
{
	int nAttempt=0,iCol;
	const VdbeOpList openBlob[]={{OP_Transaction,0,0,0},{OP_VerifyCookie,0,0,0},{OP_Integer,0,0,0},{OP_OpenRead,0,0,0},{OP_OpenWrite,0,0,0},{OP_SetNumColumns,0,0,0},{OP_Variable,1,0,0},{OP_NotExists,0,10,0},{OP_Column,0,0,0},{OP_Callback,0,0,0},{OP_Close,0,0,0},{OP_Halt,0,0,0},};
	Vdbe *v=0;
	int rc=0;
	char zErr[128];
	zErr[0]=0;
	do
	{
		Parse sParse;
		Table *pTab;
		memset(&sParse,0,sizeof(Parse));
		sParse.db=db;
		if(rc=WN_SQL3SafetyOn(db))return rc;
		pTab=WN_SQL3LocateTable(&sParse,zTable,zDb);
		if(!pTab)
		{
			if(sParse.zErrMsg)
				WN_SQL3_snprintf(sizeof(zErr),zErr,"%s",sParse.zErrMsg);
			WN_SQL3FreeX(sParse.zErrMsg);
			rc=WN_SQL_ERROR;
			WN_SQL3SafetyOff(db);
			goto blob_open_out;
		}
		for(iCol=0;iCol<pTab->nCol;iCol++)
			if(WN_SQL3StrICmp(pTab->aCol[iCol].zName,zColumn)==0)break;
		if(iCol==pTab->nCol)
		{
			WN_SQL3_snprintf(sizeof(zErr),zErr,"no such column:\"%s\"",zColumn);
			rc=WN_SQL_ERROR;
			WN_SQL3SafetyOff(db);
			goto blob_open_out;
		}
		if(flags)
		{
			Index *pIdx;
			for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)
			{
				int j;
				for(j=0;j<pIdx->nColumn;j++)
					if(pIdx->aiColumn[j]==iCol)
					{
						WN_SQL3_snprintf(sizeof(zErr),zErr,"cannot open indexed column for writing");
						rc=WN_SQL_ERROR;
						WN_SQL3SafetyOff(db);
						goto blob_open_out;
					}
			}
		}
		v=WN_SQL3VdbeCreate(db);
		if(v)
		{
			int iDb=WN_SQL3SchemaToIndex(db,pTab->pSchema);
			WN_SQL3VdbeAddOpList(v,sizeof(openBlob)/sizeof(VdbeOpList),openBlob);
			WN_SQL3VdbeChangeP1(v,0,iDb);
			WN_SQL3VdbeChangeP2(v,0,(flags ? 1 :0));
			WN_SQL3VdbeChangeP1(v,1,iDb);
			WN_SQL3VdbeChangeP2(v,1,pTab->pSchema->schema_cookie);
			WN_SQL3VdbeChangeP1(v,2,iDb);
			WN_SQL3VdbeChangeToNoop(v,(flags ? 3 :4),1);
			WN_SQL3VdbeChangeP2(v,(flags ? 4 :3),pTab->tnum);
			WN_SQL3VdbeChangeP2(v,5,pTab->nCol+1);
			if(!WN_SQL3MallocFailed())WN_SQL3VdbeMakeReady(v,1,0,1,0);
		}
		rc=WN_SQL3SafetyOff(db);
		if(rc || WN_SQL3MallocFailed())goto blob_open_out;
		WN_SQL3_bind_int64((WN_SQL3_stmt *)v,1,iRow);
		rc=WN_SQL3_step((WN_SQL3_stmt *)v);
		if(rc!=WN_SQL_ROW)
		{
			nAttempt++;
			rc=WN_SQL3_finalize((WN_SQL3_stmt *)v);
			WN_SQL3_snprintf(sizeof(zErr),zErr,WN_SQL3_errmsg(db));
			v=0;
		}
	}while(nAttempt<5 && rc==WN_SQL_SCHEMA);
	if(rc==WN_SQL_ROW)
	{
		Incrblob *pBlob;
		u32 type=v->apCsr[0]->aType[iCol];
		if(type<12)
		{
			WN_SQL3_snprintf(sizeof(zErr),zErr,"cannot open value of type %s",type==0?"null":type==7?"real":"integer");
			rc=WN_SQL_ERROR;
			goto blob_open_out;
		}
		pBlob=(Incrblob *)WN_SQL3Malloc(sizeof(Incrblob));
		if(WN_SQL3MallocFailed())
		{
			WN_SQL3FreeX(pBlob);
			goto blob_open_out;
		}
		pBlob->flags=flags;
		pBlob->pCsr=v->apCsr[0]->pCursor;
		WN_SQL3BtreeCacheOverflow(pBlob->pCsr);
		pBlob->pStmt=(WN_SQL3_stmt *)v;
		pBlob->iOffset=v->apCsr[0]->aOffset[iCol];
		pBlob->nByte=WN_SQL3VdbeSerialTypeLen(type);
		*ppBlob=(WN_SQL3_blob *)pBlob;
		rc=0;
	}
	else
		if(rc==0)
		{
			WN_SQL3_snprintf(sizeof(zErr),zErr,"no such rowid:%lld",iRow);
			rc=WN_SQL_ERROR;
		}
blob_open_out:
	zErr[sizeof(zErr)-1]='\0';
	if(rc || WN_SQL3MallocFailed())WN_SQL3_finalize((WN_SQL3_stmt *)v);
	WN_SQL3Error(db,rc,(rc==0?0:zErr));
	return WN_SQL3ApiExit(db,rc);
}
int WN_SQL3_blob_close(WN_SQL3_blob *pBlob)
{
	Incrblob *p=(Incrblob *)pBlob;
	WN_SQL3_stmt *pStmt=p->pStmt;
	WN_SQL3FreeX(p);
	return WN_SQL3_finalize(pStmt);
}
int blobReadWrite(WN_SQL3_blob *pBlob,void *z,int n,int iOffset,int(*xCall)(BtCursor*,u32,u32,void*))
{
	Incrblob *p=(Incrblob *)pBlob;
	Vdbe *v=(Vdbe *)(p->pStmt);
	if(!v)return WN_SQL_ABORT;
	if((iOffset+n)>p->nByte)return WN_SQL_ERROR;
	WN_SQL3 *db=v->db;
	int rc=xCall(p->pCsr,iOffset+p->iOffset,n,z);
	if(rc==WN_SQL_ABORT)
	{
		WN_SQL3VdbeFinalize(v);
		p->pStmt=0;
	}
	else
	{
		db->errCode=rc;
		v->rc=rc;
	}
	return WN_SQL3ApiExit(db,rc);
}
int WN_SQL3_blob_read(WN_SQL3_blob *pBlob,void *z,int n,int iOffset)
{
	return blobReadWrite(pBlob,z,n,iOffset,WN_SQL3BtreeData);
}
int WN_SQL3_blob_write(WN_SQL3_blob *pBlob,const void *z,int n,int iOffset)
{
	return blobReadWrite(pBlob,(void *)z,n,iOffset,WN_SQL3BtreePutData);
}
int WN_SQL3_blob_bytes(WN_SQL3_blob *pBlob)
{
	Incrblob *p=(Incrblob *)pBlob;
	return p->nByte;
}
#endif
char WN_SQL3ExprAffinity(Expr *pExpr)
{
	int op=pExpr->op;
	if(op==TK_SELECT)return WN_SQL3ExprAffinity(pExpr->pSelect->pEList->a[0].pExpr);
#ifndef WN_SQL_OMIT_CAST
	if(op==TK_CAST)return WN_SQL3AffinityType(&pExpr->token);
#endif
	return pExpr->affinity;
}
Expr *WN_SQL3ExprSetColl(Parse *pParse,Expr *pExpr,Token *pName)
{
	if(pExpr==0)return 0;
	CollSeq *pColl=WN_SQL3LocateCollSeq(pParse,(char*)pName->z,pName->n);
	if(pColl)
	{
		pExpr->pColl=pColl;
		pExpr->flags |=EP_ExpCollate;
	}
	return pExpr;
}
CollSeq *WN_SQL3ExprCollSeq(Parse *pParse,Expr *pExpr)
{
	CollSeq *pColl=0;
	if(pExpr)
	{
		int op;
		pColl=pExpr->pColl;
		op=pExpr->op;
		if((op==TK_CAST || op==TK_UPLUS)&& !pColl)return WN_SQL3ExprCollSeq(pParse,pExpr->pLeft);
	}
	if(WN_SQL3CheckCollSeq(pParse,pColl))pColl=0;
	return pColl;
}
char WN_SQL3CompareAffinity(Expr *pExpr,char aff2)
{
	char aff1=WN_SQL3ExprAffinity(pExpr);
	if(aff1 && aff2)
	{
		if(WN_SQL3IsNumericAffinity(aff1)|| WN_SQL3IsNumericAffinity(aff2))
			return WN_SQL_AFF_NUMERIC;
		else
			return WN_SQL_AFF_NONE;
	}
	else
		if(!aff1 && !aff2)
			return WN_SQL_AFF_NONE;
		else
			return(aff1+aff2);
}
char comparisonAffinity(Expr *pExpr)
{
	pExpr->op==TK_GT || pExpr->op==TK_GE || pExpr->op==TK_LE ||
pExpr->op==TK_NE);
	char aff=WN_SQL3ExprAffinity(pExpr->pLeft);
	if(pExpr->pRight)
		aff=WN_SQL3CompareAffinity(pExpr->pRight,aff);
	else
		if(pExpr->pSelect)
			aff=WN_SQL3CompareAffinity(pExpr->pSelect->pEList->a[0].pExpr,aff);
		else
			if(!aff)aff=WN_SQL_AFF_NONE;
	return aff;
}
int WN_SQL3IndexAffinityOk(Expr *pExpr,char idx_affinity)
{
	char aff=comparisonAffinity(pExpr);
	switch(aff)
	{
	case WN_SQL_AFF_NONE:
		return 1;
	case WN_SQL_AFF_TEXT:
		return idx_affinity==WN_SQL_AFF_TEXT;
	default:
		return WN_SQL3IsNumericAffinity(idx_affinity);
	}
}
int binaryCompareP1(Expr *pExpr1,Expr *pExpr2,int jumpIfNull)
{
	char aff=WN_SQL3ExprAffinity(pExpr2);
	return((int)WN_SQL3CompareAffinity(pExpr1,aff))+(jumpIfNull?0x100:0);
}
CollSeq* WN_SQL3BinaryCompareCollSeq(Parse *pParse,Expr *pLeft,Expr *pRight)
{
	CollSeq *pColl;
	if(pLeft->flags & EP_ExpCollate)
		pColl=pLeft->pColl;
	else
		if(pRight && pRight->flags & EP_ExpCollate)
			pColl=pRight->pColl;
		else
		{
			pColl=WN_SQL3ExprCollSeq(pParse,pLeft);
			if(!pColl)pColl=WN_SQL3ExprCollSeq(pParse,pRight);
		}
		return pColl;
}
int codeCompare(Parse *pParse,Expr *pLeft,Expr *pRight,int opcode,int dest,int jumpIfNull)
{
	int p1=binaryCompareP1(pLeft,pRight,jumpIfNull);
	CollSeq *p3=WN_SQL3BinaryCompareCollSeq(pParse,pLeft,pRight);
	return WN_SQL3VdbeOp3(pParse->pVdbe,opcode,p1,dest,(void*)p3,P3_COLLSEQ);
}
Expr *WN_SQL3Expr(int op,Expr *pLeft,Expr *pRight,const Token *pToken)
{
	Expr *pNew=WN_SQL3Malloc(sizeof(Expr));
	if(pNew==0)
	{
		WN_SQL3ExprDelete(pLeft);
		WN_SQL3ExprDelete(pRight);
		return 0;
	}
	pNew->op=op;
	pNew->pLeft=pLeft;
	pNew->pRight=pRight;
	pNew->iAgg=-1;
	if(pToken)
		pNew->span=pNew->token=*pToken;
	else
		if(pLeft)
		{
			if(pRight)
			{
				WN_SQL3ExprSpan(pNew,&pLeft->span,&pRight->span);
				if(pRight->flags & EP_ExpCollate)
				{
					pNew->flags |=EP_ExpCollate;
					pNew->pColl=pRight->pColl;
				}
			}
			if(pLeft->flags & EP_ExpCollate)
			{
				pNew->flags |=EP_ExpCollate;
				pNew->pColl=pLeft->pColl;
			}
		}
		WN_SQL3ExprSetHeight(pNew);
		return pNew;
}
Expr *WN_SQL3ExprOrFree(int op,Expr *pLeft,Expr *pRight,const Token *pToken)
{
	Expr *pNew=WN_SQL3Expr(op,pLeft,pRight,pToken);
	if(pNew==0)
	{
		WN_SQL3ExprDelete(pLeft);
		WN_SQL3ExprDelete(pRight);
	}
	return pNew;
}
Expr *WN_SQL3RegisterExpr(Parse *pParse,Token *pToken)
{
	Vdbe *v=pParse->pVdbe;
	Expr *p;
	int depth;
	if(pParse->nested==0)
	{
		WN_SQL3ErrorMsg(pParse,"near \"%T\":syntax error",pToken);
		return WN_SQL3Expr(TK_NULL,0,0,0);
	}
	if(v==0)return 0;
	p=WN_SQL3Expr(TK_REGISTER,0,0,pToken);
	if(p==0)return 0;
	depth=atoi((char*)&pToken->z[1]);
	p->iTable=pParse->nMem++;
	WN_SQL3VdbeAddOp(v,OP_Dup,depth,0);
	WN_SQL3VdbeAddOp(v,OP_MemStore,p->iTable,1);
	return p;
}
Expr *WN_SQL3ExprAnd(Expr *pLeft,Expr *pRight)
{
	if(pLeft==0)
		return pRight;
	else
		if(pRight==0)
			return pLeft;
		else
			return WN_SQL3Expr(TK_AND,pLeft,pRight,0);
}
void WN_SQL3ExprSpan(Expr *pExpr,Token *pLeft,Token *pRight)
{
	if(!WN_SQL3MallocFailed()&& pRight->z && pLeft->z)
		if(pLeft->dyn==0 && pRight->dyn==0)
		{
			pExpr->span.z=pLeft->z;
			pExpr->span.n=pRight->n+(pRight->z-pLeft->z);
		}
		else
			pExpr->span.z=0;
}
Expr *WN_SQL3ExprFunction(ExprList *pList,Token *pToken)
{
	Expr *pNew=WN_SQL3Malloc(sizeof(Expr));
	if(pNew==0)
	{
		WN_SQL3ExprListDelete(pList);
		return 0;
	}
	pNew->op=TK_FUNCTION;
	pNew->pList=pList;
	pNew->token=*pToken;
	pNew->span=pNew->token;
	WN_SQL3ExprSetHeight(pNew);
	return pNew;
}
void WN_SQL3ExprAssignVarNumber(Parse *pParse,Expr *pExpr)
{
	Token *pToken;
	if(pExpr==0)return;
	pToken=&pExpr->token;
	if(pToken->n==1)
		pExpr->iTable=++pParse->nVar;
	else
		if(pToken->z[0]=='?')
		{
			int i;
			pExpr->iTable=i=atoi((char*)&pToken->z[1]);
			if(i<1 || i>WN_SQL_MAX_VARIABLE_NUMBER)WN_SQL3ErrorMsg(pParse,"variable number must be between ?1 and ?%d",WN_SQL_MAX_VARIABLE_NUMBER);
			if(i>pParse->nVar)pParse->nVar=i;
		}
		else
		{
			int i,n;
			n=pToken->n;
			for(i=0;i<pParse->nVarExpr;i++)
			{
				Expr *pE;
				if((pE=pParse->apVarExpr[i])&& pE->token.n==n&& memcmp(pE->token.z,pToken->z,n)==0)
				{
					pExpr->iTable=pE->iTable;
					break;
				}
			}
			if(i>=pParse->nVarExpr)
			{
				pExpr->iTable=++pParse->nVar;
				if(pParse->nVarExpr>=pParse->nVarExprAlloc-1)
				{
					pParse->nVarExprAlloc+=pParse->nVarExprAlloc+10;
					pParse->apVarExpr=WN_SQLReallocOrFree(pParse->apVarExpr,pParse->nVarExprAlloc*sizeof(pParse->apVarExpr[0]));
				}
				if(!WN_SQL3MallocFailed())pParse->apVarExpr[pParse->nVarExpr++]=pExpr;
			}
		}
		if(!pParse->nErr && pParse->nVar>WN_SQL_MAX_VARIABLE_NUMBER)WN_SQL3ErrorMsg(pParse,"too many SQL variables");
}
void WN_SQL3ExprDelete(Expr *p)
{
	if(p==0)return;
	if(p->span.dyn)WN_SQL3FreeX((char*)p->span.z);
	if(p->token.dyn)WN_SQL3FreeX((char*)p->token.z);
	WN_SQL3ExprDelete(p->pLeft);
	WN_SQL3ExprDelete(p->pRight);
	WN_SQL3ExprListDelete(p->pList);
	WN_SQL3SelectDelete(p->pSelect);
	WN_SQL3FreeX(p);
}
void WN_SQL3DequoteExpr(Expr *p)
{
	if(ExprHasAnyProperty(p,EP_Dequoted))return;
	ExprSetProperty(p,EP_Dequoted);
	if(p->token.dyn==0)WN_SQL3TokenCopy(&p->token,&p->token);
	WN_SQL3Dequote((char*)p->token.z);
}
Expr *WN_SQL3ExprDup(Expr *p)
{
	if(p==0)return 0;
	Expr *pNew=WN_SQLMallocRaw(sizeof(*p));
	if(pNew==0)return 0;
	memcpy(pNew,p,sizeof(*pNew));
	if(p->token.z)
	{
		pNew->token.z=(u8*)WN_SQLStrNDup((char*)p->token.z,p->token.n);
		pNew->token.dyn=1;
	}
	pNew->span.z=0;
	pNew->pLeft=WN_SQL3ExprDup(p->pLeft);
	pNew->pRight=WN_SQL3ExprDup(p->pRight);
	pNew->pList=WN_SQL3ExprListDup(p->pList);
	pNew->pSelect=WN_SQL3SelectDup(p->pSelect);
	return pNew;
}
void WN_SQL3TokenCopy(Token *pTo,Token *pFrom)
{
	if(pTo->dyn)WN_SQL3FreeX((char*)pTo->z);
	if(pFrom->z)
	{
		pTo->n=pFrom->n;
		pTo->z=(u8*)WN_SQLStrNDup((char*)pFrom->z,pFrom->n);
		pTo->dyn=1;
	}
	else
		pTo->z=0;
}
ExprList *WN_SQL3ExprListDup(ExprList *p)
{
	ExprList *pNew;
	struct ExprList_item *pItem,*pOldItem;
	int i;
	if(p==0)return 0;
	pNew=WN_SQL3Malloc(sizeof(*pNew));
	if(pNew==0)return 0;
	pNew->nExpr=pNew->nAlloc=p->nExpr;
	pNew->a=pItem=WN_SQL3Malloc(p->nExpr*sizeof(p->a[0]));
	if(pItem==0)
	{
		WN_SQL3FreeX(pNew);
		return 0;
	}
	pOldItem=p->a;
	for(i=0;i<p->nExpr;i++,pItem++,pOldItem++)
	{
		Expr *pNewExpr,*pOldExpr;
		pItem->pExpr=pNewExpr=WN_SQL3ExprDup(pOldExpr=pOldItem->pExpr);
		if(pOldExpr->span.z && pNewExpr)WN_SQL3TokenCopy(&pNewExpr->span,&pOldExpr->span);
		pItem->zName=WN_SQLStrDup(pOldItem->zName);
		pItem->sortOrder=pOldItem->sortOrder;
		pItem->isAgg=pOldItem->isAgg;
		pItem->done=0;
	}
return pNew;
}
#if !defined(WN_SQL_OMIT_VIEW)|| !defined(WN_SQL_OMIT_TRIGGER)\
|| !defined(WN_SQL_OMIT_SUBQUERY)
SrcList *WN_SQL3SrcListDup(SrcList *p)
{
	if(p==0)return 0;
	int i,nByte;
	nByte=sizeof(*p)+(p->nSrc>0 ? sizeof(p->a[0])*(p->nSrc-1):0);
	SrcList *pNew=WN_SQLMallocRaw(nByte);
	if(pNew==0)return 0;
	pNew->nSrc=pNew->nAlloc=p->nSrc;
	for(i=0;i<p->nSrc;i++)
	{
		struct SrcList_item *pNewItem=&pNew->a[i],*pOldItem=&p->a[i];
		pNewItem->zDatabase=WN_SQLStrDup(pOldItem->zDatabase);
		pNewItem->zName=WN_SQLStrDup(pOldItem->zName);
		pNewItem->zAlias=WN_SQLStrDup(pOldItem->zAlias);
		pNewItem->jointype=pOldItem->jointype;
		pNewItem->iCursor=pOldItem->iCursor;
		pNewItem->isPopulated=pOldItem->isPopulated;
		Table *pTab=pNewItem->pTab=pOldItem->pTab;
		if(pTab)pTab->nRef++;
		pNewItem->pSelect=WN_SQL3SelectDup(pOldItem->pSelect);
		pNewItem->pOn=WN_SQL3ExprDup(pOldItem->pOn);
		pNewItem->pUsing=WN_SQL3IdListDup(pOldItem->pUsing);
		pNewItem->colUsed=pOldItem->colUsed;
	}
	return pNew;
}
IdList *WN_SQL3IdListDup(IdList *p)
{
	if(p==0)return 0;
	int i;
	IdList *pNew=WN_SQLMallocRaw(sizeof(*pNew));
	if(pNew==0)return 0;
	pNew->nId=pNew->nAlloc=p->nId;
	pNew->a=WN_SQLMallocRaw(p->nId*sizeof(p->a[0]));
	if(pNew->a==0)
	{
		WN_SQL3FreeX(pNew);
		return 0;
	}
	for(i=0;i<p->nId;i++)
	{
		struct IdList_item *pNewItem=&pNew->a[i];
		struct IdList_item *pOldItem=&p->a[i];
		pNewItem->zName=WN_SQLStrDup(pOldItem->zName);
		pNewItem->idx=pOldItem->idx;
	}
	return pNew;
}
Select *WN_SQL3SelectDup(Select *p)
{
	if(p==0)return 0;
	Select *pNew=WN_SQLMallocRaw(sizeof(*p));
	if(pNew==0)return 0;
	pNew->isDistinct=p->isDistinct;
	pNew->pEList=WN_SQL3ExprListDup(p->pEList);
	pNew->pSrc=WN_SQL3SrcListDup(p->pSrc);
	pNew->pWhere=WN_SQL3ExprDup(p->pWhere);
	pNew->pGroupBy=WN_SQL3ExprListDup(p->pGroupBy);
	pNew->pHaving=WN_SQL3ExprDup(p->pHaving);
	pNew->pOrderBy=WN_SQL3ExprListDup(p->pOrderBy);
	pNew->op=p->op;
	pNew->pPrior=WN_SQL3SelectDup(p->pPrior);
	pNew->pLimit=WN_SQL3ExprDup(p->pLimit);
	pNew->pOffset=WN_SQL3ExprDup(p->pOffset);
	pNew->iLimit=-1;
	pNew->iOffset=-1;
	pNew->isResolved=p->isResolved;
	pNew->isAgg=p->isAgg;
	pNew->usesEphm=0;
	pNew->disallowOrderBy=0;
	pNew->pRightmost=0;
	pNew->addrOpenEphm[0]=-1;
	pNew->addrOpenEphm[1]=-1;
	pNew->addrOpenEphm[2]=-1;
	return pNew;
}
#else
Select *WN_SQL3SelectDup(Select *p){
return 0;
}
#endif
ExprList *WN_SQL3ExprListAppend(ExprList *pList,Expr *pExpr,Token *pName)
{
	if(pList==0)
	{
		pList=WN_SQL3Malloc(sizeof(ExprList));
		if(pList==0)goto no_mem;
	}
	if(pList->nAlloc<=pList->nExpr)
	{
		struct ExprList_item *a;
		int n=pList->nAlloc*2+4;
		a=WN_SQLRealloc(pList->a,n*sizeof(pList->a[0]));
		if(a==0)goto no_mem;
		pList->a=a;
		pList->nAlloc=n;
	}
	if(pExpr || pName)
	{
		struct ExprList_item *pItem=&pList->a[pList->nExpr++];
		memset(pItem,0,sizeof(*pItem));
		pItem->zName=WN_SQL3NameFromToken(pName);
		pItem->pExpr=pExpr;
	}
	return pList;
no_mem:
	WN_SQL3ExprDelete(pExpr);
	WN_SQL3ExprListDelete(pList);
	return 0;
}
void WN_SQL3ExprListCheckLength(Parse *pParse,ExprList *pEList,int iLimit,const char *zObject)
{
	if(pEList && pEList->nExpr>iLimit)WN_SQL3ErrorMsg(pParse,"too many columns in %s",zObject);
}
#if WN_SQL_MAX_EXPR_DEPTH>0
void heightOfExpr(Expr *p,int *pnHeight)
{
	if(p&&p->nHeight>*pnHeight)*pnHeight=p->nHeight;
}
void heightOfExprList(ExprList *p,int *pnHeight)
{
	if(p)for(int i=0;i<p->nExpr;i++)heightOfExpr(p->a[i].pExpr,pnHeight);
}
void heightOfSelect(Select *p,int *pnHeight)
{
	if(p)
	{
		heightOfExpr(p->pWhere,pnHeight);
		heightOfExpr(p->pHaving,pnHeight);
		heightOfExpr(p->pLimit,pnHeight);
		heightOfExpr(p->pOffset,pnHeight);
		heightOfExprList(p->pEList,pnHeight);
		heightOfExprList(p->pGroupBy,pnHeight);
		heightOfExprList(p->pOrderBy,pnHeight);
		heightOfSelect(p->pPrior,pnHeight);
	}
}
void WN_SQL3ExprSetHeight(Expr *p)
{
	int nHeight=0;
	heightOfExpr(p->pLeft,&nHeight);
	heightOfExpr(p->pRight,&nHeight);
	heightOfExprList(p->pList,&nHeight);
	heightOfSelect(p->pSelect,&nHeight);
	p->nHeight=nHeight+1;
}
int WN_SQL3SelectExprHeight(Select *p)
{
	int nHeight=0;
	heightOfSelect(p,&nHeight);
	return nHeight;
}
#endif
void WN_SQL3ExprListDelete(ExprList *pList)
{
	int i;
	struct ExprList_item *pItem;
	if(pList==0)return;
	for(pItem=pList->a,i=0;i<pList->nExpr;i++,pItem++)
	{
		WN_SQL3ExprDelete(pItem->pExpr);
		WN_SQL3FreeX(pItem->zName);
	}
	WN_SQL3FreeX(pList->a);
	WN_SQL3FreeX(pList);
}
int walkExprList(ExprList *,int(*)(void *,Expr*),void *);
int walkExprTree(Expr *pExpr,int(*xFunc)(void*,Expr*),void *pArg)
{
	if(pExpr==0)return 0;
	int rc=(*xFunc)(pArg,pExpr);
	if(rc==0)
	{
		if(walkExprTree(pExpr->pLeft,xFunc,pArg))return 1;
		if(walkExprTree(pExpr->pRight,xFunc,pArg))return 1;
		if(walkExprList(pExpr->pList,xFunc,pArg))return 1;
	}
	return rc>1;
}
int walkExprList(ExprList *p,int(*xFunc)(void *,Expr*),void *pArg)
{
	int i;
	struct ExprList_item *pItem;
	if(!p)return 0;
	for(i=p->nExpr,pItem=p->a;i>0;i--,pItem++)if(walkExprTree(pItem->pExpr,xFunc,pArg))return 1;
	return 0;
}
int walkSelectExpr(Select *p,int(*xFunc)(void *,Expr*),void *pArg)
{
	walkExprList(p->pEList,xFunc,pArg);
	walkExprTree(p->pWhere,xFunc,pArg);
	walkExprList(p->pGroupBy,xFunc,pArg);
	walkExprTree(p->pHaving,xFunc,pArg);
	walkExprList(p->pOrderBy,xFunc,pArg);
	if(p->pPrior)walkSelectExpr(p->pPrior,xFunc,pArg);
	return 0;
}
int exprNodeIsConstant(void *pArg,Expr *pExpr)
{
	int *pN=(int*)pArg;
	if((*pN)==3 && ExprHasAnyProperty(pExpr,EP_FromJoin))
	{
		*pN=0;
		return 2;
	}
	switch(pExpr->op)
	{
	case TK_FUNCTION:
		if((*pN)==2)return 0;
	case TK_ID:
	case TK_COLUMN:
	case TK_DOT:
	case TK_AGG_FUNCTION:
	case TK_AGG_COLUMN:
#ifndef WN_SQL_OMIT_SUBQUERY
	case TK_SELECT:
	case TK_EXISTS:
#endif
		*pN=0;
		return 2;
	case TK_IN:
		if(pExpr->pSelect)
		{
			*pN=0;
			return 2;
		}
	default:
		return 0;
	}
}
int WN_SQL3ExprIsConstant(Expr *p)
{
	int isConst=1;
	walkExprTree(p,exprNodeIsConstant,&isConst);
	return isConst;
}
int WN_SQL3ExprIsConstantNotJoin(Expr *p)
{
	int isConst=3;
	walkExprTree(p,exprNodeIsConstant,&isConst);
	return isConst!=0;
}
int WN_SQL3ExprIsConstantOrFunction(Expr *p)
{
	int isConst=2;
	walkExprTree(p,exprNodeIsConstant,&isConst);
	return isConst!=0;
}
int WN_SQL3ExprIsInteger(Expr *p,int *pValue)
{
	switch(p->op)
	{
	case TK_INTEGER:
		if(WN_SQL3GetInt32((char*)p->token.z,pValue))return 1;
		break;
	case TK_UPLUS:
		return WN_SQL3ExprIsInteger(p->pLeft,pValue);
	case TK_UMINUS:
		int v;
		if(WN_SQL3ExprIsInteger(p->pLeft,&v))
		{
			*pValue=-v;
			return 1;
		}
	}
	return 0;
}
int WN_SQL3IsRowid(const char *z)
{
	return !(WN_SQL3StrICmp(z,"_ROWID_")&&WN_SQL3StrICmp(z,"ROWID")&&WN_SQL3StrICmp(z,"OID"));
}
int lookupName(Parse *pParse,Token *pDbToken,Token *pTableToken,Token *pColumnToken,NameContext *pNC,Expr *pExpr)
{
	char *zDb=0,*zTab=0,*zCol=0;
	int i,j,cnt=0,cntTab=0;
	WN_SQL3 *db=pParse->db;
	struct SrcList_item *pItem,SrcList_item *pMatch=0;
	NameContext *pTopNC=pNC;
	zDb=WN_SQL3NameFromToken(pDbToken);
	zTab=WN_SQL3NameFromToken(pTableToken);
	zCol=WN_SQL3NameFromToken(pColumnToken);
	if(WN_SQL3MallocFailed())goto lookupname_end;
	pExpr->iTable=-1;
	while(pNC && cnt==0)
	{
		ExprList *pEList;
		SrcList *pSrcList=pNC->pSrcList;
		if(pSrcList)
		{
			for(i=0,pItem=pSrcList->a;i<pSrcList->nSrc;i++,pItem++)
			{
				Column *pCol;
				Table *pTab=pItem->pTab;
				int iDb=WN_SQL3SchemaToIndex(db,pTab->pSchema);
				if(zTab)
				{
					if(pItem->zAlias)
					{
						char *zTabName=pItem->zAlias;
						if(WN_SQL3StrICmp(zTabName,zTab))continue;
					}
					else
					{
						char *zTabName=pTab->zName;
						if(zTabName==0 || WN_SQL3StrICmp(zTabName,zTab))continue;
						if(zDb && WN_SQL3StrICmp(db->aDb[iDb].zName,zDb))continue;
					}
				}
				if(0==(cntTab++))
				{
					pExpr->iTable=pItem->iCursor;
					pExpr->pSchema=pTab->pSchema;
					pMatch=pItem;
				}
				for(j=0,pCol=pTab->aCol;j<pTab->nCol;j++,pCol++)
				{
					if(WN_SQL3StrICmp(pCol->zName,zCol)==0)
					{
						const char *zColl=pTab->aCol[j].zColl;
						IdList *pUsing;
						cnt++;
						pExpr->iTable=pItem->iCursor;
						pMatch=pItem;
						pExpr->pSchema=pTab->pSchema;
						pExpr->iColumn=j==pTab->iPKey ?-1 :j;
						pExpr->affinity=pTab->aCol[j].affinity;
						if((pExpr->flags & EP_ExpCollate)==0)pExpr->pColl=WN_SQL3FindCollSeq(db,ENC(db),zColl,-1,0);
						if(i<pSrcList->nSrc-1)
						{
							if(pItem[1].jointype & JT_NATURAL)
							{
								pItem++;
								i++;
							}
							else
								if((pUsing=pItem[1].pUsing))
								{
									int k;
									for(k=0;k<pUsing->nId;k++)
									{
										if(WN_SQL3StrICmp(pUsing->a[k].zName,zCol)==0)
										{
											pItem++;
											i++;
											break;
										}
									}
								}
						}
						break;
					}
				}
			}
		}
#ifndef WN_SQL_OMIT_TRIGGER
		if(zDb==0 && zTab && cnt==0 && pParse->trigStack)
		{
			TriggerStack *pTriggerStack=pParse->trigStack;
			Table *pTab=0;
			if(pTriggerStack->newIdx!=-1 && WN_SQL3StrICmp("new",zTab)==0)
			{
				pExpr->iTable=pTriggerStack->newIdx;
				pTab=pTriggerStack->pTab;
			}
			else
				if(pTriggerStack->oldIdx!=-1 && WN_SQL3StrICmp("old",zTab)==0)
				{
					pExpr->iTable=pTriggerStack->oldIdx;
					pTab=pTriggerStack->pTab;
				}
				if(pTab)
				{
					int iCol;
					Column *pCol=pTab->aCol;
					pExpr->pSchema=pTab->pSchema;
					cntTab++;
					for(iCol=0;iCol<pTab->nCol;iCol++,pCol++)
					{
						if(WN_SQL3StrICmp(pCol->zName,zCol)==0)
						{
							const char *zColl=pTab->aCol[iCol].zColl;
							cnt++;
							pExpr->iColumn=iCol==pTab->iPKey ?-1 :iCol;
							pExpr->affinity=pTab->aCol[iCol].affinity;
							if((pExpr->flags & EP_ExpCollate)==0)
								pExpr->pColl=WN_SQL3FindCollSeq(db,ENC(db),zColl,-1,0);
							pExpr->pTab=pTab;
							break;
						}
					}
				}
		}
#endif
		if(cnt==0 && cntTab==1 && WN_SQL3IsRowid(zCol))
		{
			cnt=1;
			pExpr->iColumn=-1;
			pExpr->affinity=WN_SQL_AFF_INTEGER;
		}
		if(cnt==0 &&(pEList=pNC->pEList)&& zTab==0)
		{
			for(j=0;j<pEList->nExpr;j++)
			{
				char *zAs=pEList->a[j].zName;
				if(zAs && WN_SQL3StrICmp(zAs,zCol)==0)
				{
					Expr *pDup=WN_SQL3ExprDup(pEList->a[j].pExpr);
					if(pExpr->flags & EP_ExpCollate)
					{
						pDup->pColl=pExpr->pColl;
						pDup->flags |=EP_ExpCollate;
					}
					if(pExpr->span.dyn)WN_SQL3FreeX((char*)pExpr->span.z);
					if(pExpr->token.dyn)WN_SQL3FreeX((char*)pExpr->token.z);
					memcpy(pExpr,pDup,sizeof(*pExpr));
					WN_SQL3FreeX(pDup);
					cnt=1;
					pMatch=0;
					goto lookupname_end_2;
				}
			}
		}
		if(cnt==0)pNC=pNC->pNext;
	}
	if(cnt==0 && zTab==0 && pColumnToken->z[0]=='"')
	{
		WN_SQL3FreeX(zCol);
		return 0;
	}
	if(cnt!=1)
	{
		char *z=0,*zErr=cnt==0 ? "no such column:%s" :"ambiguous column name:%s";
		if(zDb)
			WN_SQL3SetString(&z,zDb,".",zTab,".",zCol,(char*)0);
		else
			if(zTab)
				WN_SQL3SetString(&z,zTab,".",zCol,(char*)0);
			else
				z=WN_SQLStrDup(zCol);
		WN_SQL3ErrorMsg(pParse,zErr,z);
		WN_SQL3FreeX(z);
		pTopNC->nErr++;
	}
	if(pExpr->iColumn>=0 && pMatch)
	{
		int n=pExpr->iColumn;
		if(n>=sizeof(Bitmask)*8)n=sizeof(Bitmask)*8-1;
		pMatch->colUsed |=((Bitmask)1)<<n;
	}
lookupname_end:
	WN_SQL3FreeX(zDb);
	WN_SQL3FreeX(zTab);
	WN_SQL3ExprDelete(pExpr->pLeft);
	pExpr->pLeft=0;
	WN_SQL3ExprDelete(pExpr->pRight);
	pExpr->pRight=0;
	pExpr->op=TK_COLUMN;
lookupname_end_2:
	WN_SQL3FreeX(zCol);
	if(cnt==1)
	{
		WN_SQL3AuthRead(pParse,pExpr,pNC->pSrcList);
		if(pMatch && !pMatch->pSelect)pExpr->pTab=pMatch->pTab;
		for(;;)
		{
			pTopNC->nRef++;
			if(pTopNC==pNC)break;
			pTopNC=pTopNC->pNext;
		}
		return 0;
	}
	else
		return 1;
}
int nameResolverStep(void *pArg,Expr *pExpr)
{
	NameContext *pNC=(NameContext*)pArg;
	Parse *pParse;
	if(pExpr==0)return 1;
	pParse=pNC->pParse;
	if(ExprHasAnyProperty(pExpr,EP_Resolved))return 1;
	ExprSetProperty(pExpr,EP_Resolved);
#ifndef NDEBUG
	if(pNC->pSrcList && pNC->pSrcList->nAlloc>0)
	{
		SrcList *pSrcList=pNC->pSrcList;
		int i;
		for(i=0;i<pNC->pSrcList->nSrc;i++);
	}
#endif
	switch(pExpr->op)
	{
	case TK_STRING:
		if(pExpr->token.z[0]=='\'')break;
	case TK_ID:
		lookupName(pParse,0,0,&pExpr->token,pNC,pExpr);
		return 1;
	case TK_DOT:
		Token *pColumn,*pTable,*pDb;
		Expr *pRight;
		pRight=pExpr->pRight;
		if(pRight->op==TK_ID)
		{
			pDb=0;
			pTable=&pExpr->pLeft->token;
			pColumn=&pRight->token;
		}
		else
		{
			pDb=&pExpr->pLeft->token;
			pTable=&pRight->pLeft->token;
			pColumn=&pRight->pRight->token;
		}
		lookupName(pParse,pDb,pTable,pColumn,pNC,pExpr);
		return 1;
	case TK_CONST_FUNC:
	case TK_FUNCTION:
		ExprList *pList=pExpr->pList;
		int n=pList ? pList->nExpr :0,no_such_func=0,wrong_num_args=0,is_agg=0,
			i,auth,nId;
		const char *zId;
		FuncDef *pDef;
		int enc=ENC(pParse->db);
		zId=(char*)pExpr->token.z;
		nId=pExpr->token.n;
		pDef=WN_SQL3FindFunction(pParse->db,zId,nId,n,enc,0);
		if(pDef==0)
		{
			pDef=WN_SQL3FindFunction(pParse->db,zId,nId,-1,enc,0);
			if(pDef==0)
				no_such_func=1;
			else
				wrong_num_args=1;
		}
		else
			is_agg=pDef->xFunc==0;
#ifndef WN_SQL_OMIT_AUTHORIZATION
		if(pDef)
		{
			auth=WN_SQL3AuthCheck(pParse,WN_SQL_FUNCTION,0,pDef->zName,0);
			if(auth)
			{
				if(auth==WN_SQL_DENY)
				{
					WN_SQL3ErrorMsg(pParse,"not authorized to use function:%s",pDef->zName);
					pNC->nErr++;
				}
				pExpr->op=TK_NULL;
				return 1;
			}
		}
#endif
		if(is_agg && !pNC->allowAgg)
		{
			WN_SQL3ErrorMsg(pParse,"misuse of aggregate function %.*s()",nId,zId);
			pNC->nErr++;
			is_agg=0;
		}
		else
			if(no_such_func)
			{
				WN_SQL3ErrorMsg(pParse,"no such function:%.*s",nId,zId);
				pNC->nErr++;
			}
			else
				if(wrong_num_args)
				{
					WN_SQL3ErrorMsg(pParse,"wrong number of arguments to function %.*s()",nId,zId);
					pNC->nErr++;
				}
		if(is_agg)
		{
			pExpr->op=TK_AGG_FUNCTION;
			pNC->hasAgg=1;
		}
		if(is_agg)pNC->allowAgg=0;
		for(i=0;pNC->nErr==0 && i<n;i++)
			walkExprTree(pList->a[i].pExpr,nameResolverStep,pNC);
		if(is_agg)pNC->allowAgg=1;
		return is_agg;
#ifndef WN_SQL_OMIT_SUBQUERY
	case TK_SELECT:
	case TK_EXISTS:
#endif
	case TK_IN:
		if(pExpr->pSelect)
		{
			int nRef=pNC->nRef;
#ifndef WN_SQL_OMIT_CHECK
			if(pNC->isCheck)WN_SQL3ErrorMsg(pParse,"subqueries prohibited in CHECK constraints");
#endif
			WN_SQL3SelectResolve(pParse,pExpr->pSelect,pNC);
			if(nRef!=pNC->nRef)ExprSetProperty(pExpr,EP_VarSelect);
		}
		break;
#ifndef WN_SQL_OMIT_CHECK
	case TK_VARIABLE:
		if(pNC->isCheck)
			WN_SQL3ErrorMsg(pParse,"parameters prohibited in CHECK constraints");
		break;
#endif
	}
	return 0;
}
int WN_SQL3ExprResolveNames(NameContext *pNC,Expr *pExpr)
{
	int savedHasAgg;
	if(pExpr==0)return 0;
#if WN_SQL_MAX_EXPR_DEPTH>0
	if((pExpr->nHeight+pNC->pParse->nHeight)>WN_SQL_MAX_EXPR_DEPTH)
	{
		WN_SQL3ErrorMsg(pNC->pParse,"Expression tree is too large(maximum depth %d)",WN_SQL_MAX_EXPR_DEPTH);
		return 1;
	}
	pNC->pParse->nHeight+=pExpr->nHeight;
#endif
	savedHasAgg=pNC->hasAgg;
	pNC->hasAgg=0;
	walkExprTree(pExpr,nameResolverStep,pNC);
#if WN_SQL_MAX_EXPR_DEPTH>0
	pNC->pParse->nHeight-=pExpr->nHeight;
#endif
	if(pNC->nErr>0)ExprSetProperty(pExpr,EP_Error);
	if(pNC->hasAgg)
		ExprSetProperty(pExpr,EP_Agg);
	else
		if(savedHasAgg)pNC->hasAgg=1;
	return ExprHasProperty(pExpr,EP_Error);
}
typedef struct QueryCoder QueryCoder;
struct QueryCoder
{
	Parse *pParse;
	NameContext *pNC;
};
#ifndef WN_SQL_OMIT_SUBQUERY
void WN_SQL3CodeSubselect(Parse *pParse,Expr *pExpr)
{
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v==0)return;
	int testAddr=0;
	if(!ExprHasAnyProperty(pExpr,EP_VarSelect)&& !pParse->trigStack)
	{
		int mem=pParse->nMem++;
		WN_SQL3VdbeAddOp(v,OP_MemLoad,mem,0);
		testAddr=WN_SQL3VdbeAddOp(v,OP_If,0,0);
		WN_SQL3VdbeAddOp(v,OP_MemInt,1,mem);
	}
	switch(pExpr->op)
	{
	case TK_IN:
		KeyInfo keyInfo;
		char affinity=WN_SQL3ExprAffinity(pExpr->pLeft);
		pExpr->iTable=pParse->nTab++;
		int addr=WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,pExpr->iTable,0);
		memset(&keyInfo,0,sizeof(keyInfo));
		keyInfo.nField=1;
		WN_SQL3VdbeAddOp(v,OP_SetNumColumns,pExpr->iTable,1);
		if(pExpr->pSelect)
		{
			int iParm=pExpr->iTable+(((int)affinity)<<16);
			ExprList *pEList;
			if(WN_SQL3Select(pParse,pExpr->pSelect,SRT_Set,iParm,0,0,0,0))return;
			pEList=pExpr->pSelect->pEList;
			if(pEList && pEList->nExpr>0)keyInfo.aColl[0]=WN_SQL3BinaryCompareCollSeq(pParse,pExpr->pLeft,pEList->a[0].pExpr);
		}
		else
			if(pExpr->pList)
			{
				int i;
				ExprList *pList=pExpr->pList;
				struct ExprList_item *pItem;
				if(!affinity)affinity=WN_SQL_AFF_NONE;
				keyInfo.aColl[0]=pExpr->pLeft->pColl;
				for(i=pList->nExpr,pItem=pList->a;i>0;i--,pItem++)
				{
					Expr *pE2=pItem->pExpr;
					if(testAddr>0 && !WN_SQL3ExprIsConstant(pE2))
					{
						WN_SQL3VdbeChangeToNoop(v,testAddr-1,3);
						testAddr=0;
					}
					WN_SQL3ExprCode(pParse,pE2);
					WN_SQL3VdbeOp3(v,OP_MakeRecord,1,0,&affinity,1);
					WN_SQL3VdbeAddOp(v,OP_IdxInsert,pExpr->iTable,0);
				}
			}
			WN_SQL3VdbeChangeP3(v,addr,(void *)&keyInfo,P3_KEYINFO);
			break;
	case TK_EXISTS:
	case TK_SELECT:
		const Token one={(u8*)"1",0,1};
		int iMem;
		int sop;
		pExpr->iColumn=iMem=pParse->nMem++;
		Select *pSel=pExpr->pSelect;
		if(pExpr->op==TK_SELECT)
		{
			sop=SRT_Mem;
			WN_SQL3VdbeAddOp(v,OP_MemNull,iMem,0);
			VdbeComment((v,"# Init subquery result"));
		}
		else
		{
			sop=SRT_Exists;
			WN_SQL3VdbeAddOp(v,OP_MemInt,0,iMem);
			VdbeComment((v,"# Init EXISTS result"));
		}
		WN_SQL3ExprDelete(pSel->pLimit);
		pSel->pLimit=WN_SQL3Expr(TK_INTEGER,0,0,&one);
		if(WN_SQL3Select(pParse,pSel,sop,iMem,0,0,0,0))return;
		break;
	}
	if(testAddr)WN_SQL3VdbeJumpHere(v,testAddr);return;
}
#endif
void codeInteger(Vdbe *v,const char *z,int n)
{
	if(z)
	{
		int i;
		if(WN_SQL3GetInt32(z,&i))
			WN_SQL3VdbeAddOp(v,OP_Integer,i,0);
		else
			if(WN_SQL3FitsIn64Bits(z))
				WN_SQL3VdbeOp3(v,OP_Int64,0,0,z,n);
			else
				WN_SQL3VdbeOp3(v,OP_Real,0,0,z,n);
	}
}
void WN_SQL3ExprCodeGetColumn(Vdbe *v,Table *pTab,int iColumn,int iTable)
{
	if(iColumn<0)
	{
		int op=(pTab && IsVirtual(pTab))? OP_VRowid :OP_Rowid;
		WN_SQL3VdbeAddOp(v,op,iTable,0);
	}
	else
		if(pTab==0)
			WN_SQL3VdbeAddOp(v,OP_Column,iTable,iColumn);
		else
		{
			int op=IsVirtual(pTab)? OP_VColumn :OP_Column;
			WN_SQL3VdbeAddOp(v,op,iTable,iColumn);
			WN_SQL3ColumnDefault(v,pTab,iColumn);
#ifndef WN_SQL_OMIT_FLOATING_POINT
			if(pTab->aCol[iColumn].affinity==WN_SQL_AFF_REAL)
				WN_SQL3VdbeAddOp(v,OP_RealAffinity,0,0);
#endif
		}
}
void WN_SQL3ExprCode(Parse *pParse,Expr *pExpr)
{
	Vdbe *v=pParse->pVdbe;
	if(v==0)return;
	int op,stackChng=1;
	if(pExpr==0)
	{
		WN_SQL3VdbeAddOp(v,OP_Null,0,0);
		return;
	}
	op=pExpr->op;
	switch(op)
	{
	case TK_AGG_COLUMN:
		AggInfo *pAggInfo=pExpr->pAggInfo;
		struct AggInfo_col *pCol=&pAggInfo->aCol[pExpr->iAgg];
		if(!pAggInfo->directMode)
		{
			WN_SQL3VdbeAddOp(v,OP_MemLoad,pCol->iMem,0);
			break;
		}
		else
			if(pAggInfo->useSortingIdx)
			{
				WN_SQL3VdbeAddOp(v,OP_Column,pAggInfo->sortingIdx,pCol->iSorterColumn);
				break;
			}
case TK_COLUMN:
	if(pExpr->iTable<0)
		WN_SQL3VdbeAddOp(v,OP_Dup,pParse->ckOffset-pExpr->iColumn-1,1);
	else
		WN_SQL3ExprCodeGetColumn(v,pExpr->pTab,pExpr->iColumn,pExpr->iTable);
	break;
	case TK_INTEGER:
		codeInteger(v,(char*)pExpr->token.z,pExpr->token.n);
		break;
	case TK_FLOAT:
	case TK_STRING:
		WN_SQL3DequoteExpr(pExpr);
		WN_SQL3VdbeOp3(v,op,0,0,(char*)pExpr->token.z,pExpr->token.n);
		break;
	case TK_NULL:
		WN_SQL3VdbeAddOp(v,OP_Null,0,0);
		break;
#ifndef WN_SQL_OMIT_BLOB_LITERAL
	case TK_BLOB:
		int n;
		const char *z;
		n=pExpr->token.n-3;
		z=(char*)pExpr->token.z+2;
		if(n==0)z="";
		WN_SQL3VdbeOp3(v,op,0,0,z,n);
		break;
#endif
	case TK_VARIABLE:
		WN_SQL3VdbeAddOp(v,OP_Variable,pExpr->iTable,0);
		if(pExpr->token.n>1)WN_SQL3VdbeChangeP3(v,-1,(char*)pExpr->token.z,pExpr->token.n);
		break;
	case TK_REGISTER:
		WN_SQL3VdbeAddOp(v,OP_MemLoad,pExpr->iTable,0);
		break;
#ifndef WN_SQL_OMIT_CAST
	case TK_CAST:
		int aff,to_op;
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		aff=WN_SQL3AffinityType(&pExpr->token);
		to_op=aff-WN_SQL_AFF_TEXT+OP_ToText;
		WN_SQL3VdbeAddOp(v,to_op,0,0);
		stackChng=0;
		break;
#endif
	case TK_LT:
	case TK_LE:
	case TK_GT:
	case TK_GE:
	case TK_NE:
	case TK_EQ:
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		WN_SQL3ExprCode(pParse,pExpr->pRight);
		codeCompare(pParse,pExpr->pLeft,pExpr->pRight,op,0,0);
		stackChng=-1;
		break;
	case TK_AND:
	case TK_OR:
	case TK_PLUS:
	case TK_STAR:
	case TK_MINUS:
	case TK_REM:
	case TK_BITAND:
	case TK_BITOR:
	case TK_SLASH:
	case TK_LSHIFT:
	case TK_RSHIFT:
	case TK_CONCAT:
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		WN_SQL3ExprCode(pParse,pExpr->pRight);
		WN_SQL3VdbeAddOp(v,op,0,0);
		stackChng=-1;
		break;
	case TK_UMINUS:
		Expr *pLeft=pExpr->pLeft;
		if(pLeft->op==TK_FLOAT || pLeft->op==TK_INTEGER)
		{
			Token *p=&pLeft->token;
			char *z=WN_SQL3MPrintf("-%.*s",p->n,p->z);
			if(pLeft->op==TK_FLOAT)
				WN_SQL3VdbeOp3(v,OP_Real,0,0,z,p->n+1);
			else
				codeInteger(v,z,p->n+1);
			WN_SQL3FreeX(z);
			break;
		}
	case TK_BITNOT:
	case TK_NOT:
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		WN_SQL3VdbeAddOp(v,op,0,0);
		stackChng=0;
		break;
	case TK_ISNULL:
	case TK_NOTNULL:
		int dest;
		WN_SQL3VdbeAddOp(v,OP_Integer,1,0);
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		dest=WN_SQL3VdbeCurrentAddr(v)+2;
		WN_SQL3VdbeAddOp(v,op,1,dest);
		WN_SQL3VdbeAddOp(v,OP_AddImm,-1,0);
		stackChng=0;
		break;
	case TK_AGG_FUNCTION:{
		AggInfo *pInfo=pExpr->pAggInfo;
		if(pInfo==0)
			WN_SQL3ErrorMsg(pParse,"misuse of aggregate:%T",&pExpr->span);
		else
			WN_SQL3VdbeAddOp(v,OP_MemLoad,pInfo->aFunc[pExpr->iAgg].iMem,0);
		break;
	case TK_CONST_FUNC:
	case TK_FUNCTION:
		ExprList *pList=pExpr->pList;
		int nExpr=pList ? pList->nExpr :0;
		FuncDef *pDef;
		int nId,constMask=0,i;
		const char *zId;
		u8 enc=ENC(pParse->db);
		CollSeq *pColl=0;
		zId=(char*)pExpr->token.z;
		nId=pExpr->token.n;
		pDef=WN_SQL3FindFunction(pParse->db,zId,nId,nExpr,enc,0);
		nExpr=WN_SQL3ExprCodeExprList(pParse,pList);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		if(nExpr>=2 &&(pExpr->flags & EP_InfixFunc))
			pDef=WN_SQL3VtabOverloadFunction(pDef,nExpr,pList->a[1].pExpr);
		else
			if(nExpr>0)pDef=WN_SQL3VtabOverloadFunction(pDef,nExpr,pList->a[0].pExpr);
#endif
		for(i=0;i<nExpr && i<32;i++)
		{
			if(WN_SQL3ExprIsConstant(pList->a[i].pExpr))constMask |=(1<<i);
			if(pDef->needCollSeq && !pColl)pColl=WN_SQL3ExprCollSeq(pParse,pList->a[i].pExpr);
		}
		if(pDef->needCollSeq)
		{
			if(!pColl)pColl=pParse->db->pDfltColl;
			WN_SQL3VdbeOp3(v,OP_CollSeq,0,0,(char *)pColl,P3_COLLSEQ);
		}
		WN_SQL3VdbeOp3(v,OP_Function,constMask,nExpr,(char*)pDef,P3_FUNCDEF);
		stackChng=1-nExpr;
		break;
#ifndef WN_SQL_OMIT_SUBQUERY
	case TK_EXISTS:
	case TK_SELECT:
		if(pExpr->iColumn==0)WN_SQL3CodeSubselect(pParse,pExpr);
		WN_SQL3VdbeAddOp(v,OP_MemLoad,pExpr->iColumn,0);
		VdbeComment((v,"# load subquery result"));
		break;
	case TK_IN:
		int addr;
		char affinity;
		int ckOffset=pParse->ckOffset;
		WN_SQL3CodeSubselect(pParse,pExpr);
		affinity=comparisonAffinity(pExpr);
		WN_SQL3VdbeAddOp(v,OP_Integer,1,0);
		pParse->ckOffset=(ckOffset ?(ckOffset+1):0);
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		addr=WN_SQL3VdbeCurrentAddr(v);
		WN_SQL3VdbeAddOp(v,OP_NotNull,-1,addr+4);
		WN_SQL3VdbeAddOp(v,OP_Pop,2,0);
		WN_SQL3VdbeAddOp(v,OP_Null,0,0);
		WN_SQL3VdbeAddOp(v,OP_Goto,0,addr+7);
		WN_SQL3VdbeOp3(v,OP_MakeRecord,1,0,&affinity,1);
		WN_SQL3VdbeAddOp(v,OP_Found,pExpr->iTable,addr+7);
		WN_SQL3VdbeAddOp(v,OP_AddImm,-1,0);
		break;
#endif
	case TK_BETWEEN:
		Expr *pLeft=pExpr->pLeft;
		struct ExprList_item *pLItem=pExpr->pList->a;
		Expr *pRight=pLItem->pExpr;
		WN_SQL3ExprCode(pParse,pLeft);
		WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
		WN_SQL3ExprCode(pParse,pRight);
		codeCompare(pParse,pLeft,pRight,OP_Ge,0,0);
		WN_SQL3VdbeAddOp(v,OP_Pull,1,0);
		pLItem++;
		pRight=pLItem->pExpr;
		WN_SQL3ExprCode(pParse,pRight);
		codeCompare(pParse,pLeft,pRight,OP_Le,0,0);
		WN_SQL3VdbeAddOp(v,OP_And,0,0);
		break;
	case TK_UPLUS:
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		stackChng=0;
		break;
	case TK_CASE:
		int expr_end_label,jumpInst,nExpr,i;
		ExprList *pEList;
		struct ExprList_item *aListelem;
		pEList=pExpr->pList;
		aListelem=pEList->a;
		nExpr=pEList->nExpr;
		expr_end_label=WN_SQL3VdbeMakeLabel(v);
		if(pExpr->pLeft)WN_SQL3ExprCode(pParse,pExpr->pLeft);
		for(i=0;i<nExpr;i=i+2)
		{
			WN_SQL3ExprCode(pParse,aListelem[i].pExpr);
			if(pExpr->pLeft)
			{
				WN_SQL3VdbeAddOp(v,OP_Dup,1,1);
				jumpInst=codeCompare(pParse,pExpr->pLeft,aListelem[i].pExpr,OP_Ne,0,1);
				WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
			}
			else
				jumpInst=WN_SQL3VdbeAddOp(v,OP_IfNot,1,0);
			WN_SQL3ExprCode(pParse,aListelem[i+1].pExpr);
			WN_SQL3VdbeAddOp(v,OP_Goto,0,expr_end_label);
			WN_SQL3VdbeJumpHere(v,jumpInst);
		}
		if(pExpr->pLeft)WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
		if(pExpr->pRight)
			WN_SQL3ExprCode(pParse,pExpr->pRight);
		else
			WN_SQL3VdbeAddOp(v,OP_Null,0,0);
		WN_SQL3VdbeResolveLabel(v,expr_end_label);
		break;
#ifndef WN_SQL_OMIT_TRIGGER
	case TK_RAISE:
		if(!pParse->trigStack)
		{
			WN_SQL3ErrorMsg(pParse,"RAISE()may only be used within a trigger-program");
			return;
		}
		if(pExpr->iColumn!=OE_Ignore)
		{
			pExpr->iColumn==OE_Abort ||pExpr->iColumn==OE_Fail);
			WN_SQL3DequoteExpr(pExpr);
			WN_SQL3VdbeOp3(v,OP_Halt,WN_SQL_CONSTRAINT,pExpr->iColumn,(char*)pExpr->token.z,pExpr->token.n);
		}
		else
		{
			WN_SQL3VdbeAddOp(v,OP_ContextPop,0,0);
			WN_SQL3VdbeAddOp(v,OP_Goto,0,pParse->trigStack->ignoreJump);
			VdbeComment((v,"# raise(IGNORE)"));
		}
		stackChng=0;
		break;
#endif
	}
	if(pParse->ckOffset)pParse->ckOffset+=stackChng;
}
#ifndef WN_SQL_OMIT_TRIGGER
void WN_SQL3ExprCodeAndCache(Parse *pParse,Expr *pExpr)
{
	Vdbe *v=pParse->pVdbe;
	if(v==0)return;
	int addr1=WN_SQL3VdbeCurrentAddr(v),addr2=WN_SQL3VdbeCurrentAddr(v);
	WN_SQL3ExprCode(pParse,pExpr);
	if(addr2>addr1+1 || WN_SQL3VdbeGetOp(v,addr1)->opcode==OP_Function)
	{
		int iMem=pExpr->iTable=pParse->nMem++;
		WN_SQL3VdbeAddOp(v,OP_MemStore,iMem,0);
		pExpr->op=TK_REGISTER;
	}
}
#endif
int WN_SQL3ExprCodeExprList(Parse *pParse,ExprList *pList)
{
	if(pList==0)return 0;
	struct ExprList_item *pItem;
	int i,n=pList->nExpr;
	for(pItem=pList->a,i=n;i>0;i--,pItem++)WN_SQL3ExprCode(pParse,pItem->pExpr);
	return n;
}
void WN_SQL3ExprIfTrue(Parse *pParse,Expr *pExpr,int dest,int jumpIfNull)
{
	Vdbe *v=pParse->pVdbe;
	if(v==0 || pExpr==0)return;
	int op=pExpr->op,ckOffset=pParse->ckOffset;
	switch(op)
	{
	case TK_AND:
		int d2=WN_SQL3VdbeMakeLabel(v);
		WN_SQL3ExprIfFalse(pParse,pExpr->pLeft,d2,!jumpIfNull);
		WN_SQL3ExprIfTrue(pParse,pExpr->pRight,dest,jumpIfNull);
		WN_SQL3VdbeResolveLabel(v,d2);
		break;
	case TK_OR:
		WN_SQL3ExprIfTrue(pParse,pExpr->pLeft,dest,jumpIfNull);
		WN_SQL3ExprIfTrue(pParse,pExpr->pRight,dest,jumpIfNull);
		break;
	case TK_NOT:
		WN_SQL3ExprIfFalse(pParse,pExpr->pLeft,dest,jumpIfNull);
		break;
	case TK_LT:
	case TK_LE:
	case TK_GT:
	case TK_GE:
	case TK_NE:
	case TK_EQ:
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		WN_SQL3ExprCode(pParse,pExpr->pRight);
		codeCompare(pParse,pExpr->pLeft,pExpr->pRight,op,dest,jumpIfNull);
		break;
	case TK_ISNULL:
	case TK_NOTNULL:
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		WN_SQL3VdbeAddOp(v,op,1,dest);
		break;
	case TK_BETWEEN:
		Expr *pLeft=pExpr->pLeft,*pRight=pExpr->pList->a[0].pExpr;
		WN_SQL3ExprCode(pParse,pLeft);
		WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
		WN_SQL3ExprCode(pParse,pRight);
		int addr=codeCompare(pParse,pLeft,pRight,OP_Lt,0,!jumpIfNull);
		pRight=pExpr->pList->a[1].pExpr;
		WN_SQL3ExprCode(pParse,pRight);
		codeCompare(pParse,pLeft,pRight,OP_Le,dest,jumpIfNull);
		WN_SQL3VdbeAddOp(v,OP_Integer,0,0);
		WN_SQL3VdbeJumpHere(v,addr);
		WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
		break;
	default:
		WN_SQL3ExprCode(pParse,pExpr);
		WN_SQL3VdbeAddOp(v,OP_If,jumpIfNull,dest);
	}
	pParse->ckOffset=ckOffset;
}
void WN_SQL3ExprIfFalse(Parse *pParse,Expr *pExpr,int dest,int jumpIfNull)
{
	Vdbe *v=pParse->pVdbe;
	if(v==0 || pExpr==0)return;
	int op=((pExpr->op+(TK_ISNULL&1))^1)-(TK_ISNULL&1),ckOffset=pParse->ckOffset;
	switch(pExpr->op)
	{
	case TK_AND:
		WN_SQL3ExprIfFalse(pParse,pExpr->pLeft,dest,jumpIfNull);
		WN_SQL3ExprIfFalse(pParse,pExpr->pRight,dest,jumpIfNull);
		break;
	case TK_OR:
		int d2=WN_SQL3VdbeMakeLabel(v);
		WN_SQL3ExprIfTrue(pParse,pExpr->pLeft,d2,!jumpIfNull);
		WN_SQL3ExprIfFalse(pParse,pExpr->pRight,dest,jumpIfNull);
		WN_SQL3VdbeResolveLabel(v,d2);
		break;
	case TK_NOT:
		WN_SQL3ExprIfTrue(pParse,pExpr->pLeft,dest,jumpIfNull);
		break;
	case TK_LT:
	case TK_LE:
	case TK_GT:
	case TK_GE:
	case TK_NE:
	case TK_EQ:
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		WN_SQL3ExprCode(pParse,pExpr->pRight);
		codeCompare(pParse,pExpr->pLeft,pExpr->pRight,op,dest,jumpIfNull);
		break;
	case TK_ISNULL:
	case TK_NOTNULL:
		WN_SQL3ExprCode(pParse,pExpr->pLeft);
		WN_SQL3VdbeAddOp(v,op,1,dest);
		break;
	case TK_BETWEEN:
		int addr;
		Expr *pLeft=pExpr->pLeft,*pRight=pExpr->pList->a[0].pExpr;
		WN_SQL3ExprCode(pParse,pLeft);
		WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
		WN_SQL3ExprCode(pParse,pRight);
		addr=WN_SQL3VdbeCurrentAddr(v);
		codeCompare(pParse,pLeft,pRight,OP_Ge,addr+3,!jumpIfNull);
		WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
		WN_SQL3VdbeAddOp(v,OP_Goto,0,dest);
		pRight=pExpr->pList->a[1].pExpr;
		WN_SQL3ExprCode(pParse,pRight);
		codeCompare(pParse,pLeft,pRight,OP_Gt,dest,jumpIfNull);
		break;
	default:
		WN_SQL3ExprCode(pParse,pExpr);
		WN_SQL3VdbeAddOp(v,OP_IfNot,jumpIfNull,dest);
	}
	pParse->ckOffset=ckOffset;
}
int WN_SQL3ExprCompare(Expr *pA,Expr *pB)
{
	if(pA==0||pB==0)return pB==pA;
	if(pA->op!=pB->op)return 0;
	int i;
	if((pA->flags & EP_Distinct)!=(pB->flags & EP_Distinct))return 0;
	if(!WN_SQL3ExprCompare(pA->pLeft,pB->pLeft))return 0;
	if(!WN_SQL3ExprCompare(pA->pRight,pB->pRight))return 0;
	if(pA->pList)
	{
		if(pB->pList==0)return 0;
		if(pA->pList->nExpr!=pB->pList->nExpr)return 0;
		for(i=0;i<pA->pList->nExpr;i++)
		{
			if(!WN_SQL3ExprCompare(pA->pList->a[i].pExpr,pB->pList->a[i].pExpr))return 0;
		}
	}
	else
		if(pB->pList)return 0;
	if(pA->pSelect || pB->pSelect)return 0;
	if(pA->iTable!=pB->iTable || pA->iColumn!=pB->iColumn)return 0;
	if(pA->op!=TK_COLUMN && pA->token.z)
	{
		if(pB->token.z==0)return 0;
		if(pB->token.n!=pA->token.n)return 0;
		if(WN_SQL3StrNICmp((char*)pA->token.z,(char*)pB->token.z,pB->token.n))return 0;
	}
	return 1;
}
int addAggInfoColumn(AggInfo *pInfo)
{
	int i;
	pInfo->aCol=WN_SQL3ArrayAllocate(pInfo->aCol,sizeof(pInfo->aCol[0]),3,&pInfo->nColumn,&pInfo->nColumnAlloc,&i);
	return i;
}
int addAggInfoFunc(AggInfo *pInfo)
{
	int i;
	pInfo->aFunc=WN_SQL3ArrayAllocate(pInfo->aFunc,sizeof(pInfo->aFunc[0]),3,&pInfo->nFunc,&pInfo->nFuncAlloc,&i);
	return i;
}
int analyzeAggregate(void *pArg,Expr *pExpr)
{
	int i;
	NameContext *pNC=(NameContext *)pArg;
	Parse *pParse=pNC->pParse;
	SrcList *pSrcList=pNC->pSrcList;
	AggInfo *pAggInfo=pNC->pAggInfo;
	switch(pExpr->op)
	{
	case TK_AGG_COLUMN:
	case TK_COLUMN:
		if(pSrcList)
		{
			struct SrcList_item *pItem=pSrcList->a;
			for(i=0;i<pSrcList->nSrc;i++,pItem++)
			{
				struct AggInfo_col *pCol;
				if(pExpr->iTable==pItem->iCursor)
				{
					int k;
					pCol=pAggInfo->aCol;
					for(k=0;k<pAggInfo->nColumn;k++,pCol++)
						if(pCol->iTable==pExpr->iTable && pCol->iColumn==pExpr->iColumn)break;
					if(k>=pAggInfo->nColumn &&(k=addAggInfoColumn(pAggInfo))>=0)
					{
						pCol=&pAggInfo->aCol[k];
						pCol->pTab=pExpr->pTab;
						pCol->iTable=pExpr->iTable;
						pCol->iColumn=pExpr->iColumn;
						pCol->iMem=pParse->nMem++;
						pCol->iSorterColumn=-1;
						pCol->pExpr=pExpr;
						if(pAggInfo->pGroupBy)
						{
							int j,n;
							ExprList *pGB=pAggInfo->pGroupBy;
							struct ExprList_item *pTerm=pGB->a;
							n=pGB->nExpr;
							for(j=0;j<n;j++,pTerm++)
							{
								Expr *pE=pTerm->pExpr;
								if(pE->op==TK_COLUMN && pE->iTable==pExpr->iTable &&pE->iColumn==pExpr->iColumn)
								{
									pCol->iSorterColumn=j;
									break;
								}
							}
						}
						if(pCol->iSorterColumn<0)Col->iSorterColumn=pAggInfo->nSortingColumn++;
					}
					pExpr->pAggInfo=pAggInfo;
					pExpr->op=TK_AGG_COLUMN;
					pExpr->iAgg=k;
					break;
				}
			}
		}
		return 1;
	case TK_AGG_FUNCTION:
		if(pNC->nDepth==0)
		{
			struct AggInfo_func *pItem=pAggInfo->aFunc;
			for(i=0;i<pAggInfo->nFunc;i++,pItem++)
			{
				if(WN_SQL3ExprCompare(pItem->pExpr,pExpr))break;
				if(i>=pAggInfo->nFunc)
				{
					u8 enc=ENC(pParse->db);
					i=addAggInfoFunc(pAggInfo);
					if(i>=0)
					{
						pItem=&pAggInfo->aFunc[i];
						pItem->pExpr=pExpr;
						pItem->iMem=pParse->nMem++;
						pItem->pFunc=WN_SQL3FindFunction(pParse->db,(char*)pExpr->token.z,pExpr->token.n,pExpr->pList ? pExpr->pList->nExpr :0,enc,0);
						if(pExpr->flags & EP_Distinct)
							pItem->iDistinct=pParse->nTab++;
						else
							pItem->iDistinct=-1;
					}
				}
				pExpr->iAgg=i;
				pExpr->pAggInfo=pAggInfo;
				return 1;
			}
		}
	}
	if(pExpr->pSelect)
	{
		pNC->nDepth++;
		walkSelectExpr(pExpr->pSelect,analyzeAggregate,pNC);
		pNC->nDepth--;
	}
	return 0;
}
int WN_SQL3ExprAnalyzeAggregates(NameContext *pNC,Expr *pExpr)
{
	int nErr=pNC->pParse->nErr;
	walkExprTree(pExpr,analyzeAggregate,pNC);
	return pNC->pParse->nErr-nErr;
}
int WN_SQL3ExprAnalyzeAggList(NameContext *pNC,ExprList *pList)
{
	struct ExprList_item *pItem;
	int i,nErr=0;
	if(pList)for(pItem=pList->a,i=0;nErr==0 && i<pList->nExpr;i++,pItem++)nErr+=WN_SQL3ExprAnalyzeAggregates(pNC,pItem->pExpr);
	return nErr;
}
#ifndef WN_SQL_OMIT_ALTERTABLE
void renameTableFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	unsigned char const *zSql=WN_SQL3_value_text(argv[0]),*zTableName=WN_SQL3_value_text(argv[1]);
	int token;
	Token tname;
	unsigned char const *zCsr=zSql;
	int len=0;
	char *zRet;
	if(zSql)
	{
		do
		{
			if(!*zCsr)return;
			tname.z=zCsr;
			tname.n=len;
			do
			{
				zCsr+=len;
				len=WN_SQL3GetToken(zCsr,&token);
			}while(token==TK_SPACE);
		}while(token!=TK_LP && token!=TK_USING);
		zRet=WN_SQL3MPrintf("%.*s%Q%s",tname.z-zSql,zSql,zTableName,tname.z+tname.n);
		WN_SQL3_result_text(context,zRet,-1,WN_SQL3FreeX);
	}
}
#ifndef WN_SQL_OMIT_TRIGGER
void renameTriggerFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	unsigned char const *zSql=WN_SQL3_value_text(argv[0]),*zTableName=WN_SQL3_value_text(argv[1]);
	int token;
	Token tname;
	int dist=3;
	unsigned char const *zCsr=zSql;
	int len=0;
	char *zRet;
	if(zSql)
	{
		do
		{
			if(!*zCsr)return;
			tname.z=zCsr;
			tname.n=len;
			do
			{
				zCsr+=len;
				len=WN_SQL3GetToken(zCsr,&token);
			}while(token==TK_SPACE);
			dist++;
			if(token==TK_DOT || token==TK_ON)dist=0;
		}while(dist!=2 ||(token!=TK_WHEN && token!=TK_FOR && token!=TK_BEGIN));
		zRet=WN_SQL3MPrintf("%.*s%Q%s",tname.z-zSql,zSql,zTableName,tname.z+tname.n);
		WN_SQL3_result_text(context,zRet,-1,WN_SQL3FreeX);
	}
}
#endif
void WN_SQL3AlterFunctions(WN_SQL3 *db)
{
	const struct
	{
		char *zName;
		signed char nArg;
		void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value **);
	}aFuncs[]={{"WN_SQL_rename_table",2,renameTableFunc},#ifndef WN_SQL_OMIT_TRIGGER
{"WN_SQL_rename_trigger",2,renameTriggerFunc},#endif
	};
	int i;
	for(i=0;i<sizeof(aFuncs)/sizeof(aFuncs[0]);i++)	WN_SQL3CreateFunc(db,aFuncs[i].zName,aFuncs[i].nArg,WN_SQL_UTF8,0,aFuncs[i].xFunc,0,0);
}
char *whereTempTriggers(Parse *pParse,Table *pTab)
{
	Trigger *pTrig;
	char *zWhere=0;
	char *tmp=0;
	const Schema *pTempSchema=pParse->db->aDb[1].pSchema;
	if(pTab->pSchema!=pTempSchema)
		for(pTrig=pTab->pTrigger;pTrig;pTrig=pTrig->pNext)
			if(pTrig->pSchema==pTempSchema)
				if(!zWhere)
					zWhere=WN_SQL3MPrintf("name=%Q",pTrig->name);
				else
				{
					tmp=zWhere;
					zWhere=WN_SQL3MPrintf("%s OR name=%Q",zWhere,pTrig->name);
					WN_SQL3FreeX(tmp);
				}
	return zWhere;
}
void reloadTableSchema(Parse *pParse,Table *pTab,const char *zName)
{
	char *zWhere;
#ifndef WN_SQL_OMIT_TRIGGER
	Trigger *pTrig;
#endif
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(!v)return;
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
#ifndef WN_SQL_OMIT_TRIGGER
	for(pTrig=pTab->pTrigger;pTrig;pTrig=pTrig->pNext)
	{
		int iTrigDb=WN_SQL3SchemaToIndex(pParse->db,pTrig->pSchema);
		WN_SQL3VdbeOp3(v,OP_DropTrigger,iTrigDb,0,pTrig->name,0);
	}
#endif
	WN_SQL3VdbeOp3(v,OP_DropTable,iDb,0,pTab->zName,0);
	zWhere=WN_SQL3MPrintf("tbl_name=%Q",zName);
	if(!zWhere)return;
	WN_SQL3VdbeOp3(v,OP_ParseSchema,iDb,0,zWhere,P3_DYNAMIC);
#ifndef WN_SQL_OMIT_TRIGGER
	if((zWhere=whereTempTriggers(pParse,pTab)))WN_SQL3VdbeOp3(v,OP_ParseSchema,1,0,zWhere,P3_DYNAMIC);
#endif
}
void WN_SQL3AlterRenameTable(Parse *pParse,SrcList *pSrc,Token *pName)
{
	WN_SQL3 *db=pParse->db;
	int nTabName;
	const char *zTabName;
	Vdbe *v;
#ifndef WN_SQL_OMIT_TRIGGER
	char *zWhere=0;
#endif
	int isVirtualRename=0;
	if(WN_SQL3MallocFailed())goto exit_rename_table;
	Table *pTab=WN_SQL3LocateTable(pParse,pSrc->a[0].zName,pSrc->a[0].zDatabase);
	if(!pTab)goto exit_rename_table;
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
	char *zDb=db->aDb[iDb].zName;
	char *zName=WN_SQL3NameFromToken(pName);
	if(!zName)goto exit_rename_table;
	if(WN_SQL3FindTable(db,zName,zDb)|| WN_SQL3FindIndex(db,zName,zDb))
	{
		WN_SQL3ErrorMsg(pParse,"there is already another table or index with this name:%s",zName);
		goto exit_rename_table;
	}
	if(strlen(pTab->zName)>6 && 0==WN_SQL3StrNICmp(pTab->zName,"WN_SQL_",7))
	{
		WN_SQL3ErrorMsg(pParse,"table %s may not be altered",pTab->zName);
		goto exit_rename_table;
	}
	if(WN_SQL3CheckObjectName(pParse,zName))goto exit_rename_table;
#ifndef WN_SQL_OMIT_AUTHORIZATION
	if(WN_SQL3AuthCheck(pParse,WN_SQL_ALTER_TABLE,zDb,pTab->zName,0))goto exit_rename_table;
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(WN_SQL3ViewGetColumnNames(pParse,pTab))goto exit_rename_table;
	if(IsVirtual(pTab)&& pTab->pMod->pModule->xRename)isVirtualRename=1;
#endif
	v=WN_SQL3GetVdbe(pParse);
	if(v==0)goto exit_rename_table;
	WN_SQL3BeginWriteOperation(pParse,isVirtualRename,iDb);
	WN_SQL3ChangeCookie(db,v,iDb);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(isVirtualRename)
	{
		WN_SQL3VdbeOp3(v,OP_String8,0,0,zName,0);
		WN_SQL3VdbeOp3(v,OP_VRename,0,0,(const char*)pTab->pVtab,P3_VTAB);
	}
#endif
	zTabName=pTab->zName;
	nTabName=WN_SQL3Utf8CharLen(zTabName,-1);
	WN_SQL3NestedParse(pParse,"UPDATE %Q.%s SET "
#ifdef WN_SQL_OMIT_TRIGGER
		"sql=WN_SQL_rename_table(sql,%Q),"
#else
		"sql=CASE "
		"WHEN type='trigger' THEN WN_SQL_rename_trigger(sql,%Q)"
		"ELSE WN_SQL_rename_table(sql,%Q)END,"
#endif
		"tbl_name=%Q,"
		"name=CASE "
"WHEN type='table' THEN %Q "
"WHEN name LIKE 'WN_SQL_autoindex%%' AND type='index' THEN "
"'WN_SQL_autoindex_' || %Q || substr(name,%d+18,10)"
"ELSE name END "
"WHERE tbl_name=%Q AND "
"(type='table' OR type='index' OR type='trigger');",zDb,SCHEMA_TABLE(iDb),zName,zName,zName,#ifndef WN_SQL_OMIT_TRIGGER zName,#endif zName,nTabName,zTabName);
#ifndef WN_SQL_OMIT_AUTOINCREMENT
	if(WN_SQL3FindTable(db,"WN_SQL_sequence",zDb))WN_SQL3NestedParse(pParse,"UPDATE %Q.WN_SQL_sequence set name=%Q WHERE name=%Q",zDb,zName,pTab->zName);
#endif
#ifndef WN_SQL_OMIT_TRIGGER
	if((zWhere=whereTempTriggers(pParse,pTab)))
	{
		WN_SQL3NestedParse(pParse,"UPDATE WN_SQL_temp_master SET "
"sql=WN_SQL_rename_trigger(sql,%Q),"
"tbl_name=%Q "
"WHERE %s;",zName,zName,zWhere);
		WN_SQL3FreeX(zWhere);
	}
#endif
	reloadTableSchema(pParse,pTab,zName);
exit_rename_table:
	WN_SQL3SrcListDelete(pSrc);
	WN_SQL3FreeX(zName);
}
void WN_SQL3AlterFinishAddColumn(Parse *pParse,Token *pColDef)
{
	if(pParse->nErr)return;
	Table *pNew=pParse->pNewTable,*pTab;
	const char *zDb=pParse->db->aDb[iDb].zName,*zTab;
	char *zCol;
	Column *pCol;
	Expr *pDflt;
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pNew->pSchema);
	zTab=pNew->zName;
	pCol=&pNew->aCol[pNew->nCol-1];
	pDflt=pCol->pDflt;
	pTab=WN_SQL3FindTable(pParse->db,zTab,zDb);
#ifndef WN_SQL_OMIT_AUTHORIZATION
	if(WN_SQL3AuthCheck(pParse,WN_SQL_ALTER_TABLE,zDb,pTab->zName,0))return;
#endif
	if(pDflt && pDflt->op==TK_NULL)pDflt=0;
	if(pCol->isPrimKey)
	{
		WN_SQL3ErrorMsg(pParse,"Cannot add a PRIMARY KEY column");
		return;
	}
	if(pNew->pIndex)
	{
		WN_SQL3ErrorMsg(pParse,"Cannot add a UNIQUE column");
		return;
	}
	if(pCol->notNull && !pDflt)
	{
		WN_SQL3ErrorMsg(pParse,"Cannot add a NOT NULL column with default value NULL");
		return;
	}
	if(pDflt)
	{
		WN_SQL3_value *pVal;
		if(WN_SQL3ValueFromExpr(pDflt,WN_SQL_UTF8,WN_SQL_AFF_NONE,&pVal))return;
		if(!pVal)
		{
			WN_SQL3ErrorMsg(pParse,"Cannot add a column with non-constant default");
			return;
		}
		WN_SQL3ValueFree(pVal);
	}
	zCol=WN_SQLStrNDup((char*)pColDef->z,pColDef->n);
	if(zCol)
	{
		char *zEnd=&zCol[pColDef->n-1];
		while((zEnd>zCol && *zEnd==';')|| isspace(*(unsigned char *)zEnd))*zEnd--='\0';
		WN_SQL3NestedParse(pParse,"UPDATE %Q.%s SET "
"sql=substr(sql,1,%d)|| ',' || %Q || substr(sql,%d,length(sql))"
"WHERE type='table' AND name=%Q",zDb,SCHEMA_TABLE(iDb),pNew->addColOffset,zCol,pNew->addColOffset+1,zTab);
		WN_SQL3FreeX(zCol);
	}
	WN_SQL3MinimumFileFormat(pParse,iDb,pDflt ? 3 :2);
	reloadTableSchema(pParse,pTab,pTab->zName);
}
void WN_SQL3AlterBeginAddColumn(Parse *pParse,SrcList *pSrc)
{
	Table *pNew,*pTab;
	Vdbe *v;
	int iDb,i,nAlloc;
	if(WN_SQL3MallocFailed())goto exit_begin_add_column;
	pTab=WN_SQL3LocateTable(pParse,pSrc->a[0].zName,pSrc->a[0].zDatabase);
	if(!pTab)goto exit_begin_add_column;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(IsVirtual(pTab))
	{
		WN_SQL3ErrorMsg(pParse,"virtual tables may not be altered");
		goto exit_begin_add_column;
	}
#endif
	if(pTab->pSelect)
	{
		WN_SQL3ErrorMsg(pParse,"Cannot add a column to a view");
		goto exit_begin_add_column;
	}
	iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
	pNew=(Table *)WN_SQL3Malloc(sizeof(Table));
	if(!pNew)goto exit_begin_add_column;
	pParse->pNewTable=pNew;
	pNew->nRef=1;
	pNew->nCol=pTab->nCol;
	nAlloc=(((pNew->nCol-1)/8)*8)+8;
	pNew->aCol=(Column *)WN_SQL3Malloc(sizeof(Column)*nAlloc);
	pNew->zName=WN_SQLStrDup(pTab->zName);
	if(!pNew->aCol || !pNew->zName)goto exit_begin_add_column;
	memcpy(pNew->aCol,pTab->aCol,sizeof(Column)*pNew->nCol);
	for(i=0;i<pNew->nCol;i++)
	{
		Column *pCol=&pNew->aCol[i];
		pCol->zName=WN_SQLStrDup(pCol->zName);
		pCol->zColl=0;
		pCol->zType=0;
		pCol->pDflt=0;
	}
	pNew->pSchema=pParse->db->aDb[iDb].pSchema;
	pNew->addColOffset=pTab->addColOffset;
	pNew->nRef=1;
	WN_SQL3BeginWriteOperation(pParse,0,iDb);
	v=WN_SQL3GetVdbe(pParse);
	if(!v)goto exit_begin_add_column;
	WN_SQL3ChangeCookie(pParse->db,v,iDb);
exit_begin_add_column:
	WN_SQL3SrcListDelete(pSrc);
	return;
}
#endif
#ifndef WN_SQL_OMIT_ANALYZE
void openStatTable(Parse *pParse,int iDb,int iStatCur,const char *zWhere
)
{
	WN_SQL3 *db=pParse->db;
	int iRootPage;
	Table *pStat;
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v==0)return;
	Db *pDb=&db->aDb[iDb];
	if((pStat=WN_SQL3FindTable(db,"WN_SQL_stat1",pDb->zName))==0)
	{
		WN_SQL3NestedParse(pParse,"CREATE TABLE %Q.WN_SQL_stat1(tbl,idx,stat)",pDb->zName);
		iRootPage=0;
	}
	else
		if(zWhere)
		{
			WN_SQL3NestedParse(pParse,"DELETE FROM %Q.WN_SQL_stat1 WHERE tbl=%Q",pDb->zName,zWhere);
			iRootPage=pStat->tnum;
		}
		else
		{
			iRootPage=pStat->tnum;
			WN_SQL3VdbeAddOp(v,OP_Clear,pStat->tnum,iDb);
		}
		if(iRootPage>0)WN_SQL3TableLock(pParse,iDb,iRootPage,1,"WN_SQL_stat1");
		WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
		WN_SQL3VdbeAddOp(v,OP_OpenWrite,iStatCur,iRootPage);
		WN_SQL3VdbeAddOp(v,OP_SetNumColumns,iStatCur,3);
}
void analyzeOneTable(Parse *pParse,Table *pTab,int iStatCur,int iMem)
{
	Index *pIdx;
	int iIdxCur,nCol,i,topOfLoop,endOfLoop,addr,iDb;
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v==0 || pTab==0 || pTab->pIndex==0)return;
	iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
#ifndef WN_SQL_OMIT_AUTHORIZATION
	if(WN_SQL3AuthCheck(pParse,WN_SQL_ANALYZE,pTab->zName,0,pParse->db->aDb[iDb].zName))return;
#endif
	WN_SQL3TableLock(pParse,iDb,pTab->tnum,0,pTab->zName);
	iIdxCur=pParse->nTab;
	for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)
	{
		KeyInfo *pKey=WN_SQL3IndexKeyinfo(pParse,pIdx);
		WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
		VdbeComment((v,"# %s",pIdx->zName));
		WN_SQL3VdbeOp3(v,OP_OpenRead,iIdxCur,pIdx->tnum,(char *)pKey,P3_KEYINFO_HANDOFF);
		nCol=pIdx->nColumn;
		if(iMem+nCol*2>=pParse->nMem)pParse->nMem=iMem+nCol*2+1;
		WN_SQL3VdbeAddOp(v,OP_SetNumColumns,iIdxCur,nCol+1);
		for(i=0;i<=nCol;i++)WN_SQL3VdbeAddOp(v,OP_MemInt,0,iMem+i);
		for(i=0;i<nCol;i++)WN_SQL3VdbeAddOp(v,OP_MemNull,iMem+nCol+i+1,0);
		endOfLoop=WN_SQL3VdbeMakeLabel(v);
		WN_SQL3VdbeAddOp(v,OP_Rewind,iIdxCur,endOfLoop);
		topOfLoop=WN_SQL3VdbeCurrentAddr(v);
		WN_SQL3VdbeAddOp(v,OP_MemIncr,1,iMem);
		for(i=0;i<nCol;i++)
		{
			WN_SQL3VdbeAddOp(v,OP_Column,iIdxCur,i);
			WN_SQL3VdbeAddOp(v,OP_MemLoad,iMem+nCol+i+1,0);
			WN_SQL3VdbeAddOp(v,OP_Ne,0x100,0);
		}
		WN_SQL3VdbeAddOp(v,OP_Goto,0,endOfLoop);
		for(i=0;i<nCol;i++)
		{
			addr=WN_SQL3VdbeAddOp(v,OP_MemIncr,1,iMem+i+1);
			WN_SQL3VdbeChangeP2(v,topOfLoop+3*i+3,addr);
			WN_SQL3VdbeAddOp(v,OP_Column,iIdxCur,i);
			WN_SQL3VdbeAddOp(v,OP_MemStore,iMem+nCol+i+1,1);
		}
		WN_SQL3VdbeResolveLabel(v,endOfLoop);
		WN_SQL3VdbeAddOp(v,OP_Next,iIdxCur,topOfLoop);
		WN_SQL3VdbeAddOp(v,OP_Close,iIdxCur,0);
		WN_SQL3VdbeAddOp(v,OP_MemLoad,iMem,0);
		addr=WN_SQL3VdbeAddOp(v,OP_IfNot,0,0);
		WN_SQL3VdbeAddOp(v,OP_NewRowid,iStatCur,0);
		WN_SQL3VdbeOp3(v,OP_String8,0,0,pTab->zName,0);
		WN_SQL3VdbeOp3(v,OP_String8,0,0,pIdx->zName,0);
		WN_SQL3VdbeAddOp(v,OP_MemLoad,iMem,0);
		WN_SQL3VdbeOp3(v,OP_String8,0,0," ",0);
		for(i=0;i<nCol;i++)
		{
			WN_SQL3VdbeAddOp(v,OP_MemLoad,iMem,0);
			WN_SQL3VdbeAddOp(v,OP_MemLoad,iMem+i+1,0);
			WN_SQL3VdbeAddOp(v,OP_Add,0,0);
			WN_SQL3VdbeAddOp(v,OP_AddImm,-1,0);
			WN_SQL3VdbeAddOp(v,OP_MemLoad,iMem+i+1,0);
			WN_SQL3VdbeAddOp(v,OP_Divide,0,0);
			WN_SQL3VdbeAddOp(v,OP_ToInt,0,0);
			if(i==nCol-1)
				WN_SQL3VdbeAddOp(v,OP_Concat,nCol*2-1,0);
			else
				WN_SQL3VdbeAddOp(v,OP_Dup,1,0);
		}
		WN_SQL3VdbeOp3(v,OP_MakeRecord,3,0,"aaa",0);
		WN_SQL3VdbeAddOp(v,OP_Insert,iStatCur,OPFLAG_APPEND);
		WN_SQL3VdbeJumpHere(v,addr);
	}
}
void loadAnalysis(Parse *pParse,int iDb)
{
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v)WN_SQL3VdbeAddOp(v,OP_LoadAnalysis,iDb,0);
}
void analyzeDatabase(Parse *pParse,int iDb)
{
	WN_SQL3 *db=pParse->db;
	Schema *pSchema=db->aDb[iDb].pSchema;
	HashElem *k;
	int iStatCur,iMem;
	WN_SQL3BeginWriteOperation(pParse,0,iDb);
	iStatCur=pParse->nTab++;
	openStatTable(pParse,iDb,iStatCur,0);
	iMem=pParse->nMem;
	for(k=WN_SQLHashFirst(&pSchema->tblHash);k;k=WN_SQLHashNext(k))
	{
		Table *pTab=(Table*)WN_SQLHashData(k);
		analyzeOneTable(pParse,pTab,iStatCur,iMem);
	}
	loadAnalysis(pParse,iDb);
}
void analyzeTable(Parse *pParse,Table *pTab)
{
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema),iStatCur;
	WN_SQL3BeginWriteOperation(pParse,0,iDb);
	iStatCur=pParse->nTab++;
	openStatTable(pParse,iDb,iStatCur,pTab->zName);
	analyzeOneTable(pParse,pTab,iStatCur,pParse->nMem);
	loadAnalysis(pParse,iDb);
}
void WN_SQL3Analyze(Parse *pParse,Token *pName1,Token *pName2)
{
	WN_SQL3 *db=pParse->db;
	int iDb,i;
	char *z,*zDb;
	Table *pTab;
	Token *pTableName;
	if(WN_SQL3ReadSchema(pParse))return;
	if(pName1==0)
		for(i=0;i<db->nDb;i++)
		{
			if(i!=1)analyzeDatabase(pParse,i);
		}
	else
		if(pName2==0 || pName2->n==0)
		{
			iDb=WN_SQL3FindDb(db,pName1);
			if(iDb>=0)
				analyzeDatabase(pParse,iDb);
			else
			{
				z=WN_SQL3NameFromToken(pName1);
				pTab=WN_SQL3LocateTable(pParse,z,0);
				WN_SQL3FreeX(z);
				if(pTab)analyzeTable(pParse,pTab);
			}
		}
		else
		{
			iDb=WN_SQL3TwoPartName(pParse,pName1,pName2,&pTableName);
			if(iDb>=0)
			{
				zDb=db->aDb[iDb].zName;
				z=WN_SQL3NameFromToken(pTableName);
				if(z)
				{
					pTab=WN_SQL3LocateTable(pParse,z,zDb);
					WN_SQL3FreeX(z);
					if(pTab)analyzeTable(pParse,pTab);
				}
			}
		}
}
typedef struct analysisInfo analysisInfo;
struct analysisInfo
{
	WN_SQL3 *db;
	const char *zDatabase;
};
int analysisLoader(void *pData,int argc,char **argv,char **azNotUsed)
{
	analysisInfo *pInfo=(analysisInfo*)pData;
	int i,c;
	u32 v;
	const char *z;
	if(argv==0 || argv[0]==0 || argv[1]==0)return 0;
	Index *pIndex=WN_SQL3FindIndex(pInfo->db,argv[0],pInfo->zDatabase);
	if(pIndex==0)return 0;
	z=argv[1];
	for(i=0;*z && i<=pIndex->nColumn;i++)
	{
		v=0;
		while((c=z[0])>='0' && c<='9')
		{
			v=v*10+c-'0';
			z++;
		}
		pIndex->aiRowEst[i]=v;
		if(*z==' ')z++;
	}
	return 0;
}
int WN_SQL3AnalysisLoad(WN_SQL3 *db,int iDb)
{
	analysisInfo sInfo;
	HashElem *i;
	int rc;
	for(i=WN_SQLHashFirst(&db->aDb[iDb].pSchema->idxHash);i;i=WN_SQLHashNext(i))
	{
		Index *pIdx=WN_SQLHashData(i);
		WN_SQL3DefaultRowEst(pIdx);
	}
	sInfo.db=db;
	sInfo.zDatabase=db->aDb[iDb].zName;
	if(WN_SQL3FindTable(db,"WN_SQL_stat1",sInfo.zDatabase)==0)return WN_SQL_ERROR;
	char *zSql=WN_SQL3MPrintf("SELECT idx,stat FROM %Q.WN_SQL_stat1",sInfo.zDatabase);
	WN_SQL3SafetyOff(db);
	rc=WN_SQL3_exec(db,zSql,analysisLoader,&sInfo,0);
	WN_SQL3SafetyOn(db);
	WN_SQL3FreeX(zSql);
	return rc;
}
#endif
#ifndef WN_SQL_OMIT_ATTACH
int resolveAttachExpr(NameContext *pName,Expr *pExpr)
{
	int rc=0;
	if(pExpr)
	{
		if(pExpr->op!=TK_ID)
		{
			rc=WN_SQL3ExprResolveNames(pName,pExpr);
			if(rc==0 && !WN_SQL3ExprIsConstant(pExpr))
			{
				WN_SQL3ErrorMsg(pName->pParse,"invalid name:\"%T\"",&pExpr->span);
				return WN_SQL_ERROR;
			}
		}
		else
			pExpr->op=TK_STRING;
	}
	return rc;
}
void attachFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	int i,rc=0;
	WN_SQL3 *db=WN_SQL3_user_data(context);
	Db *aNew;
	char zErr[128],*zErrDyn=0;
	const char *zFile=(const char *)WN_SQL3_value_text(argv[0]),*zName=(const char *)WN_SQL3_value_text(argv[1]);
	if(zFile==0)zFile="";
	if(zName==0)zName="";
	if(db->nDb>=WN_SQL_MAX_ATTACHED+2)
	{
		WN_SQL3_snprintf(sizeof(zErr),zErr,"too many attached databases-max %d",WN_SQL_MAX_ATTACHED);
		goto attach_error;
	}
	if(!db->autoCommit)
	{
		WN_SQL3_snprintf(sizeof(zErr),zErr,"cannot ATTACH database within transaction");
		goto attach_error;
	}
	for(i=0;i<db->nDb;i++)
	{
		char *z=db->aDb[i].zName;
		if(z && zName && WN_SQL3StrICmp(z,zName)==0)
		{
			WN_SQL3_snprintf(sizeof(zErr),zErr,"database %s is already in use",zName);
			goto attach_error;
		}
	}
	if(db->aDb==db->aDbStatic)
	{
		aNew=WN_SQL3Malloc(sizeof(db->aDb[0])*3);
		if(aNew==0)return;
		memcpy(aNew,db->aDb,sizeof(db->aDb[0])*2);
	}
	else
	{
		aNew=WN_SQLRealloc(db->aDb,sizeof(db->aDb[0])*(db->nDb+1));
		if(aNew==0)return;
	}
	db->aDb=aNew;
	aNew=&db->aDb[db->nDb++];
	memset(aNew,0,sizeof(*aNew));
	rc=WN_SQL3BtreeFactory(db,zFile,0,WN_SQL_DEFAULT_CACHE_SIZE,&aNew->pBt);
	if(rc==0)
	{
		aNew->pSchema=WN_SQL3SchemaGet(aNew->pBt);
		if(!aNew->pSchema)
			rc=WN_SQL_NOMEM;
		else
			if(aNew->pSchema->file_format && aNew->pSchema->enc!=ENC(db))
			{
				WN_SQL3_snprintf(sizeof(zErr),zErr,"attached databases must use the same text encoding as main database");
				goto attach_error;
			}
			WN_SQL3PagerLockingMode(WN_SQL3BtreePager(aNew->pBt),db->dfltLockMode);
	}
	aNew->zName=WN_SQLStrDup(zName);
	aNew->safety_level=3;
#if WN_SQL_HAS_CODEC
	extern int WN_SQL3CodecAttach(WN_SQL3*,int,const void*,int);
	extern void WN_SQL3CodecGetKey(WN_SQL3*,int,void**,int*);
	int nKey;
	char *zKey;
	int t=WN_SQL3_value_type(argv[2]);
	switch(t)
	{
	case WN_SQL_INTEGER:
	case WN_SQL_FLOAT:
		zErrDyn=WN_SQLStrDup("Invalid key value");
		rc=WN_SQL_ERROR;
		break;
	case WN_SQL_TEXT:
	case WN_SQL_BLOB:
		nKey=WN_SQL3_value_bytes(argv[2]);
		zKey=(char *)WN_SQL3_value_blob(argv[2]);
		WN_SQL3CodecAttach(db,db->nDb-1,zKey,nKey);
		break;
	case WN_SQL_NULL:
		WN_SQL3CodecGetKey(db,0,(void**)&zKey,&nKey);
		WN_SQL3CodecAttach(db,db->nDb-1,zKey,nKey);
		break;
	}
#endif
	if(rc==0)
	{
		WN_SQL3SafetyOn(db);
		rc=WN_SQL3Init(db,&zErrDyn);
		WN_SQL3SafetyOff(db);
	}
	if(rc)
	{
		int iDb=db->nDb-1;
		if(db->aDb[iDb].pBt)
		{
			WN_SQL3BtreeClose(db->aDb[iDb].pBt);
			db->aDb[iDb].pBt=0;
			db->aDb[iDb].pSchema=0;
		}
		WN_SQL3ResetInternalSchema(db,0);
		db->nDb=iDb;
		if(rc==WN_SQL_NOMEM)
		{
			WN_SQL3FailedMalloc();
			WN_SQL3_snprintf(sizeof(zErr),zErr,"out of memory");
		}
		else
			WN_SQL3_snprintf(sizeof(zErr),zErr,"unable to open database:%s",zFile);
		goto attach_error;
	}
	return;
attach_error:
	if(zErrDyn)
	{
		WN_SQL3_result_error(context,zErrDyn,-1);
		WN_SQL3FreeX(zErrDyn);
	}
	else
	{
		zErr[sizeof(zErr)-1]=0;
		WN_SQL3_result_error(context,zErr,-1);
	}
}
void detachFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	const char *zName=(const char *)WN_SQL3_value_text(argv[0]);
	WN_SQL3 *db=WN_SQL3_user_data(context);
	int i;
	Db *pDb=0;
	char zErr[128];
	if(zName==0)zName="";
	for(i=0;i<db->nDb;i++)
	{
		pDb=&db->aDb[i];
		if(pDb->pBt==0)continue;
		if(WN_SQL3StrICmp(pDb->zName,zName)==0)break;
	}
	if(i>=db->nDb)
	{
		WN_SQL3_snprintf(sizeof(zErr),zErr,"no such database:%s",zName);
		goto detach_error;
	}
	if(i<2)
	{
		WN_SQL3_snprintf(sizeof(zErr),zErr,"cannot detach database %s",zName);
		goto detach_error;
	}
	if(!db->autoCommit)
	{
		WN_SQL3_snprintf(sizeof(zErr),zErr,"cannot DETACH database within transaction");
		goto detach_error;
	}
	if(WN_SQL3BtreeIsInReadTrans(pDb->pBt))
	{
		WN_SQL3_snprintf(sizeof(zErr),zErr,"database %s is locked",zName);
		goto detach_error;
	}
	WN_SQL3BtreeClose(pDb->pBt);
	pDb->pBt=0;
	pDb->pSchema=0;
	WN_SQL3ResetInternalSchema(db,0);
	return;
detach_error:
	WN_SQL3_result_error(context,zErr,-1);
}
void codeAttach(Parse *pParse,int type,const char *zFunc,int nFunc,Expr *pAuthArg,Expr *pFilename,Expr *pDbname,Expr *pKey)
{
	int rc;
	NameContext sName;
	Vdbe *v;
	FuncDef *pFunc;
	WN_SQL3* db=pParse->db;
#ifndef WN_SQL_OMIT_AUTHORIZATION
	if(pAuthArg)
	{
		char *zAuthArg=WN_SQL3NameFromToken(&pAuthArg->span);
		if(!zAuthArg)goto attach_end;
		rc=WN_SQL3AuthCheck(pParse,type,zAuthArg,0,0);
		WN_SQL3FreeX(zAuthArg);
		if(rc)goto attach_end;
	}
#endif
	memset(&sName,0,sizeof(NameContext));
	sName.pParse=pParse;
	if((rc=resolveAttachExpr(&sName,pFilename))||(rc=resolveAttachExpr(&sName,pDbname))||(rc=resolveAttachExpr(&sName,pKey)))
	{
		pParse->nErr++;
		goto attach_end;
	}
	v=WN_SQL3GetVdbe(pParse);
	WN_SQL3ExprCode(pParse,pFilename);
	WN_SQL3ExprCode(pParse,pDbname);
	WN_SQL3ExprCode(pParse,pKey);
	if(v)
	{
		WN_SQL3VdbeAddOp(v,OP_Function,0,nFunc);
		pFunc=WN_SQL3FindFunction(db,zFunc,strlen(zFunc),nFunc,WN_SQL_UTF8,0);
		WN_SQL3VdbeChangeP3(v,-1,(char *)pFunc,P3_FUNCDEF);
		WN_SQL3VdbeAddOp(v,OP_Expire,(type==WN_SQL_ATTACH),0);
	}
attach_end:
	WN_SQL3ExprDelete(pFilename);
	WN_SQL3ExprDelete(pDbname);
	WN_SQL3ExprDelete(pKey);
}
void WN_SQL3Detach(Parse *pParse,Expr *pDbname)
{
	codeAttach(pParse,WN_SQL_DETACH,"WN_SQL_detach",1,pDbname,0,0,pDbname);
}
void WN_SQL3Attach(Parse *pParse,Expr *p,Expr *pDbname,Expr *pKey)
{
	codeAttach(pParse,WN_SQL_ATTACH,"WN_SQL_attach",3,p,p,pDbname,pKey);
}
#endif
void WN_SQL3AttachFunctions(WN_SQL3 *db)
{
#ifndef WN_SQL_OMIT_ATTACH
	const int enc=WN_SQL_UTF8;
	WN_SQL3CreateFunc(db,"WN_SQL_attach",3,enc,db,attachFunc,0,0);
	WN_SQL3CreateFunc(db,"WN_SQL_detach",1,enc,db,detachFunc,0,0);
#endif
}
int WN_SQL3FixInit(DbFixer *pFix,Parse *pParse,int iDb,const char *zType,const Token *pName)
{
	if(iDb<0 || iDb==1)return 0;
	WN_SQL3 *db=pParse->db;
	pFix->pParse=pParse;
	pFix->zDb=db->aDb[iDb].zName;
	pFix->zType=zType;
	pFix->pName=pName;
	return 1;
}
int WN_SQL3FixSrcList(DbFixer *pFix,SrcList *pList)
{
	if(pList==0)return 0;
	struct SrcList_item *pItem;
	const char *zDb=pFix->zDb;
	int i;
	for(i=0,pItem=pList->a;i<pList->nSrc;i++,pItem++)
	{
		if(pItem->zDatabase==0)
			pItem->zDatabase=WN_SQLStrDup(zDb);
		else
			if(WN_SQL3StrICmp(pItem->zDatabase,zDb))
			{
				WN_SQL3ErrorMsg(pFix->pParse,"%s %T cannot reference objects in database %s",pFix->zType,pFix->pName,pItem->zDatabase);
				return 1;
			}
#if !defined(WN_SQL_OMIT_VIEW)|| !defined(WN_SQL_OMIT_TRIGGER)
		if(WN_SQL3FixSelect(pFix,pItem->pSelect))return 1;
		if(WN_SQL3FixExpr(pFix,pItem->pOn))return 1;
#endif
	}
	return 0;
}
#if !defined(WN_SQL_OMIT_VIEW)|| !defined(WN_SQL_OMIT_TRIGGER)
int WN_SQL3FixSelect(DbFixer *pFix,Select *pSelect)
{
	while(pSelect)
	{
		if(WN_SQL3FixExprList(pFix,pSelect->pEList)||WN_SQL3FixSrcList(pFix,pSelect->pSrc)||WN_SQL3FixExpr(pFix,pSelect->pWhere)||WN_SQL3FixExpr(pFix,pSelect->pHaving))return 1;
		pSelect=pSelect->pPrior;
	}
	return 0;
}
int WN_SQL3FixExpr(DbFixer *pFix,Expr *pExpr)
{
	while(pExpr)
	{
		if(WN_SQL3FixSelect(pFix,pExpr->pSelect))return 1;
		if(WN_SQL3FixExprList(pFix,pExpr->pList))return 1;
		if(WN_SQL3FixExpr(pFix,pExpr->pRight))return 1;
		pExpr=pExpr->pLeft;
	}
	return 0;
}
int WN_SQL3FixExprList(DbFixer *pFix,ExprList *pList)
{
	if(pList==0)return 0;
	int i;
	struct ExprList_item *pItem;
	for(i=0,pItem=pList->a;i<pList->nExpr;i++,pItem++)
		if(WN_SQL3FixExpr(pFix,pItem->pExpr))return 1;
	return 0;
}
#endif
#ifndef WN_SQL_OMIT_TRIGGER
int WN_SQL3FixTriggerStep(DbFixer *pFix,TriggerStep *pStep)
{
	while(pStep)
	{
		if(WN_SQL3FixSelect(pFix,pStep->pSelect)||WN_SQL3FixExpr(pFix,pStep->pWhere)||WN_SQL3FixExprList(pFix,pStep->pExprList))return 1;
		pStep=pStep->pNext;
	}
	return 0;
}
#endif
#ifndef WN_SQL_OMIT_AUTHORIZATION
int WN_SQL3_set_authorizer(WN_SQL3 *db,int(*xAuth)(void*,int,const char*,const char*,const char*,const char*),void *pArg)
{
	db->xAuth=xAuth;
	db->pAuthArg=pArg;
	WN_SQL3ExpirePreparedStatements(db);
	return 0;
}
void WN_SQLAuthBadReturnCode(Parse *pParse,int rc)
{
	WN_SQL3ErrorMsg(pParse,"illegal return value(%d)from the "
"authorization function-should be 0,WN_SQL_IGNORE,"
"or WN_SQL_DENY",rc);
	pParse->rc=WN_SQL_ERROR;
}
void WN_SQL3AuthRead(Parse *pParse,Expr *pExpr,SrcList *pTabList)
{	WN_SQL3 *db=pParse->db;
	if(db->xAuth==0)return;
	Table *pTab;
	const char *zCol;
	const char *zDBase;
	TriggerStack *pStack;
	if(pExpr->op!=TK_COLUMN)return;
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pExpr->pSchema);
	if(iDb<0)return;
	int iSrc;
	for(iSrc=0;pTabList && iSrc<pTabList->nSrc;iSrc++)
		if(pExpr->iTable==pTabList->a[iSrc].iCursor)break;
	if(iSrc>=0 && pTabList && iSrc<pTabList->nSrc)
		pTab=pTabList->a[iSrc].pTab;
	else
		if((pStack=pParse->trigStack))
			pTab=pStack->pTab;
		else
			return;
	if(pTab==0)return;
	if(pExpr->iColumn>=0)
		zCol=pTab->aCol[pExpr->iColumn].zName;
	else
		if(pTab->iPKey>=0)
			zCol=pTab->aCol[pTab->iPKey].zName;
		else
			zCol="ROWID";
	zDBase=db->aDb[iDb].zName;
	int rc=db->xAuth(db->pAuthArg,WN_SQL_READ,pTab->zName,zCol,zDBase,pParse->zAuthContext);
	if(rc==WN_SQL_IGNORE)
		pExpr->op=TK_NULL;
	else
		if(rc==WN_SQL_DENY)
		{	if(db->nDb>2 || iDb)
				WN_SQL3ErrorMsg(pParse,"access to %s.%s.%s is prohibited",zDBase,pTab->zName,zCol);
			else
				WN_SQL3ErrorMsg(pParse,"access to %s.%s is prohibited",pTab->zName,zCol);
			pParse->rc=WN_SQL_AUTH;
		}
		else
			if(rc)WN_SQLAuthBadReturnCode(pParse,rc);
}
int WN_SQL3AuthCheck(Parse *pParse,int code,const char *zArg1,const char *zArg2,const char *zArg3)
{	WN_SQL3 *db=pParse->db;
	int rc;
	if(db->init.busy || IN_DECLARE_VTAB)return 0;
	if(db->xAuth==0)return 0;
	rc=db->xAuth(db->pAuthArg,code,zArg1,zArg2,zArg3,pParse->zAuthContext);
	if(rc==WN_SQL_DENY)
	{	WN_SQL3ErrorMsg(pParse,"not authorized");
		pParse->rc=WN_SQL_AUTH;
	}
	else
		if(rc && rc!=WN_SQL_IGNORE)
		{	rc=WN_SQL_DENY;
			WN_SQLAuthBadReturnCode(pParse,rc);
		}
		return rc;
}
void WN_SQL3AuthContextPush(Parse *pParse,AuthContext *pContext,const char *zContext)
{
	pContext->pParse=pParse;
	if(pParse)
	{	pContext->zAuthContext=pParse->zAuthContext;
		pParse->zAuthContext=zContext;
	}
}
void WN_SQL3AuthContextPop(AuthContext *pContext)
{
	if(pContext->pParse)
	{
		pContext->pParse->zAuthContext=pContext->zAuthContext;
		pContext->pParse=0;
	}
}
#endif
void WN_SQL3BeginParse(Parse *pParse,int explainFlag)
{
	pParse->explain=explainFlag;
	pParse->nVar=0;
}
#ifndef WN_SQL_OMIT_SHARED_CACHE
struct TableLock
{
	int iDb,iTab;
	u8 isWriteLock;
	const char *zName;
};
void WN_SQL3TableLock(Parse *pParse,int iDb,int iTab,u8 isWriteLock,const char *zName)
{
	int i,nBytes;
	TableLock *p;
	if(0==WN_SQL3ThreadDataReadOnly()->useSharedData || iDb<0)return;
	for(i=0;i<pParse->nTableLock;i++)
	{
		p=&pParse->aTableLock[i];
		if(p->iDb==iDb && p->iTab==iTab)
		{
			p->isWriteLock=(p->isWriteLock || isWriteLock);
			return;
		}
	}
	nBytes=sizeof(TableLock)*(pParse->nTableLock+1);
	pParse->aTableLock=WN_SQLReallocOrFree(pParse->aTableLock,nBytes);
	if(pParse->aTableLock)
	{
		p=&pParse->aTableLock[pParse->nTableLock++];
		p->iDb=iDb;
		p->iTab=iTab;
		p->isWriteLock=isWriteLock;
		p->zName=zName;
	}
}
void codeTableLocks(Parse *pParse)
{
	int i;
	Vdbe *pVdbe;
	if(0==(pVdbe=WN_SQL3GetVdbe(pParse)))return;
	for(i=0;i<pParse->nTableLock;i++)
	{
		TableLock *p=&pParse->aTableLock[i];
		int p1=p->iDb;
		if(p->isWriteLock)p1=-1*(p1+1);
		WN_SQL3VdbeOp3(pVdbe,OP_TableLock,p1,p->iTab,p->zName,P3_STATIC);
	}
}
#else
#define codeTableLocks(x)
#endif
void WN_SQL3FinishCoding(Parse *pParse)
{
	WN_SQL3 *db;
	Vdbe *v;
	if(WN_SQL3MallocFailed())return;
	if(pParse->nested)return;
	if(!pParse->pVdbe)
		if(pParse->rc==0 && pParse->nErr)
		{
			pParse->rc=WN_SQL_ERROR;
			return;
		}
	db=pParse->db;
	v=WN_SQL3GetVdbe(pParse);
	if(v)
	{
		WN_SQL3VdbeAddOp(v,OP_Halt,0,0);
		if(pParse->cookieGoto>0)
		{
			u32 mask;
			int iDb;
			WN_SQL3VdbeJumpHere(v,pParse->cookieGoto-1);
			for(iDb=0,mask=1;iDb<db->nDb;mask<<=1,iDb++)
			{
				if((mask & pParse->cookieMask)==0)continue;
				WN_SQL3VdbeAddOp(v,OP_Transaction,iDb,(mask & pParse->writeMask)!=0);
				WN_SQL3VdbeAddOp(v,OP_VerifyCookie,iDb,pParse->cookieValue[iDb]);
			}
#ifndef WN_SQL_OMIT_VIRTUALTABLE
			if(pParse->pVirtualLock)
			{
				char *vtab=(char *)pParse->pVirtualLock->pVtab;
				WN_SQL3VdbeOp3(v,OP_VBegin,0,0,vtab,P3_VTAB);
			}
#endif
			codeTableLocks(pParse);
			WN_SQL3VdbeAddOp(v,OP_Goto,0,pParse->cookieGoto);
		}
#ifndef WN_SQL_OMIT_TRACE
		WN_SQL3VdbeOp3(v,OP_Noop,0,0,pParse->zSql,pParse->zTail-pParse->zSql);
#endif
	}
	if(v && pParse->nErr==0 && !WN_SQL3MallocFailed())
	{
#ifdef WN_SQL_DEBUG
		FILE *trace=(db->flags & WN_SQL_VdbeTrace)? stdout :0;
		WN_SQL3VdbeTrace(v,trace);
#endif
		WN_SQL3VdbeMakeReady(v,pParse->nVar,pParse->nMem+3,pParse->nTab+3,pParse->explain);
		pParse->rc=WN_SQL_DONE;
		pParse->colNamesSet=0;
	}
	else
		if(pParse->rc==0)pParse->rc=WN_SQL_ERROR;
		pParse->nTab=0;
		pParse->nMem=0;
		pParse->nSet=0;
		pParse->nVar=0;
		pParse->cookieMask=0;
		pParse->cookieGoto=0;
}
void WN_SQL3NestedParse(Parse *pParse,const char *zFormat,...)
{
	va_list ap;
	char *zSql;
# define SAVE_SZ(sizeof(Parse)-offsetof(Parse,nVar))
	char saveBuf[SAVE_SZ];
	if(pParse->nErr)return;
	va_start(ap,zFormat);
	zSql=WN_SQL3VMPrintf(zFormat,ap);
	va_end(ap);
	if(zSql==0)return;
	pParse->nested++;
	memcpy(saveBuf,&pParse->nVar,SAVE_SZ);
	memset(&pParse->nVar,0,SAVE_SZ);
	WN_SQL3RunParser(pParse,zSql,0);
	WN_SQL3FreeX(zSql);
	memcpy(&pParse->nVar,saveBuf,SAVE_SZ);
	pParse->nested--;
}
Table *WN_SQL3FindTable(WN_SQL3 *db,const char *zName,const char *zDatabase)
{
	Table *p=0;
	int i;
	for(i=OMIT_TEMPDB;i<db->nDb;i++)
	{
		int j=(i<2)? i^1 :i;
		if(zDatabase && WN_SQL3StrICmp(zDatabase,db->aDb[j].zName))continue;
		p=WN_SQL3HashFind(&db->aDb[j].pSchema->tblHash,zName,strlen(zName)+1);
		if(p)break;
	}
	return p;
}
Table *WN_SQL3LocateTable(Parse *pParse,const char *zName,const char *zDbase)
{
	Table *p;
	if(WN_SQL3ReadSchema(pParse))return 0;
	p=WN_SQL3FindTable(pParse->db,zName,zDbase);
	if(p==0)
	{
		if(zDbase)
			WN_SQL3ErrorMsg(pParse,"no such table:%s.%s",zDbase,zName);
		else
			WN_SQL3ErrorMsg(pParse,"no such table:%s",zName);
		pParse->checkSchema=1;
	}
	return p;
}
Index *WN_SQL3FindIndex(WN_SQL3 *db,const char *zName,const char *zDb)
{
	Index *p=0;
	int i;
	for(i=OMIT_TEMPDB;i<db->nDb;i++)
	{
		int j=(i<2)? i^1 :i;
		Schema *pSchema=db->aDb[j].pSchema;
		if(zDb && WN_SQL3StrICmp(zDb,db->aDb[j].zName))continue;
		if(pSchema)p=WN_SQL3HashFind(&pSchema->idxHash,zName,strlen(zName)+1);
		if(p)break;
	}
	return p;
}
void freeIndex(Index *p)
{
	WN_SQL3FreeX(p->zColAff);
	WN_SQL3FreeX(p);
}
void WN_SQLDeleteIndex(Index *p)
{
	const char *zName=p->zName;
	Index *pOld=WN_SQL3HashInsert(&p->pSchema->idxHash,zName,strlen(zName)+1,0);
	freeIndex(p);
}
void WN_SQL3UnlinkAndDeleteIndex(WN_SQL3 *db,int iDb,const char *zIdxName)
{
	int len=strlen(zIdxName);
	Hash *pHash=&db->aDb[iDb].pSchema->idxHash;
	Index *pIndex=WN_SQL3HashInsert(pHash,zIdxName,len+1,0);
	if(pIndex)
	{
		if(pIndex->pTable->pIndex==pIndex)
			pIndex->pTable->pIndex=pIndex->pNext;
		else
		{
			Index *p;
			for(p=pIndex->pTable->pIndex;p && p->pNext!=pIndex;p=p->pNext);
			if(p && p->pNext==pIndex)p->pNext=pIndex->pNext;
		}
		freeIndex(pIndex);
	}
	db->flags |=WN_SQL_InternChanges;
}
void WN_SQL3ResetInternalSchema(WN_SQL3 *db,int iDb)
{
	int i,j;
	for(i=iDb;i<db->nDb;i++)
	{
		Db *pDb=&db->aDb[i];
		if(pDb->pSchema)WN_SQL3SchemaFree(pDb->pSchema);
		if(iDb>0)return;
	}
	db->flags &=~WN_SQL_InternChanges;
	for(i=0;i<db->nDb;i++)
	{
		struct Db *pDb=&db->aDb[i];
		if(pDb->pBt==0)
		{
			if(pDb->pAux && pDb->xFreeAux)pDb->xFreeAux(pDb->pAux);
			pDb->pAux=0;
		}
	}
	for(i=j=2;i<db->nDb;i++)
	{
		struct Db *pDb=&db->aDb[i];
		if(pDb->pBt==0)
		{
			WN_SQL3FreeX(pDb->zName);
			pDb->zName=0;
			continue;
		}
		if(j<i)	db->aDb[j]=db->aDb[i];
		j++;
	}
	memset(&db->aDb[j],0,(db->nDb-j)*sizeof(db->aDb[j]));
	db->nDb=j;
	if(db->nDb<=2 && db->aDb!=db->aDbStatic)
	{
		memcpy(db->aDbStatic,db->aDb,2*sizeof(db->aDb[0]));
		WN_SQL3FreeX(db->aDb);
		db->aDb=db->aDbStatic;
	}
}
void WN_SQL3CommitInternalChanges(WN_SQL3 *db)
{
	db->flags &=~WN_SQL_InternChanges;
}
void WN_SQLResetColumnNames(Table *pTable)
{
	int i;
	Column *pCol;
	if((pCol=pTable->aCol))
	{
		for(i=0;i<pTable->nCol;i++,pCol++)
		{
			WN_SQL3FreeX(pCol->zName);
			WN_SQL3ExprDelete(pCol->pDflt);
			WN_SQL3FreeX(pCol->zType);
			WN_SQL3FreeX(pCol->zColl);
		}
		WN_SQL3FreeX(pTable->aCol);
	}
	pTable->aCol=0;
	pTable->nCol=0;
}
void WN_SQL3DeleteTable(Table *pTable)
{
	if(pTable==0)return;
	if(pTable->nRef>0)return;
	Index *pIndex,*pNext;
	FKey *pFKey,*pNextFKey;
	pTable->nRef--;
	for(pIndex=pTable->pIndex;pIndex;pIndex=pNext)
	{
		pNext=pIndex->pNext;
		WN_SQLDeleteIndex(pIndex);
	}
#ifndef WN_SQL_OMIT_FOREIGN_KEY
	for(pFKey=pTable->pFKey;pFKey;pFKey=pNextFKey)
	{
		pNextFKey=pFKey->pNextFrom;
		WN_SQL3FreeX(pFKey);
	}
#endif
	WN_SQLResetColumnNames(pTable);
	WN_SQL3FreeX(pTable->zName);
	WN_SQL3FreeX(pTable->zColAff);
	WN_SQL3SelectDelete(pTable->pSelect);
#ifndef WN_SQL_OMIT_CHECK
	WN_SQL3ExprDelete(pTable->pCheck);
#endif
	WN_SQL3VtabClear(pTable);
	WN_SQL3FreeX(pTable);
}
void WN_SQL3UnlinkAndDeleteTable(WN_SQL3 *db,int iDb,const char *zTabName)
{
	FKey *pF1,*pF2;
	Db *pDb=&db->aDb[iDb];
	Table *p=WN_SQL3HashInsert(&pDb->pSchema->tblHash,zTabName,strlen(zTabName)+1,0);
	if(p)
	{
#ifndef WN_SQL_OMIT_FOREIGN_KEY
		for(pF1=p->pFKey;pF1;pF1=pF1->pNextFrom)
		{
			int nTo=strlen(pF1->zTo)+1;
			pF2=WN_SQL3HashFind(&pDb->pSchema->aFKey,pF1->zTo,nTo);
			if(pF2==pF1)
				WN_SQL3HashInsert(&pDb->pSchema->aFKey,pF1->zTo,nTo,pF1->pNextTo);
			else
				while(pF2 && pF2->pNextTo!=pF1){pF2=pF2->pNextTo;}
					if(pF2)pF2->pNextTo=pF1->pNextTo;
		}
#endif
		WN_SQL3DeleteTable(p);
	}
	db->flags |=WN_SQL_InternChanges;
}
char *WN_SQL3NameFromToken(Token *pName)
{
	char *zName;
	if(pName)
	{
		zName=WN_SQLStrNDup((char*)pName->z,pName->n);
		WN_SQL3Dequote(zName);
	}
	else
		zName=0;
	return zName;
}
void WN_SQL3OpenMasterTable(Parse *p,int iDb)
{
	Vdbe *v=WN_SQL3GetVdbe(p);
	WN_SQL3TableLock(p,iDb,MASTER_ROOT,1,SCHEMA_TABLE(iDb));
	WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
	WN_SQL3VdbeAddOp(v,OP_OpenWrite,0,MASTER_ROOT);
	WN_SQL3VdbeAddOp(v,OP_SetNumColumns,0,5);
}
int WN_SQL3FindDb(WN_SQL3 *db,Token *pName)
{
	int i=-1;
	Db *pDb;
	char *zName=WN_SQL3NameFromToken(pName);
	if(zName)
	{
		int n=strlen(zName);
		for(i=(db->nDb-1),pDb=&db->aDb[i];i>=0;i--,pDb--)
			if((!OMIT_TEMPDB || i!=1)&& n==strlen(pDb->zName)&& 0==WN_SQL3StrICmp(pDb->zName,zName))break;
		WN_SQL3FreeX(zName);
	}
	return i;
}
int WN_SQL3TwoPartName(Parse *pParse,Token *pName1,Token *pName2,Token **pUnqual)
{
	int iDb;
	WN_SQL3 *db=pParse->db;
	if(pName2 && pName2->n>0)
	{
		*pUnqual=pName2;
		iDb=WN_SQL3FindDb(db,pName1);
		if(iDb<0)
		{
			WN_SQL3ErrorMsg(pParse,"unknown database %T",pName1);
			pParse->nErr++;
			return-1;
		}
	}
	else
	{
		iDb=db->init.iDb;
		*pUnqual=pName1;
	}
	return iDb;
}
int WN_SQL3CheckObjectName(Parse *pParse,const char *zName)
{
	if(!pParse->db->init.busy && pParse->nested==0 &&(pParse->db->flags & WN_SQL_WriteSchema)==0 && 0==WN_SQL3StrNICmp(zName,"WN_SQL_",7))
	{
		WN_SQL3ErrorMsg(pParse,"object name reserved for internal use:%s",zName);
		return WN_SQL_ERROR;
	}
	return 0;
}
void WN_SQL3StartTable(Parse *pParse,Token *pName1,Token *pName2,int isTemp,int isView,int isVirtual,int noErr)
{
	Table *pTable;
	WN_SQL3 *db=pParse->db;
	Vdbe *v;
	Token *pName;
	int iDb=WN_SQL3TwoPartName(pParse,pName1,pName2,&pName);
	if(iDb<0)return;
	if(!OMIT_TEMPDB && isTemp && iDb>1)
	{
		WN_SQL3ErrorMsg(pParse,"temporary table name must be unqualified");
		return;
	}
	if(!OMIT_TEMPDB && isTemp)iDb=1;
	pParse->sNameToken=*pName;
	char *zName=WN_SQL3NameFromToken(pName);
	if(zName==0)return;
	if(WN_SQL3CheckObjectName(pParse,zName))goto begin_table_error;
	if(db->init.iDb==1)isTemp=1;
#ifndef WN_SQL_OMIT_AUTHORIZATION
		char *zDb=db->aDb[iDb].zName;
		if(WN_SQL3AuthCheck(pParse,WN_SQL_INSERT,SCHEMA_TABLE(isTemp),0,zDb))goto begin_table_error;
		int code;
		if(isView)
		{
			if(!OMIT_TEMPDB && isTemp)
				code=WN_SQL_CREATE_TEMP_VIEW;
			else
				code=WN_SQL_CREATE_VIEW;
		}
		else
			if(!OMIT_TEMPDB && isTemp)
				code=WN_SQL_CREATE_TEMP_TABLE;
			else
				code=WN_SQL_CREATE_TABLE;
		if(!isVirtual && WN_SQL3AuthCheck(pParse,code,zName,0,zDb))goto begin_table_error;
#endif
	if(!IN_DECLARE_VTAB)
	{
		if(WN_SQL3ReadSchema(pParse))goto begin_table_error;
		pTable=WN_SQL3FindTable(db,zName,db->aDb[iDb].zName);
		if(pTable)
		{
			if(!noErr)WN_SQL3ErrorMsg(pParse,"table %T already exists",pName);
			goto begin_table_error;
		}
		if(WN_SQL3FindIndex(db,zName,0)&&(iDb==0 || !db->init.busy))
		{
			WN_SQL3ErrorMsg(pParse,"there is already an index named %s",zName);
			goto begin_table_error;
		}
	}
	pTable=WN_SQL3Malloc(sizeof(Table));
	if(pTable==0)
	{
		pParse->rc=WN_SQL_NOMEM;
		pParse->nErr++;
		goto begin_table_error;
	}
	pTable->zName=zName;
	pTable->iPKey=-1;
	pTable->pSchema=db->aDb[iDb].pSchema;
	pTable->nRef=1;
	if(pParse->pNewTable)WN_SQL3DeleteTable(pParse->pNewTable);
	pParse->pNewTable=pTable;
#ifndef WN_SQL_OMIT_AUTOINCREMENT
	if(!pParse->nested && strcmp(zName,"WN_SQL_sequence")==0)pTable->pSchema->pSeqTab=pTable;
#endif
	if(!db->init.busy &&(v=WN_SQL3GetVdbe(pParse)))
	{
		WN_SQL3BeginWriteOperation(pParse,0,iDb);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		if(isVirtual)WN_SQL3VdbeAddOp(v,OP_VBegin,0,0);
#endif
		WN_SQL3VdbeAddOp(v,OP_ReadCookie,iDb,1);
		int lbl=WN_SQL3VdbeMakeLabel(v);
		WN_SQL3VdbeAddOp(v,OP_If,0,lbl);
		int fileFormat=(db->flags & WN_SQL_LegacyFileFmt) ? 1 :WN_SQL_MAX_FILE_FORMAT;
		WN_SQL3VdbeAddOp(v,OP_Integer,fileFormat,0);
		WN_SQL3VdbeAddOp(v,OP_SetCookie,iDb,1);
		WN_SQL3VdbeAddOp(v,OP_Integer,ENC(db),0);
		WN_SQL3VdbeAddOp(v,OP_SetCookie,iDb,4);
		WN_SQL3VdbeResolveLabel(v,lbl);
#if !defined(WN_SQL_OMIT_VIEW)|| !defined(WN_SQL_OMIT_VIRTUALTABLE)
		if(isView || isVirtual)
			WN_SQL3VdbeAddOp(v,OP_Integer,0,0);
		else
#endif
		WN_SQL3VdbeAddOp(v,OP_CreateTable,iDb,0);
		WN_SQL3OpenMasterTable(pParse,iDb);
		WN_SQL3VdbeAddOp(v,OP_NewRowid,0,0);
		WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
		WN_SQL3VdbeAddOp(v,OP_Null,0,0);
		WN_SQL3VdbeAddOp(v,OP_Insert,0,OPFLAG_APPEND);
		WN_SQL3VdbeAddOp(v,OP_Close,0,0);
		WN_SQL3VdbeAddOp(v,OP_Pull,1,0);
	}
	return;
begin_table_error:
	WN_SQL3FreeX(zName);
	return;
}
#define STRICMP(x,y) (\
WN_SQL3UpperToLower[*(unsigned char *)(x)]==\
WN_SQL3UpperToLower[*(unsigned char *)(y)] \
&& WN_SQL3StrICmp((x)+1,(y)+1)==0)
void WN_SQL3AddColumn(Parse *pParse,Token *pName)
{
	Table *p=pParse->pNewTable
	if((p==0)return;
	if(p->nCol+1>WN_SQL_MAX_COLUMN)
	{
		WN_SQL3ErrorMsg(pParse,"too many columns on %s",p->zName);
		return;
	}
	char *z=WN_SQL3NameFromToken(pName);
	if(z==0)return;
	int i;
	for(i=0;i<p->nCol;i++)
		if(STRICMP(z,p->aCol[i].zName))
		{
			WN_SQL3ErrorMsg(pParse,"duplicate column name:%s",z);
			WN_SQL3FreeX(z);
			return;
		}
	if((p->nCol & 0x7)==0)
	{
		Column *aNew=WN_SQLRealloc(p->aCol,(p->nCol+8)*sizeof(p->aCol[0]));
		if(aNew==0)
		{
			WN_SQL3FreeX(z);
			return;
		}
		p->aCol=aNew;
	}
	Column *pCol=&p->aCol[p->nCol];
	memset(pCol,0,sizeof(p->aCol[0]));
	pCol->zName=z;
	pCol->affinity=WN_SQL_AFF_NONE;
	p->nCol++;
}
void WN_SQL3AddNotNull(Parse *pParse,int onError)
{
	Table *p;
	if((p=pParse->pNewTable)==0)return;
	int i=p->nCol-1;
	if(i>=0)p->aCol[i].notNull=onError;
}
char WN_SQL3AffinityType(const Token *pType)
{
	u32 h=0;
	char aff=WN_SQL_AFF_NUMERIC;
	const unsigned char *zIn=pType->z,*zEnd=&pType->z[pType->n];
	while(zIn!=zEnd)
	{
		h=(h<<8)+WN_SQL3UpperToLower[*zIn];
		zIn++;
		if(h==(('c'<<24)+('h'<<16)+('a'<<8)+'r'))
			aff=WN_SQL_AFF_TEXT;
		else
			if(h==(('c'<<24)+('l'<<16)+('o'<<8)+'b'))
				aff=WN_SQL_AFF_TEXT;
			else
				if(h==(('t'<<24)+('e'<<16)+('x'<<8)+'t'))
					aff=WN_SQL_AFF_TEXT;
				else
					if(h==(('b'<<24)+('l'<<16)+('o'<<8)+'b')&&(aff==WN_SQL_AFF_NUMERIC || aff==WN_SQL_AFF_REAL))
						aff=WN_SQL_AFF_NONE;
#ifndef WN_SQL_OMIT_FLOATING_POINT
					else
						if(h==(('r'<<24)+('e'<<16)+('a'<<8)+'l')&& aff==WN_SQL_AFF_NUMERIC)
							aff=WN_SQL_AFF_REAL;
						else
							if(h==(('f'<<24)+('l'<<16)+('o'<<8)+'a')&& aff==WN_SQL_AFF_NUMERIC)
								aff=WN_SQL_AFF_REAL;
							else
								if(h==(('d'<<24)+('o'<<16)+('u'<<8)+'b')&& aff==WN_SQL_AFF_NUMERIC)
									aff=WN_SQL_AFF_REAL;
#endif
								else
									if((h&0x00FFFFFF)==(('i'<<16)+('n'<<8)+'t'))
									{
										aff=WN_SQL_AFF_INTEGER;
										break;
									}
	}
	return aff;
}
void WN_SQL3AddColumnType(Parse *pParse,Token *pType)
{
	Table *p;
	if((p=pParse->pNewTable)==0)return;
	int i=p->nCol-1;
	if(i<0)return;
	Column *pCol=&p->aCol[i];
	WN_SQL3FreeX(pCol->zType);
	pCol->zType=WN_SQL3NameFromToken(pType);
	pCol->affinity=WN_SQL3AffinityType(pType);
}
void WN_SQL3AddDefaultValue(Parse *pParse,Expr *pExpr)
{
	Table *p=pParse->pNewTable;
	Column *pCol;
	if(p)
	{
		pCol=&(p->aCol[p->nCol-1]);
		if(!WN_SQL3ExprIsConstantOrFunction(pExpr))
			WN_SQL3ErrorMsg(pParse,"default value of column [%s] is not constant",pCol->zName);
		else
		{
			Expr *pCopy;
			WN_SQL3ExprDelete(pCol->pDflt);
			pCol->pDflt=pCopy=WN_SQL3ExprDup(pExpr);
			if(pCopy)WN_SQL3TokenCopy(&pCopy->span,&pExpr->span);
		}
	}
	WN_SQL3ExprDelete(pExpr);
}
void WN_SQL3AddPrimaryKey(Parse *pParse,ExprList *pList,int onError,int autoInc,int sortOrder)
{
	Table *pTab=pParse->pNewTable;
	if(pTab==0 || IN_DECLARE_VTAB)goto primary_key_exit;
	char *zType=0;
	int iCol=-1,i;
	if(pTab->hasPrimKey)
	{
		WN_SQL3ErrorMsg(pParse,"table \"%s\" has more than one primary key",pTab->zName);
		goto primary_key_exit;
	}
	pTab->hasPrimKey=1;
	if(pList==0)
	{
		iCol=pTab->nCol-1;
		pTab->aCol[iCol].isPrimKey=1;
	}
	else
	{
		for(i=0;i<pList->nExpr;i++)
		{
			for(iCol=0;iCol<pTab->nCol;iCol++)
				if(WN_SQL3StrICmp(pList->a[i].zName,pTab->aCol[iCol].zName)==0)
					break;
			if(iCol<pTab->nCol)pTab->aCol[iCol].isPrimKey=1;
		}
		if(pList->nExpr>1)iCol=-1;
	}
	if(iCol>=0 && iCol<pTab->nCol) zType=pTab->aCol[iCol].zType;
	if(zType && WN_SQL3StrICmp(zType,"INTEGER")==0 && sortOrder==WN_SQL_SO_ASC)
	{
		pTab->iPKey=iCol;
		pTab->keyConf=onError;
		pTab->autoInc=autoInc;
	}
	else
		if(autoInc)
		{
#ifndef WN_SQL_OMIT_AUTOINCREMENT
			WN_SQL3ErrorMsg(pParse,"AUTOINCREMENT is only allowed on an "
				"INTEGER PRIMARY KEY");
#endif
		}
		else
		{
			WN_SQL3CreateIndex(pParse,0,0,0,pList,onError,0,0,sortOrder,0);
			pList=0;
		}
primary_key_exit:
	WN_SQL3ExprListDelete(pList);
	return;
}
void WN_SQL3AddCheckConstraint(Parse *pParse,Expr *pCheckExpr)
{
#ifndef WN_SQL_OMIT_CHECK
	Table *pTab=pParse->pNewTable;
	if(pTab && !IN_DECLARE_VTAB)pTab->pCheck=WN_SQL3ExprAnd(pTab->pCheck,WN_SQL3ExprDup(pCheckExpr));
#endif
	WN_SQL3ExprDelete(pCheckExpr);
}
void WN_SQL3AddCollateType(Parse *pParse,const char *zType,int nType)
{
	Table *p=pParse->pNewTable;
	if(p==0)return;
	int i=p->nCol-1;
	if(WN_SQL3LocateCollSeq(pParse,zType,nType))
	{
		Index *pIdx;
		p->aCol[i].zColl=WN_SQLStrNDup(zType,nType);
		for(pIdx=p->pIndex;pIdx;pIdx=pIdx->pNext) if(pIdx->aiColumn[0]==i)pIdx->azColl[0]=p->aCol[i].zColl;
	}
}
CollSeq *WN_SQL3LocateCollSeq(Parse *pParse,const char *zName,int nName)
{
	WN_SQL3 *db=pParse->db;
	u8 enc=ENC(db),initbusy=db->init.busy;
	CollSeq *pColl=WN_SQL3FindCollSeq(db,enc,zName,nName,initbusy);
	if(!initbusy &&(!pColl || !pColl->xCmp))
	{
		pColl=WN_SQL3GetCollSeq(db,pColl,zName,nName);
		if(!pColl)
		{
			if(nName<0)
			{
				nName=strlen(zName);
			}
			WN_SQL3ErrorMsg(pParse,"no such collation sequence:%.*s",nName,zName);
			pColl=0;
		}
	}
	return pColl;
}
void WN_SQL3ChangeCookie(WN_SQL3 *db,Vdbe *v,int iDb)
{
	WN_SQL3VdbeAddOp(v,OP_Integer,db->aDb[iDb].pSchema->schema_cookie+1,0);
	WN_SQL3VdbeAddOp(v,OP_SetCookie,iDb,0);
}
int identLength(const char *z)
{
	int n;
	for(n=0;*z;n++,z++)if(*z=='"')n++;
	return n+2;
}
void identPut(char *z,int *pIdx,char *zSignedIdent)
{
	unsigned char *zIdent=(unsigned char*)zSignedIdent;
	int i=*pIdx,j;
	for(j=0;zIdent[j];j++)if(!isalnum(zIdent[j])&& zIdent[j]!='_')break;
	int needQuote=zIdent[j] || isdigit(zIdent[0])|| WN_SQL3KeywordCode(zIdent,j)!=TK_ID;
	if(needQuote)z[i++]='"';
	for(j=0;zIdent[j];j++)
	{
		z[i++]=zIdent[j];
		if(zIdent[j]=='"')z[i++]='"';
	}
	if(needQuote)z[i++]='"';
	z[i]=0;
	*pIdx=i;
}
char *createTableStmt(Table *p,int isTemp)
{
	int i,k,n=0;
	char *zStmt,*zSep,*zSep2,*zEnd,*z;
	Column *pCol;
	for(pCol=p->aCol,i=0;i<p->nCol;i++,pCol++)
	{
		n+=identLength(pCol->zName);
		z=pCol->zType;
		if(z)n+=(strlen(z)+1);
	}
	n+=identLength(p->zName);
	if(n<50)
	{
		zSep="";
		zSep2=",";
		zEnd=")";
	}
	else
	{
		zSep="\n ";
		zSep2=",\n ";
		zEnd="\n)";
	}
	n+=35+6*p->nCol;
	zStmt=WN_SQLMallocRaw(n);
	if(zStmt==0)return 0;
	WN_SQL3_snprintf(n,zStmt,!OMIT_TEMPDB&&isTemp ? "CREATE TEMP TABLE ":"CREATE TABLE ");
	k=strlen(zStmt);
	identPut(zStmt,&k,p->zName);
	zStmt[k++]='(';
	for(pCol=p->aCol,i=0;i<p->nCol;i++,pCol++)
	{
		WN_SQL3_snprintf(n-k,&zStmt[k],zSep);
		k+=strlen(&zStmt[k]);
		zSep=zSep2;
		identPut(zStmt,&k,pCol->zName);
		if((z=pCol->zType))
		{
			zStmt[k++]=' ';
			WN_SQL3_snprintf(n-k,&zStmt[k],"%s",z);
			k+=strlen(z);
		}
	}
	WN_SQL3_snprintf(n-k,&zStmt[k],"%s",zEnd);
	return zStmt;
}
void WN_SQL3EndTable(Parse *pParse,Token *pCons,Token *pEnd,Select *pSelect )
{
	WN_SQL3 *db=pParse->db;
	if((pEnd==0 && pSelect==0)|| pParse->nErr || WN_SQL3MallocFailed())	return;
	Table *p=pParse->pNewTable;
	if(p==0)return;
	int iDb=WN_SQL3SchemaToIndex(db,p->pSchema);
#ifndef WN_SQL_OMIT_CHECK
	if(p->pCheck)
	{
		SrcList sSrc;
		NameContext sNC;
		memset(&sNC,0,sizeof(sNC));
		memset(&sSrc,0,sizeof(sSrc));
		sSrc.nSrc=1;
		sSrc.a[0].zName=p->zName;
		sSrc.a[0].pTab=p;
		sSrc.a[0].iCursor=-1;
		sNC.pParse=pParse;
		sNC.pSrcList=&sSrc;
		sNC.isCheck=1;
		if(WN_SQL3ExprResolveNames(&sNC,p->pCheck))return;
	}
#endif
	if(db->init.busy)p->tnum=db->init.newTnum;
	if(!db->init.busy)
	{
		Vdbe *v=WN_SQL3GetVdbe(pParse);
		if(v==0)return;
		int n;
		char *zType,*zType2,*zStmt;
		WN_SQL3VdbeAddOp(v,OP_Close,0,0);
		if(p->pSelect==0)
		{
			zType="table";
			zType2="TABLE";
#ifndef WN_SQL_OMIT_VIEW
		}
		else
		{
			zType="view";
			zType2="VIEW";
#endif
		}
		if(pSelect)
		{
			Table *pSelTab;
			WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
			WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
			WN_SQL3VdbeAddOp(v,OP_OpenWrite,1,0);
			pParse->nTab=2;
			WN_SQL3Select(pParse,pSelect,SRT_Table,1,0,0,0,0);
			WN_SQL3VdbeAddOp(v,OP_Close,1,0);
			if(pParse->nErr==0)
			{
				pSelTab=WN_SQL3ResultSetOfSelect(pParse,0,pSelect);
				if(pSelTab==0)return;
				p->nCol=pSelTab->nCol;
				p->aCol=pSelTab->aCol;
				pSelTab->nCol=0;
				pSelTab->aCol=0;
				WN_SQL3DeleteTable(pSelTab);
			}
		}
		if(pSelect)
			zStmt=createTableStmt(p,p->pSchema==pParse->db->aDb[1].pSchema);
		else
		{
			n=pEnd->z-pParse->sNameToken.z+1;
			zStmt=WN_SQL3MPrintf("CREATE %s %.*s",zType2,n,pParse->sNameToken.z);
		}
		WN_SQL3NestedParse(pParse,"UPDATE %Q.%s "
"SET type='%s',name=%Q,tbl_name=%Q,rootpage=#0,sql=%Q "
"WHERE rowid=#1",db->aDb[iDb].zName,SCHEMA_TABLE(iDb),zType,p->zName,p->zName,zStmt);
		WN_SQL3FreeX(zStmt);
		WN_SQL3ChangeCookie(db,v,iDb);
#ifndef WN_SQL_OMIT_AUTOINCREMENT
		if(p->autoInc)
		{
			Db *pDb=&db->aDb[iDb];
			if(pDb->pSchema->pSeqTab==0)WN_SQL3NestedParse(pParse,"CREATE TABLE %Q.WN_SQL_sequence(name,seq)",pDb->zName);
		}
#endif
		WN_SQL3VdbeOp3(v,OP_ParseSchema,iDb,0,WN_SQL3MPrintf("tbl_name='%q'",p->zName),P3_DYNAMIC);
	}
	if(db->init.busy && pParse->nErr==0)
	{
		FKey *pFKey;
		Schema *pSchema=p->pSchema;
		Table *pOld=WN_SQL3HashInsert(&pSchema->tblHash,p->zName,strlen(p->zName)+1,p);
		if(pOld)return;
#ifndef WN_SQL_OMIT_FOREIGN_KEY
		for(pFKey=p->pFKey;pFKey;pFKey=pFKey->pNextFrom)
		{
			int nTo=strlen(pFKey->zTo)+1;
			pFKey->pNextTo=WN_SQL3HashFind(&pSchema->aFKey,pFKey->zTo,nTo);
			WN_SQL3HashInsert(&pSchema->aFKey,pFKey->zTo,nTo,pFKey);
		}
#endif
		pParse->pNewTable=0;
		db->nTable++;
		db->flags |=WN_SQL_InternChanges;
#ifndef WN_SQL_OMIT_ALTERTABLE
		if(!p->pSelect)
		{
			const char *zName=(const char *)pParse->sNameToken.z;
			if(pCons->z==0)pCons=pEnd;
			int nName=(const char *)pCons->z-zName;
			p->addColOffset=13+WN_SQL3Utf8CharLen(zName,nName);
		}
#endif
	}
}
#ifndef WN_SQL_OMIT_VIEW
void WN_SQL3CreateView(Parse *pParse,Token *pBegin,Token *pName1,Token *pName2,Select *pSelect,int isTemp,int noErr)
{
	DbFixer sFix;
	Token *pName;
	if(pParse->nVar>0)
	{
		WN_SQL3ErrorMsg(pParse,"parameters are not allowed in views");
		WN_SQL3SelectDelete(pSelect);
		return;
	}
	WN_SQL3StartTable(pParse,pName1,pName2,isTemp,1,0,noErr);
	Table *p=pParse->pNewTable;
	if(p==0 || pParse->nErr)
	{
		WN_SQL3SelectDelete(pSelect);
		return;
	}
	WN_SQL3TwoPartName(pParse,pName1,pName2,&pName);
	int iDb=WN_SQL3SchemaToIndex(pParse->db,p->pSchema);
	if(WN_SQL3FixInit(&sFix,pParse,iDb,"view",pName)&& WN_SQL3FixSelect(&sFix,pSelect))
	{
		WN_SQL3SelectDelete(pSelect);
		return;
	}
	p->pSelect=WN_SQL3SelectDup(pSelect);
	WN_SQL3SelectDelete(pSelect);
	if(WN_SQL3MallocFailed())return;
	if(!pParse->db->init.busy)WN_SQL3ViewGetColumnNames(pParse,p);
	Token sEnd=pParse->sLastToken;
	if(sEnd.z[0] && sEnd.z[0]!=';')sEnd.z+=sEnd.n;
	sEnd.n=0;
	int n=sEnd.z-pBegin->z;
	const unsigned char *z=(const unsigned char*)pBegin->z;
	while(n>0 &&(z[n-1]==';' || isspace(z[n-1])))n--;
	sEnd.z=&z[n-1];
	sEnd.n=1;
	WN_SQL3EndTable(pParse,0,&sEnd,0);
	return;
}
#endif
#if !defined(WN_SQL_OMIT_VIEW)|| !defined(WN_SQL_OMIT_VIRTUALTABLE)
int WN_SQL3ViewGetColumnNames(Parse *pParse,Table *pTable)
{
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(WN_SQL3VtabCallConnect(pParse,pTable))return WN_SQL_ERROR;
	if(IsVirtual(pTable))return 0;
#endif
#ifndef WN_SQL_OMIT_VIEW
	if(pTable->nCol>0)return 0;
	if(pTable->nCol<0)
	{
		WN_SQL3ErrorMsg(pParse,"view %s is circularly defined",pTable->zName);
		return 1;
	}
	Select *pSel=WN_SQL3SelectDup(pTable->pSelect);
	int nErr=0,n;
	Table *pSelTab;
	if(pSel)
	{
		n=pParse->nTab;
		WN_SQL3SrcListAssignCursors(pParse,pSel->pSrc);
		pTable->nCol=-1;
		pSelTab=WN_SQL3ResultSetOfSelect(pParse,0,pSel);
		pParse->nTab=n;
		if(pSelTab)
		{
			pTable->nCol=pSelTab->nCol;
			pTable->aCol=pSelTab->aCol;
			pSelTab->nCol=pSelTab->aCol=0;
			WN_SQL3DeleteTable(pSelTab);
			pTable->pSchema->flags |=DB_UnresetViews;
		}
		else
		{
			pTable->nCol=0;
			nErr++;
		}
		WN_SQL3SelectDelete(pSel);
	}
	else
		nErr++;
#endif
	return nErr;
}
#endif
#ifndef WN_SQL_OMIT_VIEW
void WN_SQLViewResetAll(WN_SQL3 *db,int idx)
{
	if(!DbHasProperty(db,idx,DB_UnresetViews))return;
	HashElem *i;
	for(i=WN_SQLHashFirst(&db->aDb[idx].pSchema->tblHash);i;i=WN_SQLHashNext(i))
	{
		Table *pTab=WN_SQLHashData(i);
		if(pTab->pSelect)WN_SQLResetColumnNames(pTab);
	}
	DbClearProperty(db,idx,DB_UnresetViews);
}
#else
# define WN_SQLViewResetAll(A,B)
#endif
#ifndef WN_SQL_OMIT_AUTOVACUUM
void WN_SQL3RootPageMoved(Db *pDb,int iFrom,int iTo)
{
	HashElem *pElem;
	Hash *pHash=&pDb->pSchema->tblHash;
	for(pElem=WN_SQLHashFirst(pHash);pElem;pElem=WN_SQLHashNext(pElem))
	{
		Table *pTab=WN_SQLHashData(pElem);
		if(pTab->tnum==iFrom)pTab->tnum=iTo;
	}
	pHash=&pDb->pSchema->idxHash;
	for(pElem=WN_SQLHashFirst(pHash);pElem;pElem=WN_SQLHashNext(pElem))
	{
		Index *pIdx=WN_SQLHashData(pElem);
		if(pIdx->tnum==iFrom)pIdx->tnum=iTo;
	}
}
#endif
void destroyRootPage(Parse *pParse,int iTable,int iDb)
{
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	WN_SQL3VdbeAddOp(v,OP_Destroy,iTable,iDb);
#ifndef WN_SQL_OMIT_AUTOVACUUM
	WN_SQL3NestedParse(pParse,"UPDATE %Q.%s SET rootpage=%d WHERE #0 AND rootpage=#0",pParse->db->aDb[iDb].zName,SCHEMA_TABLE(iDb),iTable);
#endif
}
void destroyTable(Parse *pParse,Table *pTab)
{
#ifdef WN_SQL_OMIT_AUTOVACUUM
	Index *pIdx;
	int Db=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
	destroyRootPage(pParse,pTab->tnum,iDb);
	for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)destroyRootPage(pParse,pIdx->tnum,iDb);
#else
	int iTab=pTab->tnum,iDestroyed=0;
	while(1)
	{
		Index *pIdx;
		int iLargest=0;
		if(iDestroyed==0 || iTab<iDestroyed)iLargest=iTab;
		int iIdx;
		for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)
		{
			iIdx=pIdx->tnum;
			if((iDestroyed==0 ||(iIdx<iDestroyed))&& iIdx>iLargest)
				iLargest=iIdx;
		}
		if(iLargest==0)
			return;
		else
		{
			int iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
			destroyRootPage(pParse,iLargest,iDb);
			iDestroyed=iLargest;
		}
	}
#endif
}
void WN_SQL3DropTable(Parse *pParse,SrcList *pName,int isView,int noErr)
{
	if(pParse->nErr || WN_SQL3MallocFailed())goto exit_drop_table;
	WN_SQL3 *db=pParse->db;
	Table *pTab=WN_SQL3LocateTable(pParse,pName->a[0].zName,pName->a[0].zDatabase);
	if(pTab==0)
	{
		if(noErr)WN_SQL3ErrorClear(pParse);
		goto exit_drop_table;
	}
	int iDb=WN_SQL3SchemaToIndex(db,pTab->pSchema);
#ifndef WN_SQL_OMIT_AUTHORIZATION
	{
		const char *zTab=SCHEMA_TABLE(iDb),*zDb=db->aDb[iDb].zName,*zArg2=0;
		if(WN_SQL3AuthCheck(pParse,WN_SQL_DELETE,zTab,0,zDb))goto exit_drop_table;
		int code;
		if(isView)
		{
			if(!OMIT_TEMPDB && iDb==1)
				code=WN_SQL_DROP_TEMP_VIEW;
			else
				code=WN_SQL_DROP_VIEW;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		}
		else
			if(IsVirtual(pTab))
			{
				if(WN_SQL3ViewGetColumnNames(pParse,pTab))goto exit_drop_table;
				code=WN_SQL_DROP_VTABLE;
				zArg2=pTab->pMod->zName;
#endif
			}
			else
			{
				if(!OMIT_TEMPDB && iDb==1)
					code=WN_SQL_DROP_TEMP_TABLE;
				else
					code=WN_SQL_DROP_TABLE;
			}
			if(WN_SQL3AuthCheck(pParse,code,pTab->zName,zArg2,zDb))goto exit_drop_table;
			if(WN_SQL3AuthCheck(pParse,WN_SQL_DELETE,pTab->zName,0,zDb))goto exit_drop_table;
	}
#endif
	if(pTab->readOnly || pTab==db->aDb[iDb].pSchema->pSeqTab)
	{
		WN_SQL3ErrorMsg(pParse,"table %s may not be dropped",pTab->zName);
		goto exit_drop_table;
	}
#ifndef WN_SQL_OMIT_VIEW
	if(isView && pTab->pSelect==0)
	{
		WN_SQL3ErrorMsg(pParse,"use DROP TABLE to delete table %s",pTab->zName);
		goto exit_drop_table;
	}
	if(!isView && pTab->pSelect)
	{
		WN_SQL3ErrorMsg(pParse,"use DROP VIEW to delete view %s",pTab->zName);
		goto exit_drop_table;
	}
#endif
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v)
	{
		Db *pDb=&db->aDb[iDb];
		WN_SQL3BeginWriteOperation(pParse,0,iDb);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		if(IsVirtual(pTab))
		{
			Vdbe *v=WN_SQL3GetVdbe(pParse);
			if(v)WN_SQL3VdbeAddOp(v,OP_VBegin,0,0);
		}
#endif
		Trigger *pTrigger=pTab->pTrigger;
		while(pTrigger)
		{
			pTrigger->pSchema==db->aDb[1].pSchema);
			WN_SQL3DropTriggerPtr(pParse,pTrigger);
			pTrigger=pTrigger->pNext;
		}
#ifndef WN_SQL_OMIT_AUTOINCREMENT
		if(pTab->autoInc)WN_SQL3NestedParse(pParse,"DELETE FROM %s.WN_SQL_sequence WHERE name=%Q",pDb->zName,pTab->zName);
#endif
		WN_SQL3NestedParse(pParse,"DELETE FROM %Q.%s WHERE tbl_name=%Q and type!='trigger'",pDb->zName,SCHEMA_TABLE(iDb),pTab->zName);
		if(!isView && !IsVirtual(pTab))destroyTable(pParse,pTab);
		if(IsVirtual(pTab))WN_SQL3VdbeOp3(v,OP_VDestroy,iDb,0,pTab->zName,0);
		WN_SQL3VdbeOp3(v,OP_DropTable,iDb,0,pTab->zName,0);
		WN_SQL3ChangeCookie(db,v,iDb);
	}
	WN_SQLViewResetAll(db,iDb);
exit_drop_table:
	WN_SQL3SrcListDelete(pName);
}
void WN_SQL3CreateForeignKey(Parse *pParse,ExprList *pFromCol,Token *pTo,ExprList *pToCol,int flags)
{
#ifndef WN_SQL_OMIT_FOREIGN_KEY
	Table *p=pParse->pNewTable;
	if(p==0 || pParse->nErr || IN_DECLARE_VTAB)goto fk_end;
	FKey *pFKey=0;
	if(pFromCol==0)
	{
		int iCol=p->nCol-1;
		if(iCol<0)goto fk_end;
		if(pToCol && pToCol->nExpr!=1)
		{
			WN_SQL3ErrorMsg(pParse,"foreign key on %s"
" should reference only one column of table %T",p->aCol[iCol].zName,pTo);
			goto fk_end;
		}
		nCol=1;
	}
	else
		if(pToCol && pToCol->nExpr!=pFromCol->nExpr)
		{
			WN_SQL3ErrorMsg(pParse,"number of columns in foreign key does not match the number of "
"columns in the referenced table");
			goto fk_end;
		}
		else
			nCol=pFromCol->nExpr;
	nByte=sizeof(*pFKey)+nCol*sizeof(pFKey->aCol[0])+pTo->n+1;
	if(pToCol)
		for(i=0;i<pToCol->nExpr;i++)nByte+=strlen(pToCol->a[i].zName)+1;
	pFKey=WN_SQL3Malloc(nByte);
	if(pFKey==0)goto fk_end;
	pFKey->pFrom=p;
	pFKey->pNextFrom=p->pFKey;
	z=(char*)&pFKey[1];
	pFKey->aCol=(struct sColMap*)z;
	z+=sizeof(struct sColMap)*nCol;
	pFKey->zTo=z;
	memcpy(z,pTo->z,pTo->n);
	z[pTo->n]=0;
	z+=pTo->n+1;
	pFKey->pNextTo=0;
	pFKey->nCol=nCol;
	if(pFromCol==0)
		pFKey->aCol[0].iFrom=p->nCol-1;
	else
	{
		for(i=0;i<nCol;i++)
		{
			int j;
			for(j=0;j<p->nCol;j++)
				if(WN_SQL3StrICmp(p->aCol[j].zName,pFromCol->a[i].zName)==0)
				{
					pFKey->aCol[i].iFrom=j;
					break;
				}
			if(j>=p->nCol)
			{
				WN_SQL3ErrorMsg(pParse,"unknown column \"%s\" in foreign key definition",pFromCol->a[i].zName);
				goto fk_end;
			}
		}
	}
	if(pToCol)
		for(i=0;i<nCol;i++)
		{
			int n=strlen(pToCol->a[i].zName);
			pFKey->aCol[i].zCol=z;
			memcpy(z,pToCol->a[i].zName,n);
			z[n]=0;
			z+=n+1;
		}
		pFKey->isDeferred=0;
		pFKey->deleteConf=flags & 0xff;
		pFKey->updateConf=(flags >> 8)& 0xff;
		pFKey->insertConf=(flags >> 16)& 0xff;
		p->pFKey=pFKey;
		pFKey=0;
fk_end:
		WN_SQL3FreeX(pFKey);
#endif
		WN_SQL3ExprListDelete(pFromCol);
		WN_SQL3ExprListDelete(pToCol);
}
void WN_SQL3DeferForeignKey(Parse *pParse,int isDeferred)
{
#ifndef WN_SQL_OMIT_FOREIGN_KEY
	Table *pTab;
	FKey *pFKey;
	if(!(pTab=pParse->pNewTable && pFKey=pTab->pFKey))return;
	pFKey->isDeferred=isDeferred;
#endif
}
void WN_SQL3RefillIndex(Parse *pParse,Index *pIndex,int memRootPage)
{
	Table *pTab=pIndex->pTable;
	int iTab=pParse->nTab,iIdx=pParse->nTab+1,addr1,tnum;
	Vdbe *v;
	KeyInfo *pKey;
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pIndex->pSchema);
#ifndef WN_SQL_OMIT_AUTHORIZATION
	if(WN_SQL3AuthCheck(pParse,WN_SQL_REINDEX,pIndex->zName,0,pParse->db->aDb[iDb].zName))return;
#endif
	WN_SQL3TableLock(pParse,iDb,pTab->tnum,1,pTab->zName);
	v=WN_SQL3GetVdbe(pParse);
	if(v==0)return;
	if(memRootPage>=0)
	{
		WN_SQL3VdbeAddOp(v,OP_MemLoad,memRootPage,0);
		tnum=0;
	}
	else
	{
		tnum=pIndex->tnum;
		WN_SQL3VdbeAddOp(v,OP_Clear,tnum,iDb);
	}
	WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
	pKey=WN_SQL3IndexKeyinfo(pParse,pIndex);
	WN_SQL3VdbeOp3(v,OP_OpenWrite,iIdx,tnum,(char *)pKey,P3_KEYINFO_HANDOFF);
	WN_SQL3OpenTable(pParse,iTab,iDb,pTab,OP_OpenRead);
	addr1=WN_SQL3VdbeAddOp(v,OP_Rewind,iTab,0);
	WN_SQL3GenerateIndexKey(v,pIndex,iTab);
	if(pIndex->onError!=OE_None)
	{	int curaddr=WN_SQL3VdbeCurrentAddr(v),addr2=curaddr+4;
		WN_SQL3VdbeChangeP2(v,curaddr-1,addr2);
		WN_SQL3VdbeAddOp(v,OP_Rowid,iTab,0);
		WN_SQL3VdbeAddOp(v,OP_AddImm,1,0);
		WN_SQL3VdbeAddOp(v,OP_IsUnique,iIdx,addr2);
		WN_SQL3VdbeOp3(v,OP_Halt,WN_SQL_CONSTRAINT,OE_Abort,"indexed columns are not unique",P3_STATIC);
	}
	WN_SQL3VdbeAddOp(v,OP_IdxInsert,iIdx,0);
	WN_SQL3VdbeAddOp(v,OP_Next,iTab,addr1+1);
	WN_SQL3VdbeJumpHere(v,addr1);
	WN_SQL3VdbeAddOp(v,OP_Close,iTab,0);
	WN_SQL3VdbeAddOp(v,OP_Close,iIdx,0);
}
void WN_SQL3CreateIndex(Parse *pParse,Token *pName1,Token *pName2,SrcList *pTblName,ExprList *pList,int onError,Token *pStart,Token *pEnd,int sortOrder,int ifNotExist)
{
	Table *pTab=0;
	Index *pIndex=0;
	char *zName=0;
	int sortOrderMask,nName,i,j;
	Token nullId;
	DbFixer sFix;
	WN_SQL3 *db=pParse->db;
	Db *pDb;
	int iDb;
	Token *pName=0;
	struct ExprList_item *pListItem;
	int nCol,nExtra=0;
	char *zExtra;
	if(pParse->nErr || WN_SQL3MallocFailed()|| IN_DECLARE_VTAB)goto exit_create_index;
	if(pTblName)
	{
		iDb=WN_SQL3TwoPartName(pParse,pName1,pName2,&pName);
		if(iDb<0)goto exit_create_index;
#ifndef WN_SQL_OMIT_TEMPDB
		pTab=WN_SQL3SrcListLookup(pParse,pTblName);
		if(pName2 && pName2->n==0 && pTab && pTab->pSchema==db->aDb[1].pSchema)iDb=1;
#endif
		if(WN_SQL3FixInit(&sFix,pParse,iDb,"index",pName)&&WN_SQL3FixSrcList(&sFix,pTblName))pTab=WN_SQL3LocateTable(pParse,pTblName->a[0].zName,pTblName->a[0].zDatabase);
		if(!pTab)goto exit_create_index;
	}
	else
	{	pTab=pParse->pNewTable;
		if(!pTab)goto exit_create_index;
		iDb=WN_SQL3SchemaToIndex(db,pTab->pSchema);
	}
	pDb=&db->aDb[iDb];
	if(pTab==0 || pParse->nErr)goto exit_create_index;
	if(pTab->readOnly)
	{
		WN_SQL3ErrorMsg(pParse,"table %s may not be indexed",pTab->zName);
		goto exit_create_index;
	}
#ifndef WN_SQL_OMIT_VIEW
	if(pTab->pSelect)
	{
		WN_SQL3ErrorMsg(pParse,"views may not be indexed");
		goto exit_create_index;
	}
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(IsVirtual(pTab))
	{
		WN_SQL3ErrorMsg(pParse,"virtual tables may not be indexed");
		goto exit_create_index;
	}
#endif
	if(pName)
	{
		zName=WN_SQL3NameFromToken(pName);
		if(WN_SQL3ReadSchema(pParse))goto exit_create_index;
		if(zName==0)goto exit_create_index;
		if(WN_SQL3CheckObjectName(pParse,zName))goto exit_create_index;
		if(!db->init.busy)
		{	if(WN_SQL3ReadSchema(pParse))goto exit_create_index;
			if(WN_SQL3FindTable(db,zName,0))
			{	WN_SQL3ErrorMsg(pParse,"there is already a table named %s",zName);
				goto exit_create_index;
			}
		}
		if(WN_SQL3FindIndex(db,zName,pDb->zName))
		{	if(!ifNotExist)WN_SQL3ErrorMsg(pParse,"index %s already exists",zName);
			goto exit_create_index;
	}	}
	else
	{	char zBuf[30];
		int n;
		Index *pLoop;
		for(pLoop=pTab->pIndex,n=1;pLoop;pLoop=pLoop->pNext,n++);
		WN_SQL3_snprintf(sizeof(zBuf),zBuf,"_%d",n);
		zName=0;
		WN_SQL3SetString(&zName,"WN_SQL_autoindex_",pTab->zName,zBuf,(char*)0);
		if(zName==0)goto exit_create_index;
	}
#ifndef WN_SQL_OMIT_AUTHORIZATION
	const char *zDb=pDb->zName;
	if(WN_SQL3AuthCheck(pParse,WN_SQL_INSERT,SCHEMA_TABLE(iDb),0,zDb))goto exit_create_index;
	i=WN_SQL_CREATE_INDEX;
	if(!OMIT_TEMPDB && iDb==1)i=WN_SQL_CREATE_TEMP_INDEX;
	if(WN_SQL3AuthCheck(pParse,i,zName,pTab->zName,zDb))goto exit_create_index;
#endif
	if(pList==0)
	{	nullId.z=(u8*)pTab->aCol[pTab->nCol-1].zName;
		nullId.n=strlen((char*)nullId.z);
		pList=WN_SQL3ExprListAppend(0,0,&nullId);
		if(pList==0)goto exit_create_index;
		pList->a[0].sortOrder=sortOrder;
	}
	for(i=0;i<pList->nExpr;i++)
	{	Expr *pExpr=pList->a[i].pExpr;
		if(pExpr)nExtra+=(1+strlen(pExpr->pColl->zName));
	}
	nName=strlen(zName);
	nCol=pList->nExpr;
	pIndex=WN_SQL3Malloc(sizeof(Index)+sizeof(int)*nCol+sizeof(int)*(nCol+1)+sizeof(char *)*nCol+sizeof(u8)*nCol+nName+1+nExtra);
	if(WN_SQL3MallocFailed())goto exit_create_index;
	pIndex->azColl=(char**)(&pIndex[1]);
	pIndex->aiColumn=(int *)(&pIndex->azColl[nCol]);
	pIndex->aiRowEst=(unsigned *)(&pIndex->aiColumn[nCol]);
	pIndex->aSortOrder=(u8 *)(&pIndex->aiRowEst[nCol+1]);
	pIndex->zName=(char *)(&pIndex->aSortOrder[nCol]);
	zExtra=(char *)(&pIndex->zName[nName+1]);
	memcpy(pIndex->zName,zName,nName+1);
	pIndex->pTable=pTab;
	pIndex->nColumn=pList->nExpr;
	pIndex->onError=onError;
	pIndex->autoIndex=pName==0;
	pIndex->pSchema=db->aDb[iDb].pSchema;
	if(pDb->pSchema->file_format>=4)
		sortOrderMask=-1;
	else
		sortOrderMask=0;
	for(i=0,pListItem=pList->a;i<pList->nExpr;i++,pListItem++)
	{	const char *zColName=pListItem->zName;
		Column *pTabCol;
		int requestedSortOrder;
		char *zColl;
		for(j=0,pTabCol=pTab->aCol;j<pTab->nCol;j++,pTabCol++)
			if(WN_SQL3StrICmp(zColName,pTabCol->zName)==0)break;
		if(j>=pTab->nCol)
		{	WN_SQL3ErrorMsg(pParse,"table %s has no column named %s",pTab->zName,zColName);
			goto exit_create_index;
		}
		pIndex->aiColumn[i]=j;
		if(pListItem->pExpr)
		{	zColl=zExtra;
			WN_SQL3_snprintf(nExtra,zExtra,"%s",pListItem->pExpr->pColl->zName);
			zExtra+=(strlen(zColl)+1);
		}
		else
		{	zColl=pTab->aCol[j].zColl;
			if(!zColl)zColl=db->pDfltColl->zName;
		}
		if(!db->init.busy && !WN_SQL3LocateCollSeq(pParse,zColl,-1))goto exit_create_index;
		pIndex->azColl[i]=zColl;
		requestedSortOrder=pListItem->sortOrder & sortOrderMask;
		pIndex->aSortOrder[i]=requestedSortOrder;
	}
	WN_SQL3DefaultRowEst(pIndex);
	if(pTab==pParse->pNewTable)
	{	Index *pIdx;
	for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)
	{	int k;
		if(pIdx->nColumn!=pIndex->nColumn)continue;
		for(k=0;k<pIdx->nColumn;k++)
		{	const char *z1=pIdx->azColl[k],*z2=pIndex->azColl[k];
			if((pIdx->aiColumn[k]!=pIndex->aiColumn[k])||(pIdx->aSortOrder[k]!=pIndex->aSortOrder[k])||(z1!=z2 && WN_SQL3StrICmp(z1,z2)))break;
		}
		if(k==pIdx->nColumn)
		{	if(pIdx->onError!=pIndex->onError)
			{	if(!(pIdx->onError==OE_Default || pIndex->onError==OE_Default))WN_SQL3ErrorMsg(pParse,"conflicting ON CONFLICT clauses specified",0);
				if(pIdx->onError==OE_Default)pIdx->onError=pIndex->onError;
			}
			goto exit_create_index;
}	}	}
	if(db->init.busy)
	{	Index *p=WN_SQL3HashInsert(&pIndex->pSchema->idxHash,pIndex->zName,strlen(pIndex->zName)+1,pIndex);
		if(p)goto exit_create_index;
		db->flags |=WN_SQL_InternChanges;
		if(pTblName)pIndex->tnum=db->init.newTnum;
	}
	else
		if(db->init.busy==0)
		{	char *zStmt;
			int iMem=pParse->nMem++;
			Vdbe *v=WN_SQL3GetVdbe(pParse);
			if(v==0)goto exit_create_index;
			WN_SQL3BeginWriteOperation(pParse,1,iDb);
			WN_SQL3VdbeAddOp(v,OP_CreateIndex,iDb,0);
			WN_SQL3VdbeAddOp(v,OP_MemStore,iMem,0);
			if(pStart && pEnd)
				zStmt=WN_SQL3MPrintf("CREATE%s INDEX %.*s",onError==OE_None ? "" :" UNIQUE",pEnd->z-pName->z+1,pName->z);
			else
				zStmt=0;
			WN_SQL3NestedParse(pParse,"INSERT INTO %Q.%s VALUES('index',%Q,%Q,#0,%Q);",db->aDb[iDb].zName,SCHEMA_TABLE(iDb),pIndex->zName,pTab->zName,zStmt);
			WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
			WN_SQL3FreeX(zStmt);
			if(pTblName)
			{	WN_SQL3RefillIndex(pParse,pIndex,iMem);
				WN_SQL3ChangeCookie(db,v,iDb);
				WN_SQL3VdbeOp3(v,OP_ParseSchema,iDb,0,WN_SQL3MPrintf("name='%q'",pIndex->zName),P3_DYNAMIC);
				WN_SQL3VdbeAddOp(v,OP_Expire,0,0);
	}		}
	if(db->init.busy || pTblName==0)
	{
		if(onError!=OE_Replace || pTab->pIndex==0|| pTab->pIndex->onError==OE_Replace)
		{	pIndex->pNext=pTab->pIndex;
			pTab->pIndex=pIndex;
		}
		else
		{	Index *pOther=pTab->pIndex;
			while(pOther->pNext && pOther->pNext->onError!=OE_Replace)pOther=pOther->pNext;
			pIndex->pNext=pOther->pNext;
			pOther->pNext=pIndex;
		}
		pIndex=0;
	}
exit_create_index:
	if(pIndex)freeIndex(pIndex);
	WN_SQL3ExprListDelete(pList);
	WN_SQL3SrcListDelete(pTblName);
	WN_SQL3FreeX(zName);
	return;
}
void WN_SQL3MinimumFileFormat(Parse *pParse,int iDb,int minFormat)
{	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v)
	{	WN_SQL3VdbeAddOp(v,OP_ReadCookie,iDb,1);
		WN_SQL3VdbeAddOp(v,OP_Integer,minFormat,0);
		WN_SQL3VdbeAddOp(v,OP_Ge,0,WN_SQL3VdbeCurrentAddr(v)+3);
		WN_SQL3VdbeAddOp(v,OP_Integer,minFormat,0);
		WN_SQL3VdbeAddOp(v,OP_SetCookie,iDb,1);
}	}
void WN_SQL3DefaultRowEst(Index *pIdx)
{	unsigned *a=pIdx->aiRowEst;
	int i;
	a[0]=1000000;
	for(i=pIdx->nColumn;i>=5;i--)a[i]=5;
	while(i>=1)
	{	a[i]=11-i;
		i--;
	}
	if(pIdx->onError!=OE_None)a[pIdx->nColumn]=1;
}
void WN_SQL3DropIndex(Parse *pParse,SrcList *pName,int ifExists)
{	WN_SQL3 *db=pParse->db;
	if(pParse->nErr || WN_SQL3MallocFailed())goto exit_drop_index;
	if(WN_SQL3ReadSchema(pParse))goto exit_drop_index;
	Index *pIndex=WN_SQL3FindIndex(db,pName->a[0].zName,pName->a[0].zDatabase);
	if(pIndex==0)
	{	if(!ifExists)WN_SQL3ErrorMsg(pParse,"no such index:%S",pName,0);
		pParse->checkSchema=1;
		goto exit_drop_index;
	}
	if(pIndex->autoIndex)
	{	WN_SQL3ErrorMsg(pParse,"index associated with UNIQUE "
"or PRIMARY KEY constraint cannot be dropped",0);
		goto exit_drop_index;
	}
	int iDb=WN_SQL3SchemaToIndex(db,pIndex->pSchema);
#ifndef WN_SQL_OMIT_AUTHORIZATION
	int code=WN_SQL_DROP_INDEX;
	Table *pTab=pIndex->pTable;
	const char *zDb=db->aDb[iDb].zName,*zTab=SCHEMA_TABLE(iDb);
	if(WN_SQL3AuthCheck(pParse,WN_SQL_DELETE,zTab,0,zDb))goto exit_drop_index;
	if(!OMIT_TEMPDB && iDb)code=WN_SQL_DROP_TEMP_INDEX;
	if(WN_SQL3AuthCheck(pParse,code,pIndex->zName,pTab->zName,zDb))goto exit_drop_index;
#endif
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v)
	{	WN_SQL3NestedParse(pParse,"DELETE FROM %Q.%s WHERE name=%Q",db->aDb[iDb].zName,SCHEMA_TABLE(iDb),pIndex->zName);
		WN_SQL3ChangeCookie(db,v,iDb);
		destroyRootPage(pParse,pIndex->tnum,iDb);
		WN_SQL3VdbeOp3(v,OP_DropIndex,iDb,0,pIndex->zName,0);
	}
exit_drop_index:
	WN_SQL3SrcListDelete(pName);
}
void *WN_SQL3ArrayAllocate(void *pArray,int szEntry,int initSize,int *pnEntry,int *pnAlloc,int *pIdx)
{	char *z;
	if(*pnEntry >=*pnAlloc)
	{	int newSize=(*pnAlloc)*2+initSize;
		void *pNew=WN_SQLRealloc(pArray,newSize*szEntry);
		if(pNew==0)
		{	*pIdx=-1;
			return pArray;
		}
		*pnAlloc=newSize;
		pArray=pNew;
	}
	z=(char*)pArray;
	memset(&z[*pnEntry * szEntry],0,szEntry);
	*pIdx=*pnEntry;
	++*pnEntry;
	return pArray;
}
IdList *WN_SQL3IdListAppend(IdList *pList,Token *pToken)
{	int i;
	if(pList==0)
	{	pList=WN_SQL3Malloc(sizeof(IdList));
		if(pList==0)return 0;
		pList->nAlloc=0;
	}
	pList->a=WN_SQL3ArrayAllocate(pList->a,sizeof(pList->a[0]),5,&pList->nId,&pList->nAlloc,&i);
	if(i<0)
	{	WN_SQL3IdListDelete(pList);
		return 0;
	}
	pList->a[i].zName=WN_SQL3NameFromToken(pToken);
	return pList;
}
void WN_SQL3IdListDelete(IdList *pList)
{	if(pList==0)return;
	for(int i=0;i<pList->nId;i++)WN_SQL3FreeX(pList->a[i].zName);
	WN_SQL3FreeX(pList->a);
	WN_SQL3FreeX(pList);
}
int WN_SQL3IdListIndex(IdList *pList,const char *zName)
{	if(pList==0)return-1;
	for(int i=0;i<pList->nId;i++)if(WN_SQL3StrICmp(pList->a[i].zName,zName)==0)return i;
	return-1;
}
SrcList *WN_SQL3SrcListAppend(SrcList *pList,Token *pTable,Token *pDatabase)
{	struct SrcList_item *pItem;
	if(pList==0)
	{	pList=WN_SQL3Malloc(sizeof(SrcList));
		if(pList==0)return 0;
		pList->nAlloc=1;
	}
	if(pList->nSrc>=pList->nAlloc)
	{	pList->nAlloc *=2;
		SrcList *pNew=WN_SQLRealloc(pList,sizeof(*pList)+(pList->nAlloc-1)*sizeof(pList->a[0]));
		if(pNew==0)
		{	WN_SQL3SrcListDelete(pList);
			return 0;
		}
		pList=pNew;
	}
	pItem=&pList->a[pList->nSrc];
	memset(pItem,0,sizeof(pList->a[0]));
	if(pDatabase && pDatabase->z==0)pDatabase=0;
	if(pDatabase && pTable)
	{	Token *pTemp=pDatabase;
		pDatabase=pTable;
		pTable=pTemp;
	}
	pItem->zName=WN_SQL3NameFromToken(pTable);
	pItem->zDatabase=WN_SQL3NameFromToken(pDatabase);
	pItem->iCursor=-1;
	pItem->isPopulated=0;
	pList->nSrc++;
	return pList;
}
void WN_SQL3SrcListAssignCursors(Parse *pParse,SrcList *pList)
{	int i;
	struct SrcList_item *pItem;
	if(pList)
	{	for(i=0,pItem=pList->a;i<pList->nSrc;i++,pItem++)
		{	if(pItem->iCursor>=0)break;
			pItem->iCursor=pParse->nTab++;
			if(pItem->pSelect)WN_SQL3SrcListAssignCursors(pParse,pItem->pSelect->pSrc);
}	}	}
void WN_SQL3SrcListDelete(SrcList *pList)
{	int i;
	struct SrcList_item *pItem;
	if(pList==0)return;
	for(pItem=pList->a,i=0;i<pList->nSrc;i++,pItem++)
	{	WN_SQL3FreeX(pItem->zDatabase);
		WN_SQL3FreeX(pItem->zName);
		WN_SQL3FreeX(pItem->zAlias);
		WN_SQL3DeleteTable(pItem->pTab);	
		WN_SQL3SelectDelete(pItem->pSelect);
		WN_SQL3ExprDelete(pItem->pOn);
		WN_SQL3IdListDelete(pItem->pUsing);
	}
	WN_SQL3FreeX(pList);
}
SrcList *WN_SQL3SrcListAppendFromTerm(SrcList *p,Token *pTable,Token *pDatabase,Token *pAlias,Select *pSubquery,Expr *pOn,IdList *pUsing)
{	struct SrcList_item *pItem;
	p=WN_SQL3SrcListAppend(p,pTable,pDatabase);
	if(p==0 || p->nSrc==0)
	{	WN_SQL3ExprDelete(pOn);
		WN_SQL3IdListDelete(pUsing);
		WN_SQL3SelectDelete(pSubquery);
		return p;
	}
	pItem=&p->a[p->nSrc-1];
	if(pAlias && pAlias->n)pItem->zAlias=WN_SQL3NameFromToken(pAlias);
	pItem->pSelect=pSubquery;
	pItem->pOn=pOn;
	pItem->pUsing=pUsing;
	return p;
}
void WN_SQL3SrcListShiftJoinType(SrcList *p)
{	if(p && p->a)
	{	int i;
		for(i=p->nSrc-1;i>0;i--)p->a[i].jointype=p->a[i-1].jointype;
		p->a[0].jointype=0;
}	}
void WN_SQL3BeginTransaction(Parse *pParse,int type)
{	WN_SQL3 *db;
	if(pParse==0 ||(db=pParse->db)==0 || db->aDb[0].pBt==0)return;	
	if(pParse->nErr || WN_SQL3MallocFailed())return;
	if(WN_SQL3AuthCheck(pParse,WN_SQL_TRANSACTION,"BEGIN",0,0))return;
	int i;
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(!v)return;
	if(type!=TK_DEFERRED)for(i=0;i<db->nDb;i++)WN_SQL3VdbeAddOp(v,OP_Transaction,i,(type==TK_EXCLUSIVE)+1);
	WN_SQL3VdbeAddOp(v,OP_AutoCommit,0,0);
}
void WN_SQL3CommitTransaction(Parse *pParse)
{	WN_SQL3 *db;
	if(pParse==0 ||(db=pParse->db)==0 || db->aDb[0].pBt==0)return;
	if(pParse->nErr || WN_SQL3MallocFailed())return;
	if(WN_SQL3AuthCheck(pParse,WN_SQL_TRANSACTION,"COMMIT",0,0))return;
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v)WN_SQL3VdbeAddOp(v,OP_AutoCommit,1,0);
}
void WN_SQL3RollbackTransaction(Parse *pParse)
{
	WN_SQL3 *db;
	if(pParse==0 ||(db=pParse->db)==0 || db->aDb[0].pBt==0)return;
	if(pParse->nErr || WN_SQL3MallocFailed())return;
	if(WN_SQL3AuthCheck(pParse,WN_SQL_TRANSACTION,"ROLLBACK",0,0))return;
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v)WN_SQL3VdbeAddOp(v,OP_AutoCommit,1,1);
}
int WN_SQL3OpenTempDatabase(Parse *pParse)
{
	WN_SQL3 *db=pParse->db;
	if(db->aDb[1].pBt==0 && !pParse->explain)
	{
		int rc=WN_SQL3BtreeFactory(db,0,0,WN_SQL_DEFAULT_CACHE_SIZE,&db->aDb[1].pBt);
		if(rc)
		{
			WN_SQL3ErrorMsg(pParse,"unable to open a temporary database "
"file for storing temporary tables");
			pParse->rc=rc;
			return 1;
		}
		if(db->flags & !db->autoCommit)
		{
			rc=WN_SQL3BtreeBeginTrans(db->aDb[1].pBt,1);
			if(rc)
			{
				WN_SQL3ErrorMsg(pParse,"unable to get a write lock on "
"the temporary database file");
				pParse->rc=rc;
				return 1;
	}	}	}
	return 0;
}
void WN_SQL3CodeVerifySchema(Parse *pParse,int iDb)
{
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v==0)return;
	WN_SQL3 *db=pParse->db;
	if(pParse->cookieGoto==0)pParse->cookieGoto=WN_SQL3VdbeAddOp(v,OP_Goto,0,0)+1;
	if(iDb>=0)
	{
		int mask=1<<iDb;
		if((pParse->cookieMask & mask)==0)
		{
			pParse->cookieMask |=mask;
			pParse->cookieValue[iDb]=db->aDb[iDb].pSchema->schema_cookie;
			if(!OMIT_TEMPDB && iDb==1)WN_SQL3OpenTempDatabase(pParse);
		}
	}
}
void WN_SQL3BeginWriteOperation(Parse *pParse,int setStatement,int iDb)
{
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v==0)return;
	WN_SQL3CodeVerifySchema(pParse,iDb);
	pParse->writeMask |=1<<iDb;
	if(setStatement && pParse->nested==0)WN_SQL3VdbeAddOp(v,OP_Statement,iDb,0);
	if((OMIT_TEMPDB || iDb!=1)&& pParse->db->aDb[1].pBt)WN_SQL3BeginWriteOperation(pParse,setStatement,1);
}
#ifndef WN_SQL_OMIT_REINDEX
int collationMatch(const char *zColl,Index *pIndex)
{
	int i;
	for(i=0;i<pIndex->nColumn;i++)
	{
		const char *z=pIndex->azColl[i];
		if(z==zColl ||(z && zColl && 0==WN_SQL3StrICmp(z,zColl)))return 1;
	}
	return 0;
}
void reindexTable(Parse *pParse,Table *pTab,char const *zColl)
{	Index *pIndex;
	for(pIndex=pTab->pIndex;pIndex;pIndex=pIndex->pNext)if(zColl==0 || collationMatch(zColl,pIndex))
	{	int iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
		WN_SQL3BeginWriteOperation(pParse,0,iDb);
		WN_SQL3RefillIndex(pParse,pIndex,-1);
}	}
void reindexDatabases(Parse *pParse,char const *zColl){	Db *pDb;
	int iDb;
	WN_SQL3 *db=pParse->db;
	HashElem *k;
	Table *pTab;
	for(iDb=0,pDb=db->aDb;iDb<db->nDb;iDb++,pDb++)
	{	for(k=WN_SQLHashFirst(&pDb->pSchema->tblHash);k;k=WN_SQLHashNext(k))
		{	pTab=(Table*)WN_SQLHashData(k);
			reindexTable(pParse,pTab,zColl);
}	}	}
void WN_SQL3Reindex(Parse *pParse,Token *pName1,Token *pName2)
{	CollSeq *pColl;
	char *z;
	const char *zDb;
	Table *pTab;
	Index *pIndex;
	int iDb;
	WN_SQL3 *db=pParse->db;
	Token *pObjName;
	if(WN_SQL3ReadSchema(pParse))return;
	if(pName1==0 || pName1->z==0)
	{	reindexDatabases(pParse,0);
		return;
	}
	else
		if(pName2==0 || pName2->z==0)
		{	pColl=WN_SQL3FindCollSeq(db,ENC(db),(char*)pName1->z,pName1->n,0);
			if(pColl)
			{	char *zColl=WN_SQLStrNDup((const char *)pName1->z,pName1->n);
				if(zColl)
				{	reindexDatabases(pParse,zColl);
					WN_SQL3FreeX(zColl);
				}
				return;
	}		}
	iDb=WN_SQL3TwoPartName(pParse,pName1,pName2,&pObjName);
	if(iDb<0)return;
	z=WN_SQL3NameFromToken(pObjName);
	if(z==0)return;
	zDb=db->aDb[iDb].zName;
	pTab=WN_SQL3FindTable(db,z,zDb);
	if(pTab)
	{	reindexTable(pParse,pTab,0);
		WN_SQL3FreeX(z);
		return;
	}
	pIndex=WN_SQL3FindIndex(db,z,zDb);
	WN_SQL3FreeX(z);
	if(pIndex)
	{	WN_SQL3BeginWriteOperation(pParse,0,iDb);
		WN_SQL3RefillIndex(pParse,pIndex,-1);
		return;
	}
	WN_SQL3ErrorMsg(pParse,"unable to identify the object to be reindexed");
}
#endif
KeyInfo *WN_SQL3IndexKeyinfo(Parse *pParse,Index *pIdx)
{	int i,nCol=pIdx->nColumn,nBytes=sizeof(KeyInfo)+(nCol-1)*sizeof(CollSeq*)+nCol;
	KeyInfo *pKey=(KeyInfo *)WN_SQL3Malloc(nBytes);
	if(pKey)
	{	pKey->aSortOrder=(u8 *)&(pKey->aColl[nCol]);
		for(i=0;i<nCol;i++)
		{	char *zColl=pIdx->azColl[i];
			pKey->aColl[i]=WN_SQL3LocateCollSeq(pParse,zColl,-1);
			pKey->aSortOrder[i]=pIdx->aSortOrder[i];
		}
		pKey->nField=nCol;
	}
	if(pParse->nErr)
	{	WN_SQL3FreeX(pKey);
		pKey=0;
	}
	return pKey;
}
void callCollNeeded(WN_SQL3 *db,const char *zName,int nName)
{	if(nName<0)nName=strlen(zName);
	if(db->xCollNeeded)
	{	char *zExternal=WN_SQLStrNDup(zName,nName);
		if(!zExternal)return;
		db->xCollNeeded(db->pCollNeededArg,db,(int)ENC(db),zExternal);
		WN_SQL3FreeX(zExternal);
	}
#ifndef WN_SQL_OMIT_UTF16
	if(db->xCollNeeded16)
	{	char const *zExternal;
		WN_SQL3_value *pTmp=WN_SQL3ValueNew();
		WN_SQL3ValueSetStr(pTmp,nName,zName,WN_SQL_UTF8,WN_SQL_STATIC);
		zExternal=WN_SQL3ValueText(pTmp,WN_SQL_UTF16NATIVE);
		if(zExternal)db->xCollNeeded16(db->pCollNeededArg,db,(int)ENC(db),zExternal);
		WN_SQL3ValueFree(pTmp);
	}
#endif
}
int synthCollSeq(WN_SQL3 *db,CollSeq *pColl)
{	CollSeq *pColl2;
	char *z=pColl->zName;
	int n=strlen(z),i;
	const u8 aEnc[]={WN_SQL_UTF16BE,WN_SQL_UTF16LE,WN_SQL_UTF8};
	for(i=0;i<3;i++)
	{	pColl2=WN_SQL3FindCollSeq(db,aEnc[i],z,n,0);
if(pColl2->xCmp)
		{	memcpy(pColl,pColl2,sizeof(CollSeq));
			pColl->xDel=0;
			return 0;
	}	}
	return WN_SQL_ERROR;
}
CollSeq *WN_SQL3GetCollSeq(WN_SQL3* db,CollSeq *pColl,const char *zName,int nName)
{	CollSeq *p=pColl;
	if(!p)p=WN_SQL3FindCollSeq(db,ENC(db),zName,nName,0);
	if(!p || !p->xCmp)
	{	callCollNeeded(db,zName,nName);
		p=WN_SQL3FindCollSeq(db,ENC(db),zName,nName,0);
	}
	if(p && !p->xCmp && synthCollSeq(db,p))p=0;
	return p;
}
int WN_SQL3CheckCollSeq(Parse *pParse,CollSeq *pColl)
{	if(pColl)
	{	const char *zName=pColl->zName;
		CollSeq *p=WN_SQL3GetCollSeq(pParse->db,pColl,zName,-1);
		if(!p)
		{
			if(pParse->nErr==0)WN_SQL3ErrorMsg(pParse,"no such collation sequence:%s",zName);
			pParse->nErr++;
			return WN_SQL_ERROR;
	}	}
	return 0;
}
CollSeq *findCollSeqEntry(WN_SQL3 *db,const char *zName,int nName,int create)
{	if(nName<0)nName=strlen(zName);
	CollSeq *pColl=WN_SQL3HashFind(&db->aCollSeq,zName,nName);
	if(0==pColl && create)
	{	pColl=WN_SQL3Malloc(3*sizeof(*pColl)+nName+1);
		if(pColl)
		{	CollSeq *pDel=0;
			pColl[0].zName=(char*)&pColl[3];
			pColl[0].enc=WN_SQL_UTF8;
			pColl[1].zName=(char*)&pColl[3];
			pColl[1].enc=WN_SQL_UTF16LE;
			pColl[2].zName=(char*)&pColl[3];
			pColl[2].enc=WN_SQL_UTF16BE;
			memcpy(pColl[0].zName,zName,nName);
			pColl[0].zName[nName]=0;
			pDel=WN_SQL3HashInsert(&db->aCollSeq,pColl[0].zName,nName,pColl);
			if(pDel)
			{	WN_SQL3FreeX(pDel);
				pColl=0;
	}	}	}
	return pColl;
}
CollSeq *WN_SQL3FindCollSeq(WN_SQL3 *db,u8 enc,const char *zName,int nName,int create)
{	CollSeq *pColl;
	if(zName)
		pColl=findCollSeqEntry(db,zName,nName,create);	else
		pColl=db->pDfltColl;
	if(pColl)pColl+=enc-1;
	return pColl;
}
FuncDef *WN_SQL3FindFunction(WN_SQL3 *db,const char *zName,int nName,int nArg,u8 enc,int createFlag)
{	FuncDef *p;
	FuncDef *pBest=0;
	int bestmatch=0;
	if(nArg<-1)nArg=-1;
	FuncDef *pFirst=(FuncDef*)WN_SQL3HashFind(&db->aFunc,zName,nName);
	for(p=pFirst;p;p=p->pNext)
		if(p->nArg==-1 || p->nArg==nArg || nArg==-1)
		{
			int match=1;
			if(p->nArg==nArg || nArg==-1)match=4;
			if(enc==p->iPrefEnc)match+=2;
			else
				if((enc==WN_SQL_UTF16LE && p->iPrefEnc==WN_SQL_UTF16BE)||
					(enc==WN_SQL_UTF16BE && p->iPrefEnc==WN_SQL_UTF16LE))
					match+=1;
			if(match>bestmatch)
			{
				pBest=p;
				bestmatch=match;
			}
		}
	if(createFlag && bestmatch<6 &&(pBest=WN_SQL3Malloc(sizeof(*pBest)+nName)))
	{
		pBest->nArg=nArg;
		pBest->pNext=pFirst;
		pBest->iPrefEnc=enc;
		memcpy(pBest->zName,zName,nName);
		pBest->zName[nName]=0;
		if(pBest==WN_SQL3HashInsert(&db->aFunc,pBest->zName,nName,(void*)pBest))
		{
			WN_SQL3FreeX(pBest);
			return 0;
		}
	}
	if(pBest &&(pBest->xStep || pBest->xFunc || createFlag))return pBest;
	return 0;
}
void WN_SQL3SchemaFree(void *p)
{	Hash temp1,temp2;
	HashElem *pElem;
	Schema *pSchema=(Schema *)p;
	temp1=pSchema->tblHash;
	temp2=pSchema->trigHash;
	WN_SQL3HashInit(&pSchema->trigHash,WN_SQL_HASH_STRING,0);
	WN_SQL3HashClear(&pSchema->aFKey);
	WN_SQL3HashClear(&pSchema->idxHash);
	for(pElem=WN_SQLHashFirst(&temp2);pElem;pElem=WN_SQLHashNext(pElem))WN_SQL3DeleteTrigger((Trigger*)WN_SQLHashData(pElem));
	WN_SQL3HashClear(&temp2);
	WN_SQL3HashInit(&pSchema->tblHash,WN_SQL_HASH_STRING,0);
	for(pElem=WN_SQLHashFirst(&temp1);pElem;pElem=WN_SQLHashNext(pElem))
	{	Table *pTab=WN_SQLHashData(pElem);
		WN_SQL3DeleteTable(pTab);
	}
	WN_SQL3HashClear(&temp1);
	pSchema->pSeqTab=0;
	pSchema->flags &=~DB_SchemaLoaded;
}
Schema *WN_SQL3SchemaGet(Btree *pBt)
{	Schema * p;
	if(pBt)
		p=(Schema *)WN_SQL3BtreeSchema(pBt,sizeof(Schema),WN_SQL3SchemaFree);
	else
		p=(Schema *)WN_SQL3Malloc(sizeof(Schema));
	if(p && 0==p->file_format)
	{	WN_SQL3HashInit(&p->tblHash,WN_SQL_HASH_STRING,0);
		WN_SQL3HashInit(&p->idxHash,WN_SQL_HASH_STRING,0);
		WN_SQL3HashInit(&p->trigHash,WN_SQL_HASH_STRING,0);
		WN_SQL3HashInit(&p->aFKey,WN_SQL_HASH_STRING,1);
		p->enc=WN_SQL_UTF8;
	}
	return p;
}
#ifndef WN_SQL_OMIT_COMPLETE
extern const char WN_SQL3IsIdChar[];
#define IdChar(C)(((c=C)&0x80)||(c>0x1f && WN_SQL3IsIdChar[c-0x20]))
#define tkSEMI 0
#define tkWS 1
#define tkOTHER 2
#define tkEXPLAIN 3
#define tkCREATE 4
#define tkTEMP 5
#define tkTRIGGER 6
#define tkEND 7
int WN_SQL3_complete(const char *zSql)
{	u8 state=0,token;
#ifndef WN_SQL_OMIT_TRIGGER
	const u8 trans[7][8]={{0,0,1,2,3,1,1,1,},{0,1,1,1,1,1,1,1,},{0,2,1,1,3,1,1,1,},{0,3,1,1,1,3,4,1,},{5,4,4,4,4,4,4,4,},{5,5,4,4,4,4,4,6,},{0,6,4,4,4,4,4,4,},};
#else
	const u8 trans[2][3]={{0,0,1,},{0,1,1,},};
#endif
	while(*zSql)
	{	switch(*zSql)
		{
		case ';':
			token=tkSEMI;
			break;
		case ' ':
		case '\r':
		case '\t':
		case '\n':
		case '\f':
			token=tkWS;
			break;
		case '/':
			if(zSql[1]!='*')
			{	token=tkOTHER;
				break;
			}
			zSql+=2;
			while(zSql[0] &&(zSql[0]!='*' || zSql[1]!='/'))zSql++;
			if(zSql[0]==0)return 0;
			zSql++;
			token=tkWS;
			break;
		case '-':
			if(zSql[1]!='-')
			{	token=tkOTHER;
				break;
			}
			while(*zSql && *zSql!='\n')zSql++;
			if(*zSql==0)return state==0;
			token=tkWS;
			break;
		case '[':
			zSql++;
			while(*zSql && *zSql!=']')zSql++;
			if(*zSql==0)return 0;
			token=tkOTHER;
			break;
		case '`':
		case '"':
		case '\'':
			int c=*zSql;
			zSql++;
			while(*zSql && *zSql!=c)zSql++;
			if(*zSql==0)return 0;
			token=tkOTHER;
			break;
		default:
			int c;
			if(IdChar((u8)*zSql))
			{	int nId;
				for(nId=1;IdChar(zSql[nId]);nId++);
#ifdef WN_SQL_OMIT_TRIGGER
				token=tkOTHER;
#else
				switch(*zSql)
				{
				case 'c':
				case 'C':
					if(nId==6 && WN_SQL3StrNICmp(zSql,"create",6)==0)
						token=tkCREATE;
					else
						token=tkOTHER;
					break;
				case 't':
				case 'T':
					if(nId==7 && WN_SQL3StrNICmp(zSql,"trigger",7)==0)
						token=tkTRIGGER;
					else
						if(nId==4 && WN_SQL3StrNICmp(zSql,"temp",4)==0)
							token=tkTEMP;
						else
							if(nId==9 && WN_SQL3StrNICmp(zSql,"temporary",9)==0)
								token=tkTEMP;
							else
								token=tkOTHER;
					break;
				case 'e':
				case 'E':
					if(nId==3 && WN_SQL3StrNICmp(zSql,"end",3)==0)
						token=tkEND;
					else
#ifndef WN_SQL_OMIT_EXPLAIN
						if(nId==7 && WN_SQL3StrNICmp(zSql,"explain",7)==0)
							token=tkEXPLAIN;
						else
#endif
							token=tkOTHER;
					break;
				default:
					token=tkOTHER;
				}
#endif
				zSql+=nId-1;
			}
			else
				token=tkOTHER;
		}
		state=trans[state][token];
		zSql++;
	}
	return state==0;
}
#ifndef WN_SQL_OMIT_UTF16
int WN_SQL3_complete16(const void *zSql)
{	char const *zSql8;
	int rc=0;
	WN_SQL3_value *pVal=WN_SQL3ValueNew();
	WN_SQL3ValueSetStr(pVal,-1,zSql,WN_SQL_UTF16NATIVE,WN_SQL_STATIC);
	zSql8=WN_SQL3ValueText(pVal,WN_SQL_UTF8);
	if(zSql8)rc=WN_SQL3_complete(zSql8);
	WN_SQL3ValueFree(pVal);
	return WN_SQL3ApiExit(0,rc);
}
#endif
#endif
Table *WN_SQL3SrcListLookup(Parse *pParse,SrcList *pSrc)
{	Table *pTab=0;
	int i;
	struct SrcList_item *pItem;
	for(i=0,pItem=pSrc->a;i<pSrc->nSrc;i++,pItem++)
	{	pTab=WN_SQL3LocateTable(pParse,pItem->zName,pItem->zDatabase);
		WN_SQL3DeleteTable(pItem->pTab);
		pItem->pTab=pTab;
		if(pTab)pTab->nRef++;
	}
	return pTab;
}
int WN_SQL3IsReadOnly(Parse *pParse,Table *pTab,int viewOk)
{	if((pTab->readOnly &&(pParse->db->flags & WN_SQL_WriteSchema)==0&& pParse->nested==0)
	WN_SQL3ErrorMsg(pParse,"table %s may not be modified",pTab->zName);
	return 1;
}
#ifndef WN_SQL_OMIT_VIEW
	if(!viewOk && pTab->pSelect)
	{	WN_SQL3ErrorMsg(pParse,"cannot modify %s because it is a view",pTab->zName);
		return 1;
	}
#endif
	return 0;
}
void WN_SQL3OpenTable(Parse *p,int iCur,int iDb,Table *pTab,int opcode)
{
	if(IsVirtual(pTab))return;
	Vdbe *v=WN_SQL3GetVdbe(p);
	WN_SQL3TableLock(p,iDb,pTab->tnum,(opcode==OP_OpenWrite),pTab->zName);
	WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
	VdbeComment((v,"# %s",pTab->zName));
	WN_SQL3VdbeAddOp(v,opcode,iCur,pTab->tnum);
	WN_SQL3VdbeAddOp(v,OP_SetNumColumns,iCur,pTab->nCol);
}
void WN_SQL3DeleteFrom(Parse *pParse,SrcList *pTabList,Expr *pWhere)
{
	int end,addr=0,i,iCur,oldIdx=-1,iDb,memCnt=0;
	WhereInfo *pWInfo;
	Index *pIdx;
	AuthContext sContext;
	NameContext sNC;
#ifndef WN_SQL_OMIT_TRIGGER
	int isView,triggers_exist=0;
#endif
	sContext.pParse=0;
	if(pParse->nErr || WN_SQL3MallocFailed())goto delete_from_cleanup;
	WN_SQL3 *db=pParse->db;
	Table *pTab=WN_SQL3SrcListLookup(pParse,pTabList);
	if(pTab==0)goto delete_from_cleanup;
#ifndef WN_SQL_OMIT_TRIGGER
	triggers_exist=WN_SQL3TriggersExist(pParse,pTab,TK_DELETE,0);
	isView=pTab->pSelect!=0;
#else
# define triggers_exist 0
# define isView 0
#endif
#ifdef WN_SQL_OMIT_VIEW
# undef isView
# define isView 0
#endif
	if(WN_SQL3IsReadOnly(pParse,pTab,triggers_exist))goto delete_from_cleanup;
	iDb=WN_SQL3SchemaToIndex(db,pTab->pSchema);
	const char *zDb=db->aDb[iDb].zName;
	if(WN_SQL3AuthCheck(pParse,WN_SQL_DELETE,pTab->zName,0,zDb))goto delete_from_cleanup;
	if(WN_SQL3ViewGetColumnNames(pParse,pTab))goto delete_from_cleanup;
	if(triggers_exist)oldIdx=pParse->nTab++;
	iCur=pTabList->a[0].iCursor=pParse->nTab++;
	memset(&sNC,0,sizeof(sNC));
	sNC.pParse=pParse;
	sNC.pSrcList=pTabList;
	if(WN_SQL3ExprResolveNames(&sNC,pWhere))goto delete_from_cleanup;
	if(isView)WN_SQL3AuthContextPush(pParse,&sContext,pTab->zName);
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v==0)goto delete_from_cleanup;
	if(pParse->nested==0)WN_SQL3VdbeCountChanges(v);
	WN_SQL3BeginWriteOperation(pParse,triggers_exist,iDb);
	if(isView)
	{
		Select *pView=WN_SQL3SelectDup(pTab->pSelect);
		WN_SQL3Select(pParse,pView,SRT_EphemTab,iCur,0,0,0,0);
		WN_SQL3SelectDelete(pView);
	}
	if(db->flags & WN_SQL_CountRows)
	{
		memCnt=pParse->nMem++;
		WN_SQL3VdbeAddOp(v,OP_MemInt,0,memCnt);
	}
	if(pWhere==0 && !triggers_exist && !IsVirtual(pTab))
	{
		if(db->flags & WN_SQL_CountRows)
		{
			int endOfLoop=WN_SQL3VdbeMakeLabel(v),addr2;
			if(!isView)WN_SQL3OpenTable(pParse,iCur,iDb,pTab,OP_OpenRead);
			WN_SQL3VdbeAddOp(v,OP_Rewind,iCur,WN_SQL3VdbeCurrentAddr(v)+2);
			addr2=WN_SQL3VdbeAddOp(v,OP_MemIncr,1,memCnt);
			WN_SQL3VdbeAddOp(v,OP_Next,iCur,addr2);
			WN_SQL3VdbeResolveLabel(v,endOfLoop);
			WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
		}
		if(!isView)
		{
			WN_SQL3VdbeAddOp(v,OP_Clear,pTab->tnum,iDb);
			if(!pParse->nested)WN_SQL3VdbeChangeP3(v,-1,pTab->zName,P3_STATIC);
			for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)WN_SQL3VdbeAddOp(v,OP_Clear,pIdx->tnum,iDb);
		}
	}
	else
	{
		pWInfo=WN_SQL3WhereBegin(pParse,pTabList,pWhere,0);
		if(pWInfo==0)goto delete_from_cleanup;
		WN_SQL3VdbeAddOp(v,IsVirtual(pTab)? OP_VRowid :OP_Rowid,iCur,0);
		WN_SQL3VdbeAddOp(v,OP_FifoWrite,0,0);
		if(db->flags & WN_SQL_CountRows)			WN_SQL3VdbeAddOp(v,OP_MemIncr,1,memCnt);
		WN_SQL3WhereEnd(pWInfo);
		if(triggers_exist)
		{	WN_SQL3VdbeAddOp(v,OP_OpenPseudo,oldIdx,0);
		WN_SQL3VdbeAddOp(v,OP_SetNumColumns,oldIdx,pTab->nCol);
		}
		end=WN_SQL3VdbeMakeLabel(v);
		if(triggers_exist)
		{	addr=WN_SQL3VdbeAddOp(v,OP_FifoRead,0,end);
			if(!isView)
			{	WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
				WN_SQL3OpenTable(pParse,iCur,iDb,pTab,OP_OpenRead);
			}
			WN_SQL3VdbeAddOp(v,OP_MoveGe,iCur,0);
			WN_SQL3VdbeAddOp(v,OP_Rowid,iCur,0);
			WN_SQL3VdbeAddOp(v,OP_RowData,iCur,0);
			WN_SQL3VdbeAddOp(v,OP_Insert,oldIdx,0);
			if(!isView)WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
			(void)WN_SQL3CodeRowTrigger(pParse,TK_DELETE,0,TRIGGER_BEFORE,pTab,-1,oldIdx,(pParse->trigStack)?pParse->trigStack->orconf:OE_Default,addr);
		}
		if(!isView)
		{	WN_SQL3OpenTableAndIndices(pParse,pTab,iCur,OP_OpenWrite);
		if(!triggers_exist)addr=WN_SQL3VdbeAddOp(v,OP_FifoRead,0,end);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		if(IsVirtual(pTab))
		{	pParse->pVirtualLock=pTab;
			WN_SQL3VdbeOp3(v,OP_VUpdate,0,1,(const char*)pTab->pVtab,P3_VTAB);
		}
		else
#endif
			WN_SQL3GenerateRowDelete(db,v,pTab,iCur,pParse->nested==0);
	}
	if(triggers_exist)
	{	if(!isView)
		{	for(i=1,pIdx=pTab->pIndex;pIdx;i++,pIdx=pIdx->pNext)WN_SQL3VdbeAddOp(v,OP_Close,iCur+i,pIdx->tnum);
			WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
		}
	(void)WN_SQL3CodeRowTrigger(pParse,TK_DELETE,0,TRIGGER_AFTER,pTab,-1,oldIdx,(pParse->trigStack)?pParse->trigStack->orconf:OE_Default,addr);
	}
	WN_SQL3VdbeAddOp(v,OP_Goto,0,addr);
	WN_SQL3VdbeResolveLabel(v,end);
	if(!triggers_exist && !IsVirtual(pTab))
	{	for(i=1,pIdx=pTab->pIndex;pIdx;i++,pIdx=pIdx->pNext)WN_SQL3VdbeAddOp(v,OP_Close,iCur+i,pIdx->tnum);
		WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
	}
	}
	if(db->flags & WN_SQL_CountRows && pParse->nested==0 && !pParse->trigStack)
	{	WN_SQL3VdbeAddOp(v,OP_MemLoad,memCnt,0);
		WN_SQL3VdbeAddOp(v,OP_Callback,1,0);
		WN_SQL3VdbeSetNumCols(v,1);
		WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"rows deleted",P3_STATIC);
	}
delete_from_cleanup:
	WN_SQL3AuthContextPop(&sContext);
	WN_SQL3SrcListDelete(pTabList);
	WN_SQL3ExprDelete(pWhere);
	return;
}
void WN_SQL3GenerateRowDelete(WN_SQL3 *db,Vdbe *v,Table *pTab,int iCur,int count)
{	int addr=WN_SQL3VdbeAddOp(v,OP_NotExists,iCur,0);
	WN_SQL3GenerateRowIndexDelete(v,pTab,iCur,0);
	WN_SQL3VdbeAddOp(v,OP_Delete,iCur,(count?OPFLAG_NCHANGE:0));
	if(count)WN_SQL3VdbeChangeP3(v,-1,pTab->zName,P3_STATIC);
	WN_SQL3VdbeJumpHere(v,addr);
}
void WN_SQL3GenerateRowIndexDelete(Vdbe *v,Table *pTab,int iCur,char *aIdxUsed)
{	int i;
	Index *pIdx;
	for(i=1,pIdx=pTab->pIndex;pIdx;i++,pIdx=pIdx->pNext)
	{	if(aIdxUsed && aIdxUsed[i-1]==0)continue;
		WN_SQL3GenerateIndexKey(v,pIdx,iCur);
		WN_SQL3VdbeAddOp(v,OP_IdxDelete,iCur+i,0);
	}
}
void WN_SQL3GenerateIndexKey(Vdbe *v,Index *pIdx,int iCur)
{
	int j;
	Table *pTab=pIdx->pTable;
	WN_SQL3VdbeAddOp(v,OP_Rowid,iCur,0);
	for(j=0;j<pIdx->nColumn;j++)
	{
		int idx=pIdx->aiColumn[j];
		if(idx==pTab->iPKey)
			WN_SQL3VdbeAddOp(v,OP_Dup,j,0);
		else
		{
			WN_SQL3VdbeAddOp(v,OP_Column,iCur,idx);
			WN_SQL3ColumnDefault(v,pTab,idx);
		}
	}
	WN_SQL3VdbeAddOp(v,OP_MakeIdxRec,pIdx->nColumn,0);
	WN_SQL3IndexAffinityStr(v,pIdx);
}
CollSeq *WN_SQL3GetFuncCollSeq(WN_SQL3_context *context)
{
	return context->pColl;
}
void minmaxFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{	if(argc==0)return;
	int i,mask=WN_SQL3_user_data(context)==0 ? 0 :-1,iBest=0;
	CollSeq *pColl=WN_SQL3GetFuncCollSeq(context);
	if(WN_SQL3_value_type(argv[0])==WN_SQL_NULL)return;
	for(i=1;i<argc;i++)
	{	if(WN_SQL3_value_type(argv[i])==WN_SQL_NULL)return;
		if((WN_SQL3MemCompare(argv[iBest],argv[i],pColl)^mask)>=0)iBest=i;
	}
	WN_SQL3_result_value(context,argv[iBest]);
}
void typeofFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{	const char *z=0;
	switch(WN_SQL3_value_type(argv[0]))
	{
	case WN_SQL_NULL:
		z="null";
		break;
	case WN_SQL_INTEGER:
		z="integer";
		break;
	case WN_SQL_TEXT:
		z="text";
		break;
	case WN_SQL_FLOAT:
		z="real";
		break;
	case WN_SQL_BLOB:
		z="blob";
		break;
	}
	WN_SQL3_result_text(context,z,-1,WN_SQL_STATIC);
}
void lengthFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	int len;
	switch(WN_SQL3_value_type(argv[0]))
	{
	case WN_SQL_BLOB:
	case WN_SQL_INTEGER:
	case WN_SQL_FLOAT:
		WN_SQL3_result_int(context,WN_SQL3_value_bytes(argv[0]));
		break;
	case WN_SQL_TEXT:
		const unsigned char *z=WN_SQL3_value_text(argv[0]);
		if(z==0)return;
		len=0;
		while(*z)
		{
			len++;
			WN_SQL_SKIP_UTF8(z);
		}
		WN_SQL3_result_int(context,len);
		break;
	default:
		WN_SQL3_result_null(context);
		break;
	}
}
void absFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	switch(WN_SQL3_value_type(argv[0]))
	{
	case WN_SQL_INTEGER:
		i64 iVal=WN_SQL3_value_int64(argv[0]);
		if(iVal<0)
		{
			if((iVal<<1)==0)
			{
				WN_SQL3_result_error(context,"integer overflow",-1);
				return;
			}
			iVal=-iVal;
		}
		WN_SQL3_result_int64(context,iVal);
		break;
	case WN_SQL_NULL:
		WN_SQL3_result_null(context);
		break;
	default:
		double rVal=WN_SQL3_value_double(argv[0]);
		if(rVal<0)rVal=-rVal;
		WN_SQL3_result_double(context,rVal);
		break;
	}
}
void substrFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	const unsigned char *z,*z2;
	int len,p0type;
	i64 p1,p2;
	p0type=WN_SQL3_value_type(argv[0]);
	if(p0type==WN_SQL_BLOB)
	{
		len=WN_SQL3_value_bytes(argv[0]);
		z=WN_SQL3_value_blob(argv[0]);
		if(z==0)return;
	}
	else
	{
		z=WN_SQL3_value_text(argv[0]);
		if(z==0)return;
		len=0;
		for(z2=z;*z2;len++)WN_SQL_SKIP_UTF8(z2);
	}
	p1=WN_SQL3_value_int(argv[1]);
	p2=WN_SQL3_value_int(argv[2]);
	if(p1<0)
	{
		p1+=len;
		if(p1<0)
		{
			p2+=p1;
			p1=0;
		}
	}
	else
		if(p1>0)p1--;
	if(p1+p2>len)p2=len-p1;
	if(p0type!=WN_SQL_BLOB)
	{
		while(*z && p1)
		{
			WN_SQL_SKIP_UTF8(z);
			p1--;
		}
		for(z2=z;*z2 && p2;p2--)WN_SQL_SKIP_UTF8(z2);
		WN_SQL3_result_text(context,(char*)z,z2-z,WN_SQL_TRANSIENT);
	}
	else
	{
		if(p2<0)p2=0;
		WN_SQL3_result_blob(context,(char*)&z[p1],p2,WN_SQL_TRANSIENT);
	}
}
void roundFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	int n=0;
	double r;
	char zBuf[500];
	if(argc==2)
	{
		if(WN_SQL_NULL==WN_SQL3_value_type(argv[1]))return;
		n=WN_SQL3_value_int(argv[1]);
		if(n>30)n=30;
		if(n<0)n=0;
	}
	if(WN_SQL3_value_type(argv[0])==WN_SQL_NULL)return;
	r=WN_SQL3_value_double(argv[0]);
	WN_SQL3_snprintf(sizeof(zBuf),zBuf,"%.*f",n,r);
	WN_SQL3AtoF(zBuf,&r);
	WN_SQL3_result_double(context,r);
}
void upperFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	char *z1;
	const char *z2;
	int i,n;
	if(argc<1 || WN_SQL_NULL==WN_SQL3_value_type(argv[0]))return;
	z2=(char*)WN_SQL3_value_text(argv[0]);
	n=WN_SQL3_value_bytes(argv[0]);
	if(z2)
	{
		z1=WN_SQL3_malloc(n+1);
		if(z1)
		{
			memcpy(z1,z2,n+1);
			for(i=0;z1[i];i++)z1[i]=toupper(z1[i]);
			WN_SQL3_result_text(context,z1,-1,WN_SQL3_free);
		}
	}
}
void lowerFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	char *z1;
	const char *z2;
	int i,n;
	if(argc<1 || WN_SQL_NULL==WN_SQL3_value_type(argv[0]))return;
	z2=(char*)WN_SQL3_value_text(argv[0]);
	n=WN_SQL3_value_bytes(argv[0]);
	if(z2)
	{
		z1=WN_SQL3_malloc(n+1);
		if(z1)
		{
			memcpy(z1,z2,n+1);
			for(i=0;z1[i];i++)z1[i]=tolower(z1[i]);
			WN_SQL3_result_text(context,z1,-1,WN_SQL3_free);
		}
	}
}
void ifnullFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	int i;
	for(i=0;i<argc;i++)
		if(WN_SQL_NULL!=WN_SQL3_value_type(argv[i]))
		{
			WN_SQL3_result_value(context,argv[i]);
			break;
		}
}
void randomFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	WN_SQL_int64 r;
	WN_SQL3Randomness(sizeof(r),&r);
	if((r<<1)==0)r=0;
	WN_SQL3_result_int64(context,r);
}
void randomBlob(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	int n;
	unsigned char *p;
		n=WN_SQL3_value_int(argv[0]);
	if(n<1)n=1;
	if(n>WN_SQL_MAX_LENGTH)
	{
		WN_SQL3_result_error_toobig(context);
		return;
	}
	p=WN_SQL3Malloc(n);
	if(p)
	{
		WN_SQL3Randomness(n,p);
		WN_SQL3_result_blob(context,(char*)p,n,WN_SQL3FreeX);
}	}
void last_insert_rowid(WN_SQL3_context *context,int arg,WN_SQL3_value **argv)
{	WN_SQL3 *db=WN_SQL3_user_data(context);
	WN_SQL3_result_int64(context,WN_SQL3_last_insert_rowid(db));
}
void changes(WN_SQL3_context *context,int arg,WN_SQL3_value **argv)
{	WN_SQL3 *db=WN_SQL3_user_data(context);
	WN_SQL3_result_int(context,WN_SQL3_changes(db));
}
void total_changes(WN_SQL3_context *context,int arg,WN_SQL3_value **argv)
{	WN_SQL3 *db=WN_SQL3_user_data(context);
	WN_SQL3_result_int(context,WN_SQL3_total_changes(db));
}
struct compareInfo
{	u8 matchAll,matchOne,matchSet,noCase;
};
const struct compareInfo globInfo={'*','?','[',0};
const struct compareInfo likeInfoNorm={'%','_',0,1};
const struct compareInfo likeInfoAlt={'%','_',0,0};
u32 WN_SQL3ReadUtf8(const unsigned char *z)
{	u32 c;
	WN_SQL_READ_UTF8(z,c);
	return c;
}
int patternCompare(const u8 *zPattern,const u8 *zString,const struct compareInfo *pInfo,const int esc)
{
	register int c;
	u8 matchOne=pInfo->matchOne,matchAll=pInfo->matchAll,matchSet=pInfo->matchSet,noCase=pInfo->noCase;
	int invert,seen,c2,prevEscape=0;
	while((c=*zPattern))
	{
		if(!prevEscape && c==matchAll)
		{
			while((c=zPattern[1])==matchAll || c==matchOne)
			{	
				if(c==matchOne)
				{
					if(*zString==0)return 0;
					WN_SQL_SKIP_UTF8(zString);
				}
				zPattern++;
			}
			if(c && esc && WN_SQL3ReadUtf8(&zPattern[1])==esc)
			{
				u8 const *zTemp=&zPattern[1];
				WN_SQL_SKIP_UTF8(zTemp);
				c=*zTemp;
			}
			if(c==0)return 1;
			if(c==matchSet)
			{
				while(*zString && patternCompare(&zPattern[1],zString,pInfo,esc)==0)WN_SQL_SKIP_UTF8(zString);
				return *zString!=0;
			}
			else
			{	while((c2=*zString))
				{	if(noCase)
					{	c2=WN_SQL3UpperToLower[c2];
						c=WN_SQL3UpperToLower[c];
						while(c2  && c2!=c)c2=WN_SQL3UpperToLower[*++zString];
					}
					else
						while(c2  && c2!=c)c2=*++zString;
					if(c2==0)return 0;
					if(patternCompare(&zPattern[1],zString,pInfo,esc))return 1;
					WN_SQL_SKIP_UTF8(zString);
				}
				return 0;
		}	}
		else
			if(!prevEscape && c==matchOne)
			{	if(*zString==0)return 0;
				WN_SQL_SKIP_UTF8(zString);
				zPattern++;
			}
			else
				if(c==matchSet)
				{	int prior_c=0;
					seen=0;
					invert=0;
					c=WN_SQL3ReadUtf8(zString);
					if(c==0)return 0;
					c2=*++zPattern;
					if(c2=='^'){invert=1;c2=*++zPattern;
				}
				if(c2==']')
				{
					if(c==']')seen=1;
					c2=*++zPattern;
				}
				while((c2=WN_SQL3ReadUtf8(zPattern))&& c2!=']')
				{
					if(c2=='-' && zPattern[1]!=']' && zPattern[1] && prior_c>0)
					{
						zPattern++;
						c2=WN_SQL3ReadUtf8(zPattern);
						if(c>=prior_c && c<=c2)seen=1;
						prior_c=0;
					}
					else
						if(c==c2)
						{
							seen=1;
							prior_c=c2;
						}
						else
							prior_c=c2;
					WN_SQL_SKIP_UTF8(zPattern);
				}
				if(c2==0 ||(seen ^ invert)==0)return 0;
				WN_SQL_SKIP_UTF8(zString);
				zPattern++;
		}
		else
			if(esc && !prevEscape && WN_SQL3ReadUtf8(zPattern)==esc)
			{
				prevEscape=1;
				WN_SQL_SKIP_UTF8(zPattern);
			}
			else
			{
				if(noCase)
					if(WN_SQL3UpperToLower[c]!=WN_SQL3UpperToLower[*zString])return 0;
					else
						if(c!=*zString)return 0;
				zPattern++;
				zString++;
				prevEscape=0;
	}		}
	return *zString==0;
}
#ifdef WN_SQL_TEST
int WN_SQL3_like_count=0;
#endif
void likeFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	const unsigned char *zA=WN_SQL3_value_text(argv[1]),*zB=WN_SQL3_value_text(argv[0]);
	int escape=0;
	if(WN_SQL3_value_bytes(argv[0])>WN_SQL_MAX_LIKE_PATTERN_LENGTH)
	{
		WN_SQL3_result_error(context,"LIKE or GLOB pattern too complex",-1);
		return;
	}
	if(argc==3)
	{
		const unsigned char *zEsc=WN_SQL3_value_text(argv[2]);
		if(zEsc==0)return;
		if(WN_SQL3Utf8CharLen((char*)zEsc,-1)!=1)
		{
			WN_SQL3_result_error(context,"ESCAPE expression must be a single character",-1);
			return;
		}
		escape=WN_SQL3ReadUtf8(zEsc);
	}
	if(zA && zB)
	{
		struct compareInfo *pInfo=WN_SQL3_user_data(context);
#ifdef WN_SQL_TEST
		WN_SQL3_like_count++;
#endif
		WN_SQL3_result_int(context,patternCompare(zB,zA,pInfo,escape));
	}
}
void nullifFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	CollSeq *pColl=WN_SQL3GetFuncCollSeq(context);
	if(WN_SQL3MemCompare(argv[0],argv[1],pColl))WN_SQL3_result_value(context,argv[0]);
}
void versionFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	WN_SQL3_result_text(context,WN_SQL3_version,-1,WN_SQL_STATIC);
}
const char hexdigits[]={
'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
};
void quoteFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	if(argc<1)return;
	switch(WN_SQL3_value_type(argv[0]))
	{
	case WN_SQL_NULL:
		WN_SQL3_result_text(context,"NULL",4,WN_SQL_STATIC);
		break;
	case WN_SQL_INTEGER:
	case WN_SQL_FLOAT:
		WN_SQL3_result_value(context,argv[0]);
		break;
	case WN_SQL_BLOB:
		char *zText=0;
		char const *zBlob=WN_SQL3_value_blob(argv[0]);
		int nBlob=WN_SQL3_value_bytes(argv[0]);
		if(2*nBlob+4>WN_SQL_MAX_LENGTH)
		{
			WN_SQL3_result_error_toobig(context);
			return;
		}
		zText=(char *)WN_SQL3Malloc((2*nBlob)+4);
		if(!zText)
			WN_SQL3_result_error(context,"out of memory",-1);
		else
		{
			int i;
			for(i=0;i<nBlob;i++)
			{
				zText[(i*2)+2]=hexdigits[(zBlob[i]>>4)&0x0F];
				zText[(i*2)+3]=hexdigits[(zBlob[i])&0x0F];
			}
			zText[(nBlob*2)+2]='\'';
			zText[(nBlob*2)+3]='\0';
			zText[0]='X';
			zText[1]='\'';
			WN_SQL3_result_text(context,zText,-1,WN_SQL_TRANSIENT);
			WN_SQL3FreeX(zText);
		}
		break;
	case WN_SQL_TEXT:
		const unsigned char *zArg=WN_SQL3_value_text(argv[0]);
		if(zArg==0)return;
		int i,j;
		u64 n;
		for(i=0,n=0;zArg[i];i++) if(zArg[i]=='\'')n++;
		if(i+n+3>WN_SQL_MAX_LENGTH)
		{
			WN_SQL3_result_error_toobig(context);
			return;
		}
		char *z=WN_SQL3Malloc(i+n+3);
		if(z==0)return;
		z[0]='\'';
		for(i=0,j=1;zArg[i];i++)
		{
			z[j++]=zArg[i];
			if(zArg[i]=='\'')z[j++]='\'';
		}
		z[j++]='\'';
		z[j]=0;
		WN_SQL3_result_text(context,z,j,WN_SQL_TRANSIENT);
		WN_SQL3FreeX(z);
	}
}
void hexFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	int i,n=WN_SQL3_value_bytes(argv[0]);
	const unsigned char *pBlob=WN_SQL3_value_blob(argv[0]);
	if(n*2+1>WN_SQL_MAX_LENGTH)
	{
		WN_SQL3_result_error_toobig(context);
		return;
	}
	char *zHex,*z;
	z=zHex=WN_SQL3_malloc(n*2+1);
	if(zHex==0)return;
	for(i=0;i<n;i++,pBlob++)
	{
		unsigned char c=*pBlob;
		*(z++)=hexdigits[(c>>4)&0xf];
		*(z++)=hexdigits[c&0xf];
	}
	*z=0;
	WN_SQL3_result_text(context,zHex,n*2,WN_SQL3_free);
}
void zeroblobFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	i64 n=WN_SQL3_value_int64(argv[0]);
	if(n>WN_SQL_MAX_LENGTH)
		WN_SQL3_result_error_toobig(context);
	else
		WN_SQL3_result_zeroblob(context,n);
}
void replaceFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	const unsigned char *zStr=WN_SQL3_value_text(argv[0]);
	if(zStr==0)return;
	const unsigned char *zPattern=WN_SQL3_value_text(argv[1]);
	if(zPattern==0 || zPattern[0]==0)return;
	const unsigned char *zRep=WN_SQL3_value_text(argv[2]);
	if(zRep==0)return;
	int nStr=WN_SQL3_value_bytes(argv[0]),nPattern=WN_SQL3_value_bytes(argv[1]);
	i64 nOut=nStr+1;
	unsigned char *zOut=WN_SQL3_malloc((int)nOut);
	if(zOut==0)	return;
	int nRep=WN_SQL3_value_bytes(argv[2]),loopLimit=nStr-nPattern,i,j;
	for(i=j=0;i<=loopLimit;i++)
		if(zStr[i]!=zPattern[0] || memcmp(&zStr[i],zPattern,nPattern))
			zOut[j++]=zStr[i];
		else
		{
			nOut+=nRep-nPattern;
			if(nOut>=WN_SQL_MAX_LENGTH)
			{
				WN_SQL3_result_error_toobig(context);
				WN_SQL3_free(zOut);
				return;
			}
			zOut=WN_SQL3_realloc(zOut,(int)nOut);
			if(zOut==0)	return;
			memcpy(&zOut[j],zRep,nRep);
			j+=nRep;
			i+=nPattern-1;
		}
		memcpy(&zOut[j],&zStr[i],nStr-i);
	j+=nStr-i;
		zOut[j]=0;
	WN_SQL3_result_text(context,(char*)zOut,j,WN_SQL3_free);
}
void trimFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	const unsigned char *zIn=WN_SQL3_value_text(argv[0]);
	if(zIn==0)return;
	const unsigned char *zCharSet;
	int nIn,flags,i,nChar;
	unsigned char *aLen;
	const unsigned char **azChar;
	if(WN_SQL3_value_type(argv[0])==WN_SQL_NULL)return;
	nIn=WN_SQL3_value_bytes(argv[0]);
	if(argc==1)
	{
		const unsigned char lenOne[]={1},*azOne[]={(u8*)" "};
		nChar=1;
		aLen=(u8*)lenOne;
		azChar=azOne;
		zCharSet=0;
	}
	else
		if((zCharSet=WN_SQL3_value_text(argv[1]))==0)
			return;
		else
		{
			const unsigned char *z;
			for(z=zCharSet,nChar=0;*z;nChar++)WN_SQL_SKIP_UTF8(z);
			if(nChar>0)
			{
				azChar=WN_SQL3_malloc(nChar*(sizeof(char*)+1));
				if(azChar==0)return;
				aLen=(unsigned char*)&azChar[nChar];
				for(z=zCharSet,nChar=0;*z;nChar++)
				{
					azChar[nChar]=z;
					WN_SQL_SKIP_UTF8(z);
					aLen[nChar]=z-azChar[nChar];
				}
			}
		}
		if(nChar>0)
		{
			flags=(int)WN_SQL3_user_data(context);
			if(flags & 1)
				while(nIn>0)
				{
					int len;
					for(i=0;i<nChar;i++)
					{
						len=aLen[i];
						if(memcmp(zIn,azChar[i],len)==0)break;
					}
					if(i>=nChar)break;
					zIn+=len;
					nIn-=len;
				}
			if(flags & 2)
				while(nIn>0)
				{
					int len;
					for(i=0;i<nChar;i++)
					{
						len=aLen[i];
						if(len<=nIn && memcmp(&zIn[nIn-len],azChar[i],len)==0)
							break;
					}
					if(i>=nChar)break;
					nIn-=len;
				}
			if(zCharSet)
				WN_SQL3_free(azChar);
		}
		WN_SQL3_result_text(context,(char*)zIn,nIn,WN_SQL_TRANSIENT);
}
#ifdef WN_SQL_SOUNDEX
void soundexFunc(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	char zResult[8];
	int i,j;
	const unsigned char iCode[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2,0,0,0,0,0,0,0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2,0,0,0,0,0,};
	const u8 *zIn=(u8*)WN_SQL3_value_text(argv[0]);
	if(zIn==0)zIn=(u8*)"";
	for(i=0;zIn[i] && !isalpha(zIn[i]);i++);
	if(zIn[i])
	{	u8 prevcode=iCode[zIn[i]&0x7f];
		zResult[0]=toupper(zIn[i]);
		for(j=1;j<4 && zIn[i];i++)
		{	int code=iCode[zIn[i]&0x7f];
			if(code>0)
			{	if(code!=prevcode)
				{	prevcode=code;
					zResult[j++]=code+'0';
			}	}
			else
				prevcode=0;
		}
		while(j<4)zResult[j++]='0';
		zResult[j]=0;
		WN_SQL3_result_text(context,zResult,4,WN_SQL_TRANSIENT);
	}
	else
	{
		WN_SQL3_result_text(context,"?000",4,WN_SQL_STATIC);
	}
}
#endif
#ifndef WN_SQL_OMIT_LOAD_EXTENSION
void loadExt(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	const char *zFile=(const char *)WN_SQL3_value_text(argv[0]),*zProc;
	WN_SQL3 *db=WN_SQL3_user_data(context);
	char *zErrMsg=0;
	if(argc==2)
		zProc=(const char *)WN_SQL3_value_text(argv[1]);
	else
		zProc=0;
	if(zFile && WN_SQL3_load_extension(db,zFile,zProc,&zErrMsg))
	{
		WN_SQL3_result_error(context,zErrMsg,-1);
		WN_SQL3_free(zErrMsg);
	}
}
#endif
#ifdef WN_SQL_TEST
void randStr(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	const unsigned char zSrc[]=
"abcdefghijklmnopqrstuvwxyz"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"0123456789"
".-!,:*^+=_|?/<> ";
	int iMin,iMax,n,r,i;
	unsigned char zBuf[1000];
	if(argc>=1)
	{
		iMin=WN_SQL3_value_int(argv[0]);
		if(iMin<0)iMin=0;
		if(iMin>=sizeof(zBuf))iMin=sizeof(zBuf)-1;
	}
	else
		iMin=1;
	if(argc>=2)
	{
		iMax=WN_SQL3_value_int(argv[1]);
		if(iMax<iMin)iMax=iMin;
		if(iMax>=sizeof(zBuf))iMax=sizeof(zBuf)-1;
	}
	else
		iMax=50;
	n=iMin;
	if(iMax>iMin)
	{
		WN_SQL3Randomness(sizeof(r),&r);
		r &=0x7fffffff;
		n+=r%(iMax+1-iMin);
	}
	WN_SQL3Randomness(n,zBuf);
	for(i=0;i<n;i++)zBuf[i]=zSrc[zBuf[i]%(sizeof(zSrc)-1)];
	zBuf[n]=0;
	WN_SQL3_result_text(context,(char*)zBuf,n,WN_SQL_TRANSIENT);
}
#endif
#ifdef WN_SQL_TEST
int test_destructor_count_var=0;
void destructor(void *p)
{
	char *zVal=(char *)p;
	zVal--;
	WN_SQL3FreeX(zVal);
	test_destructor_count_var--;
}
void test_destructor(WN_SQL3_context *pCtx,int nArg,WN_SQL3_value **argv)
{
	char *zVal;
	int len;
	WN_SQL3 *db=WN_SQL3_user_data(pCtx);
	test_destructor_count_var++;
	if(WN_SQL3_value_type(argv[0])==WN_SQL_NULL)return;
	len=WN_SQL3ValueBytes(argv[0],ENC(db));
	zVal=WN_SQL3Malloc(len+3);
	zVal[len]=0;
	zVal[len-1]=0;
	zVal++;
	memcpy(zVal,WN_SQL3ValueText(argv[0],ENC(db)),len);
	if(ENC(db)==WN_SQL_UTF8)
	{
		WN_SQL3_result_text(pCtx,zVal,-1,destructor);
#ifndef WN_SQL_OMIT_UTF16
	}
	else
		if(ENC(db)==WN_SQL_UTF16LE)
			WN_SQL3_result_text16le(pCtx,zVal,-1,destructor);
		else
		{
			WN_SQL3_result_text16be(pCtx,zVal,-1,destructor);
#endif
		}
}
void test_destructor_count(WN_SQL3_context *pCtx,int nArg,WN_SQL3_value **argv)
{	WN_SQL3_result_int(pCtx,test_destructor_count_var);
}
#endif
#ifdef WN_SQL_TEST
void free_test_auxdata(void *p)
{	WN_SQL3FreeX(p);
}
void test_auxdata(WN_SQL3_context *pCtx,int nArg,WN_SQL3_value **argv)
{	int i;
	char *zRet=WN_SQL3Malloc(nArg*2);
	if(!zRet)return;
	for(i=0;i<nArg;i++)
	{	char const *z=(char*)WN_SQL3_value_text(argv[i]);
		if(z)
		{	char *zAux=WN_SQL3_get_auxdata(pCtx,i);
			if(zAux)
			{	zRet[i*2]='1';
				if(strcmp(zAux,z))
				{	WN_SQL3_result_error(pCtx,"Auxilary data corruption",-1);
					return;
			}	}
			else
			{	zRet[i*2]='0';
				zAux=WN_SQLStrDup(z);
				WN_SQL3_set_auxdata(pCtx,i,zAux,free_test_auxdata);
			}
			zRet[i*2+1]=' ';
	}	}
	WN_SQL3_result_text(pCtx,zRet,2*nArg-1,free_test_auxdata);
}
#endif
#ifdef WN_SQL_TEST
void test_error(WN_SQL3_context *pCtx,int nArg,WN_SQL3_value **argv)
{	WN_SQL3_result_error(pCtx,(char*)WN_SQL3_value_text(argv[0]),0);
}
#endif
typedef struct SumCtx SumCtx;
struct SumCtx
{	double rSum;
	i64 iSum,cnt;
	u8 overflow,approx;
};
void sumStep(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	int type;
	SumCtx *p=WN_SQL3_aggregate_context(context,sizeof(*p));
	type=WN_SQL3_value_numeric_type(argv[0]);
	if(p && type!=WN_SQL_NULL)
	{	p->cnt++;
		if(type==WN_SQL_INTEGER)
		{	i64 v=WN_SQL3_value_int64(argv[0]);
			p->rSum+=v;
			if((p->approx|p->overflow)==0)
			{	i64 iNewSum=p->iSum+v;
				int s1=p->iSum >>(sizeof(i64)*8-1),s2=v >>(sizeof(i64)*8-1),s3=iNewSum >>(sizeof(i64)*8-1);
				p->overflow=(s1&s2&~s3)|(~s1&~s2&s3);
				p->iSum=iNewSum;
		}	}
		else
		{
			p->rSum+=WN_SQL3_value_double(argv[0]);
			p->approx=1;
}	}	}
void sumFinalize(WN_SQL3_context *context)
{
	SumCtx *p;
	p=WN_SQL3_aggregate_context(context,0);
	if(p && p->cnt>0)
	{	if(p->overflow)
			WN_SQL3_result_error(context,"integer overflow",-1);
		else
			if(p->approx)
				WN_SQL3_result_double(context,p->rSum);
			else
				WN_SQL3_result_int64(context,p->iSum);
}	}
void avgFinalize(WN_SQL3_context *context)
{	SumCtx *p=WN_SQL3_aggregate_context(context,0);
	if(p && p->cnt>0)WN_SQL3_result_double(context,p->rSum/(double)p->cnt);
}
void totalFinalize(WN_SQL3_context *context)
{	SumCtx *p=WN_SQL3_aggregate_context(context,0);
	WN_SQL3_result_double(context,p ? p->rSum :0.0);
}
typedef struct CountCtx CountCtx;
struct CountCtx
{
	i64 n;
};
void countStep(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{	CountCtx *p=WN_SQL3_aggregate_context(context,sizeof(*p));
	if((argc==0 || WN_SQL_NULL!=WN_SQL3_value_type(argv[0]))&& p)p->n++;
}
void countFinalize(WN_SQL3_context *context)
{	CountCtx *p=WN_SQL3_aggregate_context(context,0);
	WN_SQL3_result_int64(context,p ? p->n :0);
}
void minmaxStep(WN_SQL3_context *context,int argc,WN_SQL3_value **argv)
{
	Mem *pArg=(Mem *)argv[0];Mem *pBest;
	if(WN_SQL3_value_type(argv[0])==WN_SQL_NULL)return;
	pBest=(Mem *)WN_SQL3_aggregate_context(context,sizeof(*pBest));
	if(!pBest)return;
	if(pBest->flags)
	{
		CollSeq *pColl=WN_SQL3GetFuncCollSeq(context);
		int max=WN_SQL3_user_data(context)!=0,cmp=WN_SQL3MemCompare(pBest,pArg,pColl);
		if((max && cmp<0)||(!max && cmp>0))WN_SQL3VdbeMemCopy(pBest,pArg);
	}
	else
		WN_SQL3VdbeMemCopy(pBest,pArg);
}
void minMaxFinalize(WN_SQL3_context *context)
{	WN_SQL3_value *pRes;
	pRes=(WN_SQL3_value *)WN_SQL3_aggregate_context(context,0);
	if(pRes)
	{	if(pRes->flags)WN_SQL3_result_value(context,pRes);
		WN_SQL3VdbeMemRelease(pRes);
	}
}
void WN_SQL3RegisterBuiltinFunctions(WN_SQL3 *db)
{
	const struct
	{
		char *zName;
		signed char nArg;
		u8 argType,eTextRep,needCollSeq;
		void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value **);
	}aFuncs[]={{"min",-1,0,WN_SQL_UTF8,1,minmaxFunc},{"min",0,0,WN_SQL_UTF8,1,0},{"max",-1,1,WN_SQL_UTF8,1,minmaxFunc},{"max",0,1,WN_SQL_UTF8,1,0},{"typeof",1,0,WN_SQL_UTF8,0,typeofFunc},{"length",1,0,WN_SQL_UTF8,0,lengthFunc},{"substr",3,0,WN_SQL_UTF8,0,substrFunc},{"abs",1,0,WN_SQL_UTF8,0,absFunc},{"round",1,0,WN_SQL_UTF8,0,roundFunc},{"round",2,0,WN_SQL_UTF8,0,roundFunc},{"upper",1,0,WN_SQL_UTF8,0,upperFunc},{"lower",1,0,WN_SQL_UTF8,0,lowerFunc},{"coalesce",-1,0,WN_SQL_UTF8,0,ifnullFunc},{"coalesce",0,0,WN_SQL_UTF8,0,0},{"coalesce",1,0,WN_SQL_UTF8,0,0},{"hex",1,0,WN_SQL_UTF8,0,hexFunc},{"ifnull",2,0,WN_SQL_UTF8,1,ifnullFunc},{"random",-1,0,WN_SQL_UTF8,0,randomFunc},{"randomblob",1,0,WN_SQL_UTF8,0,randomBlob},{"nullif",2,0,WN_SQL_UTF8,1,nullifFunc},{"WN_SQL_version",0,0,WN_SQL_UTF8,0,versionFunc},{"quote",1,0,WN_SQL_UTF8,0,quoteFunc},{"last_insert_rowid",0,0xff,WN_SQL_UTF8,0,last_insert_rowid},{"changes",0,0xff,WN_SQL_UTF8,0,changes},{"total_changes",0,0xff,WN_SQL_UTF8,0,total_changes},{"replace",3,0,WN_SQL_UTF8,0,replaceFunc},{"ltrim",1,1,WN_SQL_UTF8,0,trimFunc},{"ltrim",2,1,WN_SQL_UTF8,0,trimFunc},{"rtrim",1,2,WN_SQL_UTF8,0,trimFunc},{"rtrim",2,2,WN_SQL_UTF8,0,trimFunc},{"trim",1,3,WN_SQL_UTF8,0,trimFunc},{"trim",2,3,WN_SQL_UTF8,0,trimFunc},{"zeroblob",1,0,WN_SQL_UTF8,0,zeroblobFunc},#ifdef WN_SQL_SOUNDEX
{"soundex",1,0,WN_SQL_UTF8,0,soundexFunc},#endif
#ifndef WN_SQL_OMIT_LOAD_EXTENSION
{"load_extension",1,0xff,WN_SQL_UTF8,0,loadExt},{"load_extension",2,0xff,WN_SQL_UTF8,0,loadExt},#endif
#ifdef WN_SQL_TEST
{"randstr",2,0,WN_SQL_UTF8,0,randStr},{"test_destructor",1,0xff,WN_SQL_UTF8,0,test_destructor},{"test_destructor_count",0,0,WN_SQL_UTF8,0,test_destructor_count},{"test_auxdata",-1,0,WN_SQL_UTF8,0,test_auxdata},{"test_error",1,0,WN_SQL_UTF8,0,test_error},#endif
};
	const struct
	{	char *zName;
		signed char nArg;
		u8 argType,needCollSeq;
		void(*xStep)(WN_SQL3_context*,int,WN_SQL3_value**);
		void(*xFinalize)(WN_SQL3_context*);
	}aAggs[]={{"min",1,0,1,minmaxStep,minMaxFinalize},{"max",1,1,1,minmaxStep,minMaxFinalize},{"sum",1,0,0,sumStep,sumFinalize},{"total",1,0,0,sumStep,totalFinalize},{"avg",1,0,0,sumStep,avgFinalize},{"count",0,0,0,countStep,countFinalize},{"count",1,0,0,countStep,countFinalize},};
	int i;
	for(i=0;i<sizeof(aFuncs)/sizeof(aFuncs[0]);i++)
	{	void *pArg;
		u8 argType=aFuncs[i].argType;
		if(argType==0xff)
			pArg=db;
		else
			pArg=(void*)(int)argType;
		WN_SQL3CreateFunc(db,aFuncs[i].zName,aFuncs[i].nArg,aFuncs[i].eTextRep,pArg,aFuncs[i].xFunc,0,0);
		if(aFuncs[i].needCollSeq)
		{
			FuncDef *pFunc=WN_SQL3FindFunction(db,aFuncs[i].zName,strlen(aFuncs[i].zName),aFuncs[i].nArg,aFuncs[i].eTextRep,0);
			if(pFunc && aFuncs[i].needCollSeq)pFunc->needCollSeq=1;
	}	}
#ifndef WN_SQL_OMIT_ALTERTABLE
	WN_SQL3AlterFunctions(db);
#endif
#ifndef WN_SQL_OMIT_PARSER
	WN_SQL3AttachFunctions(db);
#endif
	for(i=0;i<sizeof(aAggs)/sizeof(aAggs[0]);i++)
	{	void *pArg=(void*)(int)aAggs[i].argType;
		WN_SQL3CreateFunc(db,aAggs[i].zName,aAggs[i].nArg,WN_SQL_UTF8,pArg,0,aAggs[i].xStep,aAggs[i].xFinalize);
		if(aAggs[i].needCollSeq)
		{	FuncDef *pFunc=WN_SQL3FindFunction(db,aAggs[i].zName,strlen(aAggs[i].zName),aAggs[i].nArg,WN_SQL_UTF8,0);
			if(pFunc && aAggs[i].needCollSeq)pFunc->needCollSeq=1;
	}	}
	WN_SQL3RegisterDateTimeFunctions(db);
	if(!WN_SQL3MallocFailed())
	{	int rc=WN_SQL3_overload_function(db,"MATCH",2);
		if(rc==WN_SQL_NOMEM)WN_SQL3FailedMalloc();
	}
#ifdef WN_SQL_SSE
	(void)WN_SQL3SseFunctions(db);
#endif
#ifdef WN_SQL_CASE_SENSITIVE_LIKE
	WN_SQL3RegisterLikeFunctions(db,1);
#else
	WN_SQL3RegisterLikeFunctions(db,0);
#endif
}
void setLikeOptFlag(WN_SQL3 *db,const char *zName,int flagVal)
{	FuncDef *pDef=WN_SQL3FindFunction(db,zName,strlen(zName),2,WN_SQL_UTF8,0);
	if(pDef)pDef->flags=flagVal;
}
void WN_SQL3RegisterLikeFunctions(WN_SQL3 *db,int caseSensitive)
{	struct compareInfo *pInfo;
	if(caseSensitive)
		pInfo=(struct compareInfo*)&likeInfoAlt;
	else
		pInfo=(struct compareInfo*)&likeInfoNorm;
	WN_SQL3CreateFunc(db,"like",2,WN_SQL_UTF8,pInfo,likeFunc,0,0);
	WN_SQL3CreateFunc(db,"like",3,WN_SQL_UTF8,pInfo,likeFunc,0,0);
	WN_SQL3CreateFunc(db,"glob",2,WN_SQL_UTF8,(struct compareInfo*)&globInfo,likeFunc,0,0);
	setLikeOptFlag(db,"glob",WN_SQL_FUNC_LIKE | WN_SQL_FUNC_CASE);
	setLikeOptFlag(db,"like",caseSensitive ?(WN_SQL_FUNC_LIKE | WN_SQL_FUNC_CASE):WN_SQL_FUNC_LIKE);
}
int WN_SQL3IsLikeFunction(WN_SQL3 *db,Expr *pExpr,int *pIsNocase,char *aWc)
{
	if(pExpr->op!=TK_FUNCTION || !pExpr->pList)return 0;
	if(pExpr->pList->nExpr!=2)return 0;
	FuncDef *pDef=WN_SQL3FindFunction(db,(char*)pExpr->token.z,pExpr->token.n,2,WN_SQL_UTF8,0);
	if(pDef==0 ||(pDef->flags & WN_SQL_FUNC_LIKE)==0)return 0;
	memcpy(aWc,pDef->pUserData,3);
	*pIsNocase=(pDef->flags & WN_SQL_FUNC_CASE)==0;
	return 1;
}
void WN_SQL3IndexAffinityStr(Vdbe *v,Index *pIdx)
{
	if(!pIdx->zColAff)
	{	int n;
		Table *pTab=pIdx->pTable;
		pIdx->zColAff=(char *)WN_SQL3Malloc(pIdx->nColumn+1);
		if(!pIdx->zColAff)return;
		for(n=0;n<pIdx->nColumn;n++)pIdx->zColAff[n]=pTab->aCol[pIdx->aiColumn[n]].affinity;
		pIdx->zColAff[pIdx->nColumn]='\0';
	}WN_SQL3VdbeChangeP3(v,-1,pIdx->zColAff,0);
}
void WN_SQL3TableAffinityStr(Vdbe *v,Table *pTab)
{	if(!pTab->zColAff)
	{	char *zColAff=(char *)WN_SQL3Malloc(pTab->nCol+1);
		if(!zColAff)return;
		int i;
		for(i=0;i<pTab->nCol;i++)zColAff[i]=pTab->aCol[i].affinity;
		zColAff[pTab->nCol]='\0';
		pTab->zColAff=zColAff;
	}
	WN_SQL3VdbeChangeP3(v,-1,pTab->zColAff,0);
}
int selectReadsTable(Select *p,Schema *pSchema,int iTab)
{	if(p->pSrc==0)return 0;
	int i;
	struct SrcList_item *pItem;
	for(i=0,pItem=p->pSrc->a;i<p->pSrc->nSrc;i++,pItem++)
		if(pItem->pSelect)
			if(selectReadsTable(pItem->pSelect,pSchema,iTab))return 1;
		else
			if(pItem->pTab->pSchema==pSchema && pItem->pTab->tnum==iTab)return 1;
	return 0;
}
#ifndef WN_SQL_OMIT_AUTOINCREMENT
int autoIncBegin(Parse *pParse,int iDb,Table *pTab)
{
	int memId=0;
	if(pTab->autoInc)
	{
		Vdbe *v=pParse->pVdbe;
		Db *pDb=&pParse->db->aDb[iDb];
		int iCur=pParse->nTab,addr=WN_SQL3VdbeCurrentAddr(v);
		memId=pParse->nMem+1;
		pParse->nMem+=2;
		WN_SQL3OpenTable(pParse,iCur,iDb,pDb->pSchema->pSeqTab,OP_OpenRead);
		WN_SQL3VdbeAddOp(v,OP_Rewind,iCur,addr+13);
		WN_SQL3VdbeAddOp(v,OP_Column,iCur,0);
		WN_SQL3VdbeOp3(v,OP_String8,0,0,pTab->zName,0);
		WN_SQL3VdbeAddOp(v,OP_Ne,0x100,addr+12);
		WN_SQL3VdbeAddOp(v,OP_Rowid,iCur,0);
		WN_SQL3VdbeAddOp(v,OP_MemStore,memId-1,1);
		WN_SQL3VdbeAddOp(v,OP_Column,iCur,1);
		WN_SQL3VdbeAddOp(v,OP_MemStore,memId,1);
		WN_SQL3VdbeAddOp(v,OP_Goto,0,addr+13);
		WN_SQL3VdbeAddOp(v,OP_Next,iCur,addr+4);
		WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
	}
	return memId;
}
void autoIncStep(Parse *pParse,int memId)
{	if(memId>0)WN_SQL3VdbeAddOp(pParse->pVdbe,OP_MemMax,memId,0);
}
void autoIncEnd(Parse *pParse,int iDb,Table *pTab,int memId)
{	if(pTab->autoInc)
	{	int iCur=pParse->nTab;
		Vdbe *v=pParse->pVdbe;
		Db *pDb=&pParse->db->aDb[iDb];
		int addr=WN_SQL3VdbeCurrentAddr(v);
		WN_SQL3OpenTable(pParse,iCur,iDb,pDb->pSchema->pSeqTab,OP_OpenWrite);
		WN_SQL3VdbeAddOp(v,OP_MemLoad,memId-1,0);
		WN_SQL3VdbeAddOp(v,OP_NotNull,-1,addr+7);
		WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
		WN_SQL3VdbeAddOp(v,OP_NewRowid,iCur,0);
		WN_SQL3VdbeOp3(v,OP_String8,0,0,pTab->zName,0);
		WN_SQL3VdbeAddOp(v,OP_MemLoad,memId,0);
		WN_SQL3VdbeAddOp(v,OP_MakeRecord,2,0);
		WN_SQL3VdbeAddOp(v,OP_Insert,iCur,OPFLAG_APPEND);
		WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
}	}
#else
# define autoIncBegin(A,B,C) (0)
# define autoIncStep(A,B)
# define autoIncEnd(A,B,C,D)
#endif
int xferOptimization(Parse *pParse,Table *pDest,Select *pSelect,int onError,int iDbDest);
void WN_SQL3Insert(Parse *pParse,SrcList *pTabList,ExprList *pList,Select *pSelect,IdList *pColumn,int onError)
{	Table *pTab;
	char *zTab;
	const char *zDb;
	int i,j,idx;
	Vdbe *v;
	Index *pIdx;
	int nColumn;
	int base=0;
	int iCont=0,iBreak=0;
	WN_SQL3 *db;
	int keyColumn=-1,endOfLoop,useTempTable=0,srcTab=0,iSelectLoop=0,iCleanup=0,iInsertBlock=0,iCntMem=0,newIdx=-1;
	Db *pDb;
	int counterMem=0,appendFlag=0,iDb,nHidden=0;
#ifndef WN_SQL_OMIT_TRIGGER
int isView;
	int triggers_exist=0;
#endif
	if(pParse->nErr || WN_SQL3MallocFailed())goto insert_cleanup;
	db=pParse->db;
	zTab=pTabList->a[0].zName;
	if(zTab==0)goto insert_cleanup;
	pTab=WN_SQL3SrcListLookup(pParse,pTabList);
	if(pTab==0)goto insert_cleanup;
	iDb=WN_SQL3SchemaToIndex(db,pTab->pSchema);
	pDb=&db->aDb[iDb];
	zDb=pDb->zName;
	if(WN_SQL3AuthCheck(pParse,WN_SQL_INSERT,pTab->zName,0,zDb))goto insert_cleanup;
#ifndef WN_SQL_OMIT_TRIGGER
	triggers_exist=WN_SQL3TriggersExist(pParse,pTab,TK_INSERT,0);
	isView=pTab->pSelect!=0;
#else
# define triggers_exist 0
# define isView 0
#endif
#ifdef WN_SQL_OMIT_VIEW
# undef isView
# define isView 0
#endif
	if(WN_SQL3IsReadOnly(pParse,pTab,triggers_exist))goto insert_cleanup;
	if(WN_SQL3ViewGetColumnNames(pParse,pTab))goto insert_cleanup;
	v=WN_SQL3GetVdbe(pParse);
	if(v==0)goto insert_cleanup;
	if(pParse->nested==0)WN_SQL3VdbeCountChanges(v);
	WN_SQL3BeginWriteOperation(pParse,pSelect || triggers_exist,iDb);
	if(triggers_exist)newIdx=pParse->nTab++;
#ifndef WN_SQL_OMIT_XFER_OPT
	if(pColumn==0 && xferOptimization(pParse,pTab,pSelect,onError,iDb))goto insert_cleanup;
#endif
	counterMem=autoIncBegin(pParse,iDb,pTab);
	if(pSelect)
	{	int rc,iInitCode=WN_SQL3VdbeAddOp(v,OP_Goto,0,0);
		iSelectLoop=WN_SQL3VdbeCurrentAddr(v);
		iInsertBlock=WN_SQL3VdbeMakeLabel(v);
		rc=WN_SQL3Select(pParse,pSelect,SRT_Subroutine,iInsertBlock,0,0,0,0);
		if(rc || pParse->nErr || WN_SQL3MallocFailed())goto insert_cleanup;
		iCleanup=WN_SQL3VdbeMakeLabel(v);
		WN_SQL3VdbeAddOp(v,OP_Goto,0,iCleanup);
		nColumn=pSelect->pEList->nExpr;
		if(triggers_exist || selectReadsTable(pSelect,pTab->pSchema,pTab->tnum))
			useTempTable=1;
		if(useTempTable)
		{	srcTab=pParse->nTab++;
			WN_SQL3VdbeResolveLabel(v,iInsertBlock);
			WN_SQL3VdbeAddOp(v,OP_MakeRecord,nColumn,0);
			WN_SQL3VdbeAddOp(v,OP_NewRowid,srcTab,0);
			WN_SQL3VdbeAddOp(v,OP_Pull,1,0);
			WN_SQL3VdbeAddOp(v,OP_Insert,srcTab,OPFLAG_APPEND);
			WN_SQL3VdbeAddOp(v,OP_Return,0,0);
			WN_SQL3VdbeJumpHere(v,iInitCode);
			WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,srcTab,0);
			WN_SQL3VdbeAddOp(v,OP_SetNumColumns,srcTab,nColumn);
			WN_SQL3VdbeAddOp(v,OP_Goto,0,iSelectLoop);
			WN_SQL3VdbeResolveLabel(v,iCleanup);
		}
		else
			WN_SQL3VdbeJumpHere(v,iInitCode);
	}
	else
	{	NameContext sNC;
		memset(&sNC,0,sizeof(sNC));
		sNC.pParse=pParse;
		srcTab=-1;
		useTempTable=0;
		nColumn=pList ? pList->nExpr :0;
		for(i=0;i<nColumn;i++)if(WN_SQL3ExprResolveNames(&sNC,pList->a[i].pExpr))goto insert_cleanup;
	}
	if(IsVirtual(pTab))for(i=0;i<pTab->nCol;i++)nHidden+=(IsHiddenColumn(&pTab->aCol[i])? 1 :0);
	if(pColumn==0 && nColumn && nColumn!=(pTab->nCol-nHidden))
	{	WN_SQL3ErrorMsg(pParse,"table %S has %d columns but %d values were supplied",pTabList,0,pTab->nCol,nColumn);
	goto insert_cleanup;
	}
	if(pColumn && nColumn!=pColumn->nId)
	{	WN_SQL3ErrorMsg(pParse,"%d values for %d columns",nColumn,pColumn->nId);
		goto insert_cleanup;
	}
	if(pColumn)
	{	for(i=0;i<pColumn->nId;i++)pColumn->a[i].idx=-1;		for(i=0;i<pColumn->nId;i++)
		{	for(j=0;j<pTab->nCol;j++)
				if(WN_SQL3StrICmp(pColumn->a[i].zName,pTab->aCol[j].zName)==0)
				{	pColumn->a[i].idx=j;
					if(j==pTab->iPKey)keyColumn=i;
					break;
				}
			if(j>=pTab->nCol)
			{	if(WN_SQL3IsRowid(pColumn->a[i].zName))
					keyColumn=i;
				else
				{	WN_SQL3ErrorMsg(pParse,"table %S has no column named %s",pTabList,0,pColumn->a[i].zName);
					pParse->nErr++;
					goto insert_cleanup;
	}	}	}	}
	if(pColumn==0 && nColumn>0)keyColumn=pTab->iPKey;
	if(triggers_exist)
	{	WN_SQL3VdbeAddOp(v,OP_OpenPseudo,newIdx,0);
		WN_SQL3VdbeAddOp(v,OP_SetNumColumns,newIdx,pTab->nCol);
	}
	if(db->flags & WN_SQL_CountRows)
	{	iCntMem=pParse->nMem++;
		WN_SQL3VdbeAddOp(v,OP_MemInt,0,iCntMem);
	}
	if(!triggers_exist)
	{	base=pParse->nTab;
		WN_SQL3OpenTableAndIndices(pParse,pTab,base,OP_OpenWrite);
	}
	if(useTempTable)
	{	iBreak=WN_SQL3VdbeMakeLabel(v);
		WN_SQL3VdbeAddOp(v,OP_Rewind,srcTab,iBreak);
		iCont=WN_SQL3VdbeCurrentAddr(v);
	}
	else
		if(pSelect)
		{	WN_SQL3VdbeAddOp(v,OP_Goto,0,iSelectLoop);
			WN_SQL3VdbeResolveLabel(v,iInsertBlock);
		}
	endOfLoop=WN_SQL3VdbeMakeLabel(v);
	if(triggers_exist & TRIGGER_BEFORE)
	{	if(keyColumn<0)
			WN_SQL3VdbeAddOp(v,OP_Integer,-1,0);
		else
			if(useTempTable)
				WN_SQL3VdbeAddOp(v,OP_Column,srcTab,keyColumn);
			else
			{	WN_SQL3ExprCode(pParse,pList->a[keyColumn].pExpr);
				WN_SQL3VdbeAddOp(v,OP_NotNull,-1,WN_SQL3VdbeCurrentAddr(v)+3);
				WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
				WN_SQL3VdbeAddOp(v,OP_Integer,-1,0);
				WN_SQL3VdbeAddOp(v,OP_MustBeInt,0,0);
			}
		for(i=0;i<pTab->nCol;i++)
		{	if(pColumn==0)
				j=i;
			else
				for(j=0;j<pColumn->nId;j++)if(pColumn->a[j].idx==i)break;
		if(pColumn && j>=pColumn->nId)
			WN_SQL3ExprCode(pParse,pTab->aCol[i].pDflt);
		else
			if(useTempTable)
				WN_SQL3VdbeAddOp(v,OP_Column,srcTab,j);
			else
				WN_SQL3ExprCodeAndCache(pParse,pList->a[j].pExpr);
		}
		WN_SQL3VdbeAddOp(v,OP_MakeRecord,pTab->nCol,0);
		if(!isView)WN_SQL3TableAffinityStr(v,pTab);
		WN_SQL3VdbeAddOp(v,OP_Insert,newIdx,0);
		if(WN_SQL3CodeRowTrigger(pParse,TK_INSERT,0,TRIGGER_BEFORE,pTab,newIdx,-1,onError,endOfLoop))goto insert_cleanup;
	}
	if(triggers_exist && !isView)
	{
		base=pParse->nTab;
		WN_SQL3OpenTableAndIndices(pParse,pTab,base,OP_OpenWrite);
	}
	if(!isView)
	{	if(IsVirtual(pTab))
			WN_SQL3VdbeAddOp(v,OP_Null,0,0);
		if(keyColumn>=0)
		{	if(useTempTable)
				WN_SQL3VdbeAddOp(v,OP_Column,srcTab,keyColumn);
		else
			if(pSelect)
				WN_SQL3VdbeAddOp(v,OP_Dup,nColumn-keyColumn-1,1);
			else
			{	VdbeOp *pOp;
				WN_SQL3ExprCode(pParse,pList->a[keyColumn].pExpr);
				pOp=WN_SQL3VdbeGetOp(v,WN_SQL3VdbeCurrentAddr(v)-1);
				if(pOp && pOp->opcode==OP_Null)
				{	appendFlag=1;
					pOp->opcode=OP_NewRowid;
					pOp->p1=base;
					pOp->p2=counterMem;
			}	}
			if(!appendFlag)
			{	WN_SQL3VdbeAddOp(v,OP_NotNull,-1,WN_SQL3VdbeCurrentAddr(v)+3);
				WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
				WN_SQL3VdbeAddOp(v,OP_NewRowid,base,counterMem);
				WN_SQL3VdbeAddOp(v,OP_MustBeInt,0,0);
		}	}
		else
			if(IsVirtual(pTab))
				WN_SQL3VdbeAddOp(v,OP_Null,0,0);
			else
			{	WN_SQL3VdbeAddOp(v,OP_NewRowid,base,counterMem);
				appendFlag=1;
			}
		autoIncStep(pParse,counterMem);
		nHidden=0;
		for(i=0;i<pTab->nCol;i++)
		{	if(i==pTab->iPKey)
			{	WN_SQL3VdbeAddOp(v,OP_Null,0,0);
				continue;
			}
			if(pColumn==0)
			{	if(IsHiddenColumn(&pTab->aCol[i]))
				{	j=-1;
					nHidden++;
				}
				else
					j=i-nHidden;
			}
			else
				for(j=0;j<pColumn->nId;j++)if(pColumn->a[j].idx==i)break;
			if(j<0 || nColumn==0 ||(pColumn && j>=pColumn->nId))
				WN_SQL3ExprCode(pParse,pTab->aCol[i].pDflt);
			else
				if(useTempTable)
					WN_SQL3VdbeAddOp(v,OP_Column,srcTab,j);
				else
					if(pSelect)
WN_SQL3VdbeAddOp(v,OP_Dup,i+nColumn-j+IsVirtual(pTab),1);
					else
						WN_SQL3ExprCode(pParse,pList->a[j].pExpr);
		}
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		if(IsVirtual(pTab))
		{
			pParse->pVirtualLock=pTab;
			WN_SQL3VdbeOp3(v,OP_VUpdate,1,pTab->nCol+2,(const char*)pTab->pVtab,P3_VTAB);
		}
		else
#endif
		{	WN_SQL3GenerateConstraintChecks(pParse,pTab,base,0,keyColumn>=0,0,onError,endOfLoop);
			WN_SQL3CompleteInsertion(pParse,pTab,base,0,0,0,(triggers_exist & TRIGGER_AFTER)? newIdx :-1,appendFlag);
	}	}
	if((db->flags & WN_SQL_CountRows))WN_SQL3VdbeAddOp(v,OP_MemIncr,1,iCntMem);
	if(triggers_exist)
		if(!isView)
		{	WN_SQL3VdbeAddOp(v,OP_Close,base,0);
			for(idx=1,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,idx++)WN_SQL3VdbeAddOp(v,OP_Close,idx+base,0);
		}
	if(WN_SQL3CodeRowTrigger(pParse,TK_INSERT,0,TRIGGER_AFTER,pTab,newIdx,-1,onError,endOfLoop))goto insert_cleanup;
	}
	WN_SQL3VdbeResolveLabel(v,endOfLoop);
	if(useTempTable)
	{	WN_SQL3VdbeAddOp(v,OP_Next,srcTab,iCont);
		WN_SQL3VdbeResolveLabel(v,iBreak);
		WN_SQL3VdbeAddOp(v,OP_Close,srcTab,0);
	}
	else
		if(pSelect)
		{	WN_SQL3VdbeAddOp(v,OP_Pop,nColumn,0);
			WN_SQL3VdbeAddOp(v,OP_Return,0,0);
			WN_SQL3VdbeResolveLabel(v,iCleanup);
		}
	if(!triggers_exist && !IsVirtual(pTab))
	{
		WN_SQL3VdbeAddOp(v,OP_Close,base,0);
		for(idx=1,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,idx++)WN_SQL3VdbeAddOp(v,OP_Close,idx+base,0);
	}
	autoIncEnd(pParse,iDb,pTab,counterMem);
	if(db->flags & WN_SQL_CountRows && pParse->nested==0 && !pParse->trigStack)
	{
		WN_SQL3VdbeAddOp(v,OP_MemLoad,iCntMem,0);
		WN_SQL3VdbeAddOp(v,OP_Callback,1,0);
		WN_SQL3VdbeSetNumCols(v,1);
		WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"rows inserted",P3_STATIC);
	}
insert_cleanup:
	WN_SQL3SrcListDelete(pTabList);
	WN_SQL3ExprListDelete(pList);
	WN_SQL3SelectDelete(pSelect);
	WN_SQL3IdListDelete(pColumn);
}
void WN_SQL3GenerateConstraintChecks(Parse *pParse,Table *pTab,int base,char *aIdxUsed,int rowidChng,int isUpdate,int overrideError,int ignoreDest)
{	int nCol,onError,addr,extra,iCur,seenReplace=0,jumpInst1=0,jumpInst2,
	hasTwoRowids=(isUpdate && rowidChng),i;
	Index *pIdx;
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	nCol=pTab->nCol;
	for(i=0;i<nCol;i++)
	{
		if(i==pTab->iPKey)continue;
		onError=pTab->aCol[i].notNull;
		if(onError==OE_None)continue;
		if(overrideError!=OE_Default)
			onError=overrideError;
		else
			if(onError==OE_Default)onError=OE_Abort;
		if(onError==OE_Replace && pTab->aCol[i].pDflt==0)onError=OE_Abort;
		WN_SQL3VdbeAddOp(v,OP_Dup,nCol-1-i,1);
addr=WN_SQL3VdbeAddOp(v,OP_NotNull,1,0);
		switch(onError)
		{
		case OE_Rollback:
		case OE_Abort:
		case OE_Fail:
			char *zMsg=0;
			WN_SQL3VdbeAddOp(v,OP_Halt,WN_SQL_CONSTRAINT,onError);
		WN_SQL3SetString(&zMsg,pTab->zName,".",pTab->aCol[i].zName," may not be NULL",(char*)0);
		WN_SQL3VdbeChangeP3(v,-1,zMsg,P3_DYNAMIC);
		break;
	case OE_Ignore:
		WN_SQL3VdbeAddOp(v,OP_Pop,nCol+1+hasTwoRowids,0);
		WN_SQL3VdbeAddOp(v,OP_Goto,0,ignoreDest);
		break;
	case OE_Replace:
		WN_SQL3ExprCode(pParse,pTab->aCol[i].pDflt);
		WN_SQL3VdbeAddOp(v,OP_Push,nCol-i,0);
		break;
		}
		WN_SQL3VdbeJumpHere(v,addr);
	}
#ifndef WN_SQL_OMIT_CHECK
	if(pTab->pCheck &&(pParse->db->flags & WN_SQL_IgnoreChecks)==0)
	{	int allOk=WN_SQL3VdbeMakeLabel(v);
		pParse->ckOffset=nCol;
		WN_SQL3ExprIfTrue(pParse,pTab->pCheck,allOk,1);
		pParse->ckOffset=0;
		onError=overrideError!=OE_Default ? overrideError :OE_Abort;
		if(onError==OE_Ignore || onError==OE_Replace)
		{	WN_SQL3VdbeAddOp(v,OP_Pop,nCol+1+hasTwoRowids,0);
			WN_SQL3VdbeAddOp(v,OP_Goto,0,ignoreDest);
		}
		else
			WN_SQL3VdbeAddOp(v,OP_Halt,WN_SQL_CONSTRAINT,onError);
		WN_SQL3VdbeResolveLabel(v,allOk);
	}
#endif
	if(rowidChng)
	{	onError=pTab->keyConf;
		if(overrideError!=OE_Default)
			onError=overrideError;
		else
			if(onError==OE_Default)onError=OE_Abort;
		if(isUpdate)
		{	WN_SQL3VdbeAddOp(v,OP_Dup,nCol+1,1);
			WN_SQL3VdbeAddOp(v,OP_Dup,nCol+1,1);
			jumpInst1=WN_SQL3VdbeAddOp(v,OP_Eq,0,0);
		}
		WN_SQL3VdbeAddOp(v,OP_Dup,nCol,1);
		jumpInst2=WN_SQL3VdbeAddOp(v,OP_NotExists,base,0);
		switch(onError)
		{
		default:
			onError=OE_Abort;
		case OE_Rollback:
		case OE_Abort:
		case OE_Fail:
			WN_SQL3VdbeOp3(v,OP_Halt,WN_SQL_CONSTRAINT,onError,"PRIMARY KEY must be unique",P3_STATIC);
			break;
		case OE_Replace:
			WN_SQL3GenerateRowIndexDelete(v,pTab,base,0);
			if(isUpdate)
			{
				WN_SQL3VdbeAddOp(v,OP_Dup,nCol+hasTwoRowids,1);
				WN_SQL3VdbeAddOp(v,OP_MoveGe,base,0);
			}
			seenReplace=1;
			break;
		case OE_Ignore:
			WN_SQL3VdbeAddOp(v,OP_Pop,nCol+1+hasTwoRowids,0);
			WN_SQL3VdbeAddOp(v,OP_Goto,0,ignoreDest);
		}
		WN_SQL3VdbeJumpHere(v,jumpInst2);
		if(isUpdate)
		{	WN_SQL3VdbeJumpHere(v,jumpInst1);
			WN_SQL3VdbeAddOp(v,OP_Dup,nCol+1,1);
			WN_SQL3VdbeAddOp(v,OP_MoveGe,base,0);
	}	}
	extra=-1;
	for(iCur=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,iCur++)
	{	if(aIdxUsed && aIdxUsed[iCur]==0)continue;
		extra++;
		WN_SQL3VdbeAddOp(v,OP_Dup,nCol+extra,1);
for(i=0;i<pIdx->nColumn;i++)
		{	int idx=pIdx->aiColumn[i];
			if(idx==pTab->iPKey)
				WN_SQL3VdbeAddOp(v,OP_Dup,i+extra+nCol+1,1);
			else
				WN_SQL3VdbeAddOp(v,OP_Dup,i+extra+nCol-idx,1);
		}
		jumpInst1=WN_SQL3VdbeAddOp(v,OP_MakeIdxRec,pIdx->nColumn,0);
		WN_SQL3IndexAffinityStr(v,pIdx);
		onError=pIdx->onError;
		if(onError==OE_None)continue;
		if(overrideError!=OE_Default)
			onError=overrideError;
		else
			if(onError==OE_Default)onError=OE_Abort;
		if(seenReplace)
		{	if(onError==OE_Ignore)
				onError=OE_Replace;
			else
				if(onError==OE_Fail)onError=OE_Abort;
		}
		WN_SQL3VdbeAddOp(v,OP_Dup,extra+nCol+1+hasTwoRowids,1);
		jumpInst2=WN_SQL3VdbeAddOp(v,OP_IsUnique,base+iCur+1,0);
		switch(onError)
		{
		case OE_Rollback:
		case OE_Abort:
		case OE_Fail:
			char zErrMsg[200];
			WN_SQL3_snprintf(sizeof(zErrMsg),zErrMsg,pIdx->nColumn>1 ? "columns " :"column ");
			int j,n1=strlen(zErrMsg),n2;
			for(j=0;j<pIdx->nColumn && n1<sizeof(zErrMsg)-30;j++)
			{
				char *zCol=pTab->aCol[pIdx->aiColumn[j]].zName;
				n2=strlen(zCol);
				if(j>0)
				{
					WN_SQL3_snprintf(sizeof(zErrMsg)-n1,&zErrMsg[n1],",");
					n1+=2;
				}
				if(n1+n2>sizeof(zErrMsg)-30)
				{
					WN_SQL3_snprintf(sizeof(zErrMsg)-n1,&zErrMsg[n1],"...");
					n1+=3;
					break;
				}
				else
				{
					WN_SQL3_snprintf(sizeof(zErrMsg)-n1,&zErrMsg[n1],"%s",zCol);
					n1+=n2;
			}	}
			WN_SQL3_snprintf(sizeof(zErrMsg)-n1,&zErrMsg[n1],pIdx->nColumn>1 ? " are not unique" :" is not unique");
			WN_SQL3VdbeOp3(v,OP_Halt,WN_SQL_CONSTRAINT,onError,zErrMsg,0);
			break;
		case OE_Ignore:
			WN_SQL3VdbeAddOp(v,OP_Pop,nCol+extra+3+hasTwoRowids,0);
			WN_SQL3VdbeAddOp(v,OP_Goto,0,ignoreDest);
			break;
		case OE_Replace:
			WN_SQL3GenerateRowDelete(pParse->db,v,pTab,base,0);
			if(isUpdate)
			{
				WN_SQL3VdbeAddOp(v,OP_Dup,nCol+extra+1+hasTwoRowids,1);
				WN_SQL3VdbeAddOp(v,OP_MoveGe,base,0);
			}
			seenReplace=1;
			break;
		}
#if NULL_DISTINCT_FOR_UNIQUE
		WN_SQL3VdbeJumpHere(v,jumpInst1);
#endif
		WN_SQL3VdbeJumpHere(v,jumpInst2);
}	}
void WN_SQL3CompleteInsertion(Parse *pParse,Table *pTab,int base,char *aIdxUsed,int rowidChng,int isUpdate,int newIdx,int appendBias)
{
	int i;
	int nIdx;
	Index *pIdx;
	int pik_flags;
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	for(nIdx=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,nIdx++);
	for(i=nIdx-1;i>=0;i--)
	{	if(aIdxUsed && aIdxUsed[i]==0)continue;
		WN_SQL3VdbeAddOp(v,OP_IdxInsert,base+i+1,0);
	}
	WN_SQL3VdbeAddOp(v,OP_MakeRecord,pTab->nCol,0);
	WN_SQL3TableAffinityStr(v,pTab);
#ifndef WN_SQL_OMIT_TRIGGER
	if(newIdx>=0)
	{	WN_SQL3VdbeAddOp(v,OP_Dup,1,0);
		WN_SQL3VdbeAddOp(v,OP_Dup,1,0);
		WN_SQL3VdbeAddOp(v,OP_Insert,newIdx,0);
	}
#endif
	if(pParse->nested)
		pik_flags=0;
	else
	{	pik_flags=OPFLAG_NCHANGE;
		pik_flags |=(isUpdate?OPFLAG_ISUPDATE:OPFLAG_LASTROWID);
	}
	if(appendBias)pik_flags |=OPFLAG_APPEND;
	WN_SQL3VdbeAddOp(v,OP_Insert,base,pik_flags);
	if(!pParse->nested)WN_SQL3VdbeChangeP3(v,-1,pTab->zName,P3_STATIC);
if(isUpdate && rowidChng)WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
}
void WN_SQL3OpenTableAndIndices(Parse *pParse,Table *pTab,int base,int op)
{	if(IsVirtual(pTab))return;
	Index *pIdx;
	int i,iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	WN_SQL3OpenTable(pParse,base,iDb,pTab,op);
	for(i=1,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,i++)
	{	KeyInfo *pKey=WN_SQL3IndexKeyinfo(pParse,pIdx);
		WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
		VdbeComment((v,"# %s",pIdx->zName));
		WN_SQL3VdbeOp3(v,op,i+base,pIdx->tnum,(char*)pKey,P3_KEYINFO_HANDOFF);
	}
	if(pParse->nTab<=base+i)pParse->nTab=base+i;
}
#ifdef WN_SQL_TEST
int WN_SQL3_xferopt_count;
#endif
#ifndef WN_SQL_OMIT_XFER_OPT
int xferCompatibleCollation(const char *z1,const char *z2)
{	if(z1==0)return z2==0;
	if(z2==0)return 0;
	return WN_SQL3StrICmp(z1,z2)==0;
}
int xferCompatibleIndex(Index *pDest,Index *pSrc)
{
	if(pDest->nColumn!=pSrc->nColumn)return 0;
	if(pDest->onError!=pSrc->onError)return 0;
	int i;
	for(i=0;i<pSrc->nColumn;i++)
	{
		if(pSrc->aiColumn[i]!=pDest->aiColumn[i])return 0;
		if(pSrc->aSortOrder[i]!=pDest->aSortOrder[i])return 0;
		if(pSrc->azColl[i]!=pDest->azColl[i])return 0;
	}
	return 1;
}
int xferOptimization(Parse *pParse,Table *pDest,Select *pSelect,int onError,int iDbDest)
{
	ExprList *pEList;
	Table *pSrc;
	Index *pSrcIdx,*pDestIdx;
	struct SrcList_item *pItem;
	int i,iDbSrc,iSrc,iDest,addr1,addr2,emptyDestTest,emptySrcTest,counterMem;
	Vdbe *v;
	KeyInfo *pKey;
	int destHasUniqueIdx=0;
	if(pSelect==0)return 0;
	if(pDest->pTrigger)return 0;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(pDest->isVirtual)return 0;
#endif
	if(onError==OE_Default)onError=OE_Abort;
	if(onError!=OE_Abort && onError!=OE_Rollback)return 0;
	if(pSelect->pSrc==0)return 0;
	if(pSelect->pSrc->nSrc!=1)return 0;
	if(pSelect->pSrc->a[0].pSelect)return 0;
	if(pSelect->pWhere)return 0;
	if(pSelect->pOrderBy)return 0;
	if(pSelect->pGroupBy)return 0;
	if(pSelect->pLimit)return 0;
	if(pSelect->pPrior)return 0;
	if(pSelect->isDistinct)return 0;
	pEList=pSelect->pEList;
	if(pEList->nExpr!=1)return 0;
	if(pEList->a[0].pExpr->op!=TK_ALL)return 0;
	pItem=pSelect->pSrc->a;
	pSrc=WN_SQL3LocateTable(pParse,pItem->zName,pItem->zDatabase);
	if(pSrc==0)return 0;
	if(pSrc==pDest)return 0;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(pSrc->isVirtual)return 0;
#endif
	if(pSrc->pSelect)return 0;
	if(pDest->nCol!=pSrc->nCol)return 0;
	if(pDest->iPKey!=pSrc->iPKey)return 0;
	for(i=0;i<pDest->nCol;i++)
	{	if(pDest->aCol[i].affinity!=pSrc->aCol[i].affinity)return 0;
		if(!xferCompatibleCollation(pDest->aCol[i].zColl,pSrc->aCol[i].zColl))return 0;
		if(pDest->aCol[i].notNull && !pSrc->aCol[i].notNull)return 0;
	}
	for(pDestIdx=pDest->pIndex;pDestIdx;pDestIdx=pDestIdx->pNext)
	{	if(pDestIdx->onError!=OE_None)destHasUniqueIdx=1;
		for(pSrcIdx=pSrc->pIndex;pSrcIdx;pSrcIdx=pSrcIdx->pNext)if(xferCompatibleIndex(pDestIdx,pSrcIdx))break;
		if(pSrcIdx==0)return 0;
	}
#ifndef WN_SQL_OMIT_CHECK
	if(pDest->pCheck && !WN_SQL3ExprCompare(pSrc->pCheck,pDest->pCheck))return 0;
#endif
#ifdef WN_SQL_TEST
	WN_SQL3_xferopt_count++;
#endif
	iDbSrc=WN_SQL3SchemaToIndex(pParse->db,pSrc->pSchema);
	v=WN_SQL3GetVdbe(pParse);
	iSrc=pParse->nTab++;
	iDest=pParse->nTab++;
	counterMem=autoIncBegin(pParse,iDbDest,pDest);
	WN_SQL3OpenTable(pParse,iDest,iDbDest,pDest,OP_OpenWrite);
	if((pDest->iPKey<0 && pDest->pIndex)|| destHasUniqueIdx)
	{	addr1=WN_SQL3VdbeAddOp(v,OP_Rewind,iDest,0);
		emptyDestTest=WN_SQL3VdbeAddOp(v,OP_Goto,0,0);
		WN_SQL3VdbeJumpHere(v,addr1);
	}
	else
		emptyDestTest=0;
	WN_SQL3OpenTable(pParse,iSrc,iDbSrc,pSrc,OP_OpenRead);
	emptySrcTest=WN_SQL3VdbeAddOp(v,OP_Rewind,iSrc,0);
	if(pDest->iPKey>=0)
	{	addr1=WN_SQL3VdbeAddOp(v,OP_Rowid,iSrc,0);
		WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
		addr2=WN_SQL3VdbeAddOp(v,OP_NotExists,iDest,0);
		WN_SQL3VdbeOp3(v,OP_Halt,WN_SQL_CONSTRAINT,onError,"PRIMARY KEY must be unique",P3_STATIC);
		WN_SQL3VdbeJumpHere(v,addr2);
		autoIncStep(pParse,counterMem);
	}
	else
		if(pDest->pIndex)
			addr1=WN_SQL3VdbeAddOp(v,OP_Rowid,iSrc,0);
		else
			addr1=WN_SQL3VdbeAddOp(v,OP_NewRowid,iDest,0);
	WN_SQL3VdbeAddOp(v,OP_RowData,iSrc,0);
	WN_SQL3VdbeOp3(v,OP_Insert,iDest,OPFLAG_NCHANGE|OPFLAG_LASTROWID|OPFLAG_APPEND,pDest->zName,0);
	WN_SQL3VdbeAddOp(v,OP_Next,iSrc,addr1);
	autoIncEnd(pParse,iDbDest,pDest,counterMem);
	for(pDestIdx=pDest->pIndex;pDestIdx;pDestIdx=pDestIdx->pNext)
	{
		for(pSrcIdx=pSrc->pIndex;pSrcIdx;pSrcIdx=pSrcIdx->pNext)if(xferCompatibleIndex(pDestIdx,pSrcIdx))break;
		WN_SQL3VdbeAddOp(v,OP_Close,iSrc,0);
		WN_SQL3VdbeAddOp(v,OP_Close,iDest,0);
		WN_SQL3VdbeAddOp(v,OP_Integer,iDbSrc,0);
		pKey=WN_SQL3IndexKeyinfo(pParse,pSrcIdx);
		VdbeComment((v,"# %s",pSrcIdx->zName));
		WN_SQL3VdbeOp3(v,OP_OpenRead,iSrc,pSrcIdx->tnum,(char*)pKey,P3_KEYINFO_HANDOFF);
		WN_SQL3VdbeAddOp(v,OP_Integer,iDbDest,0);
		pKey=WN_SQL3IndexKeyinfo(pParse,pDestIdx);
		VdbeComment((v,"# %s",pDestIdx->zName));
		WN_SQL3VdbeOp3(v,OP_OpenWrite,iDest,pDestIdx->tnum,(char*)pKey,P3_KEYINFO_HANDOFF);
		addr1=WN_SQL3VdbeAddOp(v,OP_Rewind,iSrc,0);
		WN_SQL3VdbeAddOp(v,OP_RowKey,iSrc,0);
		WN_SQL3VdbeAddOp(v,OP_IdxInsert,iDest,1);
		WN_SQL3VdbeAddOp(v,OP_Next,iSrc,addr1+1);
		WN_SQL3VdbeJumpHere(v,addr1);
	}
	WN_SQL3VdbeJumpHere(v,emptySrcTest);
	WN_SQL3VdbeAddOp(v,OP_Close,iSrc,0);
	WN_SQL3VdbeAddOp(v,OP_Close,iDest,0);
	if(emptyDestTest)
	{
		WN_SQL3VdbeAddOp(v,OP_Halt,0,0);
		WN_SQL3VdbeJumpHere(v,emptyDestTest);
		WN_SQL3VdbeAddOp(v,OP_Close,iDest,0);
		return 0;
	}
	else
		return 1;
}
#endif
int WN_SQL3_exec(WN_SQL3 *db,const char *zSql,WN_SQL3_callback xCallback,void *pArg,char **pzErrMsg)
{
	int rc=0;
	const char *zLeftover;
	WN_SQL3_stmt *pStmt=0;
	char **azCols=0;
	int nRetry=0;
	int nCallback;
	if(zSql==0)return 0;
	while((rc==0 ||(rc==WN_SQL_SCHEMA &&(++nRetry)<2))&& zSql[0])
	{
		int nCol;
		char **azVals=0;
		pStmt=0;
		rc=WN_SQL3_prepare(db,zSql,-1,&pStmt,&zLeftover);
		if(rc)continue;
		if(!pStmt)
		{
			zSql=zLeftover;
			continue;
		}
		nCallback=0;
		nCol=WN_SQL3_column_count(pStmt);
		azCols=WN_SQL3Malloc(2*nCol*sizeof(const char *)+1);
		if(azCols==0)goto exec_out;
		while(1)
		{
			int i;
			rc=WN_SQL3_step(pStmt);
			if(xCallback &&(WN_SQL_ROW==rc ||(WN_SQL_DONE==rc && !nCallback && db->flags&WN_SQL_NullCallback)))
			{
				if(0==nCallback)
				{
					for(i=0;i<nCol;i++)
						azCols[i]=(char *)WN_SQL3_column_name(pStmt,i);
					nCallback++;
				}
				if(rc==WN_SQL_ROW)
				{
					azVals=&azCols[nCol];
					for(i=0;i<nCol;i++)
						azVals[i]=(char *)WN_SQL3_column_text(pStmt,i);
				}
				if(xCallback(pArg,nCol,azVals,azCols))
				{
					rc=WN_SQL_ABORT;
					goto exec_out;
				}
			}
			if(rc!=WN_SQL_ROW)
			{
				rc=WN_SQL3_finalize(pStmt);
				pStmt=0;
				if(rc!=WN_SQL_SCHEMA)
				{
					nRetry=0;
					zSql=zLeftover;
					while(isspace((unsigned char)zSql[0]))zSql++;
				}
				break;
			}
		}
		WN_SQL3FreeX(azCols);
		azCols=0;
	}
exec_out:
	if(pStmt)WN_SQL3_finalize(pStmt);
	if(azCols)WN_SQL3FreeX(azCols);
	rc=WN_SQL3ApiExit(0,rc);
	if(rc && rc==WN_SQL3_errcode(db)&& pzErrMsg)
	{
		int nErrMsg=1+strlen(WN_SQL3_errmsg(db));
		*pzErrMsg=WN_SQL3_malloc(nErrMsg);
		if(*pzErrMsg)memcpy(*pzErrMsg,WN_SQL3_errmsg(db),nErrMsg);
	}
	else
		if(pzErrMsg)*pzErrMsg=0;
	return rc;
}
#ifndef WN_SQL_OMIT_LOAD_EXTENSION
#define WN_SQL_CORE 1
#ifndef _WN_SQL3EXT_H_
#define _WN_SQL3EXT_H_
typedef struct WN_SQL3_api_routines WN_SQL3_api_routines;
struct WN_SQL3_api_routines {
void *(*aggregate_context)(WN_SQL3_context*,int nBytes);
int(*aggregate_count)(WN_SQL3_context*);
int(*bind_blob)(WN_SQL3_stmt*,int,const void*,int n,void(*)(void*));
int(*bind_double)(WN_SQL3_stmt*,int,double);
int(*bind_int)(WN_SQL3_stmt*,int,int);
int(*bind_int64)(WN_SQL3_stmt*,int,WN_SQL_int64);
int(*bind_null)(WN_SQL3_stmt*,int);
int(*bind_parameter_count)(WN_SQL3_stmt*);
int(*bind_parameter_index)(WN_SQL3_stmt*,const char*zName);
const char *(*bind_parameter_name)(WN_SQL3_stmt*,int);
int(*bind_text)(WN_SQL3_stmt*,int,const char*,int n,void(*)(void*));
int(*bind_text16)(WN_SQL3_stmt*,int,const void*,int,void(*)(void*));
int(*bind_value)(WN_SQL3_stmt*,int,const WN_SQL3_value*);
int(*busy_handler)(WN_SQL3*,int(*)(void*,int),void*);
int(*busy_timeout)(WN_SQL3*,int ms);
int(*changes)(WN_SQL3*);
int(*close)(WN_SQL3*);
int(*collation_needed)(WN_SQL3*,void*,void(*)(void*,WN_SQL3*,int eTextRep,const char*));
int(*collation_needed16)(WN_SQL3*,void*,void(*)(void*,WN_SQL3*,int eTextRep,const void*));
const void *(*column_blob)(WN_SQL3_stmt*,int iCol);
int(*column_bytes)(WN_SQL3_stmt*,int iCol);
int(*column_bytes16)(WN_SQL3_stmt*,int iCol);
int(*column_count)(WN_SQL3_stmt*pStmt);
const char *(*column_database_name)(WN_SQL3_stmt*,int);
const void *(*column_database_name16)(WN_SQL3_stmt*,int);
const char *(*column_decltype)(WN_SQL3_stmt*,int i);
const void *(*column_decltype16)(WN_SQL3_stmt*,int);
double(*column_double)(WN_SQL3_stmt*,int iCol);
int(*column_int)(WN_SQL3_stmt*,int iCol);
WN_SQL_int64(*column_int64)(WN_SQL3_stmt*,int iCol);
const char *(*column_name)(WN_SQL3_stmt*,int);
const void *(*column_name16)(WN_SQL3_stmt*,int);
const char *(*column_origin_name)(WN_SQL3_stmt*,int);
const void *(*column_origin_name16)(WN_SQL3_stmt*,int);
const char *(*column_table_name)(WN_SQL3_stmt*,int);
const void *(*column_table_name16)(WN_SQL3_stmt*,int);
const unsigned char *(*column_text)(WN_SQL3_stmt*,int iCol);
const void *(*column_text16)(WN_SQL3_stmt*,int iCol);
int(*column_type)(WN_SQL3_stmt*,int iCol);
WN_SQL3_value*(*column_value)(WN_SQL3_stmt*,int iCol);
void *(*commit_hook)(WN_SQL3*,int(*)(void*),void*);
int(*complete)(const char*sql);
int(*complete16)(const void*sql);
int(*create_collation)(WN_SQL3*,const char*,int,void*,int(*)(void*,int,const void*,int,const void*));
int(*create_collation16)(WN_SQL3*,const char*,int,void*,int(*)(void*,int,const void*,int,const void*));
int(*create_function)(WN_SQL3*,const char*,int,int,void*,void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value**),void(*xStep)(WN_SQL3_context*,int,WN_SQL3_value**),void(*xFinal)(WN_SQL3_context*));
int(*create_function16)(WN_SQL3*,const void*,int,int,void*,void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value**),void(*xStep)(WN_SQL3_context*,int,WN_SQL3_value**),void(*xFinal)(WN_SQL3_context*));
int(*create_module)(WN_SQL3*,const char*,const WN_SQL3_module*,void*);
int(*data_count)(WN_SQL3_stmt*pStmt);
WN_SQL3 *(*db_handle)(WN_SQL3_stmt*);
int(*declare_vtab)(WN_SQL3*,const char*);
int(*enable_shared_cache)(int);
int(*errcode)(WN_SQL3*db);
const char *(*errmsg)(WN_SQL3*);
const void *(*errmsg16)(WN_SQL3*);
int(*exec)(WN_SQL3*,const char*,WN_SQL3_callback,void*,char**);
int(*expired)(WN_SQL3_stmt*);
int(*finalize)(WN_SQL3_stmt*pStmt);
void(*free)(void*);
void(*free_table)(char**result);
int(*get_autocommit)(WN_SQL3*);
void *(*get_auxdata)(WN_SQL3_context*,int);
int(*get_table)(WN_SQL3*,const char*,char***,int*,int*,char**);
int(*global_recover)(void);
void(*interruptx)(WN_SQL3*);
WN_SQL_int64(*last_insert_rowid)(WN_SQL3*);
const char *(*libversion)(void);
int(*libversion_number)(void);
void *(*malloc)(int);
char *(*mprintf)(const char*,...);
int(*open)(const char*,WN_SQL3**);
int(*open16)(const void*,WN_SQL3**);
int(*prepare)(WN_SQL3*,const char*,int,WN_SQL3_stmt**,const char**);
int(*prepare16)(WN_SQL3*,const void*,int,WN_SQL3_stmt**,const void**);
void *(*profile)(WN_SQL3*,void(*)(void*,const char*,WN_SQL_uint64),void*);
void(*progress_handler)(WN_SQL3*,int,int(*)(void*),void*);
void *(*realloc)(void*,int);
int(*reset)(WN_SQL3_stmt*pStmt);
void(*result_blob)(WN_SQL3_context*,const void*,int,void(*)(void*));
void(*result_double)(WN_SQL3_context*,double);
void(*result_error)(WN_SQL3_context*,const char*,int);
void(*result_error16)(WN_SQL3_context*,const void*,int);
void(*result_int)(WN_SQL3_context*,int);
void(*result_int64)(WN_SQL3_context*,WN_SQL_int64);
void(*result_null)(WN_SQL3_context*);
void(*result_text)(WN_SQL3_context*,const char*,int,void(*)(void*));
void(*result_text16)(WN_SQL3_context*,const void*,int,void(*)(void*));
void(*result_text16be)(WN_SQL3_context*,const void*,int,void(*)(void*));
void(*result_text16le)(WN_SQL3_context*,const void*,int,void(*)(void*));
void(*result_value)(WN_SQL3_context*,WN_SQL3_value*);
void *(*rollback_hook)(WN_SQL3*,void(*)(void*),void*);
int(*set_authorizer)(WN_SQL3*,int(*)(void*,int,const char*,const char*,const char*,const char*),void*);
void(*set_auxdata)(WN_SQL3_context*,int,void*,void(*)(void*));
char *(*snprintf)(int,char*,const char*,...);
int(*step)(WN_SQL3_stmt*);
int(*table_column_metadata)(WN_SQL3*,const char*,const char*,const char*,char const**,char const**,int*,int*,int*);
void(*thread_cleanup)(void);
int(*total_changes)(WN_SQL3*);
void *(*trace)(WN_SQL3*,void(*xTrace)(void*,const char*),void*);
int(*transfer_bindings)(WN_SQL3_stmt*,WN_SQL3_stmt*);
void *(*update_hook)(WN_SQL3*,void(*)(void*,int ,char const*,char const*,WN_SQL_int64),void*);
void *(*user_data)(WN_SQL3_context*);
const void *(*value_blob)(WN_SQL3_value*);
int(*value_bytes)(WN_SQL3_value*);
int(*value_bytes16)(WN_SQL3_value*);
double(*value_double)(WN_SQL3_value*);
int(*value_int)(WN_SQL3_value*);
WN_SQL_int64(*value_int64)(WN_SQL3_value*);
int(*value_numeric_type)(WN_SQL3_value*);
const unsigned char *(*value_text)(WN_SQL3_value*);
const void *(*value_text16)(WN_SQL3_value*);
const void *(*value_text16be)(WN_SQL3_value*);
const void *(*value_text16le)(WN_SQL3_value*);
int(*value_type)(WN_SQL3_value*);
char *(*vmprintf)(const char*,va_list);
int(*overload_function)(WN_SQL3*,const char *zFuncName,int nArg);
int(*prepare_v2)(WN_SQL3*,const char*,int,WN_SQL3_stmt**,const char**);
int(*prepare16_v2)(WN_SQL3*,const void*,int,WN_SQL3_stmt**,const void**);
int(*clear_bindings)(WN_SQL3_stmt*);
int(*create_module_v2)(WN_SQL3*,const char*,const WN_SQL3_module*,void*,void(*xDestroy)(void *));
};
#ifndef WN_SQL_CORE
#define WN_SQL3_aggregate_context WN_SQL3_api->aggregate_context
#define WN_SQL3_aggregate_count WN_SQL3_api->aggregate_count
#define WN_SQL3_bind_blob WN_SQL3_api->bind_blob
#define WN_SQL3_bind_double WN_SQL3_api->bind_double
#define WN_SQL3_bind_int WN_SQL3_api->bind_int
#define WN_SQL3_bind_int64 WN_SQL3_api->bind_int64
#define WN_SQL3_bind_null WN_SQL3_api->bind_null
#define WN_SQL3_bind_parameter_count WN_SQL3_api->bind_parameter_count
#define WN_SQL3_bind_parameter_index WN_SQL3_api->bind_parameter_index
#define WN_SQL3_bind_parameter_name WN_SQL3_api->bind_parameter_name
#define WN_SQL3_bind_text WN_SQL3_api->bind_text
#define WN_SQL3_bind_text16 WN_SQL3_api->bind_text16
#define WN_SQL3_bind_value WN_SQL3_api->bind_value
#define WN_SQL3_busy_handler WN_SQL3_api->busy_handler
#define WN_SQL3_busy_timeout WN_SQL3_api->busy_timeout
#define WN_SQL3_changes WN_SQL3_api->changes
#define WN_SQL3_close WN_SQL3_api->close
#define WN_SQL3_collation_needed WN_SQL3_api->collation_needed
#define WN_SQL3_collation_needed16 WN_SQL3_api->collation_needed16
#define WN_SQL3_column_blob WN_SQL3_api->column_blob
#define WN_SQL3_column_bytes WN_SQL3_api->column_bytes
#define WN_SQL3_column_bytes16 WN_SQL3_api->column_bytes16
#define WN_SQL3_column_count WN_SQL3_api->column_count
#define WN_SQL3_column_database_name WN_SQL3_api->column_database_name
#define WN_SQL3_column_database_name16 WN_SQL3_api->column_database_name16
#define WN_SQL3_column_decltype WN_SQL3_api->column_decltype
#define WN_SQL3_column_decltype16 WN_SQL3_api->column_decltype16
#define WN_SQL3_column_double WN_SQL3_api->column_double
#define WN_SQL3_column_int WN_SQL3_api->column_int
#define WN_SQL3_column_int64 WN_SQL3_api->column_int64
#define WN_SQL3_column_name WN_SQL3_api->column_name
#define WN_SQL3_column_name16 WN_SQL3_api->column_name16
#define WN_SQL3_column_origin_name WN_SQL3_api->column_origin_name
#define WN_SQL3_column_origin_name16 WN_SQL3_api->column_origin_name16
#define WN_SQL3_column_table_name WN_SQL3_api->column_table_name
#define WN_SQL3_column_table_name16 WN_SQL3_api->column_table_name16
#define WN_SQL3_column_text WN_SQL3_api->column_text
#define WN_SQL3_column_text16 WN_SQL3_api->column_text16
#define WN_SQL3_column_type WN_SQL3_api->column_type
#define WN_SQL3_column_value WN_SQL3_api->column_value
#define WN_SQL3_commit_hook WN_SQL3_api->commit_hook
#define WN_SQL3_complete WN_SQL3_api->complete
#define WN_SQL3_complete16 WN_SQL3_api->complete16
#define WN_SQL3_create_collation WN_SQL3_api->create_collation
#define WN_SQL3_create_collation16 WN_SQL3_api->create_collation16
#define WN_SQL3_create_function WN_SQL3_api->create_function
#define WN_SQL3_create_function16 WN_SQL3_api->create_function16
#define WN_SQL3_create_module WN_SQL3_api->create_module
#define WN_SQL3_create_module_v2 WN_SQL3_api->create_module_v2
#define WN_SQL3_data_count WN_SQL3_api->data_count
#define WN_SQL3_db_handle WN_SQL3_api->db_handle
#define WN_SQL3_declare_vtab WN_SQL3_api->declare_vtab
#define WN_SQL3_enable_shared_cache WN_SQL3_api->enable_shared_cache
#define WN_SQL3_errcode WN_SQL3_api->errcode
#define WN_SQL3_errmsg WN_SQL3_api->errmsg
#define WN_SQL3_errmsg16 WN_SQL3_api->errmsg16
#define WN_SQL3_exec WN_SQL3_api->exec
#define WN_SQL3_expired WN_SQL3_api->expired
#define WN_SQL3_finalize WN_SQL3_api->finalize
#define WN_SQL3_free WN_SQL3_api->free
#define WN_SQL3_free_table WN_SQL3_api->free_table
#define WN_SQL3_get_autocommit WN_SQL3_api->get_autocommit
#define WN_SQL3_get_auxdata WN_SQL3_api->get_auxdata
#define WN_SQL3_get_table WN_SQL3_api->get_table
#define WN_SQL3_interrupt WN_SQL3_api->interruptx
#define WN_SQL3_last_insert_rowid WN_SQL3_api->last_insert_rowid
#define WN_SQL3_malloc WN_SQL3_api->malloc
#define WN_SQL3_mprintf WN_SQL3_api->mprintf
#define WN_SQL3_open WN_SQL3_api->open
#define WN_SQL3_open16 WN_SQL3_api->open16
#define WN_SQL3_prepare WN_SQL3_api->prepare
#define WN_SQL3_prepare16 WN_SQL3_api->prepare16
#define WN_SQL3_prepare_v2 WN_SQL3_api->prepare_v2
#define WN_SQL3_prepare16_v2 WN_SQL3_api->prepare16_v2
#define WN_SQL3_profile WN_SQL3_api->profile
#define WN_SQL3_progress_handler WN_SQL3_api->progress_handler
#define WN_SQL3_realloc WN_SQL3_api->realloc
#define WN_SQL3_reset WN_SQL3_api->reset
#define WN_SQL3_result_blob WN_SQL3_api->result_blob
#define WN_SQL3_result_double WN_SQL3_api->result_double
#define WN_SQL3_result_error WN_SQL3_api->result_error
#define WN_SQL3_result_error16 WN_SQL3_api->result_error16
#define WN_SQL3_result_int WN_SQL3_api->result_int
#define WN_SQL3_result_int64 WN_SQL3_api->result_int64
#define WN_SQL3_result_null WN_SQL3_api->result_null
#define WN_SQL3_result_text WN_SQL3_api->result_text
#define WN_SQL3_result_text16 WN_SQL3_api->result_text16
#define WN_SQL3_result_text16be WN_SQL3_api->result_text16be
#define WN_SQL3_result_text16le WN_SQL3_api->result_text16le
#define WN_SQL3_result_value WN_SQL3_api->result_value
#define WN_SQL3_rollback_hook WN_SQL3_api->rollback_hook
#define WN_SQL3_set_authorizer WN_SQL3_api->set_authorizer
#define WN_SQL3_set_auxdata WN_SQL3_api->set_auxdata
#define WN_SQL3_snprintf WN_SQL3_api->snprintf
#define WN_SQL3_step WN_SQL3_api->step
#define WN_SQL3_table_column_metadata WN_SQL3_api->table_column_metadata
#define WN_SQL3_thread_cleanup WN_SQL3_api->thread_cleanup
#define WN_SQL3_total_changes WN_SQL3_api->total_changes
#define WN_SQL3_trace WN_SQL3_api->trace
#define WN_SQL3_transfer_bindings WN_SQL3_api->transfer_bindings
#define WN_SQL3_update_hook WN_SQL3_api->update_hook
#define WN_SQL3_user_data WN_SQL3_api->user_data
#define WN_SQL3_value_blob WN_SQL3_api->value_blob
#define WN_SQL3_value_bytes WN_SQL3_api->value_bytes
#define WN_SQL3_value_bytes16 WN_SQL3_api->value_bytes16
#define WN_SQL3_value_double WN_SQL3_api->value_double
#define WN_SQL3_value_int WN_SQL3_api->value_int
#define WN_SQL3_value_int64 WN_SQL3_api->value_int64
#define WN_SQL3_value_numeric_type WN_SQL3_api->value_numeric_type
#define WN_SQL3_value_text WN_SQL3_api->value_text
#define WN_SQL3_value_text16 WN_SQL3_api->value_text16
#define WN_SQL3_value_text16be WN_SQL3_api->value_text16be
#define WN_SQL3_value_text16le WN_SQL3_api->value_text16le
#define WN_SQL3_value_type WN_SQL3_api->value_type
#define WN_SQL3_vmprintf WN_SQL3_api->vmprintf
#define WN_SQL3_overload_function WN_SQL3_api->overload_function
#define WN_SQL3_prepare_v2 WN_SQL3_api->prepare_v2
#define WN_SQL3_prepare16_v2 WN_SQL3_api->prepare16_v2
#define WN_SQL3_clear_bindings WN_SQL3_api->clear_bindings
#endif
#define WN_SQL_EXTENSION_INIT1 const WN_SQL3_api_routines *WN_SQL3_api;
#define WN_SQL_EXTENSION_INIT2(v)WN_SQL3_api=v;
#endif
#ifndef WN_SQL_ENABLE_COLUMN_METADATA
# define WN_SQL3_column_database_name 0
# define WN_SQL3_column_database_name16 0
# define WN_SQL3_column_table_name 0
# define WN_SQL3_column_table_name16 0
# define WN_SQL3_column_origin_name 0
# define WN_SQL3_column_origin_name16 0
# define WN_SQL3_table_column_metadata 0
#endif
#ifdef WN_SQL_OMIT_AUTHORIZATION
# define WN_SQL3_set_authorizer 0
#endif
#ifdef WN_SQL_OMIT_UTF16
# define WN_SQL3_bind_text16 0
# define WN_SQL3_collation_needed16 0
# define WN_SQL3_column_decltype16 0
# define WN_SQL3_column_name16 0
# define WN_SQL3_column_text16 0
# define WN_SQL3_complete16 0
# define WN_SQL3_create_collation16 0
# define WN_SQL3_create_function16 0
# define WN_SQL3_errmsg16 0
# define WN_SQL3_open16 0
# define WN_SQL3_prepare16 0
# define WN_SQL3_prepare16_v2 0
# define WN_SQL3_result_error16 0
# define WN_SQL3_result_text16 0
# define WN_SQL3_result_text16be 0
# define WN_SQL3_result_text16le 0
# define WN_SQL3_value_text16 0
# define WN_SQL3_value_text16be 0
# define WN_SQL3_value_text16le 0
# define WN_SQL3_column_database_name16 0
# define WN_SQL3_column_table_name16 0
# define WN_SQL3_column_origin_name16 0
#endif
#ifdef WN_SQL_OMIT_COMPLETE
# define WN_SQL3_complete 0
# define WN_SQL3_complete16 0
#endif
#ifdef WN_SQL_OMIT_PROGRESS_CALLBACK
# define WN_SQL3_progress_handler 0
#endif
#ifdef WN_SQL_OMIT_VIRTUALTABLE
# define WN_SQL3_create_module 0
# define WN_SQL3_create_module_v2 0
# define WN_SQL3_declare_vtab 0
#endif
#ifdef WN_SQL_OMIT_SHARED_CACHE
# define WN_SQL3_enable_shared_cache 0
#endif
#ifdef WN_SQL_OMIT_TRACE
# define WN_SQL3_profile 0
# define WN_SQL3_trace 0
#endif
#ifdef WN_SQL_OMIT_GET_TABLE
# define WN_SQL3_free_table 0
# define WN_SQL3_get_table 0
#endif
const WN_SQL3_api_routines WN_SQL3_apis={WN_SQL3_aggregate_context,WN_SQL3_aggregate_count,WN_SQL3_bind_blob,WN_SQL3_bind_double,WN_SQL3_bind_int,WN_SQL3_bind_int64,WN_SQL3_bind_null,WN_SQL3_bind_parameter_count,WN_SQL3_bind_parameter_index,WN_SQL3_bind_parameter_name,WN_SQL3_bind_text,WN_SQL3_bind_text16,WN_SQL3_bind_value,WN_SQL3_busy_handler,WN_SQL3_busy_timeout,WN_SQL3_changes,WN_SQL3_close,WN_SQL3_collation_needed,WN_SQL3_collation_needed16,WN_SQL3_column_blob,WN_SQL3_column_bytes,WN_SQL3_column_bytes16,WN_SQL3_column_count,WN_SQL3_column_database_name,WN_SQL3_column_database_name16,WN_SQL3_column_decltype,WN_SQL3_column_decltype16,WN_SQL3_column_double,WN_SQL3_column_int,WN_SQL3_column_int64,WN_SQL3_column_name,WN_SQL3_column_name16,WN_SQL3_column_origin_name,WN_SQL3_column_origin_name16,WN_SQL3_column_table_name,WN_SQL3_column_table_name16,WN_SQL3_column_text,WN_SQL3_column_text16,WN_SQL3_column_type,WN_SQL3_column_value,WN_SQL3_commit_hook,WN_SQL3_complete,WN_SQL3_complete16,WN_SQL3_create_collation,WN_SQL3_create_collation16,WN_SQL3_create_function,WN_SQL3_create_function16,WN_SQL3_create_module,WN_SQL3_data_count,WN_SQL3_db_handle,WN_SQL3_declare_vtab,WN_SQL3_enable_shared_cache,WN_SQL3_errcode,WN_SQL3_errmsg,WN_SQL3_errmsg16,WN_SQL3_exec,WN_SQL3_expired,WN_SQL3_finalize,WN_SQL3_free,WN_SQL3_free_table,WN_SQL3_get_autocommit,WN_SQL3_get_auxdata,WN_SQL3_get_table,0,WN_SQL3_interrupt,WN_SQL3_last_insert_rowid,WN_SQL3_malloc,WN_SQL3_mprintf,WN_SQL3_open,WN_SQL3_open16,WN_SQL3_prepare,WN_SQL3_prepare16,WN_SQL3_profile,WN_SQL3_progress_handler,WN_SQL3_realloc,WN_SQL3_reset,WN_SQL3_result_blob,WN_SQL3_result_double,WN_SQL3_result_error,WN_SQL3_result_error16,WN_SQL3_result_int,WN_SQL3_result_int64,WN_SQL3_result_null,WN_SQL3_result_text,WN_SQL3_result_text16,WN_SQL3_result_text16be,WN_SQL3_result_text16le,WN_SQL3_result_value,WN_SQL3_rollback_hook,WN_SQL3_set_authorizer,WN_SQL3_set_auxdata,WN_SQL3_snprintf,WN_SQL3_step,WN_SQL3_table_column_metadata,WN_SQL3_thread_cleanup,WN_SQL3_total_changes,WN_SQL3_trace,WN_SQL3_transfer_bindings,WN_SQL3_update_hook,WN_SQL3_user_data,WN_SQL3_value_blob,WN_SQL3_value_bytes,WN_SQL3_value_bytes16,WN_SQL3_value_double,WN_SQL3_value_int,WN_SQL3_value_int64,WN_SQL3_value_numeric_type,WN_SQL3_value_text,WN_SQL3_value_text16,WN_SQL3_value_text16be,WN_SQL3_value_text16le,WN_SQL3_value_type,WN_SQL3_vmprintf,WN_SQL3_overload_function,WN_SQL3_prepare_v2,WN_SQL3_prepare16_v2,WN_SQL3_clear_bindings,WN_SQL3_create_module_v2,};
int WN_SQL3_load_extension(WN_SQL3 *db,const char *zFile,const char *zProc,char **pzErrMsg)
{
	void *handle;
	int(*xInit)(WN_SQL3*,char**,const WN_SQL3_api_routines*);
	char *zErrmsg=0;
	void **aHandle;
	if((db->flags & WN_SQL_LoadExtension)==0)
	{
		if(pzErrMsg)*pzErrMsg=WN_SQL3_mprintf("not authorized");
		return WN_SQL_ERROR;
	}
	if(zProc==0)zProc="WN_SQL3_extension_init";
	handle=WN_SQL3OsDlopen(zFile);
	if(handle==0)
	{
		if(pzErrMsg)
			*pzErrMsg=WN_SQL3_mprintf("unable to open shared library [%s]",zFile);
		return WN_SQL_ERROR;
	}
	xInit=(int(*)(WN_SQL3*,char**,const WN_SQL3_api_routines*))
	WN_SQL3OsDlsym(handle,zProc);
	if(xInit==0)
	{
		if(pzErrMsg)
			*pzErrMsg=WN_SQL3_mprintf("no entry point [%s] in shared library [%s]",zProc,zFile);
		WN_SQL3OsDlclose(handle);
		return WN_SQL_ERROR;
	}
	else
		if(xInit(db,&zErrmsg,&WN_SQL3_apis))
		{
			if(pzErrMsg)*pzErrMsg=WN_SQL3_mprintf("error during initialization:%s",zErrmsg);
			WN_SQL3_free(zErrmsg);
			WN_SQL3OsDlclose(handle);
			return WN_SQL_ERROR;
		}
		db->nExtension++;
		aHandle=WN_SQL3Malloc(sizeof(handle)*db->nExtension);
		if(aHandle==0)return WN_SQL_NOMEM;
		if(db->nExtension>0)
			memcpy(aHandle,db->aExtension,sizeof(handle)*(db->nExtension-1));
		WN_SQL3FreeX(db->aExtension);
		db->aExtension=aHandle;
		db->aExtension[db->nExtension-1]=handle;
		return 0;
}
void WN_SQL3CloseExtensions(WN_SQL3 *db)
{
	int i;
	for(i=0;i<db->nExtension;i++)WN_SQL3OsDlclose(db->aExtension[i]);
	WN_SQL3FreeX(db->aExtension);
}
int WN_SQL3_enable_load_extension(WN_SQL3 *db,int onoff)
{
	if(onoff)
		db->flags |=WN_SQL_LoadExtension;
	else
		db->flags &=~WN_SQL_LoadExtension;
	return 0;
}
int nAutoExtension=0;
void **aAutoExtension=0;
int WN_SQL3_auto_extension(void *xInit)
{
	int i,rc=0;
	WN_SQL3OsEnterMutex();
	for(i=0;i<nAutoExtension;i++)if(aAutoExtension[i]==xInit)break;
	if(i==nAutoExtension)
	{
		nAutoExtension++;
		aAutoExtension=WN_SQL3Realloc(aAutoExtension,nAutoExtension*sizeof(aAutoExtension[0]));
		if(aAutoExtension==0)
		{
			nAutoExtension=0;
			rc=WN_SQL_NOMEM;
		}
		else
			aAutoExtension[nAutoExtension-1]=xInit;
	}
	WN_SQL3OsLeaveMutex();
	return rc;
}
void WN_SQL3_reset_auto_extension(void)
{
	WN_SQL3OsEnterMutex();
	WN_SQL3FreeX(aAutoExtension);
	aAutoExtension=0;
	nAutoExtension=0;
	WN_SQL3OsLeaveMutex();
}
int WN_SQL3AutoLoadExtensions(WN_SQL3 *db)
{
	int i,go=1,rc=0;
	int(*xInit)(WN_SQL3*,char**,const WN_SQL3_api_routines*);
	if(nAutoExtension==0)return 0;
	for(i=0;go;i++)
	{
		char *zErrmsg=0;
		WN_SQL3OsEnterMutex();
		if(i>=nAutoExtension)
		{
			xInit=0;
			go=0;
		}
		else
		{
			xInit=(int(*)(WN_SQL3*,char**,const WN_SQL3_api_routines*))
			aAutoExtension[i];
		}
		WN_SQL3OsLeaveMutex();
		if(xInit && xInit(db,&zErrmsg,&WN_SQL3_apis))
		{
			WN_SQL3Error(db,WN_SQL_ERROR,"automatic extension loading failed:%s",zErrmsg);
			go=0;
			rc=WN_SQL_ERROR;
		}
	}
	return rc;
}
#endif
#if !defined(WN_SQL_OMIT_PRAGMA)&& !defined(WN_SQL_OMIT_PARSER)
#if defined(WN_SQL_DEBUG)|| defined(WN_SQL_TEST)
#endif
int getSafetyLevel(const char *z)
{
	const char zText[]="onoffalseyestruefull";
	const u8 iOffset[]={0,1,2,4,9,12,16},iLength[]={2,2,3,5,3,4,4},iValue[]={1,0,0,0,1,1,2};
	if(isdigit(*z))return atoi(z);
	int n=strlen(z),i;
	for(i=0;i<sizeof(iLength);i++)
		if(iLength[i]==n && WN_SQL3StrNICmp(&zText[iOffset[i]],z,n)==0)return iValue[i];
	return 1;
}
int getBoolean(const char *z)
{
	return getSafetyLevel(z)&1;
}
int getLockingMode(const char *z)
{
	if(z)
	{
		if(0==WN_SQL3StrICmp(z,"exclusive"))return PAGER_LOCKINGMODE_EXCLUSIVE;
		if(0==WN_SQL3StrICmp(z,"normal"))return PAGER_LOCKINGMODE_NORMAL;
	}
	return PAGER_LOCKINGMODE_QUERY;
}
#ifndef WN_SQL_OMIT_AUTOVACUUM
int getAutoVacuum(const char *z)
{
	int i;
	if(0==WN_SQL3StrICmp(z,"none"))return BTREE_AUTOVACUUM_NONE;
	if(0==WN_SQL3StrICmp(z,"full"))return BTREE_AUTOVACUUM_FULL;
	if(0==WN_SQL3StrICmp(z,"incremental"))return BTREE_AUTOVACUUM_INCR;
	i=atoi(z);
	return((i>=0&&i<=2)?i:0);
}
#endif
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
int getTempStore(const char *z)
{
	if(z[0]>='0' && z[0]<='2')
		return z[0]-'0';
	else
		if(WN_SQL3StrICmp(z,"file")==0)return 1;
		else
			if(WN_SQL3StrICmp(z,"memory")==0)
				return 2;
			else
				return 0;
}
#endif
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
int invalidateTempStorage(Parse *pParse)
{
	WN_SQL3 *db=pParse->db;
	if(db->aDb[1].pBt)
	{
		if(!db->autoCommit)
		{
			WN_SQL3ErrorMsg(pParse,"temporary storage cannot be changed "
"from within a transaction");
			return WN_SQL_ERROR;
		}
		WN_SQL3BtreeClose(db->aDb[1].pBt);
		db->aDb[1].pBt=0;
		WN_SQL3ResetInternalSchema(db,0);
	}
	return 0;
}
#endif
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
int changeTempStorage(Parse *pParse,const char *zStorageType)
{
	int ts=getTempStore(zStorageType);
	WN_SQL3 *db=pParse->db;
	if(db->temp_store==ts)return 0;
	if(invalidateTempStorage(pParse))return WN_SQL_ERROR;
	db->temp_store=ts;
	return 0;
}
#endif
void returnSingleInt(Parse *pParse,const char *zLabel,int value)
{
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	WN_SQL3VdbeAddOp(v,OP_Integer,value,0);
	if(pParse->explain==0)
	{
		WN_SQL3VdbeSetNumCols(v,1);
		WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,zLabel,P3_STATIC);
	}
	WN_SQL3VdbeAddOp(v,OP_Callback,1,0);
}
#ifndef WN_SQL_OMIT_FLAG_PRAGMAS
int flagPragma(Parse *pParse,const char *zLeft,const char *zRight)
{
	const struct sPragmaType
	{
		const char *zName;
		int mask;
	}aPragma[]={{"full_column_names",WN_SQL_FullColNames},{"short_column_names",WN_SQL_ShortColNames},{"count_changes",WN_SQL_CountRows},{"empty_result_callbacks",WN_SQL_NullCallback},{"legacy_file_format",WN_SQL_LegacyFileFmt},{"fullfsync",WN_SQL_FullFSync},#ifdef WN_SQL_DEBUG
{"sql_trace",WN_SQL_SqlTrace},{"vdbe_listing",WN_SQL_VdbeListing},{"vdbe_trace",WN_SQL_VdbeTrace},#endif
#ifndef WN_SQL_OMIT_CHECK
{"ignore_check_constraints",WN_SQL_IgnoreChecks},#endif
{"writable_schema",WN_SQL_WriteSchema|WN_SQL_RecoveryMode},{"omit_readlock",WN_SQL_NoReadlock},{"read_uncommitted",WN_SQL_ReadUncommitted},};
	int i;
	const struct sPragmaType *p;
	for(i=0,p=aPragma;i<sizeof(aPragma)/sizeof(aPragma[0]);i++,p++)
		if(WN_SQL3StrICmp(zLeft,p->zName)==0)
		{
			WN_SQL3 *db=pParse->db;
			Vdbe *v=WN_SQL3GetVdbe(pParse);
			if(v)
				if(zRight==0)
					returnSingleInt(pParse,p->zName,(db->flags & p->mask)!=0);
				else
				{
					if(getBoolean(zRight))
						db->flags |=p->mask;
					else
						db->flags &=~p->mask;
				}
			return 1;
		}
	return 0;
}
#endif
void WN_SQL3Pragma(Parse *pParse,Token *pId1,Token *pId2,Token *pValue,int minusFlag)
{
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v==0)return;
	char *zRight=0;
	Token *pId;
	WN_SQL3 *db=pParse->db;
	Db *pDb;
	int iDb=WN_SQL3TwoPartName(pParse,pId1,pId2,&pId);
	if(iDb<0)return;
	pDb=&db->aDb[iDb];
	if(iDb==1 && WN_SQL3OpenTempDatabase(pParse))return;
	char zLeft=WN_SQL3NameFromToken(pId);
	if(!zLeft)return;
	if(minusFlag)
		zRight=WN_SQL3MPrintf("-%T",pValue);
	else
		zRight=WN_SQL3NameFromToken(pValue);
	const char *zDb=((iDb>0)?pDb->zName:0);
	if(WN_SQL3AuthCheck(pParse,WN_SQL_PRAGMA,zLeft,zRight,zDb))goto pragma_out;
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
	if(WN_SQL3StrICmp(zLeft,"default_cache_size")==0)
	{
		const VdbeOpList getCacheSize[]={{OP_ReadCookie,0,2,0},{OP_AbsValue,0,0,0},{OP_Dup,0,0,0},{OP_Integer,0,0,0},{OP_Ne,0,6,0},{OP_Integer,0,0,0},{OP_Callback,1,0,0},};
		int addr;
		if(WN_SQL3ReadSchema(pParse))goto pragma_out;
		if(!zRight)
		{
			WN_SQL3VdbeSetNumCols(v,1);
			WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"cache_size",P3_STATIC);
			addr=WN_SQL3VdbeAddOpList(v,ArraySize(getCacheSize),getCacheSize);
			WN_SQL3VdbeChangeP1(v,addr,iDb);
			WN_SQL3VdbeChangeP1(v,addr+5,WN_SQL_DEFAULT_CACHE_SIZE);
		}
		else
		{
			int size=atoi(zRight);
			if(size<0)size=-size;
			WN_SQL3BeginWriteOperation(pParse,0,iDb);
		WN_SQL3VdbeAddOp(v,OP_Integer,size,0);
		WN_SQL3VdbeAddOp(v,OP_ReadCookie,iDb,2);
		addr=WN_SQL3VdbeAddOp(v,OP_Integer,0,0);
		WN_SQL3VdbeAddOp(v,OP_Ge,0,addr+3);
		WN_SQL3VdbeAddOp(v,OP_Negative,0,0);
		WN_SQL3VdbeAddOp(v,OP_SetCookie,iDb,2);
		pDb->pSchema->cache_size=size;
		WN_SQL3BtreeSetCacheSize(pDb->pBt,pDb->pSchema->cache_size);
		}
	}
	else
		if(WN_SQL3StrICmp(zLeft,"page_size")==0)
		{
			Btree *pBt=pDb->pBt;
			if(!zRight)
			{
				int size=pBt ? WN_SQL3BtreeGetPageSize(pBt):0;
				returnSingleInt(pParse,"page_size",size);
			}
			else
				WN_SQL3BtreeSetPageSize(pBt,atoi(zRight),-1);
		}
		else
			if(WN_SQL3StrICmp(zLeft,"max_page_count")==0)
			{
				Btree *pBt=pDb->pBt;
				int newMax=0;
				if(zRight)newMax=atoi(zRight);
				if(pBt)newMax=WN_SQL3BtreeMaxPageCount(pBt,newMax);
				returnSingleInt(pParse,"max_page_count",newMax);
			}
			else
				if(WN_SQL3StrICmp(zLeft,"locking_mode")==0)
				{
					const char *zRet="normal";
					int eMode=getLockingMode(zRight);
					if(pId2->n==0 && eMode==PAGER_LOCKINGMODE_QUERY)
						eMode=db->dfltLockMode;
					else
					{
						Pager *pPager;
						if(pId2->n==0)
						{
							int ii;
							for(ii=2;ii<db->nDb;ii++)
							{
								pPager=WN_SQL3BtreePager(db->aDb[ii].pBt);
								WN_SQL3PagerLockingMode(pPager,eMode);
							}
							db->dfltLockMode=eMode;
						}
						pPager=WN_SQL3BtreePager(pDb->pBt);
						eMode=WN_SQL3PagerLockingMode(pPager,eMode);
					}
					if(eMode==PAGER_LOCKINGMODE_EXCLUSIVE)zRet="exclusive";
					WN_SQL3VdbeSetNumCols(v,1);
					WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"locking_mode",P3_STATIC);
					WN_SQL3VdbeOp3(v,OP_String8,0,0,zRet,0);
					WN_SQL3VdbeAddOp(v,OP_Callback,1,0);
				}
				else
#endif
#ifndef WN_SQL_OMIT_AUTOVACUUM
					if(WN_SQL3StrICmp(zLeft,"auto_vacuum")==0)
					{
						Btree *pBt=pDb->pBt;
						if(WN_SQL3ReadSchema(pParse))goto pragma_out;
						if(!zRight)
						{
							int auto_vacuum=pBt ? WN_SQL3BtreeGetAutoVacuum(pBt):WN_SQL_DEFAULT_AUTOVACUUM;
							returnSingleInt(pParse,"auto_vacuum",auto_vacuum);
						}
						else
						{
							int eAuto=getAutoVacuum(zRight);
							if(eAuto>=0)
							{
								int rc=WN_SQL3BtreeSetAutoVacuum(pBt,eAuto);
								if(rc==0 &&(eAuto==1 || eAuto==2))
								{
									const VdbeOpList setMeta6[]={
{OP_Transaction,0,1,0},{OP_ReadCookie,0,3,0},{OP_If,0,0,0},{OP_Halt,0,OE_Abort,0},{OP_Integer,0,0,0},{OP_SetCookie,0,6,0},};
									int iAddr=	WN_SQL3VdbeAddOpList(v,ArraySize(setMeta6),setMeta6);
WN_SQL3VdbeChangeP1(v,iAddr,iDb);
WN_SQL3VdbeChangeP1(v,iAddr+1,iDb);
WN_SQL3VdbeChangeP2(v,iAddr+2,iAddr+4);
WN_SQL3VdbeChangeP1(v,iAddr+4,eAuto-1);
									WN_SQL3VdbeChangeP1(v,iAddr+5,iDb);
					}	}	}	}
					else
#endif
#ifndef WN_SQL_OMIT_AUTOVACUUM
						if(WN_SQL3StrICmp(zLeft,"incremental_vacuum")==0)
						{
							int iLimit,addr;
							if(WN_SQL3ReadSchema(pParse))goto pragma_out;
							if(zRight==0 || !WN_SQL3GetInt32(zRight,&iLimit)|| iLimit<=0)iLimit=0x7fffffff;
							WN_SQL3BeginWriteOperation(pParse,0,iDb);
							WN_SQL3VdbeAddOp(v,OP_MemInt,iLimit,0);
							addr=WN_SQL3VdbeAddOp(v,OP_IncrVacuum,iDb,0);
							WN_SQL3VdbeAddOp(v,OP_Callback,0,0);
							WN_SQL3VdbeAddOp(v,OP_MemIncr,-1,0);
							WN_SQL3VdbeAddOp(v,OP_IfMemPos,0,addr);
							WN_SQL3VdbeJumpHere(v,addr);
						}
						else
#endif
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
							if(WN_SQL3StrICmp(zLeft,"cache_size")==0)
							{
								if(WN_SQL3ReadSchema(pParse))goto pragma_out;
								if(!zRight)
									returnSingleInt(pParse,"cache_size",pDb->pSchema->cache_size);
								else
								{
									int size=atoi(zRight);
									if(size<0)size=-size;
									pDb->pSchema->cache_size=size;
									WN_SQL3BtreeSetCacheSize(pDb->pBt,pDb->pSchema->cache_size);
								}
							}
							else
								if(WN_SQL3StrICmp(zLeft,"temp_store")==0)
								{
									if(!zRight)
										returnSingleInt(pParse,"temp_store",db->temp_store);
									else
										changeTempStorage(pParse,zRight);
								}
								else
									if(WN_SQL3StrICmp(zLeft,"temp_store_directory")==0)
									{
										if(!zRight)
										{
											if(WN_SQL3_temp_directory)
											{
												WN_SQL3VdbeSetNumCols(v,1);
												WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"temp_store_directory",P3_STATIC);
												WN_SQL3VdbeOp3(v,OP_String8,0,0,WN_SQL3_temp_directory,0);
												WN_SQL3VdbeAddOp(v,OP_Callback,1,0);
											}
										}
										else
										{
											if(zRight[0] && !WN_SQL3OsIsDirWritable(zRight))
											{
												WN_SQL3ErrorMsg(pParse,"not a writable directory");
												goto pragma_out;
											}
											if(TEMP_STORE==0 ||(TEMP_STORE==1 && db->temp_store<=1)||(TEMP_STORE==2 && db->temp_store==1))invalidateTempStorage(pParse);
											WN_SQL3FreeX(WN_SQL3_temp_directory);
											if(zRight[0])
											{
												WN_SQL3_temp_directory=zRight;
												zRight=0;
											}
											else
												WN_SQL3_temp_directory=0;
										}
									}
									else
										if(WN_SQL3StrICmp(zLeft,"synchronous")==0)
										{
											if(WN_SQL3ReadSchema(pParse))goto pragma_out;
											if(!zRight)
												returnSingleInt(pParse,"synchronous",pDb->safety_level-1);
											else
											{
												if(!db->autoCommit)
													WN_SQL3ErrorMsg(pParse,"Safety level may not be changed inside a transaction");
												else
													pDb->safety_level=getSafetyLevel(zRight)+1;
											}
										}
										else
#endif
#ifndef WN_SQL_OMIT_FLAG_PRAGMAS
if(flagPragma(pParse,zLeft,zRight)){
}else
#endif
#ifndef WN_SQL_OMIT_SCHEMA_PRAGMAS
	if(WN_SQL3StrICmp(zLeft,"table_info")==0 && zRight)
{
	if(WN_SQL3ReadSchema(pParse))goto pragma_out;
	Table *pTab=WN_SQL3FindTable(db,zRight,zDb);
	if(pTab)
	{
		int i,nHidden=0;
		Column *pCol;
		WN_SQL3VdbeSetNumCols(v,6);
		WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"cid",P3_STATIC);
		WN_SQL3VdbeSetColName(v,1,COLNAME_NAME,"name",P3_STATIC);
		WN_SQL3VdbeSetColName(v,2,COLNAME_NAME,"type",P3_STATIC);
		WN_SQL3VdbeSetColName(v,3,COLNAME_NAME,"notnull",P3_STATIC);
		WN_SQL3VdbeSetColName(v,4,COLNAME_NAME,"dflt_value",P3_STATIC);
		WN_SQL3VdbeSetColName(v,5,COLNAME_NAME,"pk",P3_STATIC);
		WN_SQL3ViewGetColumnNames(pParse,pTab);
		for(i=0,pCol=pTab->aCol;i<pTab->nCol;i++,pCol++)
		{
			const Token *pDflt;
			if(IsHiddenColumn(pCol))
			{
				nHidden++;
				continue;
			}
			WN_SQL3VdbeAddOp(v,OP_Integer,i-nHidden,0);
			WN_SQL3VdbeOp3(v,OP_String8,0,0,pCol->zName,0);
			WN_SQL3VdbeOp3(v,OP_String8,0,0,pCol->zType ? pCol->zType :"",0);
			WN_SQL3VdbeAddOp(v,OP_Integer,pCol->notNull,0);
			if(pCol->pDflt &&(pDflt=&pCol->pDflt->span)->z)
				WN_SQL3VdbeOp3(v,OP_String8,0,0,(char*)pDflt->z,pDflt->n);
			else
				WN_SQL3VdbeAddOp(v,OP_Null,0,0);
			WN_SQL3VdbeAddOp(v,OP_Integer,pCol->isPrimKey,0);
			WN_SQL3VdbeAddOp(v,OP_Callback,6,0);
		}
	}
}
	else
		if(WN_SQL3StrICmp(zLeft,"index_info")==0 && zRight)
		{
			Table *pTab;
			if(WN_SQL3ReadSchema(pParse))goto pragma_out;
			Index *pIdx=WN_SQL3FindIndex(db,zRight,zDb);
			if(pIdx)
			{
				int i;
				pTab=pIdx->pTable;
				WN_SQL3VdbeSetNumCols(v,3);
				WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"seqno",P3_STATIC);
				WN_SQL3VdbeSetColName(v,1,COLNAME_NAME,"cid",P3_STATIC);
				WN_SQL3VdbeSetColName(v,2,COLNAME_NAME,"name",P3_STATIC);
				for(i=0;i<pIdx->nColumn;i++)
				{	int cnum=pIdx->aiColumn[i];
					WN_SQL3VdbeAddOp(v,OP_Integer,i,0);
					WN_SQL3VdbeAddOp(v,OP_Integer,cnum,0);
					WN_SQL3VdbeOp3(v,OP_String8,0,0,pTab->aCol[cnum].zName,0);
					WN_SQL3VdbeAddOp(v,OP_Callback,3,0);
		}	}	}
		else
			if(WN_SQL3StrICmp(zLeft,"index_list")==0 && zRight)
			{	Index *pIdx;
				if(WN_SQL3ReadSchema(pParse))goto pragma_out;
				Table *pTab=WN_SQL3FindTable(db,zRight,zDb);
				if(pTab)
				{	v=WN_SQL3GetVdbe(pParse);
					pIdx=pTab->pIndex;
					if(pIdx)
					{	int i=0;
						WN_SQL3VdbeSetNumCols(v,3);
						WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"seq",P3_STATIC);
						WN_SQL3VdbeSetColName(v,1,COLNAME_NAME,"name",P3_STATIC);
						WN_SQL3VdbeSetColName(v,2,COLNAME_NAME,"unique",P3_STATIC);
						while(pIdx)
						{	WN_SQL3VdbeAddOp(v,OP_Integer,i,0);
							WN_SQL3VdbeOp3(v,OP_String8,0,0,pIdx->zName,0);
							WN_SQL3VdbeAddOp(v,OP_Integer,pIdx->onError!=OE_None,0);
							WN_SQL3VdbeAddOp(v,OP_Callback,3,0);
							++i;
							pIdx=pIdx->pNext;
						}
					}
				}
			}
			else
				if(WN_SQL3StrICmp(zLeft,"database_list")==0)
				{
					int i;
					if(WN_SQL3ReadSchema(pParse))goto pragma_out;
					WN_SQL3VdbeSetNumCols(v,3);
					WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"seq",P3_STATIC);
					WN_SQL3VdbeSetColName(v,1,COLNAME_NAME,"name",P3_STATIC);
					WN_SQL3VdbeSetColName(v,2,COLNAME_NAME,"file",P3_STATIC);
					for(i=0;i<db->nDb;i++)
					{
						if(db->aDb[i].pBt==0)continue;
						WN_SQL3VdbeAddOp(v,OP_Integer,i,0);
						WN_SQL3VdbeOp3(v,OP_String8,0,0,db->aDb[i].zName,0);
						WN_SQL3VdbeOp3(v,OP_String8,0,0,WN_SQL3BtreeGetFilename(db->aDb[i].pBt),0);
						WN_SQL3VdbeAddOp(v,OP_Callback,3,0);
					}
				}
				else
					if(WN_SQL3StrICmp(zLeft,"collation_list")==0)
					{
						int i=0;
						HashElem *p;
						WN_SQL3VdbeSetNumCols(v,2);
						WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"seq",P3_STATIC);
						WN_SQL3VdbeSetColName(v,1,COLNAME_NAME,"name",P3_STATIC);
						for(p=WN_SQLHashFirst(&db->aCollSeq);p;p=WN_SQLHashNext(p))
						{
							CollSeq *pColl=(CollSeq *)WN_SQLHashData(p);
							WN_SQL3VdbeAddOp(v,OP_Integer,i++,0);
							WN_SQL3VdbeOp3(v,OP_String8,0,0,pColl->zName,0);
							WN_SQL3VdbeAddOp(v,OP_Callback,2,0);
						}
					}
					else
#endif
#ifndef WN_SQL_OMIT_FOREIGN_KEY
						if(WN_SQL3StrICmp(zLeft,"foreign_key_list")==0 && zRight)
						{
							FKey *pFK;
							if(WN_SQL3ReadSchema(pParse))goto pragma_out;
							Table *pTab=WN_SQL3FindTable(db,zRight,zDb);
							if(pTab)
							{
								v=WN_SQL3GetVdbe(pParse);
								pFK=pTab->pFKey;
								if(pFK)
								{
									int i=0;
									WN_SQL3VdbeSetNumCols(v,5);
									WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"id",P3_STATIC);
									WN_SQL3VdbeSetColName(v,1,COLNAME_NAME,"seq",P3_STATIC);
									WN_SQL3VdbeSetColName(v,2,COLNAME_NAME,"table",P3_STATIC);
									WN_SQL3VdbeSetColName(v,3,COLNAME_NAME,"from",P3_STATIC);
									WN_SQL3VdbeSetColName(v,4,COLNAME_NAME,"to",P3_STATIC);
									while(pFK)
									{
										int j;
										for(j=0;j<pFK->nCol;j++)
										{
											char *zCol=pFK->aCol[j].zCol;
											WN_SQL3VdbeAddOp(v,OP_Integer,i,0);
											WN_SQL3VdbeAddOp(v,OP_Integer,j,0);
											WN_SQL3VdbeOp3(v,OP_String8,0,0,pFK->zTo,0);
											WN_SQL3VdbeOp3(v,OP_String8,0,0,pTab->aCol[pFK->aCol[j].iFrom].zName,0);
											WN_SQL3VdbeOp3(v,zCol ? OP_String8 :OP_Null,0,0,zCol,0);
											WN_SQL3VdbeAddOp(v,OP_Callback,5,0);
										}
										++i;
										pFK=pFK->pNextFrom;
									}
								}
							}
						}
						else
#endif
#ifndef NDEBUG
							if(WN_SQL3StrICmp(zLeft,"parser_trace")==0)
							{
								if(zRight)
								{
									if(getBoolean(zRight))
										WN_SQL3ParserTrace(stderr,"parser:");
									else
										WN_SQL3ParserTrace(0,0);
								}
							}
							else
#endif
								if(WN_SQL3StrICmp(zLeft,"case_sensitive_like")==0){
								if(zRight)WN_SQL3RegisterLikeFunctions(db,getBoolean(zRight));
					}
					else
#ifndef WN_SQL_INTEGRITY_CHECK_ERROR_MAX
# define WN_SQL_INTEGRITY_CHECK_ERROR_MAX 100
#endif
#ifndef WN_SQL_OMIT_INTEGRITY_CHECK
						if(WN_SQL3StrICmp(zLeft,"integrity_check")==0)
						{
							int i,j,addr,mxErr;
							const VdbeOpList endCode[]={{OP_MemLoad,0,0,0},{OP_Integer,0,0,0},{OP_Ne,0,0,0},{OP_String8,0,0,"ok"},{OP_Callback,1,0,0},};
							if(WN_SQL3ReadSchema(pParse))goto pragma_out;
							WN_SQL3VdbeSetNumCols(v,1);
							WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"integrity_check",P3_STATIC);
							mxErr=WN_SQL_INTEGRITY_CHECK_ERROR_MAX;
							if(zRight)
							{
								mxErr=atoi(zRight);
								if(mxErr<=0)mxErr=WN_SQL_INTEGRITY_CHECK_ERROR_MAX;
							}
							WN_SQL3VdbeAddOp(v,OP_MemInt,mxErr,0);
							for(i=0;i<db->nDb;i++)
							{
								HashElem *x;
								Hash *pTbls;
								int cnt=0;
								if(OMIT_TEMPDB && i==1)continue;
								WN_SQL3CodeVerifySchema(pParse,i);
								addr=WN_SQL3VdbeAddOp(v,OP_IfMemPos,0,0);
								WN_SQL3VdbeAddOp(v,OP_Halt,0,0);
								WN_SQL3VdbeJumpHere(v,addr);
								pTbls=&db->aDb[i].pSchema->tblHash;
								for(x=WN_SQLHashFirst(pTbls);x;x=WN_SQLHashNext(x))
								{
									Table *pTab=WN_SQLHashData(x);
									Index *pIdx;
									WN_SQL3VdbeAddOp(v,OP_Integer,pTab->tnum,0);
									cnt++;
									for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)
									{
										WN_SQL3VdbeAddOp(v,OP_Integer,pIdx->tnum,0);
										cnt++;
									}
								}
								if(cnt==0)continue;
								WN_SQL3VdbeAddOp(v,OP_IntegrityCk,0,i);
								addr=WN_SQL3VdbeAddOp(v,OP_IsNull,-1,0);
								WN_SQL3VdbeOp3(v,OP_String8,0,0,WN_SQL3MPrintf("*** in database %s ***\n",db->aDb[i].zName),P3_DYNAMIC);
								WN_SQL3VdbeAddOp(v,OP_Pull,1,0);
								WN_SQL3VdbeAddOp(v,OP_Concat,0,0);
								WN_SQL3VdbeAddOp(v,OP_Callback,1,0);
								WN_SQL3VdbeJumpHere(v,addr);
								for(x=WN_SQLHashFirst(pTbls);x;x=WN_SQLHashNext(x))
								{
									Table *pTab=WN_SQLHashData(x);
									Index *pIdx;
									int loopTop;
									if(pTab->pIndex==0)continue;
									addr=WN_SQL3VdbeAddOp(v,OP_IfMemPos,0,0);
									WN_SQL3VdbeAddOp(v,OP_Halt,0,0);
									WN_SQL3VdbeJumpHere(v,addr);
									WN_SQL3OpenTableAndIndices(pParse,pTab,1,OP_OpenRead);
									WN_SQL3VdbeAddOp(v,OP_MemInt,0,1);
									loopTop=WN_SQL3VdbeAddOp(v,OP_Rewind,1,0);
									WN_SQL3VdbeAddOp(v,OP_MemIncr,1,1);
									for(j=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,j++)
									{
										int jmp2;
										const VdbeOpList idxErr[]={{OP_MemIncr,-1,0,0},{OP_String8,0,0,"rowid "},{OP_Rowid,1,0,0},{OP_String8,0,0," missing from index "},{OP_String8,0,0,0},{OP_Concat,2,0,0},{OP_Callback,1,0,0},};
										WN_SQL3GenerateIndexKey(v,pIdx,1);
										jmp2=WN_SQL3VdbeAddOp(v,OP_Found,j+2,0);
										addr=WN_SQL3VdbeAddOpList(v,ArraySize(idxErr),idxErr);
										WN_SQL3VdbeChangeP3(v,addr+4,pIdx->zName,P3_STATIC);
										WN_SQL3VdbeJumpHere(v,jmp2);
									}
									WN_SQL3VdbeAddOp(v,OP_Next,1,loopTop+1);
									WN_SQL3VdbeJumpHere(v,loopTop);
									for(j=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,j++)
									{
										const VdbeOpList cntIdx[]={{OP_MemInt,0,2,0},{OP_Rewind,0,0,0},{OP_MemIncr,1,2,0},{OP_Next,0,0,0},{OP_MemLoad,1,0,0},{OP_MemLoad,2,0,0},{OP_Eq,0,0,0},{OP_MemIncr,-1,0,0},{OP_String8,0,0,"wrong # of entries in index "},{OP_String8,0,0,0},{OP_Concat,0,0,0},{OP_Callback,1,0,0},};
										if(pIdx->tnum==0)continue;
										addr=WN_SQL3VdbeAddOp(v,OP_IfMemPos,0,0);
										WN_SQL3VdbeAddOp(v,OP_Halt,0,0);
										WN_SQL3VdbeJumpHere(v,addr);
										addr=WN_SQL3VdbeAddOpList(v,ArraySize(cntIdx),cntIdx);
										WN_SQL3VdbeChangeP1(v,addr+1,j+2);
										WN_SQL3VdbeChangeP2(v,addr+1,addr+4);
										WN_SQL3VdbeChangeP1(v,addr+3,j+2);
										WN_SQL3VdbeChangeP2(v,addr+3,addr+2);
										WN_SQL3VdbeJumpHere(v,addr+6);
										WN_SQL3VdbeChangeP3(v,addr+9,pIdx->zName,P3_STATIC);
									}
								}
							}
							addr=WN_SQL3VdbeAddOpList(v,ArraySize(endCode),endCode);
							WN_SQL3VdbeChangeP1(v,addr+1,mxErr);
							WN_SQL3VdbeJumpHere(v,addr+2);
						}
						else
#endif
#ifndef WN_SQL_OMIT_UTF16
							if(WN_SQL3StrICmp(zLeft,"encoding")==0)
							{
								const struct EncName
								{	char *zName;
									u8 enc;
								}encnames[]={{"UTF-8",WN_SQL_UTF8},{"UTF8",WN_SQL_UTF8},{"UTF-16le",WN_SQL_UTF16LE},{"UTF16le",WN_SQL_UTF16LE},{"UTF-16be",WN_SQL_UTF16BE},{"UTF16be",WN_SQL_UTF16BE},{"UTF-16",0},{"UTF16",0},{0,0}
};
								const struct EncName *pEnc;
								if(!zRight)
								{
									if(WN_SQL3ReadSchema(pParse))goto pragma_out;
									WN_SQL3VdbeSetNumCols(v,1);
									WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"encoding",P3_STATIC);
									WN_SQL3VdbeAddOp(v,OP_String8,0,0);
									for(pEnc=&encnames[0];pEnc->zName;pEnc++)
										if(pEnc->enc==ENC(pParse->db))
										{
											WN_SQL3VdbeChangeP3(v,-1,pEnc->zName,P3_STATIC);
											break;
										}
									WN_SQL3VdbeAddOp(v,OP_Callback,1,0);
							}
							else
								if(!(DbHasProperty(db,0,DB_SchemaLoaded))||DbHasProperty(db,0,DB_Empty))
								{
									for(pEnc=&encnames[0];pEnc->zName;pEnc++)
										if(0==WN_SQL3StrICmp(zRight,pEnc->zName))
										{
											ENC(pParse->db)=pEnc->enc ? pEnc->enc :WN_SQL_UTF16NATIVE;
											break;
										}
									if(!pEnc->zName)WN_SQL3ErrorMsg(pParse,"unsupported encoding:%s",zRight);
								}
						}
						else
#endif
#ifndef WN_SQL_OMIT_SCHEMA_VERSION_PRAGMAS
							if(WN_SQL3StrICmp(zLeft,"schema_version")==0|| WN_SQL3StrICmp(zLeft,"user_version")==0|| WN_SQL3StrICmp(zLeft,"freelist_count")==0)
							{
								int iCookie;
								switch(zLeft[0])
								{
								case 's':
								case 'S':
									iCookie=0;
									break;
								case 'f':
								case 'F':
									iCookie=1;
									iDb=(-1*(iDb+1));
									break;
								default:
									iCookie=5;
									break;
							}
							if(zRight && iDb>=0)
							{
								const VdbeOpList setCookie[]={{OP_Transaction,0,1,0},{OP_Integer,0,0,0},{OP_SetCookie,0,0,0},};
								int addr=WN_SQL3VdbeAddOpList(v,ArraySize(setCookie),setCookie);
								WN_SQL3VdbeChangeP1(v,addr,iDb);
								WN_SQL3VdbeChangeP1(v,addr+1,atoi(zRight));
								WN_SQL3VdbeChangeP1(v,addr+2,iDb);
								WN_SQL3VdbeChangeP2(v,addr+2,iCookie);
							}
							else
							{
								const VdbeOpList readCookie[]={{OP_ReadCookie,0,0,0},{OP_Callback,1,0,0}};
								int addr=WN_SQL3VdbeAddOpList(v,ArraySize(readCookie),readCookie);
								WN_SQL3VdbeChangeP1(v,addr,iDb);
								WN_SQL3VdbeChangeP2(v,addr,iCookie);
								WN_SQL3VdbeSetNumCols(v,1);
								WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,zLeft,P3_TRANSIENT);
							}
						}
						else
#endif
#if defined(WN_SQL_DEBUG)|| defined(WN_SQL_TEST)
							if(WN_SQL3StrICmp(zLeft,"lock_status")==0)
							{
								const char *const azLockName[]={"unlocked","shared","reserved","pending","exclusive"};
								int i;
								Vdbe *v=WN_SQL3GetVdbe(pParse);
								WN_SQL3VdbeSetNumCols(v,2);
								WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"database",P3_STATIC);
								WN_SQL3VdbeSetColName(v,1,COLNAME_NAME,"status",P3_STATIC);
								for(i=0;i<db->nDb;i++)
								{
									Btree *pBt;
									Pager *pPager;
									if(db->aDb[i].zName==0)continue;
									WN_SQL3VdbeOp3(v,OP_String8,0,0,db->aDb[i].zName,P3_STATIC);
									pBt=db->aDb[i].pBt;
									if(pBt==0 ||(pPager=WN_SQL3BtreePager(pBt))==0)
										WN_SQL3VdbeOp3(v,OP_String8,0,0,"closed",P3_STATIC);
									else
									{
										int j=WN_SQL3PagerLockstate(pPager);
										WN_SQL3VdbeOp3(v,OP_String8,0,0,(j>=0 && j<=4)? azLockName[j] :"unknown",P3_STATIC);
									}
									WN_SQL3VdbeAddOp(v,OP_Callback,2,0);
								}
							}
							else
#endif
#ifdef WN_SQL_SSE
								if(WN_SQL3StrICmp(zLeft,"create_WN_SQL_statement_table")==0)
								{
									extern int WN_SQL3CreateStatementsTable(Parse*);
									WN_SQL3CreateStatementsTable(pParse);
								}
								else
#endif
#if WN_SQL_HAS_CODEC
									if(WN_SQL3StrICmp(zLeft,"key")==0)
										WN_SQL3_key(db,zRight,strlen(zRight));
									else
#endif
#if WN_SQL_HAS_CODEC || defined(WN_SQL_ENABLE_CEROD)
										if(WN_SQL3StrICmp(zLeft,"activate_extensions")==0)
										{
#if WN_SQL_HAS_CODEC
											if(WN_SQL3StrNICmp(zRight,"see-",4)==0)
											{
												extern void WN_SQL3_activate_see(const char*);
												WN_SQL3_activate_see(&zRight[4]);
											}
#endif
#ifdef WN_SQL_ENABLE_CEROD
											if(WN_SQL3StrNICmp(zRight,"cerod-",6)==0){
											extern void WN_SQL3_activate_cerod(const char*);
											WN_SQL3_activate_cerod(&zRight[6]);
										}
#endif
							}
#endif
							if(v)
							{	WN_SQL3VdbeAddOp(v,OP_Expire,1,0);
#ifndef WN_SQL_OMIT_PAGER_PRAGMAS
								if(db->autoCommit)WN_SQL3BtreeSetSafetyLevel(pDb->pBt,pDb->safety_level,(db->flags&WN_SQL_FullFSync)!=0);
#endif
							}
pragma_out:
	WN_SQL3FreeX(zLeft);
	WN_SQL3FreeX(zRight);
}
#endif
void corruptSchema(InitData *pData,const char *zExtra)
{	if(!WN_SQL3MallocFailed())WN_SQL3SetString(pData->pzErrMsg,"malformed database schema",zExtra && zExtra[0] ? "-" :(char*)0,zExtra,(char*)0);
	pData->rc=WN_SQL_CORRUPT;
}
int WN_SQL3InitCallback(void *pInit,int argc,char **argv,char **azColName)
{	InitData *pData=(InitData*)pInit;
	WN_SQL3 *db=pData->db;
	int iDb=pData->iDb;
	pData->rc=0;
	DbClearProperty(db,iDb,DB_Empty);
	if(WN_SQL3MallocFailed())
	{	corruptSchema(pData,0);
		return WN_SQL_NOMEM;
	}
	if(argv==0)return 0;
	if(argv[1]==0)
	{	corruptSchema(pData,0);
		return 1;
	}
	if(argv[2] && argv[2][0])
	{	char *zErr;
		int rc;
		db->init.iDb=iDb;
		db->init.newTnum=atoi(argv[1]);
		rc=WN_SQL3_exec(db,argv[2],0,0,&zErr);
		db->init.iDb=0;
		if(rc)
		{	pData->rc=rc;
			if(rc==WN_SQL_NOMEM)
				WN_SQL3FailedMalloc();
			else
				if(rc!=WN_SQL_INTERRUPT)corruptSchema(pData,zErr);
			WN_SQL3_free(zErr);
			return 1;
		}
	}
	else
	{
		Index *pIndex=WN_SQL3FindIndex(db,argv[0],db->aDb[iDb].zName);
		if(pIndex && pIndex->tnum==0)pIndex->tnum=atoi(argv[1]);
	}
	return 0;
}
int WN_SQL3InitOne(WN_SQL3 *db,int iDb,char **pzErrMsg)
{
	int rc;
	BtCursor *curMain;
	int size;
	Table *pTab;
	Db *pDb;
	char const *azArg[4];
	int meta[10];
	InitData initData;
	char const *zMasterSchema,*zMasterName=SCHEMA_TABLE(iDb),master_schema[]=
"CREATE TABLE WN_SQL_master(\n"
" type text,\n"
" name text,\n"
" tbl_name text,\n"
" rootpage integer,\n"
" sql text\n"
")";
#ifndef WN_SQL_OMIT_TEMPDB
	const char temp_master_schema[]="CREATE TEMP TABLE WN_SQL_temp_master(\n"
" type text,\n"
" name text,\n"
" tbl_name text,\n"
" rootpage integer,\n"
" sql text\n"
")";
#else
#define temp_master_schema 0
#endif
	if(!OMIT_TEMPDB && iDb==1)
		zMasterSchema=temp_master_schema;
	else
		zMasterSchema=master_schema;
	zMasterName=SCHEMA_TABLE(iDb);
	WN_SQL3SafetyOff(db);
	azArg[0]=zMasterName;
	azArg[1]="1";
	azArg[2]=zMasterSchema;
	azArg[3]=0;
	initData.db=db;
	initData.iDb=iDb;
	initData.pzErrMsg=pzErrMsg;
	rc=WN_SQL3InitCallback(&initData,3,(char **)azArg,0);
	if(rc)
	{	WN_SQL3SafetyOn(db);
		return initData.rc;
	}
	pTab=WN_SQL3FindTable(db,zMasterName,db->aDb[iDb].zName);
	if(pTab)pTab->readOnly=1;
	WN_SQL3SafetyOn(db);
	pDb=&db->aDb[iDb];
	if(pDb->pBt==0)
	{	if(!OMIT_TEMPDB && iDb==1)DbSetProperty(db,1,DB_SchemaLoaded);
		return 0;
	}
	rc=WN_SQL3BtreeCursor(pDb->pBt,MASTER_ROOT,0,0,0,&curMain);
	if(rc && rc!=WN_SQL_EMPTY)
	{	WN_SQL3SetString(pzErrMsg,WN_SQL3ErrStr(rc),(char*)0);
		return rc;
	}
	if(rc==0)
	{	int i;
		for(i=0;rc==0 && i<sizeof(meta)/sizeof(meta[0]);i++)
			rc=WN_SQL3BtreeGetMeta(pDb->pBt,i+1,(u32 *)&meta[i]);
		if(rc)
		{
			WN_SQL3SetString(pzErrMsg,WN_SQL3ErrStr(rc),(char*)0);
			WN_SQL3BtreeCloseCursor(curMain);
			return rc;
		}
	}
	else
		memset(meta,0,sizeof(meta));
	pDb->pSchema->schema_cookie=meta[0];
	if(meta[4])
	{	if(iDb==0)
		{	ENC(db)=(u8)meta[4];
			db->pDfltColl=WN_SQL3FindCollSeq(db,WN_SQL_UTF8,"BINARY",6,0);
		}
		else
		{	if(meta[4]!=ENC(db))
			{
				WN_SQL3BtreeCloseCursor(curMain);
				WN_SQL3SetString(pzErrMsg,"attached databases must use the same"
" text encoding as main database",(char*)0);
				return WN_SQL_ERROR;
	}	}	}	
	else
		DbSetProperty(db,iDb,DB_Empty);
	pDb->pSchema->enc=ENC(db);
	size=meta[2];
	if(size==0){size=WN_SQL_DEFAULT_CACHE_SIZE;}
	pDb->pSchema->cache_size=size;
	WN_SQL3BtreeSetCacheSize(pDb->pBt,pDb->pSchema->cache_size);
	pDb->pSchema->file_format=meta[1];
	if(pDb->pSchema->file_format==0)pDb->pSchema->file_format=1;
	if(pDb->pSchema->file_format>WN_SQL_MAX_FILE_FORMAT)
	{	WN_SQL3BtreeCloseCursor(curMain);
		WN_SQL3SetString(pzErrMsg,"unsupported file format",(char*)0);
		return WN_SQL_ERROR;
	}
	if(rc==WN_SQL_EMPTY)
		rc=0;
	else
	{	char *zSql;
		zSql=WN_SQL3MPrintf("SELECT name,rootpage,sql FROM '%q'.%s",db->aDb[iDb].zName,zMasterName);
		WN_SQL3SafetyOff(db);
		rc=WN_SQL3_exec(db,zSql,WN_SQL3InitCallback,&initData,0);
		if(rc==WN_SQL_ABORT)rc=initData.rc;
		WN_SQL3SafetyOn(db);
		WN_SQL3FreeX(zSql);
#ifndef WN_SQL_OMIT_ANALYZE
		if(rc==0)WN_SQL3AnalysisLoad(db,iDb);
#endif
		WN_SQL3BtreeCloseCursor(curMain);
	}
	if(WN_SQL3MallocFailed())
	{	rc=WN_SQL_NOMEM;
		WN_SQL3ResetInternalSchema(db,0);
	}
	if(rc==0 ||(db->flags&WN_SQL_RecoveryMode))
	{	DbSetProperty(db,iDb,DB_SchemaLoaded);
		rc=0;
	}
	return rc;
}
int WN_SQL3Init(WN_SQL3 *db,char **pzErrMsg)
{	int i,rc,called_initone=0;
	if(db->init.busy)return 0;
	rc=0;
	db->init.busy=1;
	for(i=0;rc==0 && i<db->nDb;i++)
	{	if(DbHasProperty(db,i,DB_SchemaLoaded)|| i==1)continue;
		rc=WN_SQL3InitOne(db,i,pzErrMsg);
		if(rc)WN_SQL3ResetInternalSchema(db,i);
		called_initone=1;
	}
#ifndef WN_SQL_OMIT_TEMPDB
	if(rc==0 && db->nDb>1 && !DbHasProperty(db,1,DB_SchemaLoaded))
	{	rc=WN_SQL3InitOne(db,1,pzErrMsg);
		if(rc)WN_SQL3ResetInternalSchema(db,1);
		called_initone=1;
	}
#endif
	db->init.busy=0;
	if(rc==0 && called_initone)WN_SQL3CommitInternalChanges(db);
	return rc;
}
int WN_SQL3ReadSchema(Parse *pParse)
{	int rc=0;
	WN_SQL3 *db=pParse->db;
	if(!db->init.busy)rc=WN_SQL3Init(db,&pParse->zErrMsg);
	if(rc)
	{	pParse->rc=rc;
		pParse->nErr++;
	}
	return rc;
}
int schemaIsValid(WN_SQL3 *db)
{	int iDb,rc,cookie,allOk=1;
	BtCursor *curTemp;
	for(iDb=0;allOk && iDb<db->nDb;iDb++)
	{	Btree *pBt;
		pBt=db->aDb[iDb].pBt;
		if(pBt==0)continue;
		rc=WN_SQL3BtreeCursor(pBt,MASTER_ROOT,0,0,0,&curTemp);
		if(rc==0)
		{	rc=WN_SQL3BtreeGetMeta(pBt,1,(u32 *)&cookie);
			if(rc==0 && cookie!=db->aDb[iDb].pSchema->schema_cookie)allOk=0;
			WN_SQL3BtreeCloseCursor(curTemp);
	}	}
	return allOk;
}
int WN_SQL3SchemaToIndex(WN_SQL3 *db,Schema *pSchema)
{	int i=-1000000;
	if(pSchema)for(i=0;i<db->nDb;i++)if(db->aDb[i].pSchema==pSchema)break;
	return i;
}
int WN_SQL3Prepare(WN_SQL3 *db,const char *zSql,int nBytes,int saveSqlFlag,WN_SQL3_stmt **ppStmt,const char **pzTail)
{	Parse sParse;
	char *zErrMsg=0;
	int rc=0,i;
	*ppStmt=0;
	if(WN_SQL3SafetyOn(db))return WN_SQL_MISUSE;
	for(i=0;i<db->nDb;i++)
	{	Btree *pBt=db->aDb[i].pBt;
		if(pBt && WN_SQL3BtreeSchemaLocked(pBt))
		{	const char *zDb=db->aDb[i].zName;
			WN_SQL3Error(db,WN_SQL_LOCKED,"database schema is locked:%s",zDb);
			WN_SQL3SafetyOff(db);
			return WN_SQL_LOCKED;
	}	}
	memset(&sParse,0,sizeof(sParse));
	sParse.db=db;
	if(nBytes>=0 && zSql[nBytes]!=0)
	{	char *zSqlCopy;
		if(nBytes>WN_SQL_MAX_SQL_LENGTH)return WN_SQL_TOOBIG;
		zSqlCopy=WN_SQL3StrNDup(zSql,nBytes);
		if(zSqlCopy)
		{	WN_SQL3RunParser(&sParse,zSqlCopy,&zErrMsg);
			WN_SQL3FreeX(zSqlCopy);
		}
		sParse.zTail=&zSql[nBytes];
	}
	else
		WN_SQL3RunParser(&sParse,zSql,&zErrMsg);
	if(WN_SQL3MallocFailed())sParse.rc=WN_SQL_NOMEM;
	if(sParse.rc==WN_SQL_DONE)sParse.rc=0;
	if(sParse.checkSchema && !schemaIsValid(db))sParse.rc=WN_SQL_SCHEMA;
	if(sParse.rc==WN_SQL_SCHEMA)WN_SQL3ResetInternalSchema(db,0);
	if(WN_SQL3MallocFailed())sParse.rc=WN_SQL_NOMEM;
	if(pzTail)*pzTail=sParse.zTail;
	rc=sParse.rc;
#ifndef WN_SQL_OMIT_EXPLAIN
	if(rc==0 && sParse.pVdbe && sParse.explain)
	{
		if(sParse.explain==2)
		{
			WN_SQL3VdbeSetNumCols(sParse.pVdbe,3);
			WN_SQL3VdbeSetColName(sParse.pVdbe,0,COLNAME_NAME,"order",P3_STATIC);
			WN_SQL3VdbeSetColName(sParse.pVdbe,1,COLNAME_NAME,"from",P3_STATIC);
			WN_SQL3VdbeSetColName(sParse.pVdbe,2,COLNAME_NAME,"detail",P3_STATIC);
		}
		else
		{
			WN_SQL3VdbeSetNumCols(sParse.pVdbe,5);
			WN_SQL3VdbeSetColName(sParse.pVdbe,0,COLNAME_NAME,"addr",P3_STATIC);
			WN_SQL3VdbeSetColName(sParse.pVdbe,1,COLNAME_NAME,"opcode",P3_STATIC);
			WN_SQL3VdbeSetColName(sParse.pVdbe,2,COLNAME_NAME,"p1",P3_STATIC);
			WN_SQL3VdbeSetColName(sParse.pVdbe,3,COLNAME_NAME,"p2",P3_STATIC);
			WN_SQL3VdbeSetColName(sParse.pVdbe,4,COLNAME_NAME,"p3",P3_STATIC);
		}
	}
#endif
	if(WN_SQL3SafetyOff(db))rc=WN_SQL_MISUSE;
	if(saveSqlFlag)WN_SQL3VdbeSetSql(sParse.pVdbe,zSql,sParse.zTail-zSql);
	if(rc!=0 || WN_SQL3MallocFailed())
		WN_SQL3_finalize((WN_SQL3_stmt*)sParse.pVdbe);
	else
		*ppStmt=(WN_SQL3_stmt*)sParse.pVdbe;
	if(zErrMsg)
	{
		WN_SQL3Error(db,rc,"%s",zErrMsg);
		WN_SQL3FreeX(zErrMsg);
	}
	else
		WN_SQL3Error(db,rc,0);
	rc=WN_SQL3ApiExit(db,rc);
	WN_SQL3ReleaseThreadData();
	return rc;
}
int WN_SQL3Reprepare(Vdbe *p)
{
	const char *zSql=WN_SQL3VdbeGetSql(p);
	if(zSql==0)return 0;
	int rc;
	WN_SQL3_stmt *pNew;
	WN_SQL3 *db=WN_SQL3VdbeDb(p);
	if(rc=WN_SQL3Prepare(db,zSql,-1,0,&pNew,0))return 0;
	WN_SQL3VdbeSwap((Vdbe*)pNew,p);
	WN_SQL3_transfer_bindings(pNew,(WN_SQL3_stmt*)p);
	WN_SQL3VdbeResetStepResult((Vdbe*)pNew);
	WN_SQL3VdbeFinalize((Vdbe*)pNew);
	return 1;
}
int WN_SQL3_prepare(WN_SQL3 *db,const char *zSql,int nBytes,WN_SQL3_stmt **ppStmt,const char **pzTail)
{
	return WN_SQL3Prepare(db,zSql,nBytes,0,ppStmt,pzTail);
}
int WN_SQL3_prepare_v2(WN_SQL3 *db,const char *zSql,int nBytes,WN_SQL3_stmt **ppStmt,const char **pzTail)
{	return WN_SQL3Prepare(db,zSql,nBytes,1,ppStmt,pzTail);
}
#ifndef WN_SQL_OMIT_UTF16
int WN_SQL3Prepare16(WN_SQL3 *db,const void *zSql,int nBytes,int saveSqlFlag,WN_SQL3_stmt **ppStmt,const void **pzTail)
{
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
	char *zSql8=WN_SQL3Utf16to8(zSql,nBytes);
	int rc=0;
	if(zSql8)rc=WN_SQL3Prepare(db,zSql8,-1,saveSqlFlag,ppStmt,&zTail8);
	const char *zTail8=0;
	if(zTail8 && pzTail)
	{
		int chars_parsed=WN_SQL3Utf8CharLen(zSql8,zTail8-zSql8);
		*pzTail=(u8 *)zSql+WN_SQL3Utf16ByteLen(zSql,chars_parsed);
	}
	WN_SQL3FreeX(zSql8);
	return WN_SQL3ApiExit(db,rc);
}
int WN_SQL3_prepare16(WN_SQL3 *db,const void *zSql,int nBytes,WN_SQL3_stmt **ppStmt,const void **pzTail)
{
	return WN_SQL3Prepare16(db,zSql,nBytes,0,ppStmt,pzTail);
}
int WN_SQL3_prepare16_v2(WN_SQL3 *db,const void *zSql,int nBytes,WN_SQL3_stmt **ppStmt,const void **pzTail)
{
	return WN_SQL3Prepare16(db,zSql,nBytes,1,ppStmt,pzTail);
}
#endif
void clearSelect(Select *p)
{
	WN_SQL3ExprListDelete(p->pEList);
	WN_SQL3SrcListDelete(p->pSrc);
	WN_SQL3ExprDelete(p->pWhere);
	WN_SQL3ExprListDelete(p->pGroupBy);
	WN_SQL3ExprDelete(p->pHaving);
	WN_SQL3ExprListDelete(p->pOrderBy);
	WN_SQL3SelectDelete(p->pPrior);
	WN_SQL3ExprDelete(p->pLimit);
	WN_SQL3ExprDelete(p->pOffset);
}
Select *WN_SQL3SelectNew(ExprList *pEList,SrcList *pSrc,Expr *pWhere,ExprList *pGroupBy,Expr *pHaving,ExprList *pOrderBy,int isDistinct,Expr *pLimit,Expr *pOffset)
{
	Select *pNew=WN_SQL3Malloc(sizeof(*pNew)),standin;
	if(pNew==0)
	{
		pNew=&standin;
		memset(pNew,0,sizeof(*pNew));
	}
	if(pEList==0)pEList=WN_SQL3ExprListAppend(0,WN_SQL3Expr(TK_ALL,0,0,0),0);
	pNew->pEList=pEList;
	pNew->pSrc=pSrc;
	pNew->pWhere=pWhere;
	pNew->pGroupBy=pGroupBy;
	pNew->pHaving=pHaving;
	pNew->pOrderBy=pOrderBy;
	pNew->isDistinct=isDistinct;
	pNew->op=TK_SELECT;
	pNew->pLimit=pLimit;
	pNew->pOffset=pOffset;
	pNew->iLimit=-1;
	pNew->iOffset=-1;
	pNew->addrOpenEphm[0]=-1;
	pNew->addrOpenEphm[1]=-1;
	pNew->addrOpenEphm[2]=-1;
	if(pNew==&standin)
	{
		clearSelect(pNew);
		pNew=0;
	}
	return pNew;
}
void WN_SQL3SelectDelete(Select *p)
{	if(p)
	{	clearSelect(p);
		WN_SQL3FreeX(p);
}	}
int WN_SQL3JoinType(Parse *pParse,Token *pA,Token *pB,Token *pC)
{
	int jointype=0;
	Token *apAll[3],*p;
	const struct
	{
		const char zKeyword[8];
		u8 nChar,code;
	}keywords[]={{"natural",7,JT_NATURAL},{"left",4,JT_LEFT|JT_OUTER},{"right",5,JT_RIGHT|JT_OUTER},{"full",4,JT_LEFT|JT_RIGHT|JT_OUTER},{"outer",5,JT_OUTER},{"inner",5,JT_INNER},{"cross",5,JT_INNER|JT_CROSS}};
	int i,j;
	apAll[0]=pA;
	apAll[1]=pB;
	apAll[2]=pC;
	for(i=0;i<3 && apAll[i];i++)
	{
		p=apAll[i];
		for(j=0;j<sizeof(keywords)/sizeof(keywords[0]);j++)
		{
			if(p->n==keywords[j].nChar && WN_SQL3StrNICmp((char*)p->z,keywords[j].zKeyword,p->n)==0)
			{
				jointype |=keywords[j].code;
				break;
			}
		}
		if(j>=sizeof(keywords)/sizeof(keywords[0]))
		{
			jointype |=JT_ERROR;
			break;
		}
	}
	if((jointype &(JT_INNER|JT_OUTER))==(JT_INNER|JT_OUTER)||(jointype & JT_ERROR))
	{
		const char *zSp1=" ",*zSp2=" ";
		if(pB==0)zSp1++;
		if(pC==0)zSp2++;
		WN_SQL3ErrorMsg(pParse,"unknown or unsupported join type:"
"%T%s%T%s%T",pA,zSp1,pB,zSp2,pC);
		jointype=JT_INNER;
	}
	else
		if(jointype & JT_RIGHT)
		{
			WN_SQL3ErrorMsg(pParse,"RIGHT and FULL OUTER JOINs are not currently supported");
			jointype=JT_INNER;
		}
		return jointype;
}
int columnIndex(Table *pTab,const char *zCol)
{
	int i;
	for(i=0;i<pTab->nCol;i++)
		if(WN_SQL3StrICmp(pTab->aCol[i].zName,zCol)==0)return i;
	return-1;
}
void setToken(Token *p,const char *z)
{
	p->z=(u8*)z;
	p->n=z ? strlen(z):0;
	p->dyn=0;
}
void setQuotedToken(Token *p,const char *z)
{
	p->z=(u8 *)WN_SQL3MPrintf("\"%w\"",z);
	p->dyn=1;
	if(p->z)p->n=strlen((char *)p->z);
}
Expr *WN_SQL3CreateIdExpr(const char *zName)
{
	Token dummy;
	setToken(&dummy,zName);
	return WN_SQL3Expr(TK_ID,0,0,&dummy);
}
void addWhereTerm(const char *zCol,const Table *pTab1,const char *zAlias1,const Table *pTab2,const char *zAlias2,int iRightJoinTable,Expr **ppExpr )
{
	if(zAlias1==0)zAlias1=pTab1->zName;
	if(zAlias2==0)zAlias2=pTab2->zName;
	Expr *pE1a=WN_SQL3CreateIdExpr(zCol),*pE1b=WN_SQL3CreateIdExpr(zAlias1),
		*pE1c=WN_SQL3ExprOrFree(TK_DOT,pE1b,pE1a,0),*pE2a=WN_SQL3CreateIdExpr(zCol),*pE2b=WN_SQL3CreateIdExpr(zAlias2),*pE2c=WN_SQL3ExprOrFree(TK_DOT,pE2b,pE2a,0),*pE=WN_SQL3ExprOrFree(TK_EQ,pE1c,pE2c,0);
	if(pE)
	{
		ExprSetProperty(pE,EP_FromJoin);
		pE->iRightJoinTable=iRightJoinTable;
	}
	pE=WN_SQL3ExprAnd(*ppExpr,pE);
	if(pE)*ppExpr=pE;
}
void setJoinExpr(Expr *p,int iTable)
{
	while(p)
	{
		ExprSetProperty(p,EP_FromJoin);
		p->iRightJoinTable=iTable;
		setJoinExpr(p->pLeft,iTable);
		p=p->pRight;
	}
}
int WN_SQLProcessJoin(Parse *pParse,Select *p)
{
	SrcList *pSrc=p->pSrc;
	int i,j;
	struct SrcList_item *pLeft=&pSrc->a[0],*pRight=&pLeft[1];
	for(i=0;i<pSrc->nSrc-1;i++,pRight++,pLeft++)
	{
		Table *pLeftTab=pLeft->pTab;
		Table *pRightTab=pRight->pTab;
		if(pLeftTab==0 || pRightTab==0)continue;
		if(pRight->jointype & JT_NATURAL)
		{
			if(pRight->pOn || pRight->pUsing)
			{
				WN_SQL3ErrorMsg(pParse,"a NATURAL join may not have "
"an ON or USING clause",0);
				return 1;
			}
			for(j=0;j<pLeftTab->nCol;j++)
			{
				char *zName=pLeftTab->aCol[j].zName;
				if(columnIndex(pRightTab,zName)>=0)addWhereTerm(zName,pLeftTab,pLeft->zAlias,pRightTab,pRight->zAlias,pRight->iCursor,&p->pWhere);
			}
		}
		if(pRight->pOn && pRight->pUsing)
		{
			WN_SQL3ErrorMsg(pParse,"cannot have both ON and USING "
"clauses in the same join");
			return 1;
		}
		if(pRight->pOn)
		{
			setJoinExpr(pRight->pOn,pRight->iCursor);
			p->pWhere=WN_SQL3ExprAnd(p->pWhere,pRight->pOn);
			pRight->pOn=0;
		}
		if(pRight->pUsing)
		{
			IdList *pList=pRight->pUsing;
			for(j=0;j<pList->nId;j++)
			{
				char *zName=pList->a[j].zName;
				if(columnIndex(pLeftTab,zName)<0 || columnIndex(pRightTab,zName)<0)
				{
					WN_SQL3ErrorMsg(pParse,"cannot join using column %s-column "
"not present in both tables",zName);
					return 1;
				}
				addWhereTerm(zName,pLeftTab,pLeft->zAlias,pRightTab,pRight->zAlias,pRight->iCursor,&p->pWhere);
			}
		}
	}
	return 0;
}
void pushOntoSorter(Parse *pParse,ExprList *pOrderBy,Select *pSelect)
{
	Vdbe *v=pParse->pVdbe;
	WN_SQL3ExprCodeExprList(pParse,pOrderBy);
	WN_SQL3VdbeAddOp(v,OP_Sequence,pOrderBy->iECursor,0);
	WN_SQL3VdbeAddOp(v,OP_Pull,pOrderBy->nExpr+1,0);
	WN_SQL3VdbeAddOp(v,OP_MakeRecord,pOrderBy->nExpr+2,0);
	WN_SQL3VdbeAddOp(v,OP_IdxInsert,pOrderBy->iECursor,0);
	if(pSelect->iLimit>=0)
	{
		int addr1=WN_SQL3VdbeAddOp(v,OP_IfMemZero,pSelect->iLimit+1,0),addr2=WN_SQL3VdbeAddOp(v,OP_Goto,0,0);
		WN_SQL3VdbeAddOp(v,OP_MemIncr,-1,pSelect->iLimit+1);
		WN_SQL3VdbeJumpHere(v,addr1);
		WN_SQL3VdbeAddOp(v,OP_Last,pOrderBy->iECursor,0);
		WN_SQL3VdbeAddOp(v,OP_Delete,pOrderBy->iECursor,0);
		WN_SQL3VdbeJumpHere(v,addr2);
		pSelect->iLimit=-1;
	}
}
void codeOffset(Vdbe *v,Select *p,int iContinue,int nPop)
{
	if(p->iOffset>=0 && iContinue)
	{
		int addr;
		WN_SQL3VdbeAddOp(v,OP_MemIncr,-1,p->iOffset);
		addr=WN_SQL3VdbeAddOp(v,OP_IfMemNeg,p->iOffset,0);
		if(nPop>0)WN_SQL3VdbeAddOp(v,OP_Pop,nPop,0);
		WN_SQL3VdbeAddOp(v,OP_Goto,0,iContinue);
		VdbeComment((v,"# skip OFFSET records"));
		WN_SQL3VdbeJumpHere(v,addr);
	}
}
void codeDistinct(Vdbe *v,int iTab,int addrRepeat,int N)
{
	WN_SQL3VdbeAddOp(v,OP_MakeRecord,-N,0);
	WN_SQL3VdbeAddOp(v,OP_Distinct,iTab,WN_SQL3VdbeCurrentAddr(v)+3);
	WN_SQL3VdbeAddOp(v,OP_Pop,N+1,0);
	WN_SQL3VdbeAddOp(v,OP_Goto,0,addrRepeat);
	VdbeComment((v,"# skip indistinct records"));
	WN_SQL3VdbeAddOp(v,OP_IdxInsert,iTab,0);
}
int checkForMultiColumnSelectError(Parse *pParse,int eDest,int nExpr)
{
	if(nExpr>1 &&(eDest==SRT_Mem || eDest==SRT_Set))
	{
		WN_SQL3ErrorMsg(pParse,"only a single result allowed for "
"a SELECT that is part of an expression");
		return 1;
	}
	else
		return 0;
}
int selectInnerLoop(Parse *pParse,Select *p,ExprList *pEList,int srcTab,int nColumn,ExprList *pOrderBy,int distinct,int eDest,int iParm,int iContinue,int iBreak,char *aff)
{
	Vdbe *v=pParse->pVdbe;
	if(v==0)return 0;
	int i,hasDistinct=distinct>=0 && pEList->nExpr>0;
	if(pOrderBy==0 && !hasDistinct)codeOffset(v,p,iContinue,0);
	if(nColumn>0)
		for(i=0;i<nColumn;i++) WN_SQL3VdbeAddOp(v,OP_Column,srcTab,i);
	else
	{
		nColumn=pEList->nExpr;
		WN_SQL3ExprCodeExprList(pParse,pEList);
	}
	if(hasDistinct)
	{
		codeDistinct(v,distinct,iContinue,nColumn);
		if(pOrderBy==0)codeOffset(v,p,iContinue,nColumn);
	}
	if(checkForMultiColumnSelectError(pParse,eDest,pEList->nExpr))return 0;
	switch(eDest)
	{
#ifndef WN_SQL_OMIT_COMPOUND_SELECT
	case SRT_Union:
		WN_SQL3VdbeAddOp(v,OP_MakeRecord,nColumn,0);
		if(aff)WN_SQL3VdbeChangeP3(v,-1,aff,P3_STATIC);
		WN_SQL3VdbeAddOp(v,OP_IdxInsert,iParm,0);
		break;
	case SRT_Except:
		int addr=WN_SQL3VdbeAddOp(v,OP_MakeRecord,nColumn,0);
		WN_SQL3VdbeChangeP3(v,-1,aff,P3_STATIC);
		WN_SQL3VdbeAddOp(v,OP_NotFound,iParm,addr+3);
		WN_SQL3VdbeAddOp(v,OP_Delete,iParm,0);
		break;
#endif
	case SRT_Table:
	case SRT_EphemTab:
		WN_SQL3VdbeAddOp(v,OP_MakeRecord,nColumn,0);
		if(pOrderBy)
			pushOntoSorter(pParse,pOrderBy,p);
		else
		{
			WN_SQL3VdbeAddOp(v,OP_NewRowid,iParm,0);
			WN_SQL3VdbeAddOp(v,OP_Pull,1,0);
			WN_SQL3VdbeAddOp(v,OP_Insert,iParm,OPFLAG_APPEND);
		}
		break;
#ifndef WN_SQL_OMIT_SUBQUERY
	case SRT_Set:
		int addr1=WN_SQL3VdbeCurrentAddr(v),addr2;
		WN_SQL3VdbeAddOp(v,OP_NotNull,-1,addr1+3);
		WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
		addr2=WN_SQL3VdbeAddOp(v,OP_Goto,0,0);
		p->affinity=WN_SQL3CompareAffinity(pEList->a[0].pExpr,(iParm>>16)&0xff);
		if(pOrderBy)
			pushOntoSorter(pParse,pOrderBy,p);
		else
		{
			WN_SQL3VdbeOp3(v,OP_MakeRecord,1,0,&p->affinity,1);
			WN_SQL3VdbeAddOp(v,OP_IdxInsert,(iParm&0x0000FFFF),0);
		}
		WN_SQL3VdbeJumpHere(v,addr2);
		break;
	case SRT_Exists:
		WN_SQL3VdbeAddOp(v,OP_MemInt,1,iParm);
		WN_SQL3VdbeAddOp(v,OP_Pop,nColumn,0);
		break;
	case SRT_Mem:
		if(pOrderBy)
			pushOntoSorter(pParse,pOrderBy,p);
		else
			WN_SQL3VdbeAddOp(v,OP_MemStore,iParm,1);
		break;
#endif
	case SRT_Subroutine:
	case SRT_Callback:
		if(pOrderBy)
		{
			WN_SQL3VdbeAddOp(v,OP_MakeRecord,nColumn,0);
			pushOntoSorter(pParse,pOrderBy,p);
		}
		else
			if(eDest==SRT_Subroutine)
				WN_SQL3VdbeAddOp(v,OP_Gosub,0,iParm);
			else
				WN_SQL3VdbeAddOp(v,OP_Callback,nColumn,0);
			break;
#if !defined(WN_SQL_OMIT_TRIGGER)
	default:
		WN_SQL3VdbeAddOp(v,OP_Pop,nColumn,0);
#endif
	}
	if(p->iLimit>=0 && pOrderBy==0)
	{
		WN_SQL3VdbeAddOp(v,OP_MemIncr,-1,p->iLimit);
		WN_SQL3VdbeAddOp(v,OP_IfMemZero,p->iLimit,iBreak);
	}
	return 0;
}
KeyInfo *keyInfoFromExprList(Parse *pParse,ExprList *pList)
{
	WN_SQL3 *db=pParse->db;
	int nExpr=pList->nExpr,i;
	struct ExprList_item *pItem;
	KeyInfo *pInfo=WN_SQL3Malloc(sizeof(*pInfo)+nExpr*(sizeof(CollSeq*)+1));
	if(pInfo)
	{
		pInfo->aSortOrder=(u8*)&pInfo->aColl[nExpr];
		pInfo->nField=nExpr;
		pInfo->enc=ENC(db);
		for(i=0,pItem=pList->a;i<nExpr;i++,pItem++)
		{
			CollSeq *pColl=WN_SQL3ExprCollSeq(pParse,pItem->pExpr);
			if(!pColl)pColl=db->pDfltColl;
			pInfo->aColl[i]=pColl;
			pInfo->aSortOrder[i]=pItem->sortOrder;
		}
	}
	return pInfo;
}
void generateSortTail(Parse *pParse,Select *p,Vdbe *v,int nColumn,int eDest,int iParm)
{
	ExprList *pOrderBy=p->pOrderBy;
	int brk=WN_SQL3VdbeMakeLabel(v),cont=WN_SQL3VdbeMakeLabel(v),addr,
		pseudoTab=0,iTab=pOrderBy->iECursor;
	if(eDest==SRT_Callback || eDest==SRT_Subroutine)
	{
		pseudoTab=pParse->nTab++;
		WN_SQL3VdbeAddOp(v,OP_OpenPseudo,pseudoTab,0);
		WN_SQL3VdbeAddOp(v,OP_SetNumColumns,pseudoTab,nColumn);
	}
	addr=1+WN_SQL3VdbeAddOp(v,OP_Sort,iTab,brk);
	codeOffset(v,p,cont,0);
	if(eDest==SRT_Callback || eDest==SRT_Subroutine)WN_SQL3VdbeAddOp(v,OP_Integer,1,0);
	WN_SQL3VdbeAddOp(v,OP_Column,iTab,pOrderBy->nExpr+1);
	switch(eDest)
	{
	case SRT_Table:
	case SRT_EphemTab:
		WN_SQL3VdbeAddOp(v,OP_NewRowid,iParm,0);
		WN_SQL3VdbeAddOp(v,OP_Pull,1,0);
		WN_SQL3VdbeAddOp(v,OP_Insert,iParm,OPFLAG_APPEND);
		break;
#ifndef WN_SQL_OMIT_SUBQUERY
	case SRT_Set:
		WN_SQL3VdbeAddOp(v,OP_NotNull,-1,WN_SQL3VdbeCurrentAddr(v)+3);
		WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
		WN_SQL3VdbeAddOp(v,OP_Goto,0,WN_SQL3VdbeCurrentAddr(v)+3);
		WN_SQL3VdbeOp3(v,OP_MakeRecord,1,0,&p->affinity,1);
		WN_SQL3VdbeAddOp(v,OP_IdxInsert,(iParm&0x0000FFFF),0);
		break;
	case SRT_Mem:
		WN_SQL3VdbeAddOp(v,OP_MemStore,iParm,1);
		break;
#endif
	case SRT_Callback:
	case SRT_Subroutine:
		int i;
		WN_SQL3VdbeAddOp(v,OP_Insert,pseudoTab,0);
		for(i=0;i<nColumn;i++)WN_SQL3VdbeAddOp(v,OP_Column,pseudoTab,i);
		if(eDest==SRT_Callback)
			WN_SQL3VdbeAddOp(v,OP_Callback,nColumn,0);
		else
			WN_SQL3VdbeAddOp(v,OP_Gosub,0,iParm);
	}
	if(p->iLimit>=0)
	{
		WN_SQL3VdbeAddOp(v,OP_MemIncr,-1,p->iLimit);
		WN_SQL3VdbeAddOp(v,OP_IfMemZero,p->iLimit,brk);
	}
	WN_SQL3VdbeResolveLabel(v,cont);
	WN_SQL3VdbeAddOp(v,OP_Next,iTab,addr);
	WN_SQL3VdbeResolveLabel(v,brk);
	if(eDest==SRT_Callback || eDest==SRT_Subroutine)WN_SQL3VdbeAddOp(v,OP_Close,pseudoTab,0);
}
const char *columnType(NameContext *pNC,Expr *pExpr,const char **pzOriginDb,const char **pzOriginTab,const char **pzOriginCol)
{
	char const *zType=0,*zOriginDb=0,*zOriginTab=0,*zOriginCol=0;
	int j;
	if(pExpr==0 || pNC->pSrcList==0)return 0;
	switch(pExpr->op)
	{
	case TK_AGG_COLUMN:
	case TK_COLUMN:
		Table *pTab=0;
		Select *pS=0;
		int iCol=pExpr->iColumn;
		while(pNC && !pTab)
		{
			SrcList *pTabList=pNC->pSrcList;
			for(j=0;j<pTabList->nSrc && pTabList->a[j].iCursor!=pExpr->iTable;j++);
			if(j<pTabList->nSrc)
			{
				pTab=pTabList->a[j].pTab;
				pS=pTabList->a[j].pSelect;
			}
			else
				pNC=pNC->pNext;
		}
		if(pTab==0)
		{
			zType="TEXT";
			break;
		}
		if(pS)
		{
			if(iCol>=0 && iCol<pS->pEList->nExpr)
			{
				NameContext sNC;
				Expr *p=pS->pEList->a[iCol].pExpr;
				sNC.pSrcList=pS->pSrc;
				sNC.pNext=0;
				sNC.pParse=pNC->pParse;
				zType=columnType(&sNC,p,&zOriginDb,&zOriginTab,&zOriginCol);
			}
		}
		else
			if(pTab->pSchema)
			{
				if(iCol<0)iCol=pTab->iPKey;
				if(iCol<0)
				{
					zType="INTEGER";
					zOriginCol="rowid";
				}
				else
				{
					zType=pTab->aCol[iCol].zType;
					zOriginCol=pTab->aCol[iCol].zName;
				}
				zOriginTab=pTab->zName;
				if(pNC->pParse)
				{
					int iDb=WN_SQL3SchemaToIndex(pNC->pParse->db,pTab->pSchema);
					zOriginDb=pNC->pParse->db->aDb[iDb].zName;
				}
			}
			break;
#ifndef WN_SQL_OMIT_SUBQUERY
	case TK_SELECT:
		NameContext sNC;
		Select *pS=pExpr->pSelect;
		Expr *p=pS->pEList->a[0].pExpr;
		sNC.pSrcList=pS->pSrc;
		sNC.pNext=pNC;
		sNC.pParse=pNC->pParse;
		zType=columnType(&sNC,p,&zOriginDb,&zOriginTab,&zOriginCol);
#endif
	}
	if(pzOriginDb)
	{
		*pzOriginDb=zOriginDb;
		*pzOriginTab=zOriginTab;
		*pzOriginCol=zOriginCol;
	}
	return zType;
}
void generateColumnTypes(Parse *pParse,SrcList *pTabList,ExprList *pEList)
{
	Vdbe *v=pParse->pVdbe;
	int i;
	NameContext sNC;
	sNC.pSrcList=pTabList;
	sNC.pParse=pParse;
	for(i=0;i<pEList->nExpr;i++)
	{
		Expr *p=pEList->a[i].pExpr;
		const char *zOrigDb=0,*zOrigTab=0,*zOrigCol=0,*zType=columnType(&sNC,p,&zOrigDb,&zOrigTab,&zOrigCol);
		WN_SQL3VdbeSetColName(v,i,COLNAME_DECLTYPE,zType,P3_TRANSIENT);
		WN_SQL3VdbeSetColName(v,i,COLNAME_DATABASE,zOrigDb,P3_TRANSIENT);
		WN_SQL3VdbeSetColName(v,i,COLNAME_TABLE,zOrigTab,P3_TRANSIENT);
		WN_SQL3VdbeSetColName(v,i,COLNAME_COLUMN,zOrigCol,P3_TRANSIENT);
	}
}
void generateColumnNames(Parse *pParse,SrcList *pTabList,ExprList *pEList)
{
	Vdbe *v=pParse->pVdbe;
	int i,j;
	WN_SQL3 *db=pParse->db;
	int fullNames,shortNames;
#ifndef WN_SQL_OMIT_EXPLAIN
	if(pParse->explain)return;
#endif
	if(pParse->colNamesSet || v==0 || WN_SQL3MallocFailed())return;
	pParse->colNamesSet=1;
	fullNames=(db->flags & WN_SQL_FullColNames)!=0;
	shortNames=(db->flags & WN_SQL_ShortColNames)!=0;
	WN_SQL3VdbeSetNumCols(v,pEList->nExpr);
	for(i=0;i<pEList->nExpr;i++)
	{
		Expr *p=pEList->a[i].pExpr;
		if(p==0)continue;
		if(pEList->a[i].zName)
		{
			char *zName=pEList->a[i].zName;
			WN_SQL3VdbeSetColName(v,i,COLNAME_NAME,zName,strlen(zName));
			continue;
		}
		if(p->op==TK_COLUMN && pTabList)
		{
			char *zCol;
			int iCol=p->iColumn;
			for(j=0;j<pTabList->nSrc && pTabList->a[j].iCursor!=p->iTable;j++);
			Table *pTab=pTabList->a[j].pTab;
			if(iCol<0)iCol=pTab->iPKey;
			if(iCol<0)
				zCol="rowid";
			else
				zCol=pTab->aCol[iCol].zName;
			if(!shortNames && !fullNames && p->span.z && p->span.z[0])
				WN_SQL3VdbeSetColName(v,i,COLNAME_NAME,(char*)p->span.z,p->span.n);
			else
				if(fullNames ||(!shortNames && pTabList->nSrc>1))
				{
					char *zName=0,*zTab=pTabList->a[j].zAlias;
					if(fullNames || zTab==0)zTab=pTab->zName;
					WN_SQL3SetString(&zName,zTab,".",zCol,(char*)0);
					WN_SQL3VdbeSetColName(v,i,COLNAME_NAME,zName,P3_DYNAMIC);
				}
				else
					WN_SQL3VdbeSetColName(v,i,COLNAME_NAME,zCol,strlen(zCol));
		}
		else
			if(p->span.z && p->span.z[0])
				WN_SQL3VdbeSetColName(v,i,COLNAME_NAME,(char*)p->span.z,p->span.n);
			else
			{
				char zName[30];
				WN_SQL3_snprintf(sizeof(zName),zName,"column%d",i+1);
WN_SQL3VdbeSetColName(v,i,COLNAME_NAME,zName,0);
			}
	}
	generateColumnTypes(pParse,pTabList,pEList);
}
#ifndef WN_SQL_OMIT_COMPOUND_SELECT
const char *selectOpName(int id)
{
	char *z;
	switch(id)
	{
	case TK_ALL:
		z="UNION ALL";
		break;
	case TK_INTERSECT:
		z="INTERSECT";
		break;
	case TK_EXCEPT:
		z="EXCEPT";
		break;
	default:
		z="UNION";
	}
	return z;
}
#endif
Table *WN_SQL3ResultSetOfSelect(Parse *pParse,char *zTabName,Select *pSelect)
{
	int i,j;
	Column *aCol,*pCol;
	while(pSelect->pPrior)pSelect=pSelect->pPrior;
	if(prepSelectStmt(pParse,pSelect))return 0;
	if(WN_SQL3SelectResolve(pParse,pSelect,0))return 0;
	Table *pTab=WN_SQL3Malloc(sizeof(Table));
	if(pTab==0)return 0;
	pTab->nRef=1;
	pTab->zName=zTabName ? WN_SQLStrDup(zTabName):0;
	ExprList *pEList=pSelect->pEList;
	pTab->nCol=pEList->nExpr;
	pTab->aCol=aCol=WN_SQL3Malloc(sizeof(pTab->aCol[0])*pTab->nCol);
	for(i=0,pCol=aCol;i<pTab->nCol;i++,pCol++)
	{
		Expr *p,*pR;
		char *zType,*zName;
		int nName;
		CollSeq *pColl;
		int cnt;
		NameContext sNC;
		p=pEList->a[i].pExpr;
		if((zName=pEList->a[i].zName))
			zName=WN_SQLStrDup(zName);
		else
			if(p->op==TK_DOT &&(pR=p->pRight)&& pR->token.z && pR->token.z[0])zName=WN_SQL3MPrintf("%T",&pR->token);
			else
				if(p->span.z && p->span.z[0])
					zName=WN_SQL3MPrintf("%T",&p->span);
				else
					zName=WN_SQL3MPrintf("column%d",i+1);
		WN_SQL3Dequote(zName);
		if(WN_SQL3MallocFailed())
		{
			WN_SQL3FreeX(zName);
			WN_SQL3DeleteTable(pTab);
			return 0;
		}
		nName=strlen(zName);
		for(j=cnt=0;j<i;j++)
		{
			if(WN_SQL3StrICmp(aCol[j].zName,zName)==0)
			{
				zName[nName]=0;
				zName=WN_SQL3MPrintf("%z:%d",zName,++cnt);
				j=-1;
				if(zName==0)break;
			}
		}
		pCol->zName=zName;
		memset(&sNC,0,sizeof(sNC));
		sNC.pSrcList=pSelect->pSrc;
		zType=WN_SQLStrDup(columnType(&sNC,p,0,0,0));
		pCol->zType=zType;
		pCol->affinity=WN_SQL3ExprAffinity(p);
		pColl=WN_SQL3ExprCollSeq(pParse,p);
		if(pColl)pCol->zColl=WN_SQLStrDup(pColl->zName);
	}
	pTab->iPKey=-1;
	return pTab;
}
int prepSelectStmt(Parse *pParse,Select *p)
{
	int i,j,k,rc;
	SrcList *pTabList;
	ExprList *pEList;
	struct SrcList_item *pFrom;
	if(p==0 || p->pSrc==0 || WN_SQL3MallocFailed())return 1;
	pTabList=p->pSrc;
	pEList=p->pEList;
	WN_SQL3SrcListAssignCursors(pParse,p->pSrc);
	for(i=0,pFrom=pTabList->a;i<pTabList->nSrc;i++,pFrom++)
	{
		Table *pTab;
		if(pFrom->pTab)return 0;
		if(pFrom->zName==0)
		{
#ifndef WN_SQL_OMIT_SUBQUERY
			if(pFrom->zAlias==0)
				pFrom->zAlias=WN_SQL3MPrintf("WN_SQL_subquery_%p_",(void*)pFrom->pSelect);
			pFrom->pTab=pTab=WN_SQL3ResultSetOfSelect(pParse,pFrom->zAlias,pFrom->pSelect);
			if(pTab==0)return 1;
			pTab->isEphem=1;
#endif
		}
		else
		{
			pFrom->pTab=pTab=WN_SQL3LocateTable(pParse,pFrom->zName,pFrom->zDatabase);
			if(pTab==0)return 1;
			pTab->nRef++;
#if !defined(WN_SQL_OMIT_VIEW)|| !defined(WN_SQL_OMIT_VIRTUALTABLE)
			if(pTab->pSelect || IsVirtual(pTab))
			{
				if(WN_SQL3ViewGetColumnNames(pParse,pTab))return 1;
				if(pFrom->pSelect==0)pFrom->pSelect=WN_SQL3SelectDup(pTab->pSelect);
			}
#endif
		}
	}
	if(WN_SQLProcessJoin(pParse,p))return 1;
	for(k=0;k<pEList->nExpr;k++)
	{
		Expr *pE=pEList->a[k].pExpr;
		if(pE->op==TK_ALL)break;
		if(pE->op==TK_DOT && pE->pRight && pE->pRight->op==TK_ALL && pE->pLeft && pE->pLeft->op==TK_ID)break;
	}
	rc=0;
	if(k<pEList->nExpr)
	{
		struct ExprList_item *a=pEList->a;
		ExprList *pNew=0;
		int flags=pParse->db->flags;
		int longNames=(flags & WN_SQL_FullColNames)&& (flags & WN_SQL_ShortColNames)==0;
		for(k=0;k<pEList->nExpr;k++)
		{
			Expr *pE=a[k].pExpr;
			if(pE->op!=TK_ALL && (pE->op!=TK_DOT || pE->pRight==0 || pE->pRight->op!=TK_ALL))
			{
				pNew=WN_SQL3ExprListAppend(pNew,a[k].pExpr,0);
				if(pNew)
					pNew->a[pNew->nExpr-1].zName=a[k].zName;
				else
					rc=1;
				a[k].pExpr=0;
				a[k].zName=0;
			}
			else
			{
				int tableSeen=0;
				char *zTName;
				if(pE->op==TK_DOT && pE->pLeft)
					zTName=WN_SQL3NameFromToken(&pE->pLeft->token);
				else
					zTName=0;
				for(i=0,pFrom=pTabList->a;i<pTabList->nSrc;i++,pFrom++)
				{
					Table *pTab=pFrom->pTab;
					char *zTabName=pFrom->zAlias;
					if(zTabName==0 || zTabName[0]==0)zTabName=pTab->zName;
					if(zTName &&(zTabName==0 || zTabName[0]==0 || WN_SQL3StrICmp(zTName,zTabName)))continue;
					tableSeen=1;
					for(j=0;j<pTab->nCol;j++)
					{
						Expr *pExpr,*pRight;
						char *zName=pTab->aCol[j].zName;
						if(IsHiddenColumn(&pTab->aCol[j]))continue;
						if(i>0)
						{
							struct SrcList_item *pLeft=&pTabList->a[i-1];
							if((pLeft[1].jointype & JT_NATURAL)&& columnIndex(pLeft->pTab,zName)>=0)continue;
							if(WN_SQL3IdListIndex(pLeft[1].pUsing,zName)>=0)continue;
						}
						pRight=WN_SQL3Expr(TK_ID,0,0,0);
						if(pRight==0)break;
						setQuotedToken(&pRight->token,zName);
						if(zTabName &&(longNames || pTabList->nSrc>1))
						{
							Expr *pLeft=WN_SQL3Expr(TK_ID,0,0,0);
							pExpr=WN_SQL3Expr(TK_DOT,pLeft,pRight,0);
							if(pExpr==0)break;
							setQuotedToken(&pLeft->token,zTabName);
							setToken(&pExpr->span,WN_SQL3MPrintf("%s.%s",zTabName,zName));
							pExpr->span.dyn=1;
							pExpr->token.z=0;
							pExpr->token.n=0;
							pExpr->token.dyn=0;
						}
						else
						{
							pExpr=pRight;
							pExpr->span=pExpr->token;
							pExpr->span.dyn=0;
						}
						if(longNames)
							pNew=WN_SQL3ExprListAppend(pNew,pExpr,&pExpr->span);
						else
							pNew=WN_SQL3ExprListAppend(pNew,pExpr,&pRight->token);
					}
				}
				if(!tableSeen)
				{
					if(zTName)
						WN_SQL3ErrorMsg(pParse,"no such table:%s",zTName);
					else
						WN_SQL3ErrorMsg(pParse,"no tables specified");
					rc=1;
				}
				WN_SQL3FreeX(zTName);
			}
		}
		WN_SQL3ExprListDelete(pEList);
		p->pEList=pNew;
	}
	if(p->pEList && p->pEList->nExpr>WN_SQL_MAX_COLUMN)
	{
		WN_SQL3ErrorMsg(pParse,"too many columns in result set");
		rc=WN_SQL_ERROR;
	}
	if(WN_SQL3MallocFailed())rc=WN_SQL_NOMEM;
	return rc;
}
#ifndef WN_SQL_OMIT_COMPOUND_SELECT
int matchOrderbyToColumn(Parse *pParse,Select *pSelect,ExprList *pOrderBy,int iTable,int mustComplete)
{
	int nErr=0,i,j;
	ExprList *pEList;
	if(pSelect==0 || pOrderBy==0)return 1;
	if(mustComplete)for(i=0;i<pOrderBy->nExpr;i++)pOrderBy->a[i].done=0;
	if(prepSelectStmt(pParse,pSelect))return 1;
	if(pSelect->pPrior)
		if(matchOrderbyToColumn(pParse,pSelect->pPrior,pOrderBy,iTable,0))return 1;
	pEList=pSelect->pEList;
	for(i=0;i<pOrderBy->nExpr;i++)
	{
		struct ExprList_item *pItem;
		Expr *pE=pOrderBy->a[i].pExpr;
		int iCol=-1;
		char *zLabel;
		if(pOrderBy->a[i].done)continue;
		if(WN_SQL3ExprIsInteger(pE,&iCol))
		{
			if(iCol<=0 || iCol>pEList->nExpr)
			{
				WN_SQL3ErrorMsg(pParse,"ORDER BY position %d should be between 1 and %d",iCol,pEList->nExpr);
				nErr++;
				break;
			}
			if(!mustComplete)continue;
			iCol--;
		}
		if(iCol<0 &&(zLabel=WN_SQL3NameFromToken(&pE->token)))
		{
			for(j=0,pItem=pEList->a;j<pEList->nExpr;j++,pItem++)
			{
				char *zName;
				int isMatch;
				if(pItem->zName)
					zName=WN_SQL3StrDup(pItem->zName);
				else
					zName=WN_SQL3NameFromToken(&pItem->pExpr->token);
				isMatch=zName && WN_SQL3StrICmp(zName,zLabel)==0;
				WN_SQL3FreeX(zName);
				if(isMatch)
				{
					iCol=j;
					break;
				}
			}
			WN_SQL3FreeX(zLabel);
		}
		if(iCol>=0)
		{
			pE->op=TK_COLUMN;
			pE->iColumn=iCol;
			pE->iTable=iTable;
			pE->iAgg=-1;
			pOrderBy->a[i].done=1;
		}
		else
			if(mustComplete)
			{
				WN_SQL3ErrorMsg(pParse,"ORDER BY term number %d does not match any result column",i+1);
				nErr++;
				break;
			}
	}
	return nErr;
}
#endif
Vdbe *WN_SQL3GetVdbe(Parse *pParse)
{
	Vdbe *v=pParse->pVdbe;
	if(v==0)v=pParse->pVdbe=WN_SQL3VdbeCreate(pParse->db);
	return v;
}
void computeLimitRegisters(Parse *pParse,Select *p,int iBreak)
{
	Vdbe *v;
	int iLimit=0,iOffset,addr1,addr2;
	if(p->pLimit)
	{
		p->iLimit=iLimit=pParse->nMem;
		pParse->nMem+=2;
		v=WN_SQL3GetVdbe(pParse);
		if(v==0)return;
		WN_SQL3ExprCode(pParse,p->pLimit);
		WN_SQL3VdbeAddOp(v,OP_MustBeInt,0,0);
		WN_SQL3VdbeAddOp(v,OP_MemStore,iLimit,1);
		VdbeComment((v,"# LIMIT counter"));
		WN_SQL3VdbeAddOp(v,OP_IfMemZero,iLimit,iBreak);
		WN_SQL3VdbeAddOp(v,OP_MemLoad,iLimit,0);
	}
	if(p->pOffset)
	{
		p->iOffset=iOffset=pParse->nMem++;
		v=WN_SQL3GetVdbe(pParse);
		if(v==0)return;
		WN_SQL3ExprCode(pParse,p->pOffset);
		WN_SQL3VdbeAddOp(v,OP_MustBeInt,0,0);
		WN_SQL3VdbeAddOp(v,OP_MemStore,iOffset,p->pLimit==0);
		VdbeComment((v,"# OFFSET counter"));
		addr1=WN_SQL3VdbeAddOp(v,OP_IfMemPos,iOffset,0);
		WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
		WN_SQL3VdbeAddOp(v,OP_Integer,0,0);
		WN_SQL3VdbeJumpHere(v,addr1);
		if(p->pLimit)WN_SQL3VdbeAddOp(v,OP_Add,0,0);
	}
	if(p->pLimit)
	{
		addr1=WN_SQL3VdbeAddOp(v,OP_IfMemPos,iLimit,0);
		WN_SQL3VdbeAddOp(v,OP_Pop,1,0);
		WN_SQL3VdbeAddOp(v,OP_MemInt,-1,iLimit+1);
		addr2=WN_SQL3VdbeAddOp(v,OP_Goto,0,0);
		WN_SQL3VdbeJumpHere(v,addr1);
		WN_SQL3VdbeAddOp(v,OP_MemStore,iLimit+1,1);
		VdbeComment((v,"# LIMIT+OFFSET"));
		WN_SQL3VdbeJumpHere(v,addr2);
	}
}
void createSortingIndex(Parse *pParse,Select *p,ExprList *pOrderBy)
{
	if(pOrderBy)
	{
		pOrderBy->iECursor=pParse->nTab++;
		int addr=WN_SQL3VdbeAddOp(pParse->pVdbe,OP_OpenEphemeral,pOrderBy->iECursor,pOrderBy->nExpr+1);
		p->addrOpenEphm[2]=addr;
	}
}
#ifndef WN_SQL_OMIT_COMPOUND_SELECT
CollSeq *multiSelectCollSeq(Parse *pParse,Select *p,int iCol)
{
	CollSeq *pRet;
	if(p->pPrior)
		pRet=multiSelectCollSeq(pParse,p->pPrior,iCol);
	else
		pRet=0;
	if(pRet==0)pRet=WN_SQL3ExprCollSeq(pParse,p->pEList->a[iCol].pExpr);
	return pRet;
}
#endif
#ifndef WN_SQL_OMIT_COMPOUND_SELECT
int multiSelect(Parse *pParse,Select *p,int eDest,int iParm,char *aff)
{
	int rc=0,nCol;
	ExprList *pOrderBy;
	int aSetP2[2],nSetP2=0;
	if(p==0 || p->pPrior==0)
	{
		rc=1;
		goto multi_select_end;
	}
	Select *pPrior=p->pPrior;
	if(pPrior->pOrderBy)
	{
		WN_SQL3ErrorMsg(pParse,"ORDER BY clause should come after %s not before",selectOpName(p->op));
		rc=1;
		goto multi_select_end;
	}
	if(pPrior->pLimit)
	{
		WN_SQL3ErrorMsg(pParse,"LIMIT clause should come after %s not before",selectOpName(p->op));
		rc=1;
		goto multi_select_end;
	}
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v==0)
	{
		rc=1;
		goto multi_select_end;
	}
	if(eDest==SRT_EphemTab)
	{
		aSetP2[nSetP2++]=WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,iParm,0);
		eDest=SRT_Table;
	}
	pOrderBy=p->pOrderBy;
	switch(p->op)
	{
	case TK_ALL:
		if(pOrderBy==0)
		{
			int addr=0;
			pPrior->pLimit=p->pLimit;
			pPrior->pOffset=p->pOffset;
			rc=WN_SQL3Select(pParse,pPrior,eDest,iParm,0,0,0,aff);
			p->pLimit=0;
			p->pOffset=0;
			if(rc)goto multi_select_end;
			p->pPrior=0;
			p->iLimit=pPrior->iLimit;
			p->iOffset=pPrior->iOffset;
			if(p->iLimit>=0)
			{
				addr=WN_SQL3VdbeAddOp(v,OP_IfMemZero,p->iLimit,0);
				VdbeComment((v,"# Jump ahead if LIMIT reached"));
			}
			rc=WN_SQL3Select(pParse,p,eDest,iParm,0,0,0,aff);
			p->pPrior=pPrior;
			if(rc)goto multi_select_end;
			if(addr)WN_SQL3VdbeJumpHere(v,addr);
			break;
		}
	case TK_EXCEPT:
	case TK_UNION:
		int unionTab,op=0,priorOp;
		Expr *pLimit,*pOffset;
		int addr;
		priorOp=p->op==TK_ALL ? SRT_Table :SRT_Union;
		if(eDest==priorOp && pOrderBy==0 && !p->pLimit && !p->pOffset)
			unionTab=iParm;
		else
		{
			unionTab=pParse->nTab++;
			if(pOrderBy && matchOrderbyToColumn(pParse,p,pOrderBy,unionTab,1))
			{
				rc=1;
				goto multi_select_end;
			}
			addr=WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,unionTab,0);
			if(priorOp==SRT_Table)
				aSetP2[nSetP2++]=addr;
			else
			{
				p->addrOpenEphm[0]=addr;
				p->pRightmost->usesEphm=1;
			}
			createSortingIndex(pParse,p,pOrderBy);
		}
		rc=WN_SQL3Select(pParse,pPrior,priorOp,unionTab,0,0,0,aff);
		if(rc)goto multi_select_end;
		switch(p->op)
		{
		case TK_EXCEPT:
			op=SRT_Except;
			break;
		case TK_UNION:
			op=SRT_Union;
			break;
		case TK_ALL:
			op=SRT_Table;
			break;
		}
		p->pPrior=0;
		p->pOrderBy=0;
		p->disallowOrderBy=pOrderBy!=0;
		pLimit=p->pLimit;
		p->pLimit=0;
		pOffset=p->pOffset;
		p->pOffset=0;
		rc=WN_SQL3Select(pParse,p,op,unionTab,0,0,0,aff);
		WN_SQL3ExprListDelete(p->pOrderBy);
		p->pPrior=pPrior;
		p->pOrderBy=pOrderBy;
		WN_SQL3ExprDelete(p->pLimit);
		p->pLimit=pLimit;
		p->pOffset=pOffset;
		p->iLimit=-1;
		p->iOffset=-1;
		if(rc)goto multi_select_end;
		if(eDest!=priorOp || unionTab!=iParm)
		{
			int iCont,iBreak,iStart;
			if(eDest==SRT_Callback)
			{
				Select *pFirst=p;
				while(pFirst->pPrior)pFirst=pFirst->pPrior;
				generateColumnNames(pParse,0,pFirst->pEList);
			}
			iBreak=WN_SQL3VdbeMakeLabel(v);
			iCont=WN_SQL3VdbeMakeLabel(v);
			computeLimitRegisters(pParse,p,iBreak);
			WN_SQL3VdbeAddOp(v,OP_Rewind,unionTab,iBreak);
			iStart=WN_SQL3VdbeCurrentAddr(v);
			if(rc=selectInnerLoop(pParse,p,p->pEList,unionTab,p->pEList->nExpr,pOrderBy,-1,eDest,iParm,iCont,iBreak,0))
			{
				rc=1;
				goto multi_select_end;
			}
			WN_SQL3VdbeResolveLabel(v,iCont);
			WN_SQL3VdbeAddOp(v,OP_Next,unionTab,iStart);
			WN_SQL3VdbeResolveLabel(v,iBreak);
			WN_SQL3VdbeAddOp(v,OP_Close,unionTab,0);
		}
		break;
	case TK_INTERSECT:
		int iCont,iBreak,iStart;
		Expr *pLimit,*pOffset;
		int addr;
		int tab1=pParse->nTab++,tab2=pParse->nTab++;
		if(pOrderBy && matchOrderbyToColumn(pParse,p,pOrderBy,tab1,1))
		{
			rc=1;
			goto multi_select_end;
		}
		createSortingIndex(pParse,p,pOrderBy);
		addr=WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,tab1,0);
		p->addrOpenEphm[0]=addr;
		p->pRightmost->usesEphm=1;
		rc=WN_SQL3Select(pParse,pPrior,SRT_Union,tab1,0,0,0,aff);
		if(rc)goto multi_select_end;
		addr=WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,tab2,0);
		p->addrOpenEphm[1]=addr;
		p->pPrior=0;
		pLimit=p->pLimit;
		p->pLimit=0;
		pOffset=p->pOffset;
		p->pOffset=0;
		rc=WN_SQL3Select(pParse,p,SRT_Union,tab2,0,0,0,aff);
		p->pPrior=pPrior;
		WN_SQL3ExprDelete(p->pLimit);
		p->pLimit=pLimit;
		p->pOffset=pOffset;
		if(rc)goto multi_select_end;
		if(eDest==SRT_Callback)
		{
			Select *pFirst=p;
			while(pFirst->pPrior)pFirst=pFirst->pPrior;
			generateColumnNames(pParse,0,pFirst->pEList);
		}
		iBreak=WN_SQL3VdbeMakeLabel(v);
		iCont=WN_SQL3VdbeMakeLabel(v);
		computeLimitRegisters(pParse,p,iBreak);
		WN_SQL3VdbeAddOp(v,OP_Rewind,tab1,iBreak);
		iStart=WN_SQL3VdbeAddOp(v,OP_RowKey,tab1,0);
		WN_SQL3VdbeAddOp(v,OP_NotFound,tab2,iCont);
		rc=selectInnerLoop(pParse,p,p->pEList,tab1,p->pEList->nExpr,pOrderBy,-1,eDest,iParm,iCont,iBreak,0);
		if(rc)
		{
			rc=1;
			goto multi_select_end;
		}
		WN_SQL3VdbeResolveLabel(v,iCont);
		WN_SQL3VdbeAddOp(v,OP_Next,tab1,iStart);
		WN_SQL3VdbeResolveLabel(v,iBreak);
		WN_SQL3VdbeAddOp(v,OP_Close,tab2,0);
		WN_SQL3VdbeAddOp(v,OP_Close,tab1,0);
	}
	if(p->pEList->nExpr!=pPrior->pEList->nExpr)
	{
		WN_SQL3ErrorMsg(pParse,"SELECTs to the left and right of %s"
" do not have the same number of result columns",selectOpName(p->op));
		rc=1;
		goto multi_select_end;
	}
	nCol=p->pEList->nExpr;
	while(nSetP2)WN_SQL3VdbeChangeP2(v,aSetP2[--nSetP2],nCol);
	if(pOrderBy || p->usesEphm)
	{
		int i;
		KeyInfo *pKeyInfo;
		Select *pLoop;
		int nKeyCol;
		CollSeq **apColl,**aCopy;
		nKeyCol=nCol+(pOrderBy ? pOrderBy->nExpr :0);
		pKeyInfo=WN_SQL3Malloc(sizeof(*pKeyInfo)+nKeyCol*(sizeof(CollSeq*)+1));
		if(!pKeyInfo)
		{
			rc=WN_SQL_NOMEM;
			goto multi_select_end;
		}
		pKeyInfo->enc=ENC(pParse->db);
		pKeyInfo->nField=nCol;
		for(i=0,apColl=pKeyInfo->aColl;i<nCol;i++,apColl++)
		{
			*apColl=multiSelectCollSeq(pParse,p,i);
			if(0==*apColl)*apColl=pParse->db->pDfltColl;
		}
		for(pLoop=p;pLoop;pLoop=pLoop->pPrior)
			for(i=0;i<2;i++)
			{
				int addr=pLoop->addrOpenEphm[i];
				if(addr<0)break;
				WN_SQL3VdbeChangeP2(v,addr,nCol);
				WN_SQL3VdbeChangeP3(v,addr,(char*)pKeyInfo,P3_KEYINFO);
				pLoop->addrOpenEphm[i]=-1;
			}
		if(pOrderBy)
		{
			struct ExprList_item *pOTerm=pOrderBy->a;
			int nOrderByExpr=pOrderBy->nExpr;
			int addr;
			u8 *pSortOrder;
			aCopy=&pKeyInfo->aColl[nOrderByExpr];
			pSortOrder=pKeyInfo->aSortOrder=(u8*)&aCopy[nCol];
			memmove(aCopy,pKeyInfo->aColl,nCol*sizeof(CollSeq*));
			apColl=pKeyInfo->aColl;
			for(i=0;i<nOrderByExpr;i++,pOTerm++,apColl++,pSortOrder++)
			{
				Expr *pExpr=pOTerm->pExpr;
				if((pExpr->flags & EP_ExpCollate))
					*apColl=pExpr->pColl;
				else
					*apColl=aCopy[pExpr->iColumn];
				*pSortOrder=pOTerm->sortOrder;
			}
			addr=p->addrOpenEphm[2];
			WN_SQL3VdbeChangeP2(v,addr,p->pOrderBy->nExpr+2);
			pKeyInfo->nField=nOrderByExpr;
			WN_SQL3VdbeChangeP3(v,addr,(char*)pKeyInfo,P3_KEYINFO_HANDOFF);
			pKeyInfo=0;
			generateSortTail(pParse,p,v,p->pEList->nExpr,eDest,iParm);
		}
		WN_SQL3FreeX(pKeyInfo);
	}
multi_select_end:
	return rc;
}
#endif
#ifndef WN_SQL_OMIT_VIEW
void substExpr(Expr *pExpr,int iTable,ExprList *pEList)
{
	if(pExpr==0)return;
	if(pExpr->op==TK_COLUMN && pExpr->iTable==iTable)
	{
		if(pExpr->iColumn<0)
			pExpr->op=TK_NULL;
		else
		{
			Expr *pNew=pEList->a[pExpr->iColumn].pExpr;
			pExpr->op=pNew->op;
			pExpr->pLeft=WN_SQL3ExprDup(pNew->pLeft);
			pExpr->pRight=WN_SQL3ExprDup(pNew->pRight);
			pExpr->pList=WN_SQL3ExprListDup(pNew->pList);
			pExpr->iTable=pNew->iTable;
			pExpr->pTab=pNew->pTab;
			pExpr->iColumn=pNew->iColumn;
			pExpr->iAgg=pNew->iAgg;
			WN_SQL3TokenCopy(&pExpr->token,&pNew->token);
			WN_SQL3TokenCopy(&pExpr->span,&pNew->span);
			pExpr->pSelect=WN_SQL3SelectDup(pNew->pSelect);
			pExpr->flags=pNew->flags;
		}
	}
	else
	{
		substExpr(pExpr->pLeft,iTable,pEList);
		substExpr(pExpr->pRight,iTable,pEList);
		substSelect(pExpr->pSelect,iTable,pEList);
		substExprList(pExpr->pList,iTable,pEList);
	}
}
void substExprList(ExprList *pList,int iTable,ExprList *pEList)
{
	int i;
	if(pList==0)return;
	for(i=0;i<pList->nExpr;i++)substExpr(pList->a[i].pExpr,iTable,pEList);
}
void substSelect(Select *p,int iTable,ExprList *pEList)
{
	if(!p)return;
	substExprList(p->pEList,iTable,pEList);
	substExprList(p->pGroupBy,iTable,pEList);
	substExprList(p->pOrderBy,iTable,pEList);
	substExpr(p->pHaving,iTable,pEList);
	substExpr(p->pWhere,iTable,pEList);
	substSelect(p->pPrior,iTable,pEList);
}
#endif
#ifndef WN_SQL_OMIT_VIEW
int flattenSubquery(Select *p,int iFrom,int isAgg,int subqueryIsAgg)
{
	if(p==0)return 0;
	Select *pSub;
	SrcList *pSrc=p->pSrc,*pSubSrc;
	ExprList *pList;
	int iParent,i;
	Expr *pWhere;
	struct SrcList_item *pSubitem;
	pSubitem=&pSrc->a[iFrom];
	pSub=pSubitem->pSelect;
	if(isAgg && subqueryIsAgg)return 0;
	if(subqueryIsAgg && pSrc->nSrc>1)return 0;
	pSubSrc=pSub->pSrc;
	if(pSub->pLimit && p->pLimit)return 0;
	if(pSub->pOffset)return 0;
	if(p->pRightmost && pSub->pLimit && pSub->pOrderBy)return 0;
	if(pSubSrc->nSrc==0)return 0;
	if((pSub->isDistinct || pSub->pLimit)&&(pSrc->nSrc>1 || isAgg))return 0;
	if(p->isDistinct && subqueryIsAgg)return 0;
	if((p->disallowOrderBy || p->pOrderBy)&& pSub->pOrderBy)return 0;
	if(pSubSrc->nSrc>1 &&(pSubitem->jointype & JT_OUTER))return 0;
	if((pSubitem->jointype & JT_OUTER)&& pSub->pWhere)return 0;
	iParent=pSubitem->iCursor;
	{
		int nSubSrc=pSubSrc->nSrc,jointype=pSubitem->jointype;
		WN_SQL3DeleteTable(pSubitem->pTab);
		WN_SQL3FreeX(pSubitem->zDatabase);
		WN_SQL3FreeX(pSubitem->zName);
		WN_SQL3FreeX(pSubitem->zAlias);
		if(nSubSrc>1)
		{	int extra=nSubSrc-1;
			for(i=1;i<nSubSrc;i++)pSrc=WN_SQL3SrcListAppend(pSrc,0,0);
			p->pSrc=pSrc;
			for(i=pSrc->nSrc-1;i-extra>=iFrom;i--)pSrc->a[i]=pSrc->a[i-extra];
		}
		for(i=0;i<nSubSrc;i++)
		{
			pSrc->a[i+iFrom]=pSubSrc->a[i];
			memset(&pSubSrc->a[i],0,sizeof(pSubSrc->a[i]));
		}
		pSrc->a[iFrom].jointype=jointype;
	}
	pList=p->pEList;
	for(i=0;i<pList->nExpr;i++)
	{	Expr *pExpr;
		if(pList->a[i].zName==0 &&(pExpr=pList->a[i].pExpr)->span.z)pList->a[i].zName=WN_SQLStrNDup((char*)pExpr->span.z,pExpr->span.n);
	}
	substExprList(p->pEList,iParent,pSub->pEList);
	if(isAgg)
	{	substExprList(p->pGroupBy,iParent,pSub->pEList);
		substExpr(p->pHaving,iParent,pSub->pEList);
	}
	if(pSub->pOrderBy)
	{	p->pOrderBy=pSub->pOrderBy;
		pSub->pOrderBy=0;
	}
	else
		if(p->pOrderBy)substExprList(p->pOrderBy,iParent,pSub->pEList);
	if(pSub->pWhere)pWhere=WN_SQL3ExprDup(pSub->pWhere);
	else
		pWhere=0;
	if(subqueryIsAgg)
	{	p->pHaving=p->pWhere;
		p->pWhere=pWhere;
		substExpr(p->pHaving,iParent,pSub->pEList);
		p->pHaving=WN_SQL3ExprAnd(p->pHaving,WN_SQL3ExprDup(pSub->pHaving));
		p->pGroupBy=WN_SQL3ExprListDup(pSub->pGroupBy);
	}
	else
	{	substExpr(p->pWhere,iParent,pSub->pEList);
		p->pWhere=WN_SQL3ExprAnd(p->pWhere,pWhere);
	}
	p->isDistinct=p->isDistinct || pSub->isDistinct;
	if(pSub->pLimit)
	{	p->pLimit=pSub->pLimit;
		pSub->pLimit=0;
	}
	WN_SQL3SelectDelete(pSub);
	return 1;
}
#endif
int simpleMinMaxQuery(Parse *pParse,Select *p,int eDest,int iParm)
{
	Expr *pExpr;
	int iCol;
	Table *pTab;
	Index *pIdx;
	int base;
	Vdbe *v;
	int seekOp;
	ExprList *pEList,*pList,eList;
	struct ExprList_item eListItem;
	SrcList *pSrc;
	int brk,iDb;
	if(p->pGroupBy || p->pHaving || p->pWhere)return 0;
	pSrc=p->pSrc;
	if(pSrc->nSrc!=1)return 0;
	pEList=p->pEList;
	if(pEList->nExpr!=1)return 0;
	pExpr=pEList->a[0].pExpr;
	if(pExpr->op!=TK_AGG_FUNCTION)return 0;
	pList=pExpr->pList;
	if(pList==0 || pList->nExpr!=1)return 0;
	if(pExpr->token.n!=3)return 0;
	if(WN_SQL3StrNICmp((char*)pExpr->token.z,"min",3)==0)
		seekOp=OP_Rewind;
	else
		if(WN_SQL3StrNICmp((char*)pExpr->token.z,"max",3)==0)
			seekOp=OP_Last;
		else
			return 0;
		pExpr=pList->a[0].pExpr;
		if(pExpr->op!=TK_COLUMN)return 0;
		iCol=pExpr->iColumn;
		pTab=pSrc->a[0].pTab;
		if(IsVirtual(pTab))return 0;
		if(iCol<0)
			pIdx=0;
		else
		{
			CollSeq *pColl=WN_SQL3ExprCollSeq(pParse,pExpr);
			if(pColl==0)return 0;
			for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)if(pIdx->aiColumn[0]==iCol && 0==WN_SQL3StrICmp(pIdx->azColl[0],pColl->zName))break;
			if(pIdx==0)return 0;
		}
		v=WN_SQL3GetVdbe(pParse);
		if(v==0)return 0;
		if(eDest==SRT_EphemTab)WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,iParm,1);
		iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
		WN_SQL3CodeVerifySchema(pParse,iDb);
		WN_SQL3TableLock(pParse,iDb,pTab->tnum,0,pTab->zName);
		base=pSrc->a[0].iCursor;
		brk=WN_SQL3VdbeMakeLabel(v);
		computeLimitRegisters(pParse,p,brk);
		if(pSrc->a[0].pSelect==0)WN_SQL3OpenTable(pParse,base,iDb,pTab,OP_OpenRead);
		if(pIdx==0)
			WN_SQL3VdbeAddOp(v,seekOp,base,0);
		else
		{
			int iIdx;
			KeyInfo *pKey=WN_SQL3IndexKeyinfo(pParse,pIdx);
			iIdx=pParse->nTab++;
			WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
			WN_SQL3VdbeOp3(v,OP_OpenRead,iIdx,pIdx->tnum,(char*)pKey,P3_KEYINFO_HANDOFF);
			if(seekOp==OP_Rewind)
			{
				WN_SQL3VdbeAddOp(v,OP_Null,0,0);
				WN_SQL3VdbeAddOp(v,OP_MakeRecord,1,0);
				seekOp=OP_MoveGt;
			}
			if(pIdx->aSortOrder[0]==WN_SQL_SO_DESC)
			{
				if(seekOp==OP_Last)
					seekOp=OP_Rewind;
				else
					seekOp=OP_MoveLt;
			}
			WN_SQL3VdbeAddOp(v,seekOp,iIdx,0);
			WN_SQL3VdbeAddOp(v,OP_IdxRowid,iIdx,0);
			WN_SQL3VdbeAddOp(v,OP_Close,iIdx,0);
			WN_SQL3VdbeAddOp(v,OP_MoveGe,base,0);
		}
		eList.nExpr=1;
		memset(&eListItem,0,sizeof(eListItem));
		eList.a=&eListItem;
		eList.a[0].pExpr=pExpr;
		selectInnerLoop(pParse,p,&eList,0,0,0,-1,eDest,iParm,brk,brk,0);
		WN_SQL3VdbeResolveLabel(v,brk);
		WN_SQL3VdbeAddOp(v,OP_Close,base,0);
		return 1;
}
int processOrderGroupBy(NameContext *pNC,ExprList *pOrderBy,const char *zType)
{
	if(pOrderBy==0)return 0;
	int i;
	ExprList *pEList=pNC->pEList;
	Parse *pParse=pNC->pParse;
	if(pOrderBy->nExpr>WN_SQL_MAX_COLUMN)
	{
		WN_SQL3ErrorMsg(pParse,"too many terms in %s BY clause",zType);
		return 1;
	}
	for(i=0;i<pOrderBy->nExpr;i++)
	{
		int iCol;
		Expr *pE=pOrderBy->a[i].pExpr;
		if(WN_SQL3ExprIsInteger(pE,&iCol))
		{
			if(iCol>0 && iCol<=pEList->nExpr)
			{
				CollSeq *pColl=pE->pColl;
				int flags=pE->flags & EP_ExpCollate;
				WN_SQL3ExprDelete(pE);
				pE=pOrderBy->a[i].pExpr=WN_SQL3ExprDup(pEList->a[iCol-1].pExpr);
				if(pColl && flags)
				{
					pE->pColl=pColl;
					pE->flags |=flags;
				}
			}
			else
			{
				WN_SQL3ErrorMsg(pParse,"%s BY column number %d out of range-should be "
"between 1 and %d",zType,iCol,pEList->nExpr);
				return 1;
			}
		}
		if(WN_SQL3ExprResolveNames(pNC,pE))return 1;
	}
	return 0;
}
int WN_SQL3SelectResolve(Parse *pParse,Select *p,NameContext *pOuterNC)
{
	ExprList *pEList;
	int i;
	NameContext sNC;
	ExprList *pGroupBy;
	if(p->isResolved)return 0;
	p->isResolved=1;
	if(pParse->nErr>0)return WN_SQL_ERROR;
	if(prepSelectStmt(pParse,p))return WN_SQL_ERROR;
	memset(&sNC,0,sizeof(sNC));
	sNC.pParse=pParse;
	if(WN_SQL3ExprResolveNames(&sNC,p->pLimit)||WN_SQL3ExprResolveNames(&sNC,p->pOffset))return WN_SQL_ERROR;
	sNC.allowAgg=1;
	sNC.pSrcList=p->pSrc;
	sNC.pNext=pOuterNC;
	pEList=p->pEList;
	if(!pEList)return WN_SQL_ERROR;
	for(i=0;i<pEList->nExpr;i++)
	{
		Expr *pX=pEList->a[i].pExpr;
		if(WN_SQL3ExprResolveNames(&sNC,pX))return WN_SQL_ERROR;
	}
	pGroupBy=p->pGroupBy;
	if(pGroupBy || sNC.hasAgg)
		p->isAgg=1;
	else
		sNC.allowAgg=0;
	if(p->pHaving && !pGroupBy)
	{
		WN_SQL3ErrorMsg(pParse,"a GROUP BY clause is required before HAVING");
		return WN_SQL_ERROR;
	}
	sNC.pEList=p->pEList;
	if(WN_SQL3ExprResolveNames(&sNC,p->pWhere)||WN_SQL3ExprResolveNames(&sNC,p->pHaving))return WN_SQL_ERROR;
	if(p->pPrior==0)
		if(processOrderGroupBy(&sNC,p->pOrderBy,"ORDER")||processOrderGroupBy(&sNC,pGroupBy,"GROUP"))return WN_SQL_ERROR;
	if(WN_SQL3MallocFailed())return WN_SQL_NOMEM;
	if(pGroupBy)
	{
		struct ExprList_item *pItem;
		for(i=0,pItem=pGroupBy->a;i<pGroupBy->nExpr;i++,pItem++)
			if(ExprHasProperty(pItem->pExpr,EP_Agg))
			{
				WN_SQL3ErrorMsg(pParse,"aggregate functions are not allowed in "
"the GROUP BY clause");
				return WN_SQL_ERROR;
			}
	}
	if(p->pPrior)
		return WN_SQL3SelectResolve(pParse,p->pPrior,pOuterNC);
	else
		return 0;
}
void resetAccumulator(Parse *pParse,AggInfo *pAggInfo)
{
	if(pAggInfo->nFunc+pAggInfo->nColumn==0)return;
	Vdbe *v=pParse->pVdbe;
	int i;
	struct AggInfo_func *pFunc;
	for(i=0;i<pAggInfo->nColumn;i++)WN_SQL3VdbeAddOp(v,OP_MemNull,pAggInfo->aCol[i].iMem,0);
	for(pFunc=pAggInfo->aFunc,i=0;i<pAggInfo->nFunc;i++,pFunc++)
	{
		WN_SQL3VdbeAddOp(v,OP_MemNull,pFunc->iMem,0);
		if(pFunc->iDistinct>=0)
		{
			Expr *pE=pFunc->pExpr;
			if(pE->pList==0 || pE->pList->nExpr!=1)
			{
				WN_SQL3ErrorMsg(pParse,"DISTINCT in aggregate must be followed "
"by an expression");
				pFunc->iDistinct=-1;
			}
			else
			{
				KeyInfo *pKeyInfo=keyInfoFromExprList(pParse,pE->pList);
				WN_SQL3VdbeOp3(v,OP_OpenEphemeral,pFunc->iDistinct,0,(char*)pKeyInfo,P3_KEYINFO_HANDOFF);
}	}	}	}
void finalizeAggFunctions(Parse *pParse,AggInfo *pAggInfo)
{
	Vdbe *v=pParse->pVdbe;
	int i;
	struct AggInfo_func *pF;
	for(i=0,pF=pAggInfo->aFunc;i<pAggInfo->nFunc;i++,pF++)
	{
		ExprList *pList=pF->pExpr->pList;
		WN_SQL3VdbeOp3(v,OP_AggFinal,pF->iMem,pList ? pList->nExpr :0,(void*)pF->pFunc,P3_FUNCDEF);
}	}
void updateAccumulator(Parse *pParse,AggInfo *pAggInfo)
{	Vdbe *v=pParse->pVdbe;
	int i;
	struct AggInfo_func *pF;
	struct AggInfo_col *pC;
	pAggInfo->directMode=1;
	for(i=0,pF=pAggInfo->aFunc;i<pAggInfo->nFunc;i++,pF++)
	{	int nArg,addrNext=0;
		ExprList *pList=pF->pExpr->pList;
		if(pList)
		{	nArg=pList->nExpr;
			WN_SQL3ExprCodeExprList(pParse,pList);
		}
		else
			nArg=0;
		if(pF->iDistinct>=0)
		{	addrNext=WN_SQL3VdbeMakeLabel(v);
			codeDistinct(v,pF->iDistinct,addrNext,1);
		}
		if(pF->pFunc->needCollSeq)
		{	CollSeq *pColl=0;
			struct ExprList_item *pItem;
			int j;
			for(j=0,pItem=pList->a;!pColl && j<nArg;j++,pItem++)
				pColl=WN_SQL3ExprCollSeq(pParse,pItem->pExpr);
			if(!pColl)pColl=pParse->db->pDfltColl;
			WN_SQL3VdbeOp3(v,OP_CollSeq,0,0,(char *)pColl,P3_COLLSEQ);
		}
		WN_SQL3VdbeOp3(v,OP_AggStep,pF->iMem,nArg,(void*)pF->pFunc,P3_FUNCDEF);
		if(addrNext)WN_SQL3VdbeResolveLabel(v,addrNext);
	}
	for(i=0,pC=pAggInfo->aCol;i<pAggInfo->nAccumulator;i++,pC++)
	{	WN_SQL3ExprCode(pParse,pC->pExpr);
		WN_SQL3VdbeAddOp(v,OP_MemStore,pC->iMem,1);
	}
	pAggInfo->directMode=0;
}
int WN_SQL3Select(Parse *pParse,Select *p,int eDest,int iParm,Select *pParent,int parentTab,int *pParentAgg,char *aff)
{	int i,j,isAgg,isDistinct,distinct,rc=1,addrSortIndex;
	WhereInfo *pWInfo;
	Vdbe *v;
	ExprList *pEList,*pWhere,*pOrderBy,*pGroupBy;
	SrcList *pTabList;	
	Expr *pHaving;
	AggInfo sAggInfo;
	int iEnd;
	if(p==0 || WN_SQL3MallocFailed()|| pParse->nErr)return 1;
	if(WN_SQL3AuthCheck(pParse,WN_SQL_SELECT,0,0,0))return 1;
	memset(&sAggInfo,0,sizeof(sAggInfo));
#ifndef WN_SQL_OMIT_COMPOUND_SELECT
	if(p->pPrior)
	{	if(p->pRightmost==0)
		{	Select *pLoop;
			int cnt=0;
			for(pLoop=p;pLoop;pLoop=pLoop->pPrior,cnt++)pLoop->pRightmost=p;
			if(WN_SQL_MAX_COMPOUND_SELECT>0 && cnt>WN_SQL_MAX_COMPOUND_SELECT)
			{	WN_SQL3ErrorMsg(pParse,"too many terms in compound SELECT");
				return 1;
		}	}
		return multiSelect(pParse,p,eDest,iParm,aff);
	}
#endif
	pOrderBy=p->pOrderBy;
	if(IgnorableOrderby(eDest))p->pOrderBy=0;
	if(WN_SQL3SelectResolve(pParse,p,0))goto select_end;
	p->pOrderBy=pOrderBy;
	pTabList=p->pSrc;
	pWhere=p->pWhere;
	pGroupBy=p->pGroupBy;
	pHaving=p->pHaving;
	isAgg=p->isAgg;
	isDistinct=p->isDistinct;
	pEList=p->pEList;
	if(pEList==0)goto select_end;
	if(pParse->nErr>0)goto select_end;
#ifndef WN_SQL_OMIT_SUBQUERY
	if(checkForMultiColumnSelectError(pParse,eDest,pEList->nExpr))goto select_end;
#endif
	if(IgnorableOrderby(eDest))	pOrderBy=0;
	v=WN_SQL3GetVdbe(pParse);
	if(v==0)goto select_end;
#if !defined(WN_SQL_OMIT_SUBQUERY)|| !defined(WN_SQL_OMIT_VIEW)
	for(i=0;i<pTabList->nSrc;i++)
	{	const char *zSavedAuthContext=0;
		int needRestoreContext;
		struct SrcList_item *pItem=&pTabList->a[i];
		if(pItem->pSelect==0 || pItem->isPopulated)continue;
		if(pItem->zName)
		{	zSavedAuthContext=pParse->zAuthContext;
			pParse->zAuthContext=pItem->zName;
			needRestoreContext=1;
		}
		else
			needRestoreContext=0;
#if WN_SQL_MAX_EXPR_DEPTH>0
		pParse->nHeight+=WN_SQL3SelectExprHeight(p);
#endif
		WN_SQL3Select(pParse,pItem->pSelect,SRT_EphemTab,pItem->iCursor,p,i,&isAgg,0);
#if WN_SQL_MAX_EXPR_DEPTH>0
		pParse->nHeight-=WN_SQL3SelectExprHeight(p);
#endif
		if(needRestoreContext)pParse->zAuthContext=zSavedAuthContext;
		pTabList=p->pSrc;
		pWhere=p->pWhere;
		if(!IgnorableOrderby(eDest))pOrderBy=p->pOrderBy;
		pGroupBy=p->pGroupBy;
		pHaving=p->pHaving;
		isDistinct=p->isDistinct;
	}
#endif
	if(simpleMinMaxQuery(pParse,p,eDest,iParm))
	{	rc=0;
		goto select_end;
	}
#ifndef WN_SQL_OMIT_VIEW
	if(pParent && pParentAgg && flattenSubquery(pParent,parentTab,*pParentAgg,isAgg))
	{	if(isAgg)*pParentAgg=1;
		goto select_end;
	}
#endif
	if(pOrderBy)
	{	KeyInfo *pKeyInfo;
		if(pParse->nErr)goto select_end;
		pKeyInfo=keyInfoFromExprList(pParse,pOrderBy);
		pOrderBy->iECursor=pParse->nTab++;
		p->addrOpenEphm[2]=addrSortIndex=WN_SQL3VdbeOp3(v,OP_OpenEphemeral,pOrderBy->iECursor,pOrderBy->nExpr+2,(char*)pKeyInfo,P3_KEYINFO_HANDOFF);
	}
	else
		addrSortIndex=-1;
	if(eDest==SRT_EphemTab)WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,iParm,pEList->nExpr);
	iEnd=WN_SQL3VdbeMakeLabel(v);
	computeLimitRegisters(pParse,p,iEnd);
	if(isDistinct)
	{
		KeyInfo *pKeyInfo;
		distinct=pParse->nTab++;
		pKeyInfo=keyInfoFromExprList(pParse,p->pEList);
		WN_SQL3VdbeOp3(v,OP_OpenEphemeral,distinct,0,(char*)pKeyInfo,P3_KEYINFO_HANDOFF);
	}
	else distinct=-1;
	if(!isAgg && pGroupBy==0)
	{
		pWInfo=WN_SQL3WhereBegin(pParse,pTabList,pWhere,&pOrderBy);
		if(pWInfo==0)goto select_end;
		if(addrSortIndex>=0 && pOrderBy==0)
		{	WN_SQL3VdbeChangeToNoop(v,addrSortIndex,1);
			p->addrOpenEphm[2]=-1;
		}
		if(selectInnerLoop(pParse,p,pEList,0,0,pOrderBy,distinct,eDest,iParm,pWInfo->iContinue,pWInfo->iBreak,aff))goto select_end;
		WN_SQL3WhereEnd(pWInfo);
	}
	else
	{	NameContext sNC;
		int iAMem,iBMem,iUseFlag,iAbortFlag,groupBySort,addrOutputRow,addrSetAbort,addrInitializeLoop,addrTopOfLoop,addrGroupByChange,addrProcessRow,addrEnd,addrSortingIdx,addrReset;
		addrEnd=WN_SQL3VdbeMakeLabel(v);
		memset(&sNC,0,sizeof(sNC));
		sNC.pParse=pParse;
		sNC.pSrcList=pTabList;
		sNC.pAggInfo=&sAggInfo;
		sAggInfo.nSortingColumn=pGroupBy ? pGroupBy->nExpr+1 :0;
		sAggInfo.pGroupBy=pGroupBy;
		if(WN_SQL3ExprAnalyzeAggList(&sNC,pEList))goto select_end;
		if(WN_SQL3ExprAnalyzeAggList(&sNC,pOrderBy))goto select_end;
		if(pHaving && WN_SQL3ExprAnalyzeAggregates(&sNC,pHaving))goto select_end;
		sAggInfo.nAccumulator=sAggInfo.nColumn;
		for(i=0;i<sAggInfo.nFunc;i++)
		{	if(WN_SQL3ExprAnalyzeAggList(&sNC,sAggInfo.aFunc[i].pExpr->pList))
			goto select_end;
		}
		if(WN_SQL3MallocFailed())goto select_end;
		if(pGroupBy)
		{
			KeyInfo *pKeyInfo;
			addrInitializeLoop=WN_SQL3VdbeMakeLabel(v);
			addrGroupByChange=WN_SQL3VdbeMakeLabel(v);
			addrProcessRow=WN_SQL3VdbeMakeLabel(v);
			sAggInfo.sortingIdx=pParse->nTab++;
			pKeyInfo=keyInfoFromExprList(pParse,pGroupBy);
			addrSortingIdx=WN_SQL3VdbeOp3(v,OP_OpenEphemeral,sAggInfo.sortingIdx,sAggInfo.nSortingColumn,(char*)pKeyInfo,P3_KEYINFO_HANDOFF);
			iUseFlag=pParse->nMem++;
			iAbortFlag=pParse->nMem++;
			iAMem=pParse->nMem;
			pParse->nMem+=pGroupBy->nExpr;
			iBMem=pParse->nMem;
			pParse->nMem+=pGroupBy->nExpr;
			WN_SQL3VdbeAddOp(v,OP_MemInt,0,iAbortFlag);
			VdbeComment((v,"# clear abort flag"));
			WN_SQL3VdbeAddOp(v,OP_MemInt,0,iUseFlag);
			VdbeComment((v,"# indicate accumulator empty"));
			WN_SQL3VdbeAddOp(v,OP_Goto,0,addrInitializeLoop);
			addrSetAbort=WN_SQL3VdbeCurrentAddr(v);
			WN_SQL3VdbeAddOp(v,OP_MemInt,1,iAbortFlag);
			VdbeComment((v,"# set abort flag"));
			WN_SQL3VdbeAddOp(v,OP_Return,0,0);
			addrOutputRow=WN_SQL3VdbeCurrentAddr(v);
			WN_SQL3VdbeAddOp(v,OP_IfMemPos,iUseFlag,addrOutputRow+2);
			VdbeComment((v,"# Groupby result generator entry point"));
			WN_SQL3VdbeAddOp(v,OP_Return,0,0);
			finalizeAggFunctions(pParse,&sAggInfo);
			if(pHaving)WN_SQL3ExprIfFalse(pParse,pHaving,addrOutputRow+1,1);
			rc=selectInnerLoop(pParse,p,p->pEList,0,0,pOrderBy,distinct,eDest,iParm,addrOutputRow+1,addrSetAbort,aff);
			if(rc)goto select_end;
			WN_SQL3VdbeAddOp(v,OP_Return,0,0);
			VdbeComment((v,"# end groupby result generator"));
			addrReset=WN_SQL3VdbeCurrentAddr(v);
			resetAccumulator(pParse,&sAggInfo);
			WN_SQL3VdbeAddOp(v,OP_Return,0,0);
			WN_SQL3VdbeResolveLabel(v,addrInitializeLoop);
			WN_SQL3VdbeAddOp(v,OP_Gosub,0,addrReset);
			pWInfo=WN_SQL3WhereBegin(pParse,pTabList,pWhere,&pGroupBy);
			if(pWInfo==0)goto select_end;
			if(pGroupBy==0)
			{	pGroupBy=p->pGroupBy;
				groupBySort=0;
			}
			else
			{	groupBySort=1;
				WN_SQL3ExprCodeExprList(pParse,pGroupBy);
				WN_SQL3VdbeAddOp(v,OP_Sequence,sAggInfo.sortingIdx,0);
				j=pGroupBy->nExpr+1;
				for(i=0;i<sAggInfo.nColumn;i++)
				{	struct AggInfo_col *pCol=&sAggInfo.aCol[i];
					if(pCol->iSorterColumn<j)continue;
					WN_SQL3ExprCodeGetColumn(v,pCol->pTab,pCol->iColumn,pCol->iTable);
					j++;
				}
				WN_SQL3VdbeAddOp(v,OP_MakeRecord,j,0);
				WN_SQL3VdbeAddOp(v,OP_IdxInsert,sAggInfo.sortingIdx,0);
				WN_SQL3WhereEnd(pWInfo);
				WN_SQL3VdbeAddOp(v,OP_Sort,sAggInfo.sortingIdx,addrEnd);
				VdbeComment((v,"# GROUP BY sort"));
				sAggInfo.useSortingIdx=1;
			}
			addrTopOfLoop=WN_SQL3VdbeCurrentAddr(v);
			for(j=0;j<pGroupBy->nExpr;j++)
			{	if(groupBySort)
					WN_SQL3VdbeAddOp(v,OP_Column,sAggInfo.sortingIdx,j);
				else
				{
					sAggInfo.directMode=1;
					WN_SQL3ExprCode(pParse,pGroupBy->a[j].pExpr);
				}
				WN_SQL3VdbeAddOp(v,OP_MemStore,iBMem+j,j<pGroupBy->nExpr-1);
			}
			for(j=pGroupBy->nExpr-1;j>=0;j--)
			{
				if(j<pGroupBy->nExpr-1)
					WN_SQL3VdbeAddOp(v,OP_MemLoad,iBMem+j,0);
				WN_SQL3VdbeAddOp(v,OP_MemLoad,iAMem+j,0);
				if(j==0)
					WN_SQL3VdbeAddOp(v,OP_Eq,0x200,addrProcessRow);
				else
					WN_SQL3VdbeAddOp(v,OP_Ne,0x200,addrGroupByChange);
				WN_SQL3VdbeChangeP3(v,-1,(void*)pKeyInfo->aColl[j],P3_COLLSEQ);
			}
			WN_SQL3VdbeResolveLabel(v,addrGroupByChange);
			for(j=0;j<pGroupBy->nExpr;j++)
				WN_SQL3VdbeAddOp(v,OP_MemMove,iAMem+j,iBMem+j);
			WN_SQL3VdbeAddOp(v,OP_Gosub,0,addrOutputRow);
			VdbeComment((v,"# output one row"));
			WN_SQL3VdbeAddOp(v,OP_IfMemPos,iAbortFlag,addrEnd);
			VdbeComment((v,"# check abort flag"));
			WN_SQL3VdbeAddOp(v,OP_Gosub,0,addrReset);
			VdbeComment((v,"# reset accumulator"));
			WN_SQL3VdbeResolveLabel(v,addrProcessRow);
			updateAccumulator(pParse,&sAggInfo);
			WN_SQL3VdbeAddOp(v,OP_MemInt,1,iUseFlag);
			VdbeComment((v,"# indicate data in accumulator"));
			if(groupBySort)
				WN_SQL3VdbeAddOp(v,OP_Next,sAggInfo.sortingIdx,addrTopOfLoop);
			else
			{	WN_SQL3WhereEnd(pWInfo);
				WN_SQL3VdbeChangeToNoop(v,addrSortingIdx,1);
			}
			WN_SQL3VdbeAddOp(v,OP_Gosub,0,addrOutputRow);
			VdbeComment((v,"# output final row"));
		}
		else
		{	resetAccumulator(pParse,&sAggInfo);
			pWInfo=WN_SQL3WhereBegin(pParse,pTabList,pWhere,0);
			if(pWInfo==0)goto select_end;
			updateAccumulator(pParse,&sAggInfo);
			WN_SQL3WhereEnd(pWInfo);
			finalizeAggFunctions(pParse,&sAggInfo);
			pOrderBy=0;
			if(pHaving)WN_SQL3ExprIfFalse(pParse,pHaving,addrEnd,1);
			selectInnerLoop(pParse,p,p->pEList,0,0,0,-1,eDest,iParm,addrEnd,addrEnd,aff);
		}
		WN_SQL3VdbeResolveLabel(v,addrEnd);
	}
	if(pOrderBy)generateSortTail(pParse,p,v,pEList->nExpr,eDest,iParm);
#ifndef WN_SQL_OMIT_SUBQUERY
	if(pParent)pParent->pSrc->a[parentTab].isPopulated=1;
#endif
	WN_SQL3VdbeResolveLabel(v,iEnd);
	rc=0;
select_end:
	if(rc==0 && eDest==SRT_Callback)generateColumnNames(pParse,pTabList,pEList);
	WN_SQL3FreeX(sAggInfo.aCol);
	WN_SQL3FreeX(sAggInfo.aFunc);
	return rc;
}
#if defined(WN_SQL_DEBUG)
void WN_SQL3PrintExpr(Expr *p)
{
	if(p->token.z && p->token.n>0)
		WN_SQL3DebugPrintf("(%.*s",p->token.n,p->token.z);
	else
		WN_SQL3DebugPrintf("(%d",p->op);
	if(p->pLeft)
	{	WN_SQL3DebugPrintf(" ");
		WN_SQL3PrintExpr(p->pLeft);
	}
	if(p->pRight)
	{	WN_SQL3DebugPrintf(" ");
		WN_SQL3PrintExpr(p->pRight);
	}
	WN_SQL3DebugPrintf(")");
}
void WN_SQL3PrintExprList(ExprList *pList)
{	int i;
	for(i=0;i<pList->nExpr;i++)
	{	WN_SQL3PrintExpr(pList->a[i].pExpr);
		if(i<pList->nExpr-1)WN_SQL3DebugPrintf(",");
	}
}
void WN_SQL3PrintSelect(Select *p,int indent)
{
	WN_SQL3DebugPrintf("%*sSELECT(%p)",indent,"",p);
	WN_SQL3PrintExprList(p->pEList);
	WN_SQL3DebugPrintf("\n");
	if(p->pSrc)
	{
		char *zPrefix;
		int i;
		zPrefix="FROM";
		for(i=0;i<p->pSrc->nSrc;i++)
		{
			struct SrcList_item *pItem=&p->pSrc->a[i];
			WN_SQL3DebugPrintf("%*s ",indent+6,zPrefix);
			zPrefix="";
			if(pItem->pSelect)
			{
				WN_SQL3DebugPrintf("(\n");
				WN_SQL3PrintSelect(pItem->pSelect,indent+10);
				WN_SQL3DebugPrintf("%*s)",indent+8,"");
			}
			else
				if(pItem->zName)WN_SQL3DebugPrintf("%s",pItem->zName);
			if(pItem->pTab)WN_SQL3DebugPrintf("(table:%s)",pItem->pTab->zName);
			if(pItem->zAlias)WN_SQL3DebugPrintf(" AS %s",pItem->zAlias);
			if(i<p->pSrc->nSrc-1)WN_SQL3DebugPrintf(",");
			WN_SQL3DebugPrintf("\n");
		}
	}
	if(p->pWhere)
	{
		WN_SQL3DebugPrintf("%*s WHERE ",indent,"");
		WN_SQL3PrintExpr(p->pWhere);
		WN_SQL3DebugPrintf("\n");
	}
	if(p->pGroupBy)
	{
		WN_SQL3DebugPrintf("%*s GROUP BY ",indent,"");
		WN_SQL3PrintExprList(p->pGroupBy);
		WN_SQL3DebugPrintf("\n");
	}
	if(p->pHaving)
	{
		WN_SQL3DebugPrintf("%*s HAVING ",indent,"");
		WN_SQL3PrintExpr(p->pHaving);
		WN_SQL3DebugPrintf("\n");
	}
	if(p->pOrderBy)
	{
		WN_SQL3DebugPrintf("%*s ORDER BY ",indent,"");
		WN_SQL3PrintExprList(p->pOrderBy);
		WN_SQL3DebugPrintf("\n");
	}
}
#endif
#ifndef WN_SQL_OMIT_GET_TABLE
typedef struct TabResult
{
	char **azResult,*zErrMsg;
	int nResult,nAlloc,nRow,nColumn,nData,rc;
}TabResult;
int WN_SQL3_get_table_cb(void *pArg,int nCol,char **argv,char **colv)
{
	TabResult *p=(TabResult*)pArg;
	int need,i;
	char *z;
	if(p->nRow==0 && argv)
		need=nCol*2;
	else
		need=nCol;
	if(p->nData+need >=p->nAlloc)
	{	char **azNew;
		p->nAlloc=p->nAlloc*2+need+1;
		azNew=WN_SQL3_realloc(p->azResult,sizeof(char*)*p->nAlloc);
		if(azNew==0)goto malloc_failed;
		p->azResult=azNew;
	}
	if(p->nRow==0)
	{
		p->nColumn=nCol;
		for(i=0;i<nCol;i++)
		{
			if(colv[i]==0)
				z=WN_SQL3_mprintf("");
			else
				z=WN_SQL3_mprintf("%s",colv[i]);
			p->azResult[p->nData++]=z;
		}
	}
	else
		if(p->nColumn!=nCol)
		{	WN_SQL3SetString(&p->zErrMsg,"WN_SQL3_get_table()called with two or more incompatible queries",(char*)0);
			p->rc=WN_SQL_ERROR;
			return 1;
		}
	if(argv)
	{	for(i=0;i<nCol;i++)
		{	if(argv[i]==0)
				z=0;
			else
			{	int n=strlen(argv[i])+1;
				z=WN_SQL3_malloc(n);
				if(z==0)goto malloc_failed;
				memcpy(z,argv[i],n);
			}
			p->azResult[p->nData++]=z;
		}
		p->nRow++;
	}
	return 0;
malloc_failed:
	p->rc=WN_SQL_NOMEM;
	return 1;
}
int WN_SQL3_get_table(WN_SQL3 *db,const char *zSql,char ***pazResult,int *pnRow,int *pnColumn,char **pzErrMsg)
{	if(pazResult==0)return WN_SQL_ERROR;
	int rc;
	TabResult res;
	*pazResult=0;
	if(pnColumn)*pnColumn=0;
	if(pnRow)*pnRow=0;
	res.zErrMsg=0;
	res.nResult=0;
	res.nRow=0;
	res.nColumn=0;
	res.nData=1;
	res.nAlloc=20;
	res.rc=0;
	res.azResult=WN_SQL3_malloc(sizeof(char*)*res.nAlloc);
	if(res.azResult==0)return WN_SQL_NOMEM;
	res.azResult[0]=0;
	rc=WN_SQL3_exec(db,zSql,WN_SQL3_get_table_cb,&res,pzErrMsg);
	if(res.azResult) res.azResult[0]=(char*)res.nData;
	if((rc&0xff)==WN_SQL_ABORT)
	{	WN_SQL3_free_table(&res.azResult[1]);
		if(res.zErrMsg)
		{	if(pzErrMsg)
			{	WN_SQL3_free(*pzErrMsg);
				*pzErrMsg=WN_SQL3_mprintf("%s",res.zErrMsg);
			}
			WN_SQL3FreeX(res.zErrMsg);
		}
		db->errCode=res.rc;
		return res.rc & db->errMask;
	}
	WN_SQL3FreeX(res.zErrMsg);
	if(rc)
	{	WN_SQL3_free_table(&res.azResult[1]);
		return rc & db->errMask;
	}
	if(res.nAlloc>res.nData)
	{	char **azNew;
		azNew=WN_SQL3_realloc(res.azResult,sizeof(char*)*(res.nData+1));
		if(azNew==0)
		{	WN_SQL3_free_table(&res.azResult[1]);
			return WN_SQL_NOMEM;
		}
		res.nAlloc=res.nData+1;
		res.azResult=azNew;
	}
	*pazResult=&res.azResult[1];
	if(pnColumn)*pnColumn=res.nColumn;
	if(pnRow)*pnRow=res.nRow;
	return rc & db->errMask;
}
void WN_SQL3_free_table(char **azResult)
{
	if(azResult)
	{	azResult--;
		if(azResult==0)return;
		int i,n=(int)azResult[0];
		for(i=1;i<n;i++)if(azResult[i])WN_SQL3_free(azResult[i]);
		WN_SQL3_free(azResult);
	}
}
#endif
#ifndef WN_SQL_OMIT_TRIGGER
void WN_SQL3DeleteTriggerStep(TriggerStep *pTriggerStep)
{	while(pTriggerStep)
	{	TriggerStep * pTmp=pTriggerStep;
		pTriggerStep=pTriggerStep->pNext;
		if(pTmp->target.dyn)WN_SQL3FreeX((char*)pTmp->target.z);
		WN_SQL3ExprDelete(pTmp->pWhere);
		WN_SQL3ExprListDelete(pTmp->pExprList);
		WN_SQL3SelectDelete(pTmp->pSelect);
		WN_SQL3IdListDelete(pTmp->pIdList);
		WN_SQL3FreeX(pTmp);
}	}
void WN_SQL3BeginTrigger(Parse *pParse,Token *pName1,Token *pName2,int tr_tm,int op,IdList *pColumns,SrcList *pTableName,Expr *pWhen,int isTemp,int noErr)
{
	Trigger *pTrigger=0;
	char *zName=0;
	WN_SQL3 *db=pParse->db;
	int iDb;
	Token *pName;
	DbFixer sFix;
	int iTabDb;
	if(isTemp)
	{
		if(pName2->n>0)
		{
			WN_SQL3ErrorMsg(pParse,"temporary trigger may not have qualified name");
			goto trigger_cleanup;
		}
		iDb=1;
		pName=pName1;
	}
	else
	{
		iDb=WN_SQL3TwoPartName(pParse,pName1,pName2,&pName);
		if(iDb<0)goto trigger_cleanup;
	}
	if(!pTableName || WN_SQL3MallocFailed())goto trigger_cleanup;
	Table *pTab=WN_SQL3SrcListLookup(pParse,pTableName);
	if(pName2->n==0 && pTab && pTab->pSchema==db->aDb[1].pSchema)iDb=1;
	if(WN_SQL3MallocFailed())goto trigger_cleanup;
	if(WN_SQL3FixInit(&sFix,pParse,iDb,"trigger",pName)&& WN_SQL3FixSrcList(&sFix,pTableName))goto trigger_cleanup;
	pTab=WN_SQL3SrcListLookup(pParse,pTableName);
	if(!pTab)goto trigger_cleanup;
	if(IsVirtual(pTab))
	{
		WN_SQL3ErrorMsg(pParse,"cannot create triggers on virtual tables");
		goto trigger_cleanup;
	}
	zName=WN_SQL3NameFromToken(pName);
	if(!zName || WN_SQL3CheckObjectName(pParse,zName))goto trigger_cleanup;
	if(WN_SQL3HashFind(&(db->aDb[iDb].pSchema->trigHash),zName,strlen(zName)))
	{
		if(!noErr)WN_SQL3ErrorMsg(pParse,"trigger %T already exists",pName);
		goto trigger_cleanup;
	}
	if(WN_SQL3StrNICmp(pTab->zName,"WN_SQL_",7)==0)
	{
		WN_SQL3ErrorMsg(pParse,"cannot create trigger on system table");
		pParse->nErr++;
		goto trigger_cleanup;
	}
	if(pTab->pSelect && tr_tm!=TK_INSTEAD)
	{
		WN_SQL3ErrorMsg(pParse,"cannot create %s trigger on view:%S",(tr_tm==TK_BEFORE)?"BEFORE":"AFTER",pTableName,0);
		goto trigger_cleanup;
	}
	if(!pTab->pSelect && tr_tm==TK_INSTEAD)
	{
		WN_SQL3ErrorMsg(pParse,"cannot create INSTEAD OF"
" trigger on table:%S",pTableName,0);
		goto trigger_cleanup;
	}
	iTabDb=WN_SQL3SchemaToIndex(db,pTab->pSchema);
#ifndef WN_SQL_OMIT_AUTHORIZATION
	int code=WN_SQL_CREATE_TRIGGER;
	const char *zDb=db->aDb[iTabDb].zName;
	const char *zDbTrig=isTemp ? db->aDb[1].zName :zDb;
	if(iTabDb==1 || isTemp)code=WN_SQL_CREATE_TEMP_TRIGGER;
	if(WN_SQL3AuthCheck(pParse,code,zName,pTab->zName,zDbTrig))goto trigger_cleanup;
	if(WN_SQL3AuthCheck(pParse,WN_SQL_INSERT,SCHEMA_TABLE(iTabDb),0,zDb))goto trigger_cleanup;
#endif
	if(tr_tm==TK_INSTEAD)tr_tm=TK_BEFORE;
	pTrigger=(Trigger*)WN_SQL3Malloc(sizeof(Trigger));
	if(pTrigger==0)goto trigger_cleanup;
	pTrigger->name=zName;
	zName=0;
	pTrigger->table=WN_SQLStrDup(pTableName->a[0].zName);
	pTrigger->pSchema=db->aDb[iDb].pSchema;
	pTrigger->pTabSchema=pTab->pSchema;
	pTrigger->op=op;
	pTrigger->tr_tm=tr_tm==TK_BEFORE ? TRIGGER_BEFORE :TRIGGER_AFTER;
	pTrigger->pWhen=WN_SQL3ExprDup(pWhen);
	pTrigger->pColumns=WN_SQL3IdListDup(pColumns);
	WN_SQL3TokenCopy(&pTrigger->nameToken,pName);
	pParse->pNewTrigger=pTrigger;
trigger_cleanup:
	WN_SQL3FreeX(zName);
	WN_SQL3SrcListDelete(pTableName);
	WN_SQL3IdListDelete(pColumns);
	WN_SQL3ExprDelete(pWhen);
	if(!pParse->pNewTrigger)
		WN_SQL3DeleteTrigger(pTrigger);
}
void WN_SQL3FinishTrigger(Parse *pParse,TriggerStep *pStepList,Token *pAll
)
{
	WN_SQL3 *db=pParse->db;
	DbFixer sFix;
	Trigger *pTrig=pParse->pNewTrigger;
	pParse->pNewTrigger=0;
	if(pParse->nErr || !pTrig)goto triggerfinish_cleanup;
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pTrig->pSchema);
	pTrig->step_list=pStepList;
	while(pStepList)
	{
		pStepList->pTrig=pTrig;
		pStepList=pStepList->pNext;
	}
	if(WN_SQL3FixInit(&sFix,pParse,iDb,"trigger",&pTrig->nameToken)&& WN_SQL3FixTriggerStep(&sFix,pTrig->step_list))goto triggerfinish_cleanup;
	if(!db->init.busy)
	{
		const VdbeOpList insertTrig[]={
{OP_NewRowid,0,0,0},{OP_String8,0,0,"trigger"},{OP_String8,0,0,0},{OP_String8,0,0,0},{OP_Integer,0,0,0},{OP_String8,0,0,"CREATE TRIGGER "},{OP_String8,0,0,0},{OP_Concat,0,0,0},{OP_MakeRecord,5,0,"aaada"},{OP_Insert,0,0,0},};
		Vdbe *v=WN_SQL3GetVdbe(pParse);
		if(v==0)goto triggerfinish_cleanup;
		WN_SQL3BeginWriteOperation(pParse,0,iDb);
		WN_SQL3OpenMasterTable(pParse,iDb);
		int addr=WN_SQL3VdbeAddOpList(v,ArraySize(insertTrig),insertTrig);
		WN_SQL3VdbeChangeP3(v,addr+2,pTrig->name,0);
		WN_SQL3VdbeChangeP3(v,addr+3,pTrig->table,0);
		WN_SQL3VdbeChangeP3(v,addr+6,(char*)pAll->z,pAll->n);
		WN_SQL3ChangeCookie(db,v,iDb);
		WN_SQL3VdbeAddOp(v,OP_Close,0,0);
		WN_SQL3VdbeOp3(v,OP_ParseSchema,iDb,0,WN_SQL3MPrintf("type='trigger' AND name='%q'",pTrig->name),P3_DYNAMIC);
	}
	if(db->init.busy)
	{
		Trigger *pDel=WN_SQL3HashInsert(&db->aDb[iDb].pSchema->trigHash,pTrig->name,strlen(pTrig->name),pTrig);
		if(pDel)goto triggerfinish_cleanup;
		int n=strlen(pTrig->table)+1;
		Table *pTab=WN_SQL3HashFind(&pTrig->pTabSchema->tblHash,pTrig->table,n);
		pTrig->pNext=pTab->pTrigger;
		pTab->pTrigger=pTrig;
		pTrig=0;
	}
triggerfinish_cleanup:
	WN_SQL3DeleteTrigger(pTrig);
	WN_SQL3DeleteTriggerStep(pStepList);
}
void WN_SQLPersistTriggerStep(TriggerStep *p)
{
	if(p->target.z)
	{
		p->target.z=(u8*)WN_SQLStrNDup((char*)p->target.z,p->target.n);
		p->target.dyn=1;
	}
	if(p->pSelect)
	{
		Select *pNew=WN_SQL3SelectDup(p->pSelect);
		WN_SQL3SelectDelete(p->pSelect);
		p->pSelect=pNew;
	}
	if(p->pWhere)
	{
		Expr *pNew=WN_SQL3ExprDup(p->pWhere);
		WN_SQL3ExprDelete(p->pWhere);
		p->pWhere=pNew;
	}
	if(p->pExprList)
	{
		ExprList *pNew=WN_SQL3ExprListDup(p->pExprList);
		WN_SQL3ExprListDelete(p->pExprList);
		p->pExprList=pNew;
	}
	if(p->pIdList)
	{
		IdList *pNew=WN_SQL3IdListDup(p->pIdList);
		WN_SQL3IdListDelete(p->pIdList);
		p->pIdList=pNew;
	}
}
TriggerStep *WN_SQL3TriggerSelectStep(Select *pSelect)
{
	TriggerStep *pTriggerStep=WN_SQL3Malloc(sizeof(TriggerStep));
	if(pTriggerStep==0)
	{
		WN_SQL3SelectDelete(pSelect);
		return 0;
	}
	pTriggerStep->op=TK_SELECT;
	pTriggerStep->pSelect=pSelect;
	pTriggerStep->orconf=OE_Default;
	WN_SQLPersistTriggerStep(pTriggerStep);
	return pTriggerStep;
}
TriggerStep *WN_SQL3TriggerInsertStep(Token *pTableName,IdList *pColumn,ExprList *pEList,Select *pSelect,int orconf)
{
	TriggerStep *pTriggerStep=WN_SQL3Malloc(sizeof(TriggerStep));
	if(pTriggerStep)
	{
		pTriggerStep->op=TK_INSERT;
		pTriggerStep->pSelect=pSelect;
		pTriggerStep->target=*pTableName;
		pTriggerStep->pIdList=pColumn;
		pTriggerStep->pExprList=pEList;
		pTriggerStep->orconf=orconf;
		WN_SQLPersistTriggerStep(pTriggerStep);
	}
	else
	{
		WN_SQL3IdListDelete(pColumn);
		WN_SQL3ExprListDelete(pEList);
		WN_SQL3SelectDup(pSelect);
	}
	return pTriggerStep;
}
TriggerStep *WN_SQL3TriggerUpdateStep(Token *pTableName,ExprList *pEList,Expr *pWhere,int orconf)
{
	TriggerStep *pTriggerStep=WN_SQL3Malloc(sizeof(TriggerStep));
	if(pTriggerStep==0)
	{
		WN_SQL3ExprListDelete(pEList);
		WN_SQL3ExprDelete(pWhere);
		return 0;
	}
	pTriggerStep->op=TK_UPDATE;
	pTriggerStep->target=*pTableName;
	pTriggerStep->pExprList=pEList;
	pTriggerStep->pWhere=pWhere;
	pTriggerStep->orconf=orconf;
	WN_SQLPersistTriggerStep(pTriggerStep);
	return pTriggerStep;
}
TriggerStep *WN_SQL3TriggerDeleteStep(Token *pTableName,Expr *pWhere)
{
	TriggerStep *pTriggerStep=WN_SQL3Malloc(sizeof(TriggerStep));
	if(pTriggerStep==0)
	{
		WN_SQL3ExprDelete(pWhere);
		return 0;
	}
	pTriggerStep->op=TK_DELETE;
	pTriggerStep->target=*pTableName;
	pTriggerStep->pWhere=pWhere;
	pTriggerStep->orconf=OE_Default;
	WN_SQLPersistTriggerStep(pTriggerStep);
	return pTriggerStep;
}
void WN_SQL3DeleteTrigger(Trigger *pTrigger)
{
	if(pTrigger==0)return;
	WN_SQL3DeleteTriggerStep(pTrigger->step_list);
	WN_SQL3FreeX(pTrigger->name);
	WN_SQL3FreeX(pTrigger->table);
	WN_SQL3ExprDelete(pTrigger->pWhen);
	WN_SQL3IdListDelete(pTrigger->pColumns);
	if(pTrigger->nameToken.dyn)WN_SQL3FreeX((char*)pTrigger->nameToken.z);
	WN_SQL3FreeX(pTrigger);
}
void WN_SQL3DropTrigger(Parse *pParse,SrcList *pName,int noErr)
{
	Trigger *pTrigger=0;
	WN_SQL3 *db=pParse->db;
	if(WN_SQL3MallocFailed())goto drop_trigger_cleanup;
	if(WN_SQL3ReadSchema(pParse))goto drop_trigger_cleanup;
	const char* zDb=pName->a[0].zDatabase,zName=pName->a[0].zName;
	int nName=strlen(zName),i;
	for(i=OMIT_TEMPDB;i<db->nDb;i++)
	{
		int j=(i<2)? i^1 :i;
		if(zDb && WN_SQL3StrICmp(db->aDb[j].zName,zDb))continue;
		pTrigger=WN_SQL3HashFind(&(db->aDb[j].pSchema->trigHash),zName,nName);
		if(pTrigger)break;
	}
	if(!pTrigger)
	{
		if(!noErr)WN_SQL3ErrorMsg(pParse,"no such trigger:%S",pName,0);
		goto drop_trigger_cleanup;
	}
	WN_SQL3DropTriggerPtr(pParse,pTrigger);
drop_trigger_cleanup:
	WN_SQL3SrcListDelete(pName);
}
Table *tableOfTrigger(Trigger *pTrigger)
{
	int n=strlen(pTrigger->table)+1;
	return WN_SQL3HashFind(&pTrigger->pTabSchema->tblHash,pTrigger->table,n);
}
void WN_SQL3DropTriggerPtr(Parse *pParse,Trigger *pTrigger)
{
	Vdbe *v;
	WN_SQL3 *db=pParse->db;
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pTrigger->pSchema);
	Table *pTable=tableOfTrigger(pTrigger);
#ifndef WN_SQL_OMIT_AUTHORIZATION
	int code=WN_SQL_DROP_TRIGGER;
	const char *zDb=db->aDb[iDb].zName;
	const char *zTab=SCHEMA_TABLE(iDb);
	if(iDb==1)code=WN_SQL_DROP_TEMP_TRIGGER;
	if(WN_SQL3AuthCheck(pParse,code,pTrigger->name,pTable->zName,zDb)|| WN_SQL3AuthCheck(pParse,WN_SQL_DELETE,zTab,0,zDb))return;
#endif
	if((v=WN_SQL3GetVdbe(pParse)))
	{
		const VdbeOpList dropTrigger[]={{OP_Rewind,0,ADDR(9),0},{OP_String8,0,0,0},{OP_Column,0,1,0},{OP_Ne,0,ADDR(8),0},{OP_String8,0,0,"trigger"},{OP_Column,0,0,0},{OP_Ne,0,ADDR(8),0},{OP_Delete,0,0,0},{OP_Next,0,ADDR(1),0},};
		WN_SQL3BeginWriteOperation(pParse,0,iDb);
		WN_SQL3OpenMasterTable(pParse,iDb);
		int base=WN_SQL3VdbeAddOpList(v,ArraySize(dropTrigger),dropTrigger);
		WN_SQL3VdbeChangeP3(v,base+1,pTrigger->name,0);
		WN_SQL3ChangeCookie(db,v,iDb);
		WN_SQL3VdbeAddOp(v,OP_Close,0,0);
		WN_SQL3VdbeOp3(v,OP_DropTrigger,iDb,0,pTrigger->name,0);
	}
}
void WN_SQL3UnlinkAndDeleteTrigger(WN_SQL3 *db,int iDb,const char *zName)
{
	int nName=strlen(zName);
	Trigger *pTrigger=WN_SQL3HashInsert(&(db->aDb[iDb].pSchema->trigHash),zName,nName,0);
	if(pTrigger)
	{
		Table *pTable=tableOfTrigger(pTrigger);
		if(pTable->pTrigger==pTrigger)
			pTable->pTrigger=pTrigger->pNext;
		else
		{	Trigger *cc=pTable->pTrigger;
			while(cc)
			{	if(cc->pNext==pTrigger)
				{	cc->pNext=cc->pNext->pNext;
					break;
				}
				cc=cc->pNext;
		}	}
		WN_SQL3DeleteTrigger(pTrigger);
		db->flags |=WN_SQL_InternChanges;
}	}
int checkColumnOverLap(IdList *pIdList,ExprList *pEList)
{
	if(!pIdList || !pEList)return 1;
	int e;
	for(e=0;e<pEList->nExpr;e++)if(WN_SQL3IdListIndex(pIdList,pEList->a[e].zName)>=0)return 1;
	return 0;
}
int WN_SQL3TriggersExist(Parse *pParse,Table *pTab,int op,ExprList *pChanges)
{
	Trigger *pTrigger=IsVirtual(pTab)? 0 :pTab->pTrigger;
	int mask=0;
	while(pTrigger)
	{
		if(pTrigger->op==op && checkColumnOverLap(pTrigger->pColumns,pChanges))mask |=pTrigger->tr_tm;
		pTrigger=pTrigger->pNext;
	}
	return mask;
}
SrcList *targetSrcList(Parse *pParse,TriggerStep *pStep)
{
	Token sDb;
	SrcList *pSrc;
	int iDb=WN_SQL3SchemaToIndex(pParse->db,pStep->pTrig->pSchema);
	if(iDb==0 || iDb>=2)
	{
		sDb.z=(u8*)pParse->db->aDb[iDb].zName;
		sDb.n=strlen((char*)sDb.z);
		pSrc=WN_SQL3SrcListAppend(0,&sDb,&pStep->target);
	}
	else
		pSrc=WN_SQL3SrcListAppend(0,&pStep->target,0);
	return pSrc;
}
int codeTriggerProgram(Parse *pParse,TriggerStep *pStepList,int orconfin)
{
	TriggerStep * pTriggerStep=pStepList;
	int orconf;
	Vdbe *v=pParse->pVdbe;
	WN_SQL3VdbeAddOp(v,OP_ContextPush,0,0);
	VdbeComment((v,"# begin trigger %s",pStepList->pTrig->name));
	while(pTriggerStep)
	{
		orconf=(orconfin==OE_Default)?pTriggerStep->orconf:orconfin;
		pParse->trigStack->orconf=orconf;
		switch(pTriggerStep->op)
		{
		case TK_SELECT:
			Select *ss=WN_SQL3SelectDup(pTriggerStep->pSelect);
			if(ss)
			{
				WN_SQL3SelectResolve(pParse,ss,0);
				WN_SQL3Select(pParse,ss,SRT_Discard,0,0,0,0,0);
				WN_SQL3SelectDelete(ss);
			}
			break;
		case TK_UPDATE:
			SrcList *pSrc=targetSrcList(pParse,pTriggerStep);
			WN_SQL3VdbeAddOp(v,OP_ResetCount,0,0);
			WN_SQL3Update(pParse,pSrc,WN_SQL3ExprListDup(pTriggerStep->pExprList),WN_SQL3ExprDup(pTriggerStep->pWhere),orconf);
			WN_SQL3VdbeAddOp(v,OP_ResetCount,1,0);
			break;
		case TK_INSERT:
			SrcList *pSrc=targetSrcList(pParse,pTriggerStep);
			WN_SQL3VdbeAddOp(v,OP_ResetCount,0,0);
			WN_SQL3Insert(pParse,pSrc,WN_SQL3ExprListDup(pTriggerStep->pExprList),WN_SQL3SelectDup(pTriggerStep->pSelect),WN_SQL3IdListDup(pTriggerStep->pIdList),orconf);
			WN_SQL3VdbeAddOp(v,OP_ResetCount,1,0);
			break;
		case TK_DELETE:
			SrcList *pSrc=targetSrcList(pParse,pTriggerStep);
			WN_SQL3VdbeAddOp(v,OP_ResetCount,0,0);
			WN_SQL3DeleteFrom(pParse,pSrc,WN_SQL3ExprDup(pTriggerStep->pWhere));
			WN_SQL3VdbeAddOp(v,OP_ResetCount,1,0);
			break;
		}
		pTriggerStep=pTriggerStep->pNext;
	}
	WN_SQL3VdbeAddOp(v,OP_ContextPop,0,0);
	VdbeComment((v,"# end trigger %s",pStepList->pTrig->name));
	return 0;
}
int WN_SQL3CodeRowTrigger(Parse *pParse,int op,ExprList *pChanges,int tr_tm,Table *pTab,int newIdx,int oldIdx,int orconf,int ignoreJump)
{
	Trigger *p;
	TriggerStack trigStackEntry;
	for(p=pTab->pTrigger;p;p=p->pNext)
	{
		int fire_this=0;
		if(p->op==op && p->tr_tm==tr_tm && (p->pSchema==p->pTabSchema || p->pSchema==pParse->db->aDb[1].pSchema)&& (op!=TK_UPDATE||!p->pColumns||checkColumnOverLap(p->pColumns,pChanges)))
		{
			TriggerStack *pS;
			for(pS=pParse->trigStack;pS && p!=pS->pTrigger;pS=pS->pNext);
			if(!pS)fire_this=1;
#if 0
			else
			{
				WN_SQL3ErrorMsg(pParse,"recursive triggers not supported(%s)",p->name);
				return WN_SQL_ERROR;
			}
#endif
		}
		if(fire_this)
		{
			AuthContext sContext;
			NameContext sNC;
			memset(&sNC,0,sizeof(sNC));
			sNC.pParse=pParse;
			trigStackEntry.pTrigger=p;
			trigStackEntry.newIdx=newIdx;
			trigStackEntry.oldIdx=oldIdx;
			trigStackEntry.pTab=pTab;
			trigStackEntry.pNext=pParse->trigStack;
			trigStackEntry.ignoreJump=ignoreJump;
			pParse->trigStack=&trigStackEntry;
			WN_SQL3AuthContextPush(pParse,&sContext,p->name);
			int endTrigger=WN_SQL3VdbeMakeLabel(pParse->pVdbe);
			Expr *whenExpr=WN_SQL3ExprDup(p->pWhen);
			if(WN_SQL3ExprResolveNames(&sNC,whenExpr))
			{
				pParse->trigStack=trigStackEntry.pNext;
				WN_SQL3ExprDelete(whenExpr);
				return 1;
			}
			WN_SQL3ExprIfFalse(pParse,whenExpr,endTrigger,1);
			WN_SQL3ExprDelete(whenExpr);
			codeTriggerProgram(pParse,p->step_list,orconf);
			pParse->trigStack=trigStackEntry.pNext;
			WN_SQL3AuthContextPop(&sContext);
			WN_SQL3VdbeResolveLabel(pParse->pVdbe,endTrigger);
		}
	}
	return 0;
}
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
void updateVirtualTable(Parse *pParse,SrcList *pSrc,Table *pTab,ExprList *pChanges,Expr *pRowidExpr,int *aXRef,Expr *pWhere);
#endif
void WN_SQL3ColumnDefault(Vdbe *v,Table *pTab,int i)
{	if(pTab && !pTab->pSelect)
	{
		WN_SQL3_value *pValue;
		u8 enc=ENC(WN_SQL3VdbeDb(v));
		Column *pCol=&pTab->aCol[i];
		WN_SQL3ValueFromExpr(pCol->pDflt,enc,pCol->affinity,&pValue);
		if(pValue)
			WN_SQL3VdbeChangeP3(v,-1,(const char *)pValue,P3_MEM);
		else
			VdbeComment((v,"# %s.%s",pTab->zName,pCol->zName));
	}
}
void WN_SQL3Update(Parse *pParse,SrcList *pTabList,ExprList *pChanges,Expr *pWhere,int onError)
{
	if(pParse->nErr || WN_SQL3MallocFailed())goto update_cleanup;
	int i,j,addr=0,nIdx,nIdxTotal,iCur,*aXRef=0,chngRowid,iDb,memCnt=0;
	Table *pTab=WN_SQL3SrcListLookup(pParse,pTabList);
	if(pTab==0)goto update_cleanup;
	WhereInfo *pWInfo;
	Vdbe *v;
	Index *pIdx;
	WN_SQL3 *db=pParse->db;
	Index **apIdx=0;
	char *aIdxUsed=0;
	Expr *pRowidExpr=0;
	int openAll=0;
	AuthContext sContext;
	NameContext sNC;
#ifndef WN_SQL_OMIT_TRIGGER
	int isView,triggers_exist=0;
#endif
	int newIdx=-1,oldIdx=-1;
	sContext.pParse=0;
	iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
#ifndef WN_SQL_OMIT_TRIGGER
	triggers_exist=WN_SQL3TriggersExist(pParse,pTab,TK_UPDATE,pChanges);
	isView=pTab->pSelect!=0;
#else
# define triggers_exist 0
# define isView 0
#endif
#ifdef WN_SQL_OMIT_VIEW
# undef isView
# define isView 0
#endif
	if(WN_SQL3IsReadOnly(pParse,pTab,triggers_exist))goto update_cleanup;
	if(WN_SQL3ViewGetColumnNames(pParse,pTab))goto update_cleanup;
	aXRef=WN_SQLMallocRaw(sizeof(int)* pTab->nCol);
	if(aXRef==0)goto update_cleanup;
	for(i=0;i<pTab->nCol;i++)aXRef[i]=-1;
	if(triggers_exist)
	{
		newIdx=pParse->nTab++;
		oldIdx=pParse->nTab++;
	}
	pTabList->a[0].iCursor=iCur=pParse->nTab++;
	for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)pParse->nTab++;
	memset(&sNC,0,sizeof(sNC));
	sNC.pParse=pParse;
	sNC.pSrcList=pTabList;
	chngRowid=0;
	for(i=0;i<pChanges->nExpr;i++)
	{
		if(WN_SQL3ExprResolveNames(&sNC,pChanges->a[i].pExpr))goto update_cleanup;
		for(j=0;j<pTab->nCol;j++)
			if(WN_SQL3StrICmp(pTab->aCol[j].zName,pChanges->a[i].zName)==0)
			{
				if(j==pTab->iPKey)
				{
					chngRowid=1;
					pRowidExpr=pChanges->a[i].pExpr;
				}
				aXRef[j]=i;
				break;
			}
		if(j>=pTab->nCol)
			if(WN_SQL3IsRowid(pChanges->a[i].zName))
			{
				chngRowid=1;
				pRowidExpr=pChanges->a[i].pExpr;
			}
			else
			{
				WN_SQL3ErrorMsg(pParse,"no such column:%s",pChanges->a[i].zName);
				goto update_cleanup;
			}
#ifndef WN_SQL_OMIT_AUTHORIZATION
		int rc==WN_SQL3AuthCheck(pParse,WN_SQL_UPDATE,pTab->zName,pTab->aCol[j].		zName,db->aDb[iDb].zName);
		if(rc==WN_SQL_DENY)
			goto update_cleanup;
		else
			if(rc==WN_SQL_IGNORE)aXRef[j]=-1;
#endif
	}
	for(nIdx=nIdxTotal=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,nIdxTotal++)
	{
		if(chngRowid)
			i=0;
		else
			for(i=0;i<pIdx->nColumn;i++)if(aXRef[pIdx->aiColumn[i]]>=0)break;
		if(i<pIdx->nColumn)nIdx++;
	}
	if(nIdxTotal>0)
	{
		apIdx=WN_SQLMallocRaw(sizeof(Index*)* nIdx+nIdxTotal);
		if(apIdx==0)goto update_cleanup;
		aIdxUsed=(char*)&apIdx[nIdx];
	}
	for(nIdx=j=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,j++)
	{
		if(chngRowid)
			i=0;
		else
			for(i=0;i<pIdx->nColumn;i++)if(aXRef[pIdx->aiColumn[i]]>=0)break;
		if(i<pIdx->nColumn)
		{
			apIdx[nIdx++]=pIdx;
			aIdxUsed[j]=1;
		}
		else
			aIdxUsed[j]=0;
	}
	v=WN_SQL3GetVdbe(pParse);
	if(v==0)goto update_cleanup;
	if(pParse->nested==0)WN_SQL3VdbeCountChanges(v);
	WN_SQL3BeginWriteOperation(pParse,1,iDb);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	if(IsVirtual(pTab))
	{
		updateVirtualTable(pParse,pTabList,pTab,pChanges,pRowidExpr,aXRef,pWhere);
		pWhere=0;
		pTabList=0;
		goto update_cleanup;
	}
#endif
	if(WN_SQL3ExprResolveNames(&sNC,pWhere))goto update_cleanup;
	if(isView)WN_SQL3AuthContextPush(pParse,&sContext,pTab->zName);
	if(isView)
	{
		Select *pView;
		pView=WN_SQL3SelectDup(pTab->pSelect);
		WN_SQL3Select(pParse,pView,SRT_EphemTab,iCur,0,0,0,0);
		WN_SQL3SelectDelete(pView);
	}
	pWInfo=WN_SQL3WhereBegin(pParse,pTabList,pWhere,0);
	if(pWInfo==0)goto update_cleanup;
	WN_SQL3VdbeAddOp(v,IsVirtual(pTab)? OP_VRowid :OP_Rowid,iCur,0);
	WN_SQL3VdbeAddOp(v,OP_FifoWrite,0,0);
	WN_SQL3WhereEnd(pWInfo);
	if(db->flags & WN_SQL_CountRows && !pParse->trigStack)
	{
		memCnt=pParse->nMem++;
		WN_SQL3VdbeAddOp(v,OP_MemInt,0,memCnt);
	}
	if(triggers_exist)
	{
		WN_SQL3VdbeAddOp(v,OP_OpenPseudo,oldIdx,0);
		WN_SQL3VdbeAddOp(v,OP_SetNumColumns,oldIdx,pTab->nCol);
		WN_SQL3VdbeAddOp(v,OP_OpenPseudo,newIdx,0);
		WN_SQL3VdbeAddOp(v,OP_SetNumColumns,newIdx,pTab->nCol);
		addr=WN_SQL3VdbeAddOp(v,OP_FifoRead,0,0);
		if(!isView)
		{
			WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
			WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
			WN_SQL3OpenTable(pParse,iCur,iDb,pTab,OP_OpenRead);
		}
		WN_SQL3VdbeAddOp(v,OP_MoveGe,iCur,0);
		WN_SQL3VdbeAddOp(v,OP_Rowid,iCur,0);
		WN_SQL3VdbeAddOp(v,OP_RowData,iCur,0);
		WN_SQL3VdbeAddOp(v,OP_Insert,oldIdx,0);
		if(chngRowid)
			WN_SQL3ExprCodeAndCache(pParse,pRowidExpr);
		else
			WN_SQL3VdbeAddOp(v,OP_Rowid,iCur,0);
		for(i=0;i<pTab->nCol;i++)
		{
			if(i==pTab->iPKey)
			{
				WN_SQL3VdbeAddOp(v,OP_Null,0,0);
				continue;
			}
			j=aXRef[i];
			if(j<0)
			{
				WN_SQL3VdbeAddOp(v,OP_Column,iCur,i);
				WN_SQL3ColumnDefault(v,pTab,i);
			}
			else
				WN_SQL3ExprCodeAndCache(pParse,pChanges->a[j].pExpr);
		}
		WN_SQL3VdbeAddOp(v,OP_MakeRecord,pTab->nCol,0);
		if(!isView)WN_SQL3TableAffinityStr(v,pTab);
		if(pParse->nErr)goto update_cleanup;
		WN_SQL3VdbeAddOp(v,OP_Insert,newIdx,0);
		if(!isView)WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
		if(WN_SQL3CodeRowTrigger(pParse,TK_UPDATE,pChanges,TRIGGER_BEFORE,pTab,newIdx,oldIdx,onError,addr))goto update_cleanup;
	}
	if(!isView && !IsVirtual(pTab))
	{
		WN_SQL3OpenTable(pParse,iCur,iDb,pTab,OP_OpenWrite);
		if(onError==OE_Replace)
			openAll=1;
		else
		{
			openAll=0;
			for(pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext)
				if(pIdx->onError==OE_Replace)
				{
					openAll=1;
					break;
				}
		}
		for(i=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,i++)
			if(openAll || aIdxUsed[i])
			{
				KeyInfo *pKey=WN_SQL3IndexKeyinfo(pParse,pIdx);
				WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
				WN_SQL3VdbeOp3(v,OP_OpenWrite,iCur+i+1,pIdx->tnum,(char*)pKey,P3_KEYINFO_HANDOFF);
			}
		if(!triggers_exist)
		{
			addr=WN_SQL3VdbeAddOp(v,OP_FifoRead,0,0);
			WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
		}
		WN_SQL3VdbeAddOp(v,OP_NotExists,iCur,addr);
		if(chngRowid)
		{
			WN_SQL3ExprCode(pParse,pRowidExpr);
			WN_SQL3VdbeAddOp(v,OP_MustBeInt,0,0);
		}
		for(i=0;i<pTab->nCol;i++)
		{
			if(i==pTab->iPKey)
			{
				WN_SQL3VdbeAddOp(v,OP_Null,0,0);
				continue;
			}
			j=aXRef[i];
			if(j<0)
			{
				WN_SQL3VdbeAddOp(v,OP_Column,iCur,i);
				WN_SQL3ColumnDefault(v,pTab,i);
			}
			else
				WN_SQL3ExprCode(pParse,pChanges->a[j].pExpr);
		}
		WN_SQL3GenerateConstraintChecks(pParse,pTab,iCur,aIdxUsed,chngRowid,1,onError,addr);
		WN_SQL3GenerateRowIndexDelete(v,pTab,iCur,aIdxUsed);
		if(chngRowid)WN_SQL3VdbeAddOp(v,OP_Delete,iCur,0);
		WN_SQL3CompleteInsertion(pParse,pTab,iCur,aIdxUsed,chngRowid,1,-1,0);
	}
	if(db->flags & WN_SQL_CountRows && !pParse->trigStack)WN_SQL3VdbeAddOp(v,OP_MemIncr,1,memCnt);
	if(triggers_exist)
	{
		if(!isView)
		{
			for(i=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,i++)
				if(openAll || aIdxUsed[i])WN_SQL3VdbeAddOp(v,OP_Close,iCur+i+1,0);
			WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
		}
		if(WN_SQL3CodeRowTrigger(pParse,TK_UPDATE,pChanges,TRIGGER_AFTER,pTab,newIdx,oldIdx,onError,addr))goto update_cleanup;
	}
	WN_SQL3VdbeAddOp(v,OP_Goto,0,addr);
	WN_SQL3VdbeJumpHere(v,addr);
	if(!triggers_exist)
	{
		for(i=0,pIdx=pTab->pIndex;pIdx;pIdx=pIdx->pNext,i++)
			if(openAll || aIdxUsed[i])WN_SQL3VdbeAddOp(v,OP_Close,iCur+i+1,0);
		WN_SQL3VdbeAddOp(v,OP_Close,iCur,0);
	}
	else
	{
		WN_SQL3VdbeAddOp(v,OP_Close,newIdx,0);
		WN_SQL3VdbeAddOp(v,OP_Close,oldIdx,0);
	}
	if(db->flags & WN_SQL_CountRows && !pParse->trigStack && pParse->nested==0)
	{
		WN_SQL3VdbeAddOp(v,OP_MemLoad,memCnt,0);
		WN_SQL3VdbeAddOp(v,OP_Callback,1,0);
		WN_SQL3VdbeSetNumCols(v,1);
		WN_SQL3VdbeSetColName(v,0,COLNAME_NAME,"rows updated",P3_STATIC);
	}
update_cleanup:
	WN_SQL3AuthContextPop(&sContext);
	WN_SQL3FreeX(apIdx);
	WN_SQL3FreeX(aXRef);
	WN_SQL3SrcListDelete(pTabList);
	WN_SQL3ExprListDelete(pChanges);
	WN_SQL3ExprDelete(pWhere);
	return;
}
#ifndef WN_SQL_OMIT_VIRTUALTABLE
void updateVirtualTable(Parse *pParse,SrcList *pSrc,Table *pTab,ExprList *pChanges,Expr *pRowid,int *aXRef,Expr *pWhere)
{
	Vdbe *v=pParse->pVdbe;
	Expr *pExpr;
	int i;
	ExprList *pEList=WN_SQL3ExprListAppend(0,WN_SQL3CreateIdExpr("_rowid_"),0);
	if(pRowid)pEList=WN_SQL3ExprListAppend(pEList,WN_SQL3ExprDup(pRowid),0);
	for(i=0;i<pTab->nCol;i++)
	{
		if(aXRef[i]>=0)
			pExpr=WN_SQL3ExprDup(pChanges->a[aXRef[i]].pExpr);
		else
			pExpr=WN_SQL3CreateIdExpr(pTab->aCol[i].zName);
		pEList=WN_SQL3ExprListAppend(pEList,pExpr,0);
	}
	Select *pSelect=WN_SQL3SelectNew(pEList,pSrc,pWhere,0,0,0,0,0,0);
	int ephemTab=pParse->nTab++;
	WN_SQL3VdbeAddOp(v,OP_OpenEphemeral,ephemTab,pTab->nCol+1+(pRowid!=0));
	WN_SQL3Select(pParse,pSelect,SRT_Table,ephemTab,0,0,0,0);
	WN_SQL3VdbeAddOp(v,OP_Rewind,ephemTab,0);
	int addr=WN_SQL3VdbeCurrentAddr(v);
	WN_SQL3VdbeAddOp(v,OP_Column,ephemTab,0);
	if(pRowid)
		WN_SQL3VdbeAddOp(v,OP_Column,ephemTab,1);
	else
		WN_SQL3VdbeAddOp(v,OP_Dup,0,0);
	for(i=0;i<pTab->nCol;i++)
		WN_SQL3VdbeAddOp(v,OP_Column,ephemTab,i+1+(pRowid!=0));
	pParse->pVirtualLock=pTab;
	WN_SQL3VdbeOp3(v,OP_VUpdate,0,pTab->nCol+2,(const char*)pTab->pVtab,P3_VTAB);
	WN_SQL3VdbeAddOp(v,OP_Next,ephemTab,addr);
	WN_SQL3VdbeJumpHere(v,addr-1);
	WN_SQL3VdbeAddOp(v,OP_Close,ephemTab,0);
	WN_SQL3SelectDelete(pSelect);
}
#endif
#if !defined(WN_SQL_OMIT_VACUUM)&& !defined(WN_SQL_OMIT_ATTACH)
int execSql(WN_SQL3 *db,const char *zSql)
{
	WN_SQL3_stmt *pStmt;
	if(WN_SQL3_prepare(db,zSql,-1,&pStmt,0))return WN_SQL3_errcode(db);
	while(WN_SQL_ROW==WN_SQL3_step(pStmt));
	return WN_SQL3_finalize(pStmt);
}
int execExecSql(WN_SQL3 *db,const char *zSql)
{
	WN_SQL3_stmt *pStmt;
	int rc=WN_SQL3_prepare(db,zSql,-1,&pStmt,0);
	if(rc)return rc;
	while(WN_SQL_ROW==WN_SQL3_step(pStmt))
		if(rc=execSql(db,(char*)WN_SQL3_column_text(pStmt,0)))
		{
			WN_SQL3_finalize(pStmt);
			return rc;
		}
	return WN_SQL3_finalize(pStmt);
}
void WN_SQL3Vacuum(Parse *pParse)
{
	Vdbe *v=WN_SQL3GetVdbe(pParse);
	if(v)WN_SQL3VdbeAddOp(v,OP_Vacuum,0,0);
	return;
}
int WN_SQL3RunVacuum(char **pzErrMsg,WN_SQL3 *db)
{
	int rc=0;
	Btree *pMain,*pTemp;
	char *zSql=0;
	Db *pDb=0;
	int saved_flags=db->flags;
	db->flags |=WN_SQL_WriteSchema | WN_SQL_IgnoreChecks;
	if(!db->autoCommit)
	{
		WN_SQL3SetString(pzErrMsg,"cannot VACUUM from within a transaction",(char*)0);
		rc=WN_SQL_ERROR;
		goto end_of_vacuum;
	}
	pMain=db->aDb[0].pBt;
	zSql="ATTACH '' AS vacuum_db;";
	if(rc=execSql(db,zSql))goto end_of_vacuum;
	pDb=&db->aDb[db->nDb-1];
	pTemp=db->aDb[db->nDb-1].pBt;
	WN_SQL3BtreeSetPageSize(pTemp,WN_SQL3BtreeGetPageSize(pMain),WN_SQL3BtreeGetReserve(pMain));
	if(WN_SQL3MallocFailed())
	{
		rc=WN_SQL_NOMEM;
		goto end_of_vacuum;
	}
	if(rc=execSql(db,"PRAGMA vacuum_db.synchronous=OFF"))goto end_of_vacuum;
#ifndef WN_SQL_OMIT_AUTOVACUUM
	WN_SQL3BtreeSetAutoVacuum(pTemp,WN_SQL3BtreeGetAutoVacuum(pMain));
#endif
	if(rc=execSql(db,"BEGIN EXCLUSIVE;"))goto end_of_vacuum;
	rc=execExecSql(db,"SELECT 'CREATE TABLE vacuum_db.' || substr(sql,14,100000000)"
" FROM WN_SQL_master WHERE type='table' AND name!='WN_SQL_sequence'"
" AND rootpage>0"
);
	if(rc)goto end_of_vacuum;
	rc=execExecSql(db,"SELECT 'CREATE INDEX vacuum_db.' || substr(sql,14,100000000)"
" FROM WN_SQL_master WHERE sql LIKE 'CREATE INDEX %' ");
	if(rc)goto end_of_vacuum;
	rc=execExecSql(db,"SELECT 'CREATE UNIQUE INDEX vacuum_db.' || substr(sql,21,100000000)"
" FROM WN_SQL_master WHERE sql LIKE 'CREATE UNIQUE INDEX %'");
	if(rc)goto end_of_vacuum;
	rc=execExecSql(db,"SELECT 'INSERT INTO vacuum_db.' || quote(name)"
"|| ' SELECT * FROM ' || quote(name)|| ';'"
"FROM WN_SQL_master "
"WHERE type='table' AND name!='WN_SQL_sequence' "
" AND rootpage>0");
	if(rc)goto end_of_vacuum;
	rc=execExecSql(db,"SELECT 'DELETE FROM vacuum_db.' || quote(name)|| ';' "
"FROM vacuum_db.WN_SQL_master WHERE name='WN_SQL_sequence' ");
	if(rc)goto end_of_vacuum;
	rc=execExecSql(db,"SELECT 'INSERT INTO vacuum_db.' || quote(name)"
"|| ' SELECT * FROM ' || quote(name)|| ';' "
"FROM vacuum_db.WN_SQL_master WHERE name=='WN_SQL_sequence';");
	if(rc)goto end_of_vacuum;
	rc=execSql(db,"INSERT INTO vacuum_db.WN_SQL_master "
" SELECT type,name,tbl_name,rootpage,sql"
" FROM WN_SQL_master"
" WHERE type='view' OR type='trigger'"
" OR(type='table' AND rootpage=0)");
	if(rc)goto end_of_vacuum;
	if(rc==0)
	{
		u32 meta;
		int i;
		const unsigned char aCopy[]={1,1,3,0,5,0,6,0,};
		for(i=0;i<sizeof(aCopy)/sizeof(aCopy[0]);i+=2)
		{
			rc=WN_SQL3BtreeGetMeta(pMain,aCopy[i],&meta);
			if(rc)goto end_of_vacuum;
			rc=WN_SQL3BtreeUpdateMeta(pTemp,aCopy[i],meta+aCopy[i+1]);
			if(rc)goto end_of_vacuum;
		}
		rc=WN_SQL3BtreeCopyFile(pMain,pTemp);
		if(rc)goto end_of_vacuum;
		rc=WN_SQL3BtreeCommit(pTemp);
		if(rc)goto end_of_vacuum;
		rc=WN_SQL3BtreeCommit(pMain);
	}
end_of_vacuum:
	db->flags=saved_flags;
	db->autoCommit=1;
	if(pDb)
	{
		WN_SQL3MallocDisallow();
		WN_SQL3BtreeClose(pDb->pBt);
		WN_SQL3MallocAllow();
		pDb->pBt=0;
		pDb->pSchema=0;
	}
	WN_SQL3ResetInternalSchema(db,0);
	return rc;
}
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
int createModule(WN_SQL3 *db,const char *zName,const WN_SQL3_module *pModule,void *pAux,void(*xDestroy)(void *))
{
	int nName=strlen(zName);
	Module *pMod=(Module *)WN_SQLMallocRaw(sizeof(Module)+nName+1);
	if(pMod)
	{
		char *zCopy=(char *)(&pMod[1]);
		memcpy(zCopy,zName,nName+1);
		pMod->zName=zCopy;
		pMod->pModule=pModule;
		pMod->pAux=pAux;
		pMod->xDestroy=xDestroy;
		pMod=(Module *)WN_SQL3HashInsert(&db->aModule,zCopy,nName,(void*)pMod);
		if(pMod && pMod->xDestroy)pMod->xDestroy(pMod->pAux);
		WN_SQL3FreeX(pMod);
		WN_SQL3ResetInternalSchema(db,0);
	}
	return WN_SQL3ApiExit(db,0);
}
int WN_SQL3_create_module(WN_SQL3 *db,const char *zName,const WN_SQL3_module *pModule,void *pAux)
{
	return createModule(db,zName,pModule,pAux,0);
}
int WN_SQL3_create_module_v2(WN_SQL3 *db,const char *zName,const WN_SQL3_module *pModule,void *pAux,void(*xDestroy)(void *))
{
	return createModule(db,zName,pModule,pAux,xDestroy);
}
void WN_SQL3VtabLock(WN_SQL3_vtab *pVtab)
{
	pVtab->nRef++;
}
void WN_SQL3VtabUnlock(WN_SQL3 *db,WN_SQL3_vtab *pVtab)
{
	pVtab->nRef--;
	if(pVtab->nRef==0)
	{
		if(db->magic==WN_SQL_MAGIC_BUSY)
		{
			WN_SQL3SafetyOff(db);
			pVtab->pModule->xDisconnect(pVtab);
			WN_SQL3SafetyOn(db);
		}
		else
			pVtab->pModule->xDisconnect(pVtab);
	}
}
void WN_SQL3VtabClear(Table *p)
{
	WN_SQL3_vtab *pVtab=p->pVtab;
	if(pVtab)
	{
		WN_SQL3VtabUnlock(p->pSchema->db,pVtab);
		p->pVtab=0;
	}
	if(p->azModuleArg)
	{
		int i;
		for(i=0;i<p->nModuleArg;i++) WN_SQL3FreeX(p->azModuleArg[i]);
		WN_SQL3FreeX(p->azModuleArg);
	}
}
void addModuleArgument(Table *pTable,char *zArg)
{
	int i=pTable->nModuleArg++,nBytes=sizeof(char *)*(1+pTable->nModuleArg);
	char **azModuleArg=WN_SQLRealloc(pTable->azModuleArg,nBytes);
	if(azModuleArg==0)
	{
		int j;
		for(j=0;j<i;j++)WN_SQL3FreeX(pTable->azModuleArg[j]);
		WN_SQL3FreeX(zArg);
		WN_SQL3FreeX(pTable->azModuleArg);
		pTable->nModuleArg=0;
	}
	else
	{
		azModuleArg[i]=zArg;
		azModuleArg[i+1]=0;
	}
	pTable->azModuleArg=azModuleArg;
}
void WN_SQL3VtabBeginParse(Parse *pParse,Token *pName1,Token *pName2,Token *pModuleName)
{
	int iDb;
	Table *pTable;
#ifndef WN_SQL_OMIT_SHARED_CACHE
	if(WN_SQL3ThreadDataReadOnly()->useSharedData)
	{
		WN_SQL3ErrorMsg(pParse,"Cannot use virtual tables in shared-cache mode");
		return;
	}
#endif
	WN_SQL3StartTable(pParse,pName1,pName2,0,0,1,0);
	pTable=pParse->pNewTable;
	if(pTable==0 || pParse->nErr)return;
	iDb=WN_SQL3SchemaToIndex(pParse->db,pTable->pSchema);
	pTable->isVirtual=1;
	pTable->nModuleArg=0;
	addModuleArgument(pTable,WN_SQL3NameFromToken(pModuleName));
	addModuleArgument(pTable,WN_SQL3StrDup(pParse->db->aDb[iDb].zName));
	addModuleArgument(pTable,WN_SQL3StrDup(pTable->zName));
	pParse->sNameToken.n=pModuleName->z+pModuleName->n-pName1->z;
#ifndef WN_SQL_OMIT_AUTHORIZATION
	if(pTable->azModuleArg)	WN_SQL3AuthCheck(pParse,WN_SQL_CREATE_VTABLE,pTable->zName,pTable->azModuleArg[0],pParse->db->aDb[iDb].zName);
#endif
}
void addArgumentToVtab(Parse *pParse)
{
	if(pParse->sArg.z && pParse->pNewTable)
	{
		const char *z=(const char*)pParse->sArg.z;
		int n=pParse->sArg.n;
		addModuleArgument(pParse->pNewTable,WN_SQLStrNDup(z,n));
	}
}
void WN_SQL3VtabFinishParse(Parse *pParse,Token *pEnd)
{
	addArgumentToVtab(pParse);
	pParse->sArg.z=0;
	Table *pTab=pParse->pNewTable;
	if(pTab==0)return;
	if(pTab->nModuleArg<1)return;
	WN_SQL3 *db=pParse->db;
	char *zModule=pTab->azModuleArg[0];
	Module *pMod=(Module *)WN_SQL3HashFind(&db->aModule,zModule,strlen(zModule));
	pTab->pMod=pMod;
	if(!db->init.busy)
	{
		if(pEnd)pParse->sNameToken.n=pEnd->z-pParse->sNameToken.z+pEnd->n;
		char*zStmt=WN_SQL3MPrintf("CREATE VIRTUAL TABLE %T",&pParse->sNameToken);
		int iDb=WN_SQL3SchemaToIndex(db,pTab->pSchema);
		WN_SQL3NestedParse(pParse,"UPDATE %Q.%s "
"SET type='table',name=%Q,tbl_name=%Q,rootpage=0,sql=%Q "
"WHERE rowid=#1",db->aDb[iDb].zName,SCHEMA_TABLE(iDb),pTab->zName,pTab->zName,zStmt);
		WN_SQL3FreeX(zStmt);
		Vdbe *v=WN_SQL3GetVdbe(pParse);
		WN_SQL3ChangeCookie(db,v,iDb);
		WN_SQL3VdbeAddOp(v,OP_Expire,0,0);
		char* zWhere=WN_SQL3MPrintf("name='%q'",pTab->zName);
		WN_SQL3VdbeOp3(v,OP_ParseSchema,iDb,1,zWhere,P3_DYNAMIC);
		WN_SQL3VdbeOp3(v,OP_VCreate,iDb,0,pTab->zName,strlen(pTab->zName)+1);
	}
	else
	{
		Schema *pSchema=pTab->pSchema;
		const char *zName=pTab->zName;
		int nName=strlen(zName)+1;
		Table *pOld=WN_SQL3HashInsert(&pSchema->tblHash,zName,nName,pTab);
		if(pOld)return;
		pSchema->db=pParse->db;
		pParse->pNewTable=0;
	}
}
void WN_SQL3VtabArgInit(Parse *pParse)
{
	addArgumentToVtab(pParse);
	pParse->sArg.z=0;
	pParse->sArg.n=0;
}
void WN_SQL3VtabArgExtend(Parse *pParse,Token *p)
{
	Token *pArg=&pParse->sArg;
	if(pArg->z==0)
	{
		pArg->z=p->z;
		pArg->n=p->n;
	}
	else
		pArg->n=(p->z+p->n-pArg->z);
}
int vtabCallConstructor(WN_SQL3 *db,Table *pTab,Module *pMod,int(*xConstruct)(WN_SQL3*,void*,int,const char*const*,WN_SQL3_vtab**,char**),char **pzErr)
{
	int rc,rc2;
	const char *const*azArg=(const char *const*)pTab->azModuleArg;
	int nArg=pTab->nModuleArg;
	char *zErr=0,*zModuleName=WN_SQL3MPrintf("%s",pTab->zName);
	if(!zModuleName)return WN_SQL_NOMEM;
	db->pVTab=pTab;
	rc=WN_SQL3SafetyOff(db);
	rc=xConstruct(db,pMod->pAux,nArg,azArg,&pTab->pVtab,&zErr);
	rc2=WN_SQL3SafetyOn(db);
	WN_SQL3_vtab *pVtab=pTab->pVtab;
	if(rc==0 && pVtab)
	{
		pVtab->pModule=pMod->pModule;
		pVtab->nRef=1;
	}
	if(rc)
		if(zErr==0)
			*pzErr=WN_SQL3MPrintf("vtable constructor failed:%s",zModuleName);
		else
		{
			*pzErr=WN_SQL3MPrintf("%s",zErr);
			WN_SQL3_free(zErr);
		}
	else
		if(db->pVTab)
		{
			const char *zFormat="vtable constructor did not declare schema:%s";
			*pzErr=WN_SQL3MPrintf(zFormat,pTab->zName);
			rc=WN_SQL_ERROR;
		}
		if(rc==0)rc=rc2;
		db->pVTab=0;
		WN_SQL3FreeX(zModuleName);
		if(rc==0)
		{
			int iCol;
			for(iCol=0;iCol<pTab->nCol;iCol++)
			{
				char *zType=pTab->aCol[iCol].zType;
				int nType,i=0;
				if(!zType)continue;
				nType=strlen(zType);
				if(WN_SQL3StrNICmp("hidden",zType,6)||(zType[6] && zType[6]!=' '))
				{
					for(i=0;i<nType;i++)
						if((0==WN_SQL3StrNICmp(" hidden",&zType[i],7))&&(zType[i+7]=='\0' || zType[i+7]==' '))
						{
							i++;
							break;
						}
				}
				if(i<nType)
				{
					int j;
					int nDel=6+(zType[i+6] ? 1 :0);
					for(j=i;(j+nDel)<=nType;j++)zType[j]=zType[j+nDel];
					if(zType[i]=='\0' && i>0)zType[i-1]='\0';
					pTab->aCol[iCol].isHidden=1;
		}	}	}
	return rc;
}
int WN_SQL3VtabCallConnect(Parse *pParse,Table *pTab)
{
	if(!pTab || !pTab->isVirtual || pTab->pVtab)return 0;
	Module *pMod=pTab->pMod;
	int rc=0;
	if(!pMod)
	{
		const char *zModule=pTab->azModuleArg[0];
		WN_SQL3ErrorMsg(pParse,"no such module:%s",zModule);
		rc=WN_SQL_ERROR;
	}
	else
	{
		char *zErr=0;
		WN_SQL3 *db=pParse->db;
		if(rc=vtabCallConstructor(db,pTab,pMod,pMod->pModule->xConnect,&zErr))WN_SQL3ErrorMsg(pParse,"%s",zErr);
		WN_SQL3FreeX(zErr);
	}
	return rc;
}
int addToVTrans(WN_SQL3 *db,WN_SQL3_vtab *pVtab)
{
	const int ARRAY_INCR=5;
	if((db->nVTrans%ARRAY_INCR)==0)
	{
		int nBytes=sizeof(WN_SQL3_vtab *)*(db->nVTrans+ARRAY_INCR);
		WN_SQL3_vtab **aVTrans=WN_SQLRealloc((void *)db->aVTrans,nBytes);
		if(!aVTrans)return WN_SQL_NOMEM;
		memset(&aVTrans[db->nVTrans],0,sizeof(WN_SQL3_vtab *)*ARRAY_INCR);
		db->aVTrans=aVTrans;
	}
	db->aVTrans[db->nVTrans++]=pVtab;
	WN_SQL3VtabLock(pVtab);
	return 0;
}
int WN_SQL3VtabCallCreate(WN_SQL3 *db,int iDb,const char *zTab,char **pzErr)
{
	int rc=0;
	Table *pTab=WN_SQL3FindTable(db,zTab,db->aDb[iDb].zName);
	Module *pMod=pTab->pMod;
	const char *zModule=pTab->azModuleArg[0];
	if(!pMod)
	{
		*pzErr=WN_SQL3MPrintf("no such module:%s",zModule);
		rc=WN_SQL_ERROR;
	}
	else
		rc=vtabCallConstructor(db,pTab,pMod,pMod->pModule->xCreate,pzErr);
	if(rc==0 && pTab->pVtab) rc=addToVTrans(db,pTab->pVtab);
	return rc;
}
int WN_SQL3_declare_vtab(WN_SQL3 *db,const char *zCreateTable)
{
	Table *pTab=db->pVTab;
	if(!pTab)
	{
		WN_SQL3Error(db,WN_SQL_MISUSE,0);
		return WN_SQL_MISUSE;
	}
	Parse sParse;
	int rc=0;
	char *zErr=0;
	memset(&sParse,0,sizeof(Parse));
	sParse.declareVtab=1;
	sParse.db=db;
	if(0==WN_SQL3RunParser(&sParse,zCreateTable,&zErr)&& sParse.pNewTable && !sParse.pNewTable->pSelect && !sParse.pNewTable->isVirtual)
	{
		pTab->aCol=sParse.pNewTable->aCol;
		pTab->nCol=sParse.pNewTable->nCol;
		sParse.pNewTable->nCol=0;
		sParse.pNewTable->aCol=0;
		db->pVTab=0;
	}
	else
	{
		WN_SQL3Error(db,WN_SQL_ERROR,zErr);
		WN_SQL3FreeX(zErr);
		rc=WN_SQL_ERROR;
	}
	sParse.declareVtab=0;
	WN_SQL3_finalize((WN_SQL3_stmt*)sParse.pVdbe);
	WN_SQL3DeleteTable(sParse.pNewTable);
	sParse.pNewTable=0;
	return WN_SQL3ApiExit(db,rc);
}
int WN_SQL3VtabCallDestroy(WN_SQL3 *db,int iDb,const char *zTab)
{
	int rc=0;
	Table *pTab=WN_SQL3FindTable(db,zTab,db->aDb[iDb].zName);
	if(pTab->pVtab)
	{
		int(*xDestroy)(WN_SQL3_vtab *pVTab)=pTab->pMod->pModule->xDestroy;
		rc=WN_SQL3SafetyOff(db);
		if(xDestroy)rc=xDestroy(pTab->pVtab);
		WN_SQL3SafetyOn(db);
		if(rc==0)pTab->pVtab=0;
	}
	return rc;
}
void callFinaliser(WN_SQL3 *db,int offset)
{
	int i;
	if(db->aVTrans)
	{
		for(i=0;i<db->nVTrans && db->aVTrans[i];i++)
		{
			WN_SQL3_vtab *pVtab=db->aVTrans[i];
			int(*x)(WN_SQL3_vtab *);
			x=*(int(**)(WN_SQL3_vtab *))((char *)pVtab->pModule+offset);
			if(x)x(pVtab);
			WN_SQL3VtabUnlock(db,pVtab);
		}
		WN_SQL3FreeX(db->aVTrans);
		db->nVTrans=0;
		db->aVTrans=0;
	}
}
int WN_SQL3VtabSync(WN_SQL3 *db,int rc2)
{
	if(rc2)return rc2;
	int i,rc=0,rcsafety;
	WN_SQL3_vtab **aVTrans=db->aVTrans;
	rc=WN_SQL3SafetyOff(db);
	db->aVTrans=0;
	for(i=0;rc==0 && i<db->nVTrans && aVTrans[i];i++)
	{
		WN_SQL3_vtab *pVtab=aVTrans[i];
		int(*x)(WN_SQL3_vtab *);
		x=pVtab->pModule->xSync;
		if(x)rc=x(pVtab);
	}
	db->aVTrans=aVTrans;
	rcsafety=WN_SQL3SafetyOn(db);
	if(rc==0)rc=rcsafety;
	return rc;
}
int WN_SQL3VtabRollback(WN_SQL3 *db)
{
	callFinaliser(db,(int)(&((WN_SQL3_module *)0)->xRollback));
	return 0;
}
int WN_SQL3VtabCommit(WN_SQL3 *db)
{
	callFinaliser(db,(int)(&((WN_SQL3_module *)0)->xCommit));
	return 0;
}
int WN_SQL3VtabBegin(WN_SQL3 *db,WN_SQL3_vtab *pVtab)
{
	if(0==db->aVTrans && db->nVTrans>0)return WN_SQL_LOCKED;
	if(!pVtab)return 0;
	int rc=0;
	const WN_SQL3_module *pModule=pVtab->pModule;
	if(pModule->xBegin)
	{
		int i;
		for(i=0;(i<db->nVTrans)&& db->aVTrans[i];i++) if(db->aVTrans[i]==pVtab)return 0;
		if(rc=pModule->xBegin(pVtab))return rc;
		rc=addToVTrans(db,pVtab);
	}
	return rc;
}
FuncDef *WN_SQL3VtabOverloadFunction(FuncDef *pDef,int nArg,Expr *pExpr)
{
	if(pExpr==0)return pDef;
	if(pExpr->op!=TK_COLUMN)return pDef;
	Table *pTab=pExpr->pTab;
	if(pTab==0)return pDef;
	if(!pTab->isVirtual)return pDef;
	WN_SQL3_vtab *pVtab=pTab->pVtab;
	WN_SQL3_module *pMod=(WN_SQL3_module *)pVtab->pModule;
	if(pMod->xFindFunction==0)return pDef;
	void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value**);
	void *pArg;
	char *zLowerName=WN_SQL3StrDup(pDef->zName);
	unsigned char *z;
	for(z=(unsigned char*)zLowerName;*z;z++) *z=WN_SQL3UpperToLower[*z];
	int rc=pMod->xFindFunction(pVtab,nArg,zLowerName,&xFunc,&pArg);
	WN_SQL3FreeX(zLowerName);
	if(rc==0)return pDef;
	FuncDef *pNew=WN_SQL3Malloc(sizeof(*pNew)+strlen(pDef->zName));
	if(pNew==0)return pDef;
	*pNew=*pDef;
	memcpy(pNew->zName,pDef->zName,strlen(pDef->zName)+1);
	pNew->xFunc=xFunc;
	pNew->pUserData=pArg;
	pNew->flags |=WN_SQL_FUNC_EPHEM;
	return pNew;
}
#endif
#define BMS (sizeof(Bitmask)*8)
#if defined(WN_SQL_TEST)|| defined(WN_SQL_DEBUG)
int WN_SQL3_where_trace=0;
# define WHERETRACE(X) if(WN_SQL3_where_trace)WN_SQL3DebugPrintf X
#else
# define WHERETRACE(X)
#endif
typedef struct WhereClause WhereClause;
typedef struct ExprMaskSet ExprMaskSet;
typedef struct WhereTerm WhereTerm;
struct WhereTerm
{
	Expr *pExpr;
	i16 iParent,leftCursor,leftColumn;
	u16 eOperator;
	u8 flags,nChild;
	WhereClause *pWC;
	Bitmask prereqRight,prereqAll;
};
#define TERM_DYNAMIC 0x01
#define TERM_VIRTUAL 0x02
#define TERM_CODED 0x04
#define TERM_COPIED 0x08
#define TERM_OR_OK 0x10
struct WhereClause
{
	Parse *pParse;
	ExprMaskSet *pMaskSet;
	int nTerm,nSlot;
	WhereTerm *a,aStatic[10];
};
struct ExprMaskSet
{
	int n,ix[sizeof(Bitmask)*8];
};
#define WO_IN 1
#define WO_EQ 2
#define WO_LT(WO_EQ<<(TK_LT-TK_EQ))
#define WO_LE(WO_EQ<<(TK_LE-TK_EQ))
#define WO_GT(WO_EQ<<(TK_GT-TK_EQ))
#define WO_GE(WO_EQ<<(TK_GE-TK_EQ))
#define WO_MATCH 64
#define WO_ISNULL 128
#define WHERE_ROWID_EQ 0x000100
#define WHERE_ROWID_RANGE 0x000200
#define WHERE_COLUMN_EQ 0x001000
#define WHERE_COLUMN_RANGE 0x002000
#define WHERE_COLUMN_IN 0x004000
#define WHERE_TOP_LIMIT 0x010000
#define WHERE_BTM_LIMIT 0x020000
#define WHERE_IDX_ONLY 0x080000
#define WHERE_ORDERBY 0x100000
#define WHERE_REVERSE 0x200000
#define WHERE_UNIQUE 0x400000
#define WHERE_VIRTUALTABLE 0x800000
void whereClauseInit(WhereClause *pWC,Parse *pParse,ExprMaskSet *pMaskSet)
{
	pWC->pParse=pParse;
	pWC->pMaskSet=pMaskSet;
	pWC->nTerm=0;
	pWC->nSlot=ArraySize(pWC->aStatic);
	pWC->a=pWC->aStatic;
}
void whereClauseClear(WhereClause *pWC)
{
	int i;
	WhereTerm *a;
	for(i=pWC->nTerm-1,a=pWC->a;i>=0;i--,a++)
		if(a->flags & TERM_DYNAMIC) WN_SQL3ExprDelete(a->pExpr);
	if(pWC->a!=pWC->aStatic)WN_SQL3FreeX(pWC->a);
}
int whereClauseInsert(WhereClause *pWC,Expr *p,int flags)
{
	WhereTerm *pTerm;
	int idx;
	if(pWC->nTerm>=pWC->nSlot)
	{
		WhereTerm *pOld=pWC->a;
		pWC->a=WN_SQL3Malloc(sizeof(pWC->a[0])*pWC->nSlot*2);
		if(pWC->a==0)
		{
			if(flags & TERM_DYNAMIC)WN_SQL3ExprDelete(p);
			return 0;
		}
		memcpy(pWC->a,pOld,sizeof(pWC->a[0])*pWC->nTerm);
		if(pOld!=pWC->aStatic)WN_SQL3FreeX(pOld);
		pWC->nSlot *=2;
	}
	pTerm=&pWC->a[idx=pWC->nTerm];
	pWC->nTerm++;
	pTerm->pExpr=p;
	pTerm->flags=flags;
	pTerm->pWC=pWC;
	pTerm->iParent=-1;
	return idx;
}
void whereSplit(WhereClause *pWC,Expr *pExpr,int op)
{
	if(pExpr==0)return;
	if(pExpr->op!=op)
		whereClauseInsert(pWC,pExpr,0);
	else
	{
		whereSplit(pWC,pExpr->pLeft,op);
		whereSplit(pWC,pExpr->pRight,op);
	}
}
#define initMaskSet(P) memset(P,0,sizeof(*P))
Bitmask getMask(ExprMaskSet *pMaskSet,int iCursor)
{
	for(int i=0;i<pMaskSet->n;i++) if(pMaskSet->ix[i]==iCursor)return((Bitmask)1)<<i;
	return 0;
}
void createMask(ExprMaskSet *pMaskSet,int iCursor)
{
	pMaskSet->ix[pMaskSet->n++]=iCursor;
}
Bitmask exprTableUsage(ExprMaskSet *pMaskSet,Expr *p)
{
	Bitmask mask=0;
	if(p==0)return 0;
	if(p->op==TK_COLUMN)
	{
		mask=getMask(pMaskSet,p->iTable);
		return mask;
	}
	mask=exprTableUsage(pMaskSet,p->pRight) | exprTableUsage(pMaskSet,p->pLeft)|exprListTableUsage(pMaskSet,p->pList)|exprSelectTableUsage(pMaskSet,p->pSelect);
	return mask;
}
Bitmask exprListTableUsage(ExprMaskSet *pMaskSet,ExprList *pList)
{
	Bitmask mask=0;
	if(pList)
		for(int i=0;i<pList->nExpr;i++)	mask |=exprTableUsage(pMaskSet,pList->a[i].pExpr);
	return mask;
}
Bitmask exprSelectTableUsage(ExprMaskSet *pMaskSet,Select *pS)
{
	Bitmask mask;
	if(pS==0)
		mask=0;
	else
		mask=exprListTableUsage(pMaskSet,pS->pEList) | exprListTableUsage(pMaskSet,pS->pGroupBy) | exprListTableUsage(pMaskSet,pS->pOrderBy) | exprTableUsage(pMaskSet,pS->pWhere) | exprTableUsage(pMaskSet,pS->pHaving);
	return mask;
}
int allowedOp(int op)
{
	return op==TK_IN ||(op>=TK_EQ && op<=TK_GE)|| op==TK_ISNULL;
}
#define SWAP(TYPE,A,B){TYPE t=A;A=B;B=t;}
void exprCommute(Expr *pExpr)
{
	SWAP(CollSeq*,pExpr->pRight->pColl,pExpr->pLeft->pColl);
	SWAP(Expr*,pExpr->pRight,pExpr->pLeft);
	if(pExpr->op>=TK_GT)pExpr->op=((pExpr->op-TK_GT)^2)+TK_GT;
}
int operatorMask(int op)
{
	int c;
	if(op==TK_IN)
		c=WO_IN;
	else
		if(op==TK_ISNULL)
			c=WO_ISNULL;
		else
			c=WO_EQ<<(op-TK_EQ);
	return c;
}
WhereTerm *findTerm(WhereClause *pWC,int iCur,int iColumn,Bitmask notReady,u16 op,Index *pIdx)
{
	WhereTerm *pTerm;
	int k;
	for(pTerm=pWC->a,k=pWC->nTerm;k;k--,pTerm++)
		if(pTerm->leftCursor==iCur &&(pTerm->prereqRight & notReady)==0
			&& pTerm->leftColumn==iColumn &&(pTerm->eOperator & op))
		{
			if(iCur>=0 && pIdx && pTerm->eOperator!=WO_ISNULL)
			{
				Expr *pX=pTerm->pExpr;
				char idxaff;
				int j;
				Parse *pParse=pWC->pParse;
				idxaff=pIdx->pTable->aCol[iColumn].affinity;
				if(!WN_SQL3IndexAffinityOk(pX,idxaff))continue;
				CollSeq *pColl=WN_SQL3BinaryCompareCollSeq(pParse,pX->pLeft,pX->pRight);
				if(!pColl)pColl=pParse->db->pDfltColl;
				for(j=0;j<pIdx->nColumn && pIdx->aiColumn[j]!=iColumn;j++);
				if(WN_SQL3StrICmp(pColl->zName,pIdx->azColl[j]))continue;
			}
			return pTerm;
		}
	return 0;
}
void exprAnalyzeAll(SrcList *pTabList,WhereClause *pWC)
{
	int i;
	for(i=pWC->nTerm-1;i>=0;i--)exprAnalyze(pTabList,pWC,i);
}
#ifndef WN_SQL_OMIT_LIKE_OPTIMIZATION
int isLikeOrGlob(WN_SQL3 *db,Expr *pExpr,int *pnPattern,int *pisComplete)
{
	int c,cnt,noCase;
	if(!WN_SQL3IsLikeFunction(db,pExpr,&noCase,wc))return 0;
	const char *z;
	ExprList *pList=pExpr->pList;
	char wc[3];
	Expr *pRight=pList->a[0].pExpr;
	if(pRight->op!=TK_STRING)return 0;
	Expr *pLeft=pList->a[1].pExpr;
	if(pLeft->op!=TK_COLUMN)return 0;
	CollSeq *pColl=pLeft->pColl;
	if(pColl==0)pColl=db->pDfltColl;
	if((pColl->type!=WN_SQL_COLL_BINARY || noCase)&&
(pColl->type!=WN_SQL_COLL_NOCASE || !noCase))return 0;
	WN_SQL3DequoteExpr(pRight);
	z=(char *)pRight->token.z;
	for(cnt=0;(c=z[cnt])&& c!=wc[0] && c!=wc[1] && c!=wc[2];cnt++);
	if(cnt==0 || 255==(u8)z[cnt])return 0;
	*pisComplete=z[cnt]==wc[0] && z[cnt+1]==0;
	*pnPattern=cnt;
	return 1;
}
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
int isMatchOfColumn(Expr *pExpr)
{
	ExprList *pList;
	if(pExpr->op!=TK_FUNCTION)return 0;
	if(pExpr->token.n!=5 || WN_SQL3StrNICmp((const char*)pExpr->token.z,"match",5))return 0;
	pList=pExpr->pList;
	if(pList->nExpr!=2)return 0;
	if(pList->a[1].pExpr->op!=TK_COLUMN)return 0;
	return 1;
}
#endif
void transferJoinMarkings(Expr *pDerived,Expr *pBase)
{
	pDerived->flags |=pBase->flags & EP_FromJoin;
	pDerived->iRightJoinTable=pBase->iRightJoinTable;
}
#if !defined(WN_SQL_OMIT_OR_OPTIMIZATION)&& !defined(WN_SQL_OMIT_SUBQUERY)
int orTermIsOptCandidate(WhereTerm *pOrTerm,int iCursor,int iColumn)
{
	if(pOrTerm->leftCursor!=iCursor)||(pOrTerm->leftColumn!=iColumn)return 0;
	int affRight;
	return ((affRight=WN_SQL3ExprAffinity(pOrTerm->pExpr->pRight))==0) || (affRight==WN_SQL3ExprAffinity(pOrTerm->pExpr->pLeft));
}
int orTermHasOkDuplicate(WhereClause *pOr,WhereTerm *pOrTerm)
{
	return (pOrTerm->flags & TERM_COPIED)||((pOrTerm->flags & TERM_VIRTUAL)&&
		(pOr->a[pOrTerm->iParent].flags & TERM_OR_OK))
}
#endif
void exprAnalyze(SrcList *pSrc,WhereClause *pWC,int idxTerm)
{
	if(WN_SQL3MallocFailed())return;
	WhereTerm *pTerm=&pWC->a[idxTerm];
	ExprMaskSet *pMaskSet=pWC->pMaskSet;
	Expr *pExpr=pTerm->pExpr;
	Bitmask prereqLeft=exprTableUsage(pMaskSet,pExpr->pLeft),prereqAll;
	int nPattern,isComplete,op=pExpr->op;
	if(op==TK_IN)
		pTerm->prereqRight=exprListTableUsage(pMaskSet,pExpr->pList)| exprSelectTableUsage(pMaskSet,pExpr->pSelect);
	else
		if(op==TK_ISNULL)
			pTerm->prereqRight=0;
		else
			pTerm->prereqRight=exprTableUsage(pMaskSet,pExpr->pRight);
	prereqAll=exprTableUsage(pMaskSet,pExpr);
	if(ExprHasProperty(pExpr,EP_FromJoin))
		prereqAll |=getMask(pMaskSet,pExpr->iRightJoinTable);
	pTerm->prereqAll=prereqAll;
	pTerm->leftCursor=-1;
	pTerm->iParent=-1;
	pTerm->eOperator=0;
	if(allowedOp(op)&&(pTerm->prereqRight & prereqLeft)==0)
	{
		Expr *pLeft=pExpr->pLeft,*pRight=pExpr->pRight;
		if(pLeft->op==TK_COLUMN)
		{
			pTerm->leftCursor=pLeft->iTable;
			pTerm->leftColumn=pLeft->iColumn;
			pTerm->eOperator=operatorMask(op);
		}
		if(pRight && pRight->op==TK_COLUMN)
		{
			WhereTerm *pNew;
			Expr *pDup;
			if(pTerm->leftCursor>=0)
			{
				int idxNew;
				pDup=WN_SQL3ExprDup(pExpr);
				if(WN_SQL3MallocFailed())
				{
					WN_SQL3ExprDelete(pDup);
					return;
				}
				idxNew=whereClauseInsert(pWC,pDup,TERM_VIRTUAL|TERM_DYNAMIC);
				if(idxNew==0)return;
				pNew=&pWC->a[idxNew];
				pNew->iParent=idxTerm;
				pTerm=&pWC->a[idxTerm];
				pTerm->nChild=1;
				pTerm->flags |=TERM_COPIED;
			}
			else
			{
				pDup=pExpr;
				pNew=pTerm;
			}
			exprCommute(pDup);
			pLeft=pDup->pLeft;
			pNew->leftCursor=pLeft->iTable;
			pNew->leftColumn=pLeft->iColumn;
			pNew->prereqRight=prereqLeft;
			pNew->prereqAll=prereqAll;
			pNew->eOperator=operatorMask(pDup->op);
		}
	}
#ifndef WN_SQL_OMIT_BETWEEN_OPTIMIZATION
	else
		if(pExpr->op==TK_BETWEEN)
		{
			ExprList *pList=pExpr->pList;
			int i;
			const u8 ops[]={TK_GE,TK_LE};
			for(i=0;i<2;i++)
			{
				Expr *pNewExpr;
				int idxNew;
				pNewExpr=WN_SQL3Expr(ops[i],WN_SQL3ExprDup(pExpr->pLeft),WN_SQL3ExprDup(pList->a[i].pExpr),0);
				idxNew=whereClauseInsert(pWC,pNewExpr,TERM_VIRTUAL|TERM_DYNAMIC);
				exprAnalyze(pSrc,pWC,idxNew);
				pTerm=&pWC->a[idxTerm];
				pWC->a[idxNew].iParent=idxTerm;
			}
			pTerm->nChild=2;
		}
#endif
#if !defined(WN_SQL_OMIT_OR_OPTIMIZATION)&& !defined(WN_SQL_OMIT_SUBQUERY)
		else
			if(pExpr->op==TK_OR)
			{
				int ok,i,j,iColumn,iCursor;
				WhereClause sOr;
				WhereTerm *pOrTerm;
				whereClauseInit(&sOr,pWC->pParse,pMaskSet);
				whereSplit(&sOr,pExpr,TK_OR);
				exprAnalyzeAll(pSrc,&sOr);
				j=0;
				do
				{
					iColumn=sOr.a[j].leftColumn;
					iCursor=sOr.a[j].leftCursor;
					ok=iCursor>=0;
					for(i=sOr.nTerm-1,pOrTerm=sOr.a;i>=0 && ok;i--,pOrTerm++)
					{
						if(pOrTerm->eOperator!=WO_EQ)goto or_not_possible;
						if(orTermIsOptCandidate(pOrTerm,iCursor,iColumn))
							pOrTerm->flags |=TERM_OR_OK;
						else
							if(orTermHasOkDuplicate(&sOr,pOrTerm))
								pOrTerm->flags &=~TERM_OR_OK;
							else
								ok=0;
					}
				}while(!ok &&(sOr.a[j++].flags & TERM_COPIED)&& j<2);
				if(ok)
				{
					ExprList *pList=0;
					Expr *pNew,*pDup;
					Expr *pLeft=0;
					for(i=sOr.nTerm-1,pOrTerm=sOr.a;i>=0 && ok;i--,pOrTerm++)
					{
						if((pOrTerm->flags & TERM_OR_OK)==0)continue;
						pDup=WN_SQL3ExprDup(pOrTerm->pExpr->pRight);
						pList=WN_SQL3ExprListAppend(pList,pDup,0);
						pLeft=pOrTerm->pExpr->pLeft;
					}
					pDup=WN_SQL3ExprDup(pLeft);
					pNew=WN_SQL3Expr(TK_IN,pDup,0,0);
					if(pNew)
					{
						int idxNew;
						transferJoinMarkings(pNew,pExpr);
						pNew->pList=pList;
						idxNew=whereClauseInsert(pWC,pNew,TERM_VIRTUAL|TERM_DYNAMIC);
						exprAnalyze(pSrc,pWC,idxNew);
						pTerm=&pWC->a[idxTerm];
						pWC->a[idxNew].iParent=idxTerm;
						pTerm->nChild=1;
					}
					else
						WN_SQL3ExprListDelete(pList);
				}
or_not_possible:
				whereClauseClear(&sOr);
			}
#endif
#ifndef WN_SQL_OMIT_LIKE_OPTIMIZATION
			if(isLikeOrGlob(pWC->pParse->db,pExpr,&nPattern,&isComplete))
			{
				Expr *pLeft=pExpr->pList->a[1].pExpr,*pRight=pExpr->pList->a[0].pExpr,*pStr1,*pStr2,*pNewExpr1,*pNewExpr2;
				int idxNew1,idxNew2;
				pStr1=WN_SQL3Expr(TK_STRING,0,0,0);
				if(pStr1)
				{
					WN_SQL3TokenCopy(&pStr1->token,&pRight->token);
					pStr1->token.n=nPattern;
					pStr1->flags=EP_Dequoted;
				}
				pStr2=WN_SQL3ExprDup(pStr1);
				if(pStr2)++*(u8*)&pStr2->token.z[nPattern-1];
				pNewExpr1=WN_SQL3Expr(TK_GE,WN_SQL3ExprDup(pLeft),pStr1,0);
				idxNew1=whereClauseInsert(pWC,pNewExpr1,TERM_VIRTUAL|TERM_DYNAMIC);
				exprAnalyze(pSrc,pWC,idxNew1);
				pNewExpr2=WN_SQL3Expr(TK_LT,WN_SQL3ExprDup(pLeft),pStr2,0);
				idxNew2=whereClauseInsert(pWC,pNewExpr2,TERM_VIRTUAL|TERM_DYNAMIC);
				exprAnalyze(pSrc,pWC,idxNew2);
				pTerm=&pWC->a[idxTerm];
				if(isComplete)
				{
					pWC->a[idxNew1].iParent=idxTerm;
					pWC->a[idxNew2].iParent=idxTerm;
					pTerm->nChild=2;
				}
			}
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
			if(isMatchOfColumn(pExpr))
			{
				int idxNew;
				Expr *pRight,*pLeft;
				WhereTerm *pNewTerm;
				Bitmask prereqColumn,prereqExpr;
				pRight=pExpr->pList->a[0].pExpr;
				pLeft=pExpr->pList->a[1].pExpr;
				prereqExpr=exprTableUsage(pMaskSet,pRight);
				prereqColumn=exprTableUsage(pMaskSet,pLeft);
				if((prereqExpr & prereqColumn)==0)
				{
					Expr *pNewExpr;
					pNewExpr=WN_SQL3Expr(TK_MATCH,0,WN_SQL3ExprDup(pRight),0);
					idxNew=whereClauseInsert(pWC,pNewExpr,TERM_VIRTUAL|TERM_DYNAMIC);
					pNewTerm=&pWC->a[idxNew];
					pNewTerm->prereqRight=prereqExpr;
					pNewTerm->leftCursor=pLeft->iTable;
					pNewTerm->leftColumn=pLeft->iColumn;
					pNewTerm->eOperator=WO_MATCH;
					pNewTerm->iParent=idxTerm;
					pTerm=&pWC->a[idxTerm];
					pTerm->nChild=1;
					pTerm->flags |=TERM_COPIED;
					pNewTerm->prereqAll=pTerm->prereqAll;
				}
			}
#endif
}
int referencesOtherTables(ExprList *pList,ExprMaskSet *pMaskSet,int iFirst,int iBase)
{
	Bitmask allowed=~getMask(pMaskSet,iBase);
	while(iFirst<pList->nExpr)if((exprTableUsage(pMaskSet,pList->a[iFirst++].pExpr)&allowed))return 1;
	return 0;
}
int isSortingIndex(Parse *pParse,ExprMaskSet *pMaskSet,Index *pIdx,int base,ExprList *pOrderBy,int nEqCol,int *pbRev)
{
	int i,j,sortOrder=0,nTerm=pOrderBy->nExpr;
	struct ExprList_item *pTerm;
	WN_SQL3 *db=pParse->db;
	for(i=j=0,pTerm=pOrderBy->a;j<nTerm && i<=pIdx->nColumn;i++)
	{
		Expr *pExpr;
		int termSortOrder,iColumn,iSortOrder;
		const char *zColl;
		pExpr=pTerm->pExpr;
		if(pExpr->op!=TK_COLUMN || pExpr->iTable!=base)break;
		CollSeq *pColl=WN_SQL3ExprCollSeq(pParse,pExpr);
		if(!pColl)pColl=db->pDfltColl;
		if(i<pIdx->nColumn)
		{
			iColumn=pIdx->aiColumn[i];
			if(iColumn==pIdx->pTable->iPKey)iColumn=-1;
			iSortOrder=pIdx->aSortOrder[i];
			zColl=pIdx->azColl[i];
		}
		else
		{
			iColumn=-1;
			iSortOrder=0;
			zColl=pColl->zName;
		}
		if(pExpr->iColumn!=iColumn || WN_SQL3StrICmp(pColl->zName,zColl))
		{
			if(i<nEqCol)
				continue;
			else
				return 0;
		}
		termSortOrder=iSortOrder ^ pTerm->sortOrder;
		if(i>nEqCol)
		{
			if(termSortOrder!=sortOrder)return 0;
		}
		else
			sortOrder=termSortOrder;
		j++;
		pTerm++;
		if(iColumn<0 && !referencesOtherTables(pOrderBy,pMaskSet,j,base))j=nTerm;
	}
	*pbRev=sortOrder!=0;
	if(j>=nTerm)return 1;
	if(pIdx->onError!=OE_None && i==pIdx->nColumn && !referencesOtherTables(pOrderBy,pMaskSet,j,base))	return 1;
	return 0;
}
int sortableByRowid(int base,ExprList *pOrderBy,ExprMaskSet *pMaskSet,int *pbRev)
{
	Expr *p=pOrderBy->a[0].pExpr;
	if(p->op==TK_COLUMN && p->iTable==base && p->iColumn==-1 && !referencesOtherTables(pOrderBy,pMaskSet,1,base))
	{
		*pbRev=pOrderBy->a[0].sortOrder;
		return 1;
	}
	return 0;
}
double estLog(double N)
{
	double logN=1,x=10;
	while(N>x)
	{
		logN+=1;
		x *=10;
	}
	return logN;
}
#if !defined(WN_SQL_OMIT_VIRTUALTABLE) && defined(WN_SQL_DEBUG)
void TRACE_IDX_INPUTS(WN_SQL3_index_info *p)
{
	if(!WN_SQL3_where_trace)return;
	int i;
	for(i=0;i<p->nConstraint;i++)WN_SQL3DebugPrintf(" constraint[%d]:col=%d termid=%d op=%d usabled=%d\n",i,p->aConstraint[i].iColumn,p->aConstraint[i].iTermOffset,p->aConstraint[i].op,p->aConstraint[i].usable);
	for(i=0;i<p->nOrderBy;i++)WN_SQL3DebugPrintf(" orderby[%d]:col=%d desc=%d\n",i,p->aOrderBy[i].iColumn,p->aOrderBy[i].desc);
}
void TRACE_IDX_OUTPUTS(WN_SQL3_index_info *p)
{
	int i;
	if(!WN_SQL3_where_trace)return;
	for(i=0;i<p->nConstraint;i++)WN_SQL3DebugPrintf(" usage[%d]:argvIdx=%d omit=%d\n",i,p->aConstraintUsage[i].argvIndex,p->aConstraintUsage[i].omit);
	WN_SQL3DebugPrintf(" idxNum=%d\n",p->idxNum);
	WN_SQL3DebugPrintf(" idxStr=%s\n",p->idxStr);
	WN_SQL3DebugPrintf(" orderByConsumed=%d\n",p->orderByConsumed);
	WN_SQL3DebugPrintf(" estimatedCost=%g\n",p->estimatedCost);
}
#else
#define TRACE_IDX_INPUTS(A)
#define TRACE_IDX_OUTPUTS(A)
#endif
#ifndef WN_SQL_OMIT_VIRTUALTABLE
double bestVirtualIndex(Parse *pParse,WhereClause *pWC,struct SrcList_item *pSrc,Bitmask notReady,ExprList *pOrderBy,int orderByUsable,WN_SQL3_index_info **ppIdxInfo)
{
	Table *pTab=pSrc->pTab;
	struct WN_SQL3_index_constraint *pIdxCons;
	struct WN_SQL3_index_orderby *pIdxOrderBy;
	struct WN_SQL3_index_constraint_usage *pUsage;
	WhereTerm *pTerm;
	int i,j,nOrderBy,rc;
	WN_SQL3_index_info *pIdxInfo=*ppIdxInfo;
	if(pIdxInfo==0)
	{
		WhereTerm *pTerm;
		int nTerm;
		WHERETRACE(("Recomputing index info for %s...\n",pTab->zName));
		for(i=nTerm=0,pTerm=pWC->a;i<pWC->nTerm;i++,pTerm++)
		{
			if(pTerm->leftCursor!=pSrc->iCursor)continue;
			if(pTerm->eOperator==WO_IN)continue;
			nTerm++;
		}
		nOrderBy=0;
		if(pOrderBy)
		{
			for(i=0;i<pOrderBy->nExpr;i++)
			{
				Expr *pExpr=pOrderBy->a[i].pExpr;
				if(pExpr->op!=TK_COLUMN || pExpr->iTable!=pSrc->iCursor)break;
			}
			if(i==pOrderBy->nExpr)nOrderBy=pOrderBy->nExpr;
		}
		pIdxInfo=WN_SQL3Malloc(sizeof(*pIdxInfo)+(sizeof(*pIdxCons)+sizeof(*pUsage))*nTerm+sizeof(*pIdxOrderBy)*nOrderBy);
		if(pIdxInfo==0)
		{
			WN_SQL3ErrorMsg(pParse,"out of memory");
			return 0.0;
		}
		*ppIdxInfo=pIdxInfo;
		pIdxCons=(struct WN_SQL3_index_constraint*)&pIdxInfo[1];
		pIdxOrderBy=(struct WN_SQL3_index_orderby*)&pIdxCons[nTerm];
		pUsage=(struct WN_SQL3_index_constraint_usage*)&pIdxOrderBy[nOrderBy];
		*(int*)&pIdxInfo->nConstraint=nTerm;
		*(int*)&pIdxInfo->nOrderBy=nOrderBy;
		*(struct WN_SQL3_index_constraint**)&pIdxInfo->aConstraint=pIdxCons;
		*(struct WN_SQL3_index_orderby**)&pIdxInfo->aOrderBy=pIdxOrderBy;
		*(struct WN_SQL3_index_constraint_usage**)&pIdxInfo->aConstraintUsage=pUsage;
		for(i=j=0,pTerm=pWC->a;i<pWC->nTerm;i++,pTerm++)
		{
			if(pTerm->leftCursor!=pSrc->iCursor)||(pTerm->eOperator==WO_IN)continue;
			pIdxCons[j].iColumn=pTerm->leftColumn;
			pIdxCons[j].iTermOffset=i;
			pIdxCons[j].op=pTerm->eOperator;
			j++;
		}
		for(i=0;i<nOrderBy;i++)
		{
			Expr *pExpr=pOrderBy->a[i].pExpr;
			pIdxOrderBy[i].iColumn=pExpr->iColumn;
			pIdxOrderBy[i].desc=pOrderBy->a[i].sortOrder;
		}
	}
#if 0
if(pTab->pVtab==0)
{
	WN_SQL3ErrorMsg(pParse,"undefined module %s for table %s",pTab->azModuleArg[0],pTab->zName);
	return 0.0;
}
#endif
	pIdxCons=*(struct WN_SQL3_index_constraint**)&pIdxInfo->aConstraint;
	pUsage=pIdxInfo->aConstraintUsage;
	for(i=0;i<pIdxInfo->nConstraint;i++,pIdxCons++)
	{
		j=pIdxCons->iTermOffset;
		pTerm=&pWC->a[j];
		pIdxCons->usable=(pTerm->prereqRight & notReady)==0;
	}
	memset(pUsage,0,sizeof(pUsage[0])*pIdxInfo->nConstraint);
	if(pIdxInfo->needToFreeIdxStr)WN_SQL3_free(pIdxInfo->idxStr);
	pIdxInfo->idxStr=0;
	pIdxInfo->idxNum=0;
	pIdxInfo->needToFreeIdxStr=0;
	pIdxInfo->orderByConsumed=0;
	pIdxInfo->estimatedCost=WN_SQL_BIG_DBL / 2.0;
	nOrderBy=pIdxInfo->nOrderBy;
	if(pIdxInfo->nOrderBy && !orderByUsable)*(int*)&pIdxInfo->nOrderBy=0;
	WN_SQL3SafetyOff(pParse->db);
	WHERETRACE(("xBestIndex for %s\n",pTab->zName));
	TRACE_IDX_INPUTS(pIdxInfo);
	rc=pTab->pVtab->pModule->xBestIndex(pTab->pVtab,pIdxInfo);
	TRACE_IDX_OUTPUTS(pIdxInfo);
	if(rc)
	{
		if(rc==WN_SQL_NOMEM)
			WN_SQL3FailedMalloc();
		else
			WN_SQL3ErrorMsg(pParse,"%s",WN_SQL3ErrStr(rc));
		WN_SQL3SafetyOn(pParse->db);
	}
	else
		rc=WN_SQL3SafetyOn(pParse->db);
	*(int*)&pIdxInfo->nOrderBy=nOrderBy;
	return pIdxInfo->estimatedCost;
}
#endif
double bestIndex(Parse *pParse,WhereClause *pWC,struct SrcList_item *pSrc,Bitmask notReady,ExprList *pOrderBy,Index **ppIndex,int *pFlags,int *pnEq)
{
	WhereTerm *pTerm;
	Index *bestIdx=0;
	double lowestCost;
	int bestFlags=0,bestNEq=0,iCur=pSrc->iCursor;
	Index *pProbe;
	int rev,flags,nEq,eqTermMask;
	double cost;
	WHERETRACE(("bestIndex:tbl=%s notReady=%x\n",pSrc->pTab->zName,notReady));
	lowestCost=WN_SQL_BIG_DBL;
	pProbe=pSrc->pTab->pIndex;
	if(pProbe==0 && findTerm(pWC,iCur,-1,0,WO_EQ|WO_IN|WO_LT|WO_LE|WO_GT|WO_GE,0)==0 &&(pOrderBy==0 || !sortableByRowid(iCur,pOrderBy,pWC->pMaskSet,&rev)))
	{
		*pFlags=0;
		*ppIndex=0;
		*pnEq=0;
		return 0.0;
	}
	pTerm=findTerm(pWC,iCur,-1,notReady,WO_EQ|WO_IN,0);
	if(pTerm)
	{
		Expr *pExpr;
		*ppIndex=0;
		bestFlags=WHERE_ROWID_EQ;
		if(pTerm->eOperator & WO_EQ)
		{
			*pFlags=WHERE_ROWID_EQ | WHERE_UNIQUE;
			*pnEq=1;
			WHERETRACE(("... best is rowid\n"));
			return 0.0;
		}
		else
			if((pExpr=pTerm->pExpr)->pList)
			{
				lowestCost=pExpr->pList->nExpr;
				lowestCost *=estLog(lowestCost);
			}
			else
				lowestCost=200;
		WHERETRACE(("... rowid IN cost:%.9g\n",lowestCost));
	}
	cost=pProbe ? pProbe->aiRowEst[0] :1000000;
	WHERETRACE(("... table scan base cost:%.9g\n",cost));
	flags=WHERE_ROWID_RANGE;
	pTerm=findTerm(pWC,iCur,-1,notReady,WO_LT|WO_LE|WO_GT|WO_GE,0);
	if(pTerm)
	{
		if(findTerm(pWC,iCur,-1,notReady,WO_LT|WO_LE,0))
		{
			flags |=WHERE_TOP_LIMIT;
			cost /=3;
		}
		if(findTerm(pWC,iCur,-1,notReady,WO_GT|WO_GE,0))
		{
			flags |=WHERE_BTM_LIMIT;
			cost /=3;
		}
		WHERETRACE(("... rowid range reduces cost to %.9g\n",cost));
	}
	else
		flags=0;
	if(pOrderBy)
	{
		if(sortableByRowid(iCur,pOrderBy,pWC->pMaskSet,&rev))
		{
			flags |=WHERE_ORDERBY|WHERE_ROWID_RANGE;
			if(rev)	flags |=WHERE_REVERSE;
		}
		else
		{
			cost+=cost*estLog(cost);
			WHERETRACE(("... sorting increases cost to %.9g\n",cost));
		}
	}
	if(cost<lowestCost)
	{
		lowestCost=cost;
		bestFlags=flags;
	}
	if((pSrc->jointype & JT_LEFT))
		eqTermMask=WO_EQ|WO_IN;
	else
		eqTermMask=WO_EQ|WO_IN|WO_ISNULL;
	for(;pProbe;pProbe=pProbe->pNext)
	{
		int i;
		double inMultiplier=1;
		WHERETRACE(("... index %s:\n",pProbe->zName));
		flags=0;
		for(i=0;i<pProbe->nColumn;i++)
		{
			int j=pProbe->aiColumn[i];
			pTerm=findTerm(pWC,iCur,j,notReady,eqTermMask,pProbe);
			if(pTerm==0)break;
			flags |=WHERE_COLUMN_EQ;
			if(pTerm->eOperator & WO_IN)
			{
				Expr *pExpr=pTerm->pExpr;
				flags |=WHERE_COLUMN_IN;
				if(pExpr->pSelect)
					inMultiplier *=25;
				else
					if(pExpr->pList)
						inMultiplier *=pExpr->pList->nExpr+1;
			}
		}
		cost=pProbe->aiRowEst[i] * inMultiplier * estLog(inMultiplier);
		nEq=i;
		if(pProbe->onError!=OE_None &&(flags & WHERE_COLUMN_IN)==0
			&& nEq==pProbe->nColumn)
			flags |=WHERE_UNIQUE;
		WHERETRACE(("...... nEq=%d inMult=%.9g cost=%.9g\n",nEq,inMultiplier,
			cost));
		if(nEq<pProbe->nColumn)
		{
			int j=pProbe->aiColumn[nEq];
			pTerm=findTerm(pWC,iCur,j,notReady,WO_LT|WO_LE|WO_GT|WO_GE,pProbe);
			if(pTerm)
			{
				flags |=WHERE_COLUMN_RANGE;
				if(findTerm(pWC,iCur,j,notReady,WO_LT|WO_LE,pProbe))
				{
					flags |=WHERE_TOP_LIMIT;
					cost /=3;
				}
				if(findTerm(pWC,iCur,j,notReady,WO_GT|WO_GE,pProbe))
				{
					flags |=WHERE_BTM_LIMIT;
					cost /=3;
				}
				WHERETRACE(("...... range reduces cost to %.9g\n",cost));
			}
		}
		if(pOrderBy)
		{
			if((flags & WHERE_COLUMN_IN)==0 && isSortingIndex(pParse,
				pWC->pMaskSet,pProbe,iCur,pOrderBy,nEq,&rev))
			{
				if(flags==0)
					flags=WHERE_COLUMN_RANGE;
				flags |=WHERE_ORDERBY;
				if(rev)
					flags |=WHERE_REVERSE;
			}
			else
			{
				cost+=cost*estLog(cost);
				WHERETRACE(("...... orderby increases cost to %.9g\n",cost));
			}
		}
		if(flags && pSrc->colUsed<(((Bitmask)1)<<(BMS-1)))
		{
			Bitmask m=pSrc->colUsed;
			int j;
			for(j=0;j<pProbe->nColumn;j++)
			{
				int x=pProbe->aiColumn[j];
				if(x<BMS-1)
					m &=~(((Bitmask)1)<<x);
			}
			if(m==0)
			{
				flags |=WHERE_IDX_ONLY;
				cost /=2;
				WHERETRACE(("...... idx-only reduces cost to %.9g\n",cost));
			}
		}
		if(cost<lowestCost)
		{
			bestIdx=pProbe;
			lowestCost=cost;
						bestFlags=flags;
			bestNEq=nEq;
		}
	}
	*ppIndex=bestIdx;
	WHERETRACE(("best index is %s,cost=%.9g,flags=%x,nEq=%d\n",
		bestIdx ? bestIdx->zName :"(none)",lowestCost,bestFlags,bestNEq));
	*pFlags=bestFlags | eqTermMask;
	*pnEq=bestNEq;
	return lowestCost;
}
void disableTerm(WhereLevel *pLevel,WhereTerm *pTerm)
{
	if(pTerm&&(pTerm->flags & TERM_CODED)==0 &&(pLevel->iLeftJoin==0 ||
		ExprHasProperty(pTerm->pExpr,EP_FromJoin)))
	{
		pTerm->flags |=TERM_CODED;
		if(pTerm->iParent>=0)
		{
			WhereTerm *pOther=&pTerm->pWC->a[pTerm->iParent];
			if((--pOther->nChild)==0)
				disableTerm(pLevel,pOther);
		}
	}
}
void buildIndexProbe(Vdbe *v,int nColumn,Index *pIdx)
{
	WN_SQL3VdbeAddOp(v,OP_MakeRecord,nColumn,0);
	WN_SQL3IndexAffinityStr(v,pIdx);
}
void codeEqualityTerm(Parse *pParse,WhereTerm *pTerm,WhereLevel *pLevel)
{
	Expr *pX=pTerm->pExpr;
	Vdbe *v=pParse->pVdbe;
	if(pX->op==TK_EQ)
		WN_SQL3ExprCode(pParse,pX->pRight);
	else
		if(pX->op==TK_ISNULL)
		{
			WN_SQL3VdbeAddOp(v,OP_Null,0,0);
#ifndef WN_SQL_OMIT_SUBQUERY
		}
		else
		{
			int iTab;
			struct InLoop *pIn;
						WN_SQL3CodeSubselect(pParse,pX);
			iTab=pX->iTable;
			WN_SQL3VdbeAddOp(v,OP_Rewind,iTab,0);
			VdbeComment((v,"# %.*s",pX->span.n,pX->span.z));
			if(pLevel->nIn==0)pLevel->nxt=WN_SQL3VdbeMakeLabel(v);
			pLevel->nIn++;
			pLevel->aInLoop=WN_SQLReallocOrFree(pLevel->aInLoop,sizeof(pLevel->
				aInLoop[0])*pLevel->nIn);
			pIn=pLevel->aInLoop;
			if(pIn)
			{
				pIn+=pLevel->nIn-1;
				pIn->iCur=iTab;
				pIn->topAddr=WN_SQL3VdbeAddOp(v,OP_Column,iTab,0);
				WN_SQL3VdbeAddOp(v,OP_IsNull,-1,0);
			}
			else
				pLevel->nIn=0;
#endif
		}
		disableTerm(pLevel,pTerm);
}
void codeAllEqualityTerms(Parse *pParse,WhereLevel *pLevel,WhereClause *pWC,Bitmask notReady)
{
	int nEq=pLevel->nEq,termsInMem=0;
	Vdbe *v=pParse->pVdbe;
	Index *pIdx=pLevel->pIdx;
	int iCur=pLevel->iTabCur;
	WhereTerm *pTerm;
	int j;
	pLevel->iMem=pParse->nMem++;
	if(pLevel->flags & WHERE_COLUMN_IN)
	{
		pParse->nMem+=pLevel->nEq;
		termsInMem=1;
	}
	for(j=0;j<nEq;j++)
	{
		int k=pIdx->aiColumn[j];
		pTerm=findTerm(pWC,iCur,k,notReady,pLevel->flags,pIdx);
		if(pTerm==0)break;
		codeEqualityTerm(pParse,pTerm,pLevel);
		if((pTerm->eOperator &(WO_ISNULL|WO_IN))==0)WN_SQL3VdbeAddOp(v,OP_IsNull,termsInMem ?-1 :-(j+1),pLevel->brk);
		if(termsInMem)WN_SQL3VdbeAddOp(v,OP_MemStore,pLevel->iMem+j+1,1);
	}
	if(termsInMem) for(j=0;j<nEq;j++)WN_SQL3VdbeAddOp(v,OP_MemLoad,pLevel->iMem+j+1,0);
}
#if defined(WN_SQL_TEST)
char WN_SQL3_query_plan[BMS*2*40];
int nQPlan=0;
#endif
void whereInfoFree(WhereInfo *pWInfo)
{
	if(pWInfo)
	{
		int i;
		for(i=0;i<pWInfo->nLevel;i++)
		{
			WN_SQL3_index_info *pInfo=pWInfo->a[i].pIdxInfo;
			if(pInfo)
			{
				if(pInfo->needToFreeIdxStr)	WN_SQL3_free(pInfo->idxStr);
				WN_SQL3FreeX(pInfo);
			}
		}
		WN_SQL3FreeX(pWInfo);
	}
}
WhereInfo *WN_SQL3WhereBegin(Parse *pParse,SrcList *pTabList,Expr *pWhere,ExprList **ppOrderBy)
{
	int i;
	Vdbe *v=pParse->pVdbe;
	int brk,cont=0;
	Bitmask notReady;
	WhereTerm *pTerm;
	WhereClause wc;
	struct SrcList_item *pTabItem;
	WhereLevel *pLevel;
	int iFrom,andFlags;
	if(pTabList->nSrc>BMS)
	{
		WN_SQL3ErrorMsg(pParse,"at most %d tables in a join",BMS);
		return 0;
	}
	ExprMaskSet maskSet;
	initMaskSet(&maskSet);
	whereClauseInit(&wc,pParse,&maskSet);
	whereSplit(&wc,pWhere,TK_AND);
	WhereInfo *pWInfo=WN_SQL3Malloc(sizeof(WhereInfo)+pTabList->nSrc*sizeof(WhereLevel));
	if(WN_SQL3MallocFailed())goto whereBeginNoMem;
	pWInfo->nLevel=pTabList->nSrc;
	pWInfo->pParse=pParse;
	pWInfo->pTabList=pTabList;
	pWInfo->iBreak=WN_SQL3VdbeMakeLabel(v);
	if(pWhere &&(pTabList->nSrc==0 || WN_SQL3ExprIsConstantNotJoin(pWhere)))
	{
		WN_SQL3ExprIfFalse(pParse,pWhere,pWInfo->iBreak,1);
		pWhere=0;
	}
	for(i=0;i<pTabList->nSrc;i++)createMask(&maskSet,pTabList->a[i].iCursor);
	exprAnalyzeAll(pTabList,&wc);
	if(WN_SQL3MallocFailed())goto whereBeginNoMem;
	notReady=~(Bitmask)0;
	pTabItem=pTabList->a;
	pLevel=pWInfo->a;
	andFlags=~0;
	WHERETRACE(("*** Optimizer Start ***\n"));
	for(i=iFrom=0,pLevel=pWInfo->a;i<pTabList->nSrc;i++,pLevel++)
	{
		int flags,nEq,j,bestFlags=0,bestNEq=0,bestJ=0,once=0;
		Index *pIdx,*pBest=0;
		double cost,lowestCost=WN_SQL_BIG_DBL;
		Bitmask m;
		WN_SQL3_index_info *pIndex;
		for(j=iFrom,pTabItem=&pTabList->a[j];j<pTabList->nSrc;j++,pTabItem++)
		{
			int doNotReorder=(pTabItem->jointype &(JT_LEFT|JT_CROSS));
			if(once && doNotReorder)break;
			m=getMask(&maskSet,pTabItem->iCursor);
			if((m & notReady)==0)
			{
				if(j==iFrom)iFrom++;
				continue;
			}
#ifndef WN_SQL_OMIT_VIRTUALTABLE
			if(IsVirtual(pTabItem->pTab))
			{
				WN_SQL3_index_info **ppIdxInfo=&pWInfo->a[j].pIdxInfo;
				cost=bestVirtualIndex(pParse,&wc,pTabItem,notReady,ppOrderBy ? *ppOrderBy :0,i==0,ppIdxInfo);
				flags=WHERE_VIRTUALTABLE;
				pIndex=*ppIdxInfo;
				if(pIndex && pIndex->orderByConsumed)flags=WHERE_VIRTUALTABLE | WHERE_ORDERBY;
				pIdx=0;
				nEq=0;
				if((WN_SQL_BIG_DBL/2.0)<cost)cost=(WN_SQL_BIG_DBL/2.0);
			}
			else
#endif
			{
				cost=bestIndex(pParse,&wc,pTabItem,notReady,(i==0 && ppOrderBy)? *				ppOrderBy :0,&pIdx,&flags,&nEq);
				pIndex=0;
			}
			if(cost<lowestCost)
			{
				once=1;
				lowestCost=cost;
				pBest=pIdx;
				bestFlags=flags;
				bestNEq=nEq;
				bestJ=j;
				pLevel->pBestIdx=pIndex;
			}
			if(doNotReorder)break;
		}
		WHERETRACE(("*** Optimizer choose table %d for loop %d\n",bestJ,pLevel-pWInfo->a));
		if((bestFlags & WHERE_ORDERBY))*ppOrderBy=0;
		andFlags &=bestFlags;
		pLevel->flags=bestFlags;
		pLevel->pIdx=pBest;
		pLevel->nEq=bestNEq;
		pLevel->aInLoop=0;
		pLevel->nIn=0;
		if(pBest)
			pLevel->iIdxCur=pParse->nTab++;
		else
			pLevel->iIdxCur=-1;
		notReady &=~getMask(&maskSet,pTabList->a[bestJ].iCursor);
		pLevel->iFrom=bestJ;
	}
	WHERETRACE(("*** Optimizer Finished ***\n"));
	if((andFlags & WHERE_UNIQUE)&& ppOrderBy)*ppOrderBy=0;
	WN_SQL3CodeVerifySchema(pParse,-1);
	for(i=0,pLevel=pWInfo->a;i<pTabList->nSrc;i++,pLevel++)
	{
		Table *pTab;
		Index *pIx;
		int iDb;
		int iIdxCur=pLevel->iIdxCur;
#ifndef WN_SQL_OMIT_EXPLAIN
		if(pParse->explain==2)
		{
			struct SrcList_item *pItem=&pTabList->a[pLevel->iFrom];
			char *zMsg=WN_SQL3MPrintf("TABLE %s",pItem->zName);
			if(pItem->zAlias)zMsg=WN_SQL3MPrintf("%z AS %s",zMsg,pItem->zAlias);
			if((pIx=pLevel->pIdx))
				zMsg=WN_SQL3MPrintf("%z WITH INDEX %s",zMsg,pIx->zName);
			else
				if(pLevel->flags &(WHERE_ROWID_EQ|WHERE_ROWID_RANGE))zMsg=WN_SQL3MPrintf("%z USING PRIMARY KEY",zMsg);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
				else
					if(pLevel->pBestIdx)
					{
						WN_SQL3_index_info *pBestIdx=pLevel->pBestIdx;
						zMsg=WN_SQL3MPrintf("%z VIRTUAL TABLE INDEX %d:%s",zMsg,pBestIdx->idxNum,pBestIdx->idxStr);
					}
#endif
					if(pLevel->flags & WHERE_ORDERBY)zMsg=WN_SQL3MPrintf("%z ORDER BY",zMsg);
					WN_SQL3VdbeOp3(v,OP_Explain,i,pLevel->iFrom,zMsg,P3_DYNAMIC);
		}
#endif
		pTabItem=&pTabList->a[pLevel->iFrom];
		pTab=pTabItem->pTab;
		iDb=WN_SQL3SchemaToIndex(pParse->db,pTab->pSchema);
		if(pTab->isEphem || pTab->pSelect)continue;
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		if(pLevel->pBestIdx)
		{
			int iCur=pTabItem->iCursor;
			WN_SQL3VdbeOp3(v,OP_VOpen,iCur,0,(const char*)pTab->pVtab,P3_VTAB);
		}
		else
#endif
		if((pLevel->flags & WHERE_IDX_ONLY)==0)
		{
			WN_SQL3OpenTable(pParse,pTabItem->iCursor,iDb,pTab,OP_OpenRead);
			if(pTab->nCol<(sizeof(Bitmask)*8))
			{
				Bitmask b=pTabItem->colUsed;
				int n=0;
				for(;b;b=b>>1,n++);
				WN_SQL3VdbeChangeP2(v,WN_SQL3VdbeCurrentAddr(v)-1,n);
			}
		}
		else
			WN_SQL3TableLock(pParse,iDb,pTab->tnum,0,pTab->zName);
		pLevel->iTabCur=pTabItem->iCursor;
		if((pIx=pLevel->pIdx))
		{
			KeyInfo *pKey=WN_SQL3IndexKeyinfo(pParse,pIx);
			WN_SQL3VdbeAddOp(v,OP_Integer,iDb,0);
			VdbeComment((v,"# %s",pIx->zName));
			WN_SQL3VdbeOp3(v,OP_OpenRead,iIdxCur,pIx->tnum,(char*)pKey,P3_KEYINFO_HANDOFF);
		}
		if((pLevel->flags &(WHERE_IDX_ONLY|WHERE_COLUMN_RANGE)))WN_SQL3VdbeAddOp(v,OP_SetNumColumns,iIdxCur,pIx->nColumn+1);
		WN_SQL3CodeVerifySchema(pParse,iDb);
	}
	pWInfo->iTop=WN_SQL3VdbeCurrentAddr(v);
	notReady=~(Bitmask)0;
	for(i=0,pLevel=pWInfo->a;i<pTabList->nSrc;i++,pLevel++)
	{
		int j,iCur=pTabItem->iCursor,nxt,iIdxCur,omitTable,bRev;
		Index *pIdx;
		pTabItem=&pTabList->a[pLevel->iFrom];
		iCur=pTabItem->iCursor;
		pIdx=pLevel->pIdx;
		iIdxCur=pLevel->iIdxCur;
		bRev=(pLevel->flags & WHERE_REVERSE)!=0;
		omitTable=(pLevel->flags & WHERE_IDX_ONLY)!=0;
		brk=pLevel->brk=pLevel->nxt=WN_SQL3VdbeMakeLabel(v);
		cont=pLevel->cont=WN_SQL3VdbeMakeLabel(v);
		if(pLevel->iFrom>0 &&(pTabItem[0].jointype & JT_LEFT))
		{
			if(!pParse->nMem)pParse->nMem++;
			pLevel->iLeftJoin=pParse->nMem++;
			WN_SQL3VdbeAddOp(v,OP_MemInt,0,pLevel->iLeftJoin);
			VdbeComment((v,"# init LEFT JOIN no-match flag"));
		}
#ifndef WN_SQL_OMIT_VIRTUALTABLE
		if(pLevel->pBestIdx)
		{
			int j;
			WN_SQL3_index_info *pBestIdx=pLevel->pBestIdx;
			int nConstraint=pBestIdx->nConstraint;
			struct WN_SQL3_index_constraint_usage *aUsage=pBestIdx->aConstraintUsage;
			const struct WN_SQL3_index_constraint *aConstraint=pBestIdx->aConstraint;
			for(j=1;j<=nConstraint;j++)
			{
				int k;
				for(k=0;k<nConstraint;k++)
					if(aUsage[k].argvIndex==j)
					{
						int iTerm=aConstraint[k].iTermOffset;
						WN_SQL3ExprCode(pParse,wc.a[iTerm].pExpr->pRight);
						break;
					}
				if(k==nConstraint)break;
			}
			WN_SQL3VdbeAddOp(v,OP_Integer,j-1,0);
			WN_SQL3VdbeAddOp(v,OP_Integer,pBestIdx->idxNum,0);
			WN_SQL3VdbeOp3(v,OP_VFilter,iCur,brk,pBestIdx->idxStr,pBestIdx->needToFreeIdxStr ? P3_MPRINTF :P3_STATIC);
			pBestIdx->needToFreeIdxStr=0;
			for(j=0;j<pBestIdx->nConstraint;j++)
				if(aUsage[j].omit)
				{
					int iTerm=aConstraint[j].iTermOffset;
					disableTerm(pLevel,&wc.a[iTerm]);
				}
			pLevel->op=OP_VNext;
			pLevel->p1=iCur;
			pLevel->p2=WN_SQL3VdbeCurrentAddr(v);
		}
		else
#endif
		if(pLevel->flags & WHERE_ROWID_EQ)
		{
			pTerm=findTerm(&wc,iCur,-1,notReady,WO_EQ|WO_IN,0);
			codeEqualityTerm(pParse,pTerm,pLevel);
			nxt=pLevel->nxt;
			WN_SQL3VdbeAddOp(v,OP_MustBeInt,1,nxt);
			WN_SQL3VdbeAddOp(v,OP_NotExists,iCur,nxt);
			VdbeComment((v,"pk"));
			pLevel->op=OP_Noop;
		}
		else
			if(pLevel->flags & WHERE_ROWID_RANGE)
			{
				int testOp=OP_Noop,start;
				WhereTerm *pStart=findTerm(&wc,iCur,-1,notReady,WO_GT|WO_GE,0),*pEnd=findTerm(&wc,iCur,-1,notReady,WO_LT|WO_LE,0);
				if(bRev)
				{
					pTerm=pStart;
					pStart=pEnd;
					pEnd=pTerm;
				}
				if(pStart)
				{
					Expr *pX;
					pX=pStart->pExpr;
					WN_SQL3ExprCode(pParse,pX->pRight);
					WN_SQL3VdbeAddOp(v,OP_ForceInt,pX->op==TK_LE || pX->op==TK_GT,brk);
					WN_SQL3VdbeAddOp(v,bRev ? OP_MoveLt :OP_MoveGe,iCur,brk);
					VdbeComment((v,"pk"));
					disableTerm(pLevel,pStart);
				}
				else
					WN_SQL3VdbeAddOp(v,bRev ? OP_Last :OP_Rewind,iCur,brk);
				if(pEnd)
				{
					Expr *pX;
					pX=pEnd->pExpr;
					WN_SQL3ExprCode(pParse,pX->pRight);
					pLevel->iMem=pParse->nMem++;
					WN_SQL3VdbeAddOp(v,OP_MemStore,pLevel->iMem,1);
					if(pX->op==TK_LT || pX->op==TK_GT)
						testOp=bRev ? OP_Le :OP_Ge;
					else
						testOp=bRev ? OP_Lt :OP_Gt;
					disableTerm(pLevel,pEnd);
				}
				start=WN_SQL3VdbeCurrentAddr(v);
				pLevel->op=bRev ? OP_Prev :OP_Next;
				pLevel->p1=iCur;
				pLevel->p2=start;
				if(testOp!=OP_Noop)
				{
					WN_SQL3VdbeAddOp(v,OP_Rowid,iCur,0);
					WN_SQL3VdbeAddOp(v,OP_MemLoad,pLevel->iMem,0);
					WN_SQL3VdbeAddOp(v,testOp,WN_SQL_AFF_NUMERIC|0x100,brk);
				}
			}
			else
				if(pLevel->flags & WHERE_COLUMN_RANGE)
				{
					int start,nEq=pLevel->nEq,topEq=0,btmEq=0,topOp,btmOp,testOp,topLimit=(pLevel->flags & WHERE_TOP_LIMIT)!=0,btmLimit=(pLevel->flags & WHERE_BTM_LIMIT)!=0;
					codeAllEqualityTerms(pParse,pLevel,&wc,notReady);
					for(j=0;j<nEq;j++)WN_SQL3VdbeAddOp(v,OP_Dup,nEq-1,0);
					if(pIdx->aSortOrder[nEq]==WN_SQL_SO_ASC)
					{
						topOp=WO_LT|WO_LE;
						btmOp=WO_GT|WO_GE;
					}
					else
					{
						topOp=WO_GT|WO_GE;
						btmOp=WO_LT|WO_LE;
						SWAP(int,topLimit,btmLimit);
					}
					nxt=pLevel->nxt;
					if(topLimit)
					{
						Expr *pX;
						int k=pIdx->aiColumn[j];
						pTerm=findTerm(&wc,iCur,k,notReady,topOp,pIdx);
						pX=pTerm->pExpr;
						WN_SQL3ExprCode(pParse,pX->pRight);
						WN_SQL3VdbeAddOp(v,OP_IsNull,-(nEq*2+1),nxt);
						topEq=pTerm->eOperator &(WO_LE|WO_GE);
						disableTerm(pLevel,pTerm);
						testOp=OP_IdxGE;
					}
					else
					{
						testOp=nEq>0 ? OP_IdxGE :OP_Noop;
						topEq=1;
					}
					if(testOp!=OP_Noop)
					{
						int nCol=nEq+topLimit;
						pLevel->iMem=pParse->nMem++;
						buildIndexProbe(v,nCol,pIdx);
						if(bRev)
						{
							int op=topEq ? OP_MoveLe :OP_MoveLt;
							WN_SQL3VdbeAddOp(v,op,iIdxCur,nxt);
						}
						else
							WN_SQL3VdbeAddOp(v,OP_MemStore,pLevel->iMem,1);
					}
					else
						if(bRev)WN_SQL3VdbeAddOp(v,OP_Last,iIdxCur,brk);
					if(btmLimit)
					{
						int k=pIdx->aiColumn[j];
						pTerm=findTerm(&wc,iCur,k,notReady,btmOp,pIdx);
						Expr *pX=pTerm->pExpr;
						WN_SQL3ExprCode(pParse,pX->pRight);
						WN_SQL3VdbeAddOp(v,OP_IsNull,-(nEq+1),nxt);
						btmEq=pTerm->eOperator &(WO_LE|WO_GE);
						disableTerm(pLevel,pTerm);
					}
					else
						btmEq=1;
					if(nEq>0 || btmLimit)
					{
						int nCol=nEq+btmLimit;
						buildIndexProbe(v,nCol,pIdx);
						if(bRev)
						{
							pLevel->iMem=pParse->nMem++;
							WN_SQL3VdbeAddOp(v,OP_MemStore,pLevel->iMem,1);
							testOp=OP_IdxLT;
						}
						else
						{
							int op=btmEq ? OP_MoveGe :OP_MoveGt;
							WN_SQL3VdbeAddOp(v,op,iIdxCur,nxt);
						}
					}
					else
						if(bRev)
							testOp=OP_Noop;
						else
							WN_SQL3VdbeAddOp(v,OP_Rewind,iIdxCur,brk);
					start=WN_SQL3VdbeCurrentAddr(v);
					if(testOp!=OP_Noop)
					{
						WN_SQL3VdbeAddOp(v,OP_MemLoad,pLevel->iMem,0);
						WN_SQL3VdbeAddOp(v,testOp,iIdxCur,nxt);
						if((topEq && !bRev)||(!btmEq && bRev))WN_SQL3VdbeChangeP3(v,-1,"+",P3_STATIC);
					}
					if(topLimit | btmLimit)
					{
						WN_SQL3VdbeAddOp(v,OP_Column,iIdxCur,nEq);
						WN_SQL3VdbeAddOp(v,OP_IsNull,1,cont);
					}
					if(!omitTable)
					{
						WN_SQL3VdbeAddOp(v,OP_IdxRowid,iIdxCur,0);
						WN_SQL3VdbeAddOp(v,OP_MoveGe,iCur,0);
					}
					pLevel->op=bRev ? OP_Prev :OP_Next;
					pLevel->p1=iIdxCur;
					pLevel->p2=start;
}
else
	if(pLevel->flags & WHERE_COLUMN_EQ)
	{
		int start,nEq=pLevel->nEq;
		codeAllEqualityTerms(pParse,pLevel,&wc,notReady);
		nxt=pLevel->nxt;
		buildIndexProbe(v,nEq,pIdx);
		WN_SQL3VdbeAddOp(v,OP_MemStore,pLevel->iMem,0);
		if(bRev)
		{
			WN_SQL3VdbeAddOp(v,OP_MoveLe,iIdxCur,nxt);
			start=WN_SQL3VdbeAddOp(v,OP_MemLoad,pLevel->iMem,0);
			WN_SQL3VdbeAddOp(v,OP_IdxLT,iIdxCur,nxt);
			pLevel->op=OP_Prev;
		}
		else
		{
			WN_SQL3VdbeAddOp(v,OP_MoveGe,iIdxCur,nxt);
			start=WN_SQL3VdbeAddOp(v,OP_MemLoad,pLevel->iMem,0);
			WN_SQL3VdbeOp3(v,OP_IdxGE,iIdxCur,nxt,"+",P3_STATIC);
			pLevel->op=OP_Next;
		}
		if(!omitTable)
		{
			WN_SQL3VdbeAddOp(v,OP_IdxRowid,iIdxCur,0);
			WN_SQL3VdbeAddOp(v,OP_MoveGe,iCur,0);
		}
		pLevel->p1=iIdxCur;
		pLevel->p2=start;
	}
	else
	{
		pLevel->op=OP_Next;
		pLevel->p1=iCur;
		pLevel->p2=1+WN_SQL3VdbeAddOp(v,OP_Rewind,iCur,brk);
	}
	notReady &=~getMask(&maskSet,iCur);
	for(pTerm=wc.a,j=wc.nTerm;j>0;j--,pTerm++)
	{
		if(pTerm->flags &(TERM_VIRTUAL|TERM_CODED))continue;
		if((pTerm->prereqAll & notReady))continue;
		Expr *pE=pTerm->pExpr;
		if(pLevel->iLeftJoin && !ExprHasProperty(pE,EP_FromJoin))continue;
		WN_SQL3ExprIfFalse(pParse,pE,cont,1);
		pTerm->flags |=TERM_CODED;
	}
	if(pLevel->iLeftJoin)
	{
		pLevel->top=WN_SQL3VdbeCurrentAddr(v);
		WN_SQL3VdbeAddOp(v,OP_MemInt,1,pLevel->iLeftJoin);
		VdbeComment((v,"# record LEFT JOIN hit"));
		for(pTerm=wc.a,j=0;j<wc.nTerm;j++,pTerm++)
		{
			if(pTerm->flags &(TERM_VIRTUAL|TERM_CODED))continue;
			if((pTerm->prereqAll & notReady))continue;
			WN_SQL3ExprIfFalse(pParse,pTerm->pExpr,cont,1);
			pTerm->flags |=TERM_CODED;
		}
	}
}
#ifdef WN_SQL_TEST
	for(i=0;i<pTabList->nSrc;i++)
	{
		pLevel=&pWInfo->a[i];
		pTabItem=&pTabList->a[pLevel->iFrom];
		char *z=pTabItem->zAlias;
		if(z==0)z=pTabItem->pTab->zName;
		int n=strlen(z);
		if(n+nQPlan<sizeof(WN_SQL3_query_plan)-10)
		{
			if(pLevel->flags & WHERE_IDX_ONLY)
			{
				memcpy(&WN_SQL3_query_plan[nQPlan],"{}",2);
				nQPlan+=2;
			}
			else
			{
				memcpy(&WN_SQL3_query_plan[nQPlan],z,n);
				nQPlan+=n;
			}
			WN_SQL3_query_plan[nQPlan++]=' ';
		}
		if(pLevel->flags &(WHERE_ROWID_EQ|WHERE_ROWID_RANGE))
		{
			memcpy(&WN_SQL3_query_plan[nQPlan],"* ",2);
			nQPlan+=2;
		}
		else
			if(pLevel->pIdx==0)
			{
				memcpy(&WN_SQL3_query_plan[nQPlan],"{}",3);
				nQPlan+=3;
			}
			else
			{
				n=strlen(pLevel->pIdx->zName);
				if(n+nQPlan<sizeof(WN_SQL3_query_plan)-2)
				{
					memcpy(&WN_SQL3_query_plan[nQPlan],pLevel->pIdx->zName,n);
					nQPlan+=n;
					WN_SQL3_query_plan[nQPlan++]=' ';
				}
			}
	}
	while(nQPlan>0 && WN_SQL3_query_plan[nQPlan-1]==' ')WN_SQL3_query_plan[--nQPlan]=0;
	WN_SQL3_query_plan[nQPlan]=0;
	nQPlan=0;
#endif
	pWInfo->iContinue=cont;
	whereClauseClear(&wc);
	return pWInfo;
whereBeginNoMem:
	whereClauseClear(&wc);
	whereInfoFree(pWInfo);
	return 0;
}
void WN_SQL3WhereEnd(WhereInfo *pWInfo)
{
	Vdbe *v=pWInfo->pParse->pVdbe;
	int i;
	WhereLevel *pLevel;
	SrcList *pTabList=pWInfo->pTabList;
	for(i=pTabList->nSrc-1;i>=0;i--)
	{
		pLevel=&pWInfo->a[i];
		WN_SQL3VdbeResolveLabel(v,pLevel->cont);
		if(pLevel->op!=OP_Noop)WN_SQL3VdbeAddOp(v,pLevel->op,pLevel->p1,pLevel->p2);
		if(pLevel->nIn)
		{
			struct InLoop *pIn;
			int j;
			WN_SQL3VdbeResolveLabel(v,pLevel->nxt);
			for(j=pLevel->nIn,pIn=&pLevel->aInLoop[j-1];j>0;j--,pIn--)
			{
				WN_SQL3VdbeJumpHere(v,pIn->topAddr+1);
				WN_SQL3VdbeAddOp(v,OP_Next,pIn->iCur,pIn->topAddr);
				WN_SQL3VdbeJumpHere(v,pIn->topAddr-1);
			}
			WN_SQL3FreeX(pLevel->aInLoop);
		}
		WN_SQL3VdbeResolveLabel(v,pLevel->brk);
		if(pLevel->iLeftJoin)
		{
			int addr=WN_SQL3VdbeAddOp(v,OP_IfMemPos,pLevel->iLeftJoin,0);
			WN_SQL3VdbeAddOp(v,OP_NullRow,pTabList->a[i].iCursor,0);
			if(pLevel->iIdxCur>=0)WN_SQL3VdbeAddOp(v,OP_NullRow,pLevel->iIdxCur,0);
			WN_SQL3VdbeAddOp(v,OP_Goto,0,pLevel->top);
			WN_SQL3VdbeJumpHere(v,addr);
		}
	}
	WN_SQL3VdbeResolveLabel(v,pWInfo->iBreak);
	for(i=0,pLevel=pWInfo->a;i<pTabList->nSrc;i++,pLevel++)
	{
		struct SrcList_item *pTabItem=&pTabList->a[pLevel->iFrom];
		Table *pTab=pTabItem->pTab;
		if(pTab->isEphem || pTab->pSelect)continue;
		if((pLevel->flags & WHERE_IDX_ONLY)==0)WN_SQL3VdbeAddOp(v,OP_Close,pTabItem->iCursor,0);
		if(pLevel->pIdx)WN_SQL3VdbeAddOp(v,OP_Close,pLevel->iIdxCur,0);
		if(pLevel->flags & WHERE_IDX_ONLY)
		{
			int k,j,last;
			Index *pIdx=pLevel->pIdx;
			VdbeOp *pOp=WN_SQL3VdbeGetOp(v,pWInfo->iTop);
			last=WN_SQL3VdbeCurrentAddr(v);
			for(k=pWInfo->iTop;k<last;k++,pOp++)
			{
				if(pOp->p1!=pLevel->iTabCur)continue;
				if(pOp->opcode==OP_Column)
				{
					pOp->p1=pLevel->iIdxCur;
					for(j=0;j<pIdx->nColumn;j++)
						if(pOp->p2==pIdx->aiColumn[j])
						{
							pOp->p2=j;
							break;
						}
				}
				else
					if(pOp->opcode==OP_Rowid)
					{
						pOp->p1=pLevel->iIdxCur;
						pOp->opcode=OP_IdxRowid;
					}
					else
						if(pOp->opcode==OP_NullRow)	pOp->opcode=OP_Noop;
			}
		}
	}
	whereInfoFree(pWInfo);
	return;
}
struct LimitVal
{
	Expr *pLimit,*pOffset;
};
struct LikeOp
{
	Token eOperator;
	int not;
};
struct TrigEvent
{
	int a;
	IdList * b;
};
struct AttachKey
{
	int type;
	Token key;
};
#ifndef INTERFACE
# define INTERFACE 1
#endif
#define YYCODETYPE unsigned char
#define YYNOCODE 248
#define YYACTIONTYPE unsigned short int
#define YYWILDCARD 59
#define WN_SQL3ParserTOKENTYPE Token
typedef union
{
	WN_SQL3ParserTOKENTYPE yy0;
	int yy46;
	struct LikeOp yy72;
	Expr* yy172;
	ExprList* yy174;
	Select* yy219;
	struct LimitVal yy234;
	TriggerStep* yy243;
	struct TrigEvent yy370;
	SrcList* yy373;
	Expr * yy386;
	struct
	{	int value,mask;
	}yy405;
	Token yy410;
	IdList* yy432;
	int yy495;
}YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define WN_SQL3ParserARG_SDECL Parse *pParse;
#define WN_SQL3ParserARG_PDECL ,Parse *pParse
#define WN_SQL3ParserARG_FETCH Parse *pParse=yypParser->pParse
#define WN_SQL3ParserARG_STORE yypParser->pParse=pParse
#define YYNSTATE 586
#define YYNRULE 311
#define YYERRORSYMBOL 138
#define YYERRSYMDT yy495
#define YYFALLBACK 1
#define YY_NO_ACTION(YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION(YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION(YYNSTATE+YYNRULE)
const YYACTIONTYPE yy_action[]={290,898,122,585,407,170,2,437,61,61,61,61,517,63,63,63,63,64,64,65,65,65,66,231,445,209,422,428,68,63,63,63,63,64,64,65,65,65,66,231,389,386,394,449,60,59,295,432,433,429,429,62,62,61,61,61,61,261,63,63,63,63,64,64,65,65,65,66,231,290,491,492,437,487,206,81,67,417,69,152,63,63,63,63,64,64,65,65,65,66,231,67,460,69,152,422,428,571,262,58,64,64,65,65,65,66,231,395,396,419,419,419,290,60,59,295,432,433,429,429,62,62,61,61,61,61,315,63,63,63,63,64,64,65,65,65,66,231,422,428,93,65,65,65,66,231,394,231,412,34,56,296,440,441,408,486,60,59,295,432,433,429,429,62,62,61,61,61,61,488,63,63,63,63,64,64,65,65,65,66,231,290,255,522,293,569,112,406,520,449,329,315,405,20,437,338,517,394,530,529,503,445,209,568,567,206,528,422,428,147,148,395,396,412,41,208,149,531,370,487,259,566,257,417,290,60,59,295,432,433,429,429,62,62,61,61,61,61,315,63,63,63,63,64,64,65,65,65,66,231,422,428,445,331,212,419,419,419,361,437,412,41,395,396,364,565,208,290,60,59,295,432,433,429,429,62,62,61,61,61,61,394,63,63,63,63,64,64,65,65,65,66,231,422,428,489,298,522,472,66,231,211,472,224,409,284,532,20,447,521,166,60,59,295,432,433,429,429,62,62,61,61,61,61,472,63,63,63,63,64,64,65,65,65,66,231,207,478,315,76,290,235,298,55,482,225,395,396,179,545,492,343,346,347,67,150,69,152,337,522,412,35,348,237,249,368,422,428,576,20,162,116,239,341,244,342,174,320,440,441,412,3,79,250,60,59,295,432,433,429,429,62,62,61,61,61,61,172,63,63,63,63,64,64,65,65,65,66,231,290,249,548,232,485,508,351,315,116,239,341,244,342,174,179,315,523,343,346,347,250,218,413,153,462,509,422,428,348,412,34,463,208,175,173,158,233,412,34,336,547,447,321,166,60,59,295,432,433,429,429,62,62,61,61,61,61,413,63,63,63,63,64,64,65,65,65,66,231,290,540,333,515,502,539,454,569,300,19,329,142,315,388,315,328,2,360,455,292,481,371,267,266,250,568,422,428,586,389,386,456,206,493,412,49,412,49,301,583,889,157,889,494,60,59,295,432,433,429,429,62,62,61,61,61,61,199,63,63,63,63,64,64,65,65,65,66,231,290,315,179,436,253,343,346,347,368,151,580,306,248,307,450,75,348,77,380,208,423,424,413,412,27,317,422,428,438,1,22,583,888,394,888,542,476,318,261,435,435,426,427,413,60,59,295,432,433,429,429,62,62,61,61,61,61,326,63,63,63,63,64,64,65,65,65,66,231,290,425,580,372,219,92,515,9,334,394,555,394,454,67,394,69,152,397,398,399,318,234,435,435,455,316,422,428,297,395,396,318,430,435,435,579,289,456,220,325,5,217,544,290,60,59,295,432,433,429,429,62,62,61,61,61,61,393,63,63,63,63,64,64,65,65,65,66,231,422,428,480,311,390,395,396,395,396,205,395,396,821,271,515,248,198,290,60,59,295,432,433,429,429,62,62,61,61,61,61,468,63,63,63,63,64,64,65,65,65,66,231,422,428,169,158,261,261,302,413,274,117,272,261,515,515,261,515,190,290,60,70,295,432,433,429,429,62,62,61,61,61,61,377,63,63,63,63,64,64,65,65,65,66,231,422,428,382,557,303,304,248,413,318,558,435,435,559,538,358,538,385,290,194,59,295,432,433,429,429,62,62,61,61,61,61,369,63,63,63,63,64,64,65,65,65,66,231,422,428,394,273,248,248,170,246,437,413,384,365,176,177,178,467,309,121,154,126,295,432,433,429,429,62,62,61,61,61,61,315,63,63,63,63,64,64,65,65,65,66,231,72,322,175,4,315,261,315,294,261,413,412,28,315,261,315,319,72,322,315,4,418,443,443,294,395,396,412,23,412,32,437,319,324,327,412,53,412,52,315,156,412,97,449,315,192,315,275,315,324,376,469,500,315,476,277,476,163,292,449,315,412,95,74,73,467,412,100,412,101,412,111,72,313,314,412,113,417,446,74,73,479,412,16,379,315,181,465,72,313,314,72,322,417,4,206,315,184,294,315,497,498,474,206,171,339,319,412,98,419,419,419,420,421,11,359,378,305,412,33,413,412,96,324,458,419,419,419,420,421,11,413,411,449,411,160,410,315,410,466,221,222,223,103,83,471,315,507,506,315,620,475,315,74,73,245,203,21,279,412,24,437,72,313,314,280,315,417,412,54,505,412,114,315,412,115,504,201,145,547,240,510,524,200,315,511,202,315,412,25,315,241,315,18,315,412,36,315,254,419,419,419,420,421,11,256,412,37,258,412,26,315,412,38,412,39,412,40,260,412,42,315,512,315,126,315,437,315,187,375,276,266,265,412,43,291,315,252,315,126,206,581,8,412,44,412,29,412,30,412,45,350,363,126,315,543,315,126,412,46,412,47,315,355,381,551,315,171,552,315,90,562,578,90,288,366,412,48,412,31,582,367,268,269,412,10,270,554,412,50,564,412,51,278,281,282,575,144,442,403,323,226,444,461,464,242,503,550,561,513,161,392,400,516,401,345,402,7,312,83,227,332,228,82,330,57,408,416,168,78,459,123,210,414,84,335,340,299,496,500,490,229,495,243,104,247,499,501,230,285,415,215,514,518,525,526,519,236,527,473,238,352,477,286,182,356,533,354,119,183,185,87,546,130,186,535,188,140,362,191,553,216,373,374,131,560,308,132,133,572,577,136,263,134,139,536,573,391,91,94,404,574,99,214,102,621,622,431,164,434,165,71,141,17,439,448,451,155,6,452,470,110,167,453,457,124,13,213,120,80,12,125,159,483,484,85,310,105,180,251,106,118,86,107,241,344,349,353,143,534,127,357,171,189,264,108,287,128,549,129,193,537,541,14,195,88,196,556,197,137,138,135,15,563,570,109,283,146,204,383,387,899,584,899,899,899,899,899,89,};
const YYCODETYPE yy_lookahead[]={16,139,140,141,168,21,144,23,69,70,71,72,176,74,75,76,77,78,79,80,81,82,83,84,78,79,42,43,73,74,75,76,77,78,79,80,81,82,83,84,1,2,23,58,60,61,62,63,64,65,66,67,68,69,70,71,72,147,74,75,76,77,78,79,80,81,82,83,84,16,185,186,88,88,110,22,217,92,219,220,74,75,76,77,78,79,80,81,82,83,84,217,218,219,220,42,43,238,188,46,78,79,80,81,82,83,84,88,89,124,125,126,16,60,61,62,63,64,65,66,67,68,69,70,71,72,147,74,75,76,77,78,79,80,81,82,83,84,42,43,44,80,81,82,83,84,23,84,169,170,19,164,165,166,23,169,60,61,62,63,64,65,66,67,68,69,70,71,72,169,74,75,76,77,78,79,80,81,82,83,84,16,14,147,150,147,21,167,168,58,211,147,156,157,23,216,176,23,181,176,177,78,79,165,166,110,183,42,43,78,79,88,89,169,170,228,180,181,123,88,52,98,54,92,16,60,61,62,63,64,65,66,67,68,69,70,71,72,147,74,75,76,77,78,79,80,81,82,83,84,42,43,78,209,210,124,125,126,224,88,169,170,88,89,230,227,228,16,60,61,62,63,64,65,66,67,68,69,70,71,72,23,74,75,76,77,78,79,80,81,82,83,84,42,43,160,16,147,161,83,84,210,161,153,169,158,156,157,161,162,163,60,61,62,63,64,65,66,67,68,69,70,71,72,161,74,75,76,77,78,79,80,81,82,83,84,192,200,147,131,16,200,16,199,20,190,88,89,90,185,186,93,94,95,217,22,219,220,147,147,169,170,104,200,84,147,42,43,156,157,90,91,92,93,94,95,96,164,165,166,169,170,131,103,60,61,62,63,64,65,66,67,68,69,70,71,72,155,74,75,76,77,78,79,80,81,82,83,84,16,84,11,221,20,30,16,147,91,92,93,94,95,96,90,147,181,93,94,95,103,212,189,155,27,50,42,43,104,169,170,34,228,43,201,202,147,169,170,206,49,161,162,163,60,61,62,63,64,65,66,67,68,69,70,71,72,189,74,75,76,77,78,79,80,81,82,83,84,16,25,211,147,20,29,12,147,102,19,211,21,147,141,147,216,144,41,24,98,20,99,100,101,103,165,42,43,0,1,2,37,110,39,169,170,169,170,182,19,20,147,22,49,60,61,62,63,64,65,66,67,68,69,70,71,72,155,74,75,76,77,78,79,80,81,82,83,84,16,147,90,20,20,93,94,95,147,155,59,215,225,215,20,130,104,132,227,228,42,43,189,169,170,16,42,43,20,19,22,19,20,23,22,18,147,106,147,108,109,63,64,189,60,61,62,63,64,65,66,67,68,69,70,71,72,186,74,75,76,77,78,79,80,81,82,83,84,16,92,59,55,212,21,147,19,147,23,188,23,12,217,23,219,220,7,8,9,106,147,108,109,24,147,42,43,208,88,89,106,92,108,109,244,245,37,145,39,191,182,94,16,60,61,62,63,64,65,66,67,68,69,70,71,72,147,74,75,76,77,78,79,80,81,82,83,84,42,43,80,142,143,88,89,88,89,148,88,89,133,14,147,225,155,16,60,61,62,63,64,65,66,67,68,69,70,71,72,114,74,75,76,77,78,79,80,81,82,83,84,42,43,201,202,147,147,182,189,52,147,54,147,147,147,147,147,155,16,60,61,62,63,64,65,66,67,68,69,70,71,72,213,74,75,76,77,78,79,80,81,82,83,84,42,43,188,188,182,182,225,189,106,188,108,109,188,99,100,101,241,16,155,61,62,63,64,65,66,67,68,69,70,71,72,213,74,75,76,77,78,79,80,81,82,83,84,42,43,23,133,225,225,21,225,23,189,239,236,99,100,101,22,242,243,155,22,62,63,64,65,66,67,68,69,70,71,72,147,74,75,76,77,78,79,80,81,82,83,84,16,17,43,19,147,147,147,23,147,189,169,170,147,147,147,31,16,17,147,19,147,124,125,23,88,89,169,170,169,170,88,31,48,147,169,170,169,170,147,89,169,170,58,147,22,147,188,147,48,188,114,97,147,147,188,147,19,98,58,147,169,170,78,79,114,169,170,169,170,169,170,87,88,89,169,170,92,161,78,79,80,169,170,91,147,155,22,87,88,89,16,17,92,19,110,147,155,23,147,7,8,20,110,22,80,31,169,170,124,125,126,127,128,129,208,123,208,169,170,189,169,170,48,147,124,125,126,127,128,129,189,107,58,107,5,111,147,111,203,10,11,12,13,121,147,147,91,92,147,112,147,147,78,79,147,26,19,28,169,170,23,87,88,89,35,147,92,169,170,178,169,170,147,169,170,147,47,113,49,92,178,147,53,147,178,56,147,169,170,147,103,147,19,147,169,170,147,147,124,125,126,127,128,129,147,169,170,147,169,170,147,169,170,169,170,169,170,147,169,170,147,20,147,22,147,88,147,232,99,100,101,147,169,170,105,147,20,147,22,110,20,68,169,170,169,170,169,170,169,170,20,147,22,147,20,147,22,169,170,169,170,147,233,134,20,147,22,20,147,22,20,20,22,22,147,169,170,169,170,59,147,147,147,169,170,147,147,169,170,147,169,170,147,147,147,147,191,229,149,223,193,229,172,172,172,177,194,194,172,6,146,146,172,146,173,146,22,154,121,194,118,195,119,116,120,23,160,112,130,152,152,222,189,98,115,98,40,179,97,171,196,171,171,19,84,173,171,197,174,198,226,160,160,171,171,179,204,171,205,204,15,205,174,151,38,152,152,60,151,151,130,184,19,152,152,151,214,152,184,194,226,152,15,187,194,152,187,187,33,137,184,234,187,214,235,152,1,237,237,20,152,159,175,175,112,112,92,112,107,112,19,19,231,20,20,11,19,117,20,114,240,22,20,20,19,117,44,243,22,22,20,112,20,20,19,246,19,96,20,19,32,19,19,103,44,44,16,21,17,98,36,22,98,133,19,5,45,1,102,122,51,45,19,113,68,14,17,115,102,122,113,19,123,20,14,136,19,135,57,3,247,4,247,247,247,247,247,68,};
#define YY_SHIFT_USE_DFLT (-62)
#define YY_SHIFT_MAX 387
const short yy_shift_ofst[]={39,841,986,-16,841,931,931,258,123,-36,96,931,931,931,931,931,-45,400,174,19,171,-54,-54,53,165,208,251,324,393,462,531,600,643,686,643,643,643,643,643,643,643,643,643,643,643,643,643,643,643,643,643,643,729,772,772,857,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,931,-61,-61,6,6,280,22,61,399,564,19,19,19,19,19,19,19,216,171,63,-62,-62,131,326,472,472,498,559,506,799,19,799,19,19,19,19,19,19,19,19,19,19,19,19,19,849,95,-36,-36,-36,-62,-62,-62,-15,-15,333,459,478,557,530,541,616,602,793,604,607,626,19,19,881,19,19,994,19,19,807,19,19,673,807,19,19,384,384,384,19,19,673,19,19,673,19,454,685,19,19,673,19,19,19,673,19,19,19,673,673,19,19,19,19,19,468,883,921,754,754,432,406,406,406,816,406,406,811,879,879,1160,1160,1160,1160,1151,-36,1054,1059,1060,1064,1061,1159,1055,1072,1072,1092,1076,1092,1076,1094,1094,1153,1094,1098,1094,1181,1117,1159,1117,1159,1153,1094,1094,1094,1181,1202,1072,1202,1072,1202,1072,1072,1183,1097,1202,1072,1164,1164,1210,1054,1072,1224,1224,1224,1224,1054,1164,1210,1072,1212,1212,1072,1072,1109,-62,-62,-62,-62,-62,-62,525,684,727,168,894,556,555,938,944,949,912,1058,1073,1087,1091,1101,1104,1107,1030,1108,1077,1252,1236,1149,1150,1152,1154,1171,1158,1248,1250,1251,1249,1261,1254,1255,1256,1259,1260,1263,1157,1264,1165,1263,1162,1262,1267,1176,1269,1270,1265,1239,1272,1257,1274,1275,1277,1279,1258,1280,1198,1197,1287,1288,1283,1208,1271,1266,1268,1286,1273,1177,1211,1292,1307,1313,1213,1253,1276,1194,1300,1207,1308,1209,1306,1214,1223,1204,1309,1206,1310,1317,1278,1199,1196,1314,1333,1334,};
#define YY_REDUCE_USE_DFLT (-165)
#define YY_REDUCE_MAX 289
const short yy_reduce_ofst[]={-138,277,546,137,401,-21,44,36,38,242,-141,191,91,269,343,345,-126,589,338,150,147,-13,213,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,412,211,698,714,716,722,724,728,748,753,755,757,762,769,794,805,808,846,855,858,861,875,882,893,896,899,901,903,906,920,930,932,934,936,945,947,963,965,971,975,978,412,412,412,412,20,412,412,23,34,334,475,552,593,594,585,212,412,289,412,412,412,135,-164,-115,164,407,407,350,141,436,163,596,-90,763,218,765,438,586,592,595,715,718,408,723,380,634,677,787,798,144,529,588,-14,0,17,244,155,298,155,155,418,372,477,490,494,509,526,590,465,494,730,773,743,833,792,854,860,155,792,864,885,848,859,863,891,907,155,914,917,155,927,852,886,941,961,155,984,990,991,155,992,995,996,155,155,999,1002,1003,1004,1005,1006,962,964,925,929,933,987,988,989,985,993,997,998,969,970,1021,1022,1024,1026,1020,1000,982,983,1001,1007,1008,1023,966,1034,1035,1009,1010,1012,1013,1025,1027,1015,1028,1029,1032,1031,981,1048,1011,1049,1033,1039,1040,1043,1045,1069,1070,1074,1071,1075,1078,1079,1014,1016,1081,1082,1044,1051,1019,1042,1086,1053,1056,1057,1062,1047,1063,1036,1090,1017,1018,1100,1105,1037,1099,1084,1085,1038,1041,1046,};
const YYACTIONTYPE yy_default[]={592,816,897,707,897,816,897,897,843,711,872,814,897,897,897,897,789,897,843,897,623,843,843,740,897,897,897,897,897,897,897,897,741,897,818,813,809,811,810,817,742,731,738,745,723,856,747,748,754,755,873,871,777,776,795,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,779,800,778,788,616,780,781,676,611,897,897,897,897,897,897,897,782,897,783,796,797,897,897,897,897,897,897,592,707,897,707,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,701,711,890,897,897,667,897,897,897,897,897,897,897,897,897,897,599,597,897,699,897,897,625,897,897,709,897,897,714,715,897,897,897,897,897,897,897,613,897,897,688,897,849,897,897,897,863,897,897,897,861,897,897,897,690,750,830,897,876,878,897,897,699,708,897,897,812,734,734,734,646,734,734,649,744,744,596,596,596,596,666,897,744,735,737,727,739,897,897,716,716,724,726,724,726,678,678,663,678,649,678,822,827,897,827,897,663,678,678,678,822,608,716,608,716,608,716,716,853,855,608,716,680,680,756,744,716,687,687,687,687,744,680,756,716,875,875,716,716,883,633,651,651,858,890,895,897,897,897,897,763,897,897,897,897,897,897,897,897,897,897,897,897,897,836,897,897,897,897,768,764,897,765,897,693,897,897,897,897,897,897,897,897,897,897,815,897,728,897,736,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,851,852,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,897,882,897,897,885,593,897,587,590,589,591,595,598,620,621,622,600,601,602,603,604,605,606,612,614,632,634,618,636,697,698,760,691,692,696,771,762,766,767,769,770,784,785,787,793,799,802,786,791,792,794,798,801,694,695,805,619,626,627,630,631,839,841,840,842,629,628,772,775,807,808,864,865,866,867,868,803,717,806,790,729,732,733,730,700,710,719,720,721,722,705,706,712,725,758,759,713,702,703,704,804,761,773,774,637,638,768,639,640,641,679,682,683,684,642,661,664,665,643,650,644,645,652,653,654,657,658,659,660,655,656,823,824,828,826,825,647,648,662,635,624,617,668,671,672,673,674,675,677,669,670,615,607,609,718,845,854,850,846,847,848,610,819,820,681,752,753,844,857,859,757,860,862,887,685,686,689,829,869,743,746,749,751,831,832,833,834,837,838,835,870,874,877,879,880,881,884,886,891,892,893,896,894,594,588,};
#define YY_SZ_ACTTAB(int)(sizeof(yy_action)/sizeof(yy_action[0]))
#ifdef YYFALLBACK
const YYCODETYPE yyFallback[]={0,0,23,23,23,23,0,23,23,23,0,23,0,0,0,23,0,0,23,0,0,0,0,0,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#endif
struct yyStackEntry
{
	int stateno,major;
	YYMINORTYPE minor;
};
typedef struct yyStackEntry yyStackEntry;
struct yyParser
{
	int yyidx,yyerrcnt;
	WN_SQL3ParserARG_SDECL
#if YYSTACKDEPTH<=0
	int yystksz;
	yyStackEntry *yystack;
#else
	yyStackEntry yystack[YYSTACKDEPTH];
#endif
};
typedef struct yyParser yyParser;
#ifndef NDEBUG
FILE *yyTraceFILE=0;
char *yyTracePrompt=0;
#endif
#ifndef NDEBUG
void WN_SQL3ParserTrace(FILE *TraceFILE,char *zTracePrompt)
{
	yyTraceFILE=TraceFILE;
	yyTracePrompt=zTracePrompt;
	if(yyTraceFILE==0)
		yyTracePrompt=0;
	else
		if(yyTracePrompt==0)yyTraceFILE=0;
}
#endif
#ifndef NDEBUG
const char *const yyTokenName[]={"$","SEMI","EXPLAIN","QUERY","PLAN","BEGIN","TRANSACTION","DEFERRED","IMMEDIATE","EXCLUSIVE","COMMIT","END","ROLLBACK","CREATE","TABLE","IF","NOT","EXISTS","TEMP","LP","RP","AS","COMMA","ID","ABORT","AFTER","ANALYZE","ASC","ATTACH","BEFORE","CASCADE","CAST","CONFLICT","DATABASE","DESC","DETACH","EACH","FAIL","FOR","IGNORE","INITIALLY","INSTEAD","LIKE_KW","MATCH","KEY","OF","OFFSET","PRAGMA","RAISE","REPLACE","RESTRICT","ROW","TRIGGER","VACUUM","VIEW","VIRTUAL","REINDEX","RENAME","CTIME_KW","ANY","OR","AND","IS","BETWEEN","IN","ISNULL","NOTNULL","NE","EQ","GT","LE","LT","GE","ESCAPE","BITAND","BITOR","LSHIFT","RSHIFT","PLUS","MINUS","STAR","SLASH","REM","CONCAT","COLLATE","UMINUS","UPLUS","BITNOT","STRING","JOIN_KW","CONSTRAINT","DEFAULT","NULL","PRIMARY","UNIQUE","CHECK","REFERENCES","AUTOINCR","ON","DELETE","UPDATE","INSERT","SET","DEFERRABLE","FOREIGN","DROP","UNION","ALL","EXCEPT","INTERSECT","SELECT","DISTINCT","DOT","FROM","JOIN","USING","ORDER","BY","GROUP","HAVING","LIMIT","WHERE","INTO","VALUES","INTEGER","FLOAT","BLOB","REGISTER","VARIABLE","CASE","WHEN","THEN","ELSE","INDEX","ALTER","TO","ADD","COLUMNKW","error","input","cmdlist","ecmd","cmdx","cmd","explain","transtype","trans_opt","nm","create_table","create_table_args","temp","ifnotexists","dbnm","columnlist","conslist_opt","select","column","columnid","type","carglist","id","ids","typetoken","typename","signed","plus_num","minus_num","carg","ccons","term","expr","onconf","sortorder","autoinc","idxlist_opt","refargs","defer_subclause","refarg","refact","init_deferred_pred_opt","conslist","tcons","idxlist","defer_subclause_opt","orconf","resolvetype","raisetype","ifexists","fullname","oneselect","multiselect_op","distinct","selcollist","from","where_opt","groupby_opt","having_opt","orderby_opt","limit_opt","sclp","as","seltablist","stl_prefix","joinop","on_opt","using_opt","seltablist_paren","joinop2","inscollist","sortlist","sortitem","nexprlist","setlist","insert_cmd","inscollist_opt","itemlist","exprlist","likeop","escape","between_op","in_op","case_operand","case_exprlist","case_else","uniqueflag","idxitem","collate","nmnum","plus_opt","number","trigger_decl","trigger_cmd_list","trigger_time","trigger_event","foreach_clause","when_clause","trigger_cmd","database_kw_opt","key_opt","add_column_fullname","kwcolumn_opt","create_vtab","vtabarglist","vtabarg","vtabargtoken","lp","anylist",};
#endif
#ifndef NDEBUG
const char *const yyRuleName[]={"input ::=cmdlist","cmdlist ::=cmdlist ecmd","cmdlist ::=ecmd","cmdx ::=cmd","ecmd ::=SEMI","ecmd ::=explain cmdx SEMI","explain ::=","explain ::=EXPLAIN","explain ::=EXPLAIN QUERY PLAN","cmd ::=BEGIN transtype trans_opt","trans_opt ::=","trans_opt ::=TRANSACTION","trans_opt ::=TRANSACTION nm","transtype ::=","transtype ::=DEFERRED","transtype ::=IMMEDIATE","transtype ::=EXCLUSIVE","cmd ::=COMMIT trans_opt","cmd ::=END trans_opt","cmd ::=ROLLBACK trans_opt","cmd ::=create_table create_table_args","create_table ::=CREATE temp TABLE ifnotexists nm dbnm","ifnotexists ::=","ifnotexists ::=IF NOT EXISTS","temp ::=TEMP","temp ::=","create_table_args ::=LP columnlist conslist_opt RP","create_table_args ::=AS select","columnlist ::=columnlist COMMA column","columnlist ::=column","column ::=columnid type carglist","columnid ::=nm","id ::=ID","ids ::=ID|STRING","nm ::=ID","nm ::=STRING","nm ::=JOIN_KW","type ::=","type ::=typetoken","typetoken ::=typename","typetoken ::=typename LP signed RP","typetoken ::=typename LP signed COMMA signed RP","typename ::=ids","typename ::=typename ids","signed ::=plus_num","signed ::=minus_num","carglist ::=carglist carg","carglist ::=","carg ::=CONSTRAINT nm ccons","carg ::=ccons","ccons ::=DEFAULT term","ccons ::=DEFAULT LP expr RP","ccons ::=DEFAULT PLUS term","ccons ::=DEFAULT MINUS term","ccons ::=DEFAULT id","ccons ::=NULL onconf","ccons ::=NOT NULL onconf","ccons ::=PRIMARY KEY sortorder onconf autoinc","ccons ::=UNIQUE onconf","ccons ::=CHECK LP expr RP","ccons ::=REFERENCES nm idxlist_opt refargs","ccons ::=defer_subclause","ccons ::=COLLATE id","autoinc ::=","autoinc ::=AUTOINCR","refargs ::=","refargs ::=refargs refarg","refarg ::=MATCH nm","refarg ::=ON DELETE refact","refarg ::=ON UPDATE refact","refarg ::=ON INSERT refact","refact ::=SET NULL","refact ::=SET DEFAULT","refact ::=CASCADE","refact ::=RESTRICT","defer_subclause ::=NOT DEFERRABLE init_deferred_pred_opt","defer_subclause ::=DEFERRABLE init_deferred_pred_opt","init_deferred_pred_opt ::=","init_deferred_pred_opt ::=INITIALLY DEFERRED","init_deferred_pred_opt ::=INITIALLY IMMEDIATE","conslist_opt ::=","conslist_opt ::=COMMA conslist","conslist ::=conslist COMMA tcons","conslist ::=conslist tcons","conslist ::=tcons","tcons ::=CONSTRAINT nm","tcons ::=PRIMARY KEY LP idxlist autoinc RP onconf","tcons ::=UNIQUE LP idxlist RP onconf","tcons ::=CHECK LP expr RP onconf","tcons ::=FOREIGN KEY LP idxlist RP REFERENCES nm idxlist_opt refargs defer_subclause_opt","defer_subclause_opt ::=","defer_subclause_opt ::=defer_subclause","onconf ::=","onconf ::=ON CONFLICT resolvetype","orconf ::=","orconf ::=OR resolvetype","resolvetype ::=raisetype","resolvetype ::=IGNORE","resolvetype ::=REPLACE","cmd ::=DROP TABLE ifexists fullname","ifexists ::=IF EXISTS","ifexists ::=","cmd ::=CREATE temp VIEW ifnotexists nm dbnm AS select","cmd ::=DROP VIEW ifexists fullname","cmd ::=select","select ::=oneselect","select ::=select multiselect_op oneselect","multiselect_op ::=UNION","multiselect_op ::=UNION ALL","multiselect_op ::=EXCEPT|INTERSECT","oneselect ::=SELECT distinct selcollist from where_opt groupby_opt having_opt orderby_opt limit_opt","distinct ::=DISTINCT","distinct ::=ALL","distinct ::=","sclp ::=selcollist COMMA","sclp ::=","selcollist ::=sclp expr as","selcollist ::=sclp STAR","selcollist ::=sclp nm DOT STAR","as ::=AS nm","as ::=ids","as ::=","from ::=","from ::=FROM seltablist","stl_prefix ::=seltablist joinop","stl_prefix ::=","seltablist ::=stl_prefix nm dbnm as on_opt using_opt","seltablist ::=stl_prefix LP seltablist_paren RP as on_opt using_opt","seltablist_paren ::=select","seltablist_paren ::=seltablist","dbnm ::=","dbnm ::=DOT nm","fullname ::=nm dbnm","joinop ::=COMMA|JOIN","joinop ::=JOIN_KW JOIN","joinop ::=JOIN_KW nm JOIN","joinop ::=JOIN_KW nm nm JOIN","on_opt ::=ON expr","on_opt ::=","using_opt ::=USING LP inscollist RP","using_opt ::=","orderby_opt ::=","orderby_opt ::=ORDER BY sortlist","sortlist ::=sortlist COMMA sortitem sortorder","sortlist ::=sortitem sortorder","sortitem ::=expr","sortorder ::=ASC","sortorder ::=DESC","sortorder ::=","groupby_opt ::=","groupby_opt ::=GROUP BY nexprlist","having_opt ::=","having_opt ::=HAVING expr","limit_opt ::=","limit_opt ::=LIMIT expr","limit_opt ::=LIMIT expr OFFSET expr","limit_opt ::=LIMIT expr COMMA expr","cmd ::=DELETE FROM fullname where_opt","where_opt ::=","where_opt ::=WHERE expr","cmd ::=UPDATE orconf fullname SET setlist where_opt","setlist ::=setlist COMMA nm EQ expr","setlist ::=nm EQ expr","cmd ::=insert_cmd INTO fullname inscollist_opt VALUES LP itemlist RP","cmd ::=insert_cmd INTO fullname inscollist_opt select","cmd ::=insert_cmd INTO fullname inscollist_opt DEFAULT VALUES","insert_cmd ::=INSERT orconf","insert_cmd ::=REPLACE","itemlist ::=itemlist COMMA expr","itemlist ::=expr","inscollist_opt ::=","inscollist_opt ::=LP inscollist RP","inscollist ::=inscollist COMMA nm","inscollist ::=nm","expr ::=term","expr ::=LP expr RP","term ::=NULL","expr ::=ID","expr ::=JOIN_KW","expr ::=nm DOT nm","expr ::=nm DOT nm DOT nm","term ::=INTEGER|FLOAT|BLOB","term ::=STRING","expr ::=REGISTER","expr ::=VARIABLE","expr ::=expr COLLATE id","expr ::=CAST LP expr AS typetoken RP","expr ::=ID LP distinct exprlist RP","expr ::=ID LP STAR RP","term ::=CTIME_KW","expr ::=expr AND expr","expr ::=expr OR expr","expr ::=expr LT|GT|GE|LE expr","expr ::=expr EQ|NE expr","expr ::=expr BITAND|BITOR|LSHIFT|RSHIFT expr","expr ::=expr PLUS|MINUS expr","expr ::=expr STAR|SLASH|REM expr","expr ::=expr CONCAT expr","likeop ::=LIKE_KW","likeop ::=NOT LIKE_KW","likeop ::=MATCH","likeop ::=NOT MATCH","escape ::=ESCAPE expr","escape ::=","expr ::=expr likeop expr escape","expr ::=expr ISNULL|NOTNULL","expr ::=expr IS NULL","expr ::=expr NOT NULL","expr ::=expr IS NOT NULL","expr ::=NOT|BITNOT expr","expr ::=MINUS expr","expr ::=PLUS expr","between_op ::=BETWEEN","between_op ::=NOT BETWEEN","expr ::=expr between_op expr AND expr","in_op ::=IN","in_op ::=NOT IN","expr ::=expr in_op LP exprlist RP","expr ::=LP select RP","expr ::=expr in_op LP select RP","expr ::=expr in_op nm dbnm","expr ::=EXISTS LP select RP","expr ::=CASE case_operand case_exprlist case_else END","case_exprlist ::=case_exprlist WHEN expr THEN expr","case_exprlist ::=WHEN expr THEN expr","case_else ::=ELSE expr","case_else ::=","case_operand ::=expr","case_operand ::=","exprlist ::=nexprlist","exprlist ::=","nexprlist ::=nexprlist COMMA expr","nexprlist ::=expr","cmd ::=CREATE uniqueflag INDEX ifnotexists nm dbnm ON nm LP idxlist RP","uniqueflag ::=UNIQUE","uniqueflag ::=","idxlist_opt ::=","idxlist_opt ::=LP idxlist RP","idxlist ::=idxlist COMMA idxitem collate sortorder","idxlist ::=idxitem collate sortorder","idxitem ::=nm","collate ::=","collate ::=COLLATE id","cmd ::=DROP INDEX ifexists fullname","cmd ::=VACUUM","cmd ::=VACUUM nm","cmd ::=PRAGMA nm dbnm EQ nmnum","cmd ::=PRAGMA nm dbnm EQ ON","cmd ::=PRAGMA nm dbnm EQ minus_num","cmd ::=PRAGMA nm dbnm LP nmnum RP","cmd ::=PRAGMA nm dbnm","nmnum ::=plus_num","nmnum ::=nm","plus_num ::=plus_opt number","minus_num ::=MINUS number","number ::=INTEGER|FLOAT","plus_opt ::=PLUS","plus_opt ::=","cmd ::=CREATE trigger_decl BEGIN trigger_cmd_list END","trigger_decl ::=temp TRIGGER ifnotexists nm dbnm trigger_time trigger_event ON fullname foreach_clause when_clause","trigger_time ::=BEFORE","trigger_time ::=AFTER","trigger_time ::=INSTEAD OF","trigger_time ::=","trigger_event ::=DELETE|INSERT","trigger_event ::=UPDATE","trigger_event ::=UPDATE OF inscollist","foreach_clause ::=","foreach_clause ::=FOR EACH ROW","when_clause ::=","when_clause ::=WHEN expr","trigger_cmd_list ::=trigger_cmd_list trigger_cmd SEMI","trigger_cmd_list ::=","trigger_cmd ::=UPDATE orconf nm SET setlist where_opt","trigger_cmd ::=insert_cmd INTO nm inscollist_opt VALUES LP itemlist RP","trigger_cmd ::=insert_cmd INTO nm inscollist_opt select","trigger_cmd ::=DELETE FROM nm where_opt","trigger_cmd ::=select","expr ::=RAISE LP IGNORE RP","expr ::=RAISE LP raisetype COMMA nm RP","raisetype ::=ROLLBACK","raisetype ::=ABORT","raisetype ::=FAIL","cmd ::=DROP TRIGGER ifexists fullname","cmd ::=ATTACH database_kw_opt expr AS expr key_opt","cmd ::=DETACH database_kw_opt expr","key_opt ::=","key_opt ::=KEY expr","database_kw_opt ::=DATABASE","database_kw_opt ::=","cmd ::=REINDEX","cmd ::=REINDEX nm dbnm","cmd ::=ANALYZE","cmd ::=ANALYZE nm dbnm","cmd ::=ALTER TABLE fullname RENAME TO nm","cmd ::=ALTER TABLE add_column_fullname ADD kwcolumn_opt column","add_column_fullname ::=fullname","kwcolumn_opt ::=","kwcolumn_opt ::=COLUMNKW","cmd ::=create_vtab","cmd ::=create_vtab LP vtabarglist RP","create_vtab ::=CREATE VIRTUAL TABLE nm dbnm USING nm","vtabarglist ::=vtabarg","vtabarglist ::=vtabarglist COMMA vtabarg","vtabarg ::=","vtabarg ::=vtabarg vtabargtoken","vtabargtoken ::=ANY","vtabargtoken ::=lp anylist RP","lp ::=LP","anylist ::=","anylist ::=anylist ANY",};
#endif
#if YYSTACKDEPTH<=0
void yyGrowStack(yyParser *p)
{
	int newSize;
	newSize=p->yystksz*2+100;
	yyStackEntry *pNew=realloc(p->yystack,newSize*sizeof(pNew[0]));
	if(pNew)
	{
		p->yystack=pNew;
		p->yystksz=newSize;
#ifndef NDEBUG
		if(yyTraceFILE)
			fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",yyTracePrompt,p->yystksz);
#endif
	}
}
#endif
void *WN_SQL3ParserAlloc(void *(*mallocProc)(size_t))
{
	yyParser *pParser;
	pParser=(yyParser*)(*mallocProc)((size_t)sizeof(yyParser));
	if(pParser)
	{
		pParser->yyidx=-1;
#if YYSTACKDEPTH<=0
		yyGrowStack(pParser);
#endif
	}
	return pParser;
}
void yy_destructor(YYCODETYPE yymajor,YYMINORTYPE *yypminor)
{
	switch(yymajor)
	{
	case 155:
	case 189:
	case 206:
		WN_SQL3SelectDelete((yypminor->yy219));
		break;
	case 169:
	case 170:
	case 194:
	case 196:
	case 204:
	case 210:
	case 218:
	case 221:
	case 223:
	case 235:
		WN_SQL3ExprDelete((yypminor->yy172));
		break;
	case 174:
	case 182:
	case 192:
	case 195:
	case 197:
	case 199:
	case 209:
	case 211:
	case 212:
	case 215:
	case 216:
	case 222:
		WN_SQL3ExprListDelete((yypminor->yy174));
		break;
	case 188:
	case 193:
	case 201:
	case 202:
		WN_SQL3SrcListDelete((yypminor->yy373));
		break;
	case 205:
	case 208:
	case 214:
		WN_SQL3IdListDelete((yypminor->yy432));
		break;
	case 231:
	case 236:
		WN_SQL3DeleteTriggerStep((yypminor->yy243));
		break;
	case 233:
		WN_SQL3IdListDelete((yypminor->yy370).b);
		break;
	case 238:
		WN_SQL3ExprDelete((yypminor->yy386));
		break;
	}
}
int yy_pop_parser_stack(yyParser *pParser)
{
	YYCODETYPE yymajor;
	yyStackEntry *yytos=&pParser->yystack[pParser->yyidx];
	if(pParser->yyidx<0)return 0;
#ifndef NDEBUG
	if(yyTraceFILE && pParser->yyidx>=0)
		fprintf(yyTraceFILE,"%sPopping %s\n",yyTracePrompt,yyTokenName[yytos->major]);
#endif
	yymajor=yytos->major;
	yy_destructor(yymajor,&yytos->minor);
	pParser->yyidx--;
	return yymajor;
}
void WN_SQL3ParserFree(void *p,void(*freeProc)(void*))
{
	yyParser *pParser=(yyParser*)p;
	if(pParser==0)return;
	while(pParser->yyidx>=0)yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
	free(pParser->yystack);
#endif
	(*freeProc)((void*)pParser);
}
int yy_find_shift_action(yyParser *pParser,YYCODETYPE iLookAhead)
{
	int i,stateno=pParser->yystack[pParser->yyidx].stateno;
	if(stateno>YY_SHIFT_MAX ||(i=yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT)return yy_default[stateno];
	if(iLookAhead==YYNOCODE)return YY_NO_ACTION;
	i+=iLookAhead;
	if(i<0 || i>=YY_SZ_ACTTAB || yy_lookahead[i]!=iLookAhead)
	{
		if(iLookAhead>0)
		{
#ifdef YYFALLBACK
			int iFallback;
			if(iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])&&(iFallback=yyFallback[iLookAhead]))
			{
#ifndef NDEBUG
				if(yyTraceFILE)fprintf(yyTraceFILE,"%sFALLBACK %s=> %s\n",yyTracePrompt,yyTokenName[iLookAhead],yyTokenName[iFallback]);
#endif
				return yy_find_shift_action(pParser,iFallback);
			}
#endif
#ifdef YYWILDCARD
			int j=i-iLookAhead+YYWILDCARD;
			if(j>=0 && j<YY_SZ_ACTTAB && yy_lookahead[j]==YYWILDCARD)
			{
#ifndef NDEBUG
				if(yyTraceFILE)fprintf(yyTraceFILE,"%sWILDCARD %s=> %s\n",yyTracePrompt,yyTokenName[iLookAhead],yyTokenName[YYWILDCARD]);
#endif
				return yy_action[j];
			}
#endif
		}
		return yy_default[stateno];
	}
	else
		return yy_action[i];
}
int yy_find_reduce_action(int stateno,YYCODETYPE iLookAhead)
{
	int i;
	if(stateno>YY_REDUCE_MAX ||(i=yy_reduce_ofst[stateno])==YY_REDUCE_USE_DFLT)
		return yy_default[stateno];
	if(iLookAhead==YYNOCODE)return YY_NO_ACTION;
	i+=iLookAhead;
	if(i<0||i>=YY_SZ_ACTTAB||yy_lookahead[i]!=iLookAhead)
		return yy_default[stateno];
	else
		return yy_action[i];
}
void yyStackOverflow(yyParser *yypParser,YYMINORTYPE *yypMinor)
{
	WN_SQL3ParserARG_FETCH;
	yypParser->yyidx--;
#ifndef NDEBUG
	if(yyTraceFILE)	fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
#endif
	while(yypParser->yyidx>=0)yy_pop_parser_stack(yypParser);
	WN_SQL3ErrorMsg(pParse,"parser stack overflow");
	pParse->parseError=1;
	WN_SQL3ParserARG_STORE;
}
void yy_shift(yyParser *yypParser,int yyNewState,int yyMajor,
					 YYMINORTYPE *yypMinor)
{
	yyStackEntry *yytos;
	yypParser->yyidx++;
#if YYSTACKDEPTH>0
	if(yypParser->yyidx>=YYSTACKDEPTH)
	{
		yyStackOverflow(yypParser,yypMinor);
		return;
	}
#else
	if(yypParser->yyidx>=yypParser->yystksz)
	{
		yyGrowStack(yypParser);
		if(yypParser->yyidx>=yypParser->yystksz)
		{
			yyStackOverflow(yypParser,yypMinor);
			return;
		}
	}
#endif
	yytos=&yypParser->yystack[yypParser->yyidx];
	yytos->stateno=yyNewState;
	yytos->major=yyMajor;
	yytos->minor=*yypMinor;
#ifndef NDEBUG
	if(yyTraceFILE && yypParser->yyidx>0)
	{
		int i;
		fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
		fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
		for(i=1;i<=yypParser->yyidx;i++)
			fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
		fprintf(yyTraceFILE,"\n");
	}
#endif
}
const struct
{
	YYCODETYPE lhs;
	unsigned char nrhs;
}yyRuleInfo[]={{139,1}, {140,2}, {140,1}, {142,1}, {141,1}, {141,3}, {144,0},{144,1}, {144,3}, {143,3}, {146,0}, {146,1}, {146,2}, {145,0}, {145,1}, {145,1},{145,1}, {143,2}, {143,2}, {143,2}, {143,2}, {148,6}, {151,0}, {151,3}, {150,1},{150,0}, {149,4}, {149,2}, {153,3}, {153,1}, {156,3}, {157,1}, {160,1}, {161,1}, {147,1}, {147,1}, {147,1}, {158,0}, {158,1}, {162,1}, {162,4}, {162,6}, {163,1},{163,2}, {164,1}, {164,1}, {159,2}, {159,0}, {167,3}, {167,1}, {168,2}, {168,4},{168,3}, {168,3}, {168,2}, {168,2}, {168,3}, {168,5}, {168,2}, {168,4}, {168,4},{168,1}, {168,2}, {173,0}, {173,1}, {175,0}, {175,2}, {177,2}, {177,3}, {177,3},{177,3}, {178,2}, {178,2}, {178,1}, {178,1}, {176,3}, {176,2}, {179,0}, {179,2},{179,2}, {154,0}, {154,2}, {180,3}, {180,2}, {180,1}, {181,2}, {181,7}, {181,5},{181,5}, {181,10}, {183,0}, {183,1}, {171,0}, {171,3}, {184,0}, {184,2}, {185,1},{185,1}, {185,1}, {143,4}, {187,2}, {187,0}, {143,8}, {143,4}, {143,1}, {155,1},{155,3}, {190,1}, {190,2}, {190,1}, {189,9}, {191,1}, {191,1}, {191,0}, {199,2},{199,0}, {192,3}, {192,2}, {192,4}, {200,2}, {200,1}, {200,0}, {193,0}, {193,2},{202,2}, {202,0}, {201,6}, {201,7}, {206,1}, {206,1}, {152,0}, {152,2}, {188,2},{203,1}, {203,2}, {203,3}, {203,4}, {204,2}, {204,0}, {205,4}, {205,0}, {197,0},{197,3},{209,4},{209,2},{210,1},{172,1},{172,1},{172,0},{195,0},{195,3},{196,0},{196,2},{198,0},{198,2},{198,4},{198,4},{143,4},{194,0},{194,2},{143,6},{212,5},{212,3},{143,8},{143,5},{143,6},{213,2},{213,1},{215,3},{215,1},{214,0},{214,3},{208,3},{208,1},{170,1},{170,3},{169,1},{170,1},{170,1},{170,3},{170,5},{169,1},{169,1},{170,1},{170,1},{170,3},{170,6},{170,5},{170,4},{169,1},{170,3},{170,3},{170,3},{170,3},{170,3},{170,3},{170,3},{170,3},{217,1},{217,2},{217,1},{217,2},{218,2},{218,0},{170,4},{170,2},{170,3},{170,3},{170,4},{170,2},{170,2},{170,2},{219,1},{219,2},{170,5},{220,1},{220,2},{170,5},{170,3},{170,5},{170,4},{170,4},{170,5},{222,5},{222,4},{223,2},{223,0},{221,1},{221,0},{216,1},{216,0},{211,3},{211,1},{143,11},{224,1},{224,0},{174,0},{174,3},{182,5},{182,3},{225,1},{226,0},{226,2},{143,4},{143,1},{143,2},{143,5},{143,5},{143,5},{143,6},{143,3},{227,1},{227,1},{165,2},{166,2},{229,1},{228,1},{228,0},{143,5},{230,11},{232,1},{232,1},{232,2},{232,0},{233,1},{233,1},{233,3},{234,0},{234,3},{235,0},{235,2},{231,3},{231,0},{236,6},{236,8},{236,5},{236,4},{236,1},{170,4},{170,6},{186,1},{186,1},{186,1},{143,4},{143,6},{143,3},{238,0},{238,2},{237,1},{237,0},{143,1},{143,3},{143,1},{143,3},{143,6},{143,6},{239,1},{240,0},{240,1},{143,1},{143,4},{241,7},{242,1},{242,3},{243,0},{243,2},{244,1},{244,3},{245,1},{246,0},{246,2},};
	void yy_accept(yyParser*);
	int cases[]={0,0,0,1,0,0,2,3,4,5,0,0,0,6,7,7,7,8,8,9,0,10,11,12,12,11,13,14,0,0,15,16,17,17,17,17,17,0,18,19,20,21,10,22,0,0,0,0,0,0,23,24,23,25,26,0,27,28,29,30,31,32,33,11,12,34,35,36,37,38,39,40,41,42,43,44,44,11,12,11,45,46,0,0,0,0,47,48,49,50,11,44,51,44,51,44,44,52,53,54,12,11,55,56,57,58,59,7,60,7,61,12,11,11,62,63,64,65,66,19,19,67,68,69,70,71,72,73,58,74,75,19,76,77,78,79,80,81,82,83,84,63,85,86,87,81,88,89,88,63,85,82,81,90,91,92,93,94,82,81,95,96,97,98,99,100,44,53,101,102,84,83,103,104,81,105,106,107,107,108,109,106,106,110,111,112,113,114,115,116,117,117,117,117,117,117,117,117,118,119,118,119,81,82,120,121,122,123,124,125,126,127,11,12,128,11,12,129,130,131,132,133,134,135,136,81,82,81,82,85,63,101,102,137,138,139,63,62,140,141,19,142,19,143,144,144,145,146,147,148,149,19,19,19,19,17,0,0,150,151,152,153,154,152,155,155,156,0,0,157,158,159,160,161,162,163,164,165,166,167,168,138,169,170,171,172,173,174,0,0,175,176,177,178,179,180,181,0,0,182,183,184,0,0,185,0,186,186,186,0,186};
void yy_reduce(yyParser *yypParser,int yyruleno)
{
	int yygoto,yyact;
	YYMINORTYPE yygotominor;
	yyStackEntry *yymsp;
	int yysize;
	WN_SQL3ParserARG_FETCH;
	yymsp=&yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
	if(yyTraceFILE && yyruleno>=0&& yyruleno<(int)(sizeof(yyRuleName)/
		sizeof(yyRuleName[0])))
		fprintf(yyTraceFILE,"%sReduce [%s].\n",yyTracePrompt,
			yyRuleName[yyruleno]);
#endif
	memset(&yygotominor,0,sizeof(yygotominor));
	switch(cases[yyruleno])
	{
	case 1:
		WN_SQL3FinishCoding(pParse);
		break;
	case 2:
		WN_SQL3BeginParse(pParse,0);
		break;
	case 3:
		WN_SQL3BeginParse(pParse,1);
		break;
	case 4:
		WN_SQL3BeginParse(pParse,2);
		break;
	case 5:
		WN_SQL3BeginTransaction(pParse,yymsp[-1].minor.yy46);
		break;
	case 6:
		yygotominor.yy46=TK_DEFERRED;
		break;
	case 7:
		yygotominor.yy46=yymsp[0].major;
		break;
	case 8:
		WN_SQL3CommitTransaction(pParse);
		break;
	case 9:
		WN_SQL3RollbackTransaction(pParse);
		break;
	case 10:
		WN_SQL3StartTable(pParse,&yymsp[-1].minor.yy410,&yymsp[0].minor.yy410,yymsp[-4].minor.yy46,0,0,yymsp[-2].minor.yy46);
		break;
	case 11:
		yygotominor.yy46=0;
		break;
	case 12:
		yygotominor.yy46=1;
		break;
	case 13:
		WN_SQL3EndTable(pParse,&yymsp[-1].minor.yy410,&yymsp[0].minor.yy0,0);
		break;
	case 14:
		WN_SQL3EndTable(pParse,0,0,yymsp[0].minor.yy219);
		WN_SQL3SelectDelete(yymsp[0].minor.yy219);
		break;
	case 15:
		yygotominor.yy410.z=yymsp[-2].minor.yy410.z;
		yygotominor.yy410.n=(pParse->sLastToken.z-yymsp[-2].minor.yy410.z)+pParse->sLastToken.n;
		break;
	case 16:
		WN_SQL3AddColumn(pParse,&yymsp[0].minor.yy410);
		yygotominor.yy410=yymsp[0].minor.yy410;
		break;
	case 17:
		yygotominor.yy410=yymsp[0].minor.yy0;
		break;
	case 18:
		WN_SQL3AddColumnType(pParse,&yymsp[0].minor.yy410);
		break;
	case 19:
		yygotominor.yy410=yymsp[0].minor.yy410;
		break;
	case 20:
		yygotominor.yy410.z=yymsp[-3].minor.yy410.z;yygotominor.yy410.n=&yymsp[0].minor.yy0.z[yymsp[0].minor.yy0.n]-yymsp[-3].minor.yy410.z;
		break;
	case 21:
		yygotominor.yy410.z=yymsp[-5].minor.yy410.z;yygotominor.yy410.n=&yymsp[0].minor.yy0.z[yymsp[0].minor.yy0.n]-yymsp[-5].minor.yy410.z;
		break;
	case 22:
		yygotominor.yy410.z=yymsp[-1].minor.yy410.z;yygotominor.yy410.n=yymsp[0].minor.yy410.n+(yymsp[0].minor.yy410.z-yymsp[-1].minor.yy410.z);
		break;
	case 23:
		WN_SQL3AddDefaultValue(pParse,yymsp[0].minor.yy172);
		break;
	case 24:
		WN_SQL3AddDefaultValue(pParse,yymsp[-1].minor.yy172);
		break;
	case 25:
		Expr *p=WN_SQL3Expr(TK_UMINUS,yymsp[0].minor.yy172,0,0);
		WN_SQL3AddDefaultValue(pParse,p);
		break;
	case 26:
		Expr *p=WN_SQL3Expr(TK_STRING,0,0,&yymsp[0].minor.yy410);
		WN_SQL3AddDefaultValue(pParse,p);
		break;
	case 27:
		WN_SQL3AddNotNull(pParse,yymsp[0].minor.yy46);
		break;
	case 28:
		WN_SQL3AddPrimaryKey(pParse,0,yymsp[-1].minor.yy46,yymsp[0].minor.yy46,yymsp[-2].minor.yy46);
		break;
	case 29:
		WN_SQL3CreateIndex(pParse,0,0,0,0,yymsp[0].minor.yy46,0,0,0,0);
		break;
	case 30:
		WN_SQL3AddCheckConstraint(pParse,yymsp[-1].minor.yy172);
		break;
	case 31:
		WN_SQL3CreateForeignKey(pParse,0,&yymsp[-2].minor.yy410,yymsp[-1].minor.yy174,yymsp[0].minor.yy46);
		break;
	case 32:
		WN_SQL3DeferForeignKey(pParse,yymsp[0].minor.yy46);
		break;
	case 33:
		WN_SQL3AddCollateType(pParse,(char*)yymsp[0].minor.yy410.z,yymsp[0].minor.yy410.n);
		break;
	case 34:
		yygotominor.yy46=OE_Restrict*0x010101;
		break;
	case 35:
		yygotominor.yy46=(yymsp[-1].minor.yy46 & yymsp[0].minor.yy405.mask)| yymsp[0].minor.yy405.value;
		break;
	case 36:
		yygotominor.yy405.value=0;yygotominor.yy405.mask=0x000000;
		break;
	case 37:
		yygotominor.yy405.value=yymsp[0].minor.yy46;yygotominor.yy405.mask=0x0000ff;
		break;
	case 38:
		yygotominor.yy405.value=yymsp[0].minor.yy46<<8;yygotominor.yy405.mask=0x00ff00;
		break;
	case 39:
		yygotominor.yy405.value=yymsp[0].minor.yy46<<16;yygotominor.yy405.mask=0xff0000;
		break;
	case 40:
		yygotominor.yy46=OE_SetNull;
		break;
	case 41:
		yygotominor.yy46=OE_SetDflt;
		break;
	case 42:
		yygotominor.yy46=OE_Cascade;
		break;
	case 43:
		yygotominor.yy46=OE_Restrict;
		break;
	case 44:
		yygotominor.yy46=yymsp[0].minor.yy46;
		break;
	case 45:
		yygotominor.yy410.n=0;
		yygotominor.yy410.z=0;
		break;
	case 46:
		yygotominor.yy410=yymsp[-1].minor.yy0;
		break;
	case 47:
		WN_SQL3AddPrimaryKey(pParse,yymsp[-3].minor.yy174,yymsp[0].minor.yy46,yymsp[-2].minor.yy46,0);
		break;
	case 48:
		WN_SQL3CreateIndex(pParse,0,0,0,yymsp[-2].minor.yy174,yymsp[0].minor.yy46,0,0,0,0);
		break;
	case 49:
		WN_SQL3AddCheckConstraint(pParse,yymsp[-2].minor.yy172);
		break;
	case 50:
		WN_SQL3CreateForeignKey(pParse,yymsp[-6].minor.yy174,&yymsp[-3].minor.yy410,yymsp[-2].minor.yy174,yymsp[-1].minor.yy46);
		WN_SQL3DeferForeignKey(pParse,yymsp[0].minor.yy46);
		break;
	case 51:
		yygotominor.yy46=OE_Default;
		break;
	case 52:
		yygotominor.yy46=OE_Ignore;
		break;
	case 53:
		yygotominor.yy46=OE_Replace;
		break;
	case 54:
		WN_SQL3DropTable(pParse,yymsp[0].minor.yy373,0,yymsp[-1].minor.yy46);
		break;
	case 55:
		WN_SQL3CreateView(pParse,&yymsp[-7].minor.yy0,&yymsp[-3].minor.yy410,&yymsp[-2].minor.yy410,yymsp[0].minor.yy219,yymsp[-6].minor.yy46,yymsp[-4].minor.yy46);
		break;
	case 56:
		WN_SQL3DropTable(pParse,yymsp[0].minor.yy373,1,yymsp[-1].minor.yy46);
		break;
	case 57:
		WN_SQL3Select(pParse,yymsp[0].minor.yy219,SRT_Callback,0,0,0,0,0);
		WN_SQL3SelectDelete(yymsp[0].minor.yy219);
		break;
	case 58:
		yygotominor.yy219=yymsp[0].minor.yy219;
		break;
	case 59:
		if(yymsp[0].minor.yy219)
		{
			yymsp[0].minor.yy219->op=yymsp[-1].minor.yy46;
			yymsp[0].minor.yy219->pPrior=yymsp[-2].minor.yy219;
		}
		else
			WN_SQL3SelectDelete(yymsp[-2].minor.yy219);
		yygotominor.yy219=yymsp[0].minor.yy219;
		break;
	case 60:
		yygotominor.yy46=TK_ALL;
		break;
	case 61:
		yygotominor.yy219=WN_SQL3SelectNew(yymsp[-6].minor.yy174,yymsp[-5].minor.yy373,yymsp[-4].minor.yy172,yymsp[-3].minor.yy174,yymsp[-2].minor.yy172,yymsp[-1].minor.yy174,yymsp[-7].minor.yy46,yymsp[0].minor.yy234.pLimit,yymsp[0].minor.yy234.pOffset);
		break;
	case 62:
		yygotominor.yy174=yymsp[-1].minor.yy174;
		break;
	case 63:
		yygotominor.yy174=0;
		break;
	case 64:
		yygotominor.yy174=WN_SQL3ExprListAppend(yymsp[-2].minor.yy174,yymsp[-1].minor.yy172,yymsp[0].minor.yy410.n?&yymsp[0].minor.yy410:0);
		break;
	case 65:
		yygotominor.yy174=WN_SQL3ExprListAppend(yymsp[-1].minor.yy174,WN_SQL3Expr(TK_ALL,0,0,0),0);
		break;
	case 66:
		Expr *pRight=WN_SQL3Expr(TK_ALL,0,0,0);Expr *pLeft=WN_SQL3Expr(TK_ID,0,0,&yymsp[-2].minor.yy410);
		yygotominor.yy174=WN_SQL3ExprListAppend(yymsp[-3].minor.yy174,WN_SQL3Expr(TK_DOT,pLeft,pRight,0),0);
		break;
	case 67:
		yygotominor.yy410.n=0;
		break;
	case 68:
		yygotominor.yy373=WN_SQL3Malloc(sizeof(*yygotominor.yy373));
		break;
	case 69:
		yygotominor.yy373=yymsp[0].minor.yy373;WN_SQL3SrcListShiftJoinType(yygotominor.yy373);
		break;
	case 70:
		yygotominor.yy373=yymsp[-1].minor.yy373;
		if(yygotominor.yy373 && yygotominor.yy373->nSrc>0)yygotominor.yy373->a[yygotominor.yy373->nSrc-1].jointype=yymsp[0].minor.yy46;
		break;
	case 71:
		yygotominor.yy373=0;
		break;
	case 72:
		yygotominor.yy373=WN_SQL3SrcListAppendFromTerm(yymsp[-5].minor.yy373,&yymsp[-4].minor.yy410,&yymsp[-3].minor.yy410,&yymsp[-2].minor.yy410,0,yymsp[-1].minor.yy172,yymsp[0].minor.yy432);
		break;
	case 73:
		yygotominor.yy373=WN_SQL3SrcListAppendFromTerm(yymsp[-6].minor.yy373,0,0,&yymsp[-2].minor.yy410,yymsp[-4].minor.yy219,yymsp[-1].minor.yy172,yymsp[0].minor.yy432);
		break;
	case 74:
		WN_SQL3SrcListShiftJoinType(yymsp[0].minor.yy373);yygotominor.yy219=WN_SQL3SelectNew(0,yymsp[0].minor.yy373,0,0,0,0,0,0,0);
		break;
	case 75:
		yygotominor.yy410.z=0;yygotominor.yy410.n=0;
		break;
	case 76:
		yygotominor.yy373=WN_SQL3SrcListAppend(0,&yymsp[-1].minor.yy410,&yymsp[0].minor.yy410);
		break;
	case 77:
		yygotominor.yy46=JT_INNER;
		break;
	case 78:
		yygotominor.yy46=WN_SQL3JoinType(pParse,&yymsp[-1].minor.yy0,0,0);
		break;
	case 79:
		yygotominor.yy46=WN_SQL3JoinType(pParse,&yymsp[-2].minor.yy0,&yymsp[-1].minor.yy410,0);
		break;
	case 80:
		yygotominor.yy46=WN_SQL3JoinType(pParse,&yymsp[-3].minor.yy0,&yymsp[-2].minor.yy410,&yymsp[-1].minor.yy410);
		break;
	case 81:
		yygotominor.yy172=yymsp[0].minor.yy172;
		break;
	case 82:
		yygotominor.yy172=0;
		break;
	case 83:
		yygotominor.yy432=yymsp[-1].minor.yy432;
		break;
	case 84:
		yygotominor.yy432=0;
		break;
	case 85:
		yygotominor.yy174=yymsp[0].minor.yy174;
		break;
	case 86:
		yygotominor.yy174=WN_SQL3ExprListAppend(yymsp[-3].minor.yy174,yymsp[-1].minor.yy172,0);
		if(yygotominor.yy174)yygotominor.yy174->a[yygotominor.yy174->nExpr-1].sortOrder=yymsp[0].minor.yy46;
		break;
	case 87:
		yygotominor.yy174=WN_SQL3ExprListAppend(0,yymsp[-1].minor.yy172,0);
		if(yygotominor.yy174 && yygotominor.yy174->a)yygotominor.yy174->a[0].sortOrder=yymsp[0].minor.yy46;
		break;
	case 88:
		yygotominor.yy46=WN_SQL_SO_ASC;
		break;
	case 89:
		yygotominor.yy46=WN_SQL_SO_DESC;
		break;
	case 90:
		yygotominor.yy234.pLimit=0;yygotominor.yy234.pOffset=0;
		break;
	case 91:
		yygotominor.yy234.pLimit=yymsp[0].minor.yy172;yygotominor.yy234.pOffset=0;
		break;
	case 92:
		yygotominor.yy234.pLimit=yymsp[-2].minor.yy172;yygotominor.yy234.pOffset=yymsp[0].minor.yy172;
		break;
	case 93:
		yygotominor.yy234.pOffset=yymsp[-2].minor.yy172;yygotominor.yy234.pLimit=yymsp[0].minor.yy172;
		break;
	case 94:
		WN_SQL3DeleteFrom(pParse,yymsp[-1].minor.yy373,yymsp[0].minor.yy172);
		break;
	case 95:
		WN_SQL3ExprListCheckLength(pParse,yymsp[-1].minor.yy174,WN_SQL_MAX_COLUMN,"set list");
		WN_SQL3Update(pParse,yymsp[-3].minor.yy373,yymsp[-1].minor.yy174,yymsp[0].minor.yy172,yymsp[-4].minor.yy46);
		break;
	case 96:
		yygotominor.yy174=WN_SQL3ExprListAppend(yymsp[-4].minor.yy174,yymsp[0].minor.yy172,&yymsp[-2].minor.yy410);
		break;
	case 97:
		yygotominor.yy174=WN_SQL3ExprListAppend(0,yymsp[0].minor.yy172,&yymsp[-2].minor.yy410);
		break;
	case 98:
		WN_SQL3Insert(pParse,yymsp[-5].minor.yy373,yymsp[-1].minor.yy174,0,yymsp[-4].minor.yy432,yymsp[-7].minor.yy46);
		break;
	case 99:
		WN_SQL3Insert(pParse,yymsp[-2].minor.yy373,0,yymsp[0].minor.yy219,yymsp[-1].minor.yy432,yymsp[-4].minor.yy46);
		break;
	case 100:
		WN_SQL3Insert(pParse,yymsp[-3].minor.yy373,0,0,yymsp[-2].minor.yy432,yymsp[-5].minor.yy46);
		break;
	case 101:
		yygotominor.yy174=WN_SQL3ExprListAppend(yymsp[-2].minor.yy174,yymsp[0].minor.yy172,0);
		break;
	case 102:
		yygotominor.yy174=WN_SQL3ExprListAppend(0,yymsp[0].minor.yy172,0);
		break;
	case 103:
		yygotominor.yy432=WN_SQL3IdListAppend(yymsp[-2].minor.yy432,&yymsp[0].minor.yy410);
		break;
	case 104:
		yygotominor.yy432=WN_SQL3IdListAppend(0,&yymsp[0].minor.yy410);
		break;
	case 105:
		yygotominor.yy172=yymsp[-1].minor.yy172;WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
		break;
	case 106:
		yygotominor.yy172=WN_SQL3Expr(yymsp[0].major,0,0,&yymsp[0].minor.yy0);
		break;
	case 107:yygotominor.yy172=WN_SQL3Expr(TK_ID,0,0,&yymsp[0].minor.yy0);
		break;
	case 108:Expr *temp1=WN_SQL3Expr(TK_ID,0,0,&yymsp[-2].minor.yy410);
		Expr *temp2=WN_SQL3Expr(TK_ID,0,0,&yymsp[0].minor.yy410);
		yygotominor.yy172=WN_SQL3Expr(TK_DOT,temp1,temp2,0);
		break;
	case 109:
		Expr *temp1=WN_SQL3Expr(TK_ID,0,0,&yymsp[-4].minor.yy410),*temp2=WN_SQL3Expr(TK_ID,0,0,&yymsp[-2].minor.yy410),*temp3=WN_SQL3Expr(TK_ID,0,0,&yymsp[0].minor.yy410),*temp4=WN_SQL3Expr(TK_DOT,temp2,temp3,0);
		yygotominor.yy172=WN_SQL3Expr(TK_DOT,temp1,temp4,0);
		break;
	case 110:
		yygotominor.yy172=WN_SQL3RegisterExpr(pParse,&yymsp[0].minor.yy0);
		break;
	case 111:
		Token *pToken=&yymsp[0].minor.yy0;
		Expr *pExpr=yygotominor.yy172=WN_SQL3Expr(TK_VARIABLE,0,0,pToken);
		WN_SQL3ExprAssignVarNumber(pParse,pExpr);
		break;
	case 112:
		yygotominor.yy172=WN_SQL3ExprSetColl(pParse,yymsp[-2].minor.yy172,&yymsp[0].minor.yy410);
		break;
	case 113:
		yygotominor.yy172=WN_SQL3Expr(TK_CAST,yymsp[-3].minor.yy172,0,&yymsp[-1].minor.yy410);WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-5].minor.yy0,&yymsp[0].minor.yy0);
		break;
	case 114:
		if(yymsp[-1].minor.yy174 && yymsp[-1].minor.yy174->nExpr>WN_SQL_MAX_FUNCTION_ARG)WN_SQL3ErrorMsg(pParse,"too many arguments on function %T",&yymsp[-4].minor.yy0);
		yygotominor.yy172=WN_SQL3ExprFunction(yymsp[-1].minor.yy174,&yymsp[-4].minor.yy0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-4].minor.yy0,&yymsp[0].minor.yy0);
		if(yymsp[-2].minor.yy46 && yygotominor.yy172)yygotominor.yy172->flags |=EP_Distinct;
		break;
	case 115:
		yygotominor.yy172=WN_SQL3ExprFunction(0,&yymsp[-3].minor.yy0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
		break;
	case 116:
		yygotominor.yy172=WN_SQL3ExprFunction(0,&yymsp[0].minor.yy0);
		if(yygotominor.yy172)
		{
			yygotominor.yy172->op=TK_CONST_FUNC;
			yygotominor.yy172->span=yymsp[0].minor.yy0;
		}
		break;
	case 117:
		yygotominor.yy172=WN_SQL3Expr(yymsp[-1].major,yymsp[-2].minor.yy172,yymsp[0].minor.yy172,0);
		break;
	case 118:
		yygotominor.yy72.eOperator=yymsp[0].minor.yy0;yygotominor.yy72.not=0;
		break;
	case 119:
		yygotominor.yy72.eOperator=yymsp[0].minor.yy0;yygotominor.yy72.not=1;
		break;
	case 120:
		ExprList *pList;
		pList=WN_SQL3ExprListAppend(0,yymsp[-1].minor.yy172,0);
		pList=WN_SQL3ExprListAppend(pList,yymsp[-3].minor.yy172,0);
		if(yymsp[0].minor.yy172)pList=WN_SQL3ExprListAppend(pList,yymsp[0].minor.yy172,0);
		yygotominor.yy172=WN_SQL3ExprFunction(pList,&yymsp[-2].minor.yy72.eOperator);
		if(yymsp[-2].minor.yy72.not)yygotominor.yy172=WN_SQL3Expr(TK_NOT,yygotominor.yy172,0,0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-3].minor.yy172->span,&yymsp[-1].minor.yy172->span);
		if(yygotominor.yy172)yygotominor.yy172->flags |=EP_InfixFunc;
		break;
	case 121:
		yygotominor.yy172=WN_SQL3Expr(yymsp[0].major,yymsp[-1].minor.yy172,0,0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-1].minor.yy172->span,&yymsp[0].minor.yy0);
		break;
	case 122:
		yygotominor.yy172=WN_SQL3Expr(TK_ISNULL,yymsp[-2].minor.yy172,0,0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-2].minor.yy172->span,&yymsp[0].minor.yy0);
		break;
	case 123:
		yygotominor.yy172=WN_SQL3Expr(TK_NOTNULL,yymsp[-2].minor.yy172,0,0);WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-2].minor.yy172->span,&yymsp[0].minor.yy0);
		break;
	case 124:
		yygotominor.yy172=WN_SQL3Expr(TK_NOTNULL,yymsp[-3].minor.yy172,0,0);WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-3].minor.yy172->span,&yymsp[0].minor.yy0);
		break;
	case 125:
		yygotominor.yy172=WN_SQL3Expr(yymsp[-1].major,yymsp[0].minor.yy172,0,0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy172->span);
		break;
	case 126:
		yygotominor.yy172=WN_SQL3Expr(TK_UMINUS,yymsp[0].minor.yy172,0,0);				WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy172->span);
		break;
	case 127:
		yygotominor.yy172=WN_SQL3Expr(TK_UPLUS,yymsp[0].minor.yy172,0,0);				WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-1].minor.yy0,&yymsp[0].minor.yy172->span);
		break;
	case 128:
		ExprList *pList=WN_SQL3ExprListAppend(0,yymsp[-2].minor.yy172,0);
		pList=WN_SQL3ExprListAppend(pList,yymsp[0].minor.yy172,0);
		yygotominor.yy172=WN_SQL3Expr(TK_BETWEEN,yymsp[-4].minor.yy172,0,0);
		if(yygotominor.yy172)
			yygotominor.yy172->pList=pList;
		else
			WN_SQL3ExprListDelete(pList);
		if(yymsp[-3].minor.yy46)yygotominor.yy172=WN_SQL3Expr(TK_NOT,yygotominor.yy172,0,0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-4].minor.yy172->span,&yymsp[0].minor.yy172->span);
		break;
	case 129:
		yygotominor.yy172=WN_SQL3Expr(TK_IN,yymsp[-4].minor.yy172,0,0);
		if(yygotominor.yy172)
		{
			yygotominor.yy172->pList=yymsp[-1].minor.yy174;
			WN_SQL3ExprSetHeight(yygotominor.yy172);
		}
		else
			WN_SQL3ExprListDelete(yymsp[-1].minor.yy174);
		if(yymsp[-3].minor.yy46)yygotominor.yy172=WN_SQL3Expr(TK_NOT,yygotominor.yy172,0,0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-4].minor.yy172->span,&yymsp[0].minor.yy0);
		break;
	case 130:
		yygotominor.yy172=WN_SQL3Expr(TK_SELECT,0,0,0);
		if(yygotominor.yy172)
		{
			yygotominor.yy172->pSelect=yymsp[-1].minor.yy219;
			WN_SQL3ExprSetHeight(yygotominor.yy172);
		}
		else
			WN_SQL3SelectDelete(yymsp[-1].minor.yy219);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-2].minor.yy0,&yymsp[0].minor.yy0);
		break;
	case 131:
		yygotominor.yy172=WN_SQL3Expr(TK_IN,yymsp[-4].minor.yy172,0,0);
		if(yygotominor.yy172)
		{
			yygotominor.yy172->pSelect=yymsp[-1].minor.yy219;
			WN_SQL3ExprSetHeight(yygotominor.yy172);
		}
		else
			WN_SQL3SelectDelete(yymsp[-1].minor.yy219);
		if(yymsp[-3].minor.yy46)yygotominor.yy172=WN_SQL3Expr(TK_NOT,yygotominor.yy172,0,0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-4].minor.yy172->span,&yymsp[0].minor.yy0);
		break;
	case 132:
		SrcList *pSrc=WN_SQL3SrcListAppend(0,&yymsp[-1].minor.yy410,&yymsp[0].minor.yy410);
		yygotominor.yy172=WN_SQL3Expr(TK_IN,yymsp[-3].minor.yy172,0,0);
		if(yygotominor.yy172)
		{
			yygotominor.yy172->pSelect=WN_SQL3SelectNew(0,pSrc,0,0,0,0,0,0,0);
			WN_SQL3ExprSetHeight(yygotominor.yy172);
		}
		else
			WN_SQL3SrcListDelete(pSrc);
		if(yymsp[-2].minor.yy46)yygotominor.yy172=WN_SQL3Expr(TK_NOT,yygotominor.yy172,0,0);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-3].minor.yy172->span,yymsp[0].minor.yy410.z?&yymsp[0].minor.yy410:&yymsp[-1].minor.yy410);
		break;
	case 133:
		Expr *p=yygotominor.yy172=WN_SQL3Expr(TK_EXISTS,0,0,0);
		if(p)
		{
			p->pSelect=yymsp[-1].minor.yy219;
			WN_SQL3ExprSpan(p,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
			WN_SQL3ExprSetHeight(yygotominor.yy172);
		}
		else
			WN_SQL3SelectDelete(yymsp[-1].minor.yy219);
		break;
	case 134:
		yygotominor.yy172=WN_SQL3Expr(TK_CASE,yymsp[-3].minor.yy172,yymsp[-1].minor.yy172,0);
		if(yygotominor.yy172)
			yygotominor.yy172->pList=yymsp[-2].minor.yy174;WN_SQL3ExprSetHeight(yygotominor.yy172);
		else
			WN_SQL3ExprListDelete(yymsp[-2].minor.yy174);
		WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-4].minor.yy0,&yymsp[0].minor.yy0);
		break;
	case 135:
		yygotominor.yy174=WN_SQL3ExprListAppend(yymsp[-4].minor.yy174,yymsp[-2].minor.yy172,0);
		yygotominor.yy174=WN_SQL3ExprListAppend(yygotominor.yy174,yymsp[0].minor.yy172,0);
		break;
	case 136:
		yygotominor.yy174=WN_SQL3ExprListAppend(0,yymsp[-2].minor.yy172,0);
		yygotominor.yy174=WN_SQL3ExprListAppend(yygotominor.yy174,yymsp[0].minor.yy172,0);
		break;
	case 137:
		WN_SQL3CreateIndex(pParse,&yymsp[-6].minor.yy410,&yymsp[-5].minor.yy410,WN_SQL3SrcListAppend(0,&yymsp[-3].minor.yy410,0),yymsp[-1].minor.yy174,yymsp[-9].minor.yy46,&yymsp[-10].minor.yy0,&yymsp[0].minor.yy0,WN_SQL_SO_ASC,yymsp[-7].minor.yy46);
		break;
	case 138:
		yygotominor.yy46=OE_Abort;
		break;
	case 139:
		yygotominor.yy46=OE_None;
		break;
	case 140:
		Expr *p=0;
		if(yymsp[-1].minor.yy410.n>0)
		{
			p=WN_SQL3Expr(TK_COLUMN,0,0,0);
			if(p)p->pColl=WN_SQL3LocateCollSeq(pParse,(char*)yymsp[-1].minor.yy410.z,yymsp[-1].minor.yy410.n);
		}
		yygotominor.yy174=WN_SQL3ExprListAppend(yymsp[-4].minor.yy174,p,&yymsp[-2].minor.yy410);
		WN_SQL3ExprListCheckLength(pParse,yygotominor.yy174,WN_SQL_MAX_COLUMN,"index");
		if(yygotominor.yy174)yygotominor.yy174->a[yygotominor.yy174->nExpr-1].sortOrder=yymsp[0].minor.yy46;
		break;
	case 141:
		Expr *p=0;
		if(yymsp[-1].minor.yy410.n>0)
		{
			p=WN_SQL3Expr(TK_COLUMN,0,0,0);
			if(p)p->pColl=WN_SQL3LocateCollSeq(pParse,(char*)yymsp[-1].minor.yy410.z,yymsp[-1].minor.yy410.n);
		}
		yygotominor.yy174=WN_SQL3ExprListAppend(0,p,&yymsp[-2].minor.yy410);
		WN_SQL3ExprListCheckLength(pParse,yygotominor.yy174,WN_SQL_MAX_COLUMN,"index");
		if(yygotominor.yy174)yygotominor.yy174->a[yygotominor.yy174->nExpr-1].sortOrder=yymsp[0].minor.yy46;
		break;
	case 142:
		yygotominor.yy410.z=0;yygotominor.yy410.n=0;
		break;
	case 143:
		WN_SQL3DropIndex(pParse,yymsp[0].minor.yy373,yymsp[-1].minor.yy46);
		break;
	case 144:
		WN_SQL3Vacuum(pParse);
		break;
	case 145:
		WN_SQL3Pragma(pParse,&yymsp[-3].minor.yy410,&yymsp[-2].minor.yy410,&yymsp[0].minor.yy410,0);
		break;
	case 146:
		WN_SQL3Pragma(pParse,&yymsp[-3].minor.yy410,&yymsp[-2].minor.yy410,&yymsp[0].minor.yy0,0);
		break;
	case 147:
		WN_SQL3Pragma(pParse,&yymsp[-3].minor.yy410,&yymsp[-2].minor.yy410,&yymsp[0].minor.yy410,1);
		break;
	case 148:
		WN_SQL3Pragma(pParse,&yymsp[-4].minor.yy410,&yymsp[-3].minor.yy410,&yymsp[-1].minor.yy410,0);
		break;
	case 149:
		WN_SQL3Pragma(pParse,&yymsp[-1].minor.yy410,&yymsp[0].minor.yy410,0,0);
		break;
	case 150:
		Token all;all.z=yymsp[-3].minor.yy410.z;
		all.n=(yymsp[0].minor.yy0.z-yymsp[-3].minor.yy410.z)+yymsp[0].minor.yy0.n;
		WN_SQL3FinishTrigger(pParse,yymsp[-1].minor.yy243,&all);
		break;
	case 151:
		WN_SQL3BeginTrigger(pParse,&yymsp[-7].minor.yy410,&yymsp[-6].minor.yy410,yymsp[-5].minor.yy46,yymsp[-4].minor.yy370.a,yymsp[-4].minor.yy370.b,yymsp[-2].minor.yy373,yymsp[0].minor.yy172,yymsp[-10].minor.yy46,yymsp[-8].minor.yy46);
		yygotominor.yy410=(yymsp[-6].minor.yy410.n==0?yymsp[-7].minor.yy410:yymsp[-6].minor.yy410);
		break;
	case 152:
		yygotominor.yy46=TK_BEFORE;
		break;
	case 153:
		yygotominor.yy46=TK_AFTER;
		break;
	case 154:
		yygotominor.yy46=TK_INSTEAD;
		break;
	case 155:
		yygotominor.yy370.a=yymsp[0].major;yygotominor.yy370.b=0;
		break;
	case 156:
		yygotominor.yy370.a=TK_UPDATE;yygotominor.yy370.b=yymsp[0].minor.yy432;
		break;
	case 157:
		yygotominor.yy172=0;
		break;
	case 158:
		yygotominor.yy172=yymsp[0].minor.yy172;
		break;
	case 159:
		if(yymsp[-2].minor.yy243)
			yymsp[-2].minor.yy243->pLast->pNext=yymsp[-1].minor.yy243;
		else
			yymsp[-2].minor.yy243=yymsp[-1].minor.yy243;
		yymsp[-2].minor.yy243->pLast=yymsp[-1].minor.yy243;
		yygotominor.yy243=yymsp[-2].minor.yy243;
		break;
	case 160:
		yygotominor.yy243=0;
		break;
	case 161:
		yygotominor.yy243=WN_SQL3TriggerUpdateStep(&yymsp[-3].minor.yy410,yymsp[-1].minor.yy174,yymsp[0].minor.yy172,yymsp[-4].minor.yy46);
		break;
	case 162:
		yygotominor.yy243=WN_SQL3TriggerInsertStep(&yymsp[-5].minor.yy410,yymsp[-4].minor.yy432,yymsp[-1].minor.yy174,0,yymsp[-7].minor.yy46);
		break;
	case 163:
		yygotominor.yy243=WN_SQL3TriggerInsertStep(&yymsp[-2].minor.yy410,yymsp[-1].minor.yy432,0,yymsp[0].minor.yy219,yymsp[-4].minor.yy46);
		break;
	case 164:
		yygotominor.yy243=WN_SQL3TriggerDeleteStep(&yymsp[-1].minor.yy410,yymsp[0].minor.yy172);
		break;
	case 165:
		yygotominor.yy243=WN_SQL3TriggerSelectStep(yymsp[0].minor.yy219);
		break;
	case 166:
		yygotominor.yy172=WN_SQL3Expr(TK_RAISE,0,0,0);
		if(yygotominor.yy172)
		{
			yygotominor.yy172->iColumn=OE_Ignore;
			WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-3].minor.yy0,&yymsp[0].minor.yy0);
		}
		break;
	case 167:
		yygotominor.yy172=WN_SQL3Expr(TK_RAISE,0,0,&yymsp[-1].minor.yy410);
		if(yygotominor.yy172)
		{
			yygotominor.yy172->iColumn=yymsp[-3].minor.yy46;
			WN_SQL3ExprSpan(yygotominor.yy172,&yymsp[-5].minor.yy0,&yymsp[0].minor.yy0);
		}
		break;
	case 168:
		yygotominor.yy46=OE_Rollback;
		break;
	case 169:
		yygotominor.yy46=OE_Fail;
		break;
	case 170:
		WN_SQL3DropTrigger(pParse,yymsp[0].minor.yy373,yymsp[-1].minor.yy46);
		break;
	case 171:
		WN_SQL3Attach(pParse,yymsp[-3].minor.yy172,yymsp[-1].minor.yy172,yymsp[0].minor.yy386);
		break;
	case 172:
		WN_SQL3Detach(pParse,yymsp[0].minor.yy172);
		break;
	case 173:
		yygotominor.yy386=0;
		break;
	case 174:
		yygotominor.yy386=yymsp[0].minor.yy172;
		break;
	case 175:
		WN_SQL3Reindex(pParse,0,0);
		break;
	case 176:
		WN_SQL3Reindex(pParse,&yymsp[-1].minor.yy410,&yymsp[0].minor.yy410);
		break;
	case 177:
		WN_SQL3Analyze(pParse,0,0);
		break;
	case 178:
		WN_SQL3Analyze(pParse,&yymsp[-1].minor.yy410,&yymsp[0].minor.yy410);
		break;
	case 179:
		WN_SQL3AlterRenameTable(pParse,yymsp[-3].minor.yy373,&yymsp[0].minor.yy410);
		break;
	case 180:
		WN_SQL3AlterFinishAddColumn(pParse,&yymsp[0].minor.yy410);
		break;
	case 181:
		WN_SQL3AlterBeginAddColumn(pParse,yymsp[0].minor.yy373);
		break;
	case 182:
		WN_SQL3VtabFinishParse(pParse,0);
		break;
	case 183:
		WN_SQL3VtabFinishParse(pParse,&yymsp[0].minor.yy0);
		break;
	case 184:
		WN_SQL3VtabBeginParse(pParse,&yymsp[-3].minor.yy410,&yymsp[-2].minor.yy410,&yymsp[0].minor.yy410);
		break;
	case 185:
		WN_SQL3VtabArgInit(pParse);
		break;
	case 186:
		WN_SQL3VtabArgExtend(pParse,&yymsp[0].minor.yy0);
	};
	yygoto=yyRuleInfo[yyruleno].lhs;
	yysize=yyRuleInfo[yyruleno].nrhs;
	yypParser->yyidx-=yysize;
	yyact=yy_find_reduce_action(yymsp[-yysize].stateno,yygoto);
	if(yyact<YYNSTATE)
	{
#ifdef NDEBUG
		if(yysize)
		{
			yypParser->yyidx++;
			yymsp-=yysize-1;
			yymsp->stateno=yyact;
			yymsp->major=yygoto;
			yymsp->minor=yygotominor;
		}
		else
#endif
			yy_shift(yypParser,yyact,yygoto,&yygotominor);
	}
	else
		if(yyact==YYNSTATE+YYNRULE+1)yy_accept(yypParser);
}
void yy_parse_failed(yyParser *yypParser)
{
	WN_SQL3ParserARG_FETCH;
#ifndef NDEBUG
	if(yyTraceFILE)	fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
#endif
	while(yypParser->yyidx>=0)yy_pop_parser_stack(yypParser);
	WN_SQL3ParserARG_STORE;
}
void yy_syntax_error(yyParser *yypParser,int yymajor,YYMINORTYPE yyminor)
{
	WN_SQL3ParserARG_FETCH;
#define TOKEN(yyminor.yy0)
	if(!pParse->parseError)
	{
		if(TOKEN.z[0])
			WN_SQL3ErrorMsg(pParse,"near \"%T\":syntax error",&TOKEN);
		else
			WN_SQL3ErrorMsg(pParse,"incomplete SQL statement");
		pParse->parseError=1;
	}
	WN_SQL3ParserARG_STORE;
}
void yy_accept(yyParser *yypParser)
{
	WN_SQL3ParserARG_FETCH;
#ifndef NDEBUG
	if(yyTraceFILE)fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
#endif
	while(yypParser->yyidx>=0)yy_pop_parser_stack(yypParser);
	WN_SQL3ParserARG_STORE;
}
void WN_SQL3Parser(void *yyp,int yymajor,WN_SQL3ParserTOKENTYPE yyminor
						  WN_SQL3ParserARG_PDECL)
{
	YYMINORTYPE yyminorunion;
	int yyact,yyendofinput,yyerrorhit=0;
	yyParser *yypParser;
	yypParser=(yyParser*)yyp;
	if(yypParser->yyidx<0)
	{
#if YYSTACKDEPTH<=0
		if(yypParser->yystksz<=0)
		{
			memset(&yyminorunion,0,sizeof(yyminorunion));
			yyStackOverflow(yypParser,&yyminorunion);
			return;
		}
#endif
		yypParser->yyidx=0;
		yypParser->yyerrcnt=-1;
		yypParser->yystack[0].stateno=0;
		yypParser->yystack[0].major=0;
	}
	yyminorunion.yy0=yyminor;
	yyendofinput=(yymajor==0);
	WN_SQL3ParserARG_STORE;
#ifndef NDEBUG
	if(yyTraceFILE)
		fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
#endif
	do
	{
		yyact=yy_find_shift_action(yypParser,yymajor);
		if(yyact<YYNSTATE)
		{
			yy_shift(yypParser,yyact,yymajor,&yyminorunion);
			yypParser->yyerrcnt--;
			if(yyendofinput && yypParser->yyidx>=0)
				yymajor=0;
			else
				yymajor=YYNOCODE;
		}
		else
			if(yyact<YYNSTATE+YYNRULE)
				yy_reduce(yypParser,yyact-YYNSTATE);
			else
				if(yyact==YY_ERROR_ACTION)
				{
					int yymx;
#ifndef NDEBUG
					if(yyTraceFILE)
						fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
#endif
#ifdef YYERRORSYMBOL
					if(yypParser->yyerrcnt<0)
						yy_syntax_error(yypParser,yymajor,yyminorunion);
					yymx=yypParser->yystack[yypParser->yyidx].major;
					if(yymx==YYERRORSYMBOL || yyerrorhit)
					{
#ifndef NDEBUG
						if(yyTraceFILE)	fprintf(yyTraceFILE,"%sDiscard input token %s\n",yyTracePrompt,yyTokenName[yymajor]);
#endif
						yy_destructor(yymajor,&yyminorunion);
						yymajor=YYNOCODE;
					}
					else
					{
						while(yypParser->yyidx>=0 && yymx!=YYERRORSYMBOL &&
							(yyact=yy_find_reduce_action(yypParser->yystack	[yypParser->yyidx].stateno,YYERRORSYMBOL))>=YYNSTATE)
							yy_pop_parser_stack(yypParser);
						if(yypParser->yyidx<0 || yymajor==0)
						{
							yy_destructor(yymajor,&yyminorunion);
							yy_parse_failed(yypParser);
							yymajor=YYNOCODE;
						}
						else
							if(yymx!=YYERRORSYMBOL)
							{
								YYMINORTYPE u2;
								u2.YYERRSYMDT=0;
								yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
							}
					}
					yypParser->yyerrcnt=3;
					yyerrorhit=1;
#else
					if(yypParser->yyerrcnt<=0)
						yy_syntax_error(yypParser,yymajor,yyminorunion);
					yypParser->yyerrcnt=3;
					yy_destructor(yymajor,&yyminorunion);
					if(yyendofinput)yy_parse_failed(yypParser);
					yymajor=YYNOCODE;
#endif
				}
				else
				{
					yy_accept(yypParser);
					yymajor=YYNOCODE;
				}
	}while(yymajor!=YYNOCODE && yypParser->yyidx>=0);
	return;
}
#ifdef WN_SQL_ASCII
# define charMap(X)WN_SQL3UpperToLower[(unsigned char)X]
#endif
#ifdef WN_SQL_EBCDIC
# define charMap(X)ebcdicToAscii[(unsigned char)X]
const unsigned char ebcdicToAscii[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,95,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,98,99,100,101,102,103,104,105,0,0,0,0,0,0,0,106,107,108,109,110,111,112,113,114,0,0,0,0,0,0,0,0,115,116,117,118,119,120,121,122,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,97,98,99,100,101,102,103,104,105,0,0,0,0,0,0,0,106,107,108,109,110,111,112,113,114,0,0,0,0,0,0,0,0,115,116,117,118,119,120,121,122,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
#endif
int keywordCode(const char *z,int n)
{
	const char zText[526]=
"BEFOREIGNOREGEXPLAINSTEADDESCAPEACHECKEYCONSTRAINTERSECTABLEFT"
"HENDATABASELECTRANSACTIONATURALTERAISELSEXCEPTRIGGEREFERENCES"
"UNIQUERYATTACHAVINGROUPDATEMPORARYBEGINNEREINDEXCLUSIVEXISTSBETWEEN"
"OTNULLIKECASCADEFERRABLECASECOLLATECREATECURRENT_DATEDELETEDETACH"
"IMMEDIATEJOINSERTMATCHPLANALYZEPRAGMABORTVALUESVIRTUALIMITWHEN"
"WHERENAMEAFTEREPLACEANDEFAULTAUTOINCREMENTCASTCOLUMNCOMMITCONFLICT"
"CROSSCURRENT_TIMESTAMPRIMARYDEFERREDISTINCTDROPFAILFROMFULLGLOB"
"YIFINTOFFSETISNULLORDERESTRICTOUTERIGHTROLLBACKROWUNIONUSINGVACUUM"
"VIEWINITIALLY";
	const unsigned char aHash[127]={63,92,109,61,0,38,0,0,69,0,64,0,0,102,4,65,7,0,108,72,103,99,0,22,0,0,113,0,111,106,0,18,80,0,1,0,0,56,57,0,55,11,0,33,77,89,0,110,88,0,0,45,0,90,54,0,20,0,114,34,19,0,10,97,28,83,0,0,116,93,47,115,41,12,44,0,78,0,87,29,0,86,0,0,0,82,79,84,75,96,6,14,95,0,68,0,21,76,98,27,0,112,67,104,49,40,71,0,0,81,100,0,107,0,15,0,0,24,0,73,42,50,0,16,48,0,37,};
	const unsigned char aNext[116]={0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,17,0,0,0,36,39,0,0,25,0,0,31,0,0,0,43,52,0,0,0,53,0,0,0,0,0,0,0,0,0,51,0,0,0,0,26,0,8,46,2,0,0,0,0,0,0,0,3,58,66,0,13,0,91,85,0,94,0,74,0,0,62,0,35,101,0,0,105,23,30,60,70,0,0,59,0,0,};
	const unsigned char aLen[116]={6,7,3,6,6,7,7,3,4,6,4,5,3,10,9,5,4,4,3,8,2,6,11,2,7,5,5,4,6,7,10,6,5,6,6,5,6,4,9,2,5,5,7,5,9,6,7,7,3,4,4,7,3,10,4,7,6,12,6,6,9,4,6,5,4,7,6,5,6,7,5,4,5,6,5,7,3,7,13,2,2,4,6,6,8,5,17,12,7,8,8,2,4,4,4,4,4,2,2,4,6,2,3,6,5,8,5,5,8,3,5,5,6,4,9,3,};
	const unsigned short int aOffset[116]={0,2,2,6,10,13,18,23,25,26,31,33,37,40,47,55,58,61,63,65,70,71,76,85,86,91,95,99,102,107,113,123,126,131,136,141,144,148,148,152,157,160,164,166,169,177,183,189,189,192,195,199,200,204,214,218,225,231,243,249,255,264,266,272,277,279,286,291,296,302,308,313,317,320,326,330,337,339,346,348,350,359,363,369,375,383,388,388,404,411,418,419,426,430,434,438,442,445,447,449,452,452,455,458,464,468,476,480,485,493,496,501,506,512,516,521,};
	const unsigned char aCode[116]={TK_BEFORE,TK_FOREIGN,TK_FOR,TK_IGNORE,TK_LIKE_KW,TK_EXPLAIN,TK_INSTEAD,TK_ADD,TK_DESC,TK_ESCAPE,TK_EACH,TK_CHECK,TK_KEY,TK_CONSTRAINT,TK_INTERSECT,TK_TABLE,TK_JOIN_KW,TK_THEN,TK_END,TK_DATABASE,TK_AS,TK_SELECT,TK_TRANSACTION,TK_ON,TK_JOIN_KW,TK_ALTER,TK_RAISE,TK_ELSE,TK_EXCEPT,TK_TRIGGER,TK_REFERENCES,TK_UNIQUE,TK_QUERY,TK_ATTACH,TK_HAVING,TK_GROUP,TK_UPDATE,TK_TEMP,TK_TEMP,TK_OR,TK_BEGIN,TK_JOIN_KW,TK_REINDEX,TK_INDEX,TK_EXCLUSIVE,TK_EXISTS,TK_BETWEEN,TK_NOTNULL,TK_NOT,TK_NULL,TK_LIKE_KW,TK_CASCADE,TK_ASC,TK_DEFERRABLE,TK_CASE,TK_COLLATE,TK_CREATE,TK_CTIME_KW,TK_DELETE,TK_DETACH,TK_IMMEDIATE,TK_JOIN,TK_INSERT,TK_MATCH,TK_PLAN,TK_ANALYZE,TK_PRAGMA,TK_ABORT,TK_VALUES,TK_VIRTUAL,TK_LIMIT,TK_WHEN,TK_WHERE,TK_RENAME,TK_AFTER,TK_REPLACE,TK_AND,TK_DEFAULT,TK_AUTOINCR,TK_TO,TK_IN,TK_CAST,TK_COLUMNKW,TK_COMMIT,TK_CONFLICT,TK_JOIN_KW,TK_CTIME_KW,TK_CTIME_KW,TK_PRIMARY,TK_DEFERRED,TK_DISTINCT,TK_IS,TK_DROP,TK_FAIL,TK_FROM,TK_JOIN_KW,TK_LIKE_KW,TK_BY,TK_IF,TK_INTO,TK_OFFSET,TK_OF,TK_SET,TK_ISNULL,TK_ORDER,TK_RESTRICT,TK_JOIN_KW,TK_JOIN_KW,TK_ROLLBACK,TK_ROW,TK_UNION,TK_USING,TK_VACUUM,TK_VIEW,TK_INITIALLY,TK_ALL,};
	int h,i;
	if(n<2)return TK_ID;
	int h=((charMap(z[0])*4)^(charMap(z[n-1])*3)^n)% 127,i;
	for(i=((int)aHash[h])-1;i>=0;i=((int)aNext[i])-1)
		if(aLen[i]==n && WN_SQL3StrNICmp(&zText[aOffset[i]],z,n)==0)return aCode[i];
	return TK_ID;
}
int WN_SQL3KeywordCode(const unsigned char *z,int n)
{
	return keywordCode((char*)z,n);
}
#ifdef WN_SQL_ASCII
const char WN_SQL3IsIdChar[]={0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,};
#define IdChar(C)(((c=C)&0x80)||(c>0x1f && WN_SQL3IsIdChar[c-0x20]))
#endif
#ifdef WN_SQL_EBCDIC
const char WN_SQL3IsIdChar[]={0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,};
#define IdChar(C)(((c=C)>=0x42 && WN_SQL3IsIdChar[c-0x40]))
#endif
int getToken(const unsigned char *z,int *tokenType)
{
	int i,c;
	switch(*z)
	{
	case ' ':
	case '\t':
	case '\n':
	case '\f':
	case '\r':
		for(i=1;isspace(z[i]);i++);
		*tokenType=TK_SPACE;
		return i;
	case '-':
		if(z[1]=='-')
		{
			for(i=2;(c=z[i])&& c!='\n';i++);
			*tokenType=TK_COMMENT;
			return i;
		}
		*tokenType=TK_MINUS;
		return 1;
	case '(':
		*tokenType=TK_LP;
		return 1;
	case ')':
		*tokenType=TK_RP;
		return 1;
	case ';':
		*tokenType=TK_SEMI;
		return 1;
	case '+':
		*tokenType=TK_PLUS;
		return 1;
	case '*':
		*tokenType=TK_STAR;
		return 1;
	case '/':
		if(z[1]!='*' || z[2]==0)
		{
			*tokenType=TK_SLASH;
			return 1;
		}
		for(i=3,c=z[2];(c!='*' || z[i]!='/')&&(c=z[i]);i++);
		if(c)i++;
		*tokenType=TK_COMMENT;
		return i;
	case '%':
		*tokenType=TK_REM;
		return 1;
	case '=':
		*tokenType=TK_EQ;
		return 1+(z[1]=='=');
	case '<':
		if((c=z[1])=='=')
		{
			*tokenType=TK_LE;
			return 2;
		}
		else
			if(c=='>')
			{
				*tokenType=TK_NE;
				return 2;
			}
			else
				if(c=='<')
				{
					*tokenType=TK_LSHIFT;
					return 2;
				}
				else
				{
					*tokenType=TK_LT;
					return 1;
				}
	case '>':
		if((c=z[1])=='=')
		{
			*tokenType=TK_GE;
			return 2;
		}
		else
			if(c=='>')
			{
				*tokenType=TK_RSHIFT;
				return 2;
			}
			else
			{
				*tokenType=TK_GT;
				return 1;
			}
	case '!':
		if(z[1]!='=')
		{
			*tokenType=TK_ILLEGAL;
			return 2;
		}
		else
		{
			*tokenType=TK_NE;
			return 2;
		}
	case '|':
		if(z[1]!='|')
		{
			*tokenType=TK_BITOR;
			return 1;
		}
		else
		{
			*tokenType=TK_CONCAT;
			return 2;
		}
	case ',':
		*tokenType=TK_COMMA;
		return 1;
	case '&':
		*tokenType=TK_BITAND;
		return 1;
	case '~':
		tokenType=TK_BITNOT;
		return 1;
	case '`':
	case '\'':
	case '"':
		int delim=z[0];
		for(i=1;(c=z[i]);i++)
			if(c==delim)
				if(z[i+1]==delim)
					i++;
				else
					break;
		if(c)
		{
			*tokenType=TK_STRING;
			return i+1;
		}
		else
		{
			*tokenType=TK_ILLEGAL;
			return i;
		}
	case '.':
#ifndef WN_SQL_OMIT_FLOATING_POINT
		if(!isdigit(z[1]))
#endif
		{
			*tokenType=TK_DOT;
			return 1;
		}
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		*tokenType=TK_INTEGER;
		for(i=0;isdigit(z[i]);i++);
#ifndef WN_SQL_OMIT_FLOATING_POINT
		if(z[i]=='.')
		{
			i++;
			while(isdigit(z[i]))i++;
			*tokenType=TK_FLOAT;
		}
		if((z[i]=='e' || z[i]=='E')&& (isdigit(z[i+1])||((z[i+1]=='+' || z[i+1]=='-')&& isdigit(z[i+2]))))
		{
			i+=2;
			while(isdigit(z[i]))i++;
			*tokenType=TK_FLOAT;
		}
#endif
		while(IdChar(z[i]))
		{
			*tokenType=TK_ILLEGAL;
			i++;
		}
	return i;
	case '[':
		for(i=1,c=z[0];c!=']' &&(c=z[i]);i++);
		*tokenType=TK_ID;
		return i;
	case '?':
		*tokenType=TK_VARIABLE;
		for(i=1;isdigit(z[i]);i++);
		return i;
	case '#':
		for(i=1;isdigit(z[i]);i++);
		if(i>1)
		{
			*tokenType=TK_REGISTER;
			return i;
		}
#ifndef WN_SQL_OMIT_TCL_VARIABLE
	case '$':
#endif
	case '@':
	case ':':
		int n=0;
		*tokenType=TK_VARIABLE;
		for(i=1;(c=z[i]);i++)
		{
			if(IdChar(c))
			{
				n++;
#ifndef WN_SQL_OMIT_TCL_VARIABLE
			}
			else
				if(c=='(' && n>0)
				{
					do
					{
						i++;
					}while((c=z[i])&& !isspace(c)&& c!=')');
					if(c==')')
						i++;
					else
						*tokenType=TK_ILLEGAL;
					break;
				}
				else
					if(c==':' && z[i+1]==':')
					{
						i++;
#endif
					}
					else
						break;
		}
		if(n==0)*tokenType=TK_ILLEGAL;
		return i;
#ifndef WN_SQL_OMIT_BLOB_LITERAL
	case 'x':case 'X':
		if((c=z[1])=='\'' || c=='"')
		{
			int delim=c;
			*tokenType=TK_BLOB;
			for(i=2;(c=z[i]);i++)
			{
				if(c==delim)
				{
					if(i%2)*tokenType=TK_ILLEGAL;
					break;
				}
				if(!isxdigit(c))
				{
					*tokenType=TK_ILLEGAL;
					return i;
				}
			}
			if(c)i++;
			return i;
		}
#endif
	default:
		if(!IdChar(*z))break;
		for(i=1;IdChar(z[i]);i++);
		*tokenType=keywordCode((char*)z,i);
		return i;
	}
	*tokenType=TK_ILLEGAL;
	return 1;
}
int WN_SQL3GetToken(const unsigned char *z,int *tokenType)
{
	return getToken(z,tokenType);
}
int WN_SQL3RunParser(Parse *pParse,const char *zSql,char **pzErrMsg)
{
	int nErr=0;,i=0,tokenType,lastTokenParsed=-1;
	WN_SQL3 *db=pParse->db;
	if(db->activeVdbeCnt==0)db->u1.isInterrupted=0;
	pParse->rc=0;
	void *pEngine=WN_SQL3ParserAlloc((void*(*)(size_t))WN_SQL3MallocX);
	if(pEngine==0)return WN_SQL_NOMEM;
	pParse->zTail=pParse->zSql=zSql;
	while(!WN_SQL3MallocFailed()&& zSql[i])
	{
		pParse->sLastToken.z=(u8*)&zSql[i];
		pParse->sLastToken.n=getToken((unsigned char*)&zSql[i],&tokenType);
		i+=pParse->sLastToken.n;
		if(i>WN_SQL_MAX_SQL_LENGTH)
		{
			pParse->rc=WN_SQL_TOOBIG;
			break;
		}
		switch(tokenType)
		{
		case TK_SPACE:
		case TK_COMMENT:
			if(db->u1.isInterrupted)
			{
				pParse->rc=WN_SQL_INTERRUPT;
				WN_SQL3SetString(pzErrMsg,"interrupt",(char*)0);
				goto abort_parse;
			}
			break;
		case TK_ILLEGAL:
			if(pzErrMsg)
			{
				WN_SQL3FreeX(*pzErrMsg);
				*pzErrMsg=WN_SQL3MPrintf("unrecognized token:\"%T\"",
					&pParse->sLastToken);
			}
			nErr++;
			goto abort_parse;
		case TK_SEMI:
				pParse->zTail=&zSql[i];
		default:
			WN_SQL3Parser(pEngine,tokenType,pParse->sLastToken,pParse);
			lastTokenParsed=tokenType;
			if(pParse->rc)goto abort_parse;
		}
	}
abort_parse:
	if(zSql[i]==0 && nErr==0 && pParse->rc==0)
	{
		if(lastTokenParsed!=TK_SEMI)
		{
			WN_SQL3Parser(pEngine,TK_SEMI,pParse->sLastToken,pParse);
			pParse->zTail=&zSql[i];
		}
		WN_SQL3Parser(pEngine,0,pParse->sLastToken,pParse);
	}
	WN_SQL3ParserFree(pEngine,WN_SQL3FreeX);
	if(WN_SQL3MallocFailed())pParse->rc=WN_SQL_NOMEM;
	if(pParse->rc && pParse->rc!=WN_SQL_DONE && pParse->zErrMsg==0)
		WN_SQL3SetString(&pParse->zErrMsg,WN_SQL3ErrStr(pParse->rc),(char*)0);
	if(pParse->zErrMsg)
	{
		if(pzErrMsg && *pzErrMsg==0)
			*pzErrMsg=pParse->zErrMsg;
		else
			WN_SQL3FreeX(pParse->zErrMsg);
		pParse->zErrMsg=0;
		if(!nErr)nErr++;
	}
	if(pParse->pVdbe && pParse->nErr>0 && pParse->nested==0)
	{
		WN_SQL3VdbeDelete(pParse->pVdbe);
		pParse->pVdbe=0;
	}
#ifndef WN_SQL_OMIT_SHARED_CACHE
	if(pParse->nested==0)
	{
		WN_SQL3FreeX(pParse->aTableLock);
		pParse->aTableLock=0;
		pParse->nTableLock=0;
	}
#endif
	if(!IN_DECLARE_VTAB)WN_SQL3DeleteTable(pParse->pNewTable);
	WN_SQL3DeleteTrigger(pParse->pNewTrigger);
	WN_SQL3FreeX(pParse->apVarExpr);
	if(nErr>0 &&(pParse->rc==0 || pParse->rc==WN_SQL_DONE)) pParse->rc=WN_SQL_ERROR;
	return nErr;
}
void(*WN_SQL3_io_trace)(const char*,...)=0;

int binCollFunc(void *NotUsed,int nKey1,const void *pKey1,int nKey2,
					   const void *pKey2)
{
	int rc,n;
	n=nKey1<nKey2 ? nKey1 :nKey2;
	rc=memcmp(pKey1,pKey2,n);
	if(rc==0)rc=nKey1-nKey2;
	return rc;
}
int nocaseCollatingFunc(void *NotUsed,int nKey1,const void *pKey1,
	int nKey2,const void *pKey2)
{
	int r=WN_SQL3StrNICmp((const char *)pKey1,(const char *)pKey2,
		(nKey1<nKey2)?nKey1:nKey2);
	if(0==r)r=nKey1-nKey2;
	return r;
}
WN_SQL_int64 WN_SQL3_last_insert_rowid(WN_SQL3 *db)
{
	return db->lastRowid;
}
int WN_SQL3_changes(WN_SQL3 *db)
{
	return db->nChange;
}
int WN_SQL3_total_changes(WN_SQL3 *db)
{
	return db->nTotalChange;
}
int WN_SQL3_close(WN_SQL3 *db)
{
	HashElem *i;
	int j;
	if(!db)	return 0;
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
#ifdef WN_SQL_SSE
	extern void WN_SQL3SseCleanup(WN_SQL3*);
	WN_SQL3SseCleanup(db);
#endif
	WN_SQL3ResetInternalSchema(db,0);
	WN_SQL3VtabRollback(db);
	if(db->pVdbe)
	{
		WN_SQL3Error(db,WN_SQL_BUSY,
			"Unable to close due to unfinalised statements");
		return WN_SQL_BUSY;
	}
		if(db->magic!=WN_SQL_MAGIC_CLOSED && WN_SQL3SafetyOn(db))
		return WN_SQL_ERROR;
	for(j=0;j<db->nDb;j++)
	{
		struct Db *pDb=&db->aDb[j];
		if(pDb->pBt)
		{
			WN_SQL3BtreeClose(pDb->pBt);
			pDb->pBt=0;
			if(j!=1)pDb->pSchema=0;
		}
	}
	WN_SQL3ResetInternalSchema(db,0);
			for(i=WN_SQLHashFirst(&db->aFunc);i;i=WN_SQLHashNext(i))
	{
		FuncDef *pFunc,*pNext;
		for(pFunc=(FuncDef*)WN_SQLHashData(i);pFunc;pFunc=pNext)
		{
			pNext=pFunc->pNext;
			WN_SQL3FreeX(pFunc);
		}
	}
	for(i=WN_SQLHashFirst(&db->aCollSeq);i;i=WN_SQLHashNext(i))
	{
		CollSeq *pColl=(CollSeq *)WN_SQLHashData(i);
		for(j=0;j<3;j++)
			if(pColl[j].xDel)pColl[j].xDel(pColl[j].pUser);
		WN_SQL3FreeX(pColl);
	}
	WN_SQL3HashClear(&db->aCollSeq);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	for(i=WN_SQLHashFirst(&db->aModule);i;i=WN_SQLHashNext(i))
	{
		Module *pMod=(Module *)WN_SQLHashData(i);
		if(pMod->xDestroy)
		{
			pMod->xDestroy(pMod->pAux);
		}
		WN_SQL3FreeX(pMod);
	}
	WN_SQL3HashClear(&db->aModule);
#endif
	WN_SQL3HashClear(&db->aFunc);
	WN_SQL3Error(db,0,0);
	if(db->pErr)WN_SQL3ValueFree(db->pErr);
	WN_SQL3CloseExtensions(db);
	db->magic=WN_SQL_MAGIC_ERROR;
	WN_SQL3FreeX(db->aDb[1].pSchema);
	WN_SQL3FreeX(db);
	WN_SQL3ReleaseThreadData();
	return 0;
}
void WN_SQL3RollbackAll(WN_SQL3 *db)
{
	int i;
	int inTrans=0;
	for(i=0;i<db->nDb;i++)
	{
		if(db->aDb[i].pBt)
		{
			if(WN_SQL3BtreeIsInTrans(db->aDb[i].pBt))inTrans=1;
			WN_SQL3BtreeRollback(db->aDb[i].pBt);
			db->aDb[i].inTrans=0;
		}
	}
	WN_SQL3VtabRollback(db);
	if(db->flags&WN_SQL_InternChanges)WN_SQL3ResetInternalSchema(db,0);
	if(db->xRollbackCallback &&(inTrans || !db->autoCommit))
		db->xRollbackCallback(db->pRollbackArg);
}
const unsigned char WN_SQL3Err_index[]={0,1,2,3,4,5,6,7,8,9,10,11,2,12,13,2,14,15,16,17,18,19,20,21,22,23,24};
const char *WN_SQL3ErrString[]={"not an error","SQL logic error or missing database","unknown error","access permission denied","callback requested query abort","database is locked","database table is locked","out of memory","attempt to write a readonly database","interrupted","disk I/O error","database disk image is malformed","database or disk is full","unable to open database file","table contains no data","database schema has changed","String or BLOB exceeded size limit","constraint failed","datatype mismatch","library routine called out of sequence","kernel lacks large file support","authorization denied","auxiliary database format error","bind or column index out of range","file is encrypted or is not a database"};
const char *WN_SQL3ErrStr(int rc)
{
	if(rc>=100)
		if(rc>=255)
			rc&=255;
		else
			rc=0;
	return WN_SQL3ErrString[WN_SQL3Err_index[rc]];
}
int WN_SQLDefaultBusyCallback(void *ptr,int count)
{
#if OS_WIN ||(defined(HAVE_USLEEP)&& HAVE_USLEEP)
	const u8 delays[]={1,2,5,10,15,20,25,25,25,50,50,100};
	const u8 totals[]={0,1,3,8,18,33,53,78,103,128,178,228};
# define NDELAY(sizeof(delays)/sizeof(delays[0]))
	int timeout=((WN_SQL3 *)ptr)->busyTimeout;
	int delay,prior;
	if(count<NDELAY)
	{
		delay=delays[count];
		prior=totals[count];
	}
	else
	{
		delay=delays[NDELAY-1];
		prior=totals[NDELAY-1]+delay*(count-(NDELAY-1));
	}
	if(prior+delay > timeout)
	{
		delay=timeout-prior;
		if(delay<=0)return 0;
	}
	WN_SQL3OsSleep(delay);
	return 1;
#else
	int timeout=((WN_SQL3 *)ptr)->busyTimeout;
	if((count+1)*1000 > timeout)return 0;
	WN_SQL3OsSleep(1000);
	return 1;
#endif
}
int WN_SQL3InvokeBusyHandler(BusyHandler *p)
{
	if(p==0 || p->xFunc==0 || p->nBusy<0)return 0;
	int rc=p->xFunc(p->pArg,p->nBusy);
	if(rc)
		p->nBusy++;
	else
		p->nBusy=-1;
	return rc;
}
int WN_SQL3_busy_handler(WN_SQL3 *db,int(*xBusy)(void*,int),void *pArg)
{
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
	db->busyHandler.xFunc=xBusy;
	db->busyHandler.pArg=pArg;
	db->busyHandler.nBusy=0;
	return 0;
}
#ifndef WN_SQL_OMIT_PROGRESS_CALLBACK
void WN_SQL3_progress_handler(WN_SQL3 *db,int nOps,int(*xProgress)(void*),void *pArg)
{
	if(!WN_SQL3SafetyCheck(db))
		if(nOps>0)
		{
			db->xProgress=xProgress;
			db->nProgressOps=nOps;
			db->pProgressArg=pArg;
		}
		else
		{
			db->xProgress=0;
			db->nProgressOps=0;
			db->pProgressArg=0;
		}
}
#endif
int WN_SQL3_busy_timeout(WN_SQL3 *db,int ms)
{
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
	if(ms>0)
	{
		db->busyTimeout=ms;
		WN_SQL3_busy_handler(db,WN_SQLDefaultBusyCallback,(void*)db);
	}
	else
		WN_SQL3_busy_handler(db,0,0);
	return 0;
}
void WN_SQL3_interrupt(WN_SQL3 *db)
{
	if(db &&(db->magic==WN_SQL_MAGIC_OPEN || db->magic==WN_SQL_MAGIC_BUSY))db->u1.isInterrupted=1;
}
void WN_SQL3_free(void *p)
{
	if(p)WN_SQL3OsFree(p);
}
void *WN_SQL3_malloc(int nByte)
{
	return nByte>0 ? WN_SQL3OsMalloc(nByte):0;
}
void *WN_SQL3_realloc(void *pOld,int nByte)
{
	if(pOld)
		if(nByte>0)
			return WN_SQL3OsRealloc(pOld,nByte);
		else
		{
			WN_SQL3OsFree(pOld);
			return 0;
		}
	else
		return WN_SQL3_malloc(nByte);
}
int WN_SQL3CreateFunc(WN_SQL3 *db,const char *zFunctionName,int nArg,int enc,void *pUserData,void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value **),void(*xStep)(WN_SQL3_context*,int,WN_SQL3_value **),void(*xFinal)(WN_SQL3_context*))
{
	FuncDef *p;
	int nName;
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
	if(zFunctionName==0 ||(xFunc &&(xFinal || xStep))||
		(!xFunc &&(xFinal && !xStep))||(!xFunc &&(!xFinal && xStep))||
		(nArg<-1 || nArg>127)||(255<(nName=strlen(zFunctionName))))
	{
		WN_SQL3Error(db,WN_SQL_ERROR,"bad parameters");
		return WN_SQL_ERROR;
	}
#ifndef WN_SQL_OMIT_UTF16
	if(enc==WN_SQL_UTF16)
		enc=WN_SQL_UTF16NATIVE;
	else
		if(enc==WN_SQL_ANY)
		{
			int rc;
			rc=WN_SQL3CreateFunc(db,zFunctionName,nArg,WN_SQL_UTF8,pUserData,xFunc,xStep,xFinal);
			if(rc)return rc;
			rc=WN_SQL3CreateFunc(db,zFunctionName,nArg,WN_SQL_UTF16LE,pUserData,xFunc,xStep,xFinal);
			if(rc)return rc;
			enc=WN_SQL_UTF16BE;
		}
#else
	enc=WN_SQL_UTF8;
#endif
	p=WN_SQL3FindFunction(db,zFunctionName,nName,nArg,enc,0);
	if(p && p->iPrefEnc==enc && p->nArg==nArg)
		if(db->activeVdbeCnt)
		{
			WN_SQL3Error(db,WN_SQL_BUSY,"Unable to delete/modify user-function due to active statements");
						return WN_SQL_BUSY;
		}
		else
			WN_SQL3ExpirePreparedStatements(db);
	p=WN_SQL3FindFunction(db,zFunctionName,nName,nArg,enc,1);
	if(p)
	{
		p->flags=0;
		p->xFunc=xFunc;
		p->xStep=xStep;
		p->xFinalize=xFinal;
		p->pUserData=pUserData;
		p->nArg=nArg;
	}
	return 0;
}
int WN_SQL3_create_function(WN_SQL3 *db,const char *zFunctionName,int nArg,int enc,void *p,void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value **),void(*xStep)(WN_SQL3_context*,int,WN_SQL3_value **),void(*xFinal)(WN_SQL3_context*))
{
	return WN_SQL3ApiExit(db,WN_SQL3CreateFunc(db,zFunctionName,nArg,enc,p,xFunc,xStep,xFinal););
}
#ifndef WN_SQL_OMIT_UTF16
int WN_SQL3_create_function16(WN_SQL3 *db,const void *zFunctionName,int nArg,int eTextRep,void *p,void(*xFunc)(WN_SQL3_context*,int,WN_SQL3_value**),void(*xStep)(WN_SQL3_context*,int,WN_SQL3_value**),void(*xFinal)(WN_SQL3_context*))
{
	int rc;
	char *zFunc8;
	zFunc8=WN_SQL3Utf16to8(zFunctionName,-1);
	rc=WN_SQL3CreateFunc(db,zFunc8,nArg,eTextRep,p,xFunc,xStep,xFinal);
	WN_SQL3FreeX(zFunc8);
	return WN_SQL3ApiExit(db,rc);
}
#endif
int WN_SQL3_overload_function(WN_SQL3 *db,const char *zName,int nArg)
{
	int nName=strlen(zName);
	if(WN_SQL3FindFunction(db,zName,nName,nArg,WN_SQL_UTF8,0)==0)
		WN_SQL3CreateFunc(db,zName,nArg,WN_SQL_UTF8,0,WN_SQL3InvalidFunction,0,0);
	return WN_SQL3ApiExit(db,0);
}
#ifndef WN_SQL_OMIT_TRACE
void *WN_SQL3_trace(WN_SQL3 *db,void(*xTrace)(void*,const char*),void *pArg)
{
	void *pOld=db->pTraceArg;
	db->xTrace=xTrace;
	db->pTraceArg=pArg;
	return pOld;
}
void *WN_SQL3_profile(WN_SQL3 *db,void(*xProfile)(void*,const char*,N_SQL_uint64),void *pArg)
{
	void *pOld=db->pProfileArg;
	db->xProfile=xProfile;
	db->pProfileArg=pArg;
	return pOld;
}
#endif
void *WN_SQL3_commit_hook(WN_SQL3 *db,int(*xCallback)(void*),void *pArg)
{
	void *pOld=db->pCommitArg;
	db->xCommitCallback=xCallback;
	db->pCommitArg=pArg;
	return pOld;
}
void *WN_SQL3_update_hook(WN_SQL3 *db,void(*xCallback)(void*,int,char const *,char const *,WN_SQL_int64),void *pArg)
{
	void *pRet=db->pUpdateArg;
	db->xUpdateCallback=xCallback;
	db->pUpdateArg=pArg;
	return pRet;
}
void *WN_SQL3_rollback_hook(WN_SQL3 *db,void(*xCallback)(void*),void *pArg)
{
	void *pRet=db->pRollbackArg;
	db->xRollbackCallback=xCallback;
	db->pRollbackArg=pArg;
	return pRet;
}
int WN_SQL3BtreeFactory(const WN_SQL3 *db,const char *zFilename,int omitJournal,int nCache,Btree **ppBtree)
{
	int btree_flags=0,rc;
	if(omitJournal)
	{
		btree_flags |=BTREE_OMIT_JOURNAL;
	}
	if(db->flags & WN_SQL_NoReadlock)btree_flags |=BTREE_NO_READLOCK;
	if(zFilename==0)
#ifndef WN_SQL_OMIT_MEMORYDB
#if TEMP_STORE==1
		if(db->temp_store==2)zFilename=":memory:";
#endif
#if TEMP_STORE==2
		if(db->temp_store!=1)zFilename=":memory:";
#endif
#if TEMP_STORE==3
		zFilename=":memory:";
#endif
#endif
	if((rc=WN_SQL3BtreeOpen(zFilename,(WN_SQL3 *)db,ppBtree,btree_flags))==0)
	{
		WN_SQL3BtreeSetBusyHandler(*ppBtree,(void*)&db->busyHandler);
		WN_SQL3BtreeSetCacheSize(*ppBtree,nCache);
	}
	return rc;
}
const char *WN_SQL3_errmsg(WN_SQL3 *db)
{
	if(!db)	return WN_SQL3ErrStr(WN_SQL_NOMEM);
	if(WN_SQL3SafetyCheck(db)|| db->errCode==WN_SQL_MISUSE)
		return WN_SQL3ErrStr(WN_SQL_MISUSE);
	const char *z=(char*)WN_SQL3_value_text(db->pErr);
	if(z==0)z=WN_SQL3ErrStr(db->errCode);
	return z;
}
#ifndef WN_SQL_OMIT_UTF16
const void *WN_SQL3_errmsg16(WN_SQL3 *db)
{
	const char outOfMemBe[]={0,'o',0,'u',0,'t',0,' ',0,'o',0,'f',0,' ',0,'m',0,'e',0,'m',0,'o',0,'r',0,'y',0,0,0};
	const char misuseBe []={0,'l',0,'i',0,'b',0,'r',0,'a',0,'r',0,'y',0,' ',0,'r',0,'o',0,'u',0,'t',0,'i',0,'n',0,'e',0,' ',0,'c',0,'a',0,'l',0,'l',0,'e',0,'d',0,' ',0,'o',0,'u',0,'t',0,' ',0,'o',0,'f',0,' ',0,'s',0,'e',0,'q',0,'u',0,'e',0,'n',0,'c',0,'e',0,0,0};
	if(!db)	return(void *)(&outOfMemBe[WN_SQL_UTF16NATIVE==WN_SQL_UTF16LE?1:0]);
	if(WN_SQL3SafetyCheck(db)|| db->errCode==WN_SQL_MISUSE)
		return(void *)(&misuseBe[WN_SQL_UTF16NATIVE==WN_SQL_UTF16LE?1:0]);
	const void *z=WN_SQL3_value_text16(db->pErr);
	if(z==0)
	{
		WN_SQL3ValueSetStr(db->pErr,-1,WN_SQL3ErrStr(db->errCode),WN_SQL_UTF8,
			WN_SQL_STATIC);
		z=WN_SQL3_value_text16(db->pErr);
	}
	WN_SQL3ApiExit(0,0);
	return z;
}
#endif
int WN_SQL3_errcode(WN_SQL3 *db)
{
	if(!db || WN_SQL3MallocFailed())return WN_SQL_NOMEM;
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
	return db->errCode & db->errMask;
}
int createCollation(WN_SQL3* db,const char *zName,int enc,void* pCtx,
	int(*xCompare)(void*,int,const void*,int,const void*),void(*xDel)(void*))
{
	CollSeq *pColl;
	int enc2;
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
	enc2=enc & ~WN_SQL_UTF16_ALIGNED;
	if(enc2==WN_SQL_UTF16)enc2=WN_SQL_UTF16NATIVE;
	if(enc2&~3)
	{
		WN_SQL3Error(db,WN_SQL_ERROR,"unknown encoding");
		return WN_SQL_ERROR;
	}
	pColl=WN_SQL3FindCollSeq(db,(u8)enc2,zName,strlen(zName),0);
	if(pColl && pColl->xCmp)
	{
		if(db->activeVdbeCnt)
		{
			WN_SQL3Error(db,WN_SQL_BUSY,"Unable to delete/modify collation sequence due to active statements");
			return WN_SQL_BUSY;
		}
		WN_SQL3ExpirePreparedStatements(db);
		if((pColl->enc & ~WN_SQL_UTF16_ALIGNED)==enc2)
		{
			CollSeq *aColl=WN_SQL3HashFind(&db->aCollSeq,zName,strlen(zName));
			int j;
			for(j=0;j<3;j++)
			{
				CollSeq *p=&aColl[j];
				if(p->enc==pColl->enc)
				{
					if(p->xDel)	p->xDel(p->pUser);
					p->xCmp=0;
				}
			}
		}
	}
	pColl=WN_SQL3FindCollSeq(db,(u8)enc2,zName,strlen(zName),1);
	if(pColl)
	{
		pColl->xCmp=xCompare;
		pColl->pUser=pCtx;
		pColl->xDel=xDel;
		pColl->enc=enc2 |(enc & WN_SQL_UTF16_ALIGNED);
	}
	WN_SQL3Error(db,0,0);
	return 0;
}
int openDatabase(const char *zFilename,WN_SQL3 **ppDb)
{
	WN_SQL3 *db=WN_SQL3Malloc(sizeof(WN_SQL3));
	if(db==0)goto opendb_out;
	db->errMask=0xff;
	db->priorNewRowid=0;
	db->magic=WN_SQL_MAGIC_BUSY;
	db->nDb=2;
	db->aDb=db->aDbStatic;
	db->autoCommit=1;
	db->flags |=WN_SQL_ShortColNames
#if WN_SQL_DEFAULT_FILE_FORMAT<4
| WN_SQL_LegacyFileFmt
#endif
#ifdef WN_SQL_ENABLE_LOAD_EXTENSION
| WN_SQL_LoadExtension
#endif
;

	WN_SQL3HashInit(&db->aFunc,WN_SQL_HASH_STRING,0);
	WN_SQL3HashInit(&db->aCollSeq,WN_SQL_HASH_STRING,0);
#ifndef WN_SQL_OMIT_VIRTUALTABLE
	WN_SQL3HashInit(&db->aModule,WN_SQL_HASH_STRING,0);
#endif
	if(createCollation(db,"BINARY",WN_SQL_UTF8,0,binCollFunc,0)||
		createCollation(db,"BINARY",WN_SQL_UTF16BE,0,binCollFunc,0)||
		createCollation(db,"BINARY",WN_SQL_UTF16LE,0,binCollFunc,0)||
		(db->pDfltColl=WN_SQL3FindCollSeq(db,WN_SQL_UTF8,"BINARY",6,0))==0)
	{
		db->magic=WN_SQL_MAGIC_CLOSED;
		goto opendb_out;
	}
	createCollation(db,"NOCASE",WN_SQL_UTF8,0,nocaseCollatingFunc,0);
	db->pDfltColl->type=WN_SQL_COLL_BINARY;
	CollSeq *pColl=WN_SQL3FindCollSeq(db,WN_SQL_UTF8,"NOCASE",6,0);
	if(pColl)pColl->type=WN_SQL_COLL_NOCASE;
	int rc;
	if(rc=WN_SQL3BtreeFactory(db,zFilename,0,WN_SQL_DEFAULT_CACHE_SIZE,&db->aDb[0].pBt))
	{
		WN_SQL3Error(db,rc,0);
		db->magic=WN_SQL_MAGIC_CLOSED;
		goto opendb_out;
	}
	db->aDb[0].pSchema=WN_SQL3SchemaGet(db->aDb[0].pBt);
	db->aDb[1].pSchema=WN_SQL3SchemaGet(0);
	db->aDb[0].zName="main";
	db->aDb[0].safety_level=3;
#ifndef WN_SQL_OMIT_TEMPDB
	db->aDb[1].zName="temp";
	db->aDb[1].safety_level=1;
#endif
	db->magic=WN_SQL_MAGIC_OPEN;
	if(WN_SQL3MallocFailed())goto opendb_out;
	WN_SQL3Error(db,0,0);
	WN_SQL3RegisterBuiltinFunctions(db);
	(void)WN_SQL3AutoLoadExtensions(db);
	if(WN_SQL3_errcode(db))goto opendb_out;
#ifdef WN_SQL_ENABLE_FTS1
	if(!WN_SQL3MallocFailed())
	{
		extern int WN_SQL3Fts1Init(WN_SQL3*);
		rc=WN_SQL3Fts1Init(db);
	}
#endif
#ifdef WN_SQL_ENABLE_FTS2
	if(!WN_SQL3MallocFailed()&& rc==0)
	{
		extern int WN_SQL3Fts2Init(WN_SQL3*);
		rc=WN_SQL3Fts2Init(db);
	}
#endif
#ifdef WN_SQL_ENABLE_ICU
	if(!WN_SQL3MallocFailed()&& rc==0)
	{
		extern int WN_SQL3IcuInit(WN_SQL3*);
		rc=WN_SQL3IcuInit(db);
	}
#endif
	WN_SQL3Error(db,rc,0);
#ifdef WN_SQL_DEFAULT_LOCKING_MODE
	db->dfltLockMode=WN_SQL_DEFAULT_LOCKING_MODE;
	WN_SQL3PagerLockingMode(WN_SQL3BtreePager(db->aDb[0].pBt),		WN_SQL_DEFAULT_LOCKING_MODE);
#endif
opendb_out:
	if(WN_SQL_NOMEM==(rc=WN_SQL3_errcode(db)))
	{
		WN_SQL3_close(db);
		db=0;
	}
	*ppDb=db;
	return WN_SQL3ApiExit(0,rc);
}
int WN_SQL3_open(const char *zFilename,WN_SQL3 **ppDb)
{
	return openDatabase(zFilename,ppDb);
}
#ifndef WN_SQL_OMIT_UTF16
int WN_SQL3_open16(const void *zFilename,WN_SQL3 **ppDb)
{
	int rc;
	*ppDb=0;
	WN_SQL3_value *pVal=WN_SQL3ValueNew();
	WN_SQL3ValueSetStr(pVal,-1,zFilename,WN_SQL_UTF16NATIVE,WN_SQL_STATIC);
	char const *zFilename8=WN_SQL3ValueText(pVal,WN_SQL_UTF8);
	if(zFilename8)
	{
		rc=openDatabase(zFilename8,ppDb);
		if(rc==0 && *ppDb)
		{
			rc=WN_SQL3_exec(*ppDb,"PRAGMA encoding='UTF-16'",0,0,0);
			if(rc)
			{
				WN_SQL3_close(*ppDb);
				*ppDb=0;
	}	}	}
	WN_SQL3ValueFree(pVal);
	return WN_SQL3ApiExit(0,rc);
}
#endif
int WN_SQL3_finalize(WN_SQL3_stmt *pStmt)
{
	return pStmt && WN_SQL3VdbeFinalize((Vdbe*)pStmt);
}
int WN_SQL3_reset(WN_SQL3_stmt *pStmt)
{
	int rc;
	if(pStmt==0)
		rc=0;
	else
	{
		rc=WN_SQL3VdbeReset((Vdbe*)pStmt);
		WN_SQL3VdbeMakeReady((Vdbe*)pStmt,-1,0,0,0);
	}
	return rc;
}
int WN_SQL3_create_collation(WN_SQL3* db,const char *zName,int enc,	void* pCtx,
	int(*xCompare)(void*,int,const void*,int,const void*))
{
	return WN_SQL3ApiExit(db,createCollation(db,zName,enc,pCtx,xCompare,0));
}
int WN_SQL3_create_collation_v2(WN_SQL3* db,const char *zName,int enc,void* pCtx,
		int(*xCompare)(void*,int,const void*,int,const void*),void(*xDel)(void*))
{
	return WN_SQL3ApiExit(db,createCollation(db,zName,enc,pCtx,xCompare,xDel));
}
#ifndef WN_SQL_OMIT_UTF16
int WN_SQL3_create_collation16(WN_SQL3* db,const char *zName,int enc,void* pCtx,
		int(*xCompare)(void*,int,const void*,int,const void*))
{
	int rc=0;
	char *zName8=WN_SQL3Utf16to8(zName,-1);
	if(zName8)
	{
		rc=createCollation(db,zName8,enc,pCtx,xCompare,0);
		WN_SQL3FreeX(zName8);
	}
	return WN_SQL3ApiExit(db,rc);
}
#endif
int WN_SQL3_collation_needed(WN_SQL3 *db,void *pCollNeededArg,
		void(*xCollNeeded)(void*,WN_SQL3*,int eTextRep,const char*))
{
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
	db->xCollNeeded=xCollNeeded;
	db->xCollNeeded16=0;
	db->pCollNeededArg=pCollNeededArg;
	return 0;
}
#ifndef WN_SQL_OMIT_UTF16
int WN_SQL3_collation_needed16(WN_SQL3 *db,void *pCollNeededArg,
		void(*xCollNeeded16)(void*,WN_SQL3*,int eTextRep,const void*))
{
	if(WN_SQL3SafetyCheck(db))return WN_SQL_MISUSE;
	db->xCollNeeded=0;
	db->xCollNeeded16=xCollNeeded16;
	db->pCollNeededArg=pCollNeededArg;
	return 0;
}
#endif
int WN_SQL3_get_autocommit(WN_SQL3 *db)
{
	return db->autoCommit;
}
#ifdef WN_SQL_DEBUG
int WN_SQL3Corrupt(void)
{
	return WN_SQL_CORRUPT;
}
#endif
#ifndef WN_SQL_OMIT_SHARED_CACHE
int WN_SQL3_enable_shared_cache(int enable)
{
	ThreadData *pTd=WN_SQL3ThreadData();
	if(pTd)
	{
		if(pTd->pBtree && !enable)
		{
						return WN_SQL_MISUSE;
		}
		pTd->useSharedData=enable;
		WN_SQL3ReleaseThreadData();
	}
	return WN_SQL3ApiExit(0,0);
}
#endif
void WN_SQL3_thread_cleanup(void)
{
	ThreadData *pTd=WN_SQL3OsThreadSpecificData(0);
	if(pTd)
	{
		memset(pTd,0,sizeof(*pTd));
		WN_SQL3OsThreadSpecificData(-1);
	}
}
#ifdef WN_SQL_ENABLE_COLUMN_METADATA
int WN_SQL3_table_column_metadata(WN_SQL3 *db,const char *zDbName,
	const char *zTableName,const char *zColumnName,char const **pzDataType,
	char const **pzCollSeq,int *pNotNull,int *pPrimaryKey,int *pAutoinc)
{
	char *zErrMsg=0;
	char const *zDataType=0,*zCollSeq=0;
	Table *pTab=0;
	Column *pCol=0;
	int iCol,notnull=0,primarykey=0,autoinc=0,rc;
	if(WN_SQL3SafetyOn(db))return WN_SQL_MISUSE;
	if(rc=WN_SQL3Init(db,&zErrMsg))goto error_out;
	pTab=WN_SQL3FindTable(db,zTableName,zDbName);
	if(!pTab || pTab->pSelect)
	{
		pTab=0;
		goto error_out;
	}
	if(WN_SQL3IsRowid(zColumnName))
	{
		iCol=pTab->iPKey;
		if(iCol>=0)	pCol=&pTab->aCol[iCol];
	}
	else
	{
		for(iCol=0;iCol<pTab->nCol;iCol++)
		{
			pCol=&pTab->aCol[iCol];
			if(0==WN_SQL3StrICmp(pCol->zName,zColumnName))break;
		}
		if(iCol==pTab->nCol)
		{
			pTab=0;
			goto error_out;
		}
	}
	if(pCol)
	{
		zDataType=pCol->zType;
		zCollSeq=pCol->zColl;
		notnull=(pCol->notNull?1:0);
		primarykey=(pCol->isPrimKey?1:0);
		autoinc=((pTab->iPKey==iCol && pTab->autoInc)?1:0);
	}
	else
	{
		zDataType="INTEGER";
		primarykey=1;
	}
	if(!zCollSeq)zCollSeq="BINARY";
error_out:
	if(WN_SQL3SafetyOff(db))rc=WN_SQL_MISUSE;
	if(pzDataType)*pzDataType=zDataType;
	if(pzCollSeq)*pzCollSeq=zCollSeq;
	if(pNotNull)*pNotNull=notnull;
	if(pPrimaryKey)*pPrimaryKey=primarykey;
	if(pAutoinc)*pAutoinc=autoinc;
	if(!(rc || pTab))
	{
		WN_SQL3SetString(&zErrMsg,"no such table column:",zTableName,".",
			zColumnName,0);
		rc=WN_SQL_ERROR;
	}
	WN_SQL3Error(db,rc,(zErrMsg?"%s":0),zErrMsg);
	WN_SQL3FreeX(zErrMsg);
	return WN_SQL3ApiExit(db,rc);
}
#endif
int WN_SQL3_clear_bindings(WN_SQL3_stmt *pStmt)
{
	int i,rc;
	for(i=1;i<=WN_SQL3_bind_parameter_count(pStmt)&&(rc=WN_SQL3_bind_null(pStmt,i))==0;i++);
	return rc;
}
int WN_SQL3_extended_result_codes(WN_SQL3 *db,int onoff)
{
	db->errMask=onoff ? 0xffffffff :0xff;
	return 0;
}5000 33408