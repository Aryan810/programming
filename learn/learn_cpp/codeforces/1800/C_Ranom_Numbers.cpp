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
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

bool comp(pi a, pi b){
    return a.second < b.second;
}

void solve(){
    
    string s;
    cin >> s;
    int n = s.size();
    vector<array<int, 5> > cng(n, {0,0,0,0,0});
    ordered_multiset<pair<int, int> > st;
    // cout << "here" << endl;
    vi neg(n, 0);
    for (int i=n-1;i>=0;i--){
        auto it = st.upper_bound({s[i]-'A', 1e18});
        if (it != st.end()){
            auto x = *it;
            if (st.order_of_key(x) == st.size() - 1){
                // only one is there;
                for (int j=0;j<=(s[i]-'A');j++){
                    cng[x.second][j] += 2*binexpiter(10, s[i]-'A');
                }
            }
            neg[i] = 1;
        }
        st.insert({s[i]-'A', i});
    }

    vector<pi> maxes;
    int ans = 0;
    int mx = -1;
    for (int i=n-1;i>=0;i--){
        if (mx > s[i]-'A'){
            ans -= binexpiter(10, s[i]-'A');
        }else{
            ans += binexpiter(10, s[i]-'A');
        }
        if (s[i]-'A' >= mx){
            maxes.push_back({i, s[i]-'A'});
        }
        mx = max(mx, (int)(s[i]-'A'));
    }

    mx = -1;
    // int 
    vi cum(maxes.size() + 1);
    cum[0] = 0;
    int sm = 0;
    for (int i=0;i<maxes.size();i++){
        sm += binexpiter(10, maxes[i].second);
        cum[i+1] = sm;
    }

    int ind = 0;
    int fans = -1e18;
    for (int i=n-1;i>=0;i--){
        // changing this element.
        while (ind < maxes.size() && i <= maxes[ind].first){
            ind += 1;
        }

        for (int j=0;j<5;j++){
            int delta = cng[i][j];
            auto it = lower_bound(maxes.begin()+ind, maxes.end(), make_pair(i, j), comp);
            
            int tot = cum[it-maxes.begin()] - cum[ind];
            delta -= 2 * (tot);
            delta += binexpiter(10, s[i]-'A')*((neg[i]?1:-1));
            if (mx > j){
                delta -= binexpiter(10, j);
            }else{
                delta += binexpiter(10, j);
            }

            // if (i == n-1){cout << maxes.size() << " ";}
            // cout << delta << endl;
            // if (i == n-1){
            // }
            fans = max(fans, ans + delta);
        }
        // cout << ind << endl;
        mx = max(mx, (int)(s[i]-'A'));
    }

    cout << (fans) << endl;


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