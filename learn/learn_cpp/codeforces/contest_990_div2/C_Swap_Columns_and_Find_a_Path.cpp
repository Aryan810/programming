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
        int n;cin >> n;
        vll a(n);
        vll b(n);
        for (int i=0;i<n;i++) cin >> a[i];
        for (int i=0;i<n;i++) cin >> b[i];
        
        vector<pair<ll, ll> > c(n);
        for (int i=0;i<n;i++){
            c[i] = {a[i], b[i]};
        }

        ll sum = 0;
        for (int i=0;i<n;i++){
            sum += max(c[i].first, c[i].second);
        }
        ll ans = -1e18;
        for (int i=0;i<n;i++){
            if (ans < (sum + min(c[i].first, c[i].second))){
                ans = (sum + min(c[i].first, c[i].second));
            }
        }
        cout << ans << endl;
    }

    return 0;
}