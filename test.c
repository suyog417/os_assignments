// #include<stdio.h>

// int main(int argc, char const *argv[])
// {
//     int arr[] = {10,50,6,76,694,354,87,35,87,34,687,340};
//     int len = sizeof(arr) / sizeof(arr[0]);
//     printf("%d",len);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
// #include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int arr[100]; // Assuming a maximum of 100 integers
    int n; // Number of elements in the array

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) { // Child process
        char *child_args[3]; // Arguments for EXECVE
        child_args[0] = "binary_search"; // Name of the compiled binary search program
        child_args[1] = argv[1]; // Sorted array passed as argument
        child_args[2] = NULL;

        execve(child_args[0], child_args, NULL); // Load and execute the binary search program
        perror("Execve failed");
        exit(EXIT_FAILURE);
    } else { // Parent process
        wait(NULL); // Wait for the child process to finish
        
        // Sort the array
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        printf("Sorted array:");
        for (int i = 0; i < n; i++) {
            printf(" %d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}
