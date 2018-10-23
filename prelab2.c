//Prelab #2 for CS_1050
//Completed 9/2/18
//Task: Create a program that reads two non-negative integer numbers from the user
//and then adds and multiplies them.

#include <stdio.h>

int main( void)
{

	//Declaring variables
	int number1;
	int number2;
	int sum;
    int difference;
	int product;
    float quotient;

	//Entering the  first number
	printf( "Enter the first number:\n\n" );
	scanf( "%d", &number1);
	while ( number1 < 0 )
	{
		printf( "Please enter a non-negative number.\n\n" );
		scanf( "%d", &number1 );
	}
	printf( "\n" );

	//Entering the second number
	printf( "Enter the second number:\n\n" );
	scanf( "%d", &number2);
	while ( number2 < 0 )
	{
		printf( "Please enter a non-negative number.\n\n" );
		scanf( "%d", &number2 );
	}
	printf( "\n" );

	//Add the two numbers
	sum = number1 + number2;
	printf( "The sum of %d and %d is %d.\n\n", number1, number2, sum );

    //Subtract the two numbers
    difference = number1 - number2;
    printf( "The difference of %d and %d is %d.\n\n", number2, number1, difference );

	//Multiply the two numbers
	product = number1 * number2;
	printf( "The product of %d and %d is %d.\n\n", number1, number2, product );

    //Divide the two numbers
    quotient = number1 / number2;
    printf( "The quotient of %d and %d to two decimal places is %.2f.\n\n", number1, number2, quotient );

	return 0;

}
