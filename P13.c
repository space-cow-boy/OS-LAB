//Write a C program that accepts an integer n, uses the child process to print Fibonacci numbers up to n, and uses the parent process to print Armstrong numbers detected by the program from 1 through n.
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<math.h>
void febo(int num){
    int p2=1;
    int p1=1;
    int curr =0;
    printf("Febonacci \n");
    for(int i=0;i<num;i++){
        if(i==0||i==1){
            printf("1\t");
        }
        else{
            curr =p2+p1;
            p2=p1;
            p1=curr;
            printf("%d\t",curr);
        }
    }
}
bool Armstrong(int num){
    int digits = 0;
    int original = num ;
    while(original!=0){
        digits++;
        original = original/10;
    }
    original = num;
    int temp=0;
    int sum=0;
    while(original!=0){
        temp= original%10;
        sum+=pow(temp,digits);
        original = original/10;
    }
    return sum==num;
}
int main(){
    int n;
    scanf("%d",&n);
    pid_t p = fork();
    if(p<0){
        printf("Fork Failed");
        exit(0);
    }
    else if(p==0){
        febo(n);
        printf("\n");
        exit(0);
    }
    else{
        wait(NULL);
         // Parent prints Armstrong numbers from 1 to n
        printf("Armstrong numbers between 1 and %d:\n", n);
        for (int i = 1; i <= n; i++) {
            if (Armstrong(i)) {
                printf("%d\t", i);
            }
        }
        printf("\n");
    }
}