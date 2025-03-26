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
    
    if (!(n&1)){
        int ans = 0;
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            ans = ans | x;
        }
        cout << ans << endl;return;
    }else{
        vector<int> onbit(32);
        vi a(n);
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            a[i] = x;
            int k = 1;
            for (int j=0;j<32;j++){
                if (k&x){
                    onbit[j] += 1;
                }
                k = k << 1;
            }
        }

        int minContribInd = 1e18;
        int ind = 0;
        for (int i=0;i<n;i++){
            int k = 1;
            int contrib = 0;
            for (int j=0;j<32;j++){
                if (k&a[i] && onbit[j] == 1){
                    contrib += k;
                }
                k = k << 1;
            }
            if (contrib < minContribInd){
                ind = i;
                minContribInd = contrib;
            }
        }
        int ans = 0;
        for (int i=0;i<n;i++){
            if (i != ind){ans = ans | a[i];}
        }
        cout << ans << endl;
    }

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}