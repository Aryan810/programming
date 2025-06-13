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
        for(int i=0;i<n;i++) cin >> a[i];
        string s;
        cin >> s;
        int i=0,j=n-1;
        ll ans = 0;
        vll cum(n+1);
        cum[0] = 0;
        ll sum = 0;
        for (int k=0;k<n;k++){
            sum += a[k];
            cum[k+1] = sum;
        }
        while (i<j){
            while (i < n && s[i]!='L'){
                i++;
            }
            while (j >=0 && s[j]!='R'){
                j--;
            }
            if (i>=j){break;}

            if ((i>=0 && i<n) && (j<n && j >= 0)){
                ans += cum[j+1]-cum[i];
                s[i] = '.';
                s[j] = '.';
            }
        }
        cout << ans << endl;
    }

    return 0;
}