#include "headeralex.h"

/*
------------------------------------------
TEMPERATURE FUNCTIONS
------------------------------------------
*/

/*
------------------------------------------
PRESSURE FUNCTIONS
------------------------------------------
*/

/*
------------------------------------------
WIND FUNCTIONS
------------------------------------------
*/

void freeNODE_W(NODE_W* l){
    while(l!=NULL){
        NODE_W* temp = l;
        l=l->next;
        free(temp);
    }
}

int inlistNODE_W(NODE_W* l,int id){
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


// ID;orientation;vitesse
int tabWsort1(FILE* f,FILE* o){

    NODE_W* list0 = NULL;
    int id;
    int orientation;
    float speed;
    // STEP 1 : Building a linked list, reading the file line by line, calculating average orientation and speed for each station
    while(feof(f)==0){
        fscanf(f,"%d;%d;%f",&id,&orientation,&speed);
        if(inlistNODE_W(list0,id)==0){
            list0 = addNODE_W(list0,id,orientation,speed);
        }
        else{
            list0 = searchandaddNODE_W(list0,id,orientation,speed);
        }
    }
    list0 = averagingNODE_W(list0);
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_W(list0);
    NODE_W* list00=list0;
    STATION_W* list=malloc(lenght*sizeof(STATION_W));

    for(i=0;i<lenght;i++){
        *(list+i)=list00->s;
        list00=list00->next;
    }
    freeNODE_W(list0);
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

// ID;orientation;vitesse
int tabWsort2(FILE* f,FILE* o){

    NODE_W* list0 = NULL;
    int id;
    int orientation;
    float speed;
    // STEP 1 : Building a linked list, reading the file line by line, calculating average orientation and speed for each station
    while(feof(f)==0){
        fscanf(f,"%d;%d;%f",&id,&orientation,&speed);
        if(inlistNODE_W(list0,id)==0){
            list0 = addNODE_W(list0,id,orientation,speed);
        }
        else{
            list0 = searchandaddNODE_W(list0,id,orientation,speed);
        }
    }
    list0 = averagingNODE_W(list0);
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_W(list0);
    NODE_W* list00=list0;
    STATION_W* list=malloc(lenght*sizeof(STATION_W));

    for(i=0;i<lenght;i++){
        *(list+i)=list00->s;
        list00=list00->next;
    }
    freeNODE_W(list0);
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

/*
------------------------------------------
HEIGHT FUNCTIONS
------------------------------------------
*/

void freeNODE_H(NODE_H* l){
    while(l!=NULL){
        NODE_H* temp = l;
        l=l->next;
        free(temp);
    }
}

int inlistNODE_H(NODE_H* l,int id){
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

// ID;altitude
int tabHsort1(FILE* f,FILE* o){

    NODE_H* list0 = NULL;
    int id;
    int height;

    // STEP 1 : Building a linked list, reading the file line by line
    while(feof(f)==0){
        fscanf(f,"%d;%d",&id,&height);
        if(inlistNODE_H(list0,id)==0){
            list0 = addNODE_H(list0,id,height);
        }
    }
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_H(list0);
    NODE_H* list00=list0;
    STATION_H* list=malloc(lenght*sizeof(STATION_H));

    for(i=0;i<lenght;i++){
        *(list+i)=list00->s;
        list00=list00->next;
    }
    freeNODE_H(list0);
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

// ID;altitude
int tabHsort2(FILE* f,FILE* o){

    NODE_H* list0 = NULL;
    int id;
    int height;

    // STEP 1 : Building a linked list, reading the file line by line
    while(feof(f)==0){
        fscanf(f,"%d;%d",&id,&height);
        if(inlistNODE_H(list0,id)==0){
            list0 = addNODE_H(list0,id,height);
        }
    }
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_H(list0);
    NODE_H* list00=list0;
    STATION_H* list=malloc(lenght*sizeof(STATION_H));

    for(i=0;i<lenght;i++){
        *(list+i)=list00->s;
        list00=list00->next;
    }
    freeNODE_H(list0);
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

/*
------------------------------------------
MOISTURE FUNCTIONS
------------------------------------------
*/

void freeNODE_M(NODE_M* l){
    while(l!=NULL){
        NODE_M* temp = l;
        l=l->next;
        free(temp);
    }
}

int inlistNODE_M(NODE_M* l,int id){
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

// ID;humidité
int tabMsort1(FILE* f,FILE* o){

    NODE_M* list0 = NULL;
    int id;
    int moisture;
    // STEP 1 : Building a linked list, reading the file line by line
    while(feof(f)==0){
        fscanf(f,"%d;%d",&id,&moisture);
        if(inlistNODE_M(list0,id)==0){
            list0 = addNODE_M(list0,id,moisture);
        }
        else{
            list0 = searchandmaybereplaceNODE_M(list0,id,moisture);
        }
    }
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_M(list0);
    NODE_M* list00=list0;
    STATION_M* list=malloc(lenght*sizeof(STATION_M));

    for(i=0;i<lenght;i++){
        *(list+i)=list00->s;
        list00=list00->next;
    }
    freeNODE_M(list0);
    // STEP 3 : Sorting by maximal moisture level (default is descending sort, so using -r will make it ascending)
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
    fprintf(o,"ID;maximal moisture level\n");
    for(i=0;i<lenght;i++){
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

// ID;humidité
int tabMsort2(FILE* f,FILE* o){

    NODE_M* list0 = NULL;
    int id;
    int moisture;
    // STEP 1 : Building a linked list, reading the file line by line
    while(feof(f)==0){
        fscanf(f,"%d;%d",&id,&moisture);
        if(inlistNODE_M(list0,id)==0){
            list0 = addNODE_M(list0,id,moisture);
        }
        else{
            list0 = searchandmaybereplaceNODE_M(list0,id,moisture);
        }
    }
    // STEP 2 : Transfering to a static list
    int i;
    int lenght=getlenghtNODE_M(list0);
    NODE_M* list00=list0;
    STATION_M* list=malloc(lenght*sizeof(STATION_M));

    for(i=0;i<lenght;i++){
        *(list+i)=list00->s;
        list00=list00->next;
    }
    freeNODE_M(list0);
    // STEP 3 : Sorting by maximal moisture level (default is descending sort, so using -r will make it ascending)
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
    fprintf(o,"ID;maximal moisture level\n");
    for(i=0;i<lenght;i++){
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

/*
------------------------------------------
MAIN
------------------------------------------
*/

/*
int main(int argc, char* argv){
    FILE* input = fopen(argv[1],'r');            // The input file given by shell is opened.
    if(input==NULL){                             // Error code 2 if there was a problem opening the file.  
        return 2;
    }
    FILE* output = fopen(argv[2],'w');           // The output file given by shell is created or starts being rewritten.
    if(output==NULL){                            // Error code 3 if there was a problem with this file.
        return 3;
    }
    if(argv[13]==0){                             // The user did not activate descending sort.
        if(argv[3]==1){                          // Executes if temperature was chosen.
            if(argv[4]==1){                      // Executes if mode 1 was chosen for temperature.
                tabTsort11(input);
            }
            else if(argv[4]==2){                 // Executes if mode 2 was chosen for temperature.
                tabTsort21(input);
            }
            else{                                // Executes if mode 3 was chosen for temperature.
                tabTsort31(input);
            }
        }
        else if(argv[5]==1){                     // Executes if temperature or pressure was chosen (we put them in the same "if" because their outputs are very similar).
            if(argv[6]==1){                      // Executes if mode 1 was chosen for pressure.
                tabPsort11(input);
            }
            else if(argv[6]==2){                 // Executes if mode 2 was chosen for pressure.
                tabPsort21(input);
            }
            else{                                // Executes if mode 3 was chosen for pressure.
                tabPsort31(input);
            }
        }
        else if(argv[7]==1){                     // Executes if wind was chosen.
            tabWsort1(input);
        }
        else if(argv[8]==1){                     // Executes if height was chosen.
            tabHsort1(input,output);
        }
        else{                                    // Executes if moisture was chosen.
            tabMsort1(input);
        }
    }
    else{                                        // The user activated descending sort.
        if(argv[3]==1){         
            if(argv[4]==1){                      // Executes if mode 1 was chosen for temperature or pressure.
                tabTsort12(input);
            }
            else if(argv[4]==2){                 // Executes if mode 2 was chosen for temperature or pressure.
                tabTsort22(input);
            }
            else{                                // Executes if mode 3 was chosen for temperature or pressure.
                tabTsort32(input);
            }
        }
        else if(argv[5]==1){         
            if(argv[6]==1){                      // Executes if mode 1 was chosen for temperature or pressure.
                tabPsort12(input);
            }
            else if(argv[6]==2){                 // Executes if mode 2 was chosen for temperature or pressure.
                tabPsort22(input);
            }
            else{                                // Executes if mode 3 was chosen for temperature or pressure.
                tabPsort32(input);
            }
        }
        else if(argv[7]==1){                     // Executes if wind was chosen.
            tabWsort2(input);
        }
        else if(argv[8]==1){                     // Executes if height was chosen.
            tabHsort2(input);
        }
        else{                                    // Executes if moisture was chosen.
            tabMsort2(input);
        }
    }
    fclose(input);
    fclose(output);
    return 0;                                    // If no error occured by now, the program executed successfully and returns 0.
}
*/
int main(){
    FILE* input = fopen("testvent.txt","r");            // The input file given by shell is opened.
    if(input==NULL){                             // Error code 2 if there was a problem opening the file.  
        return 2;
    }
    FILE* output = fopen("sortievent.txt","w");           // The output file given by shell is created or starts being rewritten.
    if(output==NULL){                            // Error code 3 if there was a problem with this file.
        return 3;
    }
    int a;
    a=tabWsort2(input,output);
    if(a!=0){
        printf("problem");
    }
    fclose(input);
    fclose(output);
    return 0;
}
