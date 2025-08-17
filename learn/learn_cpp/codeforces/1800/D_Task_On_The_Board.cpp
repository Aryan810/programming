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

void solve(){
    
    string s;
    cin >> s;
    int n = s.size();

    array<int, 26> cnt;

    for (int i=0;i<26;i++) cnt[i]=0;
    for (int i=0;i<n;i++) cnt[s[i]-'a']++;

    int m;
    cin >> m;
    vi b(m);
    rep(i, m) cin >> b[i];
    vvi need;
    while (1){
        vi mxind;
        for (int i=0;i<m;i++){
            if (b[i]==0){
                mxind.push_back(i);
                b[i] -= 1;
            }else if (b[i] < 0){
                b[i] -= 1;
            }
        }
        if (mxind.size() == 0){break;}
        need.push_back(mxind);
        for (int i=0;i<m;i++){
            if (b[i] > 0){
                for (int j=0;j<mxind.size();j++){
                    b[i] -= abs(i-mxind[j]);
                }
            }
        }
    }
    reverse(all(need));

    string out(m, '.');
    for (int i=25;i>=0;i--){
        if (need.size() == 0) break;
        if (cnt[i] >= need.back().size()){
            for (int j=0;j<need.back().size();j++){
                out[need.back()[j]] = char(i+'a');
            }
            if (need.size() > 0) need.pop_back();
        }
    }
    cout << out << endl;



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