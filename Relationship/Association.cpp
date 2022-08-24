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

int main(){
    Professor p;
    Cource c;
    cout << "Hello Association and Dependency" << endl;
    p.st.remember(c.getKnowledge());
    return 0;
}
/*


*/