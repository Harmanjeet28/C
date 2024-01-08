/*
*****************************************************************************
						  Workshop - #8 (P2)
Full Name  : Harmanjeet Singh hara
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
#include "w8p2.h"


int getIntPositive(int* int_ptr) {
	int input;
	int flag = 1;

	do {
		scanf("%d", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	if (int_ptr != NULL)
	{
		*int_ptr = input;
	}
	return input;
}

double getDoublePositive(double* double_ptr) {
	double input;
	int flag = 1;

	do {
		scanf("%lf", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	if (double_ptr != NULL)
	{
		*double_ptr = input;
	}
	return input;
}

void openingMessage(const int seq_number) {

	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", maxProdCheck);
	printf("NOTE: A 'serving' is %dg\n", noOfGrams);
	printf("\n");
}

struct CatFoodInfo getCatFoodInfo(const int seq_number) {
	struct CatFoodInfo cfi;
	int flag;
	printf("Cat Food Product #%d\n", seq_number + 1);
	printf("--------------------\n");
	flag = 1;

	
	printf("SKU           : ");
	flag = 1;
	do {
		scanf("%d", &cfi.skuNumber);
		if (cfi.skuNumber <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	
	printf("PRICE         : $");
	flag = 1;
	do {
		scanf("%lf", &cfi.prodPrice);
		if (cfi.prodPrice <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	
	printf("WEIGHT (LBS)  : ");
	flag = 1;
	do {
		scanf("%lf", &cfi.prodWeight);
		if (cfi.prodWeight <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);


	printf("CALORIES/SERV.: ");
	flag = 1;
	do {
		scanf("%d", &cfi.caloriesServing);
		if (cfi.caloriesServing <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			flag = 0;
		}
	} while (flag);

	printf("\n");

	return cfi;

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

double convertLbsKg(const double* pounds, double* conversionResultToKg) {

	double poundsToKg = (*pounds) / poundToKg;

	if (conversionResultToKg != NULL)
	{
		*conversionResultToKg = poundsToKg;
	}

	return poundsToKg;
}

int convertLbsG(const double* pounds, int* conversionResultToG) {

	int poundsToG = ((*pounds) / poundToKg) * 1000;

	if (conversionResultToG != NULL)
	{
		*conversionResultToG = poundsToG;
	}

	return poundsToG;
}

void convertLbs(const double* pounds, double* conversionResultToKg, int* conversionResultToG) {

	double poundsToKg = (*pounds) / poundToKg;
	int poundsToG = ((*pounds) / poundToKg) * 1000;

	if (conversionResultToG != NULL && conversionResultToKg != NULL)
	{
		*conversionResultToG = poundsToG;
		*conversionResultToKg = poundsToKg;
	}
}

double calculateServings(const int servingSizeGrams, const int totalGrams, double* numberOfServings) {

	double servings = ((double)totalGrams) / servingSizeGrams;

	if (numberOfServings != NULL)
	{
		*numberOfServings = servings;
	}

	return servings;
}

double calculateCostPerServing(const double* price, const double* numberOfServings, double* result) {

	double costPerServing = (*price) / (*numberOfServings);

	if (result != NULL)
	{
		*result = costPerServing;
	}

	return costPerServing;
}


double calculateCostPerCal(const double* price, const double* totalCalories, double* result) {

	double costPerCal = (*price) / (*totalCalories);

	if (result != NULL)
	{
		*result = costPerCal;
	}

	return costPerCal;
}

struct ReportData calculateReportData(struct CatFoodInfo cfi) {

	struct ReportData rd;

	rd.skuNumber = cfi.skuNumber;
	rd.prodPrice = cfi.prodPrice;
	rd.prodWeightPounds = cfi.prodWeight;
	rd.caloriesServing = cfi.caloriesServing;

	rd.prodWeightKilos = convertLbsKg(&rd.prodWeightPounds, &rd.prodWeightKilos);
	rd.prodWeightGrams = convertLbsG(&rd.prodWeightPounds, &rd.prodWeightGrams);
	rd.servings = calculateServings(noOfGrams, rd.prodWeightGrams, &rd.servings);

	double totalCalories = rd.caloriesServing * rd.servings;

	rd.costPerServing = calculateCostPerServing(&rd.prodPrice, &rd.servings, &rd.costPerServing);
	rd.costCaloriesPerServing = calculateCostPerCal(&rd.prodPrice, &totalCalories, &rd.costCaloriesPerServing);


	return rd;
}

void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", noOfGrams);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

void displayReportData(const struct ReportData rd, const int cheapestProductCheck) {

	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rd.skuNumber, rd.prodPrice, rd.prodWeightPounds, rd.prodWeightKilos, rd.prodWeightGrams, rd.caloriesServing, rd.servings, rd.costPerServing, rd.costCaloriesPerServing);
}

void displayFinalAnalysis(const struct CatFoodInfo cfi) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%5.2lf\n", cfi.skuNumber, cfi.prodPrice);
	printf("\n");

	printf("Happy shopping!\n");
	printf("\n");
}

void start(void)
{
	struct ReportData rd[maxProdCheck] = { {0} };
	struct CatFoodInfo cfi[maxProdCheck] = { {0} };

	int i, cheapestIndex = 0;

	openingMessage(maxProdCheck);

	for (i = 0; i < maxProdCheck; i++) {
		cfi[i] = getCatFoodInfo(i);
		rd[i] = calculateReportData(cfi[i]);
	}

	displayCatFoodHeader();

	for (i = 0; i < maxProdCheck; i++) {
		displayCatFoodData(cfi[i].skuNumber, &cfi[i].prodPrice, cfi[i].caloriesServing, &cfi[i].prodWeight);
	}

	double cheapestProductPrice = rd[0].costPerServing;
	for (i = 0; i < maxProdCheck; i++)
	{
		if (rd[i].costPerServing <= cheapestProductPrice)
		{
			cheapestProductPrice = rd[i].costPerServing;
			cheapestIndex = i;
		}
	}
	printf("\n");

	displayReportHeader();

	for (i = 0; i < maxProdCheck; i++)
	{
		displayReportData(rd[i], cheapestIndex);

		if (cheapestIndex == i)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
	printf("\n");

	for (i = 0; i < maxProdCheck; i++)
	{
		if (i == cheapestIndex)
		{
			displayFinalAnalysis(cfi[i]);
		}
	}
}