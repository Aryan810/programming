#include <iostream>

using namespace std;

int binary_search(int arr[], int size, int item){
    int first = 0, last = size-1, mid;
    // int iterations=0;
    while (1){
        // iterations += 1;
        mid = (first+last)/2;
        // cout << "first: " << first << " mid: " << mid << " last: " << last << endl;
        if (arr[mid] == item){
            // cout << iterations << endl;
            return mid;
        }else if(arr[mid] > item){
            last = mid - 1;
        }else{
            first = mid + 1;
        }
        if (first >= last){
            // cout << iterations << endl;
            return first;
        }
    }
    return -1;

}


int main(){
    int arr[] = {4, 5, 7, 8, 88, 566, 575, 600, 700, 640, 900, 1000};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr, arr+size);
    cout << arr[9] << endl;
    cout << binary_search(arr, size, 1) << endl;

    return 0;
}