/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
Full Name  :
Student ID#:
Email      :
Section    :
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    
    char Ct1, Ct2, Ct3,UCt; //coffee type
    int Ds1, Ds2, Ds3, UDs; //daily servings
    int Cpw1, Cpw2, Cpw3; //coffee package weight
    char CreamR1, CreamR2, CreamR3, UCream; //coffee cream,cream reccomendation

    Ds1 = 4;
    Ds2 = 9;
    Ds3 = 14;
    

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");

    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Ct1);

    printf("Bag weight (g): ");
    scanf("%d", &Cpw1);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &CreamR1);



    printf("\nCOFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Ct2);

    printf("Bag weight (g): ");
    scanf("%d", &Cpw2);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &CreamR2);



    printf("\nCOFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &Ct3);

    printf("Bag weight (g): ");
    scanf("%d", &Cpw3);

    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &CreamR3);



    printf("\n---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (Ct1 == 'l' || Ct1 == 'L'), (Ct3 == 'l' || Ct3 == 'L'), (Ct2 == 'l' || Ct2 == 'L'),Cpw1,(Cpw1/GRAMS_IN_LBS), (CreamR1 == 'y'|| CreamR1 == 'Y'));
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", (Ct1 == 'r' || Ct1 == 'R'), (Ct3 == 'r' || Ct3 == 'R'), (Ct2 == 'r' || Ct2 == 'R'), Cpw2, (Cpw2 / GRAMS_IN_LBS), (CreamR2 == 'y' || CreamR2 == 'Y'));
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", (Ct1 == 'm' || Ct1 == 'M'), (Ct3 == 'm' || Ct3 == 'M'), (Ct2 == 'm' || Ct2 == 'M'), Cpw3, (Cpw3 / GRAMS_IN_LBS), (CreamR3 == 'y' || CreamR3 == 'Y'));



    printf("Enter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &UCt );

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &UCream);

    printf("Typical number of daily servings: ");
    scanf(" %d", &UDs);



    printf("\nThe below table shows how your preferences align to the available products:\n");

    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (UCt == 'l'|| UCt == 'L') && (Ct1 == 'l'||Ct1 == 'L'), (UDs > 0) && (Ds1 < 5), (UCream == 'y'|| UCream == 'Y') && (CreamR1 == 'y'|| CreamR1 == 'Y'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (UCt == 'l' || UCt == 'L') && (Ct2 == 'l' || Ct2 == 'L'), (UDs > 0) && (Ds2 < 5), (UCream == 'y' || UCream == 'Y') && (CreamR2 == 'y' || CreamR2 == 'Y'));
    printf(" 3|       %d         |      %d      |   %d   |\n", (UCt == 'l' || UCt == 'L') && (Ct3 == 'l' || Ct3 == 'L'), (UDs > 0) && (Ds3 < 5), (UCream == 'y' || UCream == 'Y') && (CreamR3 == 'y' || CreamR3 == 'Y'));



    printf("\nEnter how you like your coffee...\n\n");

    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &UCt);

    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &UCream);

    printf("Typical number of daily servings: ");
    scanf("%d", &UDs);



    printf("\nThe below table shows how your preferences align to the available products:\n");

    printf("\n--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n", (UCt == 'm' || UCt == 'M') && (Ct1 == 'm' || Ct1 == 'M'), (UDs > 10) && (Ds1 > 9), (UCream == 'n' || UCream == 'N') && (CreamR1 == 'n' || CreamR1 == 'N'));
    printf(" 2|       %d         |      %d      |   %d   |\n", (UCt == 'm' || UCt == 'M') && (Ct2 == 'm' || Ct2 == 'M'), (UDs > 10) && (Ds2 > 9), (UCream == 'n' || UCream == 'N') && (CreamR2 == 'n' || CreamR2 == 'N'));
    printf(" 3|       %d         |      %d      |   %d   |\n", (UCt == 'm' || UCt == 'M') && (Ct3 == 'm' || Ct3 == 'M'), (UDs > 10) && (Ds3 > 9), (UCream == 'n' || UCream == 'N') && (CreamR3 == 'n' || CreamR3 == 'N'));
    


    printf("\nHope you found a product that suits your likes!\n");
    return 0;
}
