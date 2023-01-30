
// #  \   `   |  ~   []  {}

#ifndef HEADERSHARED
	#define HEADERSHARED 1
	#include "shared.h"
#endif



void UTCtime(int* year,int* month, int* day, int* hour, int* timezone){
    // To begin this function, the hour is directly modified to match the timezone +00:00
    // If other adjustements need to be done (the hour is now at an impossible value), year, month and day can be modified.
    // The months are a special case because they don't always have the same number of days.
    // Throughout this function, it is pointers that are modified to allow returning multiple values.
    *hour = *hour - *timezone;
    if(*hour < 0){
        *hour = 24 + *hour;
        *day-=1;
        if(*day < 1){
            *month-=1;
            if(*month < 1){
                *month = 12;
                *day=31;
                *year-=1;
            }
            else if(*month==2){
                *day=28;
            }
            else if(*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10){
                *day=31;
            }
            else{
                *day=30;
            }
        }
    }
}


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


void freeNODE_T1(NODE_T1* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_T1* temp = l;
        l=l->next;
        free(temp);
    }
}


int inlistNODE_T1(NODE_T1* l,int id){
    // To know if the station which ID is 'id' is already in the list, we have to get through all of it.
    // If it is found in one of the nodes, 1 is returned.
    NODE_T1* temp=l;
    while(temp!=NULL){
        if(temp->s.id==id){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


NODE_T1* addNODE_T1(NODE_T1* l,int id, float temperature, float minimaltemperature, float maximaltemperature){
    // A new node is created using malloc (we use the freeing function later to not waste memory)
    // The parameters set the values of the structure inside it.
    // The count is set to one because when this function is called, we have encountered an id for the first time.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_T1* new = malloc(sizeof(NODE_T1));
    if(new==NULL){
        printf("Error : addNODE_T1");
        exit(4);
    }
    new->s.id=id;
    new->s.average=temperature;
    new->s.minimal=minimaltemperature;
    new->s.maximal=maximaltemperature;
    new->s.count=1;
    new->next=l;
    return new;
}


NODE_T1* searchandchangevaluesNODE_T1(NODE_T1* l,int id,float temperature,float minimaltemperature,float maximaltemperature){
    // This function first goes through the list to find the structure representing the station of ID 'id'. 
    // It is in the list as we have called another function before to know it.
    // Then, if the maximal value parameter is higher than the current one for the station, it is uptdated. Same for the minimal value.
    // Since we have seen the station one more time, the count is augmented. The temperature measured is also added to the sum to calculate the average later.
    NODE_T1* temp=l;
    while(temp!=NULL){
        if(temp->s.id == id){
            if(temp->s.maximal < maximaltemperature){
                temp->s.maximal = maximaltemperature;
            }
            if(temp->s.minimal > minimaltemperature){
                temp->s.minimal = minimaltemperature;
            }
            temp->s.average+=temperature;
            temp->s.count+=1;
            return l;
        }
        temp=temp->next;
    }
}


NODE_T1* averagingNODE_T1(NODE_T1* l){
    // To calculate the averages of the measures, all has been set up before, in the functions that change the linked list.
    // The sums of all the encountered measures are divided by the number of times the station was encountered. This for each node.
    NODE_T1* temp=l;
    while(temp!=NULL){
        temp->s.average = (temp->s.average)/(temp->s.count);
        temp=temp->next;
    }
    return l;
}


NODE_T1* linkedlist_T1(FILE* f){
    // Lines (measures) are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "Station ID;temperature;minimal temperature over 24 hrs;maximal temperature over 24hrs"
    // If the station was not seen before, we add a new node representing it.
    // If it was already seen, we search for the node representing it and uptdate its values.
    // The average values need to be calculated at the end. We use a special function to proceed.
    // The linked list representing all the encountered stations is returned at the end.
    NODE_T1* l = NULL;
    int id;
    float temperature;
    float minimaltemperature;
    float maximaltemperature;
    while(feof(f)==0){
		if(fscanf(f,"%d;%f;%f;%f",&id,&temperature,&minimaltemperature,&maximaltemperature)==4){
		        if(inlistNODE_T1(l,id)==0){                               
            		l = addNODE_T1(l,id,temperature,minimaltemperature,maximaltemperature);
        		}
        		else{                                                        
            		l = searchandchangevaluesNODE_T1(l,id,temperature,minimaltemperature,maximaltemperature);
        		}
		}
    }
    l=averagingNODE_T1(l);
    return l;
}


/*
------------------------------------------
MODE 2
------------------------------------------
*/


void freeNODE_T2(NODE_T2* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_T2* temp = l;
        l=l->next;
        free(temp);
    }
}


int inlistNODE_T2(NODE_T2* l,int year,int month, int day, int hour){
    // To know if the date defined by 'year','month','day','hour' is already in the list, we have to get through all of it.
    // If it is found in one of the nodes, 1 is returned.
    NODE_T2* temp=l;
    while(temp!=NULL){
        if(temp->t.year == year && temp->t.month == month && temp->t.day == day && temp->t.hour == hour){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


NODE_T2* addNODE_T2(NODE_T2* l,int year,int month, int day, int hour, float temperature){
    // A new node is created using malloc (we use the freeing function later to not waste memory)
    // The parameters set the values of the structure inside it.
    // The count is set to one because when this function is called, we have encountered a date for the first time.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_T2* new = malloc(sizeof(NODE_T2));
    if(new==NULL){
        printf("Error : addNODE_T2");
        exit(4);
    }
    new->t.year=year;
    new->t.month=month;
    new->t.day=day;
    new->t.hour=hour;
    new->t.count=1;
    new->t.average=temperature;
    new->next=l;
    return new;
}


NODE_T2* searchandchangevaluesNODE_T2(NODE_T2* l,int year,int month, int day, int hour,float temperature){
    // This function first goes through the list to find the structure representing the time defined by the parameters. 
    // It is in the list as we have called another function before to know it.
    // Since we have seen this given date one more time, the count is augmented. The temperature measured is also added to the sum to calculate the average later.
    NODE_T2* temp=l;
    while(temp!=NULL){
        if(temp->t.year == year && temp->t.month == month && temp->t.day == day && temp->t.hour == hour ){
            temp->t.average = temp->t.average + temperature;
            temp->t.count+=1;
            return l;
        }
        temp=temp->next;
    }
}


NODE_T2* averagingNODE_T2(NODE_T2* l){
    // To calculate the averages of the measures, all has been set up before, in the functions that change the linked list.
    // The sums of all the encountered measures are divided by the number of times the date was encountered. This for each node.
    NODE_T2* temp=l;
    while(temp!=NULL){
        temp->t.average = (temp->t.average)/(temp->t.count);
        temp=temp->next;
    }
    return l;
}


int chronologicalorder_T2(TIME_T2 d1,TIME_T2 d2){
    // Comparisons are made between the time values that are in the structures to know if the first date comes after the second.
    // When all the possibilities for that have been explored, 1 is returned because the dates are in the right order.
    if(d1.year > d2.year){
        return 0;
    }
    else if(d1.year==d2.year){
        if(d1.month > d2.month){
            return 0;
        }
        else if(d1.month == d2.month){
            if(d1.day > d2.day){
                return 0;
            }
            else if(d1.day == d2.day){
                if(d1.hour > d2.hour){
                    return 0;
                }
            }
        }
    }
    return 1;
}


void producestring_T2(FILE* o,TIME_T2 date){
    // This function is used to always write the same format for a measure, inside the file o.
    // Since most values are stored as integers, directly printing is sometimes not effective as some 0s may be missing.
    // Checks are made to counter this and use the right fprintf each time.
    fprintf(o,"%d-",date.year);
    if(date.month < 10){
        fprintf(o,"0%d-",date.month);
    }
    else{
        fprintf(o,"%d-",date.month);
    }
    if(date.day < 10){
        fprintf(o,"0%dT",date.day);
    }
    else{
        fprintf(o,"%dT",date.day);
    }
    if(date.hour < 10){
        fprintf(o,"0%d:00:00;",date.hour);
    }
    else{
        fprintf(o,"%d:00:00;",date.hour);
    }
    fprintf(o,"%f\n",date.average);
}


NODE_T2* linkedlist_T2(FILE* f){
    // Lines (measures) are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "datetime;temperature"
    // All dates are changed to match UTC time.
    // If a date was not seen before, we add a new node representing it.
    // If it was already seen, we search for the node representing it and uptdate its values.
    // The average values need to be calculated at the end. We use a special function to proceed.
    // The linked list representing all the encountered dates is returned at the end.
    NODE_T2* l = NULL;
    int year;
    int month;
    int day;
    int hour;
    int timezone;
    float temperature;
    while(feof(f)==0){
		if(fscanf(f,"%d-%d-%dT%d:00:00+%d:00;%f\n",&year,&month,&day,&hour,&timezone,&temperature)==6){
			    UTCtime(&year,&month,&day,&hour,&timezone);                       
        		if(inlistNODE_T2(l,year,month,day,hour)==0){                               
           			l = addNODE_T2(l,year,month,day,hour,temperature);
        		}
        		else{                                                     
            		l = searchandchangevaluesNODE_T2(l,year,month,day,hour,temperature);
        		}
		}                                           
    }
    l=averagingNODE_T2(l);
    return l;
}


/*
------------------------------------------
MODE 3
------------------------------------------
*/


void freeNODE_T3(NODE_T3* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_T3* temp = l;
        l=l->next;
        free(temp);
    }
}


NODE_T3* addNODE_T3(NODE_T3* l,int id,int year,int month, int day, int hour, float temperature){
    // A new node is created using malloc (we use the freeing function later to not waste memory)
    // The parameters set the values of the structure inside it.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_T3* new = malloc(sizeof(NODE_T3));
    if(new==NULL){
        printf("Error : addNODE_T3");
        exit(4);
    }
    new->m.id=id;
    new->m.year=year;
    new->m.month=month;
    new->m.day=day;
    new->m.hour=hour;
    new->m.temperature=temperature;
    new->next=l;
    return new;
}


int chronologicalorder_T3(MEASURE_T3 d1,MEASURE_T3 d2){
    // Comparisons are made between the time values that are in the structures to know if the first date comes after the second.
    // When all the possibilities for that have been explored, 1 is returned because the dates are in the right order.
    if(d1.year > d2.year){
        return 0;
    }
    else if(d1.year==d2.year){
        if(d1.month > d2.month){
            return 0;
        }
        else if(d1.month == d2.month){
            if(d1.day > d2.day){
                return 0;
            }
            else if(d1.day == d2.day){
                if(d1.hour > d2.hour){
                    return 0;
                }
            }
        }
    }
    return 1;
}


void producestring_T3(FILE* o,MEASURE_T3 measure){
    // This function is used to always write the same format for a measure, inside the file o.
    // Since most values are stored as integers, directly printing is sometimes not effective as some 0s may be missing.
    // Checks are made to counter this and use the right fprintf each time.
    fprintf(o,"%d-",measure.year);
    if(measure.month < 10){
        fprintf(o,"0%d-",measure.month);
    }
    else{
        fprintf(o,"%d-",measure.month);
    }
    if(measure.day < 10){
        fprintf(o,"0%dT",measure.day);
    }
    else{
        fprintf(o,"%dT",measure.day);
    }
    if(measure.hour < 10){
        fprintf(o,"0%d:00:00;",measure.hour);
    }
    else{
        fprintf(o,"%d:00:00;",measure.hour);
    }
    if(measure.id <= 9999 ){
        fprintf(o,"0%d;%f\n",measure.id,measure.temperature);
    }
    else{
        fprintf(o,"%d;%f\n",measure.id,measure.temperature);
    }
}


NODE_T3* linkedlist_T3(FILE* f){
    // Lines (measures) are read from the input file until its end.
    // A linked list is built. A node is added for each measure.
    // Format of the measure : "Station ID;datetime;temperature"
    // All dates are changed to match UTC time.
    // The linked list representing all the encountered measures is returned at the end.
    NODE_T3* l = NULL;
    int id;
    int year;
    int month;
    int day;
    int hour;
    int timezone;
    float temperature;
    while(feof(f)==0){
		if(fscanf(f,"%d;%d-%d-%dT%d:00:00+%d:00;%f\n",&id,&year,&month,&day,&hour,&timezone,&temperature)==7){
			UTCtime(&year,&month,&day,&hour,&timezone);                       
       	 	l=addNODE_T3(l,id,year,month,day,hour,temperature);
		}                                            
    }
    return l;
}


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


void freeNODE_P1(NODE_P1* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_P1* temp = l;
        l=l->next;
        free(temp);
    }
}


int inlistNODE_P1(NODE_P1* l,int id){
    // To know if the station which ID is 'id' is already in the list, we have to get through all of it.
    // If it is found in one of the nodes, 1 is returned.
    NODE_P1* temp=l;
    while(temp!=NULL){
        if(temp->s.id==id){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


NODE_P1* addNODE_P1(NODE_P1* l,int id, float pressure){
    // A new node is created using malloc (we use the freeing function later to not waste memory)
    // The parameters set the values of the structure inside it.
    // The count is set to one because when this function is called, we have encountered an id for the first time.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_P1* new = malloc(sizeof(NODE_P1));
    if(new==NULL){
        printf("Error : addNODE_P1");
        exit(4);
    }
    new->s.id=id;
    new->s.average=pressure;
    new->s.minimal=pressure;
    new->s.maximal=pressure;
    new->s.count=1;
    new->next=l;
    return new;
}


NODE_P1* searchandchangevaluesNODE_P1(NODE_P1* l,int id,float pressure){
    // This function first goes through the list to find the structure representing the station of ID 'id'. 
    // It is in the list as we have called another function before to know it.
    // Then, if the maximal value parameter is higher than the current one for the station, it is uptdated. Same for the minimal value.
    // Since we have seen the station one more time, the count is augmented. The pressure measured is also added to the sum to calculate the average later.
    NODE_P1* temp=l;
    while(temp!=NULL){
        if(temp->s.id == id){
            if(temp->s.maximal < pressure){
                temp->s.maximal = pressure;
            }
            if(temp->s.minimal > pressure){
                temp->s.minimal = pressure;
            }
            temp->s.average+=pressure;
            temp->s.count+=1;
            return l;
        }
        temp=temp->next;
    }
}


NODE_P1* averagingNODE_P1(NODE_P1* l){
    // To calculate the averages of the measures, all has been set up before, in the functions that change the linked list.
    // The sums of all the encountered measures are divided by the number of times the station was encountered. This for each node.
    NODE_P1* temp=l;
    while(temp!=NULL){
        temp->s.average = (temp->s.average)/(temp->s.count);
        temp=temp->next;
    }
    return l;
}


NODE_P1* linkedlist_P1(FILE* f){
    // Lines (measures) are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "Station ID;pressure"
    // If the station was not seen before, we add a new node representing it.
    // If it was already seen, we search for the node representing it and uptdate its values.
    // The average values need to be calculated at the end. We use a special function to proceed.
    // The linked list representing all the encountered stations is returned at the end.
    NODE_P1* l = NULL;
    int id;
    float pressure;
    while(feof(f)==0){
		if(fscanf(f,"%d;%f",&id,&pressure)==2){
			if(inlistNODE_P1(l,id)==0){                            
            	l = addNODE_P1(l,id,pressure);
        	}
        	else{                 
            	l = searchandchangevaluesNODE_P1(l,id,pressure);
        	}
		}                                            
    }
    l=averagingNODE_P1(l);
    return l;
}


/*
------------------------------------------
MODE 2
------------------------------------------
*/


void freeNODE_P2(NODE_P2* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_P2* temp = l;
        l=l->next;
        free(temp);
    }
}


int inlistNODE_P2(NODE_P2* l,int year,int month, int day, int hour){
    // To know if the date defined by 'year','month','day','hour' is already in the list, we have to get through all of it.
    // If it is found in one of the nodes, 1 is returned.
    NODE_P2* temp=l;
    while(temp!=NULL){
        if(temp->t.year == year && temp->t.month == month && temp->t.day == day && temp->t.hour == hour){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


NODE_P2* addNODE_P2(NODE_P2* l,int year,int month, int day, int hour, float pressure){
    // A new node is created using malloc (we use the freeing function later to not waste memory).
    // The parameters set the values of the structure inside it.
    // The count is set to one because when this function is called, we have encountered a date for the first time.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_P2* new = malloc(sizeof(NODE_P2));
    if(new==NULL){
        printf("Error : addNODE_P2");
        exit(4);
    }
    new->t.year=year;
    new->t.month=month;
    new->t.day=day;
    new->t.hour=hour;
    new->t.count=1;
    new->t.average=pressure;
    new->next=l;
    return new;
}


NODE_P2* searchandchangevaluesNODE_P2(NODE_P2* l,int year,int month, int day, int hour,float pressure){
    // This function first goes through the list to find the structure representing the date given by the parameters.. 
    // It is in the list as we have called another function before to know it.
    // Since we have seen the station one more time, the count is augmented. The pressure measured is also added to the sum to calculate the average later.
    NODE_P2* temp=l;
    while(temp!=NULL){
        if(temp->t.year == year && temp->t.month == month && temp->t.day == day && temp->t.hour == hour ){
            temp->t.average = temp->t.average + pressure;
            temp->t.count+=1;
            return l;
        }
        temp=temp->next;
    }
}


NODE_P2* averagingNODE_P2(NODE_P2* l){
    // To calculate the averages of the measures, all has been set up before, in the functions that change the linked list.
    // The sums of all the encountered measures are divided by the number of times the date was encountered. This for each node.
    NODE_P2* temp=l;
    while(temp!=NULL){
        temp->t.average = (temp->t.average)/(temp->t.count);
        temp=temp->next;
    }
    return l;
}


int chronologicalorder_P2(TIME_P2 d1,TIME_P2 d2){
    // Comparisons are made between the time values that are in the structures to know if the first date comes after the second.
    // When all the possibilities for that have been explored, 1 is returned because the dates are in the right order.
    if(d1.year > d2.year){
        return 0;
    }
    else if(d1.year==d2.year){
        if(d1.month > d2.month){
            return 0;
        }
        else if(d1.month == d2.month){
            if(d1.day > d2.day){
                return 0;
            }
            else if(d1.day == d2.day){
                if(d1.hour > d2.hour){
                    return 0;
                }
            }
        }
    }
    return 1;
}


void producestring_P2(FILE* o,TIME_P2 date){
    // This function is used to always write the same format for a measure, inside the file o.
    // Since most values are stored as integers, directly printing is sometimes not effective as some 0s may be missing.
    // Checks are made to counter this and use the right fprintf each time.
    fprintf(o,"%d-",date.year);
    if(date.month < 10){
        fprintf(o,"0%d-",date.month);
    }
    else{
        fprintf(o,"%d-",date.month);
    }
    if(date.day < 10){
        fprintf(o,"0%dT",date.day);
    }
    else{
        fprintf(o,"%dT",date.day);
    }
    if(date.hour < 10){
        fprintf(o,"0%d:00:00;",date.hour);
    }
    else{
        fprintf(o,"%d:00:00;",date.hour);
    }
    fprintf(o,"%f\n",date.average);
}


NODE_P2* linkedlist_P2(FILE* f){
    // Lines (measures) are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "datetime;pressure"
    // All dates are changed to match UTC time.
    // If a date was not seen before, we add a new node representing it.
    // If it was already seen, we search for the node representing it and uptdate its values.
    // The average values need to be calculated at the end. We use a special function to proceed.
    // The linked list representing all the encountered dates is returned at the end.
    NODE_P2* l = NULL;
    int year;
    int month;
    int day;
    int hour;
    int timezone;
    float pressure;
    while(feof(f)==0){
		if(fscanf(f,"%d-%d-%dT%d:00:00+%d:00;%f\n",&year,&month,&day,&hour,&timezone,&pressure)==6){
			UTCtime(&year,&month,&day,&hour,&timezone);                       
        	if(inlistNODE_P2(l,year,month,day,hour)==0){                               
            	l = addNODE_P2(l,year,month,day,hour,pressure);
        	}
        	else{                                                     
            	l = searchandchangevaluesNODE_P2(l,year,month,day,hour,pressure);
        	}
		}                                                     
    }
    l=averagingNODE_P2(l);
    return l;
}



/*
------------------------------------------
MODE 3
------------------------------------------
*/


void freeNODE_P3(NODE_P3* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_P3* temp = l;
        l=l->next;
        free(temp);
    }
}


NODE_P3* addNODE_P3(NODE_P3* l,int id,int year,int month, int day, int hour, float pressure){
    // A new node is created using malloc (we use the freeing function later to not waste memory).
    // The parameters set the values of the structure inside it.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_P3* new = malloc(sizeof(NODE_P3));
    if(new==NULL){
        printf("Error : addNODE_P3");
        exit(4);
    }
    new->m.id=id;
    new->m.year=year;
    new->m.month=month;
    new->m.day=day;
    new->m.hour=hour;
    new->m.pressure=pressure;
    new->next=l;
    return new;
}


int chronologicalorder_P3(MEASURE_P3 d1,MEASURE_P3 d2){
    // Comparisons are made between the time values that are in the structures to know if the first date comes after the second.
    // When all the possibilities for that have been explored, 1 is returned because the dates are in the right order.
    if(d1.year > d2.year){
        return 0;
    }
    else if(d1.year==d2.year){
        if(d1.month > d2.month){
            return 0;
        }
        else if(d1.month == d2.month){
            if(d1.day > d2.day){
                return 0;
            }
            else if(d1.day == d2.day){
                if(d1.hour > d2.hour){
                    return 0;
                }
            }
        }
    }
    return 1;
}


void producestring_P3(FILE* o,MEASURE_P3 measure){
    // This function is used to always write the same format for a measure, inside the file o.
    // Since most values are stored as integers, directly printing is sometimes not effective as some 0s may be missing.
    // Checks are made to counter this and use the right fprintf each time.
    fprintf(o,"%d-",measure.year);
    if(measure.month < 10){
        fprintf(o,"0%d-",measure.month);
    }
    else{
        fprintf(o,"%d-",measure.month);
    }
    if(measure.day < 10){
        fprintf(o,"0%dT",measure.day);
    }
    else{
        fprintf(o,"%dT",measure.day);
    }
    if(measure.hour < 10){
        fprintf(o,"0%d:00:00;",measure.hour);
    }
    else{
        fprintf(o,"%d:00:00;",measure.hour);
    }
    if(measure.id <= 9999 ){
        fprintf(o,"0%d;%f\n",measure.id,measure.pressure);
    }
    else{
        fprintf(o,"%d;%f\n",measure.id,measure.pressure);
    }
}


NODE_P3* linkedlist_P3(FILE* f){
    // Lines (measures) are read from the input file until its end.
    // A linked list is built. A node is added for each measure.
    // Format of the measure : "Station ID;datetime;pressure"
    // All dates are changed to match UTC time.
    // The linked list representing all the encountered measures is returned at the end.
    NODE_P3* l = NULL;
    int id;
    int year;
    int month;
    int day;
    int hour;
    int timezone;
    float pressure;
    while(feof(f)==0){
		if(fscanf(f,"%d;%d-%d-%dT%d:00:00+%d:00;%f\n",&id,&year,&month,&day,&hour,&timezone,&pressure)==7){
			UTCtime(&year,&month,&day,&hour,&timezone);                       
        	l=addNODE_P3(l,id,year,month,day,hour,pressure);
		}                                             
    }
    return l;
}



/*
------------------------------------------
WIND FUNCTIONS
------------------------------------------
*/


void freeNODE_W(NODE_W* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_W* temp = l;
        l=l->next;
        free(temp);
    }
}


int inlistNODE_W(NODE_W* l,int id){
    // To know if the station which ID is 'id' is already in the list, we have to get through all of it.
    // If it is found in one of the nodes, 1 is returned.
    NODE_W* temp=l;
    while(temp!=NULL){
        if(temp->s.id==id){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


NODE_W* addNODE_W(NODE_W* l,int id, int orientation, float speed){
    // A new node is created using malloc (we use the freeing function later to not waste memory).
    // The parameters set the values of the structure inside it.
    // The count is set to one because when this function is called, we have encountered an id for the first time.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_W* new = malloc(sizeof(NODE_W));
    if(new==NULL){
        printf("Error : addNODE_W");
        exit(4);
    }
    new->s.id=id;
    new->s.orientation=orientation;
    new->s.speed=speed;
    new->s.count=1;
    new->next=l;
    return new;
}


NODE_W* searchandaddNODE_W(NODE_W* l,int id,int orientation,float speed){
    // This function first goes through the list to find the structure representing the station of ID 'id'. 
    // It is in the list as we have called another function before to know it.
    // Since we have seen the station one more time, the count is augmented. The wind measured is also added to the sums to calculate the averages later.
    NODE_W* temp=l;
    while(temp!=NULL){
        if(temp->s.id == id){
            temp->s.count+=1;
            temp->s.orientation+=orientation;
            temp->s.speed+=speed;
            return l;
        }
        temp=temp->next;
    }
}


NODE_W* averagingNODE_W(NODE_W* l){
    // To calculate the averages of the measures, all has been set up before, in the functions that change the linked list.
    // The sums of all the encountered measures are divided by the number of times the station was encountered. This for each node.
    NODE_W* temp=l;
    while(temp!=NULL){
        temp->s.orientation = (temp->s.orientation)/(temp->s.count);
        temp->s.speed = (temp->s.speed)/(temp->s.count);
        temp=temp->next;
    }
    return l;
}


NODE_W* linkedlist_W(FILE* f){
    // Lines (measures) are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "Station ID;wind orientation over 10 min;wind speed over 10 min"
    // If the station was not seen before, we add a new node representing it.
    // If it was already seen, we search for the node representing it and uptdate its values.
    // The average values need to be calculated at the end. We use a special function to proceed.
    // The linked list representing all the encountered stations is returned at the end.
    NODE_W* l = NULL;
    int id;
    int orientation;
    float speed;
    while(feof(f)==0){
		if(fscanf(f,"%d;%d;%f",&id,&orientation,&speed)==3){
			if(inlistNODE_W(l,id)==0){
            	l = addNODE_W(l,id,orientation,speed);
        	}
        	else{
            	l = searchandaddNODE_W(l,id,orientation,speed);
        	}
		} 
    }
    l = averagingNODE_W(l);
    return l;
}


/*
------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------
*/


void freeNODE_H(NODE_H* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_H* temp = l;
        l=l->next;
        free(temp);
    }
}


int inlistNODE_H(NODE_H* l,int id){
    // To know if the station which ID is 'id' is already in the list, we have to get through all of it.
    // If it is found in one of the nodes, 1 is returned.
    NODE_H* temp=l;
    while(temp!=NULL){
        if(temp->s.id==id){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


NODE_H* addNODE_H(NODE_H* l,int id, int height){
    // A new node is created using malloc (we use the freeing function later to not waste memory).
    // The parameters set the values of the structure inside it.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_H* new = malloc(sizeof(NODE_H));
    if(new==NULL){
        printf("Error : addNODE_H");
        exit(4);
    }
    new->s.id=id;
    new->s.height=height;
    new->next=l;
    return new;
}


NODE_H* linkedlist_H(FILE* f){
    // Lines are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "Station ID;height of the station"
    // If the station was not seen before, we add a new node representing it.
    // Else, nothing needs to be done because a same station always has the same height.
    // The linked list representing all the encountered stations is returned at the end.
    NODE_H* l = NULL;
    int id;
    int height;
    while(feof(f)==0){
		if(fscanf(f,"%d;%d",&id,&height)==2){
			if(inlistNODE_H(l,id)==0){
        		l = addNODE_H(l,id,height);
        	}
		}
    }
    return l;
}


/*
------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------
*/


void freeNODE_M(NODE_M* l){
    // Each node of the structure needs to be freed individually.
    while(l!=NULL){
        NODE_M* temp = l;
        l=l->next;
        free(temp);
    }
}


int inlistNODE_M(NODE_M* l,int id){
    // To know if the station which ID is 'id' is already in the list, we have to get through all of it.
    // If it is found in one of the nodes, 1 is returned.
    NODE_M* temp=l;
    while(temp!=NULL){
        if(temp->s.id==id){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}


NODE_M* addNODE_M(NODE_M* l,int id, int moisture){
    // A new node is created using malloc (we use the freeing function later to not waste memory)
    // The parameters set the values of the structure inside it.
    // The new node is linked to the beginning of the linked list and is returned.
    NODE_M* new = malloc(sizeof(NODE_M));
    if(new==NULL){
        printf("Error : addNODE_M");
        exit(4);
    }
    new->s.id=id;
    new->s.maximal=moisture;
    new->next=l;
    return new;
}


NODE_M* searchandmaybereplaceNODE_M(NODE_M* l,int id,int moisture){
    // This function first goes through the list to find the structure representing the station of ID 'id'. 
    // It is in the list as we have called another function before to know it.
    // Then, if the maximal value parameter is higher than the current one for the station, it is uptdated.
    NODE_M* temp=l;
    while(temp!=NULL){
        if(temp->s.id == id){
            if(temp->s.maximal < moisture){
                temp->s.maximal = moisture;
            }
            return l;
        }
        temp=temp->next;
    }
}


NODE_M* linkedlist_M(FILE* f){
    // Lines (measures) are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "Station ID;moisture level"
    // If the station was not seen before, we add a new node representing it.
    // If it was already seen, we search for the node representing it and uptdate its values.
    // The linked list representing all the encountered stations is returned at the end.
    NODE_M* l = NULL;
    int id;
    int moisture;
    while(feof(f)==0){
		if(fscanf(f,"%d;%d",&id,&moisture)==2){
			if(inlistNODE_M(l,id)==0){
	            l = addNODE_M(l,id,moisture);
       		}
        	else{
        		l = searchandmaybereplaceNODE_M(l,id,moisture);
        	}
		}
    }
    return l;
}


