#pragma once
#include "Inventory.h"

class Player
{
private:
    std::string name;
    int gold;
    int attack;
    int defense;
    Item* equippedWeapon; //厘馒等公扁
    Item* equippedArmor; //厘馒等规绢备
    Inventory inventory;

public:
    Player(std::string name) : name(name), gold(1000), attack(10), defense(10), equippedWeapon(nullptr), equippedArmor(nullptr) {}
    Item* findItemInInventory(const std::string& itemName)
    {
        return inventory.findItem(itemName);
    }
    void removeItemFromInventory(const std::string& itemName)
    {
        inventory.removeItem(itemName);
    }
    std::string getName() const
    {
        return name;
    }
    void addItemToInventory(Item* item)
    {
        inventory.addItem(item);
    }
    void displayInventory() const
    {
        inventory.displayItems();
    }

    int getGold() const
    {
        return gold;
    }
    void subtractGold(int amount)
    {
        gold -= amount;
    }
    void addGold(int amount)
    {
        gold += amount;
    }
    void equipItem(const std::string& itemName);
    void unequipItem(const std::string& itemName);
    void displayStatus() const;
    void displayEquippedItems() const;
};
