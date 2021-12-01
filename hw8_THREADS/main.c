#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 


pthread_mutex_t the_mutex[5]={PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER,PTHREAD_MUTEX_INITIALIZER};



int rc;
int Shop[5]={900,1000,1100,950,1150};

void *producer(void *ptr) /* производство данных */
  {
	 
 	int i;
	for (i = 1; i <= 100; i++) {
		sleep(1);
        int j=0;		
        while((rc = pthread_mutex_trylock(&the_mutex[j])) != 0){            
            j++;
            if(j==5) j=0;
        }

 		
		//while (buffer != 0) pthread_cond_wait(&condp, &the_mutex);
 		Shop[j]=Shop[j]+200; 
       
		//pthread_cond_signal(&condc); /* активизация потребителя */
        printf("PROD %d %d %d %d %d\n ",Shop[0],Shop[1],Shop[2],Shop[3],Shop[4]);
 		pthread_mutex_unlock(&the_mutex[j]); /* освобождение доступа к буферу */
 	}
 	pthread_exit(0);
 }

 void *consumer(void *ptr) /* потребление данных */
 {	int buffer=0;
	int Max=10000;
 	int i;
	for (i = 1; i <= 100; i++) {
		sleep(3);
		int counter=0;
        int j=0;
        while((rc = pthread_mutex_trylock(&the_mutex[j])) != 0){           
            j++;
			counter++;
            if(j==5) j=0;
			if(counter==5) break;

        }
 		
 		//while (buffer == 0) pthread_cond_wait(&condc, &the_mutex);
		if((buffer+Shop[j])<Max){
 			buffer=buffer+Shop[j]; 
        	Shop[j]=0;
		}
		else 
			pthread_exit(0);
		
       
 		//pthread_cond_signal(&condp); /* активизация производителя */
         printf("CONS (%x) %d %d %d %d %d Buf:%d\n ",pthread_self(),Shop[0],Shop[1],Shop[2],Shop[3],Shop[4],buffer);
 		pthread_mutex_unlock(&the_mutex[j]); /* освобождение доступа к буферу */
 	}
 	pthread_exit(0);
 }

 int main(int argc, char **argv)
 {
	pthread_t pro, con,con1,con2;

 	for(int i=0;i<5;i++)
		pthread_mutex_init(&the_mutex[i], 0);
 

 	pthread_create(&con, 0, consumer, 0);
	pthread_create(&pro, 0, producer, 0); 
    pthread_create(&con1, 0, consumer, 0);
    pthread_create(&con2, 0, consumer, 0);

    pthread_join(con, 0);    
	pthread_join(pro, 0);
 	
	for(int i=0;i<5;i++)
 		pthread_mutex_destroy(&the_mutex[i]);
}