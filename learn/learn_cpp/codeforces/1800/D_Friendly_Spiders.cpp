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
vi primes;
const int N = 3*(1e5) + 1;
int isprime[N];
int n;
vi a;
int p, q;
vector<set<int> > pf;
map<int, set<int> > eles;
void calc(){
    for (int i=0;i<n;i++){
        int curr = a[i];
        int j = 0;
        while (j < primes.size() && primes[j]*primes[j] <= curr){
            if (curr%primes[j] == 0){
                pf[i].insert(primes[j]);
                eles[primes[j]].insert(i);
                while (curr%primes[j] == 0){
                    curr /= primes[j];
                }
            }
            j += 1;
        }
        if (curr != 1){
            pf[i].insert(curr);
            eles[curr].insert(i);
        }
    }

}

const int INF = 1e15;
void bfs(int v){
    queue<int> qu;
    qu.push(p);
    vi lev(n+1, INF);
    map<int, vector<int> > levele;
    levele[0].push_back(p);
    lev[p] = 0;
    levele[0].push_back(p);
    while (qu.size() > 0){
        int curr = qu.front();
        qu.pop();
        set<int> dels;
        for (auto & ele: pf[curr]){
            for (auto & e: eles[ele]){
                if (lev[e] == INF){dels.insert(e);}
            }
        }
        for (auto & ele: dels){
            lev[ele] = lev[curr] + 1;
            levele[lev[ele]].push_back(ele);
            qu.push(ele);
            for (auto & e: pf[ele]){
                if (eles[e].find(ele) != eles[e].end()){eles[e].erase(ele);}
            }
        }
    }
    // cout << lev[4] << endl;
    if (lev[q] == INF){
        cout << -1 << endl;return;
    }
    stack<int> out;
    int curr = q;
    cout << lev[curr]+1 << endl;
    while (curr != p){
        out.push(curr+1);
        int l = lev[curr];
        for (auto & ele: levele[l-1]){
            if (gcd(a[ele], a[curr]) > 1){
                curr = ele;
                break;
            }
        }
    }
    out.push(p+1);
    while (out.size() > 0){
        cout << out.top() << " ";out.pop();
    }cout << endl;


}

void solve(){
    

    cin >> n;
    a.resize(n);
    pf.resize(n);
    rep(i, n) cin >> a[i];

    cin >> p >> q;
    p -= 1;
    q -= 1;

    calc();
    bfs(p);

}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    memset(isprime, 1, sizeof(isprime));
    isprime[0] = 0;
    isprime[1] = 0;
    for (int j=2;j<N;j++){
        if (isprime[j]){
            primes.push_back(j);
            for (int i=j*j;i<N;i+=j){
                isprime[i] = 0;
            }
        }
    }

    // cout << primes.size() << endl;

    int test = 1;

    while(test--){
        solve();
    }

    return 0;
}