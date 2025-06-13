#include <iostream>

using namespace std;

class Base1{
    protected:
        int base1int;
    public:
        void set_base1int(int a){
            base1int = a;
        }
};

class Base2{
    protected:
        int base2int;
    public:
        void set_base2int(int a){
            base2int = a;
        }
};
class Base3{
    protected:
        int base3int;
    public:
        void set_base3int(int a){
            base3int = a;
        }
};

class Derived : public Base1, public Base2, public Base3{
    public:
        void show(void){
            cout << "The value of base1int = "<<base1int<<endl
                 <<"The value of base2int = "<<base2int<<endl
                 <<"The value of base3int = "<<base3int<<endl;
            cout<<"The sum is : " <<(base1int+base2int+base3int)<<endl;
        }
};

/*
IN DERIVED CLASS:

    base1int, base2int >> protected.
    set_bas1int(), set_base2int >> public.
    show() >> public
*/

int main(){
    Derived der;
    der.set_base1int(10);
    der.set_base2int(200);
    der.set_base3int(3000);
    der.show();
    

    return 0;
}