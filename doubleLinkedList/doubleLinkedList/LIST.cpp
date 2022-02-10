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

	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	// 시작 노드의 다음 노드는 마지막 노드이다
	pList->pBegin->pNext = pList->pEnd;

	// 마지막 노드의 이전 노드는 시작 노드이다.
	pList->pEnd->pPrev = pList->pBegin;

	// 마지막 노드에 다음 노드는 없으므로 NULL
	pList->pEnd->pNext = NULL;

	// 시작 노드에 이전 노드는 없으므로 NULL
	pList->pBegin->pPrev = NULL;

}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNext;
		pNode = pNode->pNext;
	}

	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
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
	PNODE pPrev = pList->pEnd->pPrev;
	

	// pENd 노드 이전 노드의 다음으로 추가할 노드를 지정한다.
	pNode->pNext = pNode;
	
	// 추가할 노드의 이전 노들 End의 이전 노드를 지정한다.
	pNode->pPrev = pPrev;

	// 새로 추가할 노드의 다음노드를 pEnd에 연결한다.
	pNode->pNext = pList->pEnd;

	// pEnd 노드의 이전 노드로 새로 추가할 노드를 지정한다.
	pList->pEnd->pPrev = pNode;

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
		pNode = pList->pBegin->pNext;

		while (pNode != pList->pEnd)
		{
			OutPutStudent(&pNode->tStudent);
			pNode = pNode->pNext;

			break;
		}

		case
		OT_INVERSE:
		// 역방향으로 출력을 할 때는 enddp 이전 노드를 얻어오고 계속 이전 노드로 진행한다
		// begin과 같아질 경우 반복을 종료한다
			pNode = pList->pEnd->pPrev;

			//역방향으로 들어가기 떄문에 노드가 begin과 같아지면 더이상 출력할 노드가 없으므로 반복을 종료한다.
			while (pNode != pList->pBegin)
			{
				OutPutStudent(&pNode->tStudent);
				pNode = pNode->pPrev;
			}

		break;
	}

	cout << "학생수 :" << pList->iSize << endl;
	system("pause");
	}

void Search(PLIST pList)
{
	system("cls");
	cout << "============ 학생탐색 ==========" << endl;

	cout << "탐색할 이름을 입력하세요 ;";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			OutPutStudent(&pNode->tStudent);
			system("pause");
			return;
		}

		pNode = pNode->pNext; 
	}

	cout << "학생을 찾을 수 없습니다." << endl;
	system("Pause");
}


void DELETE(PLIST pList)
{

	system("cls");
	cout << "============ 학생삭제 =============" << endl;
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			//현재 지울 노드의 이전노드의 다음은 현재 지울 노드로 되어있다.
			//그런데 지울 노드는 지워져야 하기때문에 이전 노드에 다음 노드를 지울 노드의 다음 노드로 준다.
			//다음 노드의 이전은 현재노드인데 이전 노드로 준다
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << strName << "학생을 삭제하였습니다" << endl;
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}
	cout << "삭제할 대상이 없습니다" << endl;
	system("pause");
}

void Sort(PLIST pList)
{

	system("cls");
	cout << "============ 학생정렬 =============" << endl;

	cout << "1, 학점기준" << endl;
	cout << "2. 평균기준" << endl;
	cout << "메뉴를 선택하세요 :";
	int iInput = InputInt();

	if (iInput <= ST_NONE || iInput > ST_AVG)
	{
		cout << "잘못 선택하였습니다." << endl;
		system("pause");
		return;
	}
	
	PNODE pFirst = pList->pBegin->pNext;
	PNODE pSecond = pFirst->pNext;


	//First 는 End의 이전 노드와 같아지게 되면 더이상 비교할 노드가 없으므로 종료한다
	while (pFirst != pList->pEnd->pPrev)
	{
		//second 는 무조건 first 노드 다음 노드부터  검사를 시작한다.
		pSecond = pFirst->pNext;
		while (pSecond != pList->pEnd)
		{
			bool bSwap = false;

			//second는 End 이전 까지 반복해야 하므로 ENd가 아닐동안만 반복한다.
			switch (iInput)
			{
			case ST_NUMBER:
				if (pFirst->tStudent.iNumber > pSecond->tStudent.iNumber)
					bSwap = true;
				break;

			case ST_AVG:
				if (pFirst->tStudent.fAvg > pSecond->tStudent.fAvg)
					bSwap = true;
				break;
			}

			//bool변수 bSwap이 true 일 경우 두 노드를 바꿔야한다.

			if (bSwap == true)
			{
				// FIrst 노드에 이전과 다음 노드를 저장한다.
				PNODE pFirstPrev = pFirst->pPrev;
				PNODE pFirstNext = pFirst->pNext;

				//Second 노드에 이전과 다음 노드를 저장한다.
				PNODE pSecondPrev = pSecond->pPrev;
				PNODE pSecondNext = pSecond->pNext;

				// 두 노드를 바꿔준다.
				PNODE pTemp = pFirst;
				pFirst = pSecond;
				pSecond = pTemp;



				// 위에서 두 노드가 서로 바꼈으므로 연결되어있던 pNext 와 pPrev 도 바꿔주어야한다.
				// 그래서 pFirtstPrev 노드의 다음 노드로 바뀐 pFirst를 저장하고
				// 바뀐 pFirst 의 이전 노드로 pFirstPrev 노드를 지정해준다.

				// 다음 노드들도 마찬가지로 교체해 준다.
				pFirstPrev->pNext = pFirst;
				pFirst->pPrev = pFirstPrev;

				pFirstNext->pPrev = pFirst;
				pFirst->pNext = pFirstPrev;

				pSecondPrev->pNext = pSecond;
				pSecond->pPrev = pSecondPrev;

				pSecondNext->pPrev = pFirst;
				pSecond->pNext = pSecondPrev;
			}
		}
	}

	cout << "정렬이 완료되었습니다." << endl;
	system("pause");



}




