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
int n, m;

void bfs(){
    queue<int> q;
    q.push(1);
    const int INF = 1e15;
    vi lev(n+1, INF);
    lev[1] = 0;
    while (q.size() > 0){
        int curr = q.front();q.pop();
        for (auto & ele: graph[curr]){
            if (lev[ele] == INF){
                lev[ele] = min(lev[ele], lev[curr] + 1);
                q.push(ele);
            }
        }
    }

    if (lev[n] == INF){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << lev[n] + 1 << endl;
        int curr = n;
        stack<int> st;
        while (1){
            st.push(curr);
            if (curr == 1){
                break;
            }
            for (auto & ele: graph[curr]){
                if (lev[ele] == lev[curr]-1){
                    curr = ele;
                    continue;
                }
            }
        }
        while (st.size() > 0){
            cout << st.top() << " ";st.pop();
        }cout << endl;
    }
}

void solve(){
    
    cin >> n >> m;
    graph.clear();
    graph.resize(n+1);
    for (int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bfs();


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