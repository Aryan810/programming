#include <iostream>

using namespace std;

class Y;

class X{
    int data;
    public:
        friend void add(X, Y);
        void setValue(int value){
            data = value;
        }
};

class Y{ 
    int num;
    public:
        friend void add(X, Y);
        void setValue(int value){
            num = value;
        }
};

 void add(X o1, Y o2){
    cout << "Sum of data of classes X and Y is: "<< (o1.data + o2.num);
 }

int main(){
    X x;
    Y y;

    x.setValue(50);
    y.setValue(40);
    add(x, y);

    

    return 0;
}