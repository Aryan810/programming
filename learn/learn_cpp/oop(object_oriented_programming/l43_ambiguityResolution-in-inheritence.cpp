#include <iostream>

using namespace std;

class Base1{
    public:
        void greet(){
            cout << "How are you!" << endl;
        }
};

class Base2{
    public:
        void greet(){
            cout << "Kaise Ho!" << endl;
        }

};

class Derived : public Base1, public Base2{
    int a;
    public:
        void great(){
            Base1 :: greet();
        }
};

class B{
    public:
        void say(){
            cout << "Hello world!"<<endl;
        }
};

class D: public B{
    int a;
    public:
        void say(){
            cout << "Hello my beautiful people"<<endl;
        }
};

int main(){
    // Ambiguity 1

    // Base1 base1obj;
    // Base2 base2obj;
    // Derived der;
    // base1obj.greet();
    // base2obj.greet();
    // der.great();

    // Ambiguity 2
    B b;
    D d;
    b.say();
    d.say();


    return 0;
}