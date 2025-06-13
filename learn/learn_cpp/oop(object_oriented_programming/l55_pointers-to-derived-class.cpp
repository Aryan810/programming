#include <iostream>

using namespace std;

class BaseClass{
    public:
        int var_base;
        void display(){
            cout << "BASE CLASS variable is "<<var_base<<endl;
        }

};

class DerivedClass : public BaseClass{
    public:
        int var_derived;
        void display(){
            // cout << "BASE CLASS variable is "<<var_base<<endl;
            cout << "DERIVED CLASS variable is "<<var_derived<<endl;
        }   
};

int main(){
    BaseClass * base_class_pointer;
    BaseClass obj_base;
    DerivedClass obj_derived;
    base_class_pointer = &obj_derived; // pointer points DerivedClass but as it is a pointer of BaseClass it runs methods and use variables of BaseClass not Derived class.
    // base_class_pointer->var_base = 34;
    // base_class_pointer->display();
    // base_class_pointer->var_derived = 134; // not valid and gives an error.
    DerivedClass * der_class_pointer;
    der_class_pointer = &obj_derived;
    der_class_pointer->var_derived = 454;
    der_class_pointer->display();
    

    return 0;
}