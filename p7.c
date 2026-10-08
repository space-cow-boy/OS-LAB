//Write a C program using fork() in which the parent prints even numbers from 2 to 20 and the child prints odd numbers from 1 to 19.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t p = fork();
    if(p<0){
        printf("Fork Failed");
        exit(1);
    }
    else if(p==0){
        printf("\nOdd numbers from 1 - 19 \n");
        for(int i=1;i<=19;i++){
            if(i%2!=0){
                printf("%d ",i);
            }
        }
    }
    else{
        wait(NULL);
        printf("\nEven number from 2 to 20\n");
        for(int i = 2 ;i<=20 ;i++){
            if(i%2==0){
                printf("%d ",i);
            }
        }
    }
}