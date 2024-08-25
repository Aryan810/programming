#include <iostream>
#include <vector>
#include <string>

using namespace std;
int is_all_equal(vector<int> & nums){
    int a = nums[0];
    for (int i=0;i<nums.size();i++){
        if (nums[i] != a){
            return 0;
        }
    }
    return 1;
}

int main(){
    // vector<int> v;
    // // v.push_back(9);
    // // v.push_back(6);
    // // sort(v.begin(), v.end());
    // // cout << v[0] << endl;
    // // v.erase(v.begin(), v.end());
    // v.insert(v.end(), 2);
    // v.insert(v.end(), 2);
    // cout << is_all_equal(v);

    // string str = "1002";
    // string s = str.substr(0, 2);
    // cout << s << endl;
    // int k = 10;
    // for(int i=0;i<k;i++){
    //     if (i==2){
    //         k = 0;
    //     }
    //     cout << i << endl;
    // }

    cout << ((2%2)==0) << endl;

    return 0;
}