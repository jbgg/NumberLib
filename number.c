
#include "number.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* TODO:
 *   check output of malloc
 */


/* it creates number zero with a specific bytes length */
void allocNumber(struct number *p, uint32_t n){

	/* allocate space for number */
	p->data = (uint8_t*) malloc(sizeof(uint8_t) * n);
	p->ndata = n;

	/* number is zero */
	p->sign = 0;
	uint32_t i;
	for(i=0;i<n;i++){
		p->data[i] = 0;
	}
}


void freeNumber(struct number *p){
	if(p->data)
		free(p->data);
}


/* it increases the number of bytes */
void expandNumber(struct number *p, uint32_t k){

	if(k==0)
		return;


	/* allocate space */
	uint8_t *q = (uint8_t*) malloc(sizeof(uint8_t)*(p->ndata+k));

	uint32_t i;
	/* copy bytes from last memory */
	for(i=0;i<p->ndata;i++){
		q[i] = p->data[i];
	}
	
	/* update new data length */
	p->ndata += k;

	/* most significant bytes are zero */
	do{
		q[i] = 0;
		i++;
		k--;
	}while(k!=0);

	free(p->data);
	/* update new memory */
	p->data = q;

}


void copyNumber(struct number *p, struct number n){

	/* init the number as zero with enough memory */
	allocNumber(p, n.ndata);

	/* copy all info of number */
	p->ndata = n.ndata;
	p->sign = n.sign;
	uint32_t i;
	for(i=0;i<n.ndata;i++)
		p->data[i] = n.data[i];

}





static uint8_t sumByte(uint8_t *r, uint8_t s, uint8_t c){
	uint16_t t = *r;
	t += s;
	t += c;
	*r = (uint8_t) (t & 0xff);
	return (uint8_t) (t >> 8);
}


/* TODO: handle sign */
void sumNumber(struct number *p, struct number n){

	if(p->ndata < n.ndata){
		expandNumber(p, n.ndata - p->ndata);
	}

	uint8_t carry = 0;
	uint32_t i;
	for(i=0;i<n.ndata;i++){
		carry = sumByte(&p->data[i], n.data[i], carry);
	}

	for(;i<p->ndata;i++){
		carry = sumByte(&p->data[i], 0, carry);
	}
	if(carry != 0){
		expandNumber(p, 1);
		sumByte(&p->data[i], 0, carry);
	}

}


int setNumber(char *str, struct number *p){
	int8_t sign;
	if(str[0] == '-'){
		sign = -1;
		str++;
	}else{
		sign = 1;
		if(str[0] == '+')
			str++;
	}
	while(str[0]=='0')
		str++;

	uint32_t i;
	for(i=0;str[i]!=0;i++){
		if(str[i]<'0' || str[i] > '9'){
			if(str[i]<'a' || str[i]>'f'){
				return -1;
			}
		}
	}
	if(i==0){
		allocNumber(p,1);
		return 0;
	}
	uint32_t n;
	n = i/2 + i % 2;
	allocNumber(p, n);

	n = 0;
	uint8_t l,u;
	do{

		i--;
		l = str[i] >= '0' && str[i] <= '9' ? (uint8_t) (str[i] - '0') : (uint8_t)(str[i] - 'a' + 0xa);
		if(i==0){
			u=0;
		}else{
			i--;
			u = str[i] >= '0' && str[i] <= '9' ? (uint8_t) (str[i] - '0') : (uint8_t)(str[i] - 'a' + 0xa);
		}

		p->data[n] = (uint8_t) ((u << 4) | l);
		n++;

	}while(i!=0);

	p->sign = sign;

	return 0;


}


void printNumber(struct number n){

	if(n.ndata == 0 || n.data == 0){
		return;
	}

	uint32_t i = n.ndata;
#if 0
	do{
		i--;
	}while(n.data[i]==0);
	i++;
#endif

	if(n.sign == -1)
		printf("-");

	do{
		i--;
		printf("%02x", n.data[i]);

	}while(i!=0);


}


