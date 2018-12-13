
#ifndef __NUMBER_H__
#define __NUMBER_H__


#include <stdint.h>

#define NODEBUG

struct number {
	uint8_t *data;
	uint32_t ndata;
	uint8_t sign;
};

void initNumber(struct number *);
void freeNumber(struct number *);

void allocNumber(struct number *, uint32_t);

void copyNumber(struct number *, struct number);
int setNumber(char *, struct number *);


void sumNumber(struct number *, struct number);

void printNumber(struct number);



#endif /* __NUMBER_H__ */
