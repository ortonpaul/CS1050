//Prelab 9
//Created by Paul Orton

//Including libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Symbolic constant
#define MAX 50

//Function prototyping
void get_size(int *size);
int check_size(int);
void initialize_pointerArray(int *, int);
void print_pointerArray(int *, int);
int find_max(int *, int);

//Main function
int main(void)
{
    //Seding rand()
    srand(time(NULL));

    //variable declaration
    int array[MAX] = {};
    int *pointer = array;
    int size;
    int max;

    printf("\n\n");

    //Asks user for size
    get_size(&size);

    //Initializes the array to random values 1-10
    initialize_pointerArray(pointer, size);

    //Prints the array
    print_pointerArray(pointer, size);

    //Finds the first occurence of the largest element in the array
    max = find_max(pointer, size);

    printf("The largest value in the pointer is: %d\n\n", max);

    return 0;
}

//Asks user for input and performs error checking
void get_size(int *size)
{
    int checker = 0;

    printf("Enter the size of the input: ");
    scanf("%d", size);

    printf("\n");

    checker = check_size(*size);

    while(checker == 0)
    {
        printf("Invalid input. Enter the size of the array again: ");
        scanf("%d", size);
        printf("\n");
        checker = check_size(*size);
    }
}

//Error checking for size
int check_size(int size)
{
    if(size >= 1 && size <= 50)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Initializes the array to random values 1-10
void initialize_pointerArray(int *pointer, int size)
{
    for(int i = 0; i < size; i++)
    {
        *(pointer + i) = (rand() % 10) + 1;
    }
}

//Prints the array
void print_pointerArray(int *pointer, int size)
{
    printf("Input array\n");
    
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(pointer + i));
    }

    printf("\n\n");
}

//Finds the first occurence of the largest value in the array
int find_max(int *pointer, int size)
{
    int max = 0;

    for(int i = 0; i < size; i++)
    {
        if(*(pointer + i) > max)
        {
            max = *(pointer + i);
        }
    }

    return max;
}
