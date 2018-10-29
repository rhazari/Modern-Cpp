#include <iostream>
#include <thread>
#include <ctime>
#include <vector>
#include <chrono>

using namespace std;

void accumulator(const vector<int>& vec, int& result, int start, int end){
    result = 0;
    for(int k = start; k < end; ++k){
        result += vec[k];
    }
}

int main(){

    vector<int> vec;
    for(int k = 0; k < 100000; ++k){
        vec.push_back(rand()%10+1);
    }

    {
        int result1 = 0;
        int result2 = 0;

        auto start = chrono::high_resolution_clock::now();

        thread t1(accumulator, std::ref(vec), std::ref(result1), 0, vec.size()/2);
        thread t2(accumulator, std::ref(vec), std::ref(result2), vec.size()/2, vec.size());
        auto end = chrono::high_resolution_clock::now();
        
        t1.join();
        t2.join();


        chrono::duration<double> time_elapsed = end - start;

        cout<<"Spinning out 2 threads"<<"\n";
        cout<<"Result1 + Result2 "<< result1+result2<<"\n";
        cout<<"Elasped time "<< time_elapsed.count()<<"\n";
    }

    {
        int result3 = 0;

        auto start = chrono::high_resolution_clock::now();

        accumulator(vec, result3, 0, vec.size());

        auto end = chrono::high_resolution_clock::now();

        chrono::duration<double> time_elapsed = end - start;

        cout<<"Executing on the main thread"<<"\n";
        cout<<"Result3 "<< result3<<"\n";
        cout<<"Elasped time "<< time_elapsed.count()<<"\n";
    }
}