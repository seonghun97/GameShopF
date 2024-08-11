#include "Shop.h"
#include <iostream>

void Shop::displayItems() const
{
    std::cout << "상점 물품 목록: " << std::endl;;
    for (const auto& item : items)
    {
        std::cout << item->getName() << " (" << item->getType() << ") - 가격: " << item->getPrice() << " 골드 - 재고: " << item->getQuantity() << std::endl;
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
        std::cout << item->getName() << "을(를) 구매했습니다.\n";
        return true;
    }
    std::cout << "골드가 부족하거나 재고가 없습니다.\n";
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
        std::cout << itemName << "을(를) 상점에 판매했습니다.\n";
    }
    else
    {
        std::cout << "판매할 아이템이 없습니다.\n";
    }
}
