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
vector<bool> primes(1e6+7, 1);
void solve(){
    int n;cin >> n;
    primes[0] = 0;
    primes[1] = 0;
    for (ll i=2;i<=1e6;i++){
        if (primes[i]){
            for (ll j=2*i;j<=1e6;j+=i){
                primes[j] = 0;
            }
        }
    }
    unordered_set<ll> tPrimes;
    for (ll i=2;i<=1e6;i++){
        if (primes[i]){
            tPrimes.insert((ll)i*i);
        }
    }
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        cout << ((tPrimes.find(x) != tPrimes.end())?"YES":"NO") << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}