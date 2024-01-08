/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Harmanjeet Singh Hara
Student ID#: 118624220
Email      : hhara@myseneca.ca
Section    : ZAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define maxItems 10
#include <stdio.h>

int main(void)
{
    const double maxSalary = 400000, minSalary = 500;
    double uNetIncome = 0;
    int uMaxItems;
    const double leastValue = 100;
    

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");

    uNetIncome = 0;

    while (uNetIncome < minSalary || uNetIncome > maxSalary)
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &uNetIncome);

        if (uNetIncome < minSalary)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
        }
        else if (uNetIncome > maxSalary)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
        else
        {
            printf("\n");
        }
    }

    uMaxItems = 0;

    while (uMaxItems <= 0 || uMaxItems >= maxItems)
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &uMaxItems);

        if (uMaxItems <= 0)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
        else if (uMaxItems > maxItems)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
        else 
        {
            printf("\n");
        }
    }

    

    
    
    double itemCost[3];
    int priority[3];
    char financing[3];

    int i;
    for (i = 1; i <= uMaxItems; i++)
    {
        printf("Item-%d Details:\n", i);

        
        do {
            printf("   Item cost: $");
            scanf("%lf", &itemCost[i - 1]);

            if (itemCost[i - 1] < leastValue)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (itemCost[i - 1] < leastValue);

       
        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i - 1]);

            if ((priority[i - 1] < 1) || (priority[i - 1] > 3))
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while ((priority[i - 1] < 1) || (priority[i - 1] > 3));

        
        do {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financing[i - 1]);

            if (!(financing[i - 1] == 'n' || financing[i - 1] == 'y'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (!(financing[i - 1] == 'n' || financing[i - 1] == 'y'));

        printf("\n");
    }

    
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

   
    int h;
    double total_cost = 0;
    for (h = 1; h <= uMaxItems; h++)
    {
        printf("  %d      %d        %c     %10.2lf\n", h, priority[h - 1], financing[h - 1], itemCost[h - 1]);
        total_cost += itemCost[h - 1];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $ %.2lf\n", total_cost);
    printf("\n");

    
    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
    
    
    


    


    


   