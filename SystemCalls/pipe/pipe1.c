// P.V.S.PRANAV
// CS21B1056

/*
Write a program using pipe() and fork() in which parent process takes one string as input. The same is sent to the child using pipe1 and child will reverse it. After the reversing is complete, the child process will send it (reversed string) to parent process using pipe2. Subsequently, parent process will read the string and displays it.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    int pipe1[2];               // pipe1 : parent can only write and child can only read
    int pipe2[2];               // pipe2 : parent can only read and child can only write
    int pid;
    
    char str[20];
    char str1[20];
    char recv[20];
    char temp;
    
    
    if(pipe(pipe1) == -1) {             //pipe1 creation
        printf("ERROR in pipe()\n");
    }
    
    if(pipe(pipe2) == -1) {             //pipe1 creation
        printf("ERROR in pipe()\n");
    }
    
    pid = fork();
    
    if(pid == 0) {
        close(pipe1[1]);            // write permission for pipe1 is restricted
        close(pipe2[0]);            // read permission for pipe2 is restricted
        
        read(pipe1[0], recv, sizeof(recv));
        printf("Received string from parent : %s\n", recv);

        int n = strlen(recv);
        char c;
        
        for(int i=0;i<n/2;i++) {
            c = recv[i];
            recv[i] = recv[n-i-1];
            recv[n-i-1] = c;
        }
        
        write(pipe2[1], recv, sizeof(recv));
    }
    else {
        close(pipe1[0]);            // read permission for pipe1 is restricted
        close(pipe2[1]);            // write permission for pipe2 is restricted
        
        printf("Enter a string : ");
        fgets(str, 20, stdin);
        
        write(pipe1[1], str, sizeof(str));
        read(pipe2[0], str1, sizeof(str1));
        
        printf("Received string from child : %s\n", str1);
    }
    
    return 0;
}
