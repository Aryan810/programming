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
        ll k;
        cin >> k;
        // cout << "N: " << n << endl;
        string s;
        cin >> s;
        vll suf(n+1);
        suf[0] = 0;
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum += (s[i]-'0' == 0)?-1:1;
            suf[i+1] = sum;
        }
        vll sufsum(n-1);
        for (int i=1;i<n;i++){
            sufsum[i-1] = (suf[n]-suf[i]);
        }
        sort(sufsum.rbegin(), sufsum.rend());
        vll cum(n-1);
        sum = 0;
        // cout << "SIZE: "<< sufsum.size() << endl;
        for (int i=0;i<sufsum.size();i++){
            sum += sufsum[i];
            cum[i] = sum;
            // cout << "sum: " << sum << endl;
        }
        ll ans = 0;
        // for (int i=0;i<cum.size();i++){cout << cum[i] << " ";}cout << endl;
        for(int i=0;i<cum.size();i++){
            if (cum[i] >= k){
                ans = i+2;
                break;
            }
            if (i == cum.size()-1){
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}