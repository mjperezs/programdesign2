/* Maria Jose Perez Smith

    This functions decrypts a message that is encrypted to repeat the characters n amount of times in terms of its nth possition.
    The decrypt function use pointers to access the string arrays.
    
*/

#include <stdio.h>


//decrypt function
void decrypt(char *input, char *output) 
{
    //defines pointers
    char *in = input;
    char *out = output;
    
    //declares variable to control the n times the nth character is repeated 
    int n = 0;

    //creates while loop to manipulate the input string
    while (*in) 
    {
        //current character 
        char current = *in;

        //stores character once into output
        *out++ = current;

        
        //moves the pointer to next character to decrypt
        n++;
        in += n; 
    }


    //adds null character to the end of the array
    *out = '\0';
}


int main() 
{
    //declares the array's legth
    char input[1001], output[1001];

    //stores input by user
    printf("Enter message: ");
    scanf("%s", input);

    //calls fuction
    decrypt(input, output);

    //prints decrypted message
    printf("Output: %s\n", output);

    return 0;
}

