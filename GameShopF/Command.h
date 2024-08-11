#pragma once
#include "Player.h"
#include "Shop.h"

class Command
{
private:
    Player* player;
    Shop* shop;

    void initializeItems(); // ������ �ʱ�ȭ �޼���

public:
    Command();
    ~Command();


    void startGame();
};
