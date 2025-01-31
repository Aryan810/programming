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

    int n, q;
    cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<vector<string> > levels(n);
    set<int> s;
    for (int i=0;i<n;i++){
        s.insert(i);
    }
    rep(i, n){
        string s = to_string(a[i]);
        while (s.size() > 1){
            levels[i].push_back(s);
            s = to_string(accumulate(all(s), -1*('0'*s.size())));
        }
        levels[i].push_back(s);
    }
    vector<int> lev(n, 0);
    for (int i=0;i<q;i++){
        int typ;cin >> typ;
        if (typ == 1){
            int l, r;cin >> l >> r;
            auto it = s.lower_bound(l-1);
            while (it != s.end() && *it < r){
                lev[*it] += 1;
                auto tmp = it++;
                if (lev[*tmp] >= levels[*tmp].size()-1){
                    s.erase(tmp);
                }
            }
        }else{
            int x;cin >> x;
            cout << levels[x-1][(lev[x-1] < levels[x-1].size())?lev[x-1]:levels[x-1].size()-1] << endl;
        }
    }

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