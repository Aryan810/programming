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

bool comp(pair<pair<int, int>, vector<int> > & a, pair<pair<int, int>, vector<int> > & b){
    return (a.first.first < b.first.first);
}

void solve(){

    int n, m;
    cin >> n >> m;
    vector<int> num(n+1, 0);
    vector<int> out(m);
    vector<pair<pair<int, int>, vector<int> > > dta;
    for (int i=0;i<m;i++){
        int sz;
        cin >> sz;
        vector<int> ele(sz);
        for (int j=0;j<sz;j++){
            cin >> ele[j];
        }
        dta.push_back({{sz, i}, ele});
    }
    sort(all(dta), comp);
    for (int i=0;i<dta.size();i++){
        pair<int, int> req = {1e18, -1};
        int sz = dta[i].first.first;
        for (int j=0;j<sz;j++){ 
            int x = dta[i].second[j];
            if (req.first > num[x]){
                req = {num[x], x};
            }
        }
        out[dta[i].first.second] = req.second;
        num[req.second] += 1;
    }
    for (int i=1;i<num.size();i++){
        if (num[i] > (m+1)/2){
            cout << "NO" << endl;return;
        }
    }
    cout << "YES" << endl;
    for (auto ele: out){
        cout << ele << " ";
    }cout <<endl;
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