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
    //Declaring main variables
    int choice;
    int leg1;
    int leg2;
    int hypotenuse;

    //Selecting input type
    printf("\n");
    printf("[RIGHT TRIANGLE SIDE LENGTH CALCULATION]\n\n");
    printf("Please select the lengths you have:\n");
    printf("[1] one leg and the hypotenuse.\n");
    printf("[2] both legs of the triangle.\n");
    printf("\n");
    scanf("%d", &choice);

    //Error checking
    while(choice != 1 && choice != 2)
    {
        printf("\n");
        printf("Invalid input.\n");
        printf("Please select the lenths you have:\n");
        printf("[1] one leg and the hypotenuse.\n");
        printf("[2] both legs of the triangle.\n");
        printf("\n");
        scanf("%d", &choice);
    }

    if(choice == 1)
    {
        //Leg input
        printf("\n");
        printf("Please enter the length of the leg:\n");
        printf("\n");
        scanf("%d", &leg1);
        //Error checking
        while(leg1 <1 || leg1 >100)
        {
            printf("\n");
            printf("Invalid input.\n");
            printf("Please enter a length from 1 to 100:\n");
            printf("\n");
            scanf("%d", &leg1);
        }
        printf("\n");
        //Hypotenuse input
        printf("Please enter the length of the hypotenuse:\n");
        printf("\n");
        scanf("%d", &hypotenuse);
        //Error checking
        while(hypotenuse <1 || hypotenuse >100)
        {
            printf("\n");
            printf("Invalid input.\n");
            printf("Please enter a length from 1 to 100:\n");
            printf("\n");
            scanf("%d", &hypotenuse);
        }
        while(hypotenuse < leg1)
        {
            printf("\n");
            printf("Invalid input.\n");
            printf("Please enter a length that is greater than the leg:\n");
            printf("\n");
            scanf("%d", &hypotenuse);
        }
        //Leg calculation
        printf("\n");
        printf("[CALCULATION]\n\n");
        printf("%.0f + b^2 = %.0f\n", (float) pow(leg1, 2), (float) pow(hypotenuse, 2));
        printf("Missing leg length= %.2f\n", (float) sqrt(pow(hypotenuse, 2) - pow(leg1, 2)));
    }
    else
    {
        //Leg 1 input
        printf("\n");
        printf("Please enter the length of the first leg:\n");
        printf("\n");
        scanf("%d", &leg1);
        //Error checking
        while(leg1 <1 || leg1 >100)
        {
            printf("\n");
            printf("Invalid input.\n");
            printf("Please enter a length from 1 to 100:\n");
            printf("\n");
            scanf("%d", &leg1);
        }
        printf("\n");
        //Leg 2 input
        printf("Please enter the length of the second leg:\n");
        printf("\n");
        scanf("%d", &leg2);
        //Error checking
        while(leg2 <1 || leg2 >100)
        {
            printf("\n");
            printf("Invalid input.\n");
            printf("Please enter a length from 1 to 100:\n");
            printf("\n");
            scanf("%d", &leg2);
        }
        //Hypotenuse calculation
        printf("\n");
        printf("[CALCULATION]\n\n");
        printf("%.0f + %.0f = c^2\n", (float) pow(leg1, 2), (float) pow(leg2, 2));
        printf("Hypotenuse length= %.2f\n", (float) sqrt(pow(leg1, 2) + pow(leg2, 2)));        
    }
    
    //Multiple calculations
    printf("Would you like to calculate again?\n");
    printf("Press 1 for no, 0 for yes:\n");
    printf("\n");
    scanf("%d", &choice);
    while(choice == 0)
    {

        //Selecting input type
        printf("\n");
        printf("[RIGHT TRIANGLE SIDE LENGTH CALCULATION]\n\n");
        printf("Please select the lengths you have:\n");
        printf("[1] one leg and the hypotenuse.\n");
        printf("[2] both legs of the triangle.\n");
        printf("\n");
        scanf("%d", &choice);

        //Error checking
        while(choice != 1 && choice != 2)
        {
            printf("\n");
            printf("Invalid input.\n");
            printf("Please select the lenths you have:\n");
            printf("[1] one leg and the hypotenuse.\n");
            printf("[2] both legs of the triangle.\n");
            printf("\n");
            scanf("%d", &choice);
        }

        if(choice == 1)
        {
            //Leg input
            printf("\n");
            printf("Please enter the length of the leg:\n");
            printf("\n");
            scanf("%d", &leg1);
            //Error checking
            while(leg1 <1 || leg1 >100)
            {
                printf("\n");
                printf("Invalid input.\n");
                printf("Please enter a length from 1 to 100:\n");
                printf("\n");
                scanf("%d", &leg1);
            }
            printf("\n");
            //Hypotenuse input
            printf("Please enter the length of the hypotenuse:\n");
            printf("\n");
            scanf("%d", &hypotenuse);
            //Error checking
            while(hypotenuse <1 || hypotenuse >100)
            {
                printf("\n");
                printf("Invalid input.\n");
                printf("Please enter a length from 1 to 100:\n");
                printf("\n");
                scanf("%d", &hypotenuse);
            }
            while(hypotenuse < leg1)
            {
                printf("\n");
                printf("Invalid input.\n");
                printf("Please enter a length that is greater than the leg:\n");
                printf("\n");
                scanf("%d", &hypotenuse);
            }
            //Leg calculation
            printf("\n");
            printf("[CALCULATION]\n\n");
            printf("%.0f + b^2 = %.0f\n", (float) pow(leg1, 2), (float) pow(hypotenuse, 2));
            printf("Missing leg length= %.2f\n", (float) sqrt(pow(hypotenuse, 2) - pow(leg1, 2)));
        }
        else
        {
            //Leg 1 input
            printf("\n");
            printf("Please enter the length of the first leg:\n");
            printf("\n");
            scanf("%d", &leg1);
            //Error checking
            while(leg1 <1 || leg1 >100)
            {      
                printf("\n");
                printf("Invalid input.\n");
                printf("Please enter a length from 1 to 100:\n");
                printf("\n");
                scanf("%d", &leg1);
            }
            printf("\n");
            //Leg 2 input
            printf("Please enter the length of the second leg:\n");
            printf("\n");
            scanf("%d", &leg2);
            //Error checking
            while(leg2 <1 || leg2 >100)
            {
                printf("\n");
                printf("Invalid input.\n");
                printf("Please enter a length from 1 to 100:\n");
                printf("\n");
                scanf("%d", &leg2);
            }
            //Hypotenuse calculation
            printf("\n");
            printf("[CALCULATION]\n\n");
            printf("%.0f + %.0f = c^2\n", (float) pow(leg1, 2), (float) pow(leg2, 2));
            printf("Hypotenuse length= %.2f\n", (float) sqrt(pow(leg1, 2) + pow(leg2, 2)));        
        }
        //Multiple calculations
        printf("Would you like to calculate again?\n");
        printf("Press 1 for no, 0 for yes:\n");
        printf("\n");
        scanf("%d", &choice);    
    }

    //Declaring bonus variables
    int base;
    int exponent;
    int i;
    int result = 1;
    int temp;

    printf("\n[BONUS PART]\n\n");
    printf("Enter a number:\n\n");
    scanf("%d", &base);
    printf("\n");

    printf("Enter the power:\n\n");
    scanf("%d", &exponent);
    printf("\n");

    for(i = 0;i < exponent; i++)
    {
        temp = base;
        result = result * temp;
    }
    printf("pow(%d, %d) = %d\n\n",base, exponent, result);

    return 0;
}
