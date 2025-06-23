// #include<atcoder/modint>
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;
// using namespace atcoder;
// using mint = modint;
#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator
#define umap(x, y) unordered_map<x, y, custom_hash>
const int M = 1e9 + 7;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
const int N = 1e5+1;
int fac[N];

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

int calc(int & k, int & b, int & n, int & a){
    int f = 1;
    for (int i=(n-a+1);i<=n;i++){
        f = (f * i%M)%M;
    }
    int inv = binexpiter(fac[a], M-2)%M;
    f = (f * inv)%M;
   
    f *= (k * (b-1))%M;
    f %= M;

    return f + 1;
}

void solve(){
    
    int a, b, k;
    cin >> a >> b >> k;
    int n = (a*k - k + 1)%M;
    int m = (calc(k, b, n, a))%M;
    cout << n << " " << m << endl;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // mint::set_mod(M);
    fac[0] = 1;
    fac[1] = 1;
    for (int i=2;i<N;i++){
        fac[i] = (fac[i-1] * i)%M;
    }
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}