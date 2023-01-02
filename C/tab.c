#include "headertab.h"

int getlenghtNODE_T1(NODE_T1* l){
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
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_T1(l);
    NODE_T1* l0=l;                                             // We keep the linked list in a variable to be able to free it later. 
    STATION_T1* list=malloc(lenght*sizeof(STATION_T1));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          // Each element of the linked list (which lenght was determined) is directly put in a static list.
        l0=l0->next;
    }
    freeNODE_T1(l);
    // STEP 3 : Sorting by maximal moisture level (default is descending sort, so using -r will make it ascending)
    // A bubble sort is applied on the stations' IDs.
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Station ID;minimal temperature;maximal temperature;average temperature"
    fprintf(o,"Station ID;minimal temperature;maximal temperature;average temperature\n");
    for(i=0;i<lenght;i++){                                   // Since the station ID is stored as an int, we need to add a 0 before the ID when it is lower than 9999.
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%f;%f;%f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
        }
        else{
            fprintf(o,"%d;%f;%f;%f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
        }  
    }
    free(list);
    return 0;
}

int tabT1sort2(FILE* o,NODE_T1* l){
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_T1(l);
    NODE_T1* l0=l;                                             // We keep the linked list in a variable to be able to free it later. 
    STATION_T1* list=malloc(lenght*sizeof(STATION_T1));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          // Each element of the linked list (which lenght was determined) is directly put in a static list.
        l0=l0->next;
    }
    freeNODE_T1(l);
    // STEP 3 : Sorting by maximal moisture level (default is descending sort, so using -r will make it ascending)
    // A bubble sort is applied on the stations' IDs.
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Station ID;minimal temperature;maximal temperature;average temperature"
    fprintf(o,"Station ID;minimal temperature;maximal temperature;average temperature\n");
    for(i=0;i<lenght;i++){                                   // Since the station ID is stored as an int, we need to add a 0 before the ID when it is lower than 9999.
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%f;%f;%f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
        }
        else{
            fprintf(o,"%d;%f;%f;%f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
        }  
    }
    free(list);
    return 0;
}

int getlenghtNODE_T2(NODE_T2* l){
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
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_T2(l);
    NODE_T2* l0=l;                                              
    TIME_T2* list=malloc(lenght*sizeof(TIME_T2));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->t;                                          
        l0=l0->next;
    }
    freeNODE_T2(l);
    // STEP 3 : Sorting by chronological order.
    // A bubble sort is applied on the dates.
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Time (UTC) ; average temperature (world)"
    fprintf(o,"Time;average temperature\n");
    for(i=0;i<lenght;i++){                                  
        producestring_T2(o,*(list+i)); 
    }
    free(list);
    return 0;
}


int tabT2sort2(FILE* o,NODE_T2* l){
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_T2(l);
    NODE_T2* l0=l;                                              
    TIME_T2* list=malloc(lenght*sizeof(TIME_T2));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->t;                                          
        l0=l0->next;
    }
    freeNODE_T2(l);
    // STEP 3 : Sorting by chronological order.
    // A bubble sort is applied on the dates.
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Time (UTC) ; average temperature (world)"
    fprintf(o,"Time;average temperature\n");
    for(i=0;i<lenght;i++){                                  
        producestring_T2(o,*(list+i)); 
    }
    free(list);
    return 0;
}

int getlenghtNODE_P1(NODE_P1* l){
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
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_P1(l);
    NODE_P1* l0=l;                                             // We keep the linked list in a variable to be able to free it later. 
    STATION_P1* list=malloc(lenght*sizeof(STATION_P1));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          // Each element of the linked list (which lenght was determined) is directly put in a static list.
        l0=l0->next;
    }
    freeNODE_P1(l);
    // STEP 3 : Sorting (default is descending sort, so using -r will make it ascending)
    // A bubble sort is applied on the stations' IDs.
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Station ID;minimal pressure;maximal pressure;average pressure"
    fprintf(o,"Station ID;minimal pressure;maximal pressure;average pression\n");
    for(i=0;i<lenght;i++){                                   // Since the station ID is stored as an int, we need to add a 0 before the ID when it is lower than 9999.
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%f;%f;%f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
        }
        else{
            fprintf(o,"%d;%f;%f;%f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
        }  
    }
    free(list);
    return 0;
}

