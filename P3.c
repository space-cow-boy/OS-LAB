//Write a C program to create a child process using fork() and display separate messages identifying the parent process and child process.
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(){
    pid_t p = fork();
    if(p==0){
        printf("Child Process\n");
    }
    else if(p>0){
        printf("Parent Process\n");
    }
    else{
        printf("Fork Failed\n");
        exit(0);
    }
}