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

    int n;
    cin >> n;
    vi a(n);
    vi cump(n+1), cumn(n+1);
    int sp = 0;
    int sn = 0;
    cump[0] = 0;
    cumn[0] = 0;
    rep(i, n){
        int x;
        cin >> x;
        a[i] = x;
        if (x > 0){sp += abs(x);}
        else{sn += abs(x);}
        cump[i+1] = sp;
        cumn[i+1] = sn;
    }
    int ansM = 0;
    int ansC = 0;
    int i=0, j=n-1;
    while (i <= j){
        // cout << "L " << i << " " << j << endl;
        while ((i < n && a[i] > 0)){
            ansC += abs(a[i]);
            i++;
        }
        while (j >= 0 && a[j] < 0){
            ansC += abs(a[j]);
            j--;
        }
        // cout << i << " " << j << endl;
        int pi=i, pj=j;
        if (i <= j){
            if (i < n && a[i] < 0){
                ansM = max(ansM, ansC + cumn[pj]-cumn[pi]);
                while (i < n && a[i] < 0){
                    i += 1;
                }
            }
            if (j >= 0 && a[j] > 0){
                ansM = max(ansM, ansC + cump[pj+1]-cump[pi+1]);
                while (j >= 0 && a[j] > 0){
                    j -= 1;
                }
            }
        }
    }
    cout << max(ansC, ansM) << endl;

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