//Homework 1 by Paul Orton
//Created on 9/20/18
//
//Task:
//-Input units consumed for previous month
//-Calculate and display the bill for connection
//  +Read a connection type from user
//  +Read units consumed from user
//  +Use rate from table
//  +Loop program until user specifies
//-Bonus
//  +Take a number, N, as an input
//  +Print

#include <stdio.h>
#include <math.h>

//Functions prototypes
void displayMenu(void);
int errorCheck(int options);
int errorCheckUnits(int units);
float getRate(int units, int option);
int getCharge(int option);
float calculateBill(int units, float rate, int charge);
void doubleSpace(void);
void bonus(void);

int main(void)
{
    //Variable declaration
    int option;
    int checker;
    int units;
    float rate;
    int connectionCharge;
    int choice = 1;
    int count = 0;
    float grandTotal = 0;

    for(count = 0; choice == 1; count++)
    {
    //Prints menu
    displayMenu();

    scanf("%d", &option);
    printf("\n");

    //Checks option for errors
    checker = errorCheck(option);
    
    while(checker == 0)
    {
        printf("Invalid input. Please make a valid selection.\n\n");

        displayMenu();

        scanf("%d", &option);
        printf("\n");
    
        checker = errorCheck(option);
    }
    
    //Units input
    printf("Please enter the units consumed in kWH: ");
    scanf("%d", &units);
    printf("\n");
    
    //Check units for errors
    checker = errorCheckUnits(units);

    while(checker == 0)
    {
        printf("Invalid input. Please enter an integer greater than zero: ");

        scanf("%d", &units);
        printf("\n");
    
        checker = errorCheckUnits(units);
    }
    
    //Rate lookup
    rate = getRate(option, units);

    //Charge lookup
    connectionCharge = getCharge(option);

    //Bill calculation
    grandTotal += calculateBill(units, rate, connectionCharge);

    printf("Would you like to calculate another bill?\n");
    printf("Enter 1 for yes, 0 for no: ");
    scanf("%d", &choice);
    printf("\n");

    }

    printf("You calculated the bill %d times and the total amount from all of the bills due is $%.2f\n", count, grandTotal);
    printf("\n");

    bonus();
    
    return 0;
}

//Menu function
void displayMenu(void)
{
    printf("\n\n\t[ELECTRICITY BILL CALCULATOR]\n\n");
    printf("[1] Residential\n");
    printf("[2] Commercial\n");
    printf("[3] Industrial\n");
    printf("\n");
    printf("Choose the type of connection: ");
}

//Option error checking function
int errorCheck(int option)
{
    if(option != 1 && option != 2 && option != 3)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//Units error checking function
int errorCheckUnits(int units)
{
    if(units <= 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

//Rate lookup function
float getRate(int option, int units)
{
    switch(option)
    {
        case 1:
            if(units <= 200)
            {
                return 7.5;
            }
            else if(units <= 700)
                {
                    return 10;
                }
                else if(units <= 1250)
                    {
                        return 13.5;
                    }
                    else
                    {
                        return 15;
                    }
            break;
        case 2:
            if(units <= 300)
            {
                return 10.5;
            }
            else if(units <= 1000)
                {
                    return 14;
                }
                else if(units <= 2000)
                    {
                        return 17.5;
                    }
                    else
                    {
                        return 20;
                    }
            break;
        case 3:
            if(units <= 500)
            {
                return 36.5;
            }
            else if(units <= 2000)
                {
                    return 40;
                }
                else if(units <= 3000)
                    {
                        return 45.5;
                    }
                    else
                    {
                        return 50;
                    }
            break;
        default: printf("Rate Error.\n");
    }

    return 0;
}

//Charge lookup function
int getCharge(int option)
{   
    switch(option)
    {
        case 1:
            return 25;
            break;
        case 2:
            return 90;
            break;
        case 3:
            return 850;
            break;
        default: printf("Charge Error.\n");
    }

    return 0;
}

//Bill calculation function
float calculateBill(int units, float rate, int connectionCharge)
{
    float energyCharge = units * rate;
    energyCharge = (round(energyCharge)) / 100;
    float total = energyCharge + connectionCharge;
    
    printf("\t[TOTAL BILL CALCULATION]");
    doubleSpace();
    printf("Energy Charge = $%.2f", energyCharge);
    doubleSpace();
    printf("Connection Charge = $%d.00", connectionCharge);
    doubleSpace();
    printf("Total Bill = $%.2f + $%d.00 = $%.2f\n", energyCharge, connectionCharge, total);
    printf("\n");

    return total;
}

//Double space function
void doubleSpace(void)
{
    printf("\n\n");
}

//Bonus function
void bonus(void)
{
    int n;
    int i;
    int sumAll = 0;
    int sumEven = 0;
    int sumOdd = 0;
    
    doubleSpace();
    printf("\t[BONUS]");
    doubleSpace();
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\nThe numbers are: ");
    for(i = 0; i <= n; i++)
    {
        printf("%d ", i);
        
        sumAll += i;

        if(i % 2 == 0)
        {
            sumEven += i;
        }
        else
        {
            sumOdd += i;
        }
    }
    doubleSpace();
    printf("The sum of all numbers from 0 to %d is %d.\n\n", n, sumAll);
    printf("The sum of all even numbers from 0 to %d is %d.\n\n", n, sumEven);
    printf("The sum of all odd numbers from 0 to %d is %d.\n\n", n, sumOdd);
}
