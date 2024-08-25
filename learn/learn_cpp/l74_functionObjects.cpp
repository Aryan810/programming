#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int main(){

    // Function object: A function wraped in a class, so that is available like a object ().
    int arr[] = {1, 3, 56, 4, 45, 34};
    sort(arr, arr+6, greater<int>());
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    


    return 0;
}