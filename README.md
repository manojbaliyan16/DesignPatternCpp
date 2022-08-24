# Design Pattern in CPP : 
#### This is for understanding the basic concepts of system desing and for the same I am following
## Dive Into DESIGN PATTERNS from [Refactoring Guru](https://refactoring.guru/design-patterns/book)
## Before Deep Dive into Design Patterns We will start move as per below agenda.
- Basic OOPS Concpets

> Abstraction: Dipicts the only required information.

> Interface: This the public part of an object which is open to interact with other objects, With interface we can define the contract between two objects.

> Encapsulation:  The Ecapsulation having the ability to hide the object's state and behaviour and exposing only limited interface to rest of the program. Encapsulate something means to make it Private or a bit less restrictive by making it protected.

> Inheritance: Interface is the mechanism to make a new class on the top of existing calss, by reusing the existing class code. New class or sub class will have the same interface as super class is having means we can't hide any method in the sub class which already existing into the super class, eventhough we can extand the functionality of the sub class by adding some extra function as per the requirment. and We have to implement all abstract methods in the sub class even these methods doesn't have any sense to our subclass.

> Polymorphism, Every subclass needs to override base or super class method on its own
and polymorphism provies us the ability to identify the real class of an object and calls its implementation even when its real type is unknown in the current context.


- Relation between Objects: 
### Dependency:
> ![Dependency](https://github.com/manojbaliyan16/DesignPatternCpp/blob/main/images/dependecy.png)

> Here source class is called the client and the target class is called the supplier, if there is a change into behaviour or structure of the target, there might be changes into source. here cart is depends on the product, So both are said to be dependent.
Below are a few reason listed by which dependency occur
  (i) Specifying the types in method signature.
  (ii) When instantiating object by constructor call.
### Association:
![Association](https://github.com/manojbaliyan16/DesignPatternCpp/blob/main/images/Association.png)

```
#include <iostream>
using namespace std;

class Cource {
    public:
    Cource(){}
    Cource(Cource &c){}
    bool getKnowledge(){
        return true;
    }
};
class Student{
    Cource c;
    public:
    void remember(bool){
    }
    int x;
};
class Professor{
     public:
    Student  st;
    void teach(Cource c){
        cout << c.getKnowledge() << endl;
         bool x=true;
        st.remember(x);
    }
    
};
};

int main(){
    Professor p;
    Cource c;
    cout << "Hello Association and Dependency" << endl;
    p.st.remember(c.getKnowledge());
    return 0;
}
```

> Here teach() Method takes an argument of the Course, which is then used in to body of the method. If someone changes the getknowledge() method of the Course Class, this code will break, It is called dependency.
Now look at the Student field, how this field being used in Professor class's teach method. This is also a dependency for Professor means if the method remember will change the Professor code will break, However Since the Student field always accessible to any method of the Professor, so The Student class is not just a dependency but also an association.

