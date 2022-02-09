#include "LISt.h"
using namespace std;

void OutPutStudent(const PSTUDENT pStudent)
{
	cout << "이름 :" << pStudent->strName << "\t학번 :" << pStudent->iNumber << endl;
	cout << "국어 :" << pStudent->ikor << "\t영어 :" << pStudent->iEng << endl;
	cout << "수학 :" << pStudent->iMath << endl;
	cout << "총점 :" << pStudent->itotal << "\t평균 :" << pStudent->fAvg << endl;
}


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



void Pust_Back(PLIST pList)
{
	system("cls");
	cout << "=========== 학생추가 ==========" << endl;
	STUDENT tStudent = {};

	cout << "이름 :";
	InputString(tStudent.strName, NAME_SIZE);


	cout << "학번 :";
	tStudent.iNumber = InputInt();

	cout << "국어 :";
	tStudent.ikor = InputInt();

	cout << "영어 :";
	tStudent.iEng = InputInt();

	cout << "수학 :";
	tStudent.iMath = InputInt();

	tStudent.itotal = tStudent.ikor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.itotal / 3.f;


	PNODE pNode = new NODE;

	pNode->tStudent = tStudent;

	// 새로 추가되는 노드는 END 노드에 이전 노드와 END 노드 사이에 추가 되어야 한다.
	// 그래서 END의 prev 노드를 구해놓는다 .
	PNODE pPrev = pList->bEnd->pPrev;
	

	// pENd 노드 이전 노드의 다음으로 추가할 노드를 지정한다.
	pNode->pNext = pNode;
	
	// 추가할 노드의 이전 노들 End의 이전 노드를 지정한다.
	pNode->pPrev = pPrev;

	// 새로 추가할 노드의 다음노드를 pEnd에 연결한다.
	pNode->pNext = pList->bEnd;

	// pEnd 노드의 이전 노드로 새로 추가할 노드를 지정한다.
	pList->bEnd->pPrev = pNode;

	++pList->iSize;


}


void Pust_Front()
{
}

void OutPut(PLIST pList)
{

	int iMenu;

	while (true)
	{

		system("cls");
		cout << "=========== 학생출력 ==========" << endl;
		cout << "1.정방향 출력" << endl;
		cout << "2.역방향 출력" << endl;
		cout << "메뉴를 선탁하세요 :";
		iMenu = InputInt();

		if (iMenu >= OT_NONE && iMenu <= OT_INVERSE)
			break;
	}

	PNODE pNode = NULL;

	switch (iMenu)
	{
		case
		OT_OUTPUT:
		// 추가되는 노느들은 begin 과 End 사이에 배치된다. 그러므로 begin에 다음 노드를 얻어온다.
		pNode = pList->bBegin->pNext;

		while (pNode != pList->bEnd)
		{
			OutPutStudent(&pNode->tStudent);
			pNode = pNode->pNext;

			break;
		}

		case
		OT_INVERSE:
		// 역방향으로 출력을 할 때는 enddp 이전 노드를 얻어오고 계속 이전 노드로 진행한다
		// begin과 같아질 경우 반복을 종료한다
			pNode = pList->bEnd->pPrev;

			//역방향으로 들어가기 떄문에 노드가 begin과 같아지면 더이상 출력할 노드가 없으므로 반복을 종료한다.
			while (pNode != pList->bBegin)
			{
				OutPutStudent(&pNode->tStudent);
				pNode = pNode->pPrev;
			}

		break;
	}

	cout << "학생수 :" << pList->iSize << endl;
	system("pause");
	}




