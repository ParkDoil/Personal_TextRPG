#include "BattleScene.h"

void BattleScene(Player& player, Monster& monster, Battle& battle)
{
	int input = 0;
	int sturnTime = 3; // ���Ͻð�

	while (1)
	{
		battle.Fild(player, monster);

		if (player._stamina >= 100)
		{
			cout << "\n �Ƿε� ���������Դϴ�. ������ 3�� ���ϻ��¿� �����մϴ�.\n";
			cout << "_ ";
		}

		cin >> input;

		switch (input)
		{
		case 1:
			if (player._isStun)
			{
				--sturnTime;
				if (sturnTime == 0)
				{
					player._isStun = false;
					sturnTime = 3;
				}
				cout << "\n���ϻ��¶� ������ �� �����ϴ�.\n";
				Sleep(1000);
				cout << "������ ����! ü���� " << monster._power - player._defense << "��ŭ �����մϴ�.\n";
				player._health -= monster._power - player._defense;
				Sleep(1000);
			}
			else
			{
				cout << "\n�÷��̾��� ����! ������ ü���� " << player._power << "��ŭ �����մϴ�.\n\n";
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
				--sturnTime;
				if (sturnTime == 0)
				{
					player._isStun = false;
					sturnTime = 3;
				}
				cout << "\n���ϻ��¶� ������ �� �����ϴ�.\n";
				Sleep(1000);
				cout << "������ ����! ü���� " << monster._power - player._defense << "��ŭ �����մϴ�.\n";
				player._health -= monster._power - player._defense;
				Sleep(1000);
			}
			else
			{
				int skillnum;
				player.PrintSkill();
				cin >> skillnum;
				int damage = player.UseSkill(skillnum);
				monster._health -= damage;

				Sleep(1000);

				if (player._stamina >= 100 && !battle.isMonsterDead(monster))
				{
					cout << "�Ƿε��� �����Ǿ� ���ϻ��¿� �����ϴ�. �÷��̾�� 3�ϵ��� ������ �� �����ϴ�.\n";
					player._isStun = true;
					player._stamina -= 100;
					Sleep(1000);
				}

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
			cout << "\n������!\n";
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