#include <iostream>
#include <vector>
#include <algorithm>

void print(int val){
    std::cout<<val<<" ";
}

bool isOdd(int val){
    return val%2;
}

bool isEven(int val){
    return !(val%2);
}


int main() {

    std::vector<int> col1 {2,3,6,4,7,8,9,1,2,5,3,8};
    std::vector<int> col2;
 
    // Back Inserter Iterator
    std::copy(col1.begin()+3, col1.end()-3, back_inserter(col2));
    std::cout<<"Collection 1..."<<"\n";
    std::for_each(col1.begin(), col1.end(), print);
    std::cout<<"\n";

    std::cout<<"Collection 2..."<<"\n";
    std::for_each(col2.begin(), col2.end(), print);
    std::cout<<"\n";

    std::vector<int> col3;
    std::copy_if(col1.begin(), col1.end(), back_inserter(col3), isOdd);
    std::cout<<"Collection 3...Only odd numbers"<<"\n";
    std::for_each(col3.begin(), col3.end(), print);
    std::cout<<"\n";

    std::vector<int> col4;
    std::copy_if(col1.begin(), col1.end(), back_inserter(col4), isEven);
    std::cout<<"Collection 4...Only even numbers"<<"\n";
    std::for_each(col4.begin(), col4.end(), print);
    std::cout<<"\n";
}