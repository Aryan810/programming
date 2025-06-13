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
    vector<int> a(11);
    int ans = 0;
    int done = 0;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        a[x] += 1;
        // for (int i=0;i<9;i++){
        //     cout << a[i] << " ";
        // }cout << endl;
        if (a[0] >= 3 && (a[1] >= 1 && (a[2] >= 2 && (a[5] >= 1 && (a[3] >= 1))))){
            if(!done){ans = i+1;done = 1;}
        }
    }
    cout << ans << endl;

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