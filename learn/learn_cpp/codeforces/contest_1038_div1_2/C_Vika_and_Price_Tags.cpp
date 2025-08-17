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
int findoper(int a, int b){
    int oper = 0;
    while (a != 0 && b != 0){
        // 1 2
        // 
        // cout << a << " " << b << endl;
        if (a > b){
            int val = a/b;
            if (val&1){
                oper += 1 + (val/2)*3;
                int tmp = a;
                a = b;
                b = tmp%b;
            }else{
                oper += (val/2)*3;
                a = a%b;
            }
        }else{
            int val = b/a;
            if (val&1){
                oper += 1 + (val/2)*3;
                int tmp = a;
                a = b%a + a;
                b = b%tmp;
            }else{
                oper += (val/2)*3;
                b = b%a;
            }
        }
    }

    if (a != 0){oper += 1;}

    return oper;
}

void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n);
    rep(i, n) cin >> b[i];

    bool poss = 1;
    set<int> st;
    for (int i=0;i<n;i++){
        int x = findoper(a[i], b[i]);
        if (a[i]==0 && b[i]==0){continue;}
        // cout << x%3 << endl;
        st.insert(x%3);
    }

    cout << (st.size()<=1?"YES":"NO") << endl;return;

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


