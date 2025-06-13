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
        int ans = -1;
        int y = 0;
        vi a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        for (int i=0;i<n;i++){
            bool x = 1;
            for (int j=0;j<n;j++){
                if (j == i){continue;}
                if (abs(a[i]-a[j])%k == 0){
                    x = 0;
                    break;
                }
            }
            if (x){y = 1;ans = i+1;break;}
        }
        if (y){
            cout << "YES" << endl << ans << endl;
        }else{
            cout << "NO" << endl;
        }
        

    }

    return 0;
}