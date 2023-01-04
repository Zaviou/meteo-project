#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tab.c"

/*
------------------------------------------------------------
STRUCTURES
------------------------------------------------------------
*/


/*
This structure represents a station and various temperature indicators.
* id      : the station's ID (int).
* maximal : the station's known maximal temperature value in °C (float).
* minimal : the station's known minimal temperature value in °C (float).
* average : the station's average temperature value in °C (float).
* count : used to know how many times the station was encountered, to compute averages later (int).
It is specifically used in tabTsort11() and in tabTsort12(), when the user chose temperature with mode 1.
*/
typedef struct STATION_T1{

    int id;
    float maximal;
    float minimal;
    float average;
    int count;

}STATION_T1;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_T1).
* next : the next node (NODE_T1*).
It is specifically used when temperature with mode 1 was chosen.
*/
typedef struct NODE_T1{

    STATION_T1 s;
    struct NODE_T1* next;

}NODE_T1;

/*
This structure represents a time and temperature measures.
* id          : the station's ID (int).
* year        : the year at which the measure was taken (int).
* month       : the month at which the measure was taken (int).
* day         : the day at which the measure was taken (int).
* hour        : the hour at which the measure was taken (int).
* temperature : the temperature recorded at the time in °C (float).
It is specifically used in tabTsort21() and in tabTsort22(), when the user chose temperature with mode 2.
*/
typedef struct TIME_T2{

    int year;
    int month;
    int day;
    int hour;
    int count;
    float average;

}TIME_T2;

/*
This structure is used to build linked lists.
Each node contains informations about the day and hour's measures.
* t : the time considered (TIME_T2).
* next : the next node (NODE_T2*).
It is specifically used when temperature with mode 2 was chosen.
*/
typedef struct NODE_T2{

    TIME_T2 t;
    struct NODE_T2* next;

}NODE_T2;

/*
This structure represents a station and a temperature measure.
* id          : the station's ID (int).
* year        : the year at which the measure was taken (int).
* month       : the month at which the measure was taken (int).
* day         : the day at which the measure was taken (int).
* hour        : the hour at which the measure was taken (int).
* temperature : the temperature recorded at the time in °C (float).
It is specifically used in tabTsort31() and in tabTsort32(), when the user chose temperature with mode 3.
*/
typedef struct MEASURE_T3{

    int id;
    int year;
    int month;
    int day;
    int hour;
    float temperature;

}MEASURE_T3;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_T3).
* next : the next node (NODE_T3*).
It is specifically used when temperature with mode 3 was chosen.
*/
typedef struct NODE_T3{

    MEASURE_T3 m;
    struct NODE_T3* next;

}NODE_T3;


/*
This structure represents a station and various pressure indicators.
* id      : the station's ID (int).
* maximal : the station's known maximal pressure value in Pa (float).
* minimal : the station's known minimal pressure value in Pa (float).
* average : the station's average pressure value in Pa (float).
* count : used to know how many times the station was encountered before (int).
It is specifically used in tabPsort11() and in tabPsort12(), when the user chose pressure with mode 1.
*/
typedef struct STATION_P1{

    int id;
    float maximal;
    float minimal;
    float average;
    int count;

}STATION_P1;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_P1).
* next : the next node (NODE_P1*).
It is specifically used when pressure with mode 1 was chosen.
*/
typedef struct NODE_P1{

    STATION_P1 s;
    struct NODE_P1* next;

}NODE_P1;

/*
This structure represents a station and a pressure measure.
* id          : the station's ID (int).
* year        : the year at which the measure was taken (int).
* month       : the month at which the measure was taken (int).
* day         : the day at which the measure was taken (int).
* hour        : the hour at which the measure was taken (int).
* pressure    : the pressure recorded at the time in Pa (float).
It is specifically used in tabPsort21() and in tabPsort22(), when the user chose pressure with mode 2.
*/
typedef struct TIME_P2{

    int year;
    int month;
    int day;
    int hour;
    int count;
    float average;

}TIME_P2;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_P2).
* next : the next node (NODE_P2*).
It is specifically used when pressure with mode 2 was chosen.
*/
typedef struct NODE_P2{

    TIME_P2 t;
    struct NODE_P2* next;

}NODE_P2;

/*
This structure represents a station and a pressure measure.
* id          : the station's ID (int).
* year        : the year at which the measure was taken (int).
* month       : the month at which the measure was taken (int).
* day         : the day at which the measure was taken (int).
* hour        : the hour at which the measure was taken (int).
* pressure    : the pressure recorded at the time in Pa (float).
It is specifically used in tabPsort31() and in tabPsort32(), when the user chose pressure with mode 3.
*/
typedef struct MEASURE_P3{

    int id;
    int year;
    int month;
    int day;
    int hour;
    float pressure;

}MEASURE_P3;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_P3).
* next : the next node (NODE_P3*).
It is specifically used when pressure with mode 3 was chosen.
*/
typedef struct NODE_P3{

    MEASURE_P3 m;
    struct NODE_P3* next;

}NODE_P3;


