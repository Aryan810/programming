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
        int n, x, y;
        cin >> n >> x >> y;
        vi a(n);
        // for (int i=1;i<=n;i++){
        //     if (i <= x && i >= y){
        //         a[i-1] = 1;
        //     }else{
        //         a[i-1] = -1;
        //     }
        // }
        int s = -1;
        for (int i=y-2;i>=0;i--){
            a[i] = s;
            s *= -1;
        }
        s = -1;
        for (int i=x;i<n;i++){
            a[i] = s;
            s *= -1;
        }
        for (int i=y-1;i<x;i++){
            a[i] = 1;
        }
        for (int i=0;i<n;i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
 
    return 0;
}