#ifndef SHARED
	#define SHARED 1
	#include "shared.c"
#endif

#ifndef HEADERTAB
	#define HEADERTAB 1
	#include "tab.h"
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


int getlenghtNODE_T1(NODE_T1* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_T1* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabT1sort1(FILE* o,NODE_T1* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_T1(l);
    NODE_T1* l0=l;                                             
    STATION_T1* list=malloc(lenght*sizeof(STATION_T1));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          
        l0=l0->next;
    }
    freeNODE_T1(l);
    // STEP 2 : Sorting by station ID (ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the IDs of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_T1 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).id > (*(list+k+1)).id ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "Id minimal_temperature maximal_temperature average_temperature".
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    fprintf(o,"# Id minimal_temperature maximal_temperature average_temperature\n");
    for(i=0;i<lenght;i++){
            fprintf(o,"%d %f %f %f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
    }
    free(list);
    return 0;
}


int tabT1sort2(FILE* o,NODE_T1* l){
    // This function works the same as tabT1sort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_T1(l);
    NODE_T1* l0=l;                                              
    STATION_T1* list=malloc(lenght*sizeof(STATION_T1));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          
        l0=l0->next;
    }
    freeNODE_T1(l);

    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_T1 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).id < (*(list+k+1)).id ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    

    fprintf(o,"# Id minimal_temperature maximal_temperature average_temperature\n");
    for(i=0;i<lenght;i++){
            fprintf(o,"%d %f %f %f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
    }
    free(list);
    return 0;
}


/*
------------------------------------------------------------
MODE 2
------------------------------------------------------------
*/


int getlenghtNODE_T2(NODE_T2* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_T2* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabT2sort1(FILE* o,NODE_T2* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_T2(l);
    NODE_T2* l0=l;                                              
    TIME_T2* list=malloc(lenght*sizeof(TIME_T2));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->t;                                          
        l0=l0->next;
    }
    freeNODE_T2(l);
    // STEP 2 : Sorting by chronological order (ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the dates of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    TIME_T2 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( chronologicalorder_T2(*(list+k),*(list+k+1)) == 0 ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "date average_temperature".
    // A special function is used to write each line because writing dates and times with ints is lenghty.
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    fprintf(o,"# Date average_temperature\n");
    for(i=0;i<lenght;i++){                                  
        producestring_T2(o,*(list+i));
    }
    free(list);
    return 0;
}


int tabT2sort2(FILE* o,NODE_T2* l){
    // This function works the same as tabT2sort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_T2(l);
    NODE_T2* l0=l;                                              
    TIME_T2* list=malloc(lenght*sizeof(TIME_T2));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->t;                                          
        l0=l0->next;
    }
    freeNODE_T2(l);

    int sorted = 0;
    int step = lenght-1;
    int k;
    TIME_T2 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( chronologicalorder_T2(*(list+k),*(list+k+1)) == 1 ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    

    fprintf(o,"# Date average_temperature\n");
    for(i=0;i<lenght;i++){                                  
        producestring_T2(o,*(list+i)); 
    }
    free(list);
    return 0;
}


/*
------------------------------------------------------------
MODE 3
------------------------------------------------------------
*/


