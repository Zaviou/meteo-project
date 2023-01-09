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
	return t;
}

NODE2_P1* rotateleftNODE2_P1(){

}

NODE2_P1* addNODE2_P1(NODE2_P1* t, STATION_P1 p1, int r){
	if(t==NULL){
		createNODE2_P1(t, p1);
	}else{
		if(t->s.id < r*(p1.id) && t->sl ==NULL){
			t->sl->s =p1;
		} else if (t->s.id < r*(p1.id) && t->sl !=NULL){
			addNODE2_P1(t->sl, p1, r);
		} else if (t->s.id > r*(p1.id) && t->sr ==NULL){
			t->sr->s =p1;
		} else {
			addNODE2_P1(t->sr, p1, r);
		}
	}
}

NODE2_P1* fillNODE2_P1withNODE_P1(NODE2_P1* t, NODE_P1* l, int r){
	NODE_P1* temp=l;
	while(temp!=NULL){
		addNODE2_P1(t, l->s, r);
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
