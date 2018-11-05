#include <iostream>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <vector>

using namespace std;

template <typename T>
class Queue{
    private:
        queue<T> Q;
        mutex mx;
        condition_variable cv;
    
    public:
        T pop(){
            unique_lock<mutex> lock(mx);
            cv.wait(lock, [this]{
                return !Q.empty();
            });

            auto elem = Q.front();
            Q.pop();
            lock.unlock();
            return elem;
        }

        void push(const T& elem){
            unique_lock<mutex> lock(mx);
            Q.push(elem);
            lock.unlock();
            cv.notify_one();
        }

        void push(T&& elem){
            unique_lock<mutex> lock(mx);
            Q.push(std::move(elem));
            lock.unlock();
            cv.notify_one();
        }
};

int main(){
    Queue<int> q;
    vector<thread> vec;
    int a, b;
    auto t1 = thread([&]{
        a = q.pop();
    });

    for(int k = 0; k < 5; ++k){
        vec.push_back(thread([&]{
            q.push(k+1);
        }));
    }

    auto t2 = thread([&]{
        b = q.pop();
    });

    cout<<a<<" "<<b<<"\n";

    for(int k = 0; k < 5; ++k){
        vec.at(k).join();
    }

    t1.join();
    t2.join();

}