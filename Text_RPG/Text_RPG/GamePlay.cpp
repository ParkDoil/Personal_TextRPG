#include "GamePlay.h"
#include "GameInfoPrint.h"
#include "BattleScene.h"

void GamePlay()
{
	Player player;
	Shelter shelter;
	Battle battle;

	player.Setting();
	while (1)
	{
		if (player.isGameEnd())
		{
			cout << "\n\n�ְ��� �޼�. �¸� ������ �����߽��ϴ�.\n";
			cout << "\t Y O U    W I N\n";
			break;
		}

		int input;
		input = PrintMainScreen();
		switch (input)
		{
		case 1:
			player.PrintNormalStatus();
			break;
		case 2:
			shelter.PrintBasic(player);
			break;
		case 3:
			Monster monster;
			monster.Setting(player);
			BattleScene(player, monster, battle);

			break;
		}
	}
}