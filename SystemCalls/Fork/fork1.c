// P.V.S.PRANAV
// CS21B1056

/*
Write a C program which will create a child process from a parent process. In parent process, define one global array and take input from the user.

 

Perform following operations.

In Parent Process:

(a) Update the array by subtracting 3 from each element of the array.

(b) Print the elements, address of the elements and find the minimum element after performing (a).

(c) Print process id and it’s parent process id

 

In Child Process:

(a) Update the global array by adding 2 on each element of the array.

(b) Print the elements, address of the elements and find the maximum element after performing (a)

(c) Print process id and it’s parent process id.


*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int arr[6];  // array declaration

int main() {
    printf("Enter 6 elements of the array : ");
    for(int i=0;i<6;i++) {
        scanf("%d",&arr[i]);    
    }
    
    int pid = fork();
    
    if(pid == 0) {
        for(int i=0;i<6;i++) {
            arr[i] = arr[i] + 2;
        }
        
        int max = arr[0];
        
        for(int i=0;i<6;i++) {
            if(arr[i] >= max) {         // to find maximum in the array
                max = arr[i];
            }
        }
        
        for(int i=0;i<6;i++) {
            printf(" %d %p \n",arr[i], &arr[i]);
        }
        printf("pid = %d parent pid = %d max = %d \n",getpid(), getppid(), max);
    }
    
    else {
        for(int i=0;i<6;i++) {
            arr[i] = arr[i] - 3;
        }
        
        int min = arr[0];
        
        for(int i=0;i<6;i++) {
            if(arr[i] <= min) {     // to find minimum in the array
                min = arr[i];
            }
        }
        
        for(int i=0;i<6;i++) {
            printf(" %d %p \n",arr[i], &arr[i]);
        }                                                                           // getppid() gives pid of the parent process of the current process
        printf("pid = %d parent pid = %d min = %d \n",getpid(), getppid(), min);    //getpid() gives pid of the running process
    }
    
    return 0;
}
