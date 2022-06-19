#pragma once

#include "Common.h"

class Player
{

public: // 기본메소드 섹션
	Player() = default;
	~Player() = default;
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;

public:

	void Setting() // 플레이어 세팅
	{
		_health = _maxHP;
	}

	// 플레이어 스테이터스 기본출력
	void PrintNormalStatus()
	{
		// 경험치 요구사항
		const int requestEXP[5] = { 100, 200,300,400,500 };
		while (1)
		{
			int input;
			system("cls");
			cout << "┌───────────┐\n";
			cout << "│  내 정보  │\n";
			cout << "└───────────┘\n";
			cout << "* 레벨 : " << _level << "\n";
			cout << "* 공격력 : " << _power << "\n";
			cout << "* 방어력 : " << _defense << "\n";
			cout << "* 체력 : " << _health << " / " << _maxHP << "\n";
			cout << "* 피로도 : " << _stamina << " / " << _maxStamina << "\n";
			cout << "* 경험치 : " << _exp << " / " << requestEXP[_levelSection] << "\n";
			cout << "* 소지골드 : " << _holedGold << "G\n";
			cout << "* 소지포션 : " << _holedPostion << "개\n\n";
			cout << "* 1. 돌아가기\n";
			cout << "_ ";
			
			cin >> input;
			if (input == 1)
			{
				break;
			}
			if (input == 2)
			{
				_health  -= 20;
				_stamina += 10;
			}
		}
	}

	// 플레이어 스테이터스 전투상태 출력
	void PrintBatlleStatus()
	{
		system("cls");
		cout << "┌───────────┐\n";
		cout << "│  내 정보  │\n";
		cout << "└───────────┘\n";
		cout << "* 공격력 : " << _power << "\n";
		cout << "* 방어력 : " << _defense << "\n";
		cout << "* 체력 : " << _health << " / " << _maxHP << "\n";
		cout << "* 피로도 : " << _stamina << " / " << _maxStamina << "\n";
		cout << "* 소지포션 : " << _holedPostion << "개\n\n";
	}
	
	// 경험치 획득시 처리 및 레벨업 처리
	void GetEXP(int getExp)
	{
		// 경험치 요구사항
		const int requestEXP[5] = { 100, 200, 300, 400, 500 };
		_exp += getExp;

		while (_exp >= requestEXP[_levelSection])
		{
			cout << "레벨업!!!\n";
			Sleep(500);
			++_level;
			_power += 5;
			_defense += 1;
			_maxHP += 10;
			_health = _maxHP;
			_stamina = 0;
			_exp -= requestEXP[_levelSection];
		}

		if (_level >= 1 && _level <= 10)
		{
			_levelSection = 0;
			return;
		}

		else if (_level >= 11 && _level <= 20)
		{
			_levelSection = 1;
			return;
		}

		else if (_level >= 21 && _level <= 30)
		{
			_levelSection = 2;
			return;
		}

		else if (_level >= 31 && _level <= 40)
		{
			_levelSection = 3;
			return;
		}

		else if (_level >= 41 && _level <= 49)
		{
			_levelSection = 4;
			return;
		}

		if (_level == 50)
		{
			_isMaxLevel = true;

			return;
		}
	}

	// 쉼터에서 휴식
	void Relex()
	{
		for (int i = 0; i < 3; ++i)
		{
			system("cls");
			cout << "\n\n\t";
			switch (i)
			{
			case 0:
				cout << "휴 식 중 .";
				break;
			case 1:
				cout << "휴 식 중 . .";
				break;
			case 2:
				cout << "휴 식 중 . . .";
				break;
			}
			Sleep(500);
		}
		_health = _maxHP;
		_stamina = 0;
	}

	// 포션 사용
	void UsePotion()
	{
		if (_holedPostion >= 1)
		{
			cout << "포션을 사용했습니다. 체력회복 / 피로도 감소!\n";
			_health = _maxHP;
			_stamina = 0;
			--_holedPostion;
		}

		else
		{
			cout << "포션이 없습니다.\n";
		}
	}

	// 최대레벨 도달시 게임 끝
	bool isGameEnd()
	{
		if (_isMaxLevel)
		{
			return true;
		}

		return false;
	}


public : // 외부에서 처리를 해야할 필드
	int				_health = 0;
	int				_stamina = 0;
	int				_holedGold = 0;
	int				_holedPostion = 0;
	int				_power = 30;
	int				_defense = 0;
	int				_level = 1;
	bool			_isStun = false;

private: // 클래스 내부에서 처리하는 필드
	int				_maxHP = 100;
	const int		_maxStamina = 100;
	int				_levelSection = 0;
	int				_exp = 0;
	bool			_isMaxLevel = false;
};