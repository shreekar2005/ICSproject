#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

int already_exist(char name[], char password[])
{
    char nameinfile[20], passwordinfile[20];
    double balance0;
    FILE *file;
    file = fopen("data.txt", "rb+");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    rewind(file); // setting pointer to start of the file

    while (1)
    {
        fscanf(file, "%s %s %lf", nameinfile, passwordinfile, &balance0);
        //++printf("%s %s %lf\n",nameinfile,passwordinfile,balance0);

        if (strcmp(nameinfile, name) == 0 && strcmp(passwordinfile, password) == 0)
        {
            fclose(file);
            return 1;
        }
        if (fgetc(file) == EOF)
            break; // to scan \n char
    }
    fclose(file);
    return 0;
}

void insert(char name[], char password[], double balance)
{
    FILE *file;
    file = fopen("data.txt", "a");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit(1);
    }
    int flag = 0;
    flag = fprintf(file, "%s %s %lf\n", name, password, balance);

    if (flag)
    {
        printf("account created successfully");
    }
    else
        printf("Error Writing to File!");
    fclose(file);
}

void ShowBalance(char name[], char password[])
{
    char nameinfile[20], passwordinfile[20];
    double balance0,balance1;
    FILE *file;
    file = fopen("data.txt", "r+");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }

    rewind(file); // setting pointer to start of the file

    while (1)
    {
        fscanf(file, "%s %s %lf", nameinfile, passwordinfile, &balance0);
        if(strcmp(name,nameinfile)==0&&strcmp(password,passwordinfile)==0) balance1=balance0;
        if (fgetc(file) == EOF)
            break; // to scan \n char
    }
    fclose(file);
    printf("your current balance is : %lf", balance1);
}

void deposit(char name[], char password[], double amt) 
{
    char nameinfile[20], passwordinfile[20];
    double balance0,balance1;
    FILE *file;
    file = fopen("data.txt", "r+");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }
    rewind(file); // setting pointer to start of the file
    while (1)
    {
        fscanf(file, "%s %s %lf", nameinfile, passwordinfile, &balance0);
        if(strcmp(name,nameinfile)==0&&strcmp(password,passwordinfile)==0) balance1=balance0;
        if (fgetc(file) == EOF)
            break; // to scan \n char
    }
    balance1 += amt;
    fprintf(file,"%s %s %lf\n", name, password, balance1);
    printf("Amount deposited\n");
    Sleep(1000);
    printf("\n");
    fclose(file);
}

void Withdraw(char name[], char password[], double amt) // TO BE DONE...
{
    char nameinfile[20], passwordinfile[20];
    double balance0,balance1;
    FILE *file;
    file = fopen("data.txt", "r+");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }
    
    rewind(file); // setting pointer to start of the file
    while (1)
    {
        fscanf(file, "%s %s %lf", nameinfile, passwordinfile, &balance0);
        if(strcmp(name,nameinfile)==0&&strcmp(password,passwordinfile)==0) balance1=balance0;
        if (fgetc(file) == EOF)
            break; // to scan \n char
    }
        //++printf("%s %s %lf\n",nameinfile,passwordinfile,balance0);

            if (balance1 >=amt)
            {
                balance1 -= amt;
                fprintf(file, "%s %s %lf\n", name, password, balance1);
                printf("Please collect your Money...\n");
                Sleep(1000);
                printf("\n");
            }
            else
            {
                printf("Insufficient Funds\n");
                Sleep(1000);
                printf("\n");
            }
            fclose(file);
            // replace balance with balance
    
}

int main()
{
    double balance;
    char password[10], name[10];
    int enter = 1;
    int op = 0;
    int i;

up:
    printf("choose your operation : \n");
    printf("Enter 1 to create new account\n");
    printf("Enter 2 to open your account\n");
    printf("Enter 3 to exit program\n");
    printf("Your option : ");
    scanf("%d", &op);
    switch (op)
    {
        int inp = 0;

    case 1:
        printf("Create name : ");
        scanf("%s", &name);
        printf("Create new password : ");
        scanf("%s", &password);
        int check = already_exist(name, password);

        if (check == 1)
        {
            printf("Given password already exists\n");
            int enter = 1;
            goto up;
            break;
        }
        printf("Enter initial balance : ");
        scanf("%lf", &balance);
        insert(name, password, balance); // it will also give message...
        Sleep(1000);
        printf("\n\n");
        int enter = 1;
        goto up;
        break;

    case 2: // open account for doing changes

        printf("enter name : ");
        scanf("%s", &name);
        printf("enter password : ");
        scanf("%s", &password);
        already_exist(name, password);
        if (already_exist(name, password) == 0)
        {
            printf("wrong name or password ...");
            Sleep(1000);
            printf("\n\n");
            goto up;
        }
        else
        {
            printf("Opening your account...\n");
            Sleep(1000);
            printf("\n");
            break;
        }
    case 3:
        printf("Exiting program.....\n");
        Sleep(1000);
        goto end;
        break;

    default:
        printf("Invalid Input !!!");
        Sleep(1000);
        printf("\n\n");
        goto up;
    }

    while (1)
    {
        double amountD = 0; // deposit
        double amount = 0;  // withdraw
        char ppassword[20];

        up2:

        printf("Enter 1 to check balance\n");
        printf("Enter 2 to withdraw money\n");
        printf("Enter 3 to deposit money\n");
        printf("Enter 4 for back\n");
        printf("Enter 5 to exit program\n");
        printf("Your option : ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Enter password : ");
            scanf("%s", &ppassword);
            //printf("\n");
            if (strcmp(password, ppassword) == 0)
            {
                ShowBalance(name, password);
            }
            else
            {
                printf("Incorrect password!!!");
                Sleep(1000);
            }
            printf("\n");
            Sleep(1000);
            printf("\n");

            break;

        case 2:
            printf("Enter amount to be Withdrawn : ");
            scanf("%lf", &amount);

            printf("Enter password : ");
            scanf("%s", &ppassword);
            if (strcmp(ppassword, password) == 0)
            {
                Withdraw(name, password, amount);
            }
            else
            {
                printf("Invalid password\n");
            }
            break;

        case 3:
            printf("Enter amount to be deposited : ");
            scanf("%lf", &amountD);
            // printf("%lf" , amountD);
            printf("Enter password : ");
            scanf("%s", &ppassword);
            if (strcmp(password, ppassword) == 0)
            {
                deposit(name, password, amountD);
            }
            else
            {
                printf("Invalid password\n");
            }
            Sleep(1000);
            break;

        case 4:
            printf("Going back to previous options...\n");
            Sleep(1000);
            printf("\n");
            goto up;
            break;

        case 5:
            printf("Exiting program.....\n");
            Sleep(1000);
            printf("\n");
            goto end;
            break;

        default:
            printf("Invalid Input\n");
            Sleep(1000);
            printf("\n");
            goto up2;
            break;
        }
    }
end:
    return 0;
}
