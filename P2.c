//Write a C program using fork() in which both the parent and child processes display their Process ID (PID) and Parent Process ID (PPID) using getpid() and getppid().

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    pid_t p = fork();
    if(p<0){
        printf("Fork Failed ");
        exit(0);
    }
    else if(p==0){
        printf(" Child Process\n");
        printf("PID Child = %d",getpid());
        printf("PPID Child = %d",getppid());
    }
    else {
        printf(" Parent Process\n");
        printf("PID Parent = %d",getpid());
        printf("PPID Parent = %d",getppid());
    }
}