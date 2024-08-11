#pragma once
#include <string>

class Item
{
private:
    std::string name;
    std::string type; // ���� �Ǵ� ��
    int price;
    int attack;
    int defense;
    int quantity; //���� 2�ΰ����Ұ���


public:
    Item(std::string name, std::string type, int price, int attack, int defense, int quantity)
        : name(name), type(type), price(price), attack(attack), defense(defense), quantity(quantity) {}

    std::string getName() const
    {
        return name;
    }
    std::string getType() const
    {
        return type;
    }
    int getPrice() const
    {
        return price;
    }
    int getAttack() const
    {
        return attack;
    }
    int getDefense() const
    {
        return defense;
    }

    int getQuantity() const
    {
        return quantity;
    }
    void reduceQuantity()
    {
        if (quantity > 0) quantity--;
    }
    void increaseQuantity()
    {
        quantity++;
    }
};
