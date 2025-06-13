#include <iostream>

using namespace std;

template <class T>
class Aryan{
    public:
        T data;
        Aryan(T a): data(a){}
        void display();
};

template <class T>
void Aryan <T> :: display(){
    cout << "Data: " << data << endl;
}

void func(int a){
    cout << "I am first func(): " << a <<endl;
}

template <class T>
void func(T a){
    cout << "I am templated func 1: " << a <<endl;
}



int main(){
    // Aryan <float> h(5.3);
    // h.display();

    func(10.3);
    

    return 0;
}