#include <iostream>
#include <string>

using namespace std;
class ICar{
    public:
    virtual ~ICar(){}
    virtual std::string getName()=0;
};

class IBike{
    public:
    virtual ~IBike(){}
    virtual std::string getName()=0;
};


class BMWCar:public ICar{
    public:
    string getName(){
        return "BMWCar";
    }
};

class AudiCar:public ICar{
    public:
    string getName(){
        return "AudiCar";
    }
};

class HondaBike:public IBike{
    public:
    string getName(){
        return "HondaBike";
    }
};

class BulletBike:public IBike{
    public:
    string getName(){
        return "BulletBike";
    }
};


class IFactory{
    public:
    virtual ~IFactory(){}
   virtual ICar* CreateCar()=0;
   virtual IBike* CreateBike()=0;
};


class ConcreteFacrtoryX:public IFactory{
    public:
  ICar* CreateCar(){
    return new BMWCar();
  }
  IBike* CreateBike(){
    return new HondaBike();
  }
   
};
class ConcreteFacrtoryY:public IFactory{
    public:
  ICar* CreateCar(){
    return new AudiCar();
  }
  IBike* CreateBike(){
    return new BulletBike();
  }
   
};

int main(){
ConcreteFacrtoryX* factoryX= new ConcreteFacrtoryX();
ConcreteFacrtoryY* factoryY= new ConcreteFacrtoryY();
ICar* p1=factoryX->CreateCar();
cout << p1->getName() << endl;
ICar* p2=factoryY->CreateCar();
cout << p2->getName() << endl;
IBike* p3=factoryX->CreateBike();
IBike* p4=factoryY->CreateBike();
cout << p3->getName() << endl;
cout << p4->getName() << endl;


delete p1;
delete p2;
delete p3;
delete p4;
delete factoryX;
delete factoryY;
return 0;
}
