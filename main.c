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
    strcpy(expensePtr->desc, "");
    expensePtr->amount = 0.0;
    int i, n;
    int valid_input[] = {1, 2, 3};
    int array_length = sizeof(valid_input) / sizeof(valid_input[0]);
    int expense_entered = 0;

 int getValidChoice(int valid_input[], int array_length) {
    int choice;
    int is_valid = 0;   

    do {
        printf("\t\t Expense Tracker \n\n");

        printf("Would you like to: \n\n");
        printf("1. Enter Expenses \n2. View Expenses \n3. Exit \n\n");
        scanf("%d", &choice);

        for (int i = 0; i < array_length; i++) {
            if (choice == valid_input[i]) {
                is_valid = 1;
                break;
            }
        }

        if (!is_valid) {
            printf("Try Again!! \n\n");
        }
    } while (!is_valid);

    return choice;
}
    
    void handleExpenseOption(int choice) {
    switch(choice) {
        case 1:
            printf("Please enter your expense description: ");
            scanf("%s", expensePtr->desc);
            printf("Please enter your expense amount: ");
            scanf("%lf", &expensePtr->amount);
            expense_entered = 1;
            break;
        case 2:
            if(expense_entered){
            printf("Description: %s\n", expensePtr->desc);
            printf("Amount: %.2f\n\n", expensePtr->amount);
            } else {
                printf("No expense entered yet. Please enter an expense first.\n\n");
                }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option\n");
    }
}

    int running = 1;
    while (running) {
        int user_choice = getValidChoice(valid_input, array_length);
        handleExpenseOption(user_choice);
        if (user_choice == 3) {
            running = 0;
        }
    }
    return 0;

}