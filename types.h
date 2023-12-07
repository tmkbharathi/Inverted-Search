#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h> 

#define DUPLICATE -1

typedef struct filename{
	char* fname;
	struct filename* link;
}filelist;

typedef struct subnode{
    int count;
	char *fname;
	struct subnode* nextsublink;
}subnode;

typedef struct mainnode{
	char word[20];
	int filecount;
	struct mainnode* nextmainlink;
	struct subnode* sublink;
}mainnode;

typedef enum{
	SUCCESS,
	FAILURE
}Status;

#endif
