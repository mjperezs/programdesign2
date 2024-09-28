/* Maria Jose Perez Smith

This program checks if the input entered by the user is all alphabetic characters in lower case. 
Besides, it allows digits, white spaces, exclamation points, question marks, or periods.
After, it prints if the input is valid or invalid.
   
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    //checks that the command line argument is greather than 2 
    if (argc <= 2) 
    {
        printf("invalid number of arguments\n");
        return 0;
    }

    // declare variables
    char ch;
    // keeps track if it's invalid or valid
    int valid = 1; 

    // loop through command line arguments
    for (int i = 1; i < argc; i++) 
    {
        // loop through characters in each argument
        for (int j = 0; argv[i][j] != '\0'; j++) 
        {
            ch = argv[i][j];
            // checks that input is alphabetic character
            if (isalpha(ch)) 
            {
                // checks that input is not lowercase
                if (!islower(ch)) 
                {
                    // marks it as invalid
                    valid = 0;
                    break;
                }
            } 
            // checks that non-alphabetic inputs are not digits, white space, exclamation point, question mark, or period.
            else if (!isdigit(ch) && !isspace(ch) && ch != '!' && ch != '?' && ch != '.') 
            {
                // marks input as invalid
                valid = 0;
                break;
            }
        }
    }

    // prints if input is invalid or valid
    if (valid) 
    {
        printf("valid\n");
    } 
    else 
    {
        printf("invalid\n");
    }

    return 0;
}
