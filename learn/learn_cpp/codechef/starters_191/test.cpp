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

    int n; 
    cin>>n; 
    vector<int> v(n,0); 
    for (auto &i:v)cin>>i;
    sort(all(v));
    vi ans(n,0);
    int ptr = 0;
    for (int i = 1 ; i<n ; i+=2)
    ans [i] = v[ptr++];
    for(int i = 0 ; i<n ; i+=2)
    ans [i] = v[ptr++];
    int nums = 0;
    for (int i = 1 ; i<n-1 ; i++)
    if(ans[i] < ans[i+1] && ans[i] < ans [i-1])nums++;
    cout<<nums<<endl; for(auto &i:ans)cout<<i<<" "; cout<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t = 1;

    while(t--){

        solve();

    }

    return 0;
}