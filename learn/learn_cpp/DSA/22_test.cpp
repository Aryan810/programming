#include <iostream>

using namespace std;

int main(){

    int * arr = (int*)malloc(4*sizeof(int));
    // int * a = arr + 1;
    arr[0] = 123;
    arr[1] = 244;
    arr[2] = 52564;
    arr[3] = 3624;
    // arr[4] = 23;
    delete arr; // deletes full array not just the first element to which it points.
    cout << arr[0];
    cout << arr[1];
    cout << arr[2];
    cout << arr[3];
    // cout << arr[4];

    return 0;
}