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

int logic(int a, int b, int n, vector<int> & dp){
    if (n == 1){return 1;}
    if (n < 1){
        return 0;
    }
    // cout << n << endl;
    bool p = 0;
    bool q = 0;
    if (n%a == 0 && a != 1){p = logic(a, b, n/a, dp);}
    q = logic(a, b, n-b, dp);
    return dp[n] = (p || q);
}

void solve(){

    int a, b, n;

    cin >> n >> a >> b;
    // vector<int> dp(n+1);
    // cout << (logic(a, b, n, dp)?"Yes":"No") << endl;

    if (a == 1){
        cout << (((n-1)%b == 0)?"Yes":"No") << endl;return;
    }
    int curr = 1;
    while (curr <= n){
        if ((n-curr)%b == 0){
            // cout << curr << endl;
            cout << "Yes" << endl;return;
        }
        curr *= a;
    }

    cout << "No" << endl;

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