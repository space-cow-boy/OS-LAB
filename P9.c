//Write a C program in which the child process terminates with exit status 10, and the parent uses wait(), WIFEXITED(), and WEXITSTATUS() to read and display the child's exit status.
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    pid_t p = fork();
    int status = 0;
    if(p<0){
        printf("Fork Failed ");
        exit(0);
    }
    else if(p==0){
        printf("Hello World from Child\n");
        exit(20);
    }
    else {
        wait(&status);
        if(WIFEXITED(status)){
            printf("Process Exited with status %d ",WEXITSTATUS(status));
        }
        else {
            printf("Child did not exit normally\n");
        }
       
    }
}
//wait(&status) → stores the child’s termination info in status.

//WIFEXITED(status) → checks if the child terminated normally (via exit() or return).

//WEXITSTATUS(status) → extracts the actual exit code (10 here).