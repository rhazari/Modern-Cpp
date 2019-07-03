#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile {
    mutex _mu;
    once_flag _flag;
    ofstream _f;

public:
    LogFile(){}

    void print_msg(string msg, int id){
        // File will be opened only once by one of the threads
        call_once(_flag, [&](){
            _f.open("logFile.txt");
        });

        unique_lock<mutex> locker(_mu, std::defer_lock);
        locker.lock();
        _f << msg <<"->"<<id<<"\n";
        locker.unlock();
    }
};

void func(LogFile& log){
    for(int k = 0; k < 100; ++k){
        log.print_msg("From thread", k+1);
    }
}

int main(){
    LogFile log;
    thread t1(func, std::ref(log));

    for(int k = 0; k < 100; ++k)
        log.print_msg("From main", k+1);

    t1.join();

    return 0;
}