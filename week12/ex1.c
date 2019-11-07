#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("/dev/random", "r");
    FILE *file = fopen("ex1.txt", "a+");
    char *text = (char *) malloc(sizeof(char));
    fgets(text, 20, f);
    fprintf(file, text);
    fclose(file);
    return 0;
} 
