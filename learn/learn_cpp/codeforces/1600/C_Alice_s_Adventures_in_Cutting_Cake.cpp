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

struct dsu{
    int n;
    vector<int> parent, set_size;
    dsu(int n){
        this->n = n;

        parent.resize(n);

        set_size.resize(n);

        for (int i = 0; i < n; i++){

            parent[i] = i;

            set_size[i] = 1;
        }
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent [v] = find (parent [v]);
    }
    void set_union (int a, int b){
        a = find(a);
        b = find (b);
        if(a != b){
            if(set_size[a] < set_size [b]){
                swap (a, b) ;
            }
            parent[b] = a;
            set_size[a] += set_size[b];
        }   
    }
};

void solve(){

    int n, m, v;
    cin >> n >> m >> v;

    vi a(n);
    rep(i, n) cin >> a[i];
    vector<int> cum(n+1);
    cum[0] = 0;
    int tmp = 0;
    for (int i=0;i<a.size();i++){
        tmp += a[i];
        cum[i+1] = tmp;
    }
    vector<pair<int, int> > pre, suf;
    int i=0, j=0;
    
    int sm = 0;
    int left = m;
    while (left > 0){
        while (sm < v){
            if (j >= a.size()){
                cout << -1 << endl;return;
            }
            sm += a[j];
            j += 1;
        }

        left -= 1;
        pre.push_back({i, j});
        i = j;
        sm = 0;
    }

    sm = 0;
    left = m;
    i = n-1;
    j = n-1;
    while (left > 0){
        while (sm < v){
            if (j < 0){
                cout << -1 << endl;return;
            }
            sm += a[j];
            j -= 1;
        }
        left -= 1;
        suf.push_back({i, j});
        i = j;
        sm = 0;
    }
    int ans = 0;
    // for (auto &ele: pre){
    //     cout << ele.first << " " << ele.second << endl;
    // }
    // cout << endl;
    // for (auto &ele: suf){
    //     cout << ele.first << " " << ele.second << endl;
    // }
    for (int i=0;i<=m;i++){
        int r = (i < m)?suf[m-i-1].second : n-1;
        int l = (i > 0)?pre[i-1].second : 0;
        // cout << i << " " << l << " " << r << endl;
        if (r < l){continue;}
        int temp = cum[r + 1] - cum[l];
        ans = max(temp, ans);
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