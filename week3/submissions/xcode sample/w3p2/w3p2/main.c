/*
/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Sampreet Klair
Student ID#: 145031225
Email      : sklair2@myseneca.ca
Section    : ZCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////
*/

#include <stdio.h>

int main()
{
    char coffee1_type, coffee2_type, coffee3_type, urcoffee1_type, urcoffee2_type;
    int coffee1_weight, coffee2_weight, coffee3_weight, urcoffee1_weight, urcoffee2_weight;
    char coffee1_cream, coffee2_cream, coffee3_cream, urcoffee1_cream, urcoffee2_cream;
    const double GRAMS_IN_LBS = 453.5924;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c", &coffee1_type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee1_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c\n", &coffee1_cream);
    printf("\n");
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c\n", &coffee2_type);
    printf("Bag weight (g): ");
    scanf("%d\n\n", &coffee2_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c\n", &coffee2_cream);
    printf("\n");
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf("%c", &coffee3_type);
    printf("Bag weight (g): ");
    scanf("%d", &coffee3_weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf("%c\n", &coffee3_cream);
    printf("\n");
    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  | (G) |  Lbs    | Cream |\n");
    return 0;
}
