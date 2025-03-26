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
    vi cum(n+1);
    cum[0] = 0;
    int sm = 0;
    rep(i, n){
        int x;cin >> x;
        sm += x;
        cum[i+1] = sm;
    }
    int ans = 0;
    int i=n;
    while (i > 0){
        unordered_set<int> temp;
        while (i > 0){
            // cout << temp.size()<< " " << i << " " << cum[i] << endl;
            if (temp.find(cum[i-1])==temp.end()){
                temp.insert(cum[i]);
                i -= 1;
            }else{  
                ans += 1;
                break;
            }
        }
    }
    cout << ans << endl;
}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}