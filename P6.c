//Write a C program that accepts an integer n, uses child processes to print the first n Fibonacci terms and calculate n!, while the original parent calculates the sum of the first n natural numbers. Use wait() to synchronize the processes.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int  fact(int num){
    int factorial = 1;
    for(int i = num ;i>0;i--){
        factorial *=i; 
    }
    return factorial;
}
int SumOfNaturalNumbers(int num){
    int sum=0;
    for(int i=1;i<=num;i++){
        sum+=i;
    }
    return sum;
}
void febonacci(int num){
    int last = 1;
    int last2 = 0;
    printf("\nFebonacci of %d \n",num);
    for(int i = 0 ;i<num;i++){
        if(i==0 || i==1){
            printf("1 \t");
        }
        else{
        int sum = last+last2;
        last2=last;
        last = sum;
        printf("%d \t",sum);
        }
    }
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
        febonacci(num);
        printf("\n");
        printf(
            "Factorial of %d = %d ",
            num,fact(num)
        );
    }
    else{
        wait(NULL);
        printf(
            "\nSum of first %d natural numbers = %d ",
            num,SumOfNaturalNumbers(num)
        );
    }
}