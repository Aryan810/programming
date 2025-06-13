#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

ll binexpiter(ll a, ll b){
    ll ans = 1;
    while (b){
        if (b&1){
            ans = ans * a;
        }
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        ll x, m;cin >> x >> m;

        ll y = 1;
        ll p = binexpiter(2, (ll)log2(x) + 1);
        ll ans = 0;
        while (y <= m && y <= p){
            // cout << "=> " << (x^y) << endl;
            ll k = (x^y != 0)?x^y:0;
            
            if (k != 0){
                if (x%(k) == 0 || y%(k) == 0){
                    ans += 1;
                }
            }
            y++;
        }
        cout << ans << endl;

    }

    return 0;
}