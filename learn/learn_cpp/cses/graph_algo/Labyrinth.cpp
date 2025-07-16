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
const int INF = 1e15;

void bfs(pi & st, pi & en, int & n, int & m, vvi & grid){
    vvi lev(n, vector<int>(m, INF));
    queue<pi> q;
    lev[st.first][st.second] = 0;
    q.push(st);
    vector<pi> poss = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    vector<char> deno = {
        'U', 'D', 'L', 'R'
    };
    while (q.size() > 0){
        auto curr = q.front();q.pop();
        for (auto & ele: poss){
            pi nxt = {ele.first + curr.first, ele.second + curr.second};
            if ((nxt.first >= 0 && nxt.first < n) && ((nxt.second >= 0 && nxt.second < m) && !grid[nxt.first][nxt.second])){
                if (lev[nxt.first][nxt.second] == INF){
                    lev[nxt.first][nxt.second] = lev[curr.first][curr.second] + 1;
                    q.push(nxt);
                }
            }
        }
    }

    auto curr = en;
    if (lev[en.first][en.second] == INF){
        cout << "NO" << endl;return;
    }
    stack<char> path;

    while (curr != st){
        for (int i=0;i<4;i++){
            auto ele = poss[i];
            pi nxt = {ele.first + curr.first, ele.second + curr.second};
            if ((nxt.first >= 0 && nxt.first < n) && ((nxt.second >= 0 && nxt.second < m) && !grid[nxt.first][nxt.second])){
                if (lev[nxt.first][nxt.second] == lev[curr.first][curr.second] - 1){
                    path.push(deno[i]);
                    curr = nxt;
                }
            }
        }
    }
    cout << "YES" << endl;
    cout << path.size() << endl;
    while (path.size() > 0){
        cout << path.top();path.pop();
    }cout << endl;
}

void solve(){
    
    int n, m;
    cin >> n >> m;

    
    pi st;
    pi en;

    vvi grid(n, vector<int>(m));

    rep(i, n){
        rep(j, m){
            char c;
            cin >> c;
            if (c == '#'){
                grid[i][j] = 1;
            }else{
                grid[i][j] = 0;
            }

            if (c == 'A'){
                st = {i, j};
            }else if (c == 'B'){
                en = {i, j};
            }
        }
    }
    bfs(st, en, n, m, grid);    


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