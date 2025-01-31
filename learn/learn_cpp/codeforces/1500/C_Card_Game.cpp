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
int M = 998244353;
int binexpiter(int a, int b){
    int ans = 1;
    while (b){
        if (b&1ll){
            ans = (ans * a)%M;
        }
        a = (a * a)%M;
        b >>= 1;
    }
    return ans;
}
int comb(int n, int r){
    int ans = 1;
    for (int i=0;i<r;i++){
        ans = (ans * (n-i)%M)%M;
    }
    int temp = 1;
    for (int i=1;i<=r;i++){
        temp = (temp * binexpiter(i, M-2))%M;
    }
    return (ans * temp)%M;
}

void solve(){

    int n;
    cin >> n;
    vector<int> A(61);
    vector<int> B(61);
    A[2] = 1;
    B[2] = 0;
    if (n == 2){
        cout << "1 0 1" << endl;return;
    }
    int x = 4;
    while (1){
        A[x] = (comb(x-1, x/2) + B[x-2])%M;
        B[x] = (comb(x-2, x/2) + A[x-2])%M;
        if (x == n){
            cout << A[x] << " " << B[x] << " " << (comb(n, n/2) - A[x] - B[x] + M)%M << endl;
            return;
        }
        x += 2;
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