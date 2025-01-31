// #include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// // #pragma GCC optimize("Ofast,unroll-loops")

// using namespace std;
// using namespace __gnu_pbds;

// #define int long long
// #define rep(i, n) for(int i=0;i<n;i++)
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// #define vi vector<int>
// #define vii vector<int>::iterator

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // find_by_order, order_of_key
// vector<vector<int> > dp;
// int logic(int i, vector<int> & a, int lies){
//     if (lies <= 0){
//         for (int j=i;j>=0;j--){
//             if (a[j] != 0){
//                 return 0;
//             }
//         }
//         return 1;
//     }
//     if (i < 0){
//         if (lies <= 0){
//             return 1;
//         }
//         return 0;
//     }else if (i == 0){
//         int ret = 0;
//         if (lies == 1){
//             ret += 1;
//         }else if (lies == 0){
//             if (a[i] == 0){
//                 ret += 1;
//             }
//         }
//         return ret;
//     }
//     cout << i << " " << lies << " " << dp[i][lies] << endl;

//     if (dp[i][lies] != -1){
//         return dp[i][lies];
//     }

//     // else if (pre[i] == lies){
//     //     for (int j=0;j<=i;j++){
//     //         if (typ[j] != 0){
//     //             if (j > 0 && pre[j-1] != a[j]){
//     //                 return;
//     //             }
//     //         }
//     //     }
//     //     ans += 1;
//     //     return;
//     // }

//     // if he is true
//     // if (typ[i] != 0){
//     int ret = 0;
//         if (a[i] == lies){
//             ret = (ret + logic(i-1, a, lies)%M)%M;
//         }
//         // if he is lier
//         if (lies-1 == a[i-1]){
//             ret = (ret + logic(i-2, a, lies-1)%M)%M;
//         }
//     return dp[i][lies] = ret;
    
//     // }else{
//     //     if (lies-1 != a[i-1]){
//     //         return;
//     //     }else{
//     //         logic(i-2, a, pre, lies-1, typ, ans);
//     //     }
//     // }
// }

// void solve(){

//     int n;
//     cin >> n;
//     vi a(n);
//     rep(i, n){cin >> a[i];}
//     // vi typ(n);
//     // rep(i, n){
//     //     int maxl = (i+1)/2;
//     //     if (a[i] > maxl){
//     //         typ[i] = 0;
//     //     }else{
//     //         typ[i] = -1;
//     //     }
//     // }
//     // rep(i, n-1){
//     //     if (typ[i] == 0 && typ[i+1] == 0){
//     //         cout << 0 << endl;return;
//     //     }
//     // }
//     // vector<int> pre(n);
//     // int lies = 0;
//     // for (int i=0;i<n;i++){
//     //     if (typ[i] == 0){lies += 1;}
//     //     pre[i] = lies;
//     // }
//     dp.assign(n, vector<int>(n, -1));
//     // if n == 1
//     if (n == 1){
//         if (a[0] != 0){
//             cout << 1 << endl;
//         }else{
//             cout << 2 << endl;
//         }
//         return;
//     }else if (n == 2){
//         // if last lie
//         int ret = 0;
//         if (a[0] == 0){
//             ret += 1;
//         }

//         // if last truth
//         ret = (ret + logic(0, a, a[1])%M)%M;
//         cout << ret << endl;
//         return;
//     }

//     cout << (logic(n-3, a, a[n-2])%M + logic(n-2, a, a[n-1])%M)%M << endl;


// }

// signed main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int test;
//     cin >> test;

//     while(test--){
//         solve();
//     }

//     return 0;
// }

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
int M = 998244353;
void solve(){

    int n;
    cin >> n;
    vi a(n);
    rep(i, n){cin >> a[i];}

    vector<int> dp(n+1, 0);
     if (n == 1){
        if (a[0] != 0){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
        return;
    }
    if (a[0] == 0){
        dp[0] = 1;
    }else{
        dp[0] = 0;
    }

    for (int i=1;i<n;i++){
        // i - 1 -> lier
        if (i == 1){
            if (a[i] == 1){
                dp[i] = (dp[i]%M + 1)%M;
            }
        }else{
            if (a[i-2] + 1 == a[i]){
                dp[i] = (dp[i] + dp[i-2]%M)%M;
            }
        }

        // (i-1) -> true
        if (a[i] == a[i-1]){
            dp[i] = (dp[i] + dp[i-1]%M)%M;
        }
    }
    cout << (dp[n-1] + dp[n-2])%M << endl;
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