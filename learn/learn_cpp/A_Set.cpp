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
        ll l, r, k;
        cin >> l >> r >> k;
        cout << (((r/k - l + 1)>=0)?(r/k - l + 1):0) << endl;
        

    }

    return 0;
}