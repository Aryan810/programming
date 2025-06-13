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
        int n, k;cin >> n >> k;
        vi a(n);
        ll sum = 0;
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            sum += x;
            a[i] = x;
        }
        sort(a.rbegin(), a.rend());
        ll ans = 0;
        if (sum < k){
            ans += k-sum;
        }else{  
            ll s = 0;
            int l = n-1;
            for (int i=0;i<n;i++){
                s += a[i];
                if (i == n-1){
                    break;
                }
                if (i<n && s+a[i+1] > k){
                    break;
                }
            }
            ans += k - s;
        }
        cout << ans << endl;

    }

    return 0;
}