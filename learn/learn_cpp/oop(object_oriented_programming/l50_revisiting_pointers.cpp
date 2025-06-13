#include <iostream>

using namespace std;

int main(){
    int a = 10;
    int* ptr = &a;
    cout << *ptr<<endl;

    // new operator
    float *p = new float(40.21);
    cout  << "The value at p is "<<*p<<endl;

    int* arr = new int[3];

    arr[0] = 1;
    *(arr + 1) = 2;
    arr[2] = 3;
    // delete[] arr; // releases the memory used by 'arr'.
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] <<endl;
    }
    

    return 0;
}