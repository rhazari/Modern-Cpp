#include <iostream>

using namespace std;

template<class T>
bool pair_compare(T a, T b){
	return a == b;
}

template<class T, class...Args>
bool pair_compare(T a, T b, Args... args){
	return a == b && pair_compare(args...);
}

int main(){
	if(pair_compare(1.5, 1.5, 3, 3, 5, 5))
		cout<<"Pairs Match"<<endl;
	else
		cout<<"Pairs don't match"<<endl;
	return 0;
}