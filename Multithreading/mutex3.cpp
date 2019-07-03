#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

class Wallet{
    int m_money;
    mutex mx;
public:
    Wallet(): m_money(0){}
    
    int getMoney(){
        return m_money;
    }

    void addMoney(int money){
        lock_guard<mutex> lk(mx);
        for(int k = 0; k < money; ++k){
            m_money++;
        }
    }
};

int func(){
    Wallet obj;
    vector<thread> vec;
    for(int k = 0; k < 5; ++k){
        vec.push_back(thread(&Wallet::addMoney, &obj, 1000));
    }

    for(int k = 0; k < vec.size(); ++k){
        vec.at(k).join();
    }
    return obj.getMoney();
}

int main(){
    int val = 0;
    for(int k = 0; k < 1000; ++k){
        if( val = func() != 5000){
            cout<<"Error..."<<"\n";
        }
        else{
            cout<<"Works all good .."<<"\n";
        }
    }
}