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

void solve(){
    int n;
    cin >> n;
    vll a(n);
    rep(i, n){cin >> a[i];}
    sort(all(a));
    ll M = a[n-1];
    if (n == 1){cout << 1 << endl;return;}
    ll gcdValue = 0;
    for (int i=0;i<n-1;i++){
        gcdValue = gcd(gcdValue, a[i+1]-a[i]);
    }

    ll newele = M+gcdValue;
    for (int i=1;i<=n-1;i++){
        if (!binary_search(all(a), M-(i*gcdValue))){
            newele = M-(i*gcdValue);
            break;
        }
    }

    if (newele > M){M = newele;}
    ll ans = 0;
    for (int i=0;i<n;i++){
        ans += (M-a[i])/gcdValue;
    }
    ans += (M - newele)/gcdValue;
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