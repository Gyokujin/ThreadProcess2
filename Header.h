#ifndef ThreadProcess
#define ThreadProcess

#include <thread>
#include <atomic>

class MyThread
{
public:
    MyThread();
    ~MyThread();
    void start(int count);
    void stop();
private:
    void threadFunction(int count);
    std::thread thread_;
    std::atomic<bool> stopFlag_;
};

#endif