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
int cnt = 0;
void solve(){
    
    string s;
    cin >> s;
    int n = s.size();
    // if (cnt == 452){
    //     cout << s << endl;return;
    // }
    if (s[0]=='?'){s[0]='(';}
    if (s.back()=='?'){s.back() = ')';}

    // cout << s << endl;

    stack<int> left;
    bool poss = 1;
    vector<pi> rst(n);
    int l=0, h=0;
    
    for (int i=n-1;i>=0;i--){
        if (s[i]==')'){
            l += 1;
            h += 1;
        }else if (s[i] == '('){
            l -= 1;
            h -= 1;
        }else{
            h += 1;
            l -= 1;
        }
        l = max(l, 0ll);
        rst[i] = {l, h};
        // cout << l << " " << h << endl;
    }
    for (int i=0;i<n-1;i++){
        if (s[i]=='('){
            left.push(i);
            continue;
        }else if (s[i]==')'){
            if (left.size() > 0){left.pop();}else{
                cout << "NOO" << endl;return;
            }
            continue;
        }
        auto r = rst[i+1];
        int poss = 0;
        // if i put ( on this ?.
        int x = left.size();
        int sz = x + 1;
        if (sz >= r.first && sz <= r.second){
            left.push(i);
            poss += 1;
        }
        // if i put ) on this ?.
        sz = x - 1;
        if (sz >= 0 && (sz >= r.first && sz <= r.second)){
            left.pop();
            poss += 1;
        }
        // cout << poss << endl;
        if (poss != 1){
            cout << "NO" << endl;return;
        }
    }

    cout << "YES" << endl;

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;
    cin >> test;

    while(test--){
        // cnt += 1;
        solve();
    }

    return 0;
}