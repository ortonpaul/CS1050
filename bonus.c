//Lab 3 by Paul Orton
//Created on 9/20/18
//
//Task:
//  Calculate the length of a triangle using the Pythagorean Theorem
//  -Allow user to choose whether they're inputting two legs or a leg and the hypotenuse
//  -Read a length from the user between 1-100
//  -Read a second length from the user between 1-100
//      +If entering hypotenuse, make sure it is greater than the leg
//  -Calculate the side length

#include <stdio.h>
#include <math.h>

int main(void)
{

    int base;
    int exponent;
    int i;
    int temp;
    int result = 1;

    printf("Enter a number:\n");
    scanf("%d", &base);

    printf("Enter the power:\n");
    scanf("%d", &exponent);

    for(i = 0;i < exponent; i++)
    {
        temp = base;
        result = result * temp;
    }
    printf("pow(%d, %d) = %d\n",base, exponent, result);

    return 0;
}
