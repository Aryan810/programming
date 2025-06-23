// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

vector<set<int> > graph;
vector<int> vis;
bool found = 0;
set<int> st;
void dfs(int v, int parent, int & found){
    vis[v] = 1;
    st.insert(v);
    for (auto ele: graph[v]){
        if (vis[ele]){
            if (st.find(ele) != st.end()){
                found = 1;
                return;
            }
            continue;
        }
        dfs(ele, v, found);
    }
    st.erase(v);
}

void solve(){

    int n, k;
    cin >> n >> k;
    graph.clear();
    graph.resize(n+1);
    vis.clear();
    vis.resize(n+1);
    for (int i=0;i<k;i++){
        vi a(n);
        rep(i, n) cin >> a[i];
        for (int i=1;i<(n-1);i++){
            graph[a[i]].insert(a[i+1]);
        }
    }
    // for (int i=1;i<=n;i++){
    //     for (auto ele: graph[i]){
    //         cout << ele << " ";
    //     }cout << endl;
    // }
    int found = 0;
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            dfs(i, 0, found);
            if (found){
                break;
            }
        }
    }
    if (found){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }



}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}