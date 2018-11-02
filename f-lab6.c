//Paul Orton
//Lab 6
//2D Arrays

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20


//Function Prototyping
int check_error(int size);
void initialize_2Darray(int array[][MAX], int size);
void print_2Darray(int array[][MAX], int size);
int findZeros(int array[][MAX], int size);
int findEvenOdd(int array[][MAX], int size);
void printTranspose(int array[][MAX], int size);
void flattenArray(int array[][MAX], int size);
void bubbleSort(int array[][MAX], int size);

//Main Function
int main(void)
{
    
    //Initializing variables
    srand(time(NULL));
    int array[MAX][MAX] = {};
    int size = 0;
    int checker = 0;
    int zeros = 0;
    int evens = 0;
    int odds = 0;

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

    //Find the number of zeros in the array
    zeros = findZeros(array, size);

    printf("\n");
    
    printf("The number of zeros in the 2-D array is %d\n", zeros);

    printf("\n");

    //Find the number of evens in the array
    evens = findEvenOdd(array, size);
    
    printf("The number of evens in the 2-D array is %d\n", evens);

    printf("\n");
    
    //Find the number of odds in the array
    odds = (size * size) - evens;
    
    printf("The number of odds in the 2-D array is %d\n", odds);

    printf("\n");

    //Print the transposed array
    printTranspose(array, size);

    printf("\n");

    //Print the flattened array    
    flattenArray(array, size);
    
    printf("\n");

    //Print the sorted array
    printf("\n\n\t[BONUS]\n\n");
    
    bubbleSort(array, size);

    printf("\n\n\n");

    //Return statement
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
void initialize_2Darray(int array[][MAX], int size)
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
void print_2Darray(int array[][MAX], int size)
{
    int row = 0;
    int col = 0;

    printf("THE 2-D ARRAY IS:\n");

    for(row = 0; row < size; row++)
    {   
        for(col = 0; col < size; col++)
        {
            printf("%3d", array[row][col]);
        }
        
        printf("\n");

    }
}

//Counting zeros in array
int findZeros(int array[][MAX], int size)
{
    int row = 0;
    int col = 0;
    int zeros = 0;

    for(row = 0; row < size; row++)
    {   
        for(col = 0; col < size; col++)
        {
            if(array[row][col] == 0)
            {
                zeros++;
            }
        }
    }

    return zeros;
}

//Finds the number of evens in the array
int findEvenOdd(int array[][MAX], int size)
{
    int row = 0;
    int col = 0;
    int evens = 0;

    for(row = 0; row < size; row++)
    {
        for(col = 0; col < size; col++)
        {
            if(array[row][col] % 2 == 0)
            {
                evens++;
            }
        }
    }

    return evens;
}

//Transposes the array
void printTranspose(int array[][MAX], int size)
{
    int row = 0;
    int col = 0;

    printf("THE TRANSPOSED 2-D ARRAY IS:\n");

    for(row = 0; row < size; row++)
    {   
        for(col = 0; col < size; col++)
        {
            printf("%3d", array[col][row]);
        }
        
        printf("\n");

    }

}

//Flattens the array
void flattenArray(int array[][MAX], int size)
{
    int flatArray[MAX * MAX] = {}; 

    for(int row = 0; row < size; row++)
    {   
        for(int col = 0; col < size; col++)
        {
            flatArray[col + (row * col)] = array[row][col];
        }

    }

    printf("THE FLATTENED 2-D ARRAY IS:\n"); 

    for(int i = 0; i < size * size; i++)
    {
        printf("%3d", flatArray[i]);
    }

}

void bubbleSort(int array[][MAX], int size)
{
    int row = 0;
    int col = 0;
    int hold = 0;
    int i = 0;
    int j = 0;

    for(row = 0; row < size; row++)
    {
        for(col = 0; col < size; col++)
        {
            hold = array[row][col];
            j = col + 1;

            for(i = row; i < size; i++)
            {
                while(j < size)
                {
                    if(hold > array[i][j])
                    {
                        hold = array[i][j];
                        array[i][j] = array[row][col];
                        array[row][col] = hold;
                    }
                    j++;
                }
                j = 0;
            }
        }        
    }

    printf("THE SORTED ARRAY IS:\n"); 

    row = 0;
    col = 0;

    for(row = 0; row < size; row++)
    {
        for(col = 0; col < size; col++)
        {
            printf("%3d", array[row][col]);
        }
    }
}
