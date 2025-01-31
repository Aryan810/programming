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
    vi a(n);
    vi b(n);
    vi bInd(n+1);
    rep(i, n) cin >> a[i];
    rep(i, n){
        int x;
        cin >> x;
        b[i] = x;
        bInd[x] = i;
    }
    vector<int> diffNum(n+1, 0);
    for (int i=0;i<n;i++){
        int j = bInd[a[i]];
        if (j >= i){
            diffNum[j-i] += 1;
        }else{
            diffNum[n - i + j] += 1;
        }
    }
    cout << *max_element(all(diffNum)) << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}