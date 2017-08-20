#include <iostream>

using namespace std;

class AddFunctor
{
	private:
		int m_val;
	public:
		AddFunctor(int _val): m_val(_val){}

		int operator()(int _val) const{
			return m_val + _val;
		}
};

int main(){

	AddFunctor obj(3);
	cout<< obj(10)<<endl;
	cout<< obj(17)<<endl;
	return 0;
}