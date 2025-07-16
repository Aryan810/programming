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
int tc = 0;
int tinp(int & sz, vi & cnt, vi & a){
    vi tcnt(10, 0);
    for (int i=0;i<sz;i++){
        int x;
        cin >> x;
        tcnt[x] += 1;
        a[i] = x;
    }
    int from = -1;
    int to = -1;
    for (int i=1;i<10;i++){
        if (tcnt[i] > cnt[i]){
            to = i;
            break;
        }
    }
    cnt = tcnt;
    return to;
}


void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vector<int> cnt(10, 0);

    for (int i=0;i<n;i++){
        cnt[a[i]] += 1;
    }
    // first
    int sz = n;
    int ans = 1;
    vi torem;
    vi v = a;
    for (int i=0;i<5;i++){
        if (sz - torem.size() == 1){
            cout << "! " << ans << endl;cout.flush();break;
        }
        cout << "- " << torem.size() << " ";
        for (int j=0;j<torem.size();j++){
            cout << torem[j] << " ";
            cnt[v[torem[j]-1]] -= 1;
        }cout << endl;cout.flush();

        sz -= torem.size();
        torem.clear();
        vi tcnt(10, 0);
        v.assign(sz, 0);
        for (int j=0;j<sz;j++){
            int x;
            cin >> x;
            tcnt[x] += 1;
            v[j] = x;
        }
        int to = -1;
        for (int j=1;j<=9;j++){
            if (tcnt[j] > cnt[j]){
                to = j;
            }
        }

        if (to != -1){
            for (int j=0;j<sz;j++){
                if (v[j] != to){
                    torem.push_back(j+1);
                }else{
                    ans = j+1;
                }
            }
        }
        cnt = tcnt;
    }

    
}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test;

    cin >> test;

    while(test--){
        tc += 1;
        solve();
    }

    return 0;
}