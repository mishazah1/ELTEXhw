#include "phones.h"


void addRecord(const char *nam, const char *num, struct pRecord *array,int n) {
	int i = 0;

	while (strcmp("0", array[i].name) != 0 && i<n) {
		i++;
	}

	strcpy(array[i].name, nam);
	strcpy(array[i].number, num);
	
}

void searchRecord(const char *nam, struct pRecord *array,int n) {
	int found=0;
	for(int i=0;i<n;i++){
		if(strcmp(nam, array[i].name) == 0){
			printf("%-3d %-21s %-15s\n", i+1, array[i].name, array[i].number);
			found=1;
		}
	}
	if(found==0) printf("\nNOT FOUND\n");	
}

void removeRecord(const char *nam, struct pRecord *array,int n) {
	
	for(int i=0;i<n;i++){
		if(strcmp(nam, array[i].name) == 0){
			strcpy(array[i].name, "0");
			strcpy(array[i].number, "0");
		}
	}
}
	

void arrayInit(struct pRecord *array,int n){
	for(int i=0;i<n;i++){
		strcpy(array[i].name,"0");
		strcpy(array[i].number,"0");
	}
}

void arrayPrint(struct pRecord *array,int n){
	
	for(int i=0;i<n;i++){
		if(strcmp("0", array[i].name) != 0)
		printf("%-3d %-21s %-15s\n", i+1, array[i].name, array[i].number);		
	}
}
