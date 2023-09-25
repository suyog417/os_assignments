#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_CONTENT 1024

int main() {
    int pipe1[2]; // Pipe for sending file paths from parent to child
    int pipe2[2]; // Pipe for sending file contents from child to parent
    pid_t pid;
    
    // Create pipe1
    if (pipe(pipe1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }
    
    // Create pipe2
    if (pipe(pipe2) == -1) {
        perror("pipe2");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        close(pipe1[1]); // Close write end of pipe1
        close(pipe2[0]); // Close read end of pipe2

        char filepath[MAX_PATH_LENGTH];
        char filecontent[MAX_FILE_CONTENT];
        
        // Read the file path from pipe1
        if (read(pipe1[0], filepath, sizeof(filepath)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Open the file for reading
        FILE *file = fopen(filepath, "r");
        if (file == NULL) {
            perror("fopen");
            exit(EXIT_FAILURE);
        }

        // Read file contents and write to pipe2
        while (fgets(filecontent, sizeof(filecontent), file) != NULL) {
            // Write file content to pipe2
            if (write(pipe2[1], filecontent, strlen(filecontent)) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // Close file and pipes
        fclose(file);
        close(pipe1[0]);
        close(pipe2[1]);
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(pipe1[0]); // Close read end of pipe1
        close(pipe2[1]); // Close write end of pipe2

        char filepath[MAX_PATH_LENGTH];
        char filecontent[MAX_FILE_CONTENT];

        // Input file path from the user
        printf("Enter the path of the file: ");
        fgets(filepath, sizeof(filepath), stdin);
        filepath[strcspn(filepath, "\n")] = '\0'; // Remove the newline character
        
        // Write the file path to pipe1
        if (write(pipe1[1], filepath, strlen(filepath)) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        // Read file contents from pipe2 and display on standard output
        while (read(pipe2[0], filecontent, sizeof(filecontent)) > 0) {
            printf("%s", filecontent);
        }

        // Close pipes and wait for the child to exit
        close(pipe1[1]);
        close(pipe2[0]);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }

    return 0;
}