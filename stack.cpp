#include <iostream>
#include "stack.h"

using namespace std;

struct StackNode {
    Item data;
    StackNode* next;
};

StackNode* top = NULL;

void push(Item item) {
    StackNode* node = new StackNode();
    node->data = item;
    node->next = top;
    top = node;
}

bool isStackEmpty() {
    return top == NULL;
}

Item pop() {
    Item item;
    if (isStackEmpty()) {
        item.id = -1;
        return item;
    }
    StackNode* temp = top;
    item = temp->data;
    top = temp->next;
    delete temp;
    return item;
}
