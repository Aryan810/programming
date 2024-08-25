#include <iostream>
using namespace std;
/*
Syntax for initialisation list constructor:
constructor (argument-list) : intilization-section
{
    assignments + other code;
}

class Test{
    int a;
    int b;
    public:
        Test(int i, int j): a(i), b(j){
            cout << "Constructor executed!";
        }

};

*/

class Test{
    int a;
    int b;
    public:
        // Test(int i, int j): a(i), b(j)
        // Test(int i, int j): a(i), b(i+j)
        // Test(int i, int j): a(i), b(2*j)
        // Test(int i, int j): a(i), b(a + j)
        Test(int i, int j): b(j), a(i+b)
        {
            cout << "Constructor executed!"<<endl;
            cout << "Value of a is: "<<a<<endl;
            cout << "Value of b is: "<<b<<endl;
        }
};

using namespace std;

int main()
{
    Test t(4, 6);
    return 0;
}