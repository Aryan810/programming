#include <iostream>

using namespace std;

class Complex{
    int real, imaginary;
    public:
        void getData(){
            cout << "The number is: "<<real<<" + "<<imaginary<<"i"<<endl;
        }
        void setData(int a, int b){
            real = a;
            imaginary = b;
        }
};

int main(){

    Complex c1;
    // Complex *ptr = &c1;
    Complex *ptr1 = new Complex;
    c1.setData(1, 3);
    c1.getData();
    (*ptr1).setData(3, 9);
    // (*ptr).getData();
    ptr1->getData();


    // Array of objects.
    Complex *ptr = new Complex[4];
    ptr -> setData(1, 2);
    ptr -> getData();
    (ptr + 1) -> setData(5, 9);
    (ptr + 1) -> getData();
    return 0;
}