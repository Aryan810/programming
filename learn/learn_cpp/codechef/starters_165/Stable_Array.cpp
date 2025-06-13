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

#define rep(i, n) for(int i=0;i<n;i++)
#define all(c) c.begin(), c.end()
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve(){
    int n;
    cin >> n;
    // cout << n << endl;
    vector<ll> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    // for (auto ele:a){cout << ele << " ";}cout << endl;
    ll ans = 0;
    ll i = n-1;
    while (i >= 0){
        int localMax = a[i];
        // cout << "Lm: " << localMax << endl;
        ll localAns = 0;
        while (i>0 && a[i-1] < localMax){
            // cout << a[i-1] << " " << localMax << endl;
            if (a[i-1] < localMax){localAns += 1;}
            i-=1;
        }
        if (ans < localAns){
            ans = localAns;
        }
        if (i == 0){
            break;
        }
        i-=1;
    }
    cout << ans << endl;
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