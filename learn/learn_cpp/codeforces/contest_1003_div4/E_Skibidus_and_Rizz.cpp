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

    int n, m, k;cin >> n >> m >> k;
    string out;
    if (max(n, m) < k || abs(n-m) > k){
        cout << -1 << endl;return;
    }

    char mx;
    char mn;
    int p, q;
    if (n > m){
        mx = '0';
        mn = '1';
        p = n;
        q = m;
    }else{
        mx = '1';
        mn = '0';
        q = n;
        p = m;
    }
    // cout << mx << " " << mn << endl;
    for (int i=0;i<k;i++){
        out.push_back(mx);
        p -= 1;
    }

    while (p > 0 || q > 0){
        if (q > 0){
            out.push_back(mn);
            q -= 1;
        }

        if (p > 0){
            out.push_back(mx);
            p -= 1;
        }
    }
    cout << (out) << endl;
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