/*
This structure represents a station and various wind indicators.
* id          : the station's ID (int).
* count       : number of times this station was encountered. Used for averaging (int).
* orientation : the wind orientation in degrees (int).
* speed       : the wind speed in m/s (float).
It is specifically used in tabWsort1() and in tabWsort2(), when the user chose wind.
*/
typedef struct STATION_W{

    int id;
    int count;
    int orientation;
    float speed;

}STATION_W;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_W).
* next : the next node (NODE_W*).
It is specifically used when wind was chosen.
*/
typedef struct NODE_W{

    STATION_W s;
    struct NODE_W* next;

}NODE_W;

/*
This structure represents a station and its height.
* id          : the station's ID (int).
* height      : the station's height in m (int).
It is specifically used in tabHsort1() and in tabHsort2(), when the user chose height.
*/
typedef struct STATION_H{

    int id;
    int height;

}STATION_H;


/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_H).
* next : the next node (NODE_H*).
It is specifically used when height was chosen.
*/
typedef struct NODE_H{

    STATION_H s;
    struct NODE_H* next;

}NODE_H;


/*
This structure represents a station and a moisture indicator.
* id          : the station's ID (int).
* maximal     : the station's known maximal moisture value in % (int).
It is specifically used in tabMsort1() and in tabMsort2(), when the user chose moisture.
*/
typedef struct STATION_M{

    int id;
    int maximal;

}STATION_M;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_M).
* next : the next node (NODE_M*).
It is specifically used when moisture was chosen.
*/
typedef struct NODE_M{

    STATION_M s;
    struct NODE_M* next;

}NODE_M;


/*
------------------------------------------------------------
FUNCTIONS
------------------------------------------------------------
*/


void UTCtime(int* year,int* month, int* day, int* hour, int* timezone) ;


/*
------------------------------------------------------------
TEMPERATURE FUNCTIONS
------------------------------------------------------------
*/

/*
------------------------------------------------------------
MODE 1
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_T1*).
Specifically used when temperature with mode 1 was chosen.
*/
void freeNODE_T1(NODE_T1* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_T1*).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when temperature with mode 1 was chosen.
*/
int inlistNODE_T1(NODE_T1* l,int id) ;

/*

*/
NODE_T1* addNODE_T1(NODE_T1* l,int id, float temperature, float minimaltemperature, float maximaltemperature) ;

NODE_T1* searchandchangevaluesNODE_T1(NODE_T1* l,int id,float temperature,float minimaltemperature,float maximaltemperature) ;

NODE_T1* averagingNODE_T1(NODE_T1* l) ;


/*
------------------------------------------------------------
MODE 2
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_T2*)
Specifically used when temperature with mode 2 was chosen.
*/
void freeNODE_T2(NODE_T2* l) ;

/*

*/
int inlistNODE_T2(NODE_T2* l,int year,int month, int day, int hour) ;

/*

*/
NODE_T2* addNODE_T2(NODE_T2* l,int year,int month, int day, int hour, float temperature) ;

NODE_T2* searchandchangevaluesNODE_T2(NODE_T2* l,int year,int month, int day, int hour,float temperature) ;

NODE_T2* averagingNODE_T2(NODE_T2* l) ;

int chronologicalorder_T2(TIME_T2 d1,TIME_T2 d2) ;

void producestring_T2(FILE* o,TIME_T2 date) ;

/*
------------------------------------------------------------
MODE 3
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_T3*)
Specifically used when temperature with mode 3 was chosen.
*/
void freeNODE_T3(NODE_T3* l) ;

/*

*/
NODE_T3* addNODE_T3(NODE_T3* l,int id,int year,int month, int day, int hour, float temperature) ;

int chronologicalorder_T3(MEASURE_T3 d1,MEASURE_T3 d2) ;

void producestring_T3(FILE* o,MEASURE_T3 measure) ;

NODE_T3* linkedlist_T3(FILE* f) ;


/*
------------------------------------------------------------
PRESSURE FUNCTIONS
------------------------------------------------------------
*/

/*
------------------------------------------------------------
MODE 1
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_P1*)
Specifically used when pressure with mode 1 was chosen.
*/
void freeNODE_P1(NODE_P1* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_P1*).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when pressure with mode 1 was chosen.
*/
int inlistNODE_P1(NODE_P1* l,int id) ;

/*

*/
NODE_P1* addNODE_P1(NODE_P1* l,int id, float pressure) ;

NODE_P1* searchandchangevaluesNODE_P1(NODE_P1* l,int id,float pressure) ;

