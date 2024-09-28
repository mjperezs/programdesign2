/* Maria Jose Perez

This program prompts the user to enter the amount of episodes a series have, 
then asks to enter the episodes watched to return the number of the episode 
that the user is missing to watch.


*/

#include <stdio.h>
int main()
{
    //declaring variables
    int num_episodes;
    int w_episodes;
    
    printf("Enter number of episodes: ");
    //stores the number of episodes of the TV series
    scanf("%d", &num_episodes);

    printf("Enter episodes watched: ");

    //creating array 
    int episodes[num_episodes];

    int i, j;


    //initializes for loop to store the number of the episodes watched
    for(i = 0; i < num_episodes - 1; i++)
    {
        scanf("%d", &w_episodes);
        episodes[i] = w_episodes;

    }

    //initialize for loop to check which episode is missing
    for (i = 1 ; i <= num_episodes; i++)
    {
        int missing_ep = 0;

        for (j = 0; j < num_episodes - 1; j++)
        {
            //determines which episode is missing
            if(episodes[j] == i)
            {
                missing_ep = 1;
                break;

            }
            
        }
        //prints missing episode
        if (!missing_ep)
        {
            printf("Missing episode: %d\n", i );
            break;
        }
    }

    return 0; 

}
