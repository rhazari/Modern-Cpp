#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <queue>
#include <condition_variable>

using namespace std;

template <typename T>
class ProducerConsumer{
    condition_variable cv;
    mutex mx;
    queue<T> Q;
    int m_size;
public:
    ProducerConsumer(int size): m_size(size){}

    void add(T var){
        unique_lock<mutex> lock(mx);
        cv.wait(lock, [this](){
            return !isFull();
        });
        Q.push(var);
        lock.unlock();
        cv.notify_all();
    }

    int consume(){
        unique_lock<mutex> lock(mx);
        cv.wait(lock, [this](){
            return !isEmpty();
        });
        auto var = Q.front();
        Q.pop();
        lock.unlock();
        cv.notify_all();
        return var;
    }

    bool isFull(){
        return Q.size() >= m_size;
    }

    bool isEmpty(){
        return Q.size() == 0;
    }

    int length(){
        return Q.size();
    }

    void clear(){
        unique_lock<mutex> lock(mx);
        while(!isEmpty()){
            Q.pop();
        }
        lock.unlock();
        cv.notify_all();
    }
};

template <typename T>
void func1(ProducerConsumer<T> &PC){
    cout<<"Producing ..."<<"\n";
    for(int k = 0; k < 5; ++k){
        PC.add(k*k+1);
    }
}

template <typename T>
void func2(ProducerConsumer<T> &PC){
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout<<"Consuming ..."<<"\n";
    while(!PC.isEmpty()){
        cout<<PC.consume()<<"\n";
    }
}

int main(){
    ProducerConsumer<int> PC(5);

    thread th1(func1<int>, std::ref(PC));
    thread th2(func2<int>, std::ref(PC));

    th1.join();
    th2.join();
}