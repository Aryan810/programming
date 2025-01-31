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

void logic(int i, vector<int> & a, vector<int> & pre, int lies, vector<int> & typ, int & ans){
    // cout << i << " " << lies << " " << ans << endl;
    if (i < 0){
        if (lies == 0){
            ans += 1;
        }
        return;
    }else if (i == 0){
        if (lies == 1){
            ans += 1;
        }else if (lies == 0){
            if (typ[i] != 0){
                ans += 1;
            }
        }
        return;
    }


    if (pre[i] > lies){
        return;
    }else if (pre[i] == lies){
        for (int j=0;j<=i;j++){
            if (typ[j] != 0){
                if (j > 0 && pre[j-1] != a[j]){
                    return;
                }
            }
        }
        ans += 1;
        return;
    }
    // if he is true
    if (typ[i] != 0){
        if (a[i] == lies){
            logic(i-1, a, pre, lies, typ, ans);
        }else{
            if (lies-1 != a[i-1]){
                return;
            }else{
                logic(i-2, a, pre, lies-1, typ, ans);
                return;
            }
        }

        // if he is lier
        if (lies-1 != a[i-1]){
            return;
        }else{
            logic(i-2, a, pre, lies-1, typ, ans);
        }
    }else{
        if (lies-1 != a[i-1]){
            return;
        }else{
            logic(i-2, a, pre, lies-1, typ, ans);
        }
    }
}

void solve(){

    int n;
    cin >> n;
    vi a(n);
    rep(i, n){cin >> a[i];}
    vi typ(n);
    rep(i, n){
        int maxl = (i+1)/2;
        if (a[i] > maxl){
            typ[i] = 0;
        }else{
            typ[i] = -1;
        }
    }
    rep(i, n-1){
        if (typ[i] == 0 && typ[i+1] == 0){
            cout << 0 << endl;return;
        }
    }
    vector<int> pre(n);
    int lies = 0;
    for (int i=0;i<n;i++){
        if (typ[i] == 0){lies += 1;}
        pre[i] = lies;
    }
    

    // if (n >= 3)
    int ans = 0;

    // if last lie
    logic(n-3, a, pre, a[n-2], typ, ans);

    // if last truth
    logic(n-2, a, pre, a[n-1], typ, ans);
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