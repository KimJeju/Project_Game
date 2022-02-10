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

	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	// ���� ����� ���� ���� ������ ����̴�
	pList->pBegin->pNext = pList->pEnd;

	// ������ ����� ���� ���� ���� ����̴�.
	pList->pEnd->pPrev = pList->pBegin;

	// ������ ��忡 ���� ���� �����Ƿ� NULL
	pList->pEnd->pNext = NULL;

	// ���� ��忡 ���� ���� �����Ƿ� NULL
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
	PNODE pPrev = pList->pEnd->pPrev;
	

	// pENd ��� ���� ����� �������� �߰��� ��带 �����Ѵ�.
	pNode->pNext = pNode;
	
	// �߰��� ����� ���� ��� End�� ���� ��带 �����Ѵ�.
	pNode->pPrev = pPrev;

	// ���� �߰��� ����� ������带 pEnd�� �����Ѵ�.
	pNode->pNext = pList->pEnd;

	// pEnd ����� ���� ���� ���� �߰��� ��带 �����Ѵ�.
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
		cout << "=========== �л���� ==========" << endl;
		cout << "1.������ ���" << endl;
		cout << "2.������ ���" << endl;
		cout << "�޴��� ��Ź�ϼ��� :";
		iMenu = InputInt();

		if (iMenu >= OT_NONE && iMenu <= OT_INVERSE)
			break;
	}

	PNODE pNode = NULL;

	switch (iMenu)
	{
		case
		OT_OUTPUT:
		// �߰��Ǵ� ������� begin �� End ���̿� ��ġ�ȴ�. �׷��Ƿ� begin�� ���� ��带 ���´�.
		pNode = pList->pBegin->pNext;

		while (pNode != pList->pEnd)
		{
			OutPutStudent(&pNode->tStudent);
			pNode = pNode->pNext;

			break;
		}

		case
		OT_INVERSE:
		// ���������� ����� �� ���� enddp ���� ��带 ������ ��� ���� ���� �����Ѵ�
		// begin�� ������ ��� �ݺ��� �����Ѵ�
			pNode = pList->pEnd->pPrev;

			//���������� ���� ������ ��尡 begin�� �������� ���̻� ����� ��尡 �����Ƿ� �ݺ��� �����Ѵ�.
			while (pNode != pList->pBegin)
			{
				OutPutStudent(&pNode->tStudent);
				pNode = pNode->pPrev;
			}

		break;
	}

	cout << "�л��� :" << pList->iSize << endl;
	system("pause");
	}

void Search(PLIST pList)
{
	system("cls");
	cout << "============ �л�Ž�� ==========" << endl;

	cout << "Ž���� �̸��� �Է��ϼ��� ;";
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

	cout << "�л��� ã�� �� �����ϴ�." << endl;
	system("Pause");
}


void DELETE(PLIST pList)
{

	system("cls");
	cout << "============ �л����� =============" << endl;
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;

	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			//���� ���� ����� ��������� ������ ���� ���� ���� �Ǿ��ִ�.
			//�׷��� ���� ���� �������� �ϱ⶧���� ���� ��忡 ���� ��带 ���� ����� ���� ���� �ش�.
			//���� ����� ������ �������ε� ���� ���� �ش�
			pNode->pPrev->pNext = pNode->pNext;
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << strName << "�л��� �����Ͽ����ϴ�" << endl;
			system("pause");
			return;
		}

		pNode = pNode->pNext;
	}
	cout << "������ ����� �����ϴ�" << endl;
	system("pause");
}

void Sort(PLIST pList)
{

	system("cls");
	cout << "============ �л����� =============" << endl;

	cout << "1, ��������" << endl;
	cout << "2. ��ձ���" << endl;
	cout << "�޴��� �����ϼ��� :";
	int iInput = InputInt();

	if (iInput <= ST_NONE || iInput > ST_AVG)
	{
		cout << "�߸� �����Ͽ����ϴ�." << endl;
		system("pause");
		return;
	}
	
	PNODE pFirst = pList->pBegin->pNext;
	PNODE pSecond = pFirst->pNext;


	//First �� End�� ���� ���� �������� �Ǹ� ���̻� ���� ��尡 �����Ƿ� �����Ѵ�
	while (pFirst != pList->pEnd->pPrev)
	{
		//second �� ������ first ��� ���� ������  �˻縦 �����Ѵ�.
		pSecond = pFirst->pNext;
		while (pSecond != pList->pEnd)
		{
			bool bSwap = false;

			//second�� End ���� ���� �ݺ��ؾ� �ϹǷ� ENd�� �ƴҵ��ȸ� �ݺ��Ѵ�.
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

			//bool���� bSwap�� true �� ��� �� ��带 �ٲ���Ѵ�.

			if (bSwap == true)
			{
				// FIrst ��忡 ������ ���� ��带 �����Ѵ�.
				PNODE pFirstPrev = pFirst->pPrev;
				PNODE pFirstNext = pFirst->pNext;

				//Second ��忡 ������ ���� ��带 �����Ѵ�.
				PNODE pSecondPrev = pSecond->pPrev;
				PNODE pSecondNext = pSecond->pNext;

				// �� ��带 �ٲ��ش�.
				PNODE pTemp = pFirst;
				pFirst = pSecond;
				pSecond = pTemp;



				// ������ �� ��尡 ���� �ٲ����Ƿ� ����Ǿ��ִ� pNext �� pPrev �� �ٲ��־���Ѵ�.
				// �׷��� pFirtstPrev ����� ���� ���� �ٲ� pFirst�� �����ϰ�
				// �ٲ� pFirst �� ���� ���� pFirstPrev ��带 �������ش�.

				// ���� ���鵵 ���������� ��ü�� �ش�.
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

	cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	system("pause");



}




