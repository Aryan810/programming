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
        unordered_map <int , int> m;
        for (int i=0;i<n;i++){
            int c;
            cin >> c;
            m[c] += 1;
            a[i] = c;
        }
        map <int, int> p;
        for (auto k: m){
            p[k.second] += 1;
        }
        ll ans = 0;
        ans += 2*(ll)ceil(p[1]/double(2));
        ans += m.size() - p[1];
        cout << ans << endl;
    }

    return 0;
}