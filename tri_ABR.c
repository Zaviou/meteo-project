
//#include "headercommun.h"
#include "tri_ABR.h"

/*
------------------------------------------------------------
STRUCTURES
------------------------------------------------------------
*/

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

int freeNODE2_T1(NODE2_T1* t){
	// Each node of the tree needs to be freed individually.
	if(NODE2_T1==NULL){
		return 4;
	}
	freeNODE2_T1(NODE2_T1->sl);
	freeNODE2_T1(NODE2_T1->sr);
	free(NODE2_T1);
	return 0;
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
PRESSURE FUNCTIONS
------------------------------------------
*/

/*
------------------------------------------
MODE 1
------------------------------------------
*/

NODE2_P1* createNODE2_P1(NODE2_P1* t, STATION_P1 p1){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
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

NODE2_P1* addNODE2_P1(NODE2_P1* t, STATION_P1 p1, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		createNODE2_P1(t, p1);
	}else{
		if(t->s.id < r*(p1.id) && t->sl ==NULL){
			createNODE2_P1(t->sl->s, p1);
		} else if (t->s.id < r*(p1.id) && t->sl !=NULL){
			addNODE2_P1(t->sl, p1, r);
		} else if (t->s.id > r*(p1.id) && t->sr ==NULL){
			createNODE2_P1(t->sr->s, p1);
		} else {
			addNODE2_P1(t->sr, p1, r);
		}
	}
}

NODE2_P1* fillNODE2_P1withNODE_P1(NODE2_P1* t, NODE_P1* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P1* temp=l;
	while(temp!=NULL){
		addNODE2_P1(t, l->s, r);
		temp=temp->next;
	}
//	freeNODE_P1(l);
}

void writeinfileNODE2_P1(FILE* o, NODE2_P1* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	fprintf(o,"Station ID;minimal pressure;maximal pressure;average pression\n");
	writeinfileNODE2_P1(o, t->sl);
	if(t->s.id <=9999){
		fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
	} else {
		fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
	}
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
