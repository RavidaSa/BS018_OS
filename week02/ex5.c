#include <stdio.h>
#include <string.h>

void print_tree(int n){
     int d;
    
    for(int i = 0; i<n;i++){
     d=n-i-1;
     printf("%*s%s", d, "", "*");
     for (int j = 0;j<2*i;++j){printf("*");}
     printf("\n");
  }
}

void print_a(int n){
    for(int i=1;i<n+1;++i){
        for(int j = 0; j<i;++j){
            printf("%c",'*');
        }
        printf("\n");
    }
}
void print_b(int n){
    for(int i=1;i<=n;++i){
        if(i<=(n/2)){
        for(int j = 0; j<i;++j){
            printf("%c",'*');
        }}
        else {
            for(int j =n- i+1; j>0;--j){
            printf("%c",'*');
            }
        }
        printf("\n");
    }
}
void print_c(int n){
    for(int i=1;i<n+1;++i){
        for(int j = 0; j<n;++j){
            printf("%c",'*');
        }
        printf("\n");
    }
}
int main(int argc, char *argv[]) {
    int n;
    sscanf(argv[1], "%d", &n);
    //print_tree(n);
    //print_a(n);
    //print_b(n);
    //print_c(n);
  return 0;
}
