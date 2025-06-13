#include <iostream>

using namespace std;

class Base{
    protected: // like private but can be inherited.
        int a;
    public:
        int b;
};

class Derived: protected Base {

};

int main(){

    Base b;
    Derived d;
    // cout << d.a; // Gives error.
    cout << b.b;
    // cout << d.b; // Gives error as public member of base comes as protected member in protected visiblity mode.
    

    return 0;
}