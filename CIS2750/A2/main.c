#include "listio.h"

int main(int argc, char * argv[]) {

	if (argv[1] == NULL) {
		printf("Need to Enter Filename as Command Parameter\n");
		exit(0);
	}

	//argv[1] = <FILENAME>
	char * htmlFile;
	char line[10000];
	int check;
	struct returnStruct * sReturn;
	htmlFile = calloc(1, sizeof(char) * strlen(argv[1]) + 5 + 6 + 1);
	if (htmlFile == NULL) {
		printf("There was a memory allocation error\n");
		exit(0);
	}

	strcat(htmlFile, "files/");
	strcat(htmlFile, argv[1]);
	strcat(htmlFile, ".html");

	FILE * html = fopen(htmlFile, "r");
	if (html != NULL) {
		char ch;
		while ((ch = getc(html)) != EOF)
			printf("%c", ch);
	}
	else if (html == NULL) {
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

		FILE * file = fopen(argv[1], "r");
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
	}

	printf("\n");
	free(htmlFile);
	
	
	return 0;
}


