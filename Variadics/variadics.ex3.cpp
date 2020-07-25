#include <iostream>
#include <unordered_map>

template <class T, class U>
class SomeClass{
    std::unordered_map<T, U> dataMap;
public:
    SomeClass(T t, U u){
        dataMap.insert({t, u});
    }
    
    template<class... Args>
    SomeClass(T t, U u, Args... args): SomeClass(args...){
        dataMap.insert({t, u});
    }
    
    U getValue(T t){
        return dataMap[t];
    }
};

int main() {
    SomeClass<std::string, int> s("A", 10, "B", 20, "C", 30);
    
    std::cout<<s.getValue("A")<<"\n";
    std::cout<<s.getValue("B")<<"\n";
    std::cout<<s.getValue("C")<<"\n";
}
