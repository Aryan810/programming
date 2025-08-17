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
    
    int n, x;
    cin >> n >> x;

    string st;
    cin >> st;
    set<int> indw;
    set<int> indn;

    for (int i=0;i<n;i++){
        if (st[i]=='#'){
            indw.insert(i);
        }else{
            indn.insert(i);
        }
    }
    int pos = x-1;
    int days = 0;
    while (1){
        days += 1;
        if (pos == 0 || pos == n-1){
            break;
        }else if (st[pos-1]=='#' || st[pos+1] == '#'){
            days += min(pos+1, n-pos) - 1;
            break;
        }
        auto it = indn.lower_bound(pos);
        int f = -1;
        int s = -1;
        auto tmp = it;
        f = *(--tmp);
        s = *(++it);
        auto it1 = indw.upper_bound(pos);
        int p = -1;
        int q = -1;
        if (it1 == indw.end()){
            q = n;
        }else{
            q = *it1;
        }

        if (it1 == indw.begin()){
            p = -1;
        }else{
            p = *(--it1);
        }
        int a = min(pos+1, n-q);
        // cout << pos+1 << " " << n-q << endl;
        // cout << q << endl;
        int b = min(p+1, n-pos-1);
        // cout << a << " " << b << endl;
        if (a > b){
            st[f] = '#';
            indw.insert(f);
            indn.erase(f);
        }else{
            st[s] = '#';
            indw.insert(s);
            indn.erase(s);
        }

        // hamid
        it = indw.upper_bound(pos);
        f = -1;
        s = -1;
        if (it == indw.end()){
            break;
        }else{
            s = *it;
        }

        if (it == indw.begin()){
            break;
        }else{
            f = *(--it);
        }

        a = f + 1;
        b = n - s;
        if (a < b){
            st[f] = '.';
            indn.insert(f);
            indw.erase(f);
            pos = f;
        }else{
            st[s] = '.';
            indn.insert(s);
            indw.erase(s);
            pos = s;
        }
        cout << "HAMID: " << st << " " << days << " " << pos << endl;

    }

    cout << days << endl;

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