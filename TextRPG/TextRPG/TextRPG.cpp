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

int main()
{
	while (true)
	{
		system("cls");
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
		
	}


	return 0;
}
