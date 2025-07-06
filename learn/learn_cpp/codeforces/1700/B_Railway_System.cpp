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
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > tracks;
    
    for (int i=1;i<=m;i++){
        string s(m, '0');
        s[i-1] = '1';
        cout << "? " << s << endl;cout.flush();
        int res;
        cin >> res;
        tracks.push_back({res, i-1});
    }

    sort(all(tracks));
    int sm = 0;
    string s(m, '0');
    for (int i=0;i<m;i++){
        auto curr = tracks[i];
        s[curr.second] = '1';
        cout << "? " << s << endl;cout.flush();
        int res;
        cin >> res;
        if (res == sm + curr.first){
            sm += curr.first;
        }else{
            s[curr.second] = '0';
        }
    }

    cout << "! " << sm << endl;cout.flush();

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