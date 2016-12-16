#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define SUCCESS 1
#define FAILURE 0

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

struct returnStruct {
	int value;
	struct dataHeader *header;
};

//-----FUNCTION DEFINITIONS-----//
struct returnStruct *buildHeader(); //Fixed
int setName(struct dataHeader *header, char *name); //Fixed
char * getName(struct dataHeader *header); //Fixed
int getLength(struct dataHeader *header); //Exception
int addString(struct dataHeader *header, char *str); //Fixed
int printString(struct dataHeader *header);
int processStrings(struct dataHeader *header); //Fixed
int freeStructure(struct dataHeader *header);

int writeStrings(char *filename, struct dataHeader * header);
struct returnStruct *readStrings(char *filename);


