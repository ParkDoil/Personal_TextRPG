#include "GameInfoPrint.h"
#include "Common.h"

void PrintTitle()
{
	system("cls");
	cout << "���ǻ��� : BGM ���尡 Ů�ϴ�. �Ҹ��� �����ϰ� �÷��� ���ּ���.\n";
	cout << "����������������������������������\n";
	cout << "��  ����� ����  ��\n";
	cout << "����������������������������������\n";
	cout << "1. ���ӽ��� / 2. �÷��� ��� / 3. ���� ����\n";
	cout << "_ ";
}

int HowToPlay()
{
	while (1)
	{
		int input;
		system("cls");
		cout << "* �ش� ������ �÷��̾��� ü���� 0�� �Ǿ� �װų�,\n";
		cout << "* �÷��̾��� ������ 50�� �Ǹ� ������ ����˴ϴ�.\n\n";
		cout << "* �������� ��ų ���� ��ų�� ���� �Ƿε��� �����ϸ�,\n";
		cout << "* �Ƿε��� 100 �̻��� �� ��쿡 3�ϵ��� ���ϻ��¿� �����ϴ�.\n\n";
		cout << "* ���� ������ ������ �����Է����� �̷�� ���ϴ�.\n";
		cout << "* �׷� ��հ� �÷��� ���ֽñ� �ٶ��ϴ�.\n";
		cout << "1. ���ư��� / 2. ��������\n";
		cout << "_ ";

		cin >> input;

		if (input == 1 || input == 2)
		{
			return input;
		}

	}
}

int PrintMainScreen()
{
	while (1)
	{
		int input;
		system("cls");
		cout << "��������������������������������\n";
		cout << "��   ��    ��   ��\n";
		cout << "��������������������������������\n";
		cout << "1. �� ���� / 2. ���� / 3. ���� ���\n";
		cout << "_ ";

		cin >> input;

		if (input == 1 || input == 2 || input == 3)
		{
			return input;
		}
	}
}