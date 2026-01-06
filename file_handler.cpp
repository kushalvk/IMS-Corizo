#include <iostream>
#include <fstream>
#include "file_handler.h"
#include "linked_list.h"
#include "hash_table.h"

using namespace std;

void loadInventory() {
    ifstream file("inventory.txt");
    if (!file.is_open()) {
        cout << "Could not open inventory.txt for reading." << endl;
        return;
    }

    Item item;
    while (file >> item.id >> item.name >> item.category >> item.quantity >> item.price) {
        addItem(item);
        hashInsert(item);
    }

    file.close();
}

void saveInventory() {
    ofstream file("inventory.txt");
    if (!file.is_open()) {
        cout << "Could not open inventory.txt for writing." << endl;
        return;
    }

    Node* temp = head;
    while (temp) {
        file << temp->data.id << " "
             << temp->data.name << " "
             << temp->data.category << " "
             << temp->data.quantity << " "
             << temp->data.price << endl;
        temp = temp->next;
    }

    file.close();
}
