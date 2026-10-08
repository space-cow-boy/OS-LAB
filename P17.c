//Write a C program in which the parent creates input.txt, writes a name, university roll number, and class into it, and the child opens the file, reads its contents, and displays them.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p = fork();

    if (p < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (p == 0) {
        // Child process: open file and read contents
        FILE *fptr = fopen("input.txt", "r");
        if (fptr == NULL) {
            perror("Child: File open failed");
            exit(1);
        }

        char ch;

        while ((ch = fgetc(fptr)) != EOF) {
            printf("%c", ch);
        }

        fclose(fptr);
        exit(0);
    }
    else {
        // Parent process: create file and write data
        FILE *fptr = fopen("input.txt", "w");
        if (fptr == NULL) {
            perror("Parent: File creation failed");
            exit(1);
        }

        fprintf(fptr, "Name: Sandeep\n");
        fprintf(fptr, "University Roll Number: 20\n");
        fprintf(fptr, "Class: B.Tech 3rd Year\n");
        fclose(fptr);

        printf("Parent: Written data to input.txt\n");

        wait(NULL);  // Wait for child to finish
        printf("Parent: Child process finished.\n");
    }

    return 0;
}
