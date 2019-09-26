#include <stdio.h>
#include <signal.h>


void handler_1(){
	printf("%s\n", "SIGKILL");
}


void handler_2(){
	printf("%s\n", "SIGSTOP");
}


void handler_3(){
	printf("%s\n", "SIGUSR1");
}

void main() {

	signal(SIGKILL, handler_1);
	signal(SIGSTOP, handler_2);
	signal(SIGUSR1, handler_3);

	while (1){

	}
}
