#pragma once

#include "Common.h"
#include "Player.h"

class Shelter
{
public: // �⺻ �޼ҵ� ����
	Shelter() = default;
	~Shelter() = default;
	Shelter(const Shelter& other) = delete;
	Shelter& operator=(const Shelter & other) = delete;

public:
	// ���� �⺻ ���ȭ��
	void PrintBasic(Player& player)
	{
		bool isExitShelter = false;
		while (!isExitShelter)
		{
			int input;
			system("cls");
			cout << "��������������������������\n";
			cout << "��  ��   ��  ��\n";
			cout << "��������������������������\n";
			cout << "* �޽��� ü���� ȸ����Ű�� �Ƿε��� ���ҽ�ŵ�ϴ�.\n";
			cout << "1. �޽� / 2. ���� ���� / 3. ���ư���\n";
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

	// ���Ǳ���
	void BuyPotion(Player& player)
	{
		while (1)
		{
			system("cls");
			int input;
			cout << "������ ������ ������ �Է��ϼ���(���� 10G)\n";
			cout << "���� �÷��̾��� ���� ��� : " << player._holedGold << "G\n";
			cout << "������ �������� �������� 0 �Է�\n";
			cout << "_ ";

			cin >> input;
			if (input == 0)
			{
				break;
			}

			if ((10 * input > player._holedGold))
			{
				cout << "��尡 ���ڶ��ϴ�.";
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