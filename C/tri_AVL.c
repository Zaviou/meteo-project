#include "tri_AVL.h"

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

NODE2_P1* createNODE2_P1(NODE2_P1* t, STATION_P1 p1){
	t =malloc(sizeof(NODE2_P1*));
	if(t ==NULL){
		printf("erreur d'allocation\n");
		exit(0);
	}
	t->s=p1;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
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
/*
		if(t->balance <-1 || t->balance >1) rebalance(t);
*/
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
//	freeNODE_P1(l);
}

void writeinfileNODE2_P1(FILE* o, NODE2_P1* t){
	fprintf(o,"Station ID;minimal pressure;maximal pressure;average pression\n");
	writeinfileNODE2_P1(o, t->sl);
	fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
	writeinfileNODE2_P1(o, t->sr);
//	freeNODE2_T1(t);
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
