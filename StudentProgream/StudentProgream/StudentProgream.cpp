#include <iostream>
using namespace std;

#define Address_SIZE 128
#define NAME_SIZE 32
#define STUDENT_MAX 10
#define PHONE_SIZE 14

struct _tagStudent
{
	char strName[NAME_SIZE];
	char strAddress[Address_SIZE];
	char strPhoneNumber[PHONE_SIZE];
	int INumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main()
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};
	//배열에 추가된 개수를 저장할 변수를 만들어준다
	int iStudentCount = 0;
	int iStdNumber = 1;

	char iStrName[NAME_SIZE] = {}; 
	
	// 스위치 밖에 변수를 사용하고 선연해야 

	/*
	C:\Users\kings\Dropbox\내 PC (DESKTOP-T269FTJ)\Desktop\C PROJECT\Project_Game\StudentProgream\StudentProgream\StudentProgream.cpp(141,3): error C2360: 'strSeachName' 초기화가 'case' 레이블에 의해 생략되었습니다.
	1>C:\Users\kings\Dropbox\내 PC (DESKTOP-T269FTJ)\Desktop\C PROJECT\Project_Game\StudentProgream\StudentProgream\StudentProgream.cpp(136): message : 'strSeachName' 선언을 참조하십시오.
	1>C:\Users\kings\Dropbox\내 PC (DESKTOP-T269FTJ)\Desktop\C PROJECT\Project_Game\StudentProgream\StudentProgream\StudentProgream.cpp(162,3): error C2361: 'strSeachName' 초기화가 'default' 레이블에 의해 생략되었습니다.
	1>C:\Users\kings\Dropbox\내 PC (DESKTOP-T269FTJ)\Desktop\C PROJECT\Project_Game\StudentProgream\StudentProgream\StudentProgream.cpp(136): message : 'strSeachName' 선언을 참조하십시오.

	위 에러가 뜨지않음
	*/

	while (true)
	{
		system("cls");

		// 메뉴를 출력한다
		cout << "1.학생등록" << endl;
		cout << "2.학생삭제" << endl;
		cout << "3.학생탐색" << endl;
		cout << "4.학생출력" << endl;
		cout << "5.종료" << endl;
		cout << "메뉴를 선택하세요 : " << endl;
		int iMENU;
		cin >> iMENU;

		//cin 은 만약 오른쪽에 int변수가 오면 정수를 입력해야한다. 오른쪽에 오는 변수타입에 맞춰서 값을 입력해야하는데
		//실수로 정수가 아닌 문자를 입력할 경우 에러가 발생한다. 그렇기 떄문에 예외처리로 에러가 발생했는지를 여기서 체크하여
		//에러가 발생하면 cin 내부의 에러버퍼를 비워주고 cin 내부에 입력버퍼가 있는데 입력버퍼는 입력한 값을 저장 해놓고
		// 그 값을 변수에 넣어주는 역할을 한다. 이 입력버퍼에 \n이 남아있으므로 버퍼를 순회하여 \n을 지워준다
		//버퍼 : 임시 저장공간

		//먼저 에러체크. cin.fail()을 했을 때 입력 에러가 발생했을 경우 true를 반환한다.
		if (cin.fail())
		{
			// 에러버퍼를 비워준다
			cin.clear();

			// 입력버퍼에 \n이 남아있으므로 입력버퍼를 검색하여 \n을 지워준다
			// 첫번쨰에는 검색하고자 하는 버퍼 크기를 지정 넉넉하게 1024 바이트정도 지정, 두번쨰는 찾고자하는 문자를 넣어준다.
			// 그래서 입력버퍼 처음부터 \n이 있는 곳 까지 찾아서 그 부분을 모두 지워서 다시 입력 받을 수 있도록 해준다.
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMENU == MENU_EXIT)
			break;

		switch (iMENU)
		{
		case MENU_INSERT:
			system("cls");
			cout << "=================== 학생추가 ==================" << endl;

			//등록 된 학생이 등록할 수 있는 최대치일 경우 더이상 등록되지않게 막는다.

			if (iStudentCount == STUDENT_MAX)
				break;


			// 학생정보를 추가한다. 학생정보는 성명, 주소, 전화번호
			// 국어, 영어, 수학 점수는 입력받고 학번, 총점, 평균은 연산을 통해 계산해준다. 
			// 이름을 입력받는다.
			cout << "이름 :";
			cin >> tStudentArr[iStudentCount].strName; 

			//cin과 cin.getline을 함께 쓸 경우 cin.getline을 무시하고 실행되는 오류가 있을 수 있기 때문에 아래 cin.ignore을 사용하여 위 엔터를 지워준다
			cin.ignore(1024, '\n');


			cout << "주소 :";
			//cin.getline 은 엔터가 쳐지기 전까지의 문자열을 반환해주며 cin.getline(함수[변수].필드, 가져올 크기) 로 구성된다.
			cin.getline(tStudentArr[iStudentCount].strAddress, Address_SIZE);

			cout << "전화번호" << endl;
			cin.getline(tStudentArr[iStudentCount].strPhoneNumber, PHONE_SIZE);

			cout << "국어 :";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어 :";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학 :";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal =
				tStudentArr[iStudentCount].iKor +
				tStudentArr[iStudentCount].iEng +
				tStudentArr[iStudentCount].iMath;
			
			tStudentArr[iStudentCount].fAvg =
				tStudentArr[iStudentCount].iTotal / 3.f;

			tStudentArr[iStudentCount].INumber = iStdNumber;
			++iStdNumber;
			++iStudentCount;

			cout << "학생 추가 완료" << endl;
		

			break;


		case MENU_DELETE:

			system("cls");

			cout << "=================== 학생삭제 ==================" << endl;

			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력해주세요 :";
			cin.getline(iStrName, NAME_SIZE);

			for (int i = 0; i < iStudentCount; ++i)
			{
				//학생을 삭제할 경우
				if (strcmp(tStudentArr[i].strName, iStrName) == 0)
				{
					for (int j = i; j < iStudentCount - 1; ++j)
					{
						tStudentArr[i] = tStudentArr[i + 1];
					}
				}
				-- iStudentCount;

				cout << "학생을 삭제하였습니다" << endl;
				break;
			}
			break;

		case MENU_SEARCH:
			system("cls");
			cout << "=================== 학생탐색 ==================" << endl;

			cin.ignore(1024, '\n');
			cout << "탐색할 학생의 이름을 입력해주세요 :";
			cin.getline(iStrName, NAME_SIZE);

			//등록되어 있는 학생 수 많큼 반복하여 학생을 찾는다.

			for (int i = 0; i < iStudentCount; ++i)
			{
				//학생을 찾았을 경우
				if (strcmp(tStudentArr[i].strName, iStrName) == 0)
				{
					cout << "이름 :" << tStudentArr[i].strName << endl;
					cout << "전화번호 :" << tStudentArr[i].strPhoneNumber << endl;
					cout << "주소 :" << tStudentArr[i].strAddress << endl;
					cout << "학번 :" << tStudentArr[i].INumber << endl;
					cout << "국어 :" << tStudentArr[i].iKor << endl;
					cout << "영어 :" << tStudentArr[i].iEng << endl;
					cout << "수학 :" << tStudentArr[i].iMath << endl;
					cout << "총점 :" << tStudentArr[i].iTotal << endl;
					cout << "평군 :" << tStudentArr[i].fAvg << endl << endl;
					break;
				}

			}
			break;


		case MENU_OUTPUT:
			system("cls");

			cout << "=================== 학생출력 ==================" << endl;

		
			//등록된 학생 수만큼 반복하며 학생 정보를 출력한다.

			for (int i = 0; i < iStudentCount; ++i)
			{
				cout << "이름 :" << tStudentArr[i].strName << endl;
				cout << "전화번호 :" << tStudentArr[i].strPhoneNumber << endl;
				cout << "주소 :" << tStudentArr[i].strAddress << endl;
				cout << "학번 :" << tStudentArr[i].INumber << endl;
				cout << "국어 :" << tStudentArr[i].iKor << endl;
				cout << "영어 :" << tStudentArr[i].iEng << endl;
				cout << "수학 :" << tStudentArr[i].iMath << endl;
				cout << "총점 :" << tStudentArr[i].iTotal << endl;
				cout << "평군 :" << tStudentArr[i].fAvg << endl << endl;
			}

			break;
		default:
			cout << "메뉴를 잘못 입력하였습니다" << endl;
			break;
		}
		system("pause");
	}
	return 0;
}
