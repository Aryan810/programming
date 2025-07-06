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

void solve(){
    
    int n;
    cin >> n;

    vi a(n);
    int ones = 0;
    rep(i, n){
        int x;
        cin >> x;
        ones += abs(x);
        a[i] = x;
    }
    if (ones&1){
        cout << -1 << endl;return;
    }

    int i=(-1);
    int j=(0);
    vector<pi> odd;
    set<pi> out;
    int x = 0;
    while (i < n-1){
        while (i+1 < n && a[i+1] == 0){
            i += 1;
        }
        if (i == n-1){break;}
        j = i+1;
        
        while (j < n && a[j] != 0){
            j += 1;
        }
        int btw = (j-i-1);
        if (btw&1){
            if (i >= 0 && a[i] == 0){
                odd.push_back({i, i+1});
                i += 2;
                for (int l=0;l<(btw-1)/2;l++){
                    if (a[i] + a[i+1] == 0){
                        out.insert({i, i});
                        out.insert({i+1, i+1});
                    }else{
                        out.insert({i, i+1});
                    }
                    i += 2;
                }
            }else{
                x += a[i+1];
                out.insert({i+1, i+1});
                i += 2;
                for (int l=0;l<(btw-1)/2;l++){
                    if (a[i] + a[i+1] == 0){
                        out.insert({i, i});
                        out.insert({i+1, i+1});
                    }else{
                        out.insert({i, i+1});
                    }
                    i += 2;
                }
            }
        }else{
            i += 1;
            for (int l=0;l<(btw)/2;l++){
                if (a[i] + a[i+1] == 0){
                    out.insert({i, i});
                    out.insert({i+1, i+1});
                }else{
                    out.insert({i, i+1});
                }
                i += 2;
            }
        }
        j = i + 1;
    }
    if (x == 0){
        if (odd.size()&1){cout << -1 << endl;return;}
    }else if (x == 1){
        if ((odd.size()+1)&1){cout << -1 << endl;return;}
        if (a[odd.back().second] == 1){
            out.insert({odd.back().first, odd.back().second});
        }else{
            out.insert({odd.back().first, odd.back().first});
            out.insert({odd.back().second, odd.back().second});
        }
        odd.pop_back();
    }else{
        if ((odd.size()+1)&1){cout << -1 << endl;return;}
        if (a[odd.back().second] == -1){
            out.insert({odd.back().first, odd.back().second});
        }else{
            out.insert({odd.back().first, odd.back().first});
            out.insert({odd.back().second, odd.back().second});
        }
        odd.pop_back();
    }
    for (int l=0;l<odd.size()/2;l++){
        if (a[odd[l].second] == 1){
            out.insert({odd[l].first, odd[l].first});
            out.insert({odd[l].second, odd[l].second});
        }else{
            out.insert({odd[l].first, odd[l].second});
        }
    }
    for (int l=odd.size()/2;l<odd.size();l++){
        if (a[odd[l].second] == -1){
            out.insert({odd[l].first, odd[l].first});
            out.insert({odd[l].second, odd[l].second});
        }else{
            out.insert({odd[l].first, odd[l].second});
        }
    }
    int lst;
    if (out.size() > 0){lst = (--out.end())->second + 2;}else{
        lst = 1;
    }
    if (lst <= n){
        out.insert({lst-1, n-1});
    }
    pi last = {-1, -1};
    vector<pi> toadd;
    for (auto & ele: out){
        if (ele.first != last.second+1){
            toadd.push_back({last.second + 1, ele.first - 1});
        }
        last = ele;
    }

    for (auto & ele: toadd){
        // cout << ele.first << " - " << ele.second << endl;
        out.insert(ele);
    }
    cout << out.size() << endl;
    for (auto & ele: out){
        cout << ele.first + 1 << " " << ele.second + 1 << endl;
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