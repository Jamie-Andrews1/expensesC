#include <stdio.h>
#include <string.h>

typedef struct Expense
{
    char desc[50];
    double amount;
} expense;

int main(void) 
{

    expense *expensePtr, exp;
    expensePtr = &exp;
    int i, n;
    int valid_input[] = {1, 2, 3};
    int array_length = sizeof(valid_input) / sizeof(valid_input[0]);
    int is_valid = 0;
    int choice = 0;

    // function to choose option
    int isChosen(int num) {        
    if(num == 1){

        printf("Please enter your expense description: ");

        scanf("%s", &expensePtr->desc);

        printf("Please enter your expense amount: ");

        scanf("%lf", &expensePtr->amount);

    } else if(num == 2) 
    {
        printf("Description: %s\n", expensePtr->desc);

        printf("Amount: %.2f\n\n", expensePtr->amount);    



    } else if(num == 3){
        return 0;
    }  

    }

    //Start of program
    printf("\t\t Expense Tracker \n");
    
    printf("Would you like to: \n\n");

    printf("1. Enter Expenses \n2. View Expenses \n3. Exit \n\n");

    scanf("%d", &choice);

    if(choice){
    for(int i = 0; i < array_length; i++){
        if(choice == valid_input[i]){
            is_valid = 1;
            break;
        }
    }
        while (!is_valid)
        {
            printf("Try Again!! \n\n");

            printf("Would you like to: \n\n");

            printf("1. Enter Expenses \n2. View Expenses \n3. Exit \n\n");

            scanf("%d", &choice);

            for(int i = 0; i < array_length; i++){
            if(choice == valid_input[i]){
            is_valid = 1;
            break;
        }
        }
        }
        if(is_valid){
            isChosen(choice);
            
        } 
          
    }
}