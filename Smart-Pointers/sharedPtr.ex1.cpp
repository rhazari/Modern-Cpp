#include <iostream>
#include <memory>
#include <vector>

class Animal{
public:
    virtual bool hasWings() = 0;
};

class Bird: public Animal{
public:
    Bird(){	std::cout<< "bird created"<<"\n"; }
    bool hasWings(){return true;}
    ~Bird() { std::cout<<"bird destroyed"<<"\n"; } 
};

class Dog: public Animal{
public:
    Dog() {std::cout<< "dog created"<<"\n"; }
    bool hasWings(){return false;}
    ~Dog(){std::cout<< "dog destroyed"<<"\n"; }
};

class Zoo{
    std::vector<std::shared_ptr<Animal>> vec;
public:
    void AddAnimals(std::shared_ptr<Animal> ptr){ 
        vec.push_back(ptr); 
    }

    std::shared_ptr<Animal> shareAnimal(size_t index) {
        if(index >= vec.size())
            return nullptr; 
        return vec[index]; 
    }

    void getShareCount(){
        for(const auto& v: vec)
            std::cout<<v.use_count()<<" ";
        std::cout<<"\n";
    }
};

int main(){
    Zoo myzoo;

    myzoo.AddAnimals(std::make_shared<Bird>());
    myzoo.AddAnimals(std::make_shared<Dog>());

    auto p1 = myzoo.shareAnimal(0);

    myzoo.getShareCount();
}