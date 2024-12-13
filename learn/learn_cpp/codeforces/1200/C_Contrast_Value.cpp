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

        vi a(n);
        for (int i=0;i<n;i++) cin >> a[i];

        int ans = 1;
        int i = 0;
        while (i < n-1){
            if (a[i+1] - a[i] > 0){
                int j = i;
                while(j < n-1 && a[j+1]-a[j] >= 0){
                    j += 1;
                }
                // cout << "HERE: " << j << " " << ans << " " << i << endl;
                ans += 1;
                i = j;

            }else if (a[i+1] - a[i] < 0){
                int j = i;
                while (j < n-1 && a[j+1]-a[j] <= 0){
                    j += 1;
                }
                // cout << "THERE: " << j << " " << ans << " " << i << endl;
                ans += 1;
                i = j;
            }else{
                i += 1;
            }
        }
        cout << ans << endl;

    }

    return 0;
}