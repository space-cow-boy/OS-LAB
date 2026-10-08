//Write a C program that accepts an integer and uses fork() so that the child checks whether the number is prime, while the parent calculates and displays its factorial after waiting for the child.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdbool.h>
int  fact(int num){
    int factorial = 1;
    for(int i = num ;i>0;i--){
        factorial *=i; 
    }
    return factorial;
}

bool prime(int num){
    int count =2;
    for(int i=2;i<num/2;i++){
        if(num%i==0)count++;
    }
    if(count>2)return 0;
    return 1;
}
int main(){
    int num ;
    scanf("%d",&num);
    pid_t p = fork();

    if(p<0){
        printf("Fork Failed");
        exit(0);
    }
    else if(p==0){
        if(prime(num)){
            printf("Number %d is prime\n",num);
        }
        else{
            printf("Number %d is not prime\n",num);
        }
        exit(0);
    }
    else{
        wait(NULL);
        printf(
            "Factorial of %d = %d \n",
            num,fact(num)
        );
    }
}