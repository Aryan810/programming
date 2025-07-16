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
    
    int n;
    cin >> n;

    vector<pair<int, int> > v;

    for (int i=0;i<n;i++){
        int l, r, a, b;
        cin >> l >> r >> a >> b;
        v.push_back({l, b});
    }
    sort(all(v));
    vector<pair<int, int> > cum;
    stack<pi> st;
    int f = -1;
    for (int i=0;i<n;i++){
        int mx = -1;
        while (st.size() > 0 && st.top().second < v[i].first){
            mx = max(mx, st.top().second);
            st.pop();
        }
        // cout << i << " " << f << " " << mx << endl;
        if (st.size() == 0){
            if (mx != -1){
                cum.push_back({f, mx});
            }
            f = v[i].first;
        }

        st.push(v[i]);
    }

    if (st.size() > 0){
        int mx = -1;
        while (st.size() > 0){
            mx = max(mx, st.top().second);
            st.pop();
        }
        cum.push_back({f, mx});
    }

    // for (auto & ele: cum){
    //     cout << ele.first << " " << ele.second << endl;
    // }

    sort(all(cum));
    int q;
    cin >> q;
    vi qri(q);
    vi def(q);
    rep(i, q){
        int x;
        cin >> x;
        def[i] = x;
        qri[i] = x;
    }
    map<int, int> ans;
    sort(all(qri));
    int curr = 0;
    int i = 0;
    while (i < q && curr < cum.size()){
        // cout << qri[i] << " " << curr << endl;
        if (qri[i] <= cum[curr].second && qri[i] >= cum[curr].first){
            // cout << qri[i] << " . " << cum[curr].second << endl;
            ans[qri[i]] = cum[curr].second;
            i += 1;
        }else{
            if (qri[i] < cum[curr].first){
                i += 1;
            }else{
                curr += 1;
            }
        }
    }
    i = 0;
    for (i=0;i<q;i++){
        if (ans.find(def[i]) != ans.end()){
            cout << ans[def[i]] << " ";
        }else{
            cout << def[i] << " ";
        }
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