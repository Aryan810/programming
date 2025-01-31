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

  int n, r;
  cin >> n >> r;
  cout << comb(n, r) << endl;

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