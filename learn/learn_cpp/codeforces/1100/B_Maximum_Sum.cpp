#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vlli a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        // cout << "h1" << endl;
        lli sum = 0;
        vlli cum(n+2);
        cum[n+1] = 0;
        cum[0] = 0;
        for (int i=1;i<=n;i++){
            sum += a[i-1];
            cum[i] = sum;
        }
        // cout << "h2" << endl;

        lli m = 1e18;
        for (int i=0;i<=k;i++){
            int j = 2*(k-i);
            // cout << "h3" << endl;
            if (j <= n){
                lli s = cum[j];
                s += (*(cum.end()-2)-*(cum.end()-2-i));
                // cout << "s: " << s << " j: " << j << endl;
                if (m > s){
                    m = s;
                }
            }
        }
        // cout << m << endl;
        cout << cum[n]-m << endl;

    }

    return 0;
}