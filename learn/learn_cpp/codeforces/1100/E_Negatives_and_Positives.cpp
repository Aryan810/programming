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
        lli sum = 0;
        int m = 1e9+7;
        int negs = 0;
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            if (x < 0){negs+=1;}
            if (abs(x) < m){m = abs(x);}
            sum += (lli)abs(x);
        };
        if (negs%2 == 0){
            cout << sum << endl;
        }else{
            cout << sum - 2*m << endl;
        }
        

    }

    return 0;
}