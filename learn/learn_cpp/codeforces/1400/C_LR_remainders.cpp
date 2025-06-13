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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    string s;
    cin >> s;
    int f = 0, l = n-1;
    for (int i=0;i<n-1;i++){
        if (s[i] == 'L'){
            f += 1;
        }else{
            l -= 1;
        }
    }
    // if (f != l){cout << "BAD" << endl;return;}
    vector<int> ans(n);
    int curr = a[f]%m;
    ans[n-1] = curr;
    for (int i=n-2;i>=0;i--){
        if (s[i] == 'L'){
            f -= 1;
            curr = (curr*(a[f]%m))%m;
        }else{
            l += 1;
            curr = (curr*(a[l]%m))%m;
        }
        ans[i] = curr;
    }
    for (auto ele: ans){
        cout << ele << " ";
    }cout << endl;
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