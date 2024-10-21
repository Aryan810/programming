#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;
// void logic(vi & a, lli & ans, int x){
//     int cust = *(a.end()-1);
//     int req = cust * x;
//     if (a.size() == 1){
//         ans += cust;
//         return;
//     }
//     a.pop_back();
//     req -= cust;
//     while(req != 0 && a.size() != 0){
//         int r = a.back();
//         if (req >= r){
//             req -= r;
//             a.pop_back();
//         }else{
//             // req = 0;
//             *(a.end()-1) -= req;
//             req = 0;
//         }
//     }
//     ans += cust;
//     // cout << ans << endl;
//     if (a.size() > 0){
//         logic(a, ans, x);
//     }
// }

bool ok(lli X, lli sum, int x){
    return (sum + X - 1ll)/X <= x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;
        vector<lli> a(n);
        for (int i=0;i<n;i++){cin >> a[i];}
        lli sum = accumulate(a.begin(), a.end(), 0ll);
        // sort(a.begin(), a.end());
        // logic(a, ans, x);

        lli r = 1e17, l = *max_element(a.begin(), a.end()), ans;
        while (r >= l){
            lli mid = (r + l)/2;
            if (ok(mid, sum, x)){
                r = mid - 1;
                ans = mid;
            }else{
                l = mid+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}