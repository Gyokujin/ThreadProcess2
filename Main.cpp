#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    MyThread myThread;
    int count = 0;
    cout << "쓰레드를 몇 초 동안 실행할 것인가요?: ";
    cin >> count;

    myThread.start(count);
    myThread.waitUntilFinished(); // 내부 쓰레드가 끝날 때까지 대기

    cout << "\n쓰레드의 대기 시간을 입력하시오. 이 시간이 끝나면 Main 쓰레드가 종료됩니다.: ";
    int delayTime = 0;
    cin >> delayTime;

    this_thread::sleep_for(chrono::seconds(delayTime));
    myThread.stop();

    cout << "메인 쓰레드 종료" << endl;
    return 0;
}