//Homework 2 by Paul Orton
//Mizzou Airline Reservation System
//Created 10/16/18
//Submitted 10/22/18
//Modification of template provided by Professor Ries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Global constants & variables
#define ROW 12
#define COL 6
#define MAX 25

int costMatrix[ROW][COL] = 
{
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500},
	{500,200,500,500,200,500}
};

//Function Prototyping
void displayMenu();	
int loginMatch(int passcode,int adminPasscode);
void initialSeats(char flight[][COL],int count);
void printFlightMap(char flight[][COL]);
void flightMenu();
int getTotalRevenue(char flight_1[][COL], char flight_2[][COL], char flight_3[][COL]);
void seatReservation(char flight[][COL]);
void printMessage(char name[], char flight_number[]);
void getSafeString(char *string, int maxsize);

//Main Function
int main (void)
{    
    //Seeding rand
    srand(time(NULL));

    //Variable Delcaration
    int choice = 0;
    int checker = 0;
    int passcode = 0;
    int adminPasscode = 105018;
    int seats = ((rand() % 20) + 1);
    char flight_number[MAX] = {};
    char flight_1[ROW][COL] =
    {
	    {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'}
    }; 
    char flight_2[ROW][COL] =
    {
	    {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'}
    };
    char flight_3[ROW][COL] =
    {
	    {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'},
        {'O','O','O','O','O','O'}
    }; 

    //Initializing filled seats
    initialSeats(flight_1, seats);
    initialSeats(flight_2, seats);
    initialSeats(flight_3, seats);
    
    //Print welcome message
    printf("\n\n\t\t[WELCOME TO MIZZOU AIRLINE BOOKING SYSTEM]\n\n");

    //Begin reservation system
    do
    {
        //Reset name array & flight choice
        char name[MAX] = {};
        int flight = 0; 

        //Print menu
        displayMenu();
        
        //Ask for choice
        scanf("%d", &choice);
        while(choice != 1 && choice != 2 && choice != 3)
        {
            printf("\nWrong option! Choose a right option.\n\n");
            displayMenu();
            scanf("%d", &choice);
        }

        printf("\n");
    
        //Admin portal
        if(choice == 1)
        {
            //Asks for passcode
            printf("Enter the login passcode to log in as admin: ");
            scanf("%d", &passcode);

            printf("\n");
            
            //Checking for a match
            checker = loginMatch(passcode, adminPasscode);

            while(checker == 0)
            {
                printf("Invalid passcode combination.\n\n");
                printf("Enter the login passccode to log in as admin: ");
                scanf("%d", &passcode);
                printf("\n");

                checker = loginMatch(passcode, adminPasscode);
            }

        //Prints the flight maps
        printf("Printing the Flight Map of flight Columbia to Miami....\n");
        printFlightMap(flight_1);
        printf("Printing the Flight Map of flight Columbia to Nashville....\n");
        printFlightMap(flight_2);
        printf("Printing the Flight Map of flight Columbia to Las Vegas....\n");
        printFlightMap(flight_3);

        //Calculates the total earnings
        printf("The total earnings from all the flights: $%d\n", getTotalRevenue(flight_1, flight_2, flight_3));
        printf("You are logged out now!\n\n");

        }

        //Seat Reservation
        if(choice == 2)
        {
            //Prints flight options & asks for flight
            while(flight != 1 && flight != 2 && flight != 3)
            {
                flightMenu();
                scanf("%d", &flight);
                printf("\n");
            }
            
            //Asks for name
            printf("Enter your first name: ");
            getSafeString(name, MAX);
            printf("\n\n");

            //Reserves seat
            switch(flight)
            {
                case 1:
                    seatReservation(flight_1);
                    strcpy(flight_number, "MIA1050");
                    break;

                case 2:
                    seatReservation(flight_2);
                    strcpy(flight_number, "BNA1050");
                    break;

                case 3:
                    seatReservation(flight_3);
                    strcpy(flight_number, "LAS1050");
                    break;
            }
            
            //Prints confirmation message
            printf("Congrats %s!! Your flight %s is booked! Enjoy your trip!\n", name, flight_number);
            printMessage(name, flight_number);
            printf("\n\nEnjoy your Thanksgiving Break :)\n\n");

        }
    
        printf("\n");

    }
    while(choice != 3);

    //Exits the program
    printf("Terminating the Program.\n");
    printf("Thank you for using Mizzou Airline Booking System!\n\n");

    return 0;
}

//Function Declaration

//Initializes random seats to 'X' 
void initialSeats(char flight[][COL],int count)
{
    for(int i = 0; i < count; i++)
    {
        int row = rand() % ROW;
        int col = rand() % COL;
        if(flight[row][col] == 'X')
        {
            i--;
        }
        else
        {
            flight[row][col] = 'X';
        }
    }
}

//Prints menu
void displayMenu()
{
    printf("1.) Admin Portal\n");
    printf("2.) Reserve a Seat on a Flight\n");
    printf("3.) Quit\n");
    printf("Choose an option: ");
}

//Prints flight map
void printFlightMap(char flight[][COL])
{
    for(int row = 0; row < ROW; row++)
    {
        for(int col = 0; col < COL; col++)
        {
            printf("%c", flight[row][col]);
        }

        printf("\n");
    }

    printf("\n");
}

//Verifies login information
int loginMatch(int passcode, int adminPasscode)
{
    if(passcode == adminPasscode)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//Calculates total reveune
int getTotalRevenue(char flight_1[][COL], char flight_2[][COL], char flight_3[][COL])
{
    int revenue = 0;

    for(int row = 0; row < ROW; row++)
    {
        for(int col = 0; col < COL; col++)
        {
            if(flight_1[row][col] == 'X')
            {
                revenue += costMatrix[row][col];
            }

            if(flight_2[row][col] == 'X')
            {
                revenue += costMatrix[row][col];
            }

            if(flight_3[row][col] == 'X')
            {
                revenue += costMatrix[row][col];
            }
        }
    }

    return revenue;
}

//Displays flight options
void flightMenu()
{
        printf("1.) COU ----> MIA\n");
        printf("2.) COU ----> BNA\n");
        printf("3.) COU ----> LAS\n");
        printf("Choose a flight: ");    
}

//Handles seat reservations
void seatReservation(char flight[][COL])
{
    int row = 0;
    int col = 0;

    printFlightMap(flight);
    printf("In which row do you want to sit?\n\n");
    scanf("%d", &row);
    printf("\n");
    while(row < 0 || row > 11)
    {
        printf("Seat rows are between 0-11\n\n");
        printf("Try again. In which row do you want to sit?\n\n");
        scanf("%d", &row);
        printf("\n");
    }

    printf("In which column do you want to sit?\n\n");
    scanf("%d", &col);
    printf("\n");
    while(col < 0 || col > 5)
    {
        printf("Seat columns are between 0-5\n\n");
        printf("Try again. In which column do you want to sit?\n\n");
        scanf("%d", &col);
        printf("\n");
    }
    
    while(flight[row][col] == 'X')
    {
        printf("Sorry! Someone has reserved that seat. Please try again.\n\n");

        printFlightMap(flight);
        printf("In which row do you want to sit?\n\n");
        scanf("%d", &row);
        printf("\n");
        while(row < 0 || row > 11)
        {
            printf("Seat rows are between 0-11\n\n");
            printf("Try again. In which row do you want to sit?\n\n");
            scanf("%d", &row);
            printf("\n");
        }

        printf("In which column do you want to sit?\n\n");
        scanf("%d", &col);
        printf("\n");
        while(col < 0 || col > 5)
        {
            printf("Seat columns are between 0-5\n\n");
            printf("Try again. In which column do you want to sit?\n\n");
            scanf("%d", &col);
            printf("\n");
        }
    }

    flight[row][col] = 'X';
    printf("Your requested seat has been reserved!\n\n");
    printFlightMap(flight);
}

//Merges name and flight number
void printMessage(char name[], char flight_number[])
{
    printf("Your e-ticket number is: ");

    int twice = sizeof(name)/sizeof(char);

    for(int i = 0; i < (MAX - twice); i++)
    {
        printf("%c", name[i]);
        printf("%c", flight_number[i]);
    }
}

//NOT MINE - Gets 25 characters and gets rid of anything more
void getSafeString(char *string, int maxsize)
{
	int indexcur=0;
	char charcur = '\n';
	
	// Spin until we get something other than newline
	while ('\n'==charcur)
	{
		charcur = getc(stdin);
	}
	while (indexcur<(maxsize-1) && '\n'!=charcur)
	{
		if ('\n'!=charcur)
		{
			string[indexcur] = charcur;
		}
		indexcur++;
		charcur = getc(stdin);
	}
	string[indexcur] = '\0';
	// Spin until they hit enter
	while ('\n'!=charcur)
	{
		charcur = getc(stdin);
	}
}
