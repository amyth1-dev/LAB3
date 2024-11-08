#include <stdio.h>

int main() {
    int balance = 1000;
    int transactions[] = {200, -150, -500, 400, -50, -2000, 300};  
    int num_transactions = sizeof(transactions) / sizeof(transactions[0]);
    int tobeprocessed[num_transactions];  
    int tobeprocessed_count = 0;

    for (int i = 0; i < num_transactions; i++) {
        int transaction = transactions[i];

        
        if (transaction < 0 && -transaction > balance) {
            printf("Transaction %d is invalid (withdrawal exceeds current balance).\n", transaction);
            tobeprocessed[tobeprocessed_count++] = transaction;  
            continue;  
        }

        
        balance += transaction;

        
        if (balance == 0) {
            printf("Balance has reached 0. No further transactions will be processed.\n");
            tobeprocessed[tobeprocessed_count++] = transaction;  
            break;  
        }
    }

    
    printf("Final Balance: %d AED\n", balance);

   
    printf("Unprocessed Transactions:\n");
    for (int i = 0; i < tobeprocessed_count; i++) {
        printf("%d ", tobeprocessed[i]);
    }
    printf("\n");

    return 0;
}