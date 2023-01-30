#ifndef HEADCOMMUN
	#define HEADCOMMUN
	#include "headercommun.h"
#endif

#ifndef COMMUN
	#define COMMUN
	#include "commun.c"
#endif

/*
------------------------------------------------------------
STRUCTURES
------------------------------------------------------------
*/

/*
This structure is used to build a tree.
Each node contains informations about the station's temperature measure.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_T1).
* sl : the next node (NODE_T1*).
* sr : the next node (NODE_T1*).
It is specifically used when temperature with mode 1 was chosen.
*/
typedef struct NODE2_T1{

	int balance;
	STATION_T1 s;
	struct NODE2_T1* sl;
	struct NODE2_T1* sr;

}NODE2_T1;

/*
This structure is used to build a tree.
Each node contains informations about temperature at a given time.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* t : the time (TIME_T2).
* sl : the next node (NODE_T2*).
* sr : the next node (NODE_T2*).
It is specifically used when temperature with mode 2 was chosen.
*/
typedef struct NODE2_T2{

	int balance;
	TIME_T2 t;
	struct NODE2_T2* sl;
	struct NODE2_T2* sr;

}NODE2_T2;

/*
This structure is used to build a tree.
Each node contains informations about the station's temperature measure.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* m : the measure (MEASURE_T3).
* sl : the next node (NODE_T3*).
* sr : the next node (NODE_T3*).
It is specifically used when temperature with mode 3 was chosen.
*/
typedef struct NODE2_T3{

	int balance;
	MEASURE_T3 m;
	struct NODE2_T3* sl;
	struct NODE2_T3* sr;

}NODE2_T3;

/*
This structure is used to build a tree.
Each node contains informations about the station's pressure measure.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_P1).
* sl : the next node (NODE_P1*).
* sr : the next node (NODE_P1*).
It is specifically used when pressure with mode 1 was chosen.
*/
typedef struct NODE2_P1{

	int balance;
	STATION_P1 s;
	struct NODE2_P1* sl;
	struct NODE2_P1* sr;

}NODE2_P1;

/*
This structure is used to build a tree.
Each node contains informations about pressure at a givent time.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* t : the time (TIME_P2).
* sl : the next node (NODE2_P2*).
* sr : the next node (NODE2_P2*).
It is specifically used when pressure with mode 2 was chosen.
*/
typedef struct NODE2_P2{

	int balance;
	TIME_P2 t;
	struct NODE2_P2* sl;
	struct NODE2_P2* sr;

}NODE2_P2;

/*
This structure is used to build a tree.
Each node contains informations about the station's pressure measure.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* m : the measure (MEASURE_P3).
* sl : the next node (NODE2_P3*).
* sr : the next node (NODE2_P3*).
It is specifically used when pressure with mode 3 was chosen.
*/
typedef struct NODE2_P3{

	int balance;
	MEASURE_P3 m;
	struct NODE2_P3* sl;
	struct NODE2_P3* sr;

}NODE2_P3;

/*
This structure is used to build a tree.
Each node contains informations about the station's wind measures.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_W).
* sl : the next node (NODE2_W*).
* sr : the next node (NODE2_W*).
It is specifically used when wind was chosen.
*/
typedef struct NODE2_W{

	int balance;
	STATION_W s;
	struct NODE2_W* sl;
	struct NODE2_W* sr;

}NODE2_W;

/*
This structure is used to build a tree.
Each node contains the station's height.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_H).
* sl : the next node (NODE2_H*).
* sr : the next node (NODE2_H*).
It is specifically used when height was chosen.
*/
typedef struct NODE2_H{

	int balance;
	STATION_H s;
	struct NODE2_H* sl;
	struct NODE2_H* sr;

}NODE2_H;

/*
This structure is used to build a tree.
Each node contains the station's height.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_H).
* sl : the next node (NODE2_H*).
* sr : the next node (NODE2_H*).
It is specifically used when moisture was chosen.
*/
typedef struct NODE2_M{

	int balance;
	STATION_M s;
	struct NODE2_M* sl;
	struct NODE2_M* sr;

}NODE2_M;

/*
------------------------------------------------------------
FUNCTIONS
------------------------------------------------------------
*/

/*
This function is called to calculate the minimum between two integer.
* a : given integer (int).
* b : given integer (int).
*/
int min(int a, int b);

