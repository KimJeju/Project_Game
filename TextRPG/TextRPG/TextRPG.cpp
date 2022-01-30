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

struct _tagLevelUpStatus
{
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHPMin;
	int iHPMax;
	int iMPMin;
	int iMPMax;


};

int main()
{
	srand((unsigned int)time(0));

	// 레벨업에 필요한 경험치 목록을 만든다 

	const int iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000};

	// JOB_END 는 4이나, 그런데 직업은 3개이므로 -1을 해주어서 배열을 각 직업별로 생성하도록 한다.
	_tagLevelUpStatus tLvUpTable[JOB_END - 1] = {};

	tLvUpTable[JOB_NIGHT - 1].iAttackMin = 4;
	tLvUpTable[JOB_NIGHT - 1].iAttackMax = 10;
	tLvUpTable[JOB_NIGHT - 1].iArmorMin = 8;
	tLvUpTable[JOB_NIGHT - 1].iArmorMax = 16;
	tLvUpTable[JOB_NIGHT - 1].iHPMin = 50;
	tLvUpTable[JOB_NIGHT - 1].iHPMax = 100;
	tLvUpTable[JOB_NIGHT - 1].iMPMin = 10;
	tLvUpTable[JOB_NIGHT - 1].iMPMax = 20;

	tLvUpTable[JOB_ARCHER - 1].iAttackMin = 10;
	tLvUpTable[JOB_ARCHER - 1].iAttackMax = 15;
	tLvUpTable[JOB_ARCHER - 1].iArmorMin = 5;
	tLvUpTable[JOB_ARCHER - 1].iArmorMax = 10;
	tLvUpTable[JOB_ARCHER - 1].iHPMin = 30;
	tLvUpTable[JOB_ARCHER - 1].iHPMax = 60;
	tLvUpTable[JOB_ARCHER - 1].iMPMin = 30;
	tLvUpTable[JOB_ARCHER - 1].iMPMax = 50;


	tLvUpTable[JOB_WIZARD - 1].iAttackMin = 15;
	tLvUpTable[JOB_WIZARD - 1].iAttackMax = 20;
	tLvUpTable[JOB_WIZARD - 1].iArmorMin = 3;
	tLvUpTable[JOB_WIZARD - 1].iArmorMax = 7;
	tLvUpTable[JOB_WIZARD - 1].iHPMin = 30;
	tLvUpTable[JOB_WIZARD - 1].iHPMax = 40;
	tLvUpTable[JOB_WIZARD - 1].iMPMin = 50;
	tLvUpTable[JOB_WIZARD - 1].iMPMax = 100;


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
		tPlayer.iAttackMin = 10;
		tPlayer.IAttackMax = 15;
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
	strcpy_s(tMonsterArr[0].strName, "고블린");
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
	strcpy_s(tMonsterArr[1].strName, "트롤");
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

	//상점에서 판매할 아이템 목록을 생성한다.

	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};

	//아이템 정보들을 설정해준다.
	strcpy_s(tStoreWeapon[0].strName, "롱소드");
	strcpy_s(tStoreWeapon[0].strTypeName, "칼");
	strcpy_s(tStoreWeapon[0].strDesc, "짱 멋진 칼");
	tStoreWeapon[0].iMIn = 10;
	tStoreWeapon[0].iMax = 15;
	tStoreWeapon[0].iPrice = 3000;
	tStoreWeapon[0].isell = 3000;

	strcpy_s(tStoreWeapon[1].strName, "강화롱소드");
	strcpy_s(tStoreWeapon[1].strTypeName, "멋진 칼");
	strcpy_s(tStoreWeapon[1].strDesc, "더 멋져진 칼");
	tStoreWeapon[1].iMIn = 100;
	tStoreWeapon[1].iMax = 150;
	tStoreWeapon[1].iPrice = 15000;
	tStoreWeapon[1].isell = 3000;

	strcpy_s(tStoreWeapon[2].strName, "존나 극강 최강칼");
	strcpy_s(tStoreWeapon[2].strTypeName, "끝판왕");
	strcpy_s(tStoreWeapon[2].strDesc, "간지 절정");
	tStoreWeapon[2].iMIn = 9999;
	tStoreWeapon[2].iMax = 9999;
	tStoreWeapon[2].iPrice = 100000;
	tStoreWeapon[2].isell = 100000;

	_tagItem tStoreArmor[STORE_ARMOR_MAX] = {};

	strcpy_s(tStoreArmor[0].strName, "천갑옷");
	strcpy_s(tStoreArmor[0].strTypeName, "옷");
	strcpy_s(tStoreArmor[0].strDesc, "허름꼬름");
	tStoreArmor[0].iMIn = 10;
	tStoreArmor[0].iMax = 15;
	tStoreArmor[0].iPrice = 3000;
	tStoreArmor[0].isell = 3000;


	strcpy_s(tStoreArmor[1].strName, "쇠갑옷");
	strcpy_s(tStoreArmor[1].strTypeName, "옷");
	strcpy_s(tStoreArmor[1].strDesc, "빛남");
	tStoreArmor[1].iMIn = 100;
	tStoreArmor[1].iMax = 150;
	tStoreArmor[1].iPrice = 15000;
	tStoreArmor[1].isell = 15000;

	strcpy_s(tStoreArmor[2].strName, "존나 이순신");
	strcpy_s(tStoreArmor[2].strTypeName, "최강 갑옷");
	strcpy_s(tStoreArmor[2].strDesc, "슉,슈슉,시발럼아");
	tStoreArmor[2].iMIn = 9999;
	tStoreArmor[2].iMax = 9999;
	tStoreArmor[2].iPrice = 9900000;
	tStoreArmor[2].isell = 9900000;



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

				cin >> iMenu;

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
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true)
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

					//플레이어 정보 출력.
					cout << "================ Player =================" << endl;
					cout << "이름 :" << tPlayer.strName << "\t직업 :" << tPlayer.strJobName << endl;
					cout << "레벨 :" << tPlayer.iLevel << "\t경험치 :" << tPlayer.iExp << " / "  << iLevelUpExp[tPlayer.iLevel - 1] << endl;

					//무기를 장착하고 있을 경우에 공격력의 무기에 공격력을 추가하여 출력한다
					if (tPlayer.bEquip[EQ_WEAPON] == true)
					{
						cout << "공격력  :" << tPlayer.iAttackMin << "+" << tPlayer.tEquip[EQ_WEAPON].iMIn << "   " << tPlayer.IAttackMax << "+" << tPlayer.tEquip[EQ_WEAPON].iMax;
					}

					else
					{
						cout << "공격력  :" << tPlayer.iAttackMin << tPlayer.IAttackMax;

					}

					//방어구를 장착하고 있을경우 방어력에 방어구 방어력을 추가하여 출력한다
					if (tPlayer.bEquip[EQ_ARMOR] == true)
					{
						cout << "\t방어력  :" << tPlayer.iArmorMin << "+" << tPlayer.tEquip[EQ_ARMOR].iMIn << "   " << tPlayer.iArmorMax << "+" << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					}

					else
					{
						cout << "\t방어력  :" << tPlayer.iArmorMin << tPlayer.iArmorMax << endl;

					}

					cout << "체력 :" << tPlayer.iHP << "/" << tPlayer.iHPMax << "\t마나 :" << tPlayer.iMP << "/" << tPlayer.iMPMax << endl;

					if (tPlayer.bEquip[EQ_WEAPON])
						cout << "장착무기 :" << tPlayer.tEquip[EQ_WEAPON].strName;

					else
						cout << "장착무기 : 없음";

					if (tPlayer.bEquip[EQ_ARMOR])
						cout << "\t장착방어구 :" << tPlayer.tEquip[EQ_ARMOR].strName << endl;

					else
						cout << "\t장착방어구 : 없음" << endl;

					cout << "보유골드 :" << tPlayer.tInventory.iGold << "Gold" << endl << endl;

					//몬스터 정보출력
					cout << "================ Monster =================" << endl;
					cout << "이름 :" << tMonster.strName << "\t레벨 :" << tMonster.iLevel << endl;
					cout << "공격력 :" << tMonster.iAttackMin << "~" << tMonster.iAttackMax << "\t방어력 :" << tMonster.iArmorMin << "~" << tMonster.iArmorMax << endl;
					cout << "체력 :" << tMonster.iHP << "/" << tMonster.iHPMax << "\t마나 :" << tMonster.iMP << "/" << tMonster.iMPMax << endl;
					cout << "획득경험치 :" << tMonster.iExp << "획득골드 :" << tMonster.iGoldMin << "~" << tMonster.iGoldMax << endl << endl;


					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요 :";
					cin >> iMenu;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu)
					{

					case BATTLE_ATTACK:
					{
						//예를 들어 min 5 Max 15 라고 가정할 경우 
						//15 - 5 + 1 을 하면 11이 된다. 11로 나눈 나머지 0 ~ 10 나오게 되고
						//여기에 Min값인 5를 더하게 되면 5 ~ 15 사이로 나오게 되는 것이다
						int iAttackmin = tPlayer.iAttackMin;
						int iAttackMax = tPlayer.IAttackMax;

						// 무기를 장착하고 있을 경우 무기의 min, Max를 더해준다.
						if (tPlayer.bEquip[EQ_WEAPON])
						{
							iAttackmin += tPlayer.tEquip[EQ_WEAPON].iMIn;
							iAttackMax += tPlayer.tEquip[EQ_WEAPON].iMax;
						}

						int iAttack = rand() & (iAttackMax - iAttackmin + 1) + iAttackmin;
						//몬스터를 때렸기 때문에 아래는 몬스터 출력
						int iArmorMin = tPlayer.iArmorMin;
						int iArmorMax = tPlayer.iArmorMax;

						if (tPlayer.bEquip[EQ_ARMOR])
						{
							iArmorMin += tPlayer.tEquip[EQ_ARMOR].iMIn;
							iArmorMax += tPlayer.tEquip[EQ_ARMOR].iMax;

						}

						int iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;

						int iDamage = iAttack - iArmor;
						// 삼향 연산자 : 조건식이 ? true일 떄 값 : false 일떄 값 ;
						/*
						if(iDamage < 1)
						   iDamage = 1;  이 코드와 아래가 같음
						*/
						iDamage = iDamage < 1 ? 1 : iDamage;
						// 몬스터 HP를 감소시킨다
						tMonster.iHP -= iDamage;

						cout << tPlayer.strName << "가" << tMonster.strName << "에게" << iDamage << "피해를 입혔습니다" << endl;

						//몬스터가 죽었을 경우를 처리한다.
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << "몬스터가 사망하였습니다" << endl;
							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << "경험치를 획득하였습니다" << endl;
							cout << iGold << "골드를 획득하였습니다." << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;


							// 레벨업을 했는지 체크해본다
							if (tPlayer.iExp >= iLevelUpExp[tPlayer.iLevel - 1])
							{
								//플레이어 경험치를 레벨업에 필요한 경험치 만큼 차감한다.
								tPlayer.iExp -= iLevelUpExp[tPlayer.iLevel - 1];

								//레벨을 증가시킨다.
								++tPlayer.iLevel;

								cout << "레벨업 하였습니다." << endl;

								// 능력치를 상승시킨다.
								// 직업 인덱스를 구한다

								int iJobIndex = tPlayer.ejob - 1;
								int iAttackUp = rand() % (tLvUpTable[iJobIndex].iAttackMax - tLvUpTable[iJobIndex].iAttackMin + 1) + tLvUpTable[iJobIndex].iAttackMin;
								int iArmorUp = rand() % (tLvUpTable[iJobIndex].iArmorMax - tLvUpTable[iJobIndex].iArmorMin + 1) + tLvUpTable[iJobIndex].iArmorMin;
								int iHPUp = rand() % (tLvUpTable[iJobIndex].iHPMax - tLvUpTable[iJobIndex].iHPMin + 1) + tLvUpTable[iJobIndex].iHPMin;
								int iMPUp = rand() % (tLvUpTable[iJobIndex].iMPMax - tLvUpTable[iJobIndex].iMPMin + 1) + tLvUpTable[iJobIndex].iMPMin;

								tPlayer.iAttackMin += tLvUpTable[iJobIndex].iAttackMin;
								tPlayer.IAttackMax += tLvUpTable[iJobIndex].iAttackMax;

								tPlayer.iArmorMin += tLvUpTable[iJobIndex].iArmorMin;
								tPlayer.iArmorMax += tLvUpTable[iJobIndex].iArmorMax;

								tPlayer.iHPMax += iHPUp;
								tPlayer.iMPMax = iMPUp;

								//체력과 나마를 회복시킨다.

								tPlayer.iHP = tPlayer.iHPMax;
								tPlayer.iMP = tPlayer.iMPMax;


							}

							system("pause");
							break;
						}

						//몬스터가 살아있다면 플레이어를 공격한다.

						iAttack = rand() & (tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin;
						//몬스터를 때렸기 때문에 아래는 몬스터 출력
						iArmor = rand() % (tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin;

						iDamage = iAttack - iArmor;
						// 삼향 연산자 : 조건식이 ? true일 떄 값 : false 일떄 값 ;
						/*
						if(iDamage < 1)
						   iDamage = 1;  이 코드와 아래가 같음
						*/
						iDamage = iDamage < 1 ? 1 : iDamage;
						// 몬스터 HP를 감소시킨다
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << "가\t" << tPlayer.strName << "에게" << iDamage << "피해를 입혔습니다" << endl;


						if (tPlayer.iHP <= 0)
						{
							cout << tMonster.strName << "플레이어가 사망하였습니다" << endl;

							int iExp = tPlayer.iExp * 0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << "경험치를 잃었습니다" << endl;
							cout << iGold << "골드를 잃었습니다" << endl;

							//플레이어의 HP와 MP회복

							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}
						system("pause");
					}
					break;

					}

				}

			}
			break;

		case MM_STORE:
			while (true)
			{
				system("cls");
				cout << "====================== 상점 =================" << endl;
				cout << "1. 무기상점" << endl;
				cout << "2. 방어구상점" << endl;
				cout << "3. 뒤로가기" << endl;
				cout << "상점을 선택하세요" << endl;

				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == SM_BACK)
					break;

				switch (iMenu)
				{
				case SM_WEAPON:
					while (true)
					{
						system("cls");
						cout << "====================== 무기상점 =================" << endl;
						//판매 목록을 보여준다.
						for (int i = 0; i < STORE_WEAPON_MAX; ++i)
						{
							cout << i + 1 << "이름 :" << tStoreWeapon[i].strName << "\t종류 :" << tStoreWeapon[i].strTypeName << endl;
							cout << "공격력 :" << tStoreWeapon[i].iMIn << "~" << tStoreWeapon[i].iMax << endl;
							cout << "가격 :" << tStoreWeapon[i].iPrice << "\t구매하기" << tStoreWeapon[i].isell << endl;
							cout << "설명 :" << tStoreWeapon[i].strDesc << endl << endl;
						}
						cout << STORE_WEAPON_MAX + 1 << ", 뒤로가기" << endl;
						cout << "보유금액 :" << tPlayer.tInventory.iGold << "Gold" << endl;
						cout << "보유공간 :" << INVENTORY_MAX - tPlayer.tInventory.iItemiCount << endl;
						cout << "구입할 아아템을 입력하세요 :";
						cin >> iMenu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}


						// 상점판매목록 배열이 인덱스를 구해준다.
						int iWeaponIdex = iMenu - 1;
						//인벤토리가 꽉 찼는지 검사한다.
						if (tPlayer.tInventory.iItemiCount == INVENTORY_MAX)
						{
							cout << "인벤토리가 꽉 찼습니다" << endl;
							system("pause");
							continue;
						}

						// 돈이 부족할 경우
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIdex].iPrice)
						{
							cout << "보유금액이 부족합니다." << endl;
							system("pause");
							continue;
						}


						// 처음에 iItemCount 는 하나도 추가되어 있지 않기 때문에 0으로 초기화 되어있으므로
						// 0번 인덱스에 구매한 아이템을 추가하게 된다. 그리고 카운이트가 1 이 된다. 다음번에 구매할 떄는 1번 인덱스에 추가하게 된다
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemiCount] = tStoreWeapon[iWeaponIdex];
						++tPlayer.tInventory.iItemiCount;

						// 골드를 차감한다
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIdex].iPrice;
						cout << tStoreWeapon[iWeaponIdex].strName << " 이이템을 구매하였습니다" << endl;
						system("pause");

					}
					break;

				case SM_ARMOR:
					while (true)
					{
						system("cls");
						cout << "====================== 방어구상점 =================" << endl;
						//판매 목록을 보여준다.
						for (int i = 0; i < STORE_ARMOR_MAX; ++i)
						{
							cout << i + 1 << "이름 :" << tStoreArmor[i].strName << "\t종류 :" << tStoreArmor[i].strTypeName << endl;
							cout << "공격력 :" << tStoreArmor[i].iMIn << "~" << tStoreArmor[i].iMax << endl;
							cout << "가격 :" << tStoreArmor[i].iPrice << "\t구매하기" << tStoreArmor[i].isell << endl;
							cout << "설명 :" << tStoreArmor[i].strDesc << endl << endl;
						}
						cout << STORE_ARMOR_MAX + 1 << ", 뒤로가기" << endl;
						cout << "보유금액 :" << tPlayer.tInventory.iGold << "Gold" << endl;
						cout << "보유공간 :" << INVENTORY_MAX - tPlayer.tInventory.iItemiCount << endl;
						cout << "구입할 아아템을 입력하세요 :";
						cin >> iMenu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}

						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;

						else if (iMenu < 1 || iMenu > STORE_WEAPON_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}


						// 상점판매목록 배열이 인덱스를 구해준다.
						int iArmorIndex = iMenu - 1;
						//인벤토리가 꽉 찼는지 검사한다.
						if (tPlayer.tInventory.iItemiCount == INVENTORY_MAX)
						{
							cout << "인벤토리가 꽉 찼습니다" << endl;
							system("pause");
							continue;
						}

						// 돈이 부족할 경우
						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "보유금액이 부족합니다." << endl;
							system("pause");
							continue;
						}


						// 처음에 iItemCount 는 하나도 추가되어 있지 않기 때문에 0으로 초기화 되어있으므로
						// 0번 인덱스에 구매한 아이템을 추가하게 된다. 그리고 카운이트가 1 이 된다. 다음번에 구매할 떄는 1번 인덱스에 추가하게 된다
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemiCount] = tStoreArmor[iArmorIndex];
						++tPlayer.tInventory.iItemiCount;

						// 골드를 차감한다
						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;
						cout << tStoreArmor[iArmorIndex].strName << " 이이템을 구매하였습니다" << endl;
						system("pause");

					}

					break;
				}

			}
			break;

		case MM_INVENTORY:

			while (true)
			{


				system("cls");
				cout << "====================== 가방 =================" << endl;
				cout << "이름 :" << tPlayer.strName << "\t직업 :" << tPlayer.strJobName << endl;
				cout << "레벨 :" << tPlayer.iLevel << "\t경험치 :" << tPlayer.iExp << " / " << iLevelUpExp[tPlayer.iLevel - 1] << endl;

				//무기를 장착하고 있을 경우에 공격력의 무기에 공격력을 추가하여 출력한다
				if (tPlayer.bEquip[EQ_WEAPON] == true)
				{
					cout << "공격력  :" << tPlayer.iAttackMin << "+" << tPlayer.tEquip[EQ_WEAPON].iMIn << "   " << tPlayer.IAttackMax << "+" << tPlayer.tEquip[EQ_WEAPON].iMax;
				}

				else
				{
					cout << "공격력  :" << tPlayer.iAttackMin << tPlayer.IAttackMax;

				}

				//방어구를 장착하고 있을경우 방어력에 방어구 방어력을 추가하여 출력한다
				if (tPlayer.bEquip[EQ_ARMOR] == true)
				{
					cout << "\t방어력  :" << tPlayer.iArmorMin << "+" << tPlayer.tEquip[EQ_ARMOR].iMIn << "   " << tPlayer.iArmorMax << "+" << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
				}

				else
				{
					cout << "\t방어력  :" << tPlayer.iArmorMin << tPlayer.iArmorMax << endl;

				}

				cout << "체력 :" << tPlayer.iHP << "/" << tPlayer.iHPMax << "\t마나 :" << tPlayer.iMP << "/" << tPlayer.iMPMax << endl;

				if (tPlayer.bEquip[EQ_WEAPON])
					cout << "장착무기 :" << tPlayer.tEquip[EQ_WEAPON].strName;

				else
					cout << "장착무기 : 없음";

				if (tPlayer.bEquip[EQ_ARMOR])
					cout << "\t장착방어구 :" << tPlayer.tEquip[EQ_ARMOR].strName << endl;

				else
					cout << "\t장착방어구 : 없음" << endl;

				cout << "보유골드 :" << tPlayer.tInventory.iGold << "Gold" << endl << endl;

				for (int i = 0; i < tPlayer.tInventory.iItemiCount; ++i)
				{
					cout << i + 1 << "이름 :" << tPlayer.tInventory.tItem[i].strName << "\t종류 :" << tPlayer.tInventory.tItem[i].strTypeName << endl;
					cout << "공격력 :" << tPlayer.tInventory.tItem[i].iMIn << "~" << tPlayer.tInventory.tItem[i].iMax << endl;
					cout << "가격 :" << tPlayer.tInventory.tItem[i].iPrice << "\t구매하기" << tPlayer.tInventory.tItem[i].isell << endl;
					cout << "설명 :" << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
				}
				cout << tPlayer.tInventory.iItemiCount + 1 << "뒤로가기" << endl;
				cout << "장착할 아이템을 선택하세요 :";
				cin >> iMenu;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				else if (iMenu == tPlayer.tInventory.iItemiCount + 1)
					break;

				else if (iMenu < 1 || iMenu > tPlayer.tInventory.iItemiCount + 1)
				{
					cout << "잘못 선택하였습니다" << endl;
					system("pause");
					continue;
				}

				// 아이템 인덱스를 구해준다
				int idx = iMenu - 1;

				// 제대로 선택했을 경우 해당 아이템 종류에 따라 장착 부위를 결정하게 한다
				EQUIP  eq = {};

				switch (tPlayer.tInventory.tItem[idx].etype)
				{
				case IT_WEAPON:
					eq = EQ_WEAPON;
					break;

				case IT_ARMOR:
					eq = EQ_ARMOR ;
					break;
				};

				// 아이템이 장착되어 있을 경우 장착되어있는 아이템과 장착할 아이템을 교체해 주어야한다. Swap 알고리즘을 활용한다
				if (tPlayer.bEquip[eq] == true)
				{
					_tagItem tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}

				// 장착 되어 있지 않을 경우 인벤토리 아이템을 장착창으로 옮기고
				// 인벤토리도 1칸 비지게 된다
				else
				{
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

					for (int i = idx; i < tPlayer.tInventory.iItemiCount - 1; ++i)
					{
						tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
					}

					--tPlayer.tInventory.iItemiCount;

					//장착을 했기 때문에 true로 만들어 준다
					tPlayer.bEquip[eq] = true;
				}

				cout << tPlayer.tEquip[eq].strName << "아이템을 장착하였습니다." << endl;

				system("pause");

			}

			break;
		default:
			cout << "잘못 선택 하였습니다" << endl;

			break;
		}
		//이번주만 좀 쉴게요,,
	}


	return 0;
}