int tabP1sort2(FILE* o,NODE_P1* l){
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_P1(l);
    NODE_P1* l0=l;                                             // We keep the linked list in a variable to be able to free it later. 
    STATION_P1* list=malloc(lenght*sizeof(STATION_P1));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          // Each element of the linked list (which lenght was determined) is directly put in a static list.
        l0=l0->next;
    }
    freeNODE_P1(l);
    // STEP 3 : Sorting (default is descending sort, so using -r will make it ascending)
    // A bubble sort is applied on the stations' IDs.
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Station ID;minimal pressure;maximal pressure;average pressure"
    fprintf(o,"Station ID;minimal pressure;maximal pressure;average pression\n");
    for(i=0;i<lenght;i++){                                   // Since the station ID is stored as an int, we need to add a 0 before the ID when it is lower than 9999.
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%f;%f;%f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
        }
        else{
            fprintf(o,"%d;%f;%f;%f\n",(*(list+i)).id,(*(list+i)).minimal,(*(list+i)).maximal,(*(list+i)).average);
        }  
    }
    free(list);
    return 0;
}

int getlenghtNODE_P2(NODE_P2* l){
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
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_P2(l);
    NODE_P2* l0=l;                                              
    TIME_P2* list=malloc(lenght*sizeof(TIME_P2));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->t;                                          
        l0=l0->next;
    }
    freeNODE_P2(l);
    // STEP 3 : Sorting by chronological order.
    // A bubble sort is applied on the dates.
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Time (UTC) ; average temperature (world)"
    fprintf(o,"Time;average pressure\n");
    for(i=0;i<lenght;i++){                                  
        producestring_P2(o,*(list+i)); 
    }
    free(list);
    return 0;
}


int tabP2sort2(FILE* o,NODE_P2* l){
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_P2(l);
    NODE_P2* l0=l;                                              
    TIME_P2* list=malloc(lenght*sizeof(TIME_P2));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->t;                                          
        l0=l0->next;
    }
    freeNODE_P2(l);
    // STEP 3 : Sorting by chronological order.
    // A bubble sort is applied on the dates.
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Time (UTC) ; average temperature (world)"
    fprintf(o,"Time;average pressure\n");
    for(i=0;i<lenght;i++){                                  
        producestring_P2(o,*(list+i)); 
    }
    free(list);
    return 0;
}


int getlenghtNODE_W(NODE_W* l){
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
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_W(l);
    NODE_W* l0=l;
    STATION_W* list=malloc(lenght*sizeof(STATION_W));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;
        l0=l0->next;
    }
    freeNODE_W(l);
    // STEP 3 : Sorting by ID (ascending sort)
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
    // STEP 4 : Writing
    fprintf(o,"ID;average wind orientation;average wind speed\n");
    for(i=0;i<lenght;i++){
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%d;%f\n",(*(list+i)).id,(*(list+i)).orientation,(*(list+i)).speed);
        }
        else{
            fprintf(o,"%d;%d;%f\n",(*(list+i)).id,(*(list+i)).orientation,(*(list+i)).speed);
        }  
    }
    free(list);
    return 0;
}

int tabWsort2(FILE* o, NODE_W* l){
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_W(l);
    NODE_W* l0=l;
    STATION_W* list=malloc(lenght*sizeof(STATION_W));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;
        l0=l0->next;
    }
    freeNODE_W(l);
    // STEP 3 : Sorting by ID (ascending sort)
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
    // STEP 4 : Writing
    fprintf(o,"ID;average wind orientation;average wind speed\n");
    for(i=0;i<lenght;i++){
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%d;%f\n",(*(list+i)).id,(*(list+i)).orientation,(*(list+i)).speed);
        }
        else{
            fprintf(o,"%d;%d;%f\n",(*(list+i)).id,(*(list+i)).orientation,(*(list+i)).speed);
        }  
    }
    free(list);
    return 0;
}

