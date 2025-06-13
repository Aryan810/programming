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

    int n, m, k;cin >> n >> m >> k;
    multiset<int> s;
    rep(i, m){
        int x;cin >> x;
        s.insert(x);
    }
    int x = n - k*(n/k);
    int big = x;
    int small = k - x;
    // if (x == 0 && s.size() == 1){
    //     if ((n/k)%(*it) != 0){cout << "NO" << endl;return;}else{
    //         cout << "YES" << endl;
    //         return;
    //     }
    // }

    if (*s.rbegin() > (n + k - 1)/k){
        cout << "NO" << endl;return;
    }
    if (n%k == 0){
        if (s.count(n/k) > small){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }else{
        if (s.count((n+k-1)/k) > big){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    
    // while (it != s.rend()){
    //     if (*it != 0){
    //         for (int i=j;i<n;i+=k){
    //             if (*it != 0){val -= 1;}else{
                    
    //             }
                
    //         }
    //         if (*it != 0){
    //             cout << "NO" << endl;return;
    //         }else{

    //         }
    //     }
    // }


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