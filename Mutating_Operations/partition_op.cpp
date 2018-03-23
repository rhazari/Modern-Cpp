#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

void print(int val){
    std::cout<<val<<" ";
}

bool isOdd(int val){
    return val%2;
}

int main(){
    
    std::vector<int> col1 {2,3,6,4,7,8,9,1,2,5,3,8};
    std::vector<int> col2;

    std::cout<<"Collection 1...Before Partition"<<"\n";
    std::for_each(col1.begin(), col1.end(), print);
    std::cout<<"\n";

    // iter holds the iterator where the partition occured
    auto iter = std::partition(col1.begin(), col1.end(), isOdd);

    std::cout<<"Collection 1...After Partition"<<"\n";
    std::for_each(col1.begin(), col1.end(), print);
    std::cout<<"\n";

    std::cout<<"First half of partition ..."<<"\n";
    std::for_each(col1.begin(), iter, print);
    std::cout<<"\n";

    std::cout<<"Second half of partition ..."<<"\n";
    std::for_each(iter, col1.end(), print);
    std::cout<<"\n";
}