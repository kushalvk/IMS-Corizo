#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "item.h"

struct Node {
    Item data;
    Node* next;
};

extern Node* head;

void addItem(Item item);
void displayItems();
void deleteItem(int id);
Node* searchItem(int id);

#endif // LINKED_LIST_H
