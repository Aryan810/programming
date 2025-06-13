#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        ll one = 0;
        for (int i=0;i<2*n;i++){
            int x;
            cin >> x;
            one += x;
        }
        int m;
        int M;
        if (one%2 == 0){
            m = 0;
        }else{
            m = 1;
        }
        M = min(one, 2*n-one);
        cout << m << ' ' << M << endl;

        

    }

    return 0;
}