int getlenghtNODE_T3(NODE_T3* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_T3* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabT3sort1(FILE* o,NODE_T3* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_T3(l);
    NODE_T3* l0=l;                                              
    MEASURE_T3* list=malloc(lenght*sizeof(MEASURE_T3));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->m;                                          
        l0=l0->next;
    }
    freeNODE_T3(l);
    // STEP 2 : Sorting by 1) chronological order (ascending) and 2) station ID (ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the dates of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    MEASURE_T3 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( chronologicalorder_T3(*(list+k),*(list+k+1)) == 0 ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
            else if( (*(list+k)).year == (*(list+k+1)).year && (*(list+k)).month == (*(list+k+1)).month && (*(list+k)).day == (*(list+k+1)).day && (*(list+k)).hour == (*(list+k+1)).hour ){
                if((*(list+k)).id > (*(list+k+1)).id){
                    sorted=0;
                    temp=(*(list+k));
                    (*(list+k))=(*(list+k+1));
                    (*(list+k+1))=temp;
                }
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "day ID temperature hours".
    // A special function is used to write each line because writing dates and times with ints is lenghty.
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    fprintf(o,"# Day ID temperature hours.\n");
    for(i=0;i<lenght;i++){
        if(i ==0) producestring_T3(o, *(list+i), addNODE_T3(NULL, 0, 0, 0, 0, 0, 0)->m);
        else producestring_T3(o, *(list+i), *(list+i-1));
    }
    free(list);
    return 0;
}


int tabT3sort2(FILE* o,NODE_T3* l){
    // This function works the same as tabT3sort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_T3(l);
    NODE_T3* l0=l;                                              
    MEASURE_T3* list=malloc(lenght*sizeof(MEASURE_T3));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->m;                                          
        l0=l0->next;
    }
    freeNODE_T3(l);
    // Sorting by 1) chronological order (descending) and 2) station ID (ascending).
    int sorted = 0;
    int step = lenght-1;
    int k;
    MEASURE_T3 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( chronologicalorder_T3(*(list+k),*(list+k+1)) == 1 ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
            else if( (*(list+k)).year == (*(list+k+1)).year && (*(list+k)).month == (*(list+k+1)).month && (*(list+k)).day == (*(list+k+1)).day && (*(list+k)).hour == (*(list+k+1)).hour ){
                if((*(list+k)).id > (*(list+k+1)).id){
                    sorted=0;
                    temp=(*(list+k));
                    (*(list+k))=(*(list+k+1));
                    (*(list+k+1))=temp;
                }
            }
        }
        step-=1;
    }
    fprintf(o,"# Day ID temperature hours.\n");
    for(i=0;i<lenght;i++){
        if(i ==0) producestring_T3(o, *(list+i), addNODE_T3(NULL, 0, 0, 0, 0, 0, 0)->m);
        else producestring_T3(o, *(list+i), *(list+i-1));
    }
    free(list);
    return 0;
}


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


int getlenghtNODE_P1(NODE_P1* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_P1* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabP1sort1(FILE* o,NODE_P1* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_P1(l);
    NODE_P1* l0=l;                                              
    STATION_P1* list=malloc(lenght*sizeof(STATION_P1));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                         
        l0=l0->next;
    }
    freeNODE_P1(l);
    // STEP 2 : Sorting by station ID (ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the IDs of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_P1 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).id > (*(list+k+1)).id ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "Id minimal_pressure maximal_pressure average_pressure".
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    fprintf(o,"# Id minimal_pressure maximal_pressure average_pressure\n");
    for(i=0;i<lenght;i++){
        fprintf(o,"%d %f %f %f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
    }
    free(list);
    return 0;
}


int tabP1sort2(FILE* o,NODE_P1* l){
    // This function works the same as tabP1sort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_P1(l);
    NODE_P1* l0=l;                                            
    STATION_P1* list=malloc(lenght*sizeof(STATION_P1));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                         
        l0=l0->next;
    }
    freeNODE_P1(l);

    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_P1 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).id < (*(list+k+1)).id ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    

    fprintf(o,"# Id minimal_pressure maximal_pressure average_pressure\n");
    for(i=0;i<lenght;i++){
        fprintf(o,"%d %f %f %f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
    }
    free(list);
    return 0;
}


/*
------------------------------------------------------------
MODE 2
------------------------------------------------------------
*/


int getlenghtNODE_P2(NODE_P2* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_P2* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabP2sort1(FILE* o,NODE_P2* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_P2(l);
    NODE_P2* l0=l;                                              
    TIME_P2* list=malloc(lenght*sizeof(TIME_P2));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->t;                                          
        l0=l0->next;
    }
    freeNODE_P2(l);
    // STEP 2 : Sorting by chronological order (ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the dates of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    TIME_P2 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( chronologicalorder_P2(*(list+k),*(list+k+1)) == 0 ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "date average_pressure".
    // A special function is used to write each line because writing dates and times with ints is lenghty.
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    fprintf(o,"# Date average_pressure\n");
    for(i=0;i<lenght;i++){                                  
        producestring_P2(o,*(list+i)); 
    }
    free(list);
    return 0;
}


int tabP2sort2(FILE* o,NODE_P2* l){
    // This function works the same as tabP2sort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_P2(l);
    NODE_P2* l0=l;                                              
    TIME_P2* list=malloc(lenght*sizeof(TIME_P2));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->t;                                          
        l0=l0->next;
    }
    freeNODE_P2(l);

    int sorted = 0;
    int step = lenght-1;
    int k;
    TIME_P2 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( chronologicalorder_P2(*(list+k),*(list+k+1)) == 1 ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    

    fprintf(o,"# Date average_pressure\n");
    for(i=0;i<lenght;i++){                                  
        producestring_P2(o,*(list+i)); 
    }
    free(list);
    return 0;
}


/*
------------------------------------------------------------
MODE 3
------------------------------------------------------------
*/


