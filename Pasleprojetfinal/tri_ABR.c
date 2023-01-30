#ifndef HEADCOMMUN
	#define HEADCOMMUN
	#include "headercommun.h"
#endif

#ifndef COMMUN
	#define COMMUN
	#include "commun.c"
#endif

#ifndef TRABR
	#define TRIABR
	#include "tri_ABR.h"

#endif

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

void freetreeNODE2_T1(NODE2_T1* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_T1(t->sl);
		freetreeNODE2_T1(t->sr);
		free(t);
	}
}

NODE2_T1* createNODE2_T1(STATION_T1 t1){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_T1* t =malloc(sizeof(NODE2_T1));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->s=t1;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_T1* addNODE2_T1(NODE2_T1* t, STATION_T1 t1, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_T1(t1);
	}else{
		if(r* (t->s.id) > r*(t1.id)){

			printf("oui %d\n", r);

			if (t->sl !=NULL) t->sl =addNODE2_T1(t->sl, t1, r);
			else t->sl =createNODE2_T1(t1);
		} else if(r* (t->s.id) < r*(t1.id)){
			if (t->sr !=NULL) t->sr =addNODE2_T1(t->sr, t1, r);
			else t->sr =createNODE2_T1(t1);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_T1* fillNODE2_T1withNODE_T1(NODE2_T1* t, NODE_T1* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T1* temp=l;
	while(temp!=NULL){
		t =addNODE2_T1(t, temp->s, r);
		temp=temp->next;
	}
	freeNODE_T1(l);
	return t;
}

void writeinfileNODE2_T1(FILE* o, NODE2_T1* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_T1(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
		writeinfileNODE2_T1(o, t->sr);
	}
	
}

/*
------------------------------------------
MODE 2
------------------------------------------
*/

void freetreeNODE2_T2(NODE2_T2* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_T2(t->sl);
		freetreeNODE2_T2(t->sr);
		free(t);
	}
}

NODE2_T2* createNODE2_T2(TIME_T2 t2){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_T2* t =malloc(sizeof(NODE2_T2));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->t=t2;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_T2* addNODE2_T2(NODE2_T2* t, TIME_T2 t2, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_T2(t2);
	}else{
		if((chronologicalorder_T2(t2, t->t) ==1 && r==1) || (chronologicalorder_T2(t2, t->t)==0 && r==-1)){
			if (t->sl !=NULL) t->sl =addNODE2_T2(t->sl, t2, r);
			else t->sl =createNODE2_T2(t2);
		} else if((chronologicalorder_T2(t->t, t2) ==1 && r==1) || (chronologicalorder_T2(t->t, t2)==0 && r==-1)){
			if (t->sr !=NULL) t->sr =addNODE2_T2(t->sr, t2, r);
			else t->sr =createNODE2_T2(t2);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_T2* fillNODE2_T2withNODE_T2(NODE2_T2* t, NODE_T2* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T2* temp=l;
	while(temp!=NULL){
		t =addNODE2_T2(t, temp->t, r);
		temp=temp->next;
	}
	freeNODE_T2(l);
	return t;
}

void writeinfileNODE2_T2(FILE* o, NODE2_T2* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_T2(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->t.id, t->t.minimal, t->t.maximal, t->t.average);
		writeinfileNODE2_T2(o, t->sr);
	}
	
}

/*
------------------------------------------
MODE 3
------------------------------------------
*/

void freetreeNODE2_T3(NODE2_T3* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_T3(t->sl);
		freetreeNODE2_T3(t->sr);
		free(t);
	}
}

NODE2_T3* createNODE2_T3(MEASURE_T3 t3){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_T3* t =malloc(sizeof(NODE2_T3));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->m=t3;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_T3* addNODE2_T3(NODE2_T3* t, MEASURE_T3 t3, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_T3(t3);
	}else{
		if(r* (t->m.id) > r*(t3.id)){
			if (t->sl !=NULL) t->sl =addNODE2_T3(t->sl, t3, r);
			else t->sl =createNODE2_T3(t3);
		} else if(r* (t->m.id) < r*(t3.id)){
			if (t->sr !=NULL) t->sr =addNODE2_T3(t->sr, t3, r);
			else t->sr =createNODE2_T3(t3);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_T3* fillNODE2_T3withNODE_T3(NODE2_T3* t, NODE_T3* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T3* temp=l;
	while(temp!=NULL){
		t =addNODE2_T3(t, temp->m, r);
		temp=temp->next;
	}
	freeNODE_T3(l);
	return t;
}

void writeinfileNODE2_T3(FILE* o, NODE2_T3* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_T3(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->m.id, t->m.minimal, t->m.maximal, t->m.average);
		writeinfileNODE2_T3(o, t->sr);
	}
	
}

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

void freetreeNODE2_P1(NODE2_P1* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_P1(t->sl);
		freetreeNODE2_P1(t->sr);
		free(t);
	}
}

NODE2_P1* createNODE2_P1(STATION_P1 p1){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_P1* t =malloc(sizeof(NODE2_P1));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->s=p1;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_P1* addNODE2_P1(NODE2_P1* t, STATION_P1 p1, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_P1(p1);
	}else{
		if(r* (t->s.id) > r*(p1.id)){
			if (t->sl !=NULL) t->sl =addNODE2_P1(t->sl, p1, r);
			else t->sl =createNODE2_P1(p1);
		} else if(r* (t->s.id) < r*(p1.id)){
			if (t->sr !=NULL) t->sr =addNODE2_P1(t->sr, p1, r);
			else t->sr =createNODE2_P1(p1);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_P1* fillNODE2_P1withNODE_P1(NODE2_P1* t, NODE_P1* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P1* temp=l;
	while(temp!=NULL){
		t =addNODE2_P1(t, temp->s, r);
		temp=temp->next;
	}
	freeNODE_P1(l);
	return t;
}

void writeinfileNODE2_P1(FILE* o, NODE2_P1* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_P1(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
		writeinfileNODE2_P1(o, t->sr);
	}
	
}

/*
------------------------------------------
MODE 2
------------------------------------------
*/

void freetreeNODE2_P2(NODE2_P2* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_P2(t->sl);
		freetreeNODE2_P2(t->sr);
		free(t);
	}
}

NODE2_P2* createNODE2_P2(TIME_P2 p2){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_P2* t =malloc(sizeof(NODE2_P2));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->t=p2;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_P2* addNODE2_P2(NODE2_P2* t, TIME_P2 p2, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_P2(p2);
	}else{
		if(r* (t->t.id) > r*(p2.id)){
			if (t->sl !=NULL) t->sl =addNODE2_P2(t->sl, p2, r);
			else t->sl =createNODE2_P2(p2);
		} else if(r* (t->t.id) < r*(p2.id)){
			if (t->sr !=NULL) t->sr =addNODE2_P2(t->sr, p2, r);
			else t->sr =createNODE2_P2(p2);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_P2* fillNODE2_P2withNODE_P2(NODE2_P2* t, NODE_P2* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P2* temp=l;
	while(temp!=NULL){
		t =addNODE2_P2(t, temp->t, r);
		temp=temp->next;
	}
	freeNODE_P2(l);
	return t;
}

void writeinfileNODE2_P2(FILE* o, NODE2_P2* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_P2(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->t.id, t->t.minimal, t->t.maximal, t->t.average);
		writeinfileNODE2_P2(o, t->sr);
	}
	
}

/*
------------------------------------------
MODE 3
------------------------------------------
*/

void freetreeNODE2_P3(NODE2_P3* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_P3(t->sl);
		freetreeNODE2_P3(t->sr);
		free(t);
	}
}

NODE2_P3* createNODE2_P3(MEASURE_P3 p3){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_P3* t =malloc(sizeof(NODE2_P3));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->m=p3;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_P3* addNODE2_P3(NODE2_P3* t, MEASURE_P3 p3, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_P3(p3);
	}else{
		if(r* (t->m.id) > r*(p3.id)){
			if (t->sl !=NULL) t->sl =addNODE2_P3(t->sl, p3, r);
			else t->sl =createNODE2_P3(p3);
		} else if(r* (t->m.id) < r*(p3.id)){
			if (t->sr !=NULL) t->sr =addNODE2_P3(t->sr, p3, r);
			else t->sr =createNODE2_P3(p3);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_P3* fillNODE2_P3withNODE_P3(NODE2_P3* t, NODE_P3* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P3* temp=l;
	while(temp!=NULL){
		t =addNODE2_P3(t, temp->m, r);
		temp=temp->next;
	}
	freeNODE_P3(l);
	return t;
}

void writeinfileNODE2_P3(FILE* o, NODE2_P3* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_P3(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->m.id, t->m.minimal, t->m.maximal, t->m.average);
		writeinfileNODE2_P3(o, t->sr);
	}
	
}

/*
------------------------------------------
WIND FUNCTIONS
------------------------------------------
*/

void freetreeNODE2_W(NODE2_W* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_W(t->sl);
		freetreeNODE2_W(t->sr);
		free(t);
	}
}

NODE2_W* createNODE2_W(STATION_W w){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_W* t =malloc(sizeof(NODE2_W));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->s=w;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_W* addNODE2_W(NODE2_W* t, STATION_W w, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_W(w);
	}else{
		if(r* (t->s.id) > r*(w.id)){
			if (t->sl !=NULL) t->sl =addNODE2_W(t->sl, w, r);
			else t->sl =createNODE2_W(w);
		} else if(r* (t->s.id) < r*(w.id)){
			if (t->sr !=NULL) t->sr =addNODE2_W(t->sr, w, r);
			else t->sr =createNODE2_W(w);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_W* fillNODE2_WwithNODE_W(NODE2_W* t, NODE_W* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_W* temp=l;
	while(temp!=NULL){
		t =addNODE2_W(t, temp->s, r);
		temp=temp->next;
	}
	freeNODE_W(l);
	return t;
}

void writeinfileNODE2_W(FILE* o, NODE2_W* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_W(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
		writeinfileNODE2_W(o, t->sr);
	}
	
}

/*
------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------
*/

void freetreeNODE2_H(NODE2_H* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_H(t->sl);
		freetreeNODE2_H(t->sr);
		free(t);
	}
}

NODE2_H* createNODE2_H(STATION_H h){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_H* t =malloc(sizeof(NODE2_H));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->s=h;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_H* addNODE2_H(NODE2_H* t, STATION_H h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_H(h);
	}else{
		if(r* (t->s.id) > r*(h.id)){
			if (t->sl !=NULL) t->sl =addNODE2_H(t->sl, h, r);
			else t->sl =createNODE2_H(h);
		} else if(r* (t->s.id) < r*(h.id)){
			if (t->sr !=NULL) t->sr =addNODE2_H(t->sr, h, r);
			else t->sr =createNODE2_H(h);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_H* fillNODE2_HwithNODE_H(NODE2_H* t, NODE_H* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_H* temp=l;
	while(temp!=NULL){
		t =addNODE2_H(t, temp->s, r);
		temp=temp->next;
	}
	freeNODE_H(l);
	return t;
}

void writeinfileNODE2_H(FILE* o, NODE2_H* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_H(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
		writeinfileNODE2_H(o, t->sr);
	}
	
}

/*
------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------
*/

void freetreeNODE2_M(NODE2_M* t){
	// Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_M(t->sl);
		freetreeNODE2_M(t->sr);
		free(t);
	}
}

NODE2_M* createNODE2_M(STATION_M m){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_M* t =malloc(sizeof(NODE2_M));
	if(t ==NULL){
		printf("in create : erreur de malloc\n");
		exit(4);
	}
	t->s=m;
	t->sl=NULL;
	t->sr=NULL;
	return t;
}

NODE2_M* addNODE2_M(NODE2_M* t, STATION_M m, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createNODE2_M(m);
	}else{
		if(r* (t->s.id) > r*(m.id)){
			if (t->sl !=NULL) t->sl =addNODE2_M(t->sl, m, r);
			else t->sl =createNODE2_M(m);
		} else if(r* (t->s.id) < r*(m.id)){
			if (t->sr !=NULL) t->sr =addNODE2_M(t->sr, m, r);
			else t->sr =createNODE2_M(m);
		} else {
			return t;
		}
	}
	return t;
}

NODE2_M* fillNODE2_MwithNODE_M(NODE2_M* t, NODE_M* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_M* temp=l;
	while(temp!=NULL){
		t =addNODE2_M(t, temp->s, r);
		temp=temp->next;
	}
	freeNODE_M(l);
	return t;
}

void writeinfileNODE2_M(FILE* o, NODE2_M* t){
	// Each element of the tree is written in the output file.
	// Format : "Station ID;minimal pressure;maximal pressure;average pression".
	// Since the station ID is sorted as an int, we need to add a 0 before the ID when it is lower than 9999, or else for example 09999 is going to be written as 9999.
	// The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
	if(t!=NULL){
		writeinfileNODE2_M(o, t->sl);
		fprintf(o, "0%d;%f;%f;%f\n", t->s.id, t->s.minimal, t->s.maximal, t->s.average);
		writeinfileNODE2_M(o, t->sr);
	}
	
}

/*


int main(){
	NODE2_T1* testt=NULL;
	FILE* f=fopen("test.csv", "r");
	if(f ==NULL){
		printf("Can't open the file f\n");
		exit(1); //à changer
	}

	NODE_T1* testl=linkedlist_T1(f);

	FILE* o=fopen("temp.csv", "w");
	if(o ==NULL){
		printf("Can't open the file o\n");
		exit(1); //à changer
	}

	testt =fillNODE2_T1withNODE_T1(testt,testl, -1);
	fprintf(o,"Station ID;minimal pressure;maximal pressure;average pressure\n");
	writeinfileNODE2_T1(o, testt);
	freetreeNODE2_T1(testt);
	fclose(o);
	fclose(f);
	return 0;
}

*/







































