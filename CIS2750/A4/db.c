#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>

#define MAX_QUERY 65000
#define HOSTNAME  "dursley.socs.uoguelph.ca"
#define USERNAME  "jdeangel"
#define PASSWORD  "0873694"
#define DATABASE  "jdeangel"

int main (int argc, char * argv[]) {

	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char query[MAX_QUERY];
	int numRows;
	int test = 0;
	int i;
	char fifoname[100];

	mysql_init(&mysql);
	if (!mysql_real_connect(&mysql, HOSTNAME, USERNAME, PASSWORD, DATABASE, 0, NULL, 0)) {
		printf("ERROR: Could not connect to Database\n");
	}
	query[0] = '\0';

	if (argc == 2 && strcmp(argv[1], "-clear") == 0) {
		// Remove all rows from table (truncate)

		strcat(query, "select name, html from HTMLTable;");
		test = mysql_query(&mysql, query);
		if (test != 0) {
			printf("An error occurred or the Table does not exist\n");
			exit(1);
		}
		res = mysql_store_result(&mysql);

		while ((row = mysql_fetch_row(res))) {
			strcat(fifoname, ".");
			strcat(fifoname, row[0]);
			strcat(fifoname, ".html");
			remove(fifoname);
			fifoname[0] = '\0';
		}

		query[0] = '\0';

		strcat(query, "truncate HTMLTable;");
		test = mysql_query(&mysql, query);
		if (test != 0) {
			printf("An error occurred or the Table does not exist\n");
			exit(1);
		}
	}

	else if (argc == 2 && strcmp(argv[1], "-reset") == 0) {
		// Drop table

		strcat(query, "select name, html from HTMLTable;");
		test = mysql_query(&mysql, query);
		if (test != 0) {
			printf("An error occurred or the Table does not exist\n");
			exit(1);
		}
		res = mysql_store_result(&mysql);

		while ((row = mysql_fetch_row(res))) {
			strcat(fifoname, ".");
			strcat(fifoname, row[0]);
			strcat(fifoname, ".html");
			remove(fifoname);
			fifoname[0] = '\0';
		}

		query[0] = '\0';
		
		strcat(query, "drop table HTMLTable;");
		test = mysql_query(&mysql, query);
		if (test != 0) {
			printf("An error occurred or the Table does not exist\n");
			exit(1);
		}
	}

	else if (argc == 2 && strcmp(argv[1], "-show") == 0) {
		// Print name length and date of each row
		

		test = mysql_query(&mysql, "select name,bytes,timestamp from HTMLTable;");
		if (test != 0) {
			printf("An error occurred or the Table does not exist\n");
			exit(1);
		}
		res = mysql_store_result(&mysql);
		numRows = mysql_num_rows(res);
		MYSQL_ROW row;
		printf("NAME, LENGTH, TIMESTAMP\n");
		printf("-----------------------\n");

  		while ((row = mysql_fetch_row(res)) != NULL) {
        	printf("%s, %s, %s\n", row[0], row[1], row[2]); 
      	}
	}

	else if (argc == 2 && strcmp(argv[1], "-help") == 0) {
		// Usage information
		printf("usage: ./db -FLAG\n");
		printf("./db -clear		Will remove all rows from the table\n");
		printf("./db -reset		Will delete the table from the database\n");
		printf("./db -show		Will print name, length, and date of each\n");
		printf("			row in the database\n");				
	}
	else {
		printf("Run './db -help' for usage information\n");
	}

	mysql_close(&mysql);
	printf("\n");

	return 0;
}