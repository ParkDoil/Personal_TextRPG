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
			cout << "* ����ġ : " << _exp << " / " << _requestEXP[_levelSection] << "\n";
			cout << "* ������� : " << _holedGold << "G\n";
			cout << "* �������� : " << _holedPostion << "��\n\n";
			cout << "* 1. ���ư���\n";
			cout << "_ ";
			
			cin >> input;
			if (input == 1)
			{
				break;
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
		cout << "* ����ġ : " << _exp << " / " << _requestEXP[_levelSection] << "\n";
		cout << "* �Ƿε� : " << _stamina << " / " << _maxStamina << "\n";
		cout << "* �������� : " << _holedPostion << "��\n\n";
	}
	
	// ����ġ ȹ��� ó�� �� ������ ó��
	void GetEXP(int getExp)
	{
		_exp += getExp;

		while (_exp >= _requestEXP[_levelSection])
		{
			cout << "������!!!\n";
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

	void PrintSkill()
	{
		cout << "1. ���� ���� (���ݷ��� 2~3���� �������� �����ϴ�.) / �Ƿε� 20���\n";
		cout << "2. �޼� ���� (���ݷ��� 3~5���� �������� �����ϴ�.) / �Ƿε� 40���\n";
		cout << "3. �ʻ��� �ϰ�  (���ݷ��� 5~7���� �������� �����ϴ�.) / �Ƿε� 60���\n";
		cout << "4. ��ź�� �Ѿ� (���ݷ��� 10���� �������� �����ϴ�.) / �Ƿε� 99��� �� 1/7Ȯ���� ü�� 1\n";
		cout << "��ź�� �Ѿ��� �����ϰ� ����ϼ���.\n";
		cout << "����� ��ų�� �Է��ϼ���.\n";
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
			cout << "\n�÷��̾��� ���Ѱ���!!! ������ ü���� " << _power * skillFactor << "��ŭ �����մϴ�.\n\n";
			_stamina += 20;
			break;

		case 2:
			skillFactor = rand() % 3 + 3;
			cout << "\n�÷��̾��� �޼� ����!!! ������ ü���� " << _power * skillFactor << "��ŭ �����մϴ�.\n\n";
			_stamina += 40;
			break;

		case 3:
			skillFactor = rand() % 3 + 5;
			cout << "\n�÷��̾��� �ʻ��� �ϰ�!!! ������ ü���� " << _power * skillFactor << "��ŭ �����մϴ�.\n\n";
			_stamina += 60;
			break;

		case 4:
			debuff = rand() % 7 + 1;
			skillFactor = 10;
			cout << "\n�÷��̾��� ��ź�� �Ѿ�!!! ������ ü���� " << _power * skillFactor << "��ŭ �����մϴ�.\n\n";
			_stamina += 99;
			if (debuff == 7)
			{
				cout << "��ź�� �Ѿ� ���ۿ����� ü���� 1�� �˴ϴ�.\n";
				_health = 1;
			}
			break;
		}

		return (_power * skillFactor);
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
	int				_health = 0; // ���� ü��
	int				_stamina = 0; // ���� �Ƿε�
	int				_holedGold = 0; // ���� ���
	int				_holedPostion = 0; // ���� ����
	int				_power = 30; // ���ݷ�
	int				_defense = 0; // ����
	int				_level = 1; // ����
	bool			_isStun = false; // ���ϻ����ΰ�

private: // Ŭ���� ���ο��� ó���ϴ� �ʵ�
	int				_maxHP = 100; // �ִ�ü��
	const int		_maxStamina = 100; // �Ѱ��Ƿε�
	int				_levelSection = 0; // ��������
	int				_exp = 0; // ���� ����ġ
	bool			_isMaxLevel = false; // �ִ뷹���ΰ�
	const int		_requestEXP[5] = { 150, 300, 450, 600, 750 }; // ����ġ �䱸����
};