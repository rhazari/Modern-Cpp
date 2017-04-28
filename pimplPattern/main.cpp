#include <iostream>
#include "container.h"

using namespace std;

int main(){

	Container ctr(10);

	ctr[2] = 23;
	ctr[5] = 37;

	cout<<ctr[2]<<" "<<ctr[5]<<endl;
	Container copy = ctr;

	copy[4] = 29;
	cout<<copy[2]<<" "<<copy[4]<<" "<<copy[5]<<endl;
	return 0;
}