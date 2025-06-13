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
        lli n, x;
        cin >> n >> x;
        vlli a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        lli w = 0;
        lli h = a[0];
        int i = 1;
        for (;i<n;i++){
            // cout << i << endl;
            if (w < x){
                h = a[i];
                w += (a[i]-a[i-1])*(i);
            }
            if (w == x){
                break;
            }
            if (w > x){
                h -= 1;
                break;
            }
        }
        if (w < x){
            if (i >= n){
                h += (x-w)/n;
            }else{
                h += abs(w-x)/i;
            }
        }
        cout << "ans: " << h << " " << w << " " << i << endl;
    }

    return 0;
}