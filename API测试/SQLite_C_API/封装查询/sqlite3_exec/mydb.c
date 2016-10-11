//mydb_c
#include <stdio.h>
#include <sqlite3.h>
//数据库的回应
//打印SQL语句的结果

//callback函数
//参数1：自定义参数，这里没有使用
//参数2：查询结果的列数
//参数3：查询结果的每一列的内容
//参数4：查询结果的每一列的名称
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for (i = 0; i < argc; i ++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
int main(int argc, char **argv)
{
	//定义一个数据库指针
	sqlite3 *db;
	
	//字符串指针
	char *zErrMsg = 0;

	//标志位
	int rc;
	
	//要求三个输入参数：
	//1.可执行文件
	//2.数据库名
	//3.SQL命令语句
	if (argc != 3) {
		fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
		return(1);
	}

	//读入数据库
	rc = sqlite3_open(argv[1], &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return(1);
	}

	//sqlite3_exec参数
	/* db       :An open database         */
	/* argv[2]  :SQL to be evaluated      */
	/* callback :Callback function        */
	/* 0        :1st argument to callback */
	/* &zErrMsg :Error msg written here   */
	rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
	
	if (rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
	
	return 0;
}

