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

    int n, A, B;
    cin >> n >> A >> B;

    vi a(n);
    rep(i, n){
        cin >> a[i];
    }
    int ans = 0;
    int ml=0, mm=0;
    int cl=0, cm=0;
    for (int i=0;i<=n;i++){ // i -> pos of mahi
        int mahiscore = ml-mm;
        int ls=cl, mr=cm;
        if (A > B){
            mr += 1;
        }else if (A < B){
            ls += 1;
        }
        for (int j=0;j<=(n-i);j++){
            int score = ls-mr;
            // cout << mahiscore << " " << score << endl;
            if (mahiscore > score){
                ans += 1;
            }
            if (j >= n+i){break;}
            if (a[j+i] < B){
                ls += 1;
            }else if (a[j+i] > B){
                mr += 1;
            }
        }
        if (i < n){
            if (a[i] > A){
                mm += 1;
            }else if (a[i] < A){
                ml += 1;
            }
            if (a[i] > B){
                cm += 1;
            }else if (a[i] < B){
                cl += 1;
            }
        }
    }
    
    // if chiku

    ml=0, mm=0;
    cl=0, cm=0;
    for (int i=0;i<=n;i++){ // i -> pos of mahi
        int cscore = cl-cm;
        int ls=ml, mr=mm;
        if (B > A){
            mr += 1;
        }else if (B < A){
            ls += 1;
        }
        for (int j=0;j<=(n-i);j++){
            int mscore = ls-mr;
            // cout << mahiscore << " " << score << endl;
            if (mscore > cscore){
                ans += 1;
            }
            if (j >= n-i){break;}
            if (a[j+i] < A){
                ls += 1;
            }else if (a[j+i] > A){
                mr += 1;
            }
        }
        if (i < n){
            if (a[i] > A){
                mm += 1;
            }else if (a[i] < A){
                ml += 1;
            }
            if (a[i] > B){
                cm += 1;
            }else if (a[i] < B){
                cl += 1;
            }
        }
    }

    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}