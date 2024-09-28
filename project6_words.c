/* Maria Jose Perez

    The program prompts the user to enter a file name, opens the file, reads it, calls a 
    function to detect strings written twice in a row. then, writes the strings written 
    twice in a row on a new file.
 
*/


#include <stdio.h>
#include <string.h>

int is_square(char *word);

int main() 
{
    //declare variables with their respective sizes
    char filename[1001];
    char word[101];

    //prompt the user to enter file name
    printf("Enter the file name: ");
    //store the input file name
    scanf("%s", filename);

    //declares pointers for the files and opens it
    FILE *fp = fopen(filename, "r");
    FILE *output = fopen("output.txt", "w");

    //loop to read words in the file
    while (fscanf(fp, "%s", word) != EOF) 
    {
        //calls function to print strings written twice in a row
        if (is_square(word)) 
        {
            fprintf(output, "%s\n", word);
        }
    }

    //closes the files
    fclose(fp);
    fclose(output);

    return 0;
}

int is_square(char *word) 
{
    //assigns the length of the word to a variable
    int length = strlen(word);

    //assigns the half of the length of a word to a variable
    int half_len = length / 2;

    //looks for strings written twice in a row on input file
    if (length % 2 != 0) 
    {
        return 0;
    }

    //creates a for loop to examine the strings
    for (int i = 0; i < half_len; i++) 
    {
        //detects if string is written twice in a row
        if (word[i] != word[i + half_len]) 
        {
            return 0;
        }
    }

    return 1;
}
