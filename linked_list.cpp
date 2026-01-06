#include <iostream>
#include "linked_list.h"

using namespace std;

Node* head = NULL;

void addItem(Item item) {
    Node* newNode = new Node();
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void displayItems() {
    Node* temp = head;
    if (!temp) {
        cout << "Inventory is empty\n";
        return;
    }
    while (temp) {
        cout << temp->data.id << " | "
             << temp->data.name << " | "
             << temp->data.category << " | "
             << temp->data.quantity << " | "
             << temp->data.price << endl;
        temp = temp->next;
    }
}

Node* searchItem(int id) {
    Node* temp = head;
    while (temp) {
        if (temp->data.id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void deleteItem(int id) {
    Node *temp = head, *prev = NULL;

    while (temp && temp->data.id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Item not found\n";
        return;
    }

    if (!prev)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Item deleted successfully\n";
}
