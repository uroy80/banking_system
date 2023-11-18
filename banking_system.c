/*File Name: Banking System
Assigned By: Maria Nancy
Last Modified Date: November 18, 2022
Description: This program is a banking system that allows the user to deposit, 
withdraw, and check their balance
Programmer Name : Usham Roy
SRM Institute Of Science & Technology
Register Number : RA2311003011574
Department : Computing Technologies
Branch : Computer Science & Engineering
*/

#include <stdio.h>

struct customer //declaring data's under the structure named customer
{
    int  account_no;
    char name[80],email[80],dob[20];
    int balance;
    long long mobile_no;
   };

char ifsc[20]="HDFC0005442",branch_code[10]="5442";
int cif=192030;
char branchaddress[100]="SRM Institute Of Science & Technology,SRM Nagar,Kattankulathur,1st Floor UB Building,603203,TN";



void accept(struct customer[], int);
void display(struct customer[], int);
int search(struct customer[], int, int);
void deposit(struct customer[], int, int, int);
void withdraw(struct customer[], int, int, int);

int main()
{
    struct customer data[20];
    int n, choice, amount, index;
    long long account_no;

    printf("Banking System\n\n");
    printf("## THIS PART IS FOR ADMINISTRATOR ##\n");
    printf("Enter the number of customers: ");//Admin Code
    
    scanf("%d", &n);
    accept(data, n);
    do
    {
        printf("## THIS PART IS FOR CUSTOMER ##\n");
        printf("\nBanking System Menu :\n");
       // printf("Press 1 to display all records-->\n");
        printf("Press 1 For A/C Details-->\n");
        printf("Press 2 to deposit amount-->\n");
        printf("Press 3 to withdraw amount-->\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);
        switch (choice)
        {
            /*case 1:
                display(data, n);
                break;*/
            case 1:
                printf("Enter account number to search : ");
                scanf("%lld", &account_no);
                index = search(data, n, account_no);
                if (index ==  - 1)
                {
                    printf("Record not found : ");
                }
                else
                {
                    printf("A/c Number: %d\nName: %s\nBalance: %d\n",
                        data[index].account_no, data[index].name,
                        data[index].balance);
                }
                break;
            case 2:
                printf("Enter account number : ");
                scanf("%lld", &account_no);
                printf("Enter amount to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, account_no, amount);
                break;
            case 3:
                printf("Enter account number : ");
                scanf("%lld", &account_no);
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(data, n, account_no, amount);
        }
    }
    while (choice != 0);

    return 0;
}

void accept(struct customer list[80], int s)
{
    FILE *file;
    file=fopen("customer_database.txt","w");
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fprintf(file,"Account No: %d\t",list[i].account_no);
        fflush(stdin);
        fprintf(file,"IFSC Code : %s\t",ifsc);
        fprintf(file,"CIF : %d\t",cif);
        cif++;


        printf("\n Enter name : ");
        fgets(list[i].name,80,stdin);
        fprintf(file,"Name Of The Customer:%s\t",list[i].name);
        printf("\n Enter Your D.O.B : ");
        fgets(list[i].dob,20,stdin);
        fprintf(file,"Date Of Birth :%s\t",list[i].dob);
        printf("\n Enter Your Email :");
        fgets(list[i].email,80,stdin);
        fprintf(file,"Email Of the Customer:%s\t",list[i].email);
        printf("\n Enter Your Mobile Number :");
        scanf("%lld",&list[i].mobile_no);

        long long m = list[i].mobile_no;
        int count=0;
    while(m!=0){
         count++;
         m=m/10;
    }if(count==10){
       fprintf(file,"Account Holder Mobile Number : %lld\t",list[i].mobile_no);
    }else{
      printf("\n !! Enter Valid Mobile Number !! \n");
    }


        list[i].balance = 0;
        fprintf(file,"Balance is : %d\t",list[i].balance );
        fclose(file);
    } 
}

void display(struct customer list[80], int s)
{
    int i;

    printf("\n\nA/c No\tName\tBalance\n");
    for (i = 0; i < s; i++)
    {
        printf("%d\t%s\t%d\n", list[i].account_no, list[i].name,
            list[i].balance);
    } 
}

int search(struct customer list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            return i;
        } 
    }
    return  - 1;
}

void deposit(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found");
    } 
    else
    {
        list[i].balance += amt;
    }
}

void withdraw(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found\n");
    } 
    else if (list[i].balance < amt)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[i].balance -= amt;
    }
}
