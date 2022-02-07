#include <iostream>
#include <conio.h>
using namespace std;

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
*/

struct _tagPoint
{
	int x;
	int y;
};


//typedef 타입을 재정의하는 기능이다.
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;


void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;


	pEndPos->x = 19;
	pEndPos->y = 19;


	*pPlayerPos = *pStartPos;
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
	strcpy_s(Maze[10],"00111100011000000000");
	strcpy_s(Maze[11],"00001000001000000000");
	strcpy_s(Maze[12],"00001110001111000000");
	strcpy_s(Maze[13],"00000010000001110000");
	strcpy_s(Maze[14],"00011110000000010000");
	strcpy_s(Maze[15],"00110000000111110000");
	strcpy_s(Maze[16],"00100000000100000000");
	strcpy_s(Maze[17],"00111100000111100000");
	strcpy_s(Maze[18],"00000111110000100000");
	strcpy_s(Maze[19],"00011100010000111100");
	strcpy_s(Maze[20],"00010000010011100113");


}

//미로 출력 반복
void OutPut(char Maze[21][21],PPOINT pPlayerPos)
{
	for (int i = 0; i < 21; ++i)
	{
		for (int j = 0; j < 21; ++j)
		{
			if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "☆";

			else if (Maze[i][j] == '0')
				cout << "■";

			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "★";

			else if (Maze[i][j] == '3')
				cout << "◎";
		}
		cout << endl;
	}
		
	
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0)
	{
		//벽인지 체크한다.
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0')
		{
			--pPlayerPos->y;
		}
	}
}


void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 < 21)
	{
		//벽인지 체크한다.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0')
		{
			++pPlayerPos->y;
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x - 1 >= 0)
	{
		//벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0')
		{
			--pPlayerPos->x;
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20)
	{
		//벽인지 체크한다.
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0')
		{
			++pPlayerPos->x;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cinput)
{
	switch (cinput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;

	}
}




int main()
{

	// 20X20 미로를 만들어준다.
	char strMaze[21][21] = {};

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	// 미로를 설정한다.
	SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

	while (true)
	{
		system("cls");
		// 미로를  출력한다.
		OutPut(strMaze, &tPlayerPos);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y && tEndPos.y)
		{
			cout << "목표지점에 도착하였습니다" << endl;
			break;
		}

		cout << "W : 위 S : 아래 A : 왼쪽 D : 오른쪽 Q : 종료";
		char cinput = _getch();

		if (cinput == 'q' || cinput == 'Q')
			break;

		MovePlayer(strMaze, &tPlayerPos, cinput);

	}
	return 0;
}

