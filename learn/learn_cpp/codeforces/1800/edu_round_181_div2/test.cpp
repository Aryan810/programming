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

void solve(){

    int l, r;
    cin >> l >> r;
    int cnt = 0;
    int n2=0, n3=0, n5=0, n7=0;
    for (int i=l;i<=r;i++){
        if (i%2 == 0){
            n2 += 1;
        }
        if (i%3==0){
            cout << i << endl;
            n3 += 1;
        }
        if (i%5==0){
            n5 += 1;
        }
        if(i%7==0){
            n7 += 1;
        }
    }
    cout << n2 << " " << n3 << " " << n5 << " " << n7 << endl;
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