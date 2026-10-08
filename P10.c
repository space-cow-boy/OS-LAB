//Write a C program to demonstrate an orphan process by terminating the parent while the child continues execution. Display the child's parent process ID before and after the parent terminates.


// orphan_process_demo.c

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
        printf("Child process started\n");
        printf("Parent PID before parent terminates: %d\n", getppid());

        sleep(5);

        printf("Parent PID after parent terminates: %d\n", getppid());
        printf("Child is now an orphan process\n");
    }

    else {

        // Parent process
        printf("Parent process\n");
        printf("Parent PID: %d\n", getpid());

        sleep(2);

        printf("Parent terminating...\n");
        exit(0);
    }

    return 0;
}