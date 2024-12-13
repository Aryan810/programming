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
        ll n;
        cin >> n;
        ll x = n;
        ll ans = 0;
        while (1){
            ans += 1;
            if (x <= 1){break;}
            if (x%2 == 0){
                x = x/2 - 1;
            }else{
                x = (x-1)/2;
            }
        }
        cout << ans << endl;
    }

    return 0;
}