#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>

struct DATA
{
    char name[20];
    double balance;
    char password[20];

} data, *ptr;

int already_exist(char name[], char password[])
{
    FILE *file;
    file = fopen("data.txt", "rb+");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }
    struct DATA read_struct;
    rewind(file); // setting pointer to start of the file
    while (fread(&read_struct, sizeof(struct DATA), 1, file))
    {
        if (strcmp(read_struct.name, name) == 0 && strcmp(read_struct.password, password) == 0)
        {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

void insert(char name[], char password[], double balance)
{
    FILE *file;
    file = fopen("data.txt", "ab");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit(1);
    }
    ptr = &data;
    strcpy(data.name, name);
    strcpy(data.password, password);
    data.balance = balance;
    int flag = 0;
    flag = fwrite(ptr, sizeof(struct DATA), 1, file);

    if (flag)
    {
        printf("account created successfully");
    }
    else
        printf("Error Writing to File!");
    fclose(file);
}

void ShowBalance(struct DATA *a)
{
    printf("your current balance is : %lf", a->balance);
}

void deposit(struct DATA *a, double amt) // TO BE DONE...
{

    (*a).balance = a->balance + amt;
    printf("deposit Successful\n");
    Sleep(1000);
}
void Withdraw(struct DATA *a, double amt) // TO BE DONE...
{
    if ((*a).balance >= amt)
    {

        (*a).balance -= amt;
        printf("Please collect your Money...\n");
    }
    else
    {
        printf("Insufficient Funds\n");
    }
    Sleep(1000);
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
        FILE *file; // this is for initialize ptr to user's structure
        file = fopen("data.txt", "rb+");
        if (file == NULL)
        {
            fprintf(stderr, "\nError opening file\n");
            exit(1);
        }
        struct DATA read_struct;
        rewind(file); // setting pointer to start of the file
        while (fread(&read_struct, sizeof(struct DATA), 1, file))
        {
            if (strcmp(read_struct.name, name) == 0 && strcmp(read_struct.password, password) == 0)
            {
                ptr = &read_struct;
                break;
            }
        }

        double amountD = 0; // deposit
        double amount = 0;  // withdraw

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
            scanf("%s", &password);
            printf("\n");
            if (strcmp(password, ptr->password) == 0)
            {
                ShowBalance(ptr);
            }
            printf("\n\n");
            Sleep(1000);
            break;

        case 2:
            printf("Enter amount to be Withdrawn : ");
            scanf("%lf", &amount);

            printf("Enter password : ");
            scanf("%s", &password);
            if (strcmp(password, ptr->password) == 0)
            {
                Withdraw(ptr, amount);
            }
            else
            {
                printf("Invalid password\n");
            }
            Sleep(1000);
            break;

        case 3:
            printf("Enter amount to be deposited : ");
            scanf("%lf", &amountD);
            // printf("%lf" , amountD);
            printf("Enter password : ");
            scanf("%s", &password);
            if (strcmp(password, ptr->password) == 0)
            {
                deposit(&read_struct, amountD);
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
            fclose(file);
            goto up;
            break;

        case 5:
            printf("Exiting program.....\n");
            Sleep(1000);
            printf("\n");
            fclose(file);
            goto end;
            break;

        default:
            printf("Invalid Input\n");
            Sleep(1000);
            printf("\n");
            break;
        }
    }
end:
    return 0;
}
