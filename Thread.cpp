#include <iostream>
#include <chrono>
#include "Header.h"

MyThread::MyThread() : stopFlag_(false) {}

MyThread::~MyThread()
{
    if (thread_.joinable())
    {
        stop();
        thread_.join();
    }
}

void MyThread::start(int count)
{
    stopFlag_.store(false);
    thread_ = std::thread(&MyThread::threadFunction, this, count);
}

void MyThread::stop()
{
    stopFlag_.store(true);
    if (thread_.joinable())
    {
        thread_.join();
    }
}

void MyThread::threadFunction(int count)
{
    for (int i = 0; i < count; i++)
    {
        if (stopFlag_.load())
        {
            std::cout << "Thread stopping" << std::endl;
            break;
        }
        std::cout << "Thread running " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}