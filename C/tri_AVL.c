#ifndef TRIAVL
	#define TRIAVL
	#include "tri_AVL.h"
#endif

/*
------------------------------------------------------------
FUNCTIONS
------------------------------------------------------------
*/

int min(int a, int b){
	return(a >b ? b : a);
}

int max(int a, int b){
	return(a <b ? b : a);
}

/*
------------------------------------------
TEMPERATURE FUNCTIONS
------------------------------------------
*/

/*
------------------------------------------
MODE 1
------------------------------------------
*/

/*
------------------------------------------
MODE 2
------------------------------------------
*/

/*
------------------------------------------
MODE 3
------------------------------------------
*/

/*
------------------------------------------------------------
PRESSURE FUNCTIONS
------------------------------------------------------------
*/

/*
------------------------------------------
MODE 1
------------------------------------------
*/

void freetreeNODE2_P1(NODE2_P1* t){
	if(t !=NULL){
		if(t->sl==NULL && t->sr==NULL) free(t);
		else {
			if(t->sl!=NULL) freeNODE2_P1(t->sl);
			if(t->sr!=NULL) freeNODE2_P1(t->sr);
		}
	}
}

NODE2_P1* createNODE2_P1(NODE2_P1* t, STATION_P1 p1){
	t =malloc(sizeof(NODE2_P1*));
	if(t ==NULL){
		//return 4;
		return NULL;
	}
	t->s=p1;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_P1* rotateleftNODE2_P1(NODE2_P1* t){
	NODE2_P1* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_P1* rotaterightNODE2_P1(NODE2_P1* t){
	NODE2_P1* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_P1* doublerotateleftNODE2_P1(NODE2_P1* t){
	t->sr =rotaterightNODE2_P1(t->sr);
	t=rotateleftNODE2_P1(t);
	return t;
}

NODE2_P1* doublerotaterightNODE2_P1(NODE2_P1* t){
	t->sl=rotateleftNODE2_P1(t->sl);
	t=rotaterightNODE2_P1(t);
	return t;
}

NODE2_P1* rebalanceNODE2_P1(NODE2_P1* t){
	if(t->balance >=2){
		if(t->sr->balance >=0) return rotateleftNODE2_P1(t);
		else return doublerotateleftNODE2_P1(t);
	} else if(t->balance<=-2){
		if(t->sl->balance<=0) return rotaterightNODE2_P1(t);
		else return doublerotaterightNODE2_P1(t);
	}
	return t;
}

NODE2_P1* addNODE2_P1(NODE2_P1* t, STATION_P1 p1, int* h, int r){
	if(t==NULL){
		*h=1;
		return createNODE2_P1(t, p1);
	}else{
		if(t->s.id < r*(p1.id)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL)addNODE2_P1(t->sl, p1, h, r);
			else createNODE2_P1(t->sl, p1);
		} else if(t->s.id > r*(p1.id)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL)addNODE2_P1(t->sr, p1, h, r);
			else createNODE2_P1(t->sr, p1);
		} else {
			*h=0;
			return t;
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_P1(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}
	return t;
}

NODE2_P1* fillNODE2_P1withNODE_P1(NODE2_P1* t, NODE_P1* l, int r){
	NODE_P1* temp=l;
	int* h=0;
	while(temp!=NULL){
		addNODE2_P1(t, l->s, h, r);
		temp=temp->next;
	}
	freeNODE_P1(l);
}

void writeinfileNODE2_P1(FILE* o, NODE2_P1* t){
	fprintf(o,"Station ID;minimal pressure;maximal pressure;average pression\n");
	writeinfileNODE2_P1(o, t->sl);
	fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
	writeinfileNODE2_P1(o, t->sr);
	freetreeNODE2_P1(t);
}

/*
------------------------------------------
MODE 2
------------------------------------------
*/

/*
------------------------------------------
MODE 3
------------------------------------------
*/

/*
------------------------------------------
WIND FUNCTIONS
------------------------------------------
*/

/*
------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------
*/

/*
------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------
*/