NODE_P1* averagingNODE_P1(NODE_P1* l) ;

/*
------------------------------------------------------------
MODE 2
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_P2*)
Specifically used when pressure with mode 2 was chosen.
*/
void freeNODE_P2(NODE_P2* l) ;

/*

*/
int inlistNODE_P2(NODE_P2* l,int id) ;

/*

*/
NODE_P2* addNODE_P2(NODE_P2* l,int id, int height) ;

NODE_P2* searchandchangevaluesNODE_P2(NODE_P2* l,int year,int month, int day, int hour,float pressure) ;

NODE_P2* averagingNODE_P2(NODE_P2* l) ;

int chronologicalorder_P2(TIME_P2 d1,TIME_P2 d2) ;

void producestring_P2(FILE* o,TIME_P2 date) ;


/*
------------------------------------------------------------
MODE 3
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_P3*).
Specifically used when pressure with mode 3 was chosen.
*/
void freeNODE_P3(NODE_P3* l) ;

/*

*/
NODE_P3* addNODE_P3(NODE_P3* l,int id,int year,int month, int day, int hour, float pressure) ;

int chronologicalorder_P3(MEASURE_P3 d1,MEASURE_P3 d2) ;

void producestring_P3(FILE* o,MEASURE_P3 measure) ;

NODE_P3* linkedlist_P3(FILE* f) ;

/*
------------------------------------------------------------
WIND FUNCTIONS
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_W*)
Specifically used when wind was chosen.
*/
void freeNODE_W(NODE_W* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_W*).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not (int).
Specifically used when wind was chosen.
*/
int inlistNODE_W(NODE_W* l,int id) ;

/*
This function is used to create a new node (containing a not encountered yet station) and add it to a linked list.
The new node is added at the beginning of the list.
* l : linked list to which add the node (NODE_W*).
* id : ID of the station (int).
* orientation : wind orientation for the encountered measure (int).
* speed : wind speed for the encountered measure (float).
* Returns the new list (NODE_W*).
Specifically used when wind was chosen.
*/
NODE_W* addNODE_W(NODE_W* l,int id, int orientation, float speed) ;



/*
A function used when a station was already encountered in the wind file. This particular station is then already in the linked list.
It searches the position of the node containing the station, and adds the orientation and speed of the measure as well as one point to the 'count' variable.
This allows to compute an average later.
* l : the linked list (NODE_W*).
* id : ID of the already encountered station (int).
* orientation : wind orientation for the encountered measure (int).
* speed : wind speed for the encountered measure (float).
* Returns the linked list l (NODE_W*).
Specifically used when wind was chosen.
*/
NODE_W* searchandaddNODE_W(NODE_W* l,int id,int orientation,float speed) ;

/*
This function is used to compute the average wind orientation and speed for each station contained in l.
The input file needs to have been read entirely and all measures addded before its call. It divides the sums by the 'count' variable.
* l : the linked list (NODE_W*).
* Returns the linked list l.
Specifically used when wind was chosen.
*/
NODE_W* averagingNODE_W(NODE_W* l) ;

/*
------------------------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_H*)
Specifically used when height was chosen.
*/
void freeNODE_H(NODE_H* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_H*).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when height was chosen.
*/
int inlistNODE_H(NODE_H* l,int id) ;

/*
This function is used to add to a linked list a node containing a station that has not been encountered before in the input file.
The node is placed at the beginning of the list.
* l : the considered linked list (NODE_H*).
* id : ID of the new station (int).
* height : height value of the new station (int).
* Returns the new linked list (NODE_H*).
Specifically used when height was chosen.
*/
NODE_H* addNODE_H(NODE_H* l,int id, int height) ;


/*
------------------------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------------------------
*/

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_M*)
Specifically used when moisture was chosen.
*/
void freeNODE_M(NODE_M* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_M*).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when moisture was chosen.
*/
int inlistNODE_M(NODE_M* l,int id) ;

/*
This function is used to add to a linked list a node containing a station that has not been encountered before in the input file.
The node is placed at the beginning of the list.
* l : the considered linked list (NODE_M*).
* id : ID of the new station (int).
* moisture : moisture value of the encountered measure (int).
* Returns the new linked list (NODE_M*).
Specifically used when moisture was chosen.
*/
NODE_M* addNODE_M(NODE_M* l,int id, int moisture) ;

/*
This function is used when a measure read from the input file comes from a station that has already been encountered.
It searches for the station's node, and modifies it if the read moisture value is greater than the one currently set (since we need to search for a maximal value). 
* l : the considered linked list (NODE_M*).
* id : ID of the station (int).
* moisture : moisture value of the encountered measure (int).
* Returns the linked list (NODE_M*).
Specifically used when moisture was chosen.
*/
NODE_M* searchandmaybereplaceNODE_M(NODE_M* l,int id,int moisture) ;



