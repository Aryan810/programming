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
    
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    set<int> ab, ba;

    for (int i=0;i<n;i++){
        if (a[i]==b[i]){continue;}
        if (a[i]=='a'){
            ab.insert(i);
        }else{
            ba.insert(i);
        }
    }
    vector<pi> out;
    while (ab.size() > 1){
        int f = *ab.begin();
        ab.erase(ab.begin());
        int s = *ab.begin();
        ab.erase(ab.begin());
        out.push_back({f+1, s+1});
    }

    while (ba.size() > 1){
        int f = *ba.begin();
        ba.erase(ba.begin());
        int s = *ba.begin();
        ba.erase(ba.begin());
        out.push_back({f+1, s+1});
    }

    if ((ab.size() + ba.size())&1){
        cout << -1 << endl;return;
    }

    if (ab.size() == 1 && ba.size() == 1){
        int f = *ab.begin();
        int s = *ba.begin();
        out.push_back({f+1, f+1});
        out.push_back({f+1, s+1});
    }

    cout << out.size() << endl;
    for (auto & ele: out){
        cout << ele.first << " " << ele.second << endl;
    }

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