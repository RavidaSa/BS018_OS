#include <stdio.h>
#include <signal.h>


void g(){
	printf("%s\n", "Ctrl C has been pressed");
}

void main() {

	signal(SIGINT, g);
	while (1){

	}
}
