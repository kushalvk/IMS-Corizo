#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "item.h"

struct HashNode {
    Item data;
    HashNode* next;
};

extern HashNode* table[10];

void hashInsert(Item item);
Item* hashSearch(int id);

#endif // HASH_TABLE_H
