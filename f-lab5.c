//Lab 5 by Paul Orton
//10/04/18


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Function prototypes
int check_error(int size);
void initialize_array(int *array, int size);
void print_array(int *array, int size);
float average(int *array, int size);
float std_dev(int *array, int size);
int min(int *array, int size);

int main(void)
{
    int array[50] = {0};
    int checker;
    int size = 0;
    float ave = 0;
    float stdDev = 0;
    int index = 0;

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
    
    printf("The array has elements:\n");
    print_array(array, size);

    printf("\n");
    ave = average(array, size);
    printf("The average is: %.2f\n", ave);

    printf("\n");
    stdDev = std_dev(array, size);
    printf("The standard deviation is: %.2f\n", stdDev);

    printf("\n\n[BONUS]\n\n");
    index = min( array, size);
    printf("The index of the smallest element is: %d\n\n", index);

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
        array[i] = (rand() % 9) + 1;
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

//Returns the average of the array
float average(int *array, int size)
{
    int sum = 0;
    float ave = 0;

    for(int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    ave = (float)sum / (float)size;
    
    return ave;
}

//Returns the standard deviation of the array
float std_dev(int *array, int size)
{
    float ave = 0;
    float stdDev = 0;

    ave = average(array, size);

    for(int i = 0; i < size; i++)
    {
        stdDev += (float)pow((array[i] - ave), 2);
    }

    return sqrt(stdDev / size);
}

//Finds the index of the smallest number
int min(int *array, int size)
{
    int index = 0;
    int min = 10;

    for(int i = 0; i < size; i++)
    {
        if(array[i] < min)
        {
            index = i;
            min = array[i];
        }
    }


    return index;
}
