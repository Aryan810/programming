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

    int n, m;
    cin >> n >> m;
    vector<int> lines(n);
    rep(i, n){
        cin >> lines[i];
    }
    sort(all(lines));
    rep(i, m){
        int a, b, c;cin >> a >> b >> c;
        double l = b-2*sqrt(a*c);
        double h = b+2*sqrt(a*c);
        int low=0, high=0;
        if (l < 0){
            low = floor(l) + 1;
        }else{
            low = (int)l + 1;
        }
        if (h < 0){
            high = (int)h - 1;
        }else{
            high = ceil(h) - 1;
        }
        auto s = lower_bound(all(lines), low);
        auto e = upper_bound(all(lines), high);
        if (s < e){
            cout << "YES" << endl;
            cout << *s << endl;
        }else{
            cout << "NO" << endl;
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