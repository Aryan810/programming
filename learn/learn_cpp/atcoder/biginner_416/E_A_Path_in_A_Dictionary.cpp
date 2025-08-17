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
vector<set<int> > graph;
vi vis;
stack<int> st;
int n, m, x, y;
bool done = 0;
void dfs(int v){
    if (!done){st.push(v);}
    if (v == y){
        done = 1;
    }
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dfs(ele);
        }
    }
    if (!done){st.pop();}
}

void solve(){
    
    cin >> n >> m >> x >> y;
    done = 0;
    graph.clear();
    
    graph.resize(n+1);
    vis.assign(n+1, 0);
    for (int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    dfs(x);

    vi out;
    while (st.size() > 0){
        out.push_back(st.top());st.pop();
    }

    reverse(all(out));

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