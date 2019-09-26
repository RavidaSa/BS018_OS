#include <stdio.h>
#include <unistd.h>
#define N 100

void main() {

    int f;

    int ar[2];
    
    pipe(ar);
    
    char *str1 = "Text to copy";
    char str2[N];

    f = fork();

    if (f > 0) 
    {
        write(ar[1], str1, sizeof(str1) + 1);
    } 
    else if (f == 0) 
    {
        read(ar[0], str2, sizeof(str1));
        printf("%s\n", str2);
    }
}
