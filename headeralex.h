#include <stdio.h>
#include <stdlib.h>


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
This structure represents a station and various wind indicators.
* id          : the station's ID (int).
* orientation : the wind orientation in degrees (int).
* speed       : the wind speed in m/s (float).
It is specifically used in tabWsort1() and in tabWsort2(), when the user chose wind.
*/
typedef struct STATION_W{

    int id;
    int orientation;
    float speed;

}STATION_W;


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
int main(int argc, char* argv) ;


/*
A sorting function used to produce the output file when temperature with mode 1 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced temperature file contains stations sorted by their ID from lowest to highest number, and for each station, the maximal, minimal and average temperature values.
*/
int tabTsort11(FILE* f) ;

/*
A sorting function used to produce the output file when temperature with mode 1 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced temperature file contains stations sorted by their ID from highest to lowest number, and for each station, the maximal, minimal and average temperature values.
*/
int tabTsort12(FILE* f) ;

/*
A sorting function used to produce the output file when temperature with mode 2 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced temperature file contains, in chronological order, the average temperature values (average made on all the stations).
*/
int tabTsort21(FILE* f) ;

/*
A sorting function used to produce the output file when temperature with mode 2 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced temperature file contains, in reverse-chronological order, the average temperature values (average made on all the stations).
*/
int tabTsort22(FILE* f) ;

/*
A sorting function used to produce the output file when temperature with mode 3 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced temperature file contains the temperature values sorted in chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int tabTsort31(FILE* f) ;

/*
A sorting function used to produce the output file when temperature with mode 3 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given temperature file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced temperature file contains the temperature values sorted in reverse-chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int tabTsort32(FILE* f) ;

/*
A sorting function used to produce the output file when pressure with mode 1 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced pressure file contains stations sorted by their ID from lowest to highest number, and for each station, the maximal, minimal and average pressure values.
*/
int tabPsort11(FILE* f) ;

/*
A sorting function used to produce the output file when pressure with mode 1 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced pressure file contains stations sorted by their ID from highest to lowest number, and for each station, the maximal, minimal and average pressure values.
*/
int tabPsort12(FILE* f) ;

/*
A sorting function used to produce the output file when pressure with mode 2 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced pressure file contains, in chronological order, the average pressure values (average made on all the stations).
*/
int tabPsort21(FILE* f) ;

/*
A sorting function used to produce the output file when pressure with mode 2 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced pressure file contains, in reverse-chronological order, the average pressure values (average made on all the stations).
*/
int tabPsort22(FILE* f) ;

/*
A sorting function used to produce the output file when pressure with mode 3 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced pressure file contains the pressure values sorted in chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int tabPsort31(FILE* f) ;

/*
A sorting function used to produce the output file when pressure with mode 3 was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given pressure file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced pressure file contains the pressure values sorted in reverse-chronological order. For the same day and hour, station IDs are sorted from lowest to highest number.
*/
int tabPsort32(FILE* f) ;

/*
A sorting function used to produce the output file when wind was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given wind file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced wind file contains the average orientation and average speed of the wind for each station. The stations' IDs are sorted from lowest to highest number. 
*/
int tabWsort1(FILE* f) ;

/*
A sorting function used to produce the output file when wind was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given wind file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced wind file contains the average orientation and average speed of the wind for each station. The stations' IDs are sorted from highest to lowest number.
*/
int tabWsort2(FILE* f) ;

/*
A sorting function used to produce the output file when height was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given height file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced height file contains the stations' IDs and their height sorted from highest to lowest.
*/
int tabHsort1(FILE* f) ;

/*
A sorting function used to produce the output file when height was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given height file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced height file contains the stations' IDs and their height sorted from lowest to highest.
*/
int tabHsort2(FILE* f) ;

/*
A sorting function used to produce the output file when moisture was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given moisture file. It uses an array sorting method.
Specifically used when the descending sort was not activated by the user with the -r option.
The produced moisture file contains the stations' IDs and their maximal moisture value sorted from highest to lowest value.
*/
int tabMsort1(FILE* f) ;

/*
A sorting function used to produce the output file when moisture was chosen.
* f : given file, which is to be sorted.
* Returns 0 if it executes correctly, something else if not.
It is used to sort a given moisture file. It uses an array sorting method.
Specifically used when the descending sort was activated by the user with the -r option.
The produced moisture file contains the stations' IDs and their maximal moisture value sorted from lowest to highest value.
*/
int tabMsort2(FILE* f) ;
