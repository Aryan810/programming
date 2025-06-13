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

    int n, m;
    cin >> n >> m;

    vi a(n), b(n), c(m);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, m) cin >> c[i];
    vector<set<int> > done(n+1);
    vector<set<int> > reqat(n+1);
    for (int i=0;i<n;i++){
        if (a[i] == b[i]){
            done[b[i]].insert(i);
        }else{
            reqat[b[i]].insert(i);
        }
    }
    int f = 0;
    int s = 0;
    vector<int> out;
    int last = -1;
    for (int i=(m-1);i>=0;i--){
        int col = c[i];
        if (reqat[c[i]].size() > 0){
            out.push_back(*reqat[c[i]].begin());
            last = *reqat[c[i]].begin();
            done[c[i]].insert(last);
            reqat[c[i]].erase(reqat[c[i]].begin());
            f += 1;
        }else if (done[c[i]].size() > 0){
            last = *done[c[i]].begin();
            out.push_back(last);
            s += 1;
        }else{
            if (last == -1){
                cout << "NO" << endl;return;
            }else{
                out.push_back(last);
            }
        }
    }

    int left_size = 0;
    for (int i=1;i<=n;i++){
        left_size += reqat[i].size();
    }

    if (left_size == 0){
        cout << "YES" << endl;
        for (int i=(out.size()-1);i>=0;i--){
            cout << out[i]+1 << " ";
        }cout << endl;
    }else{
        cout << "NO" << endl;
    }
    


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