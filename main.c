
#include "number.h"
#include <stdio.h>
#include <stdint.h>


int main(){

	struct number n;
	struct number m;

	setNumber("-000000001", &m);
	printf("m = ");
	printNumber(m);
	printf("\n");


	return 0;
}

