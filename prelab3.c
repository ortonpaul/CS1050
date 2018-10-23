//Prelab 3 by Paul Orton
//Created on 9/13/18
//
//Task:
//  Calculate area based on user choice of the following shapes:
//  -Square
//  -Cube
//  -Circle
//  Display error messages if something different is selected
//  Read a non-negative number from the user and calculate the area

#include <stdio.h>
#include <math.h>

int main(void)
{
    //Declaring variables
    int choice;
    int length;

    //Choice section
    printf("\n\n[AREA CALCULATION]\n\n");
    printf("Please make a selection:\n\n");
    printf("(1) Square\n");
    printf("(2) Cube\n");
    printf("(3) Circle\n");
    printf("\n");
    scanf("%d", &choice);
    printf("\n");

    //Check to see if input is one of the options
    while(choice != 1 && choice != 2 && choice != 3)
    {
        printf("That is not a valid input.\n");
        printf("Please select another value:\n\n");
        printf("(1) Square\n");
        printf("(2) Cube\n");
        printf("(3) Circle\n");
        printf("\n");
        scanf("%d", &choice);
        printf("\n");
    }
    
    //Checking to see if input is greater than zero

    //Square area calculation
        if(choice == 1)
        {
            printf("Please enter the side length for the square:\n\n");
            scanf("%d", &length);
            printf("\n");
            while(length <= 0)
            {
                printf("That is not a valid input.\n");
                printf("Please enter an integer greater than zero.\n\n");
                scanf("%d", &length);
                printf("\n");
            }
            printf("The area of a square with side %d is %.0f.\n\n", length, pow(length, 2));
        }
        
        else
        {
        //Cube area calculation
            if(choice == 2)
            {
                printf("Please enter the side length for the cube:\n\n");
                scanf("%d", &length);
                printf("\n");
                while(length <= 0)
                {
                    printf("That is not a valid input.\n");
                    printf("Please enter an integer greater than zero.\n\n");
                    scanf("%d", &length);
                    printf("\n");
                }
                printf("The surface area of a cube with side %d is %.0f.\n\n", length, 6*pow(length, 2));
            }
            else
            {
            //Circle area calculation
                if(choice == 3)
                {
                    printf("Please enter the radius for the circle:\n\n");
                    scanf("%d", &length);
                    printf("\n");
                    while(length <= 0)
                    {
                        printf("That is not a valid input.\n");
                        printf("Please enter an integer greater than zero.\n\n");
                        scanf("%d", &length);
                        printf("\n");
                    }
                    printf("The area of a circle with radius %d to two decimal places is %.2f.\n\n", length, (float)3.14159*pow(length, 2));
                }
            }
        }

    return 0;
}
