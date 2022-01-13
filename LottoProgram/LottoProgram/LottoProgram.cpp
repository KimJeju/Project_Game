#include <iostream>
#include <time.h> // srand를 사용하기 위한 헤더함수 || 시간 값 가져옴


using namespace std;

/*

*/

int main()
{
	srand((unsigned int)time(0)); //랜덤갑 출력을 위한 srand 선언

	int iLotto[45] = {};

	// 1 ~ 45 까지의 숫자를 차례대로 넣어준다
	for (int i = 0; i < 45; ++i)
	{
		iLotto[i] = i + 1;
	}

	/*Swap 알고리즘
	int iNum1 = 1, iNum2 = 2, iNum3 = 3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;
	*/

	//Shuffle
	int iTemp, idx1, idx2;
	//100번 정도 골고루 섞어준다
	for (int i = 0; i <= 100; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp; //itemp 에는 idx 1번이 저장되어 있다
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << iLotto[i] << "\t";
	};

	cout << "보너스번호" << iLotto[6] << endl;
}

