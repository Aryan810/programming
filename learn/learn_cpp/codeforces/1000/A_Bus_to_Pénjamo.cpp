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
        int n, r;
        cin >> n >> r;

        vi a(n);
        for (int i=0;i<n;i++) cin >> a[i];

        // int ans = 0;
        // for (int i=0;i<n;i++){
        //     while (a[i] >= 2){
        //         a[i] -= 2;
        //         r--;
        //         ans += 2;
        //     }
        // }

        // int left = 0;
        // int sum = accumulate(a.begin(), a.end(), 0);
        // int extra = 2*r - sum;
        // for (int i=0;i<n;i++){
        //     if (a[i] > 0){
        //         if (extra >= 1){
        //             extra -= 1;
        //             r--;
        //             ans += 1;
        //         }else{
        //             break;
        //         }
        //     }
        // }
        // cout << ans << endl;
        

        int sum = accumulate(a.begin(), a.end(), 0);
        int extra = 2*r - sum;
        int unhappy = 0;
        // cout << "Extra: " << extra << endl;
        for (int i=0;i<n;i++){
            if (a[i]%2 != 0){
                if (extra != 0){
                    unhappy += 0;
                    extra -= 1;
                }else{
                    unhappy += 1;
                    if (i != n-1){
                        unhappy += 1;
                        a[i+1] -= 1;
                    }
                }
            }
        }
        cout << sum-unhappy << endl;
        

    }

    return 0;
}