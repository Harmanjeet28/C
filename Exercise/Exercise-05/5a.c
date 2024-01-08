/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
Full Name  : Harmanjeet
Student ID#: 118624220
Email      : hhara@myseneca.ca
Section    : ZAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_YEAR 2012
#define MAX_YEAR 2022
#define logDays 3

int main(void)
{

    const int JAN = 1, DEC = 12;
    int Flag1 = 1, h;
    int year, month;
    double morningRating, eveningRating, morningRatingTotal = 0, eveningRatingTotal = 0;


    printf("General Well-being Log\n");
    printf("======================\n");

    while (Flag1 == 1)
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);

        if (!(year >= MIN_YEAR && year <= MAX_YEAR))
        {
            printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
        }
        if (!(month >= JAN && month <= DEC))
        {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }
        if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC))
        {
            printf("\n*** Log date set! ***\n");

            
            for (h = 1;h <= logDays; h++)
            {
                switch (month)
                {
                case 1:
                    printf("\n%d-JAN-%.2d\n", year, h);
                    break;
                case 2:
                    printf("\n%d-FEB-%.2d\n", year, h);
                    break;
                case 3:
                    printf("\n%d-MAR-%.2d\n", year, h);
                    break;
                case 4:
                    printf("\n%d-APR-%.2d\n", year, h);
                    break;
                case 5:
                    printf("\n%d-MAY-%.2d\n", year, h);
                    break;
                case 6:
                    printf("\n%d-JUN-%.2d\n", year, h);
                    break;
                case 7:
                    printf("\n%d-JUL-%.2d\n", year, h);
                    break;
                case 8:
                    printf("\n%d-AUG-%.2d\n", year, h);
                    break;
                case 9:
                    printf("\n%d-SEP-%.2d\n", year, h);
                    break;
                case 10:
                    printf("\n%d-OCT-%.2d\n", year, h);
                    break;
                case 11:
                    printf("\n%d-NOV-%.2d\n", year, h);
                    break;
                case 12:
                    printf("\n%d-DEC-%.2d\n", year, h);

                    break;
                }

                printf("   Morning rating (0.0-5.0): ");
                scanf("%lf", &morningRating);

                while ((morningRating < 0 || morningRating > 5))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Morning rating (0.0-5.0): ");
                    scanf("%lf", &morningRating);
                } 
               
                printf("   Evening rating (0.0-5.0): ");
                scanf("%lf", &eveningRating);

                while ((eveningRating < 0 || eveningRating > 5))
                {
                    printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
                    printf("   Evening rating (0.0-5.0): ");
                    scanf("%lf", &eveningRating);
                } 

                        morningRatingTotal += morningRating;
                        eveningRatingTotal += eveningRating;
                    } 
            Flag1 = 0;
                }
            }
             

             printf("\nSummary\n");
             printf("=======\n");

             printf("Morning total rating: %.3lf\n", morningRatingTotal);
             printf("Evening total rating:  %.3lf\n", eveningRatingTotal);

             printf("----------------------------\n");
             printf("Overall total rating: %.3lf\n\n", morningRatingTotal+eveningRatingTotal);


             printf("Average morning rating:  %.1lf\n", morningRatingTotal / logDays);
             printf("Average evening rating:  %.1lf\n", eveningRatingTotal / logDays);

             printf("----------------------------\n");

             printf("Average overall rating:  %.1lf\n", ((morningRatingTotal / logDays) + (eveningRatingTotal / logDays)) / 2);

    return 0;
}