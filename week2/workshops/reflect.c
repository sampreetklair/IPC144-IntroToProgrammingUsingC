#include<stdio.h>

int main(){
    int result, money = 7245; 
    
    result = money / 100; 
    
    printf("1. $%.2lf\n", money / 100); 
    printf("2. $%d\n", money / 100); 
    printf("3. $%.2lf\n", result); 
    printf("4. $%d\n", result);
}