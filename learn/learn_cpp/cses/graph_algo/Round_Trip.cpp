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
vi vis;
pi ledge = {-1, -1};
void dfs(int v, int p){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (ele == p) continue;
        if (vis[ele]){
            ledge = {ele, v};continue;
        }

        dfs(ele, v);
    }
}

void bfs(int & n){
    auto & le = ledge;
    queue<int> q;
    vi lev(n+1, -1);
    lev[le.first] = 0;
    q.push(le.first);
    while (q.size() > 0){
        int curr = q.front();
        q.pop();
        for (auto & ele: graph[curr]){
            if (lev[ele] == -1){
                if (!(curr == le.first && ele == le.second)){
                    lev[ele] = lev[curr] + 1;
                    q.push(ele);
                }
            }
        }
    }
    vi out;
    int curr = le.second;
    while (lev[curr] > 0){
        out.push_back(curr);
        for (auto & ele: graph[curr]){
            if (lev[ele] == lev[curr] - 1){
                curr = ele;
                break;
            }
        }
    }
    out.push_back(le.first);
    out.push_back(le.second);
    cout << out.size() << endl;
    for (auto & ele: out){
        cout << ele << " ";
    }cout << endl;
}

void solve(){
    
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    vis.assign(n+1, 0);
    for (int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dfs(i, 0);
        }
    }
    if (ledge == make_pair(-1ll, -1ll)){
        cout << "IMPOSSIBLE" << endl;return;
    }

    bfs(n);

    



    

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}