#pragma once

#include "Common.h"

class Player
{

public: // �⺻�޼ҵ� ����
	Player() = default;
	~Player() = default;
	Player(const Player& other) = delete;
	Player& operator=(const Player& other) = delete;

public:

	void Setting() // �÷��̾� ����
	{
		_health = _maxHP;
	}

	// �÷��̾� �������ͽ� �⺻���
	void PrintNormalStatus()
	{
		// ����ġ �䱸����
		const int requestEXP[5] = { 100, 200,300,400,500 };
		while (1)
		{
			int input;
			system("cls");
			cout << "��������������������������\n";
			cout << "��  �� ����  ��\n";
			cout << "��������������������������\n";
			cout << "* ���� : " << _level << "\n";
			cout << "* ���ݷ� : " << _power << "\n";
			cout << "* ���� : " << _defense << "\n";
			cout << "* ü�� : " << _health << " / " << _maxHP << "\n";
			cout << "* �Ƿε� : " << _stamina << " / " << _maxStamina << "\n";
			cout << "* ����ġ : " << _exp << " / " << requestEXP[_levelSection] << "\n";
			cout << "* ������� : " << _holedGold << "G\n";
			cout << "* �������� : " << _holedPostion << "��\n\n";
			cout << "* 1. ���ư���\n";
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

	// �÷��̾� �������ͽ� �������� ���
	void PrintBatlleStatus()
	{
		system("cls");
		cout << "��������������������������\n";
		cout << "��  �� ����  ��\n";
		cout << "��������������������������\n";
		cout << "* ���ݷ� : " << _power << "\n";
		cout << "* ���� : " << _defense << "\n";
		cout << "* ü�� : " << _health << " / " << _maxHP << "\n";
		cout << "* �Ƿε� : " << _stamina << " / " << _maxStamina << "\n";
		cout << "* �������� : " << _holedPostion << "��\n\n";
	}
	
	// ����ġ ȹ��� ó�� �� ������ ó��
	void GetEXP(int getExp)
	{
		// ����ġ �䱸����
		const int requestEXP[5] = { 100, 200, 300, 400, 500 };
		_exp += getExp;

		while (_exp >= requestEXP[_levelSection])
		{
			cout << "������!!!\n";
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

	// ���Ϳ��� �޽�
	void Relex()
	{
		for (int i = 0; i < 3; ++i)
		{
			system("cls");
			cout << "\n\n\t";
			switch (i)
			{
			case 0:
				cout << "�� �� �� .";
				break;
			case 1:
				cout << "�� �� �� . .";
				break;
			case 2:
				cout << "�� �� �� . . .";
				break;
			}
			Sleep(500);
		}
		_health = _maxHP;
		_stamina = 0;
	}

	// ���� ���
	void UsePotion()
	{
		if (_holedPostion >= 1)
		{
			cout << "������ ����߽��ϴ�. ü��ȸ�� / �Ƿε� ����!\n";
			_health = _maxHP;
			_stamina = 0;
			--_holedPostion;
		}

		else
		{
			cout << "������ �����ϴ�.\n";
		}
	}

	// �ִ뷹�� ���޽� ���� ��
	bool isGameEnd()
	{
		if (_isMaxLevel)
		{
			return true;
		}

		return false;
	}


public : // �ܺο��� ó���� �ؾ��� �ʵ�
	int				_health = 0;
	int				_stamina = 0;
	int				_holedGold = 0;
	int				_holedPostion = 0;
	int				_power = 30;
	int				_defense = 0;
	int				_level = 1;
	bool			_isStun = false;

private: // Ŭ���� ���ο��� ó���ϴ� �ʵ�
	int				_maxHP = 100;
	const int		_maxStamina = 100;
	int				_levelSection = 0;
	int				_exp = 0;
	bool			_isMaxLevel = false;
};