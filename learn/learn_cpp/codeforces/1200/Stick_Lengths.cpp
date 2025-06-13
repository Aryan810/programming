#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vll a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll h = a[n/2];
    ll h = 0;

    // can also be done like this.
    // if (n%2 == 0){
    //     h = (a[n/2] + a[n/2 - 1])/2;
    // }else{
    //     h = a[n/2];
    // }
    ll ans = 0;
    for (int i=0;i<n;i++){
        ans += abs(a[i]-h);
    }
    cout << ans << endl;
    return 0;
}