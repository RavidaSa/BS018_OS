#include <stdio.h>
#include <stdlib.h>

int main() {
	char arr[100];
	while (1) {
		printf("> ");
		scanf("%s", arr);
		system(arr);
	}
	return 0;
}
