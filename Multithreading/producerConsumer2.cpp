#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <vector>

using namespace std;

queue<int> Q;
mutex mx;
condition_variable cv;

bool isFull(){
    return Q.size() == 5;
}

bool isEmpty(){
    return Q.size() == 0;
}

void producer(int val){
    unique_lock<mutex> lk(mx);
    cv.wait(lk, []{
        return !isFull(); 
    });
    Q.push(val);
    lk.unlock();
    cv.notify_all();
}

void consumer(){
    unique_lock<mutex> lk(mx);
    cv.wait(lk, []{
        return !isEmpty();
    });
    cout<<Q.front()<<"\n";
    Q.pop();
    lk.unlock();
    cv.notify_all();
}

int main(){
    vector<thread> vec;
    for(int k = 0; k < 8; ++k){
        vec.push_back(thread(producer, k*k+1));
    }
    
    for(int k = 0; k < 8; ++k){
        vec.push_back(thread(consumer));
    }

    int len = vec.size();
    for(int k = 0; k < len; ++k){
        vec.at(k).join();
    }

}