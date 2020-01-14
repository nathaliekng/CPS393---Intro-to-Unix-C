/*
Author: Nathalie Ng
Purpose: To normalize given vectors. 
Input: Size and vectors from stdin.
Output: Vector's inputted and the normalized vectors. If EOF or 0 is first input it will exit with value 1. 
Certification: I certify that this lab is entirely my own work. 
*/

#include "assign2funcs.h"
/*
 main function
 Purpose: Normalize vectors from stdin
 Parameters: No parameters for main
 Return: Returns exit code from EOF and 0 to stop program. Return values change based on bad/normal input.
 Input: Vector elements and size from stdin using readFirst() and readInput()
 Output: Main function calls printVector() and printNormalizedVector() to print vectors from stdin and normalized vectors.
 */

int main(){

    int size; //number of vector elements
    int x=0; // keep the while loop running
    int y=0; // used to determine whether or not the program should run normalize
    int code=goodExit; // used for exit. code changes based on input.
    int retvalue=0; // used to get the return value from readFirst()
    int retvalue2=0; // used to get the return value from test testNonDigit()
    char waste[MAXLENGTH]; //waste variable used to store any bad input.

    while(x==0){

        double X[MAXLENGTH]; //store vectors and resets everytime the while loop re-runs
        double Y[MAXLENGTH]; //store normalized vectors
        X[0]=0; //to make sure the start of each re-run is at 0
        for(int l=0; l<MAXLENGTH; l++){
            X[l]=0;
        }
        strcpy(waste, ""); //clear waste variable
        y=0; //reset y variable 

        //Check if first input is EOF. If it is, it will check if it's a bad input or an exit. 
        retvalue=readFirst(X, waste, &y, &code);
        
        if(retvalue==0){
            size=X[0];
            readInput(X, code, size, waste);

            //Test if waste is a digit or not. If it's a digit it will continue with normalizing.
            retvalue2=testNonDigit(waste, X, size);
            if(retvalue2==1){
                code=badExit;
                y=1;
            }
            if(y==0){
                normalize(X, Y, size);
                printVector(X, size);
                printNormalizedVector(Y,size);
            }
        }
    }
    return 0;
}
