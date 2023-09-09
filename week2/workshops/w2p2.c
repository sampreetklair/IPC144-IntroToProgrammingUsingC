/*
*****************************************************************************
                <Workshop - #2 (Part-2)>
Full Name : Sampreet Klair
Student ID#: 145031225
Email : sklair2@myseneca.ca
Section : ZCC
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#include <stdio.h>

int main(){

    double price_small, price_medium, price_large;
    int patty_shirt_number, tommy_shirt_number, sally_shirt_number;
    int sub_total_patty, sub_total_tommy, sub_total_sally; 
    int taxes_patty, taxes_sally, taxes_tommy;
    int total_patty, total_tommy, total_sally;
    int sub_total_all, total_all, taxes_all;
    int qty_exctax_toonies, qty_exctax_loonies, qty_exctax_quarters, qty_exctax_dimes, qty_exctax_nickels; 
    int qty_exctax_pennies;
    double balance_exctax_toonies, balance_exctax_loonies, balance_exctax_quarters, balance_exctax_dimes, balance_exctax_nickels, balance_exctax_pennies;
    int qty_inctax_toonies, qty_inctax_loonies, qty_inctax_quarters, qty_inctax_dimes, mod_toonies_balance;
    int qty_inctax_nickels, qty_inctax_pennies;
    int balance_inctax_toonies, balance_inctax_loonies, balance_inctax_dimes, balance_inctax_nickels, balance_inctax_pennies, balance_inctax_quarters; 
    double avg_costpshirt_exctax, avg_costpshirt_inctax;
    double dec_balance_exctax_toonies, dec_balance_inctax_toonies, balance, avg;
    const double TAX = 0.13;

    printf("Set Shirt Prices"); printf("\n");
    printf("================"); printf("\n");
    printf("Enter the price for a SMALL shirt: $"); 
    scanf("%lf", &price_small);
    printf("Enter the price for a MEDIUM shirt: $"); 
    scanf("%lf", &price_medium);
    printf("Enter the price for a LARGE shirt: $"); 
    scanf("%lf", &price_large); printf("\n");
    printf("Shirt Store Price List"); printf("\n");
    printf("======================"); printf("\n");
    printf("SMALL  : $%.2lf", price_small); printf("\n");
    printf("MEDIUM : $%.2lf", price_medium); printf("\n");
    printf("LARGE  : $%.2lf", price_large); printf("\n\n");
    printf("Patty's shirt size is \'S\'"); printf("\n");
    printf("Number of shirts Patty is buying: "); 
    scanf("%d", &patty_shirt_number); printf("\n");
    printf("Tommy's shirt size is \'L\'"); printf("\n");
    printf("Number of shirts Tommy is buying: "); 
    scanf("%d", &tommy_shirt_number); printf("\n");
    printf("Sally's shirt size is \'M\'"); printf("\n");
    printf("Number of shirts Sally is buying: "); 
    scanf("%d", &sally_shirt_number); printf("\n");
    sub_total_patty = (patty_shirt_number * price_small * 100)+ 0.5;
    sub_total_tommy = (tommy_shirt_number * price_large * 100)+ 0.5;
    sub_total_sally = (sally_shirt_number * price_medium * 100)+ 0.5;
    sub_total_all = sub_total_patty +  sub_total_tommy + sub_total_sally;
    taxes_patty = sub_total_patty * TAX + 0.5;
    taxes_tommy = sub_total_tommy * TAX + 0.5;
    taxes_sally = sub_total_sally * TAX + 0.5;
    taxes_all = taxes_patty + taxes_sally + taxes_tommy;
    total_patty = sub_total_patty + taxes_patty; 
    total_tommy = sub_total_tommy + taxes_tommy;
    total_sally = sub_total_sally + taxes_sally;
    total_all =  total_patty + total_sally + total_tommy;
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------");
    printf("\nPatty    S    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf", price_small, patty_shirt_number, (double)sub_total_patty/100, (double)taxes_patty/100, (double)total_patty/100);
    printf("\nSally    M    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf", price_medium, sally_shirt_number, (double)sub_total_sally/100, (double)taxes_sally/100, (double)total_sally/100);
    printf("\nTommy    L    %.2lf   %d  %8.4lf  %8.4lf  %8.4lf", price_large, tommy_shirt_number, (double)sub_total_tommy/100, (double)taxes_tommy/100, (double)total_tommy/100);
    printf("\n-------- ---- ----- --- --------- --------- ---------");
    printf("\n                         %8.4lf  %8.4lf  %8.4lf\n\n", (double)sub_total_all/100, (double)taxes_all/100, (double)total_all/100);
    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   balanceance\n");
    printf("-------- --- ---------");
    printf("\n %22.4lf\n", (double)sub_total_all/100);
    qty_exctax_toonies = sub_total_all / 100; balance = (int)sub_total_all % 200; printf("Toonies  %3d %10.4lf\n", qty_exctax_toonies, balance / 100);
    qty_exctax_loonies = balance / 100; balance = (int)balance % 100; printf("Loonies  %3d %10.4lf\n", qty_exctax_loonies, balance / 100);
    qty_exctax_quarters = balance / 25; balance = (int)balance % 25; printf("Quarters  %2d %10.4lf\n", qty_exctax_quarters, balance / 100);
    qty_exctax_dimes = balance / 10; balance = (int)balance % 10; printf("Dimes  %5d %10.4lf\n", qty_exctax_dimes, balance / 100);
    qty_exctax_nickels = balance / 5; balance = (int)balance % 5; printf("Nickels  %3d %10.4lf\n", qty_exctax_nickels, balance / 100);
    qty_exctax_pennies = balance; balance = (int)balance % 1; printf("Pennies  %3d %10.4lf\n\n", qty_exctax_pennies, balance / 100);
    avg_costpshirt_exctax = sub_total_all / (patty_shirt_number + sally_shirt_number + tommy_shirt_number); printf("Average cost/shirt: $%.4lf\n\n", avg_costpshirt_exctax / 100.0);
    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   balanceance\n");
    printf("-------- --- ---------");
    printf("\n %22.4lf\n", (double)total_all/100);
    qty_exctax_toonies = total_all/200; balance = (int)total_all % 200; printf("Toonies  %3d %10.4lf\n", qty_inctax_toonies, balance / 100);
    qty_inctax_loonies = balance / 100; balance = (int)balance % 100; printf("Loonies  %3d %10.4lf\n", qty_inctax_loonies, balance / 100);
    qty_inctax_quarters = balance / 25; balance = (int)balance % 25; printf("Quarters  %2d %10.4lf\n", qty_inctax_quarters, balance / 100);
    qty_inctax_dimes = balance / 10; balance = (int)balance % 10; printf("Dimes  %5d %10.4lf\n", qty_inctax_dimes, balance / 100);
    qty_inctax_nickels = balance / 5; balance = (int)balance % 5; printf("Nickels  %3d %10.4lf\n", qty_inctax_nickels, balance / 100);
    qty_inctax_pennies = balance; balance = (int)balance % 1; printf("Pennies  %3d %10.4lf\n\n", qty_inctax_pennies, balance / 100);
    avg_costpshirt_inctax = total_all / (patty_shirt_number + sally_shirt_number + tommy_shirt_number); printf("Average cost/shirt: $%.4lf\n", avg_costpshirt_inctax / 100.0);

    return 0;
}