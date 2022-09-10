#include <iostream>

using namespace std;

// product Interface : doSomething()
class IProduct{
    public:
    virtual string getName()=0;
    virtual ~IProduct(){}
};


// concreateProduct BMW
class BMW:public IProduct{
    public:
    string getName(){
        return "BMW";
    }
};

// concreateProduct Audi
class Audi:public IProduct{
    public:
    string getName(){
        return "Audi";
    }
};


// Factory Class : which have create product Method and depends on product Interface  --> this Factory will create the product 
class Factory{
    public: 
    virtual IProduct* createCar()=0;
    virtual ~Factory(){}
};

// concreatefacrtory A 
class BMWFactory:public Factory{
    public:
    IProduct* createCar(){
        return new BMW();
    }
};

// conceretefacrtory B 

class Audifactory:public Factory{
    public:
    IProduct* createCar(){
        return new Audi();
    }
};


int main(){
    Factory *pfactory=new BMWFactory();
    IProduct* pcar=pfactory->createCar();
   cout <<  pcar->getName() << " Created " << endl;
    pfactory=new Audifactory();
    pcar=pfactory->createCar();
    cout <<  pcar->getName() << " Created " << endl; 
    delete pcar;
    delete pfactory;
    return 0;
}