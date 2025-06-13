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
        ll n, l, r;
        cin >> n >> l >> r;

        vll a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }

        vll cum(n+1);
        cum[0] = 0;
        ll sum = 0;
        for (int i=0;i<n;i++){
            sum += a[i];
            cum[i+1] = sum;
        }
        ll ans = 0;
        for (int i=0;i<n;i++){
            // cout << "i: " << i << " " << ans << endl;
            if (cum[i+1]-cum[i] > r){
                continue;
            }else if (cum[n]-cum[i] < l){
                break;
            }else if (cum[i+1]-cum[i] >= l && cum[i+1]-cum[i] <= r){
                ans += 1;
                continue;
            }
            else{
                ll low = i;
                ll high = n-1;
                while (low < high){
                    ll mid = (low + high)/2;
                    ll sm = cum[mid+1]-cum[i];
                    if (sm >= l){
                        high = mid;
                    }else{
                        low = mid + 1;
                    }
                }
                // cout << i << " " << high << endl;
                if (cum[high+1]-cum[i] > r){
                    continue;
                }else{
                    ans += 1;
                    i = high;
                }
            }
            
        }
            // if (cum[high+1]-cum[i] == l){
            //     ans += 1;
            //     i = high;
            // }else{
            //     if (high != n-1){
            //         if (cum[high+2]-cum[i] <= l){
            //             i = high + 1;
            //         }
            //     }
            // }
        
        cout << ans << endl;

    }

    return 0;
}