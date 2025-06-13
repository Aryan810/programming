#include <iostream>

using namespace std;

class Simple{
     int data1;
     int data2;
     public:
        Simple(int a, int b = 9){
            data1 = a;
            data2 = b;
        }
        void printData(){
            cout << "The value of data is "<<data1<<" and "<<data2<<endl;
        }
};

class Complex{
    int a, b;
    public:
        Complex(){
            a = 0;
            b = 0;
        }
        Complex(int x = 0, int y = 0){
            a = x;
            b = y;
        }

        Complex(int x = 0){
            a = x;
            b = 0;
        }

        void printNum()
        {
            cout << "Number: " << a << " + " << b << "i" << endl;
        }
};

int main(){

    Simple s(1, 10), s1(1);
    s.printData();
    s1.printData(); 


    return 0;
}