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
vector<vector<pi> > graph;
const int INF = 1e15;

void solve(){

    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    for (int i=0;i<m;i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({y, w});
    }

    vector<int> lev(n+1, INF);
    lev[1] = 0;
    vi vis(n+1, 0);
    set<pi> st;
    st.insert({0, 1});
    while (st.size() > 0){
        auto curr = *(st.begin());
        st.erase(st.begin());
        if (vis[curr.second]){continue;}
        vis[curr.second] = 1;
        for (auto & ele: graph[curr.second]){
            if (lev[ele.first] > curr.first + ele.second){
                lev[ele.first] = curr.first + ele.second;
                st.insert({lev[ele.first], ele.first});
            }
        }
    }

    for (int i=1;i<=n;i++){
        cout << lev[i] << " ";
    }cout << endl;

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