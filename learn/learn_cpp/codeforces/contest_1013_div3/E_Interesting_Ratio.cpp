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
vector<int> primes;
vector<bool> prime(1e7 + 1, true);

void solve(){

    int n;
    cin >> n;
    int ans = 0;
    for (int a=1;a<n;a++){
        // if (n/a <= a){break;}
        auto r = lower_bound(all(primes), n/a);
        // cout << a << " " << *r << endl;
        if (*r != n/a){
            ans += (int)(r-primes.begin());
        }else{
            ans += (int)(r-primes.begin()) + 1;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1e7;
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++){
        if (prime[p]){
            primes.push_back(p);
        }
    }
    // for (int i=0;i<30;i++){
    //     cout << primes[i] << " ";
    // }cout << endl;
    int test;
    cin >> test;

    while(test--){
        solve();
    }

    return 0;
}