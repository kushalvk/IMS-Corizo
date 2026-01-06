#include "clear_inventory.h"
#include "linked_list.h"
#include "hash_table.h"

void clearLinkedList() {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
}

void clearHashTable() {
    for (int i = 0; i < 10; i++) {
        HashNode* current = table[i];
        HashNode* next;

        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }

        table[i] = NULL;
    }
}

void clearInventory() {
    clearLinkedList();
    clearHashTable();
}
