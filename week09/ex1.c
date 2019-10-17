#include<stdio.h>
#include<stdlib.h>

int aging(int frames_num) {
	FILE *file = fopen("input.txt", "r");
  int miss = 0;
	int hit = 0;
	int count = 0;
	int var;

	while (fgetc(file) != EOF){
		fscanf(file, "%d", &var);
		count++;
	}

	fclose(file);

	file = fopen("input.txt", "r");
	int num;
  int *frame = calloc(frames_num, sizeof(int));
	int *age = calloc(frames_num, sizeof(int));
	
	for (int i = 0; i < count; i++){
		fscanf(file, "%d", &num);
		int free = 0;
		int hits = 0;

		for(int j = 0; j < frames_num; j++){
	  		age[j] = age[j] >> 1;

		 	if (hits != 1 && frame[j] == num){
		    	age[j] += (1 << 31);
		    	hit++;
		    	hits = 1;
		    }
		}
		if (!hits){
			for(int j = 0; j < frames_num; j++){
				if (frame[j] == 0){
					frame[j] = num;
					age[j] = 1 << 31;
					miss++;
					free = 1;
					break;
				}
			}
		} 
		if (!hits && !free){
		  int index = 0;
		  int min_age = age[0];
		  for (int j = 1; j < frames_num; j++){
		    if (age[j] < min_age){
		    	min_age = age[j];
		    	index = j;
		    }
		  }
		  frame[index] = frames_num;
		  age[index] = 1 << 31;
		  miss++; 
		}
	}
	fclose(file);
  	printf("Hit/Miss ratio: %f\n", (double) hit/miss);
  	return 0;
}

int main(){
  aging(10);
  aging(50);
  aging(100);
}
