#include <iostream>

using namespace std;

class BaseClass{
    public:
        int var_base;
        // void display(){
        virtual void display(){
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
    base_class_pointer = &obj_derived;
    base_class_pointer->display();
    

    return 0;
}