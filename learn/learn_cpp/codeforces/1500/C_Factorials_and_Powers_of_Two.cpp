#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast,unroll-loops")

using namespace __gnu_pbds;
using namespace std;
#define int long long
#define vi vector<int>
#define vii vector<int>::iterator
#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int factorial(int n){
    int ans = 1;
    for (int i=1;i<=n;i++){
        ans *= i;
    }
    return ans;
}

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

void logic(int i, int num, int sm, int & ans, int n){
    if (i < 15){
        int fac = factorial(i);
        if (sm+fac <= n){logic(i+1, sm + fac, num+1, ans, n);}
        logic(i+1, sm, num, ans, n);
    }else{
        if (sm <= n){
            int x = num + onesinbin(n-sm);
            ans = min(ans, x);
        }
    }
    
}

void solve(){

    int n;
    cin >> n;
    int ans = 1e18;
    logic(1, 0, 0, ans, n);
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