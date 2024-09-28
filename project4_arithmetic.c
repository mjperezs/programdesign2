/* Maria Jose Perez

    This program determines if a sequence of numbers is an arithmetic one or not. 
    First, it prompts the user to enter the length of the sequence. Then, enters 
    the sequence of numbers to be analyzed. After, if calls the is_arithmetic_sequence
    function to compare the sequence differences between consecutives numbers. Lastly, 
    it returns 1 when the sequence is arithmetic and 0 when it's not.

*/

#include <stdio.h>

int is_arithmetic_sequence(int *sequence,  int n);


int main()
{
    //declares variable for array length
    int length;

    //prompts the use to enter length
    printf("Enter length of the sequence: ");
    scanf("%d", &length);

    //declares array for sequence of numbers
    int seq[length];

    //prompts the user to enter array numbers
    printf("Enter numbers of the sequence: ");

    // creates for loop to store input array numbers
    int i;
    for (i=0; i<length; i++)
    {
        scanf("%d", &seq[i]);
    }

    //creates a flag to determine if arithmetic or not and calls function to determine
    int decision = is_arithmetic_sequence(seq, length);

    //prints if the sequence of numbers is arithmetic or not
    if(!decision)
    {
        printf("no");

    }
    else
    {
        printf("yes");
    }

}

//function that returns if the sequence of numbers is arithmetic or not
int is_arithmetic_sequence(int *sequence, int n)
{
    //declare variables
    int j;
    int difference; 

    //calculates difference for the first two elements of the array
    difference = *(sequence +1) - *sequence;

    //creates if statement to calculate if the array elements are less than or equal 2
    if ( n<= 2)
    {
        return 1;
    }

    //initializes for loop that calculates if the difference between numbers is not constant
    for (j = 2; j< n; j++)
    {
        //if statement to determine if the sequence of numbers is not arithmetic
        if(*(sequence + j ) - *(sequence + j - 1) != difference) 
        {

            return 0;
        }
    
    }

    
    return 1; 


}
