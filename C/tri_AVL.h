#ifndef HEADCOMMUN
	#define HEADCOMMUN
	#include "headercommun.h"
#endif

/*
------------------------------------------------------------
STRUCTURES
------------------------------------------------------------
*/

/*
This structure is used to build a tree.
Each node contains informations about the station's pressure measures.
* balance : the height of the right-sun's tree minus the height of the left-sun's tree (int).
* s : the station (STATION_T1).
* sl : the next node (NODE_T1*).
* sr : the next node (NODE_T1*).
It is specifically used when temperature with mode 1 was chosen.
*/
typedef struct NODE2_P1{

	int balance;
	STATION_P1 s;
	struct NODE2_P1* sl;
	struct NODE2_P1* sr;

}NODE2_P1;

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

/*
A function used to free all the nodes of tree.
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
NODE2_P1* createNODE2_P1(NODE2_P1* t, STATION_P1 p1) ;

/*
This function is called to modificate the orden of nodes in the tree to make it balanced.
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
This function is called to modificate the orden of nodes in the tree to make it balanced.
* t : given tree (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* doublerotateleftNODE2_P1(NODE2_P1* t);

/*
This function is called to modificate the orden of nodes in the tree to make it balanced.
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
