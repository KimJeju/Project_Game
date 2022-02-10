#include <iostream>
using namespace std;

/*
객체(object) : 모든 사물을 의미한다. C++ 에서 의미하는 것은 각 변수들도 객체로 취급할 수 있다.
			   하지만 객체지향은 프로그래밍을 지원하기 위해 지원 되는 수단은 class이다. class는 객체가 아니다. class는 객체를 만들기 위한 틀이다.

객체지향 프로그래밍(OOP) : 객체들의 관계를 설정해줘서 부품을 조립하듯이 객체들을 조립하여 완성된 프로그램을 만드는 방식이다.


클래스 선언방법 : class 클래스명 {};의 형태로 선언된다

코드블럭안에 멤버변수를 넣어 줄 수 있다. 단,함수도 멤버로 만들 수 있다.

클래스의 4가지 속성
1.캡슐화 : 클래스 안에 속하는 여러 변수 혹은 함수를 하나의 클래스로 묶어주는 기능을 말한다.
2.은닉화 : 클래스 안에 속하는 변수 혹은 함수를 내가 원하는 부분만 외부에 공개하고 외부에 공개하지 않을 수 있다.
           - public : 클래스 내부와 외부에서 모두 접근 가능한 방법이다.
		   - protected : 클래스 외부에서는 접근이 불가능하고 자기자신 내부나 자식 클래스 내부에서는 접근이 가능한 방법 이다.
		   = private :   자기자신 내부에서만 접근이 가능하고 외부나 자식 내부에서는 접근이 불가능한 방법.

3.상속성 : 클래스는 클래스와 클래스간에 부모,자식 관계를 형성할 수 있다. 자식 클래스는 부모클래스의 멤버를 물려받아 자신의 것처럼 사용할 수있다.
           단 private으로 되어 있는 멤버에는 접근이 불가능하다.

4.다형성 :  부모 자식관계로 상속관계가 형성되어 있는 클래스간에 서로 형변환이 가능한 성질을 말한다.

생성자와 소멸자

생성자 : 어떤 클래스를 이용해서 객체를 생성할 때 자동으로 호출되는 함수이다.
         객체 생성시 호출되는 함수이기 때문에 객체의 맴버변수를 초기화 할때 요긴하게 사용할 수 있다.
		 생성자를 만들어주지 않을 경우 내부적으로 기본생성자가 제공이 되어서 기본 생성자를 자동으로 호출해 주게 된다.

클래스명()
{
}

소멸자 : 어떤 클래스를 이용해서 생선한 객체가 메모리에서 해제될 때, 자동으로 호출되는 함수이다.
         객체를 사용하고 난뒤 마무리 작업을 해줄 때 유용하게 사용할 수 있다.

~클래스명()
{
}
의 형태로 선언된다.
*/

class CTracer
{
public:
	//생성자
	CTracer()
	{

		cout << "tracer 생성자" << endl;
		strcpy_s(m_strName, "트레이서");
	}

	//클래스 멤버 오버로딩
	CTracer(const char* pName)
	{
		strcpy_s(m_strName, pName);
		cout << "Name 생성자" << endl;
	}



	//initializer
	CTracer(const char* pName, int iFlash, int iBack) :
		m_iBack(iBack),
		m_iFlash(iFlash)
	{
		strcpy_s(m_strName, pName);

		cout << "Name,Flash,back 생성자" << endl;
		//m_iFlash = iFlash;

		//int a;
		//a = 10;
		//int b = 10;
	}

	//소멸자
	~CTracer()
	{
		cout << "tracer 소멸자" << endl;
	}
	// 클래스 멤버변수를 선언할때는 m_을 붙여준다.
	char m_strName[32];

public: //public 키워드 아래에 있는 멤버는 모두 외부에 접근이 가능하다.
	int m_iAttack;
	int m_iHP;

private:
	int m_iFlash;

private:
	int m_iBack;

public:
	void OutPut()
	{
		cout << "tracer OutPut" << endl;
		cout << "NAME :" << m_strName << endl;
	}

};


int main()
{
	CTracer tr1("한조",3,1);


	//main() 함수 안은 클래스 외부이기 떄문에 public 으로 설정되어 있는 멤버에만 접근이 가능하다.
	//tr1.m_iAttack = 9999;
	tr1.OutPut();

	return 0;
}