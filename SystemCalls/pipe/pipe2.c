// P.V.S.PRANAV
// CS21B1056

/*
A parent process creates a child process and the child process creates a grandchild process. The parent creates a pipe that is shared between the parent and the child. The parent writes a message to the pipe and the child reads it from the pipe. The child creates another pipe which is shared between the child and the grandchild. Note that this pipe is not available to the parent and is not the same as the one shared by the parent and the child. The grandchild writes another message to the pipe and the child reads it from the pipe. After obtaining the two messages from the pipes, the child prints the difference in lengths of the two messages. Moreover, each of the three processes prints the PID of its respective parent process. The contents of the two messages must be taken as user inputs.
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    int pipe1[2];
    char str1[20];
    char recv1[20];
    
    
    if(pipe(pipe1) == -1) {
        printf("ERROR in pipe()\n");
    }
    
    int pid = fork();
        
    if(pid == 0) {
        read(pipe1[0], recv1, sizeof(recv1));
        printf("Parent PID of Child : %d\n", getppid());
        
        int pipe2[2];               // pipe2 only accessible between child and grandchild
        
        char recv2[20];
        
        if(pipe(pipe2) == -1) {
            printf("ERROR in pipe()\n");
        }
        
        int pid1 = fork();
        
        if(pid1 == 0) {
            char str2[20];
            printf("Parent PID of Grandchild : %d\n", getppid());
            
            printf("Enter a string : ");
            fgets(str2, 20, stdin);
            
            write(pipe2[1], str2, sizeof(str2));
        }
        else {
            read(pipe2[0], recv2, sizeof(recv2));
            
            printf("String from parent process is %s\n", recv1);
            printf("String from grandchild process is %s\n", recv2);
            if(strlen(recv1) - strlen(recv2) < 0) {
                printf("Difference in lengths of the two string is %ld\n", (strlen(recv2) - strlen(recv1)));    
            }
            else {
                printf("Difference in lengths of the two string is %ld\n", (strlen(recv1) - strlen(recv2)));
            }
        }
    }
    else {
        printf("Parent PID of Parent : %d\n", getppid());
        
        printf("Enter the string : ");
        fgets(str1, 20, stdin);
        
        write(pipe1[1], str1, sizeof(str1));
        wait(NULL);
    }
    
    return 0;
}
