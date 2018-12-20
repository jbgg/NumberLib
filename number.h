
#ifndef __NUMBER_H__
#define __NUMBER_H__


#include <stdint.h>

#define NODEBUG

struct number {
	uint8_t *data;	/* {b0,b1,b2,...} =  ... b2 << 2*8 | b1 << 8 | b0  */
	uint32_t ndata; /* number of bytes allocated for data */
	int8_t sign;    /* sign of number: 0 if zero, */
   					/* 		1 if positive, and -1 if negative */
};


/* start a number equals zero with a specific number of bytes */
void allocNumber(struct number *, uint32_t);

/* free all bytes of number */
void freeNumber(struct number *);


/* creates a copy of a number */
void copyNumber(struct number *, struct number);

/* compare two number, 1 if first arg is greater than second,
 *   -1 if second arg is greater than first, 
 *   0 in other case
 */
int32_t cmpUnsignedNumber(struct number, struct number);

/* sums two number, result is stored in first argument */
void sumNumber(struct number *, struct number);

void sumUnsignedNumber(struct number *, struct number);
void diffUnsignedNumber(struct number *, struct number, struct number);

/* creates a number from a hex format string number */
int setNumber(char *, struct number *);

/* print a number in hex format */
void printNumber(struct number);



#endif /* __NUMBER_H__ */
