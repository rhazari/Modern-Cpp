#include <iostream>
#include <utility>

using namespace std;

class Foo{
public:

	Foo(){
		cout<<"Default Constructor"<<"\n";
	}
	
	Foo(const Foo& rhs){
		cout<<"Copy Constructor"<<"\n";
		if(rhs.i != nullptr){
			i = new int(*rhs.i);
		}
	}

	Foo& operator=(const Foo& rhs){
		cout<<"Copy Assignment"<<"\n";
		if(rhs.i != nullptr){
			i = new int(*rhs.i);
		}
		return *this;
	}

	Foo& operator=(Foo&& rhs){
		cout<<"Move Assignment"<<"\n";
		if(rhs.i != nullptr){
			i = rhs.i;
			rhs.i = nullptr;
		}
		return *this;
	}


	~Foo(){
		cout<<"Destrcutor"<<"\n";
		if(i != nullptr){
			delete i;

		}
	}

	int* i = nullptr;
};

int main(){

	Foo f1;
	// Copy Assignment
	{
		Foo f2;
		f2.i = new int(10);
		f1 = f2;	
	}
	cout<<"\n";
	// Move Assignment
	{
		Foo f2;
		f2.i = new int(10);
		f1 = move(f2);	
	}

	return 0;
}