int getlenghtNODE_P3(NODE_P3* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_P3* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabP3sort1(FILE* o,NODE_P3* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_P3(l);
    NODE_P3* l0=l;                                              
    MEASURE_P3* list=malloc(lenght*sizeof(MEASURE_P3));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->m;                                          
        l0=l0->next;
    }
    freeNODE_P3(l);
    // STEP 2 : Sorting by 1) chronological order (ascending) and 2) station ID (ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the dates of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    MEASURE_P3 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( chronologicalorder_P3(*(list+k),*(list+k+1)) == 0 ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
            else if( (*(list+k)).year == (*(list+k+1)).year && (*(list+k)).month == (*(list+k+1)).month && (*(list+k)).day == (*(list+k+1)).day && (*(list+k)).hour == (*(list+k+1)).hour ){
                if((*(list+k)).id > (*(list+k+1)).id){
                    sorted=0;
                    temp=(*(list+k));
                    (*(list+k))=(*(list+k+1));
                    (*(list+k+1))=temp;
                }
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "day ID pressure hours".
    // A special function is used to write each line because writing dates and times with ints is lenghty.
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    fprintf(o,"# Day ID pressure hours\n");
    for(i=0;i<lenght;i++){
        if(i ==0) producestring_P3(o, *(list+i), addNODE_P3(NULL, 0, 0, 0, 0, 0, 0)->m);
        else producestring_P3(o, *(list+i), *(list+i-1));
    }
    free(list);
    return 0;
}


int tabP3sort2(FILE* o,NODE_P3* l){
    // This function works the same as tabP3sort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_P3(l);
    NODE_P3* l0=l;                                              
    MEASURE_P3* list=malloc(lenght*sizeof(MEASURE_P3));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->m;                                          
        l0=l0->next;
    }
    freeNODE_P3(l);
    // Sorting by 1) chronological order (descending) and 2) station ID (ascending).
    int sorted = 0;
    int step = lenght-1;
    int k;
    MEASURE_P3 temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( chronologicalorder_P3(*(list+k),*(list+k+1)) == 1 ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
            else if( (*(list+k)).year == (*(list+k+1)).year && (*(list+k)).month == (*(list+k+1)).month && (*(list+k)).day == (*(list+k+1)).day && (*(list+k)).hour == (*(list+k+1)).hour ){
                if((*(list+k)).id > (*(list+k+1)).id){
                    sorted=0;
                    temp=(*(list+k));
                    (*(list+k))=(*(list+k+1));
                    (*(list+k+1))=temp;
                }
            }
        }
        step-=1;
    }   
    fprintf(o,"# Day ID pressure hours\n");
    for(i=0;i<lenght;i++){
        if(i ==0) producestring_P3(o, *(list+i), addNODE_P3(NULL, 0, 0, 0, 0, 0, 0)->m);
        else producestring_P3(o, *(list+i), *(list+i-1));
    }
    free(list);
    return 0;
}


/*
------------------------------------------------------------
WIND FUNCTIONS
------------------------------------------------------------
*/


int getlenghtNODE_W(NODE_W* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_W* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabWsort1(FILE* o, NODE_W* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_W(l);
    NODE_W* l0=l;
    STATION_W* list=malloc(lenght*sizeof(STATION_W));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;
        l0=l0->next;
    }
    freeNODE_W(l);
    // STEP 2 : Sorting by station ID (ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the IDs of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_W temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).id > (*(list+k+1)).id ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "longitude latitude rayon degré".
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    float lat;
    float lon;
    fprintf(o,"# Longitude latitude rayon degré\n");
    for(i=0;i<lenght;i++){
    	coordonate((*(list+i)).id, &lat, &lon);
        fprintf(o,"%f %f %d %f\n",lon,lat,(*(list+i)).orientation,(*(list+i)).speed);
    }
    free(list);
    return 0;
}


int tabWsort2(FILE* o, NODE_W* l){
    // This function works the same as tabWsort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_W(l);
    NODE_W* l0=l;
    STATION_W* list=malloc(lenght*sizeof(STATION_W));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;
        l0=l0->next;
    }
    freeNODE_W(l);
    
    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_W temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).id < (*(list+k+1)).id ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    

    float lat;
    float lon;
    fprintf(o,"# Longitude latitude rayon degré\n");
    for(i=0;i<lenght;i++){
  	  coordonate((*(list+i)).id, &lat, &lon);
        fprintf(o,"%f %f %d %f\n",lon,lat,(*(list+i)).orientation,(*(list+i)).speed);
    }
    free(list);
    return 0;
}


