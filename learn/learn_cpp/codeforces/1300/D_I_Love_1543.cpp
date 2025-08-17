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
    
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    rep(i, n){
        cin >> grid[i];
    }

    int h=n, w=m;
    pi st = {0, 0};
    int ans = 0;
    while (h > 0 && w > 0){
        pi tmp = st;
        string lst;
        for (int i=0;i<(w-1);i++){
            lst.push_back(grid[st.first][st.second]);
            st.second += 1;
        }
        // cout << st.first << " " << st.second << endl;
        for (int i=0;i<(h-1);i++){
            lst.push_back(grid[st.first][st.second]);
            st.first += 1;

        }

        for (int i=0;i<w-1;i++){
            lst.push_back(grid[st.first][st.second]);
            st.second -= 1;
            
        }

        for (int i=0;i<h-1;i++){
            lst.push_back(grid[st.first][st.second]);
            st.first -= 1;
        }
        int sz = lst.size();
        int f = -1;
        for (int i=0;i<sz;i++){
            if (lst[i]=='1'){
                f = i;
            }
        }
        if (f != -1){
            string lst4;
            for (int i=0;i<sz;i++){
                int ind = (f + i)%sz;
                lst4.push_back(lst[ind]);
                if (lst4.size() > 4){
                    lst4.erase(lst4.begin());
                }
                if (lst4 == "1543"){
                    ans += 1;
                }
            }
        }
        st = {tmp.first + 1, tmp.second + 1};

        h -= 2;
        w -= 2;
    }

    cout << ans << endl;

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