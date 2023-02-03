 #ifndef SHARED
	#define SHARED 1
	#include "shared.c"
#endif

#ifndef HEADERABR
	#define HEADERABR 1
	#include "abr.h"
#endif

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

void freetreeABR_NODE2_T1(ABR_NODE2_T1* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_T1(t->sl);
		freetreeABR_NODE2_T1(t->sr);
		free(t);
	}
}

ABR_NODE2_T1* createABR_NODE2_T1(STATION_T1 t1){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_T1* t =malloc(sizeof(ABR_NODE2_T1));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=t1;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}




ABR_NODE2_T1* addABR_NODE2_T1(ABR_NODE2_T1* t, STATION_T1 t1, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createABR_NODE2_T1(t1);
	}else{
		if(r* (t->s.id) > r*(t1.id)){

			if (t->sl !=NULL) t->sl =addABR_NODE2_T1(t->sl, t1, r);
			else t->sl =createABR_NODE2_T1(t1);
		} else if(r* (t->s.id) < r*(t1.id)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_T1(t->sr, t1, r);
			else t->sr =createABR_NODE2_T1(t1);
		} else {
			return t;
		}
	}
	return t;
}

ABR_NODE2_T1* fillABR_NODE2_T1withNODE_T1(ABR_NODE2_T1* t, NODE_T1* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T1* temp=l;
	while(temp!=NULL){
		t =addABR_NODE2_T1(t, temp->s, r);
		temp=temp->next;
	}
	freeNODE_T1(l);
	return t;
}

void writeinfileABR_NODE2_T1(FILE* o, ABR_NODE2_T1* t){
	// Each element of the tree is written in the output file.
	// Format : "Id minimal_temperature maximal_temperature average_temperature".
	// The static list is freed at the end.
	if(t!=NULL){
		writeinfileABR_NODE2_T1(o, t->sl);
		fprintf(o,"%d %f %f %f\n",t->s.id,t->s.minimal,t->s.maximal,t->s.average);
		writeinfileABR_NODE2_T1(o, t->sr);
	}
	
}

int ABR_sort_T1(FILE* f, FILE* o, int r){
	ABR_NODE2_T1* T_T1=NULL;
	NODE_T1* l_T1=linkedlist_T1(f);

	T_T1 =fillABR_NODE2_T1withNODE_T1(T_T1,l_T1, r);
	fprintf(o,"# Id minimal_temperature maximal_temperature average_temperature\n");
	writeinfileABR_NODE2_T1(o, T_T1);
	freetreeABR_NODE2_T1(T_T1);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MODE 2
------------------------------------------
*/

void freetreeABR_NODE2_T2(ABR_NODE2_T2* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_T2(t->sl);
		freetreeABR_NODE2_T2(t->sr);
		free(t);
	}
}

ABR_NODE2_T2* createABR_NODE2_T2(TIME_T2 t2){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_T2* t =malloc(sizeof(ABR_NODE2_T2));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->t=t2;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}


ABR_NODE2_T2* addABR_NODE2_T2(ABR_NODE2_T2* t, TIME_T2 t2,  int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createABR_NODE2_T2(t2);
	}else{
		if((chronologicalorder_T2(t2, t->t) ==1 && r==1) || (chronologicalorder_T2(t2, t->t) ==0 && r==-1)){
			if (t->sl !=NULL) t->sl =addABR_NODE2_T2(t->sl, t2, r);
			else t->sl =createABR_NODE2_T2(t2);
		} else if((chronologicalorder_T2(t->t, t2) ==1 && r==1) || (chronologicalorder_T2(t->t, t2) ==0 && r==-1)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_T2(t->sr, t2, r);
			else t->sr =createABR_NODE2_T2(t2);
		} else {
			return t;
		}
	}
	return t;
}

ABR_NODE2_T2* fillABR_NODE2_T2withNODE_T2(ABR_NODE2_T2* t, NODE_T2* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T2* temp=l;
	while(temp!=NULL){
		t =addABR_NODE2_T2(t, temp->t,  r);
		temp=temp->next;
	}
	freeNODE_T2(l);
	return t;
}

