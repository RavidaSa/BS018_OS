#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define min(a, b) (a < b ? a : b)

void *realloc(void *ptr, size_t size) {
	void* new_arr = malloc(size);
	memcpy(new_arr, ptr, size);
	free(ptr);
	return new_arr;
}

int main(){
	
	srand(time(NULL));

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);


	int* a1 = malloc(n1 * sizeof(int));

	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;

		printf("%d ", a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	a1 = realloc(a1, n2 * sizeof(int));

	for (int i = n1; i < n2; i++) {
		a1[i] = 0;
	}
	

	for(i=0; i<n2;i++){
		
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	return 0;
}
