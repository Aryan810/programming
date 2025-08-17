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
int findsum(int i, int j){
    cout << "and " << i+1 << " " << j+1 << endl;cout.flush();
    int alpha, beta;
    cin >> alpha;
    cout << "or " << i+1 << " " << j+1 << endl;cout.flush();
    cin >> beta;
    return alpha + beta;
}
void solve(){
    
    int n, k;
    cin >> n >> k;
    vector<int> eles;
    // finding first three elements.
    int s1 = findsum(0, 1);
    int s2 = findsum(0, 2);
    int s3 = findsum(1, 2);

    int diff = s1 - s2;
    int s = (s3 + diff)/2;
    int t = (s3 - diff)/2;
    int f = s1 - s;
    // cout << f << " " << s << " " << t << endl;
    eles.push_back(f);
    eles.push_back(s);
    eles.push_back(t);

    for (int i=3;i<n;i++){
        int sm = findsum(0, i);
        eles.push_back(sm - f);
    }

    sort(all(eles));

    cout << "finish " << eles[k-1] << endl;cout.flush();

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