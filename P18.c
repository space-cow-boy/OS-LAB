//C program to open a file in child process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    FILE *fptr;

    // Parent creates file
    fptr = fopen("input.txt", "w");

    if (fptr == NULL) {
        printf("File creation failed\n");
        exit(1);
    }

    fprintf(fptr, "Hello from parent\n");
    fprintf(fptr, "This file is opened by child\n");

    fclose(fptr);

    pid_t p = fork();

    if (p < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    else if (p == 0) {

        // Child opens file
        fptr = fopen("input.txt", "r");

        if (fptr == NULL) {
            printf("File opening failed\n");
            exit(1);
        }

        char ch;

        printf("Child reading file:\n");

        while ((ch = fgetc(fptr)) != EOF) {
            printf("%c", ch);
        }

        fclose(fptr);
    }

    else {

        wait(NULL);
    }

    return 0;
}