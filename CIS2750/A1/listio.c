//Julian De Angelis 0873694
//CIS 2750 - A1

#include "listio.h"

/*----------FUNCTIONS----------*/

struct dataHeader *buildHeader() {

	//Creates and initializes a new Header struct
	struct dataHeader * newHeader = malloc(sizeof(struct dataHeader));
	newHeader->name = NULL;
	newHeader->length = 0;
	newHeader->next = NULL;

	return newHeader;

}

//Will give name to the header ... header->name
void setName(struct dataHeader *header, char *name) {

	int length = strlen(name);
	header->name = malloc(sizeof(char) * length + 1);
	strcpy(header->name, name);

}

//Returns the name of a header
char * getName(struct dataHeader *header) {

	return header->name;

}

//Return the length of the header name
int getLength(struct dataHeader *header) {

	return header->length;

}

//Create a new dataString struct and adds the struct to
// the end of the linked list
void addString(struct dataHeader *header, char *str) {

	struct dataString * newString;
	struct dataString * node;

	newString = malloc(sizeof(struct dataString));
	newString->string = malloc(sizeof(char) * strlen(str) + 1);
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
}

//Traverses the dataHeader linked list and
// prints all the strings inside of dataString
// structs
void printString(struct dataHeader *header) {

	struct dataString * node;
	node = header->next;

	printf("%s\n", header->name);

	if (header->next == NULL)
		return;

	while (node != NULL) {
		printf("%s\n", node->string);
		node = node->next;
	}

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
void processStrings(struct dataHeader *header) {

	struct dataString * node;
	node = header->next;

	while (node != NULL) {

		int len = strlen(node->string);
		int i;
		int j;
		int newLen;
		int marker = 0;
		int tildes = 0;

		int oldLength;
		int newLength;

		char * tempString;
		char * newString;
		int m;
		int x;

		for (i = 0; i < len; i++) {
			//Converts '\r' and '\n' to a tilde '~'
			for (m = 0; m < strlen(node->string); m++)
				if (node->string[m] == '\n' || node->string[m] == '\r')
					node->string[m] = '~';

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
				oldLength = strlen(node->string) + 1;
				for (j = i; j < len; j++) {
					node->string[j+1] = node->string[j+2];
				}
				len = strlen(node->string);
				newLength = strlen(node->string) + 1;

				header->length = header->length - oldLength;
				header->length = header->length + newLength;

				i = 0;
			}

			//Statement will check to see how man consecutive '\r' or '\n' now
			// being '~' characters in a row. Formats accordingly to a <BR> or <P>
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

					tempString = malloc(sizeof(char) * strlen(node->string) + 1 + 1);
					strcpy(tempString, node->string);
					free(node->string);
					for (x = strlen(tempString) + 2; x >= firstTilde; x--)
						tempString[x] = tempString[x-1];
					tempString[firstTilde] = '<';
					tempString[firstTilde+1] = 'P';
					tempString[firstTilde+2] = '>';
					node->string = malloc(sizeof(char) * strlen(tempString) + 1);
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

					tempString = malloc(sizeof(char) * strlen(node->string) + 1 + 2);
					strcpy(tempString, node->string);
					free(node->string);
					tempString[firstTilde] = '<';
					tempString[firstTilde+1] = 'P';
					tempString[firstTilde+2] = '>';
					node->string = malloc(sizeof(char) * strlen(tempString) + 1);
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

					tempString = malloc(sizeof(char) * strlen(node->string) + 1 - moveOver);
					strncpy(tempString, node->string, strlen(node->string) - moveOver);

					free(node->string);
					node->string = malloc(sizeof(char) * strlen(tempString) + 1);
					strcpy(node->string, tempString);
					free(tempString);
					
					newLength = strlen(node->string) + 1;
					header->length = header->length - oldLength;
					header->length = header->length + newLength;

				}
				
			}

			//Adjusts a single \r or \n to be <BR>
			//String sizes are correctly adjusted
			else if (node->string[i] == '~' && node->string[i+1] != '~') {

				oldLength = strlen(node->string) + 1;

				tempString = malloc(sizeof(char) * strlen(node->string) + 1 + 3);
				marker = i;
				strcpy(tempString, node->string);
				free(node->string);
				len = strlen(tempString);

				for (x = len + 2; x >= marker; x--) {
					tempString[x] = tempString[x-3];
				}

				tempString[marker] = '<';
				tempString[marker+1] = 'B';
				tempString[marker+2] = 'R';
				tempString[marker+3] = '>';

				node->string = malloc(sizeof(char) * strlen(tempString) + 1);
				strcpy(node->string, tempString);
				free(tempString);
				len = strlen(node->string) + 1;

				newLength = strlen(node->string) + 1;
				header->length = header->length - oldLength;
				header->length = header->length + newLength;
			}
		}

		//Modifies the string length to fit back in the linked list
		newLen = strlen(node->string);
		newString = malloc(sizeof(char) * newLen + 1);
		strcpy(newString, node->string);
		free(node->string);
		node->string = newString;
		node = node->next;

	}

}

//Frees all string and structs from a linked
// list / header provided
void freeStructure(struct dataHeader *header) {

	struct dataString * node;
	node = header->next;

	if (header->next == NULL) {
		free(header->name);
		free(header); 
	}

	else {
		while (node != NULL) {
			free(node->string);
			free(node);
			node = node->next;
		}
		free(header->name);
		free(header);
	}

}

//Traverses the linked list (header) passed in and writes the
// contents to a binary file
//-----
//Will print the Header length, header name, length of all strings
// in dataStrings, length of next dataString, dataString->string.
// Last 2 steps are repeated for amount of string in linked list (header)
void writeStrings(char *filename, struct dataHeader * header) {

	FILE * fp;
	struct dataString * node;
	int headerLength;
	int stringLength;

	node = header->next;
	headerLength = strlen(header->name) + 1;

    fp = fopen(filename, "w");
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

}

//Opens a binary file and reads in the contents
//This function will create a header with buildHeader()
//Will read in header length, header name
//Read in string length, and string
struct dataHeader *readStrings(char *filename) {

	FILE * fp;
	struct dataHeader * newHeader;
	struct dataString * node;
	int headerLength;
	int totalCharacters;
	char * headerName;
	int stringLength;
	int totalStringLength = 0;
	char * string;

	fp = fopen(filename, "r");

	fread(&headerLength, sizeof(int), 1, fp);

	//Creates new header
	newHeader = buildHeader();
	newHeader->length = headerLength;
	headerName = malloc(sizeof(char) * headerLength);
	fread(headerName, sizeof(char), headerLength, fp);

	setName(newHeader, headerName);
	fread(&totalCharacters, sizeof(int), 1, fp);

	free(headerName);
	int i = 0;

	//Reads in binary files string lengths and strings
	// into the linked list
	while (!feof(fp)) {
		fread(&stringLength, sizeof(int), 1, fp);
		totalStringLength = totalStringLength + stringLength;
		string = malloc(sizeof(char) * stringLength);
		fread(string, sizeof(char), stringLength, fp);
		addString(newHeader, string);
		free(string);
		if (totalCharacters == totalStringLength)
			break;
	}

	newHeader->length = totalStringLength;

	fclose(fp);
	return newHeader;

}


