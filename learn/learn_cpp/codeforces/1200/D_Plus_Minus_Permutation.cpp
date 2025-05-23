#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    ll n, x, y;cin >> n >> x >> y;
    ll multiplesOfX = n/x;
    ll multiplesOfY = n/y;
    ll commonMultiples = n/(lcm(x, y));
    multiplesOfX -= commonMultiples;
    multiplesOfY -= commonMultiples;

    ll ans = ((n*(n+1)/2)-((n-multiplesOfX)*(n - multiplesOfX + 1)/2))-((multiplesOfY)*(multiplesOfY + 1)/2);
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}