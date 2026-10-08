//Write a C program to create a child process using fork() and print "Hello World" from both the parent and child processes.

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
        printf("Hello World from Child\n");
    }
    else {
        printf("Hello World from Parent\n");
    }
}