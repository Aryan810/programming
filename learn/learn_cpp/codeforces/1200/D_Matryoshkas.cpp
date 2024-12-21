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
    int n;cin >> n;
    vll a(n);
    map<ll, ll> m;
    for (int i=0;i<n;i++){
        ll x;cin >> x;
        m[x] += 1;
    }
    ll ans = 0;
    while (m.size() > 0){
        auto it = m.begin();
        auto next = ++m.begin();
        bool done = 0;
        while (!done){
            it->second -= 1;
            if (next != m.end() && next->first != it->first+1){
                done = 1;
            }
            if (it->second == 0){m.erase(it);}
            if (next == m.end()){break;}
            it = next;
            next++;
        }
        ans += 1;
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