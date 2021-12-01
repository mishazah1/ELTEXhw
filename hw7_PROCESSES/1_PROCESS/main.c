#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
  pid_t pid;
  int rv;
  
  switch(pid=fork()) {
  case -1:
          perror("fork"); /* произошла ошибка */
          exit(1); /*выход из родительского процесса*/
  case 0:
          //потомок         
          printf(" CHILD: PID моего родителя -- %d\n",getppid());
          printf(" CHILD: Мой PID -- %d\n", getpid());         
          exit(rv);
  default:
          //родитель
          printf("PARENT: PID моего родителя -- %d\n",getppid());
          printf("PARENT: Мой PID -- %d\n", getpid());
          wait(&rv);         
  }
  return 0;
}