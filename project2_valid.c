/* Maria Jose Perez Smith

This program checks if the input entered by the user is all alphabetic characters in lower case. 
Besides, it allows digits, white spaces, exaclamation point, question marks, or periods.
After, it prints if the input is valid or invalid.
   
*/


#include <stdio.h>
#include <ctype.h>

int main() 
{
    //declare variables
    char ch;
    //keeps track if its invalid or valid
    int valid = 1; 

    //prompts the user
    printf("Enter input: ");

    //loop until end of line
    while ((ch = getchar()) != '\n') 
    {
        //checks that input is alphabetic character
        if (isalpha(ch)) 
        {
            //checks that input is not lower case
            if (!islower(ch)) 
            {
                //marks it as invalid
                valid = 0;
                break;
            }
        } 
        //checks that non-alphabetics input are not digit, white space, exlamation point, question mark and period.
        else if (!isdigit(ch) && !isspace(ch) && ch != '!' && ch != '?' && ch != '.') 
        {
            //marks input as invalid
            valid = 0;
            break;
        }
    }

    //prints if input is invalid or valid
    if (valid) 
    {
        printf("valid\n");
    } else 
    {
        printf("invalid\n");
    }

    return 0;
}
