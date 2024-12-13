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

    int t;
    cin >> t;

    while(t--){
        ll n, k;cin >> n >> k;
        ll x = k/(n-1);
        ll y = k%(n-1);
        ll ans = 0;
        if (y == 0){
            ans += (n-1)*x + x-1;
        }else{
            ans += (n-1)*x + x + y;
        }
        cout << ans << endl;
        

    }

    return 0;
}