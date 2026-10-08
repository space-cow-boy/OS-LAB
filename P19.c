//Child writes all even numbers to a file, passes the filename to the parent through a pipe, and the parent reads and displays the file contents.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {

    int fd[2];

    pipe(fd);

    pid_t p = fork();

    if (p < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    else if (p == 0) {

        // Child
        close(fd[0]);

        FILE *fptr = fopen("even.txt", "w");

        if (fptr == NULL) {
            printf("File creation failed\n");
            exit(1);
        }

        // Write even numbers
        for (int i = 2; i <= 20; i += 2) {
            fprintf(fptr, "%d ", i);
        }

        fclose(fptr);

        // Send filename to parent
        char filename[] = "even.txt";

        write(fd[1], filename, strlen(filename) + 1);

        close(fd[1]);

        exit(0);
    }

    else {

        // Parent
        close(fd[1]);

        char filename[100];

        // Receive filename
        read(fd[0], filename, sizeof(filename));

        close(fd[0]);

        wait(NULL);

        // Open file
        FILE *fptr = fopen(filename, "r");

        if (fptr == NULL) {
            printf("File opening failed\n");
            exit(1);
        }

        char ch;

        printf("File contents:\n");

        while ((ch = fgetc(fptr)) != EOF) {
            printf("%c", ch);
        }

        fclose(fptr);
    }

    return 0;
}