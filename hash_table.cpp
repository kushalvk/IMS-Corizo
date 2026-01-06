#include <iostream>
#include "hash_table.h"

using namespace std;

HashNode* table[10] = {NULL};

int hashFunction(int id) {
    return id % 10;
}

void hashInsert(Item item) {
    int index = hashFunction(item.id);
    HashNode* node = new HashNode();
    node->data = item;
    node->next = table[index];
    table[index] = node;
}

Item* hashSearch(int id) {
    int index = hashFunction(id);
    HashNode* temp = table[index];
    while (temp) {
        if (temp->data.id == id)
            return &temp->data;
        temp = temp->next;
    }
    return NULL;
}
