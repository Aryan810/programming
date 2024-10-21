#include <bits/stdc++.h>
#define lli long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vllii vector<lli>::iterator
#define vlli vector<lli>

using namespace std;

bool logic(multiset<int> & m, int c, int d, int n, int a11){
    for (int i=0;i<n;i++){
            int x = a11 + c*(i);
            for (int j=0;j<n;j++){
                int y = x + d*(j);
                // cout << y << " ";
                auto k = m.find(y);
                if (k == m.end()){
                    return 0;
                }
                m.erase(k);
            }
            // cout << endl;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, c, d;
        cin >> n >> c >> d;
        multiset<int> m;
        int a11 = INT_MAX;
        for (int i=0;i<n*n;i++){
            int x;
            cin >> x;
            if (x < a11){
                a11 = x;
            }
            m.insert(x);
        }

        cout << (logic(m, c, d, n, a11)?"YES":"NO") << endl;

    }

    return 0;
}