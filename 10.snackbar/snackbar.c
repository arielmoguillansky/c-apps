// Practice using structs
// Practice writing a linear search function

/**
 * Beach Burger Shack has the following 10 items on their menu
 * Burger: $9.5
 * Vegan Burger: $11
 * Hot Dog: $5
 * Cheese Dog: $7
 * Fries: $5
 * Cheese Fries: $6
 * Cold Pressed Juice: $7
 * Cold Brew: $3
 * Water: $2
 * Soda: $2
*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>

// Number of menu items
// Adjust this value (10) to number of items input below
#define NUM_ITEMS 10

// Menu itmes have item name and price
typedef struct
{
    char item[20];
    float price;
} menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(char *item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i]. price);
    }
    printf("\n");

    float total = 0;

    while (true)
    {
        char item[20];
        printf("Enter a food item: ");
        fgets(item, sizeof item, stdin);

        if (strlen(item) == 1)
        {
            printf("\n");
            break;
        }

        total += get_cost(item);
    }

    printf("Your total cost is: $%.2f\n", total);

    return 0;
}

// Add at least the first four items to the menu array
void add_items(void)
{
    strcpy(menu[0].item, "Burger");
    menu[0].price = 9.5;
    strcpy(menu[1].item, "Vegan Burger");
    menu[1].price = 11;
    strcpy(menu[2].item, "Hot Dog");
    menu[2].price = 5;
    strcpy(menu[3].item, "Cheese Dog");
    menu[3].price = 7;
    strcpy(menu[4].item, "Fries");
    menu[4].price = 5;
    strcpy(menu[5].item, "Cheese Fries");
    menu[5].price = 6;
    strcpy(menu[6].item, "Cold Pressed Juice");
    menu[6].price = 7;
    strcpy(menu[7].item, "Cold Brew");
    menu[7].price = 3;
    strcpy(menu[8].item, "Water");
    menu[8].price = 2;
    strcpy(menu[9].item, "Soda");
    menu[9].price = 2;
    return;
}

// Search through the menu array to find an item's cost
float get_cost(char *item)
{
    // Convert the input item to lowercase
    char lowercase_item[20];
    int i;
    for (i = 0; item[i] && item[i] != '\n'; i++)
    {
        lowercase_item[i] = tolower(item[i]);
    }
    lowercase_item[i] = '\0';  // Null-terminate the string

    float tempprice = 0.0;
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        // Create a copy of temp_item before converting to lowercase
        char *lowercase_temp_item = malloc(strlen(menu[i].item) + 1);
        strcpy(lowercase_temp_item, menu[i].item);

        for (int j = 0, n = strlen(menu[i].item); j < n; j++)
        {
            lowercase_temp_item[j] = tolower(menu[i].item[j]);
        }

        if (strcmp(lowercase_temp_item, lowercase_item) == 0)
        {
            tempprice = menu[i].price;
            free(lowercase_temp_item);  // Free the allocated memory
            break;
        }

        free(lowercase_temp_item);  // Free the allocated memory
    }

    return tempprice;
}
