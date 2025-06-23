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
vector<int> lev;

void bfs(int n){
    queue<int> q;
    q.push(1);
    vi vis(n+1, 0);
    while (q.size() > 0){
        int curr = q.front();q.pop();
        vis[curr] = 1;
        for (auto & ele: graph[curr]){
            if (!vis[ele]){
                lev[ele] = lev[curr] + 1;
                q.push(ele);
            }
        }
    }   
}

void solve(){
    
    int n;
    cin >> n;
    graph.clear();
    graph.resize(n+1);
    lev.assign(n+1, 0);
    for (int i=0;i<(n-1);i++){
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    vi a(n);
    rep(i, n) cin >> a[i];  
    bfs(n);

    int curr = 0;
    for (int i=0;i<n;i++){
        if (lev[a[i]] != curr){
            if (lev[a[i]] == curr+1){
                curr += 1;
            }else{
                cout << "No" << endl;return;
            }
        }
    }
    int i = 0;
    int j = 0;
    while (i < n){
        while (j < n && lev[a[i]] == lev[a[j]]){
            j += 1;
        }
        // cout << i << " " << j << endl;
        auto & st = graph[a[i]];
        if (a[i] != 1){
            while (st.size() > 1){
                if (j >= n || st.find(a[j]) == st.end()){
                    cout << "No" << endl;return;
                }else{
                    st.erase(a[j]);
                    j += 1;
                }
            }
        }else{
            while (st.size() > 0){
                if (j >= n || st.find(a[j]) == st.end()){
                    cout << "No" << endl;return;
                }else{
                    st.erase(a[j]);
                    j += 1;
                }
            }
        }
        i += 1;
    }

    cout << "Yes" << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
        solve();

    return 0;
}