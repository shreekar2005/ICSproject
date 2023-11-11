#include<stdio.h>
#include<string.h>
#include<windows.h>
struct ATM{
    double balance;
    int pin;

}atm;


void CheckBalance(struct ATM *a){
    printf("Your balance is : %lf \n" , a->balance );
    Sleep(1000);
}
void deposit(struct ATM *a , double amt){
    
    (*a).balance = (double)a->balance + amt;
   
    printf("deposit Successful\n");
    Sleep(1000);
}
void Withdraw(struct ATM *a , double amt){
    if((*a).balance >= amt){

        (*a).balance -= amt;
     printf("Please collect your Money...\n");
    }else{
        printf("Insufficient Funds\n");
    }
    Sleep(1000);
}
int main(){ 
  
    struct ATM *ptr = &atm;
    
    printf("Enter Pin : ");
    scanf("%d" , &ptr->pin);
    printf("Enter initial balance : ");
    scanf("%lf" , &ptr->balance);
    int enter = 1;
    
    while(enter){
        printf("choose your operation : \n");
        printf("Enter 1 to check balance\n");
        printf("Enter 2 to withdraw money\n");
        printf("Enter 3 to deposit money\n");
        printf("Enter 4 to exit\n");
        Sleep(200);
        double amountD = 0; //deposit
        double amount = 0; //withdraw
        int op = 0; 
        scanf("%d" , &op);
        switch (op)
        {
            int inp = 0;
        case 1:
            printf("Enter pin : ");
            scanf("%d" , &inp);
            if(inp == ptr->pin){

            CheckBalance(ptr);
        }else{
            printf("Invalid Pin \n");
        }
            break;
        case 2: 
            printf("Enter amount to be Withdrawn : ");
            scanf("%lf" , &amount);

            printf("Enter pin : ");
            scanf("%d" , &inp);
            if(inp == ptr->pin){
                Withdraw(ptr,amount);
            }else{
            printf("Invalid Pin\n");
            }
            break;
        case 3: 
            printf("Enter amount to be deposited : ");
            scanf("%lf" , &amountD);
            //printf("%lf" , amountD);
            printf("Enter pin : ");
            scanf("%d" , &inp);
            if(inp == ptr->pin){
                deposit(ptr,amountD);
            }else{
            printf("Invalid Pin\n");
            }   
            break;
            
        case 4:
            printf("Exiting program.....\n");
            enter = 0;
            break;
        default:
            printf("Invalid Input\n");
            break;
        }

    }

}
