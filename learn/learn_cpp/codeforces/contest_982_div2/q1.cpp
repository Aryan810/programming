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
        int m1 = 0, m2 = 0;
        for (int i=0;i<n;i++){
            int x, y;
            cin >> x >> y;
            if (x > m1){
                m1 = x;
            }
            if (y > m2){
                m2 = y;
            }
        }
        cout << 2*(m1+m2) << endl;


    }

    return 0;
}   