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
int M = 1e9+7;
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1){
            ans = (ans * a%M)%M;
        }
        a = (a * a%M)%M;
        b >>= 1;
    }
    return ans;
}
void solve(){

    int n, m;
    cin >> n >> m;
    int modbinexp = binexpiter(2, n-1);
    vector<int> biton(40, 0);
    for (int i=0;i<m;i++){
        int l, r, x;
        cin >> l >> r >> x;
        for (int j=0;j<30;j++){
            if (x & (1 << j)){
                // cout << "do: " << j << endl;
                biton[j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i=0;i<biton.size();i++){
        if (biton[i] == 1){
            ans = (ans + (modbinexp * binexpiter(2, i))%M)%M;
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