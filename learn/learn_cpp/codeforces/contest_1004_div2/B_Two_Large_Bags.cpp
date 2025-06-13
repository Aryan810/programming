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

    int n;cin >> n;
    vi ai(n);
    rep(i, n){
        cin >> ai[i];
    }

    vi num(n*n + 2, 0);
    for (int i=0;i<n;i++){
        num[ai[i]] += 1;
    }

    for (int i=1;i<=(n*n+1);i++){
        // cout << i << " " << num[i] << endl;
        if (num[i] == 1){cout << "No" << endl;return;}
        else if (num[i] == 2 || num[i] == 0){continue;}
        else if (num[i] >= 3){ // num[i] >= 3;
            // cout << "here" << endl;
            num[i+1] += num[i] - 2;
        }
    }
    cout << "Yes" << endl;return;

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