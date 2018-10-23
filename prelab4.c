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
int getCourseNum();
int courseNumCheck(int courseNum);
float getScore();
float scoreCheck(float score);
float getScorePoint(float score);
void printComment(float averageScorePoint);
void dS();


//Main function
int main()
{
    int courseNum;
    float score = 0;
    float scorePoint = 0;
    float sum = 0;
    float averageScorePoint = 0;

    dS();
    printf("===========================================\n");
    printf("AVERAGE SCORE POINT CALCULATOR\n");
    printf("===========================================\n");
    dS();
        
    courseNum = getCourseNum();

    //Error checking for course number
    courseNumCheck(courseNum);

    for(int i = 1; i <= courseNum; i++)
    {
        printf("Enter your score for Course %d: ", i);
        scanf("%f", &score);
        score = scoreCheck(score);
        scorePoint = getScorePoint(score);
        printf("scorePoint = %.2f\n", scorePoint);
        dS();
        sum += scorePoint;
    }
    
    averageScorePoint = sum / courseNum;
    printf("The Student ASP: %.2f\n", averageScorePoint);

    printComment(averageScorePoint);

    return 0;
}

//***Functions***

//Gets course number from user
int getCourseNum()
{
    int courseNum;

    printf("Please enter the number of courses: ");
    scanf("%d", &courseNum);
    dS();

    //Error checking for course number
    courseNum = courseNumCheck(courseNum);

    return courseNum;
}


//Error checking for course number
int courseNumCheck(int courseNum)
{
    while(courseNum <= 1)
    {
        printf("Invalid input. Please enter an intenger greater than 1: ");
        scanf("%d", &courseNum);
        dS();
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

//Error checking for score
float scoreCheck(float score)
{
        while(score < 0 || score > 100)
        {
            printf("Invalid input. Please enter a number from 0 to 100: ");
            scanf("%f", &score);
            printf("\n");
        } 
        return score;
}

//Uses score
float getScorePoint(float score)
{
    float scorePoint;

    if(score >= 95)
    {
        scorePoint = 4;
    }
    else if(score >= 90)
    {
        scorePoint = 3.5;
    }
    else if(score >= 85)
    {
        scorePoint = 3;
    }
    else if(score >= 80)
    {
        scorePoint = 2.5;
    }
    else if(score >= 75)
    {
        scorePoint = 2;
    }
    else if(score >= 70)
    {
        scorePoint = 1;
    }
    else
    {
        scorePoint = 0;
    }
    
    return scorePoint;
}

//Prints comment
void printComment(float averageScorePoint)
{
    dS();
    printf("===========================================\n");
    printf("COMMENT: ");
    
    if(averageScorePoint >= 3.8)
    {
        printf("Excellent\n");
    }
    else if(averageScorePoint >= 3.5)
        {
            printf("Very Good\n");

        }
        else if(averageScorePoint >= 3.0)
            {
                printf("Good\n");
            }
            else if(averageScorePoint >= 2.5)
                {
                    printf("Satisfactory\n");
                }
                else if(averageScorePoint >= 2.0)
                    {
                        printf("Not Passed\n");
                    }
                    else
                    {
                        printf("Unofficial Drop\n");
                    }
    printf("===========================================\n");
    dS();
}

//Prints double space
void dS()
{
    printf("\n\n");
}
