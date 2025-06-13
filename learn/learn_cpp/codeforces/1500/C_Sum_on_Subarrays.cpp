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
    int n, k;cin >> n >> k;
    int x = k;
    vi out(n);
    for (int i=1;i<=n;i++){
        if (x >= i){
            x -= i;
            out[i-1] = i+1;
        }else{
            if (x == 0){
                for (int j=i;j<=n;j++){
                    out[j-1] = -1*((j*(j+1))/2);
                }
                break;
            }else{
                int y = i*(i+1)/2 - (x+1)*(x+2)/2 + (out[x-1]-1);
                // cout << "y: " << y << endl;
                out[i-1] = -1*y;
                for (int j=i+1;j<=n;j++){
                    out[j-1] = -1*((j*(j+1))/2);
                }
                break;
            }
        }
    }
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