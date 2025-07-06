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

bool check(int mid, set<pi> b, int & n){
    queue<array<int, 3> > q;
    for (int i=0;i<n;i++){
        if (i >= mid + q.front()[2] + 1){
            b.insert({q.front()[0], q.front()[1]});
            q.pop();
        }
        if (b.size() == 0){
            return 0;
        }
        auto lst = *(--b.end());
        b.erase(--b.end());
        q.push({lst.first - 1, lst.second, i});
        // cout << lst.second << " ";
    }
    while (q.size() > 0){
        b.insert({q.front()[0], q.front()[1]});
        q.pop();
    }
    auto lst = *(--b.end());
    if (lst.first > 0){
        return 0;
    }
    // cout << endl;
    return 1;
}

void solve(){
    
    int n;cin >> n;
    vi a(n);
    vi cnt(n+1, 0);
    rep(i, n){
        int x;
        cin >> x;
        cnt[x] += 1;
        a[i] = x;
    }
    set<pair<int, int> > b;
    int j = 0;
    sort(all(a));
    while (j < n){
        b.insert({cnt[a[j]], a[j]});
        j += cnt[a[j]];
    }
    int l = 0;
    int h = n-2;

    while (h - l > 1){
        int mid = (h+l)/2;
        // cout << l << " " << mid << " " << h << endl;

        if (check(mid, b, n)){
            l = mid;
        }else{
            h = mid - 1;
        }

    }
    if (check(h, b, n)){
        cout << h << endl;
    }else{
        cout << l << endl;
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