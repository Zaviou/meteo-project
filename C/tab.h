
// #  \   `   |  ~   []  {}

#ifndef SHARED
	#define SHARED 1
	#include "shared.c"
#endif

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
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_T1*).
* Returns the lenght of l (int).
Specifically used when temperature with mode 1 was chosen.
*/
int getlenghtNODE_T1(NODE_T1* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing stations together with temperature measures (NODE_T1*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when temperature with mode 1 was chosen.
*/
int tabT1sort1(FILE* o,NODE_T1* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
It is the same as tabT1sort1(). The only difference is the inversion of sorting order.
* o : the file to write the new data in (FILE*).
* l : linked list containing stations together with temperature measures (NODE_T1*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when temperature with mode 1 was chosen.
*/
int tabT1sort2(FILE* o,NODE_T1* l) ;


/*
------------------------------------------------------------
MODE 2
------------------------------------------------------------
*/


/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_T2*).
* Returns the lenght of l (int).
Specifically used when temperature with mode 2 was chosen.
*/
int getlenghtNODE_T2(NODE_T2* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing dates together with temperature measures (NODE_T2*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when temperature with mode 2 was chosen.
*/
int tabT2sort1(FILE* o,NODE_T2* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It is the same as tabT2sort1(). The only difference is the inversion of sorting order.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing dates together with temperature measures (NODE_T2*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when temperature with mode 2 was chosen.
*/
int tabT2sort2(FILE* o,NODE_T2* l) ;


/*
------------------------------------------------------------
MODE 3
------------------------------------------------------------
*/


/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_T3*).
* Returns the lenght of l (int).
Specifically used when temperature with mode 3 was chosen.
*/
int getlenghtNODE_T3(NODE_T3* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing temperature measures (NODE_T3*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when temperature with mode 3 was chosen.
*/
int tabT3sort1(FILE* o,NODE_T3* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It is the same as tabT3sort1(). The only difference is the inversion of sorting order.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing temperature measures (NODE_T3*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when temperature with mode 3 was chosen.
*/
int tabT3sort2(FILE* o,NODE_T3* l) ;


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
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_P1*).
* Returns the lenght of l (int).
Specifically used when pressure with mode 1 was chosen.
*/
int getlenghtNODE_P1(NODE_P1* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing pressure measures (NODE_P1*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabP1sort1(FILE* o,NODE_P1* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It is the same as tabP1sort1(). The only difference is the inversion of sorting order.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing pressure measures (NODE_P1*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabP1sort2(FILE* o,NODE_P1* l) ;


/*
------------------------------------------------------------
MODE 2
------------------------------------------------------------
*/


/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_P2*).
* Returns the lenght of l (int).
Specifically used when pressure with mode 2 was chosen.
*/
int getlenghtNODE_P2(NODE_P2* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing pressure measures (NODE_P2*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabP2sort1(FILE* o,NODE_P2* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It is the same as tabP2sort1(). The only difference is the inversion of sorting order.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing pressure measures (NODE_P2*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabP2sort2(FILE* o,NODE_P2* l) ;


/*
------------------------------------------------------------
MODE 3
------------------------------------------------------------
*/


/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_P3*).
* Returns the lenght of l (int).
Specifically used when pressure with mode 3 was chosen.
*/
int getlenghtNODE_P3(NODE_P3* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing pressure measures (NODE_P3*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabP3sort1(FILE* o,NODE_P3* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It is the same as tabP3sort1(). The only difference is the inversion of sorting order.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing pressure measures (NODE_P3*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabP3sort2(FILE* o,NODE_P3* l) ;


/*
------------------------------------------------------------
WIND FUNCTIONS
------------------------------------------------------------
*/


/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_W*).
* Returns the lenght of l (int).
Specifically used when wind was chosen.
*/
int getlenghtNODE_W(NODE_W* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing wind measures (NODE_W*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabWsort1(FILE* o,NODE_W* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
It is the same as tabWsort1(). The only difference is the inversion of sorting order.
* o : the file to write the new data in (FILE*).
* l : linked list containing wind measures (NODE_W*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabWsort2(FILE* o,NODE_W* l) ;


/*
------------------------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------------------------
*/


/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_H*).
* Returns the lenght of l (int).
Specifically used when height was chosen.
*/
int getlenghtNODE_H(NODE_H* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing stations and their height (NODE_H*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabHsort1(FILE* o,NODE_H* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
It is the same as tabHsort1(). The only difference is the inversion of sorting order.
* o : the file to write the new data in (FILE*).
* l : linked list containing stations and their height (NODE_H*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabHsort2(FILE* o,NODE_H* l) ;


/*
------------------------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------------------------
*/


/*
This function is used to know the lenght of a linked list.
* l : the linked list (NODE_M*).
* Returns the lenght of l (int).
Specifically used when moisture was chosen.
*/
int getlenghtNODE_M(NODE_M* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
* o : the file to write the new data in (FILE*).
* l : linked list containing moisture measures (NODE_M*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabMsort1(FILE* o,NODE_M* l) ;


/*
The goal of this function is to sort a set of data contained in a linked list and to write the result of the sort in the file o.
It transforms the linked list into a static one that is then sorted using a bubble sort.
It is the same as tabMsort1(). The only difference is the inversion of sorting order.
* o : the file to write the new data in (FILE*).
* l : linked list containing moisture measures (NODE_M*).
* Returns 0 if it executes correctly, something else if not.
Specifically used when pressure with mode 1 was chosen.
*/
int tabMsort2(FILE* o,NODE_M* l) ;
