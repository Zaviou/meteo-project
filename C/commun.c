#include "headercommun.h"

void UTCtime(int* year,int* month, int* day, int* hour, int* timezone){
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
    NODE_T1* temp=l;
    while(temp!=NULL){
        temp->s.average = (temp->s.average)/(temp->s.count);
        temp=temp->next;
    }
    return l;
}

NODE_T1* linkedlist_T1(FILE* f){
    NODE_T1* l = NULL;
    int id;
    float temperature;
    float minimaltemperature;
    float maximaltemperature;
    while(feof(f)==0){                                               // Lines (measures) are read from the input file until its end.
        fscanf(f,"%d;%f;%f;%f",&id,&temperature,&minimaltemperature,&maximaltemperature);                             // Format of the measure : "Station ID;temperature;minimal temperature over 24 hrs;maximal temperature over 24hrs"
        if(inlistNODE_T1(l,id)==0){                               // If the station was not seen before, we add a new node.
            l = addNODE_T1(l,id,temperature,minimaltemperature,maximaltemperature);
        }
        else{                                                        // If it was already seen, we search for the right node and replace the value if it is lower than what was just read.
            l = searchandchangevaluesNODE_T1(l,id,temperature,minimaltemperature,maximaltemperature);
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
    NODE_T2* temp=l;
    while(temp!=NULL){
        temp->t.average = (temp->t.average)/(temp->t.count);
        temp=temp->next;
    }
    return l;
}


int chronologicalorder_T2(TIME_T2 d1,TIME_T2 d2){
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
    NODE_T2* l = NULL;
    int year;
    int month;
    int day;
    int hour;
    int timezone;
    float temperature;
    while(feof(f)==0){                                             
        fscanf(f,"%d-%d-%dT%d:00:00+%d:00;%f\n",&year,&month,&day,&hour,&timezone,&temperature);
        UTCtime(&year,&month,&day,&hour,&timezone);                       
        if(inlistNODE_T2(l,year,month,day,hour)==0){                               
            l = addNODE_T2(l,year,month,day,hour,temperature);
        }
        else{                                                     
            l = searchandchangevaluesNODE_T2(l,year,month,day,hour,temperature);
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
    NODE_P1* temp=l;
    while(temp!=NULL){
        temp->s.average = (temp->s.average)/(temp->s.count);
        temp=temp->next;
    }
    return l;
}


NODE_P1* linkedlist_P1(FILE* f){
    NODE_P1* l = NULL;
    int id;
    float pressure;
    while(feof(f)==0){                                               // Lines (measures) are read from the input file until its end.
        fscanf(f,"%d;%f",&id,&pressure);                     
        if(inlistNODE_P1(l,id)==0){                               // If the station was not seen before, we add a new node.
            l = addNODE_P1(l,id,pressure);
        }
        else{                                                        // If it was already seen, we search for the right node and replace the value if it is lower than what was just read.
            l = searchandchangevaluesNODE_P1(l,id,pressure);
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
    NODE_P2* temp=l;
    while(temp!=NULL){
        temp->t.average = (temp->t.average)/(temp->t.count);
        temp=temp->next;
    }
    return l;
}


int chronologicalorder_P2(TIME_P2 d1,TIME_P2 d2){
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
    NODE_P2* l = NULL;
    int year;
    int month;
    int day;
    int hour;
    int timezone;
    float pressure;
    while(feof(f)==0){                                             
        fscanf(f,"%d-%d-%dT%d:00:00+%d:00;%f\n",&year,&month,&day,&hour,&timezone,&pressure);
        UTCtime(&year,&month,&day,&hour,&timezone);                       
        if(inlistNODE_P2(l,year,month,day,hour)==0){                               
            l = addNODE_P2(l,year,month,day,hour,pressure);
        }
        else{                                                     
            l = searchandchangevaluesNODE_P2(l,year,month,day,hour,pressure);
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
    NODE_W* temp=l;
    while(temp!=NULL){
        temp->s.orientation = (temp->s.orientation)/(temp->s.count);
        temp->s.speed = (temp->s.speed)/(temp->s.count);
        temp=temp->next;
    }
    return l;
}

NODE_W* linkedlist_W(FILE* f){
    NODE_W* l = NULL;
    int id;
    int orientation;
    float speed;
    while(feof(f)==0){
        fscanf(f,"%d;%d;%f",&id,&orientation,&speed);
        if(inlistNODE_W(l,id)==0){
            l = addNODE_W(l,id,orientation,speed);
        }
        else{
            l = searchandaddNODE_W(l,id,orientation,speed);
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
    NODE_H* l = NULL;
    int id;
    int height;

    // STEP 1 : Building a linked list, reading the file line by line
    while(feof(f)==0){
        fscanf(f,"%d;%d",&id,&height);
        if(inlistNODE_H(l,id)==0){
            l = addNODE_H(l,id,height);
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
    NODE_M* l = NULL;
    int id;
    int moisture;
    while(feof(f)==0){
        fscanf(f,"%d;%d",&id,&moisture);
        if(inlistNODE_M(l,id)==0){
            l = addNODE_M(l,id,moisture);
        }
        else{
            l = searchandmaybereplaceNODE_M(l,id,moisture);
        }
    }
    return l;
}