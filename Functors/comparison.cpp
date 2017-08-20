#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Item
{
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

struct sortByQuantity
{
	bool operator()(Item const& left, Item const& right) const{
		return left.m_quantity < right.m_quantity;
	}
};

struct findByQuantity
{
	findByQuantity(int _quantity): quant(_quantity){}

	bool operator()(Item const& other) const{
		return quant == other.m_quantity;
	} 

	int quant;
};

void display(vector<Item>& vec){
	for(const auto& item: vec)
		cout<<item.m_id<<"->"<<item.m_quantity<<endl;
}

int main(){

	vector<Item> vec = {Item(12, 117), Item(7, 109), Item(4, 97), Item(17, 67), Item(9, 91)};
	sort(begin(vec), end(vec));
	cout<<"Sort by ID"<<endl;
	display(vec);

	sort(begin(vec), end(vec), sortByQuantity());
	cout<<"Sort by Quantity"<<endl;
	display(vec);


	cout<<"Find with ID"<<endl;
	if(find(begin(vec), end(vec), 7) != end(vec))
		cout<<"Item with ID found"<<endl;
	else
		cout<<"Item not found"<<endl;

	cout<<"Find with Quantity"<<endl;
	if(find_if(begin(vec), end(vec), findByQuantity(109)) != end(vec))
		cout<<"Item with quantity found"<<endl;
	else
		cout<<"Item not found"<<endl;

	return 0;
}