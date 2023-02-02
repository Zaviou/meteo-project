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
	long check;
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
	for(i=1;i<number_of_arguments;i++){
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
		else if(strcmp(list_of_arguments[i],"--avl")==0){ 
			sort=0;
		}
		else if(strcmp(list_of_arguments[i],"--abr")==0){ 
			sort=1;
		}
		else if(strcmp(list_of_arguments[i],"--tab")==0){ 
			sort=2;
		}
		else if(strcmp(list_of_arguments[i],"-r")==0){ 
			reverse=1;
		}
		else{
			exit(4);
		}
	}
	FILE* f=fopen(name_of_file_f, "r");
	if(f==NULL){
		exit(2);
	}
	fscanf(f, "%ld", &check);
	if(check==OPTION_T1){
		temperature_1=1;
	} 
	else if(check==OPTION_T2){
		temperature_2=1;
	} 
	else if(check==OPTION_T3){
		temperature_3=1;
	} 
	else if(check==OPTION_P1){
		pressure_1=1;
	} 
	else if(check==OPTION_P2){
		pressure_2=1;
	} 
	else if(check==OPTION_P3){ 
		pressure_3=1;
	} 
	else if(check==100){
		wind=1;
	} 
	else if(check==10){
		height=1;
	} 
	else if(check==OPTION_M){
		moisture=1;
	} 
	else exit(4);
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
				sort_H(f, o, 1);
			}
			else if(wind==1){
				sort_W(f, o, 1);
			}
			else if(moisture==1){
				sort_W(f, o, 1);
			}
			else if(pressure_1==1){
				sort_P1(f, o, 1);
			}
			else if(pressure_2==1){
				sort_P2(f, o, 1);
			}
			else if(pressure_3==1){
				sort_P3(f, o, 1);
			}
			else if(temperature_1==1){
				sort_T1(f, o, 1);
			}
			else if(temperature_2==1){
				sort_T2(f, o, 1);
			}
			else if(temperature_3==1){
				sort_T3(f, o, 1);
			}		
		}
		else if(sort==1){
			if(height==1){
				ABR_sort_H(f, o, 1);
			}
			else if(wind==1){
				ABR_sort_W(f, o, 1);
			}
			else if(moisture==1){
				ABR_sort_W(f, o, 1);
			}
			else if(pressure_1==1){
				ABR_sort_P1(f, o, 1);
			}
			else if(pressure_2==1){
				ABR_sort_P2(f, o, 1);
			}
			else if(pressure_3==1){
				ABR_sort_P3(f, o, 1);
			}
			else if(temperature_1==1){
				ABR_sort_T1(f, o, 1);
			}
			else if(temperature_2==1){
				ABR_sort_T2(f, o, 1);
			}
			else if(temperature_3==1){
				ABR_sort_T3(f, o, 1);
			}
		}
		else if(sort==2){
			if(height==1){
				tabHsort1(o,linkedlist_H(f));
			}
			else if(wind==1){
				tabWsort1(o, linkedlist_W(f));
			}
			else if(moisture==1){
				tabMsort1(o,linkedlist_M(f));
			}
			else if(pressure_1==1){
				tabP1sort1(o,linkedlist_P1(f));
			}
			else if(pressure_2==1){
				tabP2sort1(o,linkedlist_P2(f));
			}
			else if(pressure_3==1){
				tabP3sort1(o,linkedlist_P3(f));
			}
			else if(temperature_1==1){
				printf("\nBON APPEL\n");
				tabT1sort1(o,linkedlist_T1(f));
			}
			else if(temperature_2==1){
				tabT2sort1(o,linkedlist_T2(f));
			}
			else if(temperature_3==1){
				tabT3sort1(o,linkedlist_T3(f));
			}
		}		
	}
	else if(reverse==1){
		if(sort==0){
			if(height==1){
				sort_H(  f,   o, -1);
			}
			else if(wind==1){
				sort_W(  f,   o, -1);
			}
			else if(moisture==1){
				sort_W(  f,   o, -1);
			}
			else if(pressure_1==1){
				sort_P1(  f,   o, -1);
			}
			else if(pressure_2==1){
				sort_P2(  f,   o, -1);
			}
			else if(pressure_3==1){
				sort_P3(  f,   o, -1);
			}
			else if(temperature_1==1){
				sort_T1(  f,   o, -1);
			}
			else if(temperature_2==1){
				sort_T2(  f,   o, -1);
			}
			else if(temperature_3==1){
				sort_T3(  f,   o, -1);
			}		
		}
		else if(sort==1){
			if(height==1){
				ABR_sort_H(f, o, -1);
			}
			else if(wind==1){
				ABR_sort_W(f, o, -1);
			}
			else if(moisture==1){
				ABR_sort_W(f, o, -1);
			}
			else if(pressure_1==1){
				ABR_sort_P1(f, o, -1);
			}
			else if(pressure_2==1){
				ABR_sort_P2(f, o, -1);
			}
			else if(pressure_3==1){
				ABR_sort_P3(f, o, -1);
			}
			else if(temperature_1==1){
				ABR_sort_T1(f, o, -1);
			}
			else if(temperature_2==1){
				ABR_sort_T2(f, o, -1);
			}
			else if(temperature_3==1){
				ABR_sort_T3(f, o, -1);
			}
		}
		else if(sort==2){
			if(height==1){
				tabHsort2(  o,linkedlist_H(  f));
			}
			else if(wind==1){
				tabWsort2(  o, linkedlist_W(  f));
			}
			else if(moisture==1){
				tabMsort2(  o,linkedlist_M(  f));
			}
			else if(pressure_1==1){
				tabP1sort2(  o,linkedlist_P1(  f));
			}
			else if(pressure_2==1){
				tabP2sort2(  o,linkedlist_P2(  f));
			}
			else if(pressure_3==1){
				tabP3sort2(  o,linkedlist_P3(  f));
			}
			else if(temperature_1==1){
				tabT1sort2(  o,linkedlist_T1(  f));
			}
			else if(temperature_2==1){
				tabT2sort2(  o,linkedlist_T2(  f));
			}
			else if(temperature_3==1){
				tabT3sort2(  o,linkedlist_T3(  f));
			}
		}		
	}
	return 0;
}
