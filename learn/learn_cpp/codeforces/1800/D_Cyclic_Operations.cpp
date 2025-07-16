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
vvi graph2;
vi vis;
int bfs(int & n, int & k, vi & heads){
    queue<int> q;
    vi lev(n+1, -1);

    for (auto & ele: heads){
        q.push(ele);
        lev[ele] = 0;
    }

    while (q.size() > 0){
        int curr = q.front();q.pop();

        for (auto & ele: graph[curr]){
            if (lev[ele] == -1){
                lev[ele] = lev[curr] + 1;
                q.push(ele);
            }else{
                if (lev[curr] + 1 - lev[ele] != k){
                    return 0;
                }
            }
        }
    }
    return 1;
}

void dfs(int v){
    vis[v] = 1;
    for (auto & ele: graph2[v]){
        if (!vis[ele]){
            dfs(ele);
        }
    }
}

void solve(){
    
    int n, k;
    cin >> n >> k;
    graph.clear();
    graph.resize(n+1);
    graph2.clear();
    graph2.resize(n+1);
    vis.assign(n+1, 0);
    vi b(n);
    rep(i, n){
        int x;
        cin >> x;
        b[i] = x;
        graph[i+1].push_back(x);
        graph2[i+1].push_back(x);
        graph2[x].push_back(i+1);
    }
    if (k == 1){
        for (int i=0;i<n;i++){
            if (b[i] != i+1){
                cout << "NO" << endl;return;
            }
        }
        cout << "YES" << endl;return;
    }
    vi heads;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            heads.push_back(i);
            dfs(i);
        }
    }

    cout << ((bfs(n, k, heads))?"YES":"NO") << endl;


    

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