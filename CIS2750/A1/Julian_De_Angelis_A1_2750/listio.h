#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//-----STRUCTS-----//
struct dataString {
    char *string;
    struct dataString *next;
};

struct dataHeader {
	char *name;
    int length;
    struct dataString *next;
};

//-----FUNCTION DEFINITIONS-----//
struct dataHeader *buildHeader();
void setName(struct dataHeader *header, char *name);
char * getName(struct dataHeader *header);
int getLength(struct dataHeader *header);
void addString(struct dataHeader *header, char *str);
void printString(struct dataHeader *header);
void processStrings(struct dataHeader *header);
void freeStructure(struct dataHeader *header);

void writeStrings(char *filename, struct dataHeader * header);
struct dataHeader *readStrings(char *filename);


