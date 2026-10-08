//Write a C program that accepts an array of integers, creates a child process, calculates the sum of the array in the child, checks whether the sum is prime, and makes the parent wait for the child to complete.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

// Function to check prime
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

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        // Child process: calculate sum and check prime
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        printf("Child: Sum of array = %d\n", sum);

        if (isPrime(sum)) {
            printf("Child: %d is a prime number.\n", sum);
        } else {
            printf("Child: %d is not a prime number.\n", sum);
        }
        exit(0);
    }
    else {
        // Parent process waits for child
        wait(NULL);
        printf("Parent: Child process finished.\n");
    }

    return 0;
}
