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
    ll n, l, r;
    cin >> n >> l >> r;
    vll a(n);
    bool iszero = 0;
    unordered_set<ll> dupli;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        a[i] = x;
        if (dupli.find(x) != dupli.end()){iszero = 1;}else{
            dupli.insert(x);
        }
    }
    if (iszero){
        if (l == 0){cout << "YES" << endl;}else{cout << "NO" << endl;}return;
    }
    ll ans = 0;
    if (n < 10){
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                ans *= a[i]^a[j];
            }
        }
        if (ans >= l && ans <= r){
            cout << "YES" << endl;
            return;
        }else{
            cout << "NO" << endl;
            return;
        }
    }else{

        cout << "NO" << endl;
        return;

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