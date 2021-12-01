#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define _GNU_SOURCE

int main(int argc,char *argv[]) {

    if(strcmp(argv[1],"ls")==0){
        char* args[] = {"ls",NULL};
        execv("/bin/ls", args);
    }
    else 
        if(strcmp(argv[1],"ps")==0){
            char* args[] = {"ps",NULL};
            execv("/bin/ps", args);
        }
    return 0;
}
