#include <iostream>
using namespace std;

class CListNode
{
	CListNode() :
		m_next(NULL),
		m_prev(NULL)
	{
	}

	~CListNode()
	{
	}


private:
	int m_iData;
	CListNode* m_next;
	CListNode* m_prev;
};

class CList
{
	CList()
	{
		m_pBegin = new CListNode;
		m_pEnd = new CListNode;
	}

	~CList()
	{
	}
private:
	CListNode* m_pBegin();
	CListNode* m_pEnd();
	int iSize;
};

int main()
{
	return 0;
}

