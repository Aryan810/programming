#include <iostream>

using namespace std;

template <class t1>
void print(t1 data){
    cout << data << endl;
}

template <class t2>
void swap_(t2& a, t2& b){
    t2 temp = a;
    a = b;
    b = temp;
}

int main(){

    // printf("The average is > %.3f", funcAvg(2.232, 4.232));
    int x=1, y=2;
    swap_(x, y);
    print(x);
    print(y);


    return 0;
}