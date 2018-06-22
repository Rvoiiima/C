#include <stdio.h>
#include <stdlib.h>

int main (void) {
	int i;
	for(i = 0 ; i <50 ; i++) {
		printf("%d \n",rand()%10);
	}
	return 0;
}
		