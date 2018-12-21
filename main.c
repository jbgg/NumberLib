
#include "number.h"
#include <stdio.h>
#include <stdint.h>


int main(){

	struct number n;
	struct number m;


	setNumber("01", &n);
	setNumber("-0f00", &m);

	printf("n = ");
	printNumber(n);
	printf("\n");

	//printf("n.ndata = %d\n", n.ndata);
	//printf("n.sign = %d\n", n.sign);

	printf("m = ");
	printNumber(m);
	printf("\n");

	//printf("m.ndata = %d\n", m.ndata);
	//printf("m.sign = %d\n", m.sign);

	sumNumber(&n, m);

	printf("n + m = ");
	printNumber(n);
	printf("\n");

	return 0;
}

