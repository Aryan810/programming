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
const int N = 1e5;
vector<int> isprime(N, 1);
vector<int> primes;
int findfac(int gc){
    int ret = 0;
    for (int i=0;i<primes.size();i++){
        while (gc%primes[i] == 0){
            gc /= primes[i];
            ret += 1;
        }
    }
    if (gc > 1){
        ret += 1;
    }
    return ret;
}
int nm = 0;
void solve(){
    
    int a, b, k;
    cin >> a >> b >> k;
    // if (nm == 3033){
    //     cout << a << "." << b << "." << k << endl;return;
    // }
    int s1, s2;
    int gc = gcd(a, b);
    s1 = findfac(a);
    s2 = findfac(b);

    int mxk = s1 + s2;
    // cout << mxk << endl;
    if (a == 1 && b == 1){
        cout << "NO" << endl;return;
    }else if (a == 1 || b == 1){
        if (k >= 1 && k <= mxk){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        if (k == 2){
            cout << "YES" << endl;
        }else if (k == 1){
            if ((a == gc || b == gc) && !(a == gc && b == gc)){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            if (k <= mxk){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }
    }
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
    // for (int i=0;i<50;i++){
    //     cout << primes[i] << " ";
    // }cout << endl;
    int test;
    cin >> test;
    while(test--){
        nm += 1;
        solve();
    }

    return 0;
}