void writeinfileABR_NODE2_T2(FILE* o, ABR_NODE2_T2* t){
	// Each element of the tree is written in the output file.
	// Format : "date average_temperature".
	// The static list is freed at the end.
	if(t!=NULL){
		writeinfileABR_NODE2_T2(o, t->sl);
		producestring_T2(o, t->t);
		writeinfileABR_NODE2_T2(o, t->sr);
	}
}

int ABR_sort_T2(FILE* f, FILE* o, int r){

	ABR_NODE2_T2* T_T2=NULL;
	NODE_T2* l_T2=linkedlist_T2(f);

	T_T2 =fillABR_NODE2_T2withNODE_T2(T_T2,l_T2, r);
	fprintf(o,"# Date average_temperature\n");
	writeinfileABR_NODE2_T2(o, T_T2);
	freetreeABR_NODE2_T2(T_T2);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MODE 3
------------------------------------------
*/

void freetreeABR_NODE2_T3(ABR_NODE2_T3* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_T3(t->sl);
		freetreeABR_NODE2_T3(t->sr);
		free(t);
	}
}

ABR_NODE2_T3* createABR_NODE2_T3(MEASURE_T3 m3){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_T3* t =malloc(sizeof(ABR_NODE2_T3));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->m=m3;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}


ABR_NODE2_T3* addABR_NODE2_T3(ABR_NODE2_T3* t, MEASURE_T3 t3,  int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createABR_NODE2_T3(t3);
	}else{
		if((chronologicalorder_T3(t3, t->m) ==1 && r==1) || (chronologicalorder_T3(t3, t->m) ==0 && r==-1)){
			if (t->sl !=NULL) t->sl =addABR_NODE2_T3(t->sl, t3, r);
			else t->sl =createABR_NODE2_T3(t3);
		} else if((chronologicalorder_T3(t->m, t3) ==1 && r==1) || (chronologicalorder_T3(t->m, t3) ==0 && r==-1)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_T3(t->sr, t3, r);
			else t->sr =createABR_NODE2_T3(t3);
		} else {
			if(r* (t->m.id) > r*(t3.id)){
				if (t->sl !=NULL) t->sl =addABR_NODE2_T3(t->sl, t3, r);
				else t->sl =createABR_NODE2_T3(t3);
			} else if(r* (t->m.id) < r*(t3.id)) {
				if (t->sr !=NULL) t->sr =addABR_NODE2_T3(t->sr, t3, r);
				else t->sr =createABR_NODE2_T3(t3);
			} else {
				return t;
			}
		}
	}
	return t;
}

ABR_NODE2_T3* fillABR_NODE2_T3withNODE_T3(ABR_NODE2_T3* t, NODE_T3* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T3* temp=l;
	
	while(temp!=NULL){
		t =addABR_NODE2_T3(t, temp->m,  r);
		temp=temp->next;
	}
	freeNODE_T3(l);
	return t;
}


ABR_NODE2_T3* ABR_getthegreatestvalueT(ABR_NODE2_T3* t){
	if (t!=0){
		if(t->sr!=NULL){
			return ABR_getthegreatestvalueT(t->sr);
		}
		else return t;
	}
	return createABR_NODE2_T3(addNODE_T3(NULL, 0, 0, 0, 0, 0, 0)->m);
}

void writeinfileABR_NODE2_T3(FILE* o, ABR_NODE2_T3* t, MEASURE_T3 old_m){
	// Each element of the tree is written in the output file.
	// Format : "day ID temperature hours".
	if(t!=NULL){
		writeinfileABR_NODE2_T3(o, t->sl, (ABR_getthegreatestvalueT(t->sl))->m);
		if(t->sl ==NULL) producestring_T3(o, t->m, ABR_getthegreatestvalueT(t->sl)->m);
		else producestring_T3(o, t->m, old_m);
		if(t->sr!=NULL){
			if(t->sr->sl==NULL) writeinfileABR_NODE2_T3(o, t->sr, t->m);
			else {
				writeinfileABR_NODE2_T3(o, t->sr, ABR_getthegreatestvalueT(t->sr->sl)->m);
			}
		}
	}
}

