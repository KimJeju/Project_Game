#include "LISt.h"
using namespace std;

// 리스트 초기화
void InitLIst(PLIST pList)
{
	pList->iSize = 0;

	pList->bBegin = new NODE;
	pList->bEnd = new NODE;

	// 시작 노드의 다음 노드는 마지막 노드이다
	pList->bBegin->pNext = pList->bEnd;

	// 마지막 노드의 이전 노드는 시작 노드이다.
	pList->bEnd->pPrev = pList->bBegin;

	// 마지막 노드에 다음 노드는 없으므로 NULL
	pList->bEnd->pNext = NULL;

	// 시작 노드에 이전 노드는 없으므로 NULL
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

