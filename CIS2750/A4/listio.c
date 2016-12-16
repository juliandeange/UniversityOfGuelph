//Julian De Angelis 0873694
//CIS 2750 - A4

// SUCCESS 1
// FAILURE 0

#include "listio.h"

/*----------FUNCTIONS----------*/

struct returnStruct *buildHeader() {

	//Creates and initializes a new Header struct
	struct returnStruct * sReturn = malloc(sizeof(struct returnStruct));
	if (sReturn == NULL) {
		sReturn->value = FAILURE;
		return sReturn;
	}
	sReturn->header = malloc(sizeof(struct dataHeader));
	if (sReturn->header == NULL)  {
		sReturn->value = FAILURE;
		return sReturn;
	}
	sReturn->header->name = NULL;
	sReturn->header->length = 0;
	sReturn->header->next = NULL;
	sReturn->value = SUCCESS;
	return sReturn;

}

//Will give name to the header ... header->name
int setName(struct dataHeader *header, char *name) {

	int length = strlen(name);
	header->name = malloc(sizeof(char) * length + 1);
	if (header->name == NULL)
		return FAILURE;

	strcpy(header->name, name);
	return SUCCESS;

}

//Returns the name of a header
char * getName(struct dataHeader *header) {

	if (strcmp(header->name, NULL) == 0 || strcmp(header->name, " ") == 0 || strcmp(header->name, "") == 0 || header == NULL)
		return NULL;
	return header->name;

}

//Return the length of the header name
int getLength(struct dataHeader *header) {

	if (header == NULL)
		return FAILURE;

	return header->length;

}

//Create a new dataString struct and adds the struct to
// the end of the linked list
int addString(struct dataHeader *header, char *str) {

	struct dataString * newString;
	struct dataString * node;

	newString = malloc(sizeof(struct dataString));
	if (newString == NULL)
		return FAILURE;
	newString->string = malloc(sizeof(char) * strlen(str) + 1);
	if (newString == NULL)
		return FAILURE;
	strcpy(newString->string, str);
	newString->next = NULL;

	header->length = header->length + strlen(str) + 1;

	if (header->next == NULL) {
		header->next = newString;
	}

	else {
		node = header->next;
		while (node->next != NULL)
			node = node->next;
		node->next = newString;
	}
	return SUCCESS;
}

//Traverses the dataHeader linked list and
// prints all the strings inside of dataString
// structs
int printString(struct dataHeader *header) {

	if (header == NULL)
		return FAILURE;

	struct dataString * node;
	node = header->next;

	printf("%s\n", header->name);

	while (node != NULL) {
		printf("%s\n", node->string);
		node = node->next;
	}
	return SUCCESS;
}

