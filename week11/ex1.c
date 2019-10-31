#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	struct stat bufstat;
	int file = open("ex1.txt", O_RDWR);
	void* map;
	int status = fstat(file, &bufstat);
	map = mmap(0,bufstat.st_size,PROT_READ | PROT_WRITE ,MAP_SHARED, file , 0);
	sprintf((char*)map, "%s\n", "This is a nice day");
	return 0;
}
