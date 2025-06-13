#include <iostream>

using namespace std;

class Complex{
    int a, b;
    public:
        Complex(){
            a = 0;
            b = 0;
        }
        Complex(int x, int y){
            a = x;
            b = y;
        }

        Complex(int x){
            a = x;
            b = 0;
        }

        void printNum()
        {
            cout << "Number: " << a << " + " << b << "i" << endl;
        }
};

int main(){
    Complex c1(4, 7), c2(10), c3;
    c1.printNum();
    c2.printNum();
    c3.printNum();
    

    return 0;
}