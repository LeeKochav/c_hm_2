#include <stdbool.h>
#include <stdio.h>
#include "myBank.h"

int main()
{

char action;
while(action!='E')
{
    printf("Transaction type? ");
    if(scanf(" %c",&action)==1)
    {
    switch (action)
    {
    case 'O':
        printf("Please enter amount number for the first deposite: \n");
        double amount=0;
        if(scanf("%lf",&amount)!=1)
        {
            printf("Invalid input \n");
            break;
        }
        openAccount(amount);
        break;
    case 'B':
        printf("Please enter account number: \n");
        int account_number=0;
        if(scanf("%d",&account_number)!=1)
        {
           printf("Invalid input \n");
           break;  
        }
        balance(account_number);
        break;
    case 'D':
        printf("Please enter account number and amount to deposite: \n");
        int account_number1=0;
        double amount1=0;
        if(scanf("%d%lf",&account_number1,&amount1)!=2)
        {
             printf("Invalid input \n");
             break;
        }
        deposite(account_number1,amount1);
        break;
    case 'W':
        printf("Please enter account number and amount to withdrawal: \n");
        int account_number2=0;
        double amount2=0;
        if(scanf("%d%lf",&account_number2,&amount2)!=2)
        {
             printf("Invalid input \n");
             break;
        }
        withdrawal(account_number2,amount2);
        break;
    case 'C':
        printf("Please enter account number: \n");
        int account_number3=0;
        if(scanf("%d",&account_number3)!=1)
        {
             printf("Invalid input \n");
             break;
        }
        closeAccount(account_number3);
    case 'I':
        printf("PLease enter the interest rate");
        double interest_rate=0;
        if(scanf("%lf",&interest_rate)!=1)
        {
             printf("Invalid input \n");
             break;
        }
        addInterest(interest_rate);
        break;
    case 'P':
        printOpenAccounts();
        break;
    case 'E':
        closeAndExit();
        break;
    default:
        printf("Error, please try again \n");
        break;
        }
    }    
}

return 0;
}