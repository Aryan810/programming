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
        ll n, k;cin >> n >> k;
        vll a(n);
        ll sum = 0;
        ll mplus = 0;
        ll mminus = 0;
        for (int i=0;i<n;i++){
            ll x;
            cin >> x;
            ll p = x/k;
            if (x != p*k){
                if (x > 0){
                    mplus += 1;
                }else{
                    mminus += 1;
                }
            }
            sum += p;
        }
        if (sum == 0){
            cout << "YES" << endl;
        }else{
            if (sum > 0){
                if (mminus >= sum){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }else{
                if (mplus >= (-1)*sum){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }
        }
        

    }

    return 0;
}