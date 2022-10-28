#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Iobserver{
    public:
    virtual void Update(float price)=0;
    virtual ~Iobserver(){}
};

class Observer:public Iobserver{ 
    private:
    string m_name;
    public:
    Observer(string name):m_name(name){}
    void Update(float price) override{
        cout << "The Price is " << price << endl;
    }

};

// Subject / Pubisher 
class Isubject{
    public:
    virtual ~Isubject(){};
    virtual void attach(Iobserver*)=0;
    virtual void detach(Iobserver*)=0;
    virtual void notify()=0;
};

class Subject:public Isubject{
    private : 
    list<Iobserver*> m_observers{};
    float m_price;
    public:
    Subject(){
        m_price=10.0;
    }
    void SetPrice(float price){
        m_price=price;
    }
    void attach(Iobserver* subscriber) override{
        m_observers.push_back(subscriber);
        
    }
     void detach(Iobserver* subscriber) override{
       m_observers.remove(subscriber);
        
    }
    void notify() override{
        auto itr=m_observers.begin();
        while(itr!=m_observers.end()){
            (*itr)->Update(m_price);
            itr++;
        }
        
    }
};


int main(){
    Subject* pSubject= new Subject();
    Iobserver* pObserver1=new Observer("Manoj");
    Iobserver* pObserver2=new Observer("Kumar");
    
    pSubject->attach(pObserver1);
    pSubject->attach(pObserver2);
   
    pSubject->SetPrice(12.5);
    pSubject->notify();

    pSubject->detach(pObserver2);


     pSubject->SetPrice(15.5);
    pSubject->notify();

    delete pObserver1;
    delete pObserver2;
    delete pSubject;
    return 0;
}