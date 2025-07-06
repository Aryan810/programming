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

struct dsu{
    int n;
    vector<int> parent, set_size, set_max;
    dsu(int n){
        this->n = n;
        parent.resize(n);
        set_size.resize(n);
        set_max.resize(n);
        for (int i = 0; i < n; i++){
            parent[i] = i;
            set_size[i] = 1;
        }
    }
    int find(int v){
        if(v == parent[v]) return v;
        return parent [v] = find (parent [v]);
    }
    void set_union (int a, int b){
        a = find(a);
        b = find (b);
        int mxheight = max(set_max[a], set_max[b]);
        if(a != b){
            if(set_size[a] < set_size [b]){
                swap (a, b) ;
            }
            parent[b] = a;
            set_size[a] += set_size[b];
            set_max[a] = mxheight;
        }
    }
};

void solve(){
    
    int n;
    cin >> n;
    
    vi a(n);
    struct dsu ds(n);
    rep(i, n){
        cin >> a[i];
        ds.set_max[i] = a[i];
    }

    set<pi> st;
    st.insert({a[0], 0});
    for (int i=1;i<n;i++){
        int mx = 0;
        while (st.size() > 0 && (--st.end())->first > a[i]){
            auto lst = --st.end();
            ds.set_union(lst->second, i);
            mx = max(lst->first, mx);
            st.erase(lst);
        }
        st.insert({max(mx, a[i]), i});
    }

    for (int i=0;i<n;i++){
        cout << ds.set_max[ds.find(i)] << " ";
    }cout << endl;
   


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