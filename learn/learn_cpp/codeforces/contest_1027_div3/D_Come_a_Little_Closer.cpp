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

    vector<pair<int, int> > row(n);
    rep(i, n) cin >> row[i].first >> row[i].second;
    if (n == 1){
        cout << 1 << endl;return;
    }
    vector<pair<int, int> > col(n);
    for (int i=0;i<n;i++){
        col[i] = {row[i].second, row[i].first};
    }
    sort(all(row));
    sort(all(col));
    int ans = 1e18;    
    for (int i=0;i<n;i++){
        int t, b, r, l;
        // min-row
        auto f = row[0];
        auto s = row[1];
        if (f == row[i]){
            t = s.first;
        }else{
            t = f.first;
        }

        // max-row
        f = row[n-1];
        s = row[n-2];
        if (f == row[i]){
            b = s.first;
        }else{
            b = f.first;
        }

        // right
        f = col[n-1];
        s = col[n-2];
        if (f == make_pair(row[i].second, row[i].first)){
            r = s.first;
        }else{
            r = f.first;
        }

        // left
        f = col[0];
        s = col[1];
        if (f == make_pair(row[i].second, row[i].first)){
            l = s.first;
        }else{
            l = f.first;
        }
        // cout << row[i].first << " - " << row[i].second << endl;
        // cout << i << " " << t << " " << b << " " << l << " " << r << endl;
        int len = (b-t+1);
        int bre = (r-l+1);
        if (len*bre >= n){
            ans = min(ans, max(0ll, len*bre));
        }else{
            if (len > bre){
                len += 1;
            }else{
                bre += 1;
            }
            ans = min(ans, max(0ll, len*bre));
        }
       
    }
    cout << ans << endl;



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