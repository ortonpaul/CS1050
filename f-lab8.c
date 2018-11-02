//Lab 8 by Paul Orton
//Created on 11/1/18
//Estimate cos(x) using the first n terms in the Maclaurin series expansion

#include <stdio.h>
#include <math.h>
#define MAX 20

//Function prototyping
int errorCheck(int number);
int factorial(int n);
void printArray(float *arrayPtr, int n);
void maclaurinSeries(float *arrayPtr, int x, int n);
void reverseArray(float *arrayPtr, int n);

//Main function
int main()
{
    //Variable declaration
    int x = 0;
    int n = 0;
    int checker = 0;
    float array[MAX] = {};
    float *arrayPtr = array;
    
    //Asks for limit to use in calculation
    printf("\n\nEnter a value to compute the Maclaurin series expansion (x): ");
    scanf("%d", &x);
    printf("\n");
    
    //Error checking for limit
    checker = errorCheck(x);

    while(checker == 0)
    {
        printf("x must be larger than 0 and less than 20\n\n");

        printf("Enter a value to compute the Maclaurin series expansion (x): ");
        scanf("%d", &x);
        printf("\n");

        checker = errorCheck(x);
    }

    //Asks for n to use in calculation
    printf("\n\nEnter a value for the Maclaurin series to run (n): ");
    scanf("%d", &n);
    printf("\n");
    
    //Error checking for limit
    checker = errorCheck(n);

    while(checker == 0)
    {
        printf("n must be larger than 0 and less than 20\n\n");

        printf("Enter a value for the Maclaurin series to run (n): ");
        scanf("%d", &n);
        printf("\n");

        checker = errorCheck(n);
    }

    maclaurinSeries(arrayPtr, n, x);

    printArray(arrayPtr, n);

    reverseArray(arrayPtr, n);

    return 0;
}

//Function Declaration

//Checks to see if a number is between 1 and 20
int errorCheck(int x)
{
    if(x < 1 || x >= MAX)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Calculates factorial from 1 to the limit, inclusive
int factorial(int n)
{
    int total = 1;

    for(int i = 0; i < n; i++)
    {   
        total *= (i + 1);
    }

    return total;
}

//Prints the content of the array
void printArray(float *arrayPtr, int n)
{
    printf("The array for the Maclaurin series is:\n");
    
    for(int i = 0; i <= n; i++)
    {
        printf("%.4f ", *(arrayPtr + i));
    }

    printf("\n\n");
}

//Calculates the values and stores them
void maclaurinSeries(float *arrayPtr, int size, int x)
{
    float total = 1;

    *arrayPtr = 1;

    for(int n = 1; n <= size; n++)
    {
        *(arrayPtr + n) =  total + (pow(-1, n) * pow(x , 2 * n)) / factorial(2 * n);
        total = *(arrayPtr + n);
    }
}

//Bonus
void reverseArray(float *arrayPtr, int n)
{
    printf("----------BONUS----------\n\n");
    
    printf("The reverse array is:\n");
    
    for(int i = n; i >= 0; i--)
    {
        printf("%.4f ", *(arrayPtr + i));
    }

    printf("\n\n");
}
