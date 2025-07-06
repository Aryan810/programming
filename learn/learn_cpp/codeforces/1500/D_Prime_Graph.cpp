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
vector<int> isprime(2000, 1);
vector<int> primes;
void solve(){
    
    int n;
    cin >> n;
    if (n == 3){
        cout << 3 << endl;
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << "3 1" << endl;
        return;
    }
    // find just larger prime.
    int p = *lower_bound(all(primes), n);

    int left = p - n;

    vvi graph(n+1);
    vector<pi> out;
    for (int i=0;i<n;i++){
        int nxt = (i+1)%(n) + 1;
        out.push_back({i+1, nxt});
    }
    
    int curr = 1;
    for (int i=0;i<left;i++){
        if (curr == n/2){
            out.push_back({curr++, n});break;
        }else{
            out.push_back({curr, n-curr});
            curr += 1;
        }
    }

    cout << out.size() << endl;
    for (auto & ele: out){
        cout << ele.first << " " << ele.second << endl;
    }




}

signed main(){
    fast_io;   
    // mint::set_mod(M);

    isprime[0] = 0;
    isprime[1] = 0;
    for (int i=2;i<2000;i++){
        if (isprime[i]){
            primes.push_back(i);
            for (int j=i*i;j<2000;j+=i){
                isprime[j] = 0;
            }
        }
    }

    // for (int i=0;i<primes.size()-1;i++){
    //     if (primes[i] > 1000){break;}
    //     cout << primes[i]/2 << " " << primes[i+1]-primes[i] << endl;
    // }
    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}