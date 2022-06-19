#include "BattleScene.h"

void BattleScene(Player& player, Monster& monster, Battle& battle)
{
	int input = 0;
	int stunCheck = 0;

	while (1)
	{
		battle.Fild(player, monster);
		cin >> input;

		switch (input)
		{
		case 1:
			if (player._isStun)
			{
				++stunCheck;
				if (stunCheck == 3)
				{
					player._isStun = false;
					stunCheck = 0;
				}
				cout << "���ϻ��¶� ������ �� �����ϴ�.\n";
				Sleep(1000);
				cout << "������ ����! ü���� " << monster._power - player._defense << "��ŭ �����մϴ�.\n";
				player._health -= monster._power - player._defense;
				Sleep(1000);
			}
			else
			{
				cout << "�÷��̾��� ����! ������ ü���� " << player._power << "��ŭ �����մϴ�.\n\n";
				monster._health -= player._power;
				Sleep(1000);
				if (monster._health > 0)
				{
					cout << "������ ����! ü���� " << monster._power - player._defense << "��ŭ �����մϴ�.\n";
					player._health -= monster._power - player._defense;
					Sleep(1000);
				}
			}
			break;
		case 2:
			if (player._isStun)
			{
				++stunCheck;
				if (stunCheck == 3)
				{
					player._isStun = false;
					stunCheck = 0;
				}
				cout << "���ϻ��¶� ������ �� �����ϴ�.\n";
				Sleep(1000);
				cout << "������ ����! ü���� " << monster._power - player._defense << "��ŭ �����մϴ�.\n";
				player._health -= monster._power - player._defense;
				Sleep(1000);
			}
			else
			{
				int skillFactor;
				skillFactor = rand() % 3 + 3;
				cout << "�÷��̾��� ��ų!!! ������ ü���� " << player._power * skillFactor << "��ŭ �����մϴ�.\n\n";
				monster._health -= player._power * skillFactor;
				player._stamina += (15 * skillFactor);

				if (player._stamina >= 100)
				{
					cout << "�Ƿε��� �����Ǿ� ���ϻ��¿� �����ϴ�. �÷��̾�� ���ϵ��� ������ �� �����ϴ�.\n";
					player._isStun = true;
					player._stamina -= 100;
				}
				Sleep(1000);

				if (monster._health > 0)
				{
					cout << "������ ����! ü���� " << monster._power - player._defense << "��ŭ �����մϴ�.\n";
					player._health -= monster._power - player._defense;
					Sleep(1000);
				}
			}
			break;
		case 3:
			player.UsePotion();
			Sleep(1000);
			break;
		case 4:
			cout << "������!\n";
			Sleep(1000);
			break;
		}

		if (input == 4)
		{
			break;
		}

		if (battle.isMonsterDead(monster))
		{
			cout << "���͸� ��ҽ��ϴ�. ���Ƿ� ���ư��ϴ�.\n";
			player.GetEXP(monster._dropExp);
			player._holedGold += monster._dropGold;
			player._isStun = false;
			Sleep(1000);
			break;
		}

		if (battle.isPlayerDead(player))
		{
			cout << "\n\n\tY O U    D I E\n";
			exit(1);
		}
	}
}