#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fin, fout;
  
  fin = open("ex1.txt", O_RDONLY);
  fout = open("ex1.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

  struct stat Stat;
  if (fstat(fin, &Stat) == -1) {
    printf("Failed to fstat\n");
  }

  if (Stat.st_size == 0) {
    exit(0);
  }

  char* src = mmap(NULL, Stat.st_size, PROT_READ, MAP_PRIVATE, fin, 0);
  if (src == MAP_FAILED) {
    printf("Failed to mmap\n");
  }

  ftruncate(fout, Stat.st_size);
  char* dest = mmap(NULL, Stat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fout, 0);

  memcpy(dest, src, Stat.st_size);

  close(fin);
  close(fout);
}
