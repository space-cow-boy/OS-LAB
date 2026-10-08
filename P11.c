//Write a C program to demonstrate a zombie process by allowing the child to terminate while the parent remains alive and does not immediately call wait().


// zombie_process_demo.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    pid_t p = fork();

    if (p < 0) {
        printf("Fork Failed\n");
        exit(1);
    }

    else if (p == 0) {

        // Child process
        printf("Child process terminating...\n");
        exit(0);
    }

    else {

        // Parent process
        printf("Parent process\n");
        printf("Parent PID: %d\n", getpid());

        // Parent stays alive without calling wait()
        sleep(7);

        printf("Parent terminating...\n");
        exit(0);
    }

    return 0;
}