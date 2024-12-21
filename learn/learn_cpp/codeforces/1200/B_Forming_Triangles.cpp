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
    ll n;
    cin >> n;
    vll a(n);
    map<ll, ll> m;
    for (int i=0;i<n;i++){
        ll x;cin >> x;
        m[x] += 1;
        a[i] = x;
    }
    sort(a.begin(), a.end());

    auto it = m.rbegin();
    ll ans = 0;
    ll done = 0;
    while (it != m.rend()){

        ll count = it->second;
        done += count;
        if (count >= 3){
            ans += (count)*(count-1)*(count-2)/6;
        }
        if (count >= 2){
            ans += ((count)*(count-1)/2)*(n-done);
        }
        it++;
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