#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

int main(){

	unique_ptr<int> p1, p2;
	int *p3 = nullptr;

	p1 = make_unique<int>(10);
	assert(p1);
	assert(!p2);
	p3 = p1.get();
	cout<<*p3<<endl;
	p3 = nullptr;

	p2 = move(p1);
	assert(!p1);
	assert(p2);

	p3 = p2.release();
	cout<<*p3<<endl;
	assert(!p2);

	delete p3;

	return 0;
}