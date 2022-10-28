#include <iostream>
#include<mutex>

using namespace std;


 mutex mu;

 
class Singleton{
    private:
    static Singleton* m_instance;
    Singleton()= default;
   

    public:
     ~Singleton(){
        cout << "deleting " << endl;
     }
    Singleton(const Singleton& )=delete;
    Singleton& operator=(const Singleton&)=delete;
    static Singleton* GetInstance();    

    void tell(){
        cout << "This is the singleton " << endl;
    }
    
};


Singleton* Singleton::m_instance=nullptr;

Singleton* Singleton::GetInstance(){
    lock_guard<mutex> mylock(mu);
    if(!m_instance){
        m_instance=new Singleton();
    }
    return m_instance;
}


int main(){
    Singleton::GetInstance()->tell();
    Singleton* ptr{Singleton::GetInstance()};
    Singleton* ptr1{Singleton::GetInstance()};
    
    cout << "Ptr1 " << ptr << " ptr2 " << ptr1 << endl;

    delete ptr;


}


