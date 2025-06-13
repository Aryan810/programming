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
        int n, k;cin >> n >> k;
        if (n%2 == 0){
            cout << ((k == n/2)?"YES":"NO") << endl;
        }else{
            cout << ((k == (n+1)/2 || k == (n-1)/2)?"YES":"NO") << endl;
        }
        

    }

    return 0;
}