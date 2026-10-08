//Write a C program that accepts the number of Fibonacci terms and a number for factorial calculation, then uses fork() so that the child prints the Fibonacci series and the parent calculates and prints the factorial.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int  fact(int num){
    int factorial = 1;
    for(int i = num ;i>0;i--){
        factorial *=i; 
    }
    return factorial;
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
    int numFeb ;
    int numFac ;
    scanf("%d",&numFeb);
    scanf("%d",&numFac);
    pid_t p = fork();

    if(p<0){
        printf("Fork Failed");
        exit(0);
    }
    else if(p==0){
        febonacci(numFeb);
    }
    else{
        printf(
            "Factorial of %d = %d ",
            numFac,fact(numFac)
        );
    }
}