#include <iostream>
#include <time.h>
using namespace std;

enum SRP // 게임을 위한 변수 생성
{
SRP_R = 1,
SRP_P,
SRP_S,
SRP_END
};

int main() 
{

	srand((unsigned int)time(0));// AI 난수 설정을 위한 난수변수 선언

	int Player, iAi; //플레이어와 AI 변수 선언


	while (true) // 메뉴만들기
	{
		cout << "1.가위" << endl;
		cout << "2.바위" << endl;
		cout << "3.보" << endl;
		cout << "4.종료" << endl;
		cout << "메뉴를 선택하세요 :";

		cin >> Player;

		// 다른 수를 입력했을 시 다시 처음부터 시작하는 코드
		if (Player < SRP_R || Player > SRP_END) // 예 -1 이나 5를 입력했을 시  출력
		{
			cout << "잘못된 값을 입력하였습니다." << endl;

			//일시정지
			system("pause");
			//continue; 반복문을 시작점으로 이동 시켜주는 함수
			continue;
		}
		else if (Player == SRP_END)
			break;

		//봇이 선택한다.
		iAi = rand() & 3 + SRP_S; // rand() 뒤에 나머지 함수를 선언함으로서 어떤 수를 3(가위,바위,보)으로 나눴을 때 나머지를 구하고 그 값에 1을 더함

		//AI가 입력한 값 출력
		switch (iAi)
		{
		case SRP_S:
			cout << "가위를 선택하였습니다" << endl;
			break;

		case SRP_R:
			cout << "바위를 선택하였습니다" << endl;
			break;

		case SRP_P:
			cout << "바위를 선택하였습니다" << endl;
			break;

		};

		// 승부닷!
		int iWin = Player - iAi;
		
		/*
		가위바위보 게임 규칙

		- 승리조건 -
		1. 입력받은 두 값을 빼서 1 나올 시 승리  || 예) R - S = 2 - 1 = 1
		2. 입력받은 두값을 빼서 -2가 나올시 승리 || 예) S - P = 1 - 3 = -2

		- 무승부 조건 -
		1. 입력받은 두 수의 나머지가 0이라면 무승부

		- 패배 -
		1. 그 나머지
	
		*/
		//스위치 문으로 만들 승부 코드 짤 시
		switch (iWin)
		{
		case 1:
		case -2:
			cout << "Player 승" << endl;
			break;

		case 0:
			cout << "비김" << endl;
			break;

		default:
			cout << "Ai 승리" << endl;
			break;

		};
		/* if문으로 짤시
		if (iWin == 1 || iWin == -2)
			cout << "Player가 승리하였습니다" << endl;
		else if (iWin == 0)
			cout << "비겼습니다" << endl;
		else
			cout << "AI승리" << endl;


		*/
		system("pause");


	};
}

