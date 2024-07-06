#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

atomic<bool> stopFlag(false);

void ThreadFunction()
{
	int count = 0;

	cout << "쓰레드에서 반복할 숫자 : ";
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		if (stopFlag.load()) // 종료 플래그가 설정되면 루프 종료
		{
			cout << "쓰레드 종료 신호 수신" << endl;
			break;
		}

		cout << "쓰레드 실행 " << endl;
		this_thread::sleep_for(chrono::seconds(1)); // 1초에 한번 쓰레드 내의 반복문이 실행되게 하였으며 for 내부 진행중에 메인 쓰레드에서 지정한 시간이 끝나면 강제로 for 문이 종료된다.
	}
}

int main()
{
	int delayTime = 0;
	cout << "딜레이 타임 : ";
	cin >> delayTime;

	thread t(ThreadFunction);
	t.detach(); // detach를 사용하면 메인 스레드와 분할하여 실행하게 된다.

	this_thread::sleep_for(chrono::seconds(delayTime)); // 필요한 시간만큼 대기. 해당 시간안에 Thread가 끝나지 않더라도 강제로 종료된다.(메인 쓰레드와 분리되어 있기 때문에)
	stopFlag.store(true); // 스레드 종료

	return 0;
}