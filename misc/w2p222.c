/*
*****************************************************************************
                          Workshop - #6 (P2)
Full Name  : 
Student ID#: 
Email      : 
Section    : 
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00
#define MIN_LIST 1
#define MAX_LIST 10
#define MIN_COST 100.00

int main(void)
{
	int valid = 1, done;
	double income,months;
	int numOfItems,selection, i,years, itemList[MAX_LIST];
	double cost, costList[MAX_LIST], total_cost = 0, cost_priority_1 = 0, cost_priority_2 = 0, cost_priority_3 = 0;
	int priority, priority[MAX_LIST];
	char financeOptions, finance[MAX_LIST];

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	do
	{
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &income);
		if (income < MIN_INCOME)
			printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		else if (income > MAX_INCOME)
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
		else
			valid = 0;
	} while (valid);
	valid = 1;

	do
	{
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &numOfItems);
    	if (numOfItems < MIN_LIST || numOfItems > MAX_LIST)
        printf("ERROR: List is restricted to between 1 and 10 items.\n");
		else
			valid = 0;
	} while (valid);

	for (i = 0; i < numOfItems; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		valid = 1;
		do
		{
			printf("   Item cost: $");
			scanf("%lf", &cost);
			if (cost < MIN_COST)
				printf("      ERROR: Cost must be at least $100.00\n");
			else
			{
				total_cost += cost;
				costList[i] = cost;
				valid = 0;
			}
		} while (valid);
		valid = 1;

		do
		{
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &priority);
			if (priority < 1 || priority > 3)
				printf("      ERROR: Value must be between 1 and 3\n");
			else
			{
				priority[i] = priority;
				switch (priority)
				{
				case 1:
					cost_priority_1 += costList[i];
					break;

				case 2:
					cost_priority_2 += costList[i];
					break;

				case 3:
					cost_priority_3 += costList[i];
					break;

				default:
					break;
				}
				valid = 0;
			}
		} while (valid);
		valid = 1;

		do
		{
			scanf("%*c");
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%c", &financeOptions);
			switch (financeOptions)
			{
			case 'y':
			case 'n':
				finance[i] = financeOptions;
				valid = 0;
				break;
			default:
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (valid);
		itemList[i] = i + 1;
	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < numOfItems; i++)
		printf("%3d  %5d    %5c    %11.2lf\n", itemList[i], priority[i], finance[i], costList[i]);
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", total_cost);
	valid = 1;

	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);

		if (selection == 0)
			valid = 0;
		else if (selection == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", total_cost);
			total_cost *= 100;
			income *= 100;
			years = (int)total_cost / (int)(income * 12);
			months = ((int)total_cost % (int)(income * 12)) / income;
			printf("Forecast: %d years, %.0lf months\n", years, months);
			total_cost /= 100;
			income /= 100;
			done = 0;
			for (i = 0; i < numOfItems; i++)
				if (finance[i] == 'y')
					done = 1;
			if (done)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");
		}

		else if (selection == 2)
		{
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &priority);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)\n", priority);
			done = 0;

			switch (priority)
			{
			case 1:
				printf("Amount:   $%1.2lf\n", cost_priority_1);
				cost_priority_1 *= 100;
				income *= 100;
				years = (int)cost_priority_1 / (int)(income * 12);
				months = ((int)cost_priority_1 % (int)(income * 12)) / income;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				cost_priority_1 /= 100;
				income /= 100;
				for (i = 0; i < numOfItems; i++)

					if (priority[i] == priority)

						if (finance[i] == 'y')

							done = 1;
				break;

			case 2:
				printf("Amount:   $%1.2lf\n", cost_priority_2);
				cost_priority_2 *= 100;
				income *= 100;
				years = (int)cost_priority_2 / (int)(income * 12);
				months = (((int)cost_priority_2 % (int)(income * 12)) / income) + 1;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				cost_priority_2 /= 100;
				income /= 100;

				for (i = 0; i < numOfItems; i++)

					if (priority[i] == priority)

						if (finance[i] == 'y')

							done = 1;
				break;

			case 3:
				printf("Amount:   $%1.2lf\n", cost_priority_3);
				cost_priority_3 *= 100;
				income *= 100;
				years = (int)cost_priority_3 / (int)(income * 12);
				months = ((int)cost_priority_3 % (int)(income * 12)) / income;
				printf("Forecast: %d years, %.0lf months\n", years, months);
				cost_priority_3 /= 100;
				income /= 100;
				for (i = 0; i < numOfItems; i++)
					if (priority[i] == priority)
						if (finance[i] == 'y')
							done = 1;
				break;

			default:
				break;
			}

			if (done)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			prin tf("====================================================\n");
		}
		else
		printf("\nERROR: Invalid menu selection.\n");
		printf("\n");
	} while (valid);

	printf("Best of luck in all your future endeavours!\n");

	return 0;
}












printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", total_cost);
			total_cost *= 100;
			income *= 100;
			years = (int)total_cost / (int)(income * 12);
			months = ((int)total_cost % (int)(income * 12)) / income;
			printf("Forecast: %d years, %.0lf months\n", years, months);
			total_cost /= 100;
			income /= 100;
			valid = 0;
			for (i = 0; i < numOfItems; i++)
				if (finance[i] == 'y')
					done = 1;
			if (done)
			{
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
			}
			printf("====================================================\n");