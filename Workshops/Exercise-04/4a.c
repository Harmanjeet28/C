/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

#include <stdio.h>

int main(void)
{

    char Format_Used;
    int Number_of_Repetition, i;





    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");


    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &Format_Used, &Number_of_Repetition);

        



        if (Format_Used == 'D' || Format_Used == 'W' || Format_Used == 'F' || Format_Used == 'Q') 
        {
            
            if (Format_Used == 'F')
            {
                if (Number_of_Repetition >= 3 && Number_of_Repetition <= 20)
                {
                    printf("FOR     : ");
                    for (i = 0; i < Number_of_Repetition; i++)
                    {
                        printf("%c", Format_Used);
                    }
                    printf("\n");
                }
                else 
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                    
                }
            }
  
            if (Format_Used == 'D')
            {
                if (Number_of_Repetition >= 3 && Number_of_Repetition <= 20)
                {
                    printf("DO-WHILE: ");
                    i = 0;
                    do
                    {
                        printf("%c", Format_Used);
                        i++;
                    } while (i < Number_of_Repetition);
                    printf("\n");
                    
                }
                
                
                else
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");

                }
            }

            if (Format_Used == 'W')
            {
                if (Number_of_Repetition >= 3 && Number_of_Repetition <= 20) 
                {   
                    printf("WHILE   : ");
                    i = 0;
                    while (i < Number_of_Repetition)
                    {

                        i++;
                        printf("%c", Format_Used);

                    }
                    printf("\n");
                    
                }
                
                
                
                else 
                {
                    printf("ERROR: The number of iterations must be between 3-20 inclusive!\n");
                    
                }
            }

        else if (Format_Used == 'Q' && Number_of_Repetition != 0)
            {
                printf("ERROR: To quit, the number of iterations should be 0!\n");
            }
            printf("\n");
            



        }
        else
        {
            printf("ERROR: Invalid entered value(s)!\n\n");
            
        }
        


    }while (!(Format_Used == 'Q' && Number_of_Repetition == 0));

    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");


    return 0;
}