// P.V.S.PRANAV
// CS21B1056

/*
Write two different programs (Sender and Receiver) in C to demonstrate IPC using shared memory. Process "Sender.c" will write atleast 100 bytes of data to the shared memory and process "Receiver.c" will read from the shared memory and displays it. Then, "Receiver.c" will write atleast 100 bytes of data to the same shared memory and  "Sender.c" will read and displays it. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define shm_size 100

int main() {
    int x, shmid;
    key_t key = 1056;
    int *shm, *s;
    
    if((shmid = shmget(key, shm_size, 0666)) < 0) {     // create shared memory
        printf("Error in shmget \n");
        exit(1);
    }
    
    if((shm = shmat(shmid, NULL, 0)) == (int *) -1) {   // attach share memory to receiver
        printf("Error in shmat \n");
        exit(1);
    }
    
    for(s = shm; *s != 0; s++) {
        printf(" %d ",*s);
    }
    
    for(x = 27;x<52;x++) {
        *s++ = x;
    }
    
    *s = 0;
    
    *shm = '#';         // sender will be in sleep until this step
    
    return 0;
}
