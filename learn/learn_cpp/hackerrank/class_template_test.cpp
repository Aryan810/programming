#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Complex
{
    public:
        int a,b;
        Complex operator + (Complex c1){
            Complex c3;
            c3.a = this->a + c1.a;
            c3.b = this->b + c1.b;
            return c3;
        }
        friend ostream& operator<<(ostream& os, const Complex& obj){
        os << obj.a << "+i" << obj.b;
        return os;
        }
        void get_complex(void){
            string s;
            cin >> s;
            int i = s.find("+i");
            this->a = stoi(s.substr(0, i));
            this-> b = stoi(s.substr(i+2, s.size()));
        }
    
}; 

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Complex c1, c2;
    c1.get_complex();
    c2.get_complex();
    Complex c3 = c1 + c2;
    cout << c3;
    return 0;
}