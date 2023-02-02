#ifndef HEADERSHARED
	#define HEADERSHARED 1
	#include "shared.h"
#endif

// Special function that is identical to the usual strsep.
// We simply had an issue where strsep wasn't found in string.h, so we searched online to implement it directly
char* personnalstrsep(char** stringp,const char *delim){
    char* rv=*stringp;
    if(rv){
        *stringp+=strcspn(*stringp,delim);
        if(**stringp){
            *(*stringp)++ = '\0';
        }   
        else{
            *stringp=0; 
        }   
    return rv;
    }
}

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

void coordonate(int id, float* lat, float* lon){
	if (id ==7650) {
		*lat=43.438;
		*lon=5.216;
	} else if (id ==81405) {
		*lat=4.822;
		*lon=-52.365;
	} else if (id ==7222) {
		*lat=47.15;
		*lon=-1.609;
	} else if (id ==7630) {
		*lat=48.717;
		*lon=1.379;
	} else if (id ==7149) {
		*lat=48.717;
		*lon=2.384;
	} else if (id ==7168) {
		*lat=48.325;
		*lon=4.02;
	} else if (id ==7690) {
		*lat=43.649;
		*lon=7.209;
	} else if (id ==7015) {
		*lat=50.57;
		*lon=3.098;
	} else if (id ==7481) {
		*lat=45.727;
		*lon=5.078;
	} else if (id ==7255) {
		*lat=47.059;
		*lon=2.360;
	} else if (id ==7299) {
		*lat=47.614;
		*lon=7.51;
	} else if (id ==7510) {
		*lat=44.831;
		*lon=-0.691;
	} else if (id ==7761) {
		*lat=41.918;
		*lon=8.793;
	} else if (id ==7434) {
		*lat=45.861;
		*lon=1.175;
	} else if (id ==7335) {
		*lat=46.594;
		*lon=0.314;
	} else if (id ==7790) {
		*lat=42.541;
		*lon=9.485;
	} else if (id ==7747) {
		*lat=42.737;
		*lon=2.873;
	} else if (id ==7577) {
		*lat=44.581;
		*lon=4.733;
	} else if (id ==7130) {
		*lat=48.069;
		*lon=-1.734;
	} else if (id ==07240) {
		*lat=47.445;
		*lon=0.727;
	} else if (id ==7110) {
		*lat=48.444;
		*lon=-4.412;
	} else if (id ==7037) {
		*lat=49.383;
		*lon=1.182;
	} else if (id ==7207) {
		*lat=47.294;
		*lon=-3.218;
	} else if (id ==7535) {
		*lat=44.745;
		*lon=1.397;
	} else if (id ==7591) {
		*lat=44.566;
		*lon=6.502;
	} else if (id ==7190) {
		*lat=48.550;
		*lon=7.640;
	} else if (id ==7005) {
		*lat=50.136;
		*lon=1.834;
	} else if (id ==7181) {
		*lat=48.581;
		*lon=5.960;
	} else if (id ==7280) {
		*lat=47.268;
		*lon=5.088;
	} else if (id ==7621) {
		*lat=43.188;
		*lon=0;
	} else if (id ==7027) {
		*lat=49.787;
		*lon=-0.456;
	} else if (id ==7460) {
		*lat=45.787;
		*lon=3.149;
	} else if (id ==7627) {
		*lat=43.005;
		*lon=1.107;
	} else if (id ==71805) {
		*lat=46.766;
		*lon=-56.179;
	} else if (id ==7607) {
		*lat=43.910;
		*lon=-0.5;
	} else if (id ==7643) {
		*lat=43.577;
		*lon=3.963;
	} else if (id ==7139) {
		*lat=48.446;
		*lon=0.110;
	} else if (id ==7117) {
		*lat=48.826;
		*lon=-3.473;
	} else if (id ==78897) {
		*lat=16.264;
		*lon=-61.516;
	} else if (id ==7558) {
		*lat=44.119;
		*lon=3.020;
	} else if (id ==7471) {
		*lat=45.075;
		*lon=3.764;
	} else if (id ==78925) {
		*lat=14.595;
		*lon=-60.996;
	} else if (id ==7020) {
		*lat=49.725;
		*lon=-1.94;
	} else if (id ==7661) {
		*lat=43.079;
		*lon=5.941;
	} else if (id ==61998) {
		*lat=-49.352;
		*lon=70.243;
	} else if (id ==61980) {
		*lat=-20.893;
		*lon=55.529;
	} else if (id ==7314) {
		*lat=46.047;
		*lon=-1.412;
	} else if (id ==61996) {
		*lat=-37.795;
		*lon=77.569;
	} else if (id ==81401) {
		*lat=5.486;
		*lon=-5.032;
	} else if (id ==89642) {
		*lat=-66.663;
		*lon=140.001;
	} else if (id ==81408) {
		*lat=3.891;
		*lon=-51.805;
	} else if (id ==61997) {
		*lat=-46.433;
		*lon=51.857;
	} else if (id ==61976) {
		*lat=-15.888;
		*lon=54.521;
	} else if (id ==81415) {
		*lat=3.640;
		*lon=-54.028;
	} else if (id ==7072) {
		*lat=49.21;
		*lon=4.155;
	} else if (id ==78922) {
		*lat=14.225;
		*lon=-60.875;
	} else if (id ==61972) {
		*lat=-22.344;
		*lon=40.341;
	} else if (id ==61968) {
		*lat=-11.583;
		*lon=47.29;
	} else if (id ==67005) {
		*lat=-12.806;
		*lon=45.283;
	} else if (id ==78890) {
		*lat=16.335;
		*lon=-61.004;
	} else if (id ==6970) {
		*lat=-17055;
		*lon=42.712;
	} else {
		*lat=0;
		*lon=0;
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
    long first=0;
    fscanf(f,"%ld\n",&first);
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
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer;
	char* field;
        field=personnalstrsep(&line,";");
        id=atoi(field);
        field=personnalstrsep(&line,";");
        temperature= (float) atof(field);
        if(strcmp(field,"")==0){
            ignore=1;
        }
        field=personnalstrsep(&line,";");
        minimaltemperature= (float) atof(field);
        if(strcmp(field,"")==0){
            ignore=1;
        }
        field=personnalstrsep(&line,";");
        if(strcmp(field,"\n")==0){
            ignore=1;
        }
        maximaltemperature= (float) atof(field);
        if(ignore==0){
            if(inlistNODE_T1(l,id)==0){                               
                l = addNODE_T1(l,id,temperature,minimaltemperature,maximaltemperature);
            }
            else{                                                        
                l = searchandchangevaluesNODE_T1(l,id,temperature,minimaltemperature,maximaltemperature);
            }
        }
        ignore=0;
    }
    free(buffer);
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
	fprintf(o,"\"%d-",date.year);
	fprintf(o,"%d-",date.month);
	fprintf(o,"%d ",date.day);
	fprintf(o,"%d:00:00\" ",date.hour);
	fprintf(o,"%f\n",date.average);
}

