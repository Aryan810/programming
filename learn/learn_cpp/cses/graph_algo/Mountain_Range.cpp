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

class segtree{
    public:
        int n;
        vi arr;
        vi leafs;
        vi val;
        int (*comp)(int a, int b) = [](int a, int b){return a+b;};
        int DEF = 0;
        int make(int v, int l, int r){
            if (l < r){
                val[v] = comp(make(2*v+1, l, (l+r)/2), make(2*v + 2, (l+r)/2 + 1, r));
                return val[v];
            }else if (l < n && l == r){
                leafs[l] = v;
                val[v] = arr[l];
                return val[v];
            }else{
                return DEF;
            }
        }
        void update(int i, int newval){
            int j = leafs[i];
            val[j] = newval;
            while (j != 0){
                int k;
                int par;
                if (j&1){
                    k = j + 1;
                    par = j/2;
                }else{
                    k = j - 1;
                    par = j/2 - 1;
                }
                val[par] = comp(val[j], val[k]);
                j = par;
            }
        }
    
        int finder(int j, int l, int r, int ql, int qr){
            if (l >= ql && r <= qr){
                return val[j];
            }else if (l > qr || r < ql){
                return DEF;
            }else{
                return comp(finder(2*j+1, l, (l+r)/2, ql, qr), finder(2*j+2, (l+r)/2+1, r, ql, qr));
            }
        }
    
        int find(int l, int r){
            return finder(0, 0, arr.size()-1, l, r);
        }

        segtree(int n, vi arr, int default_val=0, int (*comp)(int a, int b)=NULL){
            int sz = 0;
            int x = 1;
            if (comp){this->comp = comp;}
            while (1){
                sz += x;
                if (x >= n){break;}
                x *= 2;
            }
            this->n = n;
            this->DEF = default_val;
            this->arr = arr;
            this->leafs.resize(sz);
            this->val.assign(sz, this->DEF);
            make(0, 0, arr.size()-1);
        }
};


const int INF = 1e15;
void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    vector<pi> b(n);

    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        b[i] = {x, i};
    }

    sort(all(b));
    vi dp(n, 0);
    segtree sg(n, dp, 0, [](int a, int b){return max(a, b);});
    vi rightlarge(n+1, n);
    vi leftlarge(n+1, -1);
    stack<pi> st;
    st.push({INF,n});

    for (int i=n-1;i>=0;i--){
        while (st.size() > 0 && st.top().first < a[i]){
            st.pop();
        }
        rightlarge[i] = st.top().second;
        st.push({a[i], i});
    }

    while (st.size() > 0) st.pop();

    st.push({INF, -1});
    for (int i=0;i<n;i++){
        while (st.size() > 0 && st.top().first < a[i]){
            st.pop();
        }
        leftlarge[i] = st.top().second;
        st.push({a[i], i});
    }
    int ans = 1;
    for (int j=0;j<n;j++){
        int i = b[j].second;
        int l = leftlarge[i];
        int r = rightlarge[i];

        int m1 = 0;
        int m2 = 0;
        if (r-1 >= i+1){
            m1 = sg.find(i+1, r-1);
        }
        if (l+1 <= i-1){
            m2 = sg.find(l+1, i-1);
        }
        dp[i] = max(dp[i], 1 + max(m1, m2));
        // cout << i << "-> " << l << " " << r << " " << dp[i] << " " << m1 << " " << m2 << endl;
        sg.update(i, dp[i]);
        ans = max(ans, dp[i]);
    }
    // for (int i=0;i<n;i++){
    //     cout << dp[i] << " ";
    // }cout << endl;
    cout << ans << endl;



}

signed main(){
    fast_io;   
    // mint::set_mod(M);
    int test = 1;
    while(test--){
        solve();
    }

    return 0;
}