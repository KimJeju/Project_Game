#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 파워아이템
6 : 벽밀기 아이템
7 : 투명아이템
8 : 웜홀
*/

// x.y축
struct _tagPoint
{
	int x;
	int y;
};


//typedef 타입을 재정의하는 기능이다.
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;

typedef struct _tagPlayer
{
	_tagPoint tPos;
	bool bWallpush;
	bool bPushOnOff;
	bool bTransparency;
	int iBombPower;
}PLAYER, * PPLAYER;


//미로 만들기 && 플레이어 위치 && 끝 위치 && 시작위치
void SetMaze(char Maze[21][21], PPLAYER pPlayer, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;


	pEndPos->x = 19;
	pEndPos->y = 19;


	pPlayer->tPos = *pStartPos;
	/*
	pPlayerPos->x = 0;
	pPlayerPos->y = 0;
	*/

	strcpy_s(Maze[0], "21100000000000000000");
	strcpy_s(Maze[1], "00111111110000000000");
	strcpy_s(Maze[2], "00100100011111110000");
	strcpy_s(Maze[3], "01100100000000010000");
	strcpy_s(Maze[4], "01000111110001110000");
	strcpy_s(Maze[5], "01000000001111110000");
	strcpy_s(Maze[6], "01100000000100000000");
	strcpy_s(Maze[7], "00100000000111100000");
	strcpy_s(Maze[8], "01100000000000111100");
	strcpy_s(Maze[9], "00100011111111100000");
	strcpy_s(Maze[10], "00111100011000000000");
	strcpy_s(Maze[11], "00001000001000000000");
	strcpy_s(Maze[12], "00001110001111000000");
	strcpy_s(Maze[13], "00000010000001110000");
	strcpy_s(Maze[14], "00011110000000010000");
	strcpy_s(Maze[15], "00110000000111110000");
	strcpy_s(Maze[16], "00100000000100000000");
	strcpy_s(Maze[17], "00111100000111100000");
	strcpy_s(Maze[18], "00000111110000100000");
	strcpy_s(Maze[19], "00011100010000111100");
	strcpy_s(Maze[20], "00010000010011100113");


}

//미로 출력 반복
void OutPut(char Maze[21][21], PPLAYER pPlayer)
{
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{

			if (Maze[i][j] == '4')
				cout << "♨";

			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "☆";

			else if (Maze[i][j] == '0')
				cout << "■";

			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "★";

			else if (Maze[i][j] == '3')
				cout << "◎";

			else if (Maze[i][j] == '5')
				cout << "㈜";

			else if (Maze[i][j] == '6')
				cout << "※";

			else if (Maze[i][j] == '7')
				cout << "＆";

		}
		cout << endl;
	}
	cout << "폭탄파워 :" << pPlayer->iBombPower << endl;
	cout << "벽통과 :";
	if (pPlayer->bTransparency)
		cout << "ON\t";

	else
		cout << "OFF\t";

	cout << "벽밀기 :";
	if (pPlayer->bWallpush)
	{
		cout << "가능 / " << endl;

		if (pPlayer->bPushOnOff)
			cout << "ON" << endl;

		else
			cout << "OFF" << endl;

	}
	else
		cout << "불가능 / OFF" << endl;

}

bool AddiTtem(char cItemType, PPLAYER pPlayer)
{
	if (cItemType == '5')
	{
		if (pPlayer->iBombPower < 5)
			++pPlayer->iBombPower;
		return true;
	}

	else if (cItemType == '6')
	{
		pPlayer->bWallpush = true;
		pPlayer->bPushOnOff =  true;
		return true;
	}

	else if (cItemType == '7')
	{
		pPlayer->bTransparency = true;
		return true;
	}

	return false;
}