int ABR_sort_T3(FILE* f, FILE* o, int r){

	ABR_NODE2_T3* T_T3=NULL;
	NODE_T3* l_T3=linkedlist_T3(f);

	T_T3 =fillABR_NODE2_T3withNODE_T3(T_T3,l_T3, r);
	fprintf(o,"# Day ID temperature hours\n");
	writeinfileABR_NODE2_T3(o, T_T3, addNODE_T3(NULL, 0, 0, 0, 0, 0, 0)->m);
	freetreeABR_NODE2_T3(T_T3);
	fclose(o);

	return 0;
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

void freetreeABR_NODE2_P1(ABR_NODE2_P1* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_P1(t->sl);
		freetreeABR_NODE2_P1(t->sr);
		free(t);
	}
}

ABR_NODE2_P1* createABR_NODE2_P1(STATION_P1 p1){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_P1* t =malloc(sizeof(ABR_NODE2_P1));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=p1;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}

ABR_NODE2_P1* addABR_NODE2_P1(ABR_NODE2_P1* t, STATION_P1 p1, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createABR_NODE2_P1(p1);
	}else{
		if(r* (t->s.id) > r*(p1.id)){
			if (t->sl !=NULL) t->sl =addABR_NODE2_P1(t->sl, p1, r);
			else t->sl =createABR_NODE2_P1(p1);
		} else if(r* (t->s.id) < r*(p1.id)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_P1(t->sr, p1, r);
			else t->sr =createABR_NODE2_P1(p1);
		} else {
			return t;
		}
	}
	return t;
}

ABR_NODE2_P1* fillABR_NODE2_P1withNODE_P1(ABR_NODE2_P1* t, NODE_P1* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P1* temp=l;
	
	while(temp!=NULL){
		t =addABR_NODE2_P1(t, temp->s,  r);
		temp=temp->next;
	}
	freeNODE_P1(l);
	return t;
}

void writeinfileABR_NODE2_P1(FILE* o, ABR_NODE2_P1* t){
	// Each element of the tree is written in the output file.
	// Format : "Id minimal_pressure maximal_pressure average_pressure".
	// The static list is freed at the end.
	if(t!=NULL){
		writeinfileABR_NODE2_P1(o, t->sl);
		fprintf(o,"%d %f %f %f\n",t->s.id,t->s.minimal,t->s.maximal,t->s.average);
		writeinfileABR_NODE2_P1(o, t->sr);
	}
}

int ABR_sort_P1(FILE* f, FILE* o, int r){
	ABR_NODE2_P1* T_P1=NULL;
	NODE_P1* l_P1=linkedlist_P1(f);

	T_P1 =fillABR_NODE2_P1withNODE_P1(T_P1,l_P1, r);
	fprintf(o,"# Id minimal_pressure maximal_pressure average_pressure\n");
	writeinfileABR_NODE2_P1(o, T_P1);
	freetreeABR_NODE2_P1(T_P1);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MODE 2
------------------------------------------
*/

void freetreeABR_NODE2_P2(ABR_NODE2_P2* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_P2(t->sl);
		freetreeABR_NODE2_P2(t->sr);
		free(t);
	}
}

ABR_NODE2_P2* createABR_NODE2_P2(TIME_P2 p2){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_P2* t =malloc(sizeof(ABR_NODE2_P2));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->t=p2;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}


ABR_NODE2_P2* addABR_NODE2_P2(ABR_NODE2_P2* t, TIME_P2 p2,  int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createABR_NODE2_P2(p2);
	}else{
		if((chronologicalorder_P2(p2, t->t) ==1 && r==1) || (chronologicalorder_P2(p2, t->t) ==0 && r==-1)){
			if (t->sl !=NULL) t->sl =addABR_NODE2_P2(t->sl, p2, r);
			else t->sl =createABR_NODE2_P2(p2);
		} else if((chronologicalorder_P2(t->t, p2) ==1 && r==1) || (chronologicalorder_P2(t->t, p2) ==0 && r==-1)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_P2(t->sr, p2, r);
			else t->sr =createABR_NODE2_P2(p2);
		} else {
			return t;
		}
	}
	return t;
}

