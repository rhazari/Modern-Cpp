#include <iostream>
#include <map>

using namespace std;

class Person{
    int _id;
    string _name;

public:
    // If there is no element with key i, one is inserted with a value initialized (which for a user defined type means default constructed) mapped type. 
    // You then assign to it the value on the RHS of the assignment. The first part requires that the type be default constructable.
    Person() = default;

    Person(int id, string name): _id(id), _name(name){}

    // Person(const Person& p){
    //     _id = p._id;
    //     _name = p._name;
    // }

    // Person& operator =(const Person&p){
    //     if(this == &p){
    //         return *this;
    //     }
    //     this->_id = p._id;
    //     this->_name = p._name;
    //     return *this;
    // }

    // Person(Person&& p) noexcept: _id(std::move(p._id)),_name(std::move(p._name)){}

    // Person& operator =(Person&& p){
    //     if(this == &p){
    //         return *this;
    //     }
    //     _id = std::move(p._id);
    //     _name = std::move(p._name);
    //     return *this;
    // }

    int getId() const{
        return _id;
    }

    string getName() const{
        return _name;
    }
};

void displayMapContents(const map<int, Person>& mapWithPersonObjects){
    for(const auto& elem: mapWithPersonObjects){
        cout<<elem.first<<" "<<elem.second.getName()<<"\n";
    }
    cout<<"\n";
}

int main(){
    Person p1(1,"ALDI");
    Person p2(2,"CART");
    Person p3(3,"DAME");
    Person p4(4,"TAR");
    Person p5(5,"BUZZ");

    map<int, Person> mapWithPersonObjects;
    mapWithPersonObjects.insert(make_pair(p1.getId(), p1));
    mapWithPersonObjects.insert(make_pair(p2.getId(), p2));
    mapWithPersonObjects.insert(make_pair(p3.getId(), p3));
    mapWithPersonObjects.insert(make_pair(p4.getId(), p4));
    mapWithPersonObjects.insert(make_pair(p5.getId(), p5));

    displayMapContents(mapWithPersonObjects);

    mapWithPersonObjects.clear();

    mapWithPersonObjects[p1.getId()] = p1;
    mapWithPersonObjects[p2.getId()] = p2;
    mapWithPersonObjects[p3.getId()] = p3;
    mapWithPersonObjects[p4.getId()] = p4;
    mapWithPersonObjects[p5.getId()] = p5;

    displayMapContents(mapWithPersonObjects);

    mapWithPersonObjects[6] = Person(6, "FRAP");
    mapWithPersonObjects[7] = Person(7, "MAPLE");
    displayMapContents(mapWithPersonObjects);
}