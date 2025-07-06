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
const int N = 200002;
vi isprime(N, 1);
vi primes;
int bsqrt(int n){
    if (n == 0){
        return 0;
    }else if (n == 1){
        return 1;
    }
    int l = 2;
    int h = n;
    while (h-l>1){
        int mid = (h + l)/2;
        if (mid*mid == n){
            return mid;
        }else if (mid*mid < n){
            l = mid;
        }else{
            h = mid - 1;
        }
    }
    if (h*h <= n){
        return h;
    }else{
        return l;
    }
}



void solve(){
    
    int n;
    cin >> n;
    vi a(n);
    vi cnt(n+1, 0);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        cnt[x] += 1;
    }
    map<int, int> sq;
    map<pi, int> pq;
    int csq = 0;
    int cpq = 0;
    int ans = 0;
    set<int> done;
    vector<int> primecnt;
    for (int i=0;i<n;i++){
        if (a[i]==1){continue;}
        int rt = bsqrt(a[i]);
        if (rt*rt == a[i] && isprime[rt]){
            ans += cnt[rt];
            csq += 1;
            sq[rt] += 1;continue;
        }
        if (isprime[a[i]]){
            if (done.find(a[i]) == done.end()){
                primecnt.push_back(cnt[a[i]]);
                done.insert(a[i]);
            }
            continue;
        }
        // calc
        int p = -1;
        int q = -1;
        for (int j=0;j<primes.size();j++){
            if (primes[j] > rt){break;}
            if (a[i]%primes[j] == 0){
                p = primes[j];
                q = a[i]/(primes[j]);
                break;
            }
        }
        if (!isprime[q] || p == q){
            continue;
        }
        pq[{min(p, q), max(p, q)}] += 1;
        // pq, q
        ans += cnt[q] + cnt[p];
        cpq += 1;
    }
    ans += (cnt[1] * csq) + (cnt[1] * cpq);
    
    for (auto & ele: pq){
        ans += ((ele.second)*(ele.second + 1))/2;
    }
    for (auto & ele: sq){
        ans += ((ele.second)*(ele.second + 1))/2;
    }
    int sm = accumulate(all(primecnt), 0ll);
    for (int i=0;i<primecnt.size();i++){
        sm -= primecnt[i];
        ans += primecnt[i] * (sm);
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