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
        lli n, k;
        cin >> n >> k;
        int md = (int)log2(n) + 1;
        lli ans = 0;
        if (k >= md){
            lli x = n;
            int i=0;
            while (x != 0){
                if (x&1){
                    ans += pow(2, i);
                }
                i+=1;
                x = x/2;
            }
            ans += 1;
        }else{
            ans += pow(2, k);
        }
        cout << ans << endl;

    }

    return 0;
}