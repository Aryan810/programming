#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void show(vector<int> nums){
//     cout << "SHOWING: " << endl;
//     for (int i=0;i<nums.size();i++){
//         cout << nums[i] << endl;
//     }
// }

int main(){

    int t;
    cin >> t;

    int n, s, m;

    for (int i=0;i<t;i++){
        cin >> n >> s >> m;
        vector<int> l(n), r(n), gaps(n+1);
        
        for (int j=0;j<n;j++){
            cin >> l.at(j) >> r.at(j);
        }
        gaps[0] = l[0] - 0;
        gaps[n] = m - r[n-1];
        for (int j=1;j<n;j++){
            gaps[j] = l[j] - r[j-1];
        }
        if (*max_element(gaps.begin(), gaps.end()) >= s){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        // show(gaps);

    }

    return 0;
}