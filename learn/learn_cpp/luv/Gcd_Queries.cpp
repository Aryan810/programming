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
        int n, q;
        cin >> n >> q;
        vi a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        vi fwd(n);
        vi bwd(n);
        fwd[0] = a[0];
        bwd[0] = a[n-1];
        for (int i=1;i<n;i++){
            fwd[i] = gcd(fwd[i-1], a[i]);
        }
        for (int i=1;i<n;i++){
            bwd[i] = gcd(bwd[i-1], a[n-i-1]);
        }
        for (int i=0;i<q;i++){
            int l, r;
            cin >> l >> r;
            cout << gcd(fwd[l-2], bwd[n-r-1]) << endl;
        }
        

    }

    return 0;
}