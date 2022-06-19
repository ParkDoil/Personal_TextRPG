#pragma once

#include "Common.h"
#include "Player.h"

class Shelter
{
public: // 기본 메소드 섹션
	Shelter() = default;
	~Shelter() = default;
	Shelter(const Shelter& other) = delete;
	Shelter& operator=(const Shelter & other) = delete;

public:
	// 쉼터 기본 출력화면
	void PrintBasic(Player& player)
	{
		bool isExitShelter = false;
		while (!isExitShelter)
		{
			int input;
			system("cls");
			cout << "┌───────────┐\n";
			cout << "│  쉼   터  │\n";
			cout << "└───────────┘\n";
			cout << "* 휴식은 체력을 회복시키며 피로도를 감소시킵니다.\n";
			cout << "1. 휴식 / 2. 포션 구매 / 3. 돌아가기\n";
			cout << "_ ";

			cin >> input;

			switch (input)
			{
			case 1:
				player.Relex();
				break;
			case 2:
				BuyPotion(player);
				break;
			case 3:
				isExitShelter = true;
				break;
			}
		}
	}

	// 포션구매
	void BuyPotion(Player& player)
	{
		while (1)
		{
			system("cls");
			int input;
			cout << "구매할 포션을 개수를 입력하세요(개당 10G)\n";
			cout << "현재 플레이어의 소지 골드 : " << player._holedGold << "G\n";
			cout << "포션을 구매하지 않으려면 0 입력\n";
			cout << "_ ";

			cin >> input;
			if (input == 0)
			{
				break;
			}

			if ((10 * input > player._holedGold))
			{
				cout << "골드가 모자랍니다.";
				Sleep(500);
			}
			else
			{
				player._holedGold -= (10 * input);
				player._holedPostion += input;
				break;
			}
		}
	}

};