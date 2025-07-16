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

void solve(){

    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, n) cin >> a[i];
    string s;
    cin >> s;

    set<int> rod;

    set<int> s1, s2;
    for (int i=0;i<n;i++){
        s1.insert(a[i]);
        s2.insert(i+1);

        while ((s1.size() > 0 && s2.size() > 0) && (*s1.begin() == *s2.begin())){
            s1.erase(s1.begin());
            s2.erase(s2.begin());
        }

        if (s1.size() == 0 && s2.size() == 0){
            rod.insert(i);
        }
    }
    set<int> wrg;
    for (int i=0;i<n-1;i++){
        if (s[i]=='L' && s[i+1]=='R'){
            if (rod.find(i) == rod.end()){
                wrg.insert(i);
            }
        }
    }
    for (int i=0;i<q;i++){
        int x;
        cin >> x;

        if (s[x-1] == 'L'){
            if (x != 1 && s[x-2] == 'L'){
                if (rod.find(x-2) == rod.end()){
                    wrg.insert(x-2);
                }
            }
            if (x != n && s[x] == 'R'){
                if (wrg.find(x-1) != wrg.end()){
                    wrg.erase(x-1);
                }
            }
            s[x-1] = 'R';
        }else{
            if (x != n && s[x] == 'R'){
                if (rod.find(x-1) == rod.end()){
                    wrg.insert(x-1);
                }
            }
            if (x != 1 && s[x-2] == 'L'){
                if (wrg.find(x-2) != wrg.end()){
                    wrg.erase(x-2);
                }
            }
            s[x-1] = 'L';
        }

        if (wrg.size() > 0){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }



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