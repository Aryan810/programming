#include <iostream>
#include <vector>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

// using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int onesinbin(int n){
    int x = 1;
    int ans = 0;
    for (int i=0;i<40;i++){
        if (n&x){
            ans += 1;
        }
        x = x << 1;
    }
    return ans;
}



void solve(){

    int n;
    cin >> n;
    vector<int> fact(14, 0);
    fact[0] = 1;
    for (int i=1;i<14;i++){
        fact[i] = (i+1)*fact[i-1];
    }
    int ans = 1e18;
    for (int i=0;i<(1<<14);i++){
        int sm = 0;
        for (int j=0;j<14;j++){
            if (i & (1<<(j))){
                sm += fact[j];
            }
        }
        if (sm <= n){
            ans = min(ans, onesinbin(i) + onesinbin(n-sm));
        }
    }
    cout << ans << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}