//Formats strings in the ways specified in the assignment
//Duplicate spaces become 1 space
//Dublicate tabs become 1 tab
//Single Carriage Return and/or Newline becomes <BR>
//Multiple consecutive Carriage Return and/or Newlines become <P>
//---------------
//Before processing a string all Carriage Return '\r' and Newlines '\n'
// are converted to a tilde '~' character and then correctly formatted
//Single '~' becomes <BR> as per spec
//Multiple consecutive '~' becomes <P> as per spec
int processStrings(struct dataHeader *header) {
	if (header == NULL)
		return FAILURE;

	struct dataString * node;
	struct dataString * pNode;
	struct dataString * nextNode;
	struct dataString * oldNode;
	int s;
	int len;
	char * tempString;

	/////
	int f = 0;
	/////

	node = header->next;
	// placeholder to beginning for later use
	pNode = node;

	len = strlen(node->string);
	while (node != NULL) {
		len = strlen(node->string);
		for (s = 0; s < len; s++)
		if (node->string[s] == '\n' || node->string[s] == '\r') {
			node->string[s] = '~';
		}
		node = node->next;
	}

	node = pNode;
	while (node != NULL) {
		len = strlen(node->string);
		if (node->string[len - 1] == '~' && node->next != NULL && strlen(node->next->string) == 1 && node->next->string[0] == '~') {
			if (node->next->next == NULL) {
				node->next = NULL;
			}
			else {
				node->next = node->next->next;
			}
			tempString = calloc(1, sizeof(char) * strlen(node->string) + 1 + 2);
			strcpy(tempString, node->string);
			free(node->string);
			len = strlen(tempString);
			tempString[len - 1] = '<';
			tempString[len] = 'P';
			tempString[len + 1] = '>';
			node->string = calloc(1, sizeof(char) * strlen(tempString) + 1);
			strcpy(node->string, tempString);
			free(tempString);
		}
		node = node->next;
	}

	node = pNode;
	while (node != NULL) {
		f++;

		int i = 0;
		int j;
		int newLen;
		int marker = 0;
		int tildes = 0;

		int oldLength;
		int newLength;

		char * newString;
		int m;
		int x;

		len = strlen(node->string);

		//Converts '\r' and '\n' to a tilde '~'

		//end of current node == ~ and beginning of next node == ~
		//add <P> to current node and remove ~ from next node
		//if next node without ~ is NULL then node->next = node->next->next
/*		if (node->string[len - 1] == '~' && node->next->string[0] == '~') {
			tempString = calloc(1, sizeof(char) * strlen(node->string) + 1);
			if (tempString == NULL)
				return FAILURE;
			strncpy(tempString, node->string, strlen(node->string)-1);
			free(node->string);
			node->string = calloc(1, sizeof(char) * strlen(tempString) + 1);
			if (node->string == NULL)
				return FAILURE;
			strcpy(node->string, tempString);
			free(tempString);

			tempString = calloc(1, sizeof(char) * strlen(node->next->string) + 1 + 2);
			if (tempString == NULL)
				return FAILURE;
			strcpy(tempString, node->next->string);
			for (x = strlen(tempString) + 2; x >= 3; x--)
				tempString[x] = tempString[x-1];
			tempString[0] = '<';
			tempString[1] = 'P';
			tempString[2] = '>';
			node->next->string = calloc(1, sizeof(char) * strlen(tempString) + 1);
			if (node->next->string == NULL)
				return FAILURE;
			strcpy(node->next->string, tempString);
			free(tempString);
		}*/
		for (i = 0; i < len; i++) {
			//Will reduce consecuative spaces to a single space
			if (node->string[i] == ' ' && node->string[i+1] == ' ') {
				oldLength = strlen(node->string) + 1;
				for (j = i; j < len; j++) {
					node->string[j] = node->string[j+1];
				}
				len = strlen(node->string);
				newLength = strlen(node->string) + 1;

				//Adjusts length value stored in header struct
				header->length = header->length - oldLength;
				header->length = header->length + newLength;

				i = 0;
			}

			//Will reduce consecuative tabs to a single tab
			else if (node->string[i] == '\t' && node->string[i+1] == '\t') {
				len = strlen(node->string);
				oldLength = strlen(node->string) + 1;
				for (j = i; j < len - 1; j++) {
					node->string[j+1] = node->string[j+2];
				}
				newLength = strlen(node->string) + 1;
				node->string = realloc(node->string, sizeof(char) * newLength);
				if (node->string == NULL)
					return FAILURE;

				header->length = header->length - oldLength;
				header->length = header->length + newLength;
				len = strlen(node->string);

				i = 0;
			}

			//Statement will check to see how man consecutive '\r' or '\n' now
			//being '~' characters in a row. Formats accordingly to a <BR> or <P>
			else if (node->string[i] == '~' && node->string[i+1] == '~') {
				int consec = 0;
				int y = i;
				int firstTilde = y;
				while (node->string[y] == '~') {
					y++;
					consec++;
				}

				if (consec == 2) {

					oldLength = strlen(node->string) + 1;					

					tempString = calloc(1, sizeof(char) * strlen(node->string) + 1 + 2);
					if (tempString == NULL)
						return FAILURE;
					strcpy(tempString, node->string);
					free(node->string);
					for (x = strlen(tempString) + 2; x >= firstTilde + 1; x--)
						tempString[x] = tempString[x-1];
					tempString[firstTilde] = '<';
					tempString[firstTilde+1] = 'P';
					tempString[firstTilde+2] = '>';
					node->string = calloc(1, sizeof(char) * strlen(tempString) + 1);
					if (node->string == NULL)
						return FAILURE;
					strcpy(node->string, tempString);
					free(tempString);

					newLength = strlen(node->string) + 1;
					header->length = header->length - oldLength;
					header->length = header->length + newLength;
				}

				//Multiple \r or \n are replced with a <P>
				//String sizes are correctly adjusted
				else if (consec == 3) {

					oldLength = strlen(node->string) + 1;

					tempString = calloc(1, sizeof(char) * strlen(node->string) + 1 + 2);
					if (tempString == NULL)
						return FAILURE;
					strcpy(tempString, node->string);
					free(node->string);
					tempString[firstTilde] = '<';
					tempString[firstTilde+1] = 'P';
					tempString[firstTilde+2] = '>';
					node->string = calloc(1, sizeof(char) * strlen(tempString) + 1);
					if (node->string == NULL)
						return FAILURE;
					strcpy(node->string, tempString);
					free(tempString);

					newLength = strlen(node->string) + 1;
					header->length = header->length - oldLength;
					header->length = header->length + newLength;

				}

				else if (consec > 3) {

					oldLength = strlen(node->string) + 1;

					node->string[firstTilde] = '<';
					node->string[firstTilde+1] = 'P';
					node->string[firstTilde+2] = '>';
					int moveOver = consec - 3;
					
					for (x = firstTilde + 3; x < strlen(node->string) - 2; x++)
						node->string[x] = node->string[x + moveOver];

					tempString = calloc(1, sizeof(char) * strlen(node->string) + 1 - moveOver);
					if (tempString == NULL)
						return FAILURE;
					strncpy(tempString, node->string, strlen(node->string) - moveOver);

					free(node->string);
					node->string = calloc(1, sizeof(char) * strlen(tempString) + 1);
					if (node->string == NULL)
						return FAILURE;
					strcpy(node->string, tempString);
					free(tempString);
					
					newLength = strlen(node->string) + 1;
					header->length = header->length - oldLength;
					header->length = header->length + newLength;

				}
				
			}

			//Adjusts a single \r or \n to be <BR>
			//String sizes are correctly adjusted
			if (node->string[i] == '~' && node->string[i+1] != '~') {
				oldLength = strlen(node->string) + 1;

				//malloc '\0' and 'B' 'R' '>'
				tempString = malloc(sizeof(char) * strlen(node->string) + 1);
				if (tempString == NULL)
					return FAILURE;
				strcpy(tempString, node->string);
				free(node->string);
				node->string = calloc(1, sizeof(char) * strlen(tempString) + 1 + 3);
				if (node->string == NULL)
					return FAILURE;
				strcpy(node->string, tempString);
				free(tempString);

				marker = i;
				len = strlen(node->string);

				for (x = len + 2; x >= marker + 3; x--) {
					node->string[x] = node->string[x-3];
				}

				node->string[marker] = '<';
				node->string[marker+1] = 'B';
				node->string[marker+2] = 'R';
				node->string[marker+3] = '>';

				len = strlen(node->string) + 1;

				newLength = strlen(node->string) + 1;
				header->length = header->length - oldLength;
				header->length = header->length + newLength;
				//break;
			}
	 	}
	 	//printf("%d   :%s\n", f, node->string);
	 	node = node->next;

	}//end while

	//printString(header);

	//Eliminated multiple <P> and <BR> tags

	

	node = pNode;
	while(node != NULL) {
		if (node->next == NULL)
			break;
		int currLen = strlen(node->string);
		if (node->string[currLen-3] == '<' && node->string[currLen-2] == 'P' && node->string[currLen-1] == '>')
			if (node->next->string[0]=='<' && node->next->string[1]=='B' && node->next->string[2]=='R' && node->next->string[3]=='>') {
				int nextLen = strlen(node->next->string);
				if (nextLen == 4) {
					oldNode = node->next;
					node->next = node->next->next;
					free(oldNode->string);
					free(oldNode);
				}
			}
			node = node->next;
	}

	//Write string in structure to a fifo which
	// will be read and manipualted by python script

	pid_t pid = fork();
	if (pid > 0) {
		char * args[3];
		args[0] = "python3";
		args[1] = "a4.py";
		args[2] = 0;
		execvp(args[0], args);
	}
	sleep(1);

	node = pNode;
	FILE * fifo = fopen("./toPython", "w");
	fprintf(fifo, "%s\n", header->name);
	while (node != NULL) {
		fprintf(fifo, "%s\n", node->string);
		node = node->next;
	}
	fclose(fifo);


	char temp[10000];
	int y;
 	mkfifo("./toC", 0777);
 	char * fileName;
	fileName = calloc(1, sizeof(char) * strlen(header->name) + 5 + 6 + 1);
	if (fileName == NULL)
		return FAILURE;
	// strcpy(fileName, header->name);
	// strcat(fileName, ".html");
	strcpy(fileName, "files/");
	strcat(fileName, header->name);
	strcat(fileName, ".html");

   	FILE * html = fopen(fileName, "w");

   	//Reads string from a fifo queue and prints them
   	// to a .html file
	fifo = fopen("./toC", "r");
   	while (!feof(fifo)) {
	   	fgets(temp, 10000, fifo);
	   	fprintf(html, "%s\n", temp);
   	}
	fclose(fifo);
	fclose(html);
   	remove("./toC");
	
	return SUCCESS;
}

