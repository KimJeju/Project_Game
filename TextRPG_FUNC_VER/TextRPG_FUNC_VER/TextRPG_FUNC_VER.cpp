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

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};


#define NAME_SIZE 32 //이름 길이
#define ITEM_DESC_LENGTH 512 // 아이템 설명 길이
#define INVENTORY_MAX 20 // 인벤토리 아이템 최대치
#define STORE_WEAPON_MAX 3 // 무기상점 판매개수
#define STORE_ARMOR_MAX 3 //방어구상점 판매개수
#define LEVEL_MAX 10


// 레벨업에 필요한 경험치 목록을 만든다 

const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };


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

_tagMonster CreateMonster(int iAttackMIn, int iAttackMax, int iArmorMin, int iArmorMax, int iHP, int iMP, int iLevel, int iExp, int iGoldMin, int iGoldMax)
{
	_tagMonster tMonster = {};

	tMonster.iAttackMin = iAttackMIn;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHP = iHP;
	tMonster.iHPMax = iHP;
	tMonster.iMP = iMP;
	tMonster.iMPMax = iMP;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoldMax;
}


void SetMonster(_tagMonster* pMonsterArr)
{
	pMonsterArr[0] = CreateMonster(20,30,3,5,100,10,1,1000,500,1500);
	pMonsterArr[1] = CreateMonster(80, 130, 60, 90, 2000, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster( 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 50000);

}

void OutPutbattleTag(int iMenu)
{
	system("cls");
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

}

void OutPutPlayer(_tagPlayer* pPlayer)
{
	//플레이어 정보 출력.
	cout << "================ Player =================" << endl;
	cout << "이름 :" << pPlayer->strName << "\t직업 :" << pPlayer->strJobName << endl;
	cout << "레벨 :" << pPlayer->iLevel << "\t경험치 :" << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;

	//무기를 장착하고 있을 경우에 공격력의 무기에 공격력을 추가하여 출력한다
	if (pPlayer->bEquip[EQ_WEAPON] == true)
	{
		cout << "공격력  :" << pPlayer->iAttackMin << "+" << pPlayer->tEquip[EQ_WEAPON].iMIn << "   " << pPlayer->IAttackMax << "+" << pPlayer->tEquip[EQ_WEAPON].iMax;
	}

	else
	{
		cout << "공격력  :" << pPlayer->iAttackMin << pPlayer->IAttackMax;

	}

	//방어구를 장착하고 있을경우 방어력에 방어구 방어력을 추가하여 출력한다
	if (pPlayer->bEquip[EQ_ARMOR] == true)
	{
		cout << "\t방어력  :" << pPlayer->iArmorMin << "+" << pPlayer->tEquip[EQ_ARMOR].iMIn << "   " << pPlayer->iArmorMax << "+" << pPlayer->tEquip[EQ_ARMOR].iMax << endl;
	}

	else
	{
		cout << "\t방어력  :" << pPlayer->iArmorMin << pPlayer->iArmorMax << endl;

	}

	cout << "체력 :" << pPlayer->iHP << "/" << pPlayer->iHPMax << "\t마나 :" << pPlayer->iMP << "/" << pPlayer->iMPMax << endl;

	if (pPlayer->bEquip[EQ_WEAPON])
		cout << "장착무기 :" << pPlayer->tEquip[EQ_WEAPON].strName;

	else
		cout << "장착무기 : 없음";

	if (pPlayer->bEquip[EQ_ARMOR])
		cout << "\t장착방어구 :" << pPlayer->tEquip[EQ_ARMOR].strName << endl;

	else
		cout << "\t장착방어구 : 없음" << endl;

	cout << "보유골드 :" << pPlayer->tInventory.iGold << "Gold" << endl << endl;


}

void OutPutMnster(_tagMonster* pMonster)
{
	//몬스터 정보출력
	cout << "================ Monster =================" << endl;
	cout << "이름 :" << pMonster->strName << "\t레벨 :" << pMonster->iLevel << endl;
	cout << "공격력 :" << pMonster->iAttackMin << "~" << pMonster->iAttackMax << "\t방어력 :" << pMonster->iArmorMin << "~" << pMonster->iArmorMax << endl;
	cout << "체력 :" << pMonster->iHP << "/" << pMonster->iHPMax << "\t마나 :" << pMonster->iMP << "/" << pMonster->iMPMax << endl;
	cout << "획득경험치 :" << pMonster->iExp << "획득골드 :" << pMonster->iGoldMin << "~" << pMonster->iGoldMax << endl << endl;


}

int OutPutBattleMenu()
{
	cout << "1. 공격" << endl;
	cout << "2. 도망가기" << endl;
	cout << "메뉴를 선택하세요 :";

	int iMenu = Inputint();


	if (iMenu == INT_MAX || iMenu <= BATTLE_NONE || iMenu > BATTLE_BACK)
		return BATTLE_NONE;


	return iMenu;
}

void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu)
{
	_tagMonster tMonster = pMonsterArr[iMenu - 1];

	while (true)
	{
		system("cls");
		OutPutbattleTag(iMenu);

		//플레이어 출력
		OutPutPlayer(pPlayer);

		// 몬스터 출력
		OutPutMnster(&tMonster);

			switch (OutPutBattleMenu())
			{
			case BATTLE_ATTACK:
				break;

			case BATTLE_BACK:
				return;
			}

	}
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
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr)
{
	bool bLoop(true);

	while (bLoop)
	{
		int iMenu = OutPutMapMenu();

		if (MT_BACK == iMenu)
			return;

		// 전투를 시작한다.
		RunBattle(pPlayer, pMonsterArr, iMenu);
	}
}


int main()
{
	srand((unsigned int)time(0));

	// 게임을 시작할 때 플레이어 정보를 설정하게 한다.
	_tagPlayer tPlayer = {};


	// 플레이어 정보를 정의한다.
	SetPLayer(&tPlayer);


	// 몬스터를 생성한다
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	SetMonster(tMonsterArr);


	bool bLoop = true;

	while (bLoop)
	{
		switch (OutPutMainMenu())
		{
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr); // 맵 관련 루프를 처리한다.
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
