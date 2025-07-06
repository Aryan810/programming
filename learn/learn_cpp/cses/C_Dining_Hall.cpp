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

void bfs(pi & start, int & n, vi & t){
    queue<pair<int, int> > q;
    q.push(start);
    map<pi, int> lev;
    int m = 10 * n;
    vector<pi> poss = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    set<array<int, 3> > st1;
    set<array<int, 3> > st0;
    while (q.size() > 0){
        pi curr = q.front();
        q.pop();
        // first
        for (auto & child: poss){
            int x = curr.first + child.first;
            int y = curr.second + child.second;
            if (x < 0 || y < 0){continue;}
            if (lev.find({x, y}) != lev.end()){
                continue;
            }
            if (x%3 == 0 || y % 3 == 0){
                lev[{x, y}] = lev[{curr.first, curr.second}] + 1;
                q.push({x, y});
            }else{
                lev[{x, y}] = lev[{curr.first, curr.second}] + 1;
                if ((x-1)%3 == 0 && (y-1)%3 == 0){
                    st0.insert({lev[{x, y}], x, y});
                }
                st1.insert({lev[{x, y}], x, y});
            }
        }
        if (st0.size() >= 2*n && st1.size() >= 2*n){
            break;
        }
    }
    // for (auto & ele: st0){
    //     cout << ele[0] << " " << ele[1] << " " << ele[2] << endl;
    // }
    for (int i=0;i<t.size();i++){
        if (t[i] == 0){
            auto curr = *st0.begin();
            cout << curr[1] << " " << curr[2] << endl;
            st0.erase(st0.begin());
            st1.erase(curr);
        }else{
            auto curr = *st1.begin();
            cout << curr[1] << " " << curr[2] << endl;
            st1.erase(st1.begin());
            if (st0.find(curr) != st0.end()){
                st0.erase(curr);
            }
        }
    }



}

void solve(){
    
    int n;
    cin >> n;
    
    vi t(n);
    rep(i, n) cin >> t[i];
    pi start = {0, 0};
    bfs(start, n, t);


    

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