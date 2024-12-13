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
        int n, m;cin >> n >> m;

        vector<string> v(n);
        for (int i=0;i<n;i++) cin >> v[i];

        ll t = 0;
        int ans = -1;
        for (int i=0;i<n;i++){
            t += v[i].size();
            if (t > m){
                ans = i;
                break;
            }else if (t == m){
                ans = i+1;
                break;
            }
        }
        if (ans == -1){
            ans = n;
        }
        
        cout << ans << endl;
    }

    return 0;
}