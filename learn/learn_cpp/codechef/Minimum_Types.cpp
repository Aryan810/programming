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
        int n, x;
        cin >> n >> x;
        vi a(n);
        vi b(n);
        vll c(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        for (int i=0;i<n;i++){
            cin >> b[i];
        }
        for (int i=0;i<n;i++){
            c[i] = a[i]*b[i];
        }

        sort(c.rbegin(), c.rend());
        int ans = 0;
        for (int i=0;i<n;i++){
            x -= c[i];
            if (x <= 0){
                ans = i+1;
                break;
            }
        }
        if (ans == 0){ans = -1;}
        cout << ans << endl;


    }

    return 0;
}