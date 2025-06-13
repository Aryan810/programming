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
        ll x, y, z, k;
        cin >> x >> y >> z >> k;

        ll ans = 0;
        for (ll i = 1;i<=x && i<=k;i++){
            if (k%i != 0){continue;}
            ll k2 = k/i;
            for (ll j=1;j<=y && j<=k2;j++){
                if (k2%j != 0){continue;}
                ll c = k2/j;
                if (c > z){
                    continue;
                }
                // cout << i << " " << j << " " << c << endl;
                ll p = (x+1-i)*(y+1-j)*(z+1-c);
                // cout << "P: " << p << endl;
                if (ans < (p)){
                    ans = p;
                }
            }
        }
        cout << ans << endl;
        

    }

    return 0;
}