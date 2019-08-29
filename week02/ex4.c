#include <stdio.h>
#include <string.h>

void swap(int *f, int *s){
    int temp = *f;
    *f = *s;
    *s = temp;
}

int main(int argc, char *argv[]) {
  int n;
  int d;
  printf("Please enter first integer: \n");
  scanf ("%d", &n);
  scanf("%d", &d);
  swap(&n,&d);
    printf("%d %d",n,d);
  return 0;
}
