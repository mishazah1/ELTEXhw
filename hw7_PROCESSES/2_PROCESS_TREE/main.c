#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
  pid_t pid;
  pid_t pid1;
  pid_t pid2;
  pid_t pid3;
  pid_t pid4;
  int rv;
  
  switch(pid=fork()) {
  case -1:
          perror("fork"); /* произошла ошибка */
          exit(1); /*выход из родительского процесса*/
  case 0:
          //потомок  (1)       
          printf("  1: PID моего родителя -- %d\n",getppid());
          printf("     Мой PID -- %d\n\n", getpid());  
          pid1=fork();
          if(pid1==0){
              // (3)
              printf("      3: PID моего родителя -- %d\n",getppid());
              printf("         Мой PID -- %d\n\n", getpid());
              exit(rv);
          }
          else{
              wait(&rv);
          }       
          exit(rv);
  default:
          //родитель (0)
          printf("0: PID моего родителя -- %d\n",getppid());
          printf("   Мой PID -- %d\n\n", getpid());

          pid2=fork();
          if(pid2==0){
              // (2)
              printf("  2: PID моего родителя -- %d\n",getppid());
              printf("     Мой PID -- %d\n\n", getpid());

              pid3=fork();
              if(pid3==0){
                  // (4)
                  printf("      4: PID моего родителя -- %d\n",getppid());
                  printf("         Мой PID -- %d\n\n", getpid());
                  exit(rv);
              }
              else{
                  pid4=fork();
                  if(pid4==0){
                      // (5)
                      printf("      5: PID моего родителя -- %d\n",getppid());
                      printf("         Мой PID -- %d\n\n", getpid());
                      exit(rv);
                  }
                  else{
                      wait(&rv);
                  }
                  wait(&rv);
              }
              exit(rv);
          }
          else{
              wait(&rv);
          }
          wait(&rv);         
  }
  return 0;
}