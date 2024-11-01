#include <bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

using namespace std;

bool comp(pair<ll, int> a, pair<ll, int> b){
    return (a.first + a.second) < (b.first + b.second);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        ll n, c;
        cin >> n >> c;
        
        vector< pair<ll, int> > a(n);
        for (int i=0;i<n;i++){
            ll x;
            cin >> x;
            a[i] = {x, i+1};
        }
        sort(a.begin(), a.end(), comp);
        int ans = 0;
        for (int i=0;i<n;i++){
            if (c >= a[i].first+a[i].second){
                c -= a[i].first+a[i].second;
                ans += 1;
            }else{
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}