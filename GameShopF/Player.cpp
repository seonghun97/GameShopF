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
            std::cout << itemName << "��(��) �����߽��ϴ�.\n";
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
            std::cout << itemName << "��(��) �����߽��ϴ�.\n";
        }
    }
    else
    {
        std::cout << "�������� ã�� �� �����ϴ�.\n";
    }
}

void Player::unequipItem(const std::string& itemName)
{
    if (equippedWeapon && equippedWeapon->getName() == itemName)
    {
        attack -= equippedWeapon->getAttack();
        addItemToInventory(equippedWeapon);
        equippedWeapon = nullptr;
        std::cout << itemName << "��(��) Ż���߽��ϴ�.\n";
    }
    else if (equippedArmor && equippedArmor->getName() == itemName)
    {
        defense -= equippedArmor->getDefense();
        addItemToInventory(equippedArmor);
        equippedArmor = nullptr;
        std::cout << itemName << "��(��) Ż���߽��ϴ�.\n";
    }
    else
    {
        std::cout << "�ش� �������� �����ϰ� ���� �ʽ��ϴ�.\n";
    }
}

void Player::displayEquippedItems() const
{
    if (equippedWeapon)
    {
        std::cout << "���� ���� ����: " << equippedWeapon->getName() << "\n";
    }
    if (equippedArmor)
    {
        std::cout << "���� ���� ��: " << equippedArmor->getName() << "\n";
    }
    if (!equippedWeapon && !equippedArmor)
    {
        std::cout << "���� ���� ���� �������� �����ϴ�.\n";
    }
}

void Player::displayStatus() const
{
    std::cout << "�̸�: " << name << "\n";
    std::cout << "������: " << gold << " ���\n";
    std::cout << "���ݷ�: " << attack << "\n";
    std::cout << "����: " << defense << "\n";
    if (equippedWeapon)
    {
        std::cout << "���� ���� ����: " << equippedWeapon->getName() << "\n";
    }
    if (equippedArmor)
    {
        std::cout << "���� ���� ��: " << equippedArmor->getName() << "\n";
    }
    std::cout << "==========================\n";
}
