#include "Common.h"
#pragma comment (lib, "winmm.lib")
#include <mmsystem.h>;

#include "GameInfoPrint.h"
#include "GamePlay.h"


int main()
{
	srand(time(NULL));
	PlaySound(TEXT("Leonhart.wav"), NULL, SND_ASYNC | SND_LOOP);
	
	int input = 0;
	bool isEnd = false;
	while (!isEnd)
	{
		PrintTitle();
		cin >> input;

		if (input == 1)
		{
			break;
		}

		else if (input == 2)
		{
			input = HowToPlay();
			
			switch (input)
			{
			case 1:
				continue;
				break;
			case 2:
				isEnd = true;
				break;
			}
		}
		else if (input == 3)
		{
			isEnd = true;
			break;
		}
	}

	if (isEnd)
	{
		return 0;
	}

	GamePlay();
	return 0;
}