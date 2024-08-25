#include <iostream>

using namespace std;

class A{
    int a;
    public:
        A & setData(int a){
            this->a = a;
            return *this;
        }

        void getData(){
            cout << "The value of a is "<<a<<endl;
        }
};

int main(){
    A a;
    a.setData(4).getData(); // here as 'setData()' function returns a reference variable to object 'a' we can directly write 'getData()' function to get data. 
                            // In setData() func. return type is 'A &' which denotes a reference variavlble.
    

    return 0;
}