#include<bits/stdc++.h>
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

void solve(){

    int n;
    cin >> n;

    // interaction begins !
    int l, r;
    l = 1;
    r = n;
    vector<bool> ispos(n+1, 1);
    
    while (l < r){
        // first check for first half
        int tmp = (l+r)/2;
        cout << "? " << l << " " << tmp << endl;cout.flush();
        vector<int> got;
        for (int i=l;i<=tmp;i++){
            int x;
            cin >> x;
            if (!(x >= l && x <= tmp)){
                ispos[x] = 0;
            }
            got.push_back(x);
        }
        // for (int i=1;i<=n;i++){
        //     cout << ispos[i] << " ";
        // }cout << endl;
        int native = 0;
        int noneed = 0;
        vector<int> natives;
        for (int i=l;i<=tmp;i++){
            if (ispos[i]){
                if (binary_search(all(got), i)){
                    native += 1;
                    natives.push_back(i);
                }else{
                    ispos[i] = 0;
                }
            }else{
                if (binary_search(all(got), i)){
                    noneed += 1;
                }
            }
        }
        // cout << native << endl;
        if (native%2 == 0){
            l = tmp + 1;
            for (auto ele: natives){
                ispos[ele] = 0;
            }
        }else{
            r = tmp;
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (ispos[i]){
            ans = i;break;
        }
    }
    cout << "! " << ans << endl;cout.flush();

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