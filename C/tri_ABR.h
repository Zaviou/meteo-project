#ifndef SHARED
	#define SHARED 1
	#include "shared.c"
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
It is specifically used when temerature with mode 1 was chosen.
*/
typedef struct ABR_NODE2_T1{

	STATION_T1 s;
	struct ABR_NODE2_T1* sl;
	struct ABR_NODE2_T1* sr;

}ABR_NODE2_T1;

/*
This structure is used to build a tree.
Each node contains informations about temperature at a given time.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* t : the time (TIME_T2).
* sl : the next node (NODE_T2*).
* sr : the next node (NODE_T2*).
It is specifically used when temperature with mode 2 was chosen.
*/
typedef struct ABR_NODE2_T2{

	TIME_T2 t;
	struct ABR_NODE2_T2* sl;
	struct ABR_NODE2_T2* sr;

}ABR_NODE2_T2;

/*
This structure is used to build a tree.
Each node contains informations about the station's temperature measure.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* m : the measure (MEASURE_T3).
* sl : the next node (NODE_T3*).
* sr : the next node (NODE_T3*).
It is specifically used when temperature with mode 3 was chosen.
*/
typedef struct ABR_NODE2_T3{

	MEASURE_T3 m;
	struct ABR_NODE2_T3* sl;
	struct ABR_NODE2_T3* sr;

}ABR_NODE2_T3;

/*
This structure is used to build a tree.
Each node contains informations about the station's pressure measure.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_P1).
* sl : the next node (NODE_P1*).
* sr : the next node (NODE_P1*).
It is specifically used when pressure with mode 1 was chosen.
*/
typedef struct ABR_NODE2_P1{

	STATION_P1 s;
	struct ABR_NODE2_P1* sl;
	struct ABR_NODE2_P1* sr;

}ABR_NODE2_P1;

/*
This structure is used to build a tree.
Each node contains informations about pressure at a givent time.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* t : the time (TIME_P2).
* sl : the next node (ABR_NODE2_P2*).
* sr : the next node (ABR_NODE2_P2*).
It is specifically used when pressure with mode 2 was chosen.
*/
typedef struct ABR_NODE2_P2{

	TIME_P2 t;
	struct ABR_NODE2_P2* sl;
	struct ABR_NODE2_P2* sr;

}ABR_NODE2_P2;

/*
This structure is used to build a tree.
Each node contains informations about the station's pressure measure.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* m : the measure (MEASURE_P3).
* sl : the next node (ABR_NODE2_P3*).
* sr : the next node (ABR_NODE2_P3*).
It is specifically used when pressure with mode 3 was chosen.
*/
typedef struct ABR_NODE2_P3{

	MEASURE_P3 m;
	struct ABR_NODE2_P3* sl;
	struct ABR_NODE2_P3* sr;

}ABR_NODE2_P3;

/*
This structure is used to build a tree.
Each node contains informations about the station's wind measures.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_W).
* sl : the next node (ABR_NODE2_W*).
* sr : the next node (ABR_NODE2_W*).
It is specifically used when wind was chosen.
*/
typedef struct ABR_NODE2_W{

	STATION_W s;
	struct ABR_NODE2_W* sl;
	struct ABR_NODE2_W* sr;

}ABR_NODE2_W;

/*
This structure is used to build a tree.
Each node contains the station's height.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_H).
* sl : the next node (ABR_NODE2_H*).
* sr : the next node (ABR_NODE2_H*).
It is specifically used when height was chosen.
*/
typedef struct ABR_NODE2_H{

	STATION_H s;
	struct ABR_NODE2_H* sl;
	struct ABR_NODE2_H* sr;

}ABR_NODE2_H;

/*
This structure is used to build a tree.
Each node contains the station's height.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_H).
* sl : the next node (ABR_NODE2_H*).
* sr : the next node (ABR_NODE2_H*).
It is specifically used when moisture was chosen.
*/
typedef struct ABR_NODE2_M{

	STATION_M s;
	struct ABR_NODE2_M* sl;
	struct ABR_NODE2_M* sr;

}ABR_NODE2_M;

