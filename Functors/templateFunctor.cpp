#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

template <typename T>
struct matchFirst {
    matchFirst(const T& _val): m_id(_val){}

    template <typename U>
    bool operator()(const U &other){
        return m_id == other.first;
    }

    T m_id;
};

int main(){

    std::vector<std::pair<int, bool>> v1 = {std::make_pair(3, true), std::make_pair(2, false), std::make_pair(5, true), std::make_pair(9, false)};
    if(std::find_if(begin(v1), end(v1), matchFirst<int>(5)) != end(v1))
        std::cout<<"Pair with ID found"<<"\n";
    else
        std::cout<<"Pair not found"<<"\n";

    std::vector<std::pair<double, bool>> v2 = {std::make_pair(3.2, true), std::make_pair(2.0, false), std::make_pair(5.5, true), std::make_pair(9.7, false)};
    if(find_if(begin(v2), end(v2), matchFirst<double>(5.5)) != end(v2))
        std::cout<<"Pair with ID found"<<"\n";
    else
        std::cout<<"Pair not found"<<"\n";
}