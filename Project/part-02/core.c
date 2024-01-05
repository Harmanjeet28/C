/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
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
#include "core.h"

// As demonstrated in the course notes:  
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer  
// Clear the standard input buffer 
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer: 
    while (getchar() != '\n')
    {
        ; // do nothing! 
    }
}

// Wait for user to input the "enter" key to continue 
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// 1.
int inputInt(void) {

    char Line_n = 'x';
    int Input;

    while (Line_n != '\n') {
        scanf(" %d%c", &Input, &Line_n);

        if (Line_n != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
    return Input;
}

// 2.
int inputIntPositive(void) {

    int Input;

    do {
        scanf(" %d", &Input);

        if (Input <= 0) {
            clearInputBuffer();
            printf("ERROR! Value must be > 0: ");
        }
    } while (Input <= 0);

    return Input;
}

// 3.
int inputIntRange(lwrBound, uprBound) {

    char  Line_n = 'x';
    int Input;
    int Continue_loop = 1;

    while ( Line_n != '\n' && Continue_loop) {
        scanf(" %d%c", &Input, & Line_n);

        if ( Line_n != '\n') {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

        while (Input < lwrBound || Input > uprBound) {
            scanf(" %d", &Input);

            if (Input < lwrBound || Input > uprBound) {
              
                clearInputBuffer();
                printf("ERROR! Value must be between -3 and 11 inclusive: ");
            }
            else {
                Continue_loop = 0;
            }
        }
    }
    return Input;
}

// 4.
char inputCharOption(const char strArray[]) {

    char Single_Char = ' ';
    int i;
    int Continue_loop = 1;

    for (i = 0; strArray[i] != '\0' && Continue_loop; i++) {
        scanf(" %c", &Single_Char);
        if (strArray[i] != Single_Char) {
            printf("ERROR: Character must be one of [qwErty]: ");
        }
        else {
           Continue_loop = 0;
        }
    }
    return Single_Char;
}

// 5. 
void inputCString(char* string, int min, int max) {
    int Continue_loop = 1;
    int Len = 0;
    char String_C[100];

    while (Continue_loop) {
        scanf(" %[^\n]", String_C);

        for ( Len  = 0; String_C[ Len ] != '\0'; ++ Len );
        if (min == max) {
            if ( Len  != max) {
                clearInputBuffer();
                printf("ERROR: String length must be exactly %d chars: ", max);
            }
            else {
                Continue_loop = 0;
            }

        }
        else if ( Len  > max &&  Len  != max) {
            clearInputBuffer();
            printf("ERROR: String length must be no more than %d chars: ", max);
        }
        else if ( Len  < min &&  Len  != min) {
            clearInputBuffer();
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }
        else {
           Continue_loop = 0;
        }
    }

    int i;
    for (i = 0; i <  Len ; i++) {
        string[i] = String_C[i];
    }
}

// 6. 
void displayFormattedPhone(const char* phNum) {
    int i;
    int  Len  = 0;
    int Continue_loop = 1;

    if (phNum != NULL) {
        for ( Len  = 0; phNum[ Len ] != '\0'; ++ Len );

        for (i = 0; i <  Len ; i++) {
            if (phNum[i] != '\0') {
                if ((phNum[i] != '0') && (phNum[i] != '1') && (phNum[i] != '2') && (phNum[i] != '3') && (phNum[i] != '4') &&
                    (phNum[i] != '5') && (phNum[i] != '6') && (phNum[i] != '7') && (phNum[i] != '8') && (phNum[i] != '9')) {
                    Continue_loop = 0;
                }
            }
        }

        if ((Len != 10) || !Continue_loop) {
            printf("(___)___-____");
        }
        else {
            printf("(%c%c%c)%c%c%c-%c%c%c%c",
                phNum[0], phNum[1], phNum[2], phNum[3], phNum[4],
                phNum[5], phNum[6], phNum[7], phNum[8], phNum[9]);
        }
    }
    else {
        printf("(___)___-____");
    }
}
