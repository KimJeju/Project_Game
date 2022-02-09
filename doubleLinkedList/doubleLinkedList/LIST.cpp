#include "LISt.h"
using namespace std;

// ����Ʈ �ʱ�ȭ
void InitLIst(PLIST pList)
{
	pList->iSize = 0;

	pList->bBegin = new NODE;
	pList->bEnd = new NODE;

	// ���� ����� ���� ���� ������ ����̴�
	pList->bBegin->pNext = pList->bEnd;

	// ������ ����� ���� ���� ���� ����̴�.
	pList->bEnd->pPrev = pList->bBegin;

	// ������ ��忡 ���� ���� �����Ƿ� NULL
	pList->bEnd->pNext = NULL;

	// ���� ��忡 ���� ���� �����Ƿ� NULL
	pList->bBegin->pPrev = NULL;

}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->bBegin;

	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNext;
		pNode = pNext;
	}

	pList->iSize = 0;
	pList->bBegin = NULL;
	pList->bEnd = NULL;
}

void Pust_Back()
{
}

void Pust_Front()
{
}

