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
        vi a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        ll k = 1;
        ll sum = 0;
        ll ans = 0;
        for (int i=0;i<n;i++){
            sum += a[i];
            // if (sum == k*k){
            //     ans += 1;
            //     k += 2;
            // }else if(sum > k*k){k += 2;}
            if (sqrt(sum)-(ll)(sqrt(sum)) == 0){
                if ((ll)sqrt(sum) % 2 !=0){
                    ans += 1;
                }
            }
        }
        cout << ans << endl;

    }

    return 0;
}