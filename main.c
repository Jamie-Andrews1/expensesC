#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_EXPENSES 100

typedef struct
{
    char desc[50];
    double amount;
} expense;

int getValidChoice(int valid_input[], int array_length) {
    int choice;
    int is_valid = 0;

    do {
        printf("\n\n\t\t Expense Tracker \n\n");

        printf("Would you like to: \n\n");
        printf("1. Enter An Expense \n2. View Expenses \n3. Update An Expense \n4. Remove An Expense \n5. Exit  \n\n");
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
    
void handleExpenseOption(expense *expensePtr, int *expense_count, int n, int *exit) {
    int choice;
    int valid_input[] = {1, 2, 3, 4, 5};
    int array_length = sizeof(valid_input) / sizeof(valid_input[0]);

        choice = getValidChoice(valid_input, array_length);

    switch(choice) {
        case 1:
            if (*expense_count < n) {
            printf("Please enter your expense description: ");
            scanf("%49s", expensePtr[*expense_count].desc);
            printf("Please enter your expense amount: ");
            scanf("%lf", &expensePtr[*expense_count].amount);
            (*expense_count)++;
            } else {
                printf("Maximum number of expenses reached.\n");
            }
            break;
        case 2:
            if(*expense_count > 0){
            for(int i = 0; i < *expense_count; i++){
            printf("\n%d. Description: %s\t\tAmount: %.2f\n",i, expensePtr[i].desc, expensePtr[i].amount);}

            } else {
                printf("No expense entered yet. Please enter an expense first.\n\n");
                }
            break;
        case 3:
        if(*expense_count > 0){
            int exp;
            printf("Which expense would you like to update?\n");
            for(int i = 0; i < *expense_count; i++){
            printf("\n%d. Description: %s\t\tAmount: %.2f\n",i, expensePtr[i].desc, expensePtr[i].amount);}
            printf("\nPlease enter your expense number to update: ");
            scanf("%d", &exp);
            while(exp > *expense_count - 1){
            printf("\n expense doesn't exist please try again\n");
            printf("\nPlease enter your expense number to update: ");
            scanf("%d", &exp);
            }
            printf("Please enter your expense description: ");
            scanf("%49s", expensePtr[exp].desc);
            printf("Please enter your expense amount: ");
            scanf("%lf", &expensePtr[exp].amount);
            } else {    
            printf("No expense entered yet. Please enter an expense first.\n\n");
            }
        break;
        case 4:
        if(*expense_count > 0){
            int exp;
            printf("Which expense would you like to remove?\n");
            for(int i = 0; i < *expense_count; i++){
            printf("\n%d. Description: %s\t\tAmount: %.2f\n",i, expensePtr[i].desc, expensePtr[i].amount);}
            printf("\nPlease enter your expense number to remove: ");
            scanf("%d", &exp);
            while(exp > *expense_count - 1){
            printf("\n expense doesn't exist please try again\n");
            printf("\nPlease enter your expense number to remove: ");
            scanf("%d", &exp);
            }
            printf("expense %d removed\n", exp);
            for (int i = exp; i < *expense_count - 1; i++) {
                expensePtr[i] = expensePtr[i + 1];
            }
            (*expense_count)--;

            } else {    
                printf("No expense entered yet. Please enter an expense first.\n\n");
                }
            break;
            case 5:
            printf("Exiting...\n");
            *exit = 0;
            break;
        default:
            printf("Invalid option\n");
    }
}


int main() 
{
    expense expenses[MAX_EXPENSES];
    expense *expensePtr, exp;
    expensePtr = &exp;
    strcpy(expensePtr->desc, "");
    int expense_count = 0;
    expensePtr->amount = 0.0;
    int i;
    int expense_entered = 0;
    int exit = 1;
    int n = MAX_EXPENSES;

        // allocating memory for n numbers of struct person
        expensePtr = ( expense*) malloc(n * sizeof( expense ));

        if (expensePtr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    int running = 1;
    while (running) {
        handleExpenseOption(expensePtr, &expense_count, n, &exit);
        if (exit == 0) {
            running = 0;
        }
    }
    free(expensePtr);
    return 0;
    
}