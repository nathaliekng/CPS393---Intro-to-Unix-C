#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define MAXLENGTH 50
#define badExit 1
#define goodExit 0

/*
normalize function
Purpose: To normalize vectors.
Parameters: Array of doubles X to access vectors, array of doubles Y to store normalized values and number of vector elements as int
Return: returns nothing
Input: Doesn't take any extra input other than input from parameters 
Output: No output. 
*/

void normalize(double X[], double Y[], int size); 

/*
testNonDigit function
Purpose: Tests all values inputted to see if they're valid inputs. It is similar to testFirst, except
it's looking at more than one value so this function will ignore spaces. 
Parameters: String named waste being all the waste values inputted , X array and size. 
Return: returns an integer value either 1 or 0 that's used for exit codes in main function
Input: No extra input other than parameter values 
Output: Prints bad input if it's a bad input. 
*/

int testNonDigit(char waste[], double X[], int size);

/*
printNormalizedVector function
Purpose: Print the normalized vectors. 
Parameters: Array of doubles in Y to access normalized vectors. Variable size as integer to use in for loop.
Return: Returns nothing
Input: No extra input other than parameter values.
Output: Prints normalized vectors. 
*/

void printNormalizedVector(double Y[], int size);

/*
printVector function
Purpose: To print all vector elements in array X. 
Parameters: Array of doubles X to access vectors. variable size as integer used for for loop. 
Return: Returns nothing
Input: No extra input other than parameter values 
Output: Prints vectors.
*/

void printVector(double X[], int size);

/*
readInput function
Purpose: This function reads the rest of the input values and stores them in array X.
Parameters: Array of doubles to store vectors, string waste to store input that can't be used to normalize, 
integer values code and size. Code is used for the exit and size is used for for loops. 
Return: Nothing
Input: Scanf and fget are used to gather input of vector elements and waste values. 
Output: No output. 
*/

void readInput(double X[], int code, int size, char waste[]);

/*
readFirst function
Purpose: To read the first input and test if it has bad input (i.e. alphabet or non-digits)
Parameters: Array of doubles named X, String named waste and integer values for y and code.
X is the array that the vector elements will be stored in and waste will be used for any values inputted
that are not needed for normalizing (i.e. values that are of bad input or overflowing values that don't match the size )
Return: returns an integer value either 1 or 0 that's used to determine whether the program should continue to normalize
Input: Input first value used for size
Output: No output
*/

int readFirst(double X[], char waste[], int *y, int *code);
