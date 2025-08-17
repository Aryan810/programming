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
int s[200002];
int v[200002];

int findcnt(int l, int h, vi & a){
    auto it = lower_bound(all(a), l);
    auto it1 = upper_bound(all(a), h);
    return it1-it;
}

bool check(int mid, vi & a, int & k){
    int n = a.size();
    // cout << mid << endl;
    for (int i=0;i<n;i++){
        int f = a[i];
        int se = a[i] + mid - 1;
        // cout << "F: " << f << " S: " << se << endl;
        se = min(se, n);
        int in = findcnt(f, se, a);
        int out = a.size() - in;
        if (in-out >= k){
            return 1;
        }
    }
    return 0;
}

vi b;
void showarr(int diff, vi & a, int & k){
    int f = -1;
    int n = a.size();
    for (int i=0;i<n;i++){
        int fi = a[i];
        int se = a[i] + diff - 1;
        if (!v[se]){continue;}
        int in = findcnt(fi, se, a);
        if (2*in - n >= k){
            f = fi;
            break;
        }
    }
    cout << f << " " << f+diff-1 << endl;
    int l = f;
    int h = f + diff - 1;
    int curr = 0;
    int st = 0;
    vector<pi> out;
    // cout << l << " " << h << endl;
    for (int i=0;i<n;i++){
        if (b[i] >= l && b[i] <= h){
            curr += 1;
        }else{
            curr -= 1;
        }
        if (curr >= 1){
            out.push_back({st, i});
            st = i + 1;
            curr = 0;
        }
    }
    int lst = -1;
    for (int i=0;i<k-1;i++){
        lst = max(lst, out[i].second);
        cout << out[i].first+1 << " " << out[i].second + 1 << endl;
    }
    cout << lst+2 << " " << n << endl;
}



void solve(){
    
    int n, k;
    cin >> n >> k;

    vi a(n);
    b.resize(n);
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        v[x] = 1;
        b[i] = x;
    }
    sort(all(a));
    for (int i=1;i<=n;i++){
        s[i] = s[i-1] + v[i];
    }
    int l = 1;
    int h = n;
    while (h-l > 1){
        int mid = (h + l)/2;
        // cout << "L: " << l << " " << "R: " << h << " " << mid << endl;
        if (check(mid, a, k)){
            h = mid;
        }else{
            l = mid + 1;
        }
    }

    if (check(l, a, k)){
        // find a arrangement now for this.
        showarr(l, a, k);
    }else{
        showarr(h, a, k);
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