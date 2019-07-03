#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>

using namespace std;

condition_variable cv;
mutex mx;

int data = 0;

void wait(){
    unique_lock<mutex> lk(mx);
    cout<<"Waiting for signal from main()"<<"\n";
    cv.wait(lk, []{
        return data == 1;
    });
    cout<<"Done waiting ..."<<"\n";
    lk.unlock();
}

void signal(){
    this_thread::sleep_for(chrono::seconds(1));
    {
        lock_guard<mutex> lk(mx);
        cout<<"Notifying..."<<"\n";
    }
    cv.notify_all();
    this_thread::sleep_for(chrono::seconds(1));
    {
        lock_guard<mutex> lk(mx);
        data = 1;
        cout<<"Notifying again ..."<<"\n";
    }
    cv.notify_all();
}

int main(){

    thread t1(wait), t2(wait), t3(wait), t4(signal);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