/*
This function is called to calculate the maximum between two integer.
* a : given integer (int).
* b : given integer (int).
*/
int max(int a, int b);

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
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
void freetreeNODE2_T1(NODE2_T1* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (NODE2_T1*).
* t1 : (STATION_T1).
Specifically used when temprature with mode 1 was chosen.
*/
NODE2_T1* createNODE2_T1(STATION_T1 t1) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
NODE2_T1* rotateleftNODE2_T1(NODE2_T1* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
NODE2_T1* rotaterightNODE2_T1(NODE2_T1* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
NODE2_T1* doublerotateleftNODE2_T1(NODE2_T1* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
NODE2_T1* doublerotaterightNODE2_T1(NODE2_T1* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
NODE2_T1* rebalanceNODE2_T1(NODE2_T1* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_T1*).
* t1 : (STATION_t1).
* h : (int*).
* r : (int).
Specifically used when temprature with mode 1 was chosen.
*/
NODE2_T1* addNODE2_T1(NODE2_T1* t, STATION_T1 t1, int* h, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_T1*).
* l : given linked list (NODE_T1*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when temprature with mode 1 was chosen.
*/
NODE2_T1* fillNODE2_T1withNODE_T1(NODE2_T1* t, NODE_T1* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
void writeinfileNODE2_T1(FILE* o, NODE2_T1* t) ;

/*
A sorting function used to produce the output file when temperature with mode 1 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file.
The produced temperature file contains stations sorted by their ID from lowest to highest number, and for each station, the maximal, minimal and average temperature values.
*/
int sort_T1(FILE* f, FILE* o, int r) ;

/*
------------------------------------------
MODE 2
------------------------------------------
*/

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
void freetreeNODE2_T2(NODE2_T2* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (NODE2_T2*).
* t2 : (STATION_T2).
Specifically used when temprature with mode 2 was chosen.
*/
NODE2_T2* createNODE2_T2(TIME_T2 t2) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
NODE2_T2* rotateleftNODE2_T2(NODE2_T2* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
NODE2_T2* rotaterightNODE2_T2(NODE2_T2* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
NODE2_T2* doublerotateleftNODE2_T2(NODE2_T2* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
NODE2_T2* doublerotaterightNODE2_T2(NODE2_T2* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
NODE2_T2* rebalanceNODE2_T2(NODE2_T2* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_T2*).
* t2 : (STATION_t2).
* h : (int*).
* r : (int).
Specifically used when temprature with mode 2 was chosen.
*/
NODE2_T2* addNODE2_T2(NODE2_T2* t, TIME_T2 t2, int* h, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_T2*).
* l : given linked list (NODE_T2*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when temprature with mode 2 was chosen.
*/
NODE2_T2* fillNODE2_T2withNODE_T2(NODE2_T2* t, NODE_T2* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
void writeinfileNODE2_T2(FILE* o, NODE2_T2* t) ;

/*
A sorting function used to produce the output file when temperature with mode 2 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file.
The produced temperature file contains, in chronological order, the average temperature values (average made on all the stations).
*/
int sort_T2(FILE* f, FILE* o, int r) ;

/*
------------------------------------------
MODE 3
------------------------------------------
*/

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
void freetreeNODE2_T3(NODE2_T3* t) ;

This function is called to create a node using malloc.
* t : given tree (NODE2_T3*).
* t3 : (MEASURE_T3 ).
Specifically used when temprature with mode 3 was chosen.
NODE2_T3* createNODE2_T3(MEASURE_T3  t3) ;

This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
NODE2_T3* rotateleftNODE2_T3(NODE2_T3* t);

This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
NODE2_T3* rotaterightNODE2_T3(NODE2_T2* t);

This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
NODE2_T3 doublerotateleftNODE2_T3(NODE2_T3* t);

This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
NODE2_T3* doublerotaterightNODE2_T3(NODE2_T3* t);

This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
NODE2_T3* rebalanceNODE2_T3 (NODE2_T3* t);

This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_T3*).
* t3 : (MEASURE_T3 ).
* h : (int*).
* r : (int).
Specifically used when temprature with mode 3 was chosen.
NODE2_T3* addNODE2_T3(NODE2_T3* t, MEASURE_T3  t2, int* h, int r);
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_T3*).
* l : given linked list (NODE_T3*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when temprature with mode 3 was chosen.
NODE2_T3* fillNODE2_T3withNODE_T3(NODE2_T3* t, NODE_T3* l, int r);

This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
void writeinfileNODE2_T3(FILE* o, NODE2_T3* t, MEASURE_P3 old_m) ;

A sorting function used to produce the output file when temperature with mode 3 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file.
The produced temperature file contains the temperature values sorted in chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
int sort_T3(FILE* f, FILE* o, int r) ;
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

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
void freetreeNODE2_P1(NODE2_P1* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (NODE2_P1*).
* p1 : (STATION_P1).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* createNODE2_P1(STATION_P1 p1) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* rotateleftNODE2_P1(NODE2_P1* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* rotaterightNODE2_P1(NODE2_P1* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* doublerotateleftNODE2_P1(NODE2_P1* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* doublerotaterightNODE2_P1(NODE2_P1* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* rebalanceNODE2_P1(NODE2_P1* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_P1*).
* p1 : (STATION_P1).
* h : (int*).
* r : (int).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* addNODE2_P1(NODE2_P1* t, STATION_P1 p1, int* h, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_P1*).
* l : given linked list (NODE_P1*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* fillNODE2_P1withNODE_P1(NODE2_P1* t, NODE_P1* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
void writeinfileNODE2_P1(FILE* o, NODE2_P1* t) ;

/*
A sorting function used to produce the output file when pressure with mode 1 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file.
The produced pressure file contains stations sorted by their ID from highest to lowest number, and for each station, the maximal, minimal and average pressure values.
*/
int sort_P1(FILE* f, FILE* o, int r) ;

/*
------------------------------------------
MODE 2
------------------------------------------
*/

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
void freetreeNODE2_P2(NODE2_P2* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (NODE2_P2*).
* p2 : (STATION_P2).
Specifically used when pressure with mode 2 was chosen.
*/
NODE2_P2* createNODE2_P2(TIME_P2 p2) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
NODE2_P2* rotateleftNODE2_P2(NODE2_P2* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
NODE2_P2* rotaterightNODE2_P2(NODE2_P2* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
NODE2_P2* doublerotateleftNODE2_P2(NODE2_P2* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
NODE2_P2* doublerotaterightNODE2_P2(NODE2_P2* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
NODE2_P2* rebalanceNODE2_P2(NODE2_P2* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_P2*).
* p2 : (STATION_P2).
* h : (int*).
* r : (int).
Specifically used when pressure with mode 2 was chosen.
*/
NODE2_P2* addNODE2_P2(NODE2_P2* t, TIME_P2 p2, int* h, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_P2*).
* l : given linked list (NODE_P2*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when pressure with mode 2 was chosen.
*/
NODE2_P2* fillNODE2_P2withNODE_P2(NODE2_P2* t, NODE_P2* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
void writeinfileNODE2_P2(FILE* o, NODE2_P2* t) ;

/*
A sorting function used to produce the output file when pressure with mode 2 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file.
The produced pressure file contains, in reverse-chronological order, the average pressure values (average made on all the stations).
*/
int sort_P2(FILE* f, FILE* o, int r) ;

/*
------------------------------------------
MODE 3
------------------------------------------
*/
/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
void freetreeNODE2_P3(NODE2_P3* t) ;

This function is called to create a node using malloc.
* t : given tree (NODE2_P3*).
* p3 : (MEASURE_P3 ).
Specifically used when pressure with mode 3 was chosen.
NODE2_P3* createNODE2_P3(MEASURE_P3  p3) ;

This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
NODE2_P3* rotateleftNODE2_P3(NODE2_P3* t);

This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
NODE2_P3* rotaterightNODE2_P3(NODE2_P3* t);

This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
NODE2_P3* doublerotateleftNODE2_P3(NODE2_P3* t);

This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
NODE2_P3* doublerotaterightNODE2_P3(NODE2_P3* t);

This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
NODE2_P3* rebalanceNODE2_P3(NODE2_P3* t);

This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_P3*).
* p3 : (MEASURE_P3 ).
* h : (int*).
* r : (int).
Specifically used when pressure with mode 3 was chosen.
NODE2_P3* addNODE2_P3(NODE2_P3* t, MEASURE_P3  p3, int* h, int r);

This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_P3*).
* l : given linked list (NODE_P3*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when pressure with mode 3 was chosen.
NODE2_P3* fillNODE2_P3withNODE_P3(NODE2_P3* t, NODE_P3* l, int r);

This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
void writeinfileNODE2_P3(FILE* o, NODE2_P3* t, MEASURE_P3 old_m) ;

A sorting function used to produce the output file when pressure with mode 3 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file.
The produced pressure file contains the pressure values sorted in reverse-chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
int sort_P3(FILE* f, FILE* o, int r) ;
*/
/*
------------------------------------------
WIND FUNCTIONS
------------------------------------------
*/

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_W*).
Specifically used when wind was chosen.
*/
void freetreeNODE2_W(NODE2_W* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (NODE2_W*).
* w : (STATION_W).
Specifically used when wind was chosen.
*/
NODE2_W* createNODE2_W(STATION_W w) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_W*).
Specifically used when wind was chosen.
*/
NODE2_W* rotateleftNODE2_W(NODE2_W* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_W*).
Specifically used when wind was chosen.
*/
NODE2_W* rotaterightNODE2_W(NODE2_W* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_W*).
Specifically used when wind was chosen.
*/
NODE2_W* doublerotateleftNODE2_W(NODE2_W* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_W*).
Specifically used when wind was chosen.
*/
NODE2_W* doublerotaterightNODE2_W(NODE2_W* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_W*).
Specifically used when wind was chosen.
*/
NODE2_W* rebalanceNODE2_W(NODE2_W* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_W*).
* w : (STATION_W).
* h : (int*).
* r : (int).
Specifically used when wind was chosen.
*/
NODE2_W* addNODE2_W(NODE2_W* t, STATION_W w, int* h, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_W*).
* l : given linked list (NODE_W*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when wind was chosen.
*/
NODE2_W* fillNODE2_WwithNODE_W(NODE2_W* t, NODE_W* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_W*).
Specifically used when wind was chosen.
*/
void writeinfileNODE2_W(FILE* o, NODE2_W* t) ;

/*
A sorting function used to produce the output file when wind was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given wind file.
The produced wind file contains the average orientation and average speed of the wind for each station. The stations' IDs are sorted from lowest to highest number. 
*/
int sort_W(FILE* f, FILE* o, int r) ;

/*
------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------
*/

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_H*).
Specifically used when height was chosen.
*/
void freetreeNODE2_H(NODE2_H* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (NODE2_H*).
* h : (STATION_H).
Specifically used when height was chosen.
*/
NODE2_H* createNODE2_H(STATION_H h) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_H*).
Specifically used when height was chosen.
*/
NODE2_H* rotateleftNODE2_H(NODE2_H* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_H*).
Specifically used when height was chosen.
*/
NODE2_H* rotaterightNODE2_H(NODE2_H* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_H*).
Specifically used when height was chosen.
*/
NODE2_H* doublerotateleftNODE2_H(NODE2_H* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_H*).
Specifically used when height was chosen.
*/
NODE2_H* doublerotaterightNODE2_H(NODE2_H* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_H*).
Specifically used when height was chosen.
*/
NODE2_H* rebalanceNODE2_H(NODE2_H* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_H*).
* h : (STATION_H).
* h : (int*).
* r : (int).
Specifically used when height was chosen.
*/
NODE2_H* addNODE2_H(NODE2_H* t, STATION_H H, int* h, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_H*).
* l : given linked list (NODE_H*).
* r : integer representing the asked order (-1 means the ascending order, 1 means the descending order) (int).
Specifically used when height was chosen.
*/
NODE2_H* fillNODE2_HwithNODE_H(NODE2_H* t, NODE_H* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_H*).
Specifically used when height was chosen.
*/
void writeinfileNODE2_H(FILE* o, NODE2_H* t) ;

/*
A sorting function used to produce the output file when height was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (-1 means the ascending order, 1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given height file.
The produced height file contains the stations' IDs and their height sorted from highest to lowest.
*/
int sort_H(FILE* f, FILE* o, int r) ;

/*
------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------
*/

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (NODE2_M*).
Specifically used when moisture was chosen.
*/
void freetreeNODE2_M(NODE2_M* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (NODE2_M*).
* m : (STATION_M).
Specifically used when moisture with mode 3 was chosen.
*/
NODE2_M* createNODE2_M(STATION_M m) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_M*).
Specifically used when moisture with mode 3 was chosen.
*/
NODE2_M* rotateleftNODE2_M(NODE2_M* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (NODE2_M*).
Specifically used when moisture with mode 3 was chosen.
*/
NODE2_M* rotaterightNODE2_M(NODE2_M* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_M*).
Specifically used when moisture with mode 3 was chosen.
*/
NODE2_M* doublerotateleftNODE2_M(NODE2_M* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (NODE2_M*).
Specifically used when moisture with mode 3 was chosen.
*/
NODE2_M* doublerotaterightNODE2_M(NODE2_M* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (NODE2_M*).
Specifically used when moisture with mode 3 was chosen.
*/
NODE2_M* rebalanceNODE2_M(NODE2_M* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (NODE2_M*).
* m : (STATION_M).
* h : (int*).
* r : (int).
Specifically used when moisture with mode 3 was chosen.
*/
NODE2_M* addNODE2_M(NODE2_M* t, STATION_M m, int* h, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (NODE2_M*).
* l : given linked list (NODE_M*).
* r : integer representing the asked order (-1 means the ascending order, 1 means the descending order) (int).
Specifically used when moisture with mode 3 was chosen.
*/
NODE2_M* fillNODE2_MwithNODE_M(NODE2_M* t, NODE_M* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (NODE2_M*).
Specifically used when moisture with mode 3 was chosen.
*/
void writeinfileNODE2_M(FILE* o, NODE2_M* t) ;

/*
A sorting function used to produce the output file when moisture was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (-1 means the ascending order, 1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given moisture file.
The produced moisture file contains the stations' IDs and their maximal moisture value sorted from highest to lowest value.
*/
int sort_M(FILE* f, FILE* o, int r) ;