int getlenghtNODE_H(NODE_H* l){
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
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_H(l);
    NODE_H* l0=l;
    STATION_H* list=malloc(lenght*sizeof(STATION_H));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;
        l0=l0->next;
    }
    freeNODE_H(l);
    // STEP 3 : Sorting by height (default is descending sort, so using -r will make it ascending)
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
    // STEP 4 : Writing
    fprintf(o,"ID;height(m)\n");
    for(i=0;i<lenght;i++){
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%d\n",(*(list+i)).id,(*(list+i)).height);
        }
        else{
            fprintf(o,"%d;%d\n",(*(list+i)).id,(*(list+i)).height);
        }  
    }
    free(list);
    return 0;
}


int tabHsort2(FILE* o,NODE_H* l){
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_H(l);
    NODE_H* l0=l;
    STATION_H* list=malloc(lenght*sizeof(STATION_H));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;
        l0=l0->next;
    }
    freeNODE_H(l);
    // STEP 3 : Sorting by height (default is descending sort, so using -r will make it ascending)
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
    // STEP 4 : Writing
    fprintf(o,"ID;height(m)\n");
    for(i=0;i<lenght;i++){
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%d\n",(*(list+i)).id,(*(list+i)).height);
        }
        else{
            fprintf(o,"%d;%d\n",(*(list+i)).id,(*(list+i)).height);
        }  
    }
    free(list);
    return 0;
}

int getlenghtNODE_M(NODE_M* l){
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
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_M(l);
    NODE_M* l0=l;                                             // We keep the linked list in a variable to be able to free it later. 
    STATION_M* list=malloc(lenght*sizeof(STATION_M));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          // Each element of the linked list (which lenght was determined) is directly put in a static list.
        l0=l0->next;
    }
    freeNODE_M(l);
    // STEP 3 : Sorting by maximal moisture level (default is descending sort, so using -r will make it ascending)
    // A bubble sort is applied on the moisture values of the structures (STATION_M).
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Station ID;maximal moisture level"
    fprintf(o,"ID;maximal moisture level\n");
    for(i=0;i<lenght;i++){                                   // Since the station ID is stored as an int, we need to add a 0 before the ID when it is lower than 9999.
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%d\n",(*(list+i)).id,(*(list+i)).maximal);
        }
        else{
            fprintf(o,"%d;%d\n",(*(list+i)).id,(*(list+i)).maximal);
        }  
    }
    free(list);
    return 0;
}

int tabMsort2(FILE* o,NODE_M* l){
    // STEP 2 : Transfering to a static list
    // To make the sort easier, we transform the linked list into a static list.
    int i;
    int lenght=getlenghtNODE_M(l);
    NODE_M* l0=l;                                             // We keep the linked list in a variable to be able to free it later. 
    STATION_M* list=malloc(lenght*sizeof(STATION_M));

    for(i=0;i<lenght;i++){
        *(list+i)=l0->s;                                          // Each element of the linked list (which lenght was determined) is directly put in a static list.
        l0=l0->next;
    }
    freeNODE_M(l);
    // STEP 3 : Sorting by maximal moisture level (default is descending sort, so using -r will make it ascending)
    // A bubble sort is applied on the moisture values of the structures (STATION_M).
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
    // STEP 4 : Writing
    // Each element of the sorted list is then written in the output file.
    // Format : "Station ID;maximal moisture level"
    fprintf(o,"ID;maximal moisture level\n");
    for(i=0;i<lenght;i++){                                   // Since the station ID is stored as an int, we need to add a 0 before the ID when it is lower than 9999.
        if((*(list+i)).id <= 9999){
            fprintf(o,"0%d;%d\n",(*(list+i)).id,(*(list+i)).maximal);
        }
        else{
            fprintf(o,"%d;%d\n",(*(list+i)).id,(*(list+i)).maximal);
        }  
    }
    free(list);
    return 0;
}