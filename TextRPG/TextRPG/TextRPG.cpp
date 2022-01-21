#include <iostream>
#include <time.h>
using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EIXT
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
};

#define NAME_SIZE 32

struct _tagPlayer
{
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB ejob;
	int iAttackMin;
	int IAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
};

struct _tagMonster
{
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp; // 획득 Exp;
	int iGoldMin;
	int iColdMax;

};

int main()
{
	srand((unsigned int)time(0));

	// 게임을 시작할 때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {};
	// 플레이어의 이름을 입력 받는다.
	cout << "이름 :";
	cin.getline(tPlayer.strName, NAME_SIZE - 1); //문자열의 끝은 NULL로 끝내야하기 떄문에 문자에 마지막까지 꽉꽉 채워져있다면 NULL 까지 문자열로 인식하기에 - 1 || NULL 공간 확보

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");

		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 :";
		
		cin >> iJob

		if (cin.fail())
		{
			cin.clear();
			cin.getline(1024, '\n');
		}
	}


	while (true)
	{
		system("cls");
		cout << "====================== 로비 ===================" << endl;

		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 인벤토리" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 :";
		int iMenu;
		cin >> iMenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
			
		}

		if (iMenu == MM_EIXT)
		break;

		switch (iMenu)
		{

		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "====================== 맵 =================" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 :";
				
				cin >> iMenu ;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				//이 if문에 속한 break는 맵 메뉴를 돌려주기 위한 while에 속해 있으므로 이 while문을 빠져 나간다
				if (iMenu == MT_BACK)
					break;
			}
			break;

		case MM_STORE:
			break;

		case MM_INVENTORY:
			break;

		default:
			cout << "잘못 선택 하였습니다" << endl;
			break;
		}
		
	}


	return 0;
}
