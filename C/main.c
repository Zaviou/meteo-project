#ifndef SHARED
	#define SHARED 1
	#include "shared.c"
#endif

#ifndef TAB
	#define TAB 1
	#include "tab.c"
#endif

#ifndef ABR
	#define ABR 1
	#include "abr.c"
#endif

#ifndef AVL
	#define AVL 1
	#include "avl.c"
#endif

int main(int number_of_arguments , char** list_of_arguments){
	/*
	This function takes as arguments the number of arguments sent by the shell code and the list of these arguments.
	This function returns 0 if everything works well.
	It returns 2 if there is an error with the entering file.
	It returns 3 if there is an error with the exiting file.
	It returns 4 if one of the arguments sent by the shell code isn't compatible with what was planned for this function. 
	*/
	int i;
	/*
	Each option that the user can choose is represented by a variable which is equal to 0 in the beginning. 
	If the option is chosen the value of the variable will be changed to 1.
	For the type of sorting the variable can be equal to 0, 1 or 2 corresponding to the type chosen. 
	*/
	int sort=0;
	int file_f=0;
	int file_o=0;
	int reverse=0;
	int height=0;
	int temperature_1=0;
	int temperature_2=0;
	int temperature_3=0;
	int pressure_1=0;
	int pressure_2=0;
	int pressure_3=0;
	int wind=0;
	int moisture=0;
	char* name_of_file_f;
	char* name_of_file_o;
	
	for(i=2;i<number_of_arguments;i++){
		if(strcmp(list_of_arguments[i],"-f")==0){
			file_f=1;
			i++;
			name_of_file_f=list_of_arguments[i];
		}
		else if(strcmp(list_of_arguments[i],"-o")==0){
			file_o=1;
			i++;
			name_of_file_o=list_of_arguments[i];
		}
		else if(strcmp(list_of_arguments[i],"-avl")==0){ 
			sort=0;
		}
		else if(strcmp(list_of_arguments[i],"-abr")==0){ 
			sort=1;
		}
		else if(strcmp(list_of_arguments[i],"-list")==0){ 
			sort=2;
		}
		else if(strcmp(list_of_arguments[i],"-r")==0){ 
			reverse=1;
		}
		else if(strcmp(list_of_arguments[i],"-h")==0){ 
			height=1;
		}
		else if(strcmp(list_of_arguments[i],"-p1")==0){ 
			pressure_1=1;
		}
		else if(strcmp(list_of_arguments[i],"-p2")==0){ 
			pressure_2=1;
		}
		else if(strcmp(list_of_arguments[i],"-p3")==0){ 
			pressure_3=1;
		}
		else if(strcmp(list_of_arguments[i],"-t1")==0){ 
			temperature_1=1;
		}
		else if(strcmp(list_of_arguments[i],"-t2")==0){ 
			temperature_2=1;
		}
		else if(strcmp(list_of_arguments[i],"-t3")==0){ 
			temperature_3=1;
		}
		else if(strcmp(list_of_arguments[i],"-w")==0){ 
			wind=1;
		}
		else if(strcmp(list_of_arguments[i],"-m")==0){ 
			moisture=1;
		}
		else{
			exit(4);
		}
	}

	FILE* f=fopen(name_of_file_f, "r");
	if(f==NULL){
		exit(2);
	}
	FILE* o=fopen(name_of_file_o, "w");
	if(o==NULL){
		exit(3);
	}

	/*
	For each option chosen, the function assignated to sort the concerned data is called.
	*/
	if(reverse==0){
		if(sort==0){
			if(height==1){
				sort_H(name_of_file_f, name_of_file_o, 1);
			}
			else if(wind==1){
				sort_W(name_of_file_f, name_of_file_o, 1);
			}
			else if(moisture==1){
				sort_W(name_of_file_f, name_of_file_o, 1);
			}
			else if(pressure_1==1){
				sort_P1(name_of_file_f, name_of_file_o, 1);
			}
			else if(pressure_2==1){
				sort_P2(name_of_file_f, name_of_file_o, 1);
			}
			else if(pressure_3==1){
				sort_P3(name_of_file_f, name_of_file_o, 1);
			}
			else if(temperature_1==1){
				sort_T1(name_of_file_f, name_of_file_o, 1);
			}
			else if(temperature_2==1){
				sort_T2(name_of_file_f, name_of_file_o, 1);
			}
			else if(temperature_3==1){
				sort_T3(name_of_file_f, name_of_file_o, 1);
			}		
		}
		else if(sort==1){
				
		}
		else if(sort==2){
			if(height==1){
				tabHsort1(name_of_file_o,linkedlist_H(name_of_file_f));
			}
			else if(wind==1){
				tabWsort1(name_of_file_o, linkedlist_W(name_of_file_f));
			}
			else if(moisture==1){
				tabMsort1(name_of_file_o,linkedlist_M(name_of_file_f));
			}
			else if(pressure_1==1){
				tabP1sort1(name_of_file_o,linkedlist_P1(name_of_file_f));
			}
			else if(pressure_2==1){
				tabP2sort1(name_of_file_o,linkedlist_P2(name_of_file_f));
			}
			else if(pressure_3==1){
				tabP3sort1(name_of_file_o,linkedlist_P3(name_of_file_f));
			}
			else if(temperature_1==1){
				tabT1sort1(name_of_file_o,linkedlist_T1(name_of_file_f));
			}
			else if(temperature_2==1){
				tabT2sort1(name_of_file_o,linkedlist_T2(name_of_file_f));
			}
			else if(temperature_3==1){
				tabT3sort1(name_of_file_o,linkedlist_T3(name_of_file_f));
			}
		}		
	}
	else if(reverse==1){
		if(sort==0){
			if(height==1){
				sort_H(name_of_file_f, name_of_file_o, -1);
			}
			else if(wind==1){
				sort_W(name_of_file_f, name_of_file_o, -1);
			}
			else if(moisture==1){
				sort_W(name_of_file_f, name_of_file_o, -1);
			}
			else if(pressure_1==1){
				sort_P1(name_of_file_f, name_of_file_o, -1);
			}
			else if(pressure_2==1){
				sort_P2(name_of_file_f, name_of_file_o, -1);
			}
			else if(pressure_3==1){
				sort_P3(name_of_file_f, name_of_file_o, -1);
			}
			else if(temperature_1==1){
				sort_T1(name_of_file_f, name_of_file_o, -1);
			}
			else if(temperature_2==1){
				sort_T2(name_of_file_f, name_of_file_o, -1);
			}
			else if(temperature_3==1){
				sort_T3(name_of_file_f, name_of_file_o, -1);
			}		
		}
		else if(sort==1){
				
		}
		else if(sort==2){
			if(height==1){
				tabHsort2(name_of_file_o,linkedlist_H(name_of_file_f));
			}
			else if(wind==1){
				tabWsort2(name_of_file_o, linkedlist_W(name_of_file_f));
			}
			else if(moisture==1){
				tabMsort2(name_of_file_o,linkedlist_M(name_of_file_f));
			}
			else if(pressure_1==1){
				tabP1sort2(name_of_file_o,linkedlist_P1(name_of_file_f));
			}
			else if(pressure_2==1){
				tabP2sort2(name_of_file_o,linkedlist_P2(name_of_file_f));
			}
			else if(pressure_3==1){
				tabP3sort2(name_of_file_o,linkedlist_P3(name_of_file_f));
			}
			else if(temperature_1==1){
				tabT1sort2(name_of_file_o,linkedlist_T1(name_of_file_f));
			}
			else if(temperature_2==1){
				tabT2sort2(name_of_file_o,linkedlist_T2(name_of_file_f));
			}
			else if(temperature_3==1){
				tabT3sort2(name_of_file_o,linkedlist_T3(name_of_file_f));
			}
		}		
	}
	return 0;
}
