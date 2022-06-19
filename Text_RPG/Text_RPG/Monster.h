#pragma once

#include "Common.h"
#include "Player.h"

class Monster
{
public: // �⺻ �޼ҵ� ����
	Monster() = default;
	~Monster() = default;
	Monster(const Monster& other) = delete;
	Monster& operator=(const Monster& other) = delete;

public:
	void Setting(Player& player)
	{
		// ���� �ִ� ü���� �÷��̾� ���ݷ��� 5~15��
		_maxHP = player._power * (rand() % 11 + 5);
		// ���� ���ݷ��� �÷��̾� ���� + ���� 1~10
		_power = player._level + (rand() % 10 + 1);
		_health = _maxHP;
		// ���� ����ġ�� ü���� 30% + ���ݷ��� 50%
		_dropExp = (_health / 3) + (_power / 2);
		// ���� ������� ����ġ�� ����
		_dropGold = _dropExp / 2;
	}

	void PrintBattleStatus()
	{
		cout << "��������������������������\n";
		cout << "������ ������\n";
		cout << "��������������������������\n";
		cout << "* ���ݷ� : " << _power << "\n";
		cout << "* ü�� : " << _health << " / " << _maxHP << "\n";
		cout << "* �������ġ : " << _dropExp << "\n";
		cout << "* ������ : " << _dropGold << "G\n\n";
		cout << "1. ���� / 2. ��ų / 3. ���� ��� / 4. ����\n";
		cout << "_ ";
	}

public: // �ܺο��� ó���� �ʵ�
	int				_health = 0;
	int				_dropGold = 0;
	int				_dropExp = 0;
	int				_power = 0;

private: // Ŭ���� ���ο��� �����ϴ� �ʵ�
	int				_maxHP = 0;

};