/*
*****************************************************************************
                        Assignment 1 - Milestone 1
Full Name  : Harmanjeet Singh Hara
Student ID#: 118624220
Email      : hhara@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include "core.h"
#include <stdio.h>

void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

//Function 1
int inputInt(void)
{
    char charText = ' ';
    int userInput;
    do
    {
        scanf("%d%c", &userInput, &charText);

        if (charText != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    } while (charText != '\n');
    return userInput;
}

//Function 2
int inputIntPositive(void)
{
    char charText = ' ';
    int userInput;
    do
    {
        scanf("%d%c", &userInput, &charText);
        if (charText != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a number: ");
        }
        if (userInput <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (userInput <= 0);
    return userInput;
}

//Function 3
int inputIntRange(int lowerB, int upperB)
{
    char blankSpace = ' ';
    int userInput;
    do
    {
        scanf("%d%c", &userInput, &blankSpace);
        if (blankSpace != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (!(userInput >= lowerB && userInput <= upperB))
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", lowerB, upperB);
        }
    } while (!(userInput >= lowerB && userInput <= upperB));

    return userInput;
}

//Function 4
char inputCharOption(char validChars[])
{
    int i, count = 0;
    char input;
    do
    {
        scanf(" %c", &input);
        for (i = 0; validChars[i] != '\0'; i++)
        {
            if (input == validChars[i])
            {
                count++;
            }
        }
        if (count == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", validChars);
        }
        clearInputBuffer();
    } while (count == 0);
    return input;
}

//Function 5
void inputCString(char* string, int minimumChar, int maximumChar)
{
    int flag = 1;
    char charUserInput = 'a';
    while (flag)
    {
        int size = 0;
        while (charUserInput != '\n' && size <= maximumChar)
        {
            scanf("%c", &charUserInput);
            string[size] = charUserInput;
            size++;
        };
        if (charUserInput == '\n' && size <= (maximumChar + 1))
        {
            size--;
            string[size] = '\0';
        }
        else
        {
            string[maximumChar] = '\0';
            clearInputBuffer();
        }
        if (minimumChar == maximumChar && size != minimumChar)
        {
            printf("ERROR: String length must be exactly %d chars: ", minimumChar);
            charUserInput = 'a';
        }
        else if (size < minimumChar || size > maximumChar)
        {
            if (size > maximumChar)
            {
                printf("ERROR: String length must be no more than %d chars: ", maximumChar);
                charUserInput = 'a';
            }
            else if (size < minimumChar)
            {
                printf("ERROR: String length must be between %d and %d chars: ", minimumChar, maximumChar);
                charUserInput = 'a';
            }
        }
        else
        {
            flag = 0;
        }
    }
}

//Function 6
void displayFormattedPhone(char string[]) {
    if (string == NULL) {
        printf("(___)___-____");
        return;
    }

    int size = 0;
    while (string[size] != '\0' && string[size] >= '0' && string[size] <= '9') {
        size++;
    }

    int i;
    if (size == 10) {
        printf("(");
        for (i = 0; i < 3; i++) {
            printf("%c", string[i]);
        }
        printf(")");

        for (i = 3; i < 6; i++) {
            printf("%c", string[i]);
        }

        printf("-");

        for (i = 6; i < 10; i++) {
            printf("%c", string[i]);
        }
    }
    else {
        printf("(___)___-____");
    }
}