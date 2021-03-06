#include <iostream>
using namespace std;

#define NAME_SIZE 32

enum MAIN_MENU
{
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEACH,
	MM_OUTPUT,
	MM_EXIT
};

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

/*
링크드리스트 : 자료구조의 한 종류이다. 자료구조란 데이터를 관리하는 방법을 이야기 한다.
링크드리스트는 데이터 목록을 연결시켜서 접근할 수 있는 구조를 제공한다.
링크드리스트는 데이터를 저장하기 위한 노드라는 것이 존재한다. 각 노드에 특징은
다음 노드를 알 수 있게 된다. [다음노드에 메모리 주소를 저장한다는 의미]

리스트는 선형구조로 되어있다. 그렇기 떄문에 배열처럼  특정 요소에 바로 접근이 불가능하다
무조건 앞에서부터 차례대로 타고 들어가야한다.

노드를 새로 추가할 떄는 노드를 생성하고 마지막 노드에 연결만 해주면 되기 떄문에 개수에 제한이 없다.
*/


//리스트를 만든다.
typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode *pNext;
}NODE, *PNODE;


//리스트 구조체를 만들어준다.
typedef struct _tagList
{
	PNODE pBegin;
	PNODE pEnd;
	int isize;
}LIST,*PLIST;

int InputInt()
{
	int iInput;
	cin >> iInput;

	if(cin.fail())
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

void initList(PLIST pList)
{
	//포인터는 가급적이면 초기화할 때 NULL(0)으로 초기화 해두고 사용하는 것이 좋다
	//이유는 0은 false 0이 아닌 모든 수는 true 이기 떄문이다
	//초기화를 하지 않을 경우 쓰레기 값이 들어가 있는데 그 쓰레기 값 조차 true 이다.

	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->isize = 0;
}

//메뉴를 만든다
int OutPutMenu()
{
	system("cls");
	cout << "1. 학생추가" << endl;
	cout << "2. 학생삭제" << endl;
	cout << "3. 학생탐색" << endl;
	cout << "4. 학생출력" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요" << endl;
	int iInput = InputInt();

	if (iInput <= MM_NONE || iInput > MM_EXIT)
		return MM_NONE;

	return iInput;
}

void Insert(PLIST pList)
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

	//추가할 리스트 노드를 생성한다.

	PNODE pNode = new NODE;


	//현재 추가하는 노드는 가장 마지막에 추가할 노드기 떄문에 다음 노드가 존재하지 않는다.
	//그로므로 다음 노드는 NULL로 초기화 하고 정보는 뒤에서 입력받은 학생 정보를 주도록 한다.
	pNode->pNext = NULL;
	pNode->tStudent = tStudent;


	if (pList->pBegin == NULL)
		pList->pBegin = pNode;

	else
		pList->pEnd->pNext = pNode;


	pList->pEnd = pNode;

	++pList->isize;
}


void ClearList(PLIST pList)
{

	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}


	pList->pBegin = NULL;
	pList->pEnd = NULL;
	pList->isize = 0;
}


// const 포인터 이기 때문에 가르키는 대상의 값을 변경할 수 없다.
void OutPutStudent(const PSTUDENT pStudent)
{
	cout << "이름 :" << pStudent->strName << "\t학번 :" << pStudent->iNumber << endl;
	cout << "국어 :" << pStudent->ikor << "\t영어 :" << pStudent->iEng << endl;
	cout << "수학 :" << pStudent->iMath << endl;
	cout << "총점 :" << pStudent->itotal << "\t평균 :" << pStudent->fAvg << endl;
}
void OutPut(PLIST pList)
{
	system("cls");
	cout << "=========== 학생출력 ==========" << endl;

	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		OutPutStudent(&pNode->tStudent);
		pNode = pNode->pNext;
	}

	cout << "학생수 :" << pList->isize << endl;
	system("pause");
}


void Search(PLIST pList)
{

	system("cls");
	cout << "=========== 학생탐색 ==========" << endl;

	cout << "탐색할 이름을 입력하세요";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin;

	while (pNode != NULL)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			OutPutStudent(&pNode->tStudent);
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}
	cout << "학생이 없습니다" << endl;
	system("pause");
}


void Delete(PLIST pList)
{
	system("cls");
	cout << "=========== 학생삭제 ==========" << endl;

	cout << "삭제할 이름을 입력하세요";

	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin;
	PNODE pPrev = NULL;

	while (pNode != NULL)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			cout << strName << "학생삭제" << endl;
			//지울 노드에 다음 노드를 얻어온다.
			PNODE pNext = pNode->pNext;

			//만약 이전 노드가 NULL이라면 제일 첫번째 노드를 지운다는 의미이다.
			if (pPrev == NULL)
			{
				delete pNode;
				pList->pBegin = pNext;

				if (pNext == NULL)
					pList->pEnd = NULL;
			}

			// 이전 노드가 있을 경우에는 이전 노드에 다음을 지운 노드의 다음으로 연결해준다
			else
			{
				delete pNode;
				pPrev->pNext = pNext;

				if (pNext == NULL)
					pList->pEnd = pPrev;
			}

			cout << strName << "학생 삭제완료" << endl;

			--pList->isize;
			system("pause");
			return;
		}
		// 해당 학생이 아니라면 현재 노드가 이전 노드가 된다
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	cout << "삭제할 학생을 찾을 수 없습니다" << endl;
	system("pause");
}



int main()
{

	LIST tList;

	initList(&tList);

	while (true)
	{
		int iMenu = OutPutMenu();

		if (iMenu == MM_EXIT)
			break;

		switch (iMenu)
		{
		case MM_INSERT:
			Insert(&tList);
			break;

		case MM_DELETE:
			Delete(&tList);
			break;

		case MM_SEACH:
			Search(&tList);
			break;
		case MM_OUTPUT:
			OutPut(&tList);
			break;
		}
	}
	ClearList(&tList);

	return 0;
}
