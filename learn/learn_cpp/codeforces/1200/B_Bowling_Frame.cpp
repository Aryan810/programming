#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool check(ll w, ll b, ll x){
    while (x > 0){
        if (max(w, b) < x){
            return 0;
        }else{
            if (w > b){
                w -= x;
                x -= 1;
            }else{
                b -= x;
                x -= 1;
            }
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        ll w, b;
        cin >> w >> b;
        ll k = 2*(w+b);
        ll high = (ll)((sqrt(4*k+1)-1)/2);
        ll low = 1;
        while (low < high){
            ll mid = (low + high)/2;
            if (check(w, b, mid)){
                // cout << "yes" << endl;
                low = mid + 1;
                // ans = mid;
            }else{
                high = mid - 1;
            }
        }
        cout << high << endl;
    }

    return 0;
}