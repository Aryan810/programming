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
        cin >> n;
        vll a(n);
        for (int i=0;i<n;i++){
            cin >> a[i];
        }
        vector<ll> dp(n);
        dp[n-1] = a[n-1];
        for (int i=n-2;i>=0;i--){
            dp[i] = max(dp[i+1]+1, a[i]);
        }
        cout << dp[0] << endl;
        

    }

    return 0;
}