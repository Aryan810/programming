#include <iostream>

// Copy constructor

using namespace std;

class Number{
    int a;
    public:
        Number(){
            a = 0; 
        }
        Number(int num){
            a = num;
        }
        Number(Number &obj){
            // COPY CONSTRUCTOR.
            cout << "Copy constructor called!"<<endl;
            a = obj.a;
        }


        void display(){
            cout << "The number for this object is " << a << endl;
        }
};

int main(){

    Number x, y, z(45), z2;
    z.display ();
    Number z1(z); // copy constructor invoked.
    z1.display();

    // z2 = z; // here copy constructor is not called.
    Number z3 = z;

    return 0;
}