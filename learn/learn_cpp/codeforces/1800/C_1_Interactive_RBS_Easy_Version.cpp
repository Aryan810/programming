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
int qry(int l, int r){
    cout << "? ";
    cout << r-l+1 << " ";
    for (int i=l+1;i<=(r+1);i++){
        cout << i << " ";
    }cout << endl;cout.flush();
    int res;
    cin >> res;
    return res;
}

int qry(vi & a){
    cout << "? ";
    cout << a.size() << " ";
    for (auto & ele: a){
        cout << ele+1 << " ";
    }cout << endl;cout.flush();
    int res;
    cin >> res;
    return res;
}

int qry(int r1, int r2, int f, int s){
    cout << "? ";
    cout << 6 << " ";
    cout << r1 << " " << s << " " << f << " " << r2 << " " << s << " " << s;
    cout << endl;cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve(){
    
    int n;
    cin >> n;
    int f = -1;
    int s = -1;
    if (qry(0, n-1) == 0){
        f = n-1;
        s = 0;
    }else{
        // using binary search.
        int l = 0;
        int h = n-1;
        while (h-l > 1){
            int mid = (h+l)/2;
            if (qry(mid, n-1) > 0){
                l = mid;
            }else{
                h = mid;
            }
        }

        f = l;
        s = h;
    }

    string out(n, '.');

    for (int i=0;i<(n-1);i+=2){
        int res = qry(i+1, i+2, f+1, s+1);
        if (res == 1){
            out[i] = ')';
            out[i+1] = ')';
        }else if (res == 4){
            out[i] = '(';
            out[i+1] = '(';
        }else if (res == 3){
            out[i] = '(';
            out[i+1] = ')';
        }else{
            out[i] = ')';
            out[i+1] = '(';
        }
    }

    if (out[n-1]=='.'){
        int i = n-1;
        int res = qry(i+1, i+1, f+1, s+1);
        if (res == 4){
            out[i] = '(';
        }else{
            out[i] = ')';
        }
    }

    cout << "! " << out << endl;cout.flush();
    

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