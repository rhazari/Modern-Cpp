#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

class T
{
	string _str;
	int _val;
public:
	T(string str, int val):_str{str}, _val{val}{}

	string getStr() const {return _str;}

	int getVal() const {return _val;}
};

class S
{
	vector<T> vec;
public:
	S(initializer_list<T> list): vec{list}{}

	void append(initializer_list<T> list){
		vec.insert(vec.end(), list.begin(), list.end());
	}

	vector<T> getStuff() const{ return vec; } 
};

int main(){

	S _ss {
		{"value 1", 11},
		{"value 2", 12},
		{"value 3", 13},
		{"value 4", 14},
	};

	_ss.append({
		{"value 7", 17},
		{"value 9", 19},
	}); 

	auto _vv = _ss.getStuff();
	for(const auto& v: _vv)
		cout<<v.getStr()<<" "<<v.getVal()<<endl;

	return 0;
}