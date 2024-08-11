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
            std::cout << itemName << "��(��) �����߽��ϴ�." <<std::endl;
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
            std::cout << itemName << "��(��) �����߽��ϴ�." << std::endl;
        }
    }
    else
    {
        std::cout << "�������� ã�� �� �����ϴ�." << std::endl;
    }
}

void Player::unequipItem(const std::string& itemName)
{
    if (equippedWeapon && equippedWeapon->getName() == itemName)
    {
        attack -= equippedWeapon->getAttack();
        addItemToInventory(equippedWeapon);
        equippedWeapon = nullptr;
        std::cout << itemName << "��(��) Ż���߽��ϴ�." << std::endl;
    }
    else if (equippedArmor && equippedArmor->getName() == itemName)
    {
        defense -= equippedArmor->getDefense();
        addItemToInventory(equippedArmor);
        equippedArmor = nullptr;
        std::cout << itemName << "��(��) Ż���߽��ϴ�." << std::endl;
    }
    else
    {
        std::cout << "�ش� �������� �����ϰ� ���� �ʽ��ϴ�." << std::endl;
    }
}

void Player::displayEquippedItems() const
{
    if (equippedWeapon)
    {
        std::cout << "���� ���� ����: " << equippedWeapon->getName() << std::endl;
    }
    if (equippedArmor)
    {
        std::cout << "���� ���� ��: " << equippedArmor->getName() << std::endl;
    }
    if (!equippedWeapon && !equippedArmor)
    {
        std::cout << "���� ���� ���� �������� �����ϴ�." << std::endl;
    }
}

void Player::displayStatus() const
{
    std::cout << "�̸�: " << name <<std::endl;
    std::cout << "������: " << gold << " ���" << std::endl;
    std::cout << "���ݷ�: " << attack << std::endl;
    std::cout << "����: " << defense << std::endl;
    if (equippedWeapon)
    {
        std::cout << "���� ���� ����: " << equippedWeapon->getName() <<std::endl;
    }
    if (equippedArmor)
    {
        std::cout << "���� ���� ��: " << equippedArmor->getName() << std::endl;
    }
    std::cout << "==========================" << std::endl;
}
