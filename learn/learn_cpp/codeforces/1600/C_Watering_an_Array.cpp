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
int larger_or_equal_to_this(int i, int x, vector< vector<int> > & hash){
    if (i == 0){
        return 0;
    }
    auto it = lower_bound(hash[i-1].begin(), hash[i-1].end(), x);
    return (int)(hash[i-1].end() - it);
}
void solve(){

    int n, k, d;
    cin >> n >> k >> d;

    vi a(n);        
    rep(i, n) cin >> a[i];
    // if (s == 3){
    //     cout << n << " " << k << " " << d << endl;
    //     cout << endl;
    //     for (auto ele: a){
    //         cout << a[0] << " ";
    //     }cout << endl;
    // }
    vi v(k);
    rep(i, k) cin >> v[i];
    int p = 10;
    int q = 3;
    vector<int> days(q*n + p);

    for (int i=0;i<(q*n + p);i++){
        days[i] = v[i%k];
    }

    vector<vector<int> > hash(q*n + p);
    multiset<int> temp;
    for (int i=0;i<(q*n + p);i++){
        temp.insert(days[i]);
        for (auto ele: temp){
            hash[i].push_back(ele);
        }
    }

    int score = 0;
    if (a[0] == 0){
        score = d/2;
    }
    for (int i=0;i<=min(d-1, q*n + p);i++){
        int fscore = 0;
        for (int j=0;j<n;j++){
            if (larger_or_equal_to_this(i, j+1, hash) + a[j] == j+1){
                fscore += 1;
            }
        }
        score = max(score, fscore + (d-1-i)/2);
    }
    cout << score << endl;

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