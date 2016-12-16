#include "listio.h"
#include <mysql/mysql.h>

int main(int argc, char * argv[]) {

	if (argv[1] == NULL) {
		printf("Need to Enter Filename as Command Parameter\n");
		exit(0);
	}

	//argv[1] = <FILENAME>
	char * htmlFile;
	char * textFile;
	char line[10000];
	int check;
	struct returnStruct * sReturn;

	char query[MAX_QUERY];
	query[0] = '\0';
	MYSQL mysql;
	MYSQL_RES * res;
	MYSQL_ROW row;
	int test = 0;
	char fifoname[100];
	fifoname[0] = '\0';

	htmlFile = calloc(1, sizeof(char) * strlen(argv[1]) + 5 + 6 + 1);
	if (htmlFile == NULL) {
		printf("There was a memory allocation error\n");
		exit(0);
	}

	strcat(htmlFile, "files/");
	strcat(htmlFile, argv[1]);
	strcat(htmlFile, ".html");

	textFile = calloc(1, sizeof(char) * strlen(argv[1]) + 6 + 1);
	strcpy(textFile, "files/");
	strcat(textFile, argv[1]);

	FILE * html = fopen(htmlFile, "r");
	// if (html != NULL) {
	// 	char ch;
	// 	while ((ch = getc(html)) != EOF)
	// 		printf("%c", ch);
	// }
	if (html == NULL) {
		sReturn = buildHeader();
		if (sReturn->value == FAILURE) {
			printf("There was a memory allocation error\n");
			exit(0);
		}
		check = setName(sReturn->header, argv[1]);
		if (check == FAILURE) {
			printf("There was a memory allocation error\n");
			exit(0);
		}

		FILE * file = fopen(textFile, "r");
		if (file == NULL) {
			printf("There was an error opening a file\n");
			exit(0);
		}
		int i = 0;
		while(fgets(line, 10000, file) != NULL) {
			i++;
			//printf("%d   :%s", i, line);
			check = addString(sReturn->header, line);
			if (check == FAILURE) {
				printf("There was a memory allocation error\n");
				exit(0);
			}
		}
		check = processStrings(sReturn->header);
		if (check == FAILURE) {
			printf("ProcessString() encountered an error, either:\n");
			printf(" - A memory allocation error \n");
			printf(" - An error opening a file\n");
			exit(0);
		}

		free(sReturn->header);
		free(sReturn);
		fclose(file);
	}

	//printf("%s %s\n", htmlFile, textFile);

	if (argc == 3 && strcmp("-db", argv[2]) == 0) {
		mysql_init(&mysql);
		if (!mysql_real_connect(&mysql, HOSTNAME, USERNAME, PASSWORD, DATABASE, 0, NULL, 0)) {
			printf("ERROR: Could not connect to Database\n");
			exit(1);
		}
		query[0] = '\0';
		strcat(query, "create table HTMLTable (html varchar(65000),");
		strcat(query, "bytes decimal(5),");
		strcat(query, "name char(20),");
		strcat(query, "timestamp TIMESTAMP);");
		mysql_query(&mysql, query);

		char name[20];
		sscanf(textFile, "files/%s.txt", name);
		strtok(name, ".");
		
		// name = name to be stored in DB

		FILE * reopen = fopen(htmlFile, "r");
		char * htmlText = NULL;
		long fileLength;
		fseek(reopen, 0, SEEK_END);
		fileLength = ftell(reopen);
		fseek(reopen, 0, SEEK_SET);
		htmlText = calloc(1, sizeof(char) * fileLength + 1);
		fread(htmlText, 1, fileLength, reopen);

		// html test stored in htmlText
		// bytes stored in fileLength

		// FORMAT FOR INSERT
		// INSERT into HTMLTable (html, bytes, name) values ('', '', '');

		char strByte[100];
		sprintf(strByte, "%ld", fileLength);
		query[0] = '\0';
		strcat(query, "INSERT into HTMLTable  (html, bytes, name) values (");
		strcat(query, "'");
		strcat(query, htmlText);
		strcat(query, "','");
		strcat(query, strByte);
		strcat(query, "','");
		strcat(query, name);
		strcat(query, "');");
		test = mysql_query(&mysql, query);
		if (test != 0) {
			printf("An error occurred or the Table does not exist\n");
			exit(1);
		}

		query[0] = '\0';
		strcat(query, "select name, html from HTMLTable order by name ASC");
		test = mysql_query(&mysql, query);
		if (test != 0) {
			printf("An error occurred or the Table does not exist\n");
			exit(1);
		}
		res = mysql_store_result(&mysql);
		while ((row = mysql_fetch_row(res))) {
			// row[0] = name
			// row[1] = html text
			strcat(fifoname, ".");
			strcat(fifoname, row[0]);
			strcat(fifoname, ".html");
			// printf("writing: %s\n", fifoname);
			FILE * fifo = fopen(fifoname,"w");
			fprintf(fifo, "%s\n", row[1]);
			//printf("%s %s", row[0], row[1]); 
			fclose(fifo);
			fifoname[0] = '\0';

		}

		remove(htmlFile);
		mysql_close(&mysql);
		fclose(reopen);
		free(htmlText);
	}
	
	free(htmlFile);
	free(textFile);
	
	printf("\n");
	
	return 0;
}


