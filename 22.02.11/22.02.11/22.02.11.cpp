#include <iostream>
using namespace std;

int main()
{

	/*
	레퍼런스 : 다른 대상을 참조하게 만들어 주는 기능이다.
	참조를 하게 되면 그 대상에 접근하여 값을 변경할 수 있다.
	단, 레퍼런스는 처음 레퍼런스 변수를 생성시 참조하는 대상을 지정해 주어야한다.
	
	변수타입 &레퍼런스명 = 참조할변수명;
	*/

	int iNumber = 100;
	int iNumber1 = 9999;

	// iRefNum 레퍼런스 변수는 iNumber를 참조한다.
	int& iRefNum = iNumber;

	iRefNum = 1234;

	iRefNum = iNumber1;

	cout << iNumber << endl;
	cout << sizeof(iRefNum) << endl;


	return 0;
}
