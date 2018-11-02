//Paul Orton
//Prelab 6
//2D Arrays

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

//Function Prototyping
int check_error(int size);
void initialize_2Darray(int array[MAX][MAX], int size);
void print_2Darray(int array[MAX][MAX], int size);
int findZeros(int array[][MAX], int size);

int main(void)
{
    
    //Initializing variables
    srand(time(NULL));
    int array[MAX][MAX] = {};
    int size = 0;
    int checker = 0;
    int counter = 0;

    //Ask for size
    printf("\n\n");
    printf("Enter the size of the 2-D array: ");
    scanf("%d", & size);
    printf("\n");

    //Error checking
    checker = check_error(size);
    while(checker == 0)
    {
        printf("Please enter a value between 1-20 only: ");
        scanf("%d", & size);
        printf("\n");

        checker = check_error(size);
    }

    //Initialize the array
    initialize_2Darray(array, size);

    //Print the array
    print_2Darray(array, size);

    //Count the number of zeros in the array
    counter = findZeros(array, size);

    printf("\n");

    printf("The number of zeros in the 2-D array is %d\n", counter);

    printf("\n");

    return 0;
}

//Function declaration

//Error checking
int check_error(int size)
{
    if(size <= 0 || size > 20)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Array initialization
void initialize_2Darray(int array[MAX][MAX], int size)
{
    int row = 0;
    int col = 0;
    
    for(row = 0; row < size; row++)
    {
        for(col = 0; col < size; col++)
        {
            array[row][col] = (rand() % 10);
        }
    }
}

//Array printing
void print_2Darray(int array[MAX][MAX], int size)
{
    int row = 0;
    int col = 0;

    printf("THE 2-D ARRAY IS:\n");

    for(row = 0; row < size; row++)
    {   
        for(col = 0; col < size; col++)
        {
            printf("%d", array[row][col]);
        }
        
        printf("\n");

    }
}

//Counting zeros in array
int findZeros(int array[][MAX], int size)
{
    int row = 0;
    int col = 0;
    int counter = 0;

    for(row = 0; row < size; row++)
    {   
        for(col = 0; col < size; col++)
        {
            if(array[row][col] == 0)
            {
                counter++;
            }
        }
    }

    return counter;
}
