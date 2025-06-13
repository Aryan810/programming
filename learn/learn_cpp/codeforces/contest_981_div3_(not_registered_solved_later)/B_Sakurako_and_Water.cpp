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
        // cout << 1 << endl;
        unordered_map<int, int> m;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                int x;
                cin >> x;
                if (m[i-j] > x){
                    m[i-j] = x;
                }
            }
        }
        int ans = 0;
        for (auto a: m){
            ans += (int)abs(a.second);
        }
        cout << ans << endl;
        

    }

    return 0;
}