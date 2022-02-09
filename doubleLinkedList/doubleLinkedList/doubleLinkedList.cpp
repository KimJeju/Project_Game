//사용자가 만든 헤더파일을 포함시킬 때에는 ""안에 적어준다.

#include "LISt.h"
using namespace std;



enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEACH,
	MM_OUTPUT,
	MM_EXIT
};


//메뉴를 만든다

int OutPutMenu()
{
	system("cls");
	cout << "1. 학생추가" << endl;
	cout << "2. 학생삭제" << endl;
	cout << "3. 학생탐색" << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요" << endl;
	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
}


int main()
{
	LIST tList;

	InitLIst(&tList);


	while (true)
	{
		int iMenu = OutPutMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_INSERT:
			Insert(&tList);
			break;

		case MM_DELETE:
			Delete(&tList);
			break;

		case MM_SEACH:
			Search(&tList);
			break;
		case MM_OUTPUT:
			OutPut(&tList);
			break;
		}
	}
	DestroyList(&tList);
	return 0;

}

