#include <iostream>
#include "time.h"
#include "conio.h"

using namespace std;

/*

혼자 하는 빙고게임 만들기!!!

숫자는 1 ~ 25

5 줄 빙고를 완성하면 게임 끝

0을 입력하면 게임 종료!

*/

/*

AI EASY 모드는 랜덤으로 숫자 선택

AI HARD 모드는 각 배열 요소에 점수를 넣어주는 방식.

그리고 점수가 가장 높은 요소를 빙고숫자로 선택

*/


int main()
{
	int arr[25];	// 플레이어의 빙고판
	int arrAI[25];	// AI의 빙고판

	// 빙고판에 숫자 넣기
	for (int i = 0; i < 25; ++i)
	{
		arr[i] = i + 1;
		arrAI[i] = i + 1;
	}

	srand((unsigned int)time(0));

	// 숫자 SHUFFLE
	for (int i = 0; i < 100; ++i)
	{
		// Player
		int idx1 = rand() % 25; // 0 에서 24의 숫자가 랜덤생성
		int idx2 = rand() % 25;
		int temp;

		temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;

		// AI
		idx1 = rand() % 25; // 0 에서 24의 숫자가 랜덤생성
		idx2 = rand() % 25;

		temp = arrAI[idx1];
		arrAI[idx1] = arrAI[idx2];
		arrAI[idx2] = temp;
	}



	// AI의 픽 설정 <쉬움>
	// 쉬운 AI
	int easyAI;
	int easyAIPicks[25];

	for (int i = 0; i < 25; ++i)
	{
		easyAIPicks[i] = i + 1;
	}

	for (int i = 0; i < 100; ++i)
	{
		int idx1 = rand() % 25;
		int idx2 = rand() % 25;
		int temp;

		temp = easyAIPicks[idx2];
		easyAIPicks[idx2] = easyAIPicks[idx1];
		easyAIPicks[idx1] = temp;
	}



	enum AI_MODE {
		AI_EASY = 1,
		AI_HARD
	};


	int count = 0;	// 진행 횟수	
	int inputDifficulty = 0;	// 난이도
	bool levelIsNotChecked = true;

	int aiPick = 0;
	int aiIndex = 0;	// 쉬운 AI index
	int assessmentArr[25] = {};	// AI 평가점수 배열

	while (true)
	{
		while (levelIsNotChecked == true)
		{
			system("cls");
			cout << " 난이도를 선택 하세요..." << endl;
			cout << " 1 : 쉬움" << endl;
			cout << " 2 : 어려움" << endl;

			cin >> inputDifficulty;

			if (inputDifficulty < AI_EASY || AI_HARD < inputDifficulty)
			{
				continue;
			}
			else
			{
				levelIsNotChecked = false;
			}
		}

		// 빙고판 프린트
		system("cls");
		if (inputDifficulty == AI_EASY) cout << "[ 난 이 도 : EASY ]" << endl;
		if (inputDifficulty == AI_HARD) cout << "[ 난 이 도 : HARD ]" << endl;

		cout << "============= Player =============" << endl;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (arr[i * 5 + j] == 0)	cout << "■" << "\t";
				else                        cout << arr[i * 5 + j] << "\t";
			}
			cout << endl << endl;
		}

		cout << "============== A  I ==============" << endl;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (arrAI[i * 5 + j] == 0)	cout << "■" << "\t";
				else                        cout << arrAI[i * 5 + j] << "\t";


			}
			cout << endl << endl;
		}

		// AI의 평가배열 점수판을 출력
		cout << "========== AI DEBUGGING ==========" << endl;
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				cout << assessmentArr[i * 5 + j] << "\t";
			}
			cout << endl << endl;
		}
		cout << "==================================" << endl;



		// 빙고 판정
		int bingoCount = 0;
		int bingoCountAI = 0;

		// 가로 판정
		for (int i = 0; i < 5; ++i)
		{
			int sum = arr[i * 5] + arr[i * 5 + 1] + arr[i * 5 + 2] + arr[i * 5 + 3] + arr[i * 5 + 4];
			int sumAI = arrAI[i * 5] + arrAI[i * 5 + 1] + arrAI[i * 5 + 2] + arrAI[i * 5 + 3] + arrAI[i * 5 + 4];

			if (sum == 0)	++bingoCount;
			if (sumAI == 0)	++bingoCountAI;
		}
		// 세로 판정
		for (int i = 0; i < 5; ++i)
		{
			int sum = arr[i] + arr[i + 1 * 5] + arr[i + 2 * 5] + arr[i + 3 * 5] + arr[i + 4 * 5];
			int sumAI = arrAI[i] + arrAI[i + 1 * 5] + arrAI[i + 2 * 5] + arrAI[i + 3 * 5] + arrAI[i + 4 * 5];

			if (sum == 0)	++bingoCount;
			if (sumAI == 0)	++bingoCountAI;
		}

		// 대각선 판정 1
		int sum = arr[0] + arr[6] + arr[12] + arr[18] + arr[24];
		int sumAI = arrAI[0] + arrAI[6] + arrAI[12] + arrAI[18] + arrAI[24];

		if (sum == 0)	++bingoCount;
		if (sumAI == 0)	++bingoCountAI;

		// 대각선 판정 2
		sum = arr[4] + arr[8] + arr[12] + arr[16] + arr[20];
		sumAI = arrAI[4] + arrAI[8] + arrAI[12] + arrAI[16] + arrAI[20];

		if (sum == 0)	++bingoCount;
		if (sumAI == 0)	++bingoCountAI;

		// bingo 수 체크
		if (bingoCount >= 5 && bingoCountAI >= 5)
		{
			cout << "와우 비기셨습니다." << endl;
			break;
		}
		if (bingoCount >= 5 && bingoCountAI < 5)
		{
			cout << "Player : 5 빙고 승리!@@!!@!@" << endl;
			break;
		}
		if (bingoCountAI >= 5 && bingoCount < 5)
		{
			cout << "A I : 5 빙고 승리...... ㅠㅠ" << endl;
			break;
		}



		// UI Text
		cout << count << " 회차"
			<< "\t플레이어 빙고 : " << bingoCount << "개 VS "
			<< "A I 빙고 : " << bingoCountAI << " 개" << endl << endl;
		cout << "AI의 PICK : " << aiPick << endl << endl;
		for (int i = 0; i < 25; ++i)
		{
			cout << easyAIPicks[i] << " ";
		}
		cout << endl << endl;
		cout << "1~25 사이의 숫자를 입력하시오(0 : 종료)" << endl;



		// 플레이어 입력
		int player;
		cin >> player;

		if (player != 0)
		{
			for (int i = 0; i < 25; ++i)
			{
				if (player == arr[i])
				{
					arr[i] = 0;
					break;
				}
			}
		}
		else
		{
			break;
		}

		// 쉬운 AI
		if (inputDifficulty == AI_EASY)
		{
			for (int i = 0; i < 25; ++i)
			{
				if (player == arrAI[i])
				{
					arrAI[i] = 0;
					break;
				}
			}

			// 픽 pool에 동기화
			for (int i = 0; i < 25; ++i)
			{
				if (player == easyAIPicks[i])
				{
					easyAIPicks[i] = 0;
				}
			}

			while (easyAIPicks[aiIndex] == 0) // 이미 player가 체크한 숫자 지우기
			{
				++aiIndex;
			}

			aiPick = easyAI = easyAIPicks[aiIndex]; // easyAIPicks에서 하나씩 사용

			// 플레이어 빙고판에 AI의 숫자 체크
			for (int i = 0; i < 25; ++i)
			{
				if (easyAI == arrAI[i])
				{
					arrAI[i] = 0;
				}
				if (easyAI == arr[i])
				{
					arr[i] = 0;
					++count;
				}
			}

			++aiIndex;
		}

		// 어려운 AI
		else if (inputDifficulty == AI_HARD)
		{
			// 어려운 AI 초기화
			for (int i = 0; i < 0; ++i)
			{
				assessmentArr[i] = 0;
			}

			// 동기화
			for (int i = 0; i < 25; ++i)
			{
				if (player == arrAI[i])
				{
					arrAI[i] = 0;
					break;
				}
			}

			int hardAI;

			// 가로 평가
			for (int i = 0; i < 5; ++i)
			{
				int checkCount = 0; // 빙고체크한 횟수
				for (int j = 0; j < 5; ++j)
				{
					if (arrAI[i * 5 + j] == 0)	checkCount++;
				}
				// 그 줄 모두가 점수를 획득
				assessmentArr[i * 5] = assessmentArr[i * 5 + 1] = assessmentArr[i * 5 + 2] = assessmentArr[i * 5 + 3] = assessmentArr[i * 5 + 4] = checkCount;
			}

			// 세로 평가
			for (int i = 0; i < 5; ++i)
			{
				int checkCount = 0;
				for (int j = 0; j < 5; ++j)
				{
					if (arrAI[i + j * 5] == 0)	++checkCount;
				}
				// 그 줄 모두가 점수를 획득
				assessmentArr[i] += checkCount;
				assessmentArr[i + 1 * 5] += checkCount;
				assessmentArr[i + 2 * 5] += checkCount;
				assessmentArr[i + 3 * 5] += checkCount;
				assessmentArr[i + 4 * 5] += checkCount;
			}

			// 대각선 평가(왼쪽에서 오른)			
			int checkCount = 0;

			for (int i = 0; i < 5; ++i)
			{
				if (arrAI[i * 6] == 0)	++checkCount;
			}

			// 그 줄 모두가 점수를 획득
			for (int i = 0; i < 5; ++i)
			{
				assessmentArr[i * 6] += checkCount;
			}

			// 대각선 평가(오른쪽에서 왼)
			checkCount = 0;
			for (int i = 0; i < 5; ++i)
			{
				if (arrAI[4 + i * 4] == 0)	++checkCount;
			}

			// 그 줄 모두가 점수를 획득
			for (int i = 0; i < 5; ++i)
			{
				assessmentArr[4 + i * 4] += checkCount;
			}

			hardAI = 0; // AI가 선택할 빙고판의 INDEX
			int hardAINum = 0; // 평가 점수 변수
			for (int i = 0; i < 25; ++i)
			{
				// 가장 점수가 높지만 이미 체크가 된 숫자가 아닌 숫자를 찾기!
				if (assessmentArr[i] > hardAINum && arrAI[i] != 0)
				{
					hardAINum = assessmentArr[i]; // 점수 저장
					hardAI = i;					  // index 저장
				}
			}

			// 가장 큰 점수를 가진 index를 bingo check
			aiPick = arrAI[hardAI];

			// 플레이어 빙고판에 AI의 숫자 체크
			for (int i = 0; i < 25; ++i)
			{
				if (aiPick == arrAI[i])
				{
					arrAI[i] = 0;
				}
				if (aiPick == arr[i])
				{
					arr[i] = 0;
					++count;
				}
			}
		}
	}

	cout << "게임이 종료되었습니다." << endl;

	system("pause");

	return 0;
}