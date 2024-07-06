#include <iostream>
#include <chrono>
#include "Header.h"
using namespace std;
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
    thread_ = thread(&MyThread::threadFunction, this, count);
}

void MyThread::stop()
{
    stopFlag_.store(true);
    if (thread_.joinable())
    {
        thread_.join();
    }
}

void MyThread::waitUntilFinished()
{
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
            cout << "Thread stopping" << endl;
            break;
        }
        cout << endl << "Ãâ·Â " << i + 1;
        this_thread::sleep_for(chrono::seconds(1));
    }
}