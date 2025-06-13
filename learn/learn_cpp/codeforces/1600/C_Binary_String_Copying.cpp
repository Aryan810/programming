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

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<pair<int, int> > v(m);

    rep(i, m) cin >> v[i].first >> v[i].second;

    int tmp1 = -1;
    int tmp2 = -1;
    vector<int> last_zero(n);
    vector<int> last_one(n);
    for (int i=0;i<n;i++){
        if (s[i] == '0'){
            tmp1 = max(i, tmp1);
        }
        last_zero[i] = tmp1;
        if (s[i] == '1'){
            tmp2 = max(i, tmp2);
        }
        last_one[i] = tmp2;
    }

    vector<int> next_zero(n);
    vector<int> next_one(n);
    tmp1 = n, tmp2 = n;
    for (int i=n-1;i>=0;i--){
        if (s[i] == '0'){
            tmp1 = min(i, tmp1);
        }
        next_zero[i] = tmp1;
        if (s[i] == '1'){
            tmp2 = min(i, tmp2);
        }
        next_one[i] = tmp2;
    }


    set<pair<int, int> > net_sorting_area;
    int ans = 0;
    for (int i=0;i<m;i++){
        int lnet = next_one[v[i].first-1];
        int rnet = last_zero[v[i].second-1];
        if (rnet <= lnet){
            ans = 1;
        }else{
            net_sorting_area.insert({lnet, rnet});
        }
    }

    ans += net_sorting_area.size();
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