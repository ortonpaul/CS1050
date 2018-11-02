//Prelab 8 by Paul Orton
//Created on 10/23/18

#include <stdio.h>
#define MAX 10

//Function prototyping
int errorCheck(int limit);
void factorial(int *arrayPtr, int limit);
void printArray(int *arrayPtr, int limit);

//Main function
int main()
{
    //Variable declaration
    int limit = 0;
    int checker = 0;
    int array[MAX] = {};
    int *arrayPtr = array;
    
    //Asks for limit to use in calculation
    printf("Enter a value to calculate the factorial: ");
    scanf("%d", &limit);
    printf("\n");
    
    //Error checking for limit
    checker = errorCheck(limit);

    while(checker == 0)
    {
        printf("Input must be larger than 0 and less than 10\n\n");

        printf("Enter a value to calculate the factorial: ");
        scanf("%d", &limit);
        printf("\n");

        checker = errorCheck(limit);
    }

    factorial(arrayPtr, limit);

    printArray(arrayPtr, limit);


    return 0;
}

//Function Declaration

//Checks to see if a number is between 1 and 10
int errorCheck(int limit)
{
    if(limit < 1 || limit >= MAX)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Calculates factorial from 1 to the limit, inclusive
void factorial(int *arrayPtr, int limit)
{
    int total = 1;

    for(int i = 0; i < limit; i++)
    {   
        total *= (i + 1);
        *(arrayPtr + i) = total;
    }
}

//Prints the content of the array
void printArray(int *arrayPtr, int limit)
{
    printf("The array of the stored factorial values:\n");
    
    for(int i = 0; i < limit; i++)
    {
        printf("%d ", *(arrayPtr + i));
    }

    printf("\n\n");
}