//위로 움직이기 위한 함수
void MoveUp(char Maze[21][21], PPLAYER pPlayer)
{

	if (pPlayer->tPos.y - 1 >= 0)
	{
		//벽인지 체크한다.
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0' && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
		{
			--pPlayer->tPos.y;
		}

		// 벽 밀기가 가능하고 바로 윗칸이 벼긴 경우
		else if (pPlayer->bWallpush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0')
		{
			// 벽 밀기가 ON 상태인 경우
			if (pPlayer->bPushOnOff)
			{
				//위에 위칸이 0보다 크거나 같을 경우 인덱스가 있다는 의미
				if (pPlayer->tPos.y - 2 >= 0)
				{
					// 위의 위칸이 길이어야 밀기가 가능하다. 그러므로 길인지 체크한다
					if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.y;
					}

					//길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '1')
					{
						// 위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0';
						// 위의 칸이 벽인 것을 길로 만들어준다
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '1';
						// 플레이어를 이동시킨다.
						--pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					--pPlayer->tPos.y;
			}
			// 벽 밀기 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			--pPlayer->tPos.y;

		if (AddiTtem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}
}

//아래 움직임을 위한 함수
void MoveDown(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y + 1 < 21)
	{
		//벽인지 체크한다.
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
		{
			++pPlayer->tPos.y;
		}

		// 벽 밀기가 가능하고 바로 윗칸이 벼긴 경우
		else if (pPlayer->bWallpush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0')
		{
			// 벽 밀기가 ON 상태인 경우
			if (pPlayer->bPushOnOff)
			{
				//위에 위칸이 0보다 크거나 같을 경우 인덱스가 있다는 의미
				if (pPlayer->tPos.y + 2 < 20)
				{
					// 위의 위칸이 길이어야 밀기가 가능하다. 그러므로 길인지 체크한다
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.y;
					}

					//길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '1')
					{
						// 위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0';
						// 위의 칸이 벽인 것을 길로 만들어준다
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '1';
						// 플레이어를 이동시킨다.
						++pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					++pPlayer->tPos.y;
			}
			// 벽 밀기 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.y;
		}

		else if (pPlayer->bTransparency)
			++pPlayer->tPos.y;

		if (AddiTtem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}
}

// 왼쪽 움직임을 위한 함수
void MoveLeft(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x - 1 >= 0)
	{
		//벽인지 체크한다.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0' && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
		{
			--pPlayer->tPos.x;
		}
		// 벽 밀기가 가능하고 바로 윗칸이 벼긴 경우
		else if (pPlayer->bWallpush && Maze[pPlayer->tPos.y ][pPlayer->tPos.x - 1] == '0')
		{
			// 벽 밀기가 ON 상태인 경우
			if (pPlayer->bPushOnOff)
			{
				//위에 위칸이 0보다 크거나 같을 경우 인덱스가 있다는 의미
				if (pPlayer->tPos.x - 2 >= 0)
				{
					// 위의 위칸이 길이어야 밀기가 가능하다. 그러므로 길인지 체크한다
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.x;
					}

					//길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '1')
					{
						// 위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0';
						// 위의 칸이 벽인 것을 길로 만들어준다
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '1';
						// 플레이어를 이동시킨다.
						--pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency)
					--pPlayer->tPos.x;
			}
			// 벽 밀기 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.x;
		}


		else if (pPlayer->bTransparency)
			--pPlayer->tPos.x;

		if (AddiTtem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}
}

//오른쪽 움직임을 위한 함수
void MoveRight(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 < 20)
	{
		//벽인지 체크한다.
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0' && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
		{
			++pPlayer->tPos.x;
		}
		// 벽 밀기가 가능하고 바로 윗칸이 벼긴 경우
		else if (pPlayer->bWallpush && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '0')
		{
			// 벽 밀기가 ON 상태인 경우
			if (pPlayer->bPushOnOff)
			{
				//위에 위칸이 0보다 크거나 같을 경우 인덱스가 있다는 의미
				if (pPlayer->tPos.y + 2 <  20)
				{
					// 위의 위칸이 길이어야 밀기가 가능하다. 그러므로 길인지 체크한다
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.x;
					}

					//길일 경우 벽을 밀어낸다.
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '1')
					{
						// 위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '0';
						// 위의 칸이 벽인 것을 길로 만들어준다
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '1';
						// 플레이어를 이동시킨다.
						++pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					++pPlayer->tPos.x;
			}
			// 벽 밀기 OFF 상태일 경우
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.x;
		}


		else if (pPlayer->bTransparency)
			++pPlayer->tPos.x;

		if (AddiTtem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}
}


// 키보드 움직임을 위한 함수
void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cinput)
{
	switch (cinput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;

	}
}


// 포인터 변수를 const로 생성하면 가르키는 대상의 값을 변경할 수 있다.

//폭탄 설치를 위한 함수
void CreatBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '0')


		for (int i = 0; i < *pBombCount; ++i)
		{
			if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
				return;
		}

	pBombArr[*pBombCount] = pPlayer->tPos;
	++(*pBombCount);
	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

//폭탄 터지는거 처리
void Fire(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{

	for (int i = 0; i < *pBombCount; ++i)
	{
		Maze[pBombArr[i].x][pBombArr[i].y] = '1';


		//플레이어가 폭탄에 맞았을 때 시작점으로 보낸다
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
		{
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}

		for (int j = 1; j <= pPlayer->iBombPower; ++j)
		{
			if (pBombArr[i].y - j >= 0)
			{
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] = '0')

					//아이템 드랍 확률을 구한다.
					if (rand() % 100 < 20)
					{

						int iPrecnt = rand() % 100;
						if (rand() % iPrecnt < 70)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';

						else if (rand() % iPrecnt < 80)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';

						else
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
					}

					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';

				//플레이어가 폭탄에 맞았을 때 시작점으로 보낸다
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			//아래 폭탄
			if (pBombArr[i].y + j < 20)
			{
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] = '0')
				{
					if (rand() % 100 < 20)
					{

						int iPrecnt = rand() % 100;
						if (rand() % iPrecnt < 70)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';

						else if (rand() % iPrecnt < 80)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';

						else
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
					}

					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}

				//플레이어가 폭탄에 맞았을 때 시작점으로 보낸다
				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			//왼쪽
			if (pBombArr[i].y - j >= 0)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] = '0')
				{

					if (rand() % 100 < 20)
					{

						int iPrecnt = rand() % 100;
						if (rand() % iPrecnt < 70)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';

						else if (rand() % iPrecnt < 80)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';

						else
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
					}

					else
						Maze[pBombArr[i].y][pBombArr[i].x - j] = '1';
				}

				//플레이어가 폭탄에 맞았을 때 시작점으로 보낸다
				if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}

			//오른쪽
			if (pBombArr[i].y + j < 20)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] = '0')
				{
					if (rand() % 100 < 20)
					{

						int iPrecnt = rand() % 100;
						if (rand() % iPrecnt < 20)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';

						else if (rand() % iPrecnt < 10)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';

						else
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
					}

					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
				}

				//플레이어가 폭탄에 맞았을 때 시작점으로 보낸다
				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y)
				{
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}

	}

	*pBombCount = 0;
}

int main()
{
	srand((unsigned int)time(0));
	// 20X20 미로를 만들어준다.
	char strMaze[21][21] = {};

	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;
	POINT tBombPos[5];

	// 미로를 설정한다.
	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		// 미로를  출력한다.
		OutPut(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y && tEndPos.y)
		{
			cout << "목표지점에 도착하였습니다" << endl;
			break;
		}

		cout << "t : 폭탄설치 u : 폭탄터트리기 i : 벽밀기ON/OFF" << endl;
		cout << "W : 위 S : 아래 A : 왼쪽 D : 오른쪽 Q : 종료";
		char cinput = _getch();

		if (cinput == 'q' || cinput == 'Q')
			break;

		else if (cinput == 't' || cinput == 'T')
			CreatBomb(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cinput == 'u' || cinput == 'U')
			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cinput == 'i' || cinput == 'I')
		{
			if (tPlayer.bWallpush)
				tPlayer.bPushOnOff = !tPlayer.bPushOnOff;
		}

		else
			MovePlayer(strMaze, &tPlayer, cinput);

	}
	return 0;
}

