#include <iostream>

/*
CASE_1 >>
class B: public A{
    // order of execution of constructor --> first A then B.
};

CASE_2 >>

class A: public B, public C{
    // Order of exec. of constructor --> first B, then C, then A.
};

CASE_3 >>

class A: public B, virtual public C{
    // order of execution of constructor --> first C, then B, then A.
}; 
*/

using namespace std;

class Base1{
    int data1;
    public:
        Base1(int i){
            data1 = i;
            cout << "Base1 class constructor called"<<endl;
        }
        void print_data1(void){
            cout << "The value of data1 of Base1 class is "<<data1<<endl;
        }
};

class Base2{
    int data2;
    public:
        Base2(int i){
            data2 = i;
            cout << "Base2 class constructor called"<<endl;
        }

        void print_data2(void){
            cout << "The value of data2 of Base2 class is "<<data2<<endl;
        }
};

class Derived : public Base1, public Base2{
    int derived1, derived2;
    public:
        Derived(int a, int b, int c, int d) : Base1(a), Base2(b){
            derived1 = c;
            derived2 = d;
            cout << "Derived class constructor called"<<endl;
        }
        void print_data(void){
            cout << "The value of derived1 is "<<derived1<<endl;
            cout << "The value of derived2 is "<<derived2<<endl;
        }
};

int main(){
    Derived der(10, 20, 30, 40);
    der.print_data();

    der.print_data1();
    der.print_data2();
    

    return 0;
}