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
    
    int n, k;
    cin >> n >> k;
    vector<vector<int> > pos(k);
    string s;
    cin >> s;
    vector<int> fullind;
    for (int i=0;i<s.size();i++){
        pos[s[i]-'a'].push_back(i);
    }
    vector<int> temp(k, 0);
    for (int i=n-1;i>=0;i--){
        temp[s[i]-'a'] += 1;
        bool nothis = 0;
        for (auto & ele: temp){
            if (ele == 0){
                nothis = 1;
                break;
            }
        }
        if (nothis){
            continue;
        }
        temp.assign(k, 0);
        fullind.push_back(i);
    }
    reverse(all(fullind));
    int q;
    cin >> q;
    rep(i, q){
        // cout << i << endl;
        string t;
        cin >> t;
        int last = -1;
        bool inval = 0;
        for (int j=0;j<t.size();j++){
            auto & v = pos[t[j]-'a'];
            auto it = upper_bound(all(v), last);
            if (it == v.end()){
                cout << 0 << endl;
                inval = 1;
                break;
            }
            last = *it;
        }
        if (inval){
            continue;
        }
        auto it = upper_bound(all(fullind), last);
        cout << (fullind.size() - (int)(it-fullind.begin())) + 1 << endl;
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