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

    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n);
    rep(i, n) cin >> b[i];

    vector<int> out(n);

    vector<int> cum(n+1, 0);
    cum[0] = 0;
    vector<pair<pair<int, int>, int> > ord(n);
    for (int i=0;i<n;i++){
        ord[i] = {{a[i]-1, i}, b[i]};
    }
    sort(all(ord));
    int sm = 0;
    multiset<int> s;
    for (int i=0;i<n;i++){
        if (i >= k){
            if (ord[i].second > *s.begin()){
                sm += ord[i].second - *(s.begin());
                s.erase(s.begin());
                s.insert(ord[i].second);
            }
        }else{
            sm += ord[i].second;
            s.insert(ord[i].second);
        }
        cum[i+1] = sm;
    }

    for (int i=0;i<n;i++){
        int x = i;
        x = min(k, i);
        out[ord[i].first.second] = cum[i];
    }

    for (auto ele: out){
        cout << ele << " ";
    }cout << endl;



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