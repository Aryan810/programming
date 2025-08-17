#include <iostream>
#include <cmath>
using namespace std;
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
int cnt[1000001];
void solve(){
    
    int n;
    cin >> n;
    int ans = 1;
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        for (int j=1;j*j<=x;j++){
            if (x%j != 0){continue;}
            cnt[j]++;
            if (j != x/j){
                cnt[x/j]++;
            }
        }
    }
    for (int i=1000000;i>=1;i--){
        if (cnt[i] > 1){
            cout << i << endl;
            break;
        }
    }
}

signed main(){
    fast_io;   
    
    solve();

    return 0;
}
