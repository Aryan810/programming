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
        lli n, m;
        cin >> n >> m;

        vector<lli> v(n);
        for(int i=0;i<n;i++) cin >> v[i];

        sort(v.begin(), v.end());
        lli d = *(v.end()-1) + m;
        lli c = 0;
        lli M = *(v.end()-1);
        lli margin = 0;
        for (auto x: v){ 
            margin += M-x;
        }
        if (margin >= m){
            c = M;
        }else{
            m -= margin;
            c = M + (lli)ceil(m/double(n));
        }
        cout << c << ' ' << d << endl;

    }

    return 0;
}