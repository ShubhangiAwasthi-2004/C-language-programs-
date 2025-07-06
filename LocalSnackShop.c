#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char name[30];
    float price;
    int quantity;
} Snack;

Snack inventory[MAX];
int count = 0;

// Add snack
void addSnack() {
    if (count >= MAX) {
        printf("!! Inventory full!\n");
        return;
    }
    printf(">> Enter snack name: ");
    scanf(" %[^\n]", inventory[count].name);
    printf(">> Enter price: ₹");
    scanf("%f", &inventory[count].price);
    printf(">> Enter quantity: ");
    scanf("%d", &inventory[count].quantity);
    count++;
    printf("-- Snack added successfully --\n");
}

// Show all snacks
void showSnacks() {
    if (count == 0) {
        printf("!! No snacks available.\n");
        return;
    }
    printf("\n== Available Snacks ==\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | ₹%.2f | %d pcs\n", i + 1, inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    printf("-----------------------------------\n");
}

// Search snack
void searchSnack() {
    char name[30];
    printf(">> Enter snack name to search: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("-- Found: %s | ₹%.2f | %d pcs --\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
            return;
        }
    }
    printf("!! Snack not found!\n");
}

// Purchase snack
void purchaseSnack() {
    int index, qty;
    showSnacks();
    printf(">> Enter snack number to buy: ");
    scanf("%d", &index);
    index--;
    if (index < 0 || index >= count) {
        printf("!! Invalid choice.\n");
        return;
    }
    printf(">> Enter quantity: ");
    scanf("%d", &qty);
    if (qty > inventory[index].quantity) {
        printf("!! Not enough stock!\n");
        return;
    }
    float total = inventory[index].price * qty;
    inventory[index].quantity -= qty;
    printf("-- Purchased %d %s(s) for ₹%.2f --\n", qty, inventory[index].name, total);
}

int main() {
    int choice;
    printf("== Welcome to VIBHU's Snacks Shop ==\n");

    do {
        printf("\n>> Menu:\n1. Add Snack\n2. View Snacks\n3. Search Snack\n4. Purchase\n5. Exit\n>> Choose option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addSnack(); break;
            case 2: showSnacks(); break;
            case 3: searchSnack(); break;
            case 4: purchaseSnack(); break;
            case 5: printf("-- Exiting... Thank you! --\n"); break;
            default: printf("!! Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
