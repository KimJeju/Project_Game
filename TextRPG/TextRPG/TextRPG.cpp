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
	JOB_END
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

#define NAME_SIZE 32

struct _tagInventory
{
	int iGold;
};

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
	_tagInventory tInventory
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
	int iGoldMax;

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
		
		cin >> iJob;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}

			else if (iJob <= JOB_NONE || iJob >= JOB_END)
				iJob = JOB_NONE;
	}
	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.ejob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.ejob)
	{
	case JOB_NIGHT:
		strcpy_s(tPlayer.strJobName, "기사");
		tPlayer.iAttackMin = 5;
		tPlayer.IAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMPMax = 100;
		tPlayer.iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "궁수");
		tPlayer.iAttackMin = 10;
		tPlayer.IAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMPMax = 200;
		tPlayer.iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "마법사");
		tPlayer.iAttackMin = 15;
		tPlayer.IAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMPMax = 300;
		tPlayer.iMP = 300;
		break;
	}

	// 몬스터를 생성한다.
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	// 고블린 생성
	strcpy_s(tMonsterArr[0].strName,  "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 3;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	// 트롤 생성
	strcpy_s(tMonsterArr[1].strName,  "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;


	// 드래곤 생성
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;



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

				//선택한 메뉴에서 1을 빼주면 몬스터 배열의 인덱스가 있다.
				//그렇게 해서 해당 맵의 몬스터를 생성해준다
				_tagMonster tMonster = tMonsterArr[iMenu = 1];

				while (true)
				{
					switch (iMenu)
					{
					case MT_EASY:
						cout << "====================== 쉬움 =================" << endl;
						break;

					case MT_NOMAL:
						cout << "====================== 보통 =================" << endl;
						break;

					case MT_HARD:
						cout << "====================== 어려움 =================" << endl;
						break;

					}

					//플레이어 정보 출력.
					cout << "================ Player =================" << endl;
					cout << "이름 :" << tPlayer.strName << "\t직업 :" << tPlayer.strJobName << endl;
					cout << "레벨 :" << tPlayer.iLevel << "\t경험치 :" << tPlayer.iExp << endl;
					cout << "공격력 :" << tPlayer.iAttackMin << "~" << tPlayer.IAttackMax << "\t방어력 :" << tPlayer.iArmorMin << "~" << tPlayer.iArmorMax << endl;
					cout << "체력 :" << tPlayer.iHP << "/" << tPlayer.iHPMax << "\t마나 :" << tPlayer.iMP << "/" << tPlayer.iMPMax << endl;
					cout << "보유골드 :" << tPlayer.tInventory.iGold << "Gold" << endl << endl;

					//몬스터 정보출력
					cout << "================ Monster =================" << endl;
					cout << "이름 :" << tMonster.strName << "\t레벨 :" << tMonster.iLevel << endl;
					cout << "공격력 :" << tMonster.iAttackMin << "~" << tMonster.IAttackMax << "\t방어력 :" << tMonster.iArmorMin << "~" << tMonster.iArmorMax << endl;
					cout << "체력 :" << tMonster.iHP << "/" << tMonster.iHPMax << "\t마나 :" << tMonster.iMP << "/" << tMonster.iMPMax << endl;
					cout << "획득경험치 :" << tMonster.iExp << "획득골드 :" << tMonster.iGoldMin << "~" << tMonster.iGoldMax << endl << endl;


					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요 :";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n')
							continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					{
					case BATTLE_ATTACK:
						break;

					}
					
				}

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
