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

        int n;
        cin >> n;
        vi x(n);
        for(int i=0;i<n;i++) cin >> x[i];
        int q;
        cin >> q;
        sort(x.begin(), x.end());
        for (int i=0;i<q;i++){
            int m;
            cin >> m;
            cout << (upper_bound(x.begin(), x.end(), m) - x.begin()) << endl;
        }
        


    return 0;
}