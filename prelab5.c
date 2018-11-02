//Prelab 5 by Paul Orton
//9/28/18

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function prototypes
int check_error(int size);
void initialize_array(int *array, int size);
void print_array(int *array, int size);

int main()
{
    int array[50] = {0};
    int checker;
    int size = 0;

    srand(time(NULL));

    printf("\n");
    printf("Enter the size of the input: ");
    scanf("%d", &size);
    printf("\n");
    checker = check_error(size);

    //Asks for new input if error checking fails
    while(checker == 0)
    {
        printf("Invalid input. Enter the size of the input again: ");
        scanf("%d", &size);
        printf("\n");
        checker = check_error(size);
    }
    
    initialize_array(array, size);
    
    printf("Input array 1\n");
    print_array(array, size);

    return 0;
}

//Function Implementation

//Takes an integer number and checks if the number is between 1-50
int check_error(int size)
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

//Takes an array and its size and intializes the integers to randoms between 0-9 
void initialize_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
}

//Prints array
void print_array(int *array, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    
    printf("\n\n");
}