//Frees all string and structs from a linked
// list / header provided
int freeStructure(struct dataHeader *header) {

	if (header == NULL)
		return FAILURE;

	struct dataString * node;
	struct dataString * temp;
	node = header->next;

	while (node != NULL) {
		temp = node;
		node = node->next;
		free(temp->string);
		free(temp);
	}
	free(header->name);
	free(header);
	return SUCCESS;

}

//Traverses the linked list (header) passed in and writes the
// contents to a binary file
//-----
//Will print the Header length, header name, length of all strings
// in dataStrings, length of next dataString, dataString->string.
// Last 2 steps are repeated for amount of string in linked list (header)
int writeStrings(char *filename, struct dataHeader * header) {

	if (header == NULL)
		return FAILURE;

	FILE * fp;
	struct dataString * node;
	int headerLength;
	int stringLength;
	
	if (header == NULL)
		return FAILURE;

	node = header->next;
	headerLength = strlen(header->name) + 1;

    fp = fopen(filename, "w");
    if (fp == NULL)
    	return FAILURE;
    fwrite(&headerLength, sizeof(int), 1, fp);
    fwrite(header->name, sizeof(char), strlen(header->name) + 1, fp);
	fwrite(&header->length, sizeof(int), 1, fp);

	while (node != NULL) {
		stringLength = strlen(node->string) + 1;
		fwrite(&stringLength, sizeof(int), 1, fp);
		fwrite(node->string, sizeof(char), strlen(node->string) + 1, fp);
		node = node->next;
	}

	fclose(fp);
	return SUCCESS;

}

