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

    lli n, m, a;
    cin >> n >> m >> a;

    lli x = 1ll*a*(ceil(n/double(a)));
    lli y = 1ll*a*(ceil(m/double(a)));
    // cout << x << " " << y << endl;
    cout << (x*y*1ll)/(a*a*1ll) << endl;

    return 0;
}