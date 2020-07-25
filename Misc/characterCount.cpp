#include <iostream>
#include <iterator>
#include <vector>
#include <cctype>
#include <algorithm>

using tally = std::vector<size_t>;

tally collect(std::istream& in){
    using iter = std::istream_iterator<char>;
    tally v(256,0);
    for_each(iter{in}, iter{}, [&v](char c){++v.at(c);});
    return v;
}

void printTally(const tally& v, std::ostream& out){
    for(auto i = 'A'; i <= 'Z'; ++i){
        out<<i<<" = "<<v[i]<<'\n';
        auto li = char(std::tolower(i));
        out<<li<<" = "<<v[li]<<'\n';
    }
}

int main(){

    printTally(collect(std::cin), std::cout);
}