#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
It is specifically used in tabTsort11() and in tabTsort12(), when the user chose temperature with mode 1.
*/
typedef struct STATION_T1{

    int id;
    float maximal;
    float minimal;
    float average;

}STATION_T1;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_T1).
* next : the next node (NODE_T1).
It is specifically used when temperature with mode 1 was chosen.
*/
typedef struct NODE_T1{

    STATION_T1 s;
    struct NODE_T1* next;

}NODE_T1;

/*
This structure represents a station and a temperature measure.
* id          : the station's ID (int).
* year        : the year at which the measure was taken (int).
* month       : the month at which the measure was taken (int).
* day         : the day at which the measure was taken (int).
* hour        : the hour at which the measure was taken (int).
* temperature : the temperature recorded at the time in °C (float).
It is specifically used in tabTsort21() and in tabTsort22(), when the user chose temperature with mode 2.
*/
typedef struct STATION_T2{

    int id;
    int year;
    int month;
    int day;
    int hour;
    float temperature;

}STATION_T2;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_T2).
* next : the next node (NODE_T2).
It is specifically used when temperature with mode 2 was chosen.
*/
typedef struct NODE_T2{

    STATION_T2 s;
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
typedef struct STATION_T3{

    int id;
    int year;
    int month;
    int day;
    int hour;
    float temperature;

}STATION_T3;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_T3).
* next : the next node (NODE_T3).
It is specifically used when temperature with mode 3 was chosen.
*/
typedef struct NODE_T3{

    STATION_T3 s;
    struct NODE_T3* next;

}NODE_T3;


/*
This structure represents a station and various pressure indicators.
* id      : the station's ID (int)
* maximal : the station's known maximal pressure value in Pa (float)
* minimal : the station's known minimal pressure value in Pa (float)
* average : the station's average pressure value in Pa (float)
It is specifically used in tabPsort11() and in tabPsort12(), when the user chose pressure with mode 1.
*/
typedef struct STATION_P1{

    int id;
    float maximal;
    float minimal;
    float average;

}STATION_P1;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_P1).
* next : the next node (NODE_P1).
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
typedef struct STATION_P2{

    int id;
    int year;
    int month;
    int day;
    int hour;
    float pressure;

}STATION_P2;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_P2).
* next : the next node (NODE_P2).
It is specifically used when pressure with mode 2 was chosen.
*/
typedef struct NODE_P2{

    STATION_P2 s;
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
typedef struct STATION_P3{

    int id;
    int year;
    int month;
    int day;
    int hour;
    float pressure;

}STATION_P3;

/*
This structure is used to build linked lists.
Each node contains informations about the station's measures.
* s : the station (STATION_P3).
* next : the next node (NODE_P3).
It is specifically used when pressure with mode 3 was chosen.
*/
typedef struct NODE_P3{

    STATION_P3 s;
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
* next : the next node (NODE_W).
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
* next : the next node (NODE_H).
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
* next : the next node (NODE_M).
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


/*
The main function. Executes whenever the C program is called in the terminal.
* argc : number of arguments given when the C part is called. (int) 
* argv : list of all the arguments given. (char*)
         Arguments which are :
         argv[0] : The command's name (unused here)
         argv[1] : Path of the given file.
         argv[2] : Path of the produced file.
         argv[3] : 
         argv[4] :
         argv[5] :
         ...
* Returns 0 if it executes correctly, something else if not.
The goal of that function is to sort a file given by the shell program. The sorted file is written from scratch.
*/
//int main(int argc, char* argv) ;


/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_T1).
Specifically used when temperature with mode 1 was chosen.
*/
void freeNODE_T1(NODE_T1* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_T1).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when temperature with mode 1 was chosen.
*/
int inlistNODE_T1(NODE_T1* l,int id) ;

/*

*/
NODE_T1* addNODE_T1(NODE_T1* l,int id, int height) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_T1).
* Returns the lenght of l (int).
Specifically used when temperature with mode 1 was chosen.
*/
int getlenghtNODE_T1(NODE_T1* l) ;

/*
A sorting function used to produce the output file when temperature with mode 1 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced temperature file contains stations sorted by their ID from lowest to highest number, and for each station, the maximal, minimal and average temperature values.
*/
int tabTsort11(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when temperature with mode 1 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced temperature file contains stations sorted by their ID from highest to lowest number, and for each station, the maximal, minimal and average temperature values.
*/
int tabTsort12(FILE* f,FILE* o) ;

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_T2)
Specifically used when temperature with mode 2 was chosen.
*/
void freeNODE_T2(NODE_T2* l) ;

/*

*/
int inlistNODE_T2(NODE_T2* l,int id) ;

/*

*/
NODE_T2* addNODE_T2(NODE_T2* l,int id, int height) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_T2).
* Returns the lenght of l (int).
Specifically used when temperature with mode 2 was chosen.
*/
int getlenghtNODE_T2(NODE_T2* l) ;

/*
A sorting function used to produce the output file when temperature with mode 2 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced temperature file contains, in chronological order, the average temperature values (average made on all the stations).
*/
int tabTsort21(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when temperature with mode 2 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced temperature file contains, in reverse-chronological order, the average temperature values (average made on all the stations).
*/
int tabTsort22(FILE* f,FILE* o) ;

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_T3)
Specifically used when temperature with mode 3 was chosen.
*/
void freeNODE_T3(NODE_T3* l) ;

/*

*/
int inlistNODE_T3(NODE_T3* l,int id) ;

/*

*/
NODE_T3* addNODE_T3(NODE_T3* l,int id, int height) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_T3).
* Returns the lenght of l (int).
Specifically used when temperature with mode 3 was chosen.
*/
int getlenghtNODE_T3(NODE_T3* l) ;

