/* Maria Jose Perez

    This program prompts the user to enter a supply and searchs in the input file the matched supplies. 
    Then, it writes the results of the supplies matched into a new output file.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 200
#define MAX_LENGTH 100

// Structure to store supply data
struct supply 
{
    char name[MAX_LENGTH];
    char color[MAX_LENGTH];
    int quantity;
};

// Function to read line properly
int read_line(char *str, int n) 
{
    int ch, i = 0;
    // Reads characters until newline or EOF
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

// Comparison function for qsort
int compare_supplies(const void *a, const void *b)
{
    const struct supply *supply_a = (const struct supply *)a;
    const struct supply *supply_b = (const struct supply *)b;
    int cmp = strcmp(supply_a->name, supply_b->name);
    if (cmp == 0)
    {
        // If names are the same, compare by color
        return strcmp(supply_a->color, supply_b->color);
    }
    return cmp;
}

int main() 
{
    FILE *input_file = fopen("supply.csv", "r");
    FILE *output_file = fopen("result.csv", "w");

    if (input_file == NULL || output_file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    struct supply supplies[MAX_ITEMS];
    int num_supplies = 0;

    while (fscanf(input_file, "%[^,], %[^,], %d\n", supplies[num_supplies].name, supplies[num_supplies].color, &supplies[num_supplies].quantity) == 3)
    {
        num_supplies++;
    }

    // Sort the supplies array using quicksort
    qsort(supplies, num_supplies, sizeof(struct supply), compare_supplies);

    for (int i = 0; i < num_supplies; ++i) 
    {
        fprintf(output_file, "%s, %s, %d\n", supplies[i].name, supplies[i].color, supplies[i].quantity);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
