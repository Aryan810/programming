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
        int n;
        cin >> n;
        lli sum = 0ll;
        lli mm = 1e11;
        lli minimum = 1e10;
        for (int i=0;i<n;i++){
            int m;
            cin >> m;
            lli m1 = 1e10;
            lli m2 = 1e10;
            vector<int> a(m);
            int m_ind = 0;
            for (int j=0;j<m;j++){
                cin >> a[j];   
                if (a[j] < m1){
                    m1 = a[j];
                    m_ind = j;
                }
            }
            a[m_ind] = 1e9+7;
            for (int j=0;j<m;j++){
                if (a[j] >= m1 and a[j] < m2){
                    m2 = a[j];
                }
            }

            if (m == 1){m2 = m1;}
            // cout << i << ' ' << m2 << endl;
            sum += m2;
            if (m1 < minimum){
                minimum = m1;
            }
            if (m2 < mm){
                mm = m2;
            }
        }
        // cout << "minimum: " << minimum << " second min: " << mm << endl;
        // cout << sum << " " << mm << ' ' << minimum << endl;
        cout << (sum - mm + minimum) << endl;

    }

    return 0;
}