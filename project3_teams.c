/* Maria Jose Perez

This program helps the user assingned students to each team based on there points. 
First, it prompts the user to enter the amount of students and their points to determine the array.
Then, it calculates to which team the student should be assigned based on which team's point is most closer to.
After. it prints to the user the team assigned to each student.

*/

#include <stdio.h>
#include <stdlib.h>

void assign(int points[], int team_assignment[],  int n);

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

    //prints beginner team with the students assigned to it
    printf("Beginner team: student ");
    for (int i = 0; i < n; i++) 
    {
        //prints assigned students
        if (team_assignment[i] == 0) 
        {
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    //prints honor team with the students assigned to it
    printf("Honor team: student ");
    for (int i = 0; i < n; i++) 
    {
        //prints assigned student
        if (team_assignment[i] == 1) 
        {
            printf(" %d ", i + 1);
        }
    }
    printf("\n");

    //prints excellence team with the students assigned to it
    printf("Excellence team: student ");
    for (int i = 0; i < n; i++) 
    {
        //prints assigned student
        if (team_assignment[i] == 2) 
        {
            printf(" %d ", i + 1);
        }
    }

    printf("\n");
    return 0;

}

//calculates to which teams' point the student point is closer to
void assign(int points[], int team_assignment[], int n) 
{
    //initialiazes for loop to examine each point in the array
    for (int i = 0; i < n; i++) 
    {
        int beginner, honor,excellence;
        beginner = abs(points[i] - 25);
        honor = abs(points[i] - 70);
        excellence = abs(points[i] - 125); 
        
        //assigns the team for the student

        //beginner team
        if ( beginner <= honor && beginner <= excellence) 
        {
            team_assignment[i] = 0;
        }
        //honor team
        else if(honor <= beginner && honor <= excellence) 
        {
            team_assignment[i] = 1;
        } 
        //excellence team
        else 
        {
            team_assignment[i] = 2;    
        }
    }
}