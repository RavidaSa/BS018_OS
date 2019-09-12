#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 

int main() {
int n;
for (int i=0;i<3;++i){
fork();
sleep(5);

}
/* 8 processes are created in general. But at each iteration of the for loop current parent and correspondent child create 2 more processes*/

return 0;
}

