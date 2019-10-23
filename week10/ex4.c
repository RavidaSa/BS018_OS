#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

char pattern[] = "find ~ -inum ";
char buffer[256];

int main(){
    struct dirent *dir; 
    char *directory = "/home/ravi/tmp";
    DIR *dr = opendir(directory);
    struct stat dirStat;

    
    if (dr == NULL)  
    { 
        fprintf(stderr,"Can not open: %s\n", dr); 
        return 0; 
    } 
    chdir(directory);
    while ((dir = readdir(dr)) != NULL){
            if (stat(dir->d_name, &dirStat)==-1) {
                fprintf(stderr,"Cannot use stat\n");
                return 0;}
                
            if(dirStat.st_nlink >= 2){
                char node[25];
                snprintf(node,25,"%ld", dirStat.st_ino);
                strcat(buffer,"find ");
                strcat(buffer,directory);
                strcat(buffer,"/");
                strcat(buffer,dir->d_name);
                strcat(buffer," -inum ");
                strcat(buffer,node);
                strcat(buffer," >> ex4.txt");
                system(buffer);
                buffer[0]='\0';
            }
            
    }
    chdir("..");
    closedir(dr);
    return 0;
}
