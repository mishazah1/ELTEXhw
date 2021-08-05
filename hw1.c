#include <stdio.h>


void task1(){
  printf("TASK 1\n");
  int n = 0;
  int c = 1;
  printf("Input n:");
  scanf("%d",&n);
  int A[n][n];
  for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++){
  		A[i][j]=c;
  		printf("%d ",A[i][j]);
  		c++;  		
	  }
	  printf("\n");

  }
}

void task2(){
  printf("\nTASK 2\n");
  int n = 0;
  printf("Input n:");
  scanf("%d",&n);
  int A[n];
  printf("\nInput A[n]:"); 
  for(int i=0;i<n;i++){ 	
  	scanf("%d",&A[i]);
  }	
  while(n--){
  	printf("%d ",A[n]);
  	
  }
}

void task3(){
  printf("\n\nTASK 3\n");
  int n = 0;
  printf("Input n:");
  scanf("%d",&n);
  int c = n-1;
  
  int A[n][n];
  for(int i=0;i<n;i++){
  	for(int j=0;j<c;j++){	
  		A[i][j]=0;
  	}
  	for(int j=c;j<n;j++){
  		A[i][j]=1;
	}
	c--;
  }
  
  for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++){
  		printf("%d ",A[i][j]);
  	}
  	printf("\n");
  }
}

void task4(){
  printf("\nTASK 4\n");
  int n = 0;
  printf("Input n:");
  scanf("%d",&n); 
  int A[n][n];
  
  for(int i=0,j=0,k=1;k<=n*n;k++){
  	A[i][j]=k;
  	if(i<=j+1&&i+j<n-1)
            j++;
        else if(i<j&&i+j>=n-1)
            i++;
        else if(i>=j&&i+j>n-1)
            j--;
        else
            i--;
  }
  
  for(int i=0;i<n;i++){
  	for(int j=0;j<n;j++){
  		printf("%3d ",A[i][j]);
  	}
  	printf("\n");
  }
  
}
  

int main()
{
	
  task1();
  task2();
  task3();
  task4();
  
  return 0;
}
