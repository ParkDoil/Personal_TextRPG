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
				cout << "스턴상태라서 공격할 수 없습니다.\n";
				Sleep(1000);
				cout << "몬스터의 공격! 체력이 " << monster._power - player._defense << "만큼 감소합니다.\n";
				player._health -= monster._power - player._defense;
				Sleep(1000);
			}
			else
			{
				cout << "플레이어의 공격! 몬스터의 체력이 " << player._power << "만큼 감소합니다.\n\n";
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
				++stunCheck;
				if (stunCheck == 3)
				{
					player._isStun = false;
					stunCheck = 0;
				}
				cout << "스턴상태라서 공격할 수 없습니다.\n";
				Sleep(1000);
				cout << "몬스터의 공격! 체력이 " << monster._power - player._defense << "만큼 감소합니다.\n";
				player._health -= monster._power - player._defense;
				Sleep(1000);
			}
			else
			{
				int skillFactor;
				skillFactor = rand() % 3 + 3;
				cout << "플레이어의 스킬!!! 몬스터의 체력이 " << player._power * skillFactor << "만큼 감소합니다.\n\n";
				monster._health -= player._power * skillFactor;
				player._stamina += (15 * skillFactor);

				if (player._stamina >= 100)
				{
					cout << "피로도가 누적되어 스턴상태에 빠집니다. 플레이어는 몇턴동안 공격할 수 없습니다.\n";
					player._isStun = true;
					player._stamina -= 100;
				}
				Sleep(1000);

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
			cout << "빤스런!\n";
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