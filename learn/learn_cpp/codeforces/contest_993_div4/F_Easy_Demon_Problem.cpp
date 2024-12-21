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

bool logic(ll x, unordered_set<ll>& sumsa, unordered_set<ll>& sumsb){
    ll y = abs(x);
    for (ll i=2;i*i<=abs(x);i++){
        if (y%i == 0){
            if ((sumsb.find(i) != sumsb.end()) && (sumsa.find(x/i) != sumsa.end())){
                return 1;
            }else if ((sumsb.find(-1*i) != sumsb.end()) && (sumsa.find(-1*x/i) != sumsa.end())){
                return 1;
            }
            if ((sumsb.find(abs(x)/i) != sumsb.end()) && (sumsa.find(i*x/abs(x)) != sumsa.end())){
                return 1;
            }else if ((sumsb.find(-1*abs(x)/i) != sumsb.end()) && (sumsa.find(-1*i*x/abs(x)) != sumsa.end())){
                return 1;
            }
        }
    }
    y = (x > 0)?1:-1;
    if ((sumsb.find(y) != sumsb.end()) && (sumsa.find(x/y) != sumsa.end())){
        return 1;
    }else if ((sumsb.find(-1*y) != sumsb.end()) && (sumsa.find(-1*x/y) != sumsa.end())){
        return 1;
    }
    return 0;
}

void solve(){
    ll n, m, q;cin >> n >> m >> q;
    vll a(n);
    vll b(m);
    ll sa = 0;
    ll sb = 0;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        sa += x;
        a[i] = x;
    }
    for (int i=0;i<m;i++){
        ll x;
        cin >> x;
        sb += x;
        b[i] = x;
    }
    unordered_set<ll> sumsa;
    unordered_set<ll> sumsb;
    for (int i=0;i<m;i++){
        sumsb.insert(sb-b[i]);
    }
    for (int i=0;i<n;i++){
        sumsa.insert(sa-a[i]);
    }

    for (int i=0;i<q;i++){
        ll x;
        cin >> x;
        cout << ((logic(x, sumsa, sumsb)?"YES":"NO")) << endl;
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

        solve();


    return 0;
}