NODE_T2* linkedlist_T2(FILE* f){
    long first=0;
    fscanf(f,"%ld\n",&first);
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
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer; 
	char* field;

        field=personnalstrsep(&line,";");
        sscanf(field,"%d-%d-%dT%d:00:00+%d:00",&year,&month,&day,&hour,&timezone);
        
        field=personnalstrsep(&line,";");
        temperature = (float) atof(field);
        if(strcmp(field,"\n")==0){
            ignore=1;
        }
        if(ignore==0){
            UTCtime(&year,&month,&day,&hour,&timezone);                    
            if(inlistNODE_T2(l,year,month,day,hour)==0){                              
                l = addNODE_T2(l,year,month,day,hour,temperature);
            }
            else{                                                    
                l = searchandchangevaluesNODE_T2(l,year,month,day,hour,temperature);
            }
        }
        ignore=0;
    }
    free(buffer);
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

void producestring_T3(FILE* o,MEASURE_T3 measure, MEASURE_T3 old_measure){
	// This function is used to always write the same format for a measure, inside the file o.
	if(measure.year !=old_measure.year || measure.month !=old_measure.month || measure.day !=old_measure.day|| measure.hour !=old_measure.hour || measure.id !=old_measure.id){
		fprintf(o,"\n");
	}
	fprintf(o,"\"%d-",measure.year);
        fprintf(o,"%d-",measure.month);
        fprintf(o,"%d\" ",measure.day);
        fprintf(o,"%d %f ",measure.id,measure.temperature);
        fprintf(o,"%d\n",measure.hour);
}

NODE_T3* linkedlist_T3(FILE* f){
    long first=0;
    fscanf(f,"%ld\n",&first);
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
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer;
	char* field;
        
        field=personnalstrsep(&line,";");
        id=atoi(field);

        field=personnalstrsep(&line,";");
        sscanf(field,"%d-%d-%dT%d:00:00+%d:00",&year,&month,&day,&hour,&timezone);
        
        field=personnalstrsep(&line,";");
        temperature = (float) atof(field);
        if(strcmp(field,"\n")==0){
            ignore=1;
        }
        if(ignore==0){
            UTCtime(&year,&month,&day,&hour,&timezone);                       
            l=addNODE_T3(l,id,year,month,day,hour,temperature);
        }
        ignore=0;
    }
    free(buffer);
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
    long first=0;
    fscanf(f,"%ld\n",&first);
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
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer;
	char* field;
        field=personnalstrsep(&line,";");
        id=atoi(field);
        field=personnalstrsep(&line,";");
        pressure = (float) atof(field);
        if(strcmp(field,"\n")==0){
            ignore=1;
        }  
        if(ignore==0){
            if(inlistNODE_P1(l,id)==0){                            
                l = addNODE_P1(l,id,pressure);
            }
            else{                 
                l = searchandchangevaluesNODE_P1(l,id,pressure);
            }
        }  
        ignore=0;              
    }
    free(buffer);
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
	fprintf(o,"\"%d-",date.year);
        fprintf(o,"%d-",date.month);
        fprintf(o,"%d ",date.day);
        fprintf(o,"%d:00:00\" ",date.hour);
	fprintf(o,"%f\n",date.average);
}

