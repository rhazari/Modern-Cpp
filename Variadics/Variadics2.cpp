// Create a vector of strings from a list of inputs

#include <iostream>
#include <vector>
#include <sstream>

template <typename T>
std::string to_string_impl(const T& t){
    std::stringstream ss;
    ss << t;
    return ss.str();
}

template<typename ... Arg>
std::vector<std::string> to_string(const Arg& ... arg){
    return {to_string_impl(arg) ...};
}

template<typename ... Arg>
std::vector<std::string> toString(const Arg& ... arg){
    std::vector<std::string> retvec;
    std::stringstream ss;
    (void)std::initializer_list<int> { (ss.str(""), ss << arg, retvec.push_back(ss.str()), 0) ...};
    return retvec;
}

int main(){

    const auto vec = to_string(1, "hello", 5.6, "world", 2.2);
    for(const auto& v: vec)
        std::cout<<v<<"\t";
    std::cout<<"\n";

    const auto vec2 = toString(1, "hello", 5.6, "world", 2.2);
    for(const auto& v: vec2)
        std::cout<<v<<"\t";
    std::cout<<"\n";


}