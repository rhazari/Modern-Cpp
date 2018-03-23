#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

void print(int val){
    std::cout<<val<<" ";
}

int main(){
    
    std::vector<int> col1 {2,3,6,4,7,8,9,1,2,5,3,8};
    std::vector<int> col2(col1.size());
    std::vector<int> col3(col1.size());

    std::copy(col1.begin(), col1.end(), col2.begin());

    std::cout<<"Collection 1..."<<"\n";
    std::for_each(col1.begin(), col1.end(), print);
    std::cout<<"\n";

    std::cout<<"Collection 2..."<<"\n";
    std::for_each(col2.begin(), col2.end(), print);
    std::cout<<"\n";

    // Obtain the iterator position to the last point where the copy happened
    auto iter = std::copy(col1.begin()+3, col1.end()-3, col3.begin());
    // Erase from the iterator position to the end
    col3.erase(iter, col3.end());
    std::cout<<"Collection 2..."<<"\n";
    std::for_each(col3.begin(), col3.end(), print);
    std::cout<<"\n";

}