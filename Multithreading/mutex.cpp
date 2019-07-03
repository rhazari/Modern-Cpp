#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex mu;

void print_msg(string msg, int id){
	std::lock_guard<std::mutex> guard(mu);
	cout<<msg<<"->"<<id<<"\n";
}

void func(){
	for(int k = 0; k < 100; ++k)
		print_msg("Msg from thread", k+1);
}

int main(){

	thread t1(func);
	for(int k = 0; k < 100; ++k)
		print_msg("Msg from main", k+11);

	t1.join();

	return 0;
}