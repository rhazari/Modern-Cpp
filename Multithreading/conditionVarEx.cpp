#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std;

class Application{
    mutex mx;
    condition_variable cv;
    bool m_dataLoaded = false;
public:
    Application(): m_dataLoaded(true){}

    void loadData(){
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout<<"Loading Data ..."<<"\n";
        lock_guard<mutex> lk(mx);
        m_dataLoaded = true;
        cv.notify_one();
    }

    bool isDataLoaded(){
        return m_dataLoaded;
    }

    void mainTask(){
        cout<<"Setting up Application Server..."<<"\n";
        unique_lock<mutex> lk(mx);

        cv.wait(lk, [this](){
            return isDataLoaded();
        });

        cout<<"Can start processing the loaded data ..."<<"\n";
        lk.unlock();
    }
};

int main(){
    Application app;
    thread th1(&Application::mainTask, &app);
    thread th2(&Application::loadData, &app);

    th1.join();
    th2.join();
}