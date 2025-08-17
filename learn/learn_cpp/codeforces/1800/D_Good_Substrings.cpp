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
const int M = 1e9 + 7;
const int M1 = 998244353;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}


void solve(){
    
    string s;
    cin >> s;
    int n = s.size();
    string good;
    cin >> good;
    int k;cin >> k;
    vi cum(s.size()+1, 0);
    vi cumhash(n+1, 0);
    int pow = 1;
    int inv = binexpiter(31, M-2)%M;
    vi invs(n+1, 1);
    for (int i=0;i<n;i++){
        cumhash[i+1] = (cumhash[i] + ((s[i]-'a'+1)*pow)%M)%M;
        pow *= 31;
        pow %= M;
        invs[i+1] = invs[i] * inv;
        invs[i+1] %= M;
    }

    for (int i=0;i<s.size();i++){
        cum[i+1] = cum[i] + (good[s[i]-'a']=='0');
    }

    set<int> goods;
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            int bad = cum[j+1]-cum[i];
            if (bad <= k){
                int f = (cumhash[j+1]-cumhash[i]+M)%M;
                int t = f*invs[i];
                t %= M;
                goods.insert(t);
            }
        }
    }

    cout << goods.size() << endl;

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