#ifndef ITEM_H
#define ITEM_H

#include <string>

struct Item {
    int id;
    std::string name;
    std::string category;
    int quantity;
    float price;
};

#endif // ITEM_H
