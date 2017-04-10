#include <iostream>

using namespace std;

template<class T, class V>
bool is_a_match(T&& t, V&& v){
	return t == v;
}

template<class T, class V, class... Args>
bool is_a_match(T&& t, V&& v, Args&&...args){
	return (t == v) || is_a_match(t, args...);
}

int main(){
	if(is_a_match(1, 2, 3.5, 6, 1, 7, 8))
		cout<<"There is a pattern match"<<endl;
	else
		cout<<"No match"<<endl;

	return 0;
}