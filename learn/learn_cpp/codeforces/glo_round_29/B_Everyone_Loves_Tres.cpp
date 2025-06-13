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
        if (n%2 == 0){
            for (int i=0;i<n-2;i++){cout << '3';}
            cout << "66" << endl;
        }else{
            if (n >= 5){
                for (int i=0;i<n-5;i++){
                    cout << '3';
                }
                cout << "36366" << endl;
            }else{
                cout << -1 << endl;
            }
        }
        

    }

    return 0;
}