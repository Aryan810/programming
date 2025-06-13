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
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<pair<int, int> > v;
    for (int i=0;i<n;i++){
        if (a[i] < b[i]){
            v.push_back({b[i], i});
        }
    }
    sort(all(v));

    for (auto ele: v){
        int x = ele.first;
        int i = ele.second;
        // cout << x << " " << i << endl;
        int f = i;
        int s = i;
        int mx = 0;
        while ((f >= 0 && a[f] <= x) && (b[f] >= x)){
            mx =  max(mx, a[f]);
            f -= 1;
            if (a[f+1] == x){
                break;
            }
        }
        while ((s < n && a[s] <= x) && (b[s] >= x)){
            mx = max(mx, a[s]);
            s += 1;
            if (a[s-1] == x){
                break;
            }
        }
        // cout << f << " " << s << endl;
        for (int k=f+1;k<s;k++){
            a[k] = mx;
        }
        
        // for (auto ele: a){
        //     cout << ele << " ";
        // }cout << endl;
    }


    cout << ((a == b)?"YES":"NO") << endl;

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