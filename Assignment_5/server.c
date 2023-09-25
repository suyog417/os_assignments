#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Size of the shared memory segment

int main() {
    key_t key = ftok("shmfile", 'R'); // Generate a unique key
    int shmid;

    // Create a shared memory segment
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the server's address space
    char *shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Write a message to the shared memory
    strcpy(shm_ptr, "Hello from the server!");

    // Wait for the client to signal that it has read the message
    while (*shm_ptr != '*') {
        sleep(1);
    }

    // Detach the shared memory segment
    shmdt(shm_ptr);

    // Remove the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
