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

    vi a(n);
    rep(i, n) cin >> a[i];

    vector<int> maximas, minimas;

    for (int i=1;i<n-1;i++){
        if (a[i-1] < a[i] && a[i+1] < a[i]){
            maximas.push_back(i);
        }else if (a[i-1] > a[i] && a[i+1] > a[i]){
            minimas.push_back(i);
        }
    }
    
    int ans = 0;
    for (int i=0;i<n-3;i++){
        // suarrays starting with this index;
        if (a[i] > a[i+1]){
            continue;
        }
        auto mx = upper_bound(all(maximas), i);
        auto mn = upper_bound(all(minimas), i);

        if (mx == maximas.end() || mn == minimas.end()){
            continue;
        }
        int lastposs = max(*mx, *mn) + 1;
        if (i+3 > lastposs){
            lastposs = i+3;
        }
        int endpos = n-1;
        int p, q;
        if (mx+1 != maximas.end() && mn+1 != minimas.end()){
            p = *(mx+1), q = *(mn + 1);
        }else if (mx+1 == maximas.end() && mn+1 != minimas.end()){
            p = n-1;
            q = *(mn + 1);
        }else if (mx+1 != maximas.end() && mn+1 == minimas.end()){
            q = n-1;
            p = *(mx + 1);
        }else{
            p = n-1;
            q = n-1;
        }
        endpos = min(p, q);
        ans += max(0ll, (int)(endpos - lastposs + 1));
        // cout << i << " " << lastposs << " " << endpos << " " << ans << endl;

    }
    cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        solve();
    
    return 0;
}