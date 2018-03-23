#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

using namespace std;

class T
{
	string _str;
	int _ival;
	double _dval;
public:
	T(string str, int val):_str{str}, _ival{val}, _dval{0.}{}

	T(string str, double val):_str{str}, _ival{0}, _dval{val}{}

	string getStr() const {return _str;}

	int getIval() const {return _ival;}

	double getDval() const {return _dval;}
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
		{"value 2", 12.2},
		{"value 3", 13},
		{"value 4", 14.},
	};

	_ss.append({
		{"value 7", 17.1},
		{"value 9", 19},
	}); 

	auto _vv = _ss.getStuff();
	for(const auto& v: _vv)
		cout<<v.getStr()<<" "<<v.getIval()<<" "<<v.getDval()<<endl;

	return 0;
}