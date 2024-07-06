#include <iostream>
#include "Header.h"

int main() {
    MyThread myThread;
    int count = 0;
    std::cout << "Enter the number of times the thread should run: ";
    std::cin >> count;

    myThread.start(count);

    int delayTime = 0;
    std::cout << "Enter delay time in seconds: ";
    std::cin >> delayTime;

    std::this_thread::sleep_for(std::chrono::seconds(delayTime));

    myThread.stop();

    std::cout << "Main thread finishing" << std::endl;
    return 0;
}