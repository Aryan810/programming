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
        lli n, m, r, c;
        cin >> n >> m >> r >> c;
        lli ans = m-c + (n-r)*(m-1) + (n-r)*(1+abs(m-1));
        cout << ans << endl;
    }

    return 0;
}