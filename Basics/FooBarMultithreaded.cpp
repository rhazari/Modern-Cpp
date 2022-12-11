#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

void PrintFoo(){
    cout<<"Foo\n";
}

void PrintBar(){
    cout<<"Bar\n";
}

mutex mx;
condition_variable cv;

bool flag = true;
const int N = 15;

void foo(){
    for(int k = 0; k < N; ++k){
        unique_lock<mutex> lk(mx);
        cv.wait(lk, []{
            return flag;
        });
        flag = false;
        cv.notify_all();
        PrintFoo();
    }
}

void bar(){
    for(int k = 0; k < N; ++k){
        unique_lock<mutex> lk(mx);
        cv.wait(lk, []{
            return !flag;
        });
        flag = true;
        cv.notify_all();
        PrintBar();
    }
}

int main(){
    thread th1(foo);
    thread th2(bar);

    th1.join();
    th2.join();
    return 0;
}