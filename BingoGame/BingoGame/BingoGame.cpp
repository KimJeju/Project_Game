#include <time.h>
#include <iostream>
using namespace std;


int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	// 1 ~ 25 까지 숫자를 넣어준다

	for (int i = 0; i < 25; ++i)
	{
		iNumber[i] = i + 1;
	}

	//숫자를 섞어준다

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	int iBingo = 0;

	while (true)
	{
		system("cls");

		//5x5 출력
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}

		cout << "Bingo Line: " << iBingo << endl;

		//줄수가 5 이상일 경우 게임을 종료한다
		if (iBingo >= 5)
			break;

		cout << "숫자를 입력해주세요(0 : 종료)";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput < 1 || iInput > 25)
			continue;



		// 중복체크를 위한 변수, 기본적으로 중봉되었다라고 하기위해 true로 설정
		bool bAcc = true;

		/*
		모든 숫자를 중복체크해서 입력한 숫자와 같은 숫자가 있는지 찾아낸다
		*/
		for (int i = 0; i < 25; ++i)
		{
			//같은 숫자가 있을 경우
			if (iInput == iNumber[i])
			{
				//숫자를 찾았을 경우 중복된 숫자가 아니므로 bAcc 변수를 false로 만들어준다
				bAcc = false;

				// 숫자를 별로 변경하기 위해 특수한 값인 INT_MAX를 
				iNumber[i] = INT_MAX;
				//더이상 다른 숫자를 찾아볼 필요가 없으므로 반복문을 빠져나간다
				break;
			}
		}
		// bAcc 변수가 true일 경우 중복된 숫자를 입력해서 숫자를 *로 바꾸지 못했으므로 다시 입력받게 컨티뉴 해준다
		if (bAcc)
			continue;

		//빙고 줄 수 체크하는 것은 매번 숫자를 입력할 때 마다 처음부터 새로 카운트를 할 것이다
		//그러므로 iBingo 변수를 매번 새로 초기화 하고 새롭게 줄 수 있도록 구해준다
		iBingo = 0;

		//가로,세로 줄 수를 구해준다
		int iStar1 = 0, iStar2 = 0;

		for (int i = 0; i < 5; ++i)
		{
			//한줄을 체크하기 전에 먼저 0으로 별 개수를 초기화한다
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; ++j)
			{
				//가로 별 개수를 구해준다
				if (iNumber[i * 5 + j] == INT_MAX) //가로줄 별 체크 
					++iStar1;

				//세로 별 개수를 구해준다 
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;

			}
			//i for문을 빠져나오고 나면 현재 줄의 가로별 개수가 몇개인지 iStar1 변수에 들어가게 된다.
			//iStar1이 값이 5이면 한줄이 모드 * 이라는 의미이므로 빙고 줄 카운트를 추가해준다
			if (iStar1 == 5)
				++iBingo;

			//세로값
			if (iStar2 == 5)
				++iBingo;
		}
		//왼쪽상단에서 오른쪽 하단으로 가는 줄 체크 특징 :: 인덱스가 6식 증가 6,12,18,24
		iStar1 = 0;//0으로 초기화
		for (int i = 0; i <= 24; i += 6)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;

		//오른쪽 상단에서 왼쪽 하단 체크 특징 :: 인덱스 4씩 증가 4,8,12,16,20
		iStar1 = 0;
		for (int i = 0; i <= 20; i += 4)
		{
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;
	}

	return 0;
}

