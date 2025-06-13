#include <iostream>

using namespace std;

int main(){

    int* ptr = (int*) malloc(2*sizeof(int));
    *(ptr) = 1;
    *(ptr + 1) = 130;
    *(ptr+2) = 6;
    *(ptr+3) = 454;
    *(ptr+4) = 452323244;
    *(ptr+5) = 45234;
    cout << *(ptr+5);

    return 0;
}