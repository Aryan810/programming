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

        lli x, y;
        cin >> x >> y;
        lli ans = 0;
        for (int i=0;i<30;i++){
            int b1 = x%2;
            int b2 = y%2;
            if (b1 != b2){
                ans = i;
                break;
            }
            x /= 2;
            y /= 2;
        }
        cout << (lli)pow(2, ans) << endl;

    }

    return 0;
}