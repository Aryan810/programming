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

    int n, k;cin >> n >> k;
    unordered_set<int> diff;
    rep(i, n){
        int x;
        cin >> x;
        diff.insert(x);
    }
    if (diff.size() > k){
        cout << -1 << endl;return;
    }
    vector<int> out(n*k);
    for (int i=0;i<k;i++){
        int toadd = 1;
        if (diff.size() > 0){
            toadd = *(diff.begin());
            diff.erase(diff.begin());
        }
        for (int j=i;j<out.size();j+=k){
            out[j] = toadd;
        }
    }

    cout << out.size() << endl;
    for (auto ele: out){
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