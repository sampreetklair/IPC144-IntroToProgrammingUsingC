/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
Full Name  : Sampreet Klair
Student ID#: 145031225
Email      : sklair2@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAX_NUMBER_OF_ITEMS 10
#define MIN_NUMBER_OF_ITEMS 1

int main(void)
{
    const double MAX_INCOME = 400000.00;
    const double MIN_INCOME = 500.00;
    double income;
    int valid;
    int numOfItems;
    int i;
    const double MIN_COST = 100;
    const int MAX_PRIORITY = 3;
    const int MIN_PRIORITY = 1;
    int priority[MAX_NUMBER_OF_ITEMS];
    double cost[MAX_NUMBER_OF_ITEMS];
    char finance[MAX_NUMBER_OF_ITEMS];
    double total_cost = 0;
    const char YES = 'y';
    const char NO = 'n';
    int selection;
    int years;
    int months;
    int cost_priority_1;
    int cost_priority_2;
    int cost_priority_3;
    int done;
    int priority_choice;

    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n");
    printf("\n");

    do
    {
        valid = 1;
        printf("Enter your monthly NET income: $");
        scanf("%lf", &income);
        if (income < MIN_INCOME)
        {
            valid = 0;
            printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_INCOME);
        }
        if (income > MAX_INCOME)
        {
            valid = 0;
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME);
        }

    } while (valid == 0);

    printf("\n");

    do
    {
        valid = 1;
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &numOfItems);
        if (numOfItems < MIN_NUMBER_OF_ITEMS || numOfItems > MAX_NUMBER_OF_ITEMS)
        {
            valid = 0;
            printf("ERROR: List is restricted to between %d and %d items.\n", MIN_NUMBER_OF_ITEMS, MAX_NUMBER_OF_ITEMS);
            printf("\n");
        }

    } while (valid == 0);

    for (i = 0; i < numOfItems; i++)
    {
        printf("\n");
        printf("Item-%d Details:\n", i + 1);

        do
        {
            valid = 1;
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < MIN_COST)
            {
                valid = 0;
                printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
            }

        } while (valid == 0);

        do
        {
            valid = 1;
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] < MIN_PRIORITY || priority[i] > MAX_PRIORITY)
            {
                valid = 0;
                printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
            }

        } while (valid == 0);

        do
        {
            valid = 1;
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &finance[i]);
            if (finance[i] != YES && finance[i] != NO)
            {
                valid = 0;
                printf("      ERROR: Must be a lowercase \'y\' or \'n\'\n");
            }

        } while (valid == 0);
    }

    // report

    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 0; i < numOfItems; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], finance[i], cost[i]);
        total_cost = total_cost + cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", total_cost);

    for (i = 0; i < numOfItems; i++)
    {
        if (priority[i] == priority[1])
        {
            cost_priority_1 = cost_priority_1 + priority[1];
        }

        if (priority[i] == priority[2])
        {
            cost_priority_2 = cost_priority_2 + priority[2];
        }

        if (priority[i] == priority[3])
        {
            cost_priority_3 = cost_priority_3 + priority[3];
        }
    }

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
			cost_priority_1 *= 100;
			income *= 100;
			years = (int)cost_priority_1 / (int)(income * 12);
			months = ((int)cost_priority_1 % (int)(income * 12)) / income;
			printf("Forecast: %d years, %.0lf months\n", years, months);
			cost_priority_1 /= 100;
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
			printf("Filter:   by priority (%d)\n", priority_choice);
			done = 0;

			switch (priority_choice)
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

					if (priority[i] == priority_choice)

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

					if (priority[i] == priority_choice)

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
					if (priority[i] == priority_choice)
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
			printf("====================================================\n");
		}
		else
		printf("\nERROR: Invalid menu selection.\n");
		printf("\n");
	} while (valid);

	printf("Best of luck in all your future endeavours!\n");

	return 0;
}