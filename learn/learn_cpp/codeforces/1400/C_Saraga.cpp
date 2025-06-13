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

    string s, t;
    cin >> s >> t;

    vector<vector<int> > ds(26);
    vector<vector<int> > dt(26);

    for (int i=1;i<s.size();i++){
        ds[s[i]-'a'].push_back(i);
    }
    for (int i=1;i<t.size();i++){
        dt[t[t.size()-1-i]-'a'].push_back(i);
    }

    int i = 1;
    int j = t.size()-2;
    array<int, 3> ans = {(int)(1e18), -1, -1};
    for (int i=0;i<26;i++){
        if (ds[i].size() == 0 || dt[i].size() == 0){
            continue;
        }
        int f = ds[i].front();
        int l = dt[i].front();
        if (ans[0] > (f+l+1)){
            ans = {f+l+1, f, l};
        }
    }

    if (ans[0] == 1e18){
        cout << -1 << endl;return;
    }

    for (int i=0;i<=ans[1];i++){
        cout << s[i];
    }
    for (int i=(t.size()-ans[2]);i<t.size();i++){
        cout << t[i];
    }cout << endl;


}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int test;
    // cin >> test;

    // while(test--){
        solve();
    // }

    return 0;
}