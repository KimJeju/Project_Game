//�Ʒ� �Լ��� �� ������� �� �ѹ��� ���Խ�Ű�ڴٴ� �ǹ��̴�. 
#pragma once


#include <iostream>
using namespace std;

// ������Ͽ��� �����Լ� ����κ��� ������ش�.

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

	//���� ���� ������带 ������ ������ ����
	_tagNode* pNext;
	_tagNode* pPrev;

}NODE, * PNODE;

typedef struct _tagList
{
	// pbegin �� pEnd �� ��������� ó���� ���� �ǹ��ϵ��� �����.
	// ���� �����͸� �����ϴ� ���� �ƴϴ�. ���� �����͸� �����ϴ� ���� bBegin�� bEnd ���̿� �����ϰ� ����� �ش�
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
	//�̸��� ���� �������۸� ����� ���� clear.igore
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSIze - 1);
}

void InitLIst(PLIST pList);
//void CLearList(PLIST pLIst);
void DestroyList(PLIST pList);
void Pust_Back();
void Pust_Front();