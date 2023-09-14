// P.V.S.PRANAV
// CS21B1056

/*
Create parent and child processes using fork(). In each process, define an array of integer using malloc. Before that take the size of the array from the user. Insert values in your array (size and array elements may be different for both processes).

In Parent Process:
(a) Print the array elements and their addresses
(b) Sort the array and print its values.

In Child Process:
(a) Print the array elements and their address
(b) Reverse the array and print its values.

NOTE: Ensure that first child process should terminate, then Parent Process should start taking input.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    int pid = fork();
    
    if(pid < 0) {
        printf("ERROR in fork() \n");
    }
    if(pid == 0) {
        int n;
        printf("Enter the size of the array : ");
        scanf("%d",&n);
        
        int * a = (int *)malloc(sizeof(int)*n);
        
        printf("Enter %d elements of the array : \n",n);
        for(int i=0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        
        int temp;
        
        for(int i=0;i<n;i++) {
            printf(" %d %p \n",a[i], &a[i]);
        }
        
        for(int i=0;i<n/2;i++) {
            temp = a[i];
            a[i] = a[n-i-1];
            a[n-i-1] = temp;
        }
        
        printf("Reversed Array : ");
        for(int i=0;i<n;i++) {
            printf(" %d ",a[i]);
        }
        printf("\n");
        
        exit(0);            // implies successful termination of the process
    }
    else {
        wait(NULL);         // wait(NULL) will go into the block state until the child process is successfully terminated
        
        int n;
        printf("Enter the size of the array : ");
        scanf("%d",&n);
        
        int * arr = (int *)malloc(sizeof(int)*n);
        
        printf("Enter %d elements of the array : \n",n);
        for(int i=0;i<n;i++) {
            scanf("%d",&arr[i]);
        }
        
        for(int i=0;i<n;i++) {
            printf(" %d %p \n",arr[i], &arr[i]);
        }
        
        int temp;
        
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                if(arr[i]>arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];            // Bubble Sort implementation
                    arr[j] = temp;
                }
            }
        }
        
        printf("Sorted Array : ");
        for(int i=0;i<n;i++) {
            printf(" %d ",arr[i]);
        }
        printf("\n");
    }
    
    return 0;
}