/*
------------------------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------------------------
*/


int getlenghtNODE_H(NODE_H* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_H* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabHsort1(FILE* o,NODE_H* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_H(l);
    NODE_H* l0=l;
    STATION_H* list=malloc(lenght*sizeof(STATION_H));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;
        l0=l0->next;
    }
    freeNODE_H(l);
    // STEP 2 : Sorting by station height (descending, using -r will make it ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the heights of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_H temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).height < (*(list+k+1)).height ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "longitude latitude height".
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    float lat;
    float lon;
    fprintf(o,"# Longitude latitude height\n");
    for(i=0;i<lenght;i++){
        coordonate((*(list+i)).id, &lat, &lon);
        fprintf(o,"%f %f %d\n",lon,lat,(*(list+i)).height);
    }
    free(list);
    return 0;
}


int tabHsort2(FILE* o,NODE_H* l){
    // This function works the same as tabHsort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_H(l);
    NODE_H* l0=l;
    STATION_H* list=malloc(lenght*sizeof(STATION_H));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;
        l0=l0->next;
    }
    freeNODE_H(l);

    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_H temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).height > (*(list+k+1)).height ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }

    float lat;
    float lon;
    fprintf(o,"# Longitude latitude height\n");
    for(i=0;i<lenght;i++){
        coordonate((*(list+i)).id, &lat, &lon);
        fprintf(o,"%f %f %d\n",lon,lat,(*(list+i)).height);
    }
    free(list);
    return 0;
}


/*
------------------------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------------------------
*/


int getlenghtNODE_M(NODE_M* l){
    // If the list is empty, the function has to return 0.
    // Else, 1 is added to a count for every node encountered in the list.
    // The final count is returned.
    int n;
    if(l==NULL){
        return 0;
    }
    NODE_M* temp=l;
    while(temp!=NULL){
        n+=1;
        temp=temp->next;
    }
    return n;
}


int tabMsort1(FILE* o,NODE_M* l){
    // STEP 1 : Transfering the linked list's elements to a static list.
    // To make the sort easier, we transform the linked list into a static list. We can get the lenght of the linked list and create an array.
    // We make sure to keep the original linked list in a variable to be able to free it later. 
    // Each element of the linked list is directly put in a static list. The sort comes in the next step.
    // When this is finished, the linked list is freed.
    int i;
    int lenght=getlenghtNODE_M(l);
    NODE_M* l0=l;                                            
    STATION_M* list=malloc(lenght*sizeof(STATION_M));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          
        l0=l0->next;
    }
    freeNODE_M(l);
    // STEP 2 : Sorting by maximal moisture level (descending, using -r will make it ascending).
    // A bubble sort is applied on the static list.
    // What triggers the inversion of elements is the moisture levels of two adjacents structures not being in the right order.
    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_M temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).maximal < (*(list+k+1)).maximal ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    
    // STEP 3 : Writing the result in the output file.
    // Each element of the sorted list is then written in the output file.
    // Format : "longitude latitude moisture".
    // The static list is freed at the end of this operation and 0 is returned because the function executed successfully.
    float lat;
    float lon;
    fprintf(o,"# Longitude latitude moisture\n");
    for(i=0;i<lenght;i++){
        coordonate((*(list+i)).id, &lat, &lon);
        fprintf(o,"%f %f %d\n",lon,lat,(*(list+i)).maximal);
    }
    free(list);
    return 0;
}


int tabMsort2(FILE* o,NODE_M* l){
    // This function works the same as tabMsort1(). The only difference is the inversion of sorting order.
    int i;
    int lenght=getlenghtNODE_M(l);
    NODE_M* l0=l;                                             
    STATION_M* list=malloc(lenght*sizeof(STATION_M));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          
        l0=l0->next;
    }
    freeNODE_M(l);

    int sorted = 0;
    int step = lenght-1;
    int k;
    STATION_M temp;
    while(sorted==0 && step>0){
        sorted=1;
        for(k=0;k<step;k++){
            if( (*(list+k)).maximal > (*(list+k+1)).maximal ){
                sorted=0;
                temp=(*(list+k));
                (*(list+k))=(*(list+k+1));
                (*(list+k+1))=temp;
            }
        }
        step-=1;
    }    
    
    float lat;
    float lon;
    fprintf(o,"# Longitude latitude moisture\n");
    for(i=0;i<lenght;i++){
        coordonate((*(list+i)).id, &lat, &lon);
        fprintf(o,"%f %f %d\n",lon,lat,(*(list+i)).maximal);
    }
    free(list);
    return 0;
}
