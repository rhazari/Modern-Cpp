#include <iostream>
#include <memory>
#include <cassert>
#include <vector>

using namespace std;

class Base{
public:
	Base(){cout<<"Base Constructor"<<endl;}
	virtual ~Base(){cout<<"Base Destructor"<<endl;}
	virtual void func(){cout<<"Base::func"<<endl;}
};

class Derived:public Base{
public:
	Derived(){cout<<"Derived Constructor"<<endl;}
	~Derived(){cout<<"Derived Destructor"<<endl;}
	void func() override{cout<<"Derived::func"<<endl;}
};

unique_ptr<Derived> movePointer(unique_ptr<Derived> ptr){
	ptr->func();
	return ptr;
}

int main(){

	{
		auto p1 = make_unique<Derived>();
		// Unique Pointers can only be moved; not copied
		//auto p2 = movePointer(p1);
		auto p3 = movePointer(move(p1));

		assert(!p1);
		p3->func();
	}
	cout<<endl;
	cout<<endl;
	{
		unique_ptr<Base> p1 = make_unique<Derived>();
		p1->func();
		vector<unique_ptr<Base>> myVec;
		myVec.push_back(move(p1));
		myVec.push_back(make_unique<Derived>());
		myVec.emplace_back(make_unique<Derived>());

		for(const auto& p: myVec)
			p->func();
	}

	return 0;
}