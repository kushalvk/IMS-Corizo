#include <iostream>
#include "sorting.h"
#include "linked_list.h" // For Node and head
#include "item.h"      // For Item

using namespace std;

void bubbleSortByPrice() {
    if (!head) return;

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data.price > j->data.price) {
                Item temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    cout << "Inventory sorted by price\n";
}
