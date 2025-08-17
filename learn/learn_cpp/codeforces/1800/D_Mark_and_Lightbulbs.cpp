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
const int INF = 1e15;



void solve(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a[0] != b[0] || a[n-1] != b[n-1]){
        cout << -1 << endl;return;
    }

    int g1 = 1;
    int g2 = 1;
    
    for (int i=0;i<n-1;i++){
        if (a[i] != a[i+1]){
            g1 += 1;
        }
        if (b[i] != b[i+1]){
            g2 += 1;
        }
    }

    if (g1 != g2){
        cout << -1 << endl;return;
    }

    set<pi> pos;
    set<pi> neg;
    
    vector<int> diff(g1);
    int p = 0;
    int q = 0;

    for (int i=0;i<g1;i++){
        int c1 = 0;
        int c2 = 0;
        int pf = p;
        int qf = q;
        while (p < n && a[pf]==a[p]){
            c1 += 1;
            p += 1;
        }
        while (q < n && b[qf]==b[q]){
            q += 1;
            c2 += 1;
        }
        diff[i] = c1 - c2;

    }
    for (int i=0;i<g1;i++){
        if (diff[i] > 0){
            pos.insert({i, diff[i]});
        }else if (diff[i] < 0){
            neg.insert({i, -1*diff[i]});
        }
    }
    int ans = 0;
    for (int i=0;i<g1;i++){
        if (diff[i] == 0){continue;}
        if (diff[i] < 0){
            auto it = neg.lower_bound({i, -1});
            if (it == neg.end()){continue;}
            neg.erase(it);
            while (diff[i] < 0){
                it = pos.lower_bound({i, INF});
                if (it == pos.end()){cout << -1 << endl;return;}
                auto curr = *it;
                if (curr.second > -1*diff[i]){
                    ans += abs(curr.first-i)*(-1*diff[i]);
                    pos.erase(it);
                    pos.insert({curr.first, curr.second+diff[i]});
                    diff[curr.first] = curr.second + diff[i];
                    diff[i] = 0;
                }else if (curr.second <= -1*diff[i]){
                    ans += abs(curr.first-i)*(curr.second);
                    pos.erase(it);
                    diff[i] += curr.second;
                    diff[curr.first] = 0;
                }
            }
        }else if (diff[i] > 0){
            auto it = pos.lower_bound({i, -1});
            if (it == pos.end()){continue;}
            pos.erase(it);
            while (diff[i] > 0){
                it = neg.lower_bound({i, INF});
                if (it == neg.end()){cout << -1 << endl;return;}
                auto curr = *it;
                if (curr.second > diff[i]){
                    ans += abs(curr.first-i)*(diff[i]);
                    neg.erase(it);
                    neg.insert({curr.first, curr.second-diff[i]});
                    diff[curr.first] = -1*(curr.second - diff[i]);
                    diff[i] = 0;
                }else if (curr.second <= diff[i]){
                    ans += abs(curr.first-i)*(curr.second);
                    neg.erase(it);
                    diff[i] -= curr.second;
                    diff[curr.first] = 0;
                }
            }
        }
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