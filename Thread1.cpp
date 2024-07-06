#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
using namespace std;

atomic<bool> stopFlag(false);

void ThreadFunction()
{
	int count = 0;

	cout << "�����忡�� �ݺ��� ���� : ";
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		if (stopFlag.load()) // ���� �÷��װ� �����Ǹ� ���� ����
		{
			cout << "������ ���� ��ȣ ����" << endl;
			break;
		}

		cout << "������ ���� " << endl;
		this_thread::sleep_for(chrono::seconds(1)); // 1�ʿ� �ѹ� ������ ���� �ݺ����� ����ǰ� �Ͽ����� for ���� �����߿� ���� �����忡�� ������ �ð��� ������ ������ for ���� ����ȴ�.
	}
}

int main()
{
	int delayTime = 0;
	cout << "������ Ÿ�� : ";
	cin >> delayTime;

	thread t(ThreadFunction);
	t.detach(); // detach�� ����ϸ� ���� ������� �����Ͽ� �����ϰ� �ȴ�.

	this_thread::sleep_for(chrono::seconds(delayTime)); // �ʿ��� �ð���ŭ ���. �ش� �ð��ȿ� Thread�� ������ �ʴ��� ������ ����ȴ�.(���� ������� �и��Ǿ� �ֱ� ������)
	stopFlag.store(true); // ������ ����

	return 0;
}