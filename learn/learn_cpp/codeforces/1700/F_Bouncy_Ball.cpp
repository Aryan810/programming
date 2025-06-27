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

void solve(){
    int n, m, i1, j1, i2, j2;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    int vis[n+1][m+1][3][3];
    memset(vis, 0, sizeof(vis));
    string d;
    cin >> d;
    if (((i1+j1)+(i2+j2))&1){
        cout << -1 << endl;return;
    }
    pair<int, int> dir;
    if (d[0] == 'U'){
        dir.first = -1;
    }else{
        dir.first = 1;
    }

    if (d[1] == 'R'){
        dir.second = 1;
    }else{
        dir.second = -1;
    }
    pair<int, int> curr = {i1, j1};
    int ans = 0;
    while (1){
        // cout << curr.first << " " << curr.second << endl;
        if (curr.first == i2 && curr.second == j2){
            cout << ans << endl;return;
        }
        if (vis[curr.first][curr.second][dir.first + 1][dir.second + 1]){
            // cout << "here" << endl;
            break;
        }else{
            vis[curr.first][curr.second][dir.first + 1][dir.second + 1] = 1;
        }
        // cout << dir.first << " " << curr.first << endl;
        int inc = 0;
        if (dir.first == -1 && curr.first == 1){
            dir.first *= -1;
            inc = 1;
        }
        if (dir.first == 1 && curr.first == n){
            dir.first *= -1;
            inc = 1;
        }
        if (dir.second == 1 && curr.second == m){
            dir.second *= -1;
            inc = 1;
        }
        if (dir.second == -1 && curr.second == 1){
            dir.second *= -1;
            inc = 1;
        }
        ans += inc;
        curr.first += dir.first;
        curr.second += dir.second;
    }
    cout << -1 << endl;return;
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