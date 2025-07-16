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

bool check(vector<pi> f, int & n, int & m, vvi & a, vvi & vis){
    int i = 0;
    int j = 0;
    vector<pi> surr = {
        {i+1, j}, {i-1, j}, {i, j+1}, {i, j-1}, {i+1, j+1}, {i+1, j-1}, {i-1, j+1}, {i-1, j-1}
    };
    for (auto & ele: f){
        for (auto & e: surr){
            pi pt = {ele.first + e.first, ele.second + e.second};
            if ((pt.first >= 0 && pt.first < n) && (pt.second >= 0 && pt.second < m)){
                if (find(all(f), pt) != f.end()){
                    continue;
                }
                if (a[pt.first][pt.second]){
                    return 0;
                }
            }
        }
        vis[ele.first][ele.second] = 1;
    }

    return 1;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vvi a(n, vector<int>(m, 0));
    vvi vis(n, vector<int>(m, 0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            char c;
            cin >> c;
            if (c == '*'){
                a[i][j] = 1;
            }
        }
    }

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (!a[i][j] || vis[i][j]){
                continue;
            }
            if (i == n-1){
                cout << "NO" << endl;return;
            }
            
            if (m > 1 && j == m-1){
                if (a[i][j] && (a[i+1][j] && a[i+1][j-1])){
                    if (!check({{i, j}, {i+1, j}, {i+1, j-1}}, n, m, a, vis)){
                        cout << "NO" << endl;return;
                    }
                }else{
                    cout << "NO" << endl;return;
                }
                continue;
            }

            if (j > 0 && (a[i][j] && (a[i+1][j] && a[i+1][j-1]))){
                if (!check({{i, j}, {i+1, j}, {i+1, j-1}}, n, m, a, vis)){
                    cout << "NO" << endl;return;
                }
            }else if (a[i][j] && (a[i+1][j] && a[i+1][j+1])){

                if (!check({{i, j}, {i+1, j}, {i+1, j+1}}, n, m, a, vis)){
                    cout << "NO" << endl;return;
                }  
            }else if (a[i][j] && (a[i][j+1] && a[i+1][j+1])){

                if (!check({{i, j}, {i, j+1}, {i+1, j+1}}, n, m, a, vis)){
                    cout << "NO" << endl;return;
                }
            }else if (a[i][j] && (a[i][j+1] && a[i+1][j])){

                if (!check({{i, j}, {i, j+1}, {i+1, j}}, n, m, a, vis)){
                    cout << "NO" << endl;return;
                }
            }else{
                cout << "NO" << endl;return;
            }
        }
    }

    cout << "YES" << endl;return;
    

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