ABR_NODE2_P2* fillABR_NODE2_P2withNODE_P2(ABR_NODE2_P2* t, NODE_P2* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P2* temp=l;
	
	while(temp!=NULL){
		t =addABR_NODE2_P2(t, temp->t,  r);
		temp=temp->next;
	}
	freeNODE_P2(l);
	return t;
}

void writeinfileABR_NODE2_P2(FILE* o, ABR_NODE2_P2* t){
	// Each element of the tree is written in the output file.
	// Format : "date average_pressure".
	// The static list is freed at the end.
	if(t!=NULL){
		writeinfileABR_NODE2_P2(o, t->sl);
		producestring_P2(o, t->t);
		writeinfileABR_NODE2_P2(o, t->sr);
	}
}

int ABR_sort_P2(FILE* f, FILE* o, int r){
	ABR_NODE2_P2* T_P2=NULL;
	NODE_P2* l_P2=linkedlist_P2(f);

	T_P2 =fillABR_NODE2_P2withNODE_P2(T_P2,l_P2, r);
	fprintf(o,"# Date average_pressure\n");
	writeinfileABR_NODE2_P2(o, T_P2);
	freetreeABR_NODE2_P2(T_P2);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MODE 3
------------------------------------------
*/

void freetreeABR_NODE2_P3(ABR_NODE2_P3* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_P3(t->sl);
		freetreeABR_NODE2_P3(t->sr);
		free(t);
	}
}

ABR_NODE2_P3* createABR_NODE2_P3(MEASURE_P3 m3){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_P3* t =malloc(sizeof(ABR_NODE2_P3));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->m=m3;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}


ABR_NODE2_P3* addABR_NODE2_P3(ABR_NODE2_P3* t, MEASURE_P3 p3,  int r){
	//A new node is added to the tree, and sorted.
	//printf("SIUUUUUUU\n");
	if(t==NULL){
		return createABR_NODE2_P3(p3);
	}else{
		if((chronologicalorder_P3(p3, t->m) ==1 && r==1) || (chronologicalorder_P3(p3, t->m) ==0 && r==-1)){
			if (t->sl !=NULL) t->sl =addABR_NODE2_P3(t->sl, p3, r);
			else t->sl =createABR_NODE2_P3(p3);
		} else if((chronologicalorder_P3(t->m, p3) ==1 && r==1) || (chronologicalorder_P3(t->m, p3) ==0 && r==-1)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_P3(t->sr, p3, r);
			else t->sr =createABR_NODE2_P3(p3);
		} else {
			if(r* (t->m.id) > r*(p3.id)){
				if (t->sl !=NULL) t->sl =addABR_NODE2_P3(t->sl, p3, r);
				else t->sl =createABR_NODE2_P3(p3);
			} else if(r* (t->m.id) < r*(p3.id)) {
				if (t->sr !=NULL) t->sr =addABR_NODE2_P3(t->sr, p3, r);
				else t->sr =createABR_NODE2_P3(p3);
			} else {
				return t;
			}
		}
	}
	return t;
}

ABR_NODE2_P3* fillABR_NODE2_P3withNODE_P3(ABR_NODE2_P3* t, NODE_P3* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P3* temp=l;
	
	while(temp!=NULL){
		t =addABR_NODE2_P3(t, temp->m,  r);
		temp=temp->next;
	}
	freeNODE_P3(l);
	return t;
}

ABR_NODE2_P3* ABR_getthegreatestvalueP(ABR_NODE2_P3* t){
	if (t!=0){
		if(t->sr!=NULL){
			return ABR_getthegreatestvalueP(t->sr);
		}
		else return t;
	}
	return createABR_NODE2_P3(addNODE_P3(NULL, 0, 0, 0, 0, 0, 0)->m);
}

