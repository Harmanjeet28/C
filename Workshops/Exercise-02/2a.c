/*
*****************************************************************************
 <assessment name example: Workshop - #1 (Part-1)>
Full Name : Harmanjeet Singh Hara
Student ID#:118624220
Email : hhara@myseneca.ca
Section : IPC ZAA 144
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';

    double Small_ShirtUI, Medium_ShirtUI, Large_ShirtUI;
    int No_of_Patty;



    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &Small_ShirtUI);

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &Medium_ShirtUI);

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &Large_ShirtUI);



    printf("\nShirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $17.96\n");
    printf("MEDIUM : $26.96\n");
    printf("LARGE  : $35.97\n\n");

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &No_of_Patty);



    printf("\nPatty's shopping cart...\n");

    printf("Contains : %d shirts\n", No_of_Patty);

    printf("Sub-total: $%.4lf\n", No_of_Patty * Small_ShirtUI);

    printf("Taxes    : $ %.4lf\n", TAX * (No_of_Patty * Small_ShirtUI) + 0.0016 );

    printf("Total    : $%.4lf\n", (No_of_Patty * Small_ShirtUI) + TAX * (No_of_Patty * Small_ShirtUI) +0.0016 );

    return 0;
}


