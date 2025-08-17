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
vvi graph;
vvi graph1;
vi vis1, vis2;
vi c;
void retmin(int v, int & mn, int & mnele, vi & loops){
    loops.push_back(v);
    if (c[v-1] < mn){
        mn = c[v-1];
        mnele = v;
    }
    vis2[v] = 1;
    vis1[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis2[ele]){
            retmin(ele, mn, mnele, loops);
        }
    }
}

void dfs(int v, int & loop){
    vis1[v] = 1;
    for (auto & ele: graph[v]){
        if (vis1[ele]){
            loop = ele;
            continue;
        }
        dfs(ele, loop);
    }
    vis1[v] = 0;
}

void dfs1(int v, vi & out){
    bool loopele = 0;
    if (vis1[v]){loopele = 1;}
    vis1[v] = 1;
    for (auto & ele: graph1[v]){
        if (!vis1[ele]){
            dfs1(ele, out);
        }
    }
    if (!loopele){out.push_back(v);}
}


void solve(){
    
    int n;
    cin >> n;
    graph.clear();
    graph.resize(n+1);
    graph1.clear();
    graph1.resize(n+1);
    vis1.assign(n+1, 0);
    vis2.assign(n+1, 0);
    c.assign(n+1, 0);
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        graph[i+1].push_back(x);
        graph1[x].push_back(i+1);
    }

    rep(i, n) cin >> c[i];
    vi out;

    for (int i=1;i<=n;i++){
        if (!vis1[i]){ 
            int loop = -1;
            int mn = 1e18;
            int mnele = -1;
            dfs(i, loop);
            if (loop == -1){continue;}
            vector<int> loops;
            retmin(loop, mn, mnele, loops);
            for (auto & ele: loops){
                dfs1(ele, out);
            }
            int j=0;
            while (j < loops.size() && loops[j] != mnele){
                j += 1;
            }
            j += 1;
            for (int k=0;k<loops.size();k++){
                out.push_back(loops[(j+k)%loops.size()]);
            }
        }
    }

    for (auto & ele: out){
        cout << ele << " ";
    }cout << endl;




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