#include <iostream>

using namespace std;

class Complex{
    int a, b;
    public:
        // Creating a constructor
        // It is a spetial member function which is automatically invoked when object is made.
        // It is used to initialise the objects of its class.

        Complex(int x, int y); // constructor declaration

        void getNum()
        {
            cout << "Number: " << a << " + " << b << "i" << endl;
        }
};

Complex :: Complex(int x, int y){
    a = x;
    b = y;
}

int main(){
    // Implicit call
    // Complex a(4, 6);

    // Explicit call
    Complex a = Complex(4, 6);
    a.getNum();

    return 0;
}