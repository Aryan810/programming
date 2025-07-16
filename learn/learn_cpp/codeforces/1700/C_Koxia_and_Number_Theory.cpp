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
const int N = 100;
vi isPrime(N+1, 1);
vi primes;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    set<int> st;
    vector<vector<int> > dta(primes.size() + 1);
    for (int i=0;i<primes.size();i++){
        dta[i].assign(primes[i]+1, 0);
    }
    rep(i, n){
        int x;
        cin >> x;
        st.insert(x);
        a[i] = x;
        for (int j=0;j<primes.size();j++){
            dta[j][(x%primes[j])] += 1;
        }
    }
    if (st.size() != n){
        cout << "NO" << endl;return;
    }
    int num = 0;
    for (int j=0;j<primes.size();j++){
        bool found = 0;
        for (int i=0;i<primes[j];i++){
            if (dta[j][i] <= 1){
                found = 1;
            }
        }
        if (!found){
            cout << "NO" << endl;return;
        }
    }
    cout << "YES" << endl;





}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    isPrime[0] = 0;
    isPrime[1] = 0;
    // int sm = 0;
    for (int i=2;i<N;i++){
        if (isPrime[i]){
            primes.push_back(i);
            // sm += i;
            for (int j=i*i;j<N;j+=i){
                isPrime[j] = 0;
            }
        }
    }
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}