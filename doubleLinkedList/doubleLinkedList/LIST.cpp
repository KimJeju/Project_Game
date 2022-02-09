#include "LISt.h"
using namespace std;

void OutPutStudent(const PSTUDENT pStudent)
{
	cout << "�̸� :" << pStudent->strName << "\t�й� :" << pStudent->iNumber << endl;
	cout << "���� :" << pStudent->ikor << "\t���� :" << pStudent->iEng << endl;
	cout << "���� :" << pStudent->iMath << endl;
	cout << "���� :" << pStudent->itotal << "\t��� :" << pStudent->fAvg << endl;
}


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



void Pust_Back(PLIST pList)
{
	system("cls");
	cout << "=========== �л��߰� ==========" << endl;
	STUDENT tStudent = {};

	cout << "�̸� :";
	InputString(tStudent.strName, NAME_SIZE);


	cout << "�й� :";
	tStudent.iNumber = InputInt();

	cout << "���� :";
	tStudent.ikor = InputInt();

	cout << "���� :";
	tStudent.iEng = InputInt();

	cout << "���� :";
	tStudent.iMath = InputInt();

	tStudent.itotal = tStudent.ikor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.itotal / 3.f;


	PNODE pNode = new NODE;

	pNode->tStudent = tStudent;

	// ���� �߰��Ǵ� ���� END ��忡 ���� ���� END ��� ���̿� �߰� �Ǿ�� �Ѵ�.
	// �׷��� END�� prev ��带 ���س��´� .
	PNODE pPrev = pList->bEnd->pPrev;
	

	// pENd ��� ���� ����� �������� �߰��� ��带 �����Ѵ�.
	pNode->pNext = pNode;
	
	// �߰��� ����� ���� ��� End�� ���� ��带 �����Ѵ�.
	pNode->pPrev = pPrev;

	// ���� �߰��� ����� ������带 pEnd�� �����Ѵ�.
	pNode->pNext = pList->bEnd;

	// pEnd ����� ���� ���� ���� �߰��� ��带 �����Ѵ�.
	pList->bEnd->pPrev = pNode;

	++pList->iSize;


}


void Pust_Front()
{
}

void OutPut(PLIST pList)
{
	system("cls");
	cout << "=========== �л���� ==========" << endl;
	cout << "1.������ ���" << endl;
	cout << "2.������ ���" << endl;
	cout << "�޴��� ��Ź�ϼ��� :";
	int iMenu = InputInt();


}
