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
			cout << "* 경험치 : " << _exp << " / " << _requestEXP[_levelSection] << "\n";
			cout << "* 소지골드 : " << _holedGold << "G\n";
			cout << "* 소지포션 : " << _holedPostion << "개\n\n";
			cout << "* 1. 돌아가기\n";
			cout << "_ ";
			
			cin >> input;
			if (input == 1)
			{
				break;
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
		cout << "* 경험치 : " << _exp << " / " << _requestEXP[_levelSection] << "\n";
		cout << "* 피로도 : " << _stamina << " / " << _maxStamina << "\n";
		cout << "* 소지포션 : " << _holedPostion << "개\n\n";
	}
	
	// 경험치 획득시 처리 및 레벨업 처리
	void GetEXP(int getExp)
	{
		_exp += getExp;

		while (_exp >= _requestEXP[_levelSection])
		{
			cout << "레벨업!!!\n";
			Sleep(500);
			++_level;
			_power += 5;
			_defense += 1;
			_maxHP += 10;
			_health = _maxHP;
			_stamina = 0;
			_exp -= _requestEXP[_levelSection];
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

	void PrintSkill()
	{
		cout << "1. 강한 공격 (공격력의 2~3배의 데미지를 입힙니다.) / 피로도 20상승\n";
		cout << "2. 급소 공격 (공격력의 3~5배의 데미지를 입힙니다.) / 피로도 40상승\n";
		cout << "3. 필사의 일격  (공격력의 5~7배의 데미지를 입힙니다.) / 피로도 60상승\n";
		cout << "4. 마탄의 총알 (공격력의 10배의 데미지를 입힙니다.) / 피로도 99상승 및 1/7확률로 체력 1\n";
		cout << "마탄의 총알은 신중하게 사용하세요.\n";
		cout << "사용할 스킬을 입력하세요.\n";
		cout << "_ ";
	}

	int UseSkill(int skillnum)
	{
		int skillFactor = 0;
		int debuff;
		switch (skillnum)
		{
		case 1:
			skillFactor = rand() % 2 + 2;
			cout << "\n플레이어의 강한공격!!! 몬스터의 체력이 " << _power * skillFactor << "만큼 감소합니다.\n\n";
			_stamina += 20;
			break;

		case 2:
			skillFactor = rand() % 3 + 3;
			cout << "\n플레이어의 급소 공격!!! 몬스터의 체력이 " << _power * skillFactor << "만큼 감소합니다.\n\n";
			_stamina += 40;
			break;

		case 3:
			skillFactor = rand() % 3 + 5;
			cout << "\n플레이어의 필사의 일격!!! 몬스터의 체력이 " << _power * skillFactor << "만큼 감소합니다.\n\n";
			_stamina += 60;
			break;

		case 4:
			debuff = rand() % 7 + 1;
			skillFactor = 10;
			cout << "\n플레이어의 마탄의 총알!!! 몬스터의 체력이 " << _power * skillFactor << "만큼 감소합니다.\n\n";
			_stamina += 99;
			if (debuff == 7)
			{
				cout << "마탄의 총알 부작용으로 체력이 1이 됩니다.\n";
				_health = 1;
			}
			break;
		}

		return (_power * skillFactor);
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
	int				_health = 0; // 현재 체력
	int				_stamina = 0; // 현재 피로도
	int				_holedGold = 0; // 소지 골드
	int				_holedPostion = 0; // 소지 물약
	int				_power = 30; // 공격력
	int				_defense = 0; // 방어력
	int				_level = 1; // 레벨
	bool			_isStun = false; // 스턴상태인가

private: // 클래스 내부에서 처리하는 필드
	int				_maxHP = 100; // 최대체력
	const int		_maxStamina = 100; // 한계피로도
	int				_levelSection = 0; // 레벨구간
	int				_exp = 0; // 현재 경험치
	bool			_isMaxLevel = false; // 최대레벨인가
	const int		_requestEXP[5] = { 150, 300, 450, 600, 750 }; // 경험치 요구사항
};