//Write a C program in which the child process prints the numbers 1 to 5, while the parent process waits for the child to finish using wait() and then prints a completion message.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
    pid_t p = fork();
    if(p<0){
        printf("Fork failed");
        exit(0);
    }
    else if(p==0){
        for(int i =0 ;i<5;i++){
            printf("Number %d \n",i+1);
        }
    }
    else{
        wait(NULL);
        printf("Process Completed");
    }
}
