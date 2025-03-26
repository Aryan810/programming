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
    
    vi a(n);
    int sm = 0;
    vi cum(n+1);
    cum[0] = 0;
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        sm += x;
        cum[i+1] = sm;
    }

    int q;
    cin >> q;

    rep(i, q){
        int l, u;
        cin >> l >> u;

        auto it = lower_bound(all(cum), u+1+cum[l-1]);
        // cout << "it: " << it-cum.begin() << endl;
        // cout << u << " " << *it << " " << *(it-1) << endl;
        if (it == cum.end()){cout << it-cum.begin()-1 << " ";}
        else if (it-1 != (cum.begin()) && (*it-u-cum[l-1] >= u+1+cum[l-1]-*(it-1))){
            cout << max((int)(it-cum.begin()-1), l) << " ";
            // cout << "here " << abs(*it-u-0.5f) << " " << abs(u+0.5f-*(it-1)) << endl;
        }else{
            cout << max((int)(it-cum.begin()), l) << " ";
        }
    }
    cout << endl;

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