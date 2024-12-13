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
        vi a(n);
        unordered_map <int, int> m;
        for (int i=0;i<n;i++){
            int x;
            cin >> x;
            m[x-i] += 1;
            a[i] = x-i;
        }
        int ans = 0;
        for (auto k: m){
            ans += (k.second)*(k.second-1)/2;
        }
        cout << ans << endl;
    }

    return 0;
}
