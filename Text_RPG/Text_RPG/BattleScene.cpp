#include "BattleScene.h"

void BattleScene(Player& player, Monster& monster, Battle& battle)
{
	int input = 0;
	int sturnTime = 3; // 스턴시간

	while (1)
	{
		battle.Fild(player, monster);

		if (player._stamina >= 100)
		{
			cout << "\n 피로도 누적상태입니다. 강제로 3턴 스턴상태에 돌입합니다.\n";
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
				cout << "\n스턴상태라서 공격할 수 없습니다.\n";
				Sleep(1000);
				cout << "몬스터의 공격! 체력이 " << monster._power - player._defense << "만큼 감소합니다.\n";
				player._health -= monster._power - player._defense;
				Sleep(1000);
			}
			else
			{
				cout << "\n플레이어의 공격! 몬스터의 체력이 " << player._power << "만큼 감소합니다.\n\n";
				monster._health -= player._power;
				Sleep(1000);
				if (monster._health > 0)
				{
					cout << "몬스터의 공격! 체력이 " << monster._power - player._defense << "만큼 감소합니다.\n";
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
				cout << "\n스턴상태라서 공격할 수 없습니다.\n";
				Sleep(1000);
				cout << "몬스터의 공격! 체력이 " << monster._power - player._defense << "만큼 감소합니다.\n";
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
					cout << "피로도가 누적되어 스턴상태에 빠집니다. 플레이어는 3턴동안 공격할 수 없습니다.\n";
					player._isStun = true;
					player._stamina -= 100;
					Sleep(1000);
				}

				if (monster._health > 0)
				{
					cout << "몬스터의 공격! 체력이 " << monster._power - player._defense << "만큼 감소합니다.\n";
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
			cout << "\n빤스런!\n";
			Sleep(1000);
			break;
		}

		if (input == 4)
		{
			break;
		}

		if (battle.isMonsterDead(monster))
		{
			cout << "몬스터를 잡았습니다. 대기실로 돌아갑니다.\n";
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