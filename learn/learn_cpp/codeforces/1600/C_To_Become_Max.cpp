#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int check(int n, vi & a, int k){
    int req = 1e18;
    for (int j=0;j<a.size();j++){
        int curr = n;
        int temp = 0;
        int valid = 1;
        for (int i=j;i<a.size();i++){
            if (curr <= a[i]){
                break;
            }
            if (i == a.size()-1 && curr > a[i]){
                valid = 0;
            }
            temp += curr - a[i];
            curr -= 1;
        }
        if (valid){req = min(temp, req);}
    }
    if (req <= k){
        return 1;
    }else{
        return 0;
    }
}

void solve(){

    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];
    int mx = *max_element(all(a));
    int j = n-1;


    int h = mx + k + 1;
    int l = mx;

    while (h - l > 1){
        int mid = (h + l)/2;
        
        if (check(mid, a, k)){
            l = mid;
        }else{
            h = mid - 1;
        }
    }

    if (check(h, a, k)){ 
        cout << h << endl;
    }else{
        cout << l << endl;
    }

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