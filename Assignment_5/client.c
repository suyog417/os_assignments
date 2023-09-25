#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  // Size of the shared memory segment

int main() {
    key_t key = ftok("shmfile", 'R'); // Use the same key as the server
    int shmid;

    // Attach to the shared memory segment
    shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to the client's address space
    char *shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)(-1)) {
        perror("shmat");
        exit(1);
    }

    // Read and display the message from the shared memory
    printf("Message from server: %s\n", shm_ptr);

    // Signal the server that the message has been read
    *shm_ptr = '*';

    // Detach the shared memory segment
    shmdt(shm_ptr);

    return 0;
}
