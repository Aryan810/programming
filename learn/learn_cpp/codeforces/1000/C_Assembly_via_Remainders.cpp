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
        vector<int> x(n-1);
        for (int i=0;i<x.size();i++){
            cin >> x[i];
        }
        vector<lli> a(n);
        for (int i=0;i<n;i++){
            if (i == 0){
                a[0] = x[0] + 1;
                continue;
            }
            if (i == n-1){
                a[n-1] = x[n-2];
                break;
            }

            lli k = (lli)((x[i]-x[i-1])/(double)a[i-1]) + 1;
            a[i] = k*(a[i-1]) + x[i-1]; 
            if (a[i] == 1){
                k += 1;
                a[i] = k*(a[i-1]) + x[i-1];
            }
        }
        // cout << "DS " << a[0] << endl;
        for(int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}   