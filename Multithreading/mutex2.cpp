#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

class LogFile{
	std::mutex m_mutex;
	ofstream f;

public:
	LogFile(){
		f.open("logfile.txt");
	}
	~LogFile(){
		f.close();
	}

	void print_msg(string msg, int id){
		std::lock_guard<std::mutex> guard(m_mutex);
		f<<msg<<"->"<<id<<"\n";
	}
};

void func(LogFile& log){
	for(int k = 0; k < 100; ++k){
		log.print_msg("From thread", k+1);
	}
}

int main(){
	LogFile log;
	thread t1(func, std::ref(log));

	for(int k = 0; k < 100; ++k)
		log.print_msg("From main", k+1);

	t1.join();

	return 0;
}