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

void logic(ll n, ll k){
    ll total = n-1;
    if (n-1 < log2(k)){
        cout << -1 << endl;
        return;
    }
    ll i = 0;
    ll j = n-1;
    ll curr = 1;
    ll x = k;
    vector<ll> out(n);

    while (i<=j){
        // cout << x << " " << total << endl;
        // cout << "---> " << i << " " << j << endl;
        if (x!=0 && log(x)/log(2) > total-1){
            // cout << "IN1" << endl;
            out[j] = curr++;
            j-=1;
            if (i > j || total < 1){break;}
            x -= binexpiter(2, total-1);
            // cout << "IN" << endl;
        }else{
            // cout << "INTO1" << endl;
            out[i] = curr++;
            i += 1;
            if (i > j || total < 1){break;}
            // cout << "INTO" << endl;
            
        }
        total -= 1;
        // if (abs(j-i) < 1){
        //     break;
        // }
    }
    for (ll i=0;i<n;i++){
        cout << out[i] << " ";
    }cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        ll n, k;cin >> n >> k; 
        logic(n, k);
    }

    return 0;
}