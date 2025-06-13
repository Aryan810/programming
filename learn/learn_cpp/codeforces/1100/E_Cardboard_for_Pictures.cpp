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
        lli n, c;
        cin >> n >> c;
        lli ssisq = 0;
        lli ssi = 0;
        for (lli i = 0ll;i<n;i++){
            lli x;
            cin >> x;
            ssisq += x*x;
            ssi += x;
        }
        lli k = ssi/(2*(double)n);
        lli k2 = ssisq/(4*(double)n);
        lli D = k*k - k2 + c/(4*(double)n);
        lli sqD = (lli)sqrt(D);
        cout << (lli)(sqD - k) << endl;
    }

    return 0;
}