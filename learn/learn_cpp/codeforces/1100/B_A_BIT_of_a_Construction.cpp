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
        ll k;
        cin >> n >> k;
        if (n == 1){
            cout << k << endl;
        }else{
            if (log2(k+1) - (int)log2(k+1) == 0.0f){
                cout << k << " ";
                for (int i=0;i<n-1;i++){
                    cout << '0' << " ";
                }
                cout << endl;
            }else{
                ll x = pow(2, (int)log2(k))-1;
                cout << x << " ";
                cout << k-x << " ";
                for (int i=0;i<n-2;i++){cout << '0' << " ";}
                cout << endl;
            }
        }

    }

    return 0;
}