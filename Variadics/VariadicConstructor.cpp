#include <iostream>
#include <unordered_map>

using namespace std;

template <class T, class U>
class SomeClass{
    unordered_map<T, U> dataMap;
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
    SomeClass<string, int> s("A", 10, "B", 20, "C", 30);
    
    cout<<s.getValue("A")<<"\n";
    cout<<s.getValue("B")<<"\n";
    cout<<s.getValue("C")<<"\n";
}
