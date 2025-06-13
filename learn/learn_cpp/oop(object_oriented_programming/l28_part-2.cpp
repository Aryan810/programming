#include <iostream>

using namespace std;

class c2;

class c1{
    int val;
    public:
        friend void swap(c1&, c2&);
        void indata(int a){
            val = a;
        }
        void display(){
            cout << val << endl;
        }
};

class c2{
    int val2;
    public:
    friend void swap(c1&, c2&);
        void indata(int a){
            val2 = a;
        }
        void display(){
            cout << val2 << endl;
        }
};

void swap(c1 & o1, c2 & o2){
    int temp = o2.val2;
    o2.val2 = o1.val;
    o1.val = temp;
}

int main(){
    c1 o1;
    o1.indata(90);
    c2 o2;
    o2.indata(10);
    swap(o1, o2);
 
    o1.display();
    o2.display();
    

    return 0;
}