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

    int n, m, d;
    cin >> n >> m >> d;

    vi a(n);
    rep(i, n) cin >> a[i];

    multiset<int> positives;
    int sm = 0;
    int score = -1e18;
    for (int i=0;i<n;i++){
        score = max(score, sm + a[i] - d*(i+1));
        // cout << i << " " << score << endl;
        if (a[i] > 0 && (positives.size() < (m-1))){
            // cout << "HERE1" << endl;
            positives.insert(a[i]);
            sm += a[i];
            // cout << "HERE2" << endl;
        }else if (positives.size() > 0 && (a[i] > 0 && a[i] > *positives.begin())){
            // cout << "HERE3" << endl;
            sm += a[i] - (*positives.begin());
            // cout << "HERE 6" << endl;
            positives.erase(positives.begin());
            // cout << "HERE 5" << endl;
            positives.insert(a[i]);
            // cout << "HERE4" << endl;

        }
        // cout << i << " - " << score << endl;

    }
    cout << max(0ll, score) << endl;

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