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
const int N = 1e6 + 1;
vi isprime(N, 1);
vi primes;
void solve(){
    
    int n;
    cin >> n;

    int i = 1;
    int curr = n;
    int ans = 1;
    int tmp = 0;
    while (curr%2 == 0){
        curr /= 2;
        tmp += 1;
    }
    ans *= (tmp + 1);
    while (primes[i]*primes[i] <= curr){
        int cnt = 0;
        while (curr%primes[i] == 0){
            curr /= primes[i];
            cnt += 1;
        }
        i += 1;
        ans *= (cnt+1);
    }

    if (curr > 1){
        ans *= 2;
    }

    cout << ans << endl;
}

signed main(){
    fast_io;   
    // mint::set_mod(M);

    isprime[0] = 0;
    isprime[1] = 0;
    for (int i=2;i<N;i++){
        if (isprime[i]){
            primes.push_back(i);
            for (int j=i*i;j<N;j+=i){
                isprime[j] = 0;
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