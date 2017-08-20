#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

template <typename T>
struct matchFirst
{
	matchFirst(const T& _val): m_id(_val){}

	template <typename U>
	bool operator()(const U &other){
		return m_id == other.first;
	}

	T m_id;
};

int main(){

	vector<pair<int, bool>> v1 = {make_pair(3, true), make_pair(2, false), make_pair(5, true), make_pair(9, false)};
	if(find_if(begin(v1), end(v1), matchFirst<int>(5)) != end(v1))
		cout<<"Pair with ID found"<<endl;
	else
		cout<<"Pair not found"<<endl;

	vector<pair<double, bool>> v2 = {make_pair(3.2, true), make_pair(2.0, false), make_pair(5.5, true), make_pair(9.7, false)};
	if(find_if(begin(v2), end(v2), matchFirst<double>(5.5)) != end(v2))
		cout<<"Pair with ID found"<<endl;
	else
		cout<<"Pair not found"<<endl;
	return 0;
}