void writeinfileABR_NODE2_P3(FILE* o, ABR_NODE2_P3* t, MEASURE_P3 old_m){
	// Each element of the tree is written in the output file.
	// Format : "day ID temperature hours".
	if(t!=NULL){
		writeinfileABR_NODE2_P3(o, t->sl, (ABR_getthegreatestvalueP(t->sl))->m);
		if(t->sl ==NULL) producestring_P3(o, t->m, ABR_getthegreatestvalueP(t->sl)->m);
		else producestring_P3(o, t->m, old_m);
		if(t->sr!=NULL){
			if(t->sr->sl==NULL) writeinfileABR_NODE2_P3(o, t->sr, t->m);
			else {
				writeinfileABR_NODE2_P3(o, t->sr, ABR_getthegreatestvalueP(t->sr->sl)->m);
			}
		}
	}
}

int ABR_sort_P3(FILE* f, FILE* o, int r){
	ABR_NODE2_P3* T_P3=NULL;
	NODE_P3* l_P3=linkedlist_P3(f);

	T_P3 =fillABR_NODE2_P3withNODE_P3(T_P3,l_P3, r);
	fprintf(o,"# Day ID temperature hours\n");
	writeinfileABR_NODE2_P3(o, T_P3, addNODE_P3(NULL, 0, 0, 0, 0, 0, 0)->m);
	freetreeABR_NODE2_P3(T_P3);
	fclose(o);

	return 0;
}

/*
------------------------------------------
WIND FUNCTIONS
------------------------------------------
*/

void freetreeABR_NODE2_W(ABR_NODE2_W* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_W(t->sl);
		freetreeABR_NODE2_W(t->sr);
		free(t);
	}
}

ABR_NODE2_W* createABR_NODE2_W(STATION_W w){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_W* t =malloc(sizeof(ABR_NODE2_W));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=w;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}


ABR_NODE2_W* addABR_NODE2_W(ABR_NODE2_W* t, STATION_W w, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createABR_NODE2_W(w);
	}else{
		if(r* (t->s.id) > r*(w.id)){
			if (t->sl !=NULL) t->sl =addABR_NODE2_W(t->sl, w, r);
			else t->sl =createABR_NODE2_W(w);
		} else if(r* (t->s.id) < r*(w.id)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_W(t->sr, w, r);
			else t->sr =createABR_NODE2_W(w);
		} else {
			return t;
		}
	}
	return t;
}

ABR_NODE2_W* fillABR_NODE2_WwithNODE_W(ABR_NODE2_W* t, NODE_W* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_W* temp=l;
	
	while(temp!=NULL){
		t =addABR_NODE2_W(t, temp->s,  r);
		temp=temp->next;
	}
	freeNODE_W(l);
	return t;
}

void writeinfileABR_NODE2_W(FILE* o, ABR_NODE2_W* t){
	// Each element of the tree is written in the output file.
	// Format : "longitude latitude rayon degré".
	// The static list is freed at the end.
	float lat;
	float lon;
	if(t!=NULL){
		coordonate(t->s.id, &lat, &lon);
		writeinfileABR_NODE2_W(o, t->sl);
		fprintf(o,"%f %f %d %f\n",lon,lat,t->s.speed,t->s.orientation);
		writeinfileABR_NODE2_W(o, t->sr);
	}
	
}

int ABR_sort_W(FILE* f, FILE* o, int r){
	ABR_NODE2_W* T_W=NULL;
	NODE_W* l_W=linkedlist_W(f);

	T_W =fillABR_NODE2_WwithNODE_W(T_W,l_W, r);
	fprintf(o,"# Longitude latitude rayon degré\n");
	writeinfileABR_NODE2_W(o, T_W);
	freetreeABR_NODE2_W(T_W);
	fclose(o);

	fclose(f);

	return 0;
}

/*
------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------
*/

void freetreeABR_NODE2_H(ABR_NODE2_H* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_H(t->sl);
		freetreeABR_NODE2_H(t->sr);
		free(t);
	}
}

ABR_NODE2_H* createABR_NODE2_H(STATION_H h){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_H* t =malloc(sizeof(ABR_NODE2_H));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=h;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}


