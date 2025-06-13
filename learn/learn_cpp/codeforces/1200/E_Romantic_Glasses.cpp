#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
#define vi vector<int>
#define vii vector<int>::iterator
#define vlli vector<ll>::iterator
#define vll vector<ll>

void solve(){
    ll n;cin >> n;
    vll diff(n+1);
    diff[0] = 0;
    ll so = 0, se = 0;
    for (ll i=1;i<=n;i++){
        ll x;cin >> x;
        if (i&1){
            so += x;
        }else{
            se += x;
        }
        diff[i] = so - se;
    }
    
    unordered_set<ll> duplicates;
    bool possible = 0;
    for (auto x: diff){
        if (duplicates.find(x) != duplicates.end()){
            possible = 1;
        }
        duplicates.insert(x);
    }
    // ll maxDiff = 0;
    // for (auto a: sames){
    //     if (a.second.first != a.second.second){
    //         ll dif = a.second.second - a.second.first;
    //         // cout << dif << endl;
    //         if (maxDiff < dif){
    //             maxDiff = dif;
    //         }
    //         if (maxDiff >= 2){
    //             break;
    //         }
    //     }
    // }
    if (possible){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){

        solve();

    }

    return 0;
}