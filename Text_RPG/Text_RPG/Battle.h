#pragma once

#include "Common.h"
#include "Player.h"
#include "Monster.h"

class Battle
{
public: // 기본 메소드 섹션
	Battle() = default;
	~Battle() = default;
	Battle(const Battle& other) = delete;
	Battle& operator=(const Battle& other) = delete;

public:
	void Fild(Player& player, Monster& monster)
	{
		system("cls");
		player.PrintBatlleStatus();
		monster.PrintBattleStatus();
	}

	bool isPlayerDead(Player& player)
	{
		if (player._health <= 0)
		{
			return true;
		}
		return false;
	}

	bool isMonsterDead(Monster& monster)
	{
		if(monster._health <= 0)
		{
			return true;
		}
		return false;
	}

};