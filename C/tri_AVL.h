#include "headercommun.h"

/*
------------------------------------------------------------
STRUCTURES
------------------------------------------------------------
*/

/*
This structure is used to build a tree.
Each node contains informations about the station's pressure measures.
* balance : the height of the sun left's tree minus the height of the sun right's tree (int)
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
* t : the linked tree to be freed (NODE2_P1*).
Specifically used when pressure with mode 1 was chosen.
*/
void freeNODE2_P1(NODE2_P1* l) ;

/*
This function is called to create a node using malloc.
* t : given linked list (NODE2_P1*).
* p1 : (STATION_P1).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* createNODE2_P1(NODE2_P1* t, STATION_P1 p1) ;

/*
This function is called to add it as a node to t, together with pressure measures.
* t : given linked list (NODE2_P1*).
* p1 : (STATION_P1).
* h : (int*).
* r : (int).
Specifically used when pressure with mode 1 was chosen.
*/
NODE2_P1* addNODE2_P1(NODE2_P1* t, STATION_P1 p1, int* h, int r);

/*
This function is called to add it as a node to t, together with pressure measures.
* o : the way to the file to write the new data in (FILE*).
* t : given linked list (NODE2_P1*).
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