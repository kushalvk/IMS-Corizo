#include <iostream>
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "hash_table.h"
#include "sorting.h"
#include "file_handler.h"
#include "clear_inventory.h"

using namespace std;

int main() {
    clearInventory();
    loadInventory();

    int choice;
    Item item;

    do {
        cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Item\n";
        cout << "2. Display Items\n";
        cout << "3. Search Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Sort by Price\n";
        cout << "6. Undo Last Add\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter ID: ";
            cin >> item.id;
            cout << "Enter Name: ";
            cin >> item.name;
            cout << "Enter Category: ";
            cin >> item.category;
            cout << "Enter Quantity: ";
            cin >> item.quantity;
            cout << "Enter Price: ";
            cin >> item.price;

            addItem(item);
            push(item);
            hashInsert(item);
            cout << "Item added successfully\n";
            saveInventory();
            break;

        case 2:
            displayItems();
            break;

        case 3:
            cout << "Enter ID to search: ";
            cin >> item.id;
            if (hashSearch(item.id))
                cout << "Item found\n";
            else
                cout << "Item not found\n";
            break;

        case 4:
            cout << "Enter ID to delete: ";
            cin >> item.id;
            deleteItem(item.id);
            saveInventory();
            break;

        case 5:
            bubbleSortByPrice();
            break;

        case 6:
            item = pop();
            if (item.id != -1)
                deleteItem(item.id);
            saveInventory();
            break;

        case 7:
            saveInventory();
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
