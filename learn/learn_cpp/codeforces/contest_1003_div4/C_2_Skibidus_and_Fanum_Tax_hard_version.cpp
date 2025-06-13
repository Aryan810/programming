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

    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(m);
    rep(i, m){
        cin >> b[i];
    }
    sort(all(b));
    int curr = -1e18;
    for (int i=0;i<n;i++){
        int p = a[i];
        auto q1 = lower_bound(all(b), curr+a[i]);
        if (q1 == b.end()){
            // cout << "HERE1" << endl;
            if (p >= curr){
                curr = p;
            }else{
                cout << "NO" << endl;
                return;
            }
        }else{
            // cout << "HERE2" << endl;
            int q = (*q1) - a[i];
            if (curr <= min(p, q)){
                curr = min(p, q);
            }else if (curr <= max(p, q)){
                curr = max(p, q);
            }else{
                cout << "NO" << endl;return;
            }
        }
    }

    cout << "YES" << endl;
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