ABR_NODE2_H* addABR_NODE2_H(ABR_NODE2_H* t, STATION_H h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createABR_NODE2_H(h);
	}else{
		if(r* (t->s.id) > r*(h.id)){
			if (t->sl !=NULL) t->sl =addABR_NODE2_H(t->sl, h, r);
			else t->sl =createABR_NODE2_H(h);
		} else if(r* (t->s.id) < r*(h.id)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_H(t->sr, h, r);
			else t->sr =createABR_NODE2_H(h);
		} else {
			return t;
		}
	}
	return t;
}

ABR_NODE2_H* fillABR_NODE2_HwithNODE_H(ABR_NODE2_H* t, NODE_H* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_H* temp=l;
	
	while(temp!=NULL){
		t =addABR_NODE2_H(t, temp->s,  r);
		temp=temp->next;
	}
	freeNODE_H(l);
	return t;
}

void writeinfileABR_NODE2_H(FILE* o, ABR_NODE2_H* t){
	// Each element of the tree is written in the output file.
	// Format : "longitude latitude height".
	// The static list is freed at the end.
	float lat;
	float lon;
	if(t!=NULL){
		coordonate(t->s.id, &lat, &lon);
		writeinfileABR_NODE2_H(o, t->sl);
		fprintf(o,"%f %f %d\n",lon,lat,t->s.height);
		writeinfileABR_NODE2_H(o, t->sr);
	}
	
}

int ABR_sort_H(FILE* f, FILE* o, int r){
	ABR_NODE2_H* T_H=NULL;
	NODE_H* l_H=linkedlist_H(f);

	T_H =fillABR_NODE2_HwithNODE_H(T_H,l_H, r);
	fprintf(o,"# Longitude latitude height\n");
	writeinfileABR_NODE2_H(o, T_H);
	freetreeABR_NODE2_H(T_H);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------
*/

void freetreeABR_NODE2_M(ABR_NODE2_M* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeABR_NODE2_M(t->sl);
		freetreeABR_NODE2_M(t->sr);
		free(t);
	}
}

ABR_NODE2_M* createABR_NODE2_M(STATION_M m){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	ABR_NODE2_M* t =malloc(sizeof(ABR_NODE2_M));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=m;
	t->sl=NULL;
	t->sr=NULL;
	
	return t;
}


ABR_NODE2_M* addABR_NODE2_M(ABR_NODE2_M* t, STATION_M m, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		return createABR_NODE2_M(m);
	}else{
		if(r* (t->s.id) > r*(m.id)){
			if (t->sl !=NULL) t->sl =addABR_NODE2_M(t->sl, m, r);
			else t->sl =createABR_NODE2_M(m);
		} else if(r* (t->s.id) < r*(m.id)){
			if (t->sr !=NULL) t->sr =addABR_NODE2_M(t->sr, m, r);
			else t->sr =createABR_NODE2_M(m);
		} else {
			return t;
		}
	}
	return t;
}

ABR_NODE2_M* fillABR_NODE2_MwithNODE_M(ABR_NODE2_M* t, NODE_M* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_M* temp=l;
	
	while(temp!=NULL){
		t =addABR_NODE2_M(t, temp->s,  r);
		temp=temp->next;
	}
	freeNODE_M(l);
	return t;
}

void writeinfileABR_NODE2_M(FILE* o, ABR_NODE2_M* t){
	// Each element of the tree is written in the output file.
	// Format : "longitude latitude moisture".
	// The static list is freed at the end.
	float lat;
	float lon;
	if(t!=NULL){
		coordonate(t->s.id, &lat, &lon);
		writeinfileABR_NODE2_M(o, t->sl); 
		fprintf(o,"%f %f %d\n",lon,lat,t->s.maximal);
		writeinfileABR_NODE2_M(o, t->sr);
	}
}

int ABR_sort_M(FILE* f, FILE* o, int r){
	ABR_NODE2_M* T_M=NULL;
	NODE_M* l_M=linkedlist_M(f);

	T_M =fillABR_NODE2_MwithNODE_M(T_M,l_M, r);
	fprintf(o,"# Longitude latitude moisture\n");
	writeinfileABR_NODE2_M(o, T_M);
	freetreeABR_NODE2_M(T_M);
	fclose(o);

	return 0;
}
