
#include <time.h>
#include <iostream>
using namespace std;


int main()
{
    int iUpgrade = 0;
    cout << "업그레이드 수치를 입력하세요" << endl;
    cin >> iUpgrade;

    //강화확률을 구한다
    float fPercent = rand() % 10000 / 100.f;

    /*
    * 강화확률: 업그레이드가 0~3일때는 100 % | 4 ~ 6 : 40% | 7 ~  9 : 20% | 10 ~ 13 : 1% | 14 ~ 15 : 0.01
    */
    cout << "Upgrade" << iUpgrade << endl;
    cout << "Percent" << fPercent << endl;

    if (iUpgrade <= 3)
        cout << "강화성공" << endl;

    else if (4 <= iUpgrade && iUpgrade <= 6)
    {
        if (fPercent <= 40.f)
            cout << "강화성공" << endl;
        else
            cout << "실패" << endl;
    }
    else if (7 <= iUpgrade && iUpgrade <= 9) {
        if (fPercent <= 20.f)
            cout << "강화성공" << endl;
        else
            cout << "실패" << endl;
    }
    else if (10 <= iUpgrade && iUpgrade <= 13)
    {
        if (fPercent <= 1.f)
            cout << "강화성공" << endl;
        else
            cout << "실패" << endl;
    }
    else if (14 <= iUpgrade && iUpgrade <= 18)
    {
        if (fPercent <= 0.01f)
            cout << "강화성공" << endl;
        else
            cout << "실패" << endl;
    }
    else
    {
        cout << "더 이상 강화 할 수 없습니다." << endl;
    }
    system("pause");
}

