#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Global constants
#define ROW 12										// Number of Rows of seats
#define COL 6										// Number of Columns of seats
#define MAX 25										// Maximum space to reserve for merged strings (includes NULL terminator)

//A global 2-D array which holds the cost. Not a good practice to use global variables AT ALL, but I just want to test you on scope of variables.
//You will not be using Global variables much going forward.
int costMatrix[ROW][COL]= //This is the cost of each seat in all the 3 flights. There are 72 seats in each flight.
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

// Displays the Menu options
void displayMenu();	

/*This does the log-in authentication, called  to compares the password with
adminPassword */
int loginMatch(int passcode,int adminPasscode);

/*This does the initialization for each flight, called as soon as your program starts. Allocates 1-20 (specified by count)seats in the flight.
fill those seats randomly in all 3 flights Before hand.
print 'O' for unreserved seats and 'X' for reserved seats*/
void initialSeats(char flight[][COL],int count);

//Prints the current flight Map every time it is called. Send the flight as the parameter.
void printFlightMap(char flight[][COL]);

//Prints the flight options
void flightMenu();

//This calculates the Total Revenue, sum of the cost of all reserved seats from each flight. Called in admin mode only.
int getTotalRevenue(char flight1[][COL], char flight2[][COL], char flight3[][COL]);

/*Reserves seat in a flight, have to ask for which row (0-5) and which column(0-3) from the user. Perform error check inside this for row and column entered. 
mark that seat as 'X', if the seat is already taken then you need to loop back and ask again. If reservation is possible, print a success message,assign the seat
and print the flight map here*/
void seatReservation(char flight[][COL]);

/*Just before calling this function in main() : flight numbers are "MIA1050","BNA1050",LSA1050". Store this in num1[],num2,num3[] respectively 
Ask for the first name when a flight option is chosen. Store this in name[]. This function takes those two strings, name and flight number, as parameters. 
Merges them and stores them in 3rd string as shown in the output and prints the message of confirmation. BONUS ONLY
*/
void printMessage(char name[],char num[]);

// This function provided below
void getSafeString(char *string, int maxsize);


//main function... good luck!
int main (void)
{
    srand(time(NULL));
}

void initialSeats(char flight[][COL],int count)
{
    int row = rand() % ROW;
    int col = rand() % COL;
}

//Function Declaration

/*
 * Function: getSafeString
 * Parameters:
 * 	string - the target where the input string will be stored
 *	maxsize - the largest string that can be input, including the null-terminator
 * Discussion:
 * 	This function inputs a string from stdin that can contain any character, except newline.  The function will return when a newline is entered.  
 *	Newline is not included in the string.  The string will be null-terminated.  Characters beyond the max will be thrown away.
*/

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
