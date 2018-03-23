#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

void print(int val){
    std::cout<<val<<" ";
}

int square(int val){
    return val*val;
}

int main(){

    std::vector<int> col1 {2,3,6,4,7,8,9,1,2,5,3,8};
    std::vector<int> col2;

    std::transform(col1.begin(), col1.end(), back_inserter(col2), square);

    std::cout<<"Collection 1..."<<"\n";
    std::for_each(col1.begin(), col1.end(), print);
    std::cout<<"\n";

    std::cout<<"Collection 2...Square of Collection 1"<<"\n";
    std::for_each(col2.begin(), col2.end(), print);
    std::cout<<"\n";

    std::cout<<"Collection 1...Inplace transformation of collection 1"<<"\n";
    std::transform(col1.begin(), col1.end(), col1.begin(), square);
    std::for_each(col1.begin(), col1.end(), print);
    std::cout<<"\n";

}