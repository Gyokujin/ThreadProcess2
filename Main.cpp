#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    MyThread myThread;
    int count = 0;
    cout << "�����带 �� �� ���� ������ ���ΰ���?: ";
    cin >> count;

    myThread.start(count);
    myThread.waitUntilFinished(); // ���� �����尡 ���� ������ ���

    cout << "\n�������� ��� �ð��� �Է��Ͻÿ�. �� �ð��� ������ Main �����尡 ����˴ϴ�.: ";
    int delayTime = 0;
    cin >> delayTime;

    this_thread::sleep_for(chrono::seconds(delayTime));
    myThread.stop();

    cout << "���� ������ ����" << endl;
    return 0;
}