//Write a C program in which the parent calculates the sum of a fixed array, sends the sum to the child through a pipe, and the child checks and displays whether the received sum is prime.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

// Prime check function
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int fd[2];
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid_t p = fork();

    if (p < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (p == 0) {
        // Child process
        close(fd[1]);  // Close write end

        int sum;
        read(fd[0], &sum, sizeof(sum));
        close(fd[0]);

        printf("Child: Received sum = %d\n", sum);
        if (isPrime(sum)) {
            printf("Child: %d is a prime number.\n", sum);
        } else {
            printf("Child: %d is not a prime number.\n", sum);
        }
        exit(0);
    }
    else {
        // Parent process
        close(fd[0]);  // Close read end

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        printf("Parent: Calculated sum = %d\n", sum);

        write(fd[1],&sum,sizeof(sum));
        close(fd[1]);

        wait(NULL);  // Wait for child
        printf("Parent: Child process finished.\n");
    }

    return 0;
}
