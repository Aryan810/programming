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

    int n, m;
    cin >> n >> m;
    int g = gcd(n, m);
    if (n%m == 0){
        cout << 0 << endl;
        return;
    }else if ((log2(m) - (int)log2(m) != double(0)) && (log2(m/g) - (int)log2(m/g) != double(0))){
        cout << (-1) << endl;
        return;
    }
    int ans = 0;
    int d = log2(m/g);
    int x = 1;
    for (int i=0;i<32;i++){
        if (x&(n/g)){
            if (i < d){
                ans += m/g - binexpiter(2, i);
            }
        }
        x = x << 1;
    }
    cout << ans*g << endl;


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