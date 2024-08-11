#include "Player.h"
#include <iostream>

void Player::equipItem(const std::string& itemName)
{
    Item* item = inventory.findItem(itemName);
    if (item)
    {
        if (item->getType() == "Weapon")
        {
            if (equippedWeapon)
            {
                addItemToInventory(equippedWeapon);
                attack -= equippedWeapon->getAttack();
            }
            equippedWeapon = item;
            attack += item->getAttack();
            inventory.removeItem(itemName);
            std::cout << itemName << "을(를) 장착했습니다." <<std::endl;
        }
        else if (item->getType() == "Armor")
        {
            if (equippedArmor)
            {
                addItemToInventory(equippedArmor);
                defense -= equippedArmor->getDefense();
            }
            equippedArmor = item;
            defense += item->getDefense();
            inventory.removeItem(itemName);
            std::cout << itemName << "을(를) 장착했습니다." << std::endl;
        }
    }
    else
    {
        std::cout << "아이템을 찾을 수 없습니다." << std::endl;
    }
}

void Player::unequipItem(const std::string& itemName)
{
    if (equippedWeapon && equippedWeapon->getName() == itemName)
    {
        attack -= equippedWeapon->getAttack();
        addItemToInventory(equippedWeapon);
        equippedWeapon = nullptr;
        std::cout << itemName << "을(를) 탈착했습니다." << std::endl;
    }
    else if (equippedArmor && equippedArmor->getName() == itemName)
    {
        defense -= equippedArmor->getDefense();
        addItemToInventory(equippedArmor);
        equippedArmor = nullptr;
        std::cout << itemName << "을(를) 탈착했습니다." << std::endl;
    }
    else
    {
        std::cout << "해당 아이템을 장착하고 있지 않습니다." << std::endl;
    }
}

void Player::displayEquippedItems() const
{
    if (equippedWeapon)
    {
        std::cout << "장착 중인 무기: " << equippedWeapon->getName() << std::endl;
    }
    if (equippedArmor)
    {
        std::cout << "장착 중인 방어구: " << equippedArmor->getName() << std::endl;
    }
    if (!equippedWeapon && !equippedArmor)
    {
        std::cout << "현재 장착 중인 아이템이 없습니다." << std::endl;
    }
}

void Player::displayStatus() const
{
    std::cout << "이름: " << name <<std::endl;
    std::cout << "소지금: " << gold << " 골드" << std::endl;
    std::cout << "공격력: " << attack << std::endl;
    std::cout << "방어력: " << defense << std::endl;
    if (equippedWeapon)
    {
        std::cout << "장착 중인 무기: " << equippedWeapon->getName() <<std::endl;
    }
    if (equippedArmor)
    {
        std::cout << "장착 중인 방어구: " << equippedArmor->getName() << std::endl;
    }
    std::cout << "==========================" << std::endl;
}
