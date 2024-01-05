/*
*****************************************************************************
						  Workshop - #8 (P1)
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
#include <stdio.h>
#include "w8p1.h"

int getIntPositive(int* intptr)
{
	int userIntTestInput, flag;
	flag = 1;

	do
	{
		scanf("%d", &userIntTestInput);
		if (userIntTestInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else 
		{
			flag = 0;
		}
	}while (flag == 1);

	if (intptr != NULL)
	{
		*intptr = userIntTestInput;
	}
	return userIntTestInput;
}

double getDoublePositive(double* doubleptr)
{
	double userDoubleTestInput;
	int flag;
	flag = 1;

	do
	{
		scanf("%lf", &userDoubleTestInput);

		if (userDoubleTestInput <= 0) 
		{
			printf("ERROR: Enter a positive value: ");
		}
		else 
		{
			flag = 0;
		}
	}while (flag == 1);

	if (doubleptr != NULL)
	{
		*doubleptr = userDoubleTestInput;
	}
	return userDoubleTestInput;
}

void openingMessage(const int seq_number) {

	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", maxProdCheck);
	printf("NOTE: A 'serving' is %dg\n", noOfGrams);
	printf("\n");
}

struct CatFoodInfo getCatFoodInfo(const int seq_number)
{
	struct CatFoodInfo userInput;
	int flag;
	printf("Cat Food Product #%d\n", seq_number + 1);
	printf("--------------------\n");

	printf("SKU           : ");

	flag = 1;

	while (flag == 1)
	{
		scanf("%d", &userInput.skuNumber);
		
		if (userInput.skuNumber <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else 
		{
			flag = 0;
		}
	}

	printf("PRICE         : $");

	flag = 1;
	while (flag == 1) 
	{
		scanf("%lf", &userInput.prodPrice);

		if (userInput.prodPrice <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	}

	printf("WEIGHT (LBS)  : ");

	flag = 1;
	while (flag == 1) 
	{
		scanf("%lf", &userInput.prodWeight);

		if (userInput.prodWeight <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	}

	printf("CALORIES/SERV.: ");

	flag = 1;
	while (flag == 1)
	{
		scanf("%d", &userInput.caloriesServing);

		if (userInput.caloriesServing <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else 
		{
			flag = 0;
		}
	}

	printf("\n");

	return userInput;
}

void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

void displayCatFoodData(int sku_number, double* product_price, int calorie_per_serving, double* product_weight_lbs)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku_number, *product_price, *product_weight_lbs, calorie_per_serving);
}

void start(void)
{
	int i;
	struct CatFoodInfo userInput[maxProdCheck] = { {0} };
	openingMessage(maxProdCheck);

	for (i = 0; i < maxProdCheck; i++) {
		userInput[i] = getCatFoodInfo(i);
	}

	displayCatFoodHeader();

	for (i = 0; i < maxProdCheck; i++) {
		displayCatFoodData(userInput[i].skuNumber, &userInput[i].prodPrice, userInput[i].caloriesServing, &userInput[i].prodWeight);
	}

}