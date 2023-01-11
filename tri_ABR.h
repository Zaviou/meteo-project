
#include "headercommun.h"

/*
------------------------------------------------------------
STRUCTURES
------------------------------------------------------------
*/

/*
This structure is used to build an abr.
Each node contains informations about the station's measures.
* s : the station (STATION_T1).
* sl : the son left (NODE2_T1*).
* sr : the son right (NODE2_T1*).
It is specifically used when temperature with mode 1 was chosen.
*/
typedef struct NODE2_T1{

	STATION_T1 s;
	struct NODE2_T1* sl;
	struct NODE2_T1* sr;

}NODE2_T1;

/*
This structure is used to build linked lists.
Each node contains informations about temperature at a given time.
* t : the time considered (TIME_T2).
* sl : the son left (NODE2_T2*).
* sr : the son right (NODE2_T2*).
It is specifically used when temperature with mode 2 was chosen.
*/
typedef struct NODE2_T2{

	TIME_T2 t;
	struct NODE2_T2* sl;
	struct NODE2_T2* sr;

}NODE2_T2;

/*
This structure is used to build linked lists.
Each node contains informations about temperature at a given time.
* t : the time considered (TIME_T3).
* sl : the son left (NODE2_T3*).
* sr : the son right (NODE2_T3*).
It is specifically used when temperature with mode 3 was chosen.
*/
typedef struct NODE2_T3{

	MEASURE_T3 m;
	struct NODE2_T3* sl;
	struct NODE2_T3* sr;
	
}NODE2_T3;

/*
This structure is used to build an abr.
Each node contains informations about the station's measures.
* s : the station (STATION_P1).
* sl : the son left (NODE2_P1*).
* sr : the son right (NODE2_P1*).
It is specifically used when pressure with mode 1 was chosen.
*/
typedef struct NODE2_P1{

	STATION_P1 s;
	struct NODE2_P1* sl;
	struct NODE2_P1* sr;

}NODE2_P1;

/*
This structure is used to build an abr.
Each node contains informations about the station's measures.
* s : the station (STATION_P2).
* sl : the son left (NODE2_P2*).
* sr : the son right (NODE2_P2*).
It is specifically used when pressure with mode 2 was chosen.
*/
typedef struct NODE2_P2{

	STATION_P2 t;
	struct NODE2_P2* sl;
	struct NODE2_P2* sr;

}NODE2_P2;

/*
This structure is used to build an abr.
Each node contains informations about the station's measures.
* s : the station (STATION_P3).
* sl : the son left (NODE2_P3*).
* sr : the son right (NODE2_P3*).
It is specifically used when pressure with mode 3 was chosen.
*/
typedef struct NODE2_P3{

	STATION_P3 m;
	struct NODE2_P3* sl;
	struct NODE2_P3* sr;

}NODE2_P3;

/*
This structure is used to build an abr.
Each node contains informations about the station's measures.
* s : the station (STATION_W).
* sl : the son left (NODE2_W*).
* sr : the son right (NODE2_W*).
It is specifically used when wind was chosen.
*/
typedef struct NODE2_W{

	STATION_W s;
	struct NODE2_W* sl;
	struct NODE2_W* sr;

}NODE2_W;

/*
This structure is used to build an abr.
Each node contains informations about the station's measures.
* s : the station (STATION_H).
* sl : the son left (NODE2_H*).
* sr : the son right (NODE2_H*).
It is specifically used when height was chosen.
*/
typedef struct NODE_H{

	STATION_H s;
	struct NODE2_H* sl;
	struct NODE2_H* sr;

}NODE2_H;

/*
This structure is used to build an abr.
Each node contains informations about the station's measures.
* s : the station (STATION_M).
* sl : the son left (NODE2_M*).
* sr : the son right (NODE2_M*).
It is specifically used when moisture was chosen.
*/
typedef struct NODE2_M{

	STATION_M s;
	struct NODE2_M* sl;
	struct NODE2_m* sr;

}NODE2_M;


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
Specifically used when temperature with mode 1 was chosen.
*/
int freeNODE2_T1(NODE2_T1* t) ;

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
