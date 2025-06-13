#include <iostream>

using namespace std;

class Complex{
    int a, b;
    public:
        // Creating a constructor
        // It is a spetial member function which is automatically invoked when object is made.
        // It is used to initialise the objects of its class.

        Complex(void); // constructor declaration

        void getNum()
        {
            cout << "Number: " << a << " + " << b << "i" << endl;
        }
};

Complex :: Complex(void){  // --->> as it takes no parameteres it is a default constructor.
    a = 0;
    b = 0;
}

int main(){

    Complex c;
    c.getNum();

    return 0;
}