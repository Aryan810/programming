#include <iostream>

using namespace std;

template <class t1=int, class t2=float>
class Aryan{
    public:
        t1 a;
        t2 b;
        Aryan(t1 x, t2 y){
            a = x;
            b = y;
        }
        void display(){
            cout << "The value of a is "<<a<<endl;
            cout << "The value of b is "<<b<<endl;
        }
};

int main(){
    Aryan <char, char> h('c', 'd');
    h.display();
    

    return 0;
}