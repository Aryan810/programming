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
int M = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    vi a(n);
    rep(i, n)cin >> a[i];
    int x = 0;
    // bool inc = 1;
    if (a[n-1] != n+1){cout << 0 << endl;return;}
    for (int i=0;i<n-1;i++){
        if (a[i+1] < a[i]){
            cout << 0 << endl;return;
        }
    }
    for (int i=0;i<n;i++){
        if (a[i] > i+2){
            cout << 0 << endl;return;
        }
    }
    vector<int> arr;
    vector<int> num(n);

    int last = 1;
    if (a[0] == 2){
        num[0] = -1;
        last = 2;
    }
    for (int i=0;i<n-1;i++){
        if (a[i+1] > a[i]){
            for (int j=last+1;j<(a[i]);j++){
                arr.push_back(j);
            }
            last = a[i];
            num[i+1] = -1;
        }
    }
 
    for (int j=last+1;j<(n+1);j++){
        arr.push_back(j);
    }
    
    // if (a[0] == 2 && x == n-1){cout << 0 << endl;return;}

    for (int i=0;i<n;i++){
        if (num[i] != -1){
            auto f = lower_bound(all(arr), a[i]);
            num[i] = (int)(arr.end()-f);
        }
    }
    int ans = 1;
    int done = 0;
    for (int i=n-1;i>=0;i--){
        if (num[i] != -1){
            ans = (ans * (num[i]-done))%M;
            done += 1;
        }
    }
    // for (int i=0;i<num.size();i++){
    //     cout << num[i] << " ";
    // }cout << endl;
    // int ans = 1;
    // for (int i=2;i<=(n-x);i++){
    //     ans = (ans%M * i)%M;
    // }
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