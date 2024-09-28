/* Maria Jose Perez Smith

This program prompts the user to enter an amount of coins, then gives 3 choices of candy after entering 0. 
After, it evaluates the total coins and gives change, or returns cents if the amount of coins is insufficent or the choice is envalid.

*/

#include <stdio.h>

//defines constants 
#define hershey 15
#define reese 25
#define snickers 50


int main()
{
    //defines variables
    int coins;
    int choice;
    int total_coins = 0;
    
    //prompts the user to enter coins
    printf("Insert coins: ");
    scanf("%d", &coins);
    
    //starts while loop until 0 coins are entered
    while (coins != 0)
    {
        total_coins += coins;
        printf("Insert coins: ");
        scanf("%d", &coins);
        
    }
    
    //prints candy options
    printf("1 - Hershey's kisses (15 cents), 2 - Reese's Peanut Butter Cups  (25 cents), 3 - Snickers (50 cents)\nEnter your choice:" );
    scanf("%d", &choice);
    
    //evaluates what candy is chosen
    if (choice == 1)
    {
        //calculates if the amount of coins given is sufficent
        if (total_coins >= hershey)
        {
            //calculates the expected change of cents
            int change = total_coins % hershey;
            printf("Your change is %d cents", change);
        }
        else
        {
            printf("Insufficent amount, %d cents returned\n", total_coins);
        }
    }
    else if (choice == 2)
    {
        if (total_coins >= reese)
        {
            int change = total_coins % reese;
            printf("Your change is %d cents", change);
        }
        else
        {
            printf("Insufficent amount, %d cents returned\n", total_coins);
        }
    }
    else if (choice == 3)
    {
        if (total_coins >= snickers)
        {
            int change = total_coins % snickers;
            printf("Your change is %d cents", change);
        }
        else
        {
            printf("Insufficent amount, %d cents returned\n", total_coins);
        }
    }
    else
    {
        printf("Invalid selection, %d cents returned\n", total_coins);
    }
    
    
    return 0;
    
    
    
    
}