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
class s_table{
    public:
        vvi stable;
        int n;
        vi arr;
        int mx;
        int DEF;
        // default comparator.
        int (*comp)(int a, int b) = [](int a, int b){return min(a, b);};
        void calc_table(){
            for (int i=0;i<n;i++){
                stable[i][0] = arr[i];
            }
            for (int i=1;i<=mx;i++){
                for (int j=0;j<=(n-(1ll<<i));j++){
                    stable[j][i] = comp(stable[j][i-1], stable[j+(1ll<<(i-1))][i-1]);
                }
            }
        }
        int find(int l, int h){
            if (h < l){
                return this->DEF;
            }
            int x = log2(h-l+1);
            int f = stable[l][x];
            int s = stable[h-(1ll<<x)+1][x];
            return this->comp(f, s);
        }
        s_table(int n, vi & arr, int DEF = 0, int (*comp)(int a, int b) = NULL){
            this->arr = arr;
            this->n = n;
            if (comp != NULL){
                this->comp = comp;
            }
            this->mx = log2(n);
            this->DEF = DEF;
            stable.assign(n+1, vector<int>(mx+1, DEF));
            calc_table();
        }
};
void solve(){
    
    int n;
    cin >> n;

    map<int, int> ind;
    vector<pi> vals;

    vi a(n);
    rep(i, n){
        int x;
        cin >> x;
        ind[x] = i+1;
        a[i] = x;
        vals.push_back({x, i+1});
    }
    int k;
    cin >> k;

    sort(all(vals));
    vals.push_back({0, 0});
    
    vector<pi> cr;
    for (int i=0;i<n;i++){
        if (vals[i+1].first != vals[i].first){
            cr.push_back(vals[i]);
        }
    }

    stack<pi> st;
    int mx = 1e15;
    st.push({0, mx});
    int lft = k;
    int lst = 0;
    map<int, int> mp;
    for (auto & ele: cr){
        if (ele.second < lst){
            continue;
        }
        lst = ele.second;
        if (st.empty()){
            break;
        }

        pi pr = st.top();st.pop();
        int diff = ele.first - pr.first;
        int lm = lft/diff;
        lm = min(lm, pr.second);
        lft -= lm * diff;
        st.push({pr.first, pr.second - lm});
        st.push({ele.first, lm});
    }
    vi out(n+1, 0);

    while (st.size() > 0){
        pi curr = st.top();st.pop();
        out[ind[curr.first]] = curr.second;
    }


   for (int i=n-1;i>=1;i--){
        out[i] = out[i+1] + out[i];
   }

   for (int i=1;i<=n;i++){
    cout << out[i] << " ";
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