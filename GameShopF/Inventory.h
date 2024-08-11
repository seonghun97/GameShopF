#pragma once
#include <vector>
#include "Item.h"

class Inventory
{
private:
    std::vector<Item*> items;

public:
    void addItem(Item* item)
    {
        items.push_back(item);
    }
    void removeItem(const std::string& itemName);
    void displayItems() const;
    Item* findItem(const std::string& itemName) const;
};
