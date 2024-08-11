#include "Inventory.h"
#include <iostream>

void Inventory::removeItem(const std::string& itemName)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if ((*it)->getName() == itemName)
        {
            items.erase(it);
            break;
        }
    }
}

void Inventory::displayItems() const
{
    for (const auto& item : items)
    {
        std::cout << item->getName() << " (" << item->getType() << ")\n";
    }
}

Item* Inventory::findItem(const std::string& itemName) const
{
    for (const auto& item : items)
    {
        if (item->getName() == itemName)
        {
            return item;
        }
    }
    return nullptr;
}
