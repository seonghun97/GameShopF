#include "Command.h"
#include <iostream>

Command::Command() {
    player = new Player("용사");
    shop = new Shop();
    initializeItems(); // 아이템 초기화
}

Command::~Command() {
    delete player;
    delete shop;
}

void Command::initializeItems()
{
    // 아이템들을 생성하고 상점에 추가
    shop->addItem(new Item("장검", "Weapon", 500, 30, 0, 2));
    shop->addItem(new Item("단검", "Weapon", 300, 20, 0, 2));
    shop->addItem(new Item("방패", "Armor", 200, 0, 15, 2));
    shop->addItem(new Item("투구", "Armor", 150, 0, 10, 2));
}

void Command::startGame() {
    std::string choice;

    while (true) {
        std::cout << "1. 상점에 들어간다\n";
        std::cout << "2. 인벤토리를 확인한다\n";
        std::cout << "3. 내 정보를 확인한다\n";
        std::cout << "4. 게임을 종료한다\n";
        std::cout << "선택: ";
        std::cin >> choice;

        if (choice == "1")
        {
            shop->displayItems();
            std::cout << "구매하려면 (b)를, 판매하려면 (s)를 입력하세요: ";
            std::cin >> choice;
            if (choice == "b")
            {
                std::cout << "구매할 아이템 이름을 입력하세요: ";
                std::cin.ignore();
                std::getline(std::cin, choice);
                Item* item = shop->findItemByName(choice);
                if (item)
                {
                    shop->buyItem(player, item);
                }
                else
                {
                    std::cout << "아이템을 찾을 수 없습니다.\n";
                }
            }
            else if (choice == "s")
            {
                player->displayInventory();  // 인벤토리 출력
                std::cout << "판매할 아이템 이름을 입력하세요: ";
                std::cin.ignore();
                std::getline(std::cin, choice);
                shop->sellItem(player, choice);
            }
        }
        else if (choice == "2")
        {
            std::cout << "인벤토리:" << std::endl;
            player->displayInventory();  // 인벤토리 출력

            std::cout << "1. 장착 2. 탈착" << std::endl;;
            std::cout << "선택: ";
            std::cin >> choice;

            if (choice == "1")
            {
                std::cout << "장착할 아이템 이름을 입력하세요: ";
                std::cin.ignore();
                std::getline(std::cin, choice);
                player->equipItem(choice);
            }
            else if (choice == "2")
            {
                std::cout << "장착 해제할 아이템 이름을 입력하세요: ";
                std::cin.ignore();
                std::getline(std::cin, choice);
                player->unequipItem(choice);
            }


        }
        else if (choice == "3")
        {
            player->displayStatus();  // 플레이어 상태 출력
        }
        else if (choice == "4")
        {
            std::cout << "게임을 종료합니다...\n";
            break;
        }
        else
        {
            std::cout << "잘못된 선택입니다! 다시 입력해주세요.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
