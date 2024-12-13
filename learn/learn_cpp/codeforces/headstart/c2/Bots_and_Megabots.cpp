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
        sort(a.begin(), a.end());
        ll min_bots = *(a.end()-1);
        ll summ = accumulate(a.begin(), a.end(), 0ll);
        ll max_bots = summ;
        ll low = min_bots;
        ll high = max_bots;
        ll ans = high;
        while(low <= high){
            ll mid = (low + high)/2;
            double x = summ/double(mid);
            if (x > 3.0){
                low = mid + 1;
            }else if(x == 3){
                low = mid;
                ans = mid;
                break;
            }else{
                ans = mid;
                high = mid - 1;
            }
        }
        cout << ans << endl;

    }

    return 0;
}