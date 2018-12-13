
#include "number.h"
#include <stdio.h>
#include <stdint.h>


int main(){

	struct number n;
	struct number m;
	setNumber("abf000000000000008", &n);
	printf("n = ");
	printNumber(n);
	printf("\n");

	setNumber("fffffffff002000002", &m);
	printf("m = ");
	printNumber(m);
	printf("\n");


	sumNumber(&m, n);

	printf("m + n = ");
	printNumber(m);
	printf("\n");



	return 0;
}

