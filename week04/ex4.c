#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 256

int main() {
    char input[MAX_LEN];
    while(1) {
        printf("   $ ");
        fgets(input, MAX_LEN, stdin);
        system(input);
    }
    
    return 0;
}
