#include "phones.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(){
	
	char nam[25]={""};
	char num[20]={""};
	
	int key=-1;
	int n=10;
	struct pRecord Phones[n];
	
	arrayInit(Phones,n);

	printf("1. Add record\n2. Remove record\n3. Search record\n4. View all\n0. Exit\n\n");
	
	while(key!=0){
		
		scanf("%d",&key);
		//printf("111\n");
		switch(key){
			
			case 1:
				printf("Input name:\n");
				scanf("%30s", nam);
				printf("Input phone number:\n");
				scanf("%15s", num);
				
				addRecord(nam,num,Phones,n);
				printf("\n1. Add record\n2. Remove record\n3. Search record\n4. View all\n0. Exit\n\n");
				break;
			
			case 2:
				printf("Input name:\n");
				scanf("%30s", nam);
				
				removeRecord(nam,Phones,n);
				printf("\n1. Add record\n2. Remove record\n3. Search record\n4. View all\n0. Exit\n\n");
				break;
			
			case 3:
				printf("Input name:\n");
				scanf("%30s", nam);
				
				searchRecord(nam,Phones,n);
				printf("\n1. Add record\n2. Remove record\n3. Search record\n4. View all\n0. Exit\n\n");
				break;	
			case 4:
				arrayPrint(Phones,n);
				printf("\n1. Add record\n2. Remove record\n3. Search record\n4. View all\n0. Exit\n\n");
				break;
		}	
	
	}
	
	return 0;					
}
