#include <stdio.h>
#include <unistd.h>
#define N 100 

int main()
{
  int a[2];

  pipe(a);

  char *str1 = "Text to copy";
  char str2[N];
  
  write(a[1], str1, N);
  read(a[0], str2, N);

  printf("%s\n", str2);
}
