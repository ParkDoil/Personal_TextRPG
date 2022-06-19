#pragma once

#include "Common.h"
#include "Player.h"

class Monster
{
public: // 기본 메소드 섹션
	Monster() = default;
	~Monster() = default;
	Monster(const Monster& other) = delete;
	Monster& operator=(const Monster& other) = delete;

public:
	void Setting(Player& player)
	{
		// 몬스터 최대 체력은 플레이어 공격력의 5~15배
		_maxHP = player._power * (rand() % 11 + 5);
		// 몬스터 공격력은 플레이어 레벨 + 랜덤 1~10
		_power = player._level + (rand() % 10 + 1);
		_health = _maxHP;
		// 몬스터 경험치는 체력의 30% + 공격력의 50%
		_dropExp = (_health / 3) + (_power / 2);
		// 몬스터 드랍골드는 경험치의 반절
		_dropGold = _dropExp / 2;
	}

	void PrintBattleStatus()
	{
		cout << "┌───────────┐\n";
		cout << "│몬스터 정보│\n";
		cout << "└───────────┘\n";
		cout << "* 공격력 : " << _power << "\n";
		cout << "* 체력 : " << _health << " / " << _maxHP << "\n";
		cout << "* 드랍경험치 : " << _dropExp << "\n";
		cout << "* 드랍골드 : " << _dropGold << "G\n\n";
		cout << "1. 공격 / 2. 스킬 / 3. 포션 사용 / 4. 도망\n";
		cout << "_ ";
	}

public: // 외부에서 처리할 필드
	int				_health = 0;
	int				_dropGold = 0;
	int				_dropExp = 0;
	int				_power = 0;

private: // 클래스 내부에서 관리하는 필드
	int				_maxHP = 0;

};