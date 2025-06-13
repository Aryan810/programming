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

bool logic(int n, vi & a){
    if (a[0]%10 == 0){
        rep(i, n){
            if (a[i]%10 == 0 && a[i] != a[0]){return 0;}else if(a[i]%10 == 5 && a[i] != a[0]-5){
                return 0;
            }else if (a[i]%10 != 0 && a[i]%10 != 5){
                return 0;
            }
        }
        return 1;
    }else if (a[0]%10 == 5){
        bool all5 = 1;
        rep(i, n){
            if (a[i]%10 == 0){
                all5 = 0;break;
            }
        }
        if (all5){
            rep(i, n){
                if (a[i] != a[0]){
                    return 0;
                }
            }
            return 1;
        }else{
            rep(i, n){
                if (!(a[i] == a[0] || (a[i]%10 == 0 && a[i]-5 == a[0]))){
                    return 0;
                }
            }
            return 1;
        }
    }else{
        rep(i, n){
            if (a[i]%10 == 0 || a[i]%10 == 5){
                return 0;
            }
        }
        while (a[0]%10 != 2){
            a[0] += a[0]%10;
        }
        int lastDigit = 2;
        for (int i=1;i<n;i++){
            while (a[i]%10 != lastDigit){
                a[i] += a[i]%10;
            }
            if (abs(a[i]-a[0])%20 != 0){
                return 0;
            }
        }
        return 1;
    }
}

void solve(){

    int n;cin >> n;
    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    cout << (logic(n, a)?"Yes":"No") << endl;

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