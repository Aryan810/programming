#include <iostream>

using namespace std;

// int sum(int a, int b){
//     return (a+b);
// }

// call by reference by pointers.
// void swap(int* a, int*b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// call by reference with c++ reference variables.
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// returning a reference variables
int& refVar(int &a, int &b){
    return a;
}

int main(){
    int c = 1;
    int d = 10;
    // swap(c, d);
    refVar(c, d) = 900;
    cout << c;
    // cout << "c: " << c << "\nd: " << d << endl;

    return 0;
}
