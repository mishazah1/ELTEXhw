#ifndef PHONE_H
#define PHONE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pRecord {
	char name[25];
	char number[20];
};


	
void addRecord(const char *nam, const char *num, struct pRecord *array,int n);

void searchRecord(const char *nam, struct pRecord *array,int n);

void removeRecord(const char *nam, struct pRecord *array,int n);

void arrayInit(struct pRecord *array,int n);
	
void arrayPrint(struct pRecord *array,int n);

#endif
