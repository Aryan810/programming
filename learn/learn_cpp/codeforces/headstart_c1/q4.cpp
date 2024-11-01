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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        int req = 1;
        lli ans = 0;
        for (int i=0;i<n;i++){
            if (a[i] == req){
                req += 1;
            }else if (a[i] > req){
                ans += a[i] - req;
                req += 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}