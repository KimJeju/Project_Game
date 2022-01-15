#include <iostream>
#include <time.h>
//console input output 헤더파일, 콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일
#include <conio.h>
using namespace std;

int main()
{
	
	srand((unsigned int)time(0));


	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	//가장 마지막 칸은 공백으로 비워놓는다, 공백을 의미하는 값으로 특수한 값을 사용할 것인데
	//int Max라는 값을 사용할 것이다, 이것은 이미 정의되어있는 값으로 int로 ㅍ현할 수 있는 최대값이다 
	iNumber[24] = INT_MAX;

	// 별 위치를 찾기 위해선 별 이 있는 위치를 저장할 변수를 만들어준다
	int iStarindex = 24; //바뀔 때 마다 위치 갱신

	// 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만 섞어준다, 즉 인덱스는 0 ~ 23번 인덱스까지만 섞어준다

	int iTemp, idx1, idx2; // 섞는 식


	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		
		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	    
	}

	


	while (true)
	{
		system("cls");
		// i for문이 세로줄을 의미 
		for (int i = 0; i < 5; ++i)
		{   //j for문이 가로줄을 의미
			for (int j = 0; j < 5; ++j)
			{
				//i가 0 일때 j는 0 ~ 4 까지 반복한다, 이경우 0 * 5 + (0 ~ 4) 를 더하게 되어 인덱스는 0,1,2,3,4가 나오게 된다. 이 경우 인덱스는 0,1,2,3,4가 나오게 된다
				//i가 1 일때 j는 0 ~ 4 까지 반복한다, 이경우 1 * 5 + (0 ~ 4) 를 더하게 되어 인덱스는 5,6,7,8,9가 나오게 된다. 이 경우 인덱스는 0,1,2,3,4가 나오게 된다
				//i가 2 일때 j는 0 ~ 4 까지 반복한다, 이경우 2 * 5 + (0 ~ 4) 를 더하게 되어 인덱스는 10,11,12,13,14가 나오게 된다. 이 경우 인덱스는 0,1,2,3,4가 나오게 된다
				//i가 3 일때 j는 0 ~ 4 까지 반복한다, 이경우 3 * 5 + (0 ~ 4) 를 더하게 되어 인덱스는 15,16,17,18,19가 나오게 된다. 이 경우 인덱스는 0,1,2,3,4가 나오게 된다
				//i가 4 일때 j는 0 ~ 4 까지 반복한다, 이경우 4 * 5 + (0 ~ 4) 를 더하게 되어 인덱스는 20,21,22,23,24가 나오게 된다. 이 경우 인덱스는 0,1,2,3,4가 나오게 된다
				// 줄번호 * 가로개수 + 칸번호.
				if (iNumber[i * 5 + j] == INT_MAX) //24번에만 INT_MAX가 대입되었기 떄문에 24가 되면 별로 출력
					cout << "*\t";

				else //INT_MAX(24) 가 아니라면 일반 출력
					cout << iNumber[i * 5 + j] << "\t";

			}
			cout << endl;
		}
	
		
		

		// true로 만들어서 모두 맞췄다 라고 가정해준다,
		bool bWin = true;
		//퍼즐을 맞추었는지 체크한다.
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}



		if (bWin == true)
		{
			cout << "숫자를 모두 맞추었습니다" << endl;
			break;
		}

		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 :"; //키보드 입력
		// getch() 는 문자한개를 입력받는 함수이다. 이 함수는 엔터를 치치않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.
		char cinput = _getch();

		if (cinput == 'q' || cinput == 'Q')
			break;

		switch (cinput)
		{

		case 'w':
		case 'W':
			//가장 윗줄은 W 눌러도 위로 올라가선 안된다.
			if (iStarindex > 4)
			{
				//별이 있는 위치에 바로 위에 있는 값을 넣어준다
				iNumber[iStarindex] = iNumber[iStarindex - 5];
				// 위에 위치에 별을 넣어주어서 2개의 값을 서로 교환한다.
				iNumber[iStarindex - 5] = INT_MAX;
				// 별이 한칸 뒤로 올라갔으므로 한칸 위에 인덱스로 만들어준다
				iStarindex -= 5;
			}
			break;

		case 's':
		case 'S':
			//가장 아랫줄이 아닐 경우 움직인다.
			if (iStarindex < 20)
			{
				iNumber[iStarindex] = iNumber[iStarindex + 5];
				iNumber[iStarindex + 5] = INT_MAX;
				iStarindex += 5;
			}
			break;

		case 'a':
		case 'A':
			if (iStarindex % 5 != 0)
			{

				iNumber[iStarindex] = iNumber[iStarindex - 1];
				iNumber[iStarindex - 1] = INT_MAX;
				--iStarindex; // 1씩 빠지기 때문에 증감식 사용가능

			}
			break;

		case 'd':
		case 'D':
			if (iStarindex % 5 != 4)
			{
				iNumber[iStarindex] = iNumber[iStarindex + 1];
				iNumber[iStarindex + 1] = INT_MAX;
				++iStarindex; // 1 씩 증가하기 때문에 증감식 사용가능
			}
			break;

		}
	}

	cout << endl << "게임을 종료합니다." << endl;

	return 0;
}

