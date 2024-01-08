/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Harmanjeet Singh Hara
Student ID#: 118624220
Email      : hhara@myseneca.ca
Section    : IPC144ZAA
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    int P1Id = 111, P2Id = 222, P3Id = 111;
    double P1Price = 111.49, P2Price = 222.99, P3Price = 334.49;
    char Taxed1 = 'Y', Taxed2 = 'N', Taxed3 = 'N';
    double avergePrice;

    //Formula

    avergePrice = ((P1Price + P2Price) + P3Price)/3;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", P1Id);
    printf("  Taxed: %c\n", Taxed1);
    printf("  Price: $%.4lf\n\n", P1Price);


    printf("Product-2 (ID:%d)\n", P2Id);
    printf("  Taxed: %c\n", Taxed2);
    printf("  Price: $%.4lf\n\n", P2Price);


    printf("Product-3 (ID:%d)\n", P3Id);
    printf("  Taxed: %c\n", Taxed3);
    printf("  Price: $%.4lf\n\n", P3Price);


    printf("The average of all prices is: $%.4lf\n\n", avergePrice);


    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");


    printf("Some Data Analysis...\n");
    printf("=====================\n");


    printf("1. Is product 1 taxable? -> %d\n\n", Taxed1 == 'Y');

    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", Taxed2 == 'N' && Taxed3 == 'N');

    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n",testValue, (int)P3Price == (int)testValue);

    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", (P1Price + P2Price) < P3Price);

    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", (P3Price - P2Price) <= P1Price, P3Price - P2Price);

    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", P2Price >= avergePrice);

    printf("7. Based on product ID, product 1 is unique -> %d\n\n", P1Id != P2Id && P1Id != P3Id);

    printf("8. Based on product ID, product 2 is unique -> %d\n\n", P2Id != P1Id && P2Id != P3Id);

    printf("9. Based on product ID, product 3 is unique -> %d\n\n", P3Id != P1Id && P3Id != P2Id);

    

    return 0;
}