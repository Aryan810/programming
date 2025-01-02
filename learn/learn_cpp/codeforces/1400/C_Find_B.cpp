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

    int n, q;cin >> n >> q;
    vi cum(n+1);
    cum[0] = 0;
    vi ones(n+1);
    ones[0] = 0;
    int sum=0;
    int one = 0;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        sum += x;
        if (x == 1){
            one += 1;
        }
        cum[i+1] = sum;
        ones[i+1] = one;
    }

    for (int i=0;i<q;i++){
        int l, r;
        cin >> l >> r;
        if (l == r){
            cout << "NO" << endl;
            continue;
        }
        int o = ones[r] - ones[l-1];
        int leftsum = (cum[r]-cum[l-1]) - (r-l+1);
        // cout << o << " " << leftsum << endl;
        if (o > (leftsum)){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
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