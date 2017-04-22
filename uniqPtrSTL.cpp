#include <iostream>
#include <memory>
#include <vector>

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

int main(){

	vector<unique_ptr<Dummy>> myVec;

	for(int k = 0; k < 10; ++k){
		myVec.push_back(make_unique<Dummy>());
	}

	return 0;
}