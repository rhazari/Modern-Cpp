#include <iostream>
#include <vector>
#include <algorithm>

class Item {
public:
    Item(int id, int quantity): m_id(id), m_quantity(quantity){}

    bool operator<(Item other){
        return m_id < other.m_id;
    }

    bool operator ==(int id){
        return m_id == id;
    }

    int m_id;
    int m_quantity;
};

struct sortByQuantity {
    bool operator()(Item const& left, Item const& right) const{
        return left.m_quantity < right.m_quantity;
    }
};

struct findByQuantity {
    findByQuantity(int _quantity): quant(_quantity){}

    bool operator()(Item const& other) const{
        return quant == other.m_quantity;
    } 

    int quant;
};

void display(std::vector<Item>& vec){
    for(const auto& item: vec)
        std::cout<<item.m_id<<"->"<<item.m_quantity<<"\n";
}

int main(){ 
    std::vector<Item> vec = {Item(12, 117), Item(7, 109), Item(4, 97), Item(17, 67), Item(9, 91)};
    std::sort(begin(vec), end(vec));
    std::cout<<"Sort by ID"<<"\n";
    display(vec);

    sort(begin(vec), end(vec), sortByQuantity());
    std::cout<<"Sort by Quantity"<<"\n";
    display(vec);

    std::cout<<"Find with ID"<<"\n";
    if(find(begin(vec), end(vec), 7) != end(vec))
        std::cout<<"Item with ID found"<<"\n";
    else
        std::cout<<"Item not found"<<"\n";

    std::cout<<"Find with Quantity"<<"\n";
    if(find_if(begin(vec), end(vec), findByQuantity(109)) != end(vec))
        std::cout<<"Item with quantity found"<<"\n";
    else
        std::cout<<"Item not found"<<"\n";
