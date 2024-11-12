#include <stdio.h>


struct FoodItem {
    int id;
    char name[20];
    float price;
};


void displayMenu(struct FoodItem menu[], int size) {
    printf("\n----- Food Menu -----\n");
    printf("ID\tItem\t\tPrice\n");
    printf("----------------------------\n");
    for(int i = 0; i < size; i++);
	{
        printf("%d\t%-10s\t$%.2f\n", menu[i].id, menu[i].name, menu[i].price);
    }
}


struct FoodItem* findFoodItemById(struct FoodItem menu[], int size, int id) {
    for (int i = 0; i < size; i++) {
        if (menu[i].id == id) {
            return &menu[i];
        }
    }
    return NULL; 
}

int main() {
    
    struct FoodItem menu[] = {
        {1, "Burger", 5.99},
        {2, "Pizza", 8.99},
        {3, "Pasta", 6.50},
        {4, "Salad", 4.00},
        {5, "Soda", 1.50}
    };
    int menuSize = sizeof(menu) / sizeof(menu[0]);

    float totalBill = 0.0;
    char choice;

    printf("Welcome to the Food Billing System!\n");

    do {
        
        displayMenu(menu, menuSize);

        
        int itemId;
        printf("\nEnter the ID of the food item you want to order: ");
        scanf("%d", &itemId);

       
        struct FoodItem* selectedItem = findFoodItemById(menu, menuSize, itemId);
        if (selectedItem == NULL) {
            printf("Invalid ID. Please try again.\n");
            continue;
        }

       
        int quantity;
        printf("Enter quantity for %s: ", selectedItem->name);
        scanf("%d", &quantity);

        
        float cost = selectedItem->price * quantity;
        totalBill += cost;

       
        printf("Added %d x %s for $%.2f\n", quantity, selectedItem->name, cost);
        printf("Current total bill: $%.2f\n", totalBill);

       
        printf("\nWould you like to order more items? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    
    printf("\n----- Final Bill -----\n");
    printf("Total Amount: $%.2f\n", totalBill);
    printf("Thank you for your order!\n");

    return 0;
}

