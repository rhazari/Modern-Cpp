#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Animal{
public:
	virtual bool hasWings() = 0;
};

class Bird: public Animal{
public:
	Bird(){	cout<< "bird created"<<endl; }
	bool hasWings(){return true;}
	~Bird() { cout<<"bird destroyed"<<endl; } 
};

class Dog: public Animal{
public:
	Dog() {cout<< "dog created"<<endl; }
	bool hasWings(){return false;}
	~Dog(){cout<< "dog destroyed"<<endl; }
};

class Zoo{
	vector<shared_ptr<Animal>> vec;
public:
	void AddAnimals(shared_ptr<Animal> ptr){ 
		vec.push_back(ptr); 
	}

	shared_ptr<Animal> shareAnimal(size_t index) {
		if(index >= vec.size())
			return nullptr; 
		return vec[index]; 
	}

	void getShareCount(){
		for(const auto& v: vec)
			cout<<v.use_count()<<" ";
		cout<<endl;
	}
};

int main(){
	Zoo myzoo;

	myzoo.AddAnimals(make_shared<Bird>());
	myzoo.AddAnimals(make_shared<Dog>());

	auto p1 = myzoo.shareAnimal(0);

	myzoo.getShareCount();

	return 0;
}