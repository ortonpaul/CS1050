//Prelab 4
//Created by Paul Orton
//9/25/18
//
//Task:
//-Calculate Average Score Point (ASP) of a student taking N courses
//-Ask for number of course (courses)
//  +Error check to be greater than 1
//-Ask student for course scores
//-Calculate ASP
//-Comment on ASP

#include <stdio.h>

//Function prototypes
int courseNumCheck(int courseNum);
float getScore();
int getUnit();
int scoreErrorCheck(float score);
int unitErrorCheck(int unit);
int getScorePoint(float score);
void printComment(float GPA);
int computeSCU(float scorePoint, int unit);


//Main function
int main()
{
    //Variable declaration
    int courseNum = 0;
    float score = 0;
    float scorePoint = 0;
    int unit = 0;
    float sumScorePointUnit = 0;
    int sumUnit = 0;
    float GPA = 0;
    int SCU = 0;

    //Printing main menu
    printf("\n\n");
    printf("===========================================\n");
    printf("STUDENT GPA CALCULATOR\n");
    printf("===========================================\n");    
    printf("\n\n");
    
    //Get courseNum from user
    printf("Please enter the number of courses: ");
    scanf("%d", &courseNum);
    printf("\n\n");

    //Error checking for course number
    courseNum = courseNumCheck(courseNum);

    //Calculates sumScorePoint & sumUnit
    for(int i = 1; i <= courseNum; i++)
    {
        int checker;

        //Gets course score from user
        printf("Enter your percent score for Course %d: ", i);
        scanf("%f", &score);
        printf("\n");
        
        //Error checks score from user
        checker = scoreErrorCheck(score);
        while(checker == 0)
        {
            printf("Invalid input. Please enter a valid course score: ");
            scanf("%f", &score);
            printf("\n");
            checker = scoreErrorCheck(score);
        }

        //Gets scorePoint from table
        scorePoint = getScorePoint(score);

        //Gets course units from user
        printf("Enter the number of units for course %d: ", i);
        unit = getUnit();
        printf("\n");

        //Error checks course units from user
        checker = unitErrorCheck(unit);
        while(checker == 0)
        {
            printf("Invalid input. Please enter a valid course unit: ");
            scanf("%d", &unit);
            printf("\n");
            checker = unitErrorCheck(unit);
        }

        //[BONUS] Computes SCU & displays it
        SCU = computeSCU(scorePoint, unit);
        printf("MULTIPLICATION OF SCP AND CU: %d\n", SCU);

        //Calculates the sum of SC*CU & CU
        sumScorePointUnit += (scorePoint * unit);
        sumUnit += unit;
        printf("\n\n");
    }
    
    //Calculates GPA & displays it
    GPA = sumScorePointUnit / sumUnit;
    printf("The Student GPA: %.2f\n", GPA);
    
    //Uses GPA calculated above and prints comment from table
    printComment(GPA);

    return 0;
}

//***Functions***

//Error checking for course number (courseNum must be > 1)
int courseNumCheck(int courseNum)
{
    while(courseNum <= 1)
    {
        printf("Invalid input. Please enter an intenger greater than 1: ");
        scanf("%d", &courseNum);
        printf("\n\n");
    }

    return courseNum;
}

//Gets score from user
float getScore()
{
    float score;
    
    scanf("%f", &score);

    return score;
}

//Gets course units from user
int getUnit()
{
    int unit;
    
    scanf("%d", &unit);

    return unit;
}


//Error checking for score
int scoreErrorCheck(float score)
{
        if(score > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}

//Error checking for unit
int unitErrorCheck(int unit)
{
        if(unit > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}


//Uses score to determine scorePoint
int getScorePoint(float score)
{
    int scorePoint;

    if(score >= 90)
    {
        scorePoint = 4;
    }
    else if(score >= 80)
    {
        scorePoint = 3;
    }
    else if(score >= 70)
    {
        scorePoint = 2;
    }
    else if(score >= 60)
    {
        scorePoint = 1;
    }
    else
    {
        scorePoint = 0;
    }
    
    return scorePoint;
}

//Uses GPA to determine which comment to print
void printComment(float GPA)
{
    printf("\n\n");
    printf("===========================================\n");
    printf("COMMENT: ");
    
    if(GPA >= 3.8)
    {
        printf("Outstanding !!\n");
    }
    else if(GPA >= 3.5)
        {
            printf("Excellent !!\n");

        }
        else if(GPA >= 3.0)
            {
                printf("Good !!\n");
            }
            else if(GPA >= 2.5)
                {
                    printf("Satisfactory !!\n");
                }
                else if(GPA >= 2.0)
                    {
                        printf("Not Satisfactory !!\n");
                    }
                    else
                    {
                        printf("Do Better Next Semester.\n");
                    }
    printf("===========================================\n");
    printf("\n\n");
}

//Bonus function
int computeSCU(float scorePoint, int unit)
{
    int SCU = scorePoint*unit;
    
    return SCU;
}
