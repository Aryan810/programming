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
int vis[51][51];
void blockb(pi v, vector<vector<char> > & grid, int & n, int & m){
    vis[v.first][v.second] = 1;
    vector<pi> poss = {
        {0, -1}, 
        {-1, 0}, 
        {1, 0},
        {0, 1}
    };

    for (auto & ele: poss){
        pi nxt = {v.first + ele.first, v.second + ele.second};
        if (((nxt.first >= 0 && nxt.first < n) && (nxt.second >= 0 && nxt.second < m)) && (grid[nxt.first][nxt.second] != '#')){
            if (grid[nxt.first][nxt.second] == 'B'){
                if (grid[v.first][v.second] == '.'){
                    grid[v.first][v.second] = '#';
                }
            }
            if (!vis[nxt.first][nxt.second]){
                blockb(nxt, grid, n, m);
            }
        }
    }
}

void canreachb(pi v, vector<vector<char> > & grid, int & n, int & m, bool & pos){
    if (grid[v.first][v.second] == 'B'){
        pos = 1;
    }
    vis[v.first][v.second] = 1;
    vector<pi> poss = {
        {0, -1}, 
        {-1, 0}, 
        {1, 0},
        {0, 1}
    };

    for (auto & ele: poss){
        pi nxt = {v.first + ele.first, v.second + ele.second};
        if (((nxt.first >= 0 && nxt.first < n) && (nxt.second >= 0 && nxt.second < m)) && (grid[nxt.first][nxt.second] != '#')){
            if (!vis[nxt.first][nxt.second]){
                canreachb(nxt, grid, n, m, pos);
            }
        }
    }
}

void canreachallg(pi v, vector<vector<char> > & grid, int & n, int & m, int & gs){
    if (grid[v.first][v.second] == 'G'){
        gs += 1;
    }
    vis[v.first][v.second] = 1;
    vector<pi> poss = {
        {0, -1}, 
        {-1, 0}, 
        {1, 0},
        {0, 1}
    };

    for (auto & ele: poss){
        pi nxt = {v.first + ele.first, v.second + ele.second};
        if (((nxt.first >= 0 && nxt.first < n) && (nxt.second >= 0 && nxt.second < m)) && (grid[nxt.first][nxt.second] != '#')){
            if (!vis[nxt.first][nxt.second]){
                canreachallg(nxt, grid, n, m, gs);
            }
        }
    }
}


void solve(){
    
    int n, m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char>(m));
    int g = 0;
    memset(vis, 0, sizeof(vis));
    // int 
    for (int i=0;i<n;i++){
        string s;
        cin >> s;
        for (int j=0;j<m;j++){
            if (s[j] == 'G'){
                g += 1;
            }
            grid[i][j] = s[j];
        }
    }
    if (g == 0){
        cout << "Yes" << endl;return;
    }
    blockb({n-1, m-1}, grid, n, m);
    bool pos = 0;
    memset(vis, 0, sizeof(vis));
    canreachb({n-1, m-1}, grid, n, m, pos);
    if (pos){
        cout << "No" << endl;return;
    }
    int gs = 0;
    memset(vis, 0, sizeof(vis));
    canreachallg({n-1, m-1}, grid, n, m, gs);
    if (g == gs){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }




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