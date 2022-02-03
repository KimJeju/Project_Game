#include <iostream>
#include <time.h>
using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NOMAL,
	MT_HARD,
	MT_BACK,
};


enum JOB
{
	JOB_NONE,
	JOB_NIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};


enum ITEM_TYPE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK

};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX,
};




//숫자를 입력받는다. 입력 오류까지 처리해주고 INT_MAX를 리턴하면 입력오류다
int Inputint()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX; //INT_MAX가 리턴되면 입력이 잘못되었다는 의미.
	}
	return iInput;
}

//메인 메뉴를 화면에 보여주고 입력받은 메뉴를 반환한다.
//입력 오류거나 잘못된 번호를 입력한 경우 MM_NONE를 반환한다.
int OutPutMainMenu()
{
	system("cls");
	cout << "====================== 로비 ===================" << endl;

	cout << "1. 맵" << endl;
	cout << "2. 상점" << endl;
	cout << "3. 인벤토리" << endl;
	cout << "4. 종료" << endl;
	cout << "메뉴를 선택하세요 :";
	int iMenu = Inputint();

	if (iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT)
		return MM_NONE;

	return iMenu;

}


int OutPutMapMenu()
{
	system("cls");
	cout << "====================== 맵 =================" << endl;
	cout << "1. 쉬움" << endl;
	cout << "2. 보통" << endl;
	cout << "3. 어려움" << endl;
	cout << "4. 뒤로가기" << endl;
	cout << "맵을 선택하세요 :";
	int iMenu = Inputint();


	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
		return MT_NONE;

	return iMenu;
}

//맵에 관련된 동작을 처리한다.
void RunMap()
{
	bool bLoop(true);

	while (bLoop)
	{
		switch (OutPutMapMenu())
		{
		case MT_EASY:
			break;

		case MT_NOMAL:
			break;

		case MT_HARD:
			break;

		case MT_BACK:
			bLoop = false;
			break;
		}
	}
}


int main()
{
	srand((unsigned int)time(0));

	bool bLoop = true;

	while (bLoop)
	{
		switch (OutPutMainMenu())
		{
		case MM_MAP:
			RunMap(); // 맵 관련 루프를 처리한다.
			break;

		case MM_STORE:
			break;

		case MM_INVENTORY:
			break;

		case MM_EXIT:
			bLoop = false;
			break;

		default:
			break;
		}
	}
	return 0;
}
