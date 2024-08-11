#pragma once
#include "Player.h"
#include "Shop.h"

class Command
{
private:
    Player* player;
    Shop* shop;

    void initializeItems(); // 아이템 초기화 메서드

public:
    Command();
    ~Command();


    void startGame();
};
