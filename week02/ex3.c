#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n;
  int d;
  printf("Please enter the integer: \n");
  sscanf(argv[1], "%d", &n);
  
  for(int i = 0; i<n;i++){
     d=n-i-1;
     printf("%*s%s", d, "", "*");
     for (int j = 0;j<2*i;++j){printf("*");}
     printf("\n");
  }
  return 0;
}
