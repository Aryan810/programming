#include <iostream>
#include <vector>
#include <algorithm>

// why i have to make global variable INDEX, why if i just return the 'index' at line 23 it return absurd value ???
using namespace std;
int INDEX = 0;

// void show(vector<int> nums){
//     cout << "SHOWING: " << endl;
//     for (int i=0;i<nums.size();i++){
//         cout << nums[i] << endl;
//     }
// }

void max_last_element(vector<int> v){
    int index = max_element(v.begin(), v.end())-v.begin();
    // cout << "index: " << index << endl;
    // show(v);
    // cout << "test: " << ((index%2)==0) << endl;
    if ((index%2) == 0){
        // cout << "YEES" << endl;
        INDEX = index;
    }else{
        v[index] = 0;
        max_last_element(v);
    }
}

int main(){

    int t;
    cin >> t;
    int n;

    for (int i=0;i<t;i++){
        cin >> n;
        vector<int> arr(n);
        for (int j=0;j<n;j++){
            cin >> arr[j];
        }
        max_last_element(arr);
        cout << arr[INDEX] << endl;
    }

    return 0;
}