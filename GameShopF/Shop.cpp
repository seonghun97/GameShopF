#include "Shop.h"
#include <iostream>

void Shop::displayItems() const
{
    std::cout << "���� ��ǰ ���: " << std::endl;;
    for (const auto& item : items)
    {
        std::cout << item->getName() << " (" << item->getType() << ") - ����: " << item->getPrice() << " ��� - ���: " << item->getQuantity() << std::endl;
    }
}

Item* Shop::findItemByName(const std::string& itemName) const
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

bool Shop::buyItem(Player* player, Item* item)
{
    if (player->getGold() >= item->getPrice() && item->getQuantity() > 0)
    {
        player->subtractGold(item->getPrice());
        player->addItemToInventory(new Item(*item));
        item->reduceQuantity();
        std::cout << item->getName() << "��(��) �����߽��ϴ�.\n";
        return true;
    }
    std::cout << "��尡 �����ϰų� ��� �����ϴ�.\n";
    return false;
}

void Shop::sellItem(Player* player, const std::string& itemName)
{
    Item* item = player->findItemInInventory(itemName);
    if (item)
    {
        player->addGold(item->getPrice() / 2);
        player->removeItemFromInventory(itemName);
        Item* shopItem = findItemByName(itemName);
        if (shopItem)
        {
            shopItem->increaseQuantity();
        }
        else
        {
            addItem(new Item(*item));
        }
        std::cout << itemName << "��(��) ������ �Ǹ��߽��ϴ�.\n";
    }
    else
    {
        std::cout << "�Ǹ��� �������� �����ϴ�.\n";
    }
}
