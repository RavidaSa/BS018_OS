#include <stdio.h>
#include <sys/types.h>

int main() {
int n;

n = fork();

if (n==0)
    printf("Hello from child [%d - %d]\n", getpid(), n);
else
    printf("Hello from parent [%d - %d]\n", getpid(), n);

return 0;
/* In the above code, a child process is created, fork() 
returns 0 in the child process and positive integer to the parent process.
Here, two outputs are possible because the parent process and child process are running concurrently. 
So we don’t know if OS first give control to which process a parent process or a child process.*/
}


