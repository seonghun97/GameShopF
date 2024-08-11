#include "Command.h"
#include <iostream>

Command::Command() {
    player = new Player("���");
    shop = new Shop();
    initializeItems(); // ������ �ʱ�ȭ
}

Command::~Command() {
    delete player;
    delete shop;
}

void Command::initializeItems()
{
    // �����۵��� �����ϰ� ������ �߰�
    shop->addItem(new Item("���", "Weapon", 500, 30, 0, 2));
    shop->addItem(new Item("�ܰ�", "Weapon", 300, 20, 0, 2));
    shop->addItem(new Item("����", "Armor", 200, 0, 15, 2));
    shop->addItem(new Item("����", "Armor", 150, 0, 10, 2));
}

void Command::startGame() {
    std::string choice;

    while (true) {
        std::cout << "1. ������ ����\n";
        std::cout << "2. �κ��丮�� Ȯ���Ѵ�\n";
        std::cout << "3. �� ������ Ȯ���Ѵ�\n";
        std::cout << "4. ������ �����Ѵ�\n";
        std::cout << "����: ";
        std::cin >> choice;

        if (choice == "1")
        {
            shop->displayItems();
            std::cout << "�����Ϸ��� (b)��, �Ǹ��Ϸ��� (s)�� �Է��ϼ���: ";
            std::cin >> choice;
            if (choice == "b")
            {
                std::cout << "������ ������ �̸��� �Է��ϼ���: ";
                std::cin.ignore();
                std::getline(std::cin, choice);
                Item* item = shop->findItemByName(choice);
                if (item)
                {
                    shop->buyItem(player, item);
                }
                else
                {
                    std::cout << "�������� ã�� �� �����ϴ�.\n";
                }
            }
            else if (choice == "s")
            {
                player->displayInventory();  // �κ��丮 ���
                std::cout << "�Ǹ��� ������ �̸��� �Է��ϼ���: ";
                std::cin.ignore();
                std::getline(std::cin, choice);
                shop->sellItem(player, choice);
            }
        }
        else if (choice == "2")
        {
            std::cout << "�κ��丮:" << std::endl;
            player->displayInventory();  // �κ��丮 ���

            std::cout << "1. ���� 2. Ż��" << std::endl;;
            std::cout << "����: ";
            std::cin >> choice;

            if (choice == "1")
            {
                std::cout << "������ ������ �̸��� �Է��ϼ���: ";
                std::cin.ignore();
                std::getline(std::cin, choice);
                player->equipItem(choice);
            }
            else if (choice == "2")
            {
                std::cout << "���� ������ ������ �̸��� �Է��ϼ���: ";
                std::cin.ignore();
                std::getline(std::cin, choice);
                player->unequipItem(choice);
            }


        }
        else if (choice == "3")
        {
            player->displayStatus();  // �÷��̾� ���� ���
        }
        else if (choice == "4")
        {
            std::cout << "������ �����մϴ�...\n";
            break;
        }
        else
        {
            std::cout << "�߸��� �����Դϴ�! �ٽ� �Է����ּ���.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
