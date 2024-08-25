#include <iostream>

using namespace std;

class Complex;

class Calculator{
    public: 
        int add(int a, int b){
            return (a+b);
        }

        int sumRealComplex(Complex, Complex);
        int sumImagComplex(Complex, Complex);
};

class Complex
{
    int a, b;

    public:
        void setNumber(int n1, int n2)
        {
            a = n1;
            b = n2;
        }

        // Making class as friend >>
        friend class Calculator;


        void getNum()
        {
            cout << "Number: " << a << " + " << b << "i" << endl;
        }
};

int Calculator :: sumRealComplex(Complex o1, Complex o2){
    return (o1.a + o2.a);
}
int Calculator :: sumImagComplex(Complex o1, Complex o2){
    return (o1.b + o2.b);
}

int main(){
    Complex o1, o2;
    o1.setNumber(1, 4);
    o2.setNumber(9, 7);

    Calculator calc;
    // int res = calc.sumRealComplex(o1, o2);
    int res = calc.sumImagComplex(o1, o2);
    
    cout << "Sum is " << res;
    

    return 0;
}
