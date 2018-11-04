#include <iostream>

using namespace std;

class RC {
    private:
        int m_count; 

    public:
        RC() : m_count(0){}

        void addRef(){
            m_count++;
        }

        int release(){
            return --m_count;
        }

        int getRefCount(){
            return m_count;
        }
};

template <typename T>
class SP{
    private:
        T* m_data;
        RC *m_reference;
    
    public:
        SP(): m_data(nullptr), m_reference(nullptr){}

        SP(T* data): m_data(data), m_reference( new RC() )
        {
            m_reference->addRef();
            cout<<"Created smart pointer "<<"\n";
        }

        SP(const SP<T>& sp): m_data(sp.m_data), m_reference(sp.m_reference)
        {
            m_reference->addRef();
            cout<<"Copied smart pointer"<<"\n";
            cout<<"Ref count is "<<m_reference->getRefCount()<<"\n";
        }

        ~SP()
        {
            cout<<"Destroying smart pointer "<<"\n";
            cout<<"Ref count is "<<m_reference->getRefCount()-1<<"\n";
            if(m_reference->release() == 0)
            {
                delete m_data;
                delete m_reference;
            }
        }

        T& operator* ()
        {
            return *m_data;
        }

        T* operator-> ()
        {
            return m_data;
        }

        SP<T>& operator = (const SP<T>& sp) {
            cout<<"Copy assignment of smart pointer"<<"\n";
            if(this != & sp){
                if(m_reference && m_reference->release() == 0){
                    delete m_data;
                    delete m_reference;
                }

                m_data = sp.m_data;
                m_reference = sp.m_reference;
                m_reference->addRef();
            }
            cout<<"Ref count is "<<m_reference->getRefCount()<<"\n";
            return *this;
        }
};

class Person {
    int m_age;
    string m_name;

    public:
        Person(): m_age(0),m_name(""){ }

        Person(int age, string name): m_age(age), m_name(name){}
        
        ~Person(){}

        void display(){
            cout<<"Name "<< m_name<<"\n";
            cout<<"Age "<<m_age<<"\n";
        } 
};

int main(){
    SP<Person> person1(new Person(30, "Raihan"));
    person1->display();
    {
        SP<Person> person2 = person1;
        person2->display();

        SP<Person> person3;
        person3 = person2;
        person3->display(); 
    }
}