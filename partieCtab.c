#include <stdio.h>
#include <stdlib.h>


/* Order used for argv's content :    Si le C filtre les lieux et dates, sinon il faut enlever 10,11,12
0 : command's name
1 : the input file's path (-f option)
2 : the output file's path (-o option)
3 : 1 or 0 for temperature (-t option)
4 : 0,1,2 or 3 for the mode of -t
5 : 1 or 0 for pressure(-p option)
6 : 0,1,2 or 3 for the mode of -p
7 : 1 or 0 for wind (-w option)
8 : 1 or 0 for height (-h option)
9 : 1 or 0 for moisture (-m option)
10 : 0,1,2,3,4,5 or 6 for the chosen zone (-F ; -G ; -S ; -A ; -Q ; -O)
11 : Date 1 if specified, else 0 (-d option)
12 : Date 2 if specified, else 0 (-d option)
13 : 1 or 0 for descending sort
(14 : type of sort)
*/

int main(int argc, char* argv){
  
  
  
    FILE* input = fopen(argv[1],'r');            // The input file given by shell is opened.
    if(input==NULL){                             // Error code 2 if there was a problem opening the file.  
        return 2;
    }
    FILE* output = fopen(argv[2],'w');           // The output file given by shell is created or starts being rewritten.
    if(output==NULL){                            // Error code 3 if there was a problem with this file.
        return 3;
    }
  
  
  
    if(argv[13]==0){                              // The user did not activate descending sort.
        if(argv[3]==1 || argv[5]==1){             // Executes if temperature or pressure was chosen (we put them in the same "if" because their outputs are very similar).
            if(argv[4]==1 || argv[6]==1){         // Executes if mode 1 was chosen for temperature or pressure.
                tabTPsort11(input);
            }
            else if(argv[4]==2 || argv[6]==2){    // Executes if mode 2 was chosen for temperature or pressure.
                tabTPsort21(input);
            }
            else{                                 // Executes if mode 3 was chosen for temperature or pressure.
                tabTPsort31(input);
            }
        }
        else if(argv[7]==1){                      // Executes if wind was chosen.
            tabWsort1(input);
        }
        else if(argv[8]==1){                      // Executes if height was chosen.
            tabHsort1(input);
        }
        else{                                     // Executes if moisture was chosen.
            tabMsort1(input);
        }
    }
  
  
    else{                                         // The user activated descending sort.
        if(argv[3]==1 || argv[5]==1){         
            if(argv[4]==1 || argv[6]==1){         // Executes if mode 1 was chosen for temperature or pressure.
                tabTPsort12(input);
            }
            else if(argv[4]==2 || argv[6]==2){    // Executes if mode 2 was chosen for temperature or pressure.
                tabTPsort22(input);
            }
            else{                                 // Executes if mode 3 was chosen for temperature or pressure.
                tabTPsort32(input);
            }
        }
        else if(argv[7]==1){                      // Executes if wind was chosen.
            tabWsort2(input);
        }
        else if(argv[8]==1){                      // Executes if height was chosen.
            tabHsort2(input);
        }
        else{                                     // Executes if moisture was chosen.
            tabMsort2(input);
        }
    }
  
  
    return 0;                                     // If no error occured by now, the program executed successfully and returns 0.
}
