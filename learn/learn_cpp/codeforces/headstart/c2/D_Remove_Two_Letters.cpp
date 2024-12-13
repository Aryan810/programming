
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

        int n;cin >> n;
        string s;cin >> s;
        int ans = n-1;
        for (int i=1;i<n-1;i++){
            if (s[i-1] == s[i+1]){
                ans -= 1;
            }
        }
        cout << ans << endl;

    }

    return 0;
}