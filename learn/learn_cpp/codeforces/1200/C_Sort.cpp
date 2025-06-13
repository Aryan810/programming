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
        int n, q;cin >> n >> q;
        vector< vector<int> > d1(n+1);
        vector< vector<int> > d(n+1);
        string a;
        cin >> a;
        string b;
        cin >> b;
        vector<int> v(26, 0);
        d[0] = v;
        d1[0] = v;
        for (int i=0;i<n;i++){
            auto x = d[i];
            auto y = d1[i];
            x[a[i]-'a'] += 1;
            y[b[i]-'a'] += 1;
            d[i+1] = x;
            d1[i+1] = y;
        }

        for (int i=0;i<q;i++){
            int l, r;
            int ans = 0;
            cin >> l >> r;
            for (int j=0;j<26;j++){
                ans += abs(d[r][j] - d[l-1][j] - (d1[r][j] - d1[l-1][j]));
            }
            cout << ans/2 << endl;
        }
        

    }

    return 0;
}