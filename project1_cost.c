
/* Maria Jose Perez Smith

    This program promts the user to enter an event venue for parties package number. Stores it and then, calculates the total charge 
    depending on the amount of hours rented and the number of people. The food is charged separtely per person. 


*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Defining the variables
    int package, num_guests, hrs_rented, total_charge; 

    //prompts the user for package number
    printf("Please select from three packages: 1, 2, and 3\nEnter package selection:");
    scanf("%d", &package);

    //number of package range
    if(package < 1 || package > 3)
    {
        printf("Invalid selection.\n");
        // exit the program
        exit(0);
    }
    //prompts the user for number of hours
    printf("Enter hours:");
    scanf("%d", &hrs_rented);

    //number of hours range.
    if (hrs_rented < 1 || hrs_rented > 4)
    {
        printf("Invalid hours.\n");
        // exit the program.
        exit(0);
    }
    
    //prompts the user for number of guests
    printf("Enter the number of guests: ");
    scanf("%d", &num_guests);

    //controls package 1 rates
    if (package == 1)
    {
        //defines package 1 rate variables
        int first_hour = 150;
        int hourly_cost = 100;
        int min_guests = 5;
        int max_guests = 20;
        int cost_food = 25;
        int max_charge = 595;

        //calculates total_charge for package 1

            //makes sure it is between the num of guests range
        if (num_guests <= max_guests && num_guests >= min_guests )
        {
            //calculates first hour cost of package
            if (hrs_rented == 1)
            {
                int finalhr = first_hour;
                int final_food = num_guests * cost_food;
                total_charge = finalhr + final_food;

                if (total_charge > max_charge)
                {
                    total_charge = max_charge;
                }
                else{}
            }

            //calculates when hours rented is more than 1
            else if ( hrs_rented <= 4 && hrs_rented > 1 )
            {
                int finalhr = first_hour + (hourly_cost * (hrs_rented - 1));
                
                int final_food = num_guests * cost_food;
                total_charge = finalhr + final_food;

                if (total_charge > max_charge)
                {
                    total_charge = max_charge;
                }
                else{}
            }

        }
        else
        {
            //num of guests permitted is not met
            printf("Invalid number of guests.\n");
            // exit the program.
            exit(0); 
        }


    }
   //controls package 2 rates 
    if (package ==2)
    {
        //define package 2 rate variables
        int first_hour = 180;
        int hourly_cost = 120;
        int min_guests = 8;
        int max_guests = 30;
        int cost_food = 22;
        int max_charge = 850;

        //calculates total charge for package 2 
            //makes sure num of guests permitted is met
        if (num_guests <= max_guests && num_guests >= min_guests )
        {
            //calculates first hour cost of package 
            if (hrs_rented == 1)
            {
                int finalhr = first_hour;
                int final_food = num_guests * cost_food;
                total_charge = finalhr + final_food;

                if (total_charge > max_charge)
                {
                    total_charge = max_charge;
                }
                else{}
            }

            //calculates when hours rented is more than 1
            else if ( hrs_rented <= 4 && hrs_rented > 1 )
            {
                int finalhr = first_hour + (hourly_cost * (hrs_rented - 1));
                
                int final_food = num_guests * cost_food;
                total_charge = finalhr + final_food;

                if (total_charge > max_charge)
                {
                    total_charge = max_charge;
                }
                else{}
            }

        }
        else
        {
            //num of guests permitted is not met
            printf("Invalid number of guests.\n");
            // exit the program.
            exit(0); 
        }


    }
    
    //controls package 3 rates
    if (package == 3)
    {
        //define variables for package 3 rates
        int first_hour = 200;
        int hourly_cost = 150;
        int min_guests = 10;
        int max_guests = 40;
        int cost_food = 20;
        int max_charge = 1050;

        //calculates the total charge of package 3
            //makes sure num of guests permitted is met
        if (num_guests <= max_guests && num_guests >= min_guests )
        {
            //calculates first hour of rent
            if (hrs_rented == 1)
            {
                int finalhr = first_hour;
                int final_food = num_guests * cost_food;
                total_charge = finalhr + final_food;

                if (total_charge > max_charge)
                {
                    total_charge = max_charge;
                }
                else{}
            }
            //calculates when hours rented is more than 1
            else if ( hrs_rented <= 4 && hrs_rented > 1 )
            {
                int finalhr = first_hour + (hourly_cost * (hrs_rented - 1));
                
                int final_food = num_guests * cost_food;
                total_charge = finalhr + final_food;

                if (total_charge > max_charge)
                {
                    total_charge = max_charge;
                }
                else{}
            }

        }
        else
        {
            //num of guests permitted is not met
            printf("Invalid number of guests.\n");
            // exit the program.
            exit(0); 
        }


    }
    
    //prints total charge for event package
    printf("Charge($):%d\n", total_charge);

    return 0;

}

