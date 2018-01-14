#include <iostream>
#include <memory>

using namespace std;

class Dummy{
public:
	Dummy(){
		cout<<"Dummy "<<this<<" constructed"<<endl;
	}
	virtual ~Dummy(){
		cout<<"Dummy "<<this<<" destructed"<<endl;
	}
};

unique_ptr<Dummy> source(){
	// make_unique not available in C++11
	return make_unique<Dummy>();
}

void sink(unique_ptr<Dummy> ptr){
	cout<<"Sink gets the value "<<ptr.get()<<endl;
}

int main(){

	unique_ptr<Dummy> ptr = source();

	// Move unique pointers
	sink(move(ptr));

	return 0;
}