//Lab #2 for CS_1050
//Completed 9/13/18
//Task
//  Write a program that:
//      -Reads two non-negative numbers
//      -Performs vairous arithmetic operations
//      -Finds the larger of the two numbers

#include <stdio.h>
#include <math.h>

int main( void)
{

	//Declaring variables
    float number1;
    float number2;
	float sum;
    float difference;
	float product;
    float quotient;
    float biggerNumber;
    float number3;
    float root;

	//Entering the  first number
	printf( "Enter the first number:\n\n" );
	scanf( "%f", &number1 );
	while ( number1 < 0 )
	{
		printf( "Please enter a non-negative number.\n\n" );
		scanf( "%f", &number1 );
	}
    printf( "\n" );

	//Entering the second number
	printf( "Enter the second number:\n\n" );
	scanf( "%f", &number2 );
	while ( number2 < 0 )
	{
		printf( "Please enter a non-negative number.\n\n" );
		scanf( "%f", &number2 );
	}
	printf( "\n" );

	//Add the two numbers
    printf( "-ADDITION-\n" );
    sum = number1 + number2;
	printf( "The sum of %f and %f is %f.\n\n", number1, number2, sum );

    //Subtract the two numbers
    printf( "-SUBTRACTION-\n" );
    difference = number1 - number2;
    printf( "The difference of %f and %f is %f.\n\n", number1, number2, difference );

	//Multiply the two numbers
    printf( "-MULTIPLICATION-\n" );
    product = number1 * number2;
	printf( "The product of %f and %f is %f.\n\n", number1, number2, product );

    //Divide the two numbers
    printf( "-DIVISION-\n" );
    while ( number2 == 0 )
    {
        printf("Cannot divide by zero! Please enter a new number:\n\n" );
        scanf( "%f", &number2 );
    }
    quotient = (float) number1 / number2;
    printf( "The quotient of %f and %f to two decimal places is %f.\n\n", number1, number2, quotient );

    //Find the bigger number
    if( number1 >= number2 )
    {
        biggerNumber = number1;
    }
    else
    {
        biggerNumber = number2;
    }

    printf( "-BIGGER NUMBER-\n" );
    printf( "The bigger number is %f.\n\n", biggerNumber);

    //Take the square root of a number
    printf( "-SQUARE ROOT-\n");
    printf( "Please enter a number for the square root operation:\n\n" );
    scanf( "%f", &number3 );
    while ( number3 < 0 )
    {
        printf( "Please enter a non-negative number.\n\n");
        scanf( "%f", &number3 );
    }
    root = sqrt(number3);
    printf( "The square root of %f to two decimal places is %f.\n\n", number3, root);

	return 0;
}
