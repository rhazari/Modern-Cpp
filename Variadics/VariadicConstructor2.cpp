#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

template <class T, class U>
class SomeClass{
    unordered_map<T, vector<U>> dataMap;
public:
    SomeClass(T t, vector<U> u){
        dataMap.insert({t, u});
    }
    
    template<class... Args>
    SomeClass(T t, vector<U> u, Args... args): SomeClass(args...){
        dataMap.insert({t, u});
    }
    
    vector<U> getValue(T t){
        return dataMap[t];
    }
};

int main() {
    SomeClass<string, int> s("A", {10, 20, 30});

    auto vec = s.getValue("A");
    for(auto elem: vec)
        cout<<elem<<"\n";
    cout<<"\n";
}
