#include <iostream>
#include <vector>
#include <algorithm>
#define lli long long int
#define vi vector<int>
#define vlli vector<lli>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, x;
        cin >> n >> x;
        vector<int> cnt(n+2, 0);
        for (int i=0;i<n;i++){
            int temp;
            cin >> temp;
            if (temp <= n+1){
                cnt[temp] += 1;
            }
        }

        for (int i=0;i<=n+1;i++){
            if (cnt[i] > 1){
                int t = x+i;
                while((t <= n+1)&&(cnt[i] > 1)){
                    cnt[t] += 1;
                    cnt[i] -= 1;
                    t += x;
                }
            }
        }
        for (int i=0;i<=n+1;i++){
            if (cnt[i] == 0){
                cout << i << endl;
                break;
            }
        }





    }

    return 0;
}