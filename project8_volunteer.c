/* Maria Jose Perez

  This program asks for an operation code. Then, acorrdingly computes the task. 
  The program uses dynamically allocated linked list to maintain the list. 
  If the operation code is to add a new volunteer, it prompts the user to enter the data 
  and makes sure the volunteer doesn't exists already, if not, it adds the data to a new volunteer
  in the list. When the task is to search a volunteer, the code compares the grade level to find the 
  match and prints all the matched volunteers. If user the input is to print, then the code prints all 
  the volunteers in the list. When the user asks to quit, all the memory of the list is cleared.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMAIL_LEN 100
#define NAME_LEN 30

//declare a structure for volunteer data
struct volunteer
{
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int grade_level;
	struct volunteer *next;
};

//declares functions
struct volunteer *add_to_list(struct volunteer *list);
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct volunteer *volunteer_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': volunteer_list = add_to_list(volunteer_list);
                break;
      case 's': search_list(volunteer_list);
                break;
      case 'p': print_list(volunteer_list);
                break;
      case 'q': clear_list(volunteer_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

//function that adds a new volunteer to list
struct volunteer *add_to_list(struct volunteer *list)
{
  //creates memory for new volunteer
  struct volunteer *new_volunteer = malloc(sizeof(struct volunteer));

  //prompts the user for volunteer's last name
  printf("Enter last name: ");
  read_line(new_volunteer->last, NAME_LEN);

  //prompts the user for volunteer's first name 
  printf("Enter first name: ");
  read_line(new_volunteer->first, NAME_LEN);

  //prompts the user for volunteer's email 
  printf("Enter email address: ");
  read_line(new_volunteer->email, EMAIL_LEN);

  //prompts the user for volunteer's grade level
  printf("Enter grade level: ");
  scanf("%d", &new_volunteer->grade_level);
  
   
  //verifies if the volunteer already exists

  struct volunteer *curr = list;

  while (curr != NULL) 
  {
    if ((strcmp(curr->email, new_volunteer->email) == 0) && (strcmp(curr->last, new_volunteer->last) == 0)) 
    {
      printf("volunteer already exists.\n");
      free(new_volunteer);
      
      return list; 
    }

    curr = curr->next;
  
  }

  //add the new volunteer to the end of the list
  new_volunteer->next = NULL;

  if (list == NULL) 
  {
    return new_volunteer;
  }
  else
  {
    struct volunteer *curr = list;

    while (curr->next != NULL) 
    {
      curr = curr->next; 
    }
    curr->next = new_volunteer;
    return list;
  }
 
}

//function to search for volunteers by grade level
void search_list(struct volunteer *list)
{

  //declare variable
  int grade;

  //prompts the user to enter grade level to be searched
  printf("Enter grade level: ");
  //stores the grade level
  scanf("%d", &grade);


  //declares flag if volunteers matched
  int found = 0;

  //looks for the matched volunteers and prints them
  struct volunteer *curr = list;
  
  while (curr != NULL) 
  {
    if (curr->grade_level == grade) 
    {
      printf("%-12s%-12s%-30s\n", curr->last, curr->first, curr->email, curr->grade_level);
      found = 1;
    }
      curr = curr->next;
    }
    if (!found) 
    {
      printf("not found\n");
    }
}

//prints the volunteer list
void print_list(struct volunteer *list)
{
  struct volunteer *curr = list;
  
  //traverses the list and prints volunteers's data
  while (curr != NULL) 
  {
    printf("%-12s%-12s%-30s%5d\n", curr->last, curr->first, curr->email, curr->grade_level);
    curr = curr->next;
  }


}

//clears the list memory
void clear_list(struct volunteer *list)
{
  struct volunteer *curr = list;
  
  //traverses the list and frees memory of each volunteer
  while (curr != NULL) 
  {
    struct volunteer *temp = curr;
    curr = curr->next;
    free(temp);
  }

}

//reads the input line
int read_line(char str[], int n)
{
  int ch, i = 0;


  //skips white spaces
  while (isspace(ch = getchar()))
    ;

  //reads the characters until new line or max length 
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
