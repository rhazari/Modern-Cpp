#include <iostream>
#include <iterator>
#include <map>
#include <cctype>
#include <algorithm>

using tally = std::map<std::string, size_t>;

tally collect(std::istream& in){
    using iter = std::istream_iterator<std::string>;
    tally m;
    for_each(iter{in}, iter{}, [&m](std::string str){++m[str];});
    return m;
}

void printTally(const tally& m, std::ostream& out){
    for(const auto& p: m){
        out<<p.first<<" "<<p.second<<'\n';
    }
}

int main(){

    printTally(collect(std::cin), std::cout);
}