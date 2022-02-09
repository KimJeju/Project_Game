//아래 함수는 이 헤더파일 딱 한번만 포함시키겠다는 의미이다. 
#pragma once


#include <iostream>
using namespace std;

// 헤더파일에는 보통함수 선언부분을 만들어준다.

#define NAME_SIZE 32



typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int ikor;
	int iEng;
	int iMath;
	int itotal;
	float fAvg;
}STUDENT, * PSTUDENT;


typedef struct _tagNode
{
	STUDENT tStudent;

	//이전 노드와 다음노드를 저장할 포인터 변수
	_tagNode* pNext;
	_tagNode* pPrev;

}NODE, * PNODE;

typedef struct _tagList
{
	// pbegin 과 pEnd 는 명시적으로 처음과 끝을 의미하도록 만든다.
	// 실제 데이터를 저장하는 노드는 아니다. 실제 데이터를 저장하는 노드는 bBegin과 bEnd 사이에 존재하게 만들어 준다
	PNODE bBegin;
	PNODE bEnd;
	int iSize;
}LIST, * PLIST;



int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}


void InputString(char* pString, int iSIze)
{
	//이름을 띄어쓰는 에러버퍼를 지우기 위한 clear.igore
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSIze - 1);
}

void InitLIst(PLIST pList);
//void CLearList(PLIST pLIst);
void DestroyList(PLIST pList);
void Pust_Back();
void Pust_Front();