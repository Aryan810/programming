// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
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
vector<vector<pair<int, int> > > graph;
vector<int> vis;
vector<int> roles;
int dfs(int v, int role, bool & valid){
    vis[v] = 1;
    if (roles[v] != -1){
        if (role != roles[v]){
            valid = 0;
        }
    }else{
        roles[v] = role;
    }
    int ret = role;
    for (auto & ele: graph[v]){
        if (vis[ele.first]){
            if (ele.second == 1){
                if (roles[ele.first] != 1 - role){
                    valid = 0;
                }
            }else{
                if (roles[ele.first] != role){
                    valid = 0;
                }
            }
            continue;
        }
        if (!vis[ele.first]){
            ret += dfs(ele.first, ((ele.second)?(1 - role):role), valid);
        }
    }
    return ret;
}

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
    struct dsu ds(n);
    graph.clear();
    graph.resize(n+1);
    vis.resize(n+1);
    vis.assign(n+1, 0);
    roles.resize(n+1);
    roles.assign(n+1, -1);
    for (int i=0;i<m;i++){
        int u, v;cin >> u >> v;
        ds.set_union(u-1, v-1);
        string s;
        cin >> s;
        if (s == "imposter"){
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 1});
        }else{
            graph[u].push_back({v, 0});
            graph[v].push_back({u, 0});
        }
    }
    bool valid = 1;
    int ans = 0;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            int tot = ds.set_size[ds.find(i-1)];
            int possimp = dfs(i, 0, valid);
            ans += max(possimp, tot - possimp);
            if (!valid){
                cout << -1 << endl;return;
            }
        }   
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