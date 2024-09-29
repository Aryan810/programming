#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int a = 1000000000;
    int b = 1000000000;
    // float c = (log2(__LONG_LONG_MAX__) + 1)/8;
    // long int c = a * b; // gives absurd output
    long int c = a * 1LL * b; // works fine
    cout << c << endl;

    return 0;
}