/*
A sorting function used to produce the output file when temperature with mode 3 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced temperature file contains the temperature values sorted in chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int tabTsort31(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when temperature with mode 3 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced temperature file contains the temperature values sorted in reverse-chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int tabTsort32(FILE* f,FILE* o) ;

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_P1)
Specifically used when pressure with mode 1 was chosen.
*/
void freeNODE_P1(NODE_P1* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_P1).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when pressure with mode 1 was chosen.
*/
int inlistNODE_P1(NODE_P1* l,int id) ;

/*

*/
NODE_P1* addNODE_P1(NODE_P1* l,int id, int height) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_P1).
* Returns the lenght of l (int).
Specifically used when pressure with mode 1 was chosen.
*/
int getlenghtNODE_P1(NODE_P1* l) ;

/*
A sorting function used to produce the output file when pressure with mode 1 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced pressure file contains stations sorted by their ID from lowest to highest number, and for each station, the maximal, minimal and average pressure values.
*/
int tabPsort11(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when pressure with mode 1 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced pressure file contains stations sorted by their ID from highest to lowest number, and for each station, the maximal, minimal and average pressure values.
*/
int tabPsort12(FILE* f,FILE* o) ;

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_T1)
Specifically used when pressure with mode 2 was chosen.
*/
void freeNODE_P2(NODE_P2* l) ;

/*

*/
int inlistNODE_P2(NODE_P2* l,int id) ;

/*

*/
NODE_P2* addNODE_P2(NODE_P2* l,int id, int height) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_P2).
* Returns the lenght of l (int).
Specifically used when pressure with mode 2 was chosen.
*/
int getlenghtNODE_P2(NODE_P2* l) ;

/*
A sorting function used to produce the output file when pressure with mode 2 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced pressure file contains, in chronological order, the average pressure values (average made on all the stations).
*/
int tabPsort21(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when pressure with mode 2 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced pressure file contains, in reverse-chronological order, the average pressure values (average made on all the stations).
*/
int tabPsort22(FILE* f,FILE* o) ;

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_P3)
Specifically used when pressure with mode 3 was chosen.
*/
void freeNODE_P3(NODE_P3* l) ;

/*

*/
int inlistNODE_P3(NODE_P3* l,int id) ;

/*

*/
NODE_P3* addNODE_P3(NODE_P3* l,int id, int height) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_T1).
* Returns the lenght of l (int).
Specifically used when pressure with mode 3 was chosen.
*/
int getlenghtNODE_P3(NODE_P3* l) ;

/*
A sorting function used to produce the output file when pressure with mode 3 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced pressure file contains the pressure values sorted in chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int tabPsort31(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when pressure with mode 3 was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced pressure file contains the pressure values sorted in reverse-chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int tabPsort32(FILE* f,FILE* o) ;

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_W)
Specifically used when wind was chosen.
*/
void freeNODE_W(NODE_W* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_W).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when wind was chosen.
*/
int inlistNODE_W(NODE_W* l,int id) ;

/*

*/
NODE_W* addNODE_W(NODE_W* l,int id, int orientation, float speed) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_W).
* Returns the lenght of l (int).
Specifically used when wind was chosen.
*/
int getlenghtNODE_W(NODE_W* l) ;

/*
A sorting function used to produce the output file when wind was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given wind file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced wind file contains the average orientation and average speed of the wind for each station. The stations' IDs are sorted from lowest to highest number. 
*/
int tabWsort1(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when wind was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given wind file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced wind file contains the average orientation and average speed of the wind for each station. The stations' IDs are sorted from highest to lowest number.
*/
int tabWsort2(FILE* f,FILE* o) ;

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_H)
Specifically used when height was chosen.
*/
void freeNODE_H(NODE_H* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_H).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when height was chosen.
*/
int inlistNODE_H(NODE_H* l,int id) ;

/*

*/
NODE_H* addNODE_H(NODE_H* l,int id, int height) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_H).
* Returns the lenght of l (int).
Specifically used when height was chosen.
*/
int getlenghtNODE_H(NODE_H* l) ;

/*
A sorting function used to produce the output file when height was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given height file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced height file contains the stations' IDs and their height sorted from highest to lowest.
*/
int tabHsort1(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when height was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given height file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced height file contains the stations' IDs and their height sorted from lowest to highest.
*/
int tabHsort2(FILE* f,FILE* o) ;

/*
A function used to free all the nodes of a given list.
* l : the linked list to be freed (NODE_M)
Specifically used when moisture was chosen.
*/
void freeNODE_M(NODE_M* l) ;

/*
A function used to know if a particular station is in a list.
* l : the linked list (NODE_M).
* id : the station's id (int).
* Returns 1 if the station is in the list, 0 if not.
Specifically used when moisture was chosen.
*/
int inlistNODE_M(NODE_M* l,int id) ;

/*

*/
NODE_M* addNODE_M(NODE_M* l,int id, int height) ;

/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_M).
* Returns the lenght of l (int).
Specifically used when moisture was chosen.
*/
int getlenghtNODE_M(NODE_M* l) ;

/*
A sorting function used to produce the output file when moisture was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given moisture file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced moisture file contains the stations' IDs and their maximal moisture value sorted from highest to lowest value.
*/
int tabMsort1(FILE* f,FILE* o) ;

/*
A sorting function used to produce the output file when moisture was chosen.
* f : given file, which is to be sorted.
* o : output file used to store the new data
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given moisture file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced moisture file contains the stations' IDs and their maximal moisture value sorted from lowest to highest value.
*/
int tabMsort2(FILE* f, FILE* o) ;

