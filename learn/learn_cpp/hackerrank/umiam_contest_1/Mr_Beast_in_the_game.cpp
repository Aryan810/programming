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
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}
void solve(){

    int n, M;
    cin >> n >> M;
    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    int ans = 0;

    for (int i=0;i<n;i++){
        int temp = 0;
        for (int j=0;j<n;j++){
            if (j != i){
                cout << (binexpiter(a[i], a[j])%M + binexpiter(a[j], a[i])%M)%M << " ";
            }else{
                cout << "*" << " ";
            }
        }cout << endl;
    }
    // cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


        solve();

    return 0;
}