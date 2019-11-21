#include <stdbool.h>
#include <stdio.h>
#include "myBank.h"

#define ROWS 50
#define COLUMNS 2
#define STATUS 0
int account_numbers=901;

double accounts[ROWS][COLUMNS];

void openAccount(double amount){

    bool noAccounts=true;

    for(int i=0; (i<ROWS)&&noAccounts; i++)
    {
        if(accounts[i][STATUS]==0)
        {
            if(amount<0)
            {
                printf("Invalid amount input \n");
                return;
            }
            accounts[i][STATUS+1]=amount;
            accounts[i][STATUS]=1;
            printf("Your new account number is: %d\n",account_numbers);
            account_numbers++;
            noAccounts=false;
        }

    }
    if(noAccounts==true)
    {
        printf("No available open accounts \n");
    }

}
void balance(int account_number)
{
    if((901>account_number)||(account_number>950))
    {
        printf("Invalid account number \n");
        return;
    }
    int accountN=account_number-901;
    if(accounts[accountN][STATUS]==0)
    {
        printf("Account is closed \n");
    }
    else
    {
        printf("Your balance is: %.2lf\n",accounts[accountN][STATUS+1]);
    }
    
}
void deposite(int account_number,double amount)
{
    if(amount<0)
    {
        printf("Invalid amount input \n");
        return;
    }

    if((901>account_number)||(account_number>950))
    {
        printf("Invalid account number \n");
        return;
    }
    int accountN=account_number-901;
    if(accounts[accountN][STATUS]==0)
    {
        printf("Account is closed \n");
    }
    else
    {
        accounts[accountN][STATUS+1]+=amount;
        printf("Your new balance is: %.2lf\n",accounts[accountN][STATUS+1]);
    }
    
}

void withdrawal(int account_number, double amount)
{
    double balance;

    if((901>account_number)||(account_number>950))
    {
        printf("Invalid account number \n");
        return;
    }
    int accountN=account_number-901;

    if(accounts[accountN][STATUS]==0)
    {
        printf("Account is closed \n");
    }
    else
    {
        balance= accounts[accountN][STATUS+1];
        if(balance>=amount)
        {
        accounts[accountN][STATUS+1]-=amount;
        printf("Your new balance is: %.2lf\n",accounts[accountN][STATUS+1]);
        }
        else
        {
         printf("There is not enough money in the account for withdrawal \n");
        }
        
    }  
}
void closeAccount(int account_number)
{
    if((901>account_number)||(account_number>950))
    {
        printf("Invalid account number \n");
        return;
    }
    int accountN=account_number-901;
    if(accounts[accountN][STATUS]==0)
    {
        printf("Account is allready closed \n");
    }
    else
    {
        accounts[accountN][STATUS]=0;
        accounts[accountN][STATUS+1]=0;
        printf("Account is closed \n");
    }
}

void addInterest(double interest_rate)
{
    if(interest_rate<0)
    {
        printf("Invalid input interest rate  \n");
        return;
    }
    double interest_rate_calc=(interest_rate)/100+1;

    for(int i=0; i<ROWS; i++)
    {
        if(accounts[i][STATUS]==1)
        {
            accounts[i][STATUS+1]*=interest_rate_calc;
        }
    }


}

void printOpenAccounts()
{
    for(int i=0; i<ROWS; i++)
    {
        if(accounts[i][STATUS]==1)
        {
        printf("Account number is: %d ,and the balance is: %.2lf\n",i+901,accounts[i][STATUS+1]);
        }
    }
}

void closeAndExit()
{
    for(int i=0; i<ROWS; i++)
    {
        accounts[i][STATUS+1]=0;
        accounts[i][STATUS]=0;
    }
}

