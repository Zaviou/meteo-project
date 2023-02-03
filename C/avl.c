#ifndef SHARED
	#define SHARED 1
	#include "shared.c"
#endif

#ifndef HEADERAVL
	#define HEADERAVL 1
	#include "avl.h"
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

void freetreeNODE2_T1(NODE2_T1* t){
	//Each node of the tree needs to be freed individually.
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
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=t1;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_T1* rotateleftNODE2_T1(NODE2_T1* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_T1* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_T1* rotaterightNODE2_T1(NODE2_T1* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_T1* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_T1* doublerotateleftNODE2_T1(NODE2_T1* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_T1(t->sr);
	t=rotateleftNODE2_T1(t);
	return t;
}

NODE2_T1* doublerotaterightNODE2_T1(NODE2_T1* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_T1(t->sl);
	t=rotaterightNODE2_T1(t);
	return t;
}

NODE2_T1* rebalanceNODE2_T1(NODE2_T1* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_T1(t);
		else return doublerotateleftNODE2_T1(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_T1(t);
		else return doublerotaterightNODE2_T1(t);
	}
	return t;
}

NODE2_T1* addNODE2_T1(NODE2_T1* t, STATION_T1 t1, int* h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_T1(t1);
	}else{
		if(r* (t->s.id) > r*(t1.id)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_T1(t->sl, t1, h, r);
			else t->sl =createNODE2_T1(t1);
		} else if(r* (t->s.id) < r*(t1.id)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_T1(t->sr, t1, h, r);
			else t->sr =createNODE2_T1(t1);
		} else {
			*h=0;
			return t;
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_T1(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}
	
	return t;
}

NODE2_T1* fillNODE2_T1withNODE_T1(NODE2_T1* t, NODE_T1* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T1* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_T1(t, temp->s, &h, r);
		temp=temp->next;
	}
	freeNODE_T1(l);
	return t;
}

void writeinfileNODE2_T1(FILE* o, NODE2_T1* t){
	// Each element of the tree is written in the output file.
	// Format : "Id minimal_temperature maximal_temperature average_temperature".
	// The static list is freed at the end.
	if(t!=NULL){
		writeinfileNODE2_T1(o, t->sl);
		fprintf(o,"%d %f %f %f\n",t->s.id,t->s.minimal,t->s.maximal,t->s.average);
		writeinfileNODE2_T1(o, t->sr);
	}
	
}

int sort_T1(FILE* f, FILE* o, int r){
	printf("\nSorting data...");

	NODE2_T1* T_T1=NULL;
	NODE_T1* l_T1=linkedlist_T1(f);

	T_T1 =fillNODE2_T1withNODE_T1(T_T1,l_T1, r);
	fprintf(o,"# Id minimal_temperature maximal_temperature average_temperature\n");
	writeinfileNODE2_T1(o, T_T1);
	freetreeNODE2_T1(T_T1);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MODE 2
------------------------------------------
*/

void freetreeNODE2_T2(NODE2_T2* t){
	//Each node of the tree needs to be freed individually.
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
		printf("erreur de malloc\n");
		exit(4);
	}
	t->t=t2;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_T2* rotateleftNODE2_T2(NODE2_T2* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_T2* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_T2* rotaterightNODE2_T2(NODE2_T2* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_T2* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_T2* doublerotateleftNODE2_T2(NODE2_T2* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_T2(t->sr);
	t=rotateleftNODE2_T2(t);
	return t;
}

NODE2_T2* doublerotaterightNODE2_T2(NODE2_T2* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_T2(t->sl);
	t=rotaterightNODE2_T2(t);
	return t;
}

NODE2_T2* rebalanceNODE2_T2(NODE2_T2* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_T2(t);
		else return doublerotateleftNODE2_T2(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_T2(t);
		else return doublerotaterightNODE2_T2(t);
	}
	return t;
}

NODE2_T2* addNODE2_T2(NODE2_T2* t, TIME_T2 t2, int* h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_T2(t2);
	}else{
		if((chronologicalorder_T2(t2, t->t) ==1 && r==1) || (chronologicalorder_T2(t2, t->t) ==0 && r==-1)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_T2(t->sl, t2, h, r);
			else t->sl =createNODE2_T2(t2);
		} else if((chronologicalorder_T2(t->t, t2) ==1 && r==1) || (chronologicalorder_T2(t->t, t2) ==0 && r==-1)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_T2(t->sr, t2, h, r);
			else t->sr =createNODE2_T2(t2);
		} else {
			*h=0;
			return t;
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_T2(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}
	
	return t;
}

NODE2_T2* fillNODE2_T2withNODE_T2(NODE2_T2* t, NODE_T2* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T2* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_T2(t, temp->t, &h, r);
		temp=temp->next;
	}
	freeNODE_T2(l);
	return t;
}

void writeinfileNODE2_T2(FILE* o, NODE2_T2* t){
	// Each element of the tree is written in the output file.
	// Format : "date average_temperature".
	// The static list is freed at the end.
	if(t!=NULL){
		writeinfileNODE2_T2(o, t->sl);
		producestring_T2(o, t->t);
		writeinfileNODE2_T2(o, t->sr);
	}
}

int sort_T2(FILE* f, FILE* o, int r){
	printf("\nSorting data...\n");
	printf("sort_T2 : début !\n");

	NODE2_T2* T_T2=NULL;
	NODE_T2* l_T2=linkedlist_T2(f);
	printf("sort_T2 : initialisation faite !\n");

	T_T2 =fillNODE2_T2withNODE_T2(T_T2,l_T2, r);
	fprintf(o,"# Date average_temperature\n");
	writeinfileNODE2_T2(o, T_T2);
	freetreeNODE2_T2(T_T2);
	fclose(o);

	printf("sort_T2 : fin !\n");
	return 0;
}

/*
------------------------------------------
MODE 3
------------------------------------------
*/

void freetreeNODE2_T3(NODE2_T3* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_T3(t->sl);
		freetreeNODE2_T3(t->sr);
		free(t);
	}
}

NODE2_T3* createNODE2_T3(MEASURE_T3 m3){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_T3* t =malloc(sizeof(NODE2_T3));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->m=m3;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_T3* rotateleftNODE2_T3(NODE2_T3* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_T3* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_T3* rotaterightNODE2_T3(NODE2_T3* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_T3* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_T3* doublerotateleftNODE2_T3(NODE2_T3* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_T3(t->sr);
	t=rotateleftNODE2_T3(t);
	return t;
}

NODE2_T3* doublerotaterightNODE2_T3(NODE2_T3* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_T3(t->sl);
	t=rotaterightNODE2_T3(t);
	return t;
}

NODE2_T3* rebalanceNODE2_T3(NODE2_T3* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_T3(t);
		else return doublerotateleftNODE2_T3(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_T3(t);
		else return doublerotaterightNODE2_T3(t);
	}
	return t;
}

NODE2_T3* addNODE2_T3(NODE2_T3* t, MEASURE_T3 m3, int* h, int r){
	//printf("m3.id : %d\n", m3.id);
	//printf("addNODE2_T3 : début !\n");
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_T3(m3);
	}else{
		if((chronologicalorder_T3(m3, t->m) ==1 && r==1) || (chronologicalorder_T3(m3, t->m) ==0 && r==-1)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_T3(t->sl, m3, h, r);
			else t->sl =createNODE2_T3(m3);
		} else if((chronologicalorder_T3(t->m, m3) ==1 && r==1) || (chronologicalorder_T3(t->m, m3) ==0 && r==-1)){
			if (r ==1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_T3(t->sr, m3, h, r);
			else t->sr =createNODE2_T3(m3);
		} else {
			if(r* (t->m.id) > r*(m3.id)){
				if (r ==1) *h=-*h;
				if (t->sl !=NULL) t->sl =addNODE2_T3(t->sl, m3, h, r);
				else t->sl =createNODE2_T3(m3);
			} else if(r* (t->m.id) < r*(m3.id)) {
				if (r ==1) *h=-*h;
				if (t->sr !=NULL) t->sr =addNODE2_T3(t->sr, m3, h, r);
				else t->sr =createNODE2_T3(m3);
			} else {
				return t;
			}
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_T3(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}

	//printf("addNODE2_T3 : fin !\n");
	return t;
}

NODE2_T3* fillNODE2_T3withNODE_T3(NODE2_T3* t, NODE_T3* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_T3* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_T3(t, temp->m, &h, r);
		temp=temp->next;
	}
	freeNODE_T3(l);
	return t;
}

NODE2_T3* getthegreatestvalueT(NODE2_T3* t){
	if (t!=0){
		if(t->sr!=NULL){
			return getthegreatestvalueT(t->sr);
		}
		else return t;
	}
	return createNODE2_T3(addNODE_T3(NULL, 0, 0, 0, 0, 0, 0)->m);
}

void writeinfileNODE2_T3(FILE* o, NODE2_T3* t, MEASURE_T3 old_m){
	// Each element of the tree is written in the output file.
	// Format : "day ID temperature hours".
	if(t!=NULL){
		writeinfileNODE2_T3(o, t->sl, (getthegreatestvalueT(t->sl))->m);
		if(t->sl ==NULL) producestring_T3(o, t->m, getthegreatestvalueT(t->sl)->m);
		else producestring_T3(o, t->m, old_m);
		if(t->sr!=NULL){
			if(t->sr->sl==NULL) writeinfileNODE2_T3(o, t->sr, t->m);
			else {
				writeinfileNODE2_T3(o, t->sr, getthegreatestvalueT(t->sr->sl)->m);
			}
		}
	}
}

int sort_T3(FILE* f, FILE* o, int r){
	// The static list is freed at the end.
	printf("\nSorting data...\n");

	NODE2_T3* T_T3=NULL;
	NODE_T3* l_T3=linkedlist_T3(f);

	T_T3 =fillNODE2_T3withNODE_T3(T_T3,l_T3, r);
	fprintf(o,"# Day ID temperature hours\n");
	writeinfileNODE2_T3(o, T_T3, addNODE_T3(NULL, 0, 0, 0, 0, 0, 0)->m);
	freetreeNODE2_T3(T_T3);
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

void freetreeNODE2_P1(NODE2_P1* t){
	//Each node of the tree needs to be freed individually.
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
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=p1;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_P1* rotateleftNODE2_P1(NODE2_P1* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_P1* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_P1* rotaterightNODE2_P1(NODE2_P1* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_P1* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_P1* doublerotateleftNODE2_P1(NODE2_P1* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_P1(t->sr);
	t=rotateleftNODE2_P1(t);
	return t;
}

NODE2_P1* doublerotaterightNODE2_P1(NODE2_P1* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_P1(t->sl);
	t=rotaterightNODE2_P1(t);
	return t;
}

NODE2_P1* rebalanceNODE2_P1(NODE2_P1* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_P1(t);
		else return doublerotateleftNODE2_P1(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_P1(t);
		else return doublerotaterightNODE2_P1(t);
	}
	return t;
}

NODE2_P1* addNODE2_P1(NODE2_P1* t, STATION_P1 p1, int* h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_P1(p1);
	}else{
		if(r* (t->s.id) > r*(p1.id)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_P1(t->sl, p1, h, r);
			else t->sl =createNODE2_P1(p1);
		} else if(r* (t->s.id) < r*(p1.id)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_P1(t->sr, p1, h, r);
			else t->sr =createNODE2_P1(p1);
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
	//We transfer the linked list's elements to a tree.
	NODE_P1* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_P1(t, temp->s, &h, r);
		temp=temp->next;
	}
	freeNODE_P1(l);
	return t;
}

void writeinfileNODE2_P1(FILE* o, NODE2_P1* t){
	// Each element of the tree is written in the output file.
	// Format : "Id minimal_pressure maximal_pressure average_pressure".
	// The static list is freed at the end.
	if(t!=NULL){
		writeinfileNODE2_P1(o, t->sl);
		fprintf(o,"%d %f %f %f\n",t->s.id,t->s.minimal,t->s.maximal,t->s.average);
		writeinfileNODE2_P1(o, t->sr);
	}
}

int sort_P1(FILE* f, FILE* o, int r){
	printf("\nSorting data...");

	NODE2_P1* T_P1=NULL;
	NODE_P1* l_P1=linkedlist_P1(f);

	T_P1 =fillNODE2_P1withNODE_P1(T_P1,l_P1, r);
	fprintf(o,"# Id minimal_pressure maximal_pressure average_pressure\n");
	writeinfileNODE2_P1(o, T_P1);
	freetreeNODE2_P1(T_P1);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MODE 2
------------------------------------------
*/

void freetreeNODE2_P2(NODE2_P2* t){
	//Each node of the tree needs to be freed individually.
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
		printf("erreur de malloc\n");
		exit(4);
	}
	t->t=p2;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_P2* rotateleftNODE2_P2(NODE2_P2* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_P2* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_P2* rotaterightNODE2_P2(NODE2_P2* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_P2* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_P2* doublerotateleftNODE2_P2(NODE2_P2* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_P2(t->sr);
	t=rotateleftNODE2_P2(t);
	return t;
}

NODE2_P2* doublerotaterightNODE2_P2(NODE2_P2* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_P2(t->sl);
	t=rotaterightNODE2_P2(t);
	return t;
}

NODE2_P2* rebalanceNODE2_P2(NODE2_P2* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_P2(t);
		else return doublerotateleftNODE2_P2(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_P2(t);
		else return doublerotaterightNODE2_P2(t);
	}
	return t;
}

NODE2_P2* addNODE2_P2(NODE2_P2* t, TIME_P2 p2, int* h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_P2(p2);
	}else{
		if((chronologicalorder_P2(p2, t->t) ==1 && r==1) || (chronologicalorder_P2(p2, t->t) ==0 && r==-1)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_P2(t->sl, p2, h, r);
			else t->sl =createNODE2_P2(p2);
		} else if((chronologicalorder_P2(t->t, p2) ==1 && r==1) || (chronologicalorder_P2(t->t, p2) ==0 && r==-1)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_P2(t->sr, p2, h, r);
			else t->sr =createNODE2_P2(p2);
		} else {
			*h=0;
			return t;
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_P2(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}
	
	return t;
}

NODE2_P2* fillNODE2_P2withNODE_P2(NODE2_P2* t, NODE_P2* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P2* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_P2(t, temp->t, &h, r);
		temp=temp->next;
	}
	freeNODE_P2(l);
	return t;
}

void writeinfileNODE2_P2(FILE* o, NODE2_P2* t){
	// Each element of the tree is written in the output file.
	// Format : "date average_pressure".
	// The static list is freed at the end.
	if(t!=NULL){
		writeinfileNODE2_P2(o, t->sl);
		producestring_P2(o, t->t);
		writeinfileNODE2_P2(o, t->sr);
	}
}

int sort_P2(FILE* f, FILE* o, int r){
	printf("\nSorting data...");

	NODE2_P2* T_P2=NULL;
	NODE_P2* l_P2=linkedlist_P2(f);

	T_P2 =fillNODE2_P2withNODE_P2(T_P2,l_P2, r);
	fprintf(o,"# Date average_pressure\n");
	writeinfileNODE2_P2(o, T_P2);
	freetreeNODE2_P2(T_P2);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MODE 3
------------------------------------------
*/

void freetreeNODE2_P3(NODE2_P3* t){
	//Each node of the tree needs to be freed individually.
	if(t !=NULL){
		freetreeNODE2_P3(t->sl);
		freetreeNODE2_P3(t->sr);
		free(t);
	}
}

NODE2_P3* createNODE2_P3(MEASURE_P3 m3){
	//A new node is created using malloc (we use the freeding function later to not waste memory).
	NODE2_P3* t =malloc(sizeof(NODE2_P3));
	if(t ==NULL){
		printf("erreur de malloc\n");
		exit(4);
	}
	t->m=m3;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_P3* rotateleftNODE2_P3(NODE2_P3* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_P3* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_P3* rotaterightNODE2_P3(NODE2_P3* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_P3* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_P3* doublerotateleftNODE2_P3(NODE2_P3* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_P3(t->sr);
	t=rotateleftNODE2_P3(t);
	return t;
}

NODE2_P3* doublerotaterightNODE2_P3(NODE2_P3* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_P3(t->sl);
	t=rotaterightNODE2_P3(t);
	return t;
}

NODE2_P3* rebalanceNODE2_P3(NODE2_P3* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_P3(t);
		else return doublerotateleftNODE2_P3(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_P3(t);
		else return doublerotaterightNODE2_P3(t);
	}
	return t;
}

NODE2_P3* addNODE2_P3(NODE2_P3* t, MEASURE_P3 m3, int* h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_P3(m3);
	}else{
		if((chronologicalorder_P3(m3, t->m) ==1 && r==1) || (chronologicalorder_P3(m3, t->m) ==0 && r==-1)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_P3(t->sl, m3, h, r);
			else t->sl =createNODE2_P3(m3);
		} else if((chronologicalorder_P3(t->m, m3) ==1 && r==1) || (chronologicalorder_P3(t->m, m3) ==0 && r==-1)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_P3(t->sr, m3, h, r);
			else t->sr =createNODE2_P3(m3);
		} else {
			if(r* (t->m.id) > r*(m3.id)){
				if (r ==-1) *h=-*h;
				if (t->sl !=NULL) t->sl =addNODE2_P3(t->sl, m3, h, r);
				else t->sl =createNODE2_P3(m3);
			} else if (r* (t->m.id) < r*(m3.id)){
				if (r ==-1) *h=-*h;
				if (t->sr !=NULL) t->sr =addNODE2_P3(t->sr, m3, h, r);
				else t->sr =createNODE2_P3(m3);
			} else {
				*h=0;
				return t;
			}
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_P3(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}
	
	return t;
}

NODE2_P3* fillNODE2_P3withNODE_P3(NODE2_P3* t, NODE_P3* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_P3* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_P3(t, temp->m, &h, r);
		temp=temp->next;
	}
	freeNODE_P3(l);
	return t;
}

NODE2_P3* getthegreatestvalueP(NODE2_P3* t){
	if (t!=0){
		if(t->sr!=NULL){
			return getthegreatestvalueP(t->sr);
		}
		else return t;
	}
	return createNODE2_P3(addNODE_P3(NULL, 0, 0, 0, 0, 0, 0)->m);
}

void writeinfileNODE2_P3(FILE* o, NODE2_P3* t, MEASURE_P3 old_m){
	// Each element of the tree is written in the output file.
	// Format : "day ID temperature hours".
	if(t!=NULL){
		writeinfileNODE2_P3(o, t->sl, (getthegreatestvalueT(t->sl))->m);
		if(t->sl ==NULL) producestring_P3(o, t->m, getthegreatestvalueT(t->sl)->m);
		else producestring_P3(o, t->m, old_m);
		if(t->sr!=NULL){
			if(t->sr->sl==NULL) writeinfileNODE2_P3(o, t->sr, t->m);
			else {
				writeinfileNODE2_P3(o, t->sr, getthegreatestvalueT(t->sr->sl)->m);
			}
		}
	}
}

int sort_P3(FILE* f, FILE* o, int r){
	printf("\nSorting data...");

	NODE2_P3* T_P3=NULL;
	NODE_P3* l_P3=linkedlist_P3(f);

	T_P3 =fillNODE2_P3withNODE_P3(T_P3,l_P3, r);
	fprintf(o,"# Day ID temperature hours\n");
	writeinfileNODE2_P3(o, T_P3, addNODE_P3(NULL, 0, 0, 0, 0, 0, 0)->m);
	freetreeNODE2_P3(T_P3);
	fclose(o);

	return 0;
}

/*
------------------------------------------
WIND FUNCTIONS
------------------------------------------
*/

void freetreeNODE2_W(NODE2_W* t){
	//Each node of the tree needs to be freed individually.
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
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=w;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_W* rotateleftNODE2_W(NODE2_W* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_W* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_W* rotaterightNODE2_W(NODE2_W* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_W* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_W* doublerotateleftNODE2_W(NODE2_W* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_W(t->sr);
	t=rotateleftNODE2_W(t);
	return t;
}

NODE2_W* doublerotaterightNODE2_W(NODE2_W* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_W(t->sl);
	t=rotaterightNODE2_W(t);
	return t;
}

NODE2_W* rebalanceNODE2_W(NODE2_W* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_W(t);
		else return doublerotateleftNODE2_W(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_W(t);
		else return doublerotaterightNODE2_W(t);
	}
	return t;
}

NODE2_W* addNODE2_W(NODE2_W* t, STATION_W w, int* h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_W(w);
	}else{
		if(r* (t->s.id) > r*(w.id)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_W(t->sl, w, h, r);
			else t->sl =createNODE2_W(w);
		} else if(r* (t->s.id) < r*(w.id)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_W(t->sr, w, h, r);
			else t->sr =createNODE2_W(w);
		} else {
			*h=0;
			return t;
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_W(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}
	
	return t;
}

NODE2_W* fillNODE2_WwithNODE_W(NODE2_W* t, NODE_W* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_W* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_W(t, temp->s, &h, r);
		temp=temp->next;
	}
	freeNODE_W(l);
	return t;
}

void writeinfileNODE2_W(FILE* o, NODE2_W* t){
	printf("writeinfileNODE2_W : début !\n");
	// Each element of the tree is written in the output file.
	// Format : "longitude latitude rayon degré".
	// The static list is freed at the end.
	float lat;
	float lon;
	coordonate(t->s.id, &lat, &lon);
	printf("writeinfileNODE2_W : fin coordonate !\n");
/*	if(t!=NULL){
		writeinfileNODE2_W(o, t->sl);
		fprintf(o,"%f %f %d %f\n",lon,lat,t->s.speed,t->s.orientation);
		writeinfileNODE2_W(o, t->sr);
	}*/
	
	printf("writeinfileNODE2_W : fin !\n");
}

int sort_W(FILE* f, FILE* o, int r){
	printf("\nSorting data...\n");

	NODE2_W* T_W=NULL;
	NODE_W* l_W=linkedlist_W(f);
	printf("sort_W : fin initialisaion !\n");

	T_W =fillNODE2_WwithNODE_W(T_W,l_W, r);
	printf("sort_W : fin fillNODE2_WwithNODE_W !\n");
	fprintf(o,"# Longitude latitude rayon degré\n");
	printf("sort_W : fin fprintf !\n");
	writeinfileNODE2_W(o, T_W);
	printf("sort_W : fin writeinfileNODE2_W !\n");
	freetreeNODE2_W(T_W);
	printf("sort_W : fin freetreeNODE2_W !\n");
	fclose(o);

	fclose(f);

	printf("sort_W : sortie !\n");
	return 0;
}

/*
------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------
*/

void freetreeNODE2_H(NODE2_H* t){
	//Each node of the tree needs to be freed individually.
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
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=h;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_H* rotateleftNODE2_H(NODE2_H* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_H* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_H* rotaterightNODE2_H(NODE2_H* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_H* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_H* doublerotateleftNODE2_H(NODE2_H* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_H(t->sr);
	t=rotateleftNODE2_H(t);
	return t;
}

NODE2_H* doublerotaterightNODE2_H(NODE2_H* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_H(t->sl);
	t=rotaterightNODE2_H(t);
	return t;
}

NODE2_H* rebalanceNODE2_H(NODE2_H* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_H(t);
		else return doublerotateleftNODE2_H(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_H(t);
		else return doublerotaterightNODE2_H(t);
	}
	return t;
}

NODE2_H* addNODE2_H(NODE2_H* t, STATION_H H, int* h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_H(H);
	}else{
		if(r* (t->s.id) < r*(H.id)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_H(t->sl, H, h, r);
			else t->sl =createNODE2_H(H);
		} else if(r* (t->s.id) > r*(H.id)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_H(t->sr, H, h, r);
			else t->sr =createNODE2_H(H);
		} else {
			*h=0;
			return t;
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_H(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}
	
	return t;
}

NODE2_H* fillNODE2_HwithNODE_H(NODE2_H* t, NODE_H* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_H* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_H(t, temp->s, &h, r);
		temp=temp->next;
	}
	freeNODE_H(l);
	return t;
}

void writeinfileNODE2_H(FILE* o, NODE2_H* t){
	// Each element of the tree is written in the output file.
	// Format : "longitude latitude height".
	// The static list is freed at the end.
	float lat;
	float lon;
	coordonate(t->s.id, &lat, &lon);
	if(t!=NULL){
		writeinfileNODE2_H(o, t->sl);
		fprintf(o,"%f %f %d\n",lon,lat,t->s.height);
		writeinfileNODE2_H(o, t->sr);
	}
	
}

int sort_H(FILE* f, FILE* o, int r){
	printf("\nSorting data...");

	NODE2_H* T_H=NULL;
	NODE_H* l_H=linkedlist_H(f);

	T_H =fillNODE2_HwithNODE_H(T_H,l_H, r);
	fprintf(o,"# Longitude latitude height\n");
	writeinfileNODE2_H(o, T_H);
	freetreeNODE2_H(T_H);
	fclose(o);

	return 0;
}

/*
------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------
*/

void freetreeNODE2_M(NODE2_M* t){
	//Each node of the tree needs to be freed individually.
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
		printf("erreur de malloc\n");
		exit(4);
	}
	t->s=m;
	t->sl=NULL;
	t->sr=NULL;
	t->balance=0;
	return t;
}

NODE2_M* rotateleftNODE2_M(NODE2_M* t){
	//The tree is modified (turning left) to be balanced.
	NODE2_M* temp=t->sr;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sr=temp->sl;
	temp->sl=t;
	t->balance =balance_t-max(balance_temp,0)-1;
	temp->balance =min(min(balance_t -2,balance_t+balance_temp-2), balance_temp-1);
	return temp;
}

NODE2_M* rotaterightNODE2_M(NODE2_M* t){
	//The tree is modified (turning right) to be balanced.
	NODE2_M* temp=t->sl;
	int balance_t=t->balance, balance_temp=temp->balance;
	t->sl=temp->sr;
	temp->sl=t;
	t->balance=balance_t-min(balance_temp, 0)+1;
	temp->balance=max(max(balance_t+2,balance_t+balance_temp+2),balance_temp+1);
	return temp;
}

NODE2_M* doublerotateleftNODE2_M(NODE2_M* t){
	//The tree is modified (turning twice : right then left) to be balanced.
	t->sr =rotaterightNODE2_M(t->sr);
	t=rotateleftNODE2_M(t);
	return t;
}

NODE2_M* doublerotaterightNODE2_M(NODE2_M* t){
	//The tree is modified (turning twice : left then right) to be balanced.
	t->sl=rotateleftNODE2_M(t->sl);
	t=rotaterightNODE2_M(t);
	return t;
}

NODE2_M* rebalanceNODE2_M(NODE2_M* t){
	//Checking if the tree needs to be modified to be balanced and how.
	if(t->balance >=2){
		if(t->sr !=NULL && t->sr->balance>=0) return rotateleftNODE2_M(t);
		else return doublerotateleftNODE2_M(t);
	} else if(t->balance <=-2){
		if(t->sl !=NULL && t->sl->balance<=0) return rotaterightNODE2_M(t);
		else return doublerotaterightNODE2_M(t);
	}
	return t;
}

NODE2_M* addNODE2_M(NODE2_M* t, STATION_M m, int* h, int r){
	//A new node is added to the tree, and sorted.
	if(t==NULL){
		*h=1;
		return createNODE2_M(m);
	}else{
		if(r* (t->s.id) < r*(m.id)){
			if (r ==1) *h=-*h;
			if (t->sl !=NULL) t->sl =addNODE2_M(t->sl, m, h, r);
			else t->sl =createNODE2_M(m);
		} else if(r* (t->s.id) > r*(m.id)){
			if (r ==-1) *h=-*h;
			if (t->sr !=NULL) t->sr =addNODE2_M(t->sr, m, h, r);
			else t->sr =createNODE2_M(m);
		} else {
			*h=0;
			return t;
		}
	}
	if(*h!=0){
		t->balance=t->balance+*h;
		if(t->balance <-1 || t->balance >1) rebalanceNODE2_M(t);
		if (t->balance==0) *h=0;
		else *h=1;
	}
	
	return t;
}

NODE2_M* fillNODE2_MwithNODE_M(NODE2_M* t, NODE_M* l, int r){
	//We transfer the linked list's elements to a tree.
	NODE_M* temp=l;
	int h=0;
	while(temp!=NULL){
		t =addNODE2_M(t, temp->s, &h, r);
		temp=temp->next;
	}
	freeNODE_M(l);
	return t;
}

void writeinfileNODE2_M(FILE* o, NODE2_M* t){
	// Each element of the tree is written in the output file.
	// Format : "longitude latitude moisture".
	// The static list is freed at the end.
	float lat;
	float lon;
	coordonate(t->s.id, &lat, &lon);
	if(t!=NULL){
		writeinfileNODE2_M(o, t->sl); 
		fprintf(o,"%f %f %d\n",lon,lat,t->s.maximal);
		writeinfileNODE2_M(o, t->sr);
	}
	
}

int sort_M(FILE* f, FILE* o, int r){
	printf("\nSorting data...");

	NODE2_M* T_M=NULL;
	NODE_M* l_M=linkedlist_M(f);

	T_M =fillNODE2_MwithNODE_M(T_M,l_M, r);
	fprintf(o,"# Longitude latitude moisture\n");
	writeinfileNODE2_M(o, T_M);
	freetreeNODE2_M(T_M);
	fclose(o);

	return 0;
}
