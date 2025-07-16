// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
// using namespace atcoder;
// using mint = modint;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define each(x, a) for (auto &x : a)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pi pair<int, int>
#define p(a, b) pair<a, b>
#define vi vector<int>
#define vii vector<int>::iterator
#define vvi vector<vector<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

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
int n, m;
int ind(int i, int j){
    return (i*m + j);
}

void solve(){
    
    cin >> n >> m;
    struct dsu ds(n*m + 1);
    vvi grid(n, vector<int>(m, 0));
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int j=0;j<m;j++){
            if (s[j] == '.'){
                grid[i][j] = 0;
            }else{
                if (i > 0){
                    if (grid[i-1][j]){
                        ds.set_union(ind(i-1, j), ind(i, j));
                    }
                }
                if (j > 0){
                    if (grid[i][j-1]){
                        ds.set_union(ind(i, j-1), ind(i, j));
                    }
                }
                grid[i][j] = 1;
            }
        }
    }
    // iterating over all rows.
    int ans = 0;
    for (int i=0;i<n;i++){
        set<int> par;
        int temp = 0;
        if (i+1 < n){
            for (int j=0;j<m;j++){
                if (grid[i+1][j]){par.insert(ds.find(ind(i+1, j)));}
            }
        }
        if (i-1 >= 0){
            for (int j=0;j<m;j++){
                if (grid[i-1][j]){par.insert(ds.find(ind(i-1, j)));}
            }
        }
        for (int j=0;j<m;j++){
            if (grid[i][j]){
                int p = ds.find(ind(i, j));
                if (par.find(p) == par.end()){
                    temp += 1;
                }
            }else{
                temp += 1;
            }
        }
        for (auto & ele: par){
            temp += ds.set_size[ele];
        }
        ans = max(ans, temp);
    }

    // iterating all columns.
    for (int i=0;i<m;i++){
        set<int> par;
        int temp = 0;
        if (i+1 < m){
            for (int j=0;j<n;j++){
                if (grid[j][i+1]){par.insert(ds.find(ind(j, i+1)));}
            }
        }
        if (i-1 >= 0){
            for (int j=0;j<n;j++){
                if (grid[j][i-1]){par.insert(ds.find(ind(j, i-1)));}
            }
        }else{
            for (int j=0;j<n;j++){
                if (grid[j][i+1]){par.insert(ds.find(ind(j, i+1)));}
            }
            for (int j=0;j<n;j++){
                if (grid[j][i-1]){par.insert(ds.find(ind(j, i-1)));}
            }
        }
        for (int j=0;j<n;j++){
            if (grid[j][i]){
                int p = ds.find(ind(j, i));
                if (par.find(p) == par.end()){
                    temp += 1;
                }
            }else{
                temp += 1;
            }
        }
        for (auto & ele: par){
            temp += ds.set_size[ele];
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;



}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}