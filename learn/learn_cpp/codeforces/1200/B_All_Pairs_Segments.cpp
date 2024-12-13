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
        ll n, q;
        cin >> n >> q;
        vll a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        unordered_map<ll, ll> m;
        for (ll i=0;i<n-1;i++){
            ll seg = (i+1)*(n-i-1);
            m[seg] += a[i+1] - a[i] - 1;
        }
        for (int i=0;i<n;i++){
            m[i*(n-i-1) + i + n-i-1] += 1;
        }

        for (int i=0;i<q;i++){
            ll k;
            cin >> k;
            cout << m[k] << " ";
        }
        cout << endl;

    }

    return 0;
}