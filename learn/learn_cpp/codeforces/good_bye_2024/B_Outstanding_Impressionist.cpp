#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast,unroll-loops")

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(i, n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define vi vector<int>
#define vii vector<int>::iterator

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key

void solve(){

    int n;
    cin >> n;
    vi l(n);
    vi r(n);
    set<int> f;
    unordered_map<int, int> m;
    rep(i, n){
        int x, y;
        cin >> x >> y;
        if (x == y){
            f.insert(x);
            m[x] += 1;
        }
        l[i] = x;
        r[i] = y;
    }
    vector<int> fix;
    for (auto ele: f){
        fix.push_back(ele);
    }
    sort(all(fix));
    // cout << "Sz: " << fix.size() << endl;
    string out;
    for (int i=0;i<n;i++){
        int x = l[i], y = r[i];
        auto low = lower_bound(all(fix), x);
        auto high = lower_bound(all(fix), y);
        if (x != y){
            if ((low == fix.end() || high == fix.end()) || (*low != x || *high != y)){
                out.push_back('1');
            }else{
                if (high-low != y-x){
                    out.push_back('1');
                }else{
                    out.push_back('0');
                }
            }
        }else{
            if (m[x] == 1){
                out.push_back('1');
            }else{
                out.push_back('0');
            }
        }
    }
    cout << out << endl;


}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}