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
        int n, k, q;
        cin >> n >> k >> q;
        vector<int> a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        lli ans = 0;
        for (int i=0;i<n;i++){
            if (a[i] <= q){
                int days = 0;
                for (;i<n && a[i]<=q;){
                    days += 1;
                    // cout << days << endl;
                    i++;
                }
                if (days >= k){
                    ans += (days-k+1ll)*(days-k+2ll)/2ll;
                }
            }
        }
        cout << ans << endl;
        

    }

    return 0;
}