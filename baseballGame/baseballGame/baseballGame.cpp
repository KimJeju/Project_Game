#include <iostream>
#include <time.h>
using namespace std;


int main()
{
	srand((unsigned int)time(0));

	int iNumber[9] = {};

	//1 ~ 9 사이의 숫자를 설정
	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	// 인덱스를 받아오고 서로 값을 100번 섞어줌
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

	}

	cout << "*\t*\t *" << endl;

	// cout << iNumber[0] << "\t" << iNumber[1] << "\t" << iNumber[2] << endl; 입력받은 값 숫자로 보기

	int iStrike = 0, iBall = 0;
	int iInput[3];
	int iGameCount = 1;

	while (true)
	{
		cout << iGameCount << "회" << endl;
		cout << "1 ~ 9 사이에 숫자를 입력하세요(0:종료) : \n";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;

		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "잘못 된 숫자를 입력하였습니다." << endl;
			continue;
		}

		else if (iInput[0] == iInput[1] || iInput[0] == iInput[2] || iInput[1] == iInput[2])
		{
			cout << "중복된 숫자를 입력하였습니다" << endl;
			continue;

		}

		// 매번 스트라이크와 볼의 수가 달라지기 떄문에 0으로 초기화 하고 다시 계산한다.
		iStrike = iBall = 0; // 스트라이크 , 볼 초기화


		//i for문은 맞춰야할 인덱스의 숫자를 구한다
		for (int i = 0; i < 3; ++i)
		{
			//입력받은 숫자의 인덱스를 구한다.
			for (int j = 0; j < 3; ++j)
			{
				// i가 0일 떄 j는 0 ~ 2 까지 반복한다, 즉 맞춰야할 숫자의 첫번째 값과 입력받은 숫자의 첫번째, 두번째,세번째를 차례대로 비교하여 같은 값이 있는지를 찾아낸다
				if (iNumber[i] == iInput[j])
				{
					/*
					값이 같은 것이 있는 경우 스트라이크 or 볼이므로 자리가 같은 지를 체크한다
					i 와 j 는 현재 맞춰야할 숫자의 인덱스와 입력받은 숫자의 인덱스 이고
					두값이 같으므로 이 인덱스가 곧 위치가 된다. 인덱스가 서로 같을 경우라면 자리까지 같다는 의미이므로
					스트라이크가 증가하고 그게 아니라면 자드가 다르나는 의미이므로 볼을 증가 시킨다.
					*/
					if (i == j)
						++iStrike;

					else
						++iBall;
					// 입력받은 숫자와 맞춰야할 숫자를 비교할 때 같은 수가 있으면 이 
					// 이 뒤로는 더이상 같은 수가 없으므로 다음 맞춰야할 숫자를
					// 바로 비교하면 된다 . 그래서 브레이크를 해서 j 포문을 빠져나가고
					// ++j 가 되게 하여 다음 맞춰야할 숫자와 다시 비교하게 된다.
					break;
				}
			}
		}

		if (iStrike == 3)
		{ 
			cout << "정답입니다" << endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0)
			cout << "Out" << endl;

		else
			cout << iStrike <<  "Strike" << "\t" << iBall << "Ball" << endl;

		++iGameCount;

	};

	return 0;

	system("pause");
}