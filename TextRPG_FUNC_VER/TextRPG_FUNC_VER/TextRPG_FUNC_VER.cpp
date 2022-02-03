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

#define NAME_SIZE 32 //이름 길이
#define ITEM_DESC_LENGTH 512 // 아이템 설명 길이
#define INVENTORY_MAX 20 // 인벤토리 아이템 최대치
#define STORE_WEAPON_MAX 3 // 무기상점 판매개수
#define STORE_ARMOR_MAX 3 //방어구상점 판매개수
#define LEVEL_MAX 10


struct _tagItem
{
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE etype;
	int iMIn;
	int iMax;
	int iPrice;
	int isell;
	char strDesc[ITEM_DESC_LENGTH]; //아이템 설명

};


struct _tagInventory
{
	_tagItem tItem[INVENTORY_MAX];
	int iItemiCount;
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
	_tagItem tEquip[EQ_MAX];
	bool bEquip[EQ_MAX];
	_tagInventory tInventory;
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

int SelectJob()
{

	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");

		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 :";
		iJob = Inputint();


		if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}

	return iJob;

}

void SetPLayer(_tagPlayer* pPlayer)
{
	// 플레이어의 이름을 입력 받는다.
	cout << "이름 :";
	cin.getline(pPlayer->strName, NAME_SIZE - 1); //문자열의 끝은 NULL로 끝내야하기 떄문에 문자에 마지막까지 꽉꽉 채워져있다면 NULL 까지 문자열로 인식하기에 - 1 || NULL 공간 확보
	pPlayer->ejob = (JOB)SelectJob();

	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->ejob)
	{
	case JOB_NIGHT:
		strcpy_s(pPlayer->strJobName, "기사");
		pPlayer->iAttackMin = 10;
		pPlayer->IAttackMax = 15;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 500;
		pPlayer->iMPMax = 100;
		pPlayer->iMP = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(pPlayer->strJobName, "궁수");
		pPlayer->iAttackMin = 10;
		pPlayer->IAttackMax = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 15;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMPMax = 200;
		pPlayer->iMP = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(pPlayer->strJobName, "마법사");
		pPlayer->iAttackMin = 15;
		pPlayer->IAttackMax = 20;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMax = 10;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMPMax = 300;
		pPlayer->iMP = 300;
		break;
	}



}

int main()
{
	srand((unsigned int)time(0));

	// 게임을 시작할 때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {};


	// 플레이어 정보를 정의한다.
	SetPLayer(&tPlayer);

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
