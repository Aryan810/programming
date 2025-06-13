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
    string s;
    cin >> s;

    int sm = accumulate(all(s), -1*'0'*n);

    if (sm == n){
        cout << 1 << " " << n/2 << " " << n + 1 - n/2 << " " << n << endl;return;
    }

    int fz, lz;
    for (int i=0;i<n;i++){
        if (s[i] == '0'){
            fz = i;
        }
    }
    for (int i=0;i<n;i++){
        if (s[n-1-i] == '0'){
            lz = i;
        }
    }

    if (fz > lz){
        cout << 1 << " " << fz+1 << " " << 1 << " " << fz << endl;
    }else{
        cout << n - lz << " " << n << " " << n-lz+1 << " " << n << endl;
    }



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