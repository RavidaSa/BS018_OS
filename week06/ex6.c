#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void main() {

	int status;
	int ar[2];
	pipe(ar);

	pid_t id1, id2;

	id1 = fork();
	id2 = fork();

	if (id1 != 0 & id2 != 0){
		write(ar[1], &id1, sizeof(id2));
		waitpid(id2, &status, WUNTRACED);
		printf("Status:%d\n", status);
	}
	else if (id1 == 0){
		sleep(3);
		read(ar[0], &id2, sizeof(id2));
		kill(id2, SIGSTOP);
	}
	else {
		while(1){
			sleep(1);
			printf("Second child is alive\n");
		}	
	}
}
