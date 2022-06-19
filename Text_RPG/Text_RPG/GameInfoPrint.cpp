#include "GameInfoPrint.h"
#include "Common.h"

void PrintTitle()
{
	system("cls");
	cout << "주의사항 : BGM 사운드가 큽니다. 소리를 감소하고 플레이 해주세요.\n";
	cout << "┌───────────────┐\n";
	cout << "│  용사의 모험  │\n";
	cout << "└───────────────┘\n";
	cout << "1. 게임시작 / 2. 플레이 방법 / 3. 게임 종료\n";
	cout << "_ ";
}

int HowToPlay()
{
	while (1)
	{
		int input;
		system("cls");
		cout << "* 해당 게임은 플레이어의 체력이 0이 되어 죽거나,\n";
		cout << "* 플레이어의 레벨이 50이 되면 게임이 종료됩니다.\n\n";
		cout << "* 전투에서 스킬 사용시 스킬에 따라 피로도가 증가하며,\n";
		cout << "* 피로도가 100 이상이 될 경우에 3턴동안 스턴상태에 빠집니다.\n\n";
		cout << "* 게임 진행은 오로지 숫자입력으로 이루어 집니다.\n";
		cout << "* 그럼 재밌게 플레이 해주시길 바랍니다.\n";
		cout << "1. 돌아가기 / 2. 게임종료\n";
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
		cout << "┌──────────────┐\n";
		cout << "│   로    비   │\n";
		cout << "└──────────────┘\n";
		cout << "1. 내 정보 / 2. 쉼터 / 3. 몬스터 사냥\n";
		cout << "_ ";

		cin >> input;

		if (input == 1 || input == 2 || input == 3)
		{
			return input;
		}
	}
}