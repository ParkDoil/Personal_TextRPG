#include "GamePlay.h"
#include "GameInfoPrint.h"

void GamePlay()
{
	Player player;
	Shelter shelter;

	player.Setting();
	while (1)
	{
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
			cout << "¹Ì±¸Çö";
			break;
		}
	}
}