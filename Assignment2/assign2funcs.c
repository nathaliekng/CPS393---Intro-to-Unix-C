/*
Author: Nathalie Ng
Purpose: Helper functions for main functions in main.
(Purpose for each helper function is in header file)
Input: N/A
Output: N/A
*/

#include "assign2funcs.h"

void normalize(double X[], double Y[],int size){   
    double sum; //accumulates total sum of all vectors in X
    double N; //X's length used to normalize
    
    //gather sum to normalize 
    for (int b=0; b<size; b++){
        sum+=(X[b]*X[b]);
    }
    N=sqrt(sum);
    //normalize each vector in X and store into Y
    for (int k=0; k<size; k++){
        Y[k]=X[k]/N;
    }
}

void printVector(double X[], int size){
    printf("VECTOR: [");
    for (int j=0; j<size-1; j++){
        printf(" %.3lf,", X[j]);
    }
    printf(" %.3lf ", X[size-1]);
    printf("] ");
}

void printNormalizedVector(double Y[], int size){
    printf("NORMALIZED: [");
    for (int k=0; k<size-1; k++){
        printf(" %.3lf,", Y[k]);
    }
    printf(" %.3lf ", Y[size-1]);
    printf("]\n");
}

void readInput(double X[], int code, int size, char waste[]){
    for(int g=0;g<size;g++){
        //Check the rest of the inputs if they are EOF.
        if(scanf("%lf", &X[g])==EOF){
            exit(code);
        }
    }
    //fgets is used to collect values after size indicated or collect bad input. 
    fgets(waste, MAXLENGTH, stdin);
}

int testNonDigit(char waste[], double X[], int size){
    //Check if waste value has anything in it (i.e. bad input or leftover numbers)
    //If it's not leftover numbers it will print bad input
    
    if(X[size-1]>0){
        return 0;
    }
    if(strlen(waste)>1){
        for(int k=0;k<strlen(waste);k++){
            //check if it's not a digit while ignoring spaces
            if(!isdigit(waste[k]) && !isspace(waste[k])){
                printf("BAD INPUT\n");
                return 1;
            }
        }
    }
    return 0;
}

int readFirst(double X[], char waste[], int *y, int *code){
    //check for EOR and if size=0
    if(scanf("%lf", &X[0])==EOF || X[0]==0){
        fgets(waste, MAXLENGTH, stdin);
        *y=1;
        //check if it's a bad input or an exit.
        if(strlen(waste)>1){
            for( int k=0; k<MAXLENGTH;k++){
                //check if it's an alphabet
                if(isalpha(waste[k])){
                    printf("BAD INPUT\n");
                    *y=1;
                    *code=badExit;
                    return 1;
                } 
                //check if it's punctuation 
                else if(!isdigit(waste[k])){
                    printf("BAD INPUT\n");
                    *y=1;
                    *code=badExit;
                    return 1;
                }
            }
        }
        else{
            //if it's not a bad input it will exit. 
            exit(*code);
        }
    }
    else if(X[0]>=10 || X[0] <1){
        //if size>9 or size<1 it will print bad input and be stored into waste
        printf("BAD INPUT\n");
        *code=badExit;
        *y=1;
        fgets(waste, MAXLENGTH, stdin);
        return 1;
    }
    return 0;
}
