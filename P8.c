#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p1 = fork();
    if (p1 < 0) {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (p1 == 0) {
        printf("\nChild Process 1\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n\n", getppid());
        exit(0);
    }

    pid_t p2 = fork();
    if (p2 < 0) {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (p2 == 0) {
        printf("\nChild Process 2\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n\n", getppid());
        exit(0);
    }

    pid_t p3 = fork();
    if (p3 < 0) {
        printf("Fork Failed\n");
        exit(1);
    }
    else if (p3 == 0) {
        printf("\nChild Process 3\n");
        printf("PID  : %d\n", getpid());
        printf("PPID : %d\n\n", getppid());
        exit(0);
    }

    else {
        wait(NULL);
        wait(NULL);
        wait(NULL);
        printf("\nParent Process finished waiting for all children.\n");
    }

    return 0;
}
