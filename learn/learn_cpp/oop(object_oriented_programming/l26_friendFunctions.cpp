#include <iostream>

using namespace std;

class Complex
{
    int a, b;

public:
    void setNumber(int n1, int n2)
    {
        a = n1;
        b = n2;
    }

    friend Complex sumComplex(Complex o1, Complex o2);

    void getNum()
    {
        cout << "Number: " << a << " + " << b << "i" << endl;
    }
};

Complex sumComplex(Complex o1, Complex o2)
{
    Complex c;
    c.setNumber((o1.a + o2.a), (o1.b + o2.b));
    return c;
}

int main()
{

    Complex c1, c2;
    c1.setNumber(1, 4);
    c2.setNumber(5, 8);

    c1.getNum();
    c2.getNum();

    Complex sum = sumComplex(c1, c2);
    sum.getNum();

    return 0;
}