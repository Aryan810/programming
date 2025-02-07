// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
// using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){

    int n, m, d;
    cin >> n >> m >> d;
    vi s(m);
    rep(i, m) cin >> s[i];
    bool added = 0;
    if (s[0] != 1){
        s.insert(s.begin(), 1);
        added = 1;
    }

    vi nums;
    int befmid = 0;

    for (int i=0;i<s.size()-1;i++){
        befmid += (s[i+1]-s[i]-1)/d;
    }
    befmid += (n - s.back())/d;
    // cout << befmid << endl;
    for (int i=0;i<s.size();i++){
        if (i == 0){
            if (!added){
                // cout << "here" << endl;
                nums.push_back(befmid + s.size());
            }
        }else if (i < s.size()-1){
            // cout << "I: " << i << (befmid + (s[i+1]-s[i-1]-1)/d - (s[i]-s[i-1]-1)/d - (s[i+1]-s[i]-1)/d + s.size() - 1) << endl;
            nums.push_back(befmid + (s[i+1]-s[i-1]-1)/d - (s[i]-s[i-1]-1)/d - (s[i+1]-s[i]-1)/d + s.size() - 1);
        }else{
            nums.push_back(befmid - (s[i]-s[i-1]-1)/d -(n - s.back())/d + (n - s[s.size()-2])/d + s.size()-1);
        }
    }
    sort(all(nums));
    // for (auto ele: nums){
    //     cout << ele << " ";
    // }cout << endl;
    cout << nums[0] << " " << count(all(nums), nums[0]) << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}