NODE_P2* linkedlist_P2(FILE* f){
    long first=0;
    fscanf(f,"%ld\n",&first);
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
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer;
	char* field;

        field=personnalstrsep(&line,";");
        sscanf(field,"%d-%d-%dT%d:00:00+%d:00",&year,&month,&day,&hour,&timezone);
        
        field=personnalstrsep(&line,";");
        pressure = (float) atof(field);
        if(strcmp(field,"\n")==0){
            ignore=1;
        }
        if(ignore==0){
            UTCtime(&year,&month,&day,&hour,&timezone);                       
            if(inlistNODE_P2(l,year,month,day,hour)==0){                               
                l = addNODE_P2(l,year,month,day,hour,pressure);
            }
            else{                                                     
                l = searchandchangevaluesNODE_P2(l,year,month,day,hour,pressure);
            }
        }
        ignore=0;
    }
    free(buffer);
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

void producestring_P3(FILE* o,MEASURE_P3 measure, MEASURE_P3 old_measure){
	// This function is used to always write the same format for a measure, inside the file o.
	if(measure.year !=old_measure.year || measure.month !=old_measure.month || measure.day !=old_measure.day|| measure.hour !=old_measure.hour || measure.id !=old_measure.id){
		fprintf(o,"\n");
	}
	fprintf(o,"\"%d-",measure.year);
        fprintf(o,"%d-",measure.month);
        fprintf(o,"%d\" ",measure.day);
        fprintf(o,"%d %f ",measure.id,measure.pressure);
        fprintf(o,"%d\n",measure.hour);
}

NODE_P3* linkedlist_P3(FILE* f){
    long first=0;
    fscanf(f,"%ld\n",&first);
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
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer;
	char* field;
        field=personnalstrsep(&line,";");
        id=atoi(field);

        field=personnalstrsep(&line,";");
        sscanf(field,"%d-%d-%dT%d:00:00+%d:00",&year,&month,&day,&hour,&timezone);
        
        field=personnalstrsep(&line,";");
        pressure = (float) atof(field);
        if(strcmp(field,"\n")==0){
            ignore=1;
        }
        if(ignore==0){
            UTCtime(&year,&month,&day,&hour,&timezone);                       
            l=addNODE_P3(l,id,year,month,day,hour,pressure);
        }
        ignore=0;
        
    }
    free(buffer);
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
    long first=0;
    fscanf(f,"%ld\n",&first);
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
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer; 
	char* field;
        field=personnalstrsep(&line,";");
        id=atoi(field);
        field=personnalstrsep(&line,";");
        orientation = (float) atof(field);
        if(strcmp(field,"")==0){
            ignore=1;
        }
        field=personnalstrsep(&line,";");
        speed = (float) atof(field);
        if(strcmp(field,"\n")==0){
            ignore=1;
        }
        if(ignore==0){
            if(inlistNODE_W(l,id)==0){
                l = addNODE_W(l,id,orientation,speed);
            }
            else{
                l = searchandaddNODE_W(l,id,orientation,speed);
            }
        }
        ignore=0; 
    }
    free(buffer);
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
    long first=0;
    fscanf(f,"%ld\n",&first);
    // Lines are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "Station ID;height of the station"
    // If the station was not seen before, we add a new node representing it.
    // Else, nothing needs to be done because a same station always has the same height.
    // The linked list representing all the encountered stations is returned at the end.
    NODE_H* l = NULL;
    int id;
    int height;
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer;
	char* field;
        field=personnalstrsep(&line,";");
        id=atoi(field);
        field=personnalstrsep(&line,";");
        height = atoi(field);
        if(strcmp(field,"\n")==0){
            ignore=1;
        }
        if(ignore==0){
            if(inlistNODE_H(l,id)==0){
                l = addNODE_H(l,id,height);
            }
        }
        ignore=0;
    }
    free(buffer);
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
    long first=0;
    fscanf(f,"%ld\n",&first);
    // Lines (measures) are read from the input file until its end.
    // A linked list is built.
    // Format of the measure : "Station ID;moisture level"
    // If the station was not seen before, we add a new node representing it.
    // If it was already seen, we search for the node representing it and uptdate its values.
    // The linked list representing all the encountered stations is returned at the end.
    NODE_M* l = NULL;
    int id;
    int moisture;
    int buffersize=200;
    char* buffer=malloc(buffersize*sizeof(char));
    int ignore=0;
    while(fgets(buffer,buffersize-1,f)!=NULL){ 
        char* line=buffer; 
	char* field;
        field=personnalstrsep(&line,";");
        id=atoi(field);
        field=personnalstrsep(&line,";");
        moisture = atoi(field);
        if(strcmp(field,"\n")==0){
            ignore=1;
        }
        if(ignore==0){
            if(inlistNODE_M(l,id)==0){
                l = addNODE_M(l,id,moisture);
            }
            else{
                l = searchandmaybereplaceNODE_M(l,id,moisture);
            }
        }
        ignore=0; 
    }
    free(buffer);
    return l;
}
