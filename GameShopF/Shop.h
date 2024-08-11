#pragma once
#include <vector>
#include "Player.h"

class Shop
{
private:
    std::vector<Item*> items;

public:
    void addItem(Item* item)
    {
        items.push_back(item);
    }
    void displayItems() const;
    Item* findItemByName(const std::string& itemName) const;
    bool buyItem(Player* player, Item* item);
    void sellItem(Player* player, const std::string& itemName);
};
