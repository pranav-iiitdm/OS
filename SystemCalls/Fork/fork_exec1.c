// P.V.S.PRANAV
// CS21B1056

/*
Write two programs (Given fork_exec1.c and fork_exec2.c).

For Lab5Question41.c:

In Parent Process:
(a) Print your name, roll number, and Institution name 
(b) Print process id and its parent process id and returned value of fork() system call.

In Child Process,
(a) Print id of the process, it’s parent process id, and returned value of fork() system call.
(b) Use exec() system call to execute new program written in Lab5Question42.c. In Lab5Question42.c, write or compute anything of your choice. The executable file for Lab5Question42.c is (Lab5Question42).
(c) Write a few printf statements after operation (b).

Analyze the entire creation of the parent and child processes. Make sure that the parent process terminates after the child process has finished its execution.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
    int pid = fork();
    
    if(pid == 0) {
        printf("Pid : %d   Parent Pid : %d     Fork() return : %d \n",getpid(), getppid(), pid);
        char * args[] = {"./Lab5Question42", NULL};
        execvp(args[0], args);
        
        printf("After exec() in child\n");
        exit(0);
    }
    else {
        wait(NULL);
        printf("Name : P.V.S.PRANAV\n");
        printf("Roll.No : CS21B1056\n");
        printf("Institution Name : IIITDM\n");
        printf("Pid : %d   Parent Pid : %d     Fork() return : %d \n",getpid(), getppid(), pid);
    }
    return 0;
}
