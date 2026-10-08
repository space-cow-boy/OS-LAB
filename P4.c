//Write a C program in which the child process prints the numbers 1 to 5, while the parent process waits for the child to finish using wait() and then prints a completion message.
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
