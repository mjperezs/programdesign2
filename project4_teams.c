/* Maria Jose Perez

This program helps the user assigned students to each team based on there points. 
First, it prompts the user to enter the amount of students and their points to determine the array.
Then, it calculates to which team the student should be assigned based on which team's point is most closer to.
After, it prints to the user the team assigned to each student.

*/

#include <stdio.h>
#include <stdlib.h>

void assign(int *points, int *team_assignment, int n);

int main()
{
    //declare variable for number of students
    int n;

    //prompts the user to enter the number of students and stores it
    printf("Enter number of students: ");
    scanf("%d",&n);

    //prompts the user to enter the points of each student
    printf("Enter points for each student: ");
    
    //declares arrays and varibale used in it
    int i, points[n];
    int team_assignment[n];


    //initializes for loop to store each students' point
    for (i = 0; i < n; i++)
    {
        scanf("%d", &points[i]);

    }

    //calls assign function
    assign(points, team_assignment, n);

    //prints each team with the students assigned to it

    printf("Beginner team: student ");
    //creates loop to print each student on the team
    for (int i = 0; i < n; i++) 
    {
        //searches for the students matched to the team
        if (team_assignment[i] == 0) 
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");


    printf("Honor team: student ");
    //creates loop to print each student on the team
    for (int i = 0; i < n; i++) 
    {
        //searches for the students matched to the team
        if (team_assignment[i] == 1) 
        {
            printf(" %d ", i + 1);
        }
    }
    printf("\n");

    printf("Excellence team: student ");
    //creates loop to print each student on the team
    for (int i = 0; i < n; i++) 
    {
        //searches for the students matched to the team
        if (team_assignment[i] == 2) 
        {
            printf(" %d ", i + 1);
        }
    }

    printf("\n");
    return 0;

}

//calculates to which teams' point the student point is closer to
void assign(int *points, int *team_assignment, int n) 
{
    //declares pointers
    int *p = points;
    int *q = team_assignment;

    //initialiazes for loop to examine each point in the array
    for (int i = 0; i < n; i++, p++, q++) 
    {
        //declare variables
        int beginner, honor, excellence;

        //calculates absolute value for the difference of points
        beginner = abs(*p - 25);
        honor = abs(*p - 70);
        excellence = abs(*p - 125); 
        
        //assign the team for the student

        //beginner team
        if (beginner <= honor && beginner <= excellence) 
        {
            *q = 0;
        }
        //honor team
        else if (honor <= beginner && honor <= excellence) 
        {
            *q = 1;
        } 
        //excellence team
        else 
        {
            *q = 2;    
        }
    }
}