//Opens a binary file and reads in the contents
//This function will create a header with buildHeader()
//Will read in header length, header name
//Read in string length, and string
struct returnStruct *readStrings(char *filename) {

	FILE * fp;
	// struct dataHeader * newHeader;
	struct returnStruct * sReturn;
	int headerLength;
	int totalCharacters;
	char * headerName;
	int stringLength;
	int totalStringLength = 0;
	char * string;

	fp = fopen(filename, "r");
	if (fp == NULL) {
		sReturn->value = FAILURE;
		return sReturn;
	}

	fread(&headerLength, sizeof(int), 1, fp);

	//Creates new header
	sReturn = buildHeader();
	sReturn->header->length = headerLength;
	headerName = malloc(sizeof(char) * headerLength);
	if (headerName == NULL) {
		sReturn->value = FAILURE;
		return sReturn;
	}
	fread(headerName, sizeof(char), headerLength, fp);

	setName(sReturn->header, headerName);
	fread(&totalCharacters, sizeof(int), 1, fp);

	free(headerName);
	int i = 0;

	//Reads in binary files string lengths and strings
	// into the linked list
	while (!feof(fp)) {
		fread(&stringLength, sizeof(int), 1, fp);
		totalStringLength = totalStringLength + stringLength;
		string = calloc(1, sizeof(char) * stringLength);
		if (string == NULL) {
			sReturn->value = FAILURE;
			return sReturn;
		}

		fread(string, sizeof(char), stringLength, fp);
		addString(sReturn->header, string);

		//printf("total:%d add:%d\n", totalStringLength, stringLength);
		free(string);
		if (totalCharacters == totalStringLength)
			break;
	}
	sReturn->header->length = totalStringLength;

	fclose(fp);
	sReturn->value = SUCCESS;
	return sReturn;

}


