#include <iostream>
#include <time.h>

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
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
		return INT_MAX //INT_MAX가 리턴되면 입력이 잘못되었다는 의미.

	};

	return iInput;

}

int OutPutMainMenu()
{
	system("cls");
	cout << "====================== 로비 ===================" << endl;

	cout << "1. 맵" << endl;
	cout << "2. 상점" << endl;
	cout << "3. 인벤토리" << endl;
	cout << "4. 종료" << endl;
	cout << "메뉴를 선택하세요 :";
	int iMenu = Inputint;
	cin >> iMenu;

	i



}

int main()
{
	srand((unsigned int)time(0))

		while (true)
		{

		}
	return 0;
}

