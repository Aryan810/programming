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

int qry(int a, int b){
    cout << "? " << a << " " << b << endl;cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve(){
    
    int n;
    cin >> n;

    vi rem(1ll<<n);
    for (int i=1;i<=(1ll<<n);i++){
        rem[i-1] = i;
    }

    while (rem.size() > 2){
        vi tmp;
        for (int j=0;j<rem.size();j+=4){
            int a, b, c, d;
            a = rem[j];
            b = rem[j+1];
            c = rem[j+2];
            d = rem[j+3];
            int r1 = qry(b, c);
            if (r1 == 0){
                int r2 = qry(a, d);
                if (r2==1){ // a > d
                    tmp.push_back(a);
                }else{
                    tmp.push_back(d);
                }
            }else if (r1 == 1){
                int r2 = qry(b, d);
                if (r2==1){
                    tmp.push_back(b);
                }else{
                    tmp.push_back(d);
                }
            }else{
                int r2 = qry(a, c);
                if (r2==1){
                    tmp.push_back(a);
                }else{
                    tmp.push_back(c);
                }
            }
        }
        rem = tmp;
    }
    
    if (rem.size()<2){
        cout << "! " << rem[0] << endl;
    }else{
        int res = qry(rem[0], rem[1]);
        if (res==1){
            cout << "! " << rem[0] << endl;
        }else{
            cout << "! " << rem[1] << endl;
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