/*
------------------------------------------------------------
FUNCTIONS
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

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (ABR_NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
void freetreeABR_NODE2_T1(ABR_NODE2_T1* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_T1*).
* t1 : (STATION_T1).
Specifically used when temprature with mode 1 was chosen.
*/
ABR_NODE2_T1* createABR_NODE2_T1(STATION_T1 t1) ;

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_T1*).
* t1 : (STATION_t1).
* h : (int*).
* r : (int).
Specifically used when temprature with mode 1 was chosen.
*/
ABR_NODE2_T1* addABR_NODE2_T1(ABR_NODE2_T1* t, STATION_T1 t1, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_T1*).
* l : given linked list (NODE_T1*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when temprature with mode 1 was chosen.
*/
ABR_NODE2_T1* fillABR_NODE2_T1withNODE_T1(ABR_NODE2_T1* t, NODE_T1* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_T1*).
Specifically used when temprature with mode 1 was chosen.
*/
void writeinfileABR_NODE2_T1(FILE* o, ABR_NODE2_T1* t) ;

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
* t : the tree to be freed (ABR_NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
void freetreeABR_NODE2_T2(ABR_NODE2_T2* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_T2*).
* t2 : (STATION_T2).
Specifically used when temprature with mode 2 was chosen.
*/
ABR_NODE2_T2* createABR_NODE2_T2(TIME_T2 t2) ;

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_T2*).
* t2 : (STATION_t2).
* h : (int*).
* r : (int).
Specifically used when temprature with mode 2 was chosen.
*/
ABR_NODE2_T2* addABR_NODE2_T2(ABR_NODE2_T2* t, TIME_T2 t2, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_T2*).
* l : given linked list (NODE_T2*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when temprature with mode 2 was chosen.
*/
ABR_NODE2_T2* fillABR_NODE2_T2withNODE_T2(ABR_NODE2_T2* t, NODE_T2* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_T2*).
Specifically used when temprature with mode 2 was chosen.
*/
void writeinfileABR_NODE2_T2(FILE* o, ABR_NODE2_T2* t) ;

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
* t : the tree to be freed (ABR_NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
*/
void freetreeABR_NODE2_T3(ABR_NODE2_T3* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_T3*).
* t3 : (MEASURE_T3 ).
Specifically used when temprature with mode 3 was chosen.
*/
ABR_NODE2_T3* createABR_NODE2_T3(MEASURE_T3  t3) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (ABR_NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
*/
ABR_NODE2_T3* rotateleftABR_NODE2_T3(ABR_NODE2_T3* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (ABR_NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
*/
ABR_NODE2_T3* rotaterightABR_NODE2_T3(ABR_NODE2_T2* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (ABR_NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
*/
ABR_NODE2_T3 doublerotateleftABR_NODE2_T3(ABR_NODE2_T3* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (ABR_NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.*/
ABR_NODE2_T3* doublerotaterightABR_NODE2_T3(ABR_NODE2_T3* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (ABR_NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
*/
ABR_NODE2_T3* rebalanceABR_NODE2_T3 (ABR_NODE2_T3* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_T3*).
* t3 : (MEASURE_T3 ).
* h : (int*).
* r : (int).
Specifically used when temprature with mode 3 was chosen.
*/
ABR_NODE2_T3* addABR_NODE2_T3(ABR_NODE2_T3* t, MEASURE_T3  t2, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_T3*).
* l : given linked list (NODE_T3*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when temprature with mode 3 was chosen.
*/
ABR_NODE2_T3* fillABR_NODE2_T3withNODE_T3(ABR_NODE2_T3* t, NODE_T3* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_T3*).
Specifically used when temprature with mode 3 was chosen.
*/
void writeinfileABR_NODE2_T3(FILE* o, ABR_NODE2_T3* t, MEASURE_T3 old_m) ;

/*
A sorting function used to produce the output file when temperature with mode 3 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file.
The produced temperature file contains the temperature values sorted in chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int sort_T3(FILE* f, FILE* o, int r) ;


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
* t : the tree to be freed (ABR_NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
void freetreeABR_NODE2_P1(ABR_NODE2_P1* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_P1*).
* p1 : (STATION_P1).
Specifically used when pressure with mode 1 was chosen.
*/
ABR_NODE2_P1* createABR_NODE2_P1(STATION_P1 p1) ;

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_P1*).
* p1 : (STATION_P1).
* h : (int*).
* r : (int).
Specifically used when pressure with mode 1 was chosen.
*/
ABR_NODE2_P1* addABR_NODE2_P1(ABR_NODE2_P1* t, STATION_P1 p1, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_P1*).
* l : given linked list (NODE_P1*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when pressure with mode 1 was chosen.
*/
ABR_NODE2_P1* fillABR_NODE2_P1withNODE_P1(ABR_NODE2_P1* t, NODE_P1* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
void writeinfileABR_NODE2_P1(FILE* o, ABR_NODE2_P1* t) ;

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
* t : the tree to be freed (ABR_NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
void freetreeABR_NODE2_P2(ABR_NODE2_P2* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_P2*).
* p2 : (STATION_P2).
Specifically used when pressure with mode 2 was chosen.
*/
ABR_NODE2_P2* createABR_NODE2_P2(TIME_P2 p2) ;

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_P2*).
* p2 : (STATION_P2).
* h : (int*).
* r : (int).
Specifically used when pressure with mode 2 was chosen.
*/
ABR_NODE2_P2* addABR_NODE2_P2(ABR_NODE2_P2* t, TIME_P2 p2, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_P2*).
* l : given linked list (NODE_P2*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when pressure with mode 2 was chosen.
*/
ABR_NODE2_P2* fillABR_NODE2_P2withNODE_P2(ABR_NODE2_P2* t, NODE_P2* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_P2*).
Specifically used when pressure with mode 2 was chosen.
*/
void writeinfileABR_NODE2_P2(FILE* o, ABR_NODE2_P2* t) ;

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

/*A function used to free all the nodes of a given tree.
* t : the tree to be freed (ABR_NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
*/
void freetreeABR_NODE2_P3(ABR_NODE2_P3* t) ;

/*This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_P3*).
* p3 : (MEASURE_P3 ).
Specifically used when pressure with mode 3 was chosen.
*/
ABR_NODE2_P3* createABR_NODE2_P3(MEASURE_P3  p3) ;

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (ABR_NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
*/

ABR_NODE2_P3* rotateleftABR_NODE2_P3(ABR_NODE2_P3* t);

/*
This function is called to modificate the place of nodes in the tree to make it balanced.
* t : given tree (ABR_NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
*/

ABR_NODE2_P3* rotaterightABR_NODE2_P3(ABR_NODE2_P3* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (ABR_NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
*/

ABR_NODE2_P3* doublerotateleftABR_NODE2_P3(ABR_NODE2_P3* t);

/*
This function is called to modificate the order of nodes in the tree to make it balanced.
* t : given tree (ABR_NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
*/

ABR_NODE2_P3* doublerotaterightABR_NODE2_P3(ABR_NODE2_P3* t);

/*
This function is called to chose which modification of a tree to do to make it balanced.
* t : given tree (ABR_NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
*/

ABR_NODE2_P3* rebalanceABR_NODE2_P3(ABR_NODE2_P3* t);

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_P3*).
* p3 : (MEASURE_P3 ).
* h : (int*).
* r : (int).
Specifically used when pressure with mode 3 was chosen.
*/

ABR_NODE2_P3* addABR_NODE2_P3(ABR_NODE2_P3* t, MEASURE_P3  p3, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_P3*).
* l : given linked list (NODE_P3*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when pressure with mode 3 was chosen.
*/

ABR_NODE2_P3* fillABR_NODE2_P3withNODE_P3(ABR_NODE2_P3* t, NODE_P3* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_P3*).
Specifically used when pressure with mode 3 was chosen.
*/

void writeinfileABR_NODE2_P3(FILE* o, ABR_NODE2_P3* t, MEASURE_P3 old_m) ;

/*
A sorting function used to produce the output file when pressure with mode 3 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data.
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file.
The produced pressure file contains the pressure values sorted in reverse-chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/

int sort_P3(FILE* f, FILE* o, int r) ;

/*
------------------------------------------
WIND FUNCTIONS
------------------------------------------
*/

/*
A function used to free all the nodes of a given tree.
* t : the tree to be freed (ABR_NODE2_W*).
Specifically used when wind was chosen.
*/
void freetreeABR_NODE2_W(ABR_NODE2_W* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_W*).
* w : (STATION_W).
Specifically used when wind was chosen.
*/
ABR_NODE2_W* createABR_NODE2_W(STATION_W w) ;

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_W*).
* w : (STATION_W).
* h : (int*).
* r : (int).
Specifically used when wind was chosen.
*/
ABR_NODE2_W* addABR_NODE2_W(ABR_NODE2_W* t, STATION_W w, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_W*).
* l : given linked list (NODE_W*).
* r : integer representing the asked order (1 means the ascending order, -1 means the descending order) (int).
Specifically used when wind was chosen.
*/
ABR_NODE2_W* fillABR_NODE2_WwithNODE_W(ABR_NODE2_W* t, NODE_W* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_W*).
Specifically used when wind was chosen.
*/
void writeinfileABR_NODE2_W(FILE* o, ABR_NODE2_W* t) ;

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
* t : the tree to be freed (ABR_NODE2_H*).
Specifically used when height was chosen.
*/
void freetreeABR_NODE2_H(ABR_NODE2_H* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_H*).
* h : (STATION_H).
Specifically used when height was chosen.
*/
ABR_NODE2_H* createABR_NODE2_H(STATION_H h) ;

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_H*).
* h : (STATION_H).
* h : (int*).
* r : (int).
Specifically used when height was chosen.
*/
ABR_NODE2_H* addABR_NODE2_H(ABR_NODE2_H* t, STATION_H h, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_H*).
* l : given linked list (NODE_H*).
* r : integer representing the asked order (-1 means the ascending order, 1 means the descending order) (int).
Specifically used when height was chosen.
*/
ABR_NODE2_H* fillABR_NODE2_HwithNODE_H(ABR_NODE2_H* t, NODE_H* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_H*).
Specifically used when height was chosen.
*/
void writeinfileABR_NODE2_H(FILE* o, ABR_NODE2_H* t) ;

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
* t : the tree to be freed (ABR_NODE2_M*).
Specifically used when moisture was chosen.
*/
void freetreeABR_NODE2_M(ABR_NODE2_M* t) ;

/*
This function is called to create a node using malloc.
* t : given tree (ABR_NODE2_M*).
* m : (STATION_M).
Specifically used when moisture with mode 3 was chosen.
*/
ABR_NODE2_M* createABR_NODE2_M(STATION_M m) ;

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given tree (ABR_NODE2_M*).
* m : (STATION_M).
* h : (int*).
* r : (int).
Specifically used when moisture with mode 3 was chosen.
*/
ABR_NODE2_M* addABR_NODE2_M(ABR_NODE2_M* t, STATION_M m, int r);

/*
This function is called to fill a tree with the linked list created in the asked order.
* t : given tree (ABR_NODE2_M*).
* l : given linked list (NODE_M*).
* r : integer representing the asked order (-1 means the ascending order, 1 means the descending order) (int).
Specifically used when moisture with mode 3 was chosen.
*/
ABR_NODE2_M* fillABR_NODE2_MwithNODE_M(ABR_NODE2_M* t, NODE_M* l, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given tree (ABR_NODE2_M*).
Specifically used when moisture with mode 3 was chosen.
*/
void writeinfileABR_NODE2_M(FILE* o, ABR_NODE2_M* t) ;

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




