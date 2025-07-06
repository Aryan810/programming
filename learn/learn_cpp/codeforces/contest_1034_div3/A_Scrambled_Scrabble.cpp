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

int calc(int c, int v, int n, int g){
    int ans = 0;
    for (int ng=0;ng<=(min(min(n, g), 2*v));ng++){
        int tc = c - ng;
        int temp = ng;
        temp += 3 * min(v, (tc/2));
        ans = max(temp, ans);
    }
    return ans;
}

void solve(){
    set<int> vow = {
        'A', 'E', 'I', 'O', 'U'
    };

    string s;
    cin >> s;
    int c = 0;
    int v = 0;
    int n = 0;
    int g = 0;
    int y = 0;
    for (int i=0;i<s.size();i++){
        if (s[i] == 'Y'){
            y += 1;
        }else if (vow.find(s[i]) != vow.end()){
            v += 1;
        }else{
            c += 1;
        }
        if (s[i] == 'N'){
            n += 1;
        }else if (s[i] == 'G'){
            g += 1;
        }
    }
    int ans = 0;
    for (int i=0;i<=y;i++){
        ans = max(ans, calc(c+i, v+y-i, n, g));
    }
    cout << ans << endl;

    


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