/* Maria Jose Perez

  This program asks for an operation code. Then, acorrdingly computes the task. 
  The program uses dynamically allocated linked list to maintain the list. 
  If the operation code is to add a new volunteer, it prompts the user to enter the data 
  and makes sure the volunteer doesn't exists already, if not, it adds the data to a new volunteer
  in the list. When the task is to search a volunteer, the code compares the grade level to find the 
  match and prints all the matched volunteers. If user the input is to print, then the code prints all 
  the volunteers in the list. When the user asks to quit, all the memory of the list is cleared.
  When 'd' is the input, the volunteer's list is deleted from the list.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "volunteer.h"

#define EMAIL_LEN 100
#define NAME_LEN 30

int main(void)
{
  char code;

  struct volunteer *volunteer_list = NULL;  
  printf("Operation Code: a for adding to the list, s for searching, d for deleting from the list, p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
        case 'a': volunteer_list = add_to_list(volunteer_list);
            break;
        case 'd': volunteer_list = delete_from_list(volunteer_list);
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

