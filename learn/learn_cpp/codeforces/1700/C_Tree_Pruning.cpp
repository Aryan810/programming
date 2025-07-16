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
#define vvi vector<set<int> >
#define vv(x) vector<vector<x> >
#define PRECISION(x) cout << fixed << setprecision(x);
#define mnv(v) *min_element(v.begin(), v.end())
#define mxv(v) *max_element(v.begin(), v.end())
#define umap(x, y) unordered_map<x, y, custom_hash>
const int mod7 = 1e9 + 7;
const int mod9 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
vi par;
vi vis;

int bfs(int & n, vvi & graph){
    queue<int> q;
    int ans = 1e18;
    q.push(1);
    int sm = 0;
    int removed = 0;
    while (q.size() > 0){
        // cout << "NOW" << endl;
        vector<int> nxtlev;
        while (q.size() > 0){
            sm += 1;
            int curr = q.front();
            vis[curr] = 1;
            q.pop();
            for (auto & ele: graph[curr]){
                if (!vis[ele]){
                    nxtlev.push_back(ele);
                }
            }
        }
        for (int i=0;i<nxtlev.size();i++){
            ans = min(ans, (int)(n - sm - nxtlev.size() + removed));
            if (nxtlev[i] != 1 && graph[nxtlev[i]].size() == 1){
                int curr = nxtlev[i];
                int lst = 0;
                while (1){
                    if (curr == 1 || graph[curr].size() > 2){break;}
                    // cout << curr << " " << lst << endl;
                    if (curr == 0){
                        break;
                    }
                    lst = curr;
                    curr = par[curr];
                    // cout << curr << endl;
                    removed += 1;
                }
                graph[curr].erase(lst);
            }
            // cout << "here" << endl;
            q.push(nxtlev[i]);
        }
    }
    return ans;
}

void dfs(int v, vvi & graph){
    vis[v] = 1;
    for (auto & ele: graph[v]){
        if (!vis[ele]){
            dfs(ele, graph);
        }else{
            par[v] = ele;
        }
    }
}

void solve(){
    
    int n;
    cin >> n;
    par.clear();
    par.assign(n+1, 0);
    vis.clear();
    vis.assign(n+1, 0);
    vvi graph(n+1);
    for (int i=0;i<(n-1);i++){
        int u, v;
        cin >> u >> v;
        graph[u].insert(v);
        graph[v].insert(u);
    }
    vis[1] = 1;
    dfs(1, graph);
    vis.assign(n+1, 0);
    int ans = bfs(n, graph);
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