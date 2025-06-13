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

    int fx, p, q;
    cin >> fx >> p >> q;
    int x = fx;
    int n = p, m = q;

    while ((n > 0 || m > 0) && (x > 0)){
        if (m > 0){
            x = (x + 1)/2;
            m -= 1;
            if (x == 1){
                if (n > 0){
                    x = 0;
                    break;
                }else{
                    break;
                }
            }
        }else{
            x = (x)/2;
            n -= 1;
        }
    }
    cout << x << " ";


    x = fx;
    n = p, m = q;
    while ((n > 0 || m > 0) && (x > 0)){
        if (n > 0){
            x /= 2;
            n -= 1;
        }else{
            x = (x+1)/2;
            m -= 1;
            if (x == 1){
                break;
            }
        }
    }
    cout << x << endl;
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