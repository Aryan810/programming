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
        int n;
        cin >> n;
        ll m = 1e18;
        ll M = 0;
        for (int i=0;i<n;i++){
            ll x;
            cin >> x;
            if (x > M){
                M = x;
            }
            if (x < m){
                m = x;
            }
        }
        ll avg = m;
        ll ans = 0;
        while (m != M){
            // if (M == m+1){
            //     ans += 1;
            //     break;
            // }
            m = (m+avg)/2;
            M = (M+avg)/2;
            avg = m;
            ans += 1;
            // if (M == m+1){
            //     ans += 1;
            //     break;
            // }
            // cout << ans << " " << m << " " << M << endl;
        }
        cout << ans << endl;
    }

    return 0;
}