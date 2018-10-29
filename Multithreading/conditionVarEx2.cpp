#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mx;
condition_variable cv;
string str;
bool ready = false;
bool processed = false;

void func(){
    unique_lock<mutex> lk(mx);
    cv.wait(lk, []{
        return ready;
    });

    cout<<"Worker thread is processing data..."<<"\n";
    str += " after processing";

    processed = true;
    cout<<"Worker thread signals data processing is complete"<<"\n";

    lk.unlock();
    cv.notify_one();
}

int main(){

    thread worker(func);
    str = "Sample data";
    {
        lock_guard<mutex> lk(mx);
        ready = true;
        cout<<"main() signals data is ready for processing"<<"\n";
    }
    cv.notify_all();
    {
        unique_lock<mutex> lk(mx);
        cv.wait(lk, []{
            return processed;
        });
    }

    cout<<"In main() now. Data = "<<str<<"\n";

    worker.join();
}