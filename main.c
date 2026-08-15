#include <stdio.h>
#include <stdlib.h>
// banking atm system

struct user
{
    int pin;
    char userName[50];
    int accountMoney;
    char accountType[20];
    int accountNumber;
};

struct user users[6] = {
    {1234, "Rahul", 25000, "Savings", 100001},
    {5678, "Aman", 45000, "Current", 100002},
    {9012, "Priya", 12000, "Savings", 100003},
    {3456, "Rohit", 78000, "Savings", 100004},
    {7890, "Neha", 35000, "Current", 100005},
    {2468, "Arjun", 60000, "Savings", 100006}};

int main()
{

    printf("-----ATM MACHINE-----\n");

    int InputAccNumber;
    printf("Enter your account number : ");
    scanf("%d", &InputAccNumber);

    int found = 0;
    int FoundAtIdx;
    
    for (int i = 0; i < sizeof(users) / sizeof(users[0]); i++)
    {
        if (InputAccNumber == users[i].accountNumber)
        {
            found = 1;
            FoundAtIdx = i;
            break;
        }
    }

    if (found)
    {

        int EnterPin;
        printf("Enter your pin :");
        scanf("%d", &EnterPin);

        while (1)
        {
            system("cls");
            if (EnterPin == users[FoundAtIdx].pin)
            {
                printf("1. Check Balance\n");
                printf("2. Deposit Money\n");
                printf("3. Account Details\n");
                printf("4. Withdrwal Money\n");
                printf("5. Exit\n");

                int userInput;

                scanf("%d", &userInput);

                if (userInput == 1)
                {
                    printf("Your Balance is : %d \n", users[FoundAtIdx].accountMoney);
                }
                else if (userInput == 2)
                {
                    int InputAmount;
                    printf("Enter amount : ");
                    scanf("%d", &InputAmount);
                    if (InputAmount > 0)
                    {
                        users[FoundAtIdx].accountMoney += InputAmount;
                        printf("Amount added successfully\n");
                        printf("Your Total Balance is %d \n", users[FoundAtIdx].accountMoney);
                    }
                    else
                    {
                        printf("Wrong amount \n");
                        printf("Denied\n");
                    }
                }
                else if (userInput == 3)
                {
                    printf("Account User: %s\n", users[FoundAtIdx].userName);
                    printf("Account Number: %d\n", users[FoundAtIdx].accountNumber);
                    printf("Account Type: %s\n", users[FoundAtIdx].accountType);
                    printf("Account Balance: %d\n", users[FoundAtIdx].accountMoney);
                }
                else if (userInput == 4)
                {
                    int WidthdrawalAmount;
                    printf("Enter Withdrawal Amount: ");
                    scanf("%d", &WidthdrawalAmount);

                    if (WidthdrawalAmount > 0 && WidthdrawalAmount <= users[FoundAtIdx].accountMoney)
                    {
                        users[FoundAtIdx].accountMoney -= WidthdrawalAmount;
                        printf("Money withdrawal successfull \n");
                        printf("Aavalable Balance : %d\n", users[FoundAtIdx].accountMoney);
                    }
                    else
                    {
                        printf("Insufficent balance or invalid Amount\n");
                    }
                }
                else if (userInput == 5)
                {
                    printf("Thanks for visiting.");
                    break;
                }
                else
                {

                    printf("Invalid input\n");
                }

                printf("\nPress Enter to continue...");
                getchar();
                getchar();
            }
            else
            {
                printf("Invalid PIN!\n");
                printf("Access denied\n");
                break;
            }
        }
    }
    else
    {
        printf("User Not Found with this Account number");
    }

    return 0;
}