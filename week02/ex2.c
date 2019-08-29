#include <stdio.h>
#include <string.h>

int main() {
  char s[256];
  printf("Please enter the string: \n");
  fgets(s,sizeof(s),stdin);
  for(int i=strlen(s)-2;i>=0;--i){
      printf("%c",s[i]);